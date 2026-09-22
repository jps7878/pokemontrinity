@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SilphCo_9F_MapScripts::
	.byte 0

SilphCo_9F_EventScript_Ed::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_ED, SilphCo_9F_Text_EdSeen, SilphCo_9F_Text_EdBeaten
	msgbox SilphCo_9F_Text_EdPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_EventScript_HealWoman::
	msgbox SilphCo_9F_Text_HealWoman, MSGBOX_NPC
	end

SilphCo_9F_EventScript_FloorSign::
	msgbox SilphCo_9F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_9F_Text_EdSeen:
	.string "Your POKéMON have weak points!\nI can nail them!$"

SilphCo_9F_Text_EdBeaten:
	.string "You hammered me!$"

SilphCo_9F_Text_EdPostBattle:
	.string "Exploiting weak spots does work.\nThink about type advantages.$"

SilphCo_9F_Text_HealWoman:
	.string "I keep a POTION in my desk for\nstaff.\pYou can afford your own.$"

SilphCo_9F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n9F$"
