@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SSAnne_2F_Room2_MapScripts::
	.byte 0

SSAnne_2F_Room2_EventScript_Dale::
	trainerbattle_single TRAINER_KANTO_FISHERMAN_DALE, SSAnne_2F_Room2_Text_DaleSeen, SSAnne_2F_Room2_Text_DaleBeaten
	msgbox SSAnne_2F_Room2_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room2_EventScript_Brooks::
	trainerbattle_single TRAINER_KANTO_GENTLEMAN_BROOKS, SSAnne_2F_Room2_Text_BrooksSeen, SSAnne_2F_Room2_Text_BrooksBeaten
	msgbox SSAnne_2F_Room2_Text_BrooksPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room2_Text_DaleSeen:
	.string "Check out what I fished up!$"

SSAnne_2F_Room2_Text_DaleBeaten:
	.string "I'm all out!$"

SSAnne_2F_Room2_Text_DalePostBattle:
	.string "Party?\pThe cruise ship's party should be\nover by now.$"

SSAnne_2F_Room2_Text_BrooksSeen:
	.string "Competing against the young keeps\nme youthful.$"

SSAnne_2F_Room2_Text_BrooksBeaten:
	.string "Good match!\nAh, I feel young again!$"

SSAnne_2F_Room2_Text_BrooksPostBattle:
	.string "Fifteen years ago, I would\nhave won!$"
