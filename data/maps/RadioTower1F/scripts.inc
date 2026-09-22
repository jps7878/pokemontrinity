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
@ ---- CORRECTIONS S8 MUST READ BEFORE IT ADDS ANYTHING ----------------------
@
@ (1) FOUR OF S4's TOWER STAFF ARE GSC'S *POST-CLEAR* CAST. In the story
@     inventory they carry EVENT_RADIO_TOWER_CIVILIANS_AFTER, not
@     EVENT_GOLDENROD_CITY_CIVILIANS -- S4 brought them forward on purpose, so
@     the tower is not half-empty before the raid. They are:
@         2F BLACK BELT   (1,1)
@         3F SUPER NERD   (7,4)
@         4F FISHER       (6,4)
@         5F DJ BEN      (13,5)
@     If S8 appends GSC's CIVILIANS_AFTER set wholesale it will DOUBLE-PLACE
@     all four. Either skip them or drop S4's copies -- do not do both halves.
@
@ (2) DJ BEN'S (13,5) IS GSC'S 5F TAKEOVER-ROCKET TILE. GSC parks
@     SPRITE_ROCKET on exactly (13,5) under EVENT_RADIO_TOWER_ROCKET_TAKEOVER.
@     The predicates are opposites (BEN visible iff ARC != 6, a takeover Rocket
@     visible iff ARC == 6), so a stack is SAFE and never renders two sprites at
@     once -- but it is a stack, and stacked objects are a debugging trap. S8
@     should offset its Rocket by a tile or accept the overlap knowingly.
@
@ (3) THE ON_TRANSITION SLOT IS SINGLE-OCCUPANCY. MapHeaderGetScriptTable walks
@     the map-script table and RETURNS ON THE FIRST entry matching the tag
@     (src/script.c:302-321), so adding a second
@     `map_script MAP_SCRIPT_ON_TRANSITION` to any of these five floors is
@     silently dead code. S8's arc-6 write must live in a coord_event, an
@     ON_FRAME table, another map -- or S8 edits these scripts.
@
@ (4) ORDERING HAZARD. These calls READ VAR_TRINITY_JOHTO_ARC when they run. If
@     an arc write ever lands in the same transition AFTER them, the flags
@     describe the PREVIOUS state and the flip lags by one map load. Put any
@     arc write before the visibility calls.
@
@ (5) THE DIRECTOR ESCAPE HATCH EDITS S4 FILES. Giving RadioTower5F's DIRECTOR
@     his own predicate (see that file's header) means claiming a flag and
@     adding a call to RadioTower5F's ON_TRANSITION. That is the contract
@     working as designed, not a violation -- but it is a second pass over an
@     S4 file, so no promise is made here that S4's files are frozen.
@     GoldenrodCity's ROCKET SCOUT is the worked example of the same hatch.
@
@ DECODE NOTE. 1F has a 16-tile region (x5..x12, y6..y7) that is unreachable on
@ foot with ZERO objects placed -- it is the inside of the reception desk. The
@ LUCKY NUMBER MAN (8,6) and the RADIO CARD WOMAN (12,6) sit in it, exactly as
@ GSC places them (RadioTower1F.asm:492-493), and are served over the
@ MB_COUNTER row at y=5 (GetInteractedObjectEventScript ->
@ MetatileBehavior_IsCounter -> look one tile further,
@ src/field_control_avatar.c:387-396). Objects on already-unreachable tiles
@ cost zero walkability. ELEVATION NUANCE (full statement in
@ GoldenrodDeptStore5F/scripts.inc): the lookup compares the NPC's elevation
@ against the PLAYER'S, not the counter's -- service tiles (8,4)/(12,4)/(5,4)
@ and all three desk slots decode elevation 3, so they match; the counters at
@ y=5 decode elevation 0 and are never compared.
@ ============================================================================
RadioTower1F_OnTransition:
	call RadioTower_EventScript_SetPreTakeoverVisibility
	call RadioTower_EventScript_SetTakeoverVisibility
	end

@ Shared by all five floors -- one predicate, one place to read it.
RadioTower_EventScript_SetPreTakeoverVisibility::
	goto_if_eq VAR_TRINITY_JOHTO_ARC, 6, RadioTower_EventScript_HidePreTakeover
	clearflag FLAG_TRINITY_J_RADIO_TOWER_PRE_HIDE
	return

RadioTower_EventScript_HidePreTakeover::
	setflag FLAG_TRINITY_J_RADIO_TOWER_PRE_HIDE
	return

@ ============================================================================
@ Trinity M4b S8 -- THE OCCUPATION CAST, the exact complement of the above.
@ Shared by all five floors, same shape, one place to read it.
@
@   FLAG_TRINITY_J_TOWER_ROCKETS_HIDE    visible iff VAR_TRINITY_JOHTO_ARC == 6
@
@ Thirteen sight-triggered posts across 1F-4F (R2's grunt shape). ARCHER and
@ ARIANA on 5F ride a SEPARATE flag, because the liberation scene removeobject's
@ them and removeobject CO-SIGNS the flag -- on this shared one that single
@ tidy-up would delete all fifteen posts (R1's trap, S7's cross-map corollary).
@ Nothing on this flag is ever removeobject'd.
@ ============================================================================
RadioTower_EventScript_SetTakeoverVisibility::
	goto_if_ne VAR_TRINITY_JOHTO_ARC, 6, RadioTower_EventScript_HideTakeover
	clearflag FLAG_TRINITY_J_TOWER_ROCKETS_HIDE
	return

RadioTower_EventScript_HideTakeover::
	setflag FLAG_TRINITY_J_TOWER_ROCKETS_HIDE
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
	@ M7b Task 14 (finding #9): the RADIO CARD is the channel, so the person
	@ who fits it reads the player today's bulletin -- the same arc-keyed
	@ ladder every JOHTO hub guide reads. Reached only through the existing
	@ goto_if_set FLAG_TRINITY_J_RADIO_CARD branch above.
	goto Trinity_EventScript_JohtoGuide
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

@ ============================================================================
@ Trinity M4b S8 -- the occupation. ROCKET-POST PATTERN R2: an ordinary
@ sight-triggered TRAINER_TYPE_NORMAL post, so PlayTrainerEncounterMusic's
@ map-BGM swap is correct for him and no NO_MUSIC is wanted.
@
@ DECODE (14,1): metatile 526, collision 0, elevation 3, MB_NORMAL. GSC's own
@ tile (RadioTower1F.asm:491). Facing DOWN with sight 3 puts his cone on
@ (14,2) (14,3) (14,4) -- row 2 is the open concourse the player has to walk
@ east along to reach the 2F stairs at (15,0), so he cannot be slipped past.
@ He seals nothing: (14,1) hangs off row 2 with (13,1) and (15,1) both open.
@ ============================================================================
RadioTower1F_EventScript_Grunt::
	trainerbattle_single TRAINER_ROCKET_GRUNT_M_8, RadioTower1F_Text_GruntSeen, RadioTower1F_Text_GruntBeaten
	msgbox RadioTower1F_Text_GruntAfter, MSGBOX_AUTOCLOSE
	end

RadioTower1F_Text_GruntSeen:
	.string "We've taken the RADIO TOWER.\p"
	.string "Every set in JOHTO, every car\n"
	.string "radio, every POKéGEAR -- ours.\p"
	.string "Now the whole region gets to\n"
	.string "hear what TEAM ROCKET sounds\l"
	.string "like.$"

RadioTower1F_Text_GruntBeaten:
	.string "Too strong. We'll have to\n"
	.string "watch you…$"

RadioTower1F_Text_GruntAfter:
	.string "You're too strong.\p"
	.string "The plan could come apart. I\n"
	.string "have to warn the others…$"
