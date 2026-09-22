@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SilphCo_6F_MapScripts::
	.byte 0

SilphCo_6F_EventScript_WorkerM1::
	msgbox SilphCo_6F_Text_WorkerM1, MSGBOX_NPC
	end

SilphCo_6F_EventScript_WorkerF1::
	msgbox SilphCo_6F_Text_WorkerF1, MSGBOX_NPC
	end

SilphCo_6F_EventScript_WorkerM2::
	msgbox SilphCo_6F_Text_WorkerM2, MSGBOX_NPC
	end

SilphCo_6F_EventScript_WorkerM3::
	msgbox SilphCo_6F_Text_WorkerM3, MSGBOX_NPC
	end

SilphCo_6F_EventScript_WorkerF2::
	msgbox SilphCo_6F_Text_WorkerF2, MSGBOX_NPC
	end

SilphCo_6F_EventScript_Taylor::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_TAYLOR, SilphCo_6F_Text_TaylorSeen, SilphCo_6F_Text_TaylorBeaten
	msgbox SilphCo_6F_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_6F_EventScript_FloorSign::
	msgbox SilphCo_6F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_6F_Text_WorkerM1:
	.string "We got engaged.\nHeheh!$"

SilphCo_6F_Text_WorkerF1:
	.string "He's so helpless, he needed\nsomeone like me to look after him.$"

SilphCo_6F_Text_WorkerM2:
	.string "Come work for SILPH when you\nget older.$"

SilphCo_6F_Text_WorkerM3:
	.string "Well, better get back to work.$"

SilphCo_6F_Text_WorkerF2:
	.string "I've seen your face on a magazine\ncover.\pIt didn't get any work done\neither.$"

SilphCo_6F_Text_TaylorSeen:
	.string "That rotten PRESIDENT!\pServes him right for shipping me\noff to the TIKSI BRANCH!\pThat's why TEAM ROCKET came after\nus, I'm sure of it!$"

SilphCo_6F_Text_TaylorBeaten:
	.string "Shoot!$"

SilphCo_6F_Text_TaylorPostBattle:
	.string "TIKSI BRANCH?\nIt's in Russian no-man's-land!$"

SilphCo_6F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n6F$"
