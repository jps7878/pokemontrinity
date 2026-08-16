MrPokemonsHouse_MapScripts::
	.byte 0

@ Trinity M4b S1: once PROF.ELM has named him (FLAG_TRINITY_J_MRPOKEMON_HOOK),
@ MR.POKéMON seeds the Red Scale request -- adapted from pokecrystal
@ MrPokemonText_GimmeTheScale (MrPokemonsHouse.asm:329-343).
@
@ M4b S7 pays it off, and owns the item-vs-flag ruling S1 handed forward:
@ ITEM_RED_SCALE does NOT exist in this build (verified across
@ include/constants/items.h and src/data/items.h), so the scale ships as
@ FLAG_TRINITY_J_RED_SCALE -- S1's own precedent, and S6's SECRETPOTION.
@
@ GUARD ORDER IS THE POINT (S6's terminal-state rule). The scale is a
@ CONSUMABLE carried by a flag: this script CLEARS it on the trade, so after
@ the trade the scale flag reads exactly as it did before the LAKE OF RAGE.
@ A chain with a clearflag in it must therefore test its TERMINAL state
@ FIRST -- hence FLAG_TRINITY_J_EXP_SHARE before FLAG_TRINITY_J_RED_SCALE.
@ (This is the defect that bit S6's CIANWOOD PHARMACIST.)
@
@ The gift itself is GYM PATTERN G2-shaped: giveitem, then the VAR_RESULT
@ check, and only then the two flag writes -- so a full bag costs the player
@ nothing and the trade is re-offered on the next visit. GSC's own
@ `giveitem RED_SCALE` at the lake has no such check and silently eats the
@ scale; the flag form cannot have that bug.
MrPokemonsHouse_EventScript__MrPokemon::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_EXP_SHARE, MrPokemonsHouse_EventScript__AlreadyTraded
	goto_if_set FLAG_TRINITY_J_RED_SCALE, MrPokemonsHouse_EventScript__RedScaleTrade
	goto_if_set FLAG_TRINITY_J_MRPOKEMON_HOOK, MrPokemonsHouse_EventScript__RedScaleRequest
	msgbox MrPokemonsHouse_Text__MrPokemon, MSGBOX_DEFAULT
	release
	end

MrPokemonsHouse_EventScript__RedScaleRequest::
	msgbox MrPokemonsHouse_Text__RedScaleRequest, MSGBOX_DEFAULT
	release
	end

MrPokemonsHouse_EventScript__RedScaleTrade::
	msgbox MrPokemonsHouse_Text__RedScaleTrade, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_J_EXP_SHARE
	clearflag FLAG_TRINITY_J_RED_SCALE
	msgbox MrPokemonsHouse_Text__ExpShareExplained, MSGBOX_DEFAULT
	release
	end

MrPokemonsHouse_EventScript__AlreadyTraded::
	msgbox MrPokemonsHouse_Text__AlreadyTraded, MSGBOX_DEFAULT
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

MrPokemonsHouse_Text__RedScaleTrade:
	.string "That -- that is the SCALE!\p"
	.string "Red as a coal. Warm, even.\n"
	.string "Delightful. Simply delightful.\p"
	.string "A trade is a trade. The EXP.SHARE\n"
	.string "is yours.$"

MrPokemonsHouse_Text__ExpShareExplained:
	.string "Hold it on one of your team and\n"
	.string "it takes a share of every battle,\l"
	.string "whether it fought or not.\p"
	.string "PROF.OAK swears by them. Good\n"
	.string "for the ones still growing.$"

MrPokemonsHouse_Text__AlreadyTraded:
	.string "The RED SCALE sits on my desk\n"
	.string "and it still hasn't faded.\p"
	.string "Life is delightful. Always new\n"
	.string "discoveries to be made.$"

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
