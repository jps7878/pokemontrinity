@ ============================================================================
@ Trinity M5b S13b -- CELEBI. GS_BALL (FLAG_TRINITY_K_GS_BALL, 0x4CD, set S6
@ RocketHideout_B4F, zero readers until now, confirmed by grep) -> KURT (a
@ new flavour-only branch on his own existing script, KurtsHouse/
@ scripts.inc) -> the ILEX FOREST SHRINE, where CELEBI now stands.
@
@ Design call (B1-B5 scene grammar, per the sub-plan and this fix round's
@ carry-forward): CELEBI is an ORDINARY hide-flagged standing object, the
@ EXACT SAME three-clause contract Mewtwo/the three birds already use --
@ NOT an addobject-triggered reveal off the shrine sign. Reasoning: the
@ brief's own interfaces section requires all five new legendaries to
@ "follow the same three clauses"; the proven, review-verified pattern
@ carries zero new risk, while a scripted "shrine reveals Celebi"
@ choreography would need either a scene var (to distinguish "first
@ reveal" from "re-approach") or an addobject/removeobject session-actor
@ shape with its own re-entry subtleties (S7's own documented addobject
@ trap). NEITHER IS ACTUALLY NEEDED: the existing shrine sign's own
@ unchanged text ("offerings have been left at the foot of it. Recently.")
@ already reads as the "time slip" -- CELEBI now standing beside its own
@ shrine completes the picture without a scripted reveal. Zero scene var
@ claimed (the carry-forward's own "ONE scene var max" is a ceiling, not a
@ mandate -- this design uses none, an economy stated plainly rather than
@ claimed-then-unused).
@
@ B1 -- OBJ_EVENT_GFX_SPECIES(CELEBI), own hide flag
@ FLAG_TRINITY_J_CELEBI_HIDE, ON_TRANSITION below (visible iff
@ VAR_TRINITY_KANTO_ARC>=6 AND FLAG_TRINITY_K_GS_BALL set AND
@ FLAG_TRINITY_J_CELEBI_RESOLVED unset).
@ B2 -- single provable trigger: CELEBI's own object interaction (talk),
@ the identical mechanism Mewtwo/the birds use -- no coord_event, no
@ separate scene trigger.
@ B3 -- choreography: one flavour msgbox (matching the birds' one-line
@ precedent, NOT Mewtwo's silent reading -- Celebi is not specified silent)
@ -> cry -> seteventmon -> BattleSetup_StartLegendaryBattle (both switches,
@ src/battle_setup.c + src/pokemon.c, this fix round) -> outcome handling.
@ B4 -- the player is never moved, only faced (`faceplayer`); nothing in
@ the encounter applies player movement.
@ B5 -- durable outputs: FLAG_TRINITY_J_CELEBI_RESOLVED (terminal, set on
@ WON and the CAUGHT fall-through) + ON_RESUME `removeobject` guarded on
@ B_OUTCOME_CAUGHT.
@
@ Placement (9,22): col=0 elev=3 MB_NORMAL, decoded directly from
@ IlexForest's own map.bin this session -- the tile immediately east of the
@ shrine sign (8,22), flanking it symmetrically with the sign's own
@ south-facing read tile (8,23). MB_ICE checked tree-wide on this map: 0
@ cells -- no manual slide/ice derivation needed.
@
@ Outcome switch (the 13-A lesson, re-derived here rather than assumed):
@ sCelebiLevelUpLearnset (src/data/pokemon/level_up_learnsets/gen_9.h, the
@ ACTIVE table -- P_LVL_UP_LEARNSETS is GEN_LATEST/GEN_9,
@ include/config/pokemon.h:14) at L70 gives Confusion(1)/Heal Bell(1)/
@ Magical Leaf(10)/Baton Pass(20)/Ancient Power(30)/Life Dew(40)/Leech
@ Seed(50)/Recover(60)/Future Sight(70) -- NO Teleport, Metronome, or
@ Transform. Baton Pass cannot trigger B_OUTCOME_MON_TELEPORTED (that
@ outcome is set specifically by the TELEPORT move's own battle script,
@ src/battle_script_commands.c's BS_SetTeleportOutcome, not by Baton Pass).
@ B_OUTCOME_MON_TELEPORTED is therefore UNREACHABLE for this Celebi -- the
@ three-branch bird shape (WON/RAN/PLAYER_TELEPORTED) is correct and
@ sufficient, not a gap.
@ ============================================================================
IlexForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IlexForest_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, IlexForest_OnResume
	.byte 0

IlexForest_OnTransition:
	goto_if_lt VAR_TRINITY_KANTO_ARC, 6, IlexForest_EventScript_HideCelebi
	goto_if_unset FLAG_TRINITY_K_GS_BALL, IlexForest_EventScript_HideCelebi
	goto_if_set FLAG_TRINITY_J_CELEBI_RESOLVED, IlexForest_EventScript_HideCelebi
	clearflag FLAG_TRINITY_J_CELEBI_HIDE
	end

IlexForest_EventScript_HideCelebi::
	setflag FLAG_TRINITY_J_CELEBI_HIDE
	end

@ THE THIRD MANDATORY CLAUSE of the legendary contract. A CAUGHT legendary
@ never re-enters its own talk script, so without this the object stands
@ there as a ghost. FLAG_SYS_CTRL_OBJ_DELETE is set around the battle and
@ only then does this fire.
IlexForest_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, IlexForest_EventScript_TryRemoveCelebi
	end

IlexForest_EventScript_TryRemoveCelebi::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_JOHTO_ILEX_CELEBI
	return

IlexForest_EventScript_Celebi::
	lock
	faceplayer
	msgbox IlexForest_Text_Celebi, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_CELEBI, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, IlexForest_EventScript_CelebiDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IlexForest_EventScript_CelebiFled
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, IlexForest_EventScript_CelebiFled
	@ fall-through == B_OUTCOME_CAUGHT. ON_RESUME has already removed the
	@ object.
	setflag FLAG_TRINITY_J_CELEBI_RESOLVED
	release
	end

IlexForest_EventScript_CelebiDefeated::
	setflag FLAG_TRINITY_J_CELEBI_RESOLVED
	goto Common_EventScript_RemoveStaticPokemon

IlexForest_EventScript_CelebiFled::
	setvar VAR_0x8004, SPECIES_CELEBI
	goto Common_EventScript_LegendaryFlewAway

IlexForest_Text_Celebi:
	.string "For a moment the shrine's shadow\n"
	.string "holds a shape that isn't a shadow.$"

IlexForest_EventScript_HeadbuttGuy::
	msgbox IlexForest_Text_HeadbuttGuy, MSGBOX_NPC
	end

IlexForest_EventScript_WAYNE::
	trainerbattle_single TRAINER_JOHTO_BUG_CATCHER_WAYNE, IlexForest_Text_WAYNESeen, IlexForest_Text_WAYNEBeaten
	msgbox IlexForest_Text_WAYNEBeaten, MSGBOX_AUTOCLOSE
	end

IlexForest_EventScript_Signpost::
	msgbox IlexForest_Text_Signpost, MSGBOX_SIGN
	end

@ ============================================================================
@ Trinity M4b S3 -- the ILEX FOREST SHRINE. Adapts pokecrystal
@ maps/IlexForest.asm's IlexForestShrineScript / Text_IlexForestShrine.
@ CELEBI IS POST-GAME: the GS BALL branch, the CelebiShrineEvent special and
@ the L30 encounter are all skipped, and this text must not promise a
@ summoning. Reverent flavour only.
@ (8,22) decodes collision 1 / elevation 0 -- the shrine tile itself -- read
@ facing north from (8,23), which decodes collision 0 / elevation 3. Same shape
@ as the GYM PATTERN's G5 statues.
@ ============================================================================
IlexForest_EventScript_Shrine::
	msgbox IlexForest_Text_Shrine, MSGBOX_SIGN
	end

IlexForest_Text_HeadbuttGuy:
	.string "This route sure gets more foot\ntraffic now that HOENN trainers\lkeep showing up.$"

IlexForest_Text_WAYNESeen:
	.string "Don't sneak up on\nme like that!\pYou frightened a\nPOKéMON away!$"

IlexForest_Text_WAYNEBeaten:
	.string "I hadn't seen that\nPOKéMON before…$"

@ Expands GSC Text_IlexForestShrine. The "hole that something would fit into"
@ line is deliberately NOT carried over -- that is the GS BALL hook, and CELEBI
@ is not an Act II beat.
IlexForest_Text_Shrine:
	.string "ILEX FOREST SHRINE…\p"
	.string "It's in honour of the forest's\n"
	.string "protector.\p"
	.string "No name on it. The people who\n"
	.string "built it clearly assumed you'd\l"
	.string "know, and were probably right\l"
	.string "at the time.\p"
	.string "Offerings have been left at the\n"
	.string "foot of it. Recently.\p"
	.string "The trees are very quiet here.$"

IlexForest_Text_Signpost:
	.string "ILEX FOREST is\nso overgrown with\ptrees that you\ncan't see the sky.\pPlease watch out\nfor items that may\lhave been dropped.$"
