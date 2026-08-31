@ ============================================================================
@ M4b S11 -- LORELEI'S ROOM. The sitter is WILL.
@
@ THE ROOM NAMES ARE KANTO'S FURNITURE; THE OCCUPANTS ARE JOHTO'S LEAGUE. Act III
@ puts LORELEI, BRUNO, AGATHA and LANCE back in the rooms already named for them;
@ for Indigo I the player walks LORELEI's ice room to fight WILL.
@
@ THE DOOR STATE MACHINE. Ported from pokefirered/data/scripts/pokemon_league.inc
@ into data/scripts/trinity_indigo.inc (one place for the coordinates). The Hoenn
@ twin, data/scripts/elite_four.inc, is the same machine on different tiles in a
@ different tileset -- its constants would paint HOENN metatiles into this room.
@
@   ON_FRAME   fires once per run on SCENE_INDIGO == 0: walk the player 5 up
@              off the impassable landing tile (applymovement ignores collision,
@              S6), SE_UNLOCK, swap the entry ART to closed, redraw, set 1.
@   ON_LOAD    re-authors the doors on a map reload -- the shut entry while
@              SCENE_INDIGO == 1, and the OPEN exit once FLAG_TRINITY_J_E4_WILL_BEATEN
@              is set. D2: metatile authoring lives ONLY here, never in
@              ON_TRANSITION, which InitMapLayoutData wipes microseconds later
@              (src/overworld.c:876-877, src/fieldmap.c:96-103). ON_LOAD also
@              covers continue-from-save, which ON_TRANSITION never runs on.
@   ON_WARP    turn the player north, as every league map in both parents does.
@
@ The exit warp at (6,2) CANNOT FIRE until SetDoorOpen runs: 0x293 is MB_NORMAL
@ at collision 1 and only 0x296 is MB_NON_ANIMATED_DOOR, which
@ IsWarpMetatileBehavior accepts (src/field_control_avatar.c:925-939). Beating
@ WILL is the engine-level condition for leaving forwards. There is no
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

PokemonLeague_LoreleisRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_LoreleisRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_LoreleisRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_LoreleisRoom_OnFrame
	.byte 0

PokemonLeague_LoreleisRoom_OnLoad:
	call_if_set FLAG_TRINITY_J_E4_WILL_BEATEN, PokemonLeague_LoreleisRoom_EventScript_SetDoorOpen
	call_if_set FLAG_TRINITY_K_E4_LORELEI_BEATEN, PokemonLeague_LoreleisRoom_EventScript_SetDoorOpen
	call_if_eq VAR_TRINITY_JOHTO_SCENE_INDIGO, 1, PokemonLeague_LoreleisRoom_EventScript_CloseEntry
	@ Trinity M5b S11 -- the roster switch (sub-plan §1.2). Live 8-Kanto-badge
	@ check, zero flags (SetObjectInvisibility is SCREFF_HARDWARE only), same
	@ idiom as the Indigo II lobby's own OnLoad.
	call Trinity_EventScript_CountKantoBadges
	goto_if_ge VAR_TEMP_A, 8, PokemonLeague_LoreleisRoom_EventScript_ShowLorelei
	showobjectat LOCALID_JOHTO_E4_WILL, MAP_POKEMON_LEAGUE_LORELEIS_ROOM
	hideobjectat LOCALID_KANTO_E4_LORELEI, MAP_POKEMON_LEAGUE_LORELEIS_ROOM
	end

PokemonLeague_LoreleisRoom_EventScript_ShowLorelei::
	hideobjectat LOCALID_JOHTO_E4_WILL, MAP_POKEMON_LEAGUE_LORELEIS_ROOM
	showobjectat LOCALID_KANTO_E4_LORELEI, MAP_POKEMON_LEAGUE_LORELEIS_ROOM
	end

PokemonLeague_LoreleisRoom_EventScript_SetDoorOpen::
	call Trinity_Indigo_EventScript_SetDoorOpen
	return

PokemonLeague_LoreleisRoom_EventScript_CloseEntry::
	call Trinity_Indigo_EventScript_CloseEntry
	return

PokemonLeague_LoreleisRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_LoreleisRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_LoreleisRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

PokemonLeague_LoreleisRoom_OnFrame:
	map_script_2 VAR_TRINITY_JOHTO_SCENE_INDIGO, 0, PokemonLeague_LoreleisRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_LoreleisRoom_EventScript_EnterRoom::
	lockall
	call Trinity_Indigo_EventScript_EnterRoom
	setvar VAR_TRINITY_JOHTO_SCENE_INDIGO, 1
	releaseall
	end

PokemonLeague_LoreleisRoom_EventScript_Will::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_E4_WILL_BEATEN, PokemonLeague_LoreleisRoom_EventScript_PostBattle
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox PokemonLeague_LoreleisRoom_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WILL, PokemonLeague_LoreleisRoom_Text_Defeat
	goto PokemonLeague_LoreleisRoom_EventScript_Defeated
	end

