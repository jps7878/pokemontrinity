@ ============================================================================
@ THE BASEMENT DOOR at (18,6), decoded from
@ data/layouts/GoldenrodUnderground_Johto/map.bin. See RadioTower3F's header for
@ the converter's block map (metatile = 512 + 4*<GSC block> + q, q order
@ TL/TR/BL/BR, collision from pokecrystal's <tileset>_collision.asm).
@
@   shipped  (18,6)=696 (19,6)=697 (18,7)=698 (19,7)=699  = GSC block $2e
@            gate tileset $2e = DOOR WALL FLOOR FLOOR -- the door OPEN
@   locked   756/757/758/759                              = GSC block $3d
@            gate tileset $3d = WALL WALL FLOOR FLOOR
@
@ (18,6) decodes MB_NON_ANIMATED_DOOR and is warp 2 of this map -- the door is
@ two-way INSIDE one map, (18,6) <-> (21,31), and it is the only route to
@ (22,27), which is the only route to the SWITCH ROOMS.
	.set METATILE_JohtoGate_DoorLockedTL,  756
	.set METATILE_JohtoGate_DoorLockedTR,  757
	.set METATILE_JohtoGate_DoorLockedBL,  758
	.set METATILE_JohtoGate_DoorLockedBR,  759
	.set METATILE_JohtoGate_DoorOpenTL,    696
	.set METATILE_JohtoGate_DoorOpenTR,    697
	.set METATILE_JohtoGate_DoorOpenBL,    698
	.set METATILE_JohtoGate_DoorOpenBR,    699
@ ============================================================================

GoldenrodUnderground_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodUnderground_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S8 -- RESTORING GSC'S LOCK.
@
@ GSC ships this door OPEN in the blockdata and LOCKS it in a map callback
@ (GoldenrodUnderground.asm:42-49, `changeblock 18,6,$3d` unless
@ EVENT_USED_BASEMENT_KEY). M4a carried the blockdata across and dropped the
@ callback, so the door has stood open since M3 and the whole second half of
@ this chapter has been walkable with no key.
@
@ D2: the shipped map.bin is UNLOCKED, so the authoring direction here is
@ LOCKED. D4: FLAG_TRINITY_J_BASEMENT_DOOR is the door's only state and is
@ monotonic; FLAG_TRINITY_J_BASEMENT_KEY is an INPUT.
@
@ R5 DISCLOSURE -- what the lock seals, and for how long. reach_check --dungeon
@ over UNDERGROUND + SWITCH ROOMS + WAREHOUSE, (18,6) forced impassable:
@   locked    465 of 682 tiles from the 5 outward doors
@             SEALED: (18,6) (21,31) (22,31) (22,27) and SwitchRooms (23,3)
@   unlocked  no sealed warp on the UNDERGROUND side
@ The sealed region is this map's east branch, the whole switch maze and the
@ warehouse: two item balls, two hidden items and three warehouse item balls,
@ ALL OPTIONAL, NONE gating progression, and it opens the moment the RADIO
@ TOWER's imposter hands over the key at ARC 6. This is a RESTORATION of GSC's
@ own gate, not a new seal -- in GSC the door is locked the first time a player
@ ever walks this tunnel. The two GOLDENROD stairwells, the merchant row, the
@ barbers and the COIN CASE are all on the open side and are untouched.
@ ============================================================================
GoldenrodUnderground_OnTransition:
	call GoldenrodUnderground_EventScript_AuthorBasementDoor
	end

GoldenrodUnderground_EventScript_AuthorBasementDoor::
	goto_if_set FLAG_TRINITY_J_BASEMENT_DOOR, GoldenrodUnderground_EventScript_DoorStaysOpen
	setmetatile 18, 6, METATILE_JohtoGate_DoorLockedTL, TRUE
	setmetatile 19, 6, METATILE_JohtoGate_DoorLockedTR, TRUE
	setmetatile 18, 7, METATILE_JohtoGate_DoorLockedBL, FALSE
	setmetatile 19, 7, METATILE_JohtoGate_DoorLockedBR, FALSE
GoldenrodUnderground_EventScript_DoorStaysOpen::
	return

