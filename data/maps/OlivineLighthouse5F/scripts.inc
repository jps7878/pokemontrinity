OlivineLighthouse5F_MapScripts::
	.byte 0

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
