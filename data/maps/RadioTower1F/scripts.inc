RadioTower1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RadioTower1F_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S4 -- RADIO TOWER 1F, pre-takeover.
@
@ THE S8 FLIP CONTRACT (full statement in data/maps/GoldenrodCity/scripts.inc
@ and include/constants/flags.h). S8 writes ONE thing -- setvar
@ VAR_TRINITY_JOHTO_ARC, 6 -- and never touches
@ FLAG_TRINITY_J_RADIO_TOWER_PRE_HIDE. Each of the five floors' ON_TRANSITION
@ is that flag's authoring site for that floor, all with the same predicate:
@
@   visible iff VAR_TRINITY_JOHTO_ARC != 6
@
@ EVERY pre-takeover object on the floor carries the flag -- including the ones
@ M4a placed with flag 0 -- because the flip has to cover the whole standing
@ cast, or S8 inherits a tower with half its staff still at their desks behind
@ the Rockets. The ITEM_ULTRA_BALL ball on 5F keeps its own pickup flag and is
@ NOT in the cast: items are not staff, and GSC leaves that ball on the floor
@ during the occupation too.
@
@ DECODE NOTE. 1F has a 16-tile region (x5..x12, y6..y7) that is unreachable on
@ foot with ZERO objects placed -- it is the inside of the reception desk. The
@ LUCKY NUMBER MAN (8,6) and the RADIO CARD WOMAN (12,6) sit in it, exactly as
@ GSC places them (RadioTower1F.asm:492-493), and are served over the
@ MB_COUNTER row at y=5 (GetInteractedObjectEventScript ->
@ MetatileBehavior_IsCounter -> look one tile further,
@ src/field_control_avatar.c:387-396). Objects on already-unreachable tiles
@ cost zero walkability.
@ ============================================================================
RadioTower1F_OnTransition:
	call RadioTower_EventScript_SetPreTakeoverVisibility
	end

@ Shared by all five floors -- one predicate, one place to read it.
RadioTower_EventScript_SetPreTakeoverVisibility::
	goto_if_eq VAR_TRINITY_JOHTO_ARC, 6, RadioTower_EventScript_HidePreTakeover
	clearflag FLAG_TRINITY_J_RADIO_TOWER_PRE_HIDE
	return

RadioTower_EventScript_HidePreTakeover::
	setflag FLAG_TRINITY_J_RADIO_TOWER_PRE_HIDE
	return

RadioTower1F_EventScript_Receptionist::
	msgbox RadioTower1F_Text_Receptionist, MSGBOX_NPC
	end

RadioTower1F_EventScript_Lass::
	msgbox RadioTower1F_Text_Lass, MSGBOX_NPC
	end

RadioTower1F_EventScript_Youngster::
	msgbox RadioTower1F_Text_Youngster, MSGBOX_NPC
	end

@ The quiz-show flavour. GSC's LUCKY NUMBER SHOW is a real weekly system (ID
@ matching against wLuckyNumber, MASTER BALL / EXP.SHARE / PP UP ladder); that
@ is a system, not a beat, and is logged as a deliberate skip. He keeps the
@ show, the ladder and the patter.
RadioTower1F_EventScript_LuckyNumberMan::
	msgbox RadioTower1F_Text_LuckyNumberMan, MSGBOX_NPC
	end

@ S1's ELM already fitted the POKéNAV as a radio, so the live branch is this
@ campaign's CLOSING line. The unset branch is DEFENSIVE: the arc gate on
@ leaving NEW BARK means a save cannot normally reach GOLDENROD without ELM
@ having granted the card, so it should be unreachable -- it is written as real
@ dialogue rather than an assert because a flavour NPC must never dead-end.
RadioTower1F_EventScript_RadioCardWoman::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_RADIO_CARD, RadioTower1F_EventScript_RadioCardWomanGotCard
	msgbox RadioTower1F_Text_RadioCardWomanOffer, MSGBOX_DEFAULT
	release
	end

RadioTower1F_EventScript_RadioCardWomanGotCard::
	msgbox RadioTower1F_Text_RadioCardWomanGotCard, MSGBOX_DEFAULT
	release
	end

RadioTower1F_EventScript_Directory::
	msgbox RadioTower1F_Text_Directory, MSGBOX_SIGN
	end

RadioTower1F_EventScript_LuckyChannelSign::
	msgbox RadioTower1F_Text_LuckyChannelSign, MSGBOX_SIGN
	end

@ ============================================================================
@ Text -- adapts pokecrystal RadioTower1F.asm.
@ ============================================================================
RadioTower1F_Text_Receptionist:
	.string "Welcome to the GOLDENROD RADIO\n"
	.string "TOWER!\p"
	.string "Studio tours run on the hour.\n"
	.string "Please don't open any door with\l"
	.string "a red light over it.\p"
	.string "Enjoy your visit!$"

@ GSC RadioTower1FLassText.
RadioTower1F_Text_Lass:
	.string "BEN is a fabulous DJ.\p"
	.string "His sweet voice makes me melt!\p"
	.string "He's up in STUDIO 1. I've been\n"
	.string "standing here for two hours in\l"
	.string "case he takes the stairs.$"

@ GSC RadioTower1FYoungsterText.
RadioTower1F_Text_Youngster:
	.string "I love MARY, from POKéMON TALK.\p"
	.string "I only know what she sounds\n"
	.string "like, though.\p"
	.string "…She's on the fourth floor.\n"
	.string "I've been told I can't go up.$"

@ GSC RadioTower1FLuckyNumberManAskToPlayText + the prize ladder, kept as
@ description. The draw itself is not implemented (see the skip log).
RadioTower1F_Text_LuckyNumberMan:
	.string "Hi! Are you here for the LUCKY\n"
	.string "NUMBER SHOW?\p"
	.string "Every week we draw five digits.\n"
	.string "Match them against the ID\l"
	.string "number of any POKéMON you're\l"
	.string "carrying.\p"
	.string "All five, and it's a MASTER\n"
	.string "BALL. Three, an EXP.SHARE. Two,\l"
	.string "a PP UP.\p"
	.string "This week's draw already\n"
	.string "closed, I'm afraid. Come back\l"
	.string "and see me for the next one.\p"
	.string "…And trade around! Traded\n"
	.string "POKéMON carry someone else's\l"
	.string "ID. More numbers, more chances.$"

@ DEFENSIVE branch -- see the script comment above.
RadioTower1F_Text_RadioCardWomanOffer:
	.string "We have a special quiz campaign\n"
	.string "on right now.\p"
	.string "Answer five questions and we'll\n"
	.string "fit your POKéNAV to pick up the\l"
	.string "radio, anywhere in JOHTO.\p"
	.string "Interested? Come and see me\n"
	.string "when you've got a moment.$"

RadioTower1F_Text_RadioCardWomanGotCard:
	.string "We have a quiz campaign on --\n"
	.string "five questions and we fit your\l"
	.string "POKéNAV for the radio--\p"
	.string "…Which is already done.\p"
	.string "By a PROFESSOR. Without asking\n"
	.string "us. Without the quiz.\p"
	.string "Well. Please do tune in to our\n"
	.string "shows anyway.$"

RadioTower1F_Text_Directory:
	.string "1F RECEPTION\n2F SALES\p3F PERSONNEL\n4F PRODUCTION\p5F DIRECTOR'S\n   OFFICE$"

RadioTower1F_Text_LuckyChannelSign:
	.string "LUCKY CHANNEL!\pWin with POKéMON\nID numbers!\pTrade your POKéMON\nto collect differ-\lent ID numbers!$"
