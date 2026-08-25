SafariZone_West_RestHouse_MapScripts::
	.byte 0

SafariZone_West_RestHouse_EventScript_Scientist::
	msgbox SafariZone_West_RestHouse_Text_Scientist, MSGBOX_NPC
	end

SafariZone_West_RestHouse_EventScript_Man::
	msgbox SafariZone_West_RestHouse_Text_Man, MSGBOX_NPC
	end

SafariZone_West_RestHouse_EventScript_CooltrainerF::
	msgbox SafariZone_West_RestHouse_Text_CooltrainerF, MSGBOX_NPC
	end

SafariZone_West_RestHouse_Text_Scientist:
	.string "Tossing ROCKS at POKéMON might\nmake them run, but they'll be\leasier to catch.$"

SafariZone_West_RestHouse_Text_Man:
	.string "Using BAIT will make POKéMON more\nlikely to stick around if they get\lbusy eating.$"

SafariZone_West_RestHouse_Text_CooltrainerF:
	.string "I hiked a lot, but I didn't see any\nPOKéMON I wanted.$"
