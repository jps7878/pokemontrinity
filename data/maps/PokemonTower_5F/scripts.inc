PokemonTower_5F_MapScripts::
	.byte 0

PokemonTower_5F_EventScript_Ruth::
	trainerbattle_single TRAINER_KANTO_CHANNELER_RUTH, PokemonTower_5F_Text_RuthSeen, PokemonTower_5F_Text_RuthBeaten
	msgbox PokemonTower_5F_Text_RuthBeaten, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Tammy::
	trainerbattle_single TRAINER_KANTO_CHANNELER_TAMMY, PokemonTower_5F_Text_TammySeen, PokemonTower_5F_Text_TammyBeaten
	msgbox PokemonTower_5F_Text_TammyBeaten, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Karina::
	trainerbattle_single TRAINER_KANTO_CHANNELER_KARINA, PokemonTower_5F_Text_KarinaSeen, PokemonTower_5F_Text_KarinaBeaten
	msgbox PokemonTower_5F_Text_KarinaBeaten, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Janae::
	trainerbattle_single TRAINER_KANTO_CHANNELER_JANAE, PokemonTower_5F_Text_JanaeSeen, PokemonTower_5F_Text_JanaeBeaten
	msgbox PokemonTower_5F_Text_JanaeBeaten, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Channeler::
	msgbox PokemonTower_5F_Text_Channeler, MSGBOX_NPC
	end

PokemonTower_5F_Text_RuthSeen:
	.string "…$"

PokemonTower_5F_Text_RuthBeaten:
	.string "…$"

PokemonTower_5F_Text_TammySeen:
	.string "…$"

PokemonTower_5F_Text_TammyBeaten:
	.string "…$"

PokemonTower_5F_Text_KarinaSeen:
	.string "…$"

PokemonTower_5F_Text_KarinaBeaten:
	.string "…$"

PokemonTower_5F_Text_JanaeSeen:
	.string "…$"

PokemonTower_5F_Text_JanaeBeaten:
	.string "…$"

PokemonTower_5F_Text_Channeler:
	.string "Come, child!\nI have purified this space.\lYou can rest here.$"
