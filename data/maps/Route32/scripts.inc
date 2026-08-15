Route32_MapScripts::
	.byte 0

Route32_EventScript_JUSTIN::
	trainerbattle_single TRAINER_JOHTO_FISHER_JUSTIN, Route32_Text_JUSTINSeen, Route32_Text_JUSTINBeaten
	msgbox Route32_Text_JUSTINBeaten, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_RALPH1::
	trainerbattle_single TRAINER_JOHTO_FISHER_RALPH1, Route32_Text_RALPH1Seen, Route32_Text_RALPH1Beaten
	msgbox Route32_Text_RALPH1Beaten, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_HENRY::
	trainerbattle_single TRAINER_JOHTO_FISHER_HENRY, Route32_Text_HENRYSeen, Route32_Text_HENRYBeaten
	msgbox Route32_Text_HENRYBeaten, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_ALBERT::
	trainerbattle_single TRAINER_JOHTO_YOUNGSTER_ALBERT, Route32_Text_ALBERTSeen, Route32_Text_ALBERTBeaten
	msgbox Route32_Text_ALBERTBeaten, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_GORDON::
	trainerbattle_single TRAINER_JOHTO_YOUNGSTER_GORDON, Route32_Text_GORDONSeen, Route32_Text_GORDONBeaten
	msgbox Route32_Text_GORDONBeaten, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_ROLAND::
	trainerbattle_single TRAINER_JOHTO_CAMPER_ROLAND, Route32_Text_ROLANDSeen, Route32_Text_ROLANDBeaten
	msgbox Route32_Text_ROLANDBeaten, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_LIZ1::
	trainerbattle_single TRAINER_JOHTO_PICNICKER_LIZ1, Route32_Text_LIZ1Seen, Route32_Text_LIZ1Beaten
	msgbox Route32_Text_LIZ1Beaten, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_CooltrainerM::
	msgbox Route32_Text_CooltrainerM, MSGBOX_NPC
	end

Route32_EventScript_PETER::
	trainerbattle_single TRAINER_JOHTO_BIRD_KEEPER_PETER, Route32_Text_PETERSeen, Route32_Text_PETERBeaten
	msgbox Route32_Text_PETERBeaten, MSGBOX_AUTOCLOSE
	end

Route32_EventScript_RoarTMGuy::
	msgbox Route32_Text_RoarTMGuy, MSGBOX_NPC
	end

Route32_EventScript_Sign::
	msgbox Route32_Text_Sign, MSGBOX_SIGN
	end

Route32_EventScript_RuinsSign::
	msgbox Route32_Text_RuinsSign, MSGBOX_SIGN
	end

Route32_EventScript_UnionCaveSign::
	msgbox Route32_Text_UnionCaveSign, MSGBOX_SIGN
	end

Route32_Text_JUSTINSeen:
	.string "Whoa!\pYou made me lose\nthat fish!$"

Route32_Text_JUSTINBeaten:
	.string "Sploosh!$"

Route32_Text_RALPH1Seen:
	.string "I'm really good at\nboth fishing and\lPOKéMON.\pI'm not about to\nlose to any kid!$"

Route32_Text_RALPH1Beaten:
	.string "Tch! I tried to\nrush things…$"

Route32_Text_HENRYSeen:
	.string "My POKéMON?\nFreshly caught!$"

Route32_Text_HENRYBeaten:
	.string "SPLASH?$"

Route32_Text_ALBERTSeen:
	.string "I haven't seen you\naround before.\pSo you think you\nare pretty tough?$"

Route32_Text_ALBERTBeaten:
	.string "You're strong!$"

Route32_Text_GORDONSeen:
	.string "I found some good\nPOKéMON in the\lgrass!\pI think they'll do\nit for me!$"

Route32_Text_GORDONBeaten:
	.string "Darn. I thought I\ncould win.$"

Route32_Text_ROLANDSeen:
	.string "That glance…\nIt's intriguing.$"

Route32_Text_ROLANDBeaten:
	.string "Hmmm. This is\ndisappointing.$"

Route32_Text_LIZ1Seen:
	.string "Uh-huh. Yeah, and\nyou know…\pPardon? Battle?\nI'm on the phone.\pOh, all right. But\nmake it fast.$"

Route32_Text_LIZ1Beaten:
	.string "Oh! I've got to\nrelieve my anger!$"

Route32_Text_CooltrainerM:
	.string "My grandkids won't stop talking\nabout the new champion from over\lin HOENN. Kids these days!$"

Route32_Text_PETERSeen:
	.string "That BADGE! It's\nfrom VIOLET CITY!\pYou beat FALKNER?$"

Route32_Text_PETERBeaten:
	.string "I know what my\nweaknesses are.$"

Route32_Text_RoarTMGuy:
	.string "My grandkids won't stop talking\nabout the new champion from over\lin HOENN. Kids these days!$"

Route32_Text_Sign:
	.string "ROUTE 32\pVIOLET CITY -\nAZALEA TOWN$"

Route32_Text_RuinsSign:
	.string "RUINS OF ALPH\nEAST ENTRANCE$"

Route32_Text_UnionCaveSign:
	.string "UNION CAVE\nAHEAD$"
