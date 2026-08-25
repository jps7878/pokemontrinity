SilphCo_9F_MapScripts::
	.byte 0

SilphCo_9F_EventScript_Ed::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_ED, SilphCo_9F_Text_EdSeen, SilphCo_9F_Text_EdBeaten
	msgbox SilphCo_9F_Text_EdBeaten, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_EventScript_HealWoman::
	msgbox SilphCo_9F_Text_HealWoman, MSGBOX_NPC
	end

SilphCo_9F_EventScript_FloorSign::
	msgbox SilphCo_9F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_9F_Text_EdSeen:
	.string "…$"

SilphCo_9F_Text_EdBeaten:
	.string "…$"

SilphCo_9F_Text_HealWoman:
	.string "I've fished this stretch of KANTO\nfor years. Lately it's all anyone\ltalks about -- some far-off champion.$"

SilphCo_9F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n9F$"
