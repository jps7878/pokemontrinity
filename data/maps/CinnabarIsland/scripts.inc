CinnabarIsland_MapScripts::
	.byte 0

CinnabarIsland_EventScript_Woman::
	msgbox CinnabarIsland_Text_Woman, MSGBOX_NPC
	end

CinnabarIsland_EventScript_OldMan::
	msgbox CinnabarIsland_Text_OldMan, MSGBOX_NPC
	end

@ ============================================================================
@ Trinity M5b S13b -- DEOXYS, the sail-out. Per the sub-plan §3.7/§2: Birth
@ Island's own puzzle + legendary contract are 100% pre-existing engine
@ machinery (BirthIsland_Exterior/scripts.inc), unreachable today only
@ because FLAG_ENABLE_SHIP_BIRTH_ISLAND has zero live writers tree-wide
@ (its one writer, data/scripts/gift_aurora_ticket.inc, is a Mystery-Gift-
@ only script no story path calls). This NPC reuses that exact idiom
@ verbatim: giveitem ITEM_AURORA_TICKET + setflag FLAG_ENABLE_SHIP_
@ BIRTH_ISLAND + setflag FLAG_RECEIVED_AURORA_TICKET. Once set,
@ LilycoveCity_Harbor's own ticket-menu machinery (src/script_menu.c's
@ CreateLilycoveSSTidalMultichoice, re-traced fresh this session:
@ `if (CheckBagHasItem(ITEM_AURORA_TICKET, 1) == TRUE && FlagGet(
@ FLAG_ENABLE_SHIP_BIRTH_ISLAND) == TRUE)` at :845) picks Birth Island up
@ automatically -- ZERO edits to LilycoveCity_Harbor itself. Zero new
@ Trinity registry claims. Gated on VAR_TRINITY_KANTO_ARC>=6 (world-tour
@ postgame, same read every other package in this milestone uses); no
@ hide flag needed -- the object stays visible always (flag "0", matching
@ this map's own WOMAN/OLD_MAN precedent), and the dialogue itself branches
@ on arc + FLAG_RECEIVED_AURORA_TICKET (a reused vanilla flag, not a new
@ claim) for its own idempotence.
@ ============================================================================
CinnabarIsland_EventScript_Researcher::
	lock
	faceplayer
	goto_if_lt VAR_TRINITY_KANTO_ARC, 6, CinnabarIsland_EventScript_ResearcherNotYet
	goto_if_set FLAG_RECEIVED_AURORA_TICKET, CinnabarIsland_EventScript_ResearcherAfter
	msgbox CinnabarIsland_Text_ResearcherOffer, MSGBOX_DEFAULT
	checkitemspace ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, CinnabarIsland_EventScript_ResearcherBagFull
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	msgbox CinnabarIsland_Text_ResearcherGiven, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_EventScript_ResearcherBagFull::
	msgbox CinnabarIsland_Text_ResearcherBagFull, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_EventScript_ResearcherAfter::
	msgbox CinnabarIsland_Text_ResearcherAfter, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_EventScript_ResearcherNotYet::
	msgbox CinnabarIsland_Text_ResearcherNotYet, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_EventScript_IslandSign::
	msgbox CinnabarIsland_Text_IslandSign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_PokemonLabSign::
	msgbox CinnabarIsland_Text_PokemonLabSign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_GymSign::
	msgbox CinnabarIsland_Text_GymSign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_PokemonLabSign_2::
	msgbox CinnabarIsland_Text_PokemonLabSign_2, MSGBOX_SIGN
	end

CinnabarIsland_Text_Woman:
	.string "This route's seen more foot traffic\nlately. Something about a champion\lpassing through from JOHTO.$"

CinnabarIsland_Text_OldMan:
	.string "Scientists conduct experiments \nin the burned-out building.\pYou know, the one they call the\nPOKéMON MANSION.$"

CinnabarIsland_Text_ResearcherNotYet:
	.string "Our long-range readings have been\n"
	.string "strange for months. I can't make\l"
	.string "sense of them yet.$"

CinnabarIsland_Text_ResearcherOffer:
	.string "There's a rock formation far out\n"
	.string "to sea that doesn't match anything\l"
	.string "on record. Lilycove's harbor can\l"
	.string "take you, if you're curious. Here\l"
	.string "-- you'll need this to board.$"

CinnabarIsland_Text_ResearcherBagFull:
	.string "Make some room in your bag first.\n"
	.string "This isn't something to leave\lbehind.$"

CinnabarIsland_Text_ResearcherGiven:
	.string "The harbor at LILYCOVE, in HOENN.\n"
	.string "Show them that.$"

CinnabarIsland_Text_ResearcherAfter:
	.string "Let me know what you find out\nthere.$"

CinnabarIsland_Text_IslandSign:
	.string "CINNABAR ISLAND\nThe Fiery Town of Burning Desire$"

CinnabarIsland_Text_PokemonLabSign:
	.string "POKéMON LAB$"

CinnabarIsland_Text_GymSign:
	.string "KANTO's peaceful most days, but\neven here we've heard the stories\labout that HOENN trainer.$"

CinnabarIsland_Text_PokemonLabSign_2:
	.string "POKéMON LAB$"
