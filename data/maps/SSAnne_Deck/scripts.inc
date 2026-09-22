@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

SSAnne_Deck_MapScripts::
	.byte 0

SSAnne_Deck_EventScript_Trevor::
	trainerbattle_single TRAINER_KANTO_SAILOR_TREVOR, SSAnne_Deck_Text_TrevorSeen, SSAnne_Deck_Text_TrevorBeaten
	msgbox SSAnne_Deck_Text_TrevorPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_EventScript_BaldingMan::
	msgbox SSAnne_Deck_Text_BaldingMan, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_Sailor::
	msgbox SSAnne_Deck_Text_Sailor, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_Edmond::
	trainerbattle_single TRAINER_KANTO_SAILOR_EDMOND, SSAnne_Deck_Text_EdmondSeen, SSAnne_Deck_Text_EdmondBeaten
	msgbox SSAnne_Deck_Text_EdmondPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_EventScript_Youngster::
	msgbox SSAnne_Deck_Text_Youngster, MSGBOX_NPC
	end

SSAnne_Deck_Text_TrevorSeen:
	.string "Ahoy, there!\nAre you seasick?$"

SSAnne_Deck_Text_TrevorBeaten:
	.string "I was just careless!$"

SSAnne_Deck_Text_TrevorPostBattle:
	.string "My pa said there are 100 kinds of\nPOKéMON. I think there are more.$"

SSAnne_Deck_Text_BaldingMan:
	.string "Urf… I feel ill…\pI got seasick, so I stepped out to\nget some air…$"

SSAnne_Deck_Text_Sailor:
	.string "Whew!\nScrubbing decks is hard work!$"

SSAnne_Deck_Text_EdmondSeen:
	.string "Hey, matey!\pLet's do a little jig!$"

SSAnne_Deck_Text_EdmondBeaten:
	.string "You're impressive!$"

SSAnne_Deck_Text_EdmondPostBattle:
	.string "How many kinds of POKéMON do you\nthink there are in this big world?$"

SSAnne_Deck_Text_Youngster:
	.string "The party's over.\nThe ship will be departing soon.$"
