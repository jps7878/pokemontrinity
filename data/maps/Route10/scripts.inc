@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

Route10_MapScripts::
	.byte 0

Route10_EventScript_Carol::
	trainerbattle_single TRAINER_KANTO_PICNICKER_CAROL, Route10_Text_CarolSeen, Route10_Text_CarolBeaten
	msgbox Route10_Text_CarolPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Clark::
	trainerbattle_single TRAINER_KANTO_HIKER_CLARK, Route10_Text_ClarkSeen, Route10_Text_ClarkBeaten
	msgbox Route10_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Herman::
	trainerbattle_single TRAINER_KANTO_POKEMANIAC_HERMAN, Route10_Text_HermanSeen, Route10_Text_HermanBeaten
	msgbox Route10_Text_HermanPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Trent::
	trainerbattle_single TRAINER_KANTO_HIKER_TRENT, Route10_Text_TrentSeen, Route10_Text_TrentBeaten
	msgbox Route10_Text_TrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Mark::
	trainerbattle_single TRAINER_KANTO_POKEMANIAC_MARK, Route10_Text_MarkSeen, Route10_Text_MarkBeaten
	msgbox Route10_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_EventScript_Heidi::
	trainerbattle_single TRAINER_KANTO_PICNICKER_HEIDI, Route10_Text_HeidiSeen, Route10_Text_HeidiBeaten
	msgbox Route10_Text_HeidiPostBattle, MSGBOX_AUTOCLOSE
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
	.string "I'm feeling a bit faint.\nI haven't hiked in some time.$"

Route10_Text_CarolBeaten:
	.string "I'm too tired.\nI wasn't up for it.$"

Route10_Text_CarolPostBattle:
	.string "The POKéMON here in the mountains\nare so chunky…\pI wish there were pink POKéMON\nwith a floral pattern!$"

Route10_Text_ClarkSeen:
	.string "Ha-hahah-ah-ha!$"

Route10_Text_ClarkBeaten:
	.string "Ha-haha!\nNot laughing!\lHa-hay fever! Haha-ha-choo!$"

Route10_Text_ClarkPostBattle:
	.string "Haha-ha-choo!\nHa-choo!\lSnort! Snivel!$"

Route10_Text_HermanSeen:
	.string "Hi, kid!\nWant to see my POKéMON?$"

Route10_Text_HermanBeaten:
	.string "Oh, no!\nMy POKéMON!$"

Route10_Text_HermanPostBattle:
	.string "I don't like you.\nI don't like anyone better than me!$"

Route10_Text_TrentSeen:
	.string "Ah!\nThis mountain air is delicious!$"

Route10_Text_TrentBeaten:
	.string "That cleared my head!$"

Route10_Text_TrentPostBattle:
	.string "I feel bloated on mountain air!$"

Route10_Text_MarkSeen:
	.string "Wow, you came all the way here?\nMaybe you're a POKéMANIAC, too?\lWant to see my collection?$"

Route10_Text_MarkBeaten:
	.string "Humph.\nI'm not angry!$"

Route10_Text_MarkPostBattle:
	.string "I have more rare POKéMON at home!$"

Route10_Text_HeidiSeen:
	.string "I've been out at a POKéMON GYM\na few times.\p…But I always lose.$"

Route10_Text_HeidiBeaten:
	.string "Ohh!\nAfter all my training!$"

Route10_Text_HeidiPostBattle:
	.string "I noticed some POKéMANIACS\nprowling around.\pCan you imagine? Them?\nUp here in the mountains?$"

Route10_Text_SouthRockTunnelSign:
	.string "ROCK TUNNEL$"

Route10_Text_PowerPlantSign:
	.string "POWER PLANT$"

Route10_Text_NorthRockTunnelSign:
	.string "ROCK TUNNEL\nDetour to LAVENDER TOWN$"
