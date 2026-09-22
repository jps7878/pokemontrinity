PalletTown_PlayersHouse_1F_MapScripts::
	.byte 0

PalletTown_PlayersHouse_1F_EventScript_Mom::
	msgbox PalletTown_PlayersHouse_1F_Text_Mom, MSGBOX_NPC
	end

PalletTown_PlayersHouse_1F_EventScript_TV::
	msgbox PalletTown_PlayersHouse_1F_Text_TV, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_1F_Text_Mom:
	.string "A trainer grew up in this house.\pHe left, and he never once\nwrote home.$"

PalletTown_PlayersHouse_1F_Text_TV:
	.string "Oops, wrong side…$"
