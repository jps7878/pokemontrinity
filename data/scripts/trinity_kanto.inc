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
@ Usage:
@       call Trinity_EventScript_CountKantoBadges
@       goto_if_lt VAR_TEMP_A, 3, <not enough>
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
	return

Trinity_EventScript_IncKantoBadgeCount::
	addvar VAR_TEMP_A, 1
	return
