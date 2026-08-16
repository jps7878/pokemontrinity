@ ============================================================================
@ THE TWO CRATE BLOCKS, decoded from
@ data/layouts/GoldenrodDeptStoreB1F_Johto/map.bin. Converter block map in
@ data/maps/RadioTower3F/scripts.inc.
@   (10,8)(11,8)(10,9)(11,9) = 556/557/558/559, all collision 1
@   (16,4)(17,4)             = 588/589, collision 1
@   (16,5)(17,5)             = 590/591, already collision 0
@ Both become GSC block $0d (underground tileset: FLOOR x4) = 564/565/566/567 --
@ the same block the floor at (12,8) and (9,8) already uses.
	.set METATILE_JohtoUnderground_FloorTL,  564
	.set METATILE_JohtoUnderground_FloorTR,  565
	.set METATILE_JohtoUnderground_FloorBL,  566
	.set METATILE_JohtoUnderground_FloorBR,  567
@ ============================================================================

GoldenrodDeptStoreB1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodDeptStoreB1F_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S8 -- THE CRATE MAZE, and an M4a port fix.
@
@ GSC clears ONE of three crate gaps on every map load and the card-key crate
@ separately (GoldenrodDeptStoreB1F.asm:18-41):
@
@   * (10,8) is the DEFAULT layout gap and is cleared UNCONDITIONALLY -- the
@     LAYOUT_2 / LAYOUT_3 events that would pick a different gap are never set
@     by anything in GSC, so layout 1 is permanent. M4a carried the raw
@     blockdata and dropped the callback, so this gap HAS NEVER EXISTED in
@     Trinity: B1F reads 51 of 189 tiles reachable from the elevator today, with
@     the whole east half and the WAREHOUSE door walled off. Authored open here,
@     always, which is what GSC does.
@   * (16,4) is the CARD KEY crate, `changeblock 16,4,$0d` iff
@     EVENT_RECEIVED_CARD_KEY. It is what turns the WAREHOUSE into a shortcut to
@     the street once the DIRECTOR is free, and it is the only way the
@     ITEM_AMULET_COIN at (14,2) was ever meant to be collected from this side.
@
@ MEASURED with both authored: B1F 110/195 and (17,2) <-> both elevator warps
@ mutually reachable; the whole UNDERGROUND complex reports NO SEALED WARPS.
@
@ D2: the shipped map.bin has both crates PRESENT, so the authoring direction is
@ OPEN for both. D5: whole blocks, four tiles each, y-parity respected.
@ ============================================================================
GoldenrodDeptStoreB1F_OnTransition:
	call GoldenrodDeptStoreB1F_EventScript_AuthorDefaultGap
	call GoldenrodDeptStoreB1F_EventScript_AuthorCardKeyGap
	end

GoldenrodDeptStoreB1F_EventScript_AuthorDefaultGap::
	setmetatile 10, 8, METATILE_JohtoUnderground_FloorTL, FALSE
	setmetatile 11, 8, METATILE_JohtoUnderground_FloorTR, FALSE
	setmetatile 10, 9, METATILE_JohtoUnderground_FloorBL, FALSE
	setmetatile 11, 9, METATILE_JohtoUnderground_FloorBR, FALSE
	return

GoldenrodDeptStoreB1F_EventScript_AuthorCardKeyGap::
	goto_if_unset FLAG_TRINITY_J_CARD_KEY, GoldenrodDeptStoreB1F_EventScript_CratesStay
	setmetatile 16, 4, METATILE_JohtoUnderground_FloorTL, FALSE
	setmetatile 17, 4, METATILE_JohtoUnderground_FloorTR, FALSE
	setmetatile 16, 5, METATILE_JohtoUnderground_FloorBL, FALSE
	setmetatile 17, 5, METATILE_JohtoUnderground_FloorBR, FALSE
GoldenrodDeptStoreB1F_EventScript_CratesStay::
	return

GoldenrodDeptStoreB1F_EventScript_BlackBelt1::
	msgbox GoldenrodDeptStoreB1F_Text_BlackBelt1, MSGBOX_NPC
	end

GoldenrodDeptStoreB1F_EventScript_BlackBelt2::
	msgbox GoldenrodDeptStoreB1F_Text_BlackBelt2, MSGBOX_NPC
	end

GoldenrodDeptStoreB1F_EventScript_BlackBelt3::
	msgbox GoldenrodDeptStoreB1F_Text_BlackBelt3, MSGBOX_NPC
	end

GoldenrodDeptStoreB1F_Text_BlackBelt1:
	.string "Hey, kid! You're\nholding us up!\pOur policy is to\nwork behind the\pscenes where no\none can see us!$"

GoldenrodDeptStoreB1F_Text_BlackBelt2:
	.string "I lose my passion\nfor work if some-\lone's watching.\pCome on, kid,\nscoot!$"

GoldenrodDeptStoreB1F_Text_BlackBelt3:
	.string "Oohah! Oohah!\pThe stuff on the\nground's junk.\pTake it if you\nwant it!$"
