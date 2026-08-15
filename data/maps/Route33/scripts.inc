Route33_MapScripts::
	.byte 0

Route33_EventScript_ANTHONY2::
	trainerbattle_single TRAINER_JOHTO_HIKER_ANTHONY2, Route33_Text_ANTHONY2Seen, Route33_Text_ANTHONY2Beaten
	msgbox Route33_Text_ANTHONY2Beaten, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_Lass::
	msgbox Route33_Text_Lass, MSGBOX_NPC
	end

Route33_EventScript_Sign::
	msgbox Route33_Text_Sign, MSGBOX_SIGN
	end

Route33_Text_ANTHONY2Seen:
	.string "I came through the\ntunnel, but I\pstill have plenty\nof energy left.$"

Route33_Text_ANTHONY2Beaten:
	.string "Whoa! You've got\nmore zip than me!$"

Route33_Text_Lass:
	.string "Pant, pant…\pI finally got\nthrough that cave.\pIt was much bigger\nthan I'd expected.\pI got too tired to\nexplore the whole\pthing, so I came\noutside.$"

Route33_Text_Sign:
	.string "ROUTE 33$"
