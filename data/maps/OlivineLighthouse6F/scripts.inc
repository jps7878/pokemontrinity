OlivineLighthouse6F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, OlivineLighthouse6F_SetHoleWarp
	.byte 0

@ Trinity M4a Task 7 fix: GSC pit-fall (ruling R3). Same PIT-as-staircase
@ situation as 2F (see that file's comment). Same-xy verified exact: 6F's
@ (16,5)/(17,5) match 5F's own warp_events #6/#7 coordinates precisely.
OlivineLighthouse6F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_OLIVINE_LIGHTHOUSE_5F
	end


