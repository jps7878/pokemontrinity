@ ============================================================================
@ M4b S11 -- VICTORY ROAD 1F (the KANTO/FRLG floor, reached from JOHTO's
@ ROUTE 26 gate).
@
@ THE CLIMB IS OPEN, and that was measured before a line of this file existed.
@ From (11,20) -- the tile ROUTE 26 lands the player on -- with ZERO objects
@ placed, reach_check --dungeon over the three floors reaches VictoryRoad_2F
@ (48,12), the north exit to ROUTE 23, on foot (--no-surf, 1198 tiles) as well as
@ with SURF (1435). The route is FRLG's own and the 3F detour is mandatory:
@ (48,12) is NOT reachable from VictoryRoad_2F (1,9) within 2F alone.
@
@ Nothing is sealed by M2 having dropped FRLG's ten Strength boulders and three
@ floor switches -- the barriers those switches open are not in the blockdata
@ either -- so the puzzle is a FEATURE this slice skips, not a repair it owes.
@ Logged in the S11 plan, section 10.
@
@ Two of the six TRAINER_VR_COOLTRAINER_* posts live here, on FRLG's own trainer
@ tiles with FRLG's own elevations (S4's pin: an object's elevation must match
@ the floor the PLAYER walks on, and these floors have elevation-4 shelves).
@ Sight-triggered TRAINER_TYPE_NORMAL posts, so PlayTrainerEncounterMusic's map
@ BGM swap is correct for them (R2) and NO_MUSIC is not wanted. Radii are set by
@ the S8 approach-path audit -- a post's RESTING set is P..P+(r-1)d, not P -- and
@ are cut to what the audit allows, not to what FRLG used.
@ ============================================================================

