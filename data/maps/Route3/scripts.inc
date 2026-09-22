@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

Route3_MapScripts::
	.byte 0

Route3_EventScript_Youngster::
	msgbox Route3_Text_Youngster, MSGBOX_NPC
	end

Route3_EventScript_Robin::
	trainerbattle_single TRAINER_KANTO_LASS_ROBIN, Route3_Text_RobinSeen, Route3_Text_RobinBeaten
	msgbox Route3_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_James::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_JAMES, Route3_Text_JamesSeen, Route3_Text_JamesBeaten
	msgbox Route3_Text_JamesPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Sally::
	trainerbattle_single TRAINER_KANTO_LASS_SALLY, Route3_Text_SallySeen, Route3_Text_SallyBeaten
	msgbox Route3_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Greg::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_GREG, Route3_Text_GregSeen, Route3_Text_GregBeaten
	msgbox Route3_Text_GregPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Calvin::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_CALVIN, Route3_Text_CalvinSeen, Route3_Text_CalvinBeaten
	msgbox Route3_Text_CalvinPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Janice::
	trainerbattle_single TRAINER_KANTO_LASS_JANICE, Route3_Text_JaniceSeen, Route3_Text_JaniceBeaten
	msgbox Route3_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Colton::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_COLTON, Route3_Text_ColtonSeen, Route3_Text_ColtonBeaten
	msgbox Route3_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Ben::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_BEN, Route3_Text_BenSeen, Route3_Text_BenBeaten
	msgbox Route3_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_RouteSign::
	msgbox Route3_Text_RouteSign, MSGBOX_SIGN
	end

Route3_Text_Youngster:
	.string "Whew… I better take a rest…\nGroan…\pThat tunnel from CERULEAN takes a\nlot out of you!$"

Route3_Text_RobinSeen:
	.string "Eek!\nDid you touch me?$"

Route3_Text_RobinBeaten:
	.string "That's it?$"

Route3_Text_RobinPostBattle:
	.string "ROUTE 4 is at the foot of\nMT. MOON.$"

Route3_Text_JamesSeen:
	.string "I'll battle you with the POKéMON\nI just caught.$"

Route3_Text_JamesBeaten:
	.string "Done like dinner!$"

Route3_Text_JamesPostBattle:
	.string "Trained POKéMON are stronger than\nthe wild ones.$"

Route3_Text_SallySeen:
	.string "That look you gave me…\nIt's so intriguing!$"

Route3_Text_SallyBeaten:
	.string "Be nice!$"

Route3_Text_SallyPostBattle:
	.string "You can avoid battles by not\nletting TRAINERS see you.$"

Route3_Text_GregSeen:
	.string "Are you a TRAINER?\nLet's get with it right away!$"

Route3_Text_GregBeaten:
	.string "If I had new POKéMON, I would've\nwon!$"

Route3_Text_GregPostBattle:
	.string "If a POKéMON BOX on the PC gets\nfull, just switch to another BOX.$"

Route3_Text_CalvinSeen:
	.string "Hey! You're not wearing shorts!\nWhat's wrong with you?$"

Route3_Text_CalvinBeaten:
	.string "Lost!\nLost! Lost!$"

Route3_Text_CalvinPostBattle:
	.string "I always wear shorts, even in\nwinter. That's my policy.$"

Route3_Text_JaniceSeen:
	.string "Excuse me!\nYou looked at me, didn't you?$"

Route3_Text_JaniceBeaten:
	.string "You're mean!$"

Route3_Text_JanicePostBattle:
	.string "You shouldn't be staring if you\ndon't want to battle!$"

Route3_Text_ColtonSeen:
	.string "Hey!\nI saw you in VIRIDIAN FOREST!$"

Route3_Text_ColtonBeaten:
	.string "You beat me again!$"

Route3_Text_ColtonPostBattle:
	.string "There are other kinds of POKéMON\nthan the ones you find in forests.$"

Route3_Text_BenSeen:
	.string "Hi!\nI like shorts!\pThey're delightfully comfy and\neasy to wear!$"

Route3_Text_BenBeaten:
	.string "I don't believe it!$"

Route3_Text_BenPostBattle:
	.string "Are you using a POKéMON CENTER's\nPC for storing your POKéMON?\pEach BOX can hold up to\n30 POKéMON.$"

Route3_Text_RouteSign:
	.string "ROUTE 3\nMT. MOON AHEAD$"
