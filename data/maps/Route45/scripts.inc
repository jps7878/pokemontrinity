Route45_MapScripts::
	.byte 0

Route45_EventScript_ERIK::
	trainerbattle_single TRAINER_JOHTO_HIKER_ERIK, Route45_Text_ERIKSeen, Route45_Text_ERIKBeaten
	msgbox Route45_Text_ERIKBeaten, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_MICHAEL::
	trainerbattle_single TRAINER_JOHTO_HIKER_MICHAEL, Route45_Text_MICHAELSeen, Route45_Text_MICHAELBeaten
	msgbox Route45_Text_MICHAELBeaten, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_PARRY3::
	trainerbattle_single TRAINER_JOHTO_HIKER_PARRY3, Route45_Text_PARRY3Seen, Route45_Text_PARRY3Beaten
	msgbox Route45_Text_PARRY3Beaten, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_TIMOTHY::
	trainerbattle_single TRAINER_JOHTO_HIKER_TIMOTHY, Route45_Text_TIMOTHYSeen, Route45_Text_TIMOTHYBeaten
	msgbox Route45_Text_TIMOTHYBeaten, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_KENJI3::
	trainerbattle_single TRAINER_JOHTO_BLACKBELT_T_KENJI3, Route45_Text_KENJI3Seen, Route45_Text_KENJI3Beaten
	msgbox Route45_Text_KENJI3Beaten, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_RYAN::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERM_RYAN, Route45_Text_RYANSeen, Route45_Text_RYANBeaten
	msgbox Route45_Text_RYANBeaten, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_KELLY::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_KELLY, Route45_Text_KELLYSeen, Route45_Text_KELLYBeaten
	msgbox Route45_Text_KELLYBeaten, MSGBOX_AUTOCLOSE
	end

Route45_EventScript_TrainerCamperQuentin::
	msgbox Route45_Text_TrainerCamperQuentin, MSGBOX_NPC
	end

Route45_EventScript_Sign::
	msgbox Route45_Text_Sign, MSGBOX_SIGN
	end

Route45_Text_ERIKSeen:
	.string "Be prepared for\nanything!\pLet me see if your\nPOKéMON have been\lraised properly!$"

Route45_Text_ERIKBeaten:
	.string "Oh, I lost that!$"

Route45_Text_MICHAELSeen:
	.string "Yo! You're spunky!\nBut you know what?\pWhen it comes to\nsheer spunkiness,\lI'm the man!$"

Route45_Text_MICHAELBeaten:
	.string "My POKéMON weren't\nspunky enough!$"

Route45_Text_PARRY3Seen:
	.string "My POKéMON are\npower packed!$"

Route45_Text_PARRY3Beaten:
	.string "Wahahah! I'm the\nbig loser!$"

Route45_Text_TIMOTHYSeen:
	.string "Why do I climb\nmountains?\pBecause they're\nthere.\pWhy do I train\nPOKéMON?\pBecause they're\nthere!$"

Route45_Text_TIMOTHYBeaten:
	.string "Losses…\nThey're there too!$"

Route45_Text_KENJI3Seen:
	.string "I was training\nhere alone.\pBehold the fruits\nof my labor!$"

Route45_Text_KENJI3Beaten:
	.string "Waaaargh!$"

Route45_Text_RYANSeen:
	.string "What are your\nthoughts on rais-\ling POKéMON?$"

Route45_Text_RYANBeaten:
	.string "You've won my\nrespect.$"

Route45_Text_KELLYSeen:
	.string "What is your\nbattle strategy?\pIt is foolish to\nuse strong moves\lindiscriminately.$"

Route45_Text_KELLYBeaten:
	.string "Fine. I lost.$"

Route45_Text_TrainerCamperQuentin:
	.string "Nothing much happens around here,\nbut ever since that ferry started\lrunning to HOENN, who knows.$"

Route45_Text_Sign:
	.string "ROUTE 45\nMOUNTAIN RD. AHEAD$"
