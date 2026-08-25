Route10_MapScripts::
	.byte 0

Route10_EventScript_Carol::
	trainerbattle_single TRAINER_KANTO_PICNICKER_CAROL, Route10_Text_CarolSeen, Route10_Text_CarolBeaten
	msgbox Route10_Text_CarolBeaten, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Clark::
	trainerbattle_single TRAINER_KANTO_HIKER_CLARK, Route10_Text_ClarkSeen, Route10_Text_ClarkBeaten
	msgbox Route10_Text_ClarkBeaten, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Herman::
	trainerbattle_single TRAINER_KANTO_POKEMANIAC_HERMAN, Route10_Text_HermanSeen, Route10_Text_HermanBeaten
	msgbox Route10_Text_HermanBeaten, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Trent::
	trainerbattle_single TRAINER_KANTO_HIKER_TRENT, Route10_Text_TrentSeen, Route10_Text_TrentBeaten
	msgbox Route10_Text_TrentBeaten, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Mark::
	trainerbattle_single TRAINER_KANTO_POKEMANIAC_MARK, Route10_Text_MarkSeen, Route10_Text_MarkBeaten
	msgbox Route10_Text_MarkBeaten, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Heidi::
	trainerbattle_single TRAINER_KANTO_PICNICKER_HEIDI, Route10_Text_HeidiSeen, Route10_Text_HeidiBeaten
	msgbox Route10_Text_HeidiBeaten, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_SouthRockTunnelSign::
	msgbox Route10_Text_SouthRockTunnelSign, MSGBOX_SIGN
	end

Route10_EventScript_PowerPlantSign::
	msgbox Route10_Text_PowerPlantSign, MSGBOX_SIGN
	end

Route10_EventScript_NorthRockTunnelSign::
	msgbox Route10_Text_NorthRockTunnelSign, MSGBOX_SIGN
	end

Route10_Text_CarolSeen:
	.string "…$"

Route10_Text_CarolBeaten:
	.string "…$"

Route10_Text_ClarkSeen:
	.string "…$"

Route10_Text_ClarkBeaten:
	.string "…$"

Route10_Text_HermanSeen:
	.string "…$"

Route10_Text_HermanBeaten:
	.string "…$"

Route10_Text_TrentSeen:
	.string "…$"

Route10_Text_TrentBeaten:
	.string "…$"

Route10_Text_MarkSeen:
	.string "…$"

Route10_Text_MarkBeaten:
	.string "…$"

Route10_Text_HeidiSeen:
	.string "…$"

Route10_Text_HeidiBeaten:
	.string "…$"

Route10_Text_SouthRockTunnelSign:
	.string "ROCK TUNNEL$"

Route10_Text_PowerPlantSign:
	.string "POWER PLANT$"

Route10_Text_NorthRockTunnelSign:
	.string "ROCK TUNNEL\nDetour to LAVENDER TOWN$"
