@ Trinity M5b S9 -- two MB_CRACKED_FLOOR_HOLE cells at (23,8)/(28,8), unwired per
@ check_holes.py. FRLG runs a real boulder chain on this floor too (part of the
@ same five-floor cascade, see SeafoamIslands_1F/scripts.inc); Trinity's own
@ adaptation is plain player-fall shortcuts only, a deliberate logged cut, not
@ a claim of matching FRLG. Same-xy landing on B2F decoded col0 walkable at
@ both -- the standard idiom suffices.
SeafoamIslands_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, SeafoamIslands_B1F_SetHoleWarp
	.byte 0

SeafoamIslands_B1F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_SEAFOAM_ISLANDS_B2F
	end
