AzaleaTown_MapScripts::
	.byte 0

AzaleaTown_EventScript_Gramps::
	msgbox AzaleaTown_Text_Gramps, MSGBOX_NPC
	end

AzaleaTown_EventScript_Teacher::
	msgbox AzaleaTown_Text_Teacher, MSGBOX_NPC
	end

AzaleaTown_EventScript_Youngster::
	msgbox AzaleaTown_Text_Youngster, MSGBOX_NPC
	end

AzaleaTown_EventScript_Sign::
	msgbox AzaleaTown_Text_Sign, MSGBOX_SIGN
	end

AzaleaTown_EventScript_KurtsHouseSign::
	msgbox AzaleaTown_Text_KurtsHouseSign, MSGBOX_SIGN
	end

AzaleaTown_EventScript_AzaleaGymSign::
	msgbox AzaleaTown_Text_AzaleaGymSign, MSGBOX_SIGN
	end

AzaleaTown_EventScript_SlowpokeWellSign::
	msgbox AzaleaTown_Text_SlowpokeWellSign, MSGBOX_SIGN
	end

AzaleaTown_EventScript_CharcoalKilnSign::
	msgbox AzaleaTown_Text_CharcoalKilnSign, MSGBOX_SIGN
	end

AzaleaTown_EventScript_IlextForestSign::
	msgbox AzaleaTown_Text_IlextForestSign, MSGBOX_SIGN
	end

AzaleaTown_Text_Gramps:
	.string "Did you hear? A HOENN trainer\nbecame Champion, and now folks\lhere want to challenge them.$"

AzaleaTown_Text_Teacher:
	.string "Did you come to\nget KURT to make\lsome BALLS?\pA lot of people do\njust that.$"

AzaleaTown_Text_Youngster:
	.string "Cut through AZALEA\nand you'll be in\lILEX FOREST.\pBut these skinny\ntrees make it\pimpossible to get\nthrough.\pThe CHARCOAL MAN's\nPOKéMON can CUT\ldown trees.$"

AzaleaTown_Text_Sign:
	.string "AZALEA TOWN\nWhere People and\pPOKéMON Live in\nHappy Harmony$"

AzaleaTown_Text_KurtsHouseSign:
	.string "KURT'S HOUSE$"

AzaleaTown_Text_AzaleaGymSign:
	.string "AZALEA TOWN\nPOKéMON GYM\lLEADER: BUGSY\pThe Walking\nBug POKéMON\lEncyclopedia$"

AzaleaTown_Text_SlowpokeWellSign:
	.string "SLOWPOKE WELL\pAlso known as the\nRAINMAKER WELL.\pLocals believe\nthat a SLOWPOKE's\lyawn summons rain.\pRecords show that\na SLOWPOKE's yawn\pended a drought\n400 years ago.$"

AzaleaTown_Text_CharcoalKilnSign:
	.string "CHARCOAL KILN$"

AzaleaTown_Text_IlextForestSign:
	.string "ILEX FOREST\pEnter through the\ngate.$"
