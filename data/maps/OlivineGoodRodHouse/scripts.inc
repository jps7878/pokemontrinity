OlivineGoodRodHouse_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S6 -- the GOOD ROD house. GSC's GoodRodGuru offers GOOD_ROD; the
@ Act II player already owns it (Hoenn's own fishing guru in DEWFORD), so the
@ gift is skipped -- logged with the OLIVINE CAFE's HM04 skip -- and the guru
@ keeps his thirty years of opinions.
@ ============================================================================
OlivineGoodRodHouse_EventScript_GoodRodGuru::
	msgbox OlivineGoodRodHouse_Text_GoodRodGuru, MSGBOX_NPC
	end

@ Adapts OfferGoodRodText + HaveGoodRodText.
OlivineGoodRodHouse_Text_GoodRodGuru:
	.string "OLIVINE is on the sea!\p"
	.string "And if it's on the sea, there are\n"
	.string "bound to be fish. I've fished this\l"
	.string "harbour for thirty years.\p"
	.string "…Ah. You've got a GOOD ROD on you\n"
	.string "already. Of course you have.\p"
	.string "Then here's the only advice worth\n"
	.string "anything: a different ROD brings up\l"
	.string "a different POKéMON, every time.\p"
	.string "Carry all three or don't bother.$"
