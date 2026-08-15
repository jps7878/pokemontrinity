AzaleaPokecenter1F_MapScripts::
	.byte 0

AzaleaPokecenter1F_EventScript_Nurse::
	msgbox AzaleaPokecenter1F_Text_Nurse, MSGBOX_NPC
	end

AzaleaPokecenter1F_EventScript_Gentleman::
	msgbox AzaleaPokecenter1F_Text_Gentleman, MSGBOX_NPC
	end

AzaleaPokecenter1F_EventScript_FishingGuru::
	msgbox AzaleaPokecenter1F_Text_FishingGuru, MSGBOX_NPC
	end

AzaleaPokecenter1F_EventScript_PokefanF::
	msgbox AzaleaPokecenter1F_Text_PokefanF, MSGBOX_NPC
	end

AzaleaPokecenter1F_Text_Nurse:
	.string "I've been wandering these routes\nfor years. Lately there's talk of\lnothing but the HOENN champion.$"

AzaleaPokecenter1F_Text_Gentleman:
	.string "Do your POKéMON\nknow HM moves?\pThose moves can\nbe used even if\pyour POKéMON has\nfainted.$"

AzaleaPokecenter1F_Text_FishingGuru:
	.string "BILL's PC can\nstore up to 20\lPOKéMON per BOX.$"

AzaleaPokecenter1F_Text_PokefanF:
	.string "Do you know about\nAPRICORNS?\pCrack one open,\nhollow it out and\pfit it with a\nspecial device.\pThen you can catch\nPOKéMON with it.\pBefore POKé BALLS\nwere invented,\peveryone used\nAPRICORNS.$"
