SafariZone_East_RestHouse_MapScripts::
	.byte 0

SafariZone_East_RestHouse_EventScript_Scientist::
	msgbox SafariZone_East_RestHouse_Text_Scientist, MSGBOX_NPC
	end

SafariZone_East_RestHouse_EventScript_Rocker::
	msgbox SafariZone_East_RestHouse_Text_Rocker, MSGBOX_NPC
	end

SafariZone_East_RestHouse_EventScript_BaldingMan::
	msgbox SafariZone_East_RestHouse_Text_BaldingMan, MSGBOX_NPC
	end

SafariZone_East_RestHouse_Text_Scientist:
	.string "How many did you catch?\nI'm bushed from the effort!$"

SafariZone_East_RestHouse_Text_Rocker:
	.string "I caught a CHANSEY!\pThat makes this all worthwhile.$"

SafariZone_East_RestHouse_Text_BaldingMan:
	.string "Whew!\nI'm tired from all the fun!$"
