Route29_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	.byte 0

@ Trinity M4b S1. SILVER stands on this route only while he is fleeing the
@ ELM'S LAB theft (scene 2); the battle scene removes him.
Route29_OnTransition:
	goto_if_eq VAR_TRINITY_JOHTO_SCENE_NEWBARK, 2, Route29_EventScript_ShowSilver
	setflag FLAG_TRINITY_J_SILVER_ROUTE29_HIDE
	end

Route29_EventScript_ShowSilver::
	clearflag FLAG_TRINITY_J_SILVER_ROUTE29_HIDE
	end

@ ============================================================================
@ Scene D -- TRAINER_SILVER_1
@ Adapts pokecrystal CherrygroveRivalSceneSouth/North (CherrygroveCity.asm:
@ 99-172): approach, MUSIC_RIVAL_ENCOUNTER, battle, the "my name is" reveal,
@ exit stage left. Relocated to ROUTE 29 per the M4b slice contract, and cut
@ down to one roster (GSC branches on which starter the player took).
@ GSC's BATTLETYPE_CANLOSE is dropped: a loss is an ordinary whiteout, and
@ because neither the trigger nor VAR_TRINITY_JOHTO_SCENE_NEWBARK is touched
@ before the battle resolves, the encounter simply re-arms.
@ Trigger placement: rows 6,7,10,11 are all collision-1 from x=54 to x=59, so
@ (54,8)/(54,9) is the only gateway between NEW BARK TOWN and the rest of the
@ route -- this pair cannot be walked around. Both converge on (54,8).
@ Battle BGM needs no scripting: TRAINER_CLASS_RIVAL with a name other than
@ WALLY resolves to MUS_VS_RIVAL (src/pokemon.c:6129-6133).
@ ============================================================================
Route29_EventScript_SilverSceneSouth::
	lockall
	applymovement LOCALID_PLAYER, Route29_Movement_PlayerStepNorth
	waitmovement 0
	goto Route29_EventScript_SilverScene
	end

Route29_EventScript_SilverSceneNorth::
	lockall
	goto Route29_EventScript_SilverScene
	end

@ Coord path: the player's tile is known to be (54,8), so SILVER can be walked
@ into position and walked back off afterwards.
Route29_EventScript_SilverScene::
	applymovement LOCALID_PLAYER, Route29_Movement_PlayerFaceWest
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_JOHTO_R29_SILVER, Route29_Movement_SilverBlocksTheRoad
	waitmovement 0
	call Route29_EventScript_SilverConfront
	applymovement LOCALID_JOHTO_R29_SILVER, Route29_Movement_SilverLeavesWest
	waitmovement 0
	removeobject LOCALID_JOHTO_R29_SILVER
	call Route29_EventScript_SilverAftermath
	releaseall
	end

@ Talk path. Only reachable if the player whites out mid-battle, respawns west
@ of here and walks up to SILVER from the CHERRYGROVE side instead of crossing
@ the gateway tiles again. The player's tile is therefore unknown, so this path
@ uses lock/faceplayer (works from any approach direction) and does NOT run any
@ movement script -- walking SILVER into or out of an unknown tile could deadlock
@ waitmovement.
Route29_EventScript_Silver::
	lock
	faceplayer
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
	call Route29_EventScript_SilverConfront
	removeobject LOCALID_JOHTO_R29_SILVER
	call Route29_EventScript_SilverAftermath
	release
	end

Route29_EventScript_SilverConfront::
	msgbox Route29_Text_SilverIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_SILVER_1, Route29_Text_SilverDefeat
	setflag FLAG_TRINITY_J_SILVER1_BEATEN
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
	msgbox Route29_Text_SilverNameReveal, MSGBOX_DEFAULT
	closemessage
	return

Route29_EventScript_SilverAftermath::
	setvar VAR_TRINITY_JOHTO_SCENE_NEWBARK, 3
	fadedefaultbgm
	special HealPlayerParty
	return

@ (54,9) -> (54,8): normalise onto SILVER's row.
Route29_Movement_PlayerStepNorth:
	walk_up
	step_end

Route29_Movement_PlayerFaceWest:
	face_left
	step_end

@ (52,8) -> (53,8): one step east, into the player's face at (54,8).
Route29_Movement_SilverBlocksTheRoad:
	walk_right
	face_right
	step_end

@ (53,8) -> (45,8): eight tiles west along the open corridor row, well past
@ the left edge of the viewport centred on the locked player at x=54.
Route29_Movement_SilverLeavesWest:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route29_EventScript_CatchingTutorialDude::
	msgbox Route29_Text_CatchingTutorialDude, MSGBOX_NPC
	end

Route29_EventScript_Youngster::
	msgbox Route29_Text_Youngster, MSGBOX_NPC
	end

Route29_EventScript_Teacher::
	msgbox Route29_Text_Teacher, MSGBOX_NPC
	end

Route29_EventScript_Fisher::
	msgbox Route29_Text_Fisher, MSGBOX_NPC
	end

Route29_EventScript_CooltrainerM::
	msgbox Route29_Text_CooltrainerM, MSGBOX_NPC
	end

Route29_EventScript_Sign1::
	msgbox Route29_Text_Sign1, MSGBOX_SIGN
	end

Route29_EventScript_Sign2::
	msgbox Route29_Text_Sign2, MSGBOX_SIGN
	end

Route29_Text_SilverIntro:
	.string "SILVER: ………\p"
	.string "You followed me.\p"
	.string "The CHAMPION of HOENN, running an\n"
	.string "errand for a man in a lab coat.\p"
	.string "You want it back? It was never\n"
	.string "his to begin with.\p"
	.string "A POKéMON belongs to whoever can\n"
	.string "actually use it.\p"
	.string "Let me show you what that means.$"

Route29_Text_SilverDefeat:
	.string "…Humph.$"

Route29_Text_SilverNameReveal:
	.string "SILVER: ………\p"
	.string "Fine. You're strong. I expected\n"
	.string "that much.\p"
	.string "My name is SILVER. Remember it,\n"
	.string "because you'll hear it at every\l"
	.string "GYM door you walk through.\p"
	.string "I'm going to be the strongest\n"
	.string "trainer in the world.\p"
	.string "And FERALIGATR stays with me.$"

Route29_Text_CatchingTutorialDude:
	.string "I've been wandering these routes\nfor years. Lately there's talk of\lnothing but the HOENN champion.$"

Route29_Text_Youngster:
	.string "Yo. How are your\nPOKéMON?\pIf they're weak\nand not ready for\pbattle, keep out\nof the grass.$"

Route29_Text_Teacher:
	.string "See those ledges?\nIt's scary to jump\loff them.\pBut you can go to\nNEW BARK without\pwalking through\nthe grass.$"

Route29_Text_Fisher:
	.string "I wanted to take a\nbreak, so I saved\pto record my\nprogress.$"

Route29_Text_CooltrainerM:
	.string "This route sure gets more foot\ntraffic now that HOENN trainers\lkeep showing up.$"

Route29_Text_Sign1:
	.string "ROUTE 29\pCHERRYGROVE CITY -\nNEW BARK TOWN$"

Route29_Text_Sign2:
	.string "ROUTE 29\pCHERRYGROVE CITY -\nNEW BARK TOWN$"
