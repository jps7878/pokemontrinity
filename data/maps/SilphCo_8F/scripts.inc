@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SilphCo_8F_MapScripts::
	.byte 0

SilphCo_8F_EventScript_Parker::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_PARKER, SilphCo_8F_Text_ParkerSeen, SilphCo_8F_Text_ParkerBeaten
	msgbox SilphCo_8F_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_WorkerM::
	msgbox SilphCo_8F_Text_WorkerM, MSGBOX_NPC
	end

SilphCo_8F_EventScript_FloorSign::
	msgbox SilphCo_8F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_8F_Text_ParkerSeen:
	.string "You're causing us problems!$"

SilphCo_8F_Text_ParkerBeaten:
	.string "Huh?\nI lost?$"

SilphCo_8F_Text_ParkerPostBattle:
	.string "So, what do you think of SILPH\nBUILDING's maze?$"

SilphCo_8F_Text_WorkerM:
	.string "I never put much stock in rumors,\nbut two Leagues cleared is two\lLeagues cleared. Impressive.$"

SilphCo_8F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n8F$"
