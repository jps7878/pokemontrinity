IcePathB2FMahoganySide_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IcePathB2FMahoganySide_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S10 -- the far half of GSC's ICE PATH boulder puzzle.
@
@ Four boulders that are NOT here until the matching B1F boulder has been pushed
@ down its hole. GSC ships EVENT_BOULDER_IN_ICE_PATH_n SET (B1F boulder hidden
@ is the inverse there) and _nA CLEAR, and the fall inverts both; Trinity's pair
@ is the same boolean read two ways:
@
@   FLAG_TRINITY_J_ICE_BOULDER_n   set by removeobject's FlagSet when it falls
@   FLAG_TRINITY_J_ICE_LANDING_n   this map's visibility flag, the EXACT
@                                  COMPLEMENT, authored below and nowhere else
@
@ This map is therefore the single authoring site for all four landing flags,
@ and it never touches a _BOULDER_ flag (the S1/G7 discipline: one writer).
@
@ TILE DECODES, all GSC's own (IcePathB2FMahoganySide.asm:48-51): (11,3) (4,7)
@ (3,12) (12,13), every one collision 0 / elevation 3 / MB_ICE / reachable, each
@ costing exactly one tile.
@
@ DEVIATION, LOGGED: GSC's landings are SPRITEMOVEDATA_STILL -- scenery, not
@ pushable. Hoenn has no still-boulder graphics id (TryPushBoulder keys on
@ OBJ_EVENT_GFX_PUSHABLE_BOULDER itself, src/field_player_avatar.c:970), so
@ these are ordinary Strength boulders wearing the same script as every other
@ one in the region. Harmless: they sit on ice in a room with no holes, and
@ template positions never persist anyway.
@ ============================================================================

IcePathB2FMahoganySide_OnTransition::
	call_if_set FLAG_TRINITY_J_ICE_BOULDER_1, IcePathB2FMahoganySide_EventScript_ShowLanding1
	call_if_unset FLAG_TRINITY_J_ICE_BOULDER_1, IcePathB2FMahoganySide_EventScript_HideLanding1
	call_if_set FLAG_TRINITY_J_ICE_BOULDER_2, IcePathB2FMahoganySide_EventScript_ShowLanding2
	call_if_unset FLAG_TRINITY_J_ICE_BOULDER_2, IcePathB2FMahoganySide_EventScript_HideLanding2
	call_if_set FLAG_TRINITY_J_ICE_BOULDER_3, IcePathB2FMahoganySide_EventScript_ShowLanding3
	call_if_unset FLAG_TRINITY_J_ICE_BOULDER_3, IcePathB2FMahoganySide_EventScript_HideLanding3
	call_if_set FLAG_TRINITY_J_ICE_BOULDER_4, IcePathB2FMahoganySide_EventScript_ShowLanding4
	call_if_unset FLAG_TRINITY_J_ICE_BOULDER_4, IcePathB2FMahoganySide_EventScript_HideLanding4
	end

IcePathB2FMahoganySide_EventScript_ShowLanding1::
	clearflag FLAG_TRINITY_J_ICE_LANDING_1
	return

IcePathB2FMahoganySide_EventScript_HideLanding1::
	setflag FLAG_TRINITY_J_ICE_LANDING_1
	return

IcePathB2FMahoganySide_EventScript_ShowLanding2::
	clearflag FLAG_TRINITY_J_ICE_LANDING_2
	return

IcePathB2FMahoganySide_EventScript_HideLanding2::
	setflag FLAG_TRINITY_J_ICE_LANDING_2
	return

IcePathB2FMahoganySide_EventScript_ShowLanding3::
	clearflag FLAG_TRINITY_J_ICE_LANDING_3
	return

IcePathB2FMahoganySide_EventScript_HideLanding3::
	setflag FLAG_TRINITY_J_ICE_LANDING_3
	return

IcePathB2FMahoganySide_EventScript_ShowLanding4::
	clearflag FLAG_TRINITY_J_ICE_LANDING_4
	return

IcePathB2FMahoganySide_EventScript_HideLanding4::
	setflag FLAG_TRINITY_J_ICE_LANDING_4
	return
