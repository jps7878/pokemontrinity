@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SilphCo_5F_MapScripts::
	.byte 0

SilphCo_5F_EventScript_Dalton::
	trainerbattle_single TRAINER_KANTO_JUGGLER_DALTON, SilphCo_5F_Text_DaltonSeen, SilphCo_5F_Text_DaltonBeaten
	msgbox SilphCo_5F_Text_DaltonPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_WorkerM::
	msgbox SilphCo_5F_Text_WorkerM, MSGBOX_NPC
	end

SilphCo_5F_EventScript_Beau::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_BEAU, SilphCo_5F_Text_BeauSeen, SilphCo_5F_Text_BeauBeaten
	msgbox SilphCo_5F_Text_BeauPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_PokemonReport3::
	msgbox SilphCo_5F_Text_PokemonReport3, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport2::
	msgbox SilphCo_5F_Text_PokemonReport2, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_PokemonReport1::
	msgbox SilphCo_5F_Text_PokemonReport1, MSGBOX_SIGN
	end

SilphCo_5F_EventScript_FloorSign::
	msgbox SilphCo_5F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_5F_Text_DaltonSeen:
	.string "Whaaat?\pThere shouldn't be any children\nhere!$"

SilphCo_5F_Text_DaltonBeaten:
	.string "Oh, goodness!$"

SilphCo_5F_Text_DaltonPostBattle:
	.string "You're only on 5F.\nIt's a long way to my BOSS!$"

SilphCo_5F_Text_WorkerM:
	.string "KANTO's got its own trainers worth\nwatching, but even we're curious\labout this HOENN-JOHTO champion.$"

SilphCo_5F_Text_BeauSeen:
	.string "We study POKé BALL technology on\nthis floor.$"

SilphCo_5F_Text_BeauBeaten:
	.string "Dang!\nBlast it!$"

SilphCo_5F_Text_BeauPostBattle:
	.string "We worked on the ultimate POKé\nBALL which would catch anything.$"

SilphCo_5F_Text_PokemonReport3:
	.string "It's a POKéMON REPORT!\pSome POKéMON have been confirmed\nto evolve when they are traded.$"

SilphCo_5F_Text_PokemonReport2:
	.string "It's a POKéMON REPORT!\pOver 350 POKéMON techniques have\nbeen confirmed.$"

SilphCo_5F_Text_PokemonReport1:
	.string "It's a POKéMON REPORT!\pPOKéMON LAB created PORYGON,\nthe first virtual-reality POKéMON.$"

SilphCo_5F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n5F$"
