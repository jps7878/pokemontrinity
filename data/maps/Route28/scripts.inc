Route28_MapScripts::
	.byte 0

Route28_EventScript_Sign::
	msgbox Route28_Text_Sign, MSGBOX_SIGN
	end

Route28_Text_Sign:
	.string "ROUTE 28$"

@ ============================================================================
@ Trinity M5a T5 -- the ROUTE 28/KANTO land gate. The coord_event trigger sits
@ ON TOP of the (39,8) warp_event (elevation 3, matching both), which is legal
@ and precedented tree-wide (RuinsOfAlph puzzle rooms, BlackthornGym2F, both
@ Littleroot kids' houses all stack a trigger on a warp tile the same way):
@ TryStartStepBasedScript (src/field_control_avatar.c:607-621) checks
@ TryStartCoordEventScript BEFORE TryStartWarpEventScript and returns as soon
@ as one fires, so the coord_event always wins and the warp never auto-fires
@ on this tile -- the OPEN branch below has to reissue it by hand.
@
@ Fix round 1 (review Finding 2, root cause note): the (39,8) warp_event in
@ map.json is RECIPROCAL-INDEX BOOKKEEPING ONLY, not the live mechanism --
@ its tile decodes to MB_NORMAL, which IsWarpMetatileBehavior
@ (src/field_control_avatar.c:925-939) rejects (only MB_WARP_DOOR/LADDER/
@ ESCALATOR/NON_ANIM_DOOR/the four hardcoded specials qualify), so
@ TryStartWarpEventScript (:880) would never have fired it even without the
@ coord_event stacked on top. Kept anyway so warp_events[2] is a real,
@ in-bounds dest_warp_id for qa_sweep's tree-wide bounds check and so
@ Route22's own (8,7) entry (its mirror -- see that map's scripts.inc) has
@ something real to point back at.
@
@ WHY A SCRIPTED GATE HERE AND NOT A PHYSICAL BLOCKER (the Route26 League gate's
@ shape, mirrored otherwise): Route 28's east edge is wide open column-to-column
@ (x=39 walkable at every row 0-17, plus fully-open plazas at y=0/16/17), so no
@ single tile is a cut vertex the way ROUTE26's corridor is -- a cut-vertex
@ search over every tile x=25..39 (reach_check machinery, see task-5-report.md)
@ found none. A trigger tied to the exact crossing tile catches every approach
@ angle regardless; a standing NPC in open ground would not.
@
@ READ-ONLY: this chain never sets FLAG_TRINITY_K_ARRIVED. M5b S1 is the one
@ writer (the S.S. AQUA arrival cutscene, per the M5 design spec decision 5).
Route28_EventScript_KantoGateCheck::
	goto_if_set FLAG_TRINITY_K_ARRIVED, Route28_EventScript_KantoGateOpen
	lockall
	msgbox Route28_Text_KantoGateNotYet, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route28_Movement_KantoGateStepBack
	waitmovement 0
	releaseall
	end

Route28_EventScript_KantoGateOpen::
	warp MAP_ROUTE22, 8, 7
	waitstate
	end

Route28_Movement_KantoGateStepBack:
	walk_left
	step_end

Route28_Text_KantoGateNotYet:
	.string "The trail east goes quiet here --\n"
	.string "like KANTO isn't ready for you\l"
	.string "yet.\p"
	.string "Something says turn back.$"
