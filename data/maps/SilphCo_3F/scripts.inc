@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SilphCo_3F_MapScripts::
	.byte 0

SilphCo_3F_EventScript_WorkerM::
	msgbox SilphCo_3F_Text_WorkerM, MSGBOX_NPC
	end

SilphCo_3F_EventScript_Jose::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_JOSE, SilphCo_3F_Text_JoseSeen, SilphCo_3F_Text_JoseBeaten
	msgbox SilphCo_3F_Text_JosePostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_EventScript_FloorSign::
	msgbox SilphCo_3F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_3F_Text_WorkerM:
	.string "I work for SILPH CO.\nWhat am I to do?$"

SilphCo_3F_Text_JoseSeen:
	.string "I support TEAM ROCKET more than\nI support SILPH CO.!$"

SilphCo_3F_Text_JoseBeaten:
	.string "You really got me!$"

SilphCo_3F_Text_JosePostBattle:
	.string "Humph…\pTEAM ROCKET said that if I helped\nthem, they'd let me study POKéMON.$"

SilphCo_3F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n3F$"
