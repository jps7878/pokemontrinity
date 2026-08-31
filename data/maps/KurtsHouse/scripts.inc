KurtsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KurtsHouse_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S3 -- KURT'S HOUSE. Adapts pokecrystal maps/KurtsHouse.asm.
@ ON_TRANSITION is the SINGLE AUTHORITY for both visibility flags (S1 rule).
@ KURT and the house SLOWPOKE both key off VAR_TRINITY_JOHTO_ARC >= 3, i.e.
@ the SLOWPOKE WELL raid being cleared; FLAG_TRINITY_J_AZALEA_SLOWPOKES_HIDE is
@ shared with AZALEA TOWN's four SLOWPOKE and is authored there from the same
@ predicate, so the two maps can never disagree.
@
@ GSC gates the WELL behind talking to KURT here first (Kurt1 storms out and
@ scares the guard off the well mouth). Trinity drops that prerequisite -- the
@ guard no longer seals the well (see AzaleaTown/scripts.inc) -- so KURT is
@ simply not home during the raid, his granddaughter says where he went, and
@ the canon "I fell down the shaft and landed on my back" beat is delivered by
@ KURT himself in SlowpokeWellB1F, which is where GSC puts it too.
@ ============================================================================
KurtsHouse_OnTransition:
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 3, KurtsHouse_EventScript_ShowKurt
	setflag FLAG_TRINITY_J_KURT_HOME_HIDE
	setflag FLAG_TRINITY_J_AZALEA_SLOWPOKES_HIDE
	end

KurtsHouse_EventScript_ShowKurt::
	clearflag FLAG_TRINITY_J_KURT_HOME_HIDE
	clearflag FLAG_TRINITY_J_AZALEA_SLOWPOKES_HIDE
	end

@ ============================================================================
@ KURT. GSC Kurt1's .ClearedSlowpokeWell branch: the thank-you LURE BALL first,
@ then the apricorn business for good.
@
@ The LURE BALL is the only failable gift on this path, so it owns its own flag
@ and its own label and is retried on the next talk if the bag was full -- the
@ same discipline the GYM PATTERN's G2 uses for leader TMs.
@ ============================================================================
KurtsHouse_EventScript_Kurt::
	lock
	faceplayer
	goto_if_unset FLAG_TRINITY_J_KURT_LURE_BALL, KurtsHouse_EventScript_KurtThanks
	goto KurtsHouse_EventScript_KurtApricornCheck
	end

KurtsHouse_EventScript_KurtThanks::
	msgbox KurtsHouse_Text_KurtHonored, MSGBOX_DEFAULT
	giveitem ITEM_LURE_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_J_KURT_LURE_BALL
	goto KurtsHouse_EventScript_KurtApricornCheck
	end

@ ============================================================================
@ The apricorn exchange.
@
@ GSC picks the apricorn through a `SelectApricornForKurt` special that has no
@ pokeemerald equivalent, so this is a fixed-order checkitem chain instead, and
@ GSC's one-day wait is dropped (the brief asks for no timers; GSC's own text
@ has the granddaughter speeding him up, which carries it).
@ Colour -> ball is GSC's mapping:
@   RED -> LEVEL   BLUE -> LURE    YELLOW -> MOON   GREEN -> FRIEND
@   PINK -> LOVE   WHITE -> FAST   BLACK -> HEAVY
@ All seven balls are fully implemented in this build (every catch modifier is
@ live in Cmd_handleballthrow), so nothing here is cosmetic.
@ ============================================================================
KurtsHouse_EventScript_KurtApricornCheck::
	checkitem ITEM_RED_APRICORN
	goto_if_eq VAR_RESULT, TRUE, KurtsHouse_EventScript_TradeRed
	checkitem ITEM_BLUE_APRICORN
	goto_if_eq VAR_RESULT, TRUE, KurtsHouse_EventScript_TradeBlue
	checkitem ITEM_YELLOW_APRICORN
	goto_if_eq VAR_RESULT, TRUE, KurtsHouse_EventScript_TradeYellow
	checkitem ITEM_GREEN_APRICORN
	goto_if_eq VAR_RESULT, TRUE, KurtsHouse_EventScript_TradeGreen
	checkitem ITEM_PINK_APRICORN
	goto_if_eq VAR_RESULT, TRUE, KurtsHouse_EventScript_TradePink
	checkitem ITEM_WHITE_APRICORN
	goto_if_eq VAR_RESULT, TRUE, KurtsHouse_EventScript_TradeWhite
	checkitem ITEM_BLACK_APRICORN
	goto_if_eq VAR_RESULT, TRUE, KurtsHouse_EventScript_TradeBlack
	@ Fix round 1 (review M2): the GS_BALL flag alone only implies arc>=3
	@ (set alongside `setvar VAR_TRINITY_KANTO_ARC, 3` in
	@ RocketHideout_B4F_EventScript_Evidence), but CELEBI's own visibility
	@ at the shrine requires arc>=6 (IlexForest/scripts.inc). Without this
	@ guard, Kurt would point the player at the shrine for the whole of arcs
	@ 3-5, where nothing is there yet -- a live dangling quest thread. Added
	@ ahead of the GS-Ball branch so the pointer only fires once the shrine
	@ can actually pay off.
	goto_if_lt VAR_TRINITY_KANTO_ARC, 6, KurtsHouse_EventScript_KurtNoApricorns
	goto_if_unset FLAG_TRINITY_K_GS_BALL, KurtsHouse_EventScript_KurtNoApricorns
	goto_if_set FLAG_TRINITY_J_CELEBI_RESOLVED, KurtsHouse_EventScript_KurtNoApricorns
	msgbox KurtsHouse_Text_KurtGSBall, MSGBOX_DEFAULT
	release
	end

