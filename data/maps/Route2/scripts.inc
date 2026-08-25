Route2_MapScripts::
	.byte 0

Route2_EventScript_DiglettsCaveSign::
	msgbox Route2_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

Route2_EventScript_RouteSign::
	msgbox Route2_Text_RouteSign, MSGBOX_SIGN
	end

Route2_Text_DiglettsCaveSign:
	.string "DIGLETT'S CAVE$"

Route2_Text_RouteSign:
	.string "ROUTE 2\nVIRIDIAN CITY - PEWTER CITY$"
