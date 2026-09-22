@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

MtEmber_Exterior_MapScripts::
	.byte 0

MtEmber_Exterior_EventScript_Jocelyn::
	trainerbattle_single TRAINER_KANTO_CRUSH_GIRL_JOCELYN, MtEmber_Exterior_Text_JocelynSeen, MtEmber_Exterior_Text_JocelynBeaten
	msgbox MtEmber_Exterior_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_EventScript_Logan::
	trainerbattle_single TRAINER_KANTO_PKMN_RANGER_LOGAN, MtEmber_Exterior_Text_LoganSeen, MtEmber_Exterior_Text_LoganBeaten
	msgbox MtEmber_Exterior_Text_LoganPostBattle, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_EventScript_Beth::
	trainerbattle_single TRAINER_KANTO_PKMN_RANGER_BETH, MtEmber_Exterior_Text_BethSeen, MtEmber_Exterior_Text_BethBeaten
	msgbox MtEmber_Exterior_Text_BethPostBattle, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_Text_JocelynSeen:
	.string "I've been in training so I can mend\nmy broken heart…\pIt toughened me up physically at\nleast! Hi-yah!$"

MtEmber_Exterior_Text_JocelynBeaten:
	.string "I think I tried to overdo it…$"

MtEmber_Exterior_Text_JocelynPostBattle:
	.string "The way you battle, it reminds me\nof the guy who dumped me…$"

MtEmber_Exterior_Text_LoganSeen:
	.string "An active volcano is one that's\nerupting, or about to.$"

MtEmber_Exterior_Text_LoganBeaten:
	.string "Whew… That was hot!\nSweat's erupting from me!$"

MtEmber_Exterior_Text_LoganPostBattle:
	.string "They say there're over 1,500\nactive volcanoes in the world.\pJust thinking about them makes me\nfeel all hot and gooey inside!$"

MtEmber_Exterior_Text_BethSeen:
	.string "Do you know how caves form inside\nvolcanoes?$"

MtEmber_Exterior_Text_BethBeaten:
	.string "Atchah!\nYou're shockingly good!$"

MtEmber_Exterior_Text_BethPostBattle:
	.string "When lava at the surface of magma\nhardens, and the magma inside flows\lout, caverns are left behind.$"
