@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ EXCEPT 6 string(s) on this map, which are hand-authored overlays
@ declared in tools/kanto_port/frlg_text_overrides.json -- the cold
@ KANTO voice of finding #14.  `--verify` checks those against the
@ manifest instead of against pokefirered.
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

Route6_MapScripts::
	.byte 0

Route6_EventScript_Keigo::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_KEIGO, Route6_Text_KeigoSeen, Route6_Text_KeigoBeaten
	msgbox Route6_Text_KeigoPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Ricky::
	trainerbattle_single TRAINER_KANTO_CAMPER_RICKY, Route6_Text_RickySeen, Route6_Text_RickyBeaten
	msgbox Route6_Text_RickyPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Nancy::
	trainerbattle_single TRAINER_KANTO_PICNICKER_NANCY, Route6_Text_NancySeen, Route6_Text_NancyBeaten
	msgbox Route6_Text_NancyPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Elijah::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_ELIJAH, Route6_Text_ElijahSeen, Route6_Text_ElijahBeaten
	msgbox Route6_Text_ElijahPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Isabelle::
	trainerbattle_single TRAINER_KANTO_PICNICKER_ISABELLE, Route6_Text_IsabelleSeen, Route6_Text_IsabelleBeaten
	msgbox Route6_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Jeff::
	trainerbattle_single TRAINER_KANTO_CAMPER_JEFF, Route6_Text_JeffSeen, Route6_Text_JeffBeaten
	msgbox Route6_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_UndergroundPathSign::
	msgbox Route6_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route6_Text_KeigoSeen:
	.string "Don't know you.\nDon't need to.\lKANTO judges its own.$"

Route6_Text_KeigoBeaten:
	.string "No!\nYou're kidding!$"

Route6_Text_KeigoPostBattle:
	.string "I like bugs, so I'm going back to\nVIRIDIAN FOREST.$"

Route6_Text_RickySeen:
	.string "You came up from VERMILION.\nEverybody does.\lNobody gets past me.$"

Route6_Text_RickyBeaten:
	.string "I just can't win!$"

Route6_Text_RickyPostBattle:
	.string "Whisper…\nWhisper…$"

Route6_Text_NancySeen:
	.string "All those badges, and you still\nwalk the long way round\llike the rest of us.$"

Route6_Text_NancyBeaten:
	.string "Ugh!\nI hate losing.$"

Route6_Text_NancyPostBattle:
	.string "Whisper…\nWhisper…$"

Route6_Text_ElijahSeen:
	.string "This is ROUTE 6.\nThe bugs here haven't\lheard of you.$"

Route6_Text_ElijahBeaten:
	.string "You're too good!$"

Route6_Text_ElijahPostBattle:
	.string "Are my POKéMON weak?\nOr, am I just bad?\lWhich do you think?$"

Route6_Text_IsabelleSeen:
	.string "I eat lunch on this road\nevery day. Sit down,\lor battle.$"

Route6_Text_IsabelleBeaten:
	.string "Things just didn't work…$"

Route6_Text_IsabellePostBattle:
	.string "I want to get stronger.\nWhat's your secret?$"

Route6_Text_JeffSeen:
	.string "SAFFRON is that way.\nSo is everybody else.\lBattle first.$"

Route6_Text_JeffBeaten:
	.string "This stinks…\nI couldn't beat your challenge…$"

Route6_Text_JeffPostBattle:
	.string "I should bring more POKéMON with\nme. I'll feel safer that way.$"

Route6_Text_UndergroundPathSign:
	.string "UNDERGROUND PATH\nCERULEAN CITY - VERMILION CITY$"
