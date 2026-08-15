BurnedTowerB1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BurnedTowerB1F_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S5 -- THE BURNED TOWER, B1F. The awakening.
@
@ ON_TRANSITION is the SINGLE AUTHORITY for FLAG_TRINITY_J_BEASTS_HIDE:
@   the three beasts are visible iff VAR_TRINITY_JOHTO_SCENE_ECRUTEAK == 1.
@
@ WHY EXACT EQUALITY, AND WHY NOT "VISIBLE UNTIL THE EVENT". In GSC the
@ basement cannot be entered at all before the rival battle opens the hole
@ (BurnedTower1FHoleAndLadderCallback covers the ladder until
@ EVENT_RELEASED_THE_BEASTS). This build has no changeblock: M4a baked BOTH
@ links in permanently -- the hole metatile at 1F (10,9) and the two-way ladder
@ at (7,15) on both floors -- so a player can walk down here before ever meeting
@ SILVER. Three legendaries standing in a room with no trigger attached to them
@ is worse than an empty basement, so the cast spawns only inside the armed
@ window. GSC's own sages say it for us: the beasts "can't be seen while they
@ sleep" (WiseTriosRoom.asm, SageGakuAfterBattleText).
@ Exact equality also matches S3's raid-window idiom: the window has exactly one
@ opener (the SILVER 3 aftermath) and one closer (the scene below), both S5's.
@ ============================================================================
BurnedTowerB1F_OnTransition:
	call BurnedTowerB1F_EventScript_SetBeastVisibility
	end

BurnedTowerB1F_EventScript_SetBeastVisibility::
	goto_if_eq VAR_TRINITY_JOHTO_SCENE_ECRUTEAK, 1, BurnedTowerB1F_EventScript_ShowBeasts
	setflag FLAG_TRINITY_J_BEASTS_HIDE
	return

BurnedTowerB1F_EventScript_ShowBeasts::
	clearflag FLAG_TRINITY_J_BEASTS_HIDE
	return

