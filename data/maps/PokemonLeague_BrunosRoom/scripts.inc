@ ============================================================================
@ M4b S11 -- BRUNO'S ROOM. The sitter is KOGA.
@
@ THE ROOM NAMES ARE KANTO'S FURNITURE; THE OCCUPANTS ARE JOHTO'S LEAGUE. Act III
@ puts LORELEI, BRUNO, AGATHA and LANCE back in the rooms already named for them;
@ for Indigo I the player walks BRUNO's stone room to fight KOGA.
@
@ THE DOOR STATE MACHINE. Ported from pokefirered/data/scripts/pokemon_league.inc
@ into data/scripts/trinity_indigo.inc (one place for the coordinates). The Hoenn
@ twin, data/scripts/elite_four.inc, is the same machine on different tiles in a
@ different tileset -- its constants would paint HOENN metatiles into this room.
@
@   ON_FRAME   fires once per run on SCENE_INDIGO == 1: walk the player 5 up
@              off the impassable landing tile (applymovement ignores collision,
@              S6), SE_UNLOCK, swap the entry ART to closed, redraw, set 2.
@   ON_LOAD    re-authors the doors on a map reload -- the shut entry while
@              SCENE_INDIGO == 2, and the OPEN exit once FLAG_TRINITY_J_E4_KOGA_BEATEN
@              is set. D2: metatile authoring lives ONLY here, never in
@              ON_TRANSITION, which InitMapLayoutData wipes microseconds later
@              (src/overworld.c:876-877, src/fieldmap.c:96-103). ON_LOAD also
@              covers continue-from-save, which ON_TRANSITION never runs on.
@   ON_WARP    turn the player north, as every league map in both parents does.
@
@ The exit warp at (6,2) CANNOT FIRE until SetDoorOpen runs: 0x293 is MB_NORMAL
@ at collision 1 and only 0x296 is MB_NON_ANIMATED_DOOR, which
@ IsWarpMetatileBehavior accepts (src/field_control_avatar.c:925-939). Beating
@ KOGA is the engine-level condition for leaving forwards. There is no
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

PokemonLeague_BrunosRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_BrunosRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_BrunosRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_BrunosRoom_OnFrame
	.byte 0

PokemonLeague_BrunosRoom_OnLoad:
	call_if_set FLAG_TRINITY_J_E4_KOGA_BEATEN, PokemonLeague_BrunosRoom_EventScript_SetDoorOpen
	call_if_eq VAR_TRINITY_JOHTO_SCENE_INDIGO, 2, PokemonLeague_BrunosRoom_EventScript_CloseEntry
	end

PokemonLeague_BrunosRoom_EventScript_SetDoorOpen::
	call Trinity_Indigo_EventScript_SetDoorOpen
	return

PokemonLeague_BrunosRoom_EventScript_CloseEntry::
	call Trinity_Indigo_EventScript_CloseEntry
	return

PokemonLeague_BrunosRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_BrunosRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_BrunosRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

PokemonLeague_BrunosRoom_OnFrame:
	map_script_2 VAR_TRINITY_JOHTO_SCENE_INDIGO, 1, PokemonLeague_BrunosRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_BrunosRoom_EventScript_EnterRoom::
	lockall
	call Trinity_Indigo_EventScript_EnterRoom
	setvar VAR_TRINITY_JOHTO_SCENE_INDIGO, 2
	releaseall
	end

PokemonLeague_BrunosRoom_EventScript_Koga::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_E4_KOGA_BEATEN, PokemonLeague_BrunosRoom_EventScript_PostBattle
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox PokemonLeague_BrunosRoom_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KOGA_E4, PokemonLeague_BrunosRoom_Text_Defeat
	goto PokemonLeague_BrunosRoom_EventScript_Defeated
	end

PokemonLeague_BrunosRoom_EventScript_Defeated::
	setflag FLAG_TRINITY_J_E4_KOGA_BEATEN
	call Trinity_Indigo_EventScript_OpenDoor
	msgbox PokemonLeague_BrunosRoom_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

PokemonLeague_BrunosRoom_EventScript_PostBattle::
	msgbox PokemonLeague_BrunosRoom_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

@ GSC KogasRoom.asm. The laugh, the ninja register and "POKéMON is not merely
@ about brute force" are his; the adaptation is that he has read the file.
PokemonLeague_BrunosRoom_Text_Intro:
	.string "Fwahahahaha!\p"
	.string "I am KOGA of the ELITE FOUR.\p"
	.string "I live in shadows -- a ninja!\p"
	.string "They sent your record ahead of\n"
	.string "you. Eight GYMS in HOENN. Eight\l"
	.string "more here. A LAKE. A TOWER.\p"
	.string "Every line of it describes a\n"
	.string "trainer who wins by hitting\l"
	.string "harder than the other one.\p"
	.string "Confusion. Sleep. Poison.\p"
	.string "POKéMON is not merely about brute\n"
	.string "force -- you shall see soon\l"
	.string "enough!\p"
	.string "Fwahahahaha!$"

PokemonLeague_BrunosRoom_Text_Defeat:
	.string "Ah!\n"
	.string "You have proven your worth!$"

PokemonLeague_BrunosRoom_Text_PostBattle:
	.string "I subjected you to everything I\n"
	.string "could muster.\p"
	.string "But my efforts failed. I must\n"
	.string "hone my skills.\p"
	.string "…And I must burn that file.\p"
	.string "Go on to the next room, and put\n"
	.string "your abilities to the test.$"
