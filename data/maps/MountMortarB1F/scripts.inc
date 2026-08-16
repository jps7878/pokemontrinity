MountMortarB1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MountMortarB1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MountMortarB1F_OnResume
	.byte 0

MountMortarB1F_EventScript_Kiyo::
	msgbox MountMortarB1F_Text_Kiyo, MSGBOX_NPC
	end

MountMortarB1F_Text_Kiyo:
	.string "I've been wandering these routes\nfor years. Lately there's talk of\lnothing but the HOENN champion.$"

@ ============================================================================
@ Trinity M4b S10 -- RAIKOU's lair, and GSC's Strength boulder.
@
@ AMENDMENT, STATED PLAINLY: THIS IS AN INVENTION, NOT A PORT. GSC does not put
@ RAIKOU anywhere. The beasts ROAM -- BurnedTowerB1F.asm:33-97 ends its release
@ scene with `special InitRoamMons`, and data/wild/roammon_maps.asm is a
@ route-only graph (Routes 29-39 and 42-46; no cave, no indoor map is in it).
@ Trinity has no roamer system for them and S5's B5 said so explicitly: "the
@ awakening sets a story flag, NOT encounters. S10 owns the lairs." The S10
@ contract line names Mt Mortar; the nearest GSC precedent for a static beast is
@ the TIN TOWER 1F tableau, which this copies.
@
@ TILE, DECODED: (3,18) collision 0, elevation 3, MB_NORMAL, reachable, and it
@ costs EXACTLY ONE TILE (its own) with every other object placed. It is the
@ deepest LAND tile on the floor -- 75 steps from the nearer of the two ladders
@ by BFS, in the narrow western gallery. The whole eastern half of B1F decodes
@ MB_POND_WATER at elevation 1, which is why the lair is west: an electric beast
@ standing in a lake reads as an accident.
@
@ NOT BEHIND A WATERFALL, deliberately. reach_check learned MB_WATERFALL this
@ slice, and with the ascent gate ON, MOUNT MORTAR 1F OUTSIDE loses
@ (17,5) -> MOUNT MORTAR 2F INSIDE (352 tiles -> 151): 2F Inside IS a real
@ Waterfall gate. B1F is not -- its (19,29) ladder is a door of 1F OUTSIDE's
@ non-waterfall half -- so RAIKOU sits behind no undisclosed HM wall.
@
@ GATE: FLAG_TRINITY_J_BEASTS_AWAKENED (0x46, S5's Burned Tower scene) gets its
@ first ENCOUNTER reader here; its six existing readers are all dialogue.
@ MUSIC: MUS_C_VS_LEGEND_BEAST, via the SUICUNE/RAIKOU/ENTEI case S10 added to
@ BattleSetup_StartLegendaryBattle (src/battle_setup.c). Required, not optional:
@ that switch's `default:` sits on the GROUDON body.
@
@ THE BOULDER at (9,10) is GSC's own (MountMortarB1F.asm:150), decoded
@ collision 0 / elevation 3 / MB_NORMAL / reachable, costing one tile. It is a
@ plain blocker with no hole under it, so it takes a FLAG_TEMP like vanilla's
@ own 59 boulders: template positions never persist
@ (LoadObjEventTemplatesFromHeader, src/overworld.c:521-530), so a permanent
@ flag on a boulder that can only be shoved would be dead weight, and a stray
@ removeobject on one would co-sign it out of existence for good.
@ ============================================================================

MountMortarB1F_OnTransition::
	call_if_set FLAG_TRINITY_J_RAIKOU_RESOLVED, MountMortarB1F_EventScript_HideRaikou
	call_if_unset FLAG_TRINITY_J_RAIKOU_RESOLVED, MountMortarB1F_EventScript_TryShowRaikou
	end

MountMortarB1F_EventScript_HideRaikou::
	setflag FLAG_TRINITY_J_RAIKOU_HIDE
	return

MountMortarB1F_EventScript_TryShowRaikou::
	goto_if_unset FLAG_TRINITY_J_BEASTS_AWAKENED, MountMortarB1F_EventScript_HideRaikou
	clearflag FLAG_TRINITY_J_RAIKOU_HIDE
	return

MountMortarB1F_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MountMortarB1F_EventScript_TryRemoveRaikou
	end

MountMortarB1F_EventScript_TryRemoveRaikou::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_JOHTO_MMB1_RAIKOU
	return

MountMortarB1F_EventScript_Raikou::
	lock
	faceplayer
	msgbox MountMortarB1F_Text_Raikou, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_RAIKOU, 68
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MountMortarB1F_EventScript_RaikouDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MountMortarB1F_EventScript_RaikouFled
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MountMortarB1F_EventScript_RaikouFled
	@ fall-through == B_OUTCOME_CAUGHT. ON_RESUME has already removed the object.
	setflag FLAG_TRINITY_J_RAIKOU_RESOLVED
	release
	end

MountMortarB1F_EventScript_RaikouDefeated::
	setflag FLAG_TRINITY_J_RAIKOU_RESOLVED
	goto Common_EventScript_RemoveStaticPokemon

MountMortarB1F_EventScript_RaikouFled::
	setvar VAR_0x8004, SPECIES_RAIKOU
	goto Common_EventScript_LegendaryFlewAway

MountMortarB1F_Text_Raikou:
	.string "The gallery is dry and the air in it\n"
	.string "is not.\p"
	.string "Every hair on your arms is standing\n"
	.string "up, and the thing at the end of it\l"
	.string "has not moved since you came in.$"
