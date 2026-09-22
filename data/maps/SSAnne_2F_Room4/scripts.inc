@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SSAnne_2F_Room4_MapScripts::
	.byte 0

SSAnne_2F_Room4_EventScript_Lamar::
	trainerbattle_single TRAINER_KANTO_GENTLEMAN_LAMAR, SSAnne_2F_Room4_Text_LamarSeen, SSAnne_2F_Room4_Text_LamarBeaten
	msgbox SSAnne_2F_Room4_Text_LamarPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room4_EventScript_Dawn::
	trainerbattle_single TRAINER_KANTO_LASS_DAWN, SSAnne_2F_Room4_Text_DawnSeen, SSAnne_2F_Room4_Text_DawnBeaten
	msgbox SSAnne_2F_Room4_Text_DawnPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room4_Text_LamarSeen:
	.string "Which do you find more worthy,\na strong or a rare POKéMON?$"

SSAnne_2F_Room4_Text_LamarBeaten:
	.string "I must salute you!$"

SSAnne_2F_Room4_Text_LamarPostBattle:
	.string "Personally, I prefer strong and\nrare POKéMON.$"

SSAnne_2F_Room4_Text_DawnSeen:
	.string "I don't believe I saw you at the\nparty?$"

SSAnne_2F_Room4_Text_DawnBeaten:
	.string "Take it easy!$"

SSAnne_2F_Room4_Text_DawnPostBattle:
	.string "Oh, I adore your strong POKéMON!\nOh, how I envy you for them!$"
