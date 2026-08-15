RadioTower4F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RadioTower4F_OnTransition
	.byte 0

@ Trinity M4b S4 -- RADIO TOWER 4F, pre-takeover. S8 FLIP CONTRACT: shared
@ predicate in data/maps/RadioTower1F/scripts.inc -- visible iff
@ VAR_TRINITY_JOHTO_ARC != 6. Both objects carry
@ FLAG_TRINITY_J_RADIO_TOWER_PRE_HIDE.
@ DECODE NOTE: two components, PRE-EXISTING and object-independent (the two
@ staircase pairs join through 3F and 5F). See RadioTower3F's header.
RadioTower4F_OnTransition:
	call RadioTower_EventScript_SetPreTakeoverVisibility
	end

RadioTower4F_EventScript_DJMary::
	msgbox RadioTower4F_Text_DJMary, MSGBOX_NPC
	end

RadioTower4F_EventScript_Fisher::
	msgbox RadioTower4F_Text_Fisher, MSGBOX_NPC
	end

RadioTower4F_EventScript_ProductionSign::
	msgbox RadioTower4F_Text_ProductionSign, MSGBOX_SIGN
	end

RadioTower4F_EventScript_Studio2Sign::
	msgbox RadioTower4F_Text_Studio2Sign, MSGBOX_SIGN
	end

@ GSC RadioTower4FDJMaryText_After.
RadioTower4F_Text_DJMary:
	.string "MARY: Please tune into me on\n"
	.string "PROF.OAK'S POKéMON TALK show!\p"
	.string "We take a POKéMON, we take a\n"
	.string "route, and the PROFESSOR talks\l"
	.string "about it until the music comes\l"
	.string "back in.\p"
	.string "It sounds like nothing. People\n"
	.string "plan whole days around it.$"

@ GSC RadioTower4FFisherText. Lands harder in Trinity, where the RUINS OF ALPH
@ carry G hints -- the line is left as GSC wrote it and not explained.
RadioTower4F_Text_Fisher:
	.string "I listened to the radio while I\n"
	.string "was at the RUINS.\p"
	.string "I heard a strange broadcast\n"
	.string "there.\p"
	.string "Not a station. Not static\n"
	.string "either. I came here to ask what\l"
	.string "frequency it was.\p"
	.string "They tell me it isn't one of\n"
	.string "theirs.$"

RadioTower4F_Text_ProductionSign:
	.string "4F PRODUCTION$"

RadioTower4F_Text_Studio2Sign:
	.string "4F STUDIO 2$"
