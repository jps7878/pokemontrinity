Route11_EastEntrance_2F_MapScripts::
	.byte 0

Route11_EastEntrance_2F_EventScript_Turner::
	msgbox Route11_EastEntrance_2F_Text_Turner, MSGBOX_NPC
	end

Route11_EastEntrance_2F_EventScript_Aide::
	msgbox Route11_EastEntrance_2F_Text_Aide, MSGBOX_NPC
	end

Route11_EastEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route11_EastEntrance_2F_Text_LeftBinoculars, MSGBOX_SIGN
	end

Route11_EastEntrance_2F_EventScript_RightBinoculars::
	msgbox Route11_EastEntrance_2F_Text_RightBinoculars, MSGBOX_SIGN
	end

Route11_EastEntrance_2F_Text_Turner:
	.string "Want to trade? Bring something\nKANTO hasn't already seen.$"

Route11_EastEntrance_2F_Text_Aide:
	.string "PROF. OAK's aides stopped handing\nthings out. Too many trainers\lnow -- and one of them is you.$"

Route11_EastEntrance_2F_Text_LeftBinoculars:
	.string "The binoculars look south over\nROUTE 12. Nothing is moving.$"

Route11_EastEntrance_2F_Text_RightBinoculars:
	.string "Let's see what the binoculars have\nto show…\pTo get to LAVENDER TOWN from\nCERULEAN CITY…\pROCK TUNNEL appears to be a good\nroute to take.$"
