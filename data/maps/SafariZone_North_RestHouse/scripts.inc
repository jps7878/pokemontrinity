SafariZone_North_RestHouse_MapScripts::
	.byte 0

SafariZone_North_RestHouse_EventScript_Gentleman::
	msgbox SafariZone_North_RestHouse_Text_Gentleman, MSGBOX_NPC
	end

SafariZone_North_RestHouse_EventScript_Scientist::
	msgbox SafariZone_North_RestHouse_Text_Scientist, MSGBOX_NPC
	end

SafariZone_North_RestHouse_EventScript_Fisher::
	msgbox SafariZone_North_RestHouse_Text_Fisher, MSGBOX_NPC
	end

SafariZone_North_RestHouse_Text_Gentleman:
	.string "My EEVEE evolved into FLAREON.\pBut, a friend's EEVEE turned into a\nVAPOREON. I wonder why?$"

SafariZone_North_RestHouse_Text_Scientist:
	.string "You can keep any item you find in\nthe SAFARI ZONE.\pBut, you'll run out of time if you\ntry for all of them at once.$"

SafariZone_North_RestHouse_Text_Fisher:
	.string "Go to the deepest part of the\nSAFARI ZONE. You will win a prize!$"
