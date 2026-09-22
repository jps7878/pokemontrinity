@ ============================================================================
@ Trinity M7b Task 13 -- BOBBY, the standing navigator (findings #9, #9b, #9c).
@
@ WHAT THIS FILE IS. Ten scripted POKéNAV calls, one per rung of the navigator
@ ladder, plus the shared state-aware helpers the post-league rungs and BOBBY's
@ two standing dialogues both use.
@
@ HOW A RUNG FIRES. TryStartStepCountScript (src/field_control_avatar.c) asks
@ TrinityGetPendingBobbyCall() once per overworld step; that function owns the
@ ONLY copy of the ladder (src/field_specials.c) and hands back the script for
@ the highest rung the world state satisfies, but only while that rung is
@ strictly greater than VAR_TRINITY_BOBBY_CALL_RUNG. These scripts are LEAVES:
@ none of them re-tests the ladder, so C and script cannot drift apart about
@ WHEN a rung is due.
@
@ EVERY RUNG WRITES ITS OWN LATCH VALUE, FIRST. The setvar is the first
@ instruction after lockall -- S4's I3(b) ordering rule (the durable half
@ first), and it means an interrupted message can never re-arm the call. One
@ writer per value, all ten in this file, which is what story_audit.py's
@ check_bobby_navigator() pins.
@
@ WHAT THIS FILE DOES NOT COVER. BOBBY cannot speak before the RADIO TOWER
@ reveal (arc-J >= 7) -- he is not a character the player knows until then. So
@ finding #9's OTHER stall, LAKE OF RAGE -> MAHOGANY at arc-J 4/5, is NOT
@ addressed here and is not claimed to be: that is static signposting, i.e.
@ M7b Task 14's bullet. Nothing in this file gives a mid-Johto player anything.
@
@ TEXT SHAPE. The "… … … … … … / … Beep!" open and "… / … Click!" close are
@ the tree's own POKéNAV-call frame -- all four shipped HOENN calls use it
@ (Route119, LittlerootTown_ProfessorBirchsLab, RustboroCity_Gym,
@ MauvilleCity). Body lines here are <= 34 characters with worst-case
@ placeholder expansion; the widest line in any shipped vanilla call is 36.
@
@ VOICE. BOBBY as established in RadioTower5F_Text_Bobby1..3, GoldenrodCity_
@ Text_Bobby and OlivinePort_Text_Bobby*: terse, wry, professional, and he DOES
@ use GIOVANNI's name when the name is the point (OlivinePort_Text_BobbySummons
@ does). These calls are the payoff of his GOLDENROD closing line, "I'll be
@ somewhere behind you."
@
@ COST: zero flags, zero trainer ids, zero map data, zero coordinates. The one
@ saved var is VAR_TRINITY_BOBBY_CALL_RUNG. No interactable is added, so the
@ M7 AFFORDANCE RULE has nothing to mark here.
@ ============================================================================

@ --- RUNG 1 -- arc-J >= 7: the RADIO TOWER is clear ------------------------
@ Two things the player can now do that nothing in the world says out loud:
@ the DIRECTOR's rewards are a SKIPPABLE talk (RadioTower5F_EventScript_
@ RescuedDirector), and the evidence crate in GIOVANNI's office opens at
@ arc-J >= 7 (TeamRocketBaseB3F_EventScript_EvidenceCrate) -- the SILVER WING
@ return trip finding #9 records as "communicated nowhere".
@
@ THIS RUNG IS EASY TO MISS, BY CONSTRUCTION. RADIO TOWER 5F is
@ MAP_TYPE_INDOOR and the DIRECTOR stands three tiles from where the reveal
@ ends, so the ordinary player talks to him (arc-J -> 8) BEFORE ever stepping
@ outdoors and receives rung 2 instead. Rung 2 therefore repeats the crate
@ paragraph whenever the SILVER WING is still unclaimed. Rung 1 exists for the
@ player who walks out of the tower first.
Trinity_EventScript_BobbyCall_TowerCleared::
	lockall
	setvar VAR_TRINITY_BOBBY_CALL_RUNG, 1
	pokenavcall Trinity_Text_BobbyCall_TowerCleared
	waitmessage
	releaseall
	end

