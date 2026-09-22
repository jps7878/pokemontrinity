PowerPlant_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PowerPlant_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PowerPlant_OnResume
	.byte 0

@ ============================================================================
@ Trinity M5b S3 -- THE POWER PLANT. Adapts pokecrystal maps/PowerPlant.asm (the
@ MANAGER's plea + restoration beat) and mirrors FRLG's own PowerPlant/scripts.inc
@ ZAPDOS (pokefirered/data/maps/PowerPlant/scripts.inc:16-69) for the static
@ legendary. Full decode: docs/superpowers/plans/m5b/03-cerulean-power-plant.md
@ section 2.
@
@ Kept minimal per the brief's own framing and the house "keep it simple" rule:
@ ONE new NPC (the manager) carries the whole chain. GSC's officer/gym-guide
@ flavor relay (4 more NPCs) is cross-referenced to the MAGNET TRAIN, already
@ resolved independently by S2 -- logged skipped, not ported.
@
@ THE MANAGER. OBJ_EVENT_GFX_SCIENTIST_1 (BillsFamilysHouse's own "no dedicated
@ sprite, wears a scientist" precedent). Placed (37,17) -- decoded col 0 elev 3
@ MB_CAVE (this tileset's interior-floor behavior), inside the map's central
@ machinery hall, away from every T10 pickup. Chain, MOST-ADVANCED-FIRST (the
@ CianwoodPharmacy/SECRETPOTION lesson, same discipline as CeruleanCity_Gym's
@ pool pickup):
@   1. FLAG_TRINITY_K_PLANT_RESTORED set -> cheerful, generator humming.
@   2. FLAG_TRINITY_K_SABOTEUR_DONE set -> branch on FLAG_TRINITY_K_MACHINE_PART:
@      held -> turn-in (clears the part flag, sets RESTORED -- this is what
@      arms ZAPDOS below); not held -> "I won't forgive him" waiting line.
@   3. FLAG_TRINITY_BADGE18 unset -> pre-badge stub (the brief's "post-badge"
@      pin for the saboteur beat -- the manager IS the gate, since arming the
@      gym scene is his own first-meet action).
@   4. Else (post-badge, first meet): the plea, then arm the gym scene
@      (setvar VAR_TRINITY_SCENE_CERULEAN_SABOTEUR, 1).
@ GSC's EVENT_MET_MANAGER_AT_POWER_PLANT intermediate flag is dropped: re-talking
@ before visiting the gym just re-runs step 4, which re-arms an already-armed
@ var (idempotent, zero side effects) -- a flag purely to silence one harmless
@ repeated line is not worth its own registry claim.
@ ============================================================================
PowerPlant_EventScript_Manager::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_K_PLANT_RESTORED, PowerPlant_EventScript_ManagerRestored
	goto_if_set FLAG_TRINITY_K_SABOTEUR_DONE, PowerPlant_EventScript_ManagerCheckPart
	goto_if_unset FLAG_TRINITY_BADGE18, PowerPlant_EventScript_ManagerPreBadge
	msgbox PowerPlant_Text_ManagerWhoWouldRuinMyGenerator, MSGBOX_DEFAULT
	setvar VAR_TRINITY_SCENE_CERULEAN_SABOTEUR, 1
	release
	end

PowerPlant_EventScript_ManagerPreBadge::
	msgbox PowerPlant_Text_ManagerPreBadge, MSGBOX_DEFAULT
	release
	end

PowerPlant_EventScript_ManagerCheckPart::
	goto_if_unset FLAG_TRINITY_K_MACHINE_PART, PowerPlant_EventScript_ManagerStillMissing
	msgbox PowerPlant_Text_ManagerThatsThePart, MSGBOX_DEFAULT
	clearflag FLAG_TRINITY_K_MACHINE_PART
	setflag FLAG_TRINITY_K_PLANT_RESTORED
	msgbox PowerPlant_Text_ManagerPowerRestored, MSGBOX_DEFAULT
	release
	end

PowerPlant_EventScript_ManagerStillMissing::
	msgbox PowerPlant_Text_ManagerIWontForgiveHim, MSGBOX_DEFAULT
	release
	end

PowerPlant_EventScript_ManagerRestored::
	msgbox PowerPlant_Text_ManagerCheerful, MSGBOX_DEFAULT
	release
	end

PowerPlant_Text_ManagerPreBadge:
	.string "MANAGER: The power's been out\n"
	.string "for days. I don't have time to\l"
	.string "talk -- not until MISTY's proven\l"
	.string "you're worth my trouble.$"

PowerPlant_Text_ManagerWhoWouldRuinMyGenerator:
	.string "MANAGER: I'm ready to blast\n"
	.string "someone!\p"
	.string "Who would dare ruin my\n"
	.string "generator? I spent years on it.\p"
	.string "If I catch him, he's getting a\n"
	.string "taste of my ZAP CANNON!$"

PowerPlant_Text_ManagerIWontForgiveHim:
	.string "MANAGER: I won't forgive him.\p"
	.string "He can cry and apologize all he\n"
	.string "wants -- I'll still hammer him.\p"
	.string "Someone said he ditched it in\n"
	.string "the CERULEAN GYM's pool before\l"
	.string "he ran off. Check the water\l"
	.string "yourself, if you're curious.$"

PowerPlant_Text_ManagerThatsThePart:
	.string "MANAGER: That's it! That's the\n"
	.string "part from my generator!\p"
	.string "You actually found it…$"

PowerPlant_Text_ManagerPowerRestored:
	.string "MANAGER: Keep pumping, you\n"
	.string "beautiful machine!\p"
	.string "The whole plant's running again.\n"
	.string "KANTO owes you one.$"

PowerPlant_Text_ManagerCheerful:
	.string "MANAGER: My beloved generator!\n"
	.string "Not a hiccup since you fixed it.$"

@ ============================================================================
@ Trinity M5b S3 -- ZAPDOS, THE STATIC-LEGENDARY CONTRACT (all three mandatory
@ clauses). Canonical Trinity shape: DarkCaveBlackthornEntrance's ENTEI --
@ itself the Trinity-side mirror of vanilla NavelRock_Bottom_EventScript_Lugia.
@ FRLG's own PowerPlant ZAPDOS (pokefirered/data/maps/PowerPlant/scripts.inc)
@ is additional confirming precedent: same tile family (5,11), same 3-clause
@ shape. Full decode: the sub-plan section 2.
@
@ Tile (5,11): Trinity's Kanto-ported layout decodes col 0 elev 3 MB_CAVE,
@ reachable, inside the small upper-left chamber near the map's own entrance --
@ matches FRLG's placement depth exactly.
@
@ Clause 1 -- ON_TRANSITION show-if-unset-terminal (a fled ZAPDOS must never be
@ permanently missable). Clause 2 -- ON_RESUME + FLAG_SYS_CTRL_OBJ_DELETE
@ removeobject for the caught case. Clause 3 -- ONE durable terminal flag
@ (FLAG_TRINITY_K_ZAPDOS_RESOLVED), written on WON and on the CAUGHT
@ fall-through (ON_RESUME already removed the object by then).
@
@ Gate: ZAPDOS appears only after FLAG_TRINITY_K_PLANT_RESTORED, folded into
@ clause 1's own TryShowZapdos guard rather than a separate bolt-on check.
@
@ Music: dowildbattle can ONLY play MUS_VS_WILD (S10's pin), so
@ special BattleSetup_StartLegendaryBattle is used instead. SPECIES_ZAPDOS
@ added to its switch (src/battle_setup.c, REQUIRED -- default sits on the
@ GROUDON body) and to GetBattleBGM's switch (src/pokemon.c, belt-and-braces
@ documentation parity -- its own default already agreed).
@ ============================================================================
PowerPlant_OnTransition::
	call Common_EventScript_SetupRivalGfxId
	call_if_set FLAG_TRINITY_K_ZAPDOS_RESOLVED, PowerPlant_EventScript_HideZapdos
	call_if_unset FLAG_TRINITY_K_ZAPDOS_RESOLVED, PowerPlant_EventScript_TryShowZapdos
	call PowerPlant_EventScript_SetRivalVisibility
	end

@ ============================================================================
@ M7b Task 18 (#13, WHERE): the Act I rival, cameo 3 of 4. Folded into the
@ EXISTING ON_TRANSITION rather than added as a second one (single-occupancy).
@ Mechanism, hide flag and sprite seeding as MtMoon_1F_OnTransition, whose
@ header carries the full rationale.
@
@ WINDOW: KANTO arrival done AND 6 or more KANTO badges AND the KANTO arc still
@ below 6 -- she moves to the CERULEAN CAVE mouth the moment ASH falls, so
@ exactly one sighting is ever live.
@
@ PLACEMENT (7,37): col 0, elev 3, MB_CAVE, two tiles east and one north of the
@ ROUTE 10 door landing at (5,38), clear of the northward lane (row 37 is open
@ across columns 1-9). reach_check 954 -> 953: delta 1, her own tile.
@
@ THE MAP'S OTHER ROUTE 10 DOOR IS NOT A SECOND ENTRANCE, so one cameo covers
@ every arrival. PowerPlant warp 3 at (1,11) leads to Route10 warp 4 at (2,37),
@ and that tile sits in a SIX-TILE POCKET -- (1,36)-(1,39),(2,37),(2,38) -- with
@ no walkable link to the rest of ROUTE 10: (1,40) and (3,37)/(3,38) are all
@ collision 1, verified by flood fill from (7,41), which reaches 686 tiles and
@ does not include (2,37). Every player entering from ROUTE 10 therefore comes
@ through warp 2 at (7,40) and lands on (5,38), two tiles from her.
@ ============================================================================
PowerPlant_EventScript_SetRivalVisibility::
	goto_if_unset FLAG_TRINITY_K_ARRIVED, PowerPlant_EventScript_HideRival
	goto_if_ge VAR_TRINITY_KANTO_ARC, 6, PowerPlant_EventScript_HideRival
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 6, PowerPlant_EventScript_HideRival
	clearflag FLAG_TEMP_5
	return

PowerPlant_EventScript_HideRival::
	setflag FLAG_TEMP_5
	return

PowerPlant_EventScript_HideZapdos::
	setflag FLAG_TRINITY_K_ZAPDOS_HIDE
	return

PowerPlant_EventScript_TryShowZapdos::
	goto_if_unset FLAG_TRINITY_K_PLANT_RESTORED, PowerPlant_EventScript_HideZapdos
	clearflag FLAG_TRINITY_K_ZAPDOS_HIDE
	return

PowerPlant_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, PowerPlant_EventScript_TryRemoveZapdos
	end

PowerPlant_EventScript_TryRemoveZapdos::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_KANTO_PP_ZAPDOS
	return

PowerPlant_EventScript_Zapdos::
	lock
	faceplayer
	msgbox PowerPlant_Text_Zapdos, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_ZAPDOS, 78
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerPlant_EventScript_ZapdosDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerPlant_EventScript_ZapdosFled
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_ZapdosFled
	@ Trinity M5b S13b fix round 1 (review C2, cross-slice ruling): every
	@ shipped legendary contract was missing this branch. `setteleportoutcome`
	@ is emitted from FOUR battle scripts (asm/macros/battle_script.inc:2100-
	@ 2101), not only Teleport's own: BattleScript_DoEffectTeleport,
	@ BattleScript_RoarSuccessEndBattle, and -- the route that actually
	@ matters for a WILD legendary -- BattleScript_EmergencyExitWild /
	@ _WildEnd2 (data/battle_scripts_1.s:6565/6596). A player who Skill
	@ Swaps or Entrainments ABILITY_EMERGENCY_EXIT/WIMP_OUT onto ZAPDOS (its
	@ own ability, Pressure, carries no cantBeSwapped/cantBeOverwritten flag
	@ -- src/data/abilities.h -- so it does not block the transfer) and
	@ drops it below half HP
	@ ends the battle B_OUTCOME_MON_TELEPORTED -- with no branch here, that
	@ fell through to "CAUGHT" and set FLAG_TRINITY_K_ZAPDOS_RESOLVED with
	@ nothing caught, a permanent uncatchable loss. Routed to the same Fled
	@ handler as a normal RAN outcome.
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, PowerPlant_EventScript_ZapdosFled
	@ fall-through == B_OUTCOME_CAUGHT. ON_RESUME has already removed the object.
	setflag FLAG_TRINITY_K_ZAPDOS_RESOLVED
	release
	end

PowerPlant_EventScript_ZapdosDefeated::
	setflag FLAG_TRINITY_K_ZAPDOS_RESOLVED
	goto Common_EventScript_RemoveStaticPokemon

PowerPlant_EventScript_ZapdosFled::
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto Common_EventScript_LegendaryFlewAway

PowerPlant_Text_Zapdos:
	.string "The generator's roar has gone\n"
	.string "quiet.\p"
	.string "Something enormous is perched\n"
	.string "on the coils, feathers crackling\l"
	.string "with every spare volt in the\l"
	.string "building.$"

@ ============================================================================
@ M7b Task 18 (#13): cameo 3's line, and the one that carries the real WHERE
@ payload. The postgame CERULEAN CAVE rule is stated today by exactly ONE NPC
@ -- the guard at CeruleanCity (2,13), who stands on a Surf-only shelf the
@ player has no reason to visit -- so a player can reach the LEAGUE without
@ ever being told the cave exists or what opens it. This line tells them both.
@
@ The words deliberately say nothing about the generator, ZAPDOS or the floor:
@ this map's state varies (FLAG_TRINITY_K_PLANT_RESTORED,
@ FLAG_TRINITY_K_ZAPDOS_RESOLVED) and in-world information must be reliable in
@ every state. "You can hear this place before you can see it" always is. The
@ meeting pointer is a CONDITION ("beat the LEAGUE") because cameo 4 does not
@ exist until VAR_TRINITY_KANTO_ARC reaches 6 at the HALL OF FAME.
@ ============================================================================
PowerPlant_EventScript_Rival::
	msgbox PowerPlant_Text_Rival, MSGBOX_NPC
	end

PowerPlant_Text_Rival:
	.string "{RIVAL}: You can hear this place\n"
	.string "before you can see it.\p"
	.string "Twenty pages left, and the last\n"
	.string "of them are in the cave on\l"
	.string "CERULEAN's west shore.\p"
	.string "They only open it for a\n"
	.string "CHAMPION. Beat the LEAGUE and\l"
	.string "I'll be waiting at its mouth.$"
