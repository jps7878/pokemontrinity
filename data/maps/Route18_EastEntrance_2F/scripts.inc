Route18_EastEntrance_2F_MapScripts::
	.byte 0

Route18_EastEntrance_2F_EventScript_Haden::
	msgbox Route18_EastEntrance_2F_Text_Haden, MSGBOX_NPC
	end

Route18_EastEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route18_EastEntrance_2F_Text_LeftBinoculars, MSGBOX_SIGN
	end

Route18_EastEntrance_2F_EventScript_RightBinoculars::
	msgbox Route18_EastEntrance_2F_Text_RightBinoculars, MSGBOX_SIGN
	end

Route18_EastEntrance_2F_Text_Haden:
	.string "No trades. Everybody wants what\nthe champion has. I'd lose.$"

Route18_EastEntrance_2F_Text_LeftBinoculars:
	.string "Let's see what the binoculars have\nto show…\pPALLET TOWN is in the west.$"

Route18_EastEntrance_2F_Text_RightBinoculars:
	.string "Let's see what the binoculars have\nto show…\pThere are people swimming.$"
