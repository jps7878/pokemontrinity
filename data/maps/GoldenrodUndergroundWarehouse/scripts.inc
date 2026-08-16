GoldenrodUndergroundWarehouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodUndergroundWarehouse_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S8 -- THE UNDERGROUND WAREHOUSE. Adapts pokecrystal
@ maps/GoldenrodUndergroundWarehouse.asm.
@
@ Three R2 posts and the real DIRECTOR, all on GSC's own tiles (:224-227), all
@ decoded collision 0 / elevation 3 / MB_NORMAL:
@     (9,8) mt561 facing UP    sight 3
@     (8,15) mt566 facing UP   sight 3
@     (14,3) mt566 facing RIGHT sight 4
@     (12,8) mt564  the DIRECTOR, LOOK_AROUND
@ The DIRECTOR's tile is not a cut vertex: (11,8) and (12,7) decode collision 1,
@ so (12,8) hangs off (13,8) and (12,9) and losing it costs exactly one tile.
@
@ The three posts share FLAG_TRINITY_J_UNDERGROUND_ROCKETS_HIDE with the SWITCH
@ ROOMS' four -- one predicate, authored once per map, and NOTHING on it is ever
@ removeobject'd, because a co-sign would delete four posts on another map
@ (R1's trap in S7's cross-map form). The DIRECTOR has his own flag: he does not
@ retire with the Rockets, he moves to the RADIO TOWER's 5F office, where he is
@ a DIFFERENT object (RadioTower5F (3,6), flag 0) playing the same man.
@
@ DELIBERATE SKIP: GSC's MAPCALLBACK_NEWMAP switch/door reset (:16-34). See the
@ SWITCH ROOMS header -- our door state is flags, so a solved maze stays solved.
@ ============================================================================
GoldenrodUndergroundWarehouse_OnTransition:
	call GoldenrodUndergroundWarehouse_EventScript_SetRocketVisibility
	call GoldenrodUndergroundWarehouse_EventScript_SetDirectorVisibility
	end

GoldenrodUndergroundWarehouse_EventScript_SetRocketVisibility::
	goto_if_ne VAR_TRINITY_JOHTO_ARC, 6, GoldenrodUndergroundWarehouse_EventScript_HideRockets
	clearflag FLAG_TRINITY_J_UNDERGROUND_ROCKETS_HIDE
	return

GoldenrodUndergroundWarehouse_EventScript_HideRockets::
	setflag FLAG_TRINITY_J_UNDERGROUND_ROCKETS_HIDE
	return

GoldenrodUndergroundWarehouse_EventScript_SetDirectorVisibility::
	goto_if_ne VAR_TRINITY_JOHTO_ARC, 6, GoldenrodUndergroundWarehouse_EventScript_HideDirector
	clearflag FLAG_TRINITY_J_WAREHOUSE_DIRECTOR_HIDE
	return

GoldenrodUndergroundWarehouse_EventScript_HideDirector::
	setflag FLAG_TRINITY_J_WAREHOUSE_DIRECTOR_HIDE
	return

GoldenrodUndergroundWarehouse_EventScript_GruntA::
	trainerbattle_single TRAINER_JOHTO_ROCKET_WH_A, GoldenrodUndergroundWarehouse_Text_GruntASeen, GoldenrodUndergroundWarehouse_Text_GruntABeaten
	msgbox GoldenrodUndergroundWarehouse_Text_GruntAAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodUndergroundWarehouse_EventScript_GruntB::
	trainerbattle_single TRAINER_JOHTO_ROCKET_WH_B, GoldenrodUndergroundWarehouse_Text_GruntBSeen, GoldenrodUndergroundWarehouse_Text_GruntBBeaten
	msgbox GoldenrodUndergroundWarehouse_Text_GruntBAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodUndergroundWarehouse_EventScript_GruntC::
	trainerbattle_single TRAINER_JOHTO_ROCKET_WH_C, GoldenrodUndergroundWarehouse_Text_GruntCSeen, GoldenrodUndergroundWarehouse_Text_GruntCBeaten
	msgbox GoldenrodUndergroundWarehouse_Text_GruntCAfter, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ THE REAL DIRECTOR. The CARD KEY is a FLAG, not an item -- ITEM_CARD_KEY exists
