@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SSAnne_B1F_Room2_MapScripts::
	.byte 0

SSAnne_B1F_Room2_EventScript_Huey::
	trainerbattle_single TRAINER_KANTO_SAILOR_HUEY, SSAnne_B1F_Room2_Text_HueySeen, SSAnne_B1F_Room2_Text_HueyBeaten
	msgbox SSAnne_B1F_Room2_Text_HueyPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room2_Text_HueySeen:
	.string "Even us sailors have POKéMON, too!$"

SSAnne_B1F_Room2_Text_HueyBeaten:
	.string "Okay, you're not bad.$"

SSAnne_B1F_Room2_Text_HueyPostBattle:
	.string "We caught all our POKéMON while\nwe were out at sea.$"
