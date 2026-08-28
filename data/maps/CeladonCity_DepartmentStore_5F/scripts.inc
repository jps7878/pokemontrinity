CeladonCity_DepartmentStore_5F_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_5F_EventScript_Gentleman::
	msgbox CeladonCity_DepartmentStore_5F_Text_Gentleman, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_5F_EventScript_Sailor::
	msgbox CeladonCity_DepartmentStore_5F_Text_Sailor, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_5F_EventScript_ClerkXItems::
	msgbox CeladonCity_DepartmentStore_5F_Text_ClerkXItems, MSGBOX_NPC
	end

@ ============================================================================
@ Trinity M5b S6 -- MARGINS AND CO. PREMIUM, the CELADON branch. Third
@ mirror of LilycoveCity_DepartmentStore_5F_EventScript_MarginsClerk/
@ _Pokemart_MarginsPremium, item for item and order for order -- the SAME
@ list M4b S4 already mirrored once for GoldenrodDeptStore5F. Prices need no
@ work and must not be touched: pokemart has no per-shop price override,
@ GetItemPrice reads gItemsInfo[item].price globally (src/item.c). T10's own
@ "Vitamins" clerk here is retired into MARGINS -- her old job (selling the
@ 4 individual vitamins) is now fully subsumed by the Premium shelf's own
@ 6-vitamin stock, so converting her avoids a redundant object.
@ ============================================================================
CeladonCity_DepartmentStore_5F_EventScript_ClerkVitamins::
	lock
	faceplayer
	msgbox CeladonCity_DepartmentStore_5F_Text_MarginsWelcome, MSGBOX_DEFAULT
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_5F_Pokemart_MarginsPremium
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
CeladonCity_DepartmentStore_5F_Pokemart_MarginsPremium:
	.2byte ITEM_RARE_CANDY
	.2byte ITEM_MASTER_BALL
	.2byte ITEM_PP_MAX
	.2byte ITEM_HP_UP
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CALCIUM
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HEART_SCALE
	.2byte ITEM_ABILITY_CAPSULE
	pokemartlistend

CeladonCity_DepartmentStore_5F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_5F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_5F_Text_Gentleman:
	.string "POKéMON stat enhancers can be\nbought only here.\pHP UP increases the base HP of a\nPOKéMON.\pCALCIUM raises the base SP. ATK\nstat of one POKéMON.\pZINC boosts the base SP. DEF stat\nof one POKéMON.\pCARBOS enhances the base SPEED\nstat.$"

CeladonCity_DepartmentStore_5F_Text_Sailor:
	.string "I'm here for POKéMON stat\nenhancers.\pPROTEIN increases the base ATTACK\npower.\pIRON increases the base DEFENSE\nstat.$"

CeladonCity_DepartmentStore_5F_Text_ClerkXItems:
	.string "X ITEMS wear off after one battle.\nStock up before a big fight, not\lafter.$"

@ The M1 Mr. Margins voice: booming, delighted, entirely unembarrassed
@ about the markup. Celadon is the THIRD branch (Lilycove, then Goldenrod,
@ now here) -- framed the same way GoldenrodDeptStore5F's own text frames
@ itself as the second.
CeladonCity_DepartmentStore_5F_Text_MarginsWelcome:
	.string "OH ho ho! MARGINS and CO.\n"
	.string "PREMIUM -- CELADON branch!\p"
	.string "Same shelf as LILYCOVE. Same\n"
	.string "shelf as GOLDENROD. Same\l"
	.string "beautiful, beautiful prices.\p"
	.string "Three branches now. People keep\n"
	.string "asking when I'll slow down.\p"
	.string "Anything a champion could want\n"
	.string "-- for the right price!$"

CeladonCity_DepartmentStore_5F_Text_FloorSign:
	.string "5F: DRUGSTORE$"
