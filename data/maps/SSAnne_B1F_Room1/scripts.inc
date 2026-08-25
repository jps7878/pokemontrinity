SSAnne_B1F_Room1_MapScripts::
	.byte 0

SSAnne_B1F_Room1_EventScript_Barny::
	trainerbattle_single TRAINER_KANTO_FISHERMAN_BARNY, SSAnne_B1F_Room1_Text_BarnySeen, SSAnne_B1F_Room1_Text_BarnyBeaten
	msgbox SSAnne_B1F_Room1_Text_BarnyBeaten, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_EventScript_Phillip::
	trainerbattle_single TRAINER_KANTO_SAILOR_PHILLIP, SSAnne_B1F_Room1_Text_PhillipSeen, SSAnne_B1F_Room1_Text_PhillipBeaten
	msgbox SSAnne_B1F_Room1_Text_PhillipBeaten, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_Text_BarnySeen:
	.string "…$"

SSAnne_B1F_Room1_Text_BarnyBeaten:
	.string "…$"

SSAnne_B1F_Room1_Text_PhillipSeen:
	.string "…$"

SSAnne_B1F_Room1_Text_PhillipBeaten:
	.string "…$"
