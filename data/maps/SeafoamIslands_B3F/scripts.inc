@ ============================================================================
@ Trinity M5b S9 -- SEAFOAM ISLANDS B3F. Strength-boulder-into-hole puzzle.
@
@ MUST-CITE adjudication (sub-plan 09-cinnabar-seafoam.md section 1): PROMOTE.
@ Persistent flags kept from the first pass (fix round did not touch this
@ finding): `FLAG_TRINITY_K_SEAFOAM_B3F_BOULDER_1/2` survive a real map
@ transition, which the T10 placeholder `FLAG_TEMP_5/6` cannot.
@
@ FIX ROUND (review: 4 Critical). Controller ruling replaced the first pass's
@ invented "stage 2" (push the revealed B4F boulder again, into the current)
@ with FRLG's real, simpler mechanism: the fallen boulders' PRESENCE on B4F
@ IS the calm condition (see SeafoamIslands_B4F/scripts.inc header) -- nothing
@ on B3F changes for that fix, but the boulder PLACEMENT here was also wrong
@ and is corrected in the same round (C2):
@
@ FRLG's real lock+payload design (read fresh from
@ pokefirered/data/maps/SeafoamIslands_B3F/map.json): boulder 4 (9,16) and
@ boulder 6 (13,16) are LOCKS (TRAINER_TYPE_NONE, no B4F reveal target,
@ blocking the approach to a hole); boulders 3 (6,17) and 5 (12,16) are the
@ PAYLOADS that actually fall. The first pass's decode was wrong: it treated
@ (9,16) as itself the payload for hole (9,18) via a straight 2-tile push,
@ when FRLG's own payload for that hole starts at (12,16) and the lock at
@ (9,16) exists specifically to block the LAST tile of that payload's route
@ ((9,16) is where the player must stand to push (9,17)->(9,18)).
@
@ Every tile of the corrected route decoded TRUE this time (Map queries, not
@ the ASCII grid the first pass's error came from), including the tile the
@ player stands on for each push (the row/column *above* each push, not just
@ the destination):
@   (12,16) payload start, col0 elev3 MB_CAVE
@   push SOUTH: player (12,15) col0 elev3 MB_CAVE -> boulder to (12,17) col0
@     elev3 MB_CAVE
@   push WEST x3 along row 17, player stands one tile EAST of the boulder
@     each time ((13,17)->(12,17)->(11,17), all col0 elev3 MB_CAVE, confirmed
@     open as the boulder vacates each): boulder (12,17)->(11,17)->(10,17)->
@     (9,17), all col0 elev3 MB_CAVE
@   push SOUTH: player (9,16) col0 elev3 MB_CAVE -> boulder (9,17)->(9,18),
@     the hole
@ The lock at (9,16) sits exactly on that last push's standing tile and MUST
@ be cleared sideways first -- confirmed it cannot be wasted into the hole
@ itself (its own north tile, (9,15), is col1 wall, so there is no standing
@ tile to push it south from); it can only be shoved west to (8,16) or east
@ to (10,16), both confirmed col0 elev3 MB_CAVE, clearing (9,16) for the
@ payload's final push.
@ Boulder 2's own route ((6,17)->south->hole (6,18)) is unchanged from the
@ first pass -- already correct, already unblocked (player stands (6,16),
@ col0 elev3 MB_CAVE), no lock needed there per the ruling.
@
@ I6: the hole->boulder reveal mapping is generic by HOLE POSITION, not by
@ boulder identity -- ANY boulder that lands in hole (6,18) reveals B4F's
@ counterpart there, ANY boulder in hole (9,18) reveals B4F's other one,
@ matching this tree's own engine hook (TryBoulderFallThroughHole, keyed on
@ (x,y) + the coord_event's elevation sentinel, never on which object it is).
@ The lock boulder's own talk-script backstop routes through one shared
@ CheckOnHole subroutine testing BOTH hole coordinates, not a hardcoded home
@ column, honoring the hook's own contract rather than assuming it away:
@ Blackthorn Gym 2F's own header rule is that ANY boulder in ANY hole plugs
@ THAT hole, generic by design. Checked directly (Map query, not assumed):
@ the lock's entire reachable set is 8 tiles, row 16 x=3..10 (walled at x=2
@ and x=11), and row 15 above it is solid wall end to end -- there is no
@ tile anywhere to stand and push it south, so it cannot reach either hole
@ from any position it can ever occupy. The generic dispatch costs nothing
@ and keeps that a verified fact of this map's own geometry rather than an
@ assumption baked into the script -- if a future edit ever opened a path,
@ the dispatch would already be correct without further changes.
@ ============================================================================

.equ NUM_BOULDERS_PRESENT, VAR_TEMP_2

@ setmetatile authoring must live in MAP_SCRIPT_ON_LOAD (qa_sweep.py's own gate:
@ InitMapLayoutData wipes the grid immediately after ON_TRANSITION runs,
@ src/overworld.c:876-877 + src/fieldmap.c:96-103) -- not ON_TRANSITION.
SeafoamIslands_B3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SeafoamIslands_B3F_OnLoad
	.byte 0

