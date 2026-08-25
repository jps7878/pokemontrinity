Route18_MapScripts::
	.byte 0

Route18_EventScript_Jacob::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_JACOB, Route18_Text_JacobSeen, Route18_Text_JacobBeaten
	msgbox Route18_Text_JacobBeaten, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Ramiro::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_RAMIRO, Route18_Text_RamiroSeen, Route18_Text_RamiroBeaten
	msgbox Route18_Text_RamiroBeaten, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Wilton::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_WILTON, Route18_Text_WiltonSeen, Route18_Text_WiltonBeaten
	msgbox Route18_Text_WiltonBeaten, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_CyclingRoadSign::
	msgbox Route18_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route18_EventScript_RouteSign::
	msgbox Route18_Text_RouteSign, MSGBOX_SIGN
	end

Route18_Text_JacobSeen:
	.string "…$"

Route18_Text_JacobBeaten:
	.string "…$"

Route18_Text_RamiroSeen:
	.string "…$"

Route18_Text_RamiroBeaten:
	.string "…$"

Route18_Text_WiltonSeen:
	.string "…$"

Route18_Text_WiltonBeaten:
	.string "…$"

Route18_Text_CyclingRoadSign:
	.string "CYCLING ROAD\nNo pedestrians permitted!$"

Route18_Text_RouteSign:
	.string "ROUTE 18\nCELADON CITY - FUCHSIA CITY$"
