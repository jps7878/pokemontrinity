@ ============================================================================
@ M4b S11 -- VICTORY ROAD 3F. Two league-run trainers, and one port repair.
@
@ THE HOLE AT (34,18) HAD NO LANDING. It decodes MB_CRACKED_FLOOR_HOLE, which
@ arms STEP_CB_CRACKED_FLOOR, and this map had no `setholewarp` -- so falling
@ through it warped to whatever sFixedHoleWarp last held. (In pokefirered the
@ same byte is MB_FALL_WARP; the two decomps' behaviour enums diverge, which is
@ the defect class tools/kanto_port/fix_behaviors.py exists for. Here the two
@ meanings agree, so the byte is deliberately left alone and the missing half is
@ the script.) FRLG routes that fall to VICTORY ROAD 2F, and so does the map's
@ own warp 4 at the same tile, so the landing is not a guess.
@
@ setholewarp is not a metatile write, so qa_sweep check 7 is unaffected by it
@ living under ON_TRANSITION -- which is where every vanilla user puts it
@ (BurnedTower1F/scripts.inc:9, GraniteCave_B1F/scripts.inc:9).
@ ============================================================================

VictoryRoad_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_3F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, VictoryRoad_3F_OnResume
	.byte 0

VictoryRoad_3F_OnTransition:
	setholewarp MAP_VICTORY_ROAD_2F
	call_if_set FLAG_TRINITY_K_MOLTRES_RESOLVED, VictoryRoad_3F_EventScript_HideMoltres
	call_if_unset FLAG_TRINITY_K_MOLTRES_RESOLVED, VictoryRoad_3F_EventScript_TryShowMoltres
	end

