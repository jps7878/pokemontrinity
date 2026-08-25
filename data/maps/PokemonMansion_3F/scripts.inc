PokemonMansion_3F_MapScripts::
	.byte 0

PokemonMansion_3F_EventScript_Simon::
	trainerbattle_single TRAINER_KANTO_BURGLAR_SIMON, PokemonMansion_3F_Text_SimonSeen, PokemonMansion_3F_Text_SimonBeaten
	msgbox PokemonMansion_3F_Text_SimonBeaten, MSGBOX_AUTOCLOSE
	end

PokemonMansion_3F_EventScript_Braydon::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_BRAYDON, PokemonMansion_3F_Text_BraydonSeen, PokemonMansion_3F_Text_BraydonBeaten
	msgbox PokemonMansion_3F_Text_BraydonBeaten, MSGBOX_AUTOCLOSE
	end

PokemonMansion_3F_EventScript_DiaryFeb6th::
	msgbox PokemonMansion_3F_Text_DiaryFeb6th, MSGBOX_SIGN
	end

PokemonMansion_3F_EventScript_Statue::
	msgbox PokemonMansion_3F_Text_Statue, MSGBOX_SIGN
	end

PokemonMansion_3F_Text_SimonSeen:
	.string "…$"

PokemonMansion_3F_Text_SimonBeaten:
	.string "…$"

PokemonMansion_3F_Text_BraydonSeen:
	.string "…$"

PokemonMansion_3F_Text_BraydonBeaten:
	.string "…$"

PokemonMansion_3F_Text_DiaryFeb6th:
	.string "Diary: Feb. 6\nMEW gave birth.\pWe named the newborn MEWTWO.$"

PokemonMansion_3F_Text_Statue:
	.string "Folks in KANTO don't get many\nvisitors from HOENN. Word is one\lof them cleaned up in JOHTO too.$"
