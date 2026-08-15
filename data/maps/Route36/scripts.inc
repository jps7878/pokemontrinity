Route36_MapScripts::
	.byte 0

Route36_EventScript_MARK::
	trainerbattle_single TRAINER_JOHTO_PSYCHIC_T_MARK, Route36_Text_MARKSeen, Route36_Text_MARKBeaten
	msgbox Route36_Text_MARKBeaten, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_ALAN1::
	trainerbattle_single TRAINER_JOHTO_SCHOOLBOY_ALAN1, Route36_Text_ALAN1Seen, Route36_Text_ALAN1Beaten
	msgbox Route36_Text_ALAN1Beaten, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Lass::
	msgbox Route36_Text_Lass, MSGBOX_NPC
	end

Route36_EventScript_RockSmashGuy::
	msgbox Route36_Text_RockSmashGuy, MSGBOX_NPC
	end

Route36_EventScript_TrainerTips2::
	msgbox Route36_Text_TrainerTips2, MSGBOX_SIGN
	end

Route36_EventScript_RuinsOfAlphNorthSign::
	msgbox Route36_Text_RuinsOfAlphNorthSign, MSGBOX_SIGN
	end

Route36_EventScript_Sign::
	msgbox Route36_Text_Sign, MSGBOX_SIGN
	end

Route36_EventScript_TrainerTips1::
	msgbox Route36_Text_TrainerTips1, MSGBOX_SIGN
	end

Route36_Text_MARKSeen:
	.string "I'm going to read\nyour thoughts!$"

Route36_Text_MARKBeaten:
	.string "I misread you!$"

Route36_Text_ALAN1Seen:
	.string "Thanks to my stud-\nies, I'm ready for\lany POKéMON!$"

Route36_Text_ALAN1Beaten:
	.string "Oops! Computation\nerror?$"

Route36_Text_Lass:
	.string "Word is a strong trainer crossed\nthe sea from HOENN. I wonder if\lthey'll pass through JOHTO too.$"

Route36_Text_RockSmashGuy:
	.string "This route sure gets more foot\ntraffic now that HOENN trainers\lkeep showing up.$"

Route36_Text_TrainerTips2:
	.string "TRAINER TIPS\pUse DIG to return\nto the entrance of\lany place.\pIt is convenient\nfor exploring\pcaves and other\nlandmarks.$"

Route36_Text_RuinsOfAlphNorthSign:
	.string "RUINS OF ALPH\nNORTH ENTRANCE$"

Route36_Text_Sign:
	.string "ROUTE 36$"

Route36_Text_TrainerTips1:
	.string "TRAINER TIPS\pPOKéMON stats\nvary--even within\lthe same species.\pTheir stats may be\nsimilar at first.\pHowever, differ-\nences will become\ppronounced as the\nPOKéMON grow.$"
