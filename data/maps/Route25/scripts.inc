Route25_MapScripts::
	.byte 0

Route25_EventScript_Franklin::
	trainerbattle_single TRAINER_KANTO_HIKER_FRANKLIN, Route25_Text_FranklinSeen, Route25_Text_FranklinBeaten
	msgbox Route25_Text_FranklinBeaten, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Joey::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_JOEY, Route25_Text_JoeySeen, Route25_Text_JoeyBeaten
	msgbox Route25_Text_JoeyBeaten, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Wayne::
	trainerbattle_single TRAINER_KANTO_HIKER_WAYNE, Route25_Text_WayneSeen, Route25_Text_WayneBeaten
	msgbox Route25_Text_WayneBeaten, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Dan::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_DAN, Route25_Text_DanSeen, Route25_Text_DanBeaten
	msgbox Route25_Text_DanBeaten, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Kelsey::
	trainerbattle_single TRAINER_KANTO_PICNICKER_KELSEY, Route25_Text_KelseySeen, Route25_Text_KelseyBeaten
	msgbox Route25_Text_KelseyBeaten, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Nob::
	trainerbattle_single TRAINER_KANTO_HIKER_NOB, Route25_Text_NobSeen, Route25_Text_NobBeaten
	msgbox Route25_Text_NobBeaten, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Flint::
	trainerbattle_single TRAINER_KANTO_CAMPER_FLINT, Route25_Text_FlintSeen, Route25_Text_FlintBeaten
	msgbox Route25_Text_FlintBeaten, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Chad::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_CHAD, Route25_Text_ChadSeen, Route25_Text_ChadBeaten
	msgbox Route25_Text_ChadBeaten, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Haley::
	trainerbattle_single TRAINER_KANTO_LASS_HALEY, Route25_Text_HaleySeen, Route25_Text_HaleyBeaten
	msgbox Route25_Text_HaleyBeaten, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Man::
	msgbox Route25_Text_Man, MSGBOX_NPC
	end

Route25_EventScript_SeaCottageSign::
	msgbox Route25_Text_SeaCottageSign, MSGBOX_SIGN
	end

Route25_Text_FranklinSeen:
	.string "…$"

Route25_Text_FranklinBeaten:
	.string "…$"

Route25_Text_JoeySeen:
	.string "…$"

Route25_Text_JoeyBeaten:
	.string "…$"

Route25_Text_WayneSeen:
	.string "…$"

Route25_Text_WayneBeaten:
	.string "…$"

Route25_Text_DanSeen:
	.string "…$"

Route25_Text_DanBeaten:
	.string "…$"

Route25_Text_KelseySeen:
	.string "…$"

Route25_Text_KelseyBeaten:
	.string "…$"

Route25_Text_NobSeen:
	.string "…$"

Route25_Text_NobBeaten:
	.string "…$"

Route25_Text_FlintSeen:
	.string "…$"

Route25_Text_FlintBeaten:
	.string "…$"

Route25_Text_ChadSeen:
	.string "…$"

Route25_Text_ChadBeaten:
	.string "…$"

Route25_Text_HaleySeen:
	.string "…$"

Route25_Text_HaleyBeaten:
	.string "…$"

Route25_Text_Man:
	.string "Hello, are you here alone?\pIf you're out at CERULEAN's cape…\nWell, it should be as a couple.$"

Route25_Text_SeaCottageSign:
	.string "SEA COTTAGE\nBILL lives here!$"
