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
