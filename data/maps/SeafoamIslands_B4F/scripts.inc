@ ============================================================================
@ Trinity M5b S9 -- SEAFOAM ISLANDS B4F. Revealed boulders, current-stopped,
@ ARTICUNO L78 (static legendary contract, three clauses, mirrors S3's shipped
@ ZAPDOS precedent exactly).
@
@ Two-stage puzzle (FRLG's own real shape, read from source, not guessed): a
@ boulder pushed into a B3F hole (SeafoamIslands_B3F/scripts.inc) clears the
@ matching FLAG_TRINITY_K_SEAFOAM_B4F_BOULDER_N here, revealing a fresh pushable
@ boulder at (9,18)/(8,18) -- the player must then push THAT boulder onto an
@ adjacent current tile to plug it (stage 2), which is what actually stills this
@ floor's current and opens the way to ARTICUNO.
@
@ Wrong default on the revealed boulders (should start hidden; the engine's own
@ default is shown -- !FlagGet(flagId) gates spawn, src/event_object_movement.c:
@ 1497,2738). Fixed the same way S3's Zapdos fixes its own wrong default: an
@ ON_TRANSITION recompute every load. It only ever RE-hides while the B3F source
@ hasn't fallen yet (call_if_unset); once it has, the call never fires again and
@ the B4F flag's own state (present, or gone-because-pushed-into-water) is left
@ alone -- verified by tracing both branches, not assumed.
@ ============================================================================

.equ NUM_BOULDERS_USED, VAR_TEMP_2

@ setmetatile authoring must live in MAP_SCRIPT_ON_LOAD (qa_sweep.py's own gate:
@ InitMapLayoutData wipes the grid immediately after ON_TRANSITION runs,
@ src/overworld.c:876-877 + src/fieldmap.c:96-103) -- so the current-stopped sweep
@ is split into its own ON_LOAD script; boulder-reveal and ARTICUNO visibility
@ (no setmetatile) stay on ON_TRANSITION, matching the Zapdos precedent's own
@ split (its hide/show is ON_TRANSITION too). Both recompute NUM_BOULDERS_USED
@ independently rather than sharing one computation across the two callbacks --
@ ON_TRANSITION runs first, but nothing guarantees VAR_TEMP_2 survives untouched
@ until ON_LOAD runs, so each callback counts its own copy.
SeafoamIslands_B4F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamIslands_B4F_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, SeafoamIslands_B4F_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, SeafoamIslands_B4F_OnResume
	.byte 0

SeafoamIslands_B4F_OnTransition::
	call_if_unset FLAG_TRINITY_K_SEAFOAM_B3F_BOULDER_1, SeafoamIslands_B4F_EventScript_HideBoulder1
	call_if_unset FLAG_TRINITY_K_SEAFOAM_B3F_BOULDER_2, SeafoamIslands_B4F_EventScript_HideBoulder2
	setvar NUM_BOULDERS_USED, 0
	call_if_set FLAG_TRINITY_K_SEAFOAM_B4F_BOULDER_1, SeafoamIslands_B4F_EventScript_AddBoulderUsed
	call_if_set FLAG_TRINITY_K_SEAFOAM_B4F_BOULDER_2, SeafoamIslands_B4F_EventScript_AddBoulderUsed
	call_if_set FLAG_TRINITY_K_ARTICUNO_RESOLVED, SeafoamIslands_B4F_EventScript_HideArticuno
	call_if_unset FLAG_TRINITY_K_ARTICUNO_RESOLVED, SeafoamIslands_B4F_EventScript_TryShowArticuno
	end

SeafoamIslands_B4F_OnLoad::
	setvar NUM_BOULDERS_USED, 0
	call_if_set FLAG_TRINITY_K_SEAFOAM_B4F_BOULDER_1, SeafoamIslands_B4F_EventScript_AddBoulderUsed
	call_if_set FLAG_TRINITY_K_SEAFOAM_B4F_BOULDER_2, SeafoamIslands_B4F_EventScript_AddBoulderUsed
	goto_if_eq NUM_BOULDERS_USED, 2, SeafoamIslands_B4F_EventScript_CalmCurrent
	end

@ Clause 1's gate: ARTICUNO shows only once both B4F boulders are used (current
@ stopped) -- the puzzle IS the gate, no separate story flag.
SeafoamIslands_B4F_EventScript_TryShowArticuno::
	goto_if_ne NUM_BOULDERS_USED, 2, SeafoamIslands_B4F_EventScript_HideArticuno
	clearflag FLAG_TRINITY_K_ARTICUNO_HIDE
	return

