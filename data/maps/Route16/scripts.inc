Route16_MapScripts::
	.byte 0

Route16_EventScript_Lao::
	trainerbattle_single TRAINER_KANTO_BIKER_LAO, Route16_Text_LaoSeen, Route16_Text_LaoBeaten
	msgbox Route16_Text_LaoBeaten, MSGBOX_AUTOCLOSE
	end

Route16_EventScript_Koji::
	trainerbattle_single TRAINER_KANTO_CUE_BALL_KOJI, Route16_Text_KojiSeen, Route16_Text_KojiBeaten
	msgbox Route16_Text_KojiBeaten, MSGBOX_AUTOCLOSE
	end

Route16_EventScript_Luke::
	trainerbattle_single TRAINER_KANTO_CUE_BALL_LUKE, Route16_Text_LukeSeen, Route16_Text_LukeBeaten
	msgbox Route16_Text_LukeBeaten, MSGBOX_AUTOCLOSE
	end

Route16_EventScript_Ruben::
	trainerbattle_single TRAINER_KANTO_BIKER_RUBEN, Route16_Text_RubenSeen, Route16_Text_RubenBeaten
	msgbox Route16_Text_RubenBeaten, MSGBOX_AUTOCLOSE
	end

Route16_EventScript_Hideo::
	trainerbattle_single TRAINER_KANTO_BIKER_HIDEO, Route16_Text_HideoSeen, Route16_Text_HideoBeaten
	msgbox Route16_Text_HideoBeaten, MSGBOX_AUTOCLOSE
	end

Route16_EventScript_Camron::
	trainerbattle_single TRAINER_KANTO_CUE_BALL_CAMRON, Route16_Text_CamronSeen, Route16_Text_CamronBeaten
	msgbox Route16_Text_CamronBeaten, MSGBOX_AUTOCLOSE
	end

Route16_EventScript_Lea::
	trainerbattle_single TRAINER_KANTO_YOUNG_COUPLE_LEA_JED, Route16_Text_LeaSeen, Route16_Text_LeaBeaten
	msgbox Route16_Text_LeaBeaten, MSGBOX_AUTOCLOSE
	end

Route16_EventScript_Jed::
	trainerbattle_single TRAINER_KANTO_YOUNG_COUPLE_LEA_JED_2, Route16_Text_JedSeen, Route16_Text_JedBeaten
	msgbox Route16_Text_JedBeaten, MSGBOX_AUTOCLOSE
	end

Route16_EventScript_RouteSign::
	msgbox Route16_Text_RouteSign, MSGBOX_SIGN
	end

Route16_EventScript_CyclingRoadSign::
	msgbox Route16_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route16_Text_LaoSeen:
	.string "…$"

Route16_Text_LaoBeaten:
	.string "…$"

Route16_Text_KojiSeen:
	.string "…$"

Route16_Text_KojiBeaten:
	.string "…$"

Route16_Text_LukeSeen:
	.string "…$"

Route16_Text_LukeBeaten:
	.string "…$"

Route16_Text_RubenSeen:
	.string "…$"

Route16_Text_RubenBeaten:
	.string "…$"

Route16_Text_HideoSeen:
	.string "…$"

Route16_Text_HideoBeaten:
	.string "…$"

Route16_Text_CamronSeen:
	.string "…$"

Route16_Text_CamronBeaten:
	.string "…$"

Route16_Text_LeaSeen:
	.string "…$"

Route16_Text_LeaBeaten:
	.string "…$"

Route16_Text_JedSeen:
	.string "…$"

Route16_Text_JedBeaten:
	.string "…$"

Route16_Text_RouteSign:
	.string "ROUTE 16\nCELADON CITY - FUCHSIA CITY$"

Route16_Text_CyclingRoadSign:
	.string "Enjoy the slope!\nCYCLING ROAD$"
