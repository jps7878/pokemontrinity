PokemonTower_4F_MapScripts::
	.byte 0

PokemonTower_4F_EventScript_Laurel::
	trainerbattle_single TRAINER_KANTO_CHANNELER_LAUREL, PokemonTower_4F_Text_LaurelSeen, PokemonTower_4F_Text_LaurelBeaten
	msgbox PokemonTower_4F_Text_LaurelBeaten, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_EventScript_Jody::
	trainerbattle_single TRAINER_KANTO_CHANNELER_JODY, PokemonTower_4F_Text_JodySeen, PokemonTower_4F_Text_JodyBeaten
	msgbox PokemonTower_4F_Text_JodyBeaten, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_EventScript_Paula::
	trainerbattle_single TRAINER_KANTO_CHANNELER_PAULA, PokemonTower_4F_Text_PaulaSeen, PokemonTower_4F_Text_PaulaBeaten
	msgbox PokemonTower_4F_Text_PaulaBeaten, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_Text_LaurelSeen:
	.string "…$"

PokemonTower_4F_Text_LaurelBeaten:
	.string "…$"

PokemonTower_4F_Text_JodySeen:
	.string "…$"

PokemonTower_4F_Text_JodyBeaten:
	.string "…$"

PokemonTower_4F_Text_PaulaSeen:
	.string "…$"

PokemonTower_4F_Text_PaulaBeaten:
	.string "…$"
