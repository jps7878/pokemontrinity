GoldenrodCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S4 -- GOLDENROD CITY, pre-takeover.
@
@ THE S8 FLIP CONTRACT (also in include/constants/flags.h and in each RADIO
@ TOWER floor's header). S8 writes ONE thing -- setvar VAR_TRINITY_JOHTO_ARC, 6
@ -- and never touches FLAG_TRINITY_J_GOLDENROD_PRE_HIDE. This ON_TRANSITION is
@ the flag's SINGLE AUTHORING SITE (S1 rule); it runs before InitMap and object
@ spawning, so no new-game flag defaults are needed.
@
@   visible iff VAR_TRINITY_JOHTO_ARC != 6
@
@ DELIBERATE AMENDMENT, LEDGERED: the S4 brief proposed "hidden at ARC >= 6".
@ S4 ships "!= 6" instead, because the occupation is a WINDOW, not a terminal
@ state -- ARC 7 is "Tower cleared", and a liberated city whose entire civilian
@ population stayed deleted forever is worse than the bug that would avoid. It
@ is still exactly one arc write for S8, one flag for the cast and one
@ authoring site for the map. If S8 wants a different post-clear cast it
@ narrows the predicate on the objects it cares about and claims its own flag;
@ it never has to rewrite this file.
@
@ S8's own Rocket cast gets its OWN flag and APPENDED objects, so (a) S4's
@ local ids never shift and (b) a removeobject in S8's liberation scene cannot
@ co-sign one of these civilians into permanent non-existence (R1's trap).
@
@ The ROCKET SCOUT at (4,16) is a PRE-takeover object in GSC too --
@ EVENT_GOLDENROD_CITY_ROCKET_SCOUT is CLEARED by the takeover, not set by it
@ -- and he is the referent of the COOLTRAINER F's "man in black" line at
@ (12,16), so the two only make sense placed together.
@ ============================================================================
GoldenrodCity_OnTransition:
	call GoldenrodCity_EventScript_SetPreTakeoverVisibility
	end

GoldenrodCity_EventScript_SetPreTakeoverVisibility::
	goto_if_eq VAR_TRINITY_JOHTO_ARC, 6, GoldenrodCity_EventScript_HidePreTakeover
	clearflag FLAG_TRINITY_J_GOLDENROD_PRE_HIDE
	return

GoldenrodCity_EventScript_HidePreTakeover::
	setflag FLAG_TRINITY_J_GOLDENROD_PRE_HIDE
	return

GoldenrodCity_EventScript_PokefanM::
	msgbox GoldenrodCity_Text_PokefanM, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Youngster1::
	msgbox GoldenrodCity_Text_Youngster1, MSGBOX_NPC
	end

GoldenrodCity_EventScript_CooltrainerF1::
	msgbox GoldenrodCity_Text_CooltrainerF1, MSGBOX_NPC
	end

@ Branches on S1's RADIO CARD flag: ELM already fitted the POKéNAV as a radio,
@ so the campaign line has to acknowledge it.
GoldenrodCity_EventScript_CooltrainerF2::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_RADIO_CARD, GoldenrodCity_EventScript_CooltrainerF2GotCard
	msgbox GoldenrodCity_Text_CooltrainerF2, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_CooltrainerF2GotCard::
	msgbox GoldenrodCity_Text_CooltrainerF2GotCard, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_Youngster2::
	msgbox GoldenrodCity_Text_Youngster2, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Lass::
	msgbox GoldenrodCity_Text_Lass, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Gramps::
	msgbox GoldenrodCity_Text_Gramps, MSGBOX_NPC
	end

GoldenrodCity_EventScript_RocketScout::
	msgbox GoldenrodCity_Text_RocketScout, MSGBOX_NPC
	end

GoldenrodCity_EventScript_StationSign::
	msgbox GoldenrodCity_Text_StationSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_RadioTowerSign::
	msgbox GoldenrodCity_Text_RadioTowerSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_GoldenrodDeptStoreSign::
	msgbox GoldenrodCity_Text_GoldenrodDeptStoreSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_GoldenrodGymSign::
	msgbox GoldenrodCity_Text_GoldenrodGymSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_Sign::
	msgbox GoldenrodCity_Text_Sign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_BikeShopSign::
	msgbox GoldenrodCity_Text_BikeShopSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_GameCornerSign::
	msgbox GoldenrodCity_Text_GameCornerSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_NameRaterSign::
	msgbox GoldenrodCity_Text_NameRaterSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_UndergroundSignNorth::
	msgbox GoldenrodCity_Text_UndergroundSignNorth, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_UndergroundSignSouth::
	msgbox GoldenrodCity_Text_UndergroundSignSouth, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_FlowerShopSign::
	msgbox GoldenrodCity_Text_FlowerShopSign, MSGBOX_SIGN
	end

@ ============================================================================
@ Text -- adapts pokecrystal GoldenrodCity.asm's civilian lines.
@ ============================================================================
GoldenrodCity_Text_PokefanM:
	.string "They built the new RADIO TOWER\n"
	.string "to replace the old, creaky one.\p"
	.string "Whole city runs on it now.\n"
	.string "Shows, weather, the LUCKY\l"
	.string "CHANNEL draw -- all of it out\l"
	.string "of that one building.\p"
	.string "Bit of a lot to hang on one\n"
	.string "building, if you ask me.$"

GoldenrodCity_Text_Youngster1:
	.string "I know there's a new BIKE SHOP,\n"
	.string "but I can't find it anywhere.\p"
	.string "It's a big city! Everything is\n"
	.string "behind something else!$"

GoldenrodCity_Text_CooltrainerF1:
	.string "Is that man in black dressed up\n"
	.string "like a TEAM ROCKET member?\p"
	.string "How silly! They've been gone\n"
	.string "for years.\p"
	.string "…He's been looking at the RADIO\n"
	.string "TOWER for about an hour, mind.$"

GoldenrodCity_Text_CooltrainerF2:
	.string "The RADIO TOWER in GOLDENROD\n"
	.string "CITY is a landmark.\p"
	.string "They're running a promotional\n"
	.string "campaign right now.\p"
	.string "They'll modify your POKéNAV so\n"
	.string "it can also serve as a radio.$"

GoldenrodCity_Text_CooltrainerF2GotCard:
	.string "The RADIO TOWER is running a\n"
	.string "campaign -- they'll fit your\l"
	.string "POKéNAV to pick up the radio--\p"
	.string "Oh. Yours already does.\p"
	.string "Who did that for you? A\n"
	.string "PROFESSOR? In NEW BARK?\p"
	.string "Honestly. We advertise for\n"
	.string "weeks and he just does it.$"

GoldenrodCity_Text_Youngster2:
	.string "E-he-he-he…\p"
	.string "I got in trouble for playing in\n"
	.string "the basement of the DEPT.STORE.\p"
	.string "There's a door down there that\n"
	.string "goes somewhere. A man shouted\l"
	.string "at me about it.$"

GoldenrodCity_Text_Lass:
	.string "The man at that house rates\n"
	.string "your POKéMON names.\p"
	.string "He can even rename your\n"
	.string "POKéMON.\p"
	.string "Not the traded ones, though.\n"
	.string "He's very firm about that.$"

GoldenrodCity_Text_Gramps:
	.string "Whew! This is one big town.\n"
	.string "I don't know where anything is.\p"
	.string "There's a whole second town\n"
	.string "under this one, they tell me.\p"
	.string "I'm not going down there.$"

@ GSC GoldenrodCityRocketScoutText1. He is casing the tower. S8 collects.
GoldenrodCity_Text_RocketScout:
	.string "So this is the RADIO TOWER…\p"
	.string "…What? No, I don't need\n"
	.string "anything. I'm looking at a\l"
	.string "building. People look at\l"
	.string "buildings.\p"
	.string "Move along.$"

GoldenrodCity_Text_StationSign:
	.string "GOLDENROD CITY\nSTATION$"

GoldenrodCity_Text_RadioTowerSign:
	.string "GOLDENROD CITY\nRADIO TOWER$"

GoldenrodCity_Text_GoldenrodDeptStoreSign:
	.string "Full Selection of\nPOKéMON Goods!\pGOLDENROD CITY\nDEPT.STORE$"

GoldenrodCity_Text_GoldenrodGymSign:
	.string "GOLDENROD CITY\nPOKéMON GYM\lLEADER: WHITNEY\pThe Incredibly\nPretty Girl!$"

GoldenrodCity_Text_Sign:
	.string "GOLDENROD CITY\pThe Festive City\nof Opulent Charm$"

GoldenrodCity_Text_BikeShopSign:
	.string "The World is a\nCycle Path!\lBIKE SHOP$"

GoldenrodCity_Text_GameCornerSign:
	.string "Your Playground!\pGOLDENROD CITY\nGAME CORNER$"

GoldenrodCity_Text_NameRaterSign:
	.string "NAME RATER\pGet Your POKéMON\nNicknames Rated$"

GoldenrodCity_Text_UndergroundSignNorth:
	.string "UNDERGROUND\nENTRANCE$"

GoldenrodCity_Text_UndergroundSignSouth:
	.string "UNDERGROUND\nENTRANCE$"

GoldenrodCity_Text_FlowerShopSign:
	.string "Blooming Beautiful\nFLOWER SHOP$"