@ ============================================================================
@ D1/D3/D4 -- the door itself.
@
@ The bg_event sits ON the warp tile (18,6). That is deliberate and it is why
@ D4's "test the door flag FIRST" clause matters more here than anywhere else:
@ once the door is open the tile is walkable AND a warp, so pressing A while
@ facing it must not re-run the unlock. GSC does exactly the same
@ (BasementDoorScript on bg_event 18,6).
@ ============================================================================
GoldenrodUnderground_EventScript_BasementDoor::
	lockall
	goto_if_set FLAG_TRINITY_J_BASEMENT_DOOR, GoldenrodUnderground_EventScript_BasementDoorOpen
	goto_if_unset FLAG_TRINITY_J_BASEMENT_KEY, GoldenrodUnderground_EventScript_BasementDoorLocked
	msgbox GoldenrodUnderground_Text_BasementKeyOpenedDoor, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	setmetatile 18, 6, METATILE_JohtoGate_DoorOpenTL, FALSE
	setmetatile 19, 6, METATILE_JohtoGate_DoorOpenTR, TRUE
	setmetatile 18, 7, METATILE_JohtoGate_DoorOpenBL, FALSE
	setmetatile 19, 7, METATILE_JohtoGate_DoorOpenBR, FALSE
	special DrawWholeMapView
	waitse
	setflag FLAG_TRINITY_J_BASEMENT_DOOR
	releaseall
	end

GoldenrodUnderground_EventScript_BasementDoorLocked::
	msgbox GoldenrodUnderground_Text_DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

GoldenrodUnderground_EventScript_BasementDoorOpen::
	msgbox GoldenrodUnderground_Text_DoorIsOpen, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@ Trinity M4b S4 -- the UNDERGROUND, pre-arc state.
@
@ The four merchant/barber NPCs sit on GSC's tiles: (7,11) (7,14) (7,15)
@ (7,21). Each is collision 0 elevation 3 but UNREACHABLE on foot with zero
@ objects placed -- they are booths behind the west wall -- and each is fronted
@ by an MB_COUNTER tile at (6,y), served from (5,y)
@ (GetInteractedObjectEventScript -> MetatileBehavior_IsCounter -> look one
@ tile further, src/field_control_avatar.c:387-396). Objects on
@ already-unreachable tiles cost exactly zero walkability.
@ ELEVATION NUANCE (full statement in GoldenrodDeptStore5F/scripts.inc): the
@ lookup compares the NPC's elevation against the PLAYER'S, not the counter's
@ (GetInFrontOfPlayerPosition, src/field_control_avatar.c:264-274). Service
@ tiles (5,11)/(5,14)/(5,15)/(5,21) and all four booths decode elevation 3 --
@ match. The counters at (6,y) decode elevation 0 and are never compared.
@
@ GSC gates all four behind VAR_WEEKDAY and the clock
@ (GoldenrodUnderground.asm:56-...). Trinity ports no day-of-week system, so
@ they simply stand their booths.
@
@ FLAVOUR ONLY, deliberately. The HAIRCUT BROTHERS' 500/300 friendship
@ service and the two merchants' priced stock are systems, and a "bargain"
@ price cannot even be expressed -- pokemart has no per-shop pricing
@ (GetItemPrice reads the global gItemsInfo entry). Logged as skips.
@
@ THE SWITCH DOORS STAY CLOSED. S4 adds no switch, no changeblock, no CARD KEY
@ and no BASEMENT KEY. This map's east branch stays exactly as shipped:
@ reachable only through GOLDENROD UNDERGROUND SWITCH ROOM ENTRANCES. That
@ two-component split is pre-existing and object-independent.
@ ============================================================================

GoldenrodUnderground_EventScript_BargainMerchant::
	msgbox GoldenrodUnderground_Text_BargainMerchant, MSGBOX_NPC
	end

GoldenrodUnderground_EventScript_OlderHaircutBrother::
	msgbox GoldenrodUnderground_Text_OlderHaircutBrother, MSGBOX_NPC
	end

GoldenrodUnderground_EventScript_YoungerHaircutBrother::
	msgbox GoldenrodUnderground_Text_YoungerHaircutBrother, MSGBOX_NPC
	end

GoldenrodUnderground_EventScript_HerbGranny::
	msgbox GoldenrodUnderground_Text_HerbGranny, MSGBOX_NPC
	end

GoldenrodUnderground_EventScript_ERIC::
	trainerbattle_single TRAINER_JOHTO_SUPER_NERD_ERIC, GoldenrodUnderground_Text_ERICSeen, GoldenrodUnderground_Text_ERICBeaten
	msgbox GoldenrodUnderground_Text_ERICBeaten, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_TERU::
	trainerbattle_single TRAINER_JOHTO_SUPER_NERD_TERU, GoldenrodUnderground_Text_TERUSeen, GoldenrodUnderground_Text_TERUBeaten
	msgbox GoldenrodUnderground_Text_TERUBeaten, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_ISSAC::
	trainerbattle_single TRAINER_JOHTO_POKEMANIAC_ISSAC, GoldenrodUnderground_Text_ISSACSeen, GoldenrodUnderground_Text_ISSACBeaten
	msgbox GoldenrodUnderground_Text_ISSACBeaten, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_DONALD::
	trainerbattle_single TRAINER_JOHTO_POKEMANIAC_DONALD, GoldenrodUnderground_Text_DONALDSeen, GoldenrodUnderground_Text_DONALDBeaten
	msgbox GoldenrodUnderground_Text_DONALDBeaten, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_NoEntrySign::
	msgbox GoldenrodUnderground_Text_NoEntrySign, MSGBOX_SIGN
	end

