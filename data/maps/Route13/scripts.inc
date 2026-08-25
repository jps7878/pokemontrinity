Route13_MapScripts::
	.byte 0

Route13_EventScript_Alma::
	trainerbattle_single TRAINER_KANTO_PICNICKER_ALMA, Route13_Text_AlmaSeen, Route13_Text_AlmaBeaten
	msgbox Route13_Text_AlmaBeaten, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Sebastian::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_SEBASTIAN, Route13_Text_SebastianSeen, Route13_Text_SebastianBeaten
	msgbox Route13_Text_SebastianBeaten, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Susie::
	trainerbattle_single TRAINER_KANTO_PICNICKER_SUSIE, Route13_Text_SusieSeen, Route13_Text_SusieBeaten
	msgbox Route13_Text_SusieBeaten, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Sheila::
	trainerbattle_single TRAINER_KANTO_BEAUTY_SHEILA, Route13_Text_SheilaSeen, Route13_Text_SheilaBeaten
	msgbox Route13_Text_SheilaBeaten, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Lola::
	trainerbattle_single TRAINER_KANTO_BEAUTY_LOLA, Route13_Text_LolaSeen, Route13_Text_LolaBeaten
	msgbox Route13_Text_LolaBeaten, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Valerie::
	trainerbattle_single TRAINER_KANTO_PICNICKER_VALERIE, Route13_Text_ValerieSeen, Route13_Text_ValerieBeaten
	msgbox Route13_Text_ValerieBeaten, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Gwen::
	trainerbattle_single TRAINER_KANTO_PICNICKER_GWEN, Route13_Text_GwenSeen, Route13_Text_GwenBeaten
	msgbox Route13_Text_GwenBeaten, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Robert::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_ROBERT, Route13_Text_RobertSeen, Route13_Text_RobertBeaten
	msgbox Route13_Text_RobertBeaten, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Perry::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_PERRY, Route13_Text_PerrySeen, Route13_Text_PerryBeaten
	msgbox Route13_Text_PerryBeaten, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Jared::
	trainerbattle_single TRAINER_KANTO_BIKER_JARED, Route13_Text_JaredSeen, Route13_Text_JaredBeaten
	msgbox Route13_Text_JaredBeaten, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_RouteSign::
	msgbox Route13_Text_RouteSign, MSGBOX_SIGN
	end

Route13_EventScript_TrainerTips2::
	msgbox Route13_Text_TrainerTips2, MSGBOX_SIGN
	end

Route13_EventScript_TrainerTips1::
	msgbox Route13_Text_TrainerTips1, MSGBOX_SIGN
	end

Route13_Text_AlmaSeen:
	.string "…$"

Route13_Text_AlmaBeaten:
	.string "…$"

Route13_Text_SebastianSeen:
	.string "…$"

Route13_Text_SebastianBeaten:
	.string "…$"

Route13_Text_SusieSeen:
	.string "…$"

Route13_Text_SusieBeaten:
	.string "…$"

Route13_Text_SheilaSeen:
	.string "…$"

Route13_Text_SheilaBeaten:
	.string "…$"

Route13_Text_LolaSeen:
	.string "…$"

Route13_Text_LolaBeaten:
	.string "…$"

Route13_Text_ValerieSeen:
	.string "…$"

Route13_Text_ValerieBeaten:
	.string "…$"

Route13_Text_GwenSeen:
	.string "…$"

Route13_Text_GwenBeaten:
	.string "…$"

Route13_Text_RobertSeen:
	.string "…$"

Route13_Text_RobertBeaten:
	.string "…$"

Route13_Text_PerrySeen:
	.string "…$"

Route13_Text_PerryBeaten:
	.string "…$"

Route13_Text_JaredSeen:
	.string "…$"

Route13_Text_JaredBeaten:
	.string "…$"

Route13_Text_RouteSign:
	.string "ROUTE 13\nNorth to SILENCE BRIDGE$"

Route13_Text_TrainerTips2:
	.string "TRAINER TIPS\pUse SELECT to switch items in the\nITEMS window.$"

Route13_Text_TrainerTips1:
	.string "TRAINER TIPS\pLook, look!\nLook to the left of that post!$"