@ --- RUNG 2 -- arc-J >= 8: the BELL and the WING are in hand ---------------
@ The CLEAR BELL is SUICUNE's gate at EcruteakTinTowerEntrance and the RAINBOW
@ WING is HO-OH's at TinTowerRoof, so this call names the chain. It branches
@ on FLAG_TRINITY_J_WING_SILVER because of the rung-1 note above: in the
@ ordinary order this is the FIRST call the player ever receives, and the
@ MAHOGANY crate must not be lost with rung 1.
Trinity_EventScript_BobbyCall_BellAndWing::
	lockall
	setvar VAR_TRINITY_BOBBY_CALL_RUNG, 2
	goto_if_unset FLAG_TRINITY_J_WING_SILVER, Trinity_EventScript_BobbyCall_BellAndWingCrate
	pokenavcall Trinity_Text_BobbyCall_BellAndWing
	waitmessage
	releaseall
	end

Trinity_EventScript_BobbyCall_BellAndWingCrate::
	pokenavcall Trinity_Text_BobbyCall_BellAndWingCrate
	waitmessage
	releaseall
	end

@ --- RUNG 3 -- arc-J >= 10: OLIVINE PORT ----------------------------------
@ THE HEADLINE FIX (finding #9c: "the OLIVINE PORT crossing WORKS, but nothing
@ tells the player to go there -- you only find BOBBY by already knowing").
@ His OLIVINE object is already visible in exactly this window
@ (OlivinePort_EventScript_SetBobbyVisibility: league cleared AND arc-J >= 10
@ AND FLAG_TRINITY_K_ARRIVED unset) -- this call is the pointer at an NPC who
@ was always standing there. It deliberately does NOT restate the pier speech
@ (OlivinePort_Text_BobbySummons, "GIOVANNI didn't stick around for INDIGO");
@ the pier owns that beat, this call owns the destination.
Trinity_EventScript_BobbyCall_OlivineSummons::
	lockall
	setvar VAR_TRINITY_BOBBY_CALL_RUNG, 3
	pokenavcall Trinity_Text_BobbyCall_OlivineSummons
	waitmessage
	releaseall
	end

@ --- RUNG 4 -- arc-K >= 1: arrival ----------------------------------------
@ The bug-test's own trigger case, stated correctly. The VIRIDIAN gym door is
@ `C-COUNT >= 7 AND arc-K >= 4` (ViridianCity_EventScript_GymDoorCheck), so
@ the eighth KANTO badge is NOT available on arrival and this call must not
@ say it is -- #9c records the founder at 7 badges / arc 1 assuming badge 24
@ was next and suspecting a story break. Every other KANTO gym is ungated
@ (grepped: no VAR_TRINITY_KANTO_ARC test in any other gym-door script).
Trinity_EventScript_BobbyCall_KantoArrival::
	lockall
	setvar VAR_TRINITY_BOBBY_CALL_RUNG, 4
	pokenavcall Trinity_Text_BobbyCall_KantoArrival
	waitmessage
	releaseall
	end

@ --- RUNG 5 -- arc-K >= 2: the GAME CORNER poster -------------------------
@ Finding #9's concrete instance: the poster's arc<2 refusal
@ (CeladonCity_GameCorner_Text_PosterTooEarly) is a dead end. BLUE's own
@ intel already names CELADON (ViridianCity_Text_BlueIntel); this names the
@ POSTER.
Trinity_EventScript_BobbyCall_Poster::
	lockall
	setvar VAR_TRINITY_BOBBY_CALL_RUNG, 5
	pokenavcall Trinity_Text_BobbyCall_Poster
	waitmessage
	releaseall
	end

@ --- RUNG 6 -- arc-K >= 3: the VIRIDIAN gym-yard grate --------------------
@ Pairs with M7 Task 9, which made (30,11) a real grate metatile (0x2DF).
@ Task 9 made it VISIBLE; this makes it FINDABLE. The evidence room's own text
@ hands the player "a set of coordinates"
@ (RocketHideout_B4F_Text_EvidenceCoordinates) -- this says which city.
Trinity_EventScript_BobbyCall_Grate::
	lockall
	setvar VAR_TRINITY_BOBBY_CALL_RUNG, 6
	pokenavcall Trinity_Text_BobbyCall_Grate
	waitmessage
	releaseall
	end

@ --- RUNG 7 -- arc-K >= 4: the VIRIDIAN GYM opens -------------------------
@ The door's real condition is C-COUNT >= 7 AND arc >= 4. Rung 4 already told
@ the player to leave VIRIDIAN for last; this is the other half arriving.
Trinity_EventScript_BobbyCall_GymOpen::
	lockall
	setvar VAR_TRINITY_BOBBY_CALL_RUNG, 7
	pokenavcall Trinity_Text_BobbyCall_GymOpen
	waitmessage
	releaseall
	end

@ --- RUNG 8 -- FLAG_TRINITY_BADGE24: the road to INDIGO -------------------
@ Keyed on the BADGE, not on arc-K 5, because arc 5 (SILVER's final fight on
@ ROUTE 1) is skippable and off the mandatory path -- data/maps/Route1/
@ scripts.inc:9-16 records that a tree-wide grep found NO NPC, sign or scene
@ anywhere pointing the player there. This call is that pointer, and it drops
@ the SILVER paragraph once he has actually been fought. goto_if_defeated is
@ the same engine-flag idiom Route1 itself uses for its own hide condition --
@ no custom flag.
Trinity_EventScript_BobbyCall_LeagueRoad::
	lockall
	setvar VAR_TRINITY_BOBBY_CALL_RUNG, 8
	goto_if_defeated TRAINER_SILVER_FINAL, Trinity_EventScript_BobbyCall_LeagueRoadSilverDone
	pokenavcall Trinity_Text_BobbyCall_LeagueRoad
	waitmessage
	releaseall
	end

Trinity_EventScript_BobbyCall_LeagueRoadSilverDone::
	pokenavcall Trinity_Text_BobbyCall_LeagueRoadSilverDone
	waitmessage
	releaseall
	end

@ --- RUNG 9 -- arc-K >= 6: post-league ------------------------------------
@ Second half of finding #9c: state-aware about unresolved JOHTO legendaries.
@ The picker names ONE outstanding place into STR_VAR_1 -- a call is a nudge;
@ BOBBY's two standing dialogues are the full list (see the bottom of this
@ file). The MT. SILVER line is true from here: Route28_EventScript_
@ SilverCaveGateCheck opens at VAR_TRINITY_KANTO_ARC >= 6.
Trinity_EventScript_BobbyCall_PostLeague::
	lockall
	setvar VAR_TRINITY_BOBBY_CALL_RUNG, 9
	call Trinity_EventScript_BobbyPickOutstanding
	goto_if_eq VAR_RESULT, FALSE, Trinity_EventScript_BobbyCall_PostLeagueQuiet
	pokenavcall Trinity_Text_BobbyCall_PostLeague
	waitmessage
	releaseall
	end

