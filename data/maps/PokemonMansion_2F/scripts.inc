PokemonMansion_2F_MapScripts::
	.byte 0

PokemonMansion_2F_EventScript_Arnie::
	trainerbattle_single TRAINER_KANTO_BURGLAR_ARNIE, PokemonMansion_2F_Text_ArnieSeen, PokemonMansion_2F_Text_ArnieBeaten
	msgbox PokemonMansion_2F_Text_ArnieBeaten, MSGBOX_AUTOCLOSE
	end

PokemonMansion_2F_EventScript_Statue::
	msgbox PokemonMansion_2F_Text_Statue, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_DiaryJuly10th::
	msgbox PokemonMansion_2F_Text_DiaryJuly10th, MSGBOX_SIGN
	end

PokemonMansion_2F_EventScript_DiaryJuly5th::
	msgbox PokemonMansion_2F_Text_DiaryJuly5th, MSGBOX_SIGN
	end

PokemonMansion_2F_Text_ArnieSeen:
	.string "Heh, this old place has more\nthan just dust in it.$"

PokemonMansion_2F_Text_ArnieBeaten:
	.string "Guess I'll go dig somewhere\nelse.$"

PokemonMansion_2F_Text_Statue:
	.string "This route's seen more foot traffic\nlately. Something about a champion\lpassing through from JOHTO.$"

PokemonMansion_2F_Text_DiaryJuly10th:
	.string "Diary: July 10\nWe christened the newly discovered\lPOKéMON, MEW.$"

PokemonMansion_2F_Text_DiaryJuly5th:
	.string "Diary: July 5\nGuyana, South America\pA new POKéMON was discovered deep\nin the jungle.$"
