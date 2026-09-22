@ ============================================================================
@ M4b S11 -- the INDIGO PLATEAU, outside.
@
@ THIS MAP WAS WALLED OFF FROM ROUTE 23 AND NOBODY COULD SEE IT. Its south
@ stairway -- (10..12, 14/16/18), the nine tiles between the ROUTE 23 border and
@ the plaza -- carried behaviour byte 0x2A, which is MB_ROCK_STAIRS in
@ pokefirered and MB_SEAWEED_NO_SURFACING (surfable deep water) here, because M2
@ copied the FireRed metatile_attributes.bin verbatim and the two decomps'
@ behaviour enums diverge. Measured: from ROUTE 23 (18,28) --no-surf reached 219
@ tiles and NOT (11,0); with SURF, 222 and it did. The league approach was a
@ staircase you had to swim. tools/kanto_port/fix_behaviors.py restores the byte
@ region-wide (31 entries over 10 Kanto-exclusive tilesets, behaviour byte only,
@ zero art files touched); after it, the same fill reaches (11,0) on foot.
@
@ The Center door (11,6) is MB_ANIMATED_DOOR at collision 1 -- a WALK-INTO door,
@ entered from (11,7) via TryDoorWarp rather than by standing on it. Johto's
@ converted doors are collision 0, so this idiom is new to the tree; reach_check
@ learned it in this slice or every Plateau number would read SEALED.
@
@ The giant PLATEAU lettering at (8,7)/(8,10)/(8,13)/(14,7)/(14,10)/(14,13) was
@ MB_INDIGO_PLATEAU_SIGN_1/2 in FireRed and MB_SECRET_BASE_SPOT_* here -- facing
@ one and pressing A offered to dig a Secret Base. fix_behaviors makes them plain
@ wall, and the readable sign is the bg_event below.
@
@ FIX ROUND 1 (review M6): the sign bg_event originally sat at (10,13), a
@ collision-0 walkable tile in the SOUTH STAIRWAY -- players walked straight
@ over it, not up to it, so it never read. Decoded, (10,13) is METATILE_ID
@ (blockdata) col 0 / elev 3 / MB_NORMAL -- confirmed no reading tile. Moved to
@ (10,6): collision 1 / elevation 0 (ELEVATION_TRANSITION) / MB_NORMAL, the
@ wall panel immediately WEST of the Center's own door (11,6), with (10,7)
@ (col 0, elev 3) walkable immediately south of it -- a player standing on the
@ approach side, having just climbed the stairway, faces north and reads it.
@ (12,6)/(12,7) decode identically and would work as well; (10,6) was chosen to
@ keep the sign's original x-anchor. Not to be confused with the PLATEAU
@ lettering above: (10,6) is metatile 795, not one of the 671/751 letter tiles.
@ ============================================================================

IndigoPlateau_Exterior_MapScripts::
	.byte 0

@ GSC's own INDIGO PLATEAU sign (pokecrystal/maps/Route23.asm).
IndigoPlateau_Exterior_EventScript_Sign::
	msgbox IndigoPlateau_Exterior_Text_Sign, MSGBOX_SIGN
	end

