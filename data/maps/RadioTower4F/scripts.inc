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
	call RadioTower_EventScript_SetTakeoverVisibility
	end

@ ============================================================================
@ Trinity M4b S8 -- DJ MARY is on the EAST half of this floor, behind the CARD
@ KEY shutter, and has been unreachable since M4a for exactly that reason: GSC
@ holds her hostage in STUDIO 2 (RadioTower4F.asm:18-46). Three states.
@
@ GSC's reward is the PINK BOW, which does not exist in this build; substituted
@ with ITEM_SILK_SCARF (425), the same Normal-type boost. GYM PATTERN G2 guard:
@ FLAG_TRINITY_J_MARY_SCARF, retry path = her own re-talk. S7's C1 rule (the
@ award guard must own the giver's visibility) is satisfied by her predicate --
@ she rides S4's ARC != 6, permanently true from ARC 7 on, so she can never
@ vanish owing the gift.
@ ============================================================================
RadioTower4F_EventScript_DJMary::
	lock
	faceplayer
	goto_if_lt VAR_TRINITY_JOHTO_ARC, 6, RadioTower4F_EventScript_DJMaryIdle
	goto_if_eq VAR_TRINITY_JOHTO_ARC, 6, RadioTower4F_EventScript_DJMaryHostage
	goto_if_set FLAG_TRINITY_J_MARY_SCARF, RadioTower4F_EventScript_DJMaryIdle
	msgbox RadioTower4F_Text_DJMarySaved, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_J_MARY_SCARF
	msgbox RadioTower4F_Text_DJMaryScarf, MSGBOX_DEFAULT
	release
	end

RadioTower4F_EventScript_DJMaryIdle::
	msgbox RadioTower4F_Text_DJMary, MSGBOX_DEFAULT
	release
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE -- at ARC == 6 this object is hidden by
@ FLAG_TRINITY_J_RADIO_TOWER_PRE_HIDE. Written so the ARC-6 guard resolves to
@ something in character rather than falling through into the gift path.
RadioTower4F_EventScript_DJMaryHostage::
	msgbox RadioTower4F_Text_DJMaryHostage, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ R2 posts, GSC tiles (RadioTower4F.asm:265-268), all decoded collision 0 /
@ elevation 3 / MB_NORMAL:
@   WEST half  (5,6) mt517 facing UP    sight 3
@              (4,2) mt568 facing LEFT  sight 4  -- the SCIENTIST
@   EAST half (12,4) mt724 facing RIGHT sight 1
@             (14,1) mt522 facing LEFT  sight 2
@ The two eastern posts only exist as obstacles after the CARD KEY, which is
@ why GSC's fortress line belongs to one of them.
@ ============================================================================
RadioTower4F_EventScript_GruntA::
	trainerbattle_single TRAINER_JOHTO_ROCKET_RT4F_A, RadioTower4F_Text_GruntASeen, RadioTower4F_Text_GruntABeaten
	msgbox RadioTower4F_Text_GruntAAfter, MSGBOX_AUTOCLOSE
	end

RadioTower4F_EventScript_GruntB::
	trainerbattle_single TRAINER_JOHTO_ROCKET_RT4F_B, RadioTower4F_Text_GruntBSeen, RadioTower4F_Text_GruntBBeaten
	msgbox RadioTower4F_Text_GruntBAfter, MSGBOX_AUTOCLOSE
	end

RadioTower4F_EventScript_GruntC::
	trainerbattle_single TRAINER_JOHTO_ROCKET_RT4F_C, RadioTower4F_Text_GruntCSeen, RadioTower4F_Text_GruntCBeaten
	msgbox RadioTower4F_Text_GruntCAfter, MSGBOX_AUTOCLOSE
	end

RadioTower4F_EventScript_Rich::
	trainerbattle_single TRAINER_JOHTO_ROCKET_SCI_RICH, RadioTower4F_Text_RichSeen, RadioTower4F_Text_RichBeaten
	msgbox RadioTower4F_Text_RichAfter, MSGBOX_AUTOCLOSE
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

@ ============================================================================
@ Trinity M4b S8 text.
@ ============================================================================
RadioTower4F_Text_DJMaryHostage:
	.string "MARY: Why? Why do I have to sit\n"
	.string "through this?\p"
	.string "MEOWTH, help me!$"

RadioTower4F_Text_DJMarySaved:
	.string "MARY: Oh! You're my little\n"
	.string "saviour!\p"
	.string "They sat me in front of a live\n"
	.string "microphone for six hours and\l"
	.string "told me what to read.\p"
	.string "Will you take this, as my\n"
	.string "thanks?$"

RadioTower4F_Text_DJMaryScarf:
	.string "MARY: It's a SILK SCARF.\p"
	.string "Just right for a POKéMON that\n"
	.string "knows normal-type moves.\p"
	.string "And now, back to the music.$"

RadioTower4F_Text_GruntASeen:
	.string "You plan to rescue the\n"
	.string "DIRECTOR, do you?\p"
	.string "That won't be possible. I'm\n"
	.string "going to beat you.$"

RadioTower4F_Text_GruntABeaten:
	.string "No! Unbelievable!$"

RadioTower4F_Text_GruntAAfter:
	.string "I don't believe it. I was\n"
	.string "beaten.\p"
	.string "PRODUCTION was supposed to be\n"
	.string "the safe posting.$"

RadioTower4F_Text_GruntBSeen:
	.string "How did you get onto this side\n"
	.string "of the shutters?$"

RadioTower4F_Text_GruntBBeaten:
	.string "Oh, no. They're so useless!$"

RadioTower4F_Text_GruntBAfter:
	.string "One floor up is STUDIO 1.\p"
	.string "The boss doesn't come out of\n"
	.string "STUDIO 1 for anybody.$"

RadioTower4F_Text_GruntCSeen:
	.string "Stop right there.\p"
	.string "They call me the TEAM ROCKET\n"
	.string "fortress.\p"
	.string "You're not taking another step.$"

RadioTower4F_Text_GruntCBeaten:
	.string "The fortress came down!$"

RadioTower4F_Text_GruntCAfter:
	.string "You've earned my respect, so\n"
	.string "here's some advice.\p"
	.string "It isn't too late. You can\n"
	.string "still turn back.\p"
	.string "The man upstairs isn't the one\n"
	.string "you should be worried about.$"

RadioTower4F_Text_RichSeen:
	.string "Most excellent.\p"
	.string "This RADIO TOWER will fulfil\n"
	.string "our grand design.$"

RadioTower4F_Text_RichBeaten:
	.string "Hmmm…\p"
	.string "All grand plans come with\n"
	.string "snags.$"

RadioTower4F_Text_RichAfter:
	.string "Do you honestly believe you can\n"
	.string "stop TEAM ROCKET?\p"
	.string "We aren't a gang. We're a\n"
	.string "budget with people attached.$"
