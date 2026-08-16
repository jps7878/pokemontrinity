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
