OlivineLighthouse4F_MapScripts::
	.byte 0

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
