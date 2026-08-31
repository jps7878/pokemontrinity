@ Trinity M5b S9 -- two MB_CRACKED_FLOOR_HOLE cells at (21,8)/(30,8), unwired per
@ check_holes.py. FRLG runs a real boulder chain on this floor (2 boulders,
@ each falling to reveal B1F's own counterpart -- the same five-floor cascade
@ documented in SeafoamIslands_B3F/scripts.inc and the sub-plan/report's I2/I3
@ correction). Trinity's own adaptation here is simpler by deliberate cut: no
@ boulder chain, plain player-fall shortcuts only -- logged, not a claim of
@ matching FRLG. Same-xy landing on B1F decoded col0 walkable at both -- the
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
