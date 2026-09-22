@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SSAnne_1F_Room7_MapScripts::
	.byte 0

SSAnne_1F_Room7_EventScript_Thomas::
	trainerbattle_single TRAINER_KANTO_GENTLEMAN_THOMAS, SSAnne_1F_Room7_Text_ThomasSeen, SSAnne_1F_Room7_Text_ThomasBeaten
	msgbox SSAnne_1F_Room7_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room7_Text_ThomasSeen:
	.string "I am but a solitary traveler…\pMy sole companions and friends are\nPOKéMON I caught on my journeys…$"

SSAnne_1F_Room7_Text_ThomasBeaten:
	.string "My, my friends…$"

SSAnne_1F_Room7_Text_ThomasPostBattle:
	.string "You should be nice to friends!$"
