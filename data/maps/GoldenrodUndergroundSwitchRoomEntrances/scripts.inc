GoldenrodUndergroundSwitchRoomEntrances_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodUndergroundSwitchRoomEntrances_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodUndergroundSwitchRoomEntrances_OnLoad
	.byte 0

@ ============================================================================
@ Trinity M4b S8 -- THE GOLDENROD UNDERGROUND SWITCH ROOMS. Adapts pokecrystal
@ maps/GoldenrodUndergroundSwitchRoomEntrances.asm.
@
@ ---- THE PUZZLE -----------------------------------------------------------
@
@ Three switches and eleven doors. GSC computes a POSITION from the switches --
@ position = 1*S1 + 2*S2 + 3*S3, range 0..6 -- and the position decides which
@ doors move (…UpdateDoors, :346-460). Doors 1-6 are STICKY: a position opens
@ the ONE door it names and shuts the ONE it names (position N shuts door 7-N)
@ and leaves the other four alone, so their state is HISTORY. Doors 7-11 are a
@ PURE FUNCTION of the position and therefore carry no saved state at all:
@
@   doors 7 and 10  open on ODD positions           (1, 3, 5)
@   doors 8 and 9   open on EVEN NON-ZERO positions (2, 4, 6)
@   door 11         opens ONLY at position 6
@   position 0      shuts all eleven
@
@ ---- THE MAP ---------------------------------------------------------------
@
@ Top corridor (rows 2-5, the three switches on the wall at y=1) sits above
@ three vertical shafts, each split into an upper half (rows 8-9) and a lower
@ half (rows 12-13):
@
@   door 3 (2,6)   corridor <-> shaft 1 upper      door 8  (6,8)   shaft 1<->2 upper
@   door 2 (10,6)  corridor <-> shaft 2 upper      door 7  (12,8)  shaft 2<->3 upper
@   door 1 (16,6)  corridor <-> shaft 3 upper      door 10 (6,12)  shaft 1<->2 lower
@   door 4 (2,10)  shaft 1 upper <-> lower         door 9  (12,12) shaft 2<->3 lower
@   door 5 (10,10) shaft 2 upper <-> lower         door 11 (18,12) shaft 3 lower
@   door 6 (16,10) shaft 3 upper <-> lower                         <-> the WAREHOUSE
@                                                                     antechamber
@
@ ---- WHY IT IS A PUZZLE ----------------------------------------------------
@
@ Door 11 needs position 6, and position 6 SHUTS door 1, so the descent has to
@ come from a sticky door 2 or 3 opened earlier. Doors 2 and 5 are mutually
@ exclusive (position 2 shuts 5, position 5 shuts 2), so the surviving chain is
@ 3 and 5:
@
@   P3 (S3 on)       opens door 3
@   P5 (S3+S2 on)    opens door 5   -- and does not touch 3
@   P6 (all three)   opens 6, 8, 9, 11 -- and shuts only door 1
@
@   route: corridor --3--> shaft1 upper --8--> shaft2 upper --5--> shaft2 lower
@                    --9--> shaft3 lower --11--> antechamber -> WAREHOUSE
@
@ The EMERGENCY panel at (20,11) is INSIDE the antechamber and forces exactly
@ that configuration -- it is GSC's "let me back out" button, which is why it is
@ on the far side of the maze.
@
@ MEASURED, with those eighteen collision-carrying tiles opened
@ (reach_check --dungeon over UNDERGROUND + SWITCH ROOMS + WAREHOUSE +
@ DEPT. STORE B1F): 779 of 896 tiles from all six outward doors, NO SEALED
@ WARPS. Shaft 1 LOWER (x 0..5, y 12..13, holding the SMOKE BALL ball at (1,12))
@ stays shut in this configuration because door 4 is shut -- it is reachable in
@ any position that opens door 4, and it is optional either way. Disclosed, not
@ sealed.
@
@ ---- IMPLEMENTATION --------------------------------------------------------
@
@ ONE routine, GoldenrodUndergroundSwitchRoomEntrances_EventScript_AuthorDoors, authors ALL ELEVEN doors in
@ BOTH directions from state, and both the ON_TRANSITION and the switch scripts
@ call it. That deliberately sidesteps the SETMETATILE DOOR PATTERN's D2
@ direction question (re-authoring a shut door shut is a no-op setmetatile) and
@ leaves exactly one place where a door's tiles are written. The switch path
@ adds playse SE_DOOR and `special DrawWholeMapView` (D3); the ON_LOAD author needs
@ neither. D4: each sticky door's flag is its ONLY state, and the switch flags
@ are inputs.
@
@ Metatiles come from the converter's block map (full statement in
@ data/maps/RadioTower3F/scripts.inc): 512 + 4*<GSC block> + q, q order
@ TL/TR/BL/BR, collision from pokecrystal's elite_four_room_collision.asm.
@   $3e 760-763 WALL x4          shut, doors 1-6
@   $2d 692-695 FLOOR x4         open, doors 1-6 and the lower half of 7-11
@   $3f 764-767 WALL x4          shut, the UPPER half of doors 7-11
@   $2a 680-683 WALL x4          open, the UPPER half of doors 7-11 -- ART ONLY,
@                                the collision never changes there
@   $3d 756-759 WALL FLOOR WALL FLOOR   shut, the lower half of doors 7-11
@ Every one of these tiles decodes elevation 0 = ELEVATION_TRANSITION, which
@ IsElevationMismatchAt always accepts, so an opened tile is walkable with no
@ elevation work (setmetatile never touches elevation anyway).
@
@ ---- DELIBERATE SKIP, LOGGED -----------------------------------------------
@
@ GSC resets every switch and door in a MAPCALLBACK_NEWMAP on GOLDENROD
@ UNDERGROUND and on the WAREHOUSE (GoldenrodUnderground.asm:22-40), because its
@ position byte lives in unsaved WRAM. Ours are flags, so the state is coherent
@ across saves and a solved maze STAYS SOLVED. That is strictly better and it
@ cannot strand anyone: the three switches are all in the top corridor, the
@ emergency panel is in the antechamber, and the antechamber always holds the
@ two WAREHOUSE warps, whose far side exits to the DEPT. STORE.
@
@ GSC's two BURGLARs (DUNCAN, EDDIE) are also skipped -- they are not ROCKETS,
@ and the slice's 22-post trainer-id budget buys four Rocket posts here instead.
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
GoldenrodUndergroundSwitchRoomEntrances_OnLoad:
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_AuthorDoors
	end

