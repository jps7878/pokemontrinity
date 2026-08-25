Route12_NorthEntrance_2F_MapScripts::
	.byte 0

Route12_NorthEntrance_2F_EventScript_Lass::
	msgbox Route12_NorthEntrance_2F_Text_Lass, MSGBOX_NPC
	end

Route12_NorthEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route12_NorthEntrance_2F_Text_LeftBinoculars, MSGBOX_SIGN
	end

Route12_NorthEntrance_2F_EventScript_RightBinoculars::
	msgbox Route12_NorthEntrance_2F_Text_RightBinoculars, MSGBOX_SIGN
	end

Route12_NorthEntrance_2F_Text_Lass:
	.string "KANTO's a long way from HOENN,\nbut word of that champion still\lmade it all the way here.$"

Route12_NorthEntrance_2F_Text_LeftBinoculars:
	.string "Let's see what the binoculars have\nto show…\pThere's a man fishing!$"

Route12_NorthEntrance_2F_Text_RightBinoculars:
	.string "Let's see what the binoculars have\nto show…\pIt's POKéMON TOWER!$"
