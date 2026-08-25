FuchsiaCity_Mart_MapScripts::
	.byte 0

FuchsiaCity_Mart_EventScript_Clerk::
	msgbox FuchsiaCity_Mart_Text_Clerk, MSGBOX_NPC
	end

FuchsiaCity_Mart_EventScript_Gentleman::
	msgbox FuchsiaCity_Mart_Text_Gentleman, MSGBOX_NPC
	end

FuchsiaCity_Mart_EventScript_CooltrainerF::
	msgbox FuchsiaCity_Mart_Text_CooltrainerF, MSGBOX_NPC
	end

FuchsiaCity_Mart_Text_Clerk:
	.string "KANTO's a long way from HOENN,\nbut word of that champion still\lmade it all the way here.$"

FuchsiaCity_Mart_Text_Gentleman:
	.string "Don't they have any pennants\npromoting the SAFARI ZONE?\pHow about some paper lanterns?\nAren't there even any calendars?$"

FuchsiaCity_Mart_Text_CooltrainerF:
	.string "Did you try X SPEED?\nIt speeds up a POKéMON in battle.$"
