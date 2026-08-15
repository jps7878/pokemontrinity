CherrygroveCity_MapScripts::
	.byte 0

CherrygroveCity_EventScript_CherrygroveTeacher::
	msgbox CherrygroveCity_Text_CherrygroveTeacher, MSGBOX_NPC
	end

CherrygroveCity_EventScript_CherrygroveYoungster::
	msgbox CherrygroveCity_Text_CherrygroveYoungster, MSGBOX_NPC
	end

CherrygroveCity_EventScript_MysticWaterGuy::
	msgbox CherrygroveCity_Text_MysticWaterGuy, MSGBOX_NPC
	end

CherrygroveCity_EventScript_Sign::
	msgbox CherrygroveCity_Text_Sign, MSGBOX_SIGN
	end

CherrygroveCity_EventScript_GuideGentsHouseSign::
	msgbox CherrygroveCity_Text_GuideGentsHouseSign, MSGBOX_SIGN
	end

CherrygroveCity_Text_CherrygroveTeacher:
	.string "They say the HOENN champion's\njourney is just getting started.\lWonder where they'll go next.$"

CherrygroveCity_Text_CherrygroveYoungster:
	.string "This route sure gets more foot\ntraffic now that HOENN trainers\lkeep showing up.$"

CherrygroveCity_Text_MysticWaterGuy:
	.string "I've lived in JOHTO my whole life.\nNever thought I'd meet someone\lfrom HOENN way out here.$"

CherrygroveCity_Text_Sign:
	.string "CHERRYGROVE CITY\pThe City of Cute,\nFragrant Flowers$"

CherrygroveCity_Text_GuideGentsHouseSign:
	.string "GUIDE GENT'S HOUSE$"