Trinity_EventScript_BobbyCall_PostLeagueQuiet::
	pokenavcall Trinity_Text_BobbyCall_PostLeagueQuiet
	waitmessage
	releaseall
	end

@ --- RUNG 10 -- arc-K >= 7: the farewell ----------------------------------
@ This rung ALSO carries the state-aware line, and that is not duplication:
@ the ladder hands out the HIGHEST satisfied rung, so a save that is already
@ past the KANTO league when the navigator ships receives rung 9 or rung 10
@ and NOTHING ELSE. Whichever one it lands on has to carry the report.
Trinity_EventScript_BobbyCall_Farewell::
	lockall
	setvar VAR_TRINITY_BOBBY_CALL_RUNG, 10
	call Trinity_EventScript_BobbyPickOutstanding
	goto_if_eq VAR_RESULT, FALSE, Trinity_EventScript_BobbyCall_FarewellQuiet
	pokenavcall Trinity_Text_BobbyCall_Farewell
	waitmessage
	releaseall
	end

Trinity_EventScript_BobbyCall_FarewellQuiet::
	pokenavcall Trinity_Text_BobbyCall_FarewellQuiet
	waitmessage
	releaseall
	end

@ ============================================================================
@ STATE AWARENESS -- finding #9c's second half, and it costs ZERO new flags:
@ every condition below is an existing terminal flag or scene value.
@
@ ORDER IS "WHAT CAN THE PLAYER ACTUALLY DO NEXT", not roster order. Each
@ entry names a REACHABLE place: a legendary sitting behind a token the player
@ has not collected is reported as the TOKEN's location, never as the sealed
@ door. That is why the CLEAR BELL and the SILVER WING get entries of their
@ own.
@   1 CLEAR BELL unset      -> the RADIO TOWER (the DIRECTOR's rewards are a
@                             skippable talk; the BELL is SUICUNE's gate at
@                             EcruteakTinTowerEntrance and the RAINBOW WING
@                             comes from the same scene)
@   2 SCENE_TINTOWER < 2    -> the TIN TOWER      (SUICUNE, terminal value 2)
@   3 HOOH_RESOLVED unset   -> the TIN TOWER roof (needs SCENE_TINTOWER >= 2,
@                             which entry 2 has already sent them to get)
@   4 LUGIA unresolved AND
@     WING_SILVER unset     -> the BASE under MAHOGANY (arc-J >= 7 evidence
@                             crate, TeamRocketBaseB3F -- the return trip
@                             finding #9 says is "communicated nowhere")
@   5 LUGIA_RESOLVED unset  -> the WHIRL ISLANDS  (the founder's own example)
@   6 RAIKOU_RESOLVED unset -> MT.MORTAR
@   7 ENTEI_RESOLVED unset  -> DARK CAVE
@ There is no per-legendary "caught vs beaten" split in this tree: each _RESOLVED
@ flag is set on WON and on the CAUGHT fall-through alike (the M4b S10 legendary
@ contract), so one flag is the whole terminal truth.
@ FLAG_TRINITY_J_SUICUNE_CIANWOOD is deliberately NOT read: flags.h:705 records
@ that it has no script reader anywhere and is not the beast gate. None of the
@ _HIDE flags are read either -- they are visibility plumbing re-authored on
@ every ON_TRANSITION, not durable truth, so reading one would be a bug.
@
@ The KANTO legendaries (ARTICUNO, ZAPDOS, MOLTRES, MEWTWO) are deliberately
@ absent: #9c named the JOHTO set, the ones behind invisible wing/bell gates.
@ Each KANTO bird sits in a place the player physically walks into.
@
@ CALLED, NOT JUMPED TO: this helper ends in `return` and its callers own the
@ lock. The call -> goto -> return shape is this tree's own
@ (OlivinePort_EventScript_SetBobbyVisibility).
@ ============================================================================
Trinity_EventScript_BobbyPickOutstanding::
	setvar VAR_RESULT, TRUE
	goto_if_unset FLAG_TRINITY_J_CLEAR_BELL, Trinity_EventScript_BobbyOutstandingRadioTower
	goto_if_lt VAR_TRINITY_JOHTO_SCENE_TINTOWER, 2, Trinity_EventScript_BobbyOutstandingTinTower
	goto_if_unset FLAG_TRINITY_J_HOOH_RESOLVED, Trinity_EventScript_BobbyOutstandingRoof
	goto_if_set FLAG_TRINITY_J_LUGIA_RESOLVED, Trinity_EventScript_BobbyPickOutstandingBeasts
	goto_if_unset FLAG_TRINITY_J_WING_SILVER, Trinity_EventScript_BobbyOutstandingRocketBase
	goto Trinity_EventScript_BobbyOutstandingWhirlIslands

Trinity_EventScript_BobbyPickOutstandingBeasts::
	goto_if_unset FLAG_TRINITY_J_RAIKOU_RESOLVED, Trinity_EventScript_BobbyOutstandingMtMortar
	goto_if_unset FLAG_TRINITY_J_ENTEI_RESOLVED, Trinity_EventScript_BobbyOutstandingDarkCave
	setvar VAR_RESULT, FALSE
	return

Trinity_EventScript_BobbyOutstandingRadioTower::
	bufferstring STR_VAR_1, Trinity_Text_PlaceRadioTower
	return

Trinity_EventScript_BobbyOutstandingTinTower::
	bufferstring STR_VAR_1, Trinity_Text_PlaceTinTower
	return

Trinity_EventScript_BobbyOutstandingRoof::
	bufferstring STR_VAR_1, Trinity_Text_PlaceTinTowerRoof
	return

Trinity_EventScript_BobbyOutstandingRocketBase::
	bufferstring STR_VAR_1, Trinity_Text_PlaceRocketBase
	return

Trinity_EventScript_BobbyOutstandingWhirlIslands::
	bufferstring STR_VAR_1, Trinity_Text_PlaceWhirlIslands
	return

Trinity_EventScript_BobbyOutstandingMtMortar::
	bufferstring STR_VAR_1, Trinity_Text_PlaceMtMortar
	return

Trinity_EventScript_BobbyOutstandingDarkCave::
	bufferstring STR_VAR_1, Trinity_Text_PlaceDarkCave
	return

@ Buffered place strings. Longest is 23 characters (the BASE under MAHOGANY);
@ every host line was counted against that worst case.
Trinity_Text_PlaceRadioTower:
	.string "the RADIO TOWER$"

Trinity_Text_PlaceTinTower:
	.string "the TIN TOWER$"

Trinity_Text_PlaceTinTowerRoof:
	.string "the TIN TOWER's roof$"

Trinity_Text_PlaceRocketBase:
	.string "the BASE under MAHOGANY$"

Trinity_Text_PlaceWhirlIslands:
	.string "the WHIRL ISLANDS$"

Trinity_Text_PlaceMtMortar:
	.string "MT.MORTAR$"

Trinity_Text_PlaceDarkCave:
	.string "DARK CAVE$"

@ ============================================================================
@ BOBBY'S STANDING REFERENCE -- finding #9c's "and/or his pier dialogue", the
@ half that names EVERYTHING still outstanding instead of one thing.
@
@ IT HANGS IN TWO PLACES, BOTH REACHABLE WITHOUT WINNING ANYTHING NEW:
@   * OLIVINE PORT, his pier dialogue -- OlivinePort_EventScript_BobbyDecline
@     and _BobbyWaiting, i.e. "not yet" to the boat. Zero gates beyond being
@     at the pier at all, which is the crossing itself, and it is exactly the
@     audience: the player has just cleared the JOHTO league and everything on
@     this list is JOHTO content he is about to sail away from.
@   * INDIGO PLATEAU POKéMON CENTER -- _BobbyBriefing and _BobbyClaimed, the
@     two terminal repeat lines of his reward flow. Both are reached from 8
@     KANTO badges onward (his object's own spawn condition,
@     FLAG_TRINITY_K_KANTO_CAST_HIDE), and _BobbyBriefing is the branch a
@     player who has NOT done the family gauntlet lands on -- so the reference
@     is not behind the gauntlet, the farewell battle, or the reward.
@
@ Same conditions as the picker above, evaluated independently so the list can
@ be read top to bottom as an order of operations.
@
@ This script is reached by `call` and therefore ENDS IN `return`, not
@ release/end -- each caller owns the lock.
@ ============================================================================
Trinity_EventScript_BobbyLegendaryReport::
	call Trinity_EventScript_BobbyPickOutstanding
	goto_if_eq VAR_RESULT, FALSE, Trinity_EventScript_BobbyReportAllQuiet
	msgbox Trinity_Text_BobbyReportIntro, MSGBOX_DEFAULT
	call_if_unset FLAG_TRINITY_J_CLEAR_BELL, Trinity_EventScript_BobbyReportBell
	call_if_lt VAR_TRINITY_JOHTO_SCENE_TINTOWER, 2, Trinity_EventScript_BobbyReportSuicune
	call_if_unset FLAG_TRINITY_J_HOOH_RESOLVED, Trinity_EventScript_BobbyReportHoOh
	call_if_unset FLAG_TRINITY_J_WING_SILVER, Trinity_EventScript_BobbyReportWing
	call_if_unset FLAG_TRINITY_J_LUGIA_RESOLVED, Trinity_EventScript_BobbyReportLugia
	call_if_unset FLAG_TRINITY_J_RAIKOU_RESOLVED, Trinity_EventScript_BobbyReportRaikou
	call_if_unset FLAG_TRINITY_J_ENTEI_RESOLVED, Trinity_EventScript_BobbyReportEntei
	return

Trinity_EventScript_BobbyReportAllQuiet::
	msgbox Trinity_Text_BobbyReportAllQuiet, MSGBOX_DEFAULT
	return

Trinity_EventScript_BobbyReportBell::
	msgbox Trinity_Text_BobbyReportBell, MSGBOX_DEFAULT
	return

Trinity_EventScript_BobbyReportSuicune::
	msgbox Trinity_Text_BobbyReportSuicune, MSGBOX_DEFAULT
	return

Trinity_EventScript_BobbyReportHoOh::
	msgbox Trinity_Text_BobbyReportHoOh, MSGBOX_DEFAULT
	return

Trinity_EventScript_BobbyReportWing::
	msgbox Trinity_Text_BobbyReportWing, MSGBOX_DEFAULT
	return

Trinity_EventScript_BobbyReportLugia::
	msgbox Trinity_Text_BobbyReportLugia, MSGBOX_DEFAULT
	return

Trinity_EventScript_BobbyReportRaikou::
	msgbox Trinity_Text_BobbyReportRaikou, MSGBOX_DEFAULT
	return

Trinity_EventScript_BobbyReportEntei::
	msgbox Trinity_Text_BobbyReportEntei, MSGBOX_DEFAULT
	return

@ ============================================================================
@ TEXT. Frame copied from the four shipped HOENN pokenavcall texts. `…` is
@ charmap.txt:87 (U+2026 = B0), `-` is charmap.txt:84 (AE) -- hence "--" and
@ never an em dash. Body lines counted at <= 34 with {PLAYER} = 7 and
@ {STR_VAR_1} = 23 (the longest buffered place string).
@ ============================================================================

Trinity_Text_BobbyCall_TowerCleared:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "BOBBY: The TOWER's yours. Good\n"
	.string "work on ARCHER.\p"
	.string "The DIRECTOR is loose on 5F and\n"
	.string "he's been trying to thank\l"
	.string "somebody all week. Go and let\l"
	.string "him.\p"
	.string "And the BASE under MAHOGANY.\n"
	.string "You cleared it. You never\l"
	.string "emptied it.\p"
	.string "There's a crate in GIOVANNI's\n"
	.string "old office on B3F, and it opens\l"
	.string "for you now. Go back for it.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Trinity_Text_BobbyCall_BellAndWing:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "BOBBY: A BELL and a WING. He\n"
	.string "doesn't hand those out twice.\p"
	.string "The CLEAR BELL is a key. Show\n"
	.string "it to the sages at the TIN\l"
	.string "TOWER gate in ECRUTEAK.\p"
	.string "The RAINBOW WING is a key too.\n"
	.string "The top of that tower is where\l"
	.string "it fits.\p"
	.string "Finish the badges first. INDIGO\n"
	.string "isn't going anywhere.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Trinity_Text_BobbyCall_BellAndWingCrate:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "BOBBY: A BELL and a WING. He\n"
	.string "doesn't hand those out twice.\p"
	.string "The CLEAR BELL is a key. Show\n"
	.string "it to the sages at the TIN\l"
	.string "TOWER gate in ECRUTEAK.\p"
	.string "The RAINBOW WING is a key too.\n"
	.string "The top of that tower is where\l"
	.string "it fits.\p"
	.string "One more. The BASE under\n"
	.string "MAHOGANY -- you cleared it, you\l"
	.string "never emptied it.\p"
	.string "GIOVANNI's old office, B3F.\n"
	.string "There's a crate in it that's\l"
	.string "open to you now. Go back.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Trinity_Text_BobbyCall_OlivineSummons:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "BOBBY: CHAMPION of JOHTO. Two\n"
	.string "LEAGUES now. Nobody else has\l"
	.string "ever done that.\p"
	.string "I'm not calling to congratulate\n"
	.string "you. I'm calling because I need\l"
	.string "you on a boat.\p"
	.string "OLIVINE PORT, out on the pier.\n"
	.string "I'll be the one who looks like\l"
	.string "he's been up all night.\p"
	.string "Come and find me when you're\n"
	.string "packed, {PLAYER}.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Trinity_Text_BobbyCall_KantoArrival:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "BOBBY: You're across. Good.\p"
	.string "KANTO runs eight GYMS of its\n"
	.string "own. Badges 17 through 24.\p"
	.string "Take them in any order but one.\n"
	.string "VIRIDIAN's GYM has no LEADER in\l"
	.string "it, and that door will not open\l"
	.string "until the other seven badges\l"
	.string "are on you.\p"
	.string "So leave VIRIDIAN for last.\p"
	.string "BLUE was seen sitting outside\n"
	.string "it. Talk to him -- he knows\l"
	.string "something.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Trinity_Text_BobbyCall_Poster:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "BOBBY: I heard what BLUE told\n"
	.string "you. He's right.\p"
	.string "CELADON's GAME CORNER takes in\n"
	.string "more than it pays out, and none\l"
	.string "of what it takes stays in\l"
	.string "CELADON.\p"
	.string "There's a poster on the back\n"
	.string "wall of that place that doesn't\l"
	.string "sit flat.\p"
	.string "Push on it.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Trinity_Text_BobbyCall_Grate:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "BOBBY: A GS BALL and a set of\n"
	.string "coordinates. Good day's work.\p"
	.string "Those numbers are VIRIDIAN. The\n"
	.string "GYM yard, west side.\p"
	.string "There's a service grate down at\n"
	.string "ground level that nobody has\l"
	.string "ever serviced.\p"
	.string "Mind yourself under that city.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Trinity_Text_BobbyCall_GymOpen:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "BOBBY: The rig is scrap and the\n"
	.string "man walked out of his own\l"
	.string "basement. Of course he did.\p"
	.string "He's gone upstairs. The\n"
	.string "VIRIDIAN GYM is his. It always\l"
	.string "was.\p"
	.string "Bring seven KANTO badges to\n"
	.string "that door and it opens. He'll\l"
	.string "be the eighth.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Trinity_Text_BobbyCall_LeagueRoad:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "BOBBY: Twenty-four badges. No\n"
	.string "one has ever carried that many\l"
	.string "at once.\p"
	.string "The LEAGUE is west of VIRIDIAN.\n"
	.string "ROUTE 22, then ROUTE 23, then\l"
	.string "VICTORY ROAD. That's your road.\p"
	.string "One more thing. Someone with\n"
	.string "red hair is waiting on ROUTE 1,\l"
	.string "the road south out of VIRIDIAN.\p"
	.string "He didn't come this far to be\n"
	.string "walked past.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Trinity_Text_BobbyCall_LeagueRoadSilverDone:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "BOBBY: Twenty-four badges. No\n"
	.string "one has ever carried that many\l"
	.string "at once.\p"
	.string "The LEAGUE is west of VIRIDIAN.\n"
	.string "ROUTE 22, then ROUTE 23, then\l"
	.string "VICTORY ROAD. That's your road.\p"
	.string "Go and be the first.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Trinity_Text_BobbyCall_PostLeague:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "BOBBY: CHAMPION of three\n"
	.string "regions. I'd call my file\l"
	.string "closed on that.\p"
	.string "Two loose ends. The climb to\n"
	.string "MT. SILVER off ROUTE 28 is open\l"
	.string "to you now. They don't let just\l"
	.string "anyone up there.\p"
	.string "And reports are still coming in\n"
	.string "from {STR_VAR_1}.\p"
	.string "Whatever woke up in JOHTO never\n"
	.string "went back to sleep.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Trinity_Text_BobbyCall_PostLeagueQuiet:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "BOBBY: CHAMPION of three\n"
	.string "regions. I'd call my file\l"
	.string "closed on that.\p"
	.string "One loose end. The climb to\n"
	.string "MT. SILVER off ROUTE 28 is open\l"
	.string "to you now. They don't let just\l"
	.string "anyone up there.\p"
	.string "JOHTO's gone quiet, by the way.\n"
	.string "Every one of them accounted\l"
	.string "for.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Trinity_Text_BobbyCall_Farewell:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "BOBBY: They told me nobody had\n"
	.string "been up MT. SILVER in years.\p"
	.string "Then you went up, came down,\n"
	.string "and never said a word about it.\p"
	.string "File's closed, {PLAYER}. Next\n"
	.string "time I'd rather hear it from\l"
	.string "you than read it in a report.\p"
	.string "One thing still open: reports\n"
	.string "out of {STR_VAR_1}.\p"
	.string "Take care of yourself.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Trinity_Text_BobbyCall_FarewellQuiet:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "BOBBY: They told me nobody had\n"
	.string "been up MT. SILVER in years.\p"
	.string "Then you went up, came down,\n"
	.string "and never said a word about it.\p"
	.string "File's closed, {PLAYER}. There\n"
	.string "is nothing left stirring in\l"
	.string "three regions.\p"
	.string "Next time I'd rather hear it\n"
	.string "from you than read it in a\l"
	.string "report. Take care of yourself.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Trinity_Text_BobbyReportIntro:
	.string "BOBBY: You want the list? Fine.\n"
	.string "Here's what's still open in\l"
	.string "JOHTO.$"

Trinity_Text_BobbyReportBell:
	.string "The DIRECTOR in GOLDENROD still\n"
	.string "owes you two things -- a BELL\l"
	.string "and a WING. Go and collect.$"

Trinity_Text_BobbyReportSuicune:
	.string "The TIN TOWER in ECRUTEAK. The\n"
	.string "sages say something is pacing\l"
	.string "the floor in there.$"

Trinity_Text_BobbyReportHoOh:
	.string "And above it, the roof. The\n"
	.string "RAINBOW WING is a key, not a\l"
	.string "keepsake.$"

Trinity_Text_BobbyReportWing:
	.string "The crate in GIOVANNI's office,\n"
	.string "B3F of the BASE under MAHOGANY.\l"
	.string "The SILVER WING is still in it.$"

Trinity_Text_BobbyReportLugia:
	.string "The WHIRL ISLANDS, off\n"
	.string "CIANWOOD. The sea down there\l"
	.string "hasn't settled since you took\l"
	.string "that WING.$"

Trinity_Text_BobbyReportRaikou:
	.string "MT.MORTAR. Storms inside a\n"
	.string "mountain. That's one of the\l"
	.string "three that ran from ECRUTEAK.$"

Trinity_Text_BobbyReportEntei:
	.string "DARK CAVE, the BLACKTHORN side.\n"
	.string "Warm rock and no fire in it.\l"
	.string "That's the second one.$"

Trinity_Text_BobbyReportAllQuiet:
	.string "BOBBY: Nothing left on my desk.\p"
	.string "Every one of the JOHTO beasts\n"
	.string "accounted for, both WINGS\l"
	.string "spent.\p"
	.string "You've been thorough, {PLAYER}.$"
