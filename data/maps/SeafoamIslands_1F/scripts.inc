@ Trinity M5b S9 -- two MB_CRACKED_FLOOR_HOLE cells at (21,8)/(30,8), unwired per
@ check_holes.py. Player-fall shortcuts only (FRLG carries no boulder objects on
@ this floor). Same-xy landing on B1F decoded col0 walkable at both -- the
@ standard idiom suffices, no coord_events needed.
SeafoamIslands_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, SeafoamIslands_1F_SetHoleWarp
	.byte 0

SeafoamIslands_1F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_SEAFOAM_ISLANDS_B1F
	end
