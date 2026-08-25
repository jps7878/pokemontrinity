SSAnne_1F_Room2_MapScripts::
	.byte 0

SSAnne_1F_Room2_EventScript_Ann::
	trainerbattle_single TRAINER_KANTO_LASS_ANN, SSAnne_1F_Room2_Text_AnnSeen, SSAnne_1F_Room2_Text_AnnBeaten
	msgbox SSAnne_1F_Room2_Text_AnnBeaten, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_EventScript_Tyler::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_TYLER, SSAnne_1F_Room2_Text_TylerSeen, SSAnne_1F_Room2_Text_TylerBeaten
	msgbox SSAnne_1F_Room2_Text_TylerBeaten, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_EventScript_Woman::
	msgbox SSAnne_1F_Room2_Text_Woman, MSGBOX_NPC
	end

SSAnne_1F_Room2_Text_AnnSeen:
	.string "…$"

SSAnne_1F_Room2_Text_AnnBeaten:
	.string "…$"

SSAnne_1F_Room2_Text_TylerSeen:
	.string "…$"

SSAnne_1F_Room2_Text_TylerBeaten:
	.string "…$"

SSAnne_1F_Room2_Text_Woman:
	.string "We are cruising around the world,\nmy children and I.$"
