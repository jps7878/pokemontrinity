SSAnne_1F_Room7_MapScripts::
	.byte 0

SSAnne_1F_Room7_EventScript_Thomas::
	trainerbattle_single TRAINER_KANTO_GENTLEMAN_THOMAS, SSAnne_1F_Room7_Text_ThomasSeen, SSAnne_1F_Room7_Text_ThomasBeaten
	msgbox SSAnne_1F_Room7_Text_ThomasBeaten, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room7_Text_ThomasSeen:
	.string "…$"

SSAnne_1F_Room7_Text_ThomasBeaten:
	.string "…$"