SeafoamIslands_B3F_OnLoad::
	setvar NUM_BOULDERS_PRESENT, 0
	call_if_unset FLAG_TRINITY_K_SEAFOAM_B3F_BOULDER_1, SeafoamIslands_B3F_EventScript_AddBoulderPresent
	call_if_unset FLAG_TRINITY_K_SEAFOAM_B3F_BOULDER_2, SeafoamIslands_B3F_EventScript_AddBoulderPresent
	goto_if_eq NUM_BOULDERS_PRESENT, 0, SeafoamIslands_B3F_EventScript_CalmCurrent
	end

SeafoamIslands_B3F_EventScript_AddBoulderPresent::
	addvar NUM_BOULDERS_PRESENT, 1
	return

@ Both payload boulders gone (fallen through their holes) -- still THIS
@ floor's own current. Uniform METATILE_General_CalmWater sweep, not FRLG's
@ duplicate hand-painted layout: see sub-plan section 5.5 for the full
@ reasoning (unaffected by this fix round -- the calm-water mechanism itself
@ was not part of the C1-C3 findings).
SeafoamIslands_B3F_EventScript_CalmCurrent::
	setmetatile 15,  5, METATILE_General_CalmWater, 0
	setmetatile 15,  6, METATILE_General_CalmWater, 0
	setmetatile 16,  5, METATILE_General_CalmWater, 0
	setmetatile 16,  6, METATILE_General_CalmWater, 0
	setmetatile 17,  5, METATILE_General_CalmWater, 0
	setmetatile 17,  6, METATILE_General_CalmWater, 0
	setmetatile 18,  5, METATILE_General_CalmWater, 0
	setmetatile 18,  6, METATILE_General_CalmWater, 0
	setmetatile 19,  5, METATILE_General_CalmWater, 0
	setmetatile 19,  6, METATILE_General_CalmWater, 0
	setmetatile 19, 11, METATILE_General_CalmWater, 0
	setmetatile 19, 12, METATILE_General_CalmWater, 0
	setmetatile 19, 13, METATILE_General_CalmWater, 0
	setmetatile 20,  5, METATILE_General_CalmWater, 0
	setmetatile 20,  6, METATILE_General_CalmWater, 0
	setmetatile 20, 12, METATILE_General_CalmWater, 0
	setmetatile 20, 13, METATILE_General_CalmWater, 0
	setmetatile 21,  5, METATILE_General_CalmWater, 0
	setmetatile 21,  6, METATILE_General_CalmWater, 0
	setmetatile 21, 12, METATILE_General_CalmWater, 0
	setmetatile 21, 13, METATILE_General_CalmWater, 0
	setmetatile 22,  5, METATILE_General_CalmWater, 0
	setmetatile 22,  6, METATILE_General_CalmWater, 0
	setmetatile 22, 11, METATILE_General_CalmWater, 0
	setmetatile 22, 12, METATILE_General_CalmWater, 0
	setmetatile 22, 13, METATILE_General_CalmWater, 0
	setmetatile 23,  5, METATILE_General_CalmWater, 0
	setmetatile 23,  6, METATILE_General_CalmWater, 0
	setmetatile 23,  7, METATILE_General_CalmWater, 0
	setmetatile 23,  9, METATILE_General_CalmWater, 0
	setmetatile 23, 10, METATILE_General_CalmWater, 0
	setmetatile 23, 11, METATILE_General_CalmWater, 0
	setmetatile 23, 12, METATILE_General_CalmWater, 0
	setmetatile 23, 13, METATILE_General_CalmWater, 0
	setmetatile 24,  5, METATILE_General_CalmWater, 0
	setmetatile 24,  6, METATILE_General_CalmWater, 0
	setmetatile 24,  7, METATILE_General_CalmWater, 0
	setmetatile 24,  9, METATILE_General_CalmWater, 0
	setmetatile 24, 10, METATILE_General_CalmWater, 0
	setmetatile 24, 11, METATILE_General_CalmWater, 0
	setmetatile 24, 12, METATILE_General_CalmWater, 0
	setmetatile 24, 13, METATILE_General_CalmWater, 0
	setmetatile 25, 12, METATILE_General_CalmWater, 0
	setmetatile 25, 13, METATILE_General_CalmWater, 0
	setmetatile 25, 14, METATILE_General_CalmWater, 0
	setmetatile 25, 15, METATILE_General_CalmWater, 0
	setmetatile 25, 16, METATILE_General_CalmWater, 0
	setmetatile 25, 17, METATILE_General_CalmWater, 0
	setmetatile 26, 12, METATILE_General_CalmWater, 0
	setmetatile 26, 13, METATILE_General_CalmWater, 0
	setmetatile 26, 14, METATILE_General_CalmWater, 0
	setmetatile 26, 15, METATILE_General_CalmWater, 0
	setmetatile 26, 16, METATILE_General_CalmWater, 0
	setmetatile 26, 17, METATILE_General_CalmWater, 0
	setmetatile 27, 13, METATILE_General_CalmWater, 0
	setmetatile 28, 13, METATILE_General_CalmWater, 0
	special DrawWholeMapView
	end

