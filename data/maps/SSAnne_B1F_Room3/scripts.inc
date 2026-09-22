@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SSAnne_B1F_Room3_MapScripts::
	.byte 0

SSAnne_B1F_Room3_EventScript_Dylan::
	trainerbattle_single TRAINER_KANTO_SAILOR_DYLAN, SSAnne_B1F_Room3_Text_DylanSeen, SSAnne_B1F_Room3_Text_DylanBeaten
	msgbox SSAnne_B1F_Room3_Text_DylanPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room3_Text_DylanSeen:
	.string "I like feisty kids like you!$"

SSAnne_B1F_Room3_Text_DylanBeaten:
	.string "Argh!\nLost it!$"

SSAnne_B1F_Room3_Text_DylanPostBattle:
	.string "Sea POKéMON live in deep water.\nYou'll need a ROD to fish them up!$"
