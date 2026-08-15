RuinsOfAlphResearchCenter_MapScripts::
	.byte 0

RuinsOfAlphResearchCenter_EventScript_Scientist1::
	msgbox RuinsOfAlphResearchCenter_Text_Scientist1, MSGBOX_NPC
	end

RuinsOfAlphResearchCenter_EventScript_Scientist2::
	msgbox RuinsOfAlphResearchCenter_Text_Scientist2, MSGBOX_NPC
	end

RuinsOfAlphResearchCenter_EventScript_Bookshelf::
	msgbox RuinsOfAlphResearchCenter_Text_Bookshelf, MSGBOX_SIGN
	end

RuinsOfAlphResearchCenter_Text_Scientist1:
	.string "My grandkids won't stop talking\nabout the new champion from over\lin HOENN. Kids these days!$"

RuinsOfAlphResearchCenter_Text_Scientist2:
	.string "The old timers say JOHTO used to\nfeel far from everywhere. Not\lanymore, with HOENN so close now.$"

RuinsOfAlphResearchCenter_Text_Bookshelf:
	.string "There are many\nacademic books.\pAncient Ruins…\nMysteries of the\lAncients…$"