GoldenrodUndergroundSwitchRoomEntrances_OnTransition:
	setflag FLAG_TRINITY_J_UG_SILVER_HIDE
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_SetRocketVisibility
	end

@ R1: one flag, one authoring site, and NOTHING on it is ever removeobject'd
@ (it is shared with the WAREHOUSE's three posts, and a co-sign would delete
@ them from another map -- S7's cross-map corollary).
GoldenrodUndergroundSwitchRoomEntrances_EventScript_SetRocketVisibility::
	goto_if_ne VAR_TRINITY_JOHTO_ARC, 6, GoldenrodUndergroundSwitchRoomEntrances_EventScript_HideRockets
	clearflag FLAG_TRINITY_J_UNDERGROUND_ROCKETS_HIDE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_HideRockets::
	setflag FLAG_TRINITY_J_UNDERGROUND_ROCKETS_HIDE
	return

@ ============================================================================
@ C-COUNT's sibling: the switch position, computed rather than stored.
@ VAR_TEMP_A for the same reasons (see data/scripts/trinity_johto.inc) -- the
@ value is always consumed inside the same synchronous script run that wrote it.
@ ============================================================================
GoldenrodUndergroundSwitchRoomEntrances_EventScript_ComputeSwitchPosition::
	setvar VAR_TEMP_A, 0
	call_if_set FLAG_TRINITY_J_UG_SWITCH_1, GoldenrodUndergroundSwitchRoomEntrances_EventScript_AddOne
	call_if_set FLAG_TRINITY_J_UG_SWITCH_2, GoldenrodUndergroundSwitchRoomEntrances_EventScript_AddTwo
	call_if_set FLAG_TRINITY_J_UG_SWITCH_3, GoldenrodUndergroundSwitchRoomEntrances_EventScript_AddThree
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_AddOne::
	addvar VAR_TEMP_A, 1
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_AddTwo::
	addvar VAR_TEMP_A, 2
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_AddThree::
	addvar VAR_TEMP_A, 3
	return

@ ============================================================================
@ The single authoring site for all eleven doors.
@ ============================================================================
GoldenrodUndergroundSwitchRoomEntrances_EventScript_AuthorDoors::
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_ComputeSwitchPosition
	call_if_set   FLAG_TRINITY_J_UG_DOOR_1, GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor1
	call_if_unset FLAG_TRINITY_J_UG_DOOR_1, GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor1
	call_if_set   FLAG_TRINITY_J_UG_DOOR_2, GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor2
	call_if_unset FLAG_TRINITY_J_UG_DOOR_2, GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor2
	call_if_set   FLAG_TRINITY_J_UG_DOOR_3, GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor3
	call_if_unset FLAG_TRINITY_J_UG_DOOR_3, GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor3
	call_if_set   FLAG_TRINITY_J_UG_DOOR_4, GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor4
	call_if_unset FLAG_TRINITY_J_UG_DOOR_4, GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor4
	call_if_set   FLAG_TRINITY_J_UG_DOOR_5, GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor5
	call_if_unset FLAG_TRINITY_J_UG_DOOR_5, GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor5
	call_if_set   FLAG_TRINITY_J_UG_DOOR_6, GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor6
	call_if_unset FLAG_TRINITY_J_UG_DOOR_6, GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor6
	goto_if_eq VAR_TEMP_A, 1, GoldenrodUndergroundSwitchRoomEntrances_EventScript_AuthorOddDoors
	goto_if_eq VAR_TEMP_A, 3, GoldenrodUndergroundSwitchRoomEntrances_EventScript_AuthorOddDoors
	goto_if_eq VAR_TEMP_A, 5, GoldenrodUndergroundSwitchRoomEntrances_EventScript_AuthorOddDoors
	goto_if_eq VAR_TEMP_A, 2, GoldenrodUndergroundSwitchRoomEntrances_EventScript_AuthorEvenDoors
	goto_if_eq VAR_TEMP_A, 4, GoldenrodUndergroundSwitchRoomEntrances_EventScript_AuthorEvenDoors
	goto_if_eq VAR_TEMP_A, 6, GoldenrodUndergroundSwitchRoomEntrances_EventScript_AuthorSixDoors
@ position 0 -- everything shut.
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor7
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor8
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor9
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor10
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor11
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_AuthorOddDoors::
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor7
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor8
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor9
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor10
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor11
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_AuthorEvenDoors::
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor7
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor8
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor9
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor10
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor11
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_AuthorSixDoors::
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor7
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor8
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor9
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor10
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor11
	return

@ ============================================================================
@ The eleven doors' tiles. Generated straight from GSC's ugdoor table
@ (…SwitchRoomEntrances.asm:20-31) through the converter's block map; every
@ WHOLE GSC block is authored, never part of one (D5).
@ ============================================================================
GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor1::
	setmetatile 16, 6, 692, FALSE
	setmetatile 17, 6, 693, FALSE
	setmetatile 16, 7, 694, FALSE
	setmetatile 17, 7, 695, FALSE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor1::
	setmetatile 16, 6, 760, TRUE
	setmetatile 17, 6, 761, TRUE
	setmetatile 16, 7, 762, TRUE
	setmetatile 17, 7, 763, TRUE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor2::
	setmetatile 10, 6, 692, FALSE
	setmetatile 11, 6, 693, FALSE
	setmetatile 10, 7, 694, FALSE
	setmetatile 11, 7, 695, FALSE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor2::
	setmetatile 10, 6, 760, TRUE
	setmetatile 11, 6, 761, TRUE
	setmetatile 10, 7, 762, TRUE
	setmetatile 11, 7, 763, TRUE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor3::
	setmetatile 2, 6, 692, FALSE
	setmetatile 3, 6, 693, FALSE
	setmetatile 2, 7, 694, FALSE
	setmetatile 3, 7, 695, FALSE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor3::
	setmetatile 2, 6, 760, TRUE
	setmetatile 3, 6, 761, TRUE
	setmetatile 2, 7, 762, TRUE
	setmetatile 3, 7, 763, TRUE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor4::
	setmetatile 2, 10, 692, FALSE
	setmetatile 3, 10, 693, FALSE
	setmetatile 2, 11, 694, FALSE
	setmetatile 3, 11, 695, FALSE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor4::
	setmetatile 2, 10, 760, TRUE
	setmetatile 3, 10, 761, TRUE
	setmetatile 2, 11, 762, TRUE
	setmetatile 3, 11, 763, TRUE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor5::
	setmetatile 10, 10, 692, FALSE
	setmetatile 11, 10, 693, FALSE
	setmetatile 10, 11, 694, FALSE
	setmetatile 11, 11, 695, FALSE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor5::
	setmetatile 10, 10, 760, TRUE
	setmetatile 11, 10, 761, TRUE
	setmetatile 10, 11, 762, TRUE
	setmetatile 11, 11, 763, TRUE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor6::
	setmetatile 16, 10, 692, FALSE
	setmetatile 17, 10, 693, FALSE
	setmetatile 16, 11, 694, FALSE
	setmetatile 17, 11, 695, FALSE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor6::
	setmetatile 16, 10, 760, TRUE
	setmetatile 17, 10, 761, TRUE
	setmetatile 16, 11, 762, TRUE
	setmetatile 17, 11, 763, TRUE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor7::
	setmetatile 12, 6, 680, TRUE
	setmetatile 13, 6, 681, TRUE
	setmetatile 12, 7, 682, TRUE
	setmetatile 13, 7, 683, TRUE
	setmetatile 12, 8, 692, FALSE
	setmetatile 13, 8, 693, FALSE
	setmetatile 12, 9, 694, FALSE
	setmetatile 13, 9, 695, FALSE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor7::
	setmetatile 12, 6, 764, TRUE
	setmetatile 13, 6, 765, TRUE
	setmetatile 12, 7, 766, TRUE
	setmetatile 13, 7, 767, TRUE
	setmetatile 12, 8, 756, TRUE
	setmetatile 13, 8, 757, FALSE
	setmetatile 12, 9, 758, TRUE
	setmetatile 13, 9, 759, FALSE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor8::
	setmetatile 6, 6, 680, TRUE
	setmetatile 7, 6, 681, TRUE
	setmetatile 6, 7, 682, TRUE
	setmetatile 7, 7, 683, TRUE
	setmetatile 6, 8, 692, FALSE
	setmetatile 7, 8, 693, FALSE
	setmetatile 6, 9, 694, FALSE
	setmetatile 7, 9, 695, FALSE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor8::
	setmetatile 6, 6, 764, TRUE
	setmetatile 7, 6, 765, TRUE
	setmetatile 6, 7, 766, TRUE
	setmetatile 7, 7, 767, TRUE
	setmetatile 6, 8, 756, TRUE
	setmetatile 7, 8, 757, FALSE
	setmetatile 6, 9, 758, TRUE
	setmetatile 7, 9, 759, FALSE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor9::
	setmetatile 12, 10, 680, TRUE
	setmetatile 13, 10, 681, TRUE
	setmetatile 12, 11, 682, TRUE
	setmetatile 13, 11, 683, TRUE
	setmetatile 12, 12, 692, FALSE
	setmetatile 13, 12, 693, FALSE
	setmetatile 12, 13, 694, FALSE
	setmetatile 13, 13, 695, FALSE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor9::
	setmetatile 12, 10, 764, TRUE
	setmetatile 13, 10, 765, TRUE
	setmetatile 12, 11, 766, TRUE
	setmetatile 13, 11, 767, TRUE
	setmetatile 12, 12, 756, TRUE
	setmetatile 13, 12, 757, FALSE
	setmetatile 12, 13, 758, TRUE
	setmetatile 13, 13, 759, FALSE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor10::
	setmetatile 6, 10, 680, TRUE
	setmetatile 7, 10, 681, TRUE
	setmetatile 6, 11, 682, TRUE
	setmetatile 7, 11, 683, TRUE
	setmetatile 6, 12, 692, FALSE
	setmetatile 7, 12, 693, FALSE
	setmetatile 6, 13, 694, FALSE
	setmetatile 7, 13, 695, FALSE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor10::
	setmetatile 6, 10, 764, TRUE
	setmetatile 7, 10, 765, TRUE
	setmetatile 6, 11, 766, TRUE
	setmetatile 7, 11, 767, TRUE
	setmetatile 6, 12, 756, TRUE
	setmetatile 7, 12, 757, FALSE
	setmetatile 6, 13, 758, TRUE
	setmetatile 7, 13, 759, FALSE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_OpenDoor11::
	setmetatile 18, 10, 680, TRUE
	setmetatile 19, 10, 681, TRUE
	setmetatile 18, 11, 682, TRUE
	setmetatile 19, 11, 683, TRUE
	setmetatile 18, 12, 692, FALSE
	setmetatile 19, 12, 693, FALSE
	setmetatile 18, 13, 694, FALSE
	setmetatile 19, 13, 695, FALSE
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_CloseDoor11::
	setmetatile 18, 10, 764, TRUE
	setmetatile 19, 10, 765, TRUE
	setmetatile 18, 11, 766, TRUE
	setmetatile 19, 11, 767, TRUE
	setmetatile 18, 12, 756, TRUE
	setmetatile 19, 12, 757, FALSE
	setmetatile 18, 13, 758, TRUE
	setmetatile 19, 13, 759, FALSE
	return

@ ============================================================================
@ The three switches and the EMERGENCY panel.
@
@ D1: each is a bg_event on a collision-1 wall tile (all four decode metatile
@ 734, collision 1, elevation 0) with BG_EVENT_PLAYER_FACING_NORTH, read from
@ the tile below -- (16,2) (10,2) (2,2) (20,12), all collision 0 elevation 3,
@ all kept clear of objects. Each has EXACTLY ONE reading tile and reach_check
@ cannot see that, which is S5's I1 pin.
@ ============================================================================
GoldenrodUndergroundSwitchRoomEntrances_EventScript_Switch1::
	lockall
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_Switch1, MSGBOX_DEFAULT
	goto_if_set FLAG_TRINITY_J_UG_SWITCH_1, GoldenrodUndergroundSwitchRoomEntrances_EventScript_Switch1TurnOff
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_OffTurnOn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodUndergroundSwitchRoomEntrances_EventScript_DontToggle
	setflag FLAG_TRINITY_J_UG_SWITCH_1
	goto GoldenrodUndergroundSwitchRoomEntrances_EventScript_ApplyPosition

GoldenrodUndergroundSwitchRoomEntrances_EventScript_Switch1TurnOff::
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_OnTurnOff, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodUndergroundSwitchRoomEntrances_EventScript_DontToggle
	clearflag FLAG_TRINITY_J_UG_SWITCH_1
	goto GoldenrodUndergroundSwitchRoomEntrances_EventScript_ApplyPosition

GoldenrodUndergroundSwitchRoomEntrances_EventScript_Switch2::
	lockall
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_Switch2, MSGBOX_DEFAULT
	goto_if_set FLAG_TRINITY_J_UG_SWITCH_2, GoldenrodUndergroundSwitchRoomEntrances_EventScript_Switch2TurnOff
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_OffTurnOn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodUndergroundSwitchRoomEntrances_EventScript_DontToggle
	setflag FLAG_TRINITY_J_UG_SWITCH_2
	goto GoldenrodUndergroundSwitchRoomEntrances_EventScript_ApplyPosition

GoldenrodUndergroundSwitchRoomEntrances_EventScript_Switch2TurnOff::
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_OnTurnOff, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodUndergroundSwitchRoomEntrances_EventScript_DontToggle
	clearflag FLAG_TRINITY_J_UG_SWITCH_2
	goto GoldenrodUndergroundSwitchRoomEntrances_EventScript_ApplyPosition

GoldenrodUndergroundSwitchRoomEntrances_EventScript_Switch3::
	lockall
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_Switch3, MSGBOX_DEFAULT
	goto_if_set FLAG_TRINITY_J_UG_SWITCH_3, GoldenrodUndergroundSwitchRoomEntrances_EventScript_Switch3TurnOff
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_OffTurnOn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodUndergroundSwitchRoomEntrances_EventScript_DontToggle
	setflag FLAG_TRINITY_J_UG_SWITCH_3
	goto GoldenrodUndergroundSwitchRoomEntrances_EventScript_ApplyPosition

GoldenrodUndergroundSwitchRoomEntrances_EventScript_Switch3TurnOff::
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_OnTurnOff, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodUndergroundSwitchRoomEntrances_EventScript_DontToggle
	clearflag FLAG_TRINITY_J_UG_SWITCH_3
	goto GoldenrodUndergroundSwitchRoomEntrances_EventScript_ApplyPosition

GoldenrodUndergroundSwitchRoomEntrances_EventScript_DontToggle::
	releaseall
	end

@ Position N opens door N and shuts door 7-N; the other four sticky doors keep
@ whatever they were. Toggling any individual switch also clears the EMERGENCY
@ flag, so that panel never reads ON over a configuration it did not set -- a
@ small, deliberate improvement on GSC, which leaves it stale.
GoldenrodUndergroundSwitchRoomEntrances_EventScript_ApplyPosition::
	clearflag FLAG_TRINITY_J_UG_EMERGENCY
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_ComputeSwitchPosition
	goto_if_eq VAR_TEMP_A, 1, GoldenrodUndergroundSwitchRoomEntrances_EventScript_Position1
	goto_if_eq VAR_TEMP_A, 2, GoldenrodUndergroundSwitchRoomEntrances_EventScript_Position2
	goto_if_eq VAR_TEMP_A, 3, GoldenrodUndergroundSwitchRoomEntrances_EventScript_Position3
	goto_if_eq VAR_TEMP_A, 4, GoldenrodUndergroundSwitchRoomEntrances_EventScript_Position4
	goto_if_eq VAR_TEMP_A, 5, GoldenrodUndergroundSwitchRoomEntrances_EventScript_Position5
	goto_if_eq VAR_TEMP_A, 6, GoldenrodUndergroundSwitchRoomEntrances_EventScript_Position6
@ position 0
	clearflag FLAG_TRINITY_J_UG_DOOR_1
	clearflag FLAG_TRINITY_J_UG_DOOR_2
	clearflag FLAG_TRINITY_J_UG_DOOR_3
	clearflag FLAG_TRINITY_J_UG_DOOR_4
	clearflag FLAG_TRINITY_J_UG_DOOR_5
	clearflag FLAG_TRINITY_J_UG_DOOR_6
	goto GoldenrodUndergroundSwitchRoomEntrances_EventScript_FinishToggle

GoldenrodUndergroundSwitchRoomEntrances_EventScript_Position1::
	setflag FLAG_TRINITY_J_UG_DOOR_1
	clearflag FLAG_TRINITY_J_UG_DOOR_6
	goto GoldenrodUndergroundSwitchRoomEntrances_EventScript_FinishToggle

GoldenrodUndergroundSwitchRoomEntrances_EventScript_Position2::
	setflag FLAG_TRINITY_J_UG_DOOR_2
	clearflag FLAG_TRINITY_J_UG_DOOR_5
	goto GoldenrodUndergroundSwitchRoomEntrances_EventScript_FinishToggle

GoldenrodUndergroundSwitchRoomEntrances_EventScript_Position3::
	setflag FLAG_TRINITY_J_UG_DOOR_3
	clearflag FLAG_TRINITY_J_UG_DOOR_4
	goto GoldenrodUndergroundSwitchRoomEntrances_EventScript_FinishToggle

GoldenrodUndergroundSwitchRoomEntrances_EventScript_Position4::
	setflag FLAG_TRINITY_J_UG_DOOR_4
	clearflag FLAG_TRINITY_J_UG_DOOR_3
	goto GoldenrodUndergroundSwitchRoomEntrances_EventScript_FinishToggle

GoldenrodUndergroundSwitchRoomEntrances_EventScript_Position5::
	setflag FLAG_TRINITY_J_UG_DOOR_5
	clearflag FLAG_TRINITY_J_UG_DOOR_2
	goto GoldenrodUndergroundSwitchRoomEntrances_EventScript_FinishToggle

GoldenrodUndergroundSwitchRoomEntrances_EventScript_Position6::
	setflag FLAG_TRINITY_J_UG_DOOR_6
	clearflag FLAG_TRINITY_J_UG_DOOR_1
	goto GoldenrodUndergroundSwitchRoomEntrances_EventScript_FinishToggle

@ GSC's EMERGENCY position (7) is applied and then collapsed to 6, which is
@ exactly the winning configuration: sticky doors 3, 5 and 6 open, 1, 2 and 4
@ shut, and all three switches on so 8, 9 and 11 follow.
GoldenrodUndergroundSwitchRoomEntrances_EventScript_EmergencySwitch::
	lockall
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_Emergency, MSGBOX_DEFAULT
	goto_if_set FLAG_TRINITY_J_UG_EMERGENCY, GoldenrodUndergroundSwitchRoomEntrances_EventScript_EmergencyTurnOff
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_OffTurnOn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodUndergroundSwitchRoomEntrances_EventScript_DontToggle
	setflag FLAG_TRINITY_J_UG_EMERGENCY
	setflag FLAG_TRINITY_J_UG_SWITCH_1
	setflag FLAG_TRINITY_J_UG_SWITCH_2
	setflag FLAG_TRINITY_J_UG_SWITCH_3
	setflag FLAG_TRINITY_J_UG_DOOR_3
	setflag FLAG_TRINITY_J_UG_DOOR_5
	setflag FLAG_TRINITY_J_UG_DOOR_6
	clearflag FLAG_TRINITY_J_UG_DOOR_1
	clearflag FLAG_TRINITY_J_UG_DOOR_2
	clearflag FLAG_TRINITY_J_UG_DOOR_4
	goto GoldenrodUndergroundSwitchRoomEntrances_EventScript_FinishToggle

GoldenrodUndergroundSwitchRoomEntrances_EventScript_EmergencyTurnOff::
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_OnTurnOff, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GoldenrodUndergroundSwitchRoomEntrances_EventScript_DontToggle
	clearflag FLAG_TRINITY_J_UG_EMERGENCY
	clearflag FLAG_TRINITY_J_UG_SWITCH_1
	clearflag FLAG_TRINITY_J_UG_SWITCH_2
	clearflag FLAG_TRINITY_J_UG_SWITCH_3
	clearflag FLAG_TRINITY_J_UG_DOOR_1
	clearflag FLAG_TRINITY_J_UG_DOOR_2
	clearflag FLAG_TRINITY_J_UG_DOOR_3
	clearflag FLAG_TRINITY_J_UG_DOOR_4
	clearflag FLAG_TRINITY_J_UG_DOOR_5
	clearflag FLAG_TRINITY_J_UG_DOOR_6
	goto GoldenrodUndergroundSwitchRoomEntrances_EventScript_FinishToggle

@ D3: the runtime path repeats the authoring AND redraws.
GoldenrodUndergroundSwitchRoomEntrances_EventScript_FinishToggle::
	closemessage
	playse SE_DOOR
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_AuthorDoors
	special DrawWholeMapView
	waitse
	releaseall
	end

@ ============================================================================
@ THE ROCKET POSTS. R2, sight-triggered, GSC tiles
@ (…SwitchRoomEntrances.asm:807-812), all decoded collision 0 / elevation 3 /
@ MB_NORMAL: (17,2) (11,2) (3,2) mt693 in the top corridor -- one in front of
@ each switch -- and (19,12) mt757 in the WAREHOUSE antechamber, guarding the
@ door the whole maze exists to open.
@ ============================================================================
GoldenrodUndergroundSwitchRoomEntrances_EventScript_GruntA::
	trainerbattle_single TRAINER_JOHTO_ROCKET_UG_A, GoldenrodUndergroundSwitchRoomEntrances_Text_GruntASeen, GoldenrodUndergroundSwitchRoomEntrances_Text_GruntABeaten
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_GruntAAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodUndergroundSwitchRoomEntrances_EventScript_GruntB::
	trainerbattle_single TRAINER_JOHTO_ROCKET_UG_B, GoldenrodUndergroundSwitchRoomEntrances_Text_GruntBSeen, GoldenrodUndergroundSwitchRoomEntrances_Text_GruntBBeaten
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_GruntBAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodUndergroundSwitchRoomEntrances_EventScript_GruntC::
	trainerbattle_single TRAINER_JOHTO_ROCKET_UG_C, GoldenrodUndergroundSwitchRoomEntrances_Text_GruntCSeen, GoldenrodUndergroundSwitchRoomEntrances_Text_GruntCBeaten
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_GruntCAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodUndergroundSwitchRoomEntrances_EventScript_GruntF::
	trainerbattle_single TRAINER_ROCKET_GRUNT_F_4, GoldenrodUndergroundSwitchRoomEntrances_Text_GruntFSeen, GoldenrodUndergroundSwitchRoomEntrances_Text_GruntFBeaten
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_GruntFAfter, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ SILVER 4. GSC's own staging (…SwitchRoomEntrances.asm:84-120): two coord
@ scenes at (19,4) and (19,5), the rival appearing at (23,3) and walking in.
@
@ THE PAIR IS A GENUINE CHOKEPOINT. x=19 is walkable ONLY on rows 4 and 5 --
@ rows 2 and 3 are solid at x=18,19 -- and the maze entrance (23,3) is east of
@ it while all three switches are west. Both tiles decode collision 0 /
@ elevation 3 / MB_NORMAL (mt693 and mt695).
@
@ HE IS AN ADDOBJECT-ONLY ACTOR (S1/S3/S7 idiom): ON_TRANSITION SETS his flag
@ unconditionally so the template can never spawn, and the scene addobject's
@ him. His template tile (23,3) is the map's MB_LADDER warp, and the rule that
@ an NPC never RESTS on a warp is not violated, because he never rests -- he is
@ spawned, walked off it and removed inside one lockall. GSC does exactly this.
@
@ CAMERA. From (19,4) the window is x 12..26, y 0..9; from (19,5), y 1..10.
@ Every tile of the approach -- (23,4) (22,4) (21,4) (20,4) for scene 1,
@ (23,4) (23,5) (22,5) (21,5) (20,5) for scene 2 -- is inside both and all
@ decode walkable.
@
@ ONE BATTLE, TWO PATHS. The confrontation body is `call`-ed, so the two coord
@ scenes share a single trainerbattle (S1's idiom) and neither has to reach the
@ battle through `trainerbattle_no_intro`, whose
@ EventScript_DoNoIntroTrainerBattle calls PlayTrainerEncounterMusic
@ unconditionally and would swap MUS_RG_ENCOUNTER_RIVAL out from under the
@ playbgm (data/scripts/trainer_battle.inc:53).
@ ============================================================================
GoldenrodUndergroundSwitchRoomEntrances_EventScript_SilverScene1::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	fadeoutbgm 4
	delay 20
	playse SE_EXIT
	addobject LOCALID_JOHTO_UGSW_SILVER
	waitse
	applymovement LOCALID_JOHTO_UGSW_SILVER, GoldenrodUndergroundSwitchRoomEntrances_EventScript_Movement_SilverApproach1
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_SilverBattle
	applymovement LOCALID_JOHTO_UGSW_SILVER, GoldenrodUndergroundSwitchRoomEntrances_EventScript_Movement_SilverRetreat1
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject LOCALID_JOHTO_UGSW_SILVER
	fadedefaultbgm
	releaseall
	end

GoldenrodUndergroundSwitchRoomEntrances_EventScript_SilverScene2::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	fadeoutbgm 4
	delay 20
	playse SE_EXIT
	addobject LOCALID_JOHTO_UGSW_SILVER
	waitse
	applymovement LOCALID_JOHTO_UGSW_SILVER, GoldenrodUndergroundSwitchRoomEntrances_EventScript_Movement_SilverApproach2
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_SilverBattle
	applymovement LOCALID_JOHTO_UGSW_SILVER, GoldenrodUndergroundSwitchRoomEntrances_EventScript_Movement_SilverRetreat2
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject LOCALID_JOHTO_UGSW_SILVER
	fadedefaultbgm
	releaseall
	end

@ The shared body. `trainerbattle_single` inside a `call`-ed subscript is vanilla
@ (MauvilleCity_EventScript_BattleWally).
GoldenrodUndergroundSwitchRoomEntrances_EventScript_SilverBattle::
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_SilverBefore, MSGBOX_DEFAULT
	closemessage
	@ `trainerbattle_no_intro`, NOT `trainerbattle_single`: the caller has already
	@ lockall'd and the _single form supplies its own lock (S5's pin; the vanilla
	@ precedent for the no-intro form inside a locked scene is
	@ MauvilleCity_EventScript_BattleWally). setvar VAR_LAST_TALKED pins the
	@ reveal emote on SILVER -- GSC's `setlasttalked` does the same.
	@ Battle BGM needs no scripting: TRAINER_SILVER_4 is TRAINER_CLASS_RIVAL with
	@ a name other than WALLY, so GetBattleBGM() returns MUS_VS_RIVAL.
	setvar VAR_LAST_TALKED, LOCALID_JOHTO_UGSW_SILVER
	trainerbattle_no_intro TRAINER_SILVER_4, GoldenrodUndergroundSwitchRoomEntrances_Text_SilverDefeat
	setflag FLAG_TRINITY_J_SILVER4_BEATEN
	call GoldenrodUndergroundSwitchRoomEntrances_EventScript_AdvanceToScene2
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_SilverAfter, MSGBOX_DEFAULT
	closemessage
	return

GoldenrodUndergroundSwitchRoomEntrances_EventScript_AdvanceToScene2::
	goto_if_ge VAR_TRINITY_JOHTO_SCENE_GOLDENROD, 2, GoldenrodUndergroundSwitchRoomEntrances_EventScript_Scene2AlreadySet
	setvar VAR_TRINITY_JOHTO_SCENE_GOLDENROD, 2
GoldenrodUndergroundSwitchRoomEntrances_EventScript_Scene2AlreadySet::
	return

@ (23,3) -> (23,4) -> (22,4) -> (21,4) -> (20,4). GSC's own movement.
GoldenrodUndergroundSwitchRoomEntrances_EventScript_Movement_SilverApproach1:
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodUndergroundSwitchRoomEntrances_EventScript_Movement_SilverRetreat1:
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

@ (23,3) -> (23,4) -> (23,5) -> (22,5) -> (21,5) -> (20,5).
GoldenrodUndergroundSwitchRoomEntrances_EventScript_Movement_SilverApproach2:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodUndergroundSwitchRoomEntrances_EventScript_Movement_SilverRetreat2:
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE -- the template's flag is set on every
@ transition, so it can never spawn, and the scene removes the addobject'd copy
@ before it releases.
GoldenrodUndergroundSwitchRoomEntrances_EventScript_SilverIdle::
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_SilverIdle, MSGBOX_NPC
	end

GoldenrodUndergroundSwitchRoomEntrances_EventScript_Teacher::
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_Teacher, MSGBOX_NPC
	end

GoldenrodUndergroundSwitchRoomEntrances_EventScript_SuperNerd::
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_SuperNerd, MSGBOX_NPC
	end

@ ============================================================================
@ Text.
@ ============================================================================
GoldenrodUndergroundSwitchRoomEntrances_Text_Teacher:
	.string "There are some shops down\n"
	.string "these stairs…\p"
	.string "But there are trainers too.\n"
	.string "I'm too scared to go down.$"

GoldenrodUndergroundSwitchRoomEntrances_Text_SuperNerd:
	.string "I was challenged to a battle\n"
	.string "downstairs.\p"
	.string "It's rough down there. You'd\n"
	.string "better be careful.$"

GoldenrodUndergroundSwitchRoomEntrances_Text_Switch1:
	.string "It's labeled SWITCH 1.$"

GoldenrodUndergroundSwitchRoomEntrances_Text_Switch2:
	.string "It's labeled SWITCH 2.$"

GoldenrodUndergroundSwitchRoomEntrances_Text_Switch3:
	.string "It's labeled SWITCH 3.$"

GoldenrodUndergroundSwitchRoomEntrances_Text_Emergency:
	.string "It's labeled EMERGENCY.$"

GoldenrodUndergroundSwitchRoomEntrances_Text_OffTurnOn:
	.string "It's OFF.\nTurn it ON?$"

GoldenrodUndergroundSwitchRoomEntrances_Text_OnTurnOff:
	.string "It's ON.\nTurn it OFF?$"

GoldenrodUndergroundSwitchRoomEntrances_Text_GruntASeen:
	.string "Nobody comes past the switches.\p"
	.string "There are eleven doors down\n"
	.string "here and I know every one.$"

GoldenrodUndergroundSwitchRoomEntrances_Text_GruntABeaten:
	.string "You -- how?$"

GoldenrodUndergroundSwitchRoomEntrances_Text_GruntAAfter:
	.string "Flip them all you like.\p"
	.string "Only one arrangement gets you\n"
	.string "to the warehouse, and you'd\l"
	.string "have to work it out.$"

GoldenrodUndergroundSwitchRoomEntrances_Text_GruntBSeen:
	.string "Lost, are you?\p"
	.string "Everyone is, down here. That's\n"
	.string "the design.$"

GoldenrodUndergroundSwitchRoomEntrances_Text_GruntBBeaten:
	.string "Blast it!$"

GoldenrodUndergroundSwitchRoomEntrances_Text_GruntBAfter:
	.string "The shutters run off these\n"
	.string "three switches.\p"
	.string "Turning one on turns another\n"
	.string "corridor off. It's meant to be\l"
	.string "annoying.$"

GoldenrodUndergroundSwitchRoomEntrances_Text_GruntCSeen:
	.string "Hey! This is a private\n"
	.string "basement now!$"

GoldenrodUndergroundSwitchRoomEntrances_Text_GruntCBeaten:
	.string "You're kidding!$"

GoldenrodUndergroundSwitchRoomEntrances_Text_GruntCAfter:
	.string "There's an EMERGENCY panel down\n"
	.string "past the last door.\p"
	.string "One press and everything opens\n"
	.string "the right way.\p"
	.string "…Which does none of us any\n"
	.string "good, since it's on the far\l"
	.string "side.$"

GoldenrodUndergroundSwitchRoomEntrances_Text_GruntFSeen:
	.string "Are you lost? No -- you can't\n"
	.string "be.\p"
	.string "You don't have that scared\n"
	.string "look.\p"
	.string "I'll give you something to be\n"
	.string "scared about!$"

GoldenrodUndergroundSwitchRoomEntrances_Text_GruntFBeaten:
	.string "How could you?$"

GoldenrodUndergroundSwitchRoomEntrances_Text_GruntFAfter:
	.string "Go wherever you like! Get lost!\n"
	.string "See if I care!\p"
	.string "…He's through there. The old\n"
	.string "man. Go on.$"

@ GSC UndergroundRivalBeforeText -- SILVER is down here hunting TEAM ROCKET,
@ which in Trinity is a colder joke than GSC could have known.
GoldenrodUndergroundSwitchRoomEntrances_Text_SilverBefore:
	.string "Hold it.\p"
	.string "I saw you come down, so I\n"
	.string "followed you.\p"
	.string "I don't need you underfoot\n"
	.string "while I take care of TEAM\l"
	.string "ROCKET.\p"
	.string "…Wait. You beat me before,\n"
	.string "didn't you.\p"
	.string "That was a fluke.\p"
	.string "But I repay my debts.$"

GoldenrodUndergroundSwitchRoomEntrances_Text_SilverDefeat:
	.string "…Why.\p"
	.string "Why do I lose?\p"
	.string "I've assembled the toughest\n"
	.string "POKéMON there are. I didn't\l"
	.string "ease up for a second.\p"
	.string "So why do I lose?$"

@ GSC UndergroundRivalAfterText. The LANCE conversation is the load-bearing part
@ and it is left almost untouched -- it is the last thing SILVER says before the
@ RADIO TOWER tells him whose son he is.
GoldenrodUndergroundSwitchRoomEntrances_Text_SilverAfter:
	.string "SILVER: …I don't understand.\p"
	.string "Is what that LANCE said true?\p"
	.string "That I don't treat POKéMON\n"
	.string "properly?\p"
	.string "Love.\p"
	.string "Trust.\p"
	.string "Are they really what I lack?\n"
	.string "Are they what's keeping me from\l"
	.string "winning?\p"
	.string "I… I just don't understand.\p"
	.string "But it doesn't end here. Not\n"
	.string "now. Not because of this.\p"
	.string "I'm not giving up my dream of\n"
	.string "being the strongest.\p"
	.string "Get out of my way.$"

@ INTENTIONALLY UNREACHABLE / DEFENSIVE.
GoldenrodUndergroundSwitchRoomEntrances_Text_SilverIdle:
	.string "…$"
