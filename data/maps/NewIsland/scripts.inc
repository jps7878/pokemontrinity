@ ============================================================================
@ Trinity M5b S13a -- NEW ISLAND. A genuinely new, hand-authored Trinity map
@ (LAYOUT_NEW_ISLAND_KANTO, data/layouts/NewIsland/{map.bin,border.bin}), NOT
@ a reuse of the engine's own vanilla FARAWAY ISLAND (which already carries a
@ complete, unrelated Mew encounter -- FarawayIsland_Interior/scripts.inc --
@ that this slice deliberately leaves untouched; see the sub-plan §2/§3.4 for
@ the full reasoning). Reached only via VermilionCity's own Sailor object
@ (VermilionCity/scripts.inc), gated on FLAG_TRINITY_K_MYSTERIOUS_INVITATION,
@ which this map's own MEW-resolved handler co-signs (§3.3 of the sub-plan --
@ P3 is folded into P1's own resolution site, not a separate scene).
@
@ MEW's contract reuses the ENGINE'S OWN vanilla flags -- FLAG_HIDE_MEW,
@ FLAG_DEFEATED_MEW, FLAG_CAUGHT_MEW (flags.h:807/525/528) -- rather than
@ claiming fresh Trinity hex, because FarawayIsland's own Mew encounter is
@ verified UNREACHABLE by any live path in this tree today (FLAG_ENABLE_SHIP_
@ FARAWAY_ISLAND has its only writer in the orphaned data/scripts/
@ gift_old_sea_map.inc, never called from any story script -- confirmed by a
@ tree-wide grep of ITEM_OLD_SEA_MAP at implementation time). DISCLOSED RISK,
@ not hidden: if a FUTURE milestone ever wires FarawayIsland up as a live
@ feature, beating/catching Mew at ONE of the two sites would silently
@ resolve the OTHER too, since the flags are shared, not map-scoped. Judged
@ acceptable today because Hoenn is the already-shipped base region this
@ whole milestone leaves untouched and FarawayIsland's own gift item has
@ never been part of any Trinity story path across three milestones -- but
@ any future slice that DOES wire FarawayIsland must re-litigate this call,
@ not assume it still holds.
@ ============================================================================
NewIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewIsland_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NewIsland_OnResume
	.byte 0

@ Visibility: arc>=6 (world-tour/post-game gate, the same read every other
@ package in this slice uses -- CeruleanCity/scripts.inc:34-44's own arc read
@ is the cited template), AND not yet resolved. "Resolved" for a
@ vanilla-flag-reuse contract is FLAG_DEFEATED_MEW OR FLAG_CAUGHT_MEW (the
@ two outcomes the shipped bird contracts fold into one Trinity-owned
@ RESOLVED flag -- here there is no single flag to check, so both vanilla
@ ones are read explicitly).
NewIsland_OnTransition:
	goto_if_lt VAR_TRINITY_KANTO_ARC, 6, NewIsland_EventScript_HideMew
	goto_if_set FLAG_DEFEATED_MEW, NewIsland_EventScript_HideMew
	goto_if_set FLAG_CAUGHT_MEW, NewIsland_EventScript_HideMew
	clearflag FLAG_HIDE_MEW
	end

NewIsland_EventScript_HideMew::
	setflag FLAG_HIDE_MEW
	end

@ THE THIRD MANDATORY CLAUSE of the legendary contract (bird-contract
@ precedent, e.g. SeafoamIslands_B4F/scripts.inc:285-293): a CAUGHT legendary
@ never re-enters its own talk script, so without this the object stands
@ there as a ghost. FLAG_SYS_CTRL_OBJ_DELETE is set around the battle and
@ only then does this fire.
NewIsland_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NewIsland_EventScript_TryRemoveMew
	end

NewIsland_EventScript_TryRemoveMew::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_KANTO_NEWISLAND_MEW
	return

