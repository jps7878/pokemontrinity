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
	.string "My grandkids keep going on about\nsome trainer from HOENN. Sounds\llike quite the journey so far.$"

Route11_EastEntrance_2F_Text_Aide:
	.string "My grandkids keep going on about\nsome trainer from HOENN. Sounds\llike quite the journey so far.$"

Route11_EastEntrance_2F_Text_LeftBinoculars:
	.string "KANTO's peaceful most days, but\neven here we've heard the stories\labout that HOENN trainer.$"

Route11_EastEntrance_2F_Text_RightBinoculars:
	.string "Let's see what the binoculars have\nto show…\pTo get to LAVENDER TOWN from\nCERULEAN CITY…\pROCK TUNNEL appears to be a good\nroute to take.$"
