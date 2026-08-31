LavenderTown_House2_MapScripts::
	.byte 0

@ M5b S7. The GENTLEMAN sprite/coordinate T10 shipped is FRLG-correct for a
@ Name Rater, but the script body had been flattened to flavor-only -- the
@ actual nickname-rating mechanic was dropped. Restored via the same
@ GoldenrodNameRater precedent (M4b S4, Johto): Emerald's own native Name
@ Rater flow already lives at SlateportCity_NameRatersHouse; event-script
@ labels are global, so this is a plain goto, not a reimplementation.
LavenderTown_House2_EventScript_NameRater::
	goto SlateportCity_NameRatersHouse_EventScript_NameRater
	end
