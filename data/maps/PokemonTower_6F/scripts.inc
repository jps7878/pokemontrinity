PokemonTower_6F_MapScripts::
	.byte 0

PokemonTower_6F_EventScript_Angelica::
	trainerbattle_single TRAINER_KANTO_CHANNELER_ANGELICA, PokemonTower_6F_Text_AngelicaSeen, PokemonTower_6F_Text_AngelicaBeaten
	msgbox PokemonTower_6F_Text_AngelicaBeaten, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_EventScript_Jennifer::
	trainerbattle_single TRAINER_KANTO_CHANNELER_JENNIFER, PokemonTower_6F_Text_JenniferSeen, PokemonTower_6F_Text_JenniferBeaten
	msgbox PokemonTower_6F_Text_JenniferBeaten, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_EventScript_Emilia::
	trainerbattle_single TRAINER_KANTO_CHANNELER_EMILIA, PokemonTower_6F_Text_EmiliaSeen, PokemonTower_6F_Text_EmiliaBeaten
	msgbox PokemonTower_6F_Text_EmiliaBeaten, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_Text_AngelicaSeen:
	.string "…$"

PokemonTower_6F_Text_AngelicaBeaten:
	.string "…$"

PokemonTower_6F_Text_JenniferSeen:
	.string "…$"

PokemonTower_6F_Text_JenniferBeaten:
	.string "…$"

PokemonTower_6F_Text_EmiliaSeen:
	.string "…$"

PokemonTower_6F_Text_EmiliaBeaten:
	.string "…$"
