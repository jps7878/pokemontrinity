SaffronCity_House_MapScripts::
	.byte 0

SaffronCity_House_EventScript_Lass::
	msgbox SaffronCity_House_Text_Lass, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Youngster::
	msgbox SaffronCity_House_Text_Youngster, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Letter::
	msgbox SaffronCity_House_Text_Letter, MSGBOX_SIGN
	end

SaffronCity_House_Text_Lass:
	.string "…Thank you for writing.\nI hope to see you soon!\p…Hey!\nDon't look at my letter!$"

SaffronCity_House_Text_Youngster:
	.string "The COPYCAT is cute!\nI'm getting her a POKé DOLL.$"

SaffronCity_House_Text_Letter:
	.string "I was given a PP UP as a gift.\pIt's used to increase the PP of\na POKéMON's move.\pI should use it on a powerful move\nwith only a few PP.$"
