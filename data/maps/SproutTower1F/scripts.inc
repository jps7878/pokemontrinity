SproutTower1F_MapScripts::
	.byte 0

SproutTower1F_EventScript_Sage1::
	msgbox SproutTower1F_Text_Sage1, MSGBOX_NPC
	end

SproutTower1F_EventScript_Sage2::
	msgbox SproutTower1F_Text_Sage2, MSGBOX_NPC
	end

SproutTower1F_EventScript_Granny::
	msgbox SproutTower1F_Text_Granny, MSGBOX_NPC
	end

SproutTower1F_EventScript_Teacher::
	msgbox SproutTower1F_Text_Teacher, MSGBOX_NPC
	end

SproutTower1F_EventScript_CHOW::
	trainerbattle_single TRAINER_JOHTO_SAGE_CHOW, SproutTower1F_Text_CHOWSeen, SproutTower1F_Text_CHOWBeaten
	msgbox SproutTower1F_Text_CHOWAfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower1F_EventScript_Statue::
	msgbox SproutTower1F_Text_Statue, MSGBOX_SIGN
	end

SproutTower1F_EventScript_Statue_2::
	msgbox SproutTower1F_Text_Statue_2, MSGBOX_SIGN
	end

@ HM-era line repaired (slice plan section 6): M4a shipped GSC's "Only if you
@ reach the top will you obtain an HM", which is a false pointer in Trinity --
@ field HMs are automatic and FLASH arrived in Act I. Re-pointed at the ELDER,
@ who is now a real trainer (TRAINER_JOHTO_SAGE_LI, SproutTower3F).
SproutTower1F_Text_Sage1:
	.string "Reach the top floor and the\n"
	.string "ELDER will test you himself.\p"
	.string "Few do. Fewer pass.$"

SproutTower1F_Text_Sage2:
	.string "SPROUT TOWER was\nbuilt long ago\pas a place for\nPOKéMON training.$"

SproutTower1F_Text_Granny:
	.string "A BELLSPROUT over\n100 feet tall…\pPeople say that it\nbecame the center\lpillar here.$"

SproutTower1F_Text_Teacher:
	.string "See the pillar\nshaking?\pPeople are train-\ning upstairs.$"

SproutTower1F_Text_CHOWSeen:
	.string "We stand guard in\nthis tower.\pHere, we express\nour gratitude to\lhonor all POKéMON.$"

SproutTower1F_Text_CHOWBeaten:
	.string "Th-Thank you!$"

@ GSC SageChowAfterBattleText.
SproutTower1F_Text_CHOWAfterBattle:
	.string "All living beings coexist\n"
	.string "through cooperation.\p"
	.string "We must always be thankful for\n"
	.string "this.$"

SproutTower1F_Text_Statue:
	.string "A POKéMON statue…\pIt looks very\ndistinguished.$"

SproutTower1F_Text_Statue_2:
	.string "A POKéMON statue…\pIt looks very\ndistinguished.$"