KurtsHouse_EventScript_KurtNoApricorns::
	msgbox KurtsHouse_Text_KurtBallsFromApricorns, MSGBOX_DEFAULT
	release
	end

@ S13b: flavour-only, no new persistent state (FLAG_TRINITY_K_GS_BALL
@ already exists, S6; FLAG_TRINITY_J_CELEBI_RESOLVED gates it back off once
@ the shrine encounter resolves, IlexForest/scripts.inc). Idempotent,
@ replayable -- points the player at the shrine without promising anything
@ the text can't back up. FIX ROUND 1 (review M1): "again"/"still" were
@ dropped -- both presupposed a prior Kurt/GS-Ball scene that never
@ happened (a tree-wide grep for "GS BALL" returns only the Kanto pickup
@ itself and this pair of new files); this is genuinely the player's first
@ time showing Kurt the ball.
KurtsHouse_Text_KurtGSBall:
	.string "That GS BALL you're carrying…\p"
	.string "I can't open it. But if it's meant\n"
	.string "for anyone, it's whatever stands\lat the ILEX FOREST shrine.\p"
	.string "Try there.$"

KurtsHouse_EventScript_TradeRed::
	setvar VAR_0x8008, ITEM_RED_APRICORN
	setvar VAR_0x8009, ITEM_LEVEL_BALL
	goto KurtsHouse_EventScript_TryTradeApricorn
	end

KurtsHouse_EventScript_TradeBlue::
	setvar VAR_0x8008, ITEM_BLUE_APRICORN
	setvar VAR_0x8009, ITEM_LURE_BALL
	goto KurtsHouse_EventScript_TryTradeApricorn
	end

KurtsHouse_EventScript_TradeYellow::
	setvar VAR_0x8008, ITEM_YELLOW_APRICORN
	setvar VAR_0x8009, ITEM_MOON_BALL
	goto KurtsHouse_EventScript_TryTradeApricorn
	end

KurtsHouse_EventScript_TradeGreen::
	setvar VAR_0x8008, ITEM_GREEN_APRICORN
	setvar VAR_0x8009, ITEM_FRIEND_BALL
	goto KurtsHouse_EventScript_TryTradeApricorn
	end

KurtsHouse_EventScript_TradePink::
	setvar VAR_0x8008, ITEM_PINK_APRICORN
	setvar VAR_0x8009, ITEM_LOVE_BALL
	goto KurtsHouse_EventScript_TryTradeApricorn
	end

KurtsHouse_EventScript_TradeWhite::
	setvar VAR_0x8008, ITEM_WHITE_APRICORN
	setvar VAR_0x8009, ITEM_FAST_BALL
	goto KurtsHouse_EventScript_TryTradeApricorn
	end

KurtsHouse_EventScript_TradeBlack::
	setvar VAR_0x8008, ITEM_BLACK_APRICORN
	setvar VAR_0x8009, ITEM_HEAVY_BALL
	goto KurtsHouse_EventScript_TryTradeApricorn
	end

@ Shape copied from the vanilla shard-for-stone trader
@ (Route124_DivingTreasureHuntersHouse_EventScript_TryTradeShard), which is the
@ same 1-for-1, VAR_0x8008/VAR_0x8009-parameterised exchange.
@ The `checkitem VAR_0x8008, 2` line is the load-bearing part: if the bag is
@ full but the player holds exactly ONE of the input item, handing it over frees
@ the slot the ball needs, so the trade is still allowed. removeitem therefore
@ only ever runs once space has been proven -- an apricorn can never be consumed
@ without a BALL coming back.
KurtsHouse_EventScript_TryTradeApricorn::
	bufferitemname STR_VAR_1, VAR_0x8008
	bufferitemname STR_VAR_2, VAR_0x8009
	msgbox KurtsHouse_Text_KurtOfferTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, KurtsHouse_EventScript_TradeDeclined
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, TRUE, KurtsHouse_EventScript_DoTradeApricorn
	checkitem VAR_0x8008, 2
	goto_if_eq VAR_RESULT, FALSE, KurtsHouse_EventScript_DoTradeApricorn
	goto Common_EventScript_ShowBagIsFull
	end

