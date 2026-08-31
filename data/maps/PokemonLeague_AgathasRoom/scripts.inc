@ ============================================================================
@ M4b S11 -- AGATHA'S ROOM. The sitter is BRUNO.
@
@ THE ROOM NAMES ARE KANTO'S FURNITURE; THE OCCUPANTS ARE JOHTO'S LEAGUE. Act III
@ puts LORELEI, BRUNO, AGATHA and LANCE back in the rooms already named for them;
@ for Indigo I the player walks AGATHA's dark room to fight BRUNO.
@
@ THE DOOR STATE MACHINE. Ported from pokefirered/data/scripts/pokemon_league.inc
@ into data/scripts/trinity_indigo.inc (one place for the coordinates). The Hoenn
@ twin, data/scripts/elite_four.inc, is the same machine on different tiles in a
@ different tileset -- its constants would paint HOENN metatiles into this room.
@
@   ON_FRAME   fires once per run on SCENE_INDIGO == 2: walk the player 5 up
@              off the impassable landing tile (applymovement ignores collision,
@              S6), SE_UNLOCK, swap the entry ART to closed, redraw, set 3.
@   ON_LOAD    re-authors the doors on a map reload -- the shut entry while
@              SCENE_INDIGO == 3, and the OPEN exit once FLAG_TRINITY_J_E4_BRUNO_BEATEN
@              is set. D2: metatile authoring lives ONLY here, never in
@              ON_TRANSITION, which InitMapLayoutData wipes microseconds later
@              (src/overworld.c:876-877, src/fieldmap.c:96-103). ON_LOAD also
@              covers continue-from-save, which ON_TRANSITION never runs on.
@   ON_WARP    turn the player north, as every league map in both parents does.
@
@ The exit warp at (6,2) CANNOT FIRE until SetDoorOpen runs: 0x293 is MB_NORMAL
@ at collision 1 and only 0x296 is MB_NON_ANIMATED_DOOR, which
@ IsWarpMetatileBehavior accepts (src/field_control_avatar.c:925-939). Beating
@ BRUNO is the engine-level condition for leaving forwards. There is no
@ backwards: the entry tiles are collision 1 in the shipped blockdata, in this
@ port and in FireRed both.
@
@ THE SITTER IS TALK-TRIGGERED (G1). A sight line in a 9-wide room with one
@ approach column is exactly what G1 exists to forbid. G3: the encounter track
@ sits under the intro speech, where it is audible -- EventScript_DoNoIntroTrainerBattle
@ calls PlayTrainerEncounterMusic unconditionally (data/scripts/trainer_battle.inc:52)
@ and swaps it at the transition, which is vanilla's own shape
@ (EverGrandeCity_SidneysRoom_EventScript_Sidney).
@
@ RE-CHALLENGEABLE, and this is verified rather than hoped:
@ EventScript_DoNoIntroTrainerBattle has NO GetTrainerFlag check (unlike
@ EventScript_TryDoNormalTrainerBattle at :19-20), so `trainerbattle_no_intro` can
@ run again for the same id. The story flag below is the whole guard, and the
@ INDIGO Center clears it -- which is why the terminal state of the whole act is
@ FLAG_TRINITY_J_LEAGUE_CLEARED and never this one (S6's cleared-flag rule).
@
@ There is no failable award anywhere in the gauntlet, so G2's award-guard clause
@ has nothing to protect and the door opens BEFORE the post-battle line, which is
@ vanilla's order.
@ ============================================================================

PokemonLeague_AgathasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_AgathasRoom_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonLeague_AgathasRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_AgathasRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_AgathasRoom_OnFrame
	.byte 0

PokemonLeague_AgathasRoom_OnLoad:
	call_if_set FLAG_TRINITY_J_E4_BRUNO_BEATEN, PokemonLeague_AgathasRoom_EventScript_SetDoorOpen
	call_if_set FLAG_TRINITY_K_E4_BRUNOII_BEATEN, PokemonLeague_AgathasRoom_EventScript_SetDoorOpen
	call_if_eq VAR_TRINITY_JOHTO_SCENE_INDIGO, 3, PokemonLeague_AgathasRoom_EventScript_CloseEntry
	end

@ Trinity M5b S11 fix round 1 (review C1) -- roster-switch flag authoring,
@ moved out of the broken ON_LOAD showobjectat/hideobjectat idiom into this
@ fresh ON_TRANSITION (CeruleanCity_OnTransition/FLAG_TRINITY_K_CAVE_GUARD_
@ HIDE idiom; full postmortem in PokemonLeague_LoreleisRoom/scripts.inc's
@ header). BRUNO's template now carries FLAG_TRINITY_K_JOHTO_SITTER_HIDE;
@ BRUNO-II's carries FLAG_TRINITY_K_KANTO_CAST_HIDE.
PokemonLeague_AgathasRoom_OnTransition::
	call Trinity_EventScript_CountKantoBadges
	goto_if_ge VAR_TEMP_A, 8, PokemonLeague_AgathasRoom_EventScript_ArmKantoCast
	setflag FLAG_TRINITY_K_KANTO_CAST_HIDE
	clearflag FLAG_TRINITY_K_JOHTO_SITTER_HIDE
	end

PokemonLeague_AgathasRoom_EventScript_ArmKantoCast::
	clearflag FLAG_TRINITY_K_KANTO_CAST_HIDE
	setflag FLAG_TRINITY_K_JOHTO_SITTER_HIDE
	end

PokemonLeague_AgathasRoom_EventScript_SetDoorOpen::
	call Trinity_Indigo_EventScript_SetDoorOpen
	return

PokemonLeague_AgathasRoom_EventScript_CloseEntry::
	call Trinity_Indigo_EventScript_CloseEntry
	return

PokemonLeague_AgathasRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_AgathasRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_AgathasRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

PokemonLeague_AgathasRoom_OnFrame:
	map_script_2 VAR_TRINITY_JOHTO_SCENE_INDIGO, 2, PokemonLeague_AgathasRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_AgathasRoom_EventScript_EnterRoom::
	lockall
	call Trinity_Indigo_EventScript_EnterRoom
	setvar VAR_TRINITY_JOHTO_SCENE_INDIGO, 3
	releaseall
	end

PokemonLeague_AgathasRoom_EventScript_Bruno::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_E4_BRUNO_BEATEN, PokemonLeague_AgathasRoom_EventScript_PostBattle
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox PokemonLeague_AgathasRoom_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BRUNO_E4, PokemonLeague_AgathasRoom_Text_Defeat
	goto PokemonLeague_AgathasRoom_EventScript_Defeated
	end

PokemonLeague_AgathasRoom_EventScript_Defeated::
	setflag FLAG_TRINITY_J_E4_BRUNO_BEATEN
	call Trinity_Indigo_EventScript_OpenDoor
	msgbox PokemonLeague_AgathasRoom_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

PokemonLeague_AgathasRoom_EventScript_PostBattle::
	msgbox PokemonLeague_AgathasRoom_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

@ GSC BrunosRoom.asm, kept in substance. The one Act II hook is MT. MORTAR,
@ which this player has walked (M4b S10 put boulders and a friend-crew trainer
@ in it).
PokemonLeague_AgathasRoom_Text_Intro:
	.string "I am BRUNO of the ELITE FOUR.\p"
	.string "I always train to the extreme,\n"
	.string "because I believe in our\l"
	.string "potential.\p"
	.string "That is how we became strong.\p"
	.string "I know the cave you crossed to\n"
	.string "get here. MT. MORTAR. I spent\l"
	.string "four winters in the black of it,\l"
	.string "moving stone.\p"
	.string "Can you withstand our power?\p"
	.string "Hm? I see no fear in you. You\n"
	.string "look determined.\p"
	.string "Perfect for battle!\p"
	.string "Ready, {PLAYER}? You will bow\n"
	.string "down to our overwhelming power!\p"
	.string "Hoo hah!$"

PokemonLeague_AgathasRoom_Text_Defeat:
	.string "Why?\n"
	.string "How could we lose?$"

PokemonLeague_AgathasRoom_Text_PostBattle:
	.string "Having lost, I have no right to\n"
	.string "say anything…\p"
	.string "Go. Face your next challenge.$"

@ ============================================================================
@ Trinity M5b S11 -- BRUNO-II, Kanto's E4-II (occupies AGATHA's room). Self-
@ contained mirror of BRUNO's script above. Roster reasoning re-derived for
@ the naming collision: this trainer id is TRAINER_BRUNO_II (distinct from
@ Johto's TRAINER_BRUNO_E4), and its own flag name (FLAG_TRINITY_K_E4_
@ BRUNOII_BEATEN) is likewise distinct from FLAG_TRINITY_J_E4_BRUNO_BEATEN.
@ ============================================================================
@ FIX ROUND 1 (review M3): own inline 8-badge check restored at the top (S1
@ house rule), provably unreachable now that BRUNO-II's own object cannot
@ spawn below 8 badges (FLAG_TRINITY_K_KANTO_CAST_HIDE).
PokemonLeague_AgathasRoom_EventScript_BrunoII::
	lock
	faceplayer
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 8, PokemonLeague_AgathasRoom_EventScript_BrunoIINotYet
	goto_if_set FLAG_TRINITY_K_E4_BRUNOII_BEATEN, PokemonLeague_AgathasRoom_EventScript_BrunoIIPostBattle
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox PokemonLeague_AgathasRoom_Text_BrunoIIIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BRUNO_II, PokemonLeague_AgathasRoom_Text_BrunoIIDefeat
	goto PokemonLeague_AgathasRoom_EventScript_BrunoIIDefeated
	end

