RockTunnel_1F_MapScripts::
	.byte 0

RockTunnel_1F_EventScript_Dana::
	trainerbattle_single TRAINER_KANTO_PICNICKER_DANA, RockTunnel_1F_Text_DanaSeen, RockTunnel_1F_Text_DanaBeaten
	msgbox RockTunnel_1F_Text_DanaBeaten, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ariana::
	trainerbattle_single TRAINER_KANTO_PICNICKER_ARIANA, RockTunnel_1F_Text_ArianaSeen, RockTunnel_1F_Text_ArianaBeaten
	msgbox RockTunnel_1F_Text_ArianaBeaten, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Leah::
	trainerbattle_single TRAINER_KANTO_PICNICKER_LEAH, RockTunnel_1F_Text_LeahSeen, RockTunnel_1F_Text_LeahBeaten
	msgbox RockTunnel_1F_Text_LeahBeaten, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Lucas::
	trainerbattle_single TRAINER_KANTO_HIKER_LUCAS, RockTunnel_1F_Text_LucasSeen, RockTunnel_1F_Text_LucasBeaten
	msgbox RockTunnel_1F_Text_LucasBeaten, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Oliver::
	trainerbattle_single TRAINER_KANTO_HIKER_OLIVER, RockTunnel_1F_Text_OliverSeen, RockTunnel_1F_Text_OliverBeaten
	msgbox RockTunnel_1F_Text_OliverBeaten, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Lenny::
	trainerbattle_single TRAINER_KANTO_HIKER_LENNY, RockTunnel_1F_Text_LennySeen, RockTunnel_1F_Text_LennyBeaten
	msgbox RockTunnel_1F_Text_LennyBeaten, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ashton::
	trainerbattle_single TRAINER_KANTO_POKEMANIAC_ASHTON, RockTunnel_1F_Text_AshtonSeen, RockTunnel_1F_Text_AshtonBeaten
	msgbox RockTunnel_1F_Text_AshtonBeaten, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_RouteSign::
	msgbox RockTunnel_1F_Text_RouteSign, MSGBOX_SIGN
	end

RockTunnel_1F_Text_DanaSeen:
	.string "…$"

RockTunnel_1F_Text_DanaBeaten:
	.string "…$"

RockTunnel_1F_Text_ArianaSeen:
	.string "…$"

RockTunnel_1F_Text_ArianaBeaten:
	.string "…$"

RockTunnel_1F_Text_LeahSeen:
	.string "…$"

RockTunnel_1F_Text_LeahBeaten:
	.string "…$"

RockTunnel_1F_Text_LucasSeen:
	.string "…$"

RockTunnel_1F_Text_LucasBeaten:
	.string "…$"

RockTunnel_1F_Text_OliverSeen:
	.string "…$"

RockTunnel_1F_Text_OliverBeaten:
	.string "…$"

RockTunnel_1F_Text_LennySeen:
	.string "…$"

RockTunnel_1F_Text_LennyBeaten:
	.string "…$"

RockTunnel_1F_Text_AshtonSeen:
	.string "…$"

RockTunnel_1F_Text_AshtonBeaten:
	.string "…$"

RockTunnel_1F_Text_RouteSign:
	.string "ROCK TUNNEL\nCERULEAN CITY - LAVENDER TOWN$"
