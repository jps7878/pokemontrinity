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
	.string "Two GENGAR keep me company up\nhere. Neither minds a battle.$"

PokemonTower_4F_Text_LaurelBeaten:
	.string "They enjoyed that. So did I.$"

PokemonTower_4F_Text_JodySeen:
	.string "CHANNELERs don't scare easy.\nLet's see about you.$"

PokemonTower_4F_Text_JodyBeaten:
	.string "Not bad, for someone still\nbreathing.$"

PokemonTower_4F_Text_PaulaSeen:
	.string "My GENGAR can tell when someone's\ngrieving. It felt you coming.$"

PokemonTower_4F_Text_PaulaBeaten:
	.string "Strong, and kind enough to visit.\nRare combination.$"
