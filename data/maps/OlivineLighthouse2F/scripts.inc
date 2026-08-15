OlivineLighthouse2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, OlivineLighthouse2F_SetHoleWarp
	.byte 0

@ Trinity M4a Task 7 fix: GSC pit-fall (ruling R3). Crystal's engine treats
@ COLL_PIT tiles as an ordinary warp-trigger category (engine/overworld/
@ tile_events.asm CheckWarpCollision), and these 2 PIT cells each have a real
@ matching warp_events entry (uncommented -- GSC used PIT collision for this
@ spiral staircase instead of the usual STAIRCASE/DOOR category). Same-xy
@ landing verified exact: 2F's (16,13)/(17,13) match 1F's own warp_events
@ #4/#5 coordinates precisely -- setholewarp is correct with no coord_event
@ fallback needed. Confirmed floors share dims (10x9 GSC blocks = 20x18 GBA,
@ all 6 Lighthouse floors).
OlivineLighthouse2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_OLIVINE_LIGHTHOUSE_1F
	end

OlivineLighthouse2F_EventScript_HUEY1::
	trainerbattle_single TRAINER_JOHTO_SAILOR_HUEY1, OlivineLighthouse2F_Text_HUEY1Seen, OlivineLighthouse2F_Text_HUEY1Beaten
	msgbox OlivineLighthouse2F_Text_HUEY1Beaten, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse2F_EventScript_ALFRED::
	trainerbattle_single TRAINER_JOHTO_GENTLEMAN_ALFRED, OlivineLighthouse2F_Text_ALFREDSeen, OlivineLighthouse2F_Text_ALFREDBeaten
	msgbox OlivineLighthouse2F_Text_ALFREDBeaten, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse2F_Text_HUEY1Seen:
	.string "Men of the sea are\nalways spoiling\lfor a good fight!$"

OlivineLighthouse2F_Text_HUEY1Beaten:
	.string "Urf!\nI lose!$"

OlivineLighthouse2F_Text_ALFREDSeen:
	.string "Hm? This is no\nplace for playing.$"

OlivineLighthouse2F_Text_ALFREDBeaten:
	.string "Ah! I can see that\nyou're serious.$"
