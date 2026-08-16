@ ============================================================================
@ M4b S11 -- LANCE'S ROOM. The sitter is KAREN.
@
@ Same state machine as the three 13x13 rooms, different coordinates: this room
@ is 28x24, the entry warp is (23,13) and the exit is (6,4)/(6,5), so the shared
@ Trinity_Indigo_EventScript_CloseEntry / _SetDoorOpen do NOT apply and the local
@ copies below carry pokefirered's own numbers verbatim
@ (pokefirered/data/maps/PokemonLeague_LancesRoom/scripts.inc:39-66).
@
@ THE CORRIDOR WALK is FRLG's, step for step: from (23,13) up 2, left 6, down 7,
@ left 11, up 8, ending at (6,10) -- two tiles below KAREN at (6,8), facing her.
@ Its legality does not depend on the geometry: applymovement has no collision,
@ elevation or terrain test at all (InitNpcForMovement,
@ src/event_object_movement.c:6872-6890 -- M4b S6's pin), which is also what
@ carries the player off the impassable (23,13) landing tile in the first place.
@ The entry gate then shuts at (5-7,14)/(5-7,15) BEHIND him, plus the two floor
@ shade tiles FRLG swaps at (6,16)/(7,16).
@
@ D2: every setmetatile here is reached from ON_LOAD or from the walk-in scene,
@ never from ON_TRANSITION. qa_sweep check 7 is the tree-wide gate.
@ ============================================================================

PokemonLeague_LancesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_LancesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_LancesRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_LancesRoom_OnFrame
	.byte 0

PokemonLeague_LancesRoom_OnLoad:
	call_if_set FLAG_TRINITY_J_E4_KAREN_BEATEN, PokemonLeague_LancesRoom_EventScript_SetDoorOpen
	call_if_eq VAR_TRINITY_JOHTO_SCENE_INDIGO, 4, PokemonLeague_LancesRoom_EventScript_CloseEntry
	end

PokemonLeague_LancesRoom_EventScript_SetDoorOpen::
	setmetatile 6, 4, METATILE_PokemonLeagueKanto_Door_Top_Open, TRUE
	setmetatile 6, 5, METATILE_PokemonLeagueKanto_Door_Mid_Open, FALSE
	return

PokemonLeague_LancesRoom_EventScript_CloseEntry::
	setmetatile 5, 14, METATILE_PokemonLeagueKanto_Entry_TopLeft_Closed, TRUE
	setmetatile 6, 14, METATILE_PokemonLeagueKanto_Entry_TopMid_Closed, TRUE
	setmetatile 7, 14, METATILE_PokemonLeagueKanto_Entry_TopRight_Closed, TRUE
	setmetatile 5, 15, METATILE_PokemonLeagueKanto_Entry_BottomLeft_Closed, TRUE
	setmetatile 6, 15, METATILE_PokemonLeagueKanto_Entry_BottomMid_Closed, TRUE
	setmetatile 7, 15, METATILE_PokemonLeagueKanto_Entry_BottomRight_Closed, TRUE
	setmetatile 6, 16, METATILE_PokemonLeagueKanto_Floor_ShadeFull_Lance, FALSE
	setmetatile 7, 16, METATILE_PokemonLeagueKanto_Floor_ShadeFull_Lance, FALSE
	return

PokemonLeague_LancesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_LancesRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_LancesRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

PokemonLeague_LancesRoom_OnFrame:
	map_script_2 VAR_TRINITY_JOHTO_SCENE_INDIGO, 3, PokemonLeague_LancesRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_LancesRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, PokemonLeague_LancesRoom_Movement_WalkThroughCorridor
	waitmovement 0
	playse SE_UNLOCK
	call PokemonLeague_LancesRoom_EventScript_CloseEntry
	special DrawWholeMapView
	setvar VAR_TRINITY_JOHTO_SCENE_INDIGO, 4
	releaseall
	end

PokemonLeague_LancesRoom_EventScript_Karen::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_E4_KAREN_BEATEN, PokemonLeague_LancesRoom_EventScript_PostBattle
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox PokemonLeague_LancesRoom_Text_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KAREN, PokemonLeague_LancesRoom_Text_Defeat
	goto PokemonLeague_LancesRoom_EventScript_Defeated
	end

PokemonLeague_LancesRoom_EventScript_Defeated::
	setflag FLAG_TRINITY_J_E4_KAREN_BEATEN
	call PokemonLeague_LancesRoom_EventScript_OpenDoor
	msgbox PokemonLeague_LancesRoom_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

PokemonLeague_LancesRoom_EventScript_PostBattle::
	msgbox PokemonLeague_LancesRoom_Text_PostBattle, MSGBOX_DEFAULT
	release
	end

PokemonLeague_LancesRoom_EventScript_OpenDoor::
	applymovement LOCALID_PLAYER, Common_Movement_Delay32
	waitmovement 0
	playse SE_DOOR
	call PokemonLeague_LancesRoom_EventScript_SetDoorOpen
	special DrawWholeMapView
	return

PokemonLeague_LancesRoom_Movement_WalkThroughCorridor:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ GSC KarensRoom.asm. Her post-battle speech is the one line of GSC the series
@ never improved on and it is kept almost whole. It is also the direct answer to
@ SILVER, who this player fought an hour ago on VICTORY ROAD -- so her exit line
@ points at LANCE by name rather than at "the CHAMPION", because in Trinity the
@ player has already met him twice.
PokemonLeague_LancesRoom_Text_Intro:
	.string "I am KAREN of the ELITE FOUR.\p"
	.string "You're {PLAYER}?\n"
	.string "How amusing.\p"
	.string "I love DARK-type POKéMON.\p"
	.string "I find their wild, tough image so\n"
	.string "appealing. And they're so strong.\p"
	.string "Think you can take them?\n"
	.string "Just try to entertain me.\p"
	.string "Let's go.$"

PokemonLeague_LancesRoom_Text_Defeat:
	.string "Well, aren't you good.\n"
	.string "I like that in a trainer.$"

PokemonLeague_LancesRoom_Text_PostBattle:
	.string "Strong POKéMON.\p"
	.string "Weak POKéMON.\p"
	.string "That is only the selfish\n"
	.string "perception of people.\p"
	.string "Truly skilled trainers should try\n"
	.string "to win with their favorites.\p"
	.string "I like your style. You understand\n"
	.string "what's important.\p"
	.string "There's a boy who came through\n"
	.string "here once with the strongest team\l"
	.string "I had ever seen, and I have never\l"
	.string "met anyone lonelier.\p"
	.string "Go on. LANCE is waiting, and he\n"
	.string "has been all week.$"
