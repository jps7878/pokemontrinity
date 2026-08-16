TeamRocketBaseB1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TeamRocketBaseB1F_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S7 -- TEAM ROCKET BASE B1F. Adapts pokecrystal
@ maps/TeamRocketBaseB1F.asm. THE ROCKET-POST PATTERN (R1-R5), canonical
@ implementation data/maps/SlowpokeWellB1F/scripts.inc.
@
@ R1. ONE flag for the whole base cast -- FLAG_TRINITY_J_BASE_CAST_HIDE covers
@ ten objects across THREE maps (B1F's two posts, B2F's three, B3F's four plus
@ the ROCKET LANCE has already beaten) and each of those maps' ON_TRANSITION
@ authors it from the same predicate, ARC == 4. GSC uses one event for exactly
@ this set (EVENT_TEAM_ROCKET_BASE_POPULATION), including the two shopkeepers
@ upstairs, and every member retires together, so one flag is correct (S4's C1
@ rule: check each member's lifecycle, not just the beat's).
@ NOTHING IN THE RAID removeobject's a member of this cast. That is deliberate:
@ removeobject FlagSets the object's flag (src/event_object_movement.c:
@ 1537-1545), and with a cast this size that co-sign would delete nine posts on
@ three floors the moment one of them was tidied away. The two execs and LANCE
@ therefore carry their own flags. R1's trap, avoided by construction.
@
@ LANCE IS NOT ON THIS FLOOR, in GSC or here. He goes down ahead of the player
@ and is next seen on B2F.
@
@ ---------------------------------------------------------------------------
@ TWO GSC BEATS DELIBERATELY SKIPPED (contract requires each skip logged)
@ ---------------------------------------------------------------------------
@ 1. THE FIVE SECURITY CAMERAS. GSC gives each PERSIAN statue a coord trigger
@    that teleports a shared grunt puppet to the player and fights TWO battles,
@    GRUNTM_20 then GRUNTM_21 -- the SAME two ids at all five cameras. Under
@    R3b a trainer id carries one permanent per-id defeated flag and can be
@    fought at most once per save, so a faithful port needs TEN further ids for
@    a beat the player meets five times. Cut. The statues stay as readable
@    bg_events, the master kill-switch stays, and the grunts' own dialogue
@    carries what the cameras were for.
@ 2. THE 22 EXPLODING-TRAP TILES. GSC arms them with BATTLETYPE_TRAP, which
@    makes the wild mon Selfdestruct on turn one and has no Emerald equivalent,
@    and it spends 22 event flags marking spent tiles. Cut. The WARP PANEL trap
@    survives untouched because M4a already wired it: (5,15) and (25,2) are a
@    bidirectional warp pair in map.json, so stepping on the panel in the
@    south-west still dumps the player back beside the entrance -- which is
@    precisely what SCIENTIST JED warns about, word for word from GSC.
@ ============================================================================
TeamRocketBaseB1F_OnTransition:
	goto_if_eq VAR_TRINITY_JOHTO_ARC, 4, TeamRocketBaseB1F_EventScript_ShowRaid
	setflag FLAG_TRINITY_J_BASE_CAST_HIDE
	end

@ Exact equality, not >=: the raid is the only writer of ARC 5, so "reachable at
@ ARC 4, gone at ARC 5" is the predicate ARC == 4 (S3's arc-window rule).
TeamRocketBaseB1F_EventScript_ShowRaid::
	clearflag FLAG_TRINITY_J_BASE_CAST_HIDE
	end

@ ============================================================================
@ R2. Both posts are ordinary sight-triggered TRAINER_TYPE_NORMAL trainers --
@ the M4a gym-trainer shape -- so PlayTrainerEncounterMusic's map-BGM swap is
@ correct for them; that swap is what a sight line is for (GYM PATTERN G3).
@ Neither cone can seal anything: the GRUNT looks east along row 4 from (2,4)
@ inside the six-wide west room, and JED looks west along row 12 from (18,12)
@ in the middle of an open floor.
@
@ Ids: TRAINER_ROCKET_GRUNT_M_3 from the pool, and TRAINER_JOHTO_ROCKET_SCI_JED
@ (1074) newly allocated. There is no Scientist trainer class in this build, so
@ the three ROCKET scientists take Class: Team Rocket -- which is also what
@ makes GetBattleBGM()'s Trinity guard hand them MUS_RG_VS_TRAINER, since the
@ exec branch is the contiguous range TRAINER_EXEC_PROTON..TRAINER_EXEC_ARCHER
@ (1050-1053) and 1074-1076 cannot enter it -- with Pic: Magma Grunt M so they
@ read differently from the Aqua-Grunt-pic grunts.
@ ============================================================================
TeamRocketBaseB1F_EventScript_Grunt::
	trainerbattle_single TRAINER_ROCKET_GRUNT_M_3, TeamRocketBaseB1F_Text_GruntSeen, TeamRocketBaseB1F_Text_GruntBeaten
	msgbox TeamRocketBaseB1F_Text_GruntAfterBattle, MSGBOX_AUTOCLOSE
	end