IndigoPlateau_Exterior_EventScript_Spectator::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_LEAGUE_CLEARED, IndigoPlateau_Exterior_EventScript_SpectatorAfter
	msgbox IndigoPlateau_Exterior_Text_Spectator, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_Exterior_EventScript_SpectatorAfter::
	msgbox IndigoPlateau_Exterior_Text_SpectatorAfter, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ Trinity M7b Task 16 (finding #10) -- THE PLATEAU CORDON.
@
@ The founder's dictate was "station guards blocking the Kanto-side exit so
@ the only open direction is left, into the league". Two measurements taken
@ at Task 16 decided how much of that this map can carry.
@
@ (1) THE STAIRWAY IS NOT THE KANTO EXIT. It drops into ROUTE 23's NORTH
@ component -- 222 tiles, y 0..32, with SURF and without -- whose only other
@ door is (18,28) -> VICTORY ROAD 2F, the corridor the league runner came up
@ through. ROUTE 23's south half, and KANTO past it, are reachable only
@ through KantoVictoryRoad_1F (20,10), which Task 16 gates on
@ FLAG_TRINITY_K_ARRIVED (see that map's scripts.inc for the full
@ measurement). So the seal the founder asked for exists; it just does not
@ live on this map.
@
@ (2) SEALING THIS STAIRWAY WOULD TRAP THE PLAYER, because it is also the
@ only way back to JOHTO. reach_check with (10,13)/(11,13)/(12,13) all
@ blocked: from the CENTER door's approach tile (11,7) reach falls 66 -> 45
@ and (11,19) is NOT reached; from the ROUTE 23 border tile (11,19) reach is
@ 18 -- the stairway alone -- and (11,7) is NOT reached. This map is
@ "allow_escaping": false, so ESCAPE ROPE and DIG are out; FLY's picker is
@ the HOENN region map (finding #6b); TELEPORT returns to lastHealLocation,
@ which the CENTER's own ON_TRANSITION has just set to
@ HEAL_LOCATION_INDIGO_PLATEAU. An under-levelled Act II player would be
@ stuck on the PLATEAU with a MART and a nurse and no way to train.
@
@ So the cordon is INFORMATION, not a seal: two officers on the staircase
@ head's two landing tiles, (10,13) and (12,13) -- decoded col 0 / elev 3 /
@ MB_NORMAL, metatiles 733 and 735, the white stone landing the art draws --
@ costing exactly their own two tiles (reach 66 -> 64, nothing sealed), with
@ (11,13) left open between them for the player to walk down the middle.
@ Because (9,13) and (13,13) are balustrade walls (col 1) and y=13 is
@ walkable only at x 10/11/12 plus three plaza pockets with no y=14
@ neighbour, (11,13) is FORCED -- the same property ROUTE 26's league gate
@ relies on -- so one coord_event there cannot be walked around.
@
@ THE NOTICE IS SOUTHBOUND-ONLY. A coord_event fires on entry from either
@ side, and the ARRIVING league runner walks NORTH onto (11,13) off the
@ stairs; firing a "KANTO is closed" line at someone walking INTO the
@ plateau would be nonsense. GetPlayerFacingDirection() is reliable inside a
@ coord_event -- movement sets facing to the direction of travel and
@ TryStartCoordEventScript runs on the same frame the step completes; the
@ full argument is in ViridianCity/scripts.inc's GymDoorRefuseBounce
@ comment. Facing SOUTH == walked down from (11,12) == leaving.
@
@ NO STEP-BACK and NO LATCH. No step-back because nothing is refused: the
@ player may leave, and is only being told what is down there. No latch
@ because M7 has one flag and one saved var left and both are spoken for --
@ so the notice re-fires on every southbound crossing, exactly the "fires on
@ every crossing" idiom ROUTE 26's league gate and ROUTE 28's KantoGateCheck
@ both use (VAR_TEMP_1 is never written on this map, and
@ ClearTempFieldEventData resets it on every map load).
@
@ READ-ONLY: nothing here writes FLAG_TRINITY_K_ARRIVED, any badge flag or
@ any story var. G7 discipline holds.
@ ============================================================================
IndigoPlateau_Exterior_EventScript_KantoRoadNotice::
	goto_if_set FLAG_TRINITY_K_ARRIVED, IndigoPlateau_Exterior_EventScript_KantoRoadOpen
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_ne VAR_RESULT, DIR_SOUTH, IndigoPlateau_Exterior_EventScript_KantoRoadOpen
	lockall
	msgbox IndigoPlateau_Exterior_Text_KantoRoadClosed, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

@ INTENTIONALLY EMPTY / DEFENSIVE, the exact shape of
@ Route26_EventScript_LeagueGateOpen: the trigger still fires on every
@ crossing (that is what makes the notice reliable), and this branch is what
@ makes an Act III crossing -- and every northbound arrival -- free.
IndigoPlateau_Exterior_EventScript_KantoRoadOpen::
	end

IndigoPlateau_Exterior_EventScript_GuardWest::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_K_ARRIVED, IndigoPlateau_Exterior_EventScript_GuardWestOpen
	msgbox IndigoPlateau_Exterior_Text_GuardWest, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_Exterior_EventScript_GuardWestOpen::
	msgbox IndigoPlateau_Exterior_Text_GuardWestOpen, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_Exterior_EventScript_GuardEast::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_K_ARRIVED, IndigoPlateau_Exterior_EventScript_GuardEastOpen
	msgbox IndigoPlateau_Exterior_Text_GuardEast, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_Exterior_EventScript_GuardEastOpen::
	msgbox IndigoPlateau_Exterior_Text_GuardEastOpen, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_Exterior_Text_Sign:
	.string "INDIGO PLATEAU\p"
	.string "The Ultimate Goal for TRAINERS!\p"
	.string "POKéMON LEAGUE HQ$"

IndigoPlateau_Exterior_Text_Spectator:
	.string "I came up the road behind you.\n"
	.string "Took me two days.\p"
	.string "I'm not challenging anything. I\n"
	.string "just wanted to stand here once.\p"
	.string "They say the CHAMPION is a dragon\n"
	.string "master. They say he doesn't lose.$"

IndigoPlateau_Exterior_Text_SpectatorAfter:
	.string "They're already changing the\n"
	.string "boards inside.\p"
	.string "I was standing right here when\n"
	.string "you went in.\p"
	.string "Two days up that road, and I got\n"
	.string "the best seat in JOHTO.$"

IndigoPlateau_Exterior_Text_KantoRoadClosed:
	.string "OFFICER: Heading back down?\p"
	.string "Mind that ROUTE 23 ends at VICTORY\n"
	.string "ROAD while this tournament runs.\l"
	.string "The KANTO half of the road is\l"
	.string "closed.\p"
	.string "The LEAGUE is the other way.$"

IndigoPlateau_Exterior_Text_GuardWest:
	.string "LEAGUE reception is through those\n"
	.string "doors. The desk counts your\l"
	.string "BADGES, not your reputation.\p"
	.string "Nothing else up here is open\n"
	.string "until the tournament is settled.$"

IndigoPlateau_Exterior_Text_GuardWestOpen:
	.string "Reception's through those doors.\p"
	.string "And the road down is clear now --\n"
	.string "ROUTE 23 all the way to KANTO.$"

IndigoPlateau_Exterior_Text_GuardEast:
	.string "That stairway drops to ROUTE 23.\p"
	.string "It runs back to VICTORY ROAD and\n"
	.string "no further. The KANTO half of the\l"
	.string "road is closed while this LEAGUE\l"
	.string "is running.\p"
	.string "Go home the way you came, or go\n"
	.string "in and win.$"

IndigoPlateau_Exterior_Text_GuardEastOpen:
	.string "Stairway drops to ROUTE 23.\p"
	.string "The KANTO road's open to you now.\n"
	.string "Mind the checkpoints on the way\l"
	.string "down -- they still count BADGES.$"
