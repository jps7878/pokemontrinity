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
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodDeptStoreB1F_OnLoad
	.byte 0

@ ============================================================================
@ Trinity M4b S8 -- THE CRATE MAZE, and an M4a port fix.
@
@ GSC clears ONE of three crate gaps on every map load and the card-key crate
@ separately (GoldenrodDeptStoreB1F.asm:18-41). Trinity pins the choice of gap;
@ see below.
@
@   * (10,8) is LAYOUT 1's gap. GSC ROTATES the layout -- GoldenrodDeptStoreElevator
@     .asm:17-38 advances LAYOUT_1 -> 2 -> 3 on every elevator ride, and
@     GoldenrodUndergroundWarehouse.asm:78-80 resets it to LAYOUT 1 at the CARD KEY
@     handover -- so the gap MOVES between (10,8), (4,10) and (10,12) as the player
@     uses the lift. TRINITY DELIBERATELY SIMPLIFIES THIS: we pin LAYOUT 1 and
@     author (10,8) open on every load, permanently.
@     WHY: the rotation is a flavour system, not a story beat (its own state is
@     three mutually-exclusive events driven from a THIRD map), and pinning it
@     costs nothing the chapter needs -- GSC itself resets to exactly this layout
@     the moment the CARD KEY changes hands, which is the only moment this slice
@     cares about. Logged as a simplification in the slice plan and report, not as
@     a port of GSC's behaviour.
@     WHAT IS A REAL PORT FIX: M4a carried the raw blockdata and dropped the
@     callback ENTIRELY, so NO gap has ever existed in Trinity -- B1F reads 51 of
@     189 tiles reachable from the elevator in the shipped ROM, with the whole east
@     half and the WAREHOUSE door walled off. One of the three gaps has to be open
@     at all times for the floor to work at all, and this is that fix.
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
@ D2 SLOT NOTE (M4b S9 fix round -- systemic, applied to all eight Trinity
@ metatile authors). Metatile authoring MUST live in MAP_SCRIPT_ON_LOAD, never
@ MAP_SCRIPT_ON_TRANSITION. RunOnTransitionMapScript() runs IMMEDIATELY BEFORE
@ InitMap() on both map-load paths (src/overworld.c:876-877, :945-954), and
@ InitMap -> InitMapLayoutData (src/fieldmap.c:96-103) CpuFastFill16s the whole
@ backup grid to MAPGRID_UNDEFINED and CpuCopy16s the ROM layout back over it --
@ so a setmetatile issued from ON_TRANSITION is erased before a single frame is
@ drawn. ON_LOAD is the LAST statement of InitMap (src/fieldmap.c:71), i.e. it
@ runs once the grid exists, AND of InitMapFromSavedGame (:80), so it also
@ covers continue-from-save, which ON_TRANSITION never runs on at all. Vanilla's
@ own metatile authors use exactly this slot (MauvilleCity_Gym, ShoalCave_*,
@ SootopolisCity_Gym_1F, AncientTomb). Still no DrawWholeMapView needed:
@ InitViewGraphics -> InitMapView -> DrawWholeMapView (src/overworld.c:575-580,
@ :2368) runs later in the same load. qa_sweep.py check 7 is the regression gate.
GoldenrodDeptStoreB1F_OnLoad:
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