@ ----------------------------------------------------------------------------
@ Hole (6,18): boulder 2 (6,17) falls here into B4F (8,18).
@ Hole (9,18): the payload boulder (12,16), routed via the lock's cleared
@ tile, falls here into B4F (9,18).
@ Player-fall landings reuse this map's own (dead in this engine, see
@ sub-plan 5.3) warp_events' destinations: (6,18)->B4F(8,17), (9,18)->B4F
@ (9,17), both live current on B4F -- traced safe in the fix round, see the
@ report's C3 section (this floor's own scripting is unaffected by that
@ finding; the trace concerns B4F's engine behavior only).
@ ----------------------------------------------------------------------------
SeafoamIslands_B3F_EventScript_FallToHole1::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_SEAFOAM_ISLANDS_B4F, 8, 17
	waitstate
	end

SeafoamIslands_B3F_EventScript_FallToHole2::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_SEAFOAM_ISLANDS_B4F, 9, 17
	waitstate
	end

SeafoamIslands_B3F_EventScript_BoulderFellHole1::
	lockall
	removeobject VAR_LAST_TALKED
	playse SE_FALL
	delay 20
	clearflag FLAG_TRINITY_K_SEAFOAM_B4F_BOULDER_2
	releaseall
	end

SeafoamIslands_B3F_EventScript_BoulderFellHole2::
	lockall
	removeobject VAR_LAST_TALKED
	playse SE_FALL
	delay 20
	clearflag FLAG_TRINITY_K_SEAFOAM_B4F_BOULDER_1
	releaseall
	end

@ ----------------------------------------------------------------------------
@ All three boulders (lock + both payloads). Primary path: the engine hook
@ removes a boulder the instant it lands in a hole, so it can never be talked
@ to there. Backstop path (Blackthorn precedent, mandatory not decoration --
@ the founder gate is clean-compile + review, no play-tests, so a new runtime
@ hook is the one thing that cannot be proven by running it): every boulder's
@ own talk script routes through ONE shared CheckOnHole subroutine testing
@ its current position against BOTH hole coordinates -- generic by hole
@ position (I6), not by which boulder it is, so the lock plugs whichever hole
@ it's shoved into just as validly as either payload.
@ ----------------------------------------------------------------------------
SeafoamIslands_B3F_EventScript_Lock1::
	getobjectxy VAR_LAST_TALKED, 0, VAR_0x8004, VAR_0x8005
	call SeafoamIslands_B3F_EventScript_CheckOnHole
	goto_if_eq VAR_RESULT, 1, SeafoamIslands_B3F_EventScript_BoulderFellHole1
	goto_if_eq VAR_RESULT, 2, SeafoamIslands_B3F_EventScript_BoulderFellHole2
	goto EventScript_StrengthBoulder
	end

SeafoamIslands_B3F_EventScript_Boulder1::
	getobjectxy VAR_LAST_TALKED, 0, VAR_0x8004, VAR_0x8005
	call SeafoamIslands_B3F_EventScript_CheckOnHole
	goto_if_eq VAR_RESULT, 1, SeafoamIslands_B3F_EventScript_BoulderFellHole1
	goto_if_eq VAR_RESULT, 2, SeafoamIslands_B3F_EventScript_BoulderFellHole2
	goto EventScript_StrengthBoulder
	end

SeafoamIslands_B3F_EventScript_Boulder2::
	getobjectxy VAR_LAST_TALKED, 0, VAR_0x8004, VAR_0x8005
	call SeafoamIslands_B3F_EventScript_CheckOnHole
	goto_if_eq VAR_RESULT, 1, SeafoamIslands_B3F_EventScript_BoulderFellHole1
	goto_if_eq VAR_RESULT, 2, SeafoamIslands_B3F_EventScript_BoulderFellHole2
	goto EventScript_StrengthBoulder
	end

@ VAR_0x8004/0x8005 already hold the talked-to boulder's (x,y). VAR_RESULT:
@ 1 if standing in hole (6,18), 2 if standing in hole (9,18), 0 otherwise.
SeafoamIslands_B3F_EventScript_CheckOnHole::
	setvar VAR_RESULT, 0
	goto_if_ne VAR_0x8004, 6, SeafoamIslands_B3F_EventScript_CheckOnHole2
	goto_if_ne VAR_0x8005, 18, SeafoamIslands_B3F_EventScript_CheckOnHole2
	setvar VAR_RESULT, 1
	return

SeafoamIslands_B3F_EventScript_CheckOnHole2::
	goto_if_ne VAR_0x8004, 9, Common_EventScript_NopReturn
	goto_if_ne VAR_0x8005, 18, Common_EventScript_NopReturn
	setvar VAR_RESULT, 2
	return
