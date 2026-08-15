MahoganyTown_MapScripts::
	.byte 0

MahoganyTown_EventScript_Gramps::
	msgbox MahoganyTown_Text_Gramps, MSGBOX_NPC
	end

MahoganyTown_EventScript_Sign::
	msgbox MahoganyTown_Text_Sign, MSGBOX_SIGN
	end

MahoganyTown_EventScript_RagecandybarSign::
	msgbox MahoganyTown_Text_RagecandybarSign, MSGBOX_SIGN
	end

MahoganyTown_EventScript_MahoganyGymSign::
	msgbox MahoganyTown_Text_MahoganyGymSign, MSGBOX_SIGN
	end

MahoganyTown_Text_Gramps:
	.string "They say the HOENN champion's\njourney is just getting started.\lWonder where they'll go next.$"

MahoganyTown_Text_Sign:
	.string "MAHOGANY TOWN\pWelcome to the\nHome of the Ninja$"

MahoganyTown_Text_RagecandybarSign:
	.string "While visiting\nMAHOGANY TOWN, try\la RAGECANDYBAR!$"

MahoganyTown_Text_MahoganyGymSign:
	.string "MAHOGANY TOWN\nPOKéMON GYM\lLEADER: PRYCE\pThe Teacher of\nWinter's Harshness$"
