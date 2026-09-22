VermilionCity_Mart_MapScripts::
	.byte 0

VermilionCity_Mart_EventScript_Clerk::
	msgbox VermilionCity_Mart_Text_Clerk, MSGBOX_NPC
	end

VermilionCity_Mart_EventScript_CooltrainerF::
	msgbox VermilionCity_Mart_Text_CooltrainerF, MSGBOX_NPC
	end

VermilionCity_Mart_EventScript_BaldingMan::
	msgbox VermilionCity_Mart_Text_BaldingMan, MSGBOX_NPC
	end

VermilionCity_Mart_Text_Clerk:
	.string "The counter is bare.\pNothing's come in for months.\nCELADON'S store still trades.$"

VermilionCity_Mart_Text_CooltrainerF:
	.string "I think POKéMON can be good or\nbad. It depends on the TRAINER.$"

VermilionCity_Mart_Text_BaldingMan:
	.string "There are wicked people who will\nuse POKéMON for criminal acts.\pTEAM ROCKET traffics in rare\nPOKéMON, for example.\pThey also abandon POKéMON that\nthey consider unpopular or useless.\pThat's the sort of horrid people\nthey are, TEAM ROCKET.$"