@ Clause 1 (visibility) is the object_events entry itself (map.json:
@ OBJ_EVENT_GFX_SPECIES(MEW), flag FLAG_HIDE_MEW). Clause 2 (the fight)
@ follows the exact shipped shape: seteventmon then BOTH
@ BattleSetup_StartLegendaryBattle switches already case SPECIES_MEW
@ (src/battle_setup.c:531-533, src/pokemon.c -- SPECIES_MEW falls to
@ GetBattleBGM's default, which already returns the right generic legend
@ theme; MEW's own dedicated MUS_VS_MEW is chosen on the field path by
@ BattleSetup_StartLegendaryBattle's own case, unchanged, no engine edit
@ needed for MEW). Clause 3 (terminal) sets FLAG_DEFEATED_MEW on WON and
@ FLAG_CAUGHT_MEW on the CAUGHT fall-through -- FarawayIsland_Interior's own
@ exact idiom (scripts.inc:140-148), copied verbatim onto the vanilla flags.
NewIsland_EventScript_Mew::
	lock
	faceplayer
	msgbox NewIsland_Text_Mew, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_MEW, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_MEW, 90
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewIsland_EventScript_MewDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewIsland_EventScript_MewFled
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewIsland_EventScript_MewFled
	@ fall-through == B_OUTCOME_CAUGHT. ON_RESUME has already removed the
	@ object; FLAG_TRINITY_K_MYSTERIOUS_INVITATION was already armed back at
	@ P1's own MEWTWO resolution (this is P4's own terminal state, not P3's).
	setflag FLAG_CAUGHT_MEW
	release
	end

NewIsland_EventScript_MewDefeated::
	setflag FLAG_DEFEATED_MEW
	setvar VAR_0x8004, SPECIES_MEW
	goto Common_EventScript_LegendaryFlewAway
	end

NewIsland_EventScript_MewFled::
	setvar VAR_0x8004, SPECIES_MEW
	goto Common_EventScript_LegendaryFlewAway
	end

NewIsland_Text_Mew:
	.string "Something small and pink drifts over\n"
	.string "the sand, watching you with plain\l"
	.string "curiosity.$"

@ ---------------------------------------------------------------------------
@ THE RETURN SAILOR. Deliberately the SIMPLER of the two idioms this engine
@ already ships for an event island's return trip: VermilionCity's own
@ Sailor (this map's forward half) uses a bare `warp` after a YESNO with NO
@ ferry-departure choreography, and that -- not FarawayIsland_Entrance's own
@ Common_EventScript_FerryDepartIsland dressing -- is the shape this script
@ mirrors. FerryDepartIsland was investigated and REJECTED for this site:
@ Common_EventScript_FerryDepart (data/event_scripts.s:1294) unconditionally
@ `applymovement`s VAR_0x8004 as a boat sprite's LOCALID, so it structurally
@ requires a decorative OBJ_EVENT_GFX_SS_TIDAL-class object standing at the
@ dock (FarawayIsland_Entrance/BirthIsland_Harbor/SouthernIsland_Exterior all
@ carry one) -- NEW ISLAND does not, and adding one for a single-use flourish
@ the founder's own "fade-warp only" framing does not ask for is exactly the
@ unrequested-scope class this milestone's house rule warns against. A bare
@ `warp` is already itself a fade transition (R4), which is what "fade-warp
@ only" names.
@
@ Landing tile (24,33) is NOT invented: it is the exact, already-decoded
@ arrival tile OlivinePort's own two Kanto-crossing warps already use
@ (OlivinePort/scripts.inc:125,182 -- `warp MAP_VERMILION_CITY, 24, 33`),
@ one tile east of LOCALID_KANTO_VERMILION_SAILOR's own (23,33) so the player
@ never lands on top of the NPC. No setrespawn (see this file's header
@ comment) -- a faint on NEW ISLAND must not strand the player here.
@ ---------------------------------------------------------------------------
NewIsland_EventScript_Sailor::
	lock
	faceplayer
	msgbox NewIsland_Text_SailBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NewIsland_EventScript_SailorDecline
	closemessage
	warp MAP_VERMILION_CITY, 24, 33
	waitstate
	release
	end

NewIsland_EventScript_SailorDecline::
	msgbox NewIsland_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

NewIsland_Text_SailBack:
	.string "Head back to VERMILION CITY now?$"

NewIsland_Text_SailAnotherTime:
	.string "Take your time. I'm not going\n"
	.string "anywhere.$"
