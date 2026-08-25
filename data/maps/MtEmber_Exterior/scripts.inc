MtEmber_Exterior_MapScripts::
	.byte 0

MtEmber_Exterior_EventScript_Jocelyn::
	trainerbattle_single TRAINER_KANTO_CRUSH_GIRL_JOCELYN, MtEmber_Exterior_Text_JocelynSeen, MtEmber_Exterior_Text_JocelynBeaten
	msgbox MtEmber_Exterior_Text_JocelynBeaten, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_EventScript_Logan::
	trainerbattle_single TRAINER_KANTO_PKMN_RANGER_LOGAN, MtEmber_Exterior_Text_LoganSeen, MtEmber_Exterior_Text_LoganBeaten
	msgbox MtEmber_Exterior_Text_LoganBeaten, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_EventScript_Beth::
	trainerbattle_single TRAINER_KANTO_PKMN_RANGER_BETH, MtEmber_Exterior_Text_BethSeen, MtEmber_Exterior_Text_BethBeaten
	msgbox MtEmber_Exterior_Text_BethBeaten, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_Text_JocelynSeen:
	.string "…$"

MtEmber_Exterior_Text_JocelynBeaten:
	.string "…$"

MtEmber_Exterior_Text_LoganSeen:
	.string "…$"

MtEmber_Exterior_Text_LoganBeaten:
	.string "…$"

MtEmber_Exterior_Text_BethSeen:
	.string "…$"

MtEmber_Exterior_Text_BethBeaten:
	.string "…$"
