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
	.string "I've got to buy some POTIONS.\pYou never know when your POKéMON\nwill need quick healing.$"

ViridianCity_Mart_Text_Woman:
	.string "This shop does good business in\nANTIDOTES, I've heard.$"
