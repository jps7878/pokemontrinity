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
	.string "Three GENGAR, one CHANNELER.\nThis floor's the deep end.$"

PokemonTower_6F_Text_AngelicaBeaten:
	.string "All three agree -- you earned\nthat.$"

PokemonTower_6F_Text_JenniferSeen:
	.string "Near the top now. Most turn\nback around here.$"

PokemonTower_6F_Text_JenniferBeaten:
	.string "Not many make it this far.\nGo on.$"

PokemonTower_6F_Text_EmiliaSeen:
	.string "Last floor before the roof.\nNothing up there but quiet,\lthese days.$"

PokemonTower_6F_Text_EmiliaBeaten:
	.string "Then go see the quiet for\nyourself.$"
