OlivineLighthouse1F_MapScripts::
	.byte 0

OlivineLighthouse1F_EventScript_Sailor::
	msgbox OlivineLighthouse1F_Text_Sailor, MSGBOX_NPC
	end

OlivineLighthouse1F_EventScript_PokefanF::
	msgbox OlivineLighthouse1F_Text_PokefanF, MSGBOX_NPC
	end

OlivineLighthouse1F_Text_Sailor:
	.string "People train at\nthis LIGHTHOUSE.\pIt's not easy to\nclimb because of\lall the trainers.$"

OlivineLighthouse1F_Text_PokefanF:
	.string "In the past, POKé-\nMON used to light\pthe sea around\nOLIVINE at night.\pThe LIGHTHOUSE was\nmade in honor of\lthose POKéMON.$"
