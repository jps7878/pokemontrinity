SSAnne_B1F_Room2_MapScripts::
	.byte 0

SSAnne_B1F_Room2_EventScript_Huey::
	trainerbattle_single TRAINER_KANTO_SAILOR_HUEY, SSAnne_B1F_Room2_Text_HueySeen, SSAnne_B1F_Room2_Text_HueyBeaten
	msgbox SSAnne_B1F_Room2_Text_HueyBeaten, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room2_Text_HueySeen:
	.string "…$"

SSAnne_B1F_Room2_Text_HueyBeaten:
	.string "…$"
