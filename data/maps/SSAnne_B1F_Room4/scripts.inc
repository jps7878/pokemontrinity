SSAnne_B1F_Room4_MapScripts::
	.byte 0

SSAnne_B1F_Room4_EventScript_Duncan::
	trainerbattle_single TRAINER_KANTO_SAILOR_DUNCAN, SSAnne_B1F_Room4_Text_DuncanSeen, SSAnne_B1F_Room4_Text_DuncanBeaten
	msgbox SSAnne_B1F_Room4_Text_DuncanBeaten, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_EventScript_Leonard::
	trainerbattle_single TRAINER_KANTO_SAILOR_LEONARD, SSAnne_B1F_Room4_Text_LeonardSeen, SSAnne_B1F_Room4_Text_LeonardBeaten
	msgbox SSAnne_B1F_Room4_Text_LeonardBeaten, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_Text_DuncanSeen:
	.string "…$"

SSAnne_B1F_Room4_Text_DuncanBeaten:
	.string "…$"

SSAnne_B1F_Room4_Text_LeonardSeen:
	.string "…$"

SSAnne_B1F_Room4_Text_LeonardBeaten:
	.string "…$"
