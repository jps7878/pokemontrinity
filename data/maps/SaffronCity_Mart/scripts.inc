SaffronCity_Mart_MapScripts::
	.byte 0

SaffronCity_Mart_EventScript_Clerk::
	msgbox SaffronCity_Mart_Text_Clerk, MSGBOX_NPC
	end

SaffronCity_Mart_EventScript_Youngster::
	msgbox SaffronCity_Mart_Text_Youngster, MSGBOX_NPC
	end

SaffronCity_Mart_EventScript_Lass::
	msgbox SaffronCity_Mart_Text_Lass, MSGBOX_NPC
	end

SaffronCity_Mart_Text_Clerk:
	.string "KANTO's got its own trainers worth\nwatching, but even we're curious\labout this HOENN-JOHTO champion.$"

SaffronCity_Mart_Text_Youngster:
	.string "MAX REPEL keeps weaker POKéMON\nfrom appearing.\pMAX REPEL stays effective longer\nthan SUPER REPEL.$"

SaffronCity_Mart_Text_Lass:
	.string "REVIVE is costly, but it revives\nfainted POKéMON!$"
