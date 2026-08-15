NationalParkBugContest_MapScripts::
	.byte 0

NationalParkBugContest_EventScript_RelaxationSquareSign::
	msgbox NationalParkBugContest_Text_RelaxationSquareSign, MSGBOX_SIGN
	end

NationalParkBugContest_EventScript_BattleNoticeSign::
	msgbox NationalParkBugContest_Text_BattleNoticeSign, MSGBOX_SIGN
	end

NationalParkBugContest_EventScript_TrainerTipsSign::
	msgbox NationalParkBugContest_Text_TrainerTipsSign, MSGBOX_SIGN
	end

NationalParkBugContest_Text_RelaxationSquareSign:
	.string "RELAXATION SQUARE\nNATIONAL PARK$"

NationalParkBugContest_Text_BattleNoticeSign:
	.string "What is this\nnotice?\pPlease battle only\nin the grass.\pNATIONAL PARK\nWARDEN'S OFFICE$"

NationalParkBugContest_Text_TrainerTipsSign:
	.string "TRAINER TIPS\pPrint out MAIL by\nopening it then\lpressing START.$"
