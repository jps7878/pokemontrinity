Route15_MapScripts::
	.byte 0

Route15_EventScript_Yazmin::
	trainerbattle_single TRAINER_KANTO_PICNICKER_YAZMIN, Route15_Text_YazminSeen, Route15_Text_YazminBeaten
	msgbox Route15_Text_YazminBeaten, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Edwin::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_EDWIN, Route15_Text_EdwinSeen, Route15_Text_EdwinBeaten
	msgbox Route15_Text_EdwinBeaten, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Chester::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_CHESTER, Route15_Text_ChesterSeen, Route15_Text_ChesterBeaten
	msgbox Route15_Text_ChesterBeaten, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Kindra::
	trainerbattle_single TRAINER_KANTO_PICNICKER_KINDRA, Route15_Text_KindraSeen, Route15_Text_KindraBeaten
	msgbox Route15_Text_KindraBeaten, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Olivia::
	trainerbattle_single TRAINER_KANTO_BEAUTY_OLIVIA, Route15_Text_OliviaSeen, Route15_Text_OliviaBeaten
	msgbox Route15_Text_OliviaBeaten, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Alex::
	trainerbattle_single TRAINER_KANTO_BIKER_ALEX, Route15_Text_AlexSeen, Route15_Text_AlexBeaten
	msgbox Route15_Text_AlexBeaten, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Ernest::
	trainerbattle_single TRAINER_KANTO_BIKER_ERNEST, Route15_Text_ErnestSeen, Route15_Text_ErnestBeaten
	msgbox Route15_Text_ErnestBeaten, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Becky::
	trainerbattle_single TRAINER_KANTO_PICNICKER_BECKY, Route15_Text_BeckySeen, Route15_Text_BeckyBeaten
	msgbox Route15_Text_BeckyBeaten, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Grace::
	trainerbattle_single TRAINER_KANTO_BEAUTY_GRACE, Route15_Text_GraceSeen, Route15_Text_GraceBeaten
	msgbox Route15_Text_GraceBeaten, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Celia::
	trainerbattle_single TRAINER_KANTO_PICNICKER_CELIA, Route15_Text_CeliaSeen, Route15_Text_CeliaBeaten
	msgbox Route15_Text_CeliaBeaten, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Ron::
	trainerbattle_single TRAINER_KANTO_CRUSH_KIN_RON_MYA, Route15_Text_RonSeen, Route15_Text_RonBeaten
	msgbox Route15_Text_RonBeaten, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Mya::
	trainerbattle_single TRAINER_KANTO_CRUSH_KIN_RON_MYA_2, Route15_Text_MyaSeen, Route15_Text_MyaBeaten
	msgbox Route15_Text_MyaBeaten, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_RouteSign::
	msgbox Route15_Text_RouteSign, MSGBOX_SIGN
	end

Route15_Text_YazminSeen:
	.string "…$"

Route15_Text_YazminBeaten:
	.string "…$"

Route15_Text_EdwinSeen:
	.string "…$"

Route15_Text_EdwinBeaten:
	.string "…$"

Route15_Text_ChesterSeen:
	.string "…$"

Route15_Text_ChesterBeaten:
	.string "…$"

Route15_Text_KindraSeen:
	.string "…$"

Route15_Text_KindraBeaten:
	.string "…$"

Route15_Text_OliviaSeen:
	.string "…$"

Route15_Text_OliviaBeaten:
	.string "…$"

Route15_Text_AlexSeen:
	.string "…$"

Route15_Text_AlexBeaten:
	.string "…$"

Route15_Text_ErnestSeen:
	.string "…$"

Route15_Text_ErnestBeaten:
	.string "…$"

Route15_Text_BeckySeen:
	.string "…$"

Route15_Text_BeckyBeaten:
	.string "…$"

Route15_Text_GraceSeen:
	.string "…$"

Route15_Text_GraceBeaten:
	.string "…$"

Route15_Text_CeliaSeen:
	.string "…$"

Route15_Text_CeliaBeaten:
	.string "…$"

Route15_Text_RonSeen:
	.string "…$"

Route15_Text_RonBeaten:
	.string "…$"

Route15_Text_MyaSeen:
	.string "…$"

Route15_Text_MyaBeaten:
	.string "…$"

Route15_Text_RouteSign:
	.string "ROUTE 15\nWest to FUCHSIA CITY$"
