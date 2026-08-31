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

@ ============================================================================
@ Trinity M5b S12 -- the MT. SILVER climb gate, VAR_TRINITY_KANTO_ARC >= 6
@ (Kanto-clear; never FLAG_IS_CHAMPION, PokemonLeague_HallOfFame/scripts.inc's
@ own standing warning). Full decode: docs/superpowers/plans/m5b/
@ 12-mt-silver-red.md section 2.
@
@ WHY 8 COORD_EVENTS, NOT ONE. Unlike this map's own KantoGateCheck above (a
@ coord_event stacked on a discrete WARP tile), the ROUTE28<->SILVER_CAVE_
@ OUTSIDE border is a plain `connections` edge (map.json, offset -18/left) --
@ a seamless multi-row crossing, not a single door. reach_check.py's own Map
@ class confirms the west edge (x=0) is walkable at y in {0,3,12,13,14,15,16,
@ 17} (elev 3 throughout), each with a walkable partner on SilverCaveOutside's
@ east edge at row y+18 (0->18, 3->21, 12->30, 13->31, 14->32, 15->33, 16->34,
@ 17->35 -- all confirmed walkable). BFS from this map's real entry points
@ shows all 8 are genuinely player-reachable: (0,0) and (0,14)-(0,17) from the
@ MAP_ROUTE22 warp landing (39,8); (0,3)/(0,12)/(0,13) only from the STEEL_WING
@ _HOUSE warp-back (7,3) and/or this map's own internal warp landing (33,5).
@ No single tile is a cut vertex (same class of finding as KantoGateCheck's own
@ east-edge note above) -- all 8 need their own trigger.
@
@ Bounce is a fixed walk_right (east, back into ROUTE28). FIX ROUND 1 (review
@ Major-2, Minor-4): this comment originally claimed "none of the 8 is
@ reachable by a vertical column-step" and that every (1,y) landing tile is
@ MB_NORMAL/MB_TALL_GRASS. Both false, re-checked directly against
@ LAYOUT_ROUTE_28_JOHTO: five of the eight x=0 rows ARE vertically adjacent
@ to a sibling trigger tile in both directions ((0,12)<->(0,13);
@ (0,14)<->(0,15)<->(0,16)<->(0,17) -- only (0,13)<->(0,14) is severed, by
@ MB_IMPASSABLE_NORTH at (0,14)), and (1,14) itself decodes
@ MB_IMPASSABLE_NORTH, not MB_NORMAL/MB_TALL_GRASS (the other seven (1,y)
@ tiles do). The bounce is still safe, for the reason that actually holds:
@ (a) walk_right moves the player off x=0 before a second x=0 step is ever
@ possible, so a vertical chain along the edge cannot re-trigger this gate
@ mid-bounce; and (b) independently, every (1,y) landing tile for all eight
@ rows is col=0, elev=3, non-ledge -- MB_IMPASSABLE_NORTH blocks only
@ northward entry, not the eastward landing at (1,14) nor exiting it -- so a
@ fixed east bounce is correct regardless of approach direction. No
@ GetPlayerFacingDirection() branching needed, unlike ViridianCity's own
@ thru-tile gate, but not because this edge can't be walked vertically.
@
@ Same VAR_TEMP_1==0 "always fires" idiom as KantoGateCheck/Route26's League
@ gate/CeruleanCity's cave mouth. OPEN is a bare `end` (not a manual re-warp
@ like KantoGateOpen above) because this tile is not itself a warp -- once the
@ coord_event resolves without a bounce, the player's own next westward step
@ crosses the connection normally, exactly as CeruleanCity_EventScript_
@ CaveMouthOpen's own bare `end` does for its one-tile-before-the-door shape.
@
@ READ-ONLY: this gate never writes VAR_TRINITY_KANTO_ARC. S12's own RED
@ defeat flow (SilverCaveRoom3/scripts.inc) is the ONE writer of value 7;
@ this gate only ever reads >=6 (S11's own arc write, PokemonLeague_
@ HallOfFame/scripts.inc).
@ ============================================================================
Route28_EventScript_SilverCaveGateCheck::
	goto_if_ge VAR_TRINITY_KANTO_ARC, 6, Route28_EventScript_SilverCaveGateOpen
	lockall
	msgbox Route28_Text_SilverCaveNotYet, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route28_Movement_SilverCaveGateStepBack
	waitmovement 0
	releaseall
	end

Route28_EventScript_SilverCaveGateOpen::
	end

Route28_Movement_SilverCaveGateStepBack:
	walk_right
	step_end

@ FIX ROUND 1 (review Minor-8): "Something says" originally opened both the
@ second and fourth lines of this box. Reworded the second line so the
@ construction lands once; the closing echo of Route28_Text_KantoGateNotYet's
@ own "Something says turn back." is deliberate and kept.
Route28_Text_SilverCaveNotYet:
	.string "MT. SILVER stays quiet for now.\n"
	.string "The climb doesn't feel like yours\l"
	.string "yet.\p"
	.string "Something says turn back.$"
