SilphCo_4F_MapScripts::
	.byte 0

SilphCo_4F_EventScript_Rodney::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_RODNEY, SilphCo_4F_Text_RodneySeen, SilphCo_4F_Text_RodneyBeaten
	msgbox SilphCo_4F_Text_RodneyBeaten, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_WorkerM::
	msgbox SilphCo_4F_Text_WorkerM, MSGBOX_NPC
	end

SilphCo_4F_EventScript_FloorSign::
	msgbox SilphCo_4F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_4F_Text_RodneySeen:
	.string "…$"

SilphCo_4F_Text_RodneyBeaten:
	.string "…$"

SilphCo_4F_Text_WorkerM:
	.string "They say a trainer beat both the\nHOENN and JOHTO Leagues. Wonder\lif they'll try KANTO next.$"

SilphCo_4F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n4F$"
