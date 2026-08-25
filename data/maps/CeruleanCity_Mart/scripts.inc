CeruleanCity_Mart_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Clerk::
	msgbox CeruleanCity_Mart_Text_Clerk, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_Woman::
	msgbox CeruleanCity_Mart_Text_Woman, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_Youngster::
	msgbox CeruleanCity_Mart_Text_Youngster, MSGBOX_NPC
	end

CeruleanCity_Mart_Text_Clerk:
	.string "KANTO's got its own trainers worth\nwatching, but even we're curious\labout this HOENN-JOHTO champion.$"

CeruleanCity_Mart_Text_Woman:
	.string "Do you know about RARE CANDY?\nThey don't sell it in shops.\pI think it makes POKéMON grow\nvery quickly all of a sudden.$"

CeruleanCity_Mart_Text_Youngster:
	.string "REPEL not only keeps bugs away,\nit also works on weak POKéMON.\pPut your strongest POKéMON at the\nleft of the POKéMON LIST.\pIf your first POKéMON is strong,\nREPEL's effect is boosted.$"
