@ ============================================================================
@ Trinity M7 Task 9 (finding #17): the car IS the lift. pokefirered's own
@ RocketHideout_Elevator flow on this tree's own working idiom
@ (LilycoveCity_DepartmentStoreElevator: MAP_DYNAMIC doors + setdynamicwarp).
@ Boarding through any floor's HideoutElevatorDoor auto-records that door
@ (SetupWarp, src/field_control_avatar.c:1011-1014: when the DESTINATION
@ map's target warp has mapNum MAP_DYNAMIC -- which both of this car's
@ warps now do -- SetDynamicWarp is called with the CURRENT map and the
@ warp the player just used); the panel re-points it; the player walks out
@ via (2,5) MB_SOUTH_ARROW_WARP and lands ON the chosen floor's door tile
@ (683, beh 0x69 MB_ANIMATED_DOOR, col 1 elev 0), which Task_ExitDoor walks
@ out one tile south: B1F (24,26) / B2F (28,17) / B4F (20,24) -- all decoded
@ this pass as beh 0x00 MB_NORMAL, col 0, elev 3, object-free. No door
@ open/close animation plays on that landing: 683 -- like every Kanto door
@ in the tree -- has no sDoorAnimGraphicsTable entry (src/field_door.c:223),
@ so GetDoorGraphics returns NULL, Task_ExitDoor's data[1] is -1 and it just
@ walks the player south off the closed-door art. Pre-existing tree-wide,
@ not a lift bug. B4F (20,24) is the RIGHT component: the lift is the only
@ way into it, exactly as in FRLG (S6's two invisible shuttle signs are
@ gone). No floor memory: FR's saved VAR_ELEVATOR_FLOOR has no var budget
@ (M7 Global Constraints) and temp vars die on the warp in, so choosing the
@ floor you are on re-points the door and still rides (cosmetic; FR skips
@ it). `special MoveElevator` is NOT used: its window-light task stamps
@ BattleFrontier metatiles 0x329..0x33B at (1..3,0..2) -- this car's SilphCo
@ window tiles -- and corrupts them. The ride is FR's AnimateElevator minus
@ the lights: ShakeCamera's +-1 vertical pan on a 3-frame tick, 24 ticks (FR's
@ two-floor trip), SE_ELEVATOR hum, SE_DING_DONG on arrival. ShakeCamera
@ hard-codes PlaySE(SE_M_STRENGTH) (src/field_specials.c:1730-1740);
@ SE_ELEVATOR issued on the same frame replaces it (both on MUSIC_PLAYER_SE1,
@ sound/song_table.inc) -- listen at the M7 gate. gSaveBlock1Ptr->dynamicWarp
@ already exists (Lilycove, truck): no SaveBlock change. Zero flags, zero
@ vars (0x8004-7 are ShakeCamera's own scratch), zero C. AFFORDANCE RULE
@ (M7): the panel art at (0,1)-(0,2) and the red exit mat at (2,5) are the
@ drawn affordances; the three floor doors are the distinct
@ HideoutElevatorDoor tiles.
@ ============================================================================
RocketHideout_Elevator_MapScripts::
	.byte 0

RocketHideout_Elevator_EventScript_FloorSelect::
	lockall
	goto_if_unset FLAG_TRINITY_K_LIFT_KEY, RocketHideout_Elevator_EventScript_NeedKey
	message RocketHideout_Elevator_Text_WhichFloor
	waitmessage
	multichoice 0, 0, MULTI_ROCKET_HIDEOUT_ELEVATOR, FALSE
	switch VAR_RESULT
	case 0, RocketHideout_Elevator_EventScript_ToB1F
	case 1, RocketHideout_Elevator_EventScript_ToB2F
	case 2, RocketHideout_Elevator_EventScript_ToB4F
	case 3, RocketHideout_Elevator_EventScript_Exit
	case MULTI_B_PRESSED, RocketHideout_Elevator_EventScript_Exit
	end

RocketHideout_Elevator_EventScript_ToB1F::
	setdynamicwarp MAP_ROCKET_HIDEOUT_B1F, 24, 25
	goto RocketHideout_Elevator_EventScript_Ride

RocketHideout_Elevator_EventScript_ToB2F::
	setdynamicwarp MAP_ROCKET_HIDEOUT_B2F, 28, 16
	goto RocketHideout_Elevator_EventScript_Ride

RocketHideout_Elevator_EventScript_ToB4F::
	setdynamicwarp MAP_ROCKET_HIDEOUT_B4F, 20, 23
	goto RocketHideout_Elevator_EventScript_Ride

RocketHideout_Elevator_EventScript_Ride::
	closemessage
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 24
	setvar VAR_0x8007, 3
	special ShakeCamera
	playse SE_ELEVATOR
	waitstate
	playse SE_DING_DONG
	waitse
	releaseall
	end

RocketHideout_Elevator_EventScript_Exit::
	closemessage
	releaseall
	end

RocketHideout_Elevator_EventScript_NeedKey::
	msgbox RocketHideout_Elevator_Text_NeedKey, MSGBOX_DEFAULT
	releaseall
	end

RocketHideout_Elevator_Text_WhichFloor:
	.string "Which floor do you want?$"

RocketHideout_Elevator_Text_NeedKey:
	.string "The lift's panel is locked. It\nneeds a key -- one of the grunts\lbelow must be carrying it.$"
