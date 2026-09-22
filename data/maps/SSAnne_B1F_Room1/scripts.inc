@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SSAnne_B1F_Room1_MapScripts::
	.byte 0

SSAnne_B1F_Room1_EventScript_Barny::
	trainerbattle_single TRAINER_KANTO_FISHERMAN_BARNY, SSAnne_B1F_Room1_Text_BarnySeen, SSAnne_B1F_Room1_Text_BarnyBeaten
	msgbox SSAnne_B1F_Room1_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_EventScript_Phillip::
	trainerbattle_single TRAINER_KANTO_SAILOR_PHILLIP, SSAnne_B1F_Room1_Text_PhillipSeen, SSAnne_B1F_Room1_Text_PhillipBeaten
	msgbox SSAnne_B1F_Room1_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_Text_BarnySeen:
	.string "Hello, stranger!\pI can't tell if you're from the seas\nor mountains, but stop and chat.\pAll my POKéMON are from the sea.$"

SSAnne_B1F_Room1_Text_BarnyBeaten:
	.string "Darn!\nI let that one get away!$"

SSAnne_B1F_Room1_Text_BarnyPostBattle:
	.string "I was going to make you my\nassistant, too!$"

SSAnne_B1F_Room1_Text_PhillipSeen:
	.string "Matey, you're walking the plank if\nyou lose!$"

SSAnne_B1F_Room1_Text_PhillipBeaten:
	.string "Argh!\nBeaten by a kid!$"

SSAnne_B1F_Room1_Text_PhillipPostBattle:
	.string "When we're out at sea, jellyfish\nPOKéMON sometimes drift by.$"
