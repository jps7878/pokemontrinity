Route22_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M5a T5 -- flavour half of the ROUTE 28/KANTO land gate. The real
@ west->east enforcement is the coord_event trigger on Route28's own (39,8)
@ tile (see that map's scripts.inc); the east->west half is this map's own
@ (8,7) seam trigger further down (gated since M7 Task 3 round 1). The guard
@ is deliberately redundant with both (same double-coverage shape as
@ ROUTE26's LeagueGateOfficer), and READ-ONLY: never sets the flag himself.
@ Badge-agnostic dialogue -- he names no count, just that the road is a
@ League matter.
@
@ PREMISE CORRECTION (M7 Task 3 round 1, review Major-1). This comment used
@ to claim that nobody can stand on this porch before FLAG_TRINITY_K_ARRIVED
@ is set. FALSE. The Act II corridor leaks a pre-K_ARRIVED player in from the
@ JOHTO side: Route26 -> KantoVictoryRoad_1F warp 1 (11,20) -> its (20,10)
@ coord trigger (KantoVictoryRoad_1F_EventScript_Route23ReturnWarp, an
@ UNCONDITIONAL `warp MAP_ROUTE23, 5, 28`) -> Route23's SOUTH component
@ (reach_check: 1339 tiles from (5,28), holding all seven guard nets and
@ warp 2 (8,153) -> Route22_NorthEntrance; the nets bounce a refused player
@ SOUTH, i.e. toward this map) -> Route22 (8,6). That is bug-test finding
@ #10's Kanto-side hole, and the (20,10) leak is NOT closed by Indigo
@ Plateau guards: Route23's north/plateau component (222 tiles from (18,28))
@ does not contain (5,28). Nothing on this map may therefore assume the
@ flag: the guard's Closed line below exists precisely for that player, and
@ the seam trigger refuses him too.
@
@ M7 Task 3 (bug-test findings #20 + #15, P0): he stands at (7,6), the open
@ porch tile WEST of the door approach -- decoded MB_NORMAL, collision 0,
@ elevation 3, no other object/warp/coord/bg event on it. He used to stand
@ ON (8,6), and (8,6) is the ONE way into the building: the gate has a
@ SINGLE door tile, (8,5) = block 347 MB_ANIMATED_DOOR, a push door that
@ TryDoorWarp (src/field_control_avatar.c, DIR_NORTH only) enters from the
@ tile SOUTH of it. The right-hand tile (9,5) = block 711 is a wall/pillar
@ (behaviour 0, collision 1), byte-identical to FireRed's own Route 22 data;
@ its warp_event 1 is FRLG paired-door bookkeeping (qa_sweep check 9 exempts
@ it as an adjacent same-destination sibling). It is NOT a door and must not
@ be re-stamped as one. FireRed has no guard on this porch at all; a
@ FACE_DOWN, range 0/0, flag 0 object on (8,6) sealed the only approach for
@ good (check 9's approach-tile rule now catches exactly that shape). His
@ dialogue is unchanged: badge-agnostic and READ-ONLY.
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
@ (src/field_control_avatar.c:936 -- MB_WARP_DOOR/LADDER/ESCALATOR/
@ NON_ANIM_DOOR/the four hardcoded special warps only), so
@ TryStartWarpEventScript (:887, the check at :891) always returns FALSE
@ there and the player could walk right over it doing nothing. The JSON
@ entry stays as RECIPROCAL-INDEX BOOKKEEPING ONLY (keeps warp_events[2] a
@ real, in-bounds dest_warp_id for qa_sweep's tree-wide bounds check, and
@ check 9 exempts it as live precisely because this coord_event covers the
@ same tile) -- the coord_event below is what actually fires, exactly
@ mirroring Route28's own (39,8) mechanism: a trigger at the true decoded
@ elevation (3, matching (8,7)'s own MB_NORMAL tile), gated on
@ FLAG_TRINITY_K_ARRIVED exactly like Route28's (39,8) is (M7 Task 3 round
@ 1 -- it used to read "always open, no gate needed this direction", which
@ rested on the false premise corrected at the top of this file), issuing
@ the warp by hand since a script's own `warp` command bypasses
@ IsWarpMetatileBehavior entirely (it is not the automatic
@ step-on-a-warp-tile path).
@
@ M7 Task 3 (bug-test findings #15 + #20). This used to be an IMMEDIATE
@ `warp MAP_ROUTE_28, 39, 8` sitting one tile south of the guard, so every
@ walk up column 8 toward the door silently teleported the player to JOHTO
@ and dropped them on Route 28's bare east-edge strip. It is now a YES/NO
@ confirm in the tree's own RocketHideout_B4F lift-platform shape (`lockall`
@ -> `goto_if_unset FLAG` -> `msgbox ... MSGBOX_YESNO` -> `goto_if_eq
@ VAR_RESULT, NO` -> `warp`/`waitstate`, no closemessage on the YES path
@ because the map load rebuilds the text window; NOT the Lilycove ferry,
@ whose YES path boards the player before warping), under lockall because
@ this is a coord trigger, not a talked-to NPC:
@   K_ARRIVED UNSET (round 1, review Major-1) -> Route22_EventScript_
@          KantoGateNotYet: refusal box, closemessage, releaseall. The
@          player STAYS on (8,7) -- no step-back, because (8,7) is entered
@          from four sides and is not itself the crossing (the door north of
@          it is not gated). Without this branch a pre-K_ARRIVED player who
@          reached this porch through the leak above could say YES and be
@          SEALED on Route 28: that map's (39,8) refuses eastbound below
@          K_ARRIVED, its west edge refuses westbound below
@          VAR_TRINITY_KANTO_ARC 6, (7,3)/(33,5) are a disjoint component,
@          Fly is dead in JOHTO and a ROUTE map has no Dig/Escape Rope -- a
@          file saved there is bricked. (The old immediate warp had the same
@          pocket; the confirm merely made it a chosen YES.) READ-ONLY: the
@          flag is only read here.
@   YES -> warp MAP_ROUTE_28, 37, 12. Decoded MB_NORMAL, collision 0,
@          elevation 3, no object/warp/coord/bg event on it; two tiles in
@          from the x=39 edge strip and inside the same walkable component
@          as (39,8) and the MT. SILVER crossing rows (reach_check path
@          (37,12)->(37,11)->(37,10)->(37,9)->(37,8)->(38,8)->(39,8)).
@          Not a trigger tile -- and coord_events never fire on a warp
@          landing in any case.
@   NO  -> closemessage, releaseall; the player STAYS on (8,7). Coord
@          triggers only run on a completed step onto their tile
@          (input->tookStep gates TryStartStepBasedScript,
@          src/field_control_avatar.c:193), and `releaseall` is what
@          disarms it after the script: ScrCmd_releaseall (src/scrcmd.c)
@          calls ObjectEventClearHeldMovementIfFinished on the player,
@          clearing the finished held step that would otherwise leave the
@          avatar at T_TILE_CENTER/MOVING and re-assert tookStep as soon as
@          field input resumes -- swapping either non-warp exit of this
@          script for a bare `end` would re-fire this trigger without a new
@          step. So the box does not reopen until the player steps off and
@          back on. From (8,7) the door approach (8,6) is one step north;
@          (7,6) (the guard) and (9,6) flank it.
@ The reciprocal Route28 confirm lands on (8,8), one tile SOUTH of this
@ trigger, so a return from JOHTO never arrives on the trigger tile. The
@ price, recorded on purpose (round 1, review Major-2): walking STRAIGHT
@ north from (8,8) to the door crosses (8,7) and gets this confirm once
@ (answer NO, or detour (9,8)->(9,7)->(9,6)->(8,6)) -- the same one-NO cost
@ as any walk up column 8 from the row-7/8 path below the porch.
@ ============================================================================
Route22_EventScript_KantoGateReturnWarp::
	lockall
	goto_if_unset FLAG_TRINITY_K_ARRIVED, Route22_EventScript_KantoGateNotYet
	msgbox Route22_Text_KantoGateHeadOut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route22_EventScript_KantoGateStay
	warp MAP_ROUTE_28, 37, 12
	waitstate
	releaseall
	end

Route22_EventScript_KantoGateNotYet::
	msgbox Route22_Text_KantoGateNotYet, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route22_EventScript_KantoGateStay::
	closemessage
	releaseall
	end

Route22_Text_KantoGateHeadOut:
	.string "The trail west leads out of KANTO\n"
	.string "into MT. SILVER country.\p"
	.string "Head out?$"

Route22_Text_KantoGateNotYet:
	.string "The trail west isn't open for\n"
	.string "crossing yet.\p"
	.string "Something says turn back.$"
