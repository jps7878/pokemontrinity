IlexForest_MapScripts::
	.byte 0

IlexForest_EventScript_HeadbuttGuy::
	msgbox IlexForest_Text_HeadbuttGuy, MSGBOX_NPC
	end

IlexForest_EventScript_WAYNE::
	trainerbattle_single TRAINER_JOHTO_BUG_CATCHER_WAYNE, IlexForest_Text_WAYNESeen, IlexForest_Text_WAYNEBeaten
	msgbox IlexForest_Text_WAYNEBeaten, MSGBOX_AUTOCLOSE
	end

IlexForest_EventScript_Signpost::
	msgbox IlexForest_Text_Signpost, MSGBOX_SIGN
	end

IlexForest_Text_HeadbuttGuy:
	.string "This route sure gets more foot\ntraffic now that HOENN trainers\lkeep showing up.$"

IlexForest_Text_WAYNESeen:
	.string "Don't sneak up on\nme like that!\pYou frightened a\nPOKéMON away!$"

IlexForest_Text_WAYNEBeaten:
	.string "I hadn't seen that\nPOKéMON before…$"

IlexForest_Text_Signpost:
	.string "ILEX FOREST is\nso overgrown with\ptrees that you\ncan't see the sky.\pPlease watch out\nfor items that may\lhave been dropped.$"
