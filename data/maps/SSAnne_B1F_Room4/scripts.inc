@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SSAnne_B1F_Room4_MapScripts::
	.byte 0

SSAnne_B1F_Room4_EventScript_Duncan::
	trainerbattle_single TRAINER_KANTO_SAILOR_DUNCAN, SSAnne_B1F_Room4_Text_DuncanSeen, SSAnne_B1F_Room4_Text_DuncanBeaten
	msgbox SSAnne_B1F_Room4_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_EventScript_Leonard::
	trainerbattle_single TRAINER_KANTO_SAILOR_LEONARD, SSAnne_B1F_Room4_Text_LeonardSeen, SSAnne_B1F_Room4_Text_LeonardBeaten
	msgbox SSAnne_B1F_Room4_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_Text_DuncanSeen:
	.string "Come on, then!\nMy sailor's pride is at stake!$"

SSAnne_B1F_Room4_Text_DuncanBeaten:
	.string "Your spirit sank me!$"

SSAnne_B1F_Room4_Text_DuncanPostBattle:
	.string "Did you see the FISHING GURU in\nVERMILION CITY?$"

SSAnne_B1F_Room4_Text_LeonardSeen:
	.string "You know what they say about\nsailors and battling!$"

SSAnne_B1F_Room4_Text_LeonardBeaten:
	.string "Right!\nGood battle, mate!$"

SSAnne_B1F_Room4_Text_LeonardPostBattle:
	.string "Hahaha!\nWant to be a sailor, mate?$"
