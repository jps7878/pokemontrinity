Route24_MapScripts::
	.byte 0

Route24_EventScript_Rocket::
	msgbox Route24_Text_Rocket, MSGBOX_NPC
	end

Route24_EventScript_Ethan::
	trainerbattle_single TRAINER_KANTO_CAMPER_ETHAN, Route24_Text_EthanSeen, Route24_Text_EthanBeaten
	msgbox Route24_Text_EthanBeaten, MSGBOX_AUTOCLOSE
	end

Route24_EventScript_Reli::
	trainerbattle_single TRAINER_KANTO_LASS_RELI, Route24_Text_ReliSeen, Route24_Text_ReliBeaten
	msgbox Route24_Text_ReliBeaten, MSGBOX_AUTOCLOSE
	end

Route24_EventScript_Timmy::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_TIMMY, Route24_Text_TimmySeen, Route24_Text_TimmyBeaten
	msgbox Route24_Text_TimmyBeaten, MSGBOX_AUTOCLOSE
	end

Route24_EventScript_Ali::
	trainerbattle_single TRAINER_KANTO_LASS_ALI, Route24_Text_AliSeen, Route24_Text_AliBeaten
	msgbox Route24_Text_AliBeaten, MSGBOX_AUTOCLOSE
	end

Route24_EventScript_Cale::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_CALE, Route24_Text_CaleSeen, Route24_Text_CaleBeaten
	msgbox Route24_Text_CaleBeaten, MSGBOX_AUTOCLOSE
	end

Route24_EventScript_Shane::
	trainerbattle_single TRAINER_KANTO_CAMPER_SHANE, Route24_Text_ShaneSeen, Route24_Text_ShaneBeaten
	msgbox Route24_Text_ShaneBeaten, MSGBOX_AUTOCLOSE
	end

Route24_Text_Rocket:
	.string "They say a trainer beat both the\nHOENN and JOHTO Leagues. Wonder\lif they'll try KANTO next.$"

Route24_Text_EthanSeen:
	.string "…$"

Route24_Text_EthanBeaten:
	.string "…$"

Route24_Text_ReliSeen:
	.string "…$"

Route24_Text_ReliBeaten:
	.string "…$"

Route24_Text_TimmySeen:
	.string "…$"

Route24_Text_TimmyBeaten:
	.string "…$"

Route24_Text_AliSeen:
	.string "…$"

Route24_Text_AliBeaten:
	.string "…$"

Route24_Text_CaleSeen:
	.string "…$"

Route24_Text_CaleBeaten:
	.string "…$"

Route24_Text_ShaneSeen:
	.string "…$"

Route24_Text_ShaneBeaten:
	.string "…$"
