@ ============================================================================
@ Trinity M5b S13a -- MEWTWO. The cave's own "depths": this floor's single
@ warp (5,7) is the only way in or out (re-confirmed this slice: 494 walkable
@ tiles, all one connected component from that one warp, reach_check.py).
@ MEWTWO stands at (20,13), on a central island the floor's lake wraps
@ around. CORRECTED (fix round 1, review C2): this island is REACHABLE ON
@ FOOT -- the original comment here claimed "Surf-crossing required, matching
@ FRLG's own staging", which is FALSE. An explicit 86-step dry path exists
@ from the entrance warp to (20,13), crossing only MB_LADDER/MB_CAVE/
@ MB_ROCK_STAIRS behaviours, zero water tiles:
@ (5,7)->(7,7)->(7,3)->(13,3)->(13,5)->(18,5)->(18,2)->(24,2)->(27,3)->
@ (27,6)->(33,6)->(33,20)->(29,20)->(27,18)->(27,10)->(18,10)->(18,12)->
@ (20,12)->(20,13). The floor DOES contain one genuinely water-isolated
@ 14-cell pocket at (5,12)-(9,15) -- but MEWTWO and the hidden TM pickup are
@ not on it. This was NOT re-engineered to force Surf per the controller's
@ ruling (reachable-on-foot ships as-is); an M6 note is logged instead:
@ FRLG-parity Surf staging (moving MEWTWO onto the water-isolated pocket, or
@ otherwise gating the approach behind Surf) is available as a balance/
@ flavour option for a future polish pass, not required.
@ The hidden pickup (map.json bg_events) sits on the same island at (24,13),
@ the cave's "top-shelf" prize alongside its guardian.
@
@ M6 P1 (Balance-2, founder-dictated 2026-08-31): this pickup shipped M5b as
@ ITEM_TM25 (Thunder), a disclosed duplicate of two other live TM25 sources
@ tree-wide -- a visible ball in PowerPlant/map.json
@ (FLAG_TRINITY_KANTO_PICKUPS_START + 80) and mart listings in BOTH
@ CeladonCity_DepartmentStore_2F_Pokemart_TMs and LilycoveCity_
@ DepartmentStore_4F's AttackTMs list. RETARGETED to ITEM_TM_SKILL_SWAP
@ (TM48): a tree-wide census of every giveitem / hidden_item(bg_event) /
@ mart-list TM occurrence across all 50 classic TMs (both the numbered
@ ITEM_TMnn and named ITEM_TM_<MOVE> spellings, cross-mapped via
@ include/constants/tms_hms.h's FOREACH_TM ordering) found Skill Swap the
@ ONLY TM with zero hits in those three categories -- every other TM is
@ already a curated NPC award, a bg_event hidden pickup, or a mart sale
@ somewhere else in this 3-region tree (full candidate table: M6 P1
@ report). It does carry two ordinary field-ball copies elsewhere
@ (Route12's Kanto placement, MtPyre_Exterior's native Hoenn one) -- that's
@ each region's own routine per-region TM distribution, the same category
@ TM25's own PowerPlant ball sat in without being the disqualifying factor;
@ TM25 failed dedup on its TWO mart listings, not that ball. ONLY the item
@ id changed here -- the pickup flag (+ 241), x/y/elevation, and script are
@ byte-identical to what shipped in M5b.
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
@ the cry and the battle. CORRECTED (fix round 2, review N1): the WON path
@ does NOT stay wordless start to finish -- that was true of round 1's
@ shipped shape (a bare `goto Common_EventScript_RemoveStaticPokemon`, fade/
@ removeobject/fade, no text) but round 1's own M1(a) fix (see
@ MewtwoDefeated's own comment at :120-129 below) inlined that body and added
@ the MYSTERIOUS INVITATION msgbox immediately after the fade back in. The
@ silence now covers MEWTWO's OWN encounter only -- no approach line, no
@ battle-outcome line, nothing while MEWTWO himself is on screen or fading
@ out -- and ends there by design: the beat that follows is a deliberately
@ separate narrative moment, not part of MEWTWO's own silence. This is the
@ one clause where MEWTWO's contract DIVERGES from the bird template by
@ design, not by omission.
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
	@ Trinity M5b S13b fix round 1 (review C2, cross-slice ruling): every
	@ shipped legendary contract was missing this branch. `setteleportoutcome`
	@ is emitted from FOUR battle scripts (asm/macros/battle_script.inc:2100-
	@ 2101), not only Teleport's own: BattleScript_DoEffectTeleport,
	@ BattleScript_RoarSuccessEndBattle, and -- the route that actually
	@ matters for a WILD legendary -- BattleScript_EmergencyExitWild /
	@ _WildEnd2 (data/battle_scripts_1.s:6565/6596). A player who Skill
	@ Swaps or Entrainments ABILITY_EMERGENCY_EXIT/WIMP_OUT onto MEWTWO (its
	@ own ability, Pressure, does not block the transfer) and drops it below
	@ half HP ends the battle B_OUTCOME_MON_TELEPORTED -- with no branch
	@ here, that fell through to "CAUGHT" and set FLAG_TRINITY_K_MEWTWO_
	@ RESOLVED (and printed the invitation beat) with nothing caught, a
	@ permanent uncatchable loss. Routed to the same Fled handler as a
	@ normal RAN outcome -- MEWTWO got away either way, and the invitation
	@ (armed only on WON/CAUGHT) correctly does NOT arm on this outcome.
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, CeruleanCave_B1F_EventScript_MewtwoFled
	@ fall-through == B_OUTCOME_CAUGHT. ON_RESUME has already removed the
	@ object.
	call CeruleanCave_B1F_EventScript_MewtwoResolved
	msgbox CeruleanCave_B1F_Text_Invitation, MSGBOX_DEFAULT
	release
	end

@ WON -> Common_EventScript_RemoveStaticPokemon's own body, INLINED (fade/
@ removeobject/fade) rather than `goto`-ed to, because a `goto` cannot return
@ -- and the invitation beat (review M1(a)) must print AFTER the fade-in, not
@ before it, so MEWTWO's own encounter stays wordless right up to the fade
@ (the silent reading, unaffected) while the beat that follows is a
@ deliberately separate narrative moment. Fade/removeobject/fade shape
@ verified byte-identical to Common_EventScript_RemoveStaticPokemon
@ (data/event_scripts.s:1581-1586) before inlining it. NOT LegendaryFlewAway,
@ which prints a "flew away" line inappropriate to a defeated (not fled)
@ legendary.
CeruleanCave_B1F_EventScript_MewtwoDefeated::
	call CeruleanCave_B1F_EventScript_MewtwoResolved
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox CeruleanCave_B1F_Text_Invitation, MSGBOX_DEFAULT
	release
	end

