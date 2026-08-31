@ ============================================================================
@ Trinity M5b S9 -- SEAFOAM ISLANDS B3F. Strength-boulder-into-hole puzzle.
@
@ MUST-CITE adjudication (sub-plan 09-cinnabar-seafoam.md section 1): PROMOTE.
@ The two boulders here were T10-placed on session-scoped FLAG_TEMP_5/FLAG_TEMP_6.
@ FRLG's own HandleBoulderFallThroughHole (pokefirered src/field_control_avatar.c:
@ 1066-1074) FlagClears a persistent save-block flag to reveal the fallen boulder on
@ the floor below -- that reveal must survive a real map transition, which a
@ VAR_TEMP cannot (ClearTempFieldEventData zeroes it on every load). Promoted to
@ FLAG_TRINITY_K_SEAFOAM_B3F_BOULDER_1/2.
@
@ Engine: this tree's own TryBoulderFallThroughHole (src/field_player_avatar.c:
@ 1758-1850, built for Blackthorn Gym 2F -- "Trinity M4b S9") is reused verbatim.
@ A pushed boulder landing on MB_CRACKED_FLOOR_HOLE triggers a coord_event at that
@ (x,y) tagged elevation 15 (BOULDER_HOLE_COORD_EVENT_ELEVATION) -- invisible to the
@ player's own coord scan, which only ever presents elevation 3 here.
@
@ Trinity's own boulder placement corrected: T10 kept the two FRLG boulders that,
@ at FRLG's own coordinates, never fall ((9,16)/(13,16), trainer_type NONE) and
@ dropped the two that do ((6,17)/(12,16), trainer_type = the B4F reveal flag).
@ (13,16) cannot reach either hole in this map's own geometry (decoded: south push
@ dead-ends at (13,17), a wall at (13,18); no route to stand east of it at (14,17),
@ also a wall, so a sideways push is impossible either). Relocated to (6,17), one
@ tile north of the other hole -- FRLG's own position for the boulder that falls
@ there. (9,16) is kept; it already lines up with its own hole two tiles south.
@ ============================================================================

.equ NUM_BOULDERS_PRESENT, VAR_TEMP_2

@ setmetatile authoring must live in MAP_SCRIPT_ON_LOAD (qa_sweep.py's own gate:
@ InitMapLayoutData wipes the grid immediately after ON_TRANSITION runs,
@ src/overworld.c:876-877 + src/fieldmap.c:96-103) -- not ON_TRANSITION.
SeafoamIslands_B3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SeafoamIslands_B3F_OnLoad
	.byte 0

SeafoamIslands_B3F_OnLoad::
	setvar NUM_BOULDERS_PRESENT, 0
	call_if_unset FLAG_TRINITY_K_SEAFOAM_B3F_BOULDER_1, SeafoamIslands_B3F_EventScript_AddBoulderPresent
	call_if_unset FLAG_TRINITY_K_SEAFOAM_B3F_BOULDER_2, SeafoamIslands_B3F_EventScript_AddBoulderPresent
	goto_if_eq NUM_BOULDERS_PRESENT, 0, SeafoamIslands_B3F_EventScript_CalmCurrent
	end

SeafoamIslands_B3F_EventScript_AddBoulderPresent::
	addvar NUM_BOULDERS_PRESENT, 1
	return

