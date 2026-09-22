@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

Route17_MapScripts::
	.byte 0

Route17_EventScript_Virgil::
	trainerbattle_single TRAINER_KANTO_BIKER_VIRGIL, Route17_Text_VirgilSeen, Route17_Text_VirgilBeaten
	msgbox Route17_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Isaiah::
	trainerbattle_single TRAINER_KANTO_CUE_BALL_ISAIAH, Route17_Text_IsaiahSeen, Route17_Text_IsaiahBeaten
	msgbox Route17_Text_IsaiahPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Raul::
	trainerbattle_single TRAINER_KANTO_CUE_BALL_RAUL, Route17_Text_RaulSeen, Route17_Text_RaulBeaten
	msgbox Route17_Text_RaulPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Nikolas::
	trainerbattle_single TRAINER_KANTO_BIKER_NIKOLAS, Route17_Text_NikolasSeen, Route17_Text_NikolasBeaten
	msgbox Route17_Text_NikolasPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Billy::
	trainerbattle_single TRAINER_KANTO_BIKER_BILLY, Route17_Text_BillySeen, Route17_Text_BillyBeaten
	msgbox Route17_Text_BillyPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Jamal::
	trainerbattle_single TRAINER_KANTO_CUE_BALL_JAMAL, Route17_Text_JamalSeen, Route17_Text_JamalBeaten
	msgbox Route17_Text_JamalPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Zeek::
	trainerbattle_single TRAINER_KANTO_CUE_BALL_ZEEK, Route17_Text_ZeekSeen, Route17_Text_ZeekBeaten
	msgbox Route17_Text_ZeekPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Corey::
	trainerbattle_single TRAINER_KANTO_CUE_BALL_COREY, Route17_Text_CoreySeen, Route17_Text_CoreyBeaten
	msgbox Route17_Text_CoreyPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_William::
	trainerbattle_single TRAINER_KANTO_BIKER_WILLIAM, Route17_Text_WilliamSeen, Route17_Text_WilliamBeaten
	msgbox Route17_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Jaxon::
	trainerbattle_single TRAINER_KANTO_BIKER_JAXON, Route17_Text_JaxonSeen, Route17_Text_JaxonBeaten
	msgbox Route17_Text_JaxonPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_RouteSign::
	msgbox Route17_Text_RouteSign, MSGBOX_SIGN
	end

Route17_EventScript_TrainerTips2::
	msgbox Route17_Text_TrainerTips2, MSGBOX_SIGN
	end

Route17_EventScript_TrainerTips1::
	msgbox Route17_Text_TrainerTips1, MSGBOX_SIGN
	end

Route17_EventScript_ItemsNotice::
	msgbox Route17_Text_ItemsNotice, MSGBOX_SIGN
	end

Route17_EventScript_BallsNotice::
	msgbox Route17_Text_BallsNotice, MSGBOX_SIGN
	end

Route17_EventScript_CyclingRoadSign::
	msgbox Route17_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route17_Text_VirgilSeen:
	.string "You heading to FUCHSIA?$"

Route17_Text_VirgilBeaten:
	.string "Crash and burn!$"

Route17_Text_VirgilPostBattle:
	.string "I love racing downhill!$"

Route17_Text_IsaiahSeen:
	.string "I'm mighty proud of my bod, kiddo.\nCome on!$"

Route17_Text_IsaiahBeaten:
	.string "Whoo!$"

Route17_Text_IsaiahPostBattle:
	.string "I could belly-bump you outta\nhere!$"

Route17_Text_RaulSeen:
	.string "There's no getting rich quick in\nbattling kids.$"

Route17_Text_RaulBeaten:
	.string "Burned out!$"

Route17_Text_RaulPostBattle:
	.string "You can find good stuff lying\naround on CYCLING ROAD.\pThere's good money in picking them\nup and selling them.$"

Route17_Text_NikolasSeen:
	.string "Let VOLTORB electrify you!$"

Route17_Text_NikolasBeaten:
	.string "Grounded out!$"

Route17_Text_NikolasPostBattle:
	.string "I got my VOLTORB at the abandoned\nPOWER PLANT.$"

Route17_Text_BillySeen:
	.string "We're BIKERS!\nWe rule the roads, man!$"

Route17_Text_BillyBeaten:
	.string "Smoked!$"

Route17_Text_BillyPostBattle:
	.string "Are you looking for adventure?$"

Route17_Text_JamalSeen:
	.string "I need a little exercise!$"

Route17_Text_JamalBeaten:
	.string "Whew!\nGood workout!$"

Route17_Text_JamalPostBattle:
	.string "I'm sure I lost weight there!$"

Route17_Text_ZeekSeen:
	.string "I leveled up my POKéMON, but it\nwon't evolve. Why?$"

Route17_Text_ZeekBeaten:
	.string "Why, you!$"

Route17_Text_ZeekPostBattle:
	.string "Maybe some POKéMON need element\nSTONES to evolve.$"

Route17_Text_CoreySeen:
	.string "Be a rebel!$"

Route17_Text_CoreyBeaten:
	.string "Aaaargh!$"

Route17_Text_CoreyPostBattle:
	.string "Be ready to fight for your beliefs!$"

Route17_Text_WilliamSeen:
	.string "Get lost, kid!\nI'm bushed!$"

Route17_Text_WilliamBeaten:
	.string "Are you satisfied?$"

Route17_Text_WilliamPostBattle:
	.string "I need to catch a few z's!$"

Route17_Text_JaxonSeen:
	.string "Nice BIKE!\nHow's it handle?$"

Route17_Text_JaxonBeaten:
	.string "Shoot!$"

Route17_Text_JaxonPostBattle:
	.string "The slope makes it hard to steer.$"

Route17_Text_RouteSign:
	.string "ROUTE 17\nCELADON CITY - FUCHSIA CITY$"

Route17_Text_TrainerTips2:
	.string "TRAINER TIPS\pPress the B Button to stay in place\nwhile on a slope.$"

Route17_Text_TrainerTips1:
	.string "TRAINER TIPS\pAll POKéMON are unique.\pEven POKéMON of the same species\nand level grow at different rates.$"

Route17_Text_ItemsNotice:
	.string "It's a notice.\pWatch out for discarded items.$"

Route17_Text_BallsNotice:
	.string "It's a notice!\pDon't throw the game, throw POKé\nBALLS instead!$"

Route17_Text_CyclingRoadSign:
	.string "CYCLING ROAD\nSlope ends here!$"
