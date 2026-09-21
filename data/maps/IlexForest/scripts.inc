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
@ Placement (9,22): col=0 elev=3 MB_CAVE, decoded directly from
@ IlexForest's own map.bin this session -- the tile immediately east of the
@ shrine sign (8,22), flanking it symmetrically with the sign's own
@ south-facing read tile (8,23). MB_ICE checked tree-wide on this map: 0
@ cells -- no manual slide/ice derivation needed. CORRECTED (fix round 1,
@ review): this said MB_NORMAL, true when it was written and false since
@ game 277671ee7a repainted the forest floor MB_NORMAL -> MB_CAVE. (9,22) is
@ metatile 641 (forest_johto secondary 129) and (8,23) is 642 (secondary
@ 130); both are in the 51 repainted, so both now decode MB_CAVE. Nothing
@ about the placement moves -- MB_CAVE differs from MB_NORMAL only in
@ TILE_FLAG_HAS_ENCOUNTERS (src/metatile_behavior.c:17), collision and
@ elevation are untouched, and Celebi is an object_event, not a wild.
@
@ Outcome switch. CORRECTED (fix round 1, review C2): the original claim
@ here -- "B_OUTCOME_MON_TELEPORTED is UNREACHABLE for this Celebi" -- was
@ FALSE. `GiveBoxMonInitialMoveset` (src/pokemon.c:1828-1876) keeps only
@ the LAST FOUR level-up moves at or below the mon's level, so L70 Celebi
@ actually knows Life Dew(40)/Leech Seed(50)/Recover(60)/Future Sight(70)
@ -- still no Teleport/Metronome/Transform/Roar/Whirlwind, so the MOVE-side
@ route to B_OUTCOME_MON_TELEPORTED genuinely is closed. But
@ `setteleportoutcome` is emitted from FOUR battle scripts, not one
@ (asm/macros/battle_script.inc:2100-2101): BattleScript_DoEffectTeleport,
@ BattleScript_RoarSuccessEndBattle, and -- the route the original comment
@ missed entirely -- BattleScript_EmergencyExitWild / _WildEnd2
@ (data/battle_scripts_1.s:6565/6596), the WILD-side handler for
@ ABILITY_EMERGENCY_EXIT/WIMP_OUT. Celebi's own ability, Natural Cure
@ (src/data/pokemon/species_info/gen_2_families.h), carries no
@ cantBeSwapped/cantBeOverwritten flag (src/data/abilities.h), so a player
@ can Skill Swap or Entrainment Emergency Exit/Wimp Out onto it, drop it
@ below half HP, and end the battle B_OUTCOME_MON_TELEPORTED. Without this
@ branch that fell through to "CAUGHT" and set FLAG_TRINITY_J_CELEBI_
@ RESOLVED with nothing caught -- a permanent, uncatchable loss, the exact
@ 13-A C1 class. Routed to the same Fled handler as a normal RAN outcome.
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
	@ Fix round 1 (review C2): see the header comment above for the full
	@ Emergency Exit/Wimp Out derivation. Routed to the same Fled handler.
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, IlexForest_EventScript_CelebiFled
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
@ UPDATED (fix round 1, review m2): this comment originally said "CELEBI IS
@ POST-GAME: the GS BALL branch, the CelebiShrineEvent special and the L30
@ encounter are all skipped, and this text must not promise a summoning" --
@ true when M4b S3 shipped this sign, FALSIFIED by M5b S13b, which added
@ exactly a GS-Ball-gated CELEBI at this shrine (see the header comment
@ above `IlexForest_MapScripts::`). Left stale through 13-B's own first
@ commit; corrected here. This sign's own text is UNCHANGED and still
@ correct either way -- it never promises a summoning, so nothing it says
@ needs to change now that one exists next to it.
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
