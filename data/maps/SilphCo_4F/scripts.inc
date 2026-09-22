@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SilphCo_4F_MapScripts::
	.byte 0

SilphCo_4F_EventScript_Rodney::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_RODNEY, SilphCo_4F_Text_RodneySeen, SilphCo_4F_Text_RodneyBeaten
	msgbox SilphCo_4F_Text_RodneyPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_4F_EventScript_WorkerM::
	msgbox SilphCo_4F_Text_WorkerM, MSGBOX_NPC
	end

SilphCo_4F_EventScript_FloorSign::
	msgbox SilphCo_4F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_4F_Text_RodneySeen:
	.string "My POKéMON is my loyal servant.$"

SilphCo_4F_Text_RodneyBeaten:
	.string "Darn!\nYou weak POKéMON!$"

SilphCo_4F_Text_RodneyPostBattle:
	.string "The doors are electronically\nlocked.\pIt takes a CARD KEY to open the\ndoors here.$"

SilphCo_4F_Text_WorkerM:
	.string "They say a trainer beat both the\nHOENN and JOHTO Leagues. Wonder\lif they'll try KANTO next.$"

SilphCo_4F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n4F$"
