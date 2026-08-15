Route38_MapScripts::
	.byte 0

Route38_EventScript_CHAD1::
	trainerbattle_single TRAINER_JOHTO_SCHOOLBOY_CHAD1, Route38_Text_CHAD1Seen, Route38_Text_CHAD1Beaten
	msgbox Route38_Text_CHAD1Beaten, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_DANA1::
	trainerbattle_single TRAINER_JOHTO_LASS_DANA1, Route38_Text_DANA1Seen, Route38_Text_DANA1Beaten
	msgbox Route38_Text_DANA1Beaten, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_TOBY::
	trainerbattle_single TRAINER_JOHTO_BIRD_KEEPER_TOBY, Route38_Text_TOBYSeen, Route38_Text_TOBYBeaten
	msgbox Route38_Text_TOBYBeaten, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_VALERIE::
	trainerbattle_single TRAINER_JOHTO_BEAUTY_VALERIE, Route38_Text_VALERIESeen, Route38_Text_VALERIEBeaten
	msgbox Route38_Text_VALERIEBeaten, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_HARRY::
	trainerbattle_single TRAINER_JOHTO_SAILOR_HARRY, Route38_Text_HARRYSeen, Route38_Text_HARRYBeaten
	msgbox Route38_Text_HARRYBeaten, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_OLIVIA::
	trainerbattle_single TRAINER_JOHTO_BEAUTY_OLIVIA, Route38_Text_OLIVIASeen, Route38_Text_OLIVIABeaten
	msgbox Route38_Text_OLIVIABeaten, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Sign::
	msgbox Route38_Text_Sign, MSGBOX_SIGN
	end

Route38_EventScript_TrainerTips::
	msgbox Route38_Text_TrainerTips, MSGBOX_SIGN
	end

Route38_Text_CHAD1Seen:
	.string "Let me try some-\nthing I learned\ltoday.$"

Route38_Text_CHAD1Beaten:
	.string "I didn't study\nenough, I guess.$"

Route38_Text_DANA1Seen:
	.string "You seem to be\ngood at POKéMON.\pIf you are, how\nabout giving me\lsome advice?$"

Route38_Text_DANA1Beaten:
	.string "I see. So you can\nbattle that way.$"

Route38_Text_TOBYSeen:
	.string "Fly high into the\nsky, my beloved\lbird POKéMON!$"

Route38_Text_TOBYBeaten:
	.string "I feel like just\nflying away now.$"

Route38_Text_VALERIESeen:
	.string "Hi! Aren't you a\ncute trainer!\pMay I see your\nPOKéMON?$"

Route38_Text_VALERIEBeaten:
	.string "I'm glad I got to\nsee your POKéMON!$"

Route38_Text_HARRYSeen:
	.string "I've been over-\nseas, so I know\pabout all sorts of\nPOKéMON!$"

Route38_Text_HARRYBeaten:
	.string "Your skill is\nworld class!$"

Route38_Text_OLIVIASeen:
	.string "Don't you think my\nPOKéMON and I are\lbeautiful?$"

Route38_Text_OLIVIABeaten:
	.string "We drink MOOMOO\nMILK every day.$"

Route38_Text_Sign:
	.string "ROUTE 38\pOLIVINE CITY -\nECRUTEAK CITY$"

Route38_Text_TrainerTips:
	.string "TRAINER TIPS\pIf a POKéMON is\ntrying to evolve,\lyou can stop it.\pPress the B But-\nton during evolu-\ltion.\pThat startles the\nPOKéMON and stops\lits evolution.$"
