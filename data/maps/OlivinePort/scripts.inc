OlivinePort_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivinePort_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OlivinePort_OnFrame
	.byte 0

@ Trinity M4a: arm the aide's arrival scene only if it hasn't run yet. ON_TRANSITION
@ runs before the frame loop starts, so the movement-heavy scene itself waits for
@ OnFrame (same two-step arm/fire idiom as EverGrandeCity_HallOfFame's OnWarp+OnFrame).
OlivinePort_OnTransition:
	call_if_unset FLAG_TRINITY_ARRIVED_JOHTO, OlivinePort_EventScript_ArmAideArrival
	call OlivinePort_EventScript_SetBobbyVisibility
	end

OlivinePort_EventScript_ArmAideArrival::
	setvar VAR_TEMP_1, 1
	return

@ Trinity M5b S1 -- BOBBY's Olivine summons post. Dynamic, re-authored every
@ load (GoldenrodCity_EventScript_SetBobbyVisibility's own pattern, not the
@ aide's one-way terminal-flag shape above): he must both APPEAR post-HoF-II
@ and DISAPPEAR again once the crossing has happened, so a fixed terminal
@ flag cannot express his window. Visible iff arc-J is 10 (post HALL OF FAME
@ II) AND FLAG_TRINITY_J_LEAGUE_CLEARED is set (redundant with arc==10 by
@ construction, checked anyway to mirror the S1 brief's gate literally) AND
@ FLAG_TRINITY_K_ARRIVED is still unset (his summons is spent once the
@ crossing happens; BOBBY_Departure is the one thing that ever sets it).
OlivinePort_EventScript_SetBobbyVisibility::
	goto_if_unset FLAG_TRINITY_J_LEAGUE_CLEARED, OlivinePort_EventScript_HideBobby
	goto_if_lt VAR_TRINITY_JOHTO_ARC, 10, OlivinePort_EventScript_HideBobby
	goto_if_set FLAG_TRINITY_K_ARRIVED, OlivinePort_EventScript_HideBobby
	clearflag FLAG_TRINITY_K_OLIVINE_BOBBY_HIDE
	return

OlivinePort_EventScript_HideBobby::
	setflag FLAG_TRINITY_K_OLIVINE_BOBBY_HIDE
	return

OlivinePort_OnFrame:
	map_script_2 VAR_TEMP_1, 1, OlivinePort_EventScript_AideArrival
	.2byte 0

@ Trinity M4a fix 2: crystal-faithful pier layout. The player lands at (7,22),
@ two tiles up the single-tile-wide pier column (x=7) from the SAILOR, who
@ permanently stands on (7,23) facing up -- deliberately covering the arrow-warp
@ / self-stub warp tile there (crystal's own OlivinePort parks its gangway
@ sailor on that exact tile for the same reason). The pier tip (7,24) is south
@ of him and is unreachable now; that's fine, it's just the gangway edge.
@ The aide starts at (7,15) (top of the pier, at the plaza) and is a one-shot
@ cutscene actor: she walks down to greet the player, then walks back and
@ despawns via removeobject + a permanent hide-flag, so she never blocks the
@ pier and never respawns.
OlivinePort_EventScript_AideArrival::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement LOCALID_OLIVINE_PORT_AIDE, OlivinePort_Movement_AideApproachPlayer
	waitmovement 0
	msgbox OlivinePort_Text_WelcomeToOlivineCity, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_TRINITY_ARRIVED_JOHTO
	@ M4b S11B (I4 companion): pin the respawn Johto-side from the moment the
	@ player disembarks, so a whiteout before ever visiting a Center still
	@ lands them at OLIVINE, not wherever HOENN last set it. The sailor's
	@ return-boat setrespawn HEAL_LOCATION_LILYCOVE_CITY below (talk-triggered
	@ YES/NO only) still overrides this on an actual return trip; unaffected.
	setrespawn HEAL_LOCATION_OLIVINE_CITY
	applymovement LOCALID_OLIVINE_PORT_AIDE, OlivinePort_Movement_AideReturnToStart
	waitmovement 0
	removeobject LOCALID_OLIVINE_PORT_AIDE
	releaseall
	end

@ (7,15) -> (7,21): six tiles down the plain-floor pier column, stopping one
@ tile north of the player's (7,22) landing spot, already facing down.
OlivinePort_Movement_AideApproachPlayer:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ (7,21) -> (7,15): walk back up to her starting spot at the plaza before
@ despawning, so she's never seen popping out of existence mid-pier.
OlivinePort_Movement_AideReturnToStart:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OlivinePort_EventScript_Sailor::
	lock
	faceplayer
	msgbox OlivinePort_Text_BackToLilycove, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, OlivinePort_EventScript_SailorToLilycove
	@ Trinity M5a T5 -- KANTO leg, gated OFF behind FLAG_TRINITY_K_ARRIVED.
	@ M5b S1's S.S. AQUA arrival cutscene is the one writer; this task only
	@ reads it, so this second question stays unreachable until that slice
	@ lands (read-only check, no regression to the existing LILYCOVE branch).
	goto_if_unset FLAG_TRINITY_K_ARRIVED, OlivinePort_EventScript_SailorDecline
	msgbox OlivinePort_Text_OverToVermilion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, OlivinePort_EventScript_SailorToVermilion
	goto OlivinePort_EventScript_SailorDecline
	end

OlivinePort_EventScript_SailorToLilycove::
	closemessage
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

@ Dock tile decoded on VERMILION CITY: (24,33), MB_NORMAL, elevation 3,
@ collision 0, one tile north of the S.S. ANNE dock's (22-24,34)
@ MB_SOUTH_ARROW_WARP trio -- see task-5-report.md. Fade-warp idiom only
@ (YESNO -> warp -> waitstate), no cutscene: M5b S1 owns the one scripted
@ arrival, this is every REPEAT crossing after it.
OlivinePort_EventScript_SailorToVermilion::
	closemessage
	setrespawn HEAL_LOCATION_VERMILION_CITY
	warp MAP_VERMILION_CITY, 24, 33
	waitstate
	release
	end

OlivinePort_EventScript_SailorDecline::
	msgbox OlivinePort_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ Trinity M5b S1 -- BOBBY's summons. Talk-triggered (G1 idiom: named characters
@ are talk-triggered, never sight-triggered), dialogue only -- his battle is
@ the KANTO Crew Gauntlet (M5b S11). Visibility is OlivinePort_OnTransition's
@ own job (see above); this is purely the conversation + the one scripted
@ crossing. No lockall/movement staging here: the ONE cutscene budget (spec
@ decision 5) is spent at the Vermilion end, not here -- BOBBY is a
@ conversation at Olivine, not a set-piece.
@ ============================================================================
OlivinePort_EventScript_Bobby::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_K_AQUA_TICKET, OlivinePort_EventScript_BobbyWaiting
	msgbox OlivinePort_Text_BobbySummons, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox OlivinePort_Text_ReceivedAquaTicket, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_K_AQUA_TICKET
	msgbox OlivinePort_Text_BobbyExplainTicket, MSGBOX_DEFAULT
	msgbox OlivinePort_Text_BobbyReadyQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OlivinePort_EventScript_BobbyDecline
	goto OlivinePort_EventScript_BobbyDeparture
	end

@ Reached only via the goto_if_set above -- already lock'd/faceplayer'd.
OlivinePort_EventScript_BobbyWaiting::
	msgbox OlivinePort_Text_BobbyStillReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, OlivinePort_EventScript_BobbyDeparture
	release
	end

OlivinePort_EventScript_BobbyDecline::
	msgbox OlivinePort_Text_BobbyDecline, MSGBOX_DEFAULT
	release
	end

@ Dock tile decoded on VERMILION CITY: (24,33), MB_NORMAL, elevation 3,
@ collision 0 -- same landing tile the repeat-crossing sailor uses (see
@ OlivinePort_EventScript_SailorToVermilion above). warp/waitstate alone
@ triggers the engine's own transition fade; no extra fadescreen needed.
@ No removeobject for BOBBY here: OlivinePort_EventScript_SetBobbyVisibility
@ hides him on any future OlivinePort visit the instant the Vermilion
@ arrival scene sets FLAG_TRINITY_K_ARRIVED, which this warp leads straight
@ into.
OlivinePort_EventScript_BobbyDeparture::
	closemessage
	setrespawn HEAL_LOCATION_VERMILION_CITY
	warp MAP_VERMILION_CITY, 24, 33
	waitstate
	release
	end

@ ============================================================================
@ Trinity M4b S6 -- two of GSC's port bystanders, on GSC's own tiles (4,14) and
@ (13,14). The plaza is rows 14-15, x=2..15, all MB_NORMAL collision 0 elevation
@ 3; the ONLY cut vertex on this map is (7,15), the mouth of the single-tile
@ pier column, and that is M4a's aide, a one-shot removeobject actor. Neither
@ new tile is adjacent to the pier.
@ GSC's post-Hall-of-Fame set (YOUNGSTER (4,15), COOLTRAINER F (11,15)) is
@ deliberately left for a later slice -- the plaza is only two rows deep and the
@ pier approach should stay clear.
@ ============================================================================
OlivinePort_EventScript_FishingGuru1::
	msgbox OlivinePort_Text_FishingGuru1, MSGBOX_NPC
	end

OlivinePort_EventScript_FishingGuru2::
	msgbox OlivinePort_Text_FishingGuru2, MSGBOX_NPC
	end

@ GSC OlivinePortFishingGuru1Text.
OlivinePort_Text_FishingGuru1:
	.string "SHELLDER are easy to catch off this\n"
	.string "pier. Kind of rare everywhere else.$"

@ GSC OlivinePortFishingGuru2Text.
OlivinePort_Text_FishingGuru2:
	.string "How many RODS are you carrying?\p"
	.string "Different RODS bring up different\n"
	.string "POKéMON. That's the whole trick.$"

OlivinePort_Text_WelcomeToOlivineCity:
	.string "Welcome to OLIVINE CITY!\p"
	.string "You're the HOENN Champion, aren't you?\n"
	.string "Professor ELM asked me to find you.\p"
	.string "He's studying champion-caliber teams at\n"
	.string "his lab in NEW BARK TOWN, far east.\p"
	.string "Please visit him! Follow the roads east\n"
	.string "through ECRUTEAK and VIOLET.\p"
	.string "Oh -- and JOHTO's GYM LEADERS are on a\n"
	.string "whole other level. Good luck!$"

OlivinePort_Text_BackToLilycove:
	.string "Back to LILYCOVE CITY in HOENN?$"

OlivinePort_Text_OverToVermilion:
	.string "How about VERMILION CITY, over in\n"
	.string "KANTO?$"

OlivinePort_Text_SailAnotherTime:
	.string "Please sail with us another time!$"

@ BOBBY's established voice: RadioTower5F_Text_Bobby1..3 (the reveal) and
@ GoldenrodCity_Text_Bobby (the coda, "Go and finish the badges. I'll be
@ somewhere behind you.") -- terse, wry, professional. This summons pays off
@ that closing line directly.
OlivinePort_Text_BobbySummons:
	.string "BOBBY: There you are.\p"
	.string "JOHTO's done. I need you across the\n"
	.string "water.\p"
	.string "GIOVANNI didn't stick around for\n"
	.string "INDIGO. He's gone east -- KANTO, and\l"
	.string "everything that means for him.\p"
	.string "My office wants eyes on him that\n"
	.string "aren't mine. You're already the\l"
	.string "reason two LEAGUES know his name.\p"
	.string "Got you passage on the S.S. AQUA.\n"
	.string "VERMILION CITY, KANTO side.$"

OlivinePort_Text_ReceivedAquaTicket:
	.string "{PLAYER} received the\n"
	.string "S.S. AQUA TICKET.$"

OlivinePort_Text_BobbyExplainTicket:
	.string "BOBBY: Show that at the dock and\n"
	.string "you're on board. One-way, for now.$"

OlivinePort_Text_BobbyReadyQuestion:
	.string "BOBBY: Whenever you're ready.$"

OlivinePort_Text_BobbyStillReady:
	.string "BOBBY: Boat's waiting. Ready?$"

OlivinePort_Text_BobbyDecline:
	.string "BOBBY: It'll keep. Come find me\n"
	.string "when you are.$"
