Route37_MapScripts::
	.byte 0

Route37_EventScript_ANNANDANNE1::
	trainerbattle_single TRAINER_JOHTO_TWINS_ANNANDANNE1, Route37_Text_ANNANDANNE1Seen, Route37_Text_ANNANDANNE1Beaten
	msgbox Route37_Text_ANNANDANNE1Beaten, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_ANNANDANNE2::
	trainerbattle_single TRAINER_JOHTO_TWINS_ANNANDANNE2, Route37_Text_ANNANDANNE2Seen, Route37_Text_ANNANDANNE2Beaten
	msgbox Route37_Text_ANNANDANNE2Beaten, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_GREG::
	trainerbattle_single TRAINER_JOHTO_PSYCHIC_T_GREG, Route37_Text_GREGSeen, Route37_Text_GREGBeaten
	msgbox Route37_Text_GREGBeaten, MSGBOX_AUTOCLOSE
	end

Route37_EventScript_Sign::
	msgbox Route37_Text_Sign, MSGBOX_SIGN
	end

Route37_Text_ANNANDANNE1Seen:
	.string "ANN: ANNE and I\nare in this to-\lgether!$"

Route37_Text_ANNANDANNE1Beaten:
	.string "ANN & ANNE: Nnn… A\nlittle too strong.$"

Route37_Text_ANNANDANNE2Seen:
	.string "ANNE: ANN and I\nare in this to-\lgether!$"

Route37_Text_ANNANDANNE2Beaten:
	.string "ANN & ANNE: Nnn… A\nlittle too strong.$"

Route37_Text_GREGSeen:
	.string "POKéMON can't do a\nthing if they are\lasleep.\pI'll show you how\nscary that is!$"

Route37_Text_GREGBeaten:
	.string "I lost. That's\npretty sad…$"

Route37_Text_Sign:
	.string "ROUTE 37$"
