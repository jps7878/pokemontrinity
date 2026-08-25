PokemonMansion_1F_MapScripts::
	.byte 0

PokemonMansion_1F_EventScript_Ted::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_TED, PokemonMansion_1F_Text_TedSeen, PokemonMansion_1F_Text_TedBeaten
	msgbox PokemonMansion_1F_Text_TedBeaten, MSGBOX_AUTOCLOSE
	end

PokemonMansion_1F_EventScript_Johnson::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_JOHNSON, PokemonMansion_1F_Text_JohnsonSeen, PokemonMansion_1F_Text_JohnsonBeaten
	msgbox PokemonMansion_1F_Text_JohnsonBeaten, MSGBOX_AUTOCLOSE
	end

PokemonMansion_1F_EventScript_Statue::
	msgbox PokemonMansion_1F_Text_Statue, MSGBOX_SIGN
	end

PokemonMansion_1F_Text_TedSeen:
	.string "…$"

PokemonMansion_1F_Text_TedBeaten:
	.string "…$"

PokemonMansion_1F_Text_JohnsonSeen:
	.string "…$"

PokemonMansion_1F_Text_JohnsonBeaten:
	.string "…$"

PokemonMansion_1F_Text_Statue:
	.string "KANTO's peaceful most days, but\neven here we've heard the stories\labout that HOENN trainer.$"
