SSAnne_2F_Room2_MapScripts::
	.byte 0

SSAnne_2F_Room2_EventScript_Dale::
	trainerbattle_single TRAINER_KANTO_FISHERMAN_DALE, SSAnne_2F_Room2_Text_DaleSeen, SSAnne_2F_Room2_Text_DaleBeaten
	msgbox SSAnne_2F_Room2_Text_DaleBeaten, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room2_EventScript_Brooks::
	trainerbattle_single TRAINER_KANTO_GENTLEMAN_BROOKS, SSAnne_2F_Room2_Text_BrooksSeen, SSAnne_2F_Room2_Text_BrooksBeaten
	msgbox SSAnne_2F_Room2_Text_BrooksBeaten, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room2_Text_DaleSeen:
	.string "…$"

SSAnne_2F_Room2_Text_DaleBeaten:
	.string "…$"

SSAnne_2F_Room2_Text_BrooksSeen:
	.string "…$"

SSAnne_2F_Room2_Text_BrooksBeaten:
	.string "…$"