@ Both boulders gone (fallen through their holes) -- still the current. Uniform
@ METATILE_General_CalmWater sweep, not FRLG's duplicate hand-painted layout: see
@ sub-plan section 5.5 for the full reasoning (this tree has no registered
@ _CURRENT_STOPPED sibling layout for Kanto Seafoam, and FRLG's own per-cell
@ substitution is position-sensitive, not a clean lookup -- FRLG's own script
@ already uses this exact command for the two tiles its layout-swap doesn't reach,
@ this just scales it to every current cell on this floor).
SeafoamIslands_B3F_EventScript_CalmCurrent::
	setmetatile 15,  5, METATILE_General_CalmWater, 0
	setmetatile 15,  6, METATILE_General_CalmWater, 0
	setmetatile 16,  5, METATILE_General_CalmWater, 0
	setmetatile 16,  6, METATILE_General_CalmWater, 0
	setmetatile 17,  5, METATILE_General_CalmWater, 0
	setmetatile 17,  6, METATILE_General_CalmWater, 0
	setmetatile 18,  5, METATILE_General_CalmWater, 0
	setmetatile 18,  6, METATILE_General_CalmWater, 0
	setmetatile 19,  5, METATILE_General_CalmWater, 0
	setmetatile 19,  6, METATILE_General_CalmWater, 0
	setmetatile 19, 11, METATILE_General_CalmWater, 0
	setmetatile 19, 12, METATILE_General_CalmWater, 0
	setmetatile 19, 13, METATILE_General_CalmWater, 0
	setmetatile 20,  5, METATILE_General_CalmWater, 0
	setmetatile 20,  6, METATILE_General_CalmWater, 0
	setmetatile 20, 12, METATILE_General_CalmWater, 0
	setmetatile 20, 13, METATILE_General_CalmWater, 0
	setmetatile 21,  5, METATILE_General_CalmWater, 0
	setmetatile 21,  6, METATILE_General_CalmWater, 0
	setmetatile 21, 12, METATILE_General_CalmWater, 0
	setmetatile 21, 13, METATILE_General_CalmWater, 0
	setmetatile 22,  5, METATILE_General_CalmWater, 0
	setmetatile 22,  6, METATILE_General_CalmWater, 0
	setmetatile 22, 11, METATILE_General_CalmWater, 0
	setmetatile 22, 12, METATILE_General_CalmWater, 0
	setmetatile 22, 13, METATILE_General_CalmWater, 0
	setmetatile 23,  5, METATILE_General_CalmWater, 0
	setmetatile 23,  6, METATILE_General_CalmWater, 0
	setmetatile 23,  7, METATILE_General_CalmWater, 0
	setmetatile 23,  9, METATILE_General_CalmWater, 0
	setmetatile 23, 10, METATILE_General_CalmWater, 0
	setmetatile 23, 11, METATILE_General_CalmWater, 0
	setmetatile 23, 12, METATILE_General_CalmWater, 0
	setmetatile 23, 13, METATILE_General_CalmWater, 0
	setmetatile 24,  5, METATILE_General_CalmWater, 0
	setmetatile 24,  6, METATILE_General_CalmWater, 0
	setmetatile 24,  7, METATILE_General_CalmWater, 0
	setmetatile 24,  9, METATILE_General_CalmWater, 0
	setmetatile 24, 10, METATILE_General_CalmWater, 0
	setmetatile 24, 11, METATILE_General_CalmWater, 0
	setmetatile 24, 12, METATILE_General_CalmWater, 0
	setmetatile 24, 13, METATILE_General_CalmWater, 0
	setmetatile 25, 12, METATILE_General_CalmWater, 0
	setmetatile 25, 13, METATILE_General_CalmWater, 0
	setmetatile 25, 14, METATILE_General_CalmWater, 0
	setmetatile 25, 15, METATILE_General_CalmWater, 0
	setmetatile 25, 16, METATILE_General_CalmWater, 0
	setmetatile 25, 17, METATILE_General_CalmWater, 0
	setmetatile 26, 12, METATILE_General_CalmWater, 0
	setmetatile 26, 13, METATILE_General_CalmWater, 0
	setmetatile 26, 14, METATILE_General_CalmWater, 0
	setmetatile 26, 15, METATILE_General_CalmWater, 0
	setmetatile 26, 16, METATILE_General_CalmWater, 0
	setmetatile 26, 17, METATILE_General_CalmWater, 0
	setmetatile 27, 13, METATILE_General_CalmWater, 0
	setmetatile 28, 13, METATILE_General_CalmWater, 0
	special DrawWholeMapView
	end

@ ----------------------------------------------------------------------------
@ Hole (6,18): boulder 2 (relocated to (6,17)) falls here into B4F (8,18).
@ Hole (9,18): boulder 1 (9,16) falls here into B4F (9,18).
@ Player-fall landings reuse this map's own (currently dead in this engine, see
@ sub-plan 5.3) warp_events' destinations: (6,18)->B4F(8,17), (9,18)->B4F(9,17),
@ both MB_NORTHWARD_CURRENT (col0) -- the player who falls personally lands
@ mid-current and gets swept, distinct from the boulders' own (8,18)/(9,18)
@ landing tiles one row south (no object/warp overlap).
@ ----------------------------------------------------------------------------
SeafoamIslands_B3F_EventScript_FallToHole1::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_SEAFOAM_ISLANDS_B4F, 8, 17
	waitstate
	end

SeafoamIslands_B3F_EventScript_FallToHole2::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_SEAFOAM_ISLANDS_B4F, 9, 17
	waitstate
	end

SeafoamIslands_B3F_EventScript_BoulderFellHole1::
	lockall
	removeobject VAR_LAST_TALKED
	playse SE_FALL
	delay 20
	clearflag FLAG_TRINITY_K_SEAFOAM_B4F_BOULDER_2
	releaseall
	end

SeafoamIslands_B3F_EventScript_BoulderFellHole2::
	lockall
	removeobject VAR_LAST_TALKED
	playse SE_FALL
	delay 20
	clearflag FLAG_TRINITY_K_SEAFOAM_B4F_BOULDER_1
	releaseall
	end

@ ----------------------------------------------------------------------------
@ The two boulders. Primary path: the engine hook removes the boulder the instant
@ it lands in a hole, so it can never be talked to there. Backstop path (the
@ Blackthorn precedent, mandatory not decoration -- the founder gate is
@ clean-compile + review, no play-tests, so a new runtime hook is the one thing
@ that cannot be proven by running it): each boulder's own talk script checks its
@ own position and runs the same fall script if it happens to be sitting in its
@ hole; otherwise falls through to vanilla EventScript_StrengthBoulder.
@ ----------------------------------------------------------------------------
SeafoamIslands_B3F_EventScript_Boulder1::
	getobjectxy VAR_LAST_TALKED, 0, VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, SeafoamIslands_B3F_EventScript_Boulder1CheckHole
	goto EventScript_StrengthBoulder
	end

SeafoamIslands_B3F_EventScript_Boulder1CheckHole::
	goto_if_eq VAR_0x8005, 18, SeafoamIslands_B3F_EventScript_BoulderFellHole2
	goto EventScript_StrengthBoulder
	end

SeafoamIslands_B3F_EventScript_Boulder2::
	getobjectxy VAR_LAST_TALKED, 0, VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 6, SeafoamIslands_B3F_EventScript_Boulder2CheckHole
	goto EventScript_StrengthBoulder
	end

SeafoamIslands_B3F_EventScript_Boulder2CheckHole::
	goto_if_eq VAR_0x8005, 18, SeafoamIslands_B3F_EventScript_BoulderFellHole1
	goto EventScript_StrengthBoulder
	end
