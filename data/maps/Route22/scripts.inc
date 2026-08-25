Route22_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M5a T5 -- flavour half of the ROUTE 28/KANTO land gate. The real
@ enforcement is the coord_event trigger on Route28's own (39,8) tile (see
@ that map's scripts.inc); by the time a player can stand here and talk to
@ this guard, they already crossed, which only happens once
@ FLAG_TRINITY_K_ARRIVED is set. He is deliberately redundant with that
@ trigger (same double-coverage shape as ROUTE26's LeagueGateOfficer), and
@ READ-ONLY: never sets the flag himself. Badge-agnostic dialogue -- he names
@ no count, just that the road is a League matter.
Route22_EventScript_KantoGateGuard::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_K_ARRIVED, Route22_EventScript_KantoGateGuardOpen
	msgbox Route22_Text_KantoGateGuardClosed, MSGBOX_DEFAULT
	release
	end

Route22_EventScript_KantoGateGuardOpen::
	msgbox Route22_Text_KantoGateGuardOpen, MSGBOX_DEFAULT
	release
	end

Route22_Text_KantoGateGuardClosed:
	.string "This road runs west out to JOHTO,\n"
	.string "but it isn't open for crossing.\p"
	.string "The LEAGUE office has to clear it\n"
	.string "first. Nothing I can do till then.$"

Route22_Text_KantoGateGuardOpen:
	.string "Road's open. Safe travels out to\n"
	.string "JOHTO.$"

@ ============================================================================
@ Trinity M5a T5 fix round 1 (review Finding 2). The (8,7) warp_event in
@ map.json (dest MAP_ROUTE_28 #2) never auto-fires by itself: it decodes to
@ MB_NORMAL, which is not in IsWarpMetatileBehavior's list
@ (src/field_control_avatar.c:925-939 -- MB_WARP_DOOR/LADDER/ESCALATOR/
@ NON_ANIM_DOOR/the four hardcoded special warps only), so
@ TryStartWarpEventScript (:880) always returns FALSE there and the player
@ could walk right over it doing nothing. The JSON entry stays as
@ RECIPROCAL-INDEX BOOKKEEPING ONLY (keeps warp_events[2] a real, in-bounds
@ dest_warp_id for qa_sweep's tree-wide bounds check and for anyone reading
@ the pairing) -- the coord_event below is what actually fires, exactly
@ mirroring Route28's own (39,8) mechanism one tile away: a trigger at the
@ true decoded elevation (3, matching (8,7)'s own MB_NORMAL tile), always
@ open (no gate needed this direction -- only west->east into KANTO is
@ gated), issuing the warp by hand since a script's own `warp` command
@ bypasses IsWarpMetatileBehavior entirely (it is not the automatic
@ step-on-a-warp-tile path).
@ ============================================================================
Route22_EventScript_KantoGateReturnWarp::
	warp MAP_ROUTE_28, 39, 8
	waitstate
	end
