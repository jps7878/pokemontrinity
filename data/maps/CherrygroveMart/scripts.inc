CherrygroveMart_MapScripts::
	.byte 0

CherrygroveMart_EventScript_Clerk::
	msgbox CherrygroveMart_Text_Clerk, MSGBOX_NPC
	end

CherrygroveMart_EventScript_CooltrainerM::
	msgbox CherrygroveMart_Text_CooltrainerM, MSGBOX_NPC
	end

CherrygroveMart_EventScript_Youngster::
	msgbox CherrygroveMart_Text_Youngster, MSGBOX_NPC
	end

CherrygroveMart_Text_Clerk:
	.string "JOHTO's changed a lot since the\nHOENN champion opened the sea\lroutes here.$"

CherrygroveMart_Text_CooltrainerM:
	.string "This route sure gets more foot\ntraffic now that HOENN trainers\lkeep showing up.$"

CherrygroveMart_Text_Youngster:
	.string "When I was walking\nin the grass, a\pbug POKéMON poi-\nsoned my POKéMON!\pI just kept going,\nbut then my\lPOKéMON fainted.\pYou should keep an\nANTIDOTE with you.$"
