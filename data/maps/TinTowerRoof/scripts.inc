TinTowerRoof_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TinTowerRoof_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, TinTowerRoof_OnResume
	.byte 0

@ ============================================================================
@ Trinity M4b S10 -- HO-OH, at the top of nine tiers.
@
@ THE CLIMB HAD TO BE REPAIRED FIRST. Before this slice, `--dungeon` over the
@ TIN TOWER complex reported TinTower5F (11,15) -> 6F SEALED and every warp on
@ 6F/7F/8F/9F/Roof with it: this map was unreachable in the shipped ROM. GSC's
@ 5F is a hop maze using chained and TWO-DIRECTION hops, neither of which
@ survived the M4a port; tools/johto_port/fix_hops.py rebuilds them from
@ pokecrystal ground truth. See that tool's docstring.
@
@ TILE, DECODED. GSC's own (9,5): collision 0, elevation 3, MB_NORMAL,
@ reachable. The roof is 18 walkable tiles with the 9F ladder at (9,13).
@ (9,4) and (10,5) both decode collision 1, so HO-OH's only free neighbours are
@ (9,6) and (8,5) -- the approach is a single column and R5's "geometry
@ normalises the player's tile" comes free. Talk-triggered, so no camera window
@ to check.
@
@ THE GATE is the brief's, and both halves of it are S8/S10 state that had no
@ reader before now:
@   FLAG_TRINITY_J_WING_RAINBOW (0x29A, S8's DIRECTOR) -- FIRST READER
@   VAR_TRINITY_JOHTO_SCENE_TINTOWER >= 2, i.e. SUICUNE resolved
@ GSC gates it on holding the RAINBOW WING too (TinTowerRoofHoOhCallback's
@ `checkitem RAINBOW_WING`); Trinity's wing is a flag, per S8's item ruling.
@ GSC ALSO deletes the 2F stairs until the wing is in hand
@ (TinTower1FStairsCallback's changeblock). That is the same gate one floor
@ lower, and Trinity does not need both -- skipped, logged in the S10 plan.
@
@ MUSIC: none of Trinity's business. BattleSetup_StartLegendaryBattle already
@ carries `case SPECIES_LUGIA: case SPECIES_HO_OH: CreateBattleStartTask(
@ B_TRANSITION_BLUR, MUS_RG_VS_LEGEND)` (src/battle_setup.c:503-505), which IS
@ the M4b contract's pin. Only the three beasts needed a new case.
@
@ THE THREE MANDATORY CLAUSES of the vanilla static-legendary contract, all
@ present: ON_TRANSITION show-if-unset (so a FLED HO-OH comes back), ON_RESUME +
@ FLAG_SYS_CTRL_OBJ_DELETE (so a CAUGHT one leaves no ghost), and one durable
@ terminal flag. Omitting the first makes a fled legendary permanently missable.
@ ============================================================================

TinTowerRoof_OnTransition::
	call_if_set FLAG_TRINITY_J_HOOH_RESOLVED, TinTowerRoof_EventScript_HideHoOh
	call_if_unset FLAG_TRINITY_J_HOOH_RESOLVED, TinTowerRoof_EventScript_TryShowHoOh
	end

TinTowerRoof_EventScript_HideHoOh::
	setflag FLAG_TRINITY_J_HOOH_HIDE
	return

TinTowerRoof_EventScript_TryShowHoOh::
	goto_if_unset FLAG_TRINITY_J_WING_RAINBOW, TinTowerRoof_EventScript_HideHoOh
	goto_if_lt VAR_TRINITY_JOHTO_SCENE_TINTOWER, 2, TinTowerRoof_EventScript_HideHoOh
	clearflag FLAG_TRINITY_J_HOOH_HIDE
	return

TinTowerRoof_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TinTowerRoof_EventScript_TryRemoveHoOh
	end

TinTowerRoof_EventScript_TryRemoveHoOh::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_JOHTO_TTR_HOOH
	return

TinTowerRoof_EventScript_HoOh::
	lock
	faceplayer
	msgbox TinTowerRoof_Text_HoOh, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_HO_OH, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TinTowerRoof_EventScript_HoOhDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, TinTowerRoof_EventScript_HoOhFled
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, TinTowerRoof_EventScript_HoOhFled
	@ fall-through == B_OUTCOME_CAUGHT. ON_RESUME has already removed the object.
	setflag FLAG_TRINITY_J_HOOH_RESOLVED
	release
	end

TinTowerRoof_EventScript_HoOhDefeated::
	setflag FLAG_TRINITY_J_HOOH_RESOLVED
	goto Common_EventScript_RemoveStaticPokemon

@ seteventmon expands to three setvars plus a special (asm/macros/event.inc:
@ 2115-2121), so VAR_0x8004 has been clobbered and MUST be rewritten before the
@ shared tail buffers the species name out of it.
TinTowerRoof_EventScript_HoOhFled::
	setvar VAR_0x8004, SPECIES_HO_OH
	goto Common_EventScript_LegendaryFlewAway

TinTowerRoof_Text_HoOh:
	.string "Shaoooh!$"
