SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_MrMargins::
	lock
	faceplayer
	msgbox SlateportCity_House_Text_MarginsWelcome, MSGBOX_DEFAULT
SlateportCity_House_EventScript_MarginsMenu::
	msgbox SlateportCity_House_Text_OfferTradeQ, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_House_EventScript_MarginsTrade
	special TradeHouse_CheckHeldMon
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_House_EventScript_MarginsOfferCord
	bufferspeciesname STR_VAR_1, VAR_0x8006
	msgbox SlateportCity_House_Text_BuyBackQ, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_House_EventScript_MarginsBuyBack
SlateportCity_House_EventScript_MarginsOfferCord::
	msgbox SlateportCity_House_Text_CordQ, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_House_EventScript_MarginsBuyCord
	msgbox SlateportCity_House_Text_MarginsGoodbye, MSGBOX_DEFAULT
	release
	end

@ ---- Trade ----
SlateportCity_House_EventScript_MarginsTrade::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, SlateportCity_House_EventScript_MarginsOnlyMon
	msgbox SlateportCity_House_Text_WhichWillYouOffer, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChoosePartyMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, SlateportCity_House_EventScript_MarginsTradeCancelled
	special TradeHouse_IsChosenMonEgg
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_House_EventScript_MarginsNoEggs
	special TradeHouse_CheckHeldMon
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_House_EventScript_MarginsDoTrade
	bufferspeciesname STR_VAR_1, VAR_0x8006
	msgbox SlateportCity_House_Text_WarnSellPrevious, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_House_EventScript_MarginsTradeCancelled
	msgbox SlateportCity_House_Text_SoldMargins, MSGBOX_DEFAULT
SlateportCity_House_EventScript_MarginsDoTrade::
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	special TradeHouse_DoTrade
	waitse
	playmoncry VAR_0x8006, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_2, VAR_0x8006
	goto_if_eq VAR_0x8007, 1, SlateportCity_House_EventScript_MarginsJackpot
	msgbox SlateportCity_House_Text_TradeResult, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_House_EventScript_MarginsJackpot::
	msgbox SlateportCity_House_Text_TradeJackpot, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_House_EventScript_MarginsOnlyMon::
	msgbox SlateportCity_House_Text_OnlyMon, MSGBOX_DEFAULT
	release
	end

SlateportCity_House_EventScript_MarginsNoEggs::
	msgbox SlateportCity_House_Text_NoEggs, MSGBOX_DEFAULT
	release
	end

SlateportCity_House_EventScript_MarginsTradeCancelled::
	msgbox SlateportCity_House_Text_TradeCancelled, MSGBOX_DEFAULT
	release
	end

@ ---- Buy-back ----
SlateportCity_House_EventScript_MarginsBuyBack::
	showmoneybox 0, 0
	checkmoney 2000
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_House_EventScript_MarginsNoMoney
	special TradeHouse_BuyBack
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, SlateportCity_House_EventScript_MarginsNoRoom
	removemoney 2000
	updatemoneybox
	bufferspeciesname STR_VAR_1, VAR_0x8006
	waitse
	playmoncry VAR_0x8006, CRY_MODE_NORMAL
	msgbox SlateportCity_House_Text_BuyBackDone, MSGBOX_DEFAULT
	waitmoncry
	hidemoneybox
	release
	end

SlateportCity_House_EventScript_MarginsNoRoom::
	hidemoneybox
	msgbox SlateportCity_House_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

@ ---- Linking Cord ----
SlateportCity_House_EventScript_MarginsBuyCord::
	showmoneybox 0, 0
	checkmoney 8000
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_House_EventScript_MarginsNoMoney
	checkitemspace ITEM_LINKING_CORD
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_House_EventScript_MarginsBagFull
	removemoney 8000
	updatemoneybox
	giveitem ITEM_LINKING_CORD
	msgbox SlateportCity_House_Text_CordThanks, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

SlateportCity_House_EventScript_MarginsBagFull::
	hidemoneybox
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end

SlateportCity_House_EventScript_MarginsNoMoney::
	hidemoneybox
	msgbox SlateportCity_House_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

@ ---- Girl (satisfied customer flavor) ----
SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_HappyCustomer, MSGBOX_NPC
	end

@ ================= TEXT =================
SlateportCity_House_Text_MarginsWelcome:
	.string "OH ho ho ho! Welcome, welcome!\p"
	.string "MR. MARGINS, at your service -- the\n"
	.string "man who lets you UNDO your choices!\p"
	.string "The house always wins, friend, and\n"
	.string "I am a very cheerful house.$"

SlateportCity_House_Text_OfferTradeQ:
	.string "Care to OFFER me a POKéMON?\p"
	.string "I'll hand you one back, chosen\n"
	.string "entirely at random!$"

SlateportCity_House_Text_WhichWillYouOffer:
	.string "Splendid! Which will you part with?$"

SlateportCity_House_Text_WarnSellPrevious:
	.string "Ah, but I'm still holding your\n"
	.string "{STR_VAR_1} for buy-back!\p"
	.string "Trade again and I SELL it -- gone\n"
	.string "for GOOD. Shall we proceed?$"

SlateportCity_House_Text_SoldMargins:
	.string "SOLD! Excellent margins!$"

SlateportCity_House_Text_TradeResult:
	.string "You handed over {STR_VAR_1}...\p"
	.string "and I give you... a {STR_VAR_2}!\p"
	.string "Ho ho! Buy it back for ¥2,000 any\n"
	.string "time. The edge is mine, friend!$"

SlateportCity_House_Text_TradeJackpot:
	.string "You handed over {STR_VAR_1}...\p"
	.string "and -- JACKPOT! A magnificent\n"
	.string "{STR_VAR_2}!!\p"
	.string "Even I feel the sting! Buy your old\n"
	.string "one back for ¥2,000? Ho ho ho!$"

SlateportCity_House_Text_OnlyMon:
	.string "Ho ho, I'm no monster! I won't take\n"
	.string "your very last POKéMON.$"

SlateportCity_House_Text_NoEggs:
	.string "An EGG? I deal in POKéMON, friend,\n"
	.string "not in gambling on the unhatched!$"

SlateportCity_House_Text_TradeCancelled:
	.string "Cold feet? The offer stands, ho ho!$"

SlateportCity_House_Text_BuyBackQ:
	.string "I'm still holding your {STR_VAR_1}!\p"
	.string "Buy it back for a mere ¥2,000?$"

SlateportCity_House_Text_BuyBackDone:
	.string "Here's your {STR_VAR_1}! ¥2,000,\n"
	.string "and I'm ROBBING myself, friend!$"

SlateportCity_House_Text_NoRoom:
	.string "Your party AND your PC are full!\n"
	.string "Nowhere to put it -- come back!$"

SlateportCity_House_Text_CordQ:
	.string "A LINKING CORD, then? For customers\n"
	.string "who don't trust the artisanal\l"
	.string "method. Just ¥8,000!$"

SlateportCity_House_Text_CordThanks:
	.string "A pleasure! Evolve those trade mons\n"
	.string "at your leisure, ho ho!$"

SlateportCity_House_Text_NotEnoughMoney:
	.string "Ho ho... come back when your wallet\n"
	.string "is as fat as I am!$"

SlateportCity_House_Text_MarginsGoodbye:
	.string "Come back soon! Everyone does!$"

SlateportCity_House_Text_HappyCustomer:
	.string "I traded away a scruffy ZIGZAGOON\n"
	.string "and got a DRAGONITE!\p"
	.string "...Then a POOCHYENA. Then I bought\n"
	.string "the ZIGZAGOON back. He's very good.$"
