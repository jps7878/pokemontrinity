Route31_MapScripts::
	.byte 0

Route31_EventScript_MailRecipient::
	msgbox Route31_Text_MailRecipient, MSGBOX_NPC
	end

Route31_EventScript_Youngster::
	msgbox Route31_Text_Youngster, MSGBOX_NPC
	end

Route31_EventScript_WADE1::
	trainerbattle_single TRAINER_JOHTO_BUG_CATCHER_WADE1, Route31_Text_WADE1Seen, Route31_Text_WADE1Beaten
	msgbox Route31_Text_WADE1Beaten, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_CooltrainerM::
	msgbox Route31_Text_CooltrainerM, MSGBOX_NPC
	end

Route31_EventScript_Sign::
	msgbox Route31_Text_Sign, MSGBOX_SIGN
	end

Route31_EventScript_DarkCaveSign::
	msgbox Route31_Text_DarkCaveSign, MSGBOX_SIGN
	end

Route31_Text_MailRecipient:
	.string "My grandkids won't stop talking\nabout the new champion from over\lin HOENN. Kids these days!$"

Route31_Text_Youngster:
	.string "I found a good\nPOKéMON in DARK\lCAVE.\pI'm going to raise\nit to take on\lFALKNER.\pHe's the leader of\nVIOLET CITY's GYM.$"

Route31_Text_WADE1Seen:
	.string "I caught a bunch\nof POKéMON. Let me\lbattle with you!$"

Route31_Text_WADE1Beaten:
	.string "Awwwww…$"

Route31_Text_CooltrainerM:
	.string "DARK CAVE…\pIf POKéMON could\nlight it up, I'd\lexplore it.$"

Route31_Text_Sign:
	.string "ROUTE 31\pVIOLET CITY -\nCHERRYGROVE CITY$"

Route31_Text_DarkCaveSign:
	.string "DARK CAVE$"
