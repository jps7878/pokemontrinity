@ ============================================================================
@ Trinity M5b S13a -- MEWTWO. The cave's own "depths": this floor's single
@ warp (5,7) is the only way in or out (re-confirmed this slice: 494 walkable
@ tiles, all one connected component from that one warp, reach_check.py),
@ and MEWTWO stands on the isolated central island (20,13) the lake divides
@ the floor around -- Surf-crossing required, matching FRLG's own staging.
@ TM25 (a hidden pickup, map.json bg_events) sits on the same island at
@ (24,13), the cave's "top-shelf" prize alongside its guardian.
@
@ DISCLOSED DUPLICATE, not a dedup-grep miss papered over: TM25 already
@ exists as a visible OBJ_EVENT_GFX_ITEM_BALL pickup in PowerPlant/map.json
@ (FLAG_TRINITY_KANTO_PICKUPS_START + 80, shipped S3, likely FRLG's own real
@ TM25 placement) -- found ONLY at implementation time, correcting this
@ slice's sub-plan §3.2, which claimed "none found" after an incomplete
@ dedup grep. Kept anyway per the brief's own "spec-binding: TM25 Thunder"
@ line rather than substituted for a different TM, because TMs in this tree
@ are reusable/unlimited-use (I_REUSABLE_TMS, S4's own finding) -- a second
@ copy is redundant, not a functional bug, dead flag, or soft-lock. Flagged
@ prominently for the controller as a real correction, not swept in.
@
@ Legendary contract, three clauses (bird-contract precedent, re-read this
@ slice from SeafoamIslands_B4F/scripts.inc:280-326 and PowerPlant/scripts.inc):
@  1. Visibility -- OBJ_EVENT_GFX_SPECIES(MEWTWO) (map.json), flag
@     FLAG_TRINITY_K_MEWTWO_HIDE, ON_TRANSITION below.
@  2. The fight -- seteventmon + BOTH BattleSetup_StartLegendaryBattle
@     switches (src/battle_setup.c, src/pokemon.c's GetBattleBGM -- both
@     edited this slice to case SPECIES_MEWTWO; see those files' own comments).
@  3. Terminal -- FLAG_TRINITY_K_MEWTWO_RESOLVED, set on WON and on the
@     CAUGHT fall-through.
@
@ SILENT ENCOUNTER (sub-plan §3.1's own reading, delegated by the brief):
@ FRLG's Cerulean Cave Mewtwo has no approach dialogue at all. This is read
@ as "no flavour msgbox before the fight" -- straight from lock/faceplayer to
@ the cry and the battle -- and, on the WON path, Common_EventScript_
@ RemoveStaticPokemon (fade/removeobject/fade, NO text) rather than the
@ "flew away" message LegendaryFlewAway would print, so the encounter stays
@ wordless start to finish on its most likely outcome. This is the one clause
@ where MEWTWO's contract DIVERGES from the bird template by design, not by
@ omission.
@
@ P3 (MYSTERIOUS INVITATION) folds into this file's own resolution site
@ (sub-plan §3.3): the flag is co-signed the instant MEWTWO resolves, WON or
@ CAUGHT alike -- no separate scene, no second map touched.
@ ============================================================================
CeruleanCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCave_B1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CeruleanCave_B1F_OnResume
	.byte 0

CeruleanCave_B1F_OnTransition:
	goto_if_lt VAR_TRINITY_KANTO_ARC, 6, CeruleanCave_B1F_EventScript_HideMewtwo
	goto_if_set FLAG_TRINITY_K_MEWTWO_RESOLVED, CeruleanCave_B1F_EventScript_HideMewtwo
	clearflag FLAG_TRINITY_K_MEWTWO_HIDE
	end

CeruleanCave_B1F_EventScript_HideMewtwo::
	setflag FLAG_TRINITY_K_MEWTWO_HIDE
	end

@ THE THIRD MANDATORY CLAUSE of the legendary contract. A CAUGHT legendary
@ never re-enters its own talk script, so without this the object stands
@ there as a ghost. FLAG_SYS_CTRL_OBJ_DELETE is set around the battle and
@ only then does this fire.
CeruleanCave_B1F_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, CeruleanCave_B1F_EventScript_TryRemoveMewtwo
	end

CeruleanCave_B1F_EventScript_TryRemoveMewtwo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_KANTO_CERULEANCAVE_MEWTWO
	return

CeruleanCave_B1F_EventScript_Mewtwo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_MEWTWO, 95
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CeruleanCave_B1F_EventScript_MewtwoDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CeruleanCave_B1F_EventScript_MewtwoFled
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CeruleanCave_B1F_EventScript_MewtwoFled
	@ fall-through == B_OUTCOME_CAUGHT. ON_RESUME has already removed the
	@ object.
	call CeruleanCave_B1F_EventScript_MewtwoResolved
	release
	end

@ WON -> Common_EventScript_RemoveStaticPokemon (fade/removeobject/fade, NO
@ text), the bird-contract idiom (SeafoamIslands_B4F_EventScript_
@ ArticunoDefeated's own exact shape) -- NOT LegendaryFlewAway, which prints
@ a "flew away" line inappropriate to a defeated (not fled) legendary and
@ would break the silent reading above.
CeruleanCave_B1F_EventScript_MewtwoDefeated::
	call CeruleanCave_B1F_EventScript_MewtwoResolved
	goto Common_EventScript_RemoveStaticPokemon

CeruleanCave_B1F_EventScript_MewtwoFled::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryFlewAway

CeruleanCave_B1F_EventScript_MewtwoResolved::
	setflag FLAG_TRINITY_K_MEWTWO_RESOLVED
	setflag FLAG_TRINITY_K_MYSTERIOUS_INVITATION
	return
