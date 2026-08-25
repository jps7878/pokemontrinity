PokemonTower_3F_MapScripts::
	.byte 0

PokemonTower_3F_EventScript_Patricia::
	trainerbattle_single TRAINER_KANTO_CHANNELER_PATRICIA, PokemonTower_3F_Text_PatriciaSeen, PokemonTower_3F_Text_PatriciaBeaten
	msgbox PokemonTower_3F_Text_PatriciaBeaten, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_EventScript_Carly::
	trainerbattle_single TRAINER_KANTO_CHANNELER_CARLY, PokemonTower_3F_Text_CarlySeen, PokemonTower_3F_Text_CarlyBeaten
	msgbox PokemonTower_3F_Text_CarlyBeaten, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_EventScript_Hope::
	trainerbattle_single TRAINER_KANTO_CHANNELER_HOPE, PokemonTower_3F_Text_HopeSeen, PokemonTower_3F_Text_HopeBeaten
	msgbox PokemonTower_3F_Text_HopeBeaten, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_Text_PatriciaSeen:
	.string "…$"

PokemonTower_3F_Text_PatriciaBeaten:
	.string "…$"

PokemonTower_3F_Text_CarlySeen:
	.string "…$"

PokemonTower_3F_Text_CarlyBeaten:
	.string "…$"

PokemonTower_3F_Text_HopeSeen:
	.string "…$"

PokemonTower_3F_Text_HopeBeaten:
	.string "…$"
