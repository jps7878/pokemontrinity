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
	.string "Who are you?\nThere shouldn't be anyone\lhere.$"

PokemonMansion_1F_Text_TedBeaten:
	.string "Ouch!$"

PokemonMansion_1F_Text_JohnsonSeen:
	.string "W-w-waah! You startled me!\nI thought you were a ghost.$"

PokemonMansion_1F_Text_JohnsonBeaten:
	.string "Tch! I can't get any wins.$"

PokemonMansion_1F_Text_Statue:
	.string "A statue. Something clicks\nbehind it when you lean in.\lNothing opens.$"
