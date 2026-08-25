PalletTown_MapScripts::
	.byte 0

PalletTown_EventScript_SignLady::
	msgbox PalletTown_Text_SignLady, MSGBOX_NPC
	end

PalletTown_EventScript_FatMan::
	msgbox PalletTown_Text_FatMan, MSGBOX_NPC
	end

PalletTown_EventScript_OaksLabSign::
	msgbox PalletTown_Text_OaksLabSign, MSGBOX_SIGN
	end

PalletTown_EventScript_PlayersHouseSign::
	msgbox PalletTown_Text_PlayersHouseSign, MSGBOX_SIGN
	end

PalletTown_EventScript_RivalsHouseSign::
	msgbox PalletTown_Text_RivalsHouseSign, MSGBOX_SIGN
	end

PalletTown_EventScript_TownSign::
	msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
	end

PalletTown_EventScript_TrainerTips::
	msgbox PalletTown_Text_TrainerTips, MSGBOX_SIGN
	end

PalletTown_Text_SignLady:
	.string "KANTO's peaceful most days, but\neven here we've heard the stories\labout that HOENN trainer.$"

PalletTown_Text_FatMan:
	.string "Technology is incredible!\pYou can now store and recall items\nand POKéMON as data via PC.$"

PalletTown_Text_OaksLabSign:
	.string "I never put much stock in rumors,\nbut two Leagues cleared is two\lLeagues cleared. Impressive.$"

PalletTown_Text_PlayersHouseSign:
	.string "{PLAYER}'s house$"

PalletTown_Text_RivalsHouseSign:
	.string "{RIVAL}'s house$"

PalletTown_Text_TownSign:
	.string "PALLET TOWN\nShades of your journey await!$"

PalletTown_Text_TrainerTips:
	.string "KANTO's got its own trainers worth\nwatching, but even we're curious\labout this HOENN-JOHTO champion.$"