TeamRocketBaseB1F_EventScript_Jed::
	trainerbattle_single TRAINER_JOHTO_ROCKET_SCI_JED, TeamRocketBaseB1F_Text_JedSeen, TeamRocketBaseB1F_Text_JedBeaten
	msgbox TeamRocketBaseB1F_Text_JedAfterBattle, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ The five PERSIAN statues, at GSC's own tiles (24,1) (6,1) (24,5) (8,15)
@ (22,15) -- all five decode collision 1, and each one's single reading tile
@ ((24,2) (6,2) (24,6) (8,16) (22,16)) decodes collision 0 and is left clear of
@ objects. S5's I1 pin: a BG_EVENT_PLAYER_FACING_<DIR> on a collision-1 tile has
@ EXACTLY ONE reading tile, and reach_check cannot see it, so the tile has to be
@ decoded by hand and kept empty.
@
@ The switch at (19,11) is GSC's master kill-switch. With the cameras cut it no
@ longer disables anything, so it does the honest thing instead: it tells the
@ player what it was wired to, which is how they learn there were cameras at
@ all. Its reading tile (19,12) is clear.
@ The two bookshelves at (20,11) and (21,11) are BG_EVENT_PLAYER_FACING_ANY on
@ purpose: (21,12), the tile below the second one, holds M4a's GUARD SPEC ball,
@ so a north-facing bg_event there would be dead. FACING_ANY lets (22,11) read
@ it instead -- decoded collision 0.
@ NOTE ON THE TILES THEMSELVES: (19,11) (20,11) (21,11) decode MB_NORMAL at
@ collision 1, NOT MB_BOOKSHELF. The bookshelf behaviour is a HOENN tileset
@ affordance that M4a's Johto tilesets do not carry, so nothing here is
@ readable by walking into it -- the bg_events are the entire mechanism, which
@ is exactly why their reading tiles had to be decoded by hand.
@ ============================================================================
TeamRocketBaseB1F_EventScript_Statue::
	msgbox TeamRocketBaseB1F_Text_Statue, MSGBOX_SIGN
	end

@ Minor 11. The predicate is an ARC test, NOT the cast's visibility flag. The
@ switch is a bg_event with no object and no visibility of its own, so reading
@ FLAG_TRINITY_J_BASE_CAST_HIDE here would make a piece of scenery depend on a
@ flag whose single authoring site is this map's ON_TRANSITION -- the S1
@ ownership rule cuts both ways, and a reader outside the owning predicate is
@ how a flag quietly acquires a second meaning. ARC >= 5 is the state the line
@ is actually about.
TeamRocketBaseB1F_EventScript_SecretSwitch::
	lockall
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 5, TeamRocketBaseB1F_EventScript_SwitchDead
	msgbox TeamRocketBaseB1F_Text_SecretSwitch, MSGBOX_DEFAULT
	playse SE_PIN
	waitse
	releaseall
	end

TeamRocketBaseB1F_EventScript_SwitchDead::
	msgbox TeamRocketBaseB1F_Text_SwitchDead, MSGBOX_DEFAULT
	releaseall
	end

TeamRocketBaseB1F_EventScript_Oath::
	msgbox TeamRocketBaseB1F_Text_Oath, MSGBOX_SIGN
	end

TeamRocketBaseB1F_Text_GruntSeen:
	.string "Heheh. Feeling lucky?\p"
	.string "Go ahead. Take another step.\p"
	.string "We've got traps set in this floor,\n"
	.string "and panels that put you back at\l"
	.string "the door.$"

TeamRocketBaseB1F_Text_GruntBeaten:
	.string "Kaboom!$"

TeamRocketBaseB1F_Text_GruntAfterBattle:
	.string "I don't even know where the traps\n"
	.string "are planted.\p"
	.string "You'll just have to collect your\n"
	.string "courage and walk.$"

TeamRocketBaseB1F_Text_JedSeen:
	.string "This was once a ninja hideout.\p"
	.string "There are traps here to confound\n"
	.string "intruders like you.$"

TeamRocketBaseB1F_Text_JedBeaten:
	.string "I get it…$"

TeamRocketBaseB1F_Text_JedAfterBattle:
	.string "All right. I'll divulge a secret\n"
	.string "about our hideout.\p"
	.string "That thing on the floor up ahead\n"
	.string "is a warp panel.\p"
	.string "Step on it and you'll be warped\n"
	.string "back to the entrance.\p"
	.string "You'll do it at least twice.\n"
	.string "Everybody does.$"

TeamRocketBaseB1F_Text_Statue:
	.string "It's a PERSIAN statue…\p"
	.string "Its eyes are oddly shiny.$"

TeamRocketBaseB1F_Text_SecretSwitch:
	.string "A switch, hidden behind the\n"
	.string "shelving.\p"
	.string "{PLAYER} pressed it.\p"
	.string "Somewhere above, five sets of\n"
	.string "PERSIAN eyes stop watching.$"

TeamRocketBaseB1F_Text_SwitchDead:
	.string "The switch is turned off.\p"
	.string "Nothing on this floor is watching\n"
	.string "anything any more.$"

TeamRocketBaseB1F_Text_Oath:
	.string "TEAM ROCKET OATH\p"
	.string "Steal POKéMON for profit!\p"
	.string "Exploit POKéMON for profit!\p"
	.string "All POKéMON exist for the glory\n"
	.string "of TEAM ROCKET!$"