CeruleanCave_B1F_EventScript_MewtwoFled::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryFlewAway

@ Sets BOTH terminal flags; prints nothing itself (review M1(a): the actual
@ invitation beat is msgbox'd by each CALLER above, after MEWTWO's own fade,
@ not from inside this shared flag-setting body -- keeping the WON path's
@ fade timing correct without duplicating the msgbox line twice was the
@ deciding factor). Armed on WON and on the CAUGHT fall-through only -- a
@ fled MEWTWO must not arm it, and does not (CeruleanCave_B1F_EventScript_
@ MewtwoFled never calls this).
CeruleanCave_B1F_EventScript_MewtwoResolved::
	setflag FLAG_TRINITY_K_MEWTWO_RESOLVED
	setflag FLAG_TRINITY_K_MYSTERIOUS_INVITATION
	return

@ Review M1(a): the MYSTERIOUS INVITATION becomes a real, player-facing beat
@ -- a physical envelope the player finds and takes -- so VermilionCity's own
@ Sailor line (VermilionCity/scripts.inc, VermilionCity_Text_TwoDestinations)
@ references something that actually happened, not an invented letter. The
@ two texts are written to agree on what happened; if either changes, check
@ the other.
CeruleanCave_B1F_Text_Invitation:
	.string "Tucked among the rocks where MEWTWO\n"
	.string "stood is a plain envelope. You pick\l"
	.string "it up -- the seal shows a small\l"
	.string "island, somewhere out to sea.$"
