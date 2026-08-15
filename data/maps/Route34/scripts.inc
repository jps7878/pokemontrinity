Route34_MapScripts::
	.byte 0

Route34_EventScript_TODD1::
	trainerbattle_single TRAINER_JOHTO_CAMPER_TODD1, Route34_Text_TODD1Seen, Route34_Text_TODD1Beaten
	msgbox Route34_Text_TODD1Beaten, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_SAMUEL::
	trainerbattle_single TRAINER_JOHTO_YOUNGSTER_SAMUEL, Route34_Text_SAMUELSeen, Route34_Text_SAMUELBeaten
	msgbox Route34_Text_SAMUELBeaten, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_IAN::
	trainerbattle_single TRAINER_JOHTO_YOUNGSTER_IAN, Route34_Text_IANSeen, Route34_Text_IANBeaten
	msgbox Route34_Text_IANBeaten, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_GINA1::
	trainerbattle_single TRAINER_JOHTO_PICNICKER_GINA1, Route34_Text_GINA1Seen, Route34_Text_GINA1Beaten
	msgbox Route34_Text_GINA1Beaten, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_OfficerKeith::
	msgbox Route34_Text_OfficerKeith, MSGBOX_NPC
	end

Route34_EventScript_BRANDON::
	trainerbattle_single TRAINER_JOHTO_POKEFANM_BRANDON, Route34_Text_BRANDONSeen, Route34_Text_BRANDONBeaten
	msgbox Route34_Text_BRANDONBeaten, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_IRENE::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_IRENE, Route34_Text_IRENESeen, Route34_Text_IRENEBeaten
	msgbox Route34_Text_IRENEBeaten, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_JENN::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_JENN, Route34_Text_JENNSeen, Route34_Text_JENNBeaten
	msgbox Route34_Text_JENNBeaten, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_KATE::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_KATE, Route34_Text_KATESeen, Route34_Text_KATEBeaten
	msgbox Route34_Text_KATEBeaten, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Sign::
	msgbox Route34_Text_Sign, MSGBOX_SIGN
	end

Route34_EventScript_TrainerTips::
	msgbox Route34_Text_TrainerTips, MSGBOX_SIGN
	end

Route34_EventScript_DayCareSign::
	msgbox Route34_Text_DayCareSign, MSGBOX_SIGN
	end

Route34_Text_TODD1Seen:
	.string "I'm confident in\nmy ability to\lraise POKéMON.\pWant to see?$"

Route34_Text_TODD1Beaten:
	.string "Did I screw up my\ntraining?$"

Route34_Text_SAMUELSeen:
	.string "This is where I do\nmy training!$"

Route34_Text_SAMUELBeaten:
	.string "Beaten by a\npassing stranger!$"

Route34_Text_IANSeen:
	.string "I'm the best in my\nclass at POKéMON.$"

Route34_Text_IANBeaten:
	.string "No! There are bet-\nter trainers…$"

Route34_Text_GINA1Seen:
	.string "Are you a trainer?\pLet's have a\npractice battle.$"

Route34_Text_GINA1Beaten:
	.string "Oh, no! I just\ncan't win…$"

Route34_Text_OfficerKeith:
	.string "My grandkids won't stop talking\nabout the new champion from over\lin HOENN. Kids these days!$"

Route34_Text_BRANDONSeen:
	.string "I just got my\nPOKéMON back from\lDAY-CARE.\pLet's see how much\nstronger it got!$"

Route34_Text_BRANDONBeaten:
	.string "Why does it end\nthis way?$"

Route34_Text_IRENESeen:
	.string "IRENE: Kyaaah!\nSomeone found us!$"

Route34_Text_IRENEBeaten:
	.string "IRENE: Ohhh!\nToo strong!$"

Route34_Text_JENNSeen:
	.string "JENN: You can't\nbeat IRENE and go\lunpunished!$"

Route34_Text_JENNBeaten:
	.string "JENN: So sorry,\nIRENE! Sis!$"

Route34_Text_KATESeen:
	.string "KATE: You sure\nwere mean to my\llittle sisters!$"

Route34_Text_KATEBeaten:
	.string "KATE: No! I can't\nbelieve I lost.$"

Route34_Text_Sign:
	.string "ROUTE 34\pGOLDENROD CITY -\nAZALEA TOWN\pILEX FOREST\nSOMEWHERE BETWEEN$"

Route34_Text_TrainerTips:
	.string "TRAINER TIPS\pBERRY trees grow\nnew BERRIES\levery day.\pMake a note of\nwhich trees bear\lwhich BERRIES.$"

Route34_Text_DayCareSign:
	.string "DAY-CARE\pLET US RAISE YOUR\nPOKéMON FOR YOU!$"
