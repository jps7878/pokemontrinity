CinnabarIsland_Mart_MapScripts::
	.byte 0

CinnabarIsland_Mart_EventScript_Clerk::
	msgbox CinnabarIsland_Mart_Text_Clerk, MSGBOX_NPC
	end

CinnabarIsland_Mart_EventScript_Woman::
	msgbox CinnabarIsland_Mart_Text_Woman, MSGBOX_NPC
	end

CinnabarIsland_Mart_EventScript_Scientist::
	msgbox CinnabarIsland_Mart_Text_Scientist, MSGBOX_NPC
	end

CinnabarIsland_Mart_Text_Clerk:
	.string "The counter is bare.\pKANTO's marts have had nothing\nto sell for months.$"

CinnabarIsland_Mart_Text_Woman:
	.string "Don't they have X ATTACK?\pI like it because it raises the\nATTACK stat in battle.$"

CinnabarIsland_Mart_Text_Scientist:
	.string "It never hurts to have extra items.\nYou never know what might happen.$"
