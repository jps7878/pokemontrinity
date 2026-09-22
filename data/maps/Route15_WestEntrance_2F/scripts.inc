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
	.string "PROF. OAK's aides stopped handing\nthings out. Too many trainers\lnow -- and one of them is you.$"

Route15_WestEntrance_2F_Text_LeftBinoculars:
	.string "The binoculars look out to sea.\nNothing is flying today.$"

Route15_WestEntrance_2F_Text_RightBinoculars:
	.string "Let's see what the binoculars have\nto show…\pIt looks like a small island on\nthe horizon!$"
