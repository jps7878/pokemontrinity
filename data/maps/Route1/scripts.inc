Route1_MapScripts::
	.byte 0

Route1_EventScript_MartClerk::
	msgbox Route1_Text_MartClerk, MSGBOX_NPC
	end

Route1_EventScript_Boy::
	msgbox Route1_Text_Boy, MSGBOX_NPC
	end

Route1_EventScript_RouteSign::
	msgbox Route1_Text_RouteSign, MSGBOX_SIGN
	end

Route1_Text_MartClerk:
	.string "KANTO's got its own trainers worth\nwatching, but even we're curious\labout this HOENN-JOHTO champion.$"

Route1_Text_Boy:
	.string "See those ledges along the road?\pIt's a bit scary, but you can jump\nfrom them.\pYou can get back to PALLET TOWN\nquicker that way.$"

Route1_Text_RouteSign:
	.string "ROUTE 1\nPALLET TOWN - VIRIDIAN CITY$"
