OlivineLighthouse6F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineLighthouse6F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, OlivineLighthouse6F_SetHoleWarp
	.byte 0

@ Trinity M4a Task 7 fix: GSC pit-fall (ruling R3). Same PIT-as-staircase
@ situation as 2F (see that file's comment). Same-xy verified exact: 6F's
@ (16,5)/(17,5) match 5F's own warp_events #6/#7 coordinates precisely.
OlivineLighthouse6F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_OLIVINE_LIGHTHOUSE_5F
	end

@ ============================================================================
@ Trinity M4b S6 -- THE GLITTER LIGHTHOUSE, the lantern room. AMPHY is sick and
@ JASMINE will not leave it.
@
@ ON_TRANSITION is the SINGLE AUTHORITY for FLAG_TRINITY_J_JASMINE_LIGHTHOUSE_HIDE:
@   JASMINE is visible iff NOT FLAG_TRINITY_J_AMPHY_CURED.
@ OlivineGym's own ON_TRANSITION carries the exact complement for
@ FLAG_TRINITY_J_JASMINE_GYM_HIDE (visible iff SET), so the two halves of one
@ character are driven by one boolean with one writer -- the delivery beat below
@ -- and there is no state in which she is in both places or neither. This is
@ S5's MORTY tower/gym split with a flag instead of a scene var, because the
@ SECRET POTION errand is a flag chain rather than a cutscene sequence.
@
@ THE SLOT WAS ALREADY OCCUPIED. This map's ON_TRANSITION pointed straight at
@ CaveHole_FixCrackedGround (data/scripts/cave_hole.inc:5), and the slot is
@ SINGLE-OCCUPANCY -- MapHeaderGetScriptTable returns on the FIRST entry matching
@ the tag (src/script.c:302-321), so adding a second map_script line would have
@ been silent dead code (S4 pin I3(a)). The entry is therefore replaced by the
@ script below, which tails into the vanilla one with `goto` (not `call`:
@ CaveHole_FixCrackedGround ends with `end`, not `return`). Same resolution S5
@ used on BurnedTower1F.
@
@ DECODES. JASMINE (8,8) and AMPHY (9,8) are GSC's own tiles; both decode
@ MB_NORMAL, collision 0, elevation 3. Row 8 is the floor's full-width corridor
@ (x=2..17) but it is NOT the only link between the halves -- row 7 is open at
@ x=6..10 and row 9 at x=8..17 -- so the pair costs two tiles and no
@ connectivity (reach_check: 149/152 with both placed, the third loss being the
@ pre-existing item ball at (3,4)).
@ HAZARD CHECK (S5's rule about staging onto an armed hole): this floor runs
@ STEP_CB_CRACKED_FLOOR, and a full-map scan finds exactly TWO
@ MB_CRACKED_FLOOR_HOLE tiles, (16,5) and (17,5) -- the pit-staircases down to
@ 5F, eight columns east of the beat. No tile this scene touches is a hole, and
@ the player is never moved anyway.
@ ============================================================================
OlivineLighthouse6F_OnTransition:
	call OlivineLighthouse6F_EventScript_SetJasmineVisibility
	goto CaveHole_FixCrackedGround

OlivineLighthouse6F_EventScript_SetJasmineVisibility::
	goto_if_set FLAG_TRINITY_J_AMPHY_CURED, OlivineLighthouse6F_EventScript_HideJasmine
	clearflag FLAG_TRINITY_J_JASMINE_LIGHTHOUSE_HIDE
	return

OlivineLighthouse6F_EventScript_HideJasmine::
	setflag FLAG_TRINITY_J_JASMINE_LIGHTHOUSE_HIDE
	return

@ ============================================================================
@ JASMINE -- adapts pokecrystal OlivineLighthouseJasmine
@ (maps/OlivineLighthouse6F.asm).
@
@ GUARD ORDER IS MOST-ADVANCED-FIRST, so each later branch's precondition is
@ implicit: cured -> potion in hand -> already asked -> first meeting.
@
@ ITEM_SECRET_POTION DOES NOT EXIST IN THIS BUILD (verified: no reference
@ anywhere in include/, src/ or data/), so the key item is carried as
@ FLAG_TRINITY_J_SECRET_POTION -- exactly how S1 carried MR. POKéMON's request
@ when ITEM_RED_SCALE turned out to be absent. checkitem becomes goto_if_set and
@ takeitem becomes clearflag. Because the potion flag is CLEARED on delivery, it
@ is not the durable record of anything: FLAG_TRINITY_J_AMPHY_CURED is.
@ ============================================================================
OlivineLighthouse6F_EventScript_Jasmine::
	lock
	faceplayer
	@ INTENTIONALLY UNREACHABLE / DEFENSIVE. FLAG_TRINITY_J_AMPHY_CURED is set in
	@ exactly one place (the delivery beat below), which removeobject's JASMINE in
	@ the same breath, and ON_TRANSITION hides her on every later load. So no walk
	@ reaches this object with the flag set. Written anyway, per S1: a visibility
	@ invariant is not a substitute for a state check.
	goto_if_set FLAG_TRINITY_J_AMPHY_CURED, OlivineLighthouse6F_EventScript_JasmineIdle
	goto_if_set FLAG_TRINITY_J_SECRET_POTION, OlivineLighthouse6F_EventScript_JasmineDeliver
	goto_if_set FLAG_TRINITY_J_JASMINE_ASKED, OlivineLighthouse6F_EventScript_JasmineRepeat
	msgbox OlivineLighthouse6F_Text_JasmineAmphySick, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_J_JASMINE_ASKED
	msgbox OlivineLighthouse6F_Text_JasmineAskMedicine, MSGBOX_DEFAULT
	release
	end

OlivineLighthouse6F_EventScript_JasmineRepeat::
	msgbox OlivineLighthouse6F_Text_JasmineAskMedicine, MSGBOX_DEFAULT
	release
	end

OlivineLighthouse6F_EventScript_JasmineIdle::
	msgbox OlivineLighthouse6F_Text_JasmineThankYou, MSGBOX_DEFAULT
	release
	end

@ ----------------------------------------------------------------------------
@ THE CURE. Two deliberate departures from GSC, both for the same reason:
@
@ 1. GSC branches on VAR_FACING and walks JASMINE off the roof by one of three
@    routes. Her tile is pinned but the PLAYER'S IS NOT -- they may be standing
@    on (8,9), (9,9), (7,8), (8,7) or (9,7) -- and S4's pin is explicit that a
@    scripted walk into a tile you have not pinned is the failure mode. Under a
@    gate with no play-tests, three untested paths is not a trade worth making,
@    so her exit uses R4's fadescreen sandwich, which cannot collide with
@    anything.
@ 2. GSC's `special PlaySlowCry` becomes playmoncry ... CRY_MODE_WEAK
@    (include/constants/sound.h:34, "used when a POKéMON is unhealthy") and the
@    recovery cry is CRY_MODE_NORMAL. Same distinction, existing engine feature.
@
@ lock + applymovement <other local id> is vanilla-safe: ScriptMovement_TryAddNewMovement
@ drives the target through its own task and unfreezes it
@ (src/script_movement.c:22-31, 236-248); precedent RustboroCity_EventScript_LittleBoy.
@ Neither AMPHY nor JASMINE ever leaves its tile here -- every movement is a turn
@ in place -- so no choreography tile needs decoding beyond the two they stand on.
@ ----------------------------------------------------------------------------
OlivineLighthouse6F_EventScript_JasmineDeliver::
	msgbox OlivineLighthouse6F_Text_JasmineWillThatCure, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OlivineLighthouse6F_EventScript_JasmineRefused
	msgbox OlivineLighthouse6F_Text_HandedOverPotion, MSGBOX_DEFAULT
	clearflag FLAG_TRINITY_J_SECRET_POTION
	msgbox OlivineLighthouse6F_Text_JasmineDontBeOffended, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JOHTO_LH6F_JASMINE, Common_Movement_FaceRight
	waitmovement 0
	delay 15
	applymovement LOCALID_JOHTO_LH6F_AMPHY, Common_Movement_FaceLeft
	waitmovement 0
	msgbox OlivineLighthouse6F_Text_JasmineHowAreYouFeeling, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_AMPHAROS, CRY_MODE_WEAK
	waitmoncry
	delay 30
	fadescreen FADE_TO_WHITE
	delay 20
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	waitmoncry
	msgbox OlivineLighthouse6F_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JOHTO_LH6F_AMPHY, OlivineLighthouse6F_Movement_AmphyShakesItself
	waitmovement 0
	applymovement LOCALID_JOHTO_LH6F_JASMINE, Common_Movement_FaceDown
	waitmovement 0
	msgbox OlivineLighthouse6F_Text_JasmineThankYou, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_TRINITY_J_AMPHY_CURED
	@ R4. The removeobject also co-signs FLAG_TRINITY_J_JASMINE_LIGHTHOUSE_HIDE
	@ (RemoveObjectEventByLocalIdAndMap -> FlagSet, src/event_object_movement.c:1537-1545)
	@ and that is INTENDED -- it is what makes her exit stick for the rest of the
	@ session, before the next map load re-derives the flag from AMPHY_CURED. She
	@ owns that flag alone, so the co-sign cannot reach AMPHY (whose object flag
	@ is 0 -- GSC's own SPRITE_MONSTER carries -1 and never leaves the room).
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_JOHTO_LH6F_JASMINE
	fadescreen FADE_FROM_BLACK
	release
	end

OlivineLighthouse6F_EventScript_JasmineRefused::
	msgbox OlivineLighthouse6F_Text_JasmineISee, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JOHTO_LH6F_JASMINE, Common_Movement_FaceRight
	waitmovement 0
	delay 15
	applymovement LOCALID_JOHTO_LH6F_AMPHY, Common_Movement_FaceLeft
	waitmovement 0
	msgbox OlivineLighthouse6F_Text_JasmineHangOn, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ AMPHY. Always on stage (object flag 0 -- GSC gives SPRITE_MONSTER flag -1) and
@ it never retires, which is exactly why it is NOT on JASMINE's flag: a shared
@ cast flag is only correct while every member retires together, and here
@ precisely one of the two leaves (S4's C1 lesson, the small version).
@ ============================================================================
OlivineLighthouse6F_EventScript_Amphy::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_AMPHY_CURED, OlivineLighthouse6F_EventScript_AmphyWell
	msgbox OlivineLighthouse6F_Text_AmphyPalPaloo, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_AMPHAROS, CRY_MODE_WEAK
	waitmoncry
	msgbox OlivineLighthouse6F_Text_AmphyBreathingLabored, MSGBOX_DEFAULT
	release
	end

OlivineLighthouse6F_EventScript_AmphyWell::
	msgbox OlivineLighthouse6F_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	waitmoncry
	release
	end

@ Four turns in place at (9,8) -- GSC's own "AMPHY shakes itself" beat. No tile
@ is entered, so nothing here needs a walkability decode.
OlivineLighthouse6F_Movement_AmphyShakesItself:
	face_right
	delay_8
	face_left
	delay_8
	face_right
	delay_8
	face_down
	step_end

@ ============================================================================
@ Text -- adapts pokecrystal's JasmineCianwoodPharmacyText, JasmineGetSome-
@ MedicineText, JasmineCureAmphyText, PlayerHandedSecretpotionText, Jasmine-
@ DontBeOffendedText, JasmineAmphyHowAreYouFeelingText, JasmineThankYouText,
@ JasmineISeeText, JasmineAmphyHangOnText, AmphyPalPalooText,
@ AmphyBreathingLaboredText and AmphyPaluPaluluText.
@ ============================================================================
OlivineLighthouse6F_Text_JasmineAmphySick:
	.string "JASMINE: … This POKéMON kept the\n"
	.string "sea lit every night of its life.\p"
	.string "Then it just… stopped. It is\n"
	.string "gasping, and I cannot make it stop.\p"
	.string "They say there is a PHARMACY in\n"
	.string "CIANWOOD that can make anything.\p"
	.string "But CIANWOOD is across the water,\n"
	.string "and I will not leave AMPHY alone.$"

OlivineLighthouse6F_Text_JasmineAskMedicine:
	.string "JASMINE: … You crossed a sea to\n"
	.string "get to JOHTO at all, didn't you.\p"
	.string "Then may I ask you to cross one\n"
	.string "more? Please. Ask the PHARMACIST in\l"
	.string "CIANWOOD for the SECRETPOTION.$"

OlivineLighthouse6F_Text_JasmineWillThatCure:
	.string "JASMINE: …Is that the SECRETPOTION?\p"
	.string "Will it cure AMPHY?$"

OlivineLighthouse6F_Text_HandedOverPotion:
	.string "{PLAYER} handed the SECRETPOTION to\n"
	.string "JASMINE.$"

OlivineLighthouse6F_Text_JasmineDontBeOffended:
	.string "JASMINE: …Um. Please don't be\n"
	.string "offended.\p"
	.string "AMPHY will not take anything from\n"
	.string "anyone but me.$"

OlivineLighthouse6F_Text_JasmineHowAreYouFeeling:
	.string "JASMINE: …\p"
	.string "AMPHY. How are you feeling?$"

OlivineLighthouse6F_Text_AmphyPaluPalulu:
	.string "AMPHY: Palu! Palulu!$"

OlivineLighthouse6F_Text_JasmineThankYou:
	.string "JASMINE: …Oh. Oh, I'm so relieved.\p"
	.string "Look at it. The whole coast can see\n"
	.string "that light again tonight.\p"
	.string "Thank you. Very, very much.\p"
	.string "…I will go back down to the GYM\n"
	.string "now. Come and find me there.\p"
	.string "I owe you a proper battle.$"

OlivineLighthouse6F_Text_JasmineISee:
	.string "JASMINE: …I see. …I'm sorry.$"

OlivineLighthouse6F_Text_JasmineHangOn:
	.string "JASMINE: …AMPHY. Hang on.$"

OlivineLighthouse6F_Text_AmphyPalPaloo:
	.string "AMPHY: …\n"
	.string "…Pa… paloo…$"

OlivineLighthouse6F_Text_AmphyBreathingLabored:
	.string "Its breathing is terribly labored.\p"
	.string "The great lantern above it is dark.$"
