@ ============================================================================
@ Trinity M4b S9 -- BLACKTHORN GYM 2F. THE BOULDER PUZZLE.
@
@ GSC (pokecrystal maps/BlackthornGym2F.asm): six SPRITEMOVEDATA_STRENGTH_BOULDER
@ objects and three holes. A MAPCALLBACK_CMDQUEUE installs CMDQUEUE_STONETABLE,
@ a per-frame check that fires when a named boulder is standing on a named warp
@ id; the script `disappear`s it (setting a permanent event), shakes the screen
@ and prints "The boulder fell through!". 1F's MAPCALLBACK_TILES then reads
@ those events and `changeblock`s a fallen-boulder block into the floor below --
@ at the SAME (x,y). See data/maps/BlackthornGym1F/scripts.inc for the block
@ arithmetic and for why two of the three are mandatory for badge 16.
@
@ ---------------------------------------------------------------------------
@ WHAT THE ENGINE HAD, AND WHAT WAS ADDED
@ ---------------------------------------------------------------------------
@ pokeemerald-expansion ships the whole Strength PUSH -- OBJ_EVENT_GFX_PUSHABLE_
@ BOULDER, TryPushBoulder, Task_PushBoulder -- and 60+ live boulders in HOENN.
@ It ships NO boulder-falls-into-a-hole mechanism at all (grep FallThroughHole:
@ nothing). pokefirered does: HandleBoulderFallThroughHole
@ (pokefirered/src/field_control_avatar.c:1066) and its sibling
@ HandleBoulderActivateVictoryRoadSwitch (:1076), both called from
@ DoBoulderFinish (:1445), the exact counterpart of this tree's PushBoulder_End.
@ This expansion even carries FRLG's SeafoamIslands maps -- with
@ "object_events": [], so the boulders were never ported and the missing C was
@ never noticed.
@
@ S9 ports it, merged with the sibling's coord_event lookup so the puzzle is
@ DATA-DRIVEN: src/field_player_avatar.c's TryBoulderFallThroughHole, ~25 lines,
@ appended as the last statement of PushBoulder_End. It returns on line one
@ unless the boulder's tile is MB_CRACKED_FLOOR_HOLE, so all 60+ HOENN boulders
@ are untouched.
@
@ ---------------------------------------------------------------------------
@ THE THREE HOLE COORD_EVENTS ARE FOR THE ENGINE HOOK, NOT FOR THE PLAYER
@ ---------------------------------------------------------------------------
@ map.json carries SIX coord_events on three tiles: M4a's FallToA/B/C (the
@ player's fall) and S9's BoulderFellHoleA/B/C (the boulder's). TWO independent
@ reasons the player can never trigger the second set, EITHER of which is
@ sufficient on its own:
@   1. elevation 15 (ELEVATION_MULTI_LEVEL). GetCoordEventScriptAtPosition
@      (src/field_control_avatar.c:1085-1097) requires
@      `elevation == <player's> || == ELEVATION_TRANSITION`, and EVERY walkable
@      tile on this floor decodes elevation 3. TryBoulderFallThroughHole
@      matches on 15 explicitly and ignores the var.
@   2. var_value 1 on VAR_TEMP_0, which is zeroed by ClearTempFieldEventData on
@      every map load and written by nothing on this map -- so
@      ShouldTriggerScriptRun is false. (M4a's triggers rely on the same fact
@      from the other side: they match == 0.)
@ CORRECTED IN THE S9 FIX ROUND -- A THIRD "GUARD" WAS CLAIMED HERE AND IT WAS
@ FALSE. Ordering is NOT a guard: GetCoordEventScriptAtPosition does not stop at
@ the first entry whose POSITION matches, it only returns when
@ TryRunCoordEventScript returns non-NULL, and a var-guard failure returns NULL
@ and the loop CONTINUES (:1087-1096). That FallToA/B/C are listed first buys
@ nothing. The two guards above are the whole protection.
@ check_holes.py is satisfied either way: it wants a coord_event at the hole's
@ exact (x,y), and now there are two.
@
@ ---------------------------------------------------------------------------
@ THE SOLVE (every tile decoded from data/layouts/BlackthornGym2F_Johto/map.bin,
@ collision 0 elevation 3 unless stated)
@ ---------------------------------------------------------------------------
@   hole C (8,3): player (8,1), boulder 1 (8,2), ONE push south.
@   hole A (2,5): player (2,2), boulder 2 (2,3), push south to (2,4); player
@                 steps to (2,3), push south into (2,5).
@   hole B (8,7): boulder 3 (6,16), pushed NORTH from below nine times -- it
@                 stops itself at (6,7) because (6,6) is a wall. Player then
@                 goes (6,8)->(5,8)->(5,7) and pushes EAST: (6,7)->(7,7). Player
@                 steps to (6,7), pushes east again: (7,7)->(8,7).
@   The obvious-looking alternative -- boulder to (7,8), push north -- is
@   IMPOSSIBLE, and that is why GSC routes it the long way: the push tile would
@   be (7,9), which is MB_LADDER, a warp the player cannot stand on.
@
@ NO SOFT-LOCK IS POSSIBLE, and the reason is the same fact that made
@ persistence impossible: LoadObjEventTemplatesFromHeader (src/overworld.c:521-530,
@ called from both map-load paths at :858 and :916) CpuFills the saveblock
@ template array and CpuCopies the ROM templates back on EVERY map load. A
@ boulder is always at its template tile when you walk in. Whatever the player
@ wedges where, leaving and returning resets all six. It is also exactly why
@ GSC's own design is a permanent per-boulder event plus a changeblock rather
@ than a saved position.
@
@ ---------------------------------------------------------------------------
@ THERE ARE NO DECOYS. BOULDERS 4, 5 AND 6 ARE THE THREE LOCKS.
@ ---------------------------------------------------------------------------
@ GSC gives boulders 4/5/6 no event, so they can never fall, and the natural
@ reading -- which this file's first draft took -- is that they are red
@ herrings. MEASURED, they are nothing of the sort: each one is the single
@ obstacle standing on the approach to exactly one hole. Flood fill from the
@ (1,7) door, boulders modelled as the blockers they are:
@
@   all six placed          96 tiles   (2,2) no   (8,1) no   (6,17) no
@   boulder 4 (3,3) cleared 103        (2,2) YES  -- unlocks hole A's push tile
@   boulder 5 (6,1) cleared 105        (8,1) YES  -- unlocks hole C's push tile
@   boulder 6 (8,14) cleared 103       (6,17) YES -- unlocks hole B's approach
@   all three cleared       119        everything open
@
@ So the puzzle is two-layer, and GSC built it that way: clear the lock, then
@ push the payload.
@   hole A: boulder 4 NORTH x2 ((3,3)->(3,1), freeing (3,2) so the player can
@           reach (2,2)), then boulder 2 SOUTH x2 into (2,5).
@   hole C: boulder 5 EAST x3 ((6,1)->(9,1); two pushes is not enough, it would
@           sit ON (8,1)), then boulder 1 SOUTH x1 into (8,3).
@   hole B: boulder 6 SOUTH x3 ((8,14)->(8,17), freeing the (8,15)/(8,16) column
@           that is the only way into the bottom-right pocket), then boulder 3
@           NORTH x9 and EAST x2 as described above.
@
@ ---------------------------------------------------------------------------
@ DELIBERATE, KINDER DEVIATION FROM GSC (logged in the slice plan, 1.4)
@ ---------------------------------------------------------------------------
@ GSC's `stonetable` binds boulder N to hole N, so pushing the "wrong" boulder
@ into a hole silently does nothing. The hook here is generic: ANY boulder in
@ ANY hole plugs THAT hole. PLUG, NOT WASTE -- and that is exactly what makes
@ the two-layer structure above safe to hand to a player: a lock boulder shoved
@ into a hole by accident (or on purpose) still opens that hole's platform, so
@ no sequence of pushes can spend a hole for nothing. Six boulders, three holes,
@ permanent platform flags, and positions that reset on every map load. It is
@ also why all six carry their own visibility flag.
@
@ ---------------------------------------------------------------------------
@ THE BACKSTOP (belt and braces; the founder gate is clean-compile + review with
@ NO play-tests, so a new runtime hook is the one thing that cannot be proven by
@ running it)
@ ---------------------------------------------------------------------------
@ Every boulder's own talk script asks getobjectcurrentxy whether it is standing
@ on one of the three hole tiles and, if so, runs the same fall script;
@ otherwise it falls through to vanilla EventScript_StrengthBoulder. If the
@ engine hook never fires, pressing A on a boulder sitting in a hole still
@ solves the puzzle. Two independent paths into one script.
@ The fall-through is MANDATORY, not tidiness: FLAG_SYS_USE_STRENGTH is cleared
@ on every map load (src/overworld.c:393/403/414/454), so the vanilla prompt is
@ the only thing that re-arms Strength on this floor.
@ ============================================================================

BlackthornGym2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, BlackthornGym2F_SetHoleWarp
	.byte 0

@ NO visibility authoring for the six boulder flags, and that is deliberate: each
@ has exactly ONE writer (removeobject, whose FlagSet is the write) and the
@ correct default (clear = standing on the floor). S7's pin -- a visibility flag
@ with one writer and a correct default needs no authoring clause, and giving it
@ one would resurrect a fallen boulder.
BlackthornGym2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_BLACKTHORN_GYM_1F
	end

@ Trinity M4a Task 7 fix: GSC pit-fall (ruling R1). All 3 holes' same-xy landing
@ on 1F decodes to WALL (blocked) -- GSC's own warp_events route each hole to a
@ specific 1F tile that does NOT match the hole's own (x,y): (2,5)->(2,6),
@ (8,7)->(7,7), (8,3)->(7,6), all confirmed FLOOR/walkable. coord_events give
@ each hole its correct landing; the setholewarp above is kept as the standard
@ idiom (harmless -- coord_events are checked first and cover all 3 cells).
@ S9 NOTE: plugging a hole does NOT stop the player falling through it. That is
@ GSC's behaviour too (the stonetable removes the stone; the warp stays), and
@ all three landings are on the correct side of the puzzle either way.
BlackthornGym2F_EventScript_FallToA::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_BLACKTHORN_GYM_1F, 2, 6
	waitstate
	end

BlackthornGym2F_EventScript_FallToB::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_BLACKTHORN_GYM_1F, 7, 7
	waitstate
	end

BlackthornGym2F_EventScript_FallToC::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_BLACKTHORN_GYM_1F, 7, 6
	waitstate
	end

@ ============================================================================
@ The boulder script (all six objects). Primary path: never runs -- the engine
@ hook removes the boulder the instant it lands, so it can never be talked to
@ in a hole. Backstop path: see the header.
@ getobjectcurrentxy returns UNSHIFTED map coordinates (GetObjectPosition,
@ src/field_specials.c:4488-4505, subtracts MAP_OFFSET), so these compare
@ directly against the hole tiles. VAR_LAST_TALKED is the interacted object's
@ local id.
@ ============================================================================
BlackthornGym2F_EventScript_Boulder::
	@ The 0 is CURRENT_POSITION. It is spelled as a literal on purpose: that name
	@ is an ENUM member (include/constants/field_specials.h:112-115), not a
	@ #define, so the assembler cannot see it even though event_scripts.s
	@ includes the header.
	getobjectxy VAR_LAST_TALKED, 0, VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 8, BlackthornGym2F_EventScript_BoulderColumn8
	goto_if_eq VAR_0x8004, 2, BlackthornGym2F_EventScript_BoulderColumn2
	goto EventScript_StrengthBoulder
	end

BlackthornGym2F_EventScript_BoulderColumn8::
	goto_if_eq VAR_0x8005, 3, BlackthornGym2F_EventScript_BoulderFellHoleC
	goto_if_eq VAR_0x8005, 7, BlackthornGym2F_EventScript_BoulderFellHoleB
	goto EventScript_StrengthBoulder
	end

BlackthornGym2F_EventScript_BoulderColumn2::
	goto_if_eq VAR_0x8005, 5, BlackthornGym2F_EventScript_BoulderFellHoleA
	goto EventScript_StrengthBoulder
	end

@ ============================================================================
@ The three fall scripts. Entered EITHER from TryBoulderFallThroughHole (which
@ has already played SE_FALL, set VAR_LAST_TALKED to the boulder and removed it)
@ OR from the talk backstop (which has done none of that). The common prologue
@ is written so both arrivals are correct:
@   removeobject VAR_LAST_TALKED -- on the engine path this is a NO-OP, because
@     RemoveObjectEventByLocalIdAndMap's body is skipped when
@     TryGetObjectEventIdByLocalIdAndMap fails to find the object
@     (src/event_object_movement.c:1537-1545). On the backstop path it does the
@     work, and its FlagSet is what makes the removal permanent (R1).
@   playse SE_FALL is issued HERE and only here. The C hook deliberately does
@     not sound it (pokefirered does, but pokefirered has no script leg), so it
@     plays exactly once on both paths.
@   SE_M_EARTHQUAKE stands in for GSC's `earthquake 80` screen shake -- the
@     sound without the shake, which is the part that reads.
@ Each script's ONLY durable output is one platform flag, which
@ BlackthornGym1F's ON_TRANSITION consumes.
@ ============================================================================
BlackthornGym2F_EventScript_BoulderFellHoleA::
	lockall
	call BlackthornGym2F_EventScript_BoulderFellCommon
	setflag FLAG_TRINITY_J_BGYM_PLATFORM_A
	msgbox BlackthornGym2F_Text_BoulderFellThrough, MSGBOX_DEFAULT
	releaseall
	end

BlackthornGym2F_EventScript_BoulderFellHoleB::
	lockall
	call BlackthornGym2F_EventScript_BoulderFellCommon
	setflag FLAG_TRINITY_J_BGYM_PLATFORM_B
	msgbox BlackthornGym2F_Text_BoulderFellThrough, MSGBOX_DEFAULT
	releaseall
	end

BlackthornGym2F_EventScript_BoulderFellHoleC::
	lockall
	call BlackthornGym2F_EventScript_BoulderFellCommon
	setflag FLAG_TRINITY_J_BGYM_PLATFORM_C
	msgbox BlackthornGym2F_Text_BoulderFellThrough, MSGBOX_DEFAULT
	releaseall
	end

BlackthornGym2F_EventScript_BoulderFellCommon::
	removeobject VAR_LAST_TALKED
	playse SE_FALL
	delay 20
	playse SE_M_EARTHQUAKE
	delay 30
	return

@ ============================================================================
@ G6 -- M4a's two 2F gym trainers keep their ids, GSC tiles and seen/beaten
@ text, and each gains GSC's own distinct after-battle line. Sight-triggered,
@ so G3's NO_MUSIC does not apply. Neither is a cut vertex: (4,1) and (4,11)
@ each cost exactly their own tile in the flood fill.
@ ============================================================================
BlackthornGym2F_EventScript_CODY::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERM_CODY, BlackthornGym2F_Text_CODYSeen, BlackthornGym2F_Text_CODYBeaten
	msgbox BlackthornGym2F_Text_CODYAfterBattle, MSGBOX_AUTOCLOSE
	end

BlackthornGym2F_EventScript_FRAN::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_FRAN, BlackthornGym2F_Text_FRANSeen, BlackthornGym2F_Text_FRANBeaten
	msgbox BlackthornGym2F_Text_FRANAfterBattle, MSGBOX_AUTOCLOSE
	end

BlackthornGym2F_Text_BoulderFellThrough:
	.string "The boulder fell through!$"

BlackthornGym2F_Text_CODYSeen:
	.string "It's not as if we all use\n"
	.string "dragon-type POKéMON.$"

BlackthornGym2F_Text_CODYBeaten:
	.string "Rats! If only I had a dragon!$"

BlackthornGym2F_Text_CODYAfterBattle:
	.string "Members of our dragon-user clan\n"
	.string "can use dragon POKéMON only after\l"
	.string "our MASTER allows it.$"

BlackthornGym2F_Text_FRANSeen:
	.string "I can't allow a nameless trainer\n"
	.string "past me!\p"
	.string "CLAIR would be livid if I did!$"

BlackthornGym2F_Text_FRANBeaten:
	.string "Awww… I lost…$"

BlackthornGym2F_Text_FRANAfterBattle:
	.string "Uh-oh… CLAIR is going to be mad…$"
