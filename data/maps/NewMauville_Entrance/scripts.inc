NewMauville_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Entrance_OnTransition
	.byte 0

NewMauville_Entrance_OnLoad:
	call_if_eq VAR_NEW_MAUVILLE_STATE, 0, NewMauville_Entrance_EventScript_CloseDoor
	end

NewMauville_Entrance_EventScript_CloseDoor::
	setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile0, TRUE
	setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile1, TRUE
	setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile2, TRUE
	setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile3, TRUE
	setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile4, TRUE
	setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile5, TRUE
	return

NewMauville_Entrance_OnTransition:
	setflag FLAG_LANDMARK_NEW_MAUVILLE
	end

NewMauville_Entrance_EventScript_Door::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox NewMauville_Entrance_Text_DoorIsLocked, MSGBOX_DEFAULT
	checkitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, FALSE, NewMauville_Entrance_EventScript_DontOpenDoor
	msgbox NewMauville_Entrance_Text_UseBasementKey, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NewMauville_Entrance_EventScript_DontOpenDoor
	msgbox NewMauville_Entrance_Text_UsedBasementKey, MSGBOX_DEFAULT
	setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile0, FALSE
	setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile1, FALSE
	setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile2, FALSE
	setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile3, TRUE
	setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile4, FALSE
	setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile5, TRUE
	special DrawWholeMapView
	playse SE_BANG
	setvar VAR_NEW_MAUVILLE_STATE, 1
	releaseall
	end

NewMauville_Entrance_EventScript_DontOpenDoor::
	releaseall
	end

NewMauville_Entrance_Text_DoorIsLocked:
	.string "The door is locked.$"

NewMauville_Entrance_Text_UseBasementKey:
	.string "Use the BASEMENT KEY?$"

NewMauville_Entrance_Text_UsedBasementKey:
	.string "{PLAYER} used the BASEMENT KEY.\p"
	.string "The door opened!$"

NewMauville_Entrance_EventScript_Prabhjit::
	trainerbattle_single TRAINER_PRABHJIT, NewMauville_Entrance_Text_PrabhjitIntro, NewMauville_Entrance_Text_PrabhjitDefeat, NewMauville_Entrance_EventScript_PrabhjitReward
	goto_if_unset FLAG_RECEIVED_REWARD_PRABHJIT, NewMauville_Entrance_EventScript_PrabhjitReward
	msgbox NewMauville_Entrance_Text_PrabhjitPostReward, MSGBOX_DEFAULT
	release
	end

NewMauville_Entrance_EventScript_PrabhjitReward::
	msgbox NewMauville_Entrance_Text_PrabhjitRewardOffer, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_FAMILY_REWARD, FALSE
	switch VAR_RESULT
	case 0, NewMauville_Entrance_EventScript_PrabhjitMasterBalls
	case 1, NewMauville_Entrance_EventScript_PrabhjitRareCandies
	case 2, NewMauville_Entrance_EventScript_PrabhjitCancel
	case MULTI_B_PRESSED, NewMauville_Entrance_EventScript_PrabhjitCancel
	end

NewMauville_Entrance_EventScript_PrabhjitMasterBalls::
	giveitem ITEM_MASTER_BALL, 2
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_REWARD_PRABHJIT
	msgbox NewMauville_Entrance_Text_PrabhjitPostReward, MSGBOX_DEFAULT
	release
	end

NewMauville_Entrance_EventScript_PrabhjitRareCandies::
	giveitem ITEM_RARE_CANDY, 99
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_REWARD_PRABHJIT
	msgbox NewMauville_Entrance_Text_PrabhjitPostReward, MSGBOX_DEFAULT
	release
	end

NewMauville_Entrance_EventScript_PrabhjitCancel::
	release
	end

NewMauville_Entrance_Text_PrabhjitIntro:
	.string "Migs, it's time to Duel!$"

NewMauville_Entrance_Text_PrabhjitDefeat:
	.string "PHATASE!$"

NewMauville_Entrance_Text_PrabhjitRewardOffer:
	.string "You've earned a reward.\n"
	.string "Choose wisely.$"

NewMauville_Entrance_Text_PrabhjitPostReward:
	.string "Next time, the voltage will\n"
	.string "be much higher...$"