KantoVictoryRoad_1F_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M5a T5 fix round 1 (review Finding 3). The (20,10) warp_event
@ (dest MAP_ROUTE23 #0, added in T5's original pass as the ROUTE 23
@ reciprocal) never auto-fires by itself: it decodes to MB_CAVE, which is
@ not in IsWarpMetatileBehavior's list (src/field_control_avatar.c:925-939),
@ so TryStartWarpEventScript (:880) always returns FALSE there -- and a
@ tree-wide scan for a genuine door/ladder/escalator-class behavior anywhere
@ on this map found exactly one: (3,2) MB_LADDER, already the live
@ VICTORY_ROAD_2F warp. Nowhere near the room's south side qualifies, so
@ relocating instead of scripting was not an option here. The JSON entry
@ stays as reciprocal-index bookkeeping (real, in-bounds dest_warp_id for
@ qa_sweep, and what ROUTE23's own (5,28)->#2 pairing points at); this
@ coord_event -- Route28's exact mechanism, see that map's scripts.inc for
@ the full IsWarpMetatileBehavior/TryStartCoordEventScript writeup -- is
@ what actually fires. The M4b S11 ROUTE26 #0 <-> VR1F #1 corridor above is
@ untouched by any of this.
@
@ M7b Task 16 (finding #10): THIS DIRECTION IS NO LONGER UNCONDITIONAL.
@ Re-measured at Task 16: ROUTE 23 is TWO disconnected components and this
@ warp is the only door between them for an Act II player. From (18,28) --
@ where VICTORY ROAD 2F lands the JOHTO league runner -- reach is 222 tiles
@ (y 0..32), with SURF and without, and it touches neither (5,28) nor
@ (8,153). From (5,28), where this warp lands, reach is 479 tiles on foot
@ and 1332 with SURF, including (8,153) -> ROUTE 22 NORTH ENTRANCE ->
@ ROUTE 22 -> VIRIDIAN CITY; the Act II player is the HOENN CHAMPION and
@ has SURF. reach_check --dungeon over KantoVictoryRoad_1F + VictoryRoad_2F
@ + VictoryRoad_3F + Route23 + IndigoPlateau_Exterior, seeded at (11,20):
@ 3047 nodes and (8,153) REACHED with this edge, 1715 nodes and (8,153)
@ NOT reached without it -- while the league door
@ IndigoPlateau_Exterior (11,7) stays reached either way. So gating HERE,
@ and only here, closes KANTO to a pre-Act-III player without touching the
@ Act II league corridor. ROUTE 28's and ROUTE 22's own K_ARRIVED comments
@ name this leak as the reason their confirms had to be gated; this is that
@ leak's source, and since the fix round of this task both of those comments
@ record it in the past tense with this gate as the closure. Their refusals
@ stay in place as defence-in-depth.
@
@ READ-ONLY: this gate never writes FLAG_TRINITY_K_ARRIVED. M5b S1's S.S.
@ AQUA arrival scene (VermilionCity/scripts.inc) is the one writer.
@
@ NO STEP-BACK, deliberately. (20,10)'s three walkable neighbours are
@ (19,10), (21,10) and (20,11) -- the officer stands on the third -- so a
@ fixed bounce direction would be wrong for one of the two approaches, and
@ there is nothing to bounce away from: the tile is ordinary MB_CAVE floor
@ (metatile 641, col 0, elev 3), not a door approach, and standing on it
@ does nothing once the warp is refused. The refusal re-fires on every
@ fresh crossing -- VAR_TEMP_1 is never written on this map and
@ ClearTempFieldEventData resets it on every map load -- the same "fires on
@ every crossing" property ROUTE 26's and ROUTE 28's gates rely on.
@
@ NOT A METATILE FIX. Re-stamping (20,10) with a real warp-behaviour
@ metatile would make IsWarpMetatileBehavior true there, so
@ TryStartWarpEventScript would fire the bookkeeping warp_event BEFORE any
@ coord_event could test a flag -- i.e. it would make this gate
@ unimplementable. The AFFORDANCE RULE is discharged with an object
@ instead: LOCALID_KANTO_VR1F_R23_OFFICER at (20,11), decoded col 0 /
@ elev 3 / MB_CAVE, facing up at the transit tile. (20,11) is a
@ three-neighbour alcove with no warp, item or bg_event: reach_check puts
@ this map at 228 tiles with its two trainers placed and 227 with the
@ officer added -- he costs exactly his own tile. The two tiles that WOULD
@ have sealed something, (21,10) (reach 194) and (19,10) (reach 189), are
@ left clear.
@ ============================================================================
KantoVictoryRoad_1F_EventScript_Route23ReturnWarp::
	goto_if_unset FLAG_TRINITY_K_ARRIVED, KantoVictoryRoad_1F_EventScript_Route23Sealed
	warp MAP_ROUTE23, 5, 28
	waitstate
	end

KantoVictoryRoad_1F_EventScript_Route23Sealed::
	lockall
	msgbox KantoVictoryRoad_1F_Text_Route23Sealed, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

@ The post itself. Talk-triggered, two states, no flag of its own -- the same
@ read of FLAG_TRINITY_K_ARRIVED the coord script above uses.
KantoVictoryRoad_1F_EventScript_Route23Officer::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_K_ARRIVED, KantoVictoryRoad_1F_EventScript_Route23OfficerOpen
	msgbox KantoVictoryRoad_1F_Text_OfficerSealed, MSGBOX_DEFAULT
	release
	end

KantoVictoryRoad_1F_EventScript_Route23OfficerOpen::
	msgbox KantoVictoryRoad_1F_Text_OfficerOpen, MSGBOX_DEFAULT
	release
	end

KantoVictoryRoad_1F_EventScript_DARNELL::
	trainerbattle_single TRAINER_VR_COOLTRAINER_M_1, KantoVictoryRoad_1F_Text_DARNELLSeen, KantoVictoryRoad_1F_Text_DARNELLBeaten
	msgbox KantoVictoryRoad_1F_Text_DARNELLAfter, MSGBOX_AUTOCLOSE
	end

KantoVictoryRoad_1F_EventScript_SIENNA::
	trainerbattle_single TRAINER_VR_COOLTRAINER_F_1, KantoVictoryRoad_1F_Text_SIENNASeen, KantoVictoryRoad_1F_Text_SIENNABeaten
	msgbox KantoVictoryRoad_1F_Text_SIENNAAfter, MSGBOX_AUTOCLOSE
	end

KantoVictoryRoad_1F_Text_DARNELLSeen:
	.string "Everyone who gets this far has\n"
	.string "eight BADGES.\p"
	.string "That's the point. From here it\n"
	.string "stops meaning anything.$"

KantoVictoryRoad_1F_Text_DARNELLBeaten:
	.string "So it still means something\n"
	.string "when you have them.$"

KantoVictoryRoad_1F_Text_DARNELLAfter:
	.string "Three floors. Then a long road,\n"
	.string "and then the PLATEAU.\p"
	.string "Rest before the last one. Nobody\n"
	.string "ever does.$"

KantoVictoryRoad_1F_Text_SIENNASeen:
	.string "I've camped on this floor for a\n"
	.string "month, battling whoever comes up.\p"
	.string "You're the eleventh. The other ten\n"
	.string "went back down.$"

KantoVictoryRoad_1F_Text_SIENNABeaten:
	.string "…And you're not going to.$"

KantoVictoryRoad_1F_Text_SIENNAAfter:
	.string "Go on up. I'll still be here\n"
	.string "when you come back through.\p"
	.string "Somebody has to tell the next ten\n"
	.string "how it went.$"

KantoVictoryRoad_1F_Text_Route23Sealed:
	.string "OFFICER: Hold it.\p"
	.string "That gap drops onto ROUTE 23, past\n"
	.string "every LEAGUE checkpoint on it.\p"
	.string "KANTO stays closed to you until\n"
	.string "JOHTO's tournament is settled.$"

KantoVictoryRoad_1F_Text_OfficerSealed:
	.string "OFFICER: That gap behind me opens\n"
	.string "onto ROUTE 23, below every LEAGUE\l"
	.string "checkpoint on it.\p"
	.string "KANTO's not open to you yet. The\n"
	.string "way on is up, not out.$"

KantoVictoryRoad_1F_Text_OfficerOpen:
	.string "OFFICER: ROUTE 23 is right behind\n"
	.string "me. Mind the checkpoints -- they\l"
	.string "count KANTO BADGES, not JOHTO.$"
