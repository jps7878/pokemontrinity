GoldenrodPokecenter1F_MapScripts::
	.byte 0

GoldenrodPokecenter1F_EventScript_Nurse::
	msgbox GoldenrodPokecenter1F_Text_Nurse, MSGBOX_NPC
	end

GoldenrodPokecenter1F_EventScript_ObjectEvent::
	msgbox GoldenrodPokecenter1F_Text_ObjectEvent, MSGBOX_NPC
	end

GoldenrodPokecenter1F_EventScript_Lass::
	msgbox GoldenrodPokecenter1F_Text_Lass, MSGBOX_NPC
	end

GoldenrodPokecenter1F_EventScript_PokefanF::
	msgbox GoldenrodPokecenter1F_Text_PokefanF, MSGBOX_NPC
	end

GoldenrodPokecenter1F_Text_Nurse:
	.string "I've lived in JOHTO my whole life.\nNever thought I'd meet someone\lfrom HOENN way out here.$"

GoldenrodPokecenter1F_Text_ObjectEvent:
	.string "This route sure gets more foot\ntraffic now that HOENN trainers\lkeep showing up.$"

GoldenrodPokecenter1F_Text_Lass:
	.string "A higher level\nPOKéMON doesn't\lalways win.\pAfter all, it may\nhave a type dis-\ladvantage.\pI don't think\nthere is a single\pPOKéMON that is\nthe toughest.$"

GoldenrodPokecenter1F_Text_PokefanF:
	.string "I've been wandering these routes\nfor years. Lately there's talk of\lnothing but the HOENN champion.$"
