@ ============================================================================
@ Trinity M5b S8 -- the Fuchsia Safari Zone entrance booth, wired onto the
@ vanilla Hoenn safari engine wholesale (canonical source:
@ Route121_SafariZoneEntrance/scripts.inc). See
@ docs/superpowers/plans/m5b/08-fuchsia-safari.md section 1.
@
@ ON_FRAME: mirrors Route121's own table exactly -- VAR_SAFARI_ZONE_STATE==1
@ means "now exiting" for EITHER region (data/scripts/safari_zone.inc picks
@ this map as the landing site only when the session was Kanto's, state==3
@ at exit-decision time; both branches converge on state==1 before the warp).
@
@ Room decode (9x9, LAYOUT_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE_KANTO): a 3-wide
@ public corridor (cols 3-5) flanked by two MB_COUNTER-walled staff pockets
@ (col 1 west, col 7 east) -- byte-for-byte match to pokefirered's own
@ layout. The counter trigger sits at (4,3), the corridor's own row-3 mouth,
@ mirroring Route121's single-trigger shape (not FRLG's own three-directional
@ VAR_TEMP_2 split, which is FireRed-engine-specific and not ported).
@
@ Deliberate divergence from Route121's literal fee flow: the
@ ITEM_POKEBLOCK_CASE gate is DROPPED. Pokeblocks are a Hoenn-only mechanic
@ with no Kanto/FRLG counterpart (pokefirered's own real entrance script has
@ no such check) -- copying it wholesale would gate Kanto's safari on an
@ item with no in-region purpose.
@ ============================================================================
FuchsiaCity_SafariZone_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_SafariZone_Entrance_OnFrame
	.byte 0

FuchsiaCity_SafariZone_Entrance_OnFrame:
	map_script_2 VAR_SAFARI_ZONE_STATE, 1, FuchsiaCity_SafariZone_Entrance_EventScript_ExitSafariZone
	.2byte 0

FuchsiaCity_SafariZone_Entrance_EventScript_ExitSafariZone::
	lockall
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_ExitSafariZone
	waitmovement 0
	setvar VAR_SAFARI_ZONE_STATE, 0
	releaseall
	end

FuchsiaCity_SafariZone_Entrance_Movement_ExitSafariZone:
	walk_down
	step_end

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
@ The fee counter -- NEW coord_event trigger, (4,3), the corridor's row-3
@ mouth. Step-triggered (TryStartCoordEventScript fires from
@ TryStartStepBasedScript, src/field_control_avatar.c:608-611, on a
@ completed step -- never re-evaluated for a stationary player), so no
@ VAR_TEMP_1 disarm is needed, matching Route121's own trigger (which never
@ touches VAR_TEMP_1 either).
@ ============================================================================
FuchsiaCity_SafariZone_Entrance_EventScript_EntranceCounterTrigger::
	lockall
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZone_Entrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZone_Entrance_EventScript_TryEnterSafariZone
	msgbox FuchsiaCity_SafariZone_Entrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	releaseall
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
	applymovement LOCALID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZone
	waitmovement 0
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 3
	warp MAP_SAFARI_ZONE_CENTER, 26, 30
	waitstate
	end

FuchsiaCity_SafariZone_Entrance_EventScript_CheckHasRoomForPokemon::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, FuchsiaCity_SafariZone_Entrance_EventScript_HasRoomForPokemon
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, FuchsiaCity_SafariZone_Entrance_EventScript_HasRoomForPokemon
	msgbox FuchsiaCity_SafariZone_Entrance_Text_PCIsFull, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	releaseall
	end

FuchsiaCity_SafariZone_Entrance_EventScript_HasRoomForPokemon::
	return

FuchsiaCity_SafariZone_Entrance_EventScript_NotEnoughMoney::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	releaseall
	end

FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZone:
	walk_up
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
