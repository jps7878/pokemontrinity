@ ============================================================================
@ Trinity -- shared INDIGO PLATEAU / ELITE FOUR door engine. Authored by M4b S11.
@
@ THE ROOMS ARE ONE-WAY TRAPS BY CONSTRUCTION, BEFORE ANY SCRIPT RUNS.
@ Every league room's ENTRY tiles are collision 1 in the shipped blockdata --
@ in this port AND in pokefirered, which the layouts are byte-identical to. The
@ player arrives on one by warp (a warp destination need not be walkable;
@ SetupWarp simply puts them there) and is walked off it by applymovement, which
@ ignores collision, water and elevation entirely (M4b S6's pin;
@ InitNpcForMovement, src/event_object_movement.c:6872-6890). So CloseEntry
@ below swaps ART ONLY -- open portcullis for closed portcullis, collision 1
@ either way. It is the beat, not the mechanism.
@
@ THE EXIT DOOR IS THE MECHANISM.
@   0x293 Door_Mid closed -> MB_NORMAL,             collision 1
@   0x296 Door_Mid_Open   -> MB_NON_ANIMATED_DOOR,  collision 0 (setmetatile FALSE)
@ IsWarpMetatileBehavior (src/field_control_avatar.c:925-939) accepts
@ MB_NON_ANIMATED_DOOR and nothing else on that tile does, so the room's exit
@ warp_event CANNOT FIRE until SetDoorOpen has run. Beating the sitter is
@ therefore the literal, engine-level condition for leaving the room forwards,
@ and there is no way backwards. That is the sequential gauntlet.
@
@ D2 (re-pinned by the M4b S9 fix round): EVERY setmetatile below is reached
@ only from MAP_SCRIPT_ON_LOAD or from a mid-scene script -- NEVER from
@ MAP_SCRIPT_ON_TRANSITION, which InitMapLayoutData wipes microseconds later
@ (src/overworld.c:876-877, src/fieldmap.c:96-103). qa_sweep check 7 is the
@ permanent, tree-wide gate on that and it sees these Kanto maps.
@ D3: ON_LOAD needs no DrawWholeMapView (InitViewGraphics draws later in the
@ same load); the mid-scene opener does one and has it.
@
@ Source: pokefirered/data/scripts/pokemon_league.inc, coordinates verbatim.
@ The Hoenn twin (data/scripts/elite_four.inc) is the same state machine on
@ different tiles and in a different tileset; using its constants here would
@ paint HOENN metatiles into a KANTO room.
@
@ Used by PokemonLeague_LoreleisRoom / _BrunosRoom / _AgathasRoom (identical
@ 13x13 geometry). LANCE'S ROOM is 28x24 and carries its own copy with its own
@ coordinates; the CHAMPION'S ROOM has no door machinery at all, exactly as
@ neither vanilla parent's champion room does.
@ ============================================================================

@ (6,12) landing -> (6,7), the middle of the floor. There is no
@ Common_Movement_WalkUp5 in this tree (movement.inc has 4 and 6 only).
Trinity_Indigo_Movement_WalkUp5:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Trinity_Indigo_EventScript_EnterRoom::
	applymovement LOCALID_PLAYER, Trinity_Indigo_Movement_WalkUp5
	waitmovement 0
	playse SE_UNLOCK
	call Trinity_Indigo_EventScript_CloseEntry
	special DrawWholeMapView
	return

Trinity_Indigo_EventScript_CloseEntry::
	setmetatile 5, 11, METATILE_PokemonLeagueKanto_Entry_TopLeft_Closed, TRUE
	setmetatile 6, 11, METATILE_PokemonLeagueKanto_Entry_TopMid_Closed, TRUE
	setmetatile 7, 11, METATILE_PokemonLeagueKanto_Entry_TopRight_Closed, TRUE
	setmetatile 5, 12, METATILE_PokemonLeagueKanto_Entry_BottomLeft_Closed, TRUE
	setmetatile 6, 12, METATILE_PokemonLeagueKanto_Entry_BottomMid_Closed, TRUE
	setmetatile 7, 12, METATILE_PokemonLeagueKanto_Entry_BottomRight_Closed, TRUE
	return

@ The impassable arg matters: the door FRAME above the opening stays solid
@ (TRUE), the opening itself becomes walkable (FALSE) and only then does its
@ warp_event exist as far as the engine is concerned.
Trinity_Indigo_EventScript_SetDoorOpen::
	setmetatile 6, 1, METATILE_PokemonLeagueKanto_Door_Top_Open, TRUE
	setmetatile 6, 2, METATILE_PokemonLeagueKanto_Door_Mid_Open, FALSE
	return

Trinity_Indigo_EventScript_OpenDoor::
	applymovement LOCALID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	playse SE_DOOR
	call Trinity_Indigo_EventScript_SetDoorOpen
	special DrawWholeMapView
	return
