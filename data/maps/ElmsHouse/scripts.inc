ElmsHouse_MapScripts::
	.byte 0

ElmsHouse_EventScript_ElmsWife::
	msgbox ElmsHouse_Text_ElmsWife, MSGBOX_NPC
	end

ElmsHouse_EventScript_ElmsSon::
	msgbox ElmsHouse_Text_ElmsSon, MSGBOX_NPC
	end

ElmsHouse_EventScript_PC::
	msgbox ElmsHouse_Text_PC, MSGBOX_SIGN
	end

ElmsHouse_Text_ElmsWife:
	.string "Hi, {PLAYER}! My\nhusband's always\pso busy--I hope\nhe's OK.\pWhen he's caught\nup in his POKéMON\presearch, he even\nforgets to eat.$"

ElmsHouse_Text_ElmsSon:
	.string "When I grow up,\nI'm going to help\lmy dad!\pI'm going to be a\ngreat POKéMON\lprofessor!$"

ElmsHouse_Text_PC:
	.string "POKéMON. Where do\nthey come from? \pWhere are they\ngoing?\pWhy has no one\never witnessed a\lPOKéMON's birth?\pI want to know! I\nwill dedicate my\plife to the study\nof POKéMON!\p…\pIt's a part of\nPROF.ELM's re-\lsearch papers.$"
