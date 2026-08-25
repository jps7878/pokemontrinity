SilphCo_10F_MapScripts::
	.byte 0

SilphCo_10F_EventScript_Travis::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_TRAVIS, SilphCo_10F_Text_TravisSeen, SilphCo_10F_Text_TravisBeaten
	msgbox SilphCo_10F_Text_TravisBeaten, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_EventScript_WorkerF::
	msgbox SilphCo_10F_Text_WorkerF, MSGBOX_NPC
	end

SilphCo_10F_EventScript_FloorSign::
	msgbox SilphCo_10F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_10F_Text_TravisSeen:
	.string "…$"

SilphCo_10F_Text_TravisBeaten:
	.string "…$"

SilphCo_10F_Text_WorkerF:
	.string "I've fished this stretch of KANTO\nfor years. Lately it's all anyone\ltalks about -- some far-off champion.$"

SilphCo_10F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n10F$"
