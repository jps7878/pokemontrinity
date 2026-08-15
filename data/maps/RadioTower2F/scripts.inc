RadioTower2F_MapScripts::
	.byte 0

RadioTower2F_EventScript_Teacher::
	msgbox RadioTower2F_Text_Teacher, MSGBOX_NPC
	end

RadioTower2F_EventScript_Buena::
	msgbox RadioTower2F_Text_Buena, MSGBOX_NPC
	end

RadioTower2F_EventScript_SalesSign::
	msgbox RadioTower2F_Text_SalesSign, MSGBOX_SIGN
	end

RadioTower2F_EventScript_OaksPKMNTalkSign::
	msgbox RadioTower2F_Text_OaksPKMNTalkSign, MSGBOX_SIGN
	end

RadioTower2F_EventScript_PokemonRadioSign::
	msgbox RadioTower2F_Text_PokemonRadioSign, MSGBOX_SIGN
	end

RadioTower2F_Text_Teacher:
	.string "The old timers say JOHTO used to\nfeel far from everywhere. Not\lanymore, with HOENN so close now.$"

RadioTower2F_Text_Buena:
	.string "Nothing much happens around here,\nbut ever since that ferry started\lrunning to HOENN, who knows.$"

RadioTower2F_Text_SalesSign:
	.string "2F SALES$"

RadioTower2F_Text_OaksPKMNTalkSign:
	.string "PROF.OAK'S POKéMON\nTALK\pThe Hottest Show\non the Air!$"

RadioTower2F_Text_PokemonRadioSign:
	.string "Anywhere, Anytime\nPOKéMON Radio$"
