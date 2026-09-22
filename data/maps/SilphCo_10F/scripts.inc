@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SilphCo_10F_MapScripts::
	.byte 0

SilphCo_10F_EventScript_Travis::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_TRAVIS, SilphCo_10F_Text_TravisSeen, SilphCo_10F_Text_TravisBeaten
	msgbox SilphCo_10F_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_EventScript_WorkerF::
	msgbox SilphCo_10F_Text_WorkerF, MSGBOX_NPC
	end

SilphCo_10F_EventScript_FloorSign::
	msgbox SilphCo_10F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_10F_Text_TravisSeen:
	.string "Enough of your silly games!$"

SilphCo_10F_Text_TravisBeaten:
	.string "No continues left!$"

SilphCo_10F_Text_TravisPostBattle:
	.string "Are you satisfied with beating me?\nThen go on home!$"

SilphCo_10F_Text_WorkerF:
	.string "I've fished this stretch of KANTO\nfor years. Lately it's all anyone\ltalks about -- some far-off champion.$"

SilphCo_10F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n10F$"
