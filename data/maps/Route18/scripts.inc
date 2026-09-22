@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

Route18_MapScripts::
	.byte 0

Route18_EventScript_Jacob::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_JACOB, Route18_Text_JacobSeen, Route18_Text_JacobBeaten
	msgbox Route18_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Ramiro::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_RAMIRO, Route18_Text_RamiroSeen, Route18_Text_RamiroBeaten
	msgbox Route18_Text_RamiroPostBattle, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_Wilton::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_WILTON, Route18_Text_WiltonSeen, Route18_Text_WiltonBeaten
	msgbox Route18_Text_WiltonPostBattle, MSGBOX_AUTOCLOSE
	end

Route18_EventScript_CyclingRoadSign::
	msgbox Route18_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route18_EventScript_RouteSign::
	msgbox Route18_Text_RouteSign, MSGBOX_SIGN
	end

Route18_Text_JacobSeen:
	.string "This is my turf!\nGet out of here!$"

Route18_Text_JacobBeaten:
	.string "Darn!$"

Route18_Text_JacobPostBattle:
	.string "This is my fave area for catching\nPOKéMON.$"

Route18_Text_RamiroSeen:
	.string "Kurukkoo!\nHow do you like my birdcall?$"

Route18_Text_RamiroBeaten:
	.string "I had to bug you!$"

Route18_Text_RamiroPostBattle:
	.string "I collect sea POKéMON on weekends\nbecause the sea is so close.$"

Route18_Text_WiltonSeen:
	.string "I always check every grassy area\nfor new POKéMON.$"

Route18_Text_WiltonBeaten:
	.string "Tch!$"

Route18_Text_WiltonPostBattle:
	.string "I wish I had a BIKE!$"

Route18_Text_CyclingRoadSign:
	.string "CYCLING ROAD\nNo pedestrians permitted!$"

Route18_Text_RouteSign:
	.string "ROUTE 18\nCELADON CITY - FUCHSIA CITY$"