KurtsHouse_EventScript_DoTradeApricorn::
	removeitem VAR_0x8008
	giveitem VAR_0x8009
	msgbox KurtsHouse_Text_KurtTurnedOutGreat, MSGBOX_DEFAULT
	release
	end

KurtsHouse_EventScript_TradeDeclined::
	msgbox KurtsHouse_Text_KurtLetdown, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ GSC KurtsGranddaughter1 -- three states, collapsed to the two that matter in
@ Act II: SLOWPOKE gone / SLOWPOKE back.
@ ============================================================================
KurtsHouse_EventScript_Granddaughter::
	lock
	faceplayer
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 3, KurtsHouse_EventScript_GranddaughterAfter
	msgbox KurtsHouse_Text_GranddaughterBefore, MSGBOX_DEFAULT
	release
	end

KurtsHouse_EventScript_GranddaughterAfter::
	msgbox KurtsHouse_Text_GranddaughterAfter, MSGBOX_DEFAULT
	release
	end

KurtsHouse_EventScript_Slowpoke::
	lock
	msgbox KurtsHouse_Text_Slowpoke, MSGBOX_DEFAULT
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
	waitmoncry
	release
	end

KurtsHouse_EventScript_OakPhoto::
	msgbox KurtsHouse_Text_OakPhoto, MSGBOX_SIGN
	end

KurtsHouse_EventScript_OakPhoto_2::
	msgbox KurtsHouse_Text_OakPhoto_2, MSGBOX_SIGN
	end

KurtsHouse_EventScript_CelebiStatue::
	msgbox KurtsHouse_Text_CelebiStatue, MSGBOX_SIGN
	end

@ ============================================================================
@ Text
@ ============================================================================
@ GSC KurtsHouseKurtHonoredToMakeBallsText.
KurtsHouse_Text_KurtHonored:
	.string "KURT: There you are.\p"
	.string "You handled yourself like a real\n"
	.string "hero down that WELL, and I'm the\l"
	.string "one who ought to have done it.\p"
	.string "I like your style anyway.\p"
	.string "I'd be honoured to make BALLS\n"
	.string "for a trainer like you.\p"
	.string "This one's already on the bench.\n"
	.string "Take it.$"

@ GSC KurtsHouseKurtBallsFromApricornsText.
KurtsHouse_Text_KurtBallsFromApricorns:
	.string "KURT: I make BALLS out of\n"
	.string "APRICORNS.\p"
	.string "Not the factory kind. You pick\n"
	.string "the fruit, I hollow it, and what\l"
	.string "comes out does one thing better\l"
	.string "than anything in a MART.\p"
	.string "Bring me one and I'll show you.\p"
	.string "There's a tree at the north end\n"
	.string "of town, for a start.$"

@ GSC KurtsHouseKurtAskYouHaveAnApricornText.
KurtsHouse_Text_KurtOfferTrade:
	.string "KURT: That's a {STR_VAR_1}.\p"
	.string "Give it here and I'll turn it\n"
	.string "into a {STR_VAR_2}.\p"
	.string "Well?$"

@ GSC KurtsHouseKurtTurnedOutGreatText. GSC makes you wait a day; the
@ granddaughter's help is why this one doesn't.
KurtsHouse_Text_KurtTurnedOutGreat:
	.string "KURT: …There.\p"
	.string "That turned out great.\p"
	.string "My granddaughter does the sand-\n"
	.string "ing now. We work fast.\p"
	.string "Go and catch something with it.$"

@ GSC KurtsHouseKurtThatsALetdownText.
KurtsHouse_Text_KurtLetdown:
	.string "KURT: Oh.\n"
	.string "That's a letdown.$"

@ Adapts GSC KurtsGranddaughterSlowpokeGoneText + the "Grandpa's gone" line.
KurtsHouse_Text_GranddaughterBefore:
	.string "The SLOWPOKE are gone. Were they\n"
	.string "taken away by bad people?\p"
	.string "Grandpa got his coat and went\n"
	.string "down to the WELL to shout at\l"
	.string "them.\p"
	.string "That was a while ago now.$"

@ GSC KurtsGranddaughterSlowpokeBackText + KurtsGranddaughterHelpText.
KurtsHouse_Text_GranddaughterAfter:
	.string "The SLOWPOKE my dad gave me came\n"
	.string "back! Its TAIL is growing in\l"
	.string "again too.\p"
	.string "And I get to help Grandpa now.\p"
	.string "We'll make good BALLS for you,\n"
	.string "so bring him lots of APRICORNS!$"

KurtsHouse_Text_Slowpoke:
	.string "SLOWPOKE: …\n"
	.string "Yawn?$"

KurtsHouse_Text_OakPhoto:
	.string "…A young PROF.\nOAK?$"

KurtsHouse_Text_OakPhoto_2:
	.string "…A young PROF.\nOAK?$"

KurtsHouse_Text_CelebiStatue:
	.string "It's a statue of\nthe forest's pro-\ltector.$"
