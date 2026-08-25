Route4_MapScripts::
	.byte 0

Route4_EventScript_Woman::
	msgbox Route4_Text_Woman, MSGBOX_NPC
	end

Route4_EventScript_Crissy::
	trainerbattle_single TRAINER_KANTO_LASS_CRISSY, Route4_Text_CrissySeen, Route4_Text_CrissyBeaten
	msgbox Route4_Text_CrissyBeaten, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_MtMoonSign::
	msgbox Route4_Text_MtMoonSign, MSGBOX_SIGN
	end

Route4_EventScript_RouteSign::
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
	end

Route4_Text_Woman:
	.string "Ouch! I tripped over a rocky\nPOKéMON, GEODUDE!$"

Route4_Text_CrissySeen:
	.string "…$"

Route4_Text_CrissyBeaten:
	.string "…$"

Route4_Text_MtMoonSign:
	.string "MT. MOON\nTunnel Entrance$"

Route4_Text_RouteSign:
	.string "ROUTE 4\nMT. MOON - CERULEAN CITY$"
