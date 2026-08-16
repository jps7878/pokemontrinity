DarkCaveBlackthornEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DarkCaveBlackthornEntrance_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, DarkCaveBlackthornEntrance_OnResume
	.byte 0

DarkCaveBlackthornEntrance_EventScript_Pharmacist::
	msgbox DarkCaveBlackthornEntrance_Text_Pharmacist, MSGBOX_NPC
	end

DarkCaveBlackthornEntrance_Text_Pharmacist:
	.string "Did you hear? A HOENN trainer\nbecame Champion, and now folks\lhere want to challenge them.$"

@ ============================================================================
@ Trinity M4b S10 -- ENTEI's lair.
@
@ AMENDMENT, SAME AS RAIKOU'S: an invention, not a port. GSC's beasts roam a
@ route-only graph (data/wild/roammon_maps.asm) and appear in no cave at all;
@ DARK CAVE's own GSC cast is a PHARMACIST, two item balls and four Rock Smash
@ rocks. The S10 contract line names "a Dark Cave chamber", and this is the
@ BLACKTHORN side because it is the deeper of the two entrances -- reached from
@ ROUTE 45 or through the VIOLET half, and the further from any town.
@
@ TILE, DECODED: (21,27) collision 0, elevation 3, MB_NORMAL, reachable, and it
@ costs EXACTLY ONE TILE (its own). It sits in the southern chamber (row 27 is
@ walkable at x 18..24 and nowhere else), the deepest pocket on the map's
@ reachable side. The map reads 380 of 831 walkable tiles reachable from its two
@ doors; the unreached half is pre-existing port geometry and ENTEI is placed
@ INSIDE the flood-filled component, never in it.
@
@ GATE: FLAG_TRINITY_J_BEASTS_AWAKENED (0x46, S5).
@ MUSIC: MUS_C_VS_LEGEND_BEAST -- see the case S10 added to
@ BattleSetup_StartLegendaryBattle (src/battle_setup.c).
@ ============================================================================

DarkCaveBlackthornEntrance_OnTransition::
	call_if_set FLAG_TRINITY_J_ENTEI_RESOLVED, DarkCaveBlackthornEntrance_EventScript_HideEntei
	call_if_unset FLAG_TRINITY_J_ENTEI_RESOLVED, DarkCaveBlackthornEntrance_EventScript_TryShowEntei
	end

DarkCaveBlackthornEntrance_EventScript_HideEntei::
	setflag FLAG_TRINITY_J_ENTEI_HIDE
	return

DarkCaveBlackthornEntrance_EventScript_TryShowEntei::
	goto_if_unset FLAG_TRINITY_J_BEASTS_AWAKENED, DarkCaveBlackthornEntrance_EventScript_HideEntei
	clearflag FLAG_TRINITY_J_ENTEI_HIDE
	return

DarkCaveBlackthornEntrance_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, DarkCaveBlackthornEntrance_EventScript_TryRemoveEntei
	end

DarkCaveBlackthornEntrance_EventScript_TryRemoveEntei::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_JOHTO_DCBE_ENTEI
	return

DarkCaveBlackthornEntrance_EventScript_Entei::
	lock
	faceplayer
	msgbox DarkCaveBlackthornEntrance_Text_Entei, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_ENTEI, 68
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, DarkCaveBlackthornEntrance_EventScript_EnteiDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, DarkCaveBlackthornEntrance_EventScript_EnteiFled
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, DarkCaveBlackthornEntrance_EventScript_EnteiFled
	@ fall-through == B_OUTCOME_CAUGHT. ON_RESUME has already removed the object.
	setflag FLAG_TRINITY_J_ENTEI_RESOLVED
	release
	end

DarkCaveBlackthornEntrance_EventScript_EnteiDefeated::
	setflag FLAG_TRINITY_J_ENTEI_RESOLVED
	goto Common_EventScript_RemoveStaticPokemon

DarkCaveBlackthornEntrance_EventScript_EnteiFled::
	setvar VAR_0x8004, SPECIES_ENTEI
	goto Common_EventScript_LegendaryFlewAway

DarkCaveBlackthornEntrance_Text_Entei:
	.string "You have been walking through cold\n"
	.string "stone for an hour.\p"
	.string "This chamber is warm, and there is\n"
	.string "nothing burning in it.$"
