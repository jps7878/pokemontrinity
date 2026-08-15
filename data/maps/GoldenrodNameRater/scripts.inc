GoldenrodNameRater_MapScripts::
	.byte 0

@ Trinity M4b S4. The house is called NAME RATER, GOLDENROD CITY's sign at
@ (12,7) advertises it and the new city LASS at (17,10) points visitors here,
@ so it rates names. GSC's GoldenrodNameRater is `special NameRater`; Emerald
@ ships the same flow as an event script at SLATEPORT, whose text never names
@ SLATEPORT, so this is a plain goto -- event-script labels are global.
@ The Emerald flow already opens with lock/faceplayer, so nothing is needed
@ before the jump.
GoldenrodNameRater_EventScript_GoldenrodNameRater::
	goto SlateportCity_NameRatersHouse_EventScript_NameRater
	end
