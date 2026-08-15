GoldenrodUnderground_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S4 -- the UNDERGROUND, pre-arc state.
@
@ The four merchant/barber NPCs sit on GSC's tiles: (7,11) (7,14) (7,15)
@ (7,21). Each is collision 0 elevation 3 but UNREACHABLE on foot with zero
@ objects placed -- they are booths behind the west wall -- and each is fronted
@ by an MB_COUNTER tile at (6,y), served from (5,y)
@ (GetInteractedObjectEventScript -> MetatileBehavior_IsCounter -> look one
@ tile further, src/field_control_avatar.c:387-396). Objects on
@ already-unreachable tiles cost exactly zero walkability.
@
@ GSC gates all four behind VAR_WEEKDAY and the clock
@ (GoldenrodUnderground.asm:56-...). Trinity ports no day-of-week system, so
@ they simply stand their booths.
@
@ FLAVOUR ONLY, deliberately. The HAIRCUT BROTHERS' 500/300 friendship
@ service and the two merchants' priced stock are systems, and a "bargain"
@ price cannot even be expressed -- pokemart has no per-shop pricing
@ (GetItemPrice reads the global gItemsInfo entry). Logged as skips.
@
@ THE SWITCH DOORS STAY CLOSED. S4 adds no switch, no changeblock, no CARD KEY
@ and no BASEMENT KEY. This map's east branch stays exactly as shipped:
@ reachable only through GOLDENROD UNDERGROUND SWITCH ROOM ENTRANCES. That
@ two-component split is pre-existing and object-independent.
@ ============================================================================

GoldenrodUnderground_EventScript_BargainMerchant::
	msgbox GoldenrodUnderground_Text_BargainMerchant, MSGBOX_NPC
	end

GoldenrodUnderground_EventScript_OlderHaircutBrother::
	msgbox GoldenrodUnderground_Text_OlderHaircutBrother, MSGBOX_NPC
	end

GoldenrodUnderground_EventScript_YoungerHaircutBrother::
	msgbox GoldenrodUnderground_Text_YoungerHaircutBrother, MSGBOX_NPC
	end

GoldenrodUnderground_EventScript_HerbGranny::
	msgbox GoldenrodUnderground_Text_HerbGranny, MSGBOX_NPC
	end

GoldenrodUnderground_EventScript_ERIC::
	trainerbattle_single TRAINER_JOHTO_SUPER_NERD_ERIC, GoldenrodUnderground_Text_ERICSeen, GoldenrodUnderground_Text_ERICBeaten
	msgbox GoldenrodUnderground_Text_ERICBeaten, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_TERU::
	trainerbattle_single TRAINER_JOHTO_SUPER_NERD_TERU, GoldenrodUnderground_Text_TERUSeen, GoldenrodUnderground_Text_TERUBeaten
	msgbox GoldenrodUnderground_Text_TERUBeaten, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_ISSAC::
	trainerbattle_single TRAINER_JOHTO_POKEMANIAC_ISSAC, GoldenrodUnderground_Text_ISSACSeen, GoldenrodUnderground_Text_ISSACBeaten
	msgbox GoldenrodUnderground_Text_ISSACBeaten, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_DONALD::
	trainerbattle_single TRAINER_JOHTO_POKEMANIAC_DONALD, GoldenrodUnderground_Text_DONALDSeen, GoldenrodUnderground_Text_DONALDBeaten
	msgbox GoldenrodUnderground_Text_DONALDBeaten, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_NoEntrySign::
	msgbox GoldenrodUnderground_Text_NoEntrySign, MSGBOX_SIGN
	end

@ Adapts GSC's BargainMerchantScript patter (he is the man who shouts about
@ what his stock would cost you upstairs).
GoldenrodUnderground_Text_BargainMerchant:
	.string "Step up! Bargains! Real ones!\p"
	.string "Everything on this counter is\n"
	.string "cheaper than the DEPT.STORE.\p"
	.string "Ah. Not today, sadly. Today the\n"
	.string "counter is empty and I am\l"
	.string "shouting out of habit.\p"
	.string "Come back. I'm always here.\n"
	.string "That's the whole business.$"

@ Adapts GoldenrodUndergroundOlderHaircutBrotherOfferHaircutText.
GoldenrodUnderground_Text_OlderHaircutBrother:
	.string "Welcome! I run the POKéMON\n"
	.string "SALON!\p"
	.string "I'm the older and better of the\n"
	.string "two HAIRCUT BROTHERS.\p"
	.string "I can make your POKéMON\n"
	.string "beautiful. Beautiful POKéMON\l"
	.string "like their trainers more. It's\l"
	.string "science.\p"
	.string "…Chair's full today. Look at\n"
	.string "him. He's been in it an hour.$"

GoldenrodUnderground_Text_YoungerHaircutBrother:
	.string "Don't listen to my brother.\p"
	.string "He charges more and he takes\n"
	.string "longer and the POKéMON come out\l"
	.string "the same.\p"
	.string "I'm cheaper and I'm faster.\p"
	.string "…He's better. But I'm cheaper\n"
	.string "and I'm faster.$"

@ Adapts BitterMerchantScript -- GSC's herb granny, whose stock is famously
@ effective and famously unpleasant.
GoldenrodUnderground_Text_HerbGranny:
	.string "Herbs, dear. Bitter ones.\p"
	.string "They work better than anything\n"
	.string "in a shiny wrapper upstairs,\l"
	.string "and every POKéMON that has ever\l"
	.string "tasted one has held it against\l"
	.string "its trainer.\p"
	.string "That's the trade. Nobody likes\n"
	.string "it. It's still the trade.$"

GoldenrodUnderground_Text_ERICSeen:
	.string "I got booted out\nof the GAME COR-\lNER.\pI was trying to\ncheat using my\lPOKéMON…$"

GoldenrodUnderground_Text_ERICBeaten:
	.string "…Grumble…$"

GoldenrodUnderground_Text_TERUSeen:
	.string "Do you consider\ntype alignments in\lbattle?\pIf you know your\ntype advantages,\pyou'll do better\nin battle.$"

GoldenrodUnderground_Text_TERUBeaten:
	.string "Ow, ow, ow!$"

GoldenrodUnderground_Text_ISSACSeen:
	.string "My POKéMON just\ngot a haircut!\pI'll show you how\nstrong it is!$"

GoldenrodUnderground_Text_ISSACBeaten:
	.string "Aiyeeee!$"

GoldenrodUnderground_Text_DONALDSeen:
	.string "I think you have\nsome rare POKéMON\lwith you.\pLet me see them!$"

GoldenrodUnderground_Text_DONALDBeaten:
	.string "Gaah! I lost!\nThat makes me mad!$"

GoldenrodUnderground_Text_NoEntrySign:
	.string "NO ENTRY BEYOND\nTHIS POINT$"
