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
@ Usage:
@       call Trinity_EventScript_CountJohtoBadges
@       goto_if_lt VAR_TEMP_A, 7, <not enough>
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
	return

Trinity_EventScript_IncBadgeCount::
	addvar VAR_TEMP_A, 1
	return
