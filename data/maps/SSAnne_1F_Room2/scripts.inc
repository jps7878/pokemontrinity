@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SSAnne_1F_Room2_MapScripts::
	.byte 0

SSAnne_1F_Room2_EventScript_Ann::
	trainerbattle_single TRAINER_KANTO_LASS_ANN, SSAnne_1F_Room2_Text_AnnSeen, SSAnne_1F_Room2_Text_AnnBeaten
	msgbox SSAnne_1F_Room2_Text_AnnPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_EventScript_Tyler::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_TYLER, SSAnne_1F_Room2_Text_TylerSeen, SSAnne_1F_Room2_Text_TylerBeaten
	msgbox SSAnne_1F_Room2_Text_TylerPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_EventScript_Woman::
	msgbox SSAnne_1F_Room2_Text_Woman, MSGBOX_NPC
	end

SSAnne_1F_Room2_Text_AnnSeen:
	.string "I collected these POKéMON\nfrom all around the world!$"

SSAnne_1F_Room2_Text_AnnBeaten:
	.string "Oh, no!\nI went around the world for these!$"

SSAnne_1F_Room2_Text_AnnPostBattle:
	.string "You hurt my poor POKéMON!\pI demand that you heal them at a\nPOKéMON CENTER!$"

SSAnne_1F_Room2_Text_TylerSeen:
	.string "I love POKéMON!\nDo you?$"

SSAnne_1F_Room2_Text_TylerBeaten:
	.string "Wow! \nYou're great!$"

SSAnne_1F_Room2_Text_TylerPostBattle:
	.string "Listen, listen!\nLet me be your friend, okay?\pThen we can trade POKéMON and\ndo stuff.$"

SSAnne_1F_Room2_Text_Woman:
	.string "We are cruising around the world,\nmy children and I.$"
