SSAnne_2F_Room4_MapScripts::
	.byte 0

SSAnne_2F_Room4_EventScript_Lamar::
	trainerbattle_single TRAINER_KANTO_GENTLEMAN_LAMAR, SSAnne_2F_Room4_Text_LamarSeen, SSAnne_2F_Room4_Text_LamarBeaten
	msgbox SSAnne_2F_Room4_Text_LamarBeaten, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room4_EventScript_Dawn::
	trainerbattle_single TRAINER_KANTO_LASS_DAWN, SSAnne_2F_Room4_Text_DawnSeen, SSAnne_2F_Room4_Text_DawnBeaten
	msgbox SSAnne_2F_Room4_Text_DawnBeaten, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room4_Text_LamarSeen:
	.string "…$"

SSAnne_2F_Room4_Text_LamarBeaten:
	.string "…$"

SSAnne_2F_Room4_Text_DawnSeen:
	.string "…$"

SSAnne_2F_Room4_Text_DawnBeaten:
	.string "…$"
