NationalPark_MapScripts::
	.byte 0

NationalPark_EventScript_Lass::
	msgbox NationalPark_Text_Lass, MSGBOX_NPC
	end

NationalPark_EventScript_PokefanF::
	msgbox NationalPark_Text_PokefanF, MSGBOX_NPC
	end

NationalPark_EventScript_Teacher1::
	msgbox NationalPark_Text_Teacher1, MSGBOX_NPC
	end

NationalPark_EventScript_Youngster1::
	msgbox NationalPark_Text_Youngster1, MSGBOX_NPC
	end

NationalPark_EventScript_Youngster2::
	msgbox NationalPark_Text_Youngster2, MSGBOX_NPC
	end

NationalPark_EventScript_Teacher2::
	msgbox NationalPark_Text_Teacher2, MSGBOX_NPC
	end

NationalPark_EventScript_JACK1::
	trainerbattle_single TRAINER_JOHTO_SCHOOLBOY_JACK1, NationalPark_Text_JACK1Seen, NationalPark_Text_JACK1Beaten
	msgbox NationalPark_Text_JACK1Beaten, MSGBOX_AUTOCLOSE
	end

NationalPark_EventScript_BEVERLY1::
	trainerbattle_single TRAINER_JOHTO_POKEFANF_BEVERLY1, NationalPark_Text_BEVERLY1Seen, NationalPark_Text_BEVERLY1Beaten
	msgbox NationalPark_Text_BEVERLY1Beaten, MSGBOX_AUTOCLOSE
	end

NationalPark_EventScript_WILLIAM::
	trainerbattle_single TRAINER_JOHTO_POKEFANM_WILLIAM, NationalPark_Text_WILLIAMSeen, NationalPark_Text_WILLIAMBeaten
	msgbox NationalPark_Text_WILLIAMBeaten, MSGBOX_AUTOCLOSE
	end

NationalPark_EventScript_KRISE::
	trainerbattle_single TRAINER_JOHTO_LASS_KRISE, NationalPark_Text_KRISESeen, NationalPark_Text_KRISEBeaten
	msgbox NationalPark_Text_KRISEBeaten, MSGBOX_AUTOCLOSE
	end

NationalPark_EventScript_RelaxationSquareSign::
	msgbox NationalPark_Text_RelaxationSquareSign, MSGBOX_SIGN
	end

NationalPark_EventScript_BattleNoticeSign::
	msgbox NationalPark_Text_BattleNoticeSign, MSGBOX_SIGN
	end

NationalPark_EventScript_TrainerTipsSign::
	msgbox NationalPark_Text_TrainerTipsSign, MSGBOX_SIGN
	end

NationalPark_Text_Lass:
	.string "Look! Check out my\nbag!\pI printed out my\nfavorites from my\pPOKéDEX and stuck\nthem on my bag.$"

NationalPark_Text_PokefanF:
	.string "This is MAIL I got\nfrom my daughter.\lIt cheers me up.$"

NationalPark_Text_Teacher1:
	.string "Nothing much happens around here,\nbut ever since that ferry started\lrunning to HOENN, who knows.$"

NationalPark_Text_Youngster1:
	.string "I'm playing with\nstickers I printed\lfrom my POKéDEX.$"

NationalPark_Text_Youngster2:
	.string "I get the other\nguy's POKéDEX\lsticker if I win.$"

NationalPark_Text_Teacher2:
	.string "I take walks in\nthe PARK, but I\pnever go into the\ngrass.\pTrainers always\nwant to battle…$"

NationalPark_Text_JACK1Seen:
	.string "The world of\nPOKéMON is deep.\pThere are still\nlots of things we\ldon't know.\pBut I know more\nthan you do!$"

NationalPark_Text_JACK1Beaten:
	.string "Wha-wha-what?$"

NationalPark_Text_BEVERLY1Seen:
	.string "My POKéMON are\nsimply darling.\pLet me tell you\nhow proud my\ldarlings make me.$"

NationalPark_Text_BEVERLY1Beaten:
	.string "I can beat you in\npride, but…$"

NationalPark_Text_WILLIAMSeen:
	.string "We adore our POKé-\nMON, even if they\ldislike us.\pThat's what being\na FAN is about.$"

NationalPark_Text_WILLIAMBeaten:
	.string "M-my POKéMON!$"

NationalPark_Text_KRISESeen:
	.string "Hello? Why are you\nstaring at me?\pOh, a battle?$"

NationalPark_Text_KRISEBeaten:
	.string "…Hmmm…$"

NationalPark_Text_RelaxationSquareSign:
	.string "RELAXATION SQUARE\nNATIONAL PARK$"

NationalPark_Text_BattleNoticeSign:
	.string "What is this\nnotice?\pPlease battle only\nin the grass.\pNATIONAL PARK\nWARDEN'S OFFICE$"

NationalPark_Text_TrainerTipsSign:
	.string "TRAINER TIPS\pPrint out MAIL by\nopening it then\lpressing START.$"
