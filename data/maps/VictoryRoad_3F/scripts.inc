@ ============================================================================
@ M4b S11 -- VICTORY ROAD 3F. Two league-run trainers, and one port repair.
@
@ THE HOLE AT (34,18) HAD NO LANDING. It decodes MB_CRACKED_FLOOR_HOLE, which
@ arms STEP_CB_CRACKED_FLOOR, and this map had no `setholewarp` -- so falling
@ through it warped to whatever sFixedHoleWarp last held. (In pokefirered the
@ same byte is MB_FALL_WARP; the two decomps' behaviour enums diverge, which is
@ the defect class tools/kanto_port/fix_behaviors.py exists for. Here the two
@ meanings agree, so the byte is deliberately left alone and the missing half is
@ the script.) FRLG routes that fall to VICTORY ROAD 2F, and so does the map's
@ own warp 4 at the same tile, so the landing is not a guess.
@
@ setholewarp is not a metatile write, so qa_sweep check 7 is unaffected by it
@ living under ON_TRANSITION -- which is where every vanilla user puts it
@ (BurnedTower1F/scripts.inc:9, GraniteCave_B1F/scripts.inc:9).
@ ============================================================================

VictoryRoad_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_3F_OnTransition
	.byte 0

VictoryRoad_3F_OnTransition:
	setholewarp MAP_VICTORY_ROAD_2F
	end

VictoryRoad_3F_EventScript_BRODY::
	trainerbattle_single TRAINER_VR_COOLTRAINER_M_3, VictoryRoad_3F_Text_BRODYSeen, VictoryRoad_3F_Text_BRODYBeaten
	msgbox VictoryRoad_3F_Text_BRODYAfter, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_PHILANA::
	trainerbattle_single TRAINER_VR_COOLTRAINER_F_3, VictoryRoad_3F_Text_PHILANASeen, VictoryRoad_3F_Text_PHILANABeaten
	msgbox VictoryRoad_3F_Text_PHILANAAfter, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_BRODYSeen:
	.string "Top floor. Nothing up here but\n"
	.string "rock and people who won't leave.$"

VictoryRoad_3F_Text_BRODYBeaten:
	.string "Fine. I'll leave.$"

VictoryRoad_3F_Text_BRODYAfter:
	.string "Watch the floor on the east side.\n"
	.string "There's a hole in it, and it goes\l"
	.string "all the way back down to two.\p"
	.string "Ask me how I know.$"

VictoryRoad_3F_Text_PHILANASeen:
	.string "The ELITE FOUR are past this.\p"
	.string "I've never seen them. I only ever\n"
	.string "meet the people on the way up.$"

VictoryRoad_3F_Text_PHILANABeaten:
	.string "And now I've met the one who\n"
	.string "gets through.$"

VictoryRoad_3F_Text_PHILANAAfter:
	.string "Four rooms, one after another,\n"
	.string "and the door shuts behind you\l"
	.string "each time.\p"
	.string "There's no walking back out of\n"
	.string "that place. Only forward.$"
