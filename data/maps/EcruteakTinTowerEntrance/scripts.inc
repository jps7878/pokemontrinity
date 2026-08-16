EcruteakTinTowerEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakTinTowerEntrance_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S10 -- THE TIN TOWER GATE.
@
@ THE GEOMETRY IS THE GATE, AND IT IS GSC'S OWN. Measured with reach_check on
@ ECRUTEAK CITY with zero new objects placed:
@
@   from (37,7)->MAP_TIN_TOWER_1F : 57 tiles, reaches ONLY (20,2)/(20,3)->WISE TRIOS ROOM
@   from any of the other 11 city doors : 454 tiles, all three of those SEALED OFF
@
@ The TIN TOWER's courtyard is a walled 57-tile enclave in the city whose only
@ entrance is the WISE TRIOS ROOM, which is only reachable through this
@ building. So the route is, and can only be:
@
@   ECRUTEAK CITY (18,11) -> here (4,17)/(5,17)
@      -> the 2-wide waist at (4,6)/(5,6)              <-- THIS GATE
@      -> (5,3) internal warp -> (17,15) -> (17,3)
@      -> WISE TRIOS ROOM (1,4) -> (7,4)/(7,5)
@      -> ECRUTEAK CITY (20,2)/(20,3) courtyard -> (37,7) -> TIN TOWER 1F
@
@ TILE DECODES (map.bin + metatile_attributes.bin), all reachable:
@   (4,6) (5,6) collision 0, elevation 3, MB_NORMAL. Row 6 is walkable at x=4
@         and x=5 AND NOWHERE ELSE (####..########X#..#X), so these two tiles
@         are the complete waist of the building and (4,7)/(5,7) are their only
@         approach.  Both are GSC's own sage tiles.
@   (6,9) collision 0, elevation 3, MB_NORMAL -- GSC's wandering sage, inside
@         the 8-wide south room (rows 7-13, x 1-8).
@   (3,11) collision 0, elevation 3, MB_NORMAL -- GSC's GRAMPS, same room.
@   None of the four is a warp tile (S5's rule) and this map has no bg_events.
@
@ AMENDMENT, DELIBERATE AND CONTROLLER-VISIBLE. GSC runs a SIDESTEP gimmick:
@ two objects on (4,6)/(5,6) with complementary events, exactly ONE visible, and
@ a coord_event pair at (4,7)/(5,7) that slides him onto whichever tile you aim
@ for (EcruteakTinTowerEntrance.asm:295-296 + the SageBlocksLeft/Right scenes).
@ Trinity stands BOTH while the gate is shut. The gimmick is correct but its
@ correctness rests on the player never reaching row 6 without first stepping
@ onto a coord tile -- an argument that holds but is delicate, and this gate
@ ships under a no-play-test regime. Two static objects make the gate
@ unambiguous, and make it visible to reach_check instead of invisible to it.
@
@ R5 DISCLOSURE. While shut, this pair seals the building's north corridor, the
@ WISE TRIOS ROOM, the 57-tile TIN TOWER courtyard and TIN TOWER 1F-Roof. ALL OF
@ IT IS OPTIONAL CONTENT: no badge, no league requirement and no other slice's
@ beat lies behind it (S11 gates INDIGO on the eight Johto badges -- see the S10
@ plan's arc-9 handoff). It opens permanently the moment the CLEAR BELL is
@ presented. This is a RESTORATION of GSC's own gate, which the M4a port shipped
@ wide open, not a new seal.
@
@ THE THREE ERAS ARE GSC'S, in order:
@   1. no FOGBADGE          -- "off limits to anyone without ECRUTEAK GYM's BADGE"
@   2. badge, no CLEAR BELL  -- "a momentous event has occurred"
@   3. CLEAR BELL            -- the unlock
@ FLAG_TRINITY_J_CLEAR_BELL (0x29C, S8) gets its FIRST READER here; S8's DIRECTOR
@ already names TIN TOWER and the WHIRL ISLANDS, so the hook needed no S8 edit.
@ ============================================================================

EcruteakTinTowerEntrance_OnTransition::
	call_if_set FLAG_TRINITY_J_TIN_TOWER_OPEN, EcruteakTinTowerEntrance_EventScript_OpenGate
	call_if_unset FLAG_TRINITY_J_TIN_TOWER_OPEN, EcruteakTinTowerEntrance_EventScript_ShutGate
	end

EcruteakTinTowerEntrance_EventScript_OpenGate::
	setflag FLAG_TRINITY_J_TIN_GATE_SAGE_HIDE
	return

EcruteakTinTowerEntrance_EventScript_ShutGate::
	clearflag FLAG_TRINITY_J_TIN_GATE_SAGE_HIDE
	return

@ ---------------------------------------------------------------------------
@ Both sages share ONE script. They are the same character in GSC too (the
@ sidestep pair is one man rendered twice); here they are two men saying the
@ same thing, which reads correctly either way.
@ ---------------------------------------------------------------------------
EcruteakTinTowerEntrance_EventScript_Sage::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_TIN_TOWER_OPEN, EcruteakTinTowerEntrance_EventScript_SagePass
	goto_if_set FLAG_TRINITY_J_CLEAR_BELL, EcruteakTinTowerEntrance_EventScript_SageBell
	goto_if_unset FLAG_TRINITY_BADGE12, EcruteakTinTowerEntrance_EventScript_SageNoBadge
	msgbox EcruteakTinTowerEntrance_Text_SageMomentous, MSGBOX_DEFAULT
	release
	end

EcruteakTinTowerEntrance_EventScript_SageNoBadge::
	msgbox EcruteakTinTowerEntrance_Text_SageNoBadge, MSGBOX_DEFAULT
	release
	end

@ The unlock. R4: the sage's departure happens inside a fade, so nothing pops.
@ removeobject CO-SIGNS FLAG_TRINITY_J_TIN_GATE_SAGE_HIDE
@ (RemoveObjectEventByLocalIdAndMap FlagSets before despawning,
@ src/event_object_movement.c:1537-1545) -- intended: it is the same flag
@ ON_TRANSITION authors, so the two agree from this moment on.
EcruteakTinTowerEntrance_EventScript_SageBell::
	msgbox EcruteakTinTowerEntrance_Text_SageBell1, MSGBOX_DEFAULT
	playse SE_M_HEAL_BELL
	waitse
	msgbox EcruteakTinTowerEntrance_Text_SageBell2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_TRINITY_J_TIN_TOWER_OPEN
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_JOHTO_TTE_SAGE_LEFT
	fadescreen FADE_FROM_BLACK
	msgbox EcruteakTinTowerEntrance_Text_SagePass, MSGBOX_DEFAULT
	release
	end

EcruteakTinTowerEntrance_EventScript_SagePass::
	msgbox EcruteakTinTowerEntrance_Text_SagePass, MSGBOX_DEFAULT
	release
	end

EcruteakTinTowerEntrance_EventScript_WanderingSage::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_CLEAR_BELL, EcruteakTinTowerEntrance_EventScript_WanderingSageBell
	msgbox EcruteakTinTowerEntrance_Text_WanderingSage, MSGBOX_DEFAULT
	release
	end

EcruteakTinTowerEntrance_EventScript_WanderingSageBell::
	msgbox EcruteakTinTowerEntrance_Text_WanderingSageBell, MSGBOX_DEFAULT
	release
	end

EcruteakTinTowerEntrance_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakTinTowerEntrance_Text_Gramps, MSGBOX_DEFAULT
	release
	end

EcruteakTinTowerEntrance_Text_SageNoBadge:
	.string "The TIN TOWER is off limits to\n"
	.string "anyone who does not carry ECRUTEAK\l"
	.string "GYM's BADGE.\p"
	.string "I am sorry. You will have to\n"
	.string "leave.$"

EcruteakTinTowerEntrance_Text_SageMomentous:
	.string "A momentous thing has happened in\n"
	.string "this town, and I must ask you to\l"
	.string "turn back.\p"
	.string "The WISE TRIO say the TOWER will\n"
	.string "open to what soothes the soul.\p"
	.string "I confess I have never once known\n"
	.string "what they mean by it.$"

EcruteakTinTowerEntrance_Text_SageBell1:
	.string "Turn back, please. The TOWER is\n"
	.string "not for --\p"
	.string "...$"

EcruteakTinTowerEntrance_Text_SageBell2:
	.string "That sound.\p"
	.string "The CLEAR BELL. I have waited my\n"
	.string "whole life to hear it and I did not\l"
	.string "know it would sound like that.\p"
	.string "A bell answers the soul that rings\n"
	.string "it, {PLAYER}. That was your soul.\p"
	.string "Go up. Go up, and do not keep\n"
	.string "them waiting.$"

EcruteakTinTowerEntrance_Text_SagePass:
	.string "Please, go on through.$"

EcruteakTinTowerEntrance_Text_WanderingSage:
	.string "The TIN TOWER stands nine tiers\n"
	.string "high and has never once been\l"
	.string "repaired. It has never needed it.\p"
	.string "People walk out here at dusk just\n"
	.string "to look at it.$"

EcruteakTinTowerEntrance_Text_WanderingSageBell:
	.string "The TOWER shook this morning.\p"
	.string "Not the wind. Something has come\n"
	.string "back to the top of it.$"

EcruteakTinTowerEntrance_Text_Gramps:
	.string "Two towers. Two POKéMON.\p"
	.string "When one tower burned, both of\n"
	.string "them left us, and that is the whole\l"
	.string "of the story as I was told it.\p"
	.string "Everything else people say is\n"
	.string "people talking.$"
