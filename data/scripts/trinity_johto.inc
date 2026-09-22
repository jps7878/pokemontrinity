@ ============================================================================
@ Trinity -- shared Act II (JOHTO) script helpers.
@
@ C-COUNT -- COUNTING JOHTO BADGES. Authored by M4b S8; reusable by S9-S12.
@
@ Johto badges 9-16 are PLAIN FLAGS with no engine UI (GYM PATTERN G7), so
@ there is no GetBadgeCount special to call the way Hoenn's badge specials
@ count FLAG_BADGE01..08. The count is script arithmetic instead: eight
@ call_if_set into one increment subroutine.
@
@ VAR_TEMP_A, not VAR_TEMP_0/1/3: those three carry vanilla aliases
@ (VAR_TEMP_CHALLENGE_STATUS, VAR_TEMP_RECORD_MIX_GIFT_ITEM and the TV counter,
@ include/constants/vars.h:347-350). The whole TEMP block is cleared on map load
@ by ClearTempFieldEventData, which cannot race this: a script context runs
@ synchronously to completion, so the value is always consumed in the same run
@ that wrote it.
@
@ G7 DISCIPLINE: this reads the badge flags and NEVER writes one. Only a
@ <Leader>Defeated continuation writes FLAG_TRINITY_BADGE<NN>.
@
@ C-COUNT ALSO SPEAKS (M7b Task 15, finding #6). The count is buffered into
@ STR_VAR_1 as well as written to VAR_TEMP_A, so any text on a caller's path can
@ print the player's ACTUAL number with no buffer line of its own -- which is the
@ whole of finding #6's complaint: "the gate counts internally but never states
@ the number".
@ AUDITED WHEN ADDED: every file that calls either counter was grepped, and none
@ of them writes or prints STR_VAR_1/2/3 anywhere, so nothing of theirs is
@ clobbered. One caller is a MAP-LOAD script --
@ GoldenrodCity_EventScript_TryRocketTakeover (data/maps/GoldenrodCity/
@ scripts.inc:92) runs from GoldenrodCity_OnTransition -- so a GOLDENROD arrival
@ at JOHTO arc 5 rewrites STR_VAR_1 before the map draws; no text in that map
@ prints a buffer, so the write is observed by nothing.
@ THE NEW OBLIGATION this creates: a caller must not hold a string in STR_VAR_1
@ across the call.
@ G7 DISCIPLINE IS UNCHANGED -- buffering is a read of the badge flags, never a
@ write of one.
@
@ Usage:
@       call Trinity_EventScript_CountJohtoBadges
@       goto_if_lt VAR_TEMP_A, 7, <not enough>
@       ... and {STR_VAR_1} in any text on that path prints the same number.
@ ============================================================================
Trinity_EventScript_CountJohtoBadges::
	setvar VAR_TEMP_A, 0
	call_if_set FLAG_TRINITY_BADGE09, Trinity_EventScript_IncBadgeCount
	call_if_set FLAG_TRINITY_BADGE10, Trinity_EventScript_IncBadgeCount
	call_if_set FLAG_TRINITY_BADGE11, Trinity_EventScript_IncBadgeCount
	call_if_set FLAG_TRINITY_BADGE12, Trinity_EventScript_IncBadgeCount
	call_if_set FLAG_TRINITY_BADGE13, Trinity_EventScript_IncBadgeCount
	call_if_set FLAG_TRINITY_BADGE14, Trinity_EventScript_IncBadgeCount
	call_if_set FLAG_TRINITY_BADGE15, Trinity_EventScript_IncBadgeCount
	call_if_set FLAG_TRINITY_BADGE16, Trinity_EventScript_IncBadgeCount
	buffernumberstring STR_VAR_1, VAR_TEMP_A
	return

Trinity_EventScript_IncBadgeCount::
	addvar VAR_TEMP_A, 1
	return

@ ============================================================================
@ THE POST-VICTORY TALLY (M7b Task 15, finding #6). Called by the seven guides
@ who stand inside a JOHTO gym -- CIANWOOD GYM has no guide object (its
@ map.json casts four BLACK BELTs and CHUCK), and neither does GSC's gym:
@ GSC stands that guide in the Pokemon Center, where he still is and is
@ deliberately left alone (see THE JOHTO SIGNPOST LADDER header below).
@ Information only: it
@ reads the badge flags and writes none of them (G7).
@ The number is spoken at the moment it changes, and both lines name the gate
@ the number is FOR: the LEAGUE gate on ROUTE 26, whose check is
@ Route26_EventScript_LeagueGateCheck (VAR_TEMP_A >= 8,
@ data/maps/Route26/scripts.inc:111-112). Where the NEXT badge is belongs to
@ Task 14's signpost voice, not here -- this speaks state, not directions.
@ ============================================================================
Trinity_EventScript_JohtoBadgeTally::
	call Trinity_EventScript_CountJohtoBadges
	goto_if_ge VAR_TEMP_A, 8, Trinity_EventScript_JohtoBadgeTallyAll
	msgbox Trinity_Text_JohtoBadgeTally, MSGBOX_DEFAULT
	return

Trinity_EventScript_JohtoBadgeTallyAll::
	msgbox Trinity_Text_JohtoBadgeTallyAll, MSGBOX_DEFAULT
	return

Trinity_Text_JohtoBadgeTally:
	.string "Your JOHTO BADGE count: {STR_VAR_1}.\p"
	.string "The LEAGUE gate on ROUTE 26 opens\n"
	.string "at eight.$"

Trinity_Text_JohtoBadgeTallyAll:
	.string "Your JOHTO BADGE count: {STR_VAR_1}.\p"
	.string "All eight. The LEAGUE gate on\n"
	.string "ROUTE 26 is open to you now.$"

@ ============================================================================
@ THE JOHTO SIGNPOST LADDER (M7b Task 14, finding #9).
@
@ "this is not a linear Pokemon game -- the player can be anywhere in three
@ regions -- so the world itself has to tell you where the story is."
@ (founder, 2026-09-07).
@
@ ONE ladder. It is read by the nine JOHTO hub Pokemon Center guides, by the
@ SEVEN gym guides who stand INSIDE a JOHTO gym, and by the two RADIO CARD
@ flavour NPCs.
@
@ CIANWOOD IS THE ONE GYM WHOSE GUIDE IS NOT WIRED, and deliberately.
@ CIANWOOD GYM's map.json casts no guide at all (four BLACK BELTs and CHUCK);
@ GSC stands CHUCK's guide in the Pokemon Center instead, and he is still
@ there -- CianwoodPokecenter1F_EventScript_CianwoodGymGuide,
@ OBJ_EVENT_GFX_EXPERT_M at (5,3), untouched. He is NOT that hub's guide:
@ Cianwood's hub guide is a DIFFERENT object in the same room, the SUPER NERD
@ (OBJ_EVENT_GFX_SCIENTIST_1 at (8,6)), and the SUPER NERD reads this ladder
@ in EVERY arc state. A post-badge branch on the gym guide would therefore
@ print the same page a second time in one room, and would say strictly less
@ than the SUPER NERD across the room already says unprompted -- so
@ requirement (d) is covered for CIANWOOD by the hub object, not by the gym
@ guide, and his shipped GSC flavour line is left as it is.
@
@ KEYED ON VAR_TRINITY_JOHTO_ARC (0x40F7) and nothing else, except three free
@ reads of existing flags and one free read of the badge count:
@   FLAG_TRINITY_K_ARRIVED      (0x4B5) -- splits the arc-10 rung, so it stops
@                                          sending you to a crossing you made.
@   FLAG_TRINITY_J_WING_SILVER  (0x29B) -- splits the arc-7 rung, so the crate
@                                          pointer stops once the crate is
@                                          empty (TeamRocketBaseB3F:532 uses
@                                          the same read as its own guard).
@   FLAG_TRINITY_BADGE09        (0x25)  -- splits the arc-2 rung (see there).
@   C-COUNT (badge flags 09-16) -- splits the arc-5 rung (see there).
@
@ CALL CONTRACT. Enter with `goto`, never `call`. Every caller has already
@ done `lock` + `faceplayer` and has left its own MSGBOX_DEFAULT page on
@ screen; this ladder prints ONE more page and then `release`s. It writes no
@ flag and no saved var, so it is safe to run at any time, from any map, in
@ any order. The ONE thing it writes is scratch: the arc-5 rung calls C-COUNT,
@ which sets VAR_TEMP_A and buffers STR_VAR_1 (the same read the GOLDENROD
@ gate itself performs). Every one of this ladder's callers is an NPC talk
@ script that has already printed its own page, so none of them is holding a
@ string in STR_VAR_1 across the `goto` -- C-COUNT's stated obligation is met.
@
@ WHY A DESCENDING goto_if_ge LADDER AND NOT `switch`: `switch` expands to
@ `copyvar VAR_0x8000, <var>` (asm/macros/event.inc) and would clobber a
@ special var in a script 30+ sites enter; and arc 9 is OPTIONAL (vars.h:299
@ note -- SUICUNE sits behind the CLEAR BELL gate, so 10 is NOT 9 + 1), which
@ an exact-match case ladder models badly and a >= ladder models exactly.
@
@ THE VOICE IS THE RADIO. ELM fits the player's POKeNAV with a RADIO CARD in
@ the first scene of Act II and says why: "This region runs on its radio. If
@ something ever goes wrong in JOHTO, you'll hear it there first."
@ (ElmsLab_Text_ElmRadioCard). These lines are what the player would have
@ heard on it -- finding #9's "Radio Card flavor NPCs are a natural in-world
@ channel", built as one channel rather than as two NPCs in one city.
@
@ WHY THE LADDER LIVES HERE AND NOT AT ELM'S LAB / THE CENTERS: story_audit.py
@ check (c) parses every arc comparison in the file that WRITES an arc value
@ and reports `n >= v` as a deadlock suspect. ElmsLab/scripts.inc writes arc 1
@ and arc 2; a ladder there would fabricate warnings in a gate whose value is
@ a stable warning list. This file writes no arc value, so check (c) never
@ parses it. (Same reason Trinity_EventScript_ElmNextStep below is here.)
@ ============================================================================
Trinity_EventScript_JohtoGuide::
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 10, Trinity_EventScript_JohtoGuideLeague
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 9, Trinity_EventScript_JohtoGuideSuicune
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 8, Trinity_EventScript_JohtoGuideBell
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 7, Trinity_EventScript_JohtoGuideDirector
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 6, Trinity_EventScript_JohtoGuideTower
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 5, Trinity_EventScript_JohtoGuideBadges
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 4, Trinity_EventScript_JohtoGuideMart
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 3, Trinity_EventScript_JohtoGuideLake
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 2, Trinity_EventScript_JohtoGuideTheft
	msgbox Trinity_Text_JohtoGuideArc0, MSGBOX_DEFAULT
	release
	end

@ ARC 2 IS THE ONE MULTI-OBJECTIVE WINDOW IN THIS LADDER, so it splits on a
@ free flag read the way the arc-7 and arc-10 rungs do. Arc 2 is written at
@ ElmsLab/scripts.inc:125 and is not left until SlowpokeWellB1F/scripts.inc:
@ 198, so VIOLET and AZALEA both sit inside it and FALKNER is normally beaten
@ while the arc is still 2. Nothing GATES AZALEA behind the badge -- the only
@ BADGE09 readers tree-wide are VioletGym and the two gate officers at
@ Route31VioletGate:16 and Route32RuinsOfAlphGate:14, and all three are
@ dialogue splits that block nothing. So the pointer follows the badge and
@ not the arc: before it, the nearest GYM; after it, the live story beat.
@ That beat is keyed on the same arc value -- AzaleaTown/scripts.inc:24 shows
@ the ROCKET posts at arc == 2 and SlowpokeWellB1F/scripts.inc:23 shows the
@ raid at arc == 2 -- so it is guaranteed on stage whenever this page prints.
Trinity_EventScript_JohtoGuideTheft::
	goto_if_set FLAG_TRINITY_BADGE09, Trinity_EventScript_JohtoGuideWell
	msgbox Trinity_Text_JohtoGuideArc2, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_JohtoGuideWell::
	msgbox Trinity_Text_JohtoGuideArc2Well, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_JohtoGuideLake::
	msgbox Trinity_Text_JohtoGuideArc3, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_JohtoGuideMart::
	msgbox Trinity_Text_JohtoGuideArc4, MSGBOX_DEFAULT
	release
	end

@ ARC 5's EXIT IS A BADGE COUNT, NOT AN ARC WRITE. GoldenrodCity_EventScript_
@ TryRocketTakeover (data/maps/GoldenrodCity/scripts.inc:90-94) fires on
@ arc == 5 AND VAR_TEMP_A >= 7, and it runs from GOLDENROD's ON_TRANSITION --
@ so a player who earns his seventh badge anywhere else stays at arc 5 while
@ already holding the thing this page tells him to go and get. C-COUNT is the
@ identical read that gate performs; it writes VAR_TEMP_A and STR_VAR_1 only.
Trinity_EventScript_JohtoGuideBadges::
	call Trinity_EventScript_CountJohtoBadges
	goto_if_ge VAR_TEMP_A, 7, Trinity_EventScript_JohtoGuideBadgesReady
	msgbox Trinity_Text_JohtoGuideArc5, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_JohtoGuideBadgesReady::
	msgbox Trinity_Text_JohtoGuideArc5Ready, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_JohtoGuideTower::
	msgbox Trinity_Text_JohtoGuideArc6, MSGBOX_DEFAULT
	release
	end

@ The crate in the ROCKET BASE opens at FLAG_TRINITY_J_DOOR_B3F && arc >= 7
@ and closes on FLAG_TRINITY_J_WING_SILVER (TeamRocketBaseB3F/scripts.inc:
@ 528-532). Reading its own already-taken guard keeps the second half of this
@ page from going stale while the player is still at arc 7.
Trinity_EventScript_JohtoGuideDirector::
	goto_if_set FLAG_TRINITY_J_WING_SILVER, Trinity_EventScript_JohtoGuideDirectorOnly
	msgbox Trinity_Text_JohtoGuideArc7, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_JohtoGuideDirectorOnly::
	msgbox Trinity_Text_JohtoGuideArc7Wing, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_JohtoGuideBell::
	msgbox Trinity_Text_JohtoGuideArc8, MSGBOX_DEFAULT
	release
	end

@ Arc 9 is optional, so this rung is not "8 + 1" -- it is the state a player
@ reaches ONLY by resolving SUICUNE. The CLEAR BELL half of the arc-8 page is
@ spent by then; the eight-badge half is not, so it is repeated here.
Trinity_EventScript_JohtoGuideSuicune::
	msgbox Trinity_Text_JohtoGuideArc9, MSGBOX_DEFAULT
	release
	end

@ FLAG_TRINITY_K_ARRIVED (0x4B5) is M5b S1's one writer -- the S.S. AQUA
@ arrival cutscene. Before it, BOBBY is still standing on OLIVINE PORT
@ waiting (OlivinePort_EventScript_SetBobbyVisibility); after it, the crossing
@ is a two-way ferry and "go find BOBBY" would be stale.
Trinity_EventScript_JohtoGuideLeague::
	goto_if_set FLAG_TRINITY_K_ARRIVED, Trinity_EventScript_JohtoGuideFerry
	msgbox Trinity_Text_JohtoGuideArc10, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_JohtoGuideFerry::
	msgbox Trinity_Text_JohtoGuideArc10Kanto, MSGBOX_DEFAULT
	release
	end

@ Arc 0 and arc 1 share this page: arc 1 (ELM met, theft armed) is effectively
@ unreachable outside the lab, because the meet trigger and the theft triggers
@ both sit in the lab's only exit corridor.
Trinity_Text_JohtoGuideArc0:
	.string "The radio's been running the\n"
	.string "same item all week -- a HOENN\l"
	.string "champion, come over the sea.\p"
	.string "PROF.ELM wants a word. His lab\n"
	.string "is in NEW BARK TOWN, east along\l"
	.string "ROUTE 29 from CHERRYGROVE.$"

@ TRUE BOTH SIDES OF THE ROUTE 29 CONFRONTATION. Arc stays 2 from the theft
@ (ElmsLab:125) until SLOWPOKE WELL writes 3, and SILVER 1 is fought partway
@ through that window (Route29:92-103), so this page never says "the thief is
@ out there, go and find him" -- he is beaten, not caught, in either state.
Trinity_Text_JohtoGuideArc2:
	.string "The lab in NEW BARK was robbed.\n"
	.string "A POKéMON taken, and the thief\l"
	.string "is still out there somewhere.\p"
	.string "Nothing you can do about that\n"
	.string "today. VIOLET CITY has the\l"
	.string "nearest GYM -- start there.$"

@ Same arc, badge already won. The bulletin moves to the other beat that is
@ live at arc 2 and names the town it is under.
Trinity_Text_JohtoGuideArc2Well:
	.string "The ZEPHYRBADGE out of VIOLET,\n"
	.string "and one other item today.\p"
	.string "Men in black are standing over\n"
	.string "the SLOWPOKE WELL in AZALEA\l"
	.string "TOWN, and nobody there will\l"
	.string "say why.$"

Trinity_Text_JohtoGuideArc3:
	.string "Bulletin out of MAHOGANY TOWN:\n"
	.string "the LAKE OF RAGE north of it is\l"
	.string "full of red GYARADOS.\p"
	.string "Nobody will say why. Somebody\n"
	.string "ought to go and look.$"

@ Finding #9's first named stall: "Lance at Lake of Rage was skippable with
@ nothing else pointing to Mahogany". LANCE's own words are the source --
@ LakeOfRage_Text_LanceRadioSignal:385-386, "The souvenir shop, I think.
@ Nobody buys that many souvenirs."
Trinity_Text_JohtoGuideArc4:
	.string "LANCE of the ELITE FOUR was\n"
	.string "seen walking into the souvenir\l"
	.string "shop in MAHOGANY TOWN.\p"
	.string "He went in and he hasn't come\n"
	.string "out. Nobody buys that many\l"
	.string "souvenirs.$"

@ THE SEVEN-BADGE GATE, said out loud. GoldenrodCity_EventScript_
@ TryRocketTakeover: arc == 5 and CountJohtoBadges >= 7, fired on ENTERING
@ GOLDENROD. Nothing else in the world names that number (finding #9c).
Trinity_Text_JohtoGuideArc5:
	.string "The base under MAHOGANY is shut\n"
	.string "down. Nothing on the radio but\l"
	.string "static out of GOLDENROD now.\p"
	.string "Earn your seventh JOHTO badge\n"
	.string "before you walk into that city.\l"
	.string "You'll want it.$"

@ Same rung, seventh badge already in hand. C-COUNT has just buffered the
@ live number into STR_VAR_1, so this states it rather than asking for it.
Trinity_Text_JohtoGuideArc5Ready:
	.string "The base under MAHOGANY is shut\n"
	.string "down. Nothing on the radio but\l"
	.string "static out of GOLDENROD now.\p"
	.string "And {STR_VAR_1} JOHTO badges behind you.\n"
	.string "Walk into that city and find\l"
	.string "out what the static is.$"

Trinity_Text_JohtoGuideArc6:
	.string "TEAM ROCKET is broadcasting out\n"
	.string "of the RADIO TOWER in\l"
	.string "GOLDENROD. Every channel.\p"
	.string "Somebody has to go up there and\n"
	.string "shut them off.$"

@ Finding #9's third named stall: "the Silver Wing's arc>=7 return-trip to
@ the Base is communicated nowhere". The DIRECTOR on TOWER 5F is what writes
@ arc 8 (RadioTower5F_EventScript_RescuedDirector).
Trinity_Text_JohtoGuideArc7:
	.string "The DIRECTOR is back in his own\n"
	.string "office, TOWER 5F in GOLDENROD,\l"
	.string "and he's asking after you.\p"
	.string "They say the office under\n"
	.string "MAHOGANY was never emptied.\l"
	.string "Might be worth a second look.$"

@ Same rung, crate already emptied.
Trinity_Text_JohtoGuideArc7Wing:
	.string "The DIRECTOR is back in his own\n"
	.string "office, TOWER 5F in GOLDENROD.\p"
	.string "He has been asking after you\n"
	.string "since the tower went quiet.$"

Trinity_Text_JohtoGuideArc8:
	.string "With the CLEAR BELL the TIN\n"
	.string "TOWER in ECRUTEAK will open to\l"
	.string "you. The bell is the gate.\p"
	.string "Eight JOHTO badges opens the\n"
	.string "other road -- east out of NEW\l"
	.string "BARK, ROUTE 27 then ROUTE 26.$"

@ The eight-badge LEAGUE gate is Route26_EventScript_LeagueGateCheck
@ (VAR_TEMP_A >= 8), never an arc test -- which is why this page repeats it.
Trinity_Text_JohtoGuideArc9:
	.string "SUICUNE's business is settled,\n"
	.string "then. Word travels.\p"
	.string "What's left is the LEAGUE.\n"
	.string "Eight JOHTO badges opens the\l"
	.string "road east out of NEW BARK --\l"
	.string "ROUTE 27, then ROUTE 26.$"

@ Finding #9c: "the Olivine Port crossing WORKS ... but nothing tells the
@ player to go there -- you only find BOBBY by already knowing."
Trinity_Text_JohtoGuideArc10:
	.string "CHAMPION of JOHTO now. They\n"
	.string "played the ceremony twice.\p"
	.string "And a sailor named BOBBY is\n"
	.string "waiting on you at OLIVINE PORT.$"

Trinity_Text_JohtoGuideArc10Kanto:
	.string "The S.S. AQUA runs OLIVINE PORT\n"
	.string "to VERMILION and back, whenever\l"
	.string "you want it.\p"
	.string "Strange to think KANTO is a\n"
	.string "boat ride away now.$"

@ ============================================================================
@ PROF.ELM's RE-ASK LADDER (M7b Task 14, finding #9: "Elm already exists as
@ the story's anchor -- make him say where to go next when talked to again").
@
@ Reached ONLY from ElmsLab_EventScript_Elm's fall-through. That fall-through
@ is scene NEWBARK 3 or 4: scene 1 and scene 2 have their own branches, and
@ the only writers tree-wide are ElmsLab:58 (1), :126 (2), Route29:103 (3) and
@ ElmsLab:166 (4). Route29:103 is the FIRST line of Route29_EventScript_
@ SilverAftermath (:102-106) -- NOT of SilverConfront, and not adjacent to the
@ setflag; the proof is the call order, not the line order. `setflag
@ FLAG_TRINITY_J_SILVER1_BEATEN` is Route29:96, inside Route29_EventScript_
@ SilverConfront (:92-100), and BOTH paths into the aftermath call the
@ confrontation first: the coord path calls :51 then :55, the talk path :75
@ then :83, and there is no third caller of either. So no path reaches the
@ scene-3 write without passing the setflag, and SCENE >= 3 IMPLIES SILVER 1
@ HAS BEEN FOUGHT -- which is why the arc-2 rung below speaks to a player who
@ has already met the thief, and never sends him chasing one down ROUTE 29.
@
@ Rungs below arc 2 are defensive: they fall straight through to ELM's
@ existing idle page with no second box.
@
@ Same call contract as the hub ladder: the caller has locked and faceplayer'd
@ and has ELM's idle page on screen; this prints one more and releases. It
@ writes no flag and no saved var; its arc-5 rung calls C-COUNT, which writes
@ scratch only (VAR_TEMP_A + STR_VAR_1), and ELM's idle page holds no buffer
@ across the `goto`. It lives here and not in ElmsLab/scripts.inc for the
@ story_audit.py check (c) reason given at the head of the hub ladder --
@ ElmsLab writes arc 1 and arc 2, so an arc comparison there is reported as a
@ deadlock suspect.
@
@ The voice is ELM's, not the radio's -- he is the anchor, so he gets his own
@ pages rather than a goto into Trinity_EventScript_JohtoGuide.
@ ============================================================================
Trinity_EventScript_ElmNextStep::
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 10, Trinity_EventScript_ElmNextLeague
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 9, Trinity_EventScript_ElmNextSuicune
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 8, Trinity_EventScript_ElmNextBell
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 7, Trinity_EventScript_ElmNextDirector
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 6, Trinity_EventScript_ElmNextTower
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 5, Trinity_EventScript_ElmNextBadges
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 4, Trinity_EventScript_ElmNextMart
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 3, Trinity_EventScript_ElmNextLake
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 2, Trinity_EventScript_ElmNextChase
	release
	end

@ Same split, same free flag read, same reason as the hub ladder's arc-2 rung
@ (see there): FALKNER is normally beaten while the arc is still 2, and after
@ that "VIOLET CITY is your road" is a road already walked.
Trinity_EventScript_ElmNextChase::
	goto_if_set FLAG_TRINITY_BADGE09, Trinity_EventScript_ElmNextWell
	msgbox Trinity_Text_ElmNext2, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_ElmNextWell::
	msgbox Trinity_Text_ElmNext2Well, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_ElmNextLake::
	msgbox Trinity_Text_ElmNext3, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_ElmNextMart::
	msgbox Trinity_Text_ElmNext4, MSGBOX_DEFAULT
	release
	end

@ Same split as the hub ladder's arc-5 rung: arc 5 is left by a badge-count
@ read on GOLDENROD's ON_TRANSITION, not by an arc write, so seven badges in
@ hand can sit inside arc 5 for as long as the player stays out of the city.
Trinity_EventScript_ElmNextBadges::
	call Trinity_EventScript_CountJohtoBadges
	goto_if_ge VAR_TEMP_A, 7, Trinity_EventScript_ElmNextBadgesReady
	msgbox Trinity_Text_ElmNext5, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_ElmNextBadgesReady::
	msgbox Trinity_Text_ElmNext5Ready, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_ElmNextTower::
	msgbox Trinity_Text_ElmNext6, MSGBOX_DEFAULT
	release
	end

@ Same free read as the hub ladder's arc-7 rung: the crate's own guard.
Trinity_EventScript_ElmNextDirector::
	goto_if_set FLAG_TRINITY_J_WING_SILVER, Trinity_EventScript_ElmNextDirectorOnly
	msgbox Trinity_Text_ElmNext7, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_ElmNextDirectorOnly::
	msgbox Trinity_Text_ElmNext7Wing, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_ElmNextBell::
	msgbox Trinity_Text_ElmNext8, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_ElmNextSuicune::
	msgbox Trinity_Text_ElmNext9, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_ElmNextLeague::
	goto_if_set FLAG_TRINITY_K_ARRIVED, Trinity_EventScript_ElmNextFerry
	msgbox Trinity_Text_ElmNext10, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_ElmNextFerry::
	msgbox Trinity_Text_ElmNext10Kanto, MSGBOX_DEFAULT
	release
	end

@ Post-ROUTE 29 by construction (see the header): the thief is beaten, not
@ caught, and SILVER turns up again at AZALEA.
Trinity_Text_ElmNext2:
	.string "ELM: You met him on ROUTE 29,\n"
	.string "then. The one who took it.\p"
	.string "Leave him be -- his sort always\n"
	.string "turns up again.\p"
	.string "VIOLET CITY is your road.\n"
	.string "FALKNER's GYM, past CHERRYGROVE.$"

@ Same page, ZEPHYRBADGE already won: the road is walked, so ELM names the
@ beat that is still live at arc 2 instead.
Trinity_Text_ElmNext2Well:
	.string "ELM: You met him on ROUTE 29,\n"
	.string "then. The one who took it.\p"
	.string "Leave him be -- his sort always\n"
	.string "turns up again.\p"
	.string "FALKNER is behind you. AZALEA\n"
	.string "TOWN next -- there are men\l"
	.string "standing over the SLOWPOKE WELL.$"

Trinity_Text_ElmNext3:
	.string "ELM: I've had MAHOGANY TOWN on\n"
	.string "the radio all morning.\p"
	.string "Red GYARADOS in the LAKE OF\n"
	.string "RAGE, north of the town.\p"
	.string "That is not a natural swarm,\n"
	.string "{PLAYER}. Somebody made it.$"

Trinity_Text_ElmNext4:
	.string "ELM: LANCE went on ahead to\n"
	.string "MAHOGANY TOWN -- the souvenir\l"
	.string "shop, he said.\p"
	.string "Go in and find him. He is not\n"
	.string "a patient man.$"

Trinity_Text_ElmNext5:
	.string "ELM: The signal under MAHOGANY\n"
	.string "has stopped. Good.\p"
	.string "Now GOLDENROD is going quiet,\n"
	.string "and I would rather you walked\l"
	.string "in there with seven JOHTO\l"
	.string "badges behind you.$"

@ Same rung, seventh badge already in hand; C-COUNT buffered the number.
Trinity_Text_ElmNext5Ready:
	.string "ELM: The signal under MAHOGANY\n"
	.string "has stopped. Good.\p"
	.string "And {STR_VAR_1} JOHTO badges behind\n"
	.string "you already. Then GOLDENROD --\l"
	.string "whatever that static is, it is\l"
	.string "not the weather.$"

Trinity_Text_ElmNext6:
	.string "ELM: They have taken the RADIO\n"
	.string "TOWER in GOLDENROD.\p"
	.string "Every channel, one voice. I can\n"
	.string "hear it from here.$"

Trinity_Text_ElmNext7:
	.string "ELM: The DIRECTOR is back in\n"
	.string "his office on TOWER 5F. He\l"
	.string "asked for you by name.\p"
	.string "And nobody ever emptied that\n"
	.string "office under MAHOGANY. I would\l"
	.string "go back down there.$"

Trinity_Text_ElmNext7Wing:
	.string "ELM: The DIRECTOR is back in\n"
	.string "his office on TOWER 5F. He\l"
	.string "asked for you by name.\p"
	.string "Go and hear what he wants.$"

Trinity_Text_ElmNext8:
	.string "ELM: A CLEAR BELL. Then\n"
	.string "ECRUTEAK -- the TIN TOWER\l"
	.string "opens to it and nothing else.\p"
	.string "Eight JOHTO badges opens the\n"
	.string "other road: east of here,\l"
	.string "ROUTE 27, then ROUTE 26.$"

Trinity_Text_ElmNext9:
	.string "ELM: So that's what SUICUNE\n"
	.string "was waiting for.\p"
	.string "Eight JOHTO badges and the\n"
	.string "LEAGUE gate opens: east of\l"
	.string "here, ROUTE 27 then ROUTE 26.$"

Trinity_Text_ElmNext10:
	.string "ELM: CHAMPION of JOHTO.\p"
	.string "A sailor called BOBBY has rung\n"
	.string "this lab twice asking when you\l"
	.string "sail. He is at OLIVINE PORT.$"

Trinity_Text_ElmNext10Kanto:
	.string "ELM: CHAMPION of JOHTO, and\n"
	.string "off to KANTO besides.\p"
	.string "The S.S. AQUA runs OLIVINE to\n"
	.string "VERMILION and back.\p"
	.string "Come and tell me how it ends.$"
