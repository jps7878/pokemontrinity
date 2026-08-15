GoldenrodHappinessRater_MapScripts::
	.byte 0

GoldenrodHappinessRater_EventScript_Teacher::
	msgbox GoldenrodHappinessRater_Text_Teacher, MSGBOX_NPC
	end

GoldenrodHappinessRater_EventScript_PokefanM::
	msgbox GoldenrodHappinessRater_Text_PokefanM, MSGBOX_NPC
	end

GoldenrodHappinessRater_EventScript_Twin::
	msgbox GoldenrodHappinessRater_Text_Twin, MSGBOX_NPC
	end

GoldenrodHappinessRater_Text_Teacher:
	.string "I've lived in JOHTO my whole life.\nNever thought I'd meet someone\lfrom HOENN way out here.$"

GoldenrodHappinessRater_Text_PokefanM:
	.string "I keep losing in\nbattles, and my\pPOKéMON end up\nfainting…\pMaybe that's why\nmy POKéMON don't\llike me much…$"

GoldenrodHappinessRater_Text_Twin:
	.string "When I use an item\non my POKéMON, it\lacts really glad!$"
