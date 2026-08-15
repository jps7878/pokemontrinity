OlivineLighthouse4F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, OlivineLighthouse4F_SetHoleWarp
	.byte 0

@ Trinity M4a Task 7 fix: GSC pit-fall (ruling R3). Same PIT-as-staircase
@ situation as 2F (see that file's comment). 4F has 2 PIT pairs, both landing
@ on 3F: same-xy verified exact for both -- (8,3)/(9,3) match 3F's own
@ warp_events #8/#9, and (16,9)/(17,9) match 3F's own warp_events #6/#7.
OlivineLighthouse4F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_OLIVINE_LIGHTHOUSE_3F
	end

OlivineLighthouse4F_EventScript_KENT::
	trainerbattle_single TRAINER_JOHTO_SAILOR_KENT, OlivineLighthouse4F_Text_KENTSeen, OlivineLighthouse4F_Text_KENTBeaten
	msgbox OlivineLighthouse4F_Text_KENTBeaten, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse4F_EventScript_CONNIE1::
	trainerbattle_single TRAINER_JOHTO_LASS_CONNIE1, OlivineLighthouse4F_Text_CONNIE1Seen, OlivineLighthouse4F_Text_CONNIE1Beaten
	msgbox OlivineLighthouse4F_Text_CONNIE1Beaten, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse4F_Text_KENTSeen:
	.string "JASMINE must be\nworried sick about\lthe POKéMON here.\pShe won't even\nsmile these days.$"

OlivineLighthouse4F_Text_KENTBeaten:
	.string "I can't manage a\nsmile either…$"

OlivineLighthouse4F_Text_CONNIE1Seen:
	.string "JASMINE is this\ncity's GYM LEADER.\pI mean to bring\nher back with me.\pNobody had better\nget in my way!$"

OlivineLighthouse4F_Text_CONNIE1Beaten:
	.string "Aaack! My POKéMON!$"
