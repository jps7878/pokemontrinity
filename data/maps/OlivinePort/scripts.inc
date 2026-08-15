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

OlivinePort_EventScript_AideArrival::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement LOCALID_OLIVINE_PORT_AIDE, OlivinePort_Movement_AideApproachPlayer
	waitmovement 0
	msgbox OlivinePort_Text_WelcomeToOlivineCity, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_TRINITY_ARRIVED_JOHTO
	releaseall
	end

@ Trinity M4a fix: the aide and the player share the same single-tile-wide pier
@ column (x=7); she starts one tile north of the arrow-warp gangway tile (7,23)
@ and steps onto it, landing directly adjacent-north of the player's (7,24)
@ landing spot, already facing down toward them. (NPC applymovement does not
@ trigger MB_SOUTH_ARROW_WARP -- only player-initiated movement does -- so her
@ stepping onto (7,23) is inert; the player itself never moves during this scene.)
OlivinePort_Movement_AideApproachPlayer:
	walk_down
	step_end

OlivinePort_EventScript_Aide::
	lock
	faceplayer
	msgbox OlivinePort_Text_AideRepeat, MSGBOX_DEFAULT
	release
	end

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

OlivinePort_Text_AideRepeat:
	.string "The GYM LEADERS of JOHTO are waiting.\n"
	.string "Good luck out there, CHAMPION!$"

OlivinePort_Text_BackToLilycove:
	.string "Back to LILYCOVE CITY in HOENN?$"

OlivinePort_Text_SailAnotherTime:
	.string "Please sail with us another time!$"
