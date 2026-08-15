NewBarkTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_OnTransition
	.byte 0

@ Trinity M4b S1. SILVER lurks in the alcove north-west of ELM'S LAB only
@ before the player has met PROF.ELM (scene 0). ON_TRANSITION runs before
@ TrySpawnObjectEvents (src/overworld.c:876/945) so the hide flag is authored
@ here rather than relying on a new-game default.
NewBarkTown_OnTransition:
	goto_if_eq VAR_TRINITY_JOHTO_SCENE_NEWBARK, 0, NewBarkTown_EventScript_ShowSilver
	setflag FLAG_TRINITY_J_SILVER_NEWBARK_HIDE
	end

NewBarkTown_EventScript_ShowSilver::
	clearflag FLAG_TRINITY_J_SILVER_NEWBARK_HIDE
	end

@ Scene A -- "What are you staring at?"
@ Adapts pokecrystal NewBarkTownRivalScript (NewBarkTown.asm:107-126): two
@ texts, he turns, he shoves you. Retargeted at a Champion instead of a kid
@ holding a new starter. SILVER rests on (3,2), a dead-end alcove tile: the
@ alcove's through-path is (2,2)->(2,3)->(2,4) and he never stands on it, so
@ nothing is sealed. (3,3) is the ELM'S LAB sign wall.
NewBarkTown_EventScript_Silver::
	lock
	msgbox NewBarkTown_Text_SilverStare, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
	turnobject LOCALID_JOHTO_NEWBARK_SILVER, DIR_WEST
	msgbox NewBarkTown_Text_SilverMove, MSGBOX_DEFAULT
	closemessage
	playse SE_MUD_BALL
	applymovement LOCALID_PLAYER, NewBarkTown_Movement_ShovedBack
	waitmovement 0
	turnobject LOCALID_JOHTO_NEWBARK_SILVER, DIR_EAST
	fadedefaultbgm
	release
	end

@ GSC's NewBarkTown_RivalShovesYouOutMovement: facing pinned north while the
@ player is knocked one tile back. (2,2) -> (2,3), both decoded walkable.
NewBarkTown_Movement_ShovedBack:
	lock_facing_direction
	jump_down
	unlock_facing_direction
	step_end

NewBarkTown_EventScript_Teacher::
	msgbox NewBarkTown_Text_Teacher, MSGBOX_NPC
	end

NewBarkTown_EventScript_Fisher::
	msgbox NewBarkTown_Text_Fisher, MSGBOX_NPC
	end

NewBarkTown_EventScript_Sign::
	msgbox NewBarkTown_Text_Sign, MSGBOX_SIGN
	end

NewBarkTown_EventScript_PlayersHouseSign::
	msgbox NewBarkTown_Text_PlayersHouseSign, MSGBOX_SIGN
	end

NewBarkTown_EventScript_ElmsLabSign::
	msgbox NewBarkTown_Text_ElmsLabSign, MSGBOX_SIGN
	end

NewBarkTown_EventScript_ElmsHouseSign::
	msgbox NewBarkTown_Text_ElmsHouseSign, MSGBOX_SIGN
	end

NewBarkTown_Text_Teacher:
	.string "Did you hear? A HOENN trainer\nbecame Champion, and now folks\lhere want to challenge them.$"

NewBarkTown_Text_Fisher:
	.string "Yo, {PLAYER}!\pI hear PROF.ELM\ndiscovered some\lnew POKéMON.$"

NewBarkTown_Text_Sign:
	.string "NEW BARK TOWN\pThe Town Where the\nWinds of a New\lBeginning Blow$"

@ Trinity M4b S1: retargeted from the ported "<PLAYER>'s House". The player
@ lives in LITTLEROOT TOWN, HOENN -- this is an ordinary NEW BARK home.
NewBarkTown_Text_PlayersHouseSign:
	.string "A NEW BARK HOME$"

NewBarkTown_Text_SilverStare:
	.string "………\p"
	.string "So this is the famous ELM POKéMON\n"
	.string "LAB.\p"
	.string "They say the HOENN CHAMPION is\n"
	.string "coming here. To be studied.\p"
	.string "Like a specimen.$"

NewBarkTown_Text_SilverMove:
	.string "…What are you staring at?\p"
	.string "So you're the CHAMPION.\n"
	.string "A trophy in a jacket.\p"
	.string "Strength like that shouldn't\n"
	.string "belong to someone who takes\l"
	.string "orders from a man in a lab coat.\p"
	.string "Move.$"

NewBarkTown_Text_ElmsLabSign:
	.string "ELM POKéMON LAB$"

NewBarkTown_Text_ElmsHouseSign:
	.string "ELM'S HOUSE$"
