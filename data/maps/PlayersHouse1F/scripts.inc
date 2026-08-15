PlayersHouse1F_MapScripts::
	.byte 0

@ Trinity M4b S1: NEW BARK flavor, at the GSC inventory's MOM (7,4) and
@ NEIGHBOR (4,4) positions. Reframed -- in Trinity the player's own house is in
@ LITTLEROOT TOWN, HOENN, so this is an ordinary NEW BARK family's home.
PlayersHouse1F_EventScript_Woman::
	msgbox PlayersHouse1F_Text_Woman, MSGBOX_NPC
	end

PlayersHouse1F_EventScript_Neighbor::
	msgbox PlayersHouse1F_Text_Neighbor, MSGBOX_NPC
	end

PlayersHouse1F_EventScript_Stove::
	msgbox PlayersHouse1F_Text_Stove, MSGBOX_SIGN
	end

PlayersHouse1F_EventScript_Sink::
	msgbox PlayersHouse1F_Text_Sink, MSGBOX_SIGN
	end

PlayersHouse1F_EventScript_Fridge::
	msgbox PlayersHouse1F_Text_Fridge, MSGBOX_SIGN
	end

PlayersHouse1F_EventScript_TV::
	msgbox PlayersHouse1F_Text_TV, MSGBOX_SIGN
	end

PlayersHouse1F_Text_Woman:
	.string "Oh! Come in, come in.\p"
	.string "This is NEW BARK TOWN. Nothing\n"
	.string "happens here, ever.\p"
	.string "Then a ship from HOENN docks at\n"
	.string "OLIVINE and suddenly the whole\l"
	.string "town is standing at its windows.$"

PlayersHouse1F_Text_Neighbor:
	.string "Mom says a real CHAMPION came all\n"
	.string "the way from HOENN just to visit\l"
	.string "PROF.ELM.\p"
	.string "When I'm older I'm going the\n"
	.string "other way. HOENN has the sea.$"

PlayersHouse1F_Text_Stove:
	.string "Mom's specialty!\pCINNABAR VOLCANO\nBURGER!$"

PlayersHouse1F_Text_Sink:
	.string "The sink is spot-\nless. Mom likes it\lclean.$"

PlayersHouse1F_Text_Fridge:
	.string "Let's see what's\nin the fridge…\pFRESH WATER and\ntasty LEMONADE!$"

PlayersHouse1F_Text_TV:
	.string "There's a movie on\nTV: Stars dot the\psky as two boys\nride on a train…\pI'd better get\nrolling too!$"
