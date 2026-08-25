Route21_South_MapScripts::
	.byte 0

Route21_South_EventScript_Claude::
	trainerbattle_single TRAINER_KANTO_FISHERMAN_CLAUDE, Route21_South_Text_ClaudeSeen, Route21_South_Text_ClaudeBeaten
	msgbox Route21_South_Text_ClaudeBeaten, MSGBOX_AUTOCLOSE
	end

Route21_South_EventScript_Nolan::
	trainerbattle_single TRAINER_KANTO_FISHERMAN_NOLAN, Route21_South_Text_NolanSeen, Route21_South_Text_NolanBeaten
	msgbox Route21_South_Text_NolanBeaten, MSGBOX_AUTOCLOSE
	end

Route21_South_EventScript_Jack::
	trainerbattle_single TRAINER_KANTO_SWIMMER_M_JACK, Route21_South_Text_JackSeen, Route21_South_Text_JackBeaten
	msgbox Route21_South_Text_JackBeaten, MSGBOX_AUTOCLOSE
	end

Route21_South_EventScript_Jerome::
	trainerbattle_single TRAINER_KANTO_SWIMMER_M_JEROME, Route21_South_Text_JeromeSeen, Route21_South_Text_JeromeBeaten
	msgbox Route21_South_Text_JeromeBeaten, MSGBOX_AUTOCLOSE
	end

Route21_South_EventScript_Roland::
	trainerbattle_single TRAINER_KANTO_SWIMMER_M_ROLAND, Route21_South_Text_RolandSeen, Route21_South_Text_RolandBeaten
	msgbox Route21_South_Text_RolandBeaten, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_ClaudeSeen:
	.string "…$"

Route21_South_Text_ClaudeBeaten:
	.string "…$"

Route21_South_Text_NolanSeen:
	.string "…$"

Route21_South_Text_NolanBeaten:
	.string "…$"

Route21_South_Text_JackSeen:
	.string "…$"

Route21_South_Text_JackBeaten:
	.string "…$"

Route21_South_Text_JeromeSeen:
	.string "…$"

Route21_South_Text_JeromeBeaten:
	.string "…$"

Route21_South_Text_RolandSeen:
	.string "…$"

Route21_South_Text_RolandBeaten:
	.string "…$"
