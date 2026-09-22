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
	.string "This route's seen more traffic\nlately. Something about a\lchampion passing in from JOHTO.$"

Route12_NorthEntrance_2F_Text_LeftBinoculars:
	.string "Let's see what the binoculars have\nto show…\pThere's a man fishing!$"

Route12_NorthEntrance_2F_Text_RightBinoculars:
	.string "Let's see what the binoculars have\nto show…\pIt's POKéMON TOWER!$"