@ in this build but it is KANTO's SILPH CO key and is reserved for M5, and
@ ITEM_BASEMENT_KEY is already Act I's NEW MAUVILLE key. Per S6's three-part
@ rule the beat still reads as a pickup (fanfare + a "received" line), the key
@ is named at every site that refers to it (here, the 3F slot and the imposter),
@ and the already-given path still does something useful.
@
@ There is NO giveitem, so there is no VAR_RESULT == FALSE branch and no G2
@ award guard -- G2 exists for a failable gift and this is not one. The scene
@ advance is guarded monotonically all the same.
@
@ Freeing him also opens the DEPT. STORE B1F crate that turns the WAREHOUSE into
@ a shortcut to the street: GSC keys that changeblock on the same event
@ (GoldenrodDeptStoreB1F.asm:18-25) and so do we, on FLAG_TRINITY_J_CARD_KEY.
@ ============================================================================
GoldenrodUndergroundWarehouse_EventScript_Director::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_CARD_KEY, GoldenrodUndergroundWarehouse_EventScript_DirectorPleading
	msgbox GoldenrodUndergroundWarehouse_Text_DirectorIntro, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox GoldenrodUndergroundWarehouse_Text_ReceivedCardKey, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_J_CARD_KEY
	msgbox GoldenrodUndergroundWarehouse_Text_DirectorCardKey, MSGBOX_DEFAULT
	call GoldenrodUndergroundWarehouse_EventScript_AdvanceToScene3
	msgbox GoldenrodUndergroundWarehouse_Text_DirectorPlea, MSGBOX_DEFAULT
	release
	end

GoldenrodUndergroundWarehouse_EventScript_AdvanceToScene3::
	goto_if_ge VAR_TRINITY_JOHTO_SCENE_GOLDENROD, 3, GoldenrodUndergroundWarehouse_EventScript_Scene3AlreadySet
	setvar VAR_TRINITY_JOHTO_SCENE_GOLDENROD, 3
GoldenrodUndergroundWarehouse_EventScript_Scene3AlreadySet::
	return

GoldenrodUndergroundWarehouse_EventScript_DirectorPleading::
	msgbox GoldenrodUndergroundWarehouse_Text_DirectorPlea, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ Text -- GSC GruntM24/M14/M15 and DirectorIntroText / DirectorCardKeyText /
@ DirectorAfterText.
@ ============================================================================
GoldenrodUndergroundWarehouse_Text_GruntASeen:
	.string "How did you get this far?\p"
	.string "I suppose it can't be helped.\n"
	.string "I'll dispose of you.$"

GoldenrodUndergroundWarehouse_Text_GruntABeaten:
	.string "I got disposed of…$"

GoldenrodUndergroundWarehouse_Text_GruntAAfter:
	.string "TEAM ROCKET will keep going,\n"
	.string "waiting for the return of\l"
	.string "GIOVANNI.\p"
	.string "We'll do whatever it takes.$"

GoldenrodUndergroundWarehouse_Text_GruntBSeen:
	.string "You're not going any farther.\p"
	.string "I don't show mercy to my\n"
	.string "enemies. Not even brats.$"

GoldenrodUndergroundWarehouse_Text_GruntBBeaten:
	.string "Blast it!$"

GoldenrodUndergroundWarehouse_Text_GruntBAfter:
	.string "I lost…\p"
	.string "Please forgive me, GIOVANNI!$"

GoldenrodUndergroundWarehouse_Text_GruntCSeen:
	.string "Hyuck-hyuck-hyuck! I remember\n"
	.string "you!\p"
	.string "You got me good at our hideout!$"

GoldenrodUndergroundWarehouse_Text_GruntCBeaten:
	.string "Hyuck-hyuck-hyuck!\n"
	.string "So that's how it is?$"

GoldenrodUndergroundWarehouse_Text_GruntCAfter:
	.string "Hyuck-hyuck-hyuck! That was a\n"
	.string "blast! I'll remember you!\p"
	.string "Old fella's over there. Untie\n"
	.string "him yourself, I'm not doing it.$"

GoldenrodUndergroundWarehouse_Text_DirectorIntro:
	.string "DIRECTOR: Who? What?\p"
	.string "You came to rescue me?\p"
	.string "Thank you. Thank you.\p"
	.string "The RADIO TOWER -- what's\n"
	.string "happening there? Taken over by\l"
	.string "TEAM ROCKET?\p"
	.string "Then take this. Quickly.$"

GoldenrodUndergroundWarehouse_Text_ReceivedCardKey:
	.string "{PLAYER} received the\n"
	.string "CARD KEY.$"

GoldenrodUndergroundWarehouse_Text_DirectorCardKey:
	.string "DIRECTOR: Use it on the slot on\n"
	.string "3F. It opens the shutters.\p"
	.string "There's a door to the DEPT.\n"
	.string "STORE at the top of this room,\l"
	.string "too. It'll be clear by the time\l"
	.string "you get there -- the staff move\l"
	.string "the crates for anyone with that\l"
	.string "key.$"

GoldenrodUndergroundWarehouse_Text_DirectorPlea:
	.string "DIRECTOR: I'm begging you.\p"
	.string "There's no telling what they'll\n"
	.string "do if they control that\l"
	.string "transmitter.\p"
	.string "They may even be able to reach\n"
	.string "POKéMON with a special signal.\p"
	.string "You're the only one I can call\n"
	.string "on.\p"
	.string "Please. Save the RADIO TOWER --\n"
	.string "and every POKéMON in range of\l"
	.string "it.$"
