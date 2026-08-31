PokemonMansion_B1F_MapScripts::
	.byte 0

PokemonMansion_B1F_EventScript_Lewis::
	trainerbattle_single TRAINER_KANTO_BURGLAR_LEWIS, PokemonMansion_B1F_Text_LewisSeen, PokemonMansion_B1F_Text_LewisBeaten
	msgbox PokemonMansion_B1F_Text_LewisBeaten, MSGBOX_AUTOCLOSE
	end

PokemonMansion_B1F_EventScript_Ivan::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_IVAN, PokemonMansion_B1F_Text_IvanSeen, PokemonMansion_B1F_Text_IvanBeaten
	msgbox PokemonMansion_B1F_Text_IvanBeaten, MSGBOX_AUTOCLOSE
	end

PokemonMansion_B1F_EventScript_DiarySep1st::
	msgbox PokemonMansion_B1F_Text_DiarySep1st, MSGBOX_SIGN
	end

PokemonMansion_B1F_EventScript_Statue::
	msgbox PokemonMansion_B1F_Text_Statue, MSGBOX_SIGN
	end

PokemonMansion_B1F_EventScript_Statue_2::
	msgbox PokemonMansion_B1F_Text_Statue_2, MSGBOX_SIGN
	end

PokemonMansion_B1F_Text_LewisSeen:
	.string "Uh-oh… Where am I now?$"

PokemonMansion_B1F_Text_LewisBeaten:
	.string "Awooh!$"

PokemonMansion_B1F_Text_IvanSeen:
	.string "This place is ideal for a lab.\nLook at all this space.$"

PokemonMansion_B1F_Text_IvanBeaten:
	.string "What was that for?$"

PokemonMansion_B1F_Text_DiarySep1st:
	.string "Diary: Sept. 1\nMEWTWO is far too powerful.\pWe have failed to curb its vicious\ntendencies…$"

PokemonMansion_B1F_Text_Statue:
	.string "Never met the champion myself.\nHeard they came up through HOENN\land JOHTO before setting foot here.$"

PokemonMansion_B1F_Text_Statue_2:
	.string "Never met the champion myself.\nHeard they came up through HOENN\land JOHTO before setting foot here.$"
