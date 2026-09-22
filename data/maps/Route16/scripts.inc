@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

Route16_MapScripts::
	.byte 0

Route16_EventScript_Lao::
	trainerbattle_single TRAINER_KANTO_BIKER_LAO, Route16_Text_LaoSeen, Route16_Text_LaoBeaten
	msgbox Route16_Text_LaoPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_EventScript_Koji::
	trainerbattle_single TRAINER_KANTO_CUE_BALL_KOJI, Route16_Text_KojiSeen, Route16_Text_KojiBeaten
	msgbox Route16_Text_KojiPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_EventScript_Luke::
	trainerbattle_single TRAINER_KANTO_CUE_BALL_LUKE, Route16_Text_LukeSeen, Route16_Text_LukeBeaten
	msgbox Route16_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

Route16_EventScript_Ruben::
	trainerbattle_single TRAINER_KANTO_BIKER_RUBEN, Route16_Text_RubenSeen, Route16_Text_RubenBeaten
	msgbox Route16_Text_RubenPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_EventScript_Hideo::
	trainerbattle_single TRAINER_KANTO_BIKER_HIDEO, Route16_Text_HideoSeen, Route16_Text_HideoBeaten
	msgbox Route16_Text_HideoPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_EventScript_Camron::
	trainerbattle_single TRAINER_KANTO_CUE_BALL_CAMRON, Route16_Text_CamronSeen, Route16_Text_CamronBeaten
	msgbox Route16_Text_CamronPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_EventScript_Lea::
	trainerbattle_single TRAINER_KANTO_YOUNG_COUPLE_LEA_JED, Route16_Text_LeaSeen, Route16_Text_LeaBeaten
	msgbox Route16_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_EventScript_Jed::
	trainerbattle_single TRAINER_KANTO_YOUNG_COUPLE_LEA_JED_2, Route16_Text_JedSeen, Route16_Text_JedBeaten
	msgbox Route16_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_EventScript_RouteSign::
	msgbox Route16_Text_RouteSign, MSGBOX_SIGN
	end

Route16_EventScript_CyclingRoadSign::
	msgbox Route16_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route16_Text_LaoSeen:
	.string "What do you want?$"

Route16_Text_LaoBeaten:
	.string "Don't you dare laugh!$"

Route16_Text_LaoPostBattle:
	.string "We like just hanging here.\nWhat's it to you?$"

Route16_Text_KojiSeen:
	.string "Nice BIKE!\nHand it over!$"

Route16_Text_KojiBeaten:
	.string "Knockout!$"

Route16_Text_KojiPostBattle:
	.string "Forget it, who needs your BIKE!$"

Route16_Text_LukeSeen:
	.string "Come out and play, little mouse!$"

Route16_Text_LukeBeaten:
	.string "You little rat!$"

Route16_Text_LukePostBattle:
	.string "I hate losing!\nGet out of my face!$"

Route16_Text_RubenSeen:
	.string "Hey, there!\nLet's have ourselves a good time!$"

Route16_Text_RubenBeaten:
	.string "Don't make me mad!$"

Route16_Text_RubenPostBattle:
	.string "I get my kicks by harassing people\nwith my stinking POKéMON.\pThey're great for startling people.\nAnd, they bite, too.$"

Route16_Text_HideoSeen:
	.string "Hey, you just bumped me!$"

Route16_Text_HideoBeaten:
	.string "Kaboom!$"

Route16_Text_HideoPostBattle:
	.string "We'll always be hanging around here\neven if you don't like it.\pYou can detour to VERMILION from\nFUCHSIA going along the coast.$"

Route16_Text_CamronSeen:
	.string "I'm feeling hungry and mean!\nI need a punching bag!$"

Route16_Text_CamronBeaten:
	.string "Bad, bad, bad!$"

Route16_Text_CamronPostBattle:
	.string "If I'm going to have POKéMON, they\nmay as well be ferocious.\pI'd use them to leave my enemies\nin tatters.$"

Route16_Text_LeaSeen:
	.string "LEA: Sometimes, the intensity of\nour love scares me.$"

Route16_Text_LeaBeaten:
	.string "LEA: Ohh! But JED looks cool\neven in a loss!$"

Route16_Text_LeaPostBattle:
	.string "LEA: Ehehe, I'm sorry.\nJED is so cool.$"

Route16_Text_JedSeen:
	.string "JED: Our love knows no bounds.\nWe're in love and we show it!$"

Route16_Text_JedBeaten:
	.string "JED: Oh, no!\nMy love has seen me as a loser!$"

Route16_Text_JedPostBattle:
	.string "JED: Listen, LEA.\nYou need to focus less on me.$"

Route16_Text_RouteSign:
	.string "ROUTE 16\nCELADON CITY - FUCHSIA CITY$"

Route16_Text_CyclingRoadSign:
	.string "Enjoy the slope!\nCYCLING ROAD$"
