Route21_North_MapScripts::
	.byte 0

Route21_North_EventScript_Ronald::
	trainerbattle_single TRAINER_KANTO_FISHERMAN_RONALD, Route21_North_Text_RonaldSeen, Route21_North_Text_RonaldBeaten
	msgbox Route21_North_Text_RonaldBeaten, MSGBOX_AUTOCLOSE
	end

Route21_North_EventScript_Wade::
	trainerbattle_single TRAINER_KANTO_FISHERMAN_WADE, Route21_North_Text_WadeSeen, Route21_North_Text_WadeBeaten
	msgbox Route21_North_Text_WadeBeaten, MSGBOX_AUTOCLOSE
	end

Route21_North_EventScript_Spencer::
	trainerbattle_single TRAINER_KANTO_SWIMMER_M_SPENCER, Route21_North_Text_SpencerSeen, Route21_North_Text_SpencerBeaten
	msgbox Route21_North_Text_SpencerBeaten, MSGBOX_AUTOCLOSE
	end

Route21_North_EventScript_Lil::
	trainerbattle_single TRAINER_KANTO_SIS_AND_BRO_LIL_IAN, Route21_North_Text_LilSeen, Route21_North_Text_LilBeaten
	msgbox Route21_North_Text_LilBeaten, MSGBOX_AUTOCLOSE
	end

Route21_North_EventScript_Ian::
	trainerbattle_single TRAINER_KANTO_SIS_AND_BRO_LIL_IAN_2, Route21_North_Text_IanSeen, Route21_North_Text_IanBeaten
	msgbox Route21_North_Text_IanBeaten, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_RonaldSeen:
	.string "…$"

Route21_North_Text_RonaldBeaten:
	.string "…$"

Route21_North_Text_WadeSeen:
	.string "…$"

Route21_North_Text_WadeBeaten:
	.string "…$"

Route21_North_Text_SpencerSeen:
	.string "…$"

Route21_North_Text_SpencerBeaten:
	.string "…$"

Route21_North_Text_LilSeen:
	.string "…$"

Route21_North_Text_LilBeaten:
	.string "…$"

Route21_North_Text_IanSeen:
	.string "…$"

Route21_North_Text_IanBeaten:
	.string "…$"
