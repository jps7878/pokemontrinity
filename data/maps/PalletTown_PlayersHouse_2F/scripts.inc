PalletTown_PlayersHouse_2F_MapScripts::
	.byte 0

PalletTown_PlayersHouse_2F_EventScript_NES::
	msgbox PalletTown_PlayersHouse_2F_Text_NES, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_2F_EventScript_PC::
	msgbox PalletTown_PlayersHouse_2F_Text_PC, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_2F_EventScript_Sign::
	msgbox PalletTown_PlayersHouse_2F_Text_Sign, MSGBOX_SIGN
	end

PalletTown_PlayersHouse_2F_Text_NES:
	.string "{PLAYER} played with the NES.\p…Okay!\nIt's time to go!$"

PalletTown_PlayersHouse_2F_Text_PC:
	.string "The PC is powered down.\nThe one in the CENTER isn't.$"

PalletTown_PlayersHouse_2F_Text_Sign:
	.string "It's a posted notice…\pIf you're confused, ask for HELP!\nPress the L or R Button!$"
