CianwoodPharmacy_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S6 -- CIANWOOD PHARMACY. Adapts pokecrystal CianwoodPharmacist
@ (maps/CianwoodPharmacy.asm).
@
@ THE SECRETPOTION IS A FLAG, NOT AN ITEM. ITEM_SECRET_POTION does not exist in
@ this build (verified: no reference anywhere in include/, src/ or data/), and
@ none of the neighbouring key items is free to repurpose, so the errand is
@ carried by FLAG_TRINITY_J_SECRET_POTION -- the same call S1 made when
@ ITEM_RED_SCALE turned out to be absent. Consequences, all handled:
@   * The beat still READS as a pickup: playfanfare MUS_OBTAIN_ITEM plus a
@     "{PLAYER} received the SECRETPOTION." line.
@   * There is no bag-full branch to guard, because there is no giveitem. That
@     is why this flag is NOT shaped like a GYM PATTERN G2 award guard -- G2
@     exists for giveitem's VAR_RESULT == FALSE path, which cannot occur here.
@   * Discoverability, the real risk of a bag-less key item, is covered by
@     naming it at three sites: here, JASMINE's request, and her delivery prompt.
@ If a later balance pass ever adds a JOHTO key-item block, this converts to
@ giveitem / checkitem / removeitem with no structural change.
@
@ GUARDS, MOST-ADVANCED-FIRST -- and the FIRST one is load-bearing.
@   AMPHY already cured  -> shop
@   already carrying it  -> shop
@   not yet asked        -> shop
@ The cured guard is not decoration. JASMINE CLEARS _SECRET_POTION when she
@ takes it, and _JASMINE_ASKED stays set forever, so after the cure the middle
@ two guards are both false again and without the first one this script would
@ hand out a SECOND SECRETPOTION for a POKéMON that is already well -- and set a
@ flag JASMINE is no longer on the map to clear, stranding it set for the rest
@ of the save. That is the cost of a possession flag that gets cleared: the
@ chain's terminal state has to be tested explicitly, because the intermediate
@ flags return to their starting values. So the map is never a dead end AND the
@ give beat runs exactly once per save.
@
@ DECODE: the PHARMACIST stays on GSC's (2,3) -- MB_NORMAL, collision 0,
@ elevation 3 -- served from (2,2) facing down, (1,3) facing right or (2,4)
@ facing up. Three approach tiles, so no seal is possible.
@ ============================================================================
CianwoodPharmacy_EventScript_CianwoodPharmacist::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_AMPHY_CURED, CianwoodPharmacy_EventScript_Shop
	goto_if_set FLAG_TRINITY_J_SECRET_POTION, CianwoodPharmacy_EventScript_Shop
	goto_if_unset FLAG_TRINITY_J_JASMINE_ASKED, CianwoodPharmacy_EventScript_Shop
	msgbox CianwoodPharmacy_Text_GiveSecretPotion, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox CianwoodPharmacy_Text_ReceivedSecretPotion, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_J_SECRET_POTION
	msgbox CianwoodPharmacy_Text_DescribeSecretPotion, MSGBOX_DEFAULT
	release
	end

@ GSC's `pokemart MARTTYPE_PHARMACY, MART_CIANWOOD`
@ (pokecrystal/data/items/marts.asm:84-91), item for item and order for order.
@ PRICES NEED NO WORK AND MUST NOT BE TOUCHED: pokemart has no per-shop
@ override, GetItemPrice reads gItemsInfo[item].price, so the shelf carries M1's
@ prices by construction (S4's Emporium lesson).
CianwoodPharmacy_EventScript_Shop::
	msgbox CianwoodPharmacy_Text_Welcome, MSGBOX_DEFAULT
	message gText_HowMayIServeYou
	waitmessage
	pokemart CianwoodPharmacy_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
CianwoodPharmacy_Pokemart:
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	pokemartlistend

@ ============================================================================
@ Text -- adapts PharmacistGiveSecretpotionText, ReceivedSecretpotionText and
@ PharmacistDescribeSecretpotionText.
@ ============================================================================
CianwoodPharmacy_Text_Welcome:
	.string "Five hundred years my family has\n"
	.string "mixed remedies in this room.\p"
	.string "Nothing fancy. Things that work.$"

CianwoodPharmacy_Text_GiveSecretPotion:
	.string "Your POKéMON all appear to be fine.\p"
	.string "Is something worrying you?\p"
	.string "…\p"
	.string "The LIGHTHOUSE POKéMON. Over in\n"
	.string "OLIVINE. That one.\p"
	.string "I know exactly what you need.$"

CianwoodPharmacy_Text_ReceivedSecretPotion:
	.string "{PLAYER} received the SECRETPOTION.$"

CianwoodPharmacy_Text_DescribeSecretPotion:
	.string "My SECRETPOTION is a tad too strong.\n"
	.string "I only hand it out in an emergency.\p"
	.string "Take it straight back across the\n"
	.string "water. Don't stop to battle.\p"
	.string "…Well. Don't stop for LONG.$"
