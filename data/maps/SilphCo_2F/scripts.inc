@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SilphCo_2F_MapScripts::
	.byte 0

SilphCo_2F_EventScript_Jerry::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_JERRY, SilphCo_2F_Text_JerrySeen, SilphCo_2F_Text_JerryBeaten
	msgbox SilphCo_2F_Text_JerryPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Connor::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_CONNOR, SilphCo_2F_Text_ConnorSeen, SilphCo_2F_Text_ConnorBeaten
	msgbox SilphCo_2F_Text_ConnorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_ThunderWaveTutor::
	msgbox SilphCo_2F_Text_ThunderWaveTutor, MSGBOX_NPC
	end

SilphCo_2F_EventScript_FloorSign::
	msgbox SilphCo_2F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_2F_Text_JerrySeen:
	.string "It's off-limits here!\nGo home!$"

SilphCo_2F_Text_JerryBeaten:
	.string "You're good.$"

SilphCo_2F_Text_JerryPostBattle:
	.string "Can you solve the maze in here?\nIt's not easy, I tell you!$"

SilphCo_2F_Text_ConnorSeen:
	.string "Help!\nI'm a SILPH employee.$"

SilphCo_2F_Text_ConnorBeaten:
	.string "How did you know\nI was a ROCKET?$"

SilphCo_2F_Text_ConnorPostBattle:
	.string "I work for both SILPH and TEAM\nROCKET.$"

SilphCo_2F_Text_ThunderWaveTutor:
	.string "I've fished this stretch of KANTO\nfor years. Lately it's all anyone\ltalks about -- some far-off champion.$"

SilphCo_2F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n2F$"
