Route12_MapScripts::
	.byte 0

Route12_EventScript_Ned::
	trainerbattle_single TRAINER_KANTO_FISHERMAN_NED, Route12_Text_NedSeen, Route12_Text_NedBeaten
	msgbox Route12_Text_NedBeaten, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Chip::
	trainerbattle_single TRAINER_KANTO_FISHERMAN_CHIP, Route12_Text_ChipSeen, Route12_Text_ChipBeaten
	msgbox Route12_Text_ChipBeaten, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Hank::
	trainerbattle_single TRAINER_KANTO_FISHERMAN_HANK, Route12_Text_HankSeen, Route12_Text_HankBeaten
	msgbox Route12_Text_HankBeaten, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Elliot::
	trainerbattle_single TRAINER_KANTO_FISHERMAN_ELLIOT, Route12_Text_ElliotSeen, Route12_Text_ElliotBeaten
	msgbox Route12_Text_ElliotBeaten, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Luca::
	trainerbattle_single TRAINER_KANTO_ROCKER_LUCA, Route12_Text_LucaSeen, Route12_Text_LucaBeaten
	msgbox Route12_Text_LucaBeaten, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Justin::
	trainerbattle_single TRAINER_KANTO_CAMPER_JUSTIN, Route12_Text_JustinSeen, Route12_Text_JustinBeaten
	msgbox Route12_Text_JustinBeaten, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Andrew::
	trainerbattle_single TRAINER_KANTO_FISHERMAN_ANDREW, Route12_Text_AndrewSeen, Route12_Text_AndrewBeaten
	msgbox Route12_Text_AndrewBeaten, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Gia::
	trainerbattle_single TRAINER_KANTO_YOUNG_COUPLE_GIA_JES, Route12_Text_GiaSeen, Route12_Text_GiaBeaten
	msgbox Route12_Text_GiaBeaten, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Jes::
	trainerbattle_single TRAINER_KANTO_YOUNG_COUPLE_GIA_JES_2, Route12_Text_JesSeen, Route12_Text_JesBeaten
	msgbox Route12_Text_JesBeaten, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_RouteSign::
	msgbox Route12_Text_RouteSign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_FishingSign, MSGBOX_SIGN
	end

Route12_Text_NedSeen:
	.string "…$"

Route12_Text_NedBeaten:
	.string "…$"

Route12_Text_ChipSeen:
	.string "…$"

Route12_Text_ChipBeaten:
	.string "…$"

Route12_Text_HankSeen:
	.string "…$"

Route12_Text_HankBeaten:
	.string "…$"

Route12_Text_ElliotSeen:
	.string "…$"

Route12_Text_ElliotBeaten:
	.string "…$"

Route12_Text_LucaSeen:
	.string "…$"

Route12_Text_LucaBeaten:
	.string "…$"

Route12_Text_JustinSeen:
	.string "…$"

Route12_Text_JustinBeaten:
	.string "…$"

Route12_Text_AndrewSeen:
	.string "…$"

Route12_Text_AndrewBeaten:
	.string "…$"

Route12_Text_GiaSeen:
	.string "…$"

Route12_Text_GiaBeaten:
	.string "…$"

Route12_Text_JesSeen:
	.string "…$"

Route12_Text_JesBeaten:
	.string "…$"

Route12_Text_RouteSign:
	.string "ROUTE 12 \nNorth to LAVENDER$"

Route12_Text_FishingSign:
	.string "SPORTFISHING AREA$"
