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
