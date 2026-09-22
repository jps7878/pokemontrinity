LavenderTown_Mart_MapScripts::
	.byte 0

LavenderTown_Mart_EventScript_Clerk::
	msgbox LavenderTown_Mart_Text_Clerk, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_BaldingMan::
	msgbox LavenderTown_Mart_Text_BaldingMan, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Rocker::
	msgbox LavenderTown_Mart_Text_Rocker, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Youngster::
	msgbox LavenderTown_Mart_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_Mart_Text_Clerk:
	.string "The counter is bare.\pNothing's come in for months.\nCELADON'S store still trades.$"

LavenderTown_Mart_Text_BaldingMan:
	.string "I'm searching for items that raise\nthe stats of POKéMON.\pThey're effective over the course\nof a single battle.\pX ATTACK, X DEFEND, X SPEED, \nand X SPECIAL are what I'm after.\pDo you know where I can get them?$"

LavenderTown_Mart_Text_Rocker:
	.string "You won't buy REVIVES here.\nNobody has in months.$"

LavenderTown_Mart_Text_Youngster:
	.string "Sometimes, a TRAINER duo will\nchallenge you with two POKéMON\lat the same time.\pIf that happens, you have to send\nout two POKéMON to battle, too.$"
