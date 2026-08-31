@ ============================================================================
@ Trinity M5b S10 -- VIRIDIAN HIDEOUT B2F, the inner floor: the two-post
@ barrier, the raid, and the rig scene (Giovanni, Mewtwo, Mew). Full decode +
@ design: docs/superpowers/plans/m5b/10-viridian-climax.md.
@
@ Reuses RocketHideout_B4F's own LAYOUT_ROCKET_HIDEOUT_B4F_KANTO. FIX ROUND 1
@ (review M6/Minor 11) -- the full component enumeration of this shared
@ blockdata is SEVEN static-collision components, not two:
@ [178, 138, 4, 4, 1, 1, 1] (327 walkable total). The two that matter:
@ 178 tiles ("main" -- gate posts, barrier, sanctum) and 138 tiles ("left" --
@ the B3F stair (11,15) and Celadon's own F_1 tile (4,2)); the remaining five
@ (4+4+1+1+1 = 11 tiles) are small pre-existing pockets this floor's content
@ never touches. Re-derived fresh this session by full BFS, matching S6's
@ own B4F finding for the SAME underlying blockdata AND
@ s10-reach/viridian_basement_manual_seeding.txt's own correct enumeration
@ (the earlier draft of THIS comment claimed only two components while
@ contradicting itself twelve lines later -- both readings are replaced here
@ with the single true count). Unlike Celadon, THIS floor's own arrival tile
@ lands directly in the 178-tile component, so no lift-shuttle bridge is
@ needed.
@
@ SELF-CAUGHT (reach_check.py per-map decode, before shipping): the FIRST
@ arrival-tile choice, (16,3), decodes as a clear, open tile, but is NOT in
@ the 178-tile component at all -- it sits in one of the four-tile pockets,
@ alongside (17,3), fully disconnected from the main body (my earlier
@ "clear tile, inside the room's northern extent" reasoning checked openness
@ but never re-verified component membership after the fact). A second
@ candidate, (18,5), IS genuinely inside the 178-tile component but sits
@ NORTH of the barrier -- landing there let the player reach the sanctum
@ (Giovanni/Mewtwo/Mew) immediately, with the barrier instead blocking the
@ path OUT to the two gate posts, inverting the intended gate direction
@ entirely. Fixed: the arrival tile is `(18,16)`, decoded fresh, `col=0
@ elev=3 MB_NORMAL`, inside the 178-tile component, south of the barrier in
@ the same sub-region as the gate posts -- re-verified with the barrier
@ ARTIFICIALLY sealed (both grunt posts reachable, the sanctum NOT: 127
@ tiles reachable, re-derived and corrected from an earlier false "40 tiles"
@ claim, review C3) and with it open (everything reachable, 171 of 327
@ walkable tiles, matching the 178-tile component minus the 6 placed-object
@ self-tiles almost exactly). Both simulated states saved to s10-reach/.
@
@ ON_TRANSITION is the SINGLE AUTHORITY for all three visibility flags here
@ (S1 rule, AzaleaTown's own multi-flag shape copied verbatim): the raid cast
@ (arc==3), Mewtwo (arc==3 AND rig unresolved), and Mew (always hidden on a
@ fresh load -- a pure addobject-spawned session actor, never present outside
@ the live scene).
@ ============================================================================
ViridianHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ViridianHideout_B2F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianHideout_B2F_OnTransition
	.byte 0

@ D1-D5 barrier, same class as RocketHideout_B4F's own shipped mechanism (S6),
@ independent flag/coordinates on this floor's own shared blockdata. (17,14)/
@ (18,14) stay open floor throughout -- confirmed col=0 in the raw, unsealed
@ blockdata, never part of the wall.
ViridianHideout_B2F_OnLoad::
	call_if_unset FLAG_TRINITY_K_VBASEMENT_B2F_DOOR, ViridianHideout_B2F_EventScript_SetBarrier
	end

ViridianHideout_B2F_OnTransition::
	call ViridianHideout_B2F_EventScript_SetRaidVisibility
	call ViridianHideout_B2F_EventScript_SetMewtwoVisibility
	setflag FLAG_TRINITY_K_RIG_MEW_HIDE
	end

ViridianHideout_B2F_EventScript_SetRaidVisibility::
	goto_if_eq VAR_TRINITY_KANTO_ARC, 3, ViridianHideout_B2F_EventScript_ShowRaid
	setflag FLAG_TRINITY_K_VBASEMENT_RAID_HIDE
	return

ViridianHideout_B2F_EventScript_ShowRaid::
	clearflag FLAG_TRINITY_K_VBASEMENT_RAID_HIDE
	return

ViridianHideout_B2F_EventScript_SetMewtwoVisibility::
	goto_if_set FLAG_TRINITY_K_RIG_RESOLVED, ViridianHideout_B2F_EventScript_HideMewtwo
	goto_if_ne VAR_TRINITY_KANTO_ARC, 3, ViridianHideout_B2F_EventScript_HideMewtwo
	clearflag FLAG_TRINITY_K_RIG_MEWTWO_HIDE
	return

ViridianHideout_B2F_EventScript_HideMewtwo::
	setflag FLAG_TRINITY_K_RIG_MEWTWO_HIDE
	return

ViridianHideout_B2F_EventScript_SetBarrier::
	setmetatile 17, 12, 718, 1
	setmetatile 18, 12, 719, 1
	setmetatile 17, 13, 726, 1
	setmetatile 18, 13, 727, 1
	setmetatile 17, 14, 642, 0
	setmetatile 18, 14, 642, 0
	return

ViridianHideout_B2F_EventScript_RemoveBarrier::
	setmetatile 17, 12, 642, 0
	setmetatile 18, 12, 641, 0
	setmetatile 17, 13, 642, 0
	setmetatile 18, 13, 641, 0
	setmetatile 17, 14, 642, 0
	setmetatile 18, 14, 641, 0
	return

@ ----------------------------------------------------------------------------
@ THE BARRIER GATE. Both posts must fall (call_if_defeated on the OTHER id,
@ Celadon's own mechanism, D4 single-state).
@ ----------------------------------------------------------------------------
ViridianHideout_B2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_K_GRUNT_M_10, ViridianHideout_B2F_Text_Grunt1Seen, ViridianHideout_B2F_Text_Grunt1Beaten, ViridianHideout_B2F_EventScript_DefeatedGrunt1
	msgbox ViridianHideout_B2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

ViridianHideout_B2F_EventScript_DefeatedGrunt1::
	call_if_defeated TRAINER_K_SCIENTIST_2, ViridianHideout_B2F_EventScript_OpenBarrier
	msgbox ViridianHideout_B2F_Text_Grunt1PostBattle
	release
	end

ViridianHideout_B2F_EventScript_Scientist2::
	trainerbattle_single TRAINER_K_SCIENTIST_2, ViridianHideout_B2F_Text_Scientist2Seen, ViridianHideout_B2F_Text_Scientist2Beaten, ViridianHideout_B2F_EventScript_DefeatedScientist2
	msgbox ViridianHideout_B2F_Text_Scientist2PostBattle, MSGBOX_AUTOCLOSE
	end

ViridianHideout_B2F_EventScript_DefeatedScientist2::
	call_if_defeated TRAINER_K_GRUNT_M_10, ViridianHideout_B2F_EventScript_OpenBarrier
	msgbox ViridianHideout_B2F_Text_Scientist2PostBattle
	release
	end

ViridianHideout_B2F_EventScript_OpenBarrier::
	setflag FLAG_TRINITY_K_VBASEMENT_B2F_DOOR
	call ViridianHideout_B2F_EventScript_RemoveBarrier
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	return

@ The rig-minder, inside the sanctum -- an ordinary raid post, reachable only
@ once the barrier is open (no narrative gate of its own).
ViridianHideout_B2F_EventScript_Scientist3::
	trainerbattle_single TRAINER_K_SCIENTIST_3, ViridianHideout_B2F_Text_Scientist3Seen, ViridianHideout_B2F_Text_Scientist3Beaten
	msgbox ViridianHideout_B2F_Text_Scientist3PostBattle, MSGBOX_AUTOCLOSE
	end

@ ----------------------------------------------------------------------------
@ MEWTWO, idle (pre-scene talk). No battle, no C change needed -- this is a
@ flavour-only interaction; the real event fires from Giovanni's own script.
@ ----------------------------------------------------------------------------
ViridianHideout_B2F_EventScript_MewtwoIdle::
	lock
	playmoncry SPECIES_MEWTWO, CRY_MODE_NORMAL
	waitmoncry
	msgbox ViridianHideout_B2F_Text_MewtwoIdle, MSGBOX_DEFAULT
	release
	end

@ MEW never actually reachable (permanently flagged hidden pre-scene, R1) --
@ a defensive, self-contained stub, not Common_EventScript_NopReturn (that
@ helper is written to be `call`ed mid-script, ending in `return`; an
@ object's OWN top-level interaction script needs `end`, not `return`).
ViridianHideout_B2F_EventScript_MewIdle::
	end

@ ----------------------------------------------------------------------------
@ THE RIG SCENE. Talk-triggered (B2's own "single provable tile" pin,
@ satisfied by Giovanni's fixed talk tile rather than an environmental
@ coord_event/ON_FRAME arm -- the same idiom as Blue's/Silver's own
@ confrontations, S5). No VAR_TEMP arm/disarm pair is needed: there is no
@ automatic trigger to mis-fire.
@ ----------------------------------------------------------------------------
ViridianHideout_B2F_EventScript_Giovanni::
	lock
	faceplayer
	msgbox ViridianHideout_B2F_Text_GiovanniConfront1, MSGBOX_DEFAULT
	msgbox ViridianHideout_B2F_Text_GiovanniConfront2, MSGBOX_DEFAULT
	closemessage
	lockall
	playmoncry SPECIES_MEWTWO, CRY_MODE_NORMAL
	waitmoncry
	msgbox ViridianHideout_B2F_Text_GiovanniPressRig, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	addobject LOCALID_KANTO_VBASEMENT_MEW
	fadescreen FADE_FROM_BLACK
	playmoncry SPECIES_MEW, CRY_MODE_NORMAL
	waitmoncry
	msgbox ViridianHideout_B2F_Text_MewMaterializes, MSGBOX_DEFAULT
	closemessage
	playse SE_ICE_CRACK
	playmoncry SPECIES_MEWTWO, CRY_MODE_NORMAL
	waitmoncry
	msgbox ViridianHideout_B2F_Text_RigFails, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_KANTO_VBASEMENT_MEWTWO, ViridianHideout_B2F_Movement_MewtwoFlees
	waitmovement 0
	playse SE_WARP_OUT
	waitse
	removeobject LOCALID_KANTO_VBASEMENT_MEWTWO
	applymovement LOCALID_KANTO_VBASEMENT_MEW, ViridianHideout_B2F_Movement_MewFlees
	waitmovement 0
	playse SE_WARP_OUT
	waitse
	removeobject LOCALID_KANTO_VBASEMENT_MEW
	setflag FLAG_TRINITY_K_RIG_RESOLVED
	msgbox ViridianHideout_B2F_Text_GiovanniAftermath, MSGBOX_DEFAULT
	closemessage
	goto_if_ge VAR_TRINITY_KANTO_ARC, 4, ViridianHideout_B2F_EventScript_GiovanniRetreat
	setvar VAR_TRINITY_KANTO_ARC, 4

@ R1 co-sign: removeobject's own engine implementation
@ (RemoveObjectEventByLocalIdAndMap, src/event_object_movement.c) calls
@ FlagSet() on the object's OWN configured map.json "flag" field as part of
@ removing it -- traced directly this round (a momentary self-caught doubt:
@ an explicit setflag was added here first, then found redundant once the
@ engine call was read, and removed again) -- so
@ FLAG_TRINITY_K_GIOVANNI_BASEMENT_HIDE is durably set by this removeobject
@ alone, no separate setflag or ON_TRANSITION entry needed. Matches Blue's
@ own shape (ViridianCity_EventScript_BlueDepart) exactly.
ViridianHideout_B2F_EventScript_GiovanniRetreat::
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_KANTO_VBASEMENT_GIOVANNI
	fadescreen FADE_FROM_BLACK
	releaseall
	end

@ ----------------------------------------------------------------------------
@ The way back up.
@ ----------------------------------------------------------------------------
@ FIX ROUND 1 (review Minor 8): lockall/releaseall wrapping added, matching
@ CeladonCity_GameCorner_EventScript_Poster:48-58's own precedent.
ViridianHideout_B2F_EventScript_AscendToB1F::
	lockall
	msgbox ViridianHideout_B2F_Text_AscendToB1F, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianHideout_B2F_EventScript_AscendDecline
	closemessage
	warp MAP_VIRIDIAN_HIDEOUT_B1F, 17, 3
	waitstate
	end

ViridianHideout_B2F_EventScript_AscendDecline::
	closemessage
	releaseall
	end

@ FIX ROUND 1 (review M1): the documented M4b R4-deviation shape
@ (TinTower1F/scripts.inc:149-158, Raikou/Entei's own withdrawal --
@ applymovement flee / waitmovement / playse SE_WARP_OUT / waitse /
@ removeobject), applied to BOTH legendaries. The original draft dropped the
@ movement and the waitse; this restores the full documented shape, matching
@ what the sub-plan claimed but the shipped script didn't do. Both paths
@ decoded fresh, dry floor the whole way: MEWTWO flees west along row 5,
@ (20,5)->(19,5)->(18,5), all col=0 elev=3 MB_NORMAL; MEW flees south,
@ (21,5)->(21,6)->(21,7), same.
ViridianHideout_B2F_Movement_MewtwoFlees:
	walk_fast_left
	walk_fast_left
	step_end

ViridianHideout_B2F_Movement_MewFlees:
	walk_fast_down
	walk_fast_down
	step_end

ViridianHideout_B2F_Text_Grunt1Seen:
	.string "This door doesn't open till\nyou've beaten both of us.$"

ViridianHideout_B2F_Text_Grunt1Beaten:
	.string "Ngh! One of us isn't enough to\nhold this door, huh.$"

ViridianHideout_B2F_Text_Grunt1PostBattle:
	.string "Go find my partner, then. Won't\nmatter till you've beaten us both.$"

ViridianHideout_B2F_Text_Scientist2Seen:
	.string "Two of us on this door. You'll\nneed to beat us both.$"

ViridianHideout_B2F_Text_Scientist2Beaten:
	.string "Argh! That's... both of us,\nthen. Door's yours.$"

ViridianHideout_B2F_Text_Scientist2PostBattle:
	.string "Go on. Nothing left to stop\nyou here.$"

ViridianHideout_B2F_Text_Scientist3Seen:
	.string "You're not cleared for this\nlevel. Especially not near IT.$"

ViridianHideout_B2F_Text_Scientist3Beaten:
	.string "Just don't get close to the\nrig! You don't know what it--$"

ViridianHideout_B2F_Text_Scientist3PostBattle:
	.string "...does. Fine. See for yourself.$"

ViridianHideout_B2F_Text_MewtwoIdle:
	.string "Restrained in the rig, MEWTWO's\neyes track your every step.$"

ViridianHideout_B2F_Text_GiovanniConfront1:
	.string "So you're the one who's been\ntearing through my operation.\pViridian, Celadon -- all of it,\nfor a name on a warehouse desk.$"

ViridianHideout_B2F_Text_GiovanniConfront2:
	.string "Fine. You want to see what all\nthis was for? Look.\pThe MANSION on CINNABAR bred\nit and lost their nerve. I don't\lhave that problem.$"

ViridianHideout_B2F_Text_GiovanniPressRig:
	.string "GIOVANNI presses a switch on the\nrig's control panel.\pMEWTWO thrashes against the\nrestraints, snarling.$"

ViridianHideout_B2F_Text_MewMaterializes:
	.string "The air ripples. A small,\npink shape blinks into being\labove the rig.\pIt's MEW -- drawn here, somehow,\nby its offspring's pain.$"

ViridianHideout_B2F_Text_RigFails:
	.string "MEW's presence surges through\nthe machine. Sparks fly from the\lcontrol panel -- the restraints\lfail all at once.\pMEWTWO tears free. In an instant,\nboth POKéMON are gone.$"

ViridianHideout_B2F_Text_GiovanniAftermath:
	.string "...Gone. Both of them, gone.\pYears of work, undone in a\nmoment, because of you.\pThis floor's finished. But don't\nmistake that for the gym being\lyours. I'll be waiting upstairs.$"

ViridianHideout_B2F_Text_AscendToB1F:
	.string "The passage climbs back up\ntoward the outer floor.\pGo up?$"
