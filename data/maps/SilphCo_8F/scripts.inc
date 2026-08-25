SilphCo_8F_MapScripts::
	.byte 0

SilphCo_8F_EventScript_Parker::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_PARKER, SilphCo_8F_Text_ParkerSeen, SilphCo_8F_Text_ParkerBeaten
	msgbox SilphCo_8F_Text_ParkerBeaten, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_WorkerM::
	msgbox SilphCo_8F_Text_WorkerM, MSGBOX_NPC
	end

SilphCo_8F_EventScript_FloorSign::
	msgbox SilphCo_8F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_8F_Text_ParkerSeen:
	.string "…$"

SilphCo_8F_Text_ParkerBeaten:
	.string "…$"

SilphCo_8F_Text_WorkerM:
	.string "I never put much stock in rumors,\nbut two Leagues cleared is two\lLeagues cleared. Impressive.$"

SilphCo_8F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n8F$"