SeafoamIslands_B4F_EventScript_HideBoulder1::
	setflag FLAG_TRINITY_K_SEAFOAM_B4F_BOULDER_1
	return

SeafoamIslands_B4F_EventScript_HideBoulder2::
	setflag FLAG_TRINITY_K_SEAFOAM_B4F_BOULDER_2
	return

SeafoamIslands_B4F_EventScript_AddBoulderUsed::
	addvar NUM_BOULDERS_USED, 1
	return

@ Both revealed boulders pushed into the current (stage 2 complete) -- still the
@ current (uniform METATILE_General_CalmWater sweep, sub-plan section 5.5). ARTICUNO
@ visibility is already resolved above (TryShowArticuno), not here.
SeafoamIslands_B4F_EventScript_CalmCurrent::
	setmetatile  3,  1, METATILE_General_CalmWater, 0
	setmetatile  3,  2, METATILE_General_CalmWater, 0
	setmetatile  3,  3, METATILE_General_CalmWater, 0
	setmetatile  3,  4, METATILE_General_CalmWater, 0
	setmetatile  3,  5, METATILE_General_CalmWater, 0
	setmetatile  3,  6, METATILE_General_CalmWater, 0
	setmetatile  3,  7, METATILE_General_CalmWater, 0
	setmetatile  3,  8, METATILE_General_CalmWater, 0
	setmetatile  3,  9, METATILE_General_CalmWater, 0
	setmetatile  3, 10, METATILE_General_CalmWater, 0
	setmetatile  3, 11, METATILE_General_CalmWater, 0
	setmetatile  3, 12, METATILE_General_CalmWater, 0
	setmetatile  3, 13, METATILE_General_CalmWater, 0
	setmetatile  3, 14, METATILE_General_CalmWater, 0
	setmetatile  3, 15, METATILE_General_CalmWater, 0
	setmetatile  3, 16, METATILE_General_CalmWater, 0
	setmetatile  4,  1, METATILE_General_CalmWater, 0
	setmetatile  4,  2, METATILE_General_CalmWater, 0
	setmetatile  4,  3, METATILE_General_CalmWater, 0
	setmetatile  4,  4, METATILE_General_CalmWater, 0
	setmetatile  4,  5, METATILE_General_CalmWater, 0
	setmetatile  4,  6, METATILE_General_CalmWater, 0
	setmetatile  4,  7, METATILE_General_CalmWater, 0
	setmetatile  4,  8, METATILE_General_CalmWater, 0
	setmetatile  4,  9, METATILE_General_CalmWater, 0
	setmetatile  4, 10, METATILE_General_CalmWater, 0
	setmetatile  4, 11, METATILE_General_CalmWater, 0
	setmetatile  4, 12, METATILE_General_CalmWater, 0
	setmetatile  4, 13, METATILE_General_CalmWater, 0
	setmetatile  4, 14, METATILE_General_CalmWater, 0
	setmetatile  4, 15, METATILE_General_CalmWater, 0
	setmetatile  4, 16, METATILE_General_CalmWater, 0
	setmetatile  5,  1, METATILE_General_CalmWater, 0
	setmetatile  5,  2, METATILE_General_CalmWater, 0
	setmetatile  5,  3, METATILE_General_CalmWater, 0
	setmetatile  5,  4, METATILE_General_CalmWater, 0
	setmetatile  5,  5, METATILE_General_CalmWater, 0
	setmetatile  5,  6, METATILE_General_CalmWater, 0
	setmetatile  5,  7, METATILE_General_CalmWater, 0
	setmetatile  5,  8, METATILE_General_CalmWater, 0
	setmetatile  5,  9, METATILE_General_CalmWater, 0
	setmetatile  5, 10, METATILE_General_CalmWater, 0
	setmetatile  5, 11, METATILE_General_CalmWater, 0
	setmetatile  5, 12, METATILE_General_CalmWater, 0
	setmetatile  5, 13, METATILE_General_CalmWater, 0
	setmetatile  5, 14, METATILE_General_CalmWater, 0
	setmetatile  5, 15, METATILE_General_CalmWater, 0
	setmetatile  5, 16, METATILE_General_CalmWater, 0
	setmetatile  6,  5, METATILE_General_CalmWater, 0
	setmetatile  6,  6, METATILE_General_CalmWater, 0
	setmetatile  6,  7, METATILE_General_CalmWater, 0
	setmetatile  6,  8, METATILE_General_CalmWater, 0
	setmetatile  6,  9, METATILE_General_CalmWater, 0
	setmetatile  6, 10, METATILE_General_CalmWater, 0
	setmetatile  6, 11, METATILE_General_CalmWater, 0
	setmetatile  6, 12, METATILE_General_CalmWater, 0
	setmetatile  6, 13, METATILE_General_CalmWater, 0
	setmetatile  6, 14, METATILE_General_CalmWater, 0
	setmetatile  6, 15, METATILE_General_CalmWater, 0
	setmetatile  6, 16, METATILE_General_CalmWater, 0
	setmetatile  7,  5, METATILE_General_CalmWater, 0
	setmetatile  7,  6, METATILE_General_CalmWater, 0
	setmetatile  7,  7, METATILE_General_CalmWater, 0
	setmetatile  7,  8, METATILE_General_CalmWater, 0
	setmetatile  7,  9, METATILE_General_CalmWater, 0
	setmetatile  7, 10, METATILE_General_CalmWater, 0
	setmetatile  7, 11, METATILE_General_CalmWater, 0
	setmetatile  7, 12, METATILE_General_CalmWater, 0
	setmetatile  7, 13, METATILE_General_CalmWater, 0
	setmetatile  7, 14, METATILE_General_CalmWater, 0
	setmetatile  7, 15, METATILE_General_CalmWater, 0
	setmetatile  7, 16, METATILE_General_CalmWater, 0
	setmetatile  8,  5, METATILE_General_CalmWater, 0
	setmetatile  8,  6, METATILE_General_CalmWater, 0
	setmetatile  8,  7, METATILE_General_CalmWater, 0
	setmetatile  8,  8, METATILE_General_CalmWater, 0
	setmetatile  8,  9, METATILE_General_CalmWater, 0
	setmetatile  8, 10, METATILE_General_CalmWater, 0
	setmetatile  8, 11, METATILE_General_CalmWater, 0
	setmetatile  8, 12, METATILE_General_CalmWater, 0
	setmetatile  8, 13, METATILE_General_CalmWater, 0
	setmetatile  8, 14, METATILE_General_CalmWater, 0
	setmetatile  8, 15, METATILE_General_CalmWater, 0
	setmetatile  8, 16, METATILE_General_CalmWater, 0
	setmetatile  8, 17, METATILE_General_CalmWater, 0
	setmetatile  8, 19, METATILE_General_CalmWater, 0
	setmetatile  8, 20, METATILE_General_CalmWater, 0
	setmetatile  8, 21, METATILE_General_CalmWater, 0
	setmetatile  9,  5, METATILE_General_CalmWater, 0
	setmetatile  9,  6, METATILE_General_CalmWater, 0
	setmetatile  9,  7, METATILE_General_CalmWater, 0
	setmetatile  9,  8, METATILE_General_CalmWater, 0
	setmetatile  9,  9, METATILE_General_CalmWater, 0
	setmetatile  9, 10, METATILE_General_CalmWater, 0
	setmetatile  9, 11, METATILE_General_CalmWater, 0
	setmetatile  9, 12, METATILE_General_CalmWater, 0
	setmetatile  9, 14, METATILE_General_CalmWater, 0
	setmetatile  9, 15, METATILE_General_CalmWater, 0
	setmetatile  9, 16, METATILE_General_CalmWater, 0
	setmetatile  9, 17, METATILE_General_CalmWater, 0
	setmetatile  9, 19, METATILE_General_CalmWater, 0
	setmetatile  9, 20, METATILE_General_CalmWater, 0
	setmetatile  9, 21, METATILE_General_CalmWater, 0
	setmetatile 10,  5, METATILE_General_CalmWater, 0
	setmetatile 10,  6, METATILE_General_CalmWater, 0
	setmetatile 10, 13, METATILE_General_CalmWater, 0
	setmetatile 10, 14, METATILE_General_CalmWater, 0
	setmetatile 10, 15, METATILE_General_CalmWater, 0
	setmetatile 10, 16, METATILE_General_CalmWater, 0
	setmetatile 11,  5, METATILE_General_CalmWater, 0
	setmetatile 11,  6, METATILE_General_CalmWater, 0
	setmetatile 11, 14, METATILE_General_CalmWater, 0
	setmetatile 11, 15, METATILE_General_CalmWater, 0
	setmetatile 11, 16, METATILE_General_CalmWater, 0
	setmetatile 12,  5, METATILE_General_CalmWater, 0
	setmetatile 12,  6, METATILE_General_CalmWater, 0
	setmetatile 12, 14, METATILE_General_CalmWater, 0
	setmetatile 12, 15, METATILE_General_CalmWater, 0
	setmetatile 12, 16, METATILE_General_CalmWater, 0
	setmetatile 13,  5, METATILE_General_CalmWater, 0
	setmetatile 13,  6, METATILE_General_CalmWater, 0
	setmetatile 13, 14, METATILE_General_CalmWater, 0
	setmetatile 13, 15, METATILE_General_CalmWater, 0
	setmetatile 13, 16, METATILE_General_CalmWater, 0
	setmetatile 14,  5, METATILE_General_CalmWater, 0
	setmetatile 14,  6, METATILE_General_CalmWater, 0
	setmetatile 14, 13, METATILE_General_CalmWater, 0
	setmetatile 14, 14, METATILE_General_CalmWater, 0
	setmetatile 14, 15, METATILE_General_CalmWater, 0
	setmetatile 14, 16, METATILE_General_CalmWater, 0
	setmetatile 15,  5, METATILE_General_CalmWater, 0
	setmetatile 15,  6, METATILE_General_CalmWater, 0
	setmetatile 15, 13, METATILE_General_CalmWater, 0
	setmetatile 15, 14, METATILE_General_CalmWater, 0
	setmetatile 15, 15, METATILE_General_CalmWater, 0
	setmetatile 15, 16, METATILE_General_CalmWater, 0
	setmetatile 16,  1, METATILE_General_CalmWater, 0
	setmetatile 16,  2, METATILE_General_CalmWater, 0
	setmetatile 16,  3, METATILE_General_CalmWater, 0
	setmetatile 16,  4, METATILE_General_CalmWater, 0
	setmetatile 16,  5, METATILE_General_CalmWater, 0
	setmetatile 16,  6, METATILE_General_CalmWater, 0
	setmetatile 16, 13, METATILE_General_CalmWater, 0
	setmetatile 16, 14, METATILE_General_CalmWater, 0
	setmetatile 16, 15, METATILE_General_CalmWater, 0
	setmetatile 16, 16, METATILE_General_CalmWater, 0
	setmetatile 17,  1, METATILE_General_CalmWater, 0
	setmetatile 17,  2, METATILE_General_CalmWater, 0
	setmetatile 17,  3, METATILE_General_CalmWater, 0
	setmetatile 17,  4, METATILE_General_CalmWater, 0
	setmetatile 17,  5, METATILE_General_CalmWater, 0
	setmetatile 17,  6, METATILE_General_CalmWater, 0
	setmetatile 18,  1, METATILE_General_CalmWater, 0
	setmetatile 18,  2, METATILE_General_CalmWater, 0
	setmetatile 18,  3, METATILE_General_CalmWater, 0
	setmetatile 18,  4, METATILE_General_CalmWater, 0
	setmetatile 18,  5, METATILE_General_CalmWater, 0
	setmetatile 18,  6, METATILE_General_CalmWater, 0
	setmetatile 19,  1, METATILE_General_CalmWater, 0
	setmetatile 19,  2, METATILE_General_CalmWater, 0
	setmetatile 19,  3, METATILE_General_CalmWater, 0
	setmetatile 19,  4, METATILE_General_CalmWater, 0
	setmetatile 19,  5, METATILE_General_CalmWater, 0
	setmetatile 19,  6, METATILE_General_CalmWater, 0
	setmetatile 26, 19, METATILE_General_CalmWater, 0
	setmetatile 26, 20, METATILE_General_CalmWater, 0
	setmetatile 26, 21, METATILE_General_CalmWater, 0
	setmetatile 27, 19, METATILE_General_CalmWater, 0
	setmetatile 27, 20, METATILE_General_CalmWater, 0
	setmetatile 27, 21, METATILE_General_CalmWater, 0
	setmetatile 28, 19, METATILE_General_CalmWater, 0
	setmetatile 28, 20, METATILE_General_CalmWater, 0
	setmetatile 28, 21, METATILE_General_CalmWater, 0
	special DrawWholeMapView
	end

