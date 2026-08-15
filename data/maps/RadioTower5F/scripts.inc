RadioTower5F_MapScripts::
	.byte 0

RadioTower5F_EventScript_Director::
	msgbox RadioTower5F_Text_Director, MSGBOX_NPC
	end

RadioTower5F_EventScript_DirectorsOfficeSign::
	msgbox RadioTower5F_Text_DirectorsOfficeSign, MSGBOX_SIGN
	end

RadioTower5F_EventScript_Studio1Sign::
	msgbox RadioTower5F_Text_Studio1Sign, MSGBOX_SIGN
	end

RadioTower5F_EventScript_Studio1Sign_2::
	msgbox RadioTower5F_Text_Studio1Sign_2, MSGBOX_SIGN
	end

RadioTower5F_Text_Director:
	.string "The old timers say JOHTO used to\nfeel far from everywhere. Not\lanymore, with HOENN so close now.$"

RadioTower5F_Text_DirectorsOfficeSign:
	.string "5F DIRECTOR'S\n   OFFICE$"

RadioTower5F_Text_Studio1Sign:
	.string "5F STUDIO 1$"

RadioTower5F_Text_Studio1Sign_2:
	.string "5F STUDIO 1$"
