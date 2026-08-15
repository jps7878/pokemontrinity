GoldenrodGameCorner_MapScripts::
	.byte 0

@ Trinity M4b S4: the duplicate PHARMACIST was deleted here -- M4a's population
@ run emitted TWO objects on (8,7) with identical sprite, movement and text
@ (…_EventScript_Pharmacist and …_EventScript_Pharmacist_2). The second object,
@ its script and its text string are gone; the survivor keeps the tile. Nothing
@ on this map names a local id, so the shift of the objects after it is inert.

GoldenrodGameCorner_EventScript_CoinVendor::
	msgbox GoldenrodGameCorner_Text_CoinVendor, MSGBOX_NPC
	end

GoldenrodGameCorner_EventScript_TMVendor::
	msgbox GoldenrodGameCorner_Text_TMVendor, MSGBOX_NPC
	end

GoldenrodGameCorner_EventScript_PrizeMonVendor::
	msgbox GoldenrodGameCorner_Text_PrizeMonVendor, MSGBOX_NPC
	end

GoldenrodGameCorner_EventScript_Pharmacist::
	msgbox GoldenrodGameCorner_Text_Pharmacist, MSGBOX_NPC
	end

GoldenrodGameCorner_EventScript_PokefanM1::
	msgbox GoldenrodGameCorner_Text_PokefanM1, MSGBOX_NPC
	end

GoldenrodGameCorner_EventScript_CooltrainerM::
	msgbox GoldenrodGameCorner_Text_CooltrainerM, MSGBOX_NPC
	end

GoldenrodGameCorner_EventScript_PokefanF::
	msgbox GoldenrodGameCorner_Text_PokefanF, MSGBOX_NPC
	end

GoldenrodGameCorner_EventScript_CooltrainerF::
	msgbox GoldenrodGameCorner_Text_CooltrainerF, MSGBOX_NPC
	end

GoldenrodGameCorner_EventScript_Gentleman::
	msgbox GoldenrodGameCorner_Text_Gentleman, MSGBOX_NPC
	end

GoldenrodGameCorner_EventScript_PokefanM2::
	msgbox GoldenrodGameCorner_Text_PokefanM2, MSGBOX_NPC
	end

GoldenrodGameCorner_Text_CoinVendor:
	.string "COIN exchange, right here!\p"
	.string "The GAME CORNER is a licensed\n"
	.string "amusement facility of GOLDENROD\l"
	.string "CITY. It says so on the wall.$"

GoldenrodGameCorner_Text_TMVendor:
	.string "TM prizes, this counter.\p"
	.string "Some of these you will not find\n"
	.string "in a MART. Not in HOENN either,\l"
	.string "before you ask.$"

GoldenrodGameCorner_Text_PrizeMonVendor:
	.string "POKéMON prizes here!\p"
	.string "People come in for one and\n"
	.string "leave four hours later with a\l"
	.string "cup of coins and no POKéMON.$"

GoldenrodGameCorner_Text_Pharmacist:
	.string "I only came in to get change.\p"
	.string "That was Tuesday.$"

GoldenrodGameCorner_Text_PokefanM1:
	.string "I always play the machine at\n"
	.string "the end. It knows me.$"

GoldenrodGameCorner_Text_CooltrainerM:
	.string "Watch the reels, not the\n"
	.string "lights. The lights are for\l"
	.string "people who are losing.$"

GoldenrodGameCorner_Text_PokefanF:
	.string "My husband is at the counter\n"
	.string "asking what a TM costs.\p"
	.string "He has forty coins.$"

GoldenrodGameCorner_Text_CooltrainerF:
	.string "I won't quit until\nI win!$"

GoldenrodGameCorner_Text_Gentleman:
	.string "I set myself a limit before I\n"
	.string "come in. Then I raise it.\p"
	.string "The limit is the ritual. The\n"
	.string "raising is the hobby.$"

GoldenrodGameCorner_Text_PokefanM2:
	.string "There's a whole UNDERGROUND\n"
	.string "beneath this city, you know.\p"
	.string "They throw people down there\n"
	.string "when they catch them cheating.\p"
	.string "…Not literally. I assume.$"