@ ============================================================================
@ Trinity M5b S11 -- MOLTRES, the third bird, static legendary contract, three
@ clauses. Mirrors S3's ZAPDOS (PowerPlant/scripts.inc) and S9's ARTICUNO
@ (SeafoamIslands_B4F/scripts.inc) exactly. Tile (10,16): TRUE, re-derived via
@ tools/johto_port/reach_check.py's own Map class -- col 0, elev 3, MB_CAVE
@ (0x8) -- the same tile family Zapdos/Articuno both use. Gate: NONE (reaching
@ it in KANTO VICTORY ROAD is the whole condition -- no story flag), so
@ Clause 1's TryShowMoltres is an unconditional clearflag, unlike Zapdos's own
@ FLAG_TRINITY_K_PLANT_RESTORED-gated version.
@
@ Clause 1 -- ON_TRANSITION show-if-unset-terminal. Clause 2 -- ON_RESUME +
@ FLAG_SYS_CTRL_OBJ_DELETE removeobject for the caught case. Clause 3 -- ONE
@ durable terminal flag (FLAG_TRINITY_K_MOLTRES_RESOLVED), written on WON and
@ on the CAUGHT fall-through.
@
@ Music: dowildbattle can only play MUS_VS_WILD, so special
@ BattleSetup_StartLegendaryBattle is used instead. SPECIES_MOLTRES added to
@ its switch (src/battle_setup.c) and to GetBattleBGM's switch (src/pokemon.c),
@ same REQUIRED/belt-and-braces split Zapdos/Articuno already established.
@
@ M7b Task 16 (finding #10, "Related known item") -- ACCEPTED AS IS, ruled
@ and recorded rather than left as folklore. The Act II league corridor does
@ cross this floor, so a JOHTO-league runner reaches MOLTRES (L80) and the
@ hidden TM15 at (12,17) before Act III. Measured at Task 16, and the
@ measurement does NOT say they are out of the way: BFS from this floor's
@ own landing (5,2), with the three objects placed, puts MOLTRES's approach
@ tile (11,16) at 22 steps and the TM15 tile (12,17) at 24, against 38 to
@ the nearest onward exit (34,9) -- they sit off the corridor by a detour of
@ about 24 steps (landing -> (11,16) -> (34,9) is 62), not in another wing.
@ They are accepted anyway, on three grounds that do not depend on distance:
@ (1) gating them REMOVES a reward from Act II, which is a power-curve
@ change in the restrictive direction, and M7's Global Constraints freeze
@ the curve; (2) M7b is legibility work -- hiding a legendary the player can
@ see behind a flag whose key is in another act is finding #6c's exact
@ "locked door with no key in sight" failure, which this milestone exists to
@ remove; (3) it would reverse S11's own deliberate "Gate: NONE" ruling
@ above on balance grounds with no play evidence against it -- the founder's
@ bug-test raised this as an accepted balance note, not a complaint.
@ Catching an L80 MOLTRES with Act II resources is itself the skill check
@ the M7b charter says to preserve. The KANTO leak finding #10 actually
@ names is closed at its source instead: KantoVictoryRoad_1F (20,10), gated
@ on FLAG_TRINITY_K_ARRIVED (M7b Task 16).
@ ============================================================================
VictoryRoad_3F_EventScript_HideMoltres::
	setflag FLAG_TRINITY_K_MOLTRES_HIDE
	return

VictoryRoad_3F_EventScript_TryShowMoltres::
	clearflag FLAG_TRINITY_K_MOLTRES_HIDE
	return

VictoryRoad_3F_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, VictoryRoad_3F_EventScript_TryRemoveMoltres
	end

VictoryRoad_3F_EventScript_TryRemoveMoltres::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_KANTO_VR3F_MOLTRES
	return

VictoryRoad_3F_EventScript_Moltres::
	lock
	faceplayer
	msgbox VictoryRoad_3F_Text_Moltres, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_MOLTRES, 80
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, VictoryRoad_3F_EventScript_MoltresDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VictoryRoad_3F_EventScript_MoltresFled
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VictoryRoad_3F_EventScript_MoltresFled
	@ Trinity M5b S13b fix round 1 (review C2, cross-slice ruling): every
	@ shipped legendary contract was missing this branch. `setteleportoutcome`
	@ is emitted from FOUR battle scripts (asm/macros/battle_script.inc:2100-
	@ 2101), not only Teleport's own: BattleScript_DoEffectTeleport,
	@ BattleScript_RoarSuccessEndBattle, and -- the route that actually
	@ matters for a WILD legendary -- BattleScript_EmergencyExitWild /
	@ _WildEnd2 (data/battle_scripts_1.s:6565/6596). A player who Skill
	@ Swaps or Entrainments ABILITY_EMERGENCY_EXIT/WIMP_OUT onto MOLTRES (its
	@ own ability, Pressure, carries no cantBeSwapped/cantBeOverwritten flag
	@ -- src/data/abilities.h -- so it does not block the transfer) and
	@ drops it below half HP
	@ ends the battle B_OUTCOME_MON_TELEPORTED -- with no branch here, that
	@ fell through to "CAUGHT" and set FLAG_TRINITY_K_MOLTRES_RESOLVED with
	@ nothing caught, a permanent uncatchable loss. Routed to the same Fled
	@ handler as a normal RAN outcome.
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, VictoryRoad_3F_EventScript_MoltresFled
	@ fall-through == B_OUTCOME_CAUGHT. ON_RESUME has already removed the object.
	setflag FLAG_TRINITY_K_MOLTRES_RESOLVED
	release
	end

VictoryRoad_3F_EventScript_MoltresDefeated::
	setflag FLAG_TRINITY_K_MOLTRES_RESOLVED
	goto Common_EventScript_RemoveStaticPokemon

VictoryRoad_3F_EventScript_MoltresFled::
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto Common_EventScript_LegendaryFlewAway

VictoryRoad_3F_Text_Moltres:
	.string "The rock ledge above the hole is\n"
	.string "warm to the touch, though nothing\l"
	.string "here should be burning.\p"
	.string "Something with wings the color of\n"
	.string "a struck match is watching you\l"
	.string "from the dark.$"

VictoryRoad_3F_EventScript_BRODY::
	trainerbattle_single TRAINER_VR_COOLTRAINER_M_3, VictoryRoad_3F_Text_BRODYSeen, VictoryRoad_3F_Text_BRODYBeaten
	msgbox VictoryRoad_3F_Text_BRODYAfter, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_PHILANA::
	trainerbattle_single TRAINER_VR_COOLTRAINER_F_3, VictoryRoad_3F_Text_PHILANASeen, VictoryRoad_3F_Text_PHILANABeaten
	msgbox VictoryRoad_3F_Text_PHILANAAfter, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_BRODYSeen:
	.string "Top floor. Nothing up here but\n"
	.string "rock and people who won't leave.$"

VictoryRoad_3F_Text_BRODYBeaten:
	.string "Fine. I'll leave.$"

VictoryRoad_3F_Text_BRODYAfter:
	.string "Watch the floor on the east side.\n"
	.string "There's a hole in it, and it goes\l"
	.string "all the way back down to two.\p"
	.string "Ask me how I know.$"

VictoryRoad_3F_Text_PHILANASeen:
	.string "The ELITE FOUR are past this.\p"
	.string "I've never seen them. I only ever\n"
	.string "meet the people on the way up.$"

VictoryRoad_3F_Text_PHILANABeaten:
	.string "And now I've met the one who\n"
	.string "gets through.$"

VictoryRoad_3F_Text_PHILANAAfter:
	.string "Four rooms, one after another,\n"
	.string "and the door shuts behind you\l"
	.string "each time.\p"
	.string "There's no walking back out of\n"
	.string "that place. Only forward.$"
