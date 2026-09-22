ViridianCity_Mart_MapScripts::
	.byte 0

ViridianCity_Mart_EventScript_Clerk::
	msgbox ViridianCity_Mart_Text_Clerk, MSGBOX_NPC
	end

ViridianCity_Mart_EventScript_Youngster::
	msgbox ViridianCity_Mart_Text_Youngster, MSGBOX_NPC
	end

ViridianCity_Mart_EventScript_Woman::
	msgbox ViridianCity_Mart_Text_Woman, MSGBOX_NPC
	end

ViridianCity_Mart_Text_Clerk:
	.string "The counter is bare.\pKANTO's marts have had nothing\nto sell for months.$"

ViridianCity_Mart_Text_Youngster:
	.string "I came in for POTIONS.\pThe shelves have been empty\nevery day I've tried.$"

ViridianCity_Mart_Text_Woman:
	.string "This shop did good business in\nANTIDOTES, I'm told.\pI've never seen it stocked.$"
