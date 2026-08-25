SilphCo_5F_MapScripts::
	.byte 0

SilphCo_5F_EventScript_Dalton::
	trainerbattle_single TRAINER_KANTO_JUGGLER_DALTON, SilphCo_5F_Text_DaltonSeen, SilphCo_5F_Text_DaltonBeaten
	msgbox SilphCo_5F_Text_DaltonBeaten, MSGBOX_AUTOCLOSE
	end

SilphCo_5F_EventScript_WorkerM::
	msgbox SilphCo_5F_Text_WorkerM, MSGBOX_NPC
	end

SilphCo_5F_EventScript_Beau::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_BEAU, SilphCo_5F_Text_BeauSeen, SilphCo_5F_Text_BeauBeaten
	msgbox SilphCo_5F_Text_BeauBeaten, MSGBOX_AUTOCLOSE
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
	.string "…$"

SilphCo_5F_Text_DaltonBeaten:
	.string "…$"

SilphCo_5F_Text_WorkerM:
	.string "KANTO's got its own trainers worth\nwatching, but even we're curious\labout this HOENN-JOHTO champion.$"

SilphCo_5F_Text_BeauSeen:
	.string "…$"

SilphCo_5F_Text_BeauBeaten:
	.string "…$"

SilphCo_5F_Text_PokemonReport3:
	.string "It's a POKéMON REPORT!\pSome POKéMON have been confirmed\nto evolve when they are traded.$"

SilphCo_5F_Text_PokemonReport2:
	.string "It's a POKéMON REPORT!\pOver 350 POKéMON techniques have\nbeen confirmed.$"

SilphCo_5F_Text_PokemonReport1:
	.string "It's a POKéMON REPORT!\pPOKéMON LAB created PORYGON,\nthe first virtual-reality POKéMON.$"

SilphCo_5F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n5F$"