PokemonLeague_LoreleisRoom_EventScript_Defeated::
	setflag FLAG_TRINITY_J_E4_WILL_BEATEN
	call Trinity_Indigo_EventScript_OpenDoor
	msgbox PokemonLeague_LoreleisRoom_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

PokemonLeague_LoreleisRoom_EventScript_PostBattle::
	msgbox PokemonLeague_LoreleisRoom_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

@ GSC WillsRoom.asm, adapted. His spine is kept -- trained all around the world,
@ psychic POKéMON, newly accepted into the ELITE FOUR, losing is not an option --
@ and the Act II turn is that he already knows exactly who walked in, and says
@ the interesting thing about it.
PokemonLeague_LoreleisRoom_Text_Intro:
	.string "Welcome to the POKéMON LEAGUE,\n"
	.string "{PLAYER}.\p"
	.string "Allow me to introduce myself.\n"
	.string "I am WILL.\p"
	.string "I have trained all around the\n"
	.string "world, making my PSYCHIC POKéMON\l"
	.string "powerful, and at last I have been\l"
	.string "accepted into the ELITE FOUR.\p"
	.string "I know what you are carrying.\n"
	.string "A HOENN badge case. A title.\p"
	.string "None of it is worth anything in\n"
	.string "this room, and I think you already\l"
	.string "understand that, or you would not\l"
	.string "have taken the stairs so slowly.\p"
	.string "I can only keep getting better.\n"
	.string "Losing is not an option!$"

PokemonLeague_LoreleisRoom_Text_Defeat:
	.string "I… I can't…\n"
	.string "believe it…$"

PokemonLeague_LoreleisRoom_Text_PostBattle:
	.string "Even though I was defeated, I\n"
	.string "won't change my course.\p"
	.string "I will keep battling until I\n"
	.string "stand above all trainers.\p"
	.string "Now, {PLAYER} -- move on, and\n"
	.string "experience the true ferocity of\l"
	.string "the ELITE FOUR.$"

@ ============================================================================
@ Trinity M5b S11 -- LORELEI, Kanto's E4-II. Self-contained mirror of WILL's
@ script above (object-level exclusivity via ON_LOAD's showobjectat/
@ hideobjectat means only one of the two objects/scripts is ever reachable
@ for a given room-load, so no live badge check is needed HERE, only in the
@ room's ON_LOAD). trainerbattle_no_intro, own FLAG_TRINITY_K_E4_LORELEI_
@ BEATEN, same door-open call -- sub-plan §4.
@ ============================================================================
PokemonLeague_LoreleisRoom_EventScript_Lorelei::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_K_E4_LORELEI_BEATEN, PokemonLeague_LoreleisRoom_EventScript_LoreleiPostBattle
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox PokemonLeague_LoreleisRoom_Text_LoreleiIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LORELEI, PokemonLeague_LoreleisRoom_Text_LoreleiDefeat
	goto PokemonLeague_LoreleisRoom_EventScript_LoreleiDefeated
	end

PokemonLeague_LoreleisRoom_EventScript_LoreleiDefeated::
	setflag FLAG_TRINITY_K_E4_LORELEI_BEATEN
	call Trinity_Indigo_EventScript_OpenDoor
	msgbox PokemonLeague_LoreleisRoom_Text_LoreleiPostBattle, MSGBOX_DEFAULT
	release
	end

PokemonLeague_LoreleisRoom_EventScript_LoreleiPostBattle::
	msgbox PokemonLeague_LoreleisRoom_Text_LoreleiPostBattle, MSGBOX_DEFAULT
	release
	end

@ LORELEI has watched this trainer's whole KANTO run from the record book
@ downstairs -- specific recognition, not generic badge-count boilerplate
@ (S8's I1 still applies: nobody counts badges here).
PokemonLeague_LoreleisRoom_Text_LoreleiIntro:
	.string "Welcome back, {PLAYER}.\p"
	.string "The last trainer to stand in\n"
	.string "this room was JOHTO's CHAMPION.\l"
	.string "You watched that happen.\p"
	.string "I am LORELEI. I keep this floor\n"
	.string "cold on purpose -- it clears the\l"
	.string "head before anything else does.\p"
	.string "Let's see what three regions'\n"
	.string "worth of training actually\l"
	.string "looks like.$"

PokemonLeague_LoreleisRoom_Text_LoreleiDefeat:
	.string "Clear-headed, and correct.\n"
	.string "That's a rare combination.$"

PokemonLeague_LoreleisRoom_Text_LoreleiPostBattle:
	.string "The cold never bothered me. Losing\n"
	.string "to someone who earned it doesn't\l"
	.string "either.\p"
	.string "Go on, {PLAYER}. The rest of us\n"
	.string "are waiting.$"
