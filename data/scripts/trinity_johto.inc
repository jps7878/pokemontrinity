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
@ THE POST-VICTORY TALLY (M7b Task 15, finding #6). Called by the seven JOHTO
@ gym guides that exist -- CIANWOOD GYM has no guide object (its map.json casts
@ four BLACK BELTs and CHUCK), and neither does GSC's. Information only: it
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