@ ----------------------------------------------------------------------------
@ The two revealed boulders' own stage-2 push-into-current detection. No engine
@ hook needed here (unlike the B3F hole-fall): Task_PushBoulder/PushBoulder_Move
@ place no terrain restriction beyond plain collision, and every current tile
@ around these boulders is col0 -- the push itself already works. This is a pure
@ script-side "did I just get pushed onto flowing water" check, run every time
@ the player talks to the boulder (the only trigger point available).
@
@ Checked against BOTH boulders' full reachable set, not just each one's own
@ "home" column: (8,18)/(9,18) are adjacent and either boulder could in
@ principle end up sideways-pushed into the other's column before being pushed
@ further north/south (once its neighbor has moved out of the way). A check
@ gated on a fixed home column alone would miss that case; checking the full
@ (x,y) pair against all four current tiles does not.
@ ----------------------------------------------------------------------------
SeafoamIslands_B4F_EventScript_Boulder1::
	getobjectxy VAR_LAST_TALKED, 0, VAR_0x8004, VAR_0x8005
	call SeafoamIslands_B4F_EventScript_CheckOnCurrent
	goto_if_eq VAR_RESULT, TRUE, SeafoamIslands_B4F_EventScript_Boulder1Used
	goto EventScript_StrengthBoulder
	end

