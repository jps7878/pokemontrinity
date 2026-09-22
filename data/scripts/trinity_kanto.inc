@ ============================================================================
@ Trinity -- shared Act III (KANTO) script helpers.
@
@ C-COUNT -- COUNTING KANTO BADGES. Authored by M5a T5 for the ROUTE 23
@ policemen; reusable by M5b (Giovanni's 7-badge VIRIDIAN gate, the League II
@ approach, etc.) exactly the way trinity_johto.inc's Johto C-COUNT is reused
@ across M4b S9-S12.
@
@ Kanto badges 17-24 (FLAG_TRINITY_BADGE17..24, renamed from
@ FLAG_UNUSED_0x4AD..0x4B4 at M5a T5 Step 0) are PLAIN FLAGS with no engine UI
@ (GYM PATTERN G7, mirroring Johto's own badges 9-16), so the count is script
@ arithmetic instead of a GetBadgeCount special: eight call_if_set into one
@ increment subroutine.
@
@ VAR_TEMP_A, not VAR_TEMP_0/1/3: same reasoning as trinity_johto.inc -- those
@ three carry vanilla aliases (VAR_TEMP_CHALLENGE_STATUS,
@ VAR_TEMP_RECORD_MIX_GIFT_ITEM and the TV counter, include/constants/vars.h:
@ 347-350). The whole TEMP block is cleared on map load by
@ ClearTempFieldEventData, which cannot race this: a script context runs
@ synchronously to completion, so the value is always consumed in the same run
@ that wrote it.
@
@ G7 DISCIPLINE: this reads the badge flags and NEVER writes one. Only a
@ <Leader>Defeated continuation (M5b) writes FLAG_TRINITY_BADGE<NN>.
@
@ C-COUNT ALSO SPEAKS (M7b Task 15, finding #6). The count is buffered into
@ STR_VAR_1 as well as written to VAR_TEMP_A, so any text on a caller's path can
@ print the player's ACTUAL number with no buffer line of its own -- which is the
@ whole of finding #6's complaint: "the gate counts internally but never states
@ the number".
@ AUDITED WHEN ADDED: every file that calls either counter was grepped, and none
@ of them writes or prints STR_VAR_1/2/3 anywhere, so nothing of theirs is
@ clobbered. SEVERAL Kanto callers are MAP-LOAD scripts: LORELEI's, BRUNO's,
@ AGATHA's, LANCE's and the CHAMPION's rooms, the HALL OF FAME and
@ IndigoPlateau_PokemonCenter_1F all count badges from their own ON_TRANSITION
@ to arm the Kanto cast, so entering any of those maps rewrites STR_VAR_1 before
@ the map draws. None of them prints a buffer anywhere (grepped: zero STR_VAR
@ hits in all seven), and the HALL OF FAME's own C code writes gStringVar1
@ immediately before it expands it (src/hall_of_fame.c:985-986), so the write is
@ observed by nothing.
@ THE NEW OBLIGATION this creates: a caller must not hold a string in STR_VAR_1
@ across the call.
@ G7 DISCIPLINE IS UNCHANGED -- buffering is a read of the badge flags, never a
@ write of one.
@
@ Usage:
@       call Trinity_EventScript_CountKantoBadges
@       goto_if_lt VAR_TEMP_A, 3, <not enough>
@       ... and {STR_VAR_1} in any text on that path prints the same number.
@
@ TRAVEL-GATE FLAGS (read-only here, no shared helper needed -- each is a
@ single goto_if_set at its point of use, not a count):
@   FLAG_TRINITY_K_ARRIVED      (0x4B5) -- Route 28 land gate (Route28
@       EventScript_KantoGateCheck), Olivine/Vermilion dock sailors. M5b S1's
@       S.S. AQUA arrival cutscene is the one writer.
@   FLAG_TRINITY_K_TRAIN_PASS   (0x4B6) -- Goldenrod<->Saffron MAGNET TRAIN
@       attendants. M5b S2 is the one writer.
@ ============================================================================
Trinity_EventScript_CountKantoBadges::
	setvar VAR_TEMP_A, 0
	call_if_set FLAG_TRINITY_BADGE17, Trinity_EventScript_IncKantoBadgeCount
	call_if_set FLAG_TRINITY_BADGE18, Trinity_EventScript_IncKantoBadgeCount
	call_if_set FLAG_TRINITY_BADGE19, Trinity_EventScript_IncKantoBadgeCount
	call_if_set FLAG_TRINITY_BADGE20, Trinity_EventScript_IncKantoBadgeCount
	call_if_set FLAG_TRINITY_BADGE21, Trinity_EventScript_IncKantoBadgeCount
	call_if_set FLAG_TRINITY_BADGE22, Trinity_EventScript_IncKantoBadgeCount
	call_if_set FLAG_TRINITY_BADGE23, Trinity_EventScript_IncKantoBadgeCount
	call_if_set FLAG_TRINITY_BADGE24, Trinity_EventScript_IncKantoBadgeCount
	buffernumberstring STR_VAR_1, VAR_TEMP_A
	return

Trinity_EventScript_IncKantoBadgeCount::
	addvar VAR_TEMP_A, 1
	return

@ ============================================================================
@ THE POST-VICTORY TALLY (M7b Task 15, finding #6). Called by the seven KANTO
@ gym guides that exist -- CELADON GYM has no GymGuy object, and neither does
@ FRLG's. Information only: it reads the badge flags and writes none (G7).
@
@ NO "OF EIGHT" DENOMINATOR, on purpose. Six shipped guide lines end on "One of
@ seven." -- the <City>_Gym_Text_GymGuyPostVictory of PewterCity_Gym:186,
@ CeruleanCity_Gym:209, VermilionCity_Gym:531, FuchsiaCity_Gym:290,
@ SaffronCity_Gym:296 and CinnabarIsland_Gym:574 -- because
@ seven badges are what open VIRIDIAN (ViridianCity_EventScript_GymDoorCheck,
@ data/maps/ViridianCity/scripts.inc:95-96, needs VAR_TEMP_A >= 7) and
@ VIRIDIAN's own badge is the eighth. This tally lands in the very next box
@ after one of those lines, so it names the two GATES the number is for instead
@ of re-counting the gyms.
@
@ THE ALL-EIGHT BRANCH EXISTS BECAUSE OF VIRIDIAN.
@ ViridianCity_Gym_EventScript_GymGuyPostVictory is reached only through
@ goto_if_set FLAG_TRINITY_BADGE24 (data/maps/ViridianCity_Gym/scripts.inc:107),
@ so a player hearing it there always holds all eight -- telling them VIRIDIAN
@ opens at seven would narrate a milestone they have just walked past. At eight
@ the actionable fact is ROUTE 23, whose last guard wants all eight
@ (Route23_EventScript_Guard7, VAR_TEMP_A >= 8) and whose first wants two, so
@ every checkpoint on that road is satisfied at once.
@ ============================================================================
Trinity_EventScript_KantoBadgeTally::
	call Trinity_EventScript_CountKantoBadges
	goto_if_ge VAR_TEMP_A, 8, Trinity_EventScript_KantoBadgeTallyAll
	msgbox Trinity_Text_KantoBadgeTally, MSGBOX_DEFAULT
	return

Trinity_EventScript_KantoBadgeTallyAll::
	msgbox Trinity_Text_KantoBadgeTallyAll, MSGBOX_DEFAULT
	return

Trinity_Text_KantoBadgeTally:
	.string "Your KANTO BADGE count: {STR_VAR_1}.\p"
	.string "VIRIDIAN GYM won't open under\n"
	.string "seven. ROUTE 23's last guard\l"
	.string "wants all eight.$"

Trinity_Text_KantoBadgeTallyAll:
	.string "Your KANTO BADGE count: {STR_VAR_1}.\p"
	.string "Every gym in KANTO. ROUTE 23's\n"
	.string "guards will wave you through to\l"
	.string "VICTORY ROAD now.$"

@ ============================================================================
@ THE KANTO SIGNPOST LADDER (M7b Task 14, finding #9). JOHTO's twin, on
@ VAR_TRINITY_KANTO_ARC (0x408B). Read by the nine KANTO city Pokemon Center
@ clerks and by the SEVEN KANTO gym guides that exist -- CELADON GYM has no
@ separate guide object (T10 placed seven trainers and MARY carries the type
@ advice from inside her own post-battle fall-through, which is a trainer
@ script with no lock of its own and so cannot chain into this ladder).
@ Zero writes, same call contract as the JOHTO ladder.
@
@ ENTRY POINTS. Gym guides arrive by `goto` from inside their own
@ lock/faceplayer'd script. The Center clerks are object_events whose
@ map.json `script` field points at Trinity_EventScript_KantoGuideDesk below,
@ which does the lock/faceplayer the ladder itself deliberately does not --
@ the ladder must not lock, because its other seven callers already have.
@
@ THE VOICE IS COLD, per finding #14's founder ruling on KANTO's register:
@ "KANTO doesn't warm up to the Hoenn+Johto Champion. They know who you are;
@ they are not impressed." This is a League route-information desk reading
@ from a file, not a fan. It is the same clerk in every Center: one
@ recognisable institution, like the nurse.
@
@ THE RADIO CARD DOES NOT REACH HERE. ELM's own line scopes it -- "Every
@ JOHTO broadcast" (ElmsLab_Text_ElmRadioCard) -- which is why KANTO's channel
@ is a person behind a desk and JOHTO's is a broadcast.
@ ============================================================================
Trinity_EventScript_KantoGuideDesk::
	lock
	faceplayer
	goto Trinity_EventScript_KantoGuide
	end

Trinity_EventScript_KantoGuide::
	goto_if_ge VAR_TRINITY_KANTO_ARC, 7, Trinity_EventScript_KantoGuideDone
	goto_if_ge VAR_TRINITY_KANTO_ARC, 6, Trinity_EventScript_KantoGuideSilver
	goto_if_ge VAR_TRINITY_KANTO_ARC, 5, Trinity_EventScript_KantoGuideLeague
	goto_if_ge VAR_TRINITY_KANTO_ARC, 4, Trinity_EventScript_KantoGuideRig
	goto_if_ge VAR_TRINITY_KANTO_ARC, 3, Trinity_EventScript_KantoGuideGrate
	goto_if_ge VAR_TRINITY_KANTO_ARC, 2, Trinity_EventScript_KantoGuidePoster
	msgbox Trinity_Text_KantoGuideArrival, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_KantoGuidePoster::
	msgbox Trinity_Text_KantoGuideArc2, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_KantoGuideGrate::
	msgbox Trinity_Text_KantoGuideArc3, MSGBOX_DEFAULT
	release
	end

@ TWO pages on one arc value, and the split is a FLAG read, not a var read:
@ arc reaches 4 when the rig goes down, but GIOVANNI's badge fight comes after
@ it, and SILVER only stands on ROUTE 1 once FLAG_TRINITY_BADGE24 is set
@ (Route1_OnTransition). Route1/scripts.inc's own header records that "a
@ tree-wide grep found no NPC, sign, or scene anywhere that points the player
@ here" -- this page is that pointer.
Trinity_EventScript_KantoGuideRig::
	goto_if_set FLAG_TRINITY_BADGE24, Trinity_EventScript_KantoGuideBadge24
	msgbox Trinity_Text_KantoGuideRig, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_KantoGuideBadge24::
	msgbox Trinity_Text_KantoGuideBadge24, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_KantoGuideLeague::
	msgbox Trinity_Text_KantoGuideArc5, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_KantoGuideSilver::
	msgbox Trinity_Text_KantoGuideArc6, MSGBOX_DEFAULT
	release
	end

Trinity_EventScript_KantoGuideDone::
	msgbox Trinity_Text_KantoGuideArc7, MSGBOX_DEFAULT
	release
	end

@ Arc 0 and arc 1 share this page: the only entrance to KANTO writes arc 1, so
@ arc 0 is unreachable from inside a KANTO Pokemon Center.
@ "Seven of eight" is exact -- only VIRIDIAN's door is gated
@ (ViridianCity_EventScript_GymDoorCheck: seven KANTO badges AND arc >= 4).
Trinity_Text_KantoGuideArrival:
	.string "Route information.\p"
	.string "Seven of KANTO's eight GYMS are\n"
	.string "open to challengers. VIRIDIAN's\l"
	.string "is not. Don't ask me why.\p"
	.string "And a trainer in VIRIDIAN CITY\n"
	.string "has been asking where you are.\l"
	.string "BLUE. Go and hear him out.$"

@ BLUE's own intel (ViridianCity_Text_BlueIntel) names CELADON and the GAME
@ CORNER; this page repeats it for the player who fought him an hour ago.
Trinity_Text_KantoGuideArc2:
	.string "BLUE told you where to look.\n"
	.string "So look.\p"
	.string "CELADON CITY. Under the GAME\n"
	.string "CORNER, he said.\p"
	.string "Not this desk's business what\n"
	.string "you find there.$"

@ Matches the two shipped descriptions word for word: the kid's hint ("a
@ loose grate on the west side of the yard", ViridianCity:278) and the grate
@ prompt itself (ViridianCity_EventScript_HideoutGrate, arc >= 3).
Trinity_Text_KantoGuideArc3:
	.string "Those papers you took name a\n"
	.string "yard in VIRIDIAN CITY.\p"
	.string "The west side, beside the GYM.\n"
	.string "There is a service grate in the\l"
	.string "grass there.\p"
	.string "It is not city maintenance.$"

Trinity_Text_KantoGuideRig:
	.string "VIRIDIAN GYM opens at seven\n"
	.string "KANTO badges. Not six.\p"
	.string "Whoever is waiting in there\n"
	.string "will keep.$"

@ ROUTE 23's seven guards each count KANTO badges (Route23_EventScript_
@ Guard1..7, VAR_TEMP_A >= 2..8), so the road itself is the eighth badge's
@ reward.
Trinity_Text_KantoGuideBadge24:
	.string "Eight badges. The LEAGUE road\n"
	.string "is ROUTE 22 west of VIRIDIAN,\l"
	.string "then north on ROUTE 23.\p"
	.string "Unrelated: a red-haired trainer\n"
	.string "has been standing on ROUTE 1,\l"
	.string "south of VIRIDIAN, for days.$"

Trinity_Text_KantoGuideArc5:
	.string "ROUTE 22, then ROUTE 23. The\n"
	.string "posts up there count badges.\p"
	.string "VICTORY ROAD after that, then\n"
	.string "the PLATEAU.\p"
	.string "The CHAMPION is called ASH.\n"
	.string "That is all the file says.$"

@ MT.SILVER's entrance is on ROUTE 28 behind Route28_EventScript_
@ SilverCaveGateCheck (arc >= 6), and ROUTE 28 is reached from KANTO through
@ the ROUTE 22 (8,7) seam, whose own prompt (M7 Task 3) says "The trail west
@ leads out of KANTO into MT. SILVER country." This page uses that phrase.
Trinity_Text_KantoGuideArc6:
	.string "Three Leagues. There is one\n"
	.string "name still above yours.\p"
	.string "MT.SILVER. Take the trail west\n"
	.string "off ROUTE 22 -- it crosses out\l"
	.string "of KANTO, and the cave gate is\l"
	.string "on ROUTE 28.\p"
	.string "Nobody here will go with you.$"

Trinity_Text_KantoGuideArc7:
	.string "Nothing left in the file.\p"
	.string "Go wherever you like. You have\n"
	.string "earned the quiet.$"
