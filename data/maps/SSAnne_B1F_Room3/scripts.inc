SSAnne_B1F_Room3_MapScripts::
	.byte 0

SSAnne_B1F_Room3_EventScript_Dylan::
	trainerbattle_single TRAINER_KANTO_SAILOR_DYLAN, SSAnne_B1F_Room3_Text_DylanSeen, SSAnne_B1F_Room3_Text_DylanBeaten
	msgbox SSAnne_B1F_Room3_Text_DylanBeaten, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room3_Text_DylanSeen:
	.string "…$"

SSAnne_B1F_Room3_Text_DylanBeaten:
	.string "…$"
