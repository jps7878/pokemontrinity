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

@ ============================================================================
@ Trinity M4b S3 -- the ILEX FOREST SHRINE. Adapts pokecrystal
@ maps/IlexForest.asm's IlexForestShrineScript / Text_IlexForestShrine.
@ CELEBI IS POST-GAME: the GS BALL branch, the CelebiShrineEvent special and
@ the L30 encounter are all skipped, and this text must not promise a
@ summoning. Reverent flavour only.
@ (8,22) decodes collision 1 / elevation 0 -- the shrine tile itself -- read
@ facing north from (8,23), which decodes collision 0 / elevation 3. Same shape
@ as the GYM PATTERN's G5 statues.
@ ============================================================================
IlexForest_EventScript_Shrine::
	msgbox IlexForest_Text_Shrine, MSGBOX_SIGN
	end

IlexForest_Text_HeadbuttGuy:
	.string "This route sure gets more foot\ntraffic now that HOENN trainers\lkeep showing up.$"

IlexForest_Text_WAYNESeen:
	.string "Don't sneak up on\nme like that!\pYou frightened a\nPOKéMON away!$"

IlexForest_Text_WAYNEBeaten:
	.string "I hadn't seen that\nPOKéMON before…$"

@ Expands GSC Text_IlexForestShrine. The "hole that something would fit into"
@ line is deliberately NOT carried over -- that is the GS BALL hook, and CELEBI
@ is not an Act II beat.
IlexForest_Text_Shrine:
	.string "ILEX FOREST SHRINE…\p"
	.string "It's in honour of the forest's\n"
	.string "protector.\p"
	.string "No name on it. The people who\n"
	.string "built it clearly assumed you'd\l"
	.string "know, and were probably right\l"
	.string "at the time.\p"
	.string "Offerings have been left at the\n"
	.string "foot of it. Recently.\p"
	.string "The trees are very quiet here.$"

IlexForest_Text_Signpost:
	.string "ILEX FOREST is\nso overgrown with\ptrees that you\ncan't see the sky.\pPlease watch out\nfor items that may\lhave been dropped.$"