@ Adapts GSC's BargainMerchantScript patter (he is the man who shouts about
@ what his stock would cost you upstairs).
GoldenrodUnderground_Text_BargainMerchant:
	.string "Step up! Bargains! Real ones!\p"
	.string "Everything on this counter is\n"
	.string "cheaper than the DEPT.STORE.\p"
	.string "Ah. Not today, sadly. Today the\n"
	.string "counter is empty and I am\l"
	.string "shouting out of habit.\p"
	.string "Come back. I'm always here.\n"
	.string "That's the whole business.$"

@ Adapts GoldenrodUndergroundOlderHaircutBrotherOfferHaircutText.
GoldenrodUnderground_Text_OlderHaircutBrother:
	.string "Welcome! I run the POKéMON\n"
	.string "SALON!\p"
	.string "I'm the older and better of the\n"
	.string "two HAIRCUT BROTHERS.\p"
	.string "I can make your POKéMON\n"
	.string "beautiful. Beautiful POKéMON\l"
	.string "like their trainers more. It's\l"
	.string "science.\p"
	.string "…Chair's full today. Look at\n"
	.string "him. He's been in it an hour.$"

GoldenrodUnderground_Text_YoungerHaircutBrother:
	.string "Don't listen to my brother.\p"
	.string "He charges more and he takes\n"
	.string "longer and the POKéMON come out\l"
	.string "the same.\p"
	.string "I'm cheaper and I'm faster.\p"
	.string "…He's better. But I'm cheaper\n"
	.string "and I'm faster.$"

@ Adapts BitterMerchantScript -- GSC's herb granny, whose stock is famously
@ effective and famously unpleasant.
GoldenrodUnderground_Text_HerbGranny:
	.string "Herbs, dear. Bitter ones.\p"
	.string "They work better than anything\n"
	.string "in a shiny wrapper upstairs,\l"
	.string "and every POKéMON that has ever\l"
	.string "tasted one has held it against\l"
	.string "its trainer.\p"
	.string "That's the trade. Nobody likes\n"
	.string "it. It's still the trade.$"

GoldenrodUnderground_Text_ERICSeen:
	.string "I got booted out\nof the GAME COR-\lNER.\pI was trying to\ncheat using my\lPOKéMON…$"

GoldenrodUnderground_Text_ERICBeaten:
	.string "…Grumble…$"

GoldenrodUnderground_Text_TERUSeen:
	.string "Do you consider\ntype alignments in\lbattle?\pIf you know your\ntype advantages,\pyou'll do better\nin battle.$"

GoldenrodUnderground_Text_TERUBeaten:
	.string "Ow, ow, ow!$"

GoldenrodUnderground_Text_ISSACSeen:
	.string "My POKéMON just\ngot a haircut!\pI'll show you how\nstrong it is!$"

GoldenrodUnderground_Text_ISSACBeaten:
	.string "Aiyeeee!$"

GoldenrodUnderground_Text_DONALDSeen:
	.string "I think you have\nsome rare POKéMON\lwith you.\pLet me see them!$"

GoldenrodUnderground_Text_DONALDBeaten:
	.string "Gaah! I lost!\nThat makes me mad!$"

GoldenrodUnderground_Text_NoEntrySign:
	.string "NO ENTRY BEYOND\nTHIS POINT$"

@ ============================================================================
@ Trinity M4b S8 text. GSC GoldenrodUndergroundTheDoorsLockedText /
@ …BasementKeyOpenedDoorText / …TheDoorIsOpenText.
@ ============================================================================
GoldenrodUnderground_Text_DoorIsLocked:
	.string "The door is locked.\p"
	.string "There is a keyhole set into the\n"
	.string "plate, and nothing else.$"

GoldenrodUnderground_Text_BasementKeyOpenedDoor:
	.string "{PLAYER} put the BASEMENT KEY\n"
	.string "into the lock.\p"
	.string "The door swung open.$"

GoldenrodUnderground_Text_DoorIsOpen:
	.string "The door is open.$"
