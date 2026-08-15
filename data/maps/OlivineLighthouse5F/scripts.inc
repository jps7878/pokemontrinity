OlivineLighthouse5F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, OlivineLighthouse5F_SetHoleWarp
	.byte 0

@ Trinity M4a Task 7 fix: GSC pit-fall (ruling R3). Same PIT-as-staircase
@ situation as 2F (see that file's comment). Same-xy verified exact: 5F's
@ (16,7)/(17,7) match 4F's own warp_events #9/#10 coordinates precisely.
OlivineLighthouse5F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_OLIVINE_LIGHTHOUSE_4F
	end

OlivineLighthouse5F_EventScript_ERNEST::
	trainerbattle_single TRAINER_JOHTO_SAILOR_ERNEST, OlivineLighthouse5F_Text_ERNESTSeen, OlivineLighthouse5F_Text_ERNESTBeaten
	msgbox OlivineLighthouse5F_Text_ERNESTBeaten, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse5F_EventScript_DENIS::
	trainerbattle_single TRAINER_JOHTO_BIRD_KEEPER_DENIS, OlivineLighthouse5F_Text_DENISSeen, OlivineLighthouse5F_Text_DENISBeaten
	msgbox OlivineLighthouse5F_Text_DENISBeaten, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse5F_Text_ERNESTSeen:
	.string "I wanted to battle\nJASMINE, but she's\pnot up to it now.\nSo, how about you?$"

OlivineLighthouse5F_Text_ERNESTBeaten:
	.string "Whoa, whoa. You're\noverwhelming!$"

OlivineLighthouse5F_Text_DENISSeen:
	.string "We're pretty high\nup here. My bird\pPOKéMON are in\nprime form.$"

OlivineLighthouse5F_Text_DENISBeaten:
	.string "Oops…They crashed…$"