SeafoamIslands_B4F_EventScript_Boulder1Used::
	removeobject VAR_LAST_TALKED
	setflag FLAG_TRINITY_K_SEAFOAM_B4F_BOULDER_1
	return

SeafoamIslands_B4F_EventScript_Boulder2::
	getobjectxy VAR_LAST_TALKED, 0, VAR_0x8004, VAR_0x8005
	call SeafoamIslands_B4F_EventScript_CheckOnCurrent
	goto_if_eq VAR_RESULT, TRUE, SeafoamIslands_B4F_EventScript_Boulder2Used
	goto EventScript_StrengthBoulder
	end

SeafoamIslands_B4F_EventScript_Boulder2Used::
	removeobject VAR_LAST_TALKED
	setflag FLAG_TRINITY_K_SEAFOAM_B4F_BOULDER_2
	return

@ VAR_0x8004/0x8005 already hold the talked-to boulder's (x,y). TRUE in
@ VAR_RESULT iff that tile is one of the four current cells flanking the
@ landing pool: (8,17) (9,17) (8,19) (9,19).
SeafoamIslands_B4F_EventScript_CheckOnCurrent::
	setvar VAR_RESULT, FALSE
	goto_if_ne VAR_0x8005, 17, SeafoamIslands_B4F_EventScript_CheckOnCurrentRowSouth
	goto_if_eq VAR_0x8004, 8, SeafoamIslands_B4F_EventScript_SetOnCurrentTrue
	goto_if_eq VAR_0x8004, 9, SeafoamIslands_B4F_EventScript_SetOnCurrentTrue
	return

