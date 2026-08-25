SilphCo_2F_MapScripts::
	.byte 0

SilphCo_2F_EventScript_Jerry::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_JERRY, SilphCo_2F_Text_JerrySeen, SilphCo_2F_Text_JerryBeaten
	msgbox SilphCo_2F_Text_JerryBeaten, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Connor::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_CONNOR, SilphCo_2F_Text_ConnorSeen, SilphCo_2F_Text_ConnorBeaten
	msgbox SilphCo_2F_Text_ConnorBeaten, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_ThunderWaveTutor::
	msgbox SilphCo_2F_Text_ThunderWaveTutor, MSGBOX_NPC
	end

SilphCo_2F_EventScript_FloorSign::
	msgbox SilphCo_2F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_2F_Text_JerrySeen:
	.string "…$"

SilphCo_2F_Text_JerryBeaten:
	.string "…$"

SilphCo_2F_Text_ConnorSeen:
	.string "…$"

SilphCo_2F_Text_ConnorBeaten:
	.string "…$"

SilphCo_2F_Text_ThunderWaveTutor:
	.string "I've fished this stretch of KANTO\nfor years. Lately it's all anyone\ltalks about -- some far-off champion.$"

SilphCo_2F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n2F$"
