@ ============================================================================
@ Trinity M5b S8 -- the Fuchsia Safari Zone entrance booth, wired onto the
@ vanilla Hoenn safari engine (canonical source:
@ Route121_SafariZoneEntrance/scripts.inc). See
@ docs/superpowers/plans/m5b/08-fuchsia-safari.md sections 1/9.
@
@ FIX ROUND (review C1/C2): the first draft's single-trigger, no-return-path
@ shape was a false "Route121 wholesale copy" -- Route121's own single
@ trigger sits on a genuine 1-tile chokepoint (the whole room narrows to it)
@ AND every refusal path routes back through a forced walk-away. Fuchsia's
@ corridor is 3 TILES WIDE at the trigger's row, so a single trigger left
@ two columns free to walk straight past, and bare `releaseall` on decline
@ let a player who triggered-then-declined simply continue forward. Fixed
@ to the FRLG shape the room's own geometry actually matches (pokefirered's
@ own FuchsiaCity_SafariZone_Entrance scripts.inc): three coord-event
@ triggers spanning the corridor's full width at row 3, ALL of them running
@ the fee flow, and a shared ForcePlayerBack every refusal/failure path
@ goes through before releasing control.
@
@ Room decode (9x9, LAYOUT_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE_KANTO): a 3-wide
@ public corridor (cols 3-5) flanked by two MB_COUNTER-walled staff pockets
@ (col 1 west, col 7 east) -- byte-for-byte match to pokefirered's own
@ layout. Every north<->south path through the corridor crosses row 3 at
@ column 3, 4, OR 5 (GBA movement is cardinal-only, one axis per step, so a
@ y=4->y=2 crossing is forced through some y=3 tile) -- three triggers at
@ (3,3)/(4,3)/(5,3) is a genuine full-width chokepoint, not a partial one.
@
@ Deliberate divergence from Route121's literal fee flow: the
@ ITEM_POKEBLOCK_CASE gate is DROPPED. Pokeblocks are a Hoenn-only mechanic
@ with no Kanto/FRLG counterpart (pokefirered's own real entrance script has
@ no such check either) -- copying it wholesale would gate Kanto's safari on
@ an item with no in-region purpose.
@
@ ON_FRAME table, two states (VAR_SAFARI_ZONE_STATE, the shared engine var,
@ extended per data/scripts/safari_zone.inc's own fix -- see that file):
@   state==1  "now exiting" -- a LEGITIMATE exit already ran ExitSafariMode
@             and set state to 1 before warping here (time's up, out of
@             balls, or Start Menu Retire). Walk the player off the door,
@             reset state to 0.
@   state==3  "session still active, but the booth just loaded" -- this can
@             ONLY happen when the player's own real movement re-triggers
@             SafariZone_Center's MB_SOUTH_ARROW_WARP tiles (25/26/27,30 all
@             warp back here, dest_warp_id 0 = this room's own (4,1)) while
@             mid-session (state was never advanced to 1 by an official exit
@             path -- FIX C2). Ask whether they want to leave early; a "no"
@             re-warps them straight back into SafariZone_Center without
@             touching state, so the session stays live exactly as it was.
@ ============================================================================
FuchsiaCity_SafariZone_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_SafariZone_Entrance_OnFrame
	.byte 0

FuchsiaCity_SafariZone_Entrance_OnFrame:
	map_script_2 VAR_SAFARI_ZONE_STATE, 1, FuchsiaCity_SafariZone_Entrance_EventScript_ExitSafariZone
	map_script_2 VAR_SAFARI_ZONE_STATE, 3, FuchsiaCity_SafariZone_Entrance_EventScript_ExitEarly
	.2byte 0

@ ============================================================================
@ FOLDED M2: two walk_down steps (FRLG's own Movement_Exit shape) park the
@ player ON (4,3) -- the middle fee trigger's own tile -- rather than one
@ step short of it. Safe: coord_events fire from TryStartStepBasedScript
@ inside the PLAYER-INPUT step pipeline (src/field_control_avatar.c), never
@ from the scripted object-movement system applymovement uses, so walking
@ through (4,3) here cannot re-trigger the fee prompt. A player who later
@ takes a REAL step off then back onto it gets prompted again, which is the
@ intended, same-as-Route121 behaviour (you can always re-approach the
@ counter).
@ ============================================================================
FuchsiaCity_SafariZone_Entrance_EventScript_ExitSafariZone::
	lockall
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_ExitSafariZone
	waitmovement 0
	setvar VAR_SAFARI_ZONE_STATE, 0
	releaseall
	end

FuchsiaCity_SafariZone_Entrance_Movement_ExitSafariZone:
	walk_down
	walk_down
	step_end

@ ============================================================================
@ FIX C2 -- the mid-session return handler (FRLG's own ExitEarly/
@ ReturnToSafariZone shape, pokefirered scripts.inc:40-61, adapted onto
@ this tree's shared VAR_SAFARI_ZONE_STATE==3 rather than FRLG's own
@ per-map scene var). Disarm discipline traced: the YES branch is the ONLY
@ branch that writes state (0, via the same ExitSafariMode-then-reset order
@ as the legitimate-exit path above); the NO branch writes nothing, so the
@ var is still 3 the next time this map loads mid-session -- correct, the
@ session is still live. Landing tile is IDENTICAL to a legitimate exit's
@ own landing ((4,1), this room's own north warp/door), so the SAME
@ walk-out movement applies to both.
@ ============================================================================
FuchsiaCity_SafariZone_Entrance_EventScript_ExitEarly::
	lockall
	msgbox FuchsiaCity_SafariZone_Entrance_Text_GoingToLeaveEarly, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FuchsiaCity_SafariZone_Entrance_EventScript_ReturnToSafariZone
	msgbox FuchsiaCity_SafariZone_Entrance_Text_ExitEarlyThanks, MSGBOX_DEFAULT
	closemessage
	special ExitSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 0
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_ExitSafariZone
	waitmovement 0
	releaseall
	end

FuchsiaCity_SafariZone_Entrance_EventScript_ReturnToSafariZone::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_GoodLuckReturn, MSGBOX_DEFAULT
	closemessage
	warp MAP_SAFARI_ZONE_CENTER, 26, 30
	waitstate
	end

@ ============================================================================
@ InfoAttendant -- (1,6), T10's own placement, FRLG's own coordinate.
@ Reachable ONLY via MB_COUNTER talk-through from (3,6) facing west (the
@ M4b G4 pin) -- not a cut vertex, the tile was never meant to be walked to.
@ Rewritten from the T10 filler line to the Route121 InfoAttendant's own
@ first-time-visitor YESNO role.
@ ============================================================================
FuchsiaCity_SafariZone_Entrance_EventScript_InfoAttendant::
	lock
	faceplayer
	msgbox FuchsiaCity_SafariZone_Entrance_Text_WelcomeFirstTime, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZone_Entrance_EventScript_FirstTimeInfo
	msgbox FuchsiaCity_SafariZone_Entrance_Text_ComeInAndEnjoy, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZone_Entrance_EventScript_FirstTimeInfo::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_FirstTimeInfo, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ FIX C1 -- the fee counter, now THREE coord-event triggers spanning the
@ corridor's full width at row 3 (VAR_TEMP_1 idiom, step-triggered only --
@ see the header, no disarm needed). Each records which column it fired
@ from in VAR_TEMP_2 (FRLG's own idiom) purely so the post-payment walk-up
@ can re-center on the door column (4) before proceeding north -- (3,y)/
@ (5,y) walking straight up from row 3 would walk into the solid wall at
@ row1 cols 3/5 (only col 4 is the door). FOLDED M3: every trigger snaps
@ the player to face up first (Common_Movement_WalkInPlaceFasterUp, matches
@ Route121 :48) so a player who approached from the north corridor still
@ visually faces the counter for the prompt.
@ ============================================================================
FuchsiaCity_SafariZone_Entrance_EventScript_EntranceCounterTriggerLeft::
	lockall
	setvar VAR_TEMP_2, 0
	goto FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone
	end

FuchsiaCity_SafariZone_Entrance_EventScript_EntranceCounterTriggerMid::
	lockall
	setvar VAR_TEMP_2, 1
	goto FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone
	end

FuchsiaCity_SafariZone_Entrance_EventScript_EntranceCounterTriggerRight::
	lockall
	setvar VAR_TEMP_2, 2
	goto FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone
	end

FuchsiaCity_SafariZone_Entrance_EventScript_AskEnterSafariZone::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZone_Entrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZone_Entrance_EventScript_TryEnterSafariZone
	msgbox FuchsiaCity_SafariZone_Entrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack
	end

FuchsiaCity_SafariZone_Entrance_EventScript_TryEnterSafariZone::
	call FuchsiaCity_SafariZone_Entrance_EventScript_CheckHasRoomForPokemon
	checkmoney 500
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_SafariZone_Entrance_EventScript_NotEnoughMoney
	playse SE_SHOP
	msgbox FuchsiaCity_SafariZone_Entrance_Text_ThatWillBe500Please, MSGBOX_DEFAULT
	removemoney 500
	updatemoneybox
	msgbox FuchsiaCity_SafariZone_Entrance_Text_HereAreYourSafariBalls, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message FuchsiaCity_SafariZone_Entrance_Text_Received30SafariBalls
	waitfanfare
	msgbox FuchsiaCity_SafariZone_Entrance_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	call_if_eq VAR_TEMP_2, 0, FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneLeft
	call_if_eq VAR_TEMP_2, 1, FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneMid
	call_if_eq VAR_TEMP_2, 2, FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneRight
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 3
	warp MAP_SAFARI_ZONE_CENTER, 26, 30
	waitstate
	end

FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneLeft::
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneLeft
	waitmovement 0
	return

FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneMid::
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneMid
	waitmovement 0
	return

FuchsiaCity_SafariZone_Entrance_EventScript_EnterSafariZoneRight::
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneRight
	waitmovement 0
	return

FuchsiaCity_SafariZone_Entrance_EventScript_CheckHasRoomForPokemon::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, FuchsiaCity_SafariZone_Entrance_EventScript_HasRoomForPokemon
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, FuchsiaCity_SafariZone_Entrance_EventScript_HasRoomForPokemon
	msgbox FuchsiaCity_SafariZone_Entrance_Text_PCIsFull, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack
	end

FuchsiaCity_SafariZone_Entrance_EventScript_HasRoomForPokemon::
	return

FuchsiaCity_SafariZone_Entrance_EventScript_NotEnoughMoney::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack
	end

@ ============================================================================
@ FIX C1 -- shared refusal/failure exit, matching pokefirered's own
@ ForcePlayerBack (scripts.inc:165-175) verbatim in shape: closemessage,
@ hidemoneybox, walk the player one tile SOUTH (off row 3, back below every
@ trigger column) before releasing. Without this, a player who triggered
@ the prompt then declined/failed could simply continue walking north from
@ the exact tile they were standing on -- the walk-back is what forces them
@ to cross a live trigger again on any further attempt.
@ ============================================================================
FuchsiaCity_SafariZone_Entrance_EventScript_ForcePlayerBack::
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_ForceBack
	waitmovement 0
	releaseall
	end

FuchsiaCity_SafariZone_Entrance_Movement_ForceBack:
	walk_down
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneLeft:
	walk_up
	walk_right
	walk_up
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneMid:
	walk_up
	walk_up
	step_end

FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZoneRight:
	walk_up
	walk_left
	walk_up
	step_end

@ ============================================================================
@ Text
@ ============================================================================
FuchsiaCity_SafariZone_Entrance_Text_WelcomeFirstTime:
	.string "Welcome to the SAFARI ZONE!\n"
	.string "Is it your first time here?$"

FuchsiaCity_SafariZone_Entrance_Text_ComeInAndEnjoy:
	.string "Come in and enjoy the SAFARI ZONE!$"

FuchsiaCity_SafariZone_Entrance_Text_FirstTimeInfo:
	.string "When you enter the SAFARI ZONE, you\n"
	.string "start with 30 SAFARI BALLS for\l"
	.string "catching POKéMON.\p"
	.string "The SAFARI Game is over when you run\n"
	.string "out of SAFARI BALLS, or when you've\l"
	.string "walked 500 steps.\p"
	.string "Come in and enjoy the SAFARI ZONE!$"

FuchsiaCity_SafariZone_Entrance_Text_WouldYouLikeToPlay:
	.string "Welcome to the SAFARI ZONE!\p"
	.string "All you can catch for just ¥500!\n"
	.string "Would you like to play a SAFARI Game?$"

FuchsiaCity_SafariZone_Entrance_Text_PlayAnotherTime:
	.string "Okay.\n"
	.string "Please play another time!$"

FuchsiaCity_SafariZone_Entrance_Text_NotEnoughMoney:
	.string "You don't have enough money.\n"
	.string "Sorry.$"

FuchsiaCity_SafariZone_Entrance_Text_ThatWillBe500Please:
	.string "That will be ¥500, please.$"

FuchsiaCity_SafariZone_Entrance_Text_HereAreYourSafariBalls:
	.string "Here are your SAFARI BALLS.$"

FuchsiaCity_SafariZone_Entrance_Text_Received30SafariBalls:
	.string "{PLAYER} received 30 SAFARI BALLS.$"

FuchsiaCity_SafariZone_Entrance_Text_PleaseEnjoyYourself:
	.string "We'll let you know when your game\n"
	.string "is over.\p"
	.string "So, until then, enjoy yourself, please!\n"
	.string "Off you go on your wild excursion!$"

FuchsiaCity_SafariZone_Entrance_Text_PCIsFull:
	.string "Excuse me!\n"
	.string "Your PC BOX is full.$"

FuchsiaCity_SafariZone_Entrance_Text_GoingToLeaveEarly:
	.string "You still have time left. Would\n"
	.string "you like to leave the SAFARI ZONE\l"
	.string "now?$"

FuchsiaCity_SafariZone_Entrance_Text_ExitEarlyThanks:
	.string "Okay.\p"
	.string "We'll take back your remaining\n"
	.string "SAFARI BALLS.\p"
	.string "Thanks for playing!$"

FuchsiaCity_SafariZone_Entrance_Text_GoodLuckReturn:
	.string "Good luck out there!$"
