PlayersHouse1F_MapScripts::
	.byte 0

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

PlayersHouse1F_Text_Stove:
	.string "Mom's specialty!\pCINNABAR VOLCANO\nBURGER!$"

PlayersHouse1F_Text_Sink:
	.string "The sink is spot-\nless. Mom likes it\lclean.$"

PlayersHouse1F_Text_Fridge:
	.string "Let's see what's\nin the fridge…\pFRESH WATER and\ntasty LEMONADE!$"

PlayersHouse1F_Text_TV:
	.string "There's a movie on\nTV: Stars dot the\psky as two boys\nride on a train…\pI'd better get\nrolling too!$"
