@ ============================================================================
@ Trinity M5b S1 -- THE GYM PATTERN (G1-G7), copied from VioletGym/scripts.inc
@ (map/leader/badge/TM/type substituted) + the FRLG trash-can switch puzzle,
@ script-reimplemented (see docs/superpowers/plans/m5b/01-arrival-vermilion.md
@ section 4.3 for the faithful-vs-simplified design call: the RANDOM SWITCH
@ LOGIC is faithful to FRLG, ported via this engine's own `random` opcode in
@ place of the FRLG-only `SetVermilionTrashCans` special (absent from this
@ tree); the BARRIER's cosmetic beam-node animation is simplified to a plain
@ locked/open swap, since the ported Kanto tileset carries no symbolic
@ METATILE_* constants for it and hand-guessing 30 numeric ids for a purely
@ cosmetic payoff is exactly the risk class this dispatch was warned against.
@ `famechecker`/`QuestLog_CutRecording` (FRLG's replay/fame system) do not
@ exist in this tree and are dropped, not substituted.
@ ============================================================================

.equ FOUND_FIRST_SWITCH, FLAG_TEMP_1
.equ TRASH_CAN_ID,       VAR_TEMP_1
.equ SWITCH1_ID,         VAR_TEMP_2
.equ SWITCH2_ID,         VAR_TEMP_3

VermilionCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Gym_OnTransition
	.byte 0

@ D-pattern: ON_LOAD is the single setmetatile-authoring site for the barrier
@ (brief-pinned; matches FRLG's own choice for this exact gym). If already
@ solved, re-stamp the OPEN floor over the shipped-locked barrier -- map.bin
@ always reloads the locked baseline, so a solved gym must re-open on every
@ load. No DrawWholeMapView here: nothing is on screen yet at ON_LOAD time.
VermilionCity_Gym_OnLoad::
	call_if_set FLAG_TRINITY_K_VERMGYM_SWITCHES_FOUND, VermilionCity_Gym_EventScript_StampOpenFloor
	end

@ The barrier: (3-7,6) and (3-7,7), 10 tiles, shipped col=1 (locked) by
@ default -- decoded raw metatile ids 0x2a9/0x2aa/0x285/0x2ab/0x2ac (row 6)
@ and 0x2b1/0x2b2/0x28d/0x2b3/0x2b4 (row 7), all distinct FRLG beam-node
@ graphics with no symbolic name in this tree. 0x281 is a plain floor
@ metatile already load-bearing at (5,8)/(4,17)/(4,18)/(5,9) on this exact
@ map -- its walkability and art are independently proven, not guessed.
@ setmetatile's own trailing arg authors passability directly, so 0x281's
@ baked attributes don't need to match.
VermilionCity_Gym_EventScript_StampOpenFloor::
	setmetatile 3, 6, 0x281, 0
	setmetatile 4, 6, 0x281, 0
	setmetatile 5, 6, 0x281, 0
	setmetatile 6, 6, 0x281, 0
	setmetatile 7, 6, 0x281, 0
	setmetatile 3, 7, 0x281, 0
	setmetatile 4, 7, 0x281, 0
	setmetatile 5, 7, 0x281, 0
	setmetatile 6, 7, 0x281, 0
	setmetatile 7, 7, 0x281, 0
	return

@ Re-roll which two cans hide the switches on every (re-)entry, unless
@ already solved -- FRLG's own InitTrashCans does the same (its own
@ FLAG_TEMP_1-based FOUND_FIRST_SWITCH does not survive a map reload
@ either; TRASH_CAN_ID/SWITCH1_ID/SWITCH2_ID are VAR_TEMP_*, likewise
@ cleared every load by ClearTempFieldEventData -- no persistent scene var
@ needed, see the sub-plan section 1).
VermilionCity_Gym_OnTransition::
	goto_if_set FLAG_TRINITY_K_VERMGYM_SWITCHES_FOUND, VermilionCity_Gym_EventScript_SkipRoll
	call VermilionCity_Gym_EventScript_RollSwitches
VermilionCity_Gym_EventScript_SkipRoll::
	end

@ ============================================================================
@ Fix round 1 (review Finding 2, Important, RULING): SWITCH2_ID is NOT a
@ uniform-random 1..15 pick -- that made the informed second guess ~1/14
@ instead of FRLG's real ~1/3, roughly 5x longer than canon, and the
@ "faithful" claim in the sub-plan/report was wrong. Restored FRLG's actual
@ adjacency rule (pokefirered src/field_specials.c:552-650,
@ SetVermilionTrashCans): SWITCH2 is always an orthogonal grid-neighbor of
@ SWITCH1 on the 5x3 trash-can layout, picked uniformly among that cell's
@ valid neighbors (2 for a corner, 3 for an edge, 4 for the interior
@ three), edge-clamped by construction (never computed out of range, so
@ FRLG's own dead ">15" safety clamp -- verified unreachable for every one
@ of the 15 cases in its C source -- has no analogue needed here).
@
@ GRID (id = (row-1)*5 + col, matching this map's own TrashCan1..15
@ bg_events at x=1,3,5,7,9 / y=10,12,14):
@     1  2  3  4  5
@     6  7  8  9 10
@    11 12 13 14 15
@
@ DERIVATION TABLE (per SWITCH1, its valid SWITCH2 set -- cross-checked
@ 1:1 against every case of the FRLG switch statement):
@   1:{2,6}      2:{1,3,7}     3:{2,4,8}     4:{3,5,9}    5:{4,10}
@   6:{1,7,11}   7:{2,6,8,12}  8:{3,7,9,13}  9:{4,8,10,14} 10:{5,9,15}
@  11:{6,12}    12:{7,11,13}  13:{8,12,14}  14:{9,13,15}  15:{10,14}
@
@ Implementation mirrors FRLG's own shape exactly: SWITCH2_ID <- SWITCH1_ID,
@ then one of four shared deltas (+-1, +-5, the grid's own row/col stride)
@ is applied, chosen by a `random <n>` sized to that position's neighbor
@ count (2/3/3/4, same as FRLG's Random()%2, %3, %4).
@ ============================================================================
VermilionCity_Gym_EventScript_RollSwitches::
	random 15
	addvar VAR_RESULT, 1
	copyvar SWITCH1_ID, VAR_RESULT
	copyvar SWITCH2_ID, SWITCH1_ID
	goto_if_eq SWITCH1_ID, 1, VermilionCity_Gym_EventScript_Neighbor_CornerTL
	goto_if_eq SWITCH1_ID, 2, VermilionCity_Gym_EventScript_Neighbor_EdgeTop
	goto_if_eq SWITCH1_ID, 3, VermilionCity_Gym_EventScript_Neighbor_EdgeTop
	goto_if_eq SWITCH1_ID, 4, VermilionCity_Gym_EventScript_Neighbor_EdgeTop
	goto_if_eq SWITCH1_ID, 5, VermilionCity_Gym_EventScript_Neighbor_CornerTR
	goto_if_eq SWITCH1_ID, 6, VermilionCity_Gym_EventScript_Neighbor_EdgeLeft
	goto_if_eq SWITCH1_ID, 7, VermilionCity_Gym_EventScript_Neighbor_Center
	goto_if_eq SWITCH1_ID, 8, VermilionCity_Gym_EventScript_Neighbor_Center
	goto_if_eq SWITCH1_ID, 9, VermilionCity_Gym_EventScript_Neighbor_Center
	goto_if_eq SWITCH1_ID, 10, VermilionCity_Gym_EventScript_Neighbor_EdgeRight
	goto_if_eq SWITCH1_ID, 11, VermilionCity_Gym_EventScript_Neighbor_CornerBL
	goto_if_eq SWITCH1_ID, 12, VermilionCity_Gym_EventScript_Neighbor_EdgeBottom
	goto_if_eq SWITCH1_ID, 13, VermilionCity_Gym_EventScript_Neighbor_EdgeBottom
	goto_if_eq SWITCH1_ID, 14, VermilionCity_Gym_EventScript_Neighbor_EdgeBottom
	@ SWITCH1_ID == 15, the only value not tested above (random 15 + addvar 1
	@ bounds it to 1..15) -- bottom-right corner.
	goto VermilionCity_Gym_EventScript_Neighbor_CornerBR

@ id 1 {2,6}: E or S.
VermilionCity_Gym_EventScript_Neighbor_CornerTL::
	random 2
	goto_if_eq VAR_RESULT, 0, VermilionCity_Gym_EventScript_SwitchPlus1
	goto VermilionCity_Gym_EventScript_SwitchPlus5

@ id 5 {4,10}: S or W.
VermilionCity_Gym_EventScript_Neighbor_CornerTR::
	random 2
	goto_if_eq VAR_RESULT, 0, VermilionCity_Gym_EventScript_SwitchPlus5
	goto VermilionCity_Gym_EventScript_SwitchMinus1

@ id 11 {6,12}: N or E.
VermilionCity_Gym_EventScript_Neighbor_CornerBL::
	random 2
	goto_if_eq VAR_RESULT, 0, VermilionCity_Gym_EventScript_SwitchMinus5
	goto VermilionCity_Gym_EventScript_SwitchPlus1

@ id 15 {10,14}: N or W.
VermilionCity_Gym_EventScript_Neighbor_CornerBR::
	random 2
	goto_if_eq VAR_RESULT, 0, VermilionCity_Gym_EventScript_SwitchMinus5
	goto VermilionCity_Gym_EventScript_SwitchMinus1

@ ids 2,3,4 {W,E,S}: E, S, or W.
VermilionCity_Gym_EventScript_Neighbor_EdgeTop::
	random 3
	goto_if_eq VAR_RESULT, 0, VermilionCity_Gym_EventScript_SwitchPlus1
	goto_if_eq VAR_RESULT, 1, VermilionCity_Gym_EventScript_SwitchPlus5
	goto VermilionCity_Gym_EventScript_SwitchMinus1

@ id 6 {1,7,11}: N, E, or S.
VermilionCity_Gym_EventScript_Neighbor_EdgeLeft::
	random 3
	goto_if_eq VAR_RESULT, 0, VermilionCity_Gym_EventScript_SwitchMinus5
	goto_if_eq VAR_RESULT, 1, VermilionCity_Gym_EventScript_SwitchPlus1
	goto VermilionCity_Gym_EventScript_SwitchPlus5

@ id 10 {5,9,15}: N, S, or W.
VermilionCity_Gym_EventScript_Neighbor_EdgeRight::
	random 3
	goto_if_eq VAR_RESULT, 0, VermilionCity_Gym_EventScript_SwitchMinus5
	goto_if_eq VAR_RESULT, 1, VermilionCity_Gym_EventScript_SwitchPlus5
	goto VermilionCity_Gym_EventScript_SwitchMinus1

@ ids 12,13,14 {N,E,W}: N, E, or W.
VermilionCity_Gym_EventScript_Neighbor_EdgeBottom::
	random 3
	goto_if_eq VAR_RESULT, 0, VermilionCity_Gym_EventScript_SwitchMinus5
	goto_if_eq VAR_RESULT, 1, VermilionCity_Gym_EventScript_SwitchPlus1
	goto VermilionCity_Gym_EventScript_SwitchMinus1

@ ids 7,8,9 {N,W,E,S}: N, E, S, or W.
VermilionCity_Gym_EventScript_Neighbor_Center::
	random 4
	goto_if_eq VAR_RESULT, 0, VermilionCity_Gym_EventScript_SwitchMinus5
	goto_if_eq VAR_RESULT, 1, VermilionCity_Gym_EventScript_SwitchPlus1
	goto_if_eq VAR_RESULT, 2, VermilionCity_Gym_EventScript_SwitchPlus5
	goto VermilionCity_Gym_EventScript_SwitchMinus1

@ Four shared deltas, reached only via `goto` (never `call`) from the shape
@ handlers above, so `return` here unwinds straight to RollSwitches' own
@ caller (VermilionCity_Gym_OnTransition / TrySwitchTwo's reset), one call
@ frame, matching RollSwitches' own contract.
VermilionCity_Gym_EventScript_SwitchPlus1::
	addvar SWITCH2_ID, 1
	return

VermilionCity_Gym_EventScript_SwitchMinus1::
	subvar SWITCH2_ID, 1
	return

VermilionCity_Gym_EventScript_SwitchPlus5::
	addvar SWITCH2_ID, 5
	return

VermilionCity_Gym_EventScript_SwitchMinus5::
	subvar SWITCH2_ID, 5
	return

VermilionCity_Gym_EventScript_TrashCan1::
	lockall
	setvar TRASH_CAN_ID, 1
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan2::
	lockall
	setvar TRASH_CAN_ID, 2
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan3::
	lockall
	setvar TRASH_CAN_ID, 3
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan4::
	lockall
	setvar TRASH_CAN_ID, 4
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan5::
	lockall
	setvar TRASH_CAN_ID, 5
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan6::
	lockall
	setvar TRASH_CAN_ID, 6
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan7::
	lockall
	setvar TRASH_CAN_ID, 7
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan8::
	lockall
	setvar TRASH_CAN_ID, 8
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan9::
	lockall
	setvar TRASH_CAN_ID, 9
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan10::
	lockall
	setvar TRASH_CAN_ID, 10
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan11::
	lockall
	setvar TRASH_CAN_ID, 11
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan12::
	lockall
	setvar TRASH_CAN_ID, 12
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan13::
	lockall
	setvar TRASH_CAN_ID, 13
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan14::
	lockall
	setvar TRASH_CAN_ID, 14
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan15::
	lockall
	setvar TRASH_CAN_ID, 15
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan::
	goto_if_set FLAG_TRINITY_K_VERMGYM_SWITCHES_FOUND, VermilionCity_Gym_EventScript_LocksAlreadyOpen
	goto_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_TrySwitchTwo
	goto_if_eq TRASH_CAN_ID, SWITCH1_ID, VermilionCity_Gym_EventScript_FoundSwitchOne
	msgbox VermilionCity_Gym_Text_JustTrash, MSGBOX_DEFAULT
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchOne::
	msgbox VermilionCity_Gym_Text_FirstLockOpened, MSGBOX_DEFAULT
	playse SE_PIN
	waitse
	setflag FOUND_FIRST_SWITCH
	releaseall
	end

VermilionCity_Gym_EventScript_TrySwitchTwo::
	goto_if_eq TRASH_CAN_ID, SWITCH2_ID, VermilionCity_Gym_EventScript_FoundSwitchTwo
	msgbox VermilionCity_Gym_Text_LocksReset, MSGBOX_DEFAULT
	clearflag FOUND_FIRST_SWITCH
	call VermilionCity_Gym_EventScript_RollSwitches
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchTwo::
	msgbox VermilionCity_Gym_Text_SecondLockOpened, MSGBOX_DEFAULT
	closemessage
	call VermilionCity_Gym_EventScript_StampOpenFloor
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	setflag FLAG_TRINITY_K_VERMGYM_SWITCHES_FOUND
	releaseall
	end

VermilionCity_Gym_EventScript_LocksAlreadyOpen::
	msgbox VermilionCity_Gym_Text_JustTrash, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@ G1-G7 -- SURGE. Canonical file: VioletGym/scripts.inc.
@ G1: TRAINER_TYPE_NONE, sight 0, flag 0, MOVEMENT_TYPE_FACE_DOWN, at the
@ FRLG tile (5,2) (decoded col=0 elev=3 MB_NORMAL, free), local_id appended
@ to map.json after Baily/Dwayne/GymGuy/Tucker so none of T10's ids shift.
@ Trinity M6 P3: Sprite OBJ_EVENT_GFX_LT_SURGE (real FRLG OW port) and
@ TRAINER_LTSURGE.Pic = Surge (real FRLG front pic) -- the Wattson
@ substitute this comment used to describe is retired at this object.
@ ============================================================================
VermilionCity_Gym_EventScript_LtSurge::
	trainerbattle_single TRAINER_LTSURGE, VermilionCity_Gym_Text_LtSurgeIntro, VermilionCity_Gym_Text_LtSurgeDefeat, VermilionCity_Gym_EventScript_LtSurgeDefeated, NO_MUSIC
	goto_if_unset FLAG_TRINITY_K_SURGE_TM24, VermilionCity_Gym_EventScript_GiveThunderbolt
	msgbox VermilionCity_Gym_Text_LtSurgePostBattle, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_EventScript_LtSurgeDefeated::
	message VermilionCity_Gym_Text_ReceivedThunderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_TRINITY_BADGE19
	msgbox VermilionCity_Gym_Text_ThunderBadgeInfo, MSGBOX_DEFAULT
	goto VermilionCity_Gym_EventScript_GiveThunderbolt
	end

VermilionCity_Gym_EventScript_GiveThunderbolt::
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_K_SURGE_TM24
	msgbox VermilionCity_Gym_Text_ExplainThunderbolt, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ G6 -- T10's gym trainers, ids/tiles/wiring reviewed and kept, placeholder
@ "..." text replaced with real Kanto-dockworker dialogue + a distinct
@ post-battle line each.
@ ============================================================================
VermilionCity_Gym_EventScript_Baily::
	trainerbattle_single TRAINER_KANTO_ENGINEER_BAILY, VermilionCity_Gym_Text_BailySeen, VermilionCity_Gym_Text_BailyBeaten
	msgbox VermilionCity_Gym_Text_BailyPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Dwayne::
	trainerbattle_single TRAINER_KANTO_SAILOR_DWAYNE, VermilionCity_Gym_Text_DwayneSeen, VermilionCity_Gym_Text_DwayneBeaten
	msgbox VermilionCity_Gym_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Tucker::
	trainerbattle_single TRAINER_KANTO_GENTLEMAN_TUCKER, VermilionCity_Gym_Text_TuckerSeen, VermilionCity_Gym_Text_TuckerBeaten
	msgbox VermilionCity_Gym_Text_TuckerPostBattle, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ G4 -- the guide. (4,17), OBJ_EVENT_GFX_EXPERT_M, matches VioletGym's guide
@ graphics. Roster verified against trainers.party + species_info.h: SURGE
@ runs ELECTRODE/MAGNETON/ELECTABUZZ/JOLTEON/RAICHU L77-79, all ELECTRIC
@ (MAGNETON adds MAGNEMITE_FAMILY_TYPE2, STEEL in this build). GROUND moves
@ hit every one of them for at least double -- kept to that floor claim
@ rather than an exact multiplier, since MAGNETON's second type depends on
@ P_UPDATED_STATS.
@ ============================================================================
VermilionCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_BADGE19, VermilionCity_Gym_EventScript_GymGuyPostVictory
	msgbox VermilionCity_Gym_Text_GymGuyAdvice, MSGBOX_DEFAULT
	release
	end

@ M7b Task 15 (finding #6): the guide states the player's LIVE badge count.
@ The tally reads the flags and buffers the number itself -- see
@ data/scripts/trinity_kanto.inc.
VermilionCity_Gym_EventScript_GymGuyPostVictory::
	msgbox VermilionCity_Gym_Text_GymGuyPostVictory, MSGBOX_DEFAULT
	call Trinity_EventScript_KantoBadgeTally
	@ M7b Task 14 (finding #9): once the badge is won this guide doubles as
	@ a pointer. The branch above is already the badge flag, so nothing new
	@ is read or written here; the ladder releases for us.
	goto Trinity_EventScript_KantoGuide
	end

@ ============================================================================
@ G5 -- the statues. (3,17)/(7,17) decode col=1 MB_SIGNPOST (T10-placed,
@ correct); read tiles (3,18)/(7,18) col=0 elev=3, free. Facing constraint
@ corrected ANY -> NORTH in map.json to match the established pattern
@ exactly (VioletGym's own two statues use BG_EVENT_PLAYER_FACING_NORTH) --
@ coordinates untouched, this is a facing-constraint fix, not a re-place.
@ ============================================================================
VermilionCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_TRINITY_BADGE19, VermilionCity_Gym_EventScript_GymStatueCertified
	msgbox VermilionCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

VermilionCity_Gym_EventScript_GymStatue_2::
	lockall
	goto_if_set FLAG_TRINITY_BADGE19, VermilionCity_Gym_EventScript_GymStatueCertified
	msgbox VermilionCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

VermilionCity_Gym_EventScript_GymStatueCertified::
	msgbox VermilionCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@ Text
@ ============================================================================
VermilionCity_Gym_Text_LtSurgeIntro:
	.string "SURGE: A GYM full of trash cans,\n"
	.string "and half this region still can't\l"
	.string "find the switches.\p"
	.string "Two LEAGUES down and you're still\n"
	.string "standing in my GYM. Big electric\l"
	.string "surprise, CHAMPION -- let's see you\l"
	.string "handle a third.$"

@ RBY canon: "Big Electric SURPRISE! Hahaha!"
VermilionCity_Gym_Text_LtSurgeDefeat:
	.string "Big electric surprise, all right.\n"
	.string "Just not the one I meant.$"

VermilionCity_Gym_Text_ReceivedThunderBadge:
	.string "{PLAYER} received the\n"
	.string "THUNDERBADGE from SURGE.$"

VermilionCity_Gym_Text_ThunderBadgeInfo:
	.string "SURGE: THUNDERBADGE.\p"
	.string "Won't hit any harder for you. You\n"
	.string "already hit hard enough.\p"
	.string "It just means KANTO's noticed.\n"
	.string "Seven of these, and VIRIDIAN has\l"
	.string "to open the door.\p"
	.string "That's the THUNDERBADGE.\n"
	.string "Take this too.$"

VermilionCity_Gym_Text_ExplainThunderbolt:
	.string "SURGE: TM24. THUNDERBOLT.\p"
	.string "You may already carry one. Doesn't\n"
	.string "matter -- mine's been through a\l"
	.string "few GYM ceilings.\p"
	.string "Full power, no charge-up, no\n"
	.string "excuses. Teach it to whatever you\l"
	.string "like. It won't wear out.$"

VermilionCity_Gym_Text_LtSurgePostBattle:
	.string "SURGE: Go rattle somebody else's\n"
	.string "cage.$"

VermilionCity_Gym_Text_BailySeen:
	.string "Watch the trash cans -- SURGE\n"
	.string "wires half of them.$"

VermilionCity_Gym_Text_BailyBeaten:
	.string "Ha! Shocked myself worse than\n"
	.string "that once.$"

VermilionCity_Gym_Text_BailyPostBattle:
	.string "SURGE trained us on the docks.\n"
	.string "Losing to him builds character.$"

VermilionCity_Gym_Text_DwayneSeen:
	.string "Every PIKACHU on this dock's a\n"
	.string "SURGE loaner. Don't ask how.$"

VermilionCity_Gym_Text_DwayneBeaten:
	.string "Current's stronger than I\n"
	.string "figured.$"

VermilionCity_Gym_Text_DwaynePostBattle:
	.string "Find the second switch yet? I\n"
	.string "never do.$"

VermilionCity_Gym_Text_TuckerSeen:
	.string "A GENTLEMAN doesn't dig through\n"
	.string "trash. I make an exception here.$"

VermilionCity_Gym_Text_TuckerBeaten:
	.string "Quite the jolt. Quite the loss.$"

VermilionCity_Gym_Text_TuckerPostBattle:
	.string "SURGE is through that far door.\n"
	.string "Mind the cans on your way.$"

VermilionCity_Gym_Text_GymGuyAdvice:
	.string "Hey! Champion, right? Word travels\n"
	.string "fast on this dock.\p"
	.string "SURGE runs ELECTRIC types --\n"
	.string "ELECTRODE, MAGNETON, ELECTABUZZ,\l"
	.string "JOLTEON, RAICHU. LEVEL 77 to 79.\p"
	.string "GROUND moves are your answer.\n"
	.string "Every one of his POKéMON takes\l"
	.string "at least double from them.\p"
	.string "Oh -- and two of these trash cans\n"
	.string "aren't trash. Good luck finding\l"
	.string "which.$"

VermilionCity_Gym_Text_GymGuyPostVictory:
	.string "Straight through SURGE! Found\n"
	.string "both switches too, I'd guess.\p"
	.string "THUNDERBADGE. One of seven.$"

VermilionCity_Gym_Text_GymStatue:
	.string "VERMILION CITY POKéMON GYM\n"
	.string "LEADER: SURGE\p"
	.string "The Lightning American$"

VermilionCity_Gym_Text_GymStatueCertified:
	.string "VERMILION CITY POKéMON GYM\n"
	.string "LEADER: SURGE\p"
	.string "SURGE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

@ Trash-can puzzle text. Replaces T10's 15 flat flavor placeholders -- once
@ the cans are interactive puzzle objects rather than read-only signs, a
@ single set of state-dependent lines (wrong guess / first switch / reset /
@ second switch) is what the mechanic actually needs; see the sub-plan.
VermilionCity_Gym_Text_JustTrash:
	.string "Just trash.$"

VermilionCity_Gym_Text_FirstLockOpened:
	.string "A switch! One of the locks up\n"
	.string "ahead just clicked open.$"

VermilionCity_Gym_Text_LocksReset:
	.string "Wrong can -- and that resets the\n"
	.string "other lock too. Try again.$"

VermilionCity_Gym_Text_SecondLockOpened:
	.string "The second switch! Both locks\n"
	.string "are open now.$"