@ ============================================================================
@ RELEASE THE BEASTS -- adapts pokecrystal ReleaseTheBeasts
@ (BurnedTowerB1F.asm:27-115).
@
@ THE BEAST-CUTSCENE SHAPE (B1-B5). S10 reuses this for SUICUNE's TIN TOWER
@ showdown, so the clauses are written out here:
@
@ B1  One OBJ_EVENT_GFX_SPECIES(...) object per legendary, all on ONE _HIDE
@     flag, window authored by ON_TRANSITION off a scene var with EXACT
@     equality. A shared cast flag is only correct while every member retires
@     together (S4's C1 lesson); these three do, permanently, so it is.
@     GSC needs SIX objects here -- a sleeping trio and a waking trio swapped
@     one-for-one -- because GS/C needed a different SPRITEMOVEDATA and palette
@     per state. OBJ_EVENT_GFX_SPECIES has no such split, so Trinity ships three
@     objects carrying both states.
@
@ B2  The trigger sits on the chamber's UNIQUE approach tile, flood-fill
@     verified, and the camera window is checked once against every tile the
@     choreography touches.
@     DECODE: the beast chamber is x=7..12, y=2..6, and its only exit is (10,7)
@     -- row 7 decodes collision 1 at x=7..9 and x=11..13. So (10,6) is the one
@     tile every approach must cross, and it is GSC's own trigger tile. The fall
@     out of the SILVER 3 scene lands at (10,9), two tiles below (10,7).
@     CAMERA: player locked at (10,6) => rows 2..11, columns 3..17. RAIKOU
@     (7,3), ENTEI (12,3), SUICUNE (10,4) and every step below are inside it.
@
@ B3  Wake beat = emote -> playmoncry -> delay, one beast at a time.
@     Flee beat = applymovement on REAL FLOOR -> playse SE_WARP_OUT ->
@     removeobject. GSC slides its beasts through walls with set_sliding;
@     Trinity does not need to, and keeping every step on decoded collision-0
@     floor means nothing here depends on how scripted movement treats
@     collision. (7,4)/(7,5)/(12,4)/(12,5)/(10,5)/(10,3)/(10,2) are all inside
@     the 6x5 chamber.
@     The removals deliberately do NOT use R4's fadescreen sandwich. R4 exists
@     so an appearance or disappearance never POPS; here the disappearance is
@     diegetic -- the beasts blur away -- and GSC covers it with exactly this
@     sound (playsound SFX_WARP_FROM / disappear). Fading to black three times
@     inside a cutscene would destroy the beat R4 is protecting.
@     R1's co-sign is INTENDED: each removeobject FlagSet's the shared
@     FLAG_TRINITY_J_BEASTS_HIDE (RemoveObjectEventByLocalIdAndMap ->
@     GetObjectEventFlagIdByObjectEventId, src/event_object_movement.c:1537-1545),
@     all three share it, and all three leave.
@
@ B4  The player is NEVER moved during a legendary cutscene -- only faced. Every
@     hazard tile in these maps (cracked floors, ladders, the gym's pit cells)
@     is one step away from everything.
@
@ B5  The scene's ONLY durable outputs are one story flag and one monotonic
@     scene-var advance. No roamers, no InitRoamMons analogue, no lair unlocks:
@     the awakening sets a story flag, NOT encounters. S10 owns the lairs.
@ ============================================================================
BurnedTowerB1F_EventScript_ReleaseTheBeasts::
	lockall
	applymovement LOCALID_PLAYER, BurnedTowerB1F_Movement_PlayerFaceNorth
	waitmovement 0
	fadeoutbgm 4
	delay 40
	msgbox BurnedTowerB1F_Text_SomethingStirs, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_JOHTO_BTB1_RAIKOU, Common_Movement_ExclamationMark
	waitmovement 0
	playmoncry SPECIES_RAIKOU, CRY_MODE_NORMAL
	waitmoncry
	delay 15
	applymovement LOCALID_JOHTO_BTB1_ENTEI, Common_Movement_ExclamationMark
	waitmovement 0
	playmoncry SPECIES_ENTEI, CRY_MODE_NORMAL
	waitmoncry
	delay 15
	applymovement LOCALID_JOHTO_BTB1_SUICUNE, Common_Movement_ExclamationMark
	waitmovement 0
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	waitmoncry
	delay 30

	@ RAIKOU bolts. (7,3) -> (7,5).
	applymovement LOCALID_JOHTO_BTB1_RAIKOU, BurnedTowerB1F_Movement_RaikouFlees
	waitmovement 0
	playse SE_WARP_OUT
	waitse
	removeobject LOCALID_JOHTO_BTB1_RAIKOU

	@ ENTEI bolts. (12,3) -> (12,5).
	applymovement LOCALID_JOHTO_BTB1_ENTEI, BurnedTowerB1F_Movement_EnteiFlees
	waitmovement 0
	playse SE_WARP_OUT
	waitse
	removeobject LOCALID_JOHTO_BTB1_ENTEI
	delay 20

	@ SUICUNE -- GLIMPSE 1. It comes one tile CLOSER instead of running, stops
	@ dead in front of the player at (10,5), and looks at them. GSC's
	@ BurnedTowerSuicuneMovement1/2 does the same thing with four times the
	@ footwork; the pause and the second cry are the whole point of the beat.
	applymovement LOCALID_JOHTO_BTB1_SUICUNE, BurnedTowerB1F_Movement_SuicuneSteps
	waitmovement 0
	delay 40
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	waitmoncry
	delay 40
	msgbox BurnedTowerB1F_Text_SuicuneLooksAtYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JOHTO_BTB1_SUICUNE, BurnedTowerB1F_Movement_SuicuneFlees
	waitmovement 0
	playse SE_WARP_OUT
	waitse
	removeobject LOCALID_JOHTO_BTB1_SUICUNE

	setflag FLAG_TRINITY_J_BEASTS_AWAKENED
	setvar VAR_TRINITY_JOHTO_SCENE_ECRUTEAK, 2
	delay 30
	fadedefaultbgm
	msgbox BurnedTowerB1F_Text_TheyAreGone, MSGBOX_DEFAULT
	releaseall
	end

@ Talk script for the sleeping cast. GSC attaches `ObjectEvent` (nothing at all);
@ a line costs no state and stops a legendary from reading as scenery.
@ No faceplayer: they are asleep.
BurnedTowerB1F_EventScript_SleepingBeast::
	lock
	msgbox BurnedTowerB1F_Text_SleepingBeast, MSGBOX_DEFAULT
	release
	end

BurnedTowerB1F_Movement_PlayerFaceNorth:
	face_up
	step_end

@ (7,3) -> (7,5), then turns west. Both steps decode collision 0 elevation 3.
BurnedTowerB1F_Movement_RaikouFlees:
	walk_fast_down
	walk_fast_down
	face_left
	step_end

@ (12,3) -> (12,5), then turns east.
BurnedTowerB1F_Movement_EnteiFlees:
	walk_fast_down
	walk_fast_down
	face_right
	step_end

@ (10,4) -> (10,5): one step toward the player, facing them.
BurnedTowerB1F_Movement_SuicuneSteps:
	walk_down
	face_down
	step_end

@ (10,5) -> (10,2): three tiles back up the chamber, all collision 0.
BurnedTowerB1F_Movement_SuicuneFlees:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

@ ============================================================================
@ Text
@ ============================================================================
BurnedTowerB1F_Text_SomethingStirs:
	.string "The air under the tower went\n"
	.string "completely still.\p"
	.string "Three shapes lay in the ash, and\n"
	.string "not one of them was breathing.$"

BurnedTowerB1F_Text_SleepingBeast:
	.string "It has not moved in a hundred and\n"
	.string "fifty years.\p"
	.string "It is not cold.$"

@ SUICUNE GLIMPSE 1. GSC gives this beat no words at all -- it is pure
@ choreography plus a second cry. Trinity keeps the choreography and adds one
@ line, because the WISE TRIO will later claim the legendary POKéMON test
@ chosen humans by letting them get close, and this is the moment that claim
@ has to be about.
BurnedTowerB1F_Text_SuicuneLooksAtYou:
	.string "The blue one did not run.\p"
	.string "It crossed the floor, stopped an\n"
	.string "arm's length away, and looked at\l"
	.string "{PLAYER} the way a judge looks at\l"
	.string "someone still on trial.$"

BurnedTowerB1F_Text_TheyAreGone:
	.string "They were gone.\p"
	.string "Ash settled where they had lain,\n"
	.string "and the burned tower was only a\l"
	.string "burned tower again.$"
