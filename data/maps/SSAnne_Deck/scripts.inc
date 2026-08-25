SSAnne_Deck_MapScripts::
	.byte 0

SSAnne_Deck_EventScript_Trevor::
	trainerbattle_single TRAINER_KANTO_SAILOR_TREVOR, SSAnne_Deck_Text_TrevorSeen, SSAnne_Deck_Text_TrevorBeaten
	msgbox SSAnne_Deck_Text_TrevorBeaten, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_EventScript_BaldingMan::
	msgbox SSAnne_Deck_Text_BaldingMan, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_Sailor::
	msgbox SSAnne_Deck_Text_Sailor, MSGBOX_NPC
	end

SSAnne_Deck_EventScript_Edmond::
	trainerbattle_single TRAINER_KANTO_SAILOR_EDMOND, SSAnne_Deck_Text_EdmondSeen, SSAnne_Deck_Text_EdmondBeaten
	msgbox SSAnne_Deck_Text_EdmondBeaten, MSGBOX_AUTOCLOSE
	end

SSAnne_Deck_EventScript_Youngster::
	msgbox SSAnne_Deck_Text_Youngster, MSGBOX_NPC
	end

SSAnne_Deck_Text_TrevorSeen:
	.string "…$"

SSAnne_Deck_Text_TrevorBeaten:
	.string "…$"

SSAnne_Deck_Text_BaldingMan:
	.string "Urf… I feel ill…\pI got seasick, so I stepped out to\nget some air…$"

SSAnne_Deck_Text_Sailor:
	.string "Whew!\nScrubbing decks is hard work!$"

SSAnne_Deck_Text_EdmondSeen:
	.string "…$"

SSAnne_Deck_Text_EdmondBeaten:
	.string "…$"

SSAnne_Deck_Text_Youngster:
	.string "The party's over.\nThe ship will be departing soon.$"