SeafoamIslands_B4F_EventScript_CheckOnCurrentRowSouth::
	goto_if_ne VAR_0x8005, 19, Common_EventScript_NopReturn
	goto_if_eq VAR_0x8004, 8, SeafoamIslands_B4F_EventScript_SetOnCurrentTrue
	goto_if_eq VAR_0x8004, 9, SeafoamIslands_B4F_EventScript_SetOnCurrentTrue
	return

SeafoamIslands_B4F_EventScript_SetOnCurrentTrue::
	setvar VAR_RESULT, TRUE
	return

@ ============================================================================
@ ARTICUNO -- static legendary contract, three clauses, mirrors S3's shipped
@ ZAPDOS (PowerPlant/scripts.inc) exactly. L78 via seteventmon. Gate: the current-
@ stopped condition above (the puzzle IS the gate, no separate story flag).
@ ============================================================================
SeafoamIslands_B4F_EventScript_HideArticuno::
	setflag FLAG_TRINITY_K_ARTICUNO_HIDE
	return

SeafoamIslands_B4F_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SeafoamIslands_B4F_EventScript_TryRemoveArticuno
	end

SeafoamIslands_B4F_EventScript_TryRemoveArticuno::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_KANTO_SEAFOAM_ARTICUNO
	return

SeafoamIslands_B4F_EventScript_Articuno::
	lock
	faceplayer
	msgbox SeafoamIslands_B4F_Text_Articuno, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_ARTICUNO, 78
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SeafoamIslands_B4F_EventScript_ArticunoDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SeafoamIslands_B4F_EventScript_ArticunoFled
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SeafoamIslands_B4F_EventScript_ArticunoFled
	@ fall-through == B_OUTCOME_CAUGHT. ON_RESUME has already removed the object.
	setflag FLAG_TRINITY_K_ARTICUNO_RESOLVED
	release
	end

