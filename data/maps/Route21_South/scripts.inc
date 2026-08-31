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
	.string "CINNABAR's volcano keeps this\nwater warm year-round. Nice, eh?$"

Route21_South_Text_ClaudeBeaten:
	.string "Not as nice as your POKéMON,\napparently.$"

Route21_South_Text_NolanSeen:
	.string "Heading to CINNABAR? Not before\nyou battle me!$"

Route21_South_Text_NolanBeaten:
	.string "Go on, then. You've earned it.$"

Route21_South_Text_JackSeen:
	.string "This close to the volcano, even\nthe sea feels alive.$"

Route21_South_Text_JackBeaten:
	.string "So does your POKéMON team,\nturns out.$"

Route21_South_Text_JeromeSeen:
	.string "One more battle before I head\ninto CINNABAR myself.$"

Route21_South_Text_JeromeBeaten:
	.string "Guess that's one battle I'll\nremember.$"

Route21_South_Text_RolandSeen:
	.string "Last stretch of open water\nbefore dry land. Ready?$"

Route21_South_Text_RolandBeaten:
	.string "You made it look easy.$"
