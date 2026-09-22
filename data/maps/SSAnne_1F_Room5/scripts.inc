@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SSAnne_1F_Room5_MapScripts::
	.byte 0

SSAnne_1F_Room5_EventScript_Arthur::
	trainerbattle_single TRAINER_KANTO_GENTLEMAN_ARTHUR, SSAnne_1F_Room5_Text_ArthurSeen, SSAnne_1F_Room5_Text_ArthurBeaten
	msgbox SSAnne_1F_Room5_Text_ArthurPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room5_Text_ArthurSeen:
	.string "You insolent pup!\nHow dare you barge in!$"

SSAnne_1F_Room5_Text_ArthurBeaten:
	.string "Humph! You rude child!\nYou have no sense of courtesy!$"

SSAnne_1F_Room5_Text_ArthurPostBattle:
	.string "I wish to be left alone!\nGet out!$"