SeafoamIslands_B4F_EventScript_ArticunoDefeated::
	setflag FLAG_TRINITY_K_ARTICUNO_RESOLVED
	goto Common_EventScript_RemoveStaticPokemon

SeafoamIslands_B4F_EventScript_ArticunoFled::
	setvar VAR_0x8004, SPECIES_ARTICUNO
	goto Common_EventScript_LegendaryFlewAway

SeafoamIslands_B4F_Text_Articuno:
	.string "The current's gone still, and the\n"
	.string "cold coming off the water isn't\l"
	.string "natural.\p"
	.string "Something with ice-blue feathers\n"
	.string "is watching you from the ledge\l"
	.string "ahead.$"

SeafoamIslands_B4F_EventScript_FastCurrentSign::
	msgbox SeafoamIslands_B4F_Text_FastCurrentSign, MSGBOX_SIGN
	end

SeafoamIslands_B4F_EventScript_BoulderHintSign::
	msgbox SeafoamIslands_B4F_Text_BoulderHintSign, MSGBOX_SIGN
	end

SeafoamIslands_B4F_Text_FastCurrentSign:
	.string "DANGER\nFast current!$"

SeafoamIslands_B4F_Text_BoulderHintSign:
	.string "Hint: Boulders might change the\nflow of water.$"
