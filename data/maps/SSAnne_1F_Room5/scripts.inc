SSAnne_1F_Room5_MapScripts::
	.byte 0

SSAnne_1F_Room5_EventScript_Arthur::
	trainerbattle_single TRAINER_KANTO_GENTLEMAN_ARTHUR, SSAnne_1F_Room5_Text_ArthurSeen, SSAnne_1F_Room5_Text_ArthurBeaten
	msgbox SSAnne_1F_Room5_Text_ArthurBeaten, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room5_Text_ArthurSeen:
	.string "…$"

SSAnne_1F_Room5_Text_ArthurBeaten:
	.string "…$"
