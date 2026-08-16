WhirlIslandLugiaChamber_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WhirlIslandLugiaChamber_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, WhirlIslandLugiaChamber_OnResume
	.byte 0

@ ============================================================================
@ Trinity M4b S10 -- LUGIA, at the bottom of the WHIRL ISLANDS.
@
@ TILE, DECODED. GSC's own (9,5): collision 0, ELEVATION 1, MB_POND_WATER,
@ reachable. LUGIA stands ON the water, as it does in GSC, and elevation 1 is
@ the surfing player's own elevation, so it is talkable from the surf. The
@ chamber's warp out is (9,13), MB_SOUTH_ARROW_WARP at elevation 3.
@
@ THE ROUTE NEEDS SURF ONLY -- the brief's "surf and waterfall territory" is an
@ overstatement, and S10 measured it rather than repeating it. reach_check
@ learned MB_WATERFALL this slice (it is TILE_FLAG_SURFABLE, so every model
@ before now let the player swim UP every waterfall in JOHTO). With the ascent
@ gate ON:
@     WhirlIslandB2F from (13,31)->WHIRL ISLAND SW : reaches (7,25)->this map
@     WhirlIslandB2F from (11,5) ->WHIRL ISLAND B1F: reaches (7,25) as well,
@                                                     riding the current DOWN
@ Descending a waterfall is not merely allowed, it is compulsory
@ (ForcedMovement_PushedSouthByCurrent, src/field_player_avatar.c:192, 561-564,
@ and PlayerStep runs forced movement before keypad input, :342-368). So the
@ B2F waterfall column is a one-way shortcut, not a gate, and the whole 8-map
@ complex reports NO SEALED WARPS in both waterfall states.
@
@ THE GATE is FLAG_TRINITY_J_WING_SILVER (0x29B, S8's ROCKET BASE evidence
@ crate) -- FIRST READER. GSC gates on `checkitem SILVER_WING`; Trinity's wing
@ is a flag, per S8's item ruling.
@
@ MUSIC: no C change needed. BattleSetup_StartLegendaryBattle already pairs
@ SPECIES_LUGIA with MUS_RG_VS_LEGEND (src/battle_setup.c:503-505) -- the
@ contract's pin, already satisfied.
@
@ Same three mandatory clauses as the roof: ON_TRANSITION show-if-unset,
@ ON_RESUME + FLAG_SYS_CTRL_OBJ_DELETE, one terminal flag.
@ ============================================================================

WhirlIslandLugiaChamber_OnTransition::
	call_if_set FLAG_TRINITY_J_LUGIA_RESOLVED, WhirlIslandLugiaChamber_EventScript_HideLugia
	call_if_unset FLAG_TRINITY_J_LUGIA_RESOLVED, WhirlIslandLugiaChamber_EventScript_TryShowLugia
	end

WhirlIslandLugiaChamber_EventScript_HideLugia::
	setflag FLAG_TRINITY_J_LUGIA_HIDE
	return

WhirlIslandLugiaChamber_EventScript_TryShowLugia::
	goto_if_unset FLAG_TRINITY_J_WING_SILVER, WhirlIslandLugiaChamber_EventScript_HideLugia
	clearflag FLAG_TRINITY_J_LUGIA_HIDE
	return

WhirlIslandLugiaChamber_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, WhirlIslandLugiaChamber_EventScript_TryRemoveLugia
	end

WhirlIslandLugiaChamber_EventScript_TryRemoveLugia::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_JOHTO_WILC_LUGIA
	return

WhirlIslandLugiaChamber_EventScript_Lugia::
	lock
	faceplayer
	msgbox WhirlIslandLugiaChamber_Text_Lugia, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_LUGIA, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, WhirlIslandLugiaChamber_EventScript_LugiaDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, WhirlIslandLugiaChamber_EventScript_LugiaFled
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, WhirlIslandLugiaChamber_EventScript_LugiaFled
	@ fall-through == B_OUTCOME_CAUGHT. ON_RESUME has already removed the object.
	setflag FLAG_TRINITY_J_LUGIA_RESOLVED
	release
	end

WhirlIslandLugiaChamber_EventScript_LugiaDefeated::
	setflag FLAG_TRINITY_J_LUGIA_RESOLVED
	goto Common_EventScript_RemoveStaticPokemon

WhirlIslandLugiaChamber_EventScript_LugiaFled::
	setvar VAR_0x8004, SPECIES_LUGIA
	goto Common_EventScript_LegendaryFlewAway

WhirlIslandLugiaChamber_Text_Lugia:
	.string "Gyaaas!$"
