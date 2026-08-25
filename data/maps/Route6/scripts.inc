Route6_MapScripts::
	.byte 0

Route6_EventScript_Keigo::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_KEIGO, Route6_Text_KeigoSeen, Route6_Text_KeigoBeaten
	msgbox Route6_Text_KeigoBeaten, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Ricky::
	trainerbattle_single TRAINER_KANTO_CAMPER_RICKY, Route6_Text_RickySeen, Route6_Text_RickyBeaten
	msgbox Route6_Text_RickyBeaten, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Nancy::
	trainerbattle_single TRAINER_KANTO_PICNICKER_NANCY, Route6_Text_NancySeen, Route6_Text_NancyBeaten
	msgbox Route6_Text_NancyBeaten, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Elijah::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_ELIJAH, Route6_Text_ElijahSeen, Route6_Text_ElijahBeaten
	msgbox Route6_Text_ElijahBeaten, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Isabelle::
	trainerbattle_single TRAINER_KANTO_PICNICKER_ISABELLE, Route6_Text_IsabelleSeen, Route6_Text_IsabelleBeaten
	msgbox Route6_Text_IsabelleBeaten, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Jeff::
	trainerbattle_single TRAINER_KANTO_CAMPER_JEFF, Route6_Text_JeffSeen, Route6_Text_JeffBeaten
	msgbox Route6_Text_JeffBeaten, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_UndergroundPathSign::
	msgbox Route6_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route6_Text_KeigoSeen:
	.string "…$"

Route6_Text_KeigoBeaten:
	.string "…$"

Route6_Text_RickySeen:
	.string "…$"

Route6_Text_RickyBeaten:
	.string "…$"

Route6_Text_NancySeen:
	.string "…$"

Route6_Text_NancyBeaten:
	.string "…$"

Route6_Text_ElijahSeen:
	.string "…$"

Route6_Text_ElijahBeaten:
	.string "…$"

Route6_Text_IsabelleSeen:
	.string "…$"

Route6_Text_IsabelleBeaten:
	.string "…$"

Route6_Text_JeffSeen:
	.string "…$"

Route6_Text_JeffBeaten:
	.string "…$"

Route6_Text_UndergroundPathSign:
	.string "UNDERGROUND PATH\nCERULEAN CITY - VERMILION CITY$"
