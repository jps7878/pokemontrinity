BirthIsland_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BirthIsland_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, BirthIsland_Exterior_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, BirthIsland_Exterior_OnReturnToField
	.byte 0

BirthIsland_Exterior_OnReturnToField:
	special SetDeoxysRockPalette
	end

BirthIsland_Exterior_OnTransition:
	setflag FLAG_MAP_SCRIPT_CHECKED_DEOXYS
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	setvar VAR_DEOXYS_ROCK_STEP_COUNT, 0
	setvar VAR_DEOXYS_ROCK_LEVEL, 0
	call_if_set FLAG_BATTLED_DEOXYS, BirthIsland_Exterior_EventScript_HideDeoxysAndPuzzle
	call_if_unset FLAG_BATTLED_DEOXYS, BirthIsland_Exterior_EventScript_TryShowDeoxysPuzzle
	end

BirthIsland_Exterior_EventScript_HideDeoxysAndPuzzle::
	setflag FLAG_HIDE_DEOXYS
	setflag FLAG_HIDE_BIRTH_ISLAND_DEOXYS_TRIANGLE
	return

BirthIsland_Exterior_EventScript_TryShowDeoxysPuzzle::
	goto_if_set FLAG_DEFEATED_DEOXYS, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_BIRTH_ISLAND_DEOXYS_TRIANGLE
	clearflag FLAG_DEOXYS_ROCK_COMPLETE
	return

BirthIsland_Exterior_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BirthIsland_Exterior_EventScript_TryRemoveDeoxys
	end

BirthIsland_Exterior_EventScript_TryRemoveDeoxys::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_BIRTH_ISLAND_DEOXYS
	return

BirthIsland_Exterior_EventScript_Triangle::
	lock
	faceplayer
	special DoDeoxysRockInteraction
	waitstate
	switch VAR_RESULT
	case DEOXYS_ROCK_FAILED,     BirthIsland_Exterior_EventScript_Failed
	case DEOXYS_ROCK_PROGRESSED, BirthIsland_Exterior_EventScript_Progressed
	case DEOXYS_ROCK_SOLVED,     BirthIsland_Exterior_EventScript_Deoxys
	case DEOXYS_ROCK_COMPLETE,   BirthIsland_Exterior_EventScript_Complete
	end

@ The actual rock triangle movement is handled by DoDeoxysRockInteraction.
@ Unless the player has solved the puzzle and needs to encounter Deoxys,
@ there's nothing else the script needs to do.
BirthIsland_Exterior_EventScript_Failed::
	release
	end

BirthIsland_Exterior_EventScript_Progressed::
	release
	end

BirthIsland_Exterior_EventScript_Complete::
	release
	end

BirthIsland_Exterior_EventScript_Deoxys::
	waitse
	setfieldeffectargument 0, LOCALID_BIRTH_ISLAND_EXTERIOR_ROCK
	setfieldeffectargument 1, MAP_NUM(MAP_BIRTH_ISLAND_EXTERIOR)
	setfieldeffectargument 2, MAP_GROUP(MAP_BIRTH_ISLAND_EXTERIOR)
	dofieldeffect FLDEFF_DESTROY_DEOXYS_ROCK
	playbgm MUS_RG_ENCOUNTER_DEOXYS, FALSE
	waitfieldeffect FLDEFF_DESTROY_DEOXYS_ROCK
	addobject LOCALID_BIRTH_ISLAND_DEOXYS
	applymovement LOCALID_BIRTH_ISLAND_DEOXYS, BirthIsland_Exterior_Movement_DeoxysApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_DEOXYS_NORMAL, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_BIRTH_ISLAND_DEOXYS
	@ Trinity M5b S13b: L30 -> L80 (this slice's own legendary level, matching
	@ Mewtwo 95 / Mew 90 / Celebi 70 / Jirachi 70) -- the puzzle's own
	@ pre-existing payload line, a minimal disclosed delta, not a fork.
	seteventmon SPECIES_DEOXYS_NORMAL, 80
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BirthIsland_Exterior_EventScript_DefeatedDeoxys
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BirthIsland_Exterior_EventScript_RanFromDeoxys
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BirthIsland_Exterior_EventScript_RanFromDeoxys
	@ Trinity M5b S13b fix (the 13-A outcome-switch lesson, applied here to
	@ PRE-EXISTING vanilla content this slice makes reachable for the first
	@ time): sDeoxysNormalLevelUpLearnset (src/data/pokemon/level_up_
	@ learnsets/gen_9.h, the ACTIVE table -- P_LVL_UP_LEARNSETS is GEN_LATEST/
	@ GEN_9, include/config/pokemon.h:14) gives DEOXYS_NORMAL TELEPORT
	@ NATURALLY at level 13 -- reachable at L80 by construction, no Metronome/
	@ Transform needed. Without this branch, B_OUTCOME_MON_TELEPORTED (10)
	@ fell through to `setflag FLAG_BATTLED_DEOXYS` below, which
	@ BirthIsland_Exterior_OnTransition reads to HIDE BOTH DEOXYS AND THE
	@ TRIANGLE PUZZLE permanently (worse than Mew's own C1 case: even the
	@ puzzle that would let the player try again disappears) -- and nothing
	@ in the tree ever clears FLAG_BATTLED_DEOXYS (hall_of_fame.inc's own
	@ reset list clears FLAG_DEFEATED_DEOXYS, a different flag). Routed to
	@ the same RanFromDeoxys handler as a normal RAN/PLAYER_TELEPORTED
	@ outcome, matching NewIsland's own C1 fix shape exactly.
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, BirthIsland_Exterior_EventScript_RanFromDeoxys
	@ fall-through == B_OUTCOME_CAUGHT.
	setflag FLAG_BATTLED_DEOXYS
	release
	end

BirthIsland_Exterior_EventScript_DefeatedDeoxys::
	setflag FLAG_DEFEATED_DEOXYS
	setvar VAR_0x8004, SPECIES_DEOXYS_NORMAL
	goto Common_EventScript_LegendaryFlewAway
	end

BirthIsland_Exterior_EventScript_RanFromDeoxys::
	setvar VAR_0x8004, SPECIES_DEOXYS_NORMAL
	goto Common_EventScript_LegendaryFlewAway
	end

BirthIsland_Exterior_Movement_DeoxysApproach:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end
