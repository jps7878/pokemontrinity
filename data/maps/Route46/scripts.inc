Route46_MapScripts::
	.byte 0

Route46_EventScript_BAILEY::
	trainerbattle_single TRAINER_JOHTO_HIKER_BAILEY, Route46_Text_BAILEYSeen, Route46_Text_BAILEYBeaten
	msgbox Route46_Text_BAILEYBeaten, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_TED::
	trainerbattle_single TRAINER_JOHTO_CAMPER_TED, Route46_Text_TEDSeen, Route46_Text_TEDBeaten
	msgbox Route46_Text_TEDBeaten, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_ERIN1::
	trainerbattle_single TRAINER_JOHTO_PICNICKER_ERIN1, Route46_Text_ERIN1Seen, Route46_Text_ERIN1Beaten
	msgbox Route46_Text_ERIN1Beaten, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Sign::
	msgbox Route46_Text_Sign, MSGBOX_SIGN
	end

Route46_Text_BAILEYSeen:
	.string "Awright! I'll show\nyou the power of\lmountain POKéMON!$"

Route46_Text_BAILEYBeaten:
	.string "Mercy! You showed\nme your power!$"

Route46_Text_TEDSeen:
	.string "I'm raising POKé-\nMON too!\pWill you battle\nwith me?$"

Route46_Text_TEDBeaten:
	.string "Wha…?$"

Route46_Text_ERIN1Seen:
	.string "I raise POKéMON\ntoo!\pWill you battle\nwith me?$"

Route46_Text_ERIN1Beaten:
	.string "Oh, rats!$"

Route46_Text_Sign:
	.string "ROUTE 46\nMOUNTAIN RD. AHEAD$"
