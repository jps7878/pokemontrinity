Route11_EastEntrance_1F_MapScripts::
	.byte 0

Route11_EastEntrance_1F_EventScript_TopGuard::
	msgbox Route11_EastEntrance_1F_Text_TopGuard, MSGBOX_NPC
	end

Route11_EastEntrance_1F_EventScript_BottomGuard::
	msgbox Route11_EastEntrance_1F_Text_BottomGuard, MSGBOX_NPC
	end

Route11_EastEntrance_1F_Text_TopGuard:
	.string "Don't you think it's hard to think\nup good names for POKéMON?\pEspecially if you've caught a\nwhole bunch?\pIn LAVENDER TOWN, there's a man\nwho rates POKéMON nicknames.\pHe can even help you rename your\nPOKéMON, too.$"

Route11_EastEntrance_1F_Text_BottomGuard:
	.string "If you're aiming to reach LAVENDER\nTOWN, take ROCK TUNNEL.\pYou can get to ROCK TUNNEL from\nCERULEAN CITY.$"
