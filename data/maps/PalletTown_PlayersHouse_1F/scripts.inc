PalletTown_PlayersHouse_1F_MapScripts::
	.byte 0

PalletTown_PlayersHouse_1F_EventScript_Mom::
	msgbox PalletTown_PlayersHouse_1F_Text_Mom, MSGBOX_NPC
	end

PalletTown_PlayersHouse_1F_EventScript_TV::
	msgbox PalletTown_PlayersHouse_1F_Text_TV, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_1F_Text_Mom:
	.string "This route's seen more foot traffic\nlately. Something about a champion\lpassing through from JOHTO.$"

PalletTown_PlayersHouse_1F_Text_TV:
	.string "KANTO's a long way from HOENN,\nbut word of that champion still\lmade it all the way here.$"
