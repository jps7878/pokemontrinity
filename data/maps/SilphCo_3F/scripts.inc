SilphCo_3F_MapScripts::
	.byte 0

SilphCo_3F_EventScript_WorkerM::
	msgbox SilphCo_3F_Text_WorkerM, MSGBOX_NPC
	end

SilphCo_3F_EventScript_Jose::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_JOSE, SilphCo_3F_Text_JoseSeen, SilphCo_3F_Text_JoseBeaten
	msgbox SilphCo_3F_Text_JoseBeaten, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_EventScript_FloorSign::
	msgbox SilphCo_3F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_3F_Text_WorkerM:
	.string "This route's seen more foot traffic\nlately. Something about a champion\lpassing through from JOHTO.$"

SilphCo_3F_Text_JoseSeen:
	.string "…$"

SilphCo_3F_Text_JoseBeaten:
	.string "…$"

SilphCo_3F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n3F$"
