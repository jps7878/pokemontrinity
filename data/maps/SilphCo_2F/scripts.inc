@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ EXCEPT 3 string(s) on this map, which are hand-authored overlays
@ declared in tools/kanto_port/frlg_text_overrides.json -- the cold
@ KANTO voice of finding #14.  `--verify` checks those against the
@ manifest instead of against pokefirered.
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
	.string "This floor is SILPH staff only.\nI'll see you out.$"

SilphCo_2F_Text_ConnorBeaten:
	.string "So you fight as well as they say.\nI still want you out.$"

SilphCo_2F_Text_ConnorPostBattle:
	.string "We test POKé BALL prototypes on\nthis floor.\pNothing you're cleared to see.$"

SilphCo_2F_Text_ThunderWaveTutor:
	.string "Don't ask. I taught moves on this\nfloor once.\pSILPH moved the programme out\nyears ago.$"

SilphCo_2F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n2F$"
