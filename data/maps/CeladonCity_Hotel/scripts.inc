CeladonCity_Hotel_MapScripts::
	.byte 0

CeladonCity_Hotel_EventScript_Receptionist::
	msgbox CeladonCity_Hotel_Text_Receptionist, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_Beauty::
	msgbox CeladonCity_Hotel_Text_Beauty, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_BeautyBoyfriend::
	msgbox CeladonCity_Hotel_Text_BeautyBoyfriend, MSGBOX_NPC
	end

CeladonCity_Hotel_EventScript_BeautyBrother::
	msgbox CeladonCity_Hotel_Text_BeautyBrother, MSGBOX_NPC
	end

CeladonCity_Hotel_Text_Receptionist:
	.string "POKéMON?\nNo, this is a hotel for people.\pWe're full up, unfortunately.$"

CeladonCity_Hotel_Text_Beauty:
	.string "I'm on vacation with my brother and\nboyfriend.\pCELADON is such a pretty city!$"

CeladonCity_Hotel_Text_BeautyBoyfriend:
	.string "Why?\nWhy did she bring her brother?$"

CeladonCity_Hotel_Text_BeautyBrother:
	.string "Yippee! I'm on vacation!\nMy sis brought me along! Awesome!$"