@ Provably unreachable, kept per S1's rule.
PokemonLeague_AgathasRoom_EventScript_BrunoIINotYet::
	release
	end

PokemonLeague_AgathasRoom_EventScript_BrunoIIDefeated::
	setflag FLAG_TRINITY_K_E4_BRUNOII_BEATEN
	call Trinity_Indigo_EventScript_OpenDoor
	msgbox PokemonLeague_AgathasRoom_Text_BrunoIIPostBattle, MSGBOX_DEFAULT
	release
	end

PokemonLeague_AgathasRoom_EventScript_BrunoIIPostBattle::
	msgbox PokemonLeague_AgathasRoom_Text_BrunoIIPostBattle, MSGBOX_DEFAULT
	release
	end

PokemonLeague_AgathasRoom_Text_BrunoIIIntro:
	.string "BRUNO. ELITE FOUR, KANTO.\p"
	.string "Same name as the man who stood\n"
	.string "on this exact floor for JOHTO.\l"
	.string "Different me, same creed: the\l"
	.string "body doesn't lie to you.\p"
	.string "HITMONLEE doesn't feint. HARIYAMA\n"
	.string "doesn't bluff. Every hit means\l"
	.string "exactly what it looks like.\p"
	.string "Show me what three regions of\n"
	.string "training actually built.$"

PokemonLeague_AgathasRoom_Text_BrunoIIDefeat:
	.string "…No bluff in that, either.\n"
	.string "Good.$"

PokemonLeague_AgathasRoom_Text_BrunoIIPostBattle:
	.string "Strength like that doesn't come\n"
	.string "from luck.\p"
	.string "One room left before the door\n"
	.string "that matters. Go.$"
