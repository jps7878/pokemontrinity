RadioTower1F_MapScripts::
	.byte 0

RadioTower1F_EventScript_Receptionist::
	msgbox RadioTower1F_Text_Receptionist, MSGBOX_NPC
	end

RadioTower1F_EventScript_Directory::
	msgbox RadioTower1F_Text_Directory, MSGBOX_SIGN
	end

RadioTower1F_EventScript_LuckyChannelSign::
	msgbox RadioTower1F_Text_LuckyChannelSign, MSGBOX_SIGN
	end

RadioTower1F_Text_Receptionist:
	.string "Did you hear? A HOENN trainer\nbecame Champion, and now folks\lhere want to challenge them.$"

RadioTower1F_Text_Directory:
	.string "1F RECEPTION\n2F SALES\p3F PERSONNEL\n4F PRODUCTION\p5F DIRECTOR'S\n   OFFICE$"

RadioTower1F_Text_LuckyChannelSign:
	.string "LUCKY CHANNEL!\pWin with POKéMON\nID numbers!\pTrade your POKéMON\nto collect differ-\lent ID numbers!$"
