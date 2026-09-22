@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SilphCo_7F_MapScripts::
	.byte 0

SilphCo_7F_EventScript_LaprasGuy::
	msgbox SilphCo_7F_Text_LaprasGuy, MSGBOX_NPC
	end

SilphCo_7F_EventScript_WorkerF::
	msgbox SilphCo_7F_Text_WorkerF, MSGBOX_NPC
	end

SilphCo_7F_EventScript_WorkerM1::
	msgbox SilphCo_7F_Text_WorkerM1, MSGBOX_NPC
	end

SilphCo_7F_EventScript_WorkerM2::
	msgbox SilphCo_7F_Text_WorkerM2, MSGBOX_NPC
	end

SilphCo_7F_EventScript_Joshua::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_JOSHUA, SilphCo_7F_Text_JoshuaSeen, SilphCo_7F_Text_JoshuaBeaten
	msgbox SilphCo_7F_Text_JoshuaPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_FloorSign::
	msgbox SilphCo_7F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_7F_Text_LaprasGuy:
	.string "You're not a ROCKET. Good.\pI've nothing to give you.\nThey took all of it.$"

SilphCo_7F_Text_WorkerF:
	.string "You!\nIt's really dangerous here!\pYou came to save me?\nYou can't!$"

SilphCo_7F_Text_WorkerM1:
	.string "TEAM ROCKET was after the MASTER\nBALL, which catches any POKéMON.$"

SilphCo_7F_Text_WorkerM2:
	.string "It would be bad if TEAM ROCKET\ntook over SILPH or our POKéMON.$"

SilphCo_7F_Text_JoshuaSeen:
	.string "Heheh!\pYou mistook me for a SILPH worker?$"

SilphCo_7F_Text_JoshuaBeaten:
	.string "I'm done!$"

SilphCo_7F_Text_JoshuaPostBattle:
	.string "Despite your age, you are a\nskilled TRAINER!$"

SilphCo_7F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n7F$"
