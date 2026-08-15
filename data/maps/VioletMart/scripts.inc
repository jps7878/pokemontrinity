VioletMart_MapScripts::
	.byte 0

VioletMart_EventScript_Clerk::
	msgbox VioletMart_Text_Clerk, MSGBOX_NPC
	end

VioletMart_EventScript_Granny::
	msgbox VioletMart_Text_Granny, MSGBOX_NPC
	end

VioletMart_EventScript_CooltrainerM::
	msgbox VioletMart_Text_CooltrainerM, MSGBOX_NPC
	end

VioletMart_Text_Clerk:
	.string "This route sure gets more foot\ntraffic now that HOENN trainers\lkeep showing up.$"

VioletMart_Text_Granny:
	.string "When you first\ncatch a POKéMON,\lit may be weak.\pBut it will even-\ntually grow to be\lstrong.\pIt's important to\ntreat POKéMON with\llove.$"

VioletMart_Text_CooltrainerM:
	.string "POKéMON can hold\nitems like POTION\land ANTIDOTE.\pBut they don't\nappear to know how\pto use manmade\nitems.$"
