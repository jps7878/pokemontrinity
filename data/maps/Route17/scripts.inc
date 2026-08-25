Route17_MapScripts::
	.byte 0

Route17_EventScript_Virgil::
	trainerbattle_single TRAINER_KANTO_BIKER_VIRGIL, Route17_Text_VirgilSeen, Route17_Text_VirgilBeaten
	msgbox Route17_Text_VirgilBeaten, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Isaiah::
	trainerbattle_single TRAINER_KANTO_CUE_BALL_ISAIAH, Route17_Text_IsaiahSeen, Route17_Text_IsaiahBeaten
	msgbox Route17_Text_IsaiahBeaten, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Raul::
	trainerbattle_single TRAINER_KANTO_CUE_BALL_RAUL, Route17_Text_RaulSeen, Route17_Text_RaulBeaten
	msgbox Route17_Text_RaulBeaten, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Nikolas::
	trainerbattle_single TRAINER_KANTO_BIKER_NIKOLAS, Route17_Text_NikolasSeen, Route17_Text_NikolasBeaten
	msgbox Route17_Text_NikolasBeaten, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Billy::
	trainerbattle_single TRAINER_KANTO_BIKER_BILLY, Route17_Text_BillySeen, Route17_Text_BillyBeaten
	msgbox Route17_Text_BillyBeaten, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Jamal::
	trainerbattle_single TRAINER_KANTO_CUE_BALL_JAMAL, Route17_Text_JamalSeen, Route17_Text_JamalBeaten
	msgbox Route17_Text_JamalBeaten, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Zeek::
	trainerbattle_single TRAINER_KANTO_CUE_BALL_ZEEK, Route17_Text_ZeekSeen, Route17_Text_ZeekBeaten
	msgbox Route17_Text_ZeekBeaten, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Corey::
	trainerbattle_single TRAINER_KANTO_CUE_BALL_COREY, Route17_Text_CoreySeen, Route17_Text_CoreyBeaten
	msgbox Route17_Text_CoreyBeaten, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_William::
	trainerbattle_single TRAINER_KANTO_BIKER_WILLIAM, Route17_Text_WilliamSeen, Route17_Text_WilliamBeaten
	msgbox Route17_Text_WilliamBeaten, MSGBOX_AUTOCLOSE
	end

Route17_EventScript_Jaxon::
	trainerbattle_single TRAINER_KANTO_BIKER_JAXON, Route17_Text_JaxonSeen, Route17_Text_JaxonBeaten
	msgbox Route17_Text_JaxonBeaten, MSGBOX_AUTOCLOSE
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
	.string "…$"

Route17_Text_VirgilBeaten:
	.string "…$"

Route17_Text_IsaiahSeen:
	.string "…$"

Route17_Text_IsaiahBeaten:
	.string "…$"

Route17_Text_RaulSeen:
	.string "…$"

Route17_Text_RaulBeaten:
	.string "…$"

Route17_Text_NikolasSeen:
	.string "…$"

Route17_Text_NikolasBeaten:
	.string "…$"

Route17_Text_BillySeen:
	.string "…$"

Route17_Text_BillyBeaten:
	.string "…$"

Route17_Text_JamalSeen:
	.string "…$"

Route17_Text_JamalBeaten:
	.string "…$"

Route17_Text_ZeekSeen:
	.string "…$"

Route17_Text_ZeekBeaten:
	.string "…$"

Route17_Text_CoreySeen:
	.string "…$"

Route17_Text_CoreyBeaten:
	.string "…$"

Route17_Text_WilliamSeen:
	.string "…$"

Route17_Text_WilliamBeaten:
	.string "…$"

Route17_Text_JaxonSeen:
	.string "…$"

Route17_Text_JaxonBeaten:
	.string "…$"

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
