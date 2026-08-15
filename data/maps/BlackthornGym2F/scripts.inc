BlackthornGym2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, BlackthornGym2F_SetHoleWarp
	.byte 0

BlackthornGym2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_BLACKTHORN_GYM_1F
	end

@ Trinity M4a Task 7 fix: GSC pit-fall (ruling R1). All 3 holes' same-xy landing
@ on 1F decodes to WALL (blocked) -- GSC's own warp_events route each hole to a
@ specific 1F tile that does NOT match the hole's own (x,y): (2,5)->(2,6),
@ (8,7)->(7,7), (8,3)->(7,6), all confirmed FLOOR/walkable. coord_events give
@ each hole its correct landing; the setholewarp above is kept as the standard
@ idiom (harmless -- coord_events are checked first and cover all 3 cells).
BlackthornGym2F_EventScript_FallToA::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_BLACKTHORN_GYM_1F, 2, 6
	waitstate
	end

BlackthornGym2F_EventScript_FallToB::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_BLACKTHORN_GYM_1F, 7, 7
	waitstate
	end

BlackthornGym2F_EventScript_FallToC::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_BLACKTHORN_GYM_1F, 7, 6
	waitstate
	end

BlackthornGym2F_EventScript_CODY::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERM_CODY, BlackthornGym2F_Text_CODYSeen, BlackthornGym2F_Text_CODYBeaten
	msgbox BlackthornGym2F_Text_CODYBeaten, MSGBOX_AUTOCLOSE
	end

BlackthornGym2F_EventScript_FRAN::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_FRAN, BlackthornGym2F_Text_FRANSeen, BlackthornGym2F_Text_FRANBeaten
	msgbox BlackthornGym2F_Text_FRANBeaten, MSGBOX_AUTOCLOSE
	end

BlackthornGym2F_Text_CODYSeen:
	.string "It's not as if we\nall use dragon-\ltype POKéMON.$"

BlackthornGym2F_Text_CODYBeaten:
	.string "Rats! If only I\nhad a dragon!$"

BlackthornGym2F_Text_FRANSeen:
	.string "I can't allow a\nnameless trainer\lpast me!\pCLAIR would be\nlivid if I did!$"

BlackthornGym2F_Text_FRANBeaten:
	.string "Awww… I lost…$"
