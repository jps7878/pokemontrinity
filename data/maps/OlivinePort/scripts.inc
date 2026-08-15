OlivinePort_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivinePort_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OlivinePort_OnFrame
	.byte 0

@ Trinity M4a: arm the aide's arrival scene only if it hasn't run yet. ON_TRANSITION
@ runs before the frame loop starts, so the movement-heavy scene itself waits for
@ OnFrame (same two-step arm/fire idiom as EverGrandeCity_HallOfFame's OnWarp+OnFrame).
OlivinePort_OnTransition:
	call_if_unset FLAG_TRINITY_ARRIVED_JOHTO, OlivinePort_EventScript_ArmAideArrival
	end

OlivinePort_EventScript_ArmAideArrival::
	setvar VAR_TEMP_1, 1
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
	goto_if_eq VAR_RESULT, NO, OlivinePort_EventScript_SailorDecline
	closemessage
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

OlivinePort_EventScript_SailorDecline::
	msgbox OlivinePort_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

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

OlivinePort_Text_SailAnotherTime:
	.string "Please sail with us another time!$"
