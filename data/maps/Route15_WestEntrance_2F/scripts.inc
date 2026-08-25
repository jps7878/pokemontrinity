Route15_WestEntrance_2F_MapScripts::
	.byte 0

Route15_WestEntrance_2F_EventScript_Aide::
	msgbox Route15_WestEntrance_2F_Text_Aide, MSGBOX_NPC
	end

Route15_WestEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route15_WestEntrance_2F_Text_LeftBinoculars, MSGBOX_SIGN
	end

Route15_WestEntrance_2F_EventScript_RightBinoculars::
	msgbox Route15_WestEntrance_2F_Text_RightBinoculars, MSGBOX_SIGN
	end

Route15_WestEntrance_2F_Text_Aide:
	.string "I've fished this stretch of KANTO\nfor years. Lately it's all anyone\ltalks about -- some far-off champion.$"

Route15_WestEntrance_2F_Text_LeftBinoculars:
	.string "This route's seen more foot traffic\nlately. Something about a champion\lpassing through from JOHTO.$"

Route15_WestEntrance_2F_Text_RightBinoculars:
	.string "Let's see what the binoculars have\nto show…\pIt looks like a small island on\nthe horizon!$"
