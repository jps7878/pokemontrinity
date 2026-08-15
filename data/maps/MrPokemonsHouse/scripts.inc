MrPokemonsHouse_MapScripts::
	.byte 0

@ Trinity M4b S1: once PROF.ELM has named him (FLAG_TRINITY_J_MRPOKEMON_HOOK),
@ MR.POKéMON seeds the Red Scale request -- adapted from pokecrystal
@ MrPokemonText_GimmeTheScale (MrPokemonsHouse.asm:329-343). The EXP.SHARE
@ payoff itself belongs to M4b S7 (Lake of Rage / Red Gyarados); note that
@ ITEM_RED_SCALE does not exist in this build, so S7 owns the item decision.
MrPokemonsHouse_EventScript__MrPokemon::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_MRPOKEMON_HOOK, MrPokemonsHouse_EventScript__RedScaleRequest
	msgbox MrPokemonsHouse_Text__MrPokemon, MSGBOX_DEFAULT
	release
	end

MrPokemonsHouse_EventScript__RedScaleRequest::
	msgbox MrPokemonsHouse_Text__RedScaleRequest, MSGBOX_DEFAULT
	release
	end

MrPokemonsHouse_EventScript__ForeignMagazines::
	msgbox MrPokemonsHouse_Text__ForeignMagazines, MSGBOX_SIGN
	end

MrPokemonsHouse_EventScript__ForeignMagazines_2::
	msgbox MrPokemonsHouse_Text__ForeignMagazines_2, MSGBOX_SIGN
	end

MrPokemonsHouse_EventScript__BrokenComputer::
	msgbox MrPokemonsHouse_Text__BrokenComputer, MSGBOX_SIGN
	end

MrPokemonsHouse_EventScript__BrokenComputer_2::
	msgbox MrPokemonsHouse_Text__BrokenComputer_2, MSGBOX_SIGN
	end

MrPokemonsHouse_EventScript__StrangeCoins::
	msgbox MrPokemonsHouse_Text__StrangeCoins, MSGBOX_SIGN
	end

MrPokemonsHouse_Text__MrPokemon:
	.string "Word is a strong trainer crossed\nthe sea from HOENN. I wonder if\lthey'll pass through JOHTO too.$"

MrPokemonsHouse_Text__RedScaleRequest:
	.string "Hello, hello! PROF.ELM's CHAMPION!\p"
	.string "Life is delightful. Always new\n"
	.string "discoveries to be made.\p"
	.string "My latest: up north at the LAKE OF\n"
	.string "RAGE, the fishermen swear there's\l"
	.string "a GYARADOS in that water the\l"
	.string "color of blood.\p"
	.string "Red. Not a trick of the light --\n"
	.string "red.\p"
	.string "If you ever stand on that shore,\n"
	.string "bring me a scale. Just one.\p"
	.string "I've something from PROF.OAK I'd\n"
	.string "trade for it. An EXP.SHARE.\p"
	.string "It's no use to an old man with no\n"
	.string "team.$"

MrPokemonsHouse_Text__ForeignMagazines:
	.string "It's packed with\nforeign magazines.\pCan't even read\ntheir titles…$"

MrPokemonsHouse_Text__ForeignMagazines_2:
	.string "It's packed with\nforeign magazines.\pCan't even read\ntheir titles…$"

MrPokemonsHouse_Text__BrokenComputer:
	.string "It's a big com-\nputer. Hmm. It's\lbroken.$"

MrPokemonsHouse_Text__BrokenComputer_2:
	.string "It's a big com-\nputer. Hmm. It's\lbroken.$"

MrPokemonsHouse_Text__StrangeCoins:
	.string "A whole pile of\nstrange coins!\pMaybe they're from\nanother country…$"
