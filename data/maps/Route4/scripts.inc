@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

Route4_MapScripts::
	.byte 0

Route4_EventScript_Woman::
	msgbox Route4_Text_Woman, MSGBOX_NPC
	end

Route4_EventScript_Crissy::
	trainerbattle_single TRAINER_KANTO_LASS_CRISSY, Route4_Text_CrissySeen, Route4_Text_CrissyBeaten
	msgbox Route4_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_MtMoonSign::
	msgbox Route4_Text_MtMoonSign, MSGBOX_SIGN
	end

Route4_EventScript_RouteSign::
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
	end

Route4_Text_Woman:
	.string "Ouch! I tripped over a rocky\nPOKéMON, GEODUDE!$"

Route4_Text_CrissySeen:
	.string "I came to MT. MOON in search of\nmushroom POKéMON.$"

Route4_Text_CrissyBeaten:
	.string "After all I did to catch them!$"

Route4_Text_CrissyPostBattle:
	.string "There might not be any more\nmushrooms here.\pI think I got them all.$"

Route4_Text_MtMoonSign:
	.string "MT. MOON\nTunnel Entrance$"

Route4_Text_RouteSign:
	.string "ROUTE 4\nMT. MOON - CERULEAN CITY$"
