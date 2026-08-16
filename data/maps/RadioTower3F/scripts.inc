@ ============================================================================
@ THE CARD KEY SHUTTER, decoded from data/layouts/RadioTower3F_Johto/map.bin.
@
@ THE CONVERTER'S BLOCK MAP (the pin S8 adds to the SETMETATILE DOOR PATTERN):
@ tools/johto_port/convert.py:97-107 writes every map cell as
@     metatile = 512 + 4*<GSC block id> + q,   q order [TL, TR, BL, BR]
@ with collision taken from pokecrystal's <tileset>_collision.asm row for that
@ block, same quadrant order. So a GSC `changeblock x,y,$NN` translates to four
@ setmetatiles with no guesswork: x-parity picks L/R, y-parity picks T/B.
@
@ Shipped state, this map:
@         x=14  x=15
@   y=2   672*  673*   = GSC block $28 (WALL WALL FLOOR WALL)  shutter, top
@   y=3   674   675*
@   y=4   676   677*   = GSC block $29 (FLOOR WALL FLOOR WALL) shutter, bottom
@   y=5   678   679*      (* = collision 1)
@ GSC opens them to $2a (WALL WALL FLOOR FLOOR) = 680-683 and $01 (FLOOR x4) =
@ 516-519 (RadioTower3F.asm:144-145). The three tiles whose COLLISION changes
@ are (15,3) (15,4) (15,5) -- the one-tile gap in the x=15 wall column that
@ joins the west floor to the 15-tile east strip and its (17,0) stair.
@
@ setmetatile never touches elevation (MapGridSetMetatileIdAt,
@ src/fieldmap.c:383-393) and every tile here decodes elevation 0 =
@ ELEVATION_TRANSITION, which IsElevationMismatchAt always accepts
@ (src/event_object_movement.c:9806-9822) -- so an opened tile is walkable with
@ no elevation work.
@
@ MEASURED: with the door open the whole tower opens. reach_check --dungeon
@ over 1F-5F goes from 357/474 with four sealed warps to 446/477 with NONE.
	.set METATILE_JohtoRadioTower_ShutterOpenTL,  680
	.set METATILE_JohtoRadioTower_ShutterOpenTR,  681
	.set METATILE_JohtoRadioTower_ShutterOpenBL,  682
	.set METATILE_JohtoRadioTower_ShutterOpenBR,  683
	.set METATILE_JohtoRadioTower_FloorTL,        516
	.set METATILE_JohtoRadioTower_FloorTR,        517
	.set METATILE_JohtoRadioTower_FloorBL,        518
	.set METATILE_JohtoRadioTower_FloorBR,        519
@ ============================================================================

RadioTower3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RadioTower3F_OnTransition
	.byte 0

@ Trinity M4b S4 -- RADIO TOWER 3F, pre-takeover. S8 FLIP CONTRACT: shared
@ predicate in data/maps/RadioTower1F/scripts.inc -- visible iff
@ VAR_TRINITY_JOHTO_ARC != 6. All three objects carry
@ FLAG_TRINITY_J_RADIO_TOWER_PRE_HIDE.
@ DECODE NOTE: this floor reads as TWO components to reach_check.py, and that
@ is PRE-EXISTING and object-independent (identical with zero objects placed).
@ The tower has two staircases per floor and the halves join through 4F, which
@ a single-map tool cannot see -- the SPROUT TOWER limitation pinned in the S3
@ ledger. The CARD KEY shutter that GSC opens at (14,2) is S8's.
RadioTower3F_OnTransition:
	call RadioTower_EventScript_SetPreTakeoverVisibility
	call RadioTower_EventScript_SetTakeoverVisibility
	call RadioTower3F_EventScript_AuthorShutter
	end

@ D2. The shipped map.bin has the shutter SHUT, so the authoring direction is
@ OPEN. No DrawWholeMapView -- ON_TRANSITION runs before the map is drawn.
RadioTower3F_EventScript_AuthorShutter::
	goto_if_set FLAG_TRINITY_J_CARD_KEY_USED, RadioTower3F_EventScript_OpenShutterTiles
	return

RadioTower3F_EventScript_OpenShutterTiles::
	setmetatile 14, 2, METATILE_JohtoRadioTower_ShutterOpenTL, TRUE
	setmetatile 15, 2, METATILE_JohtoRadioTower_ShutterOpenTR, TRUE
	setmetatile 14, 3, METATILE_JohtoRadioTower_ShutterOpenBL, FALSE
	setmetatile 15, 3, METATILE_JohtoRadioTower_ShutterOpenBR, FALSE
	setmetatile 14, 4, METATILE_JohtoRadioTower_FloorTL, FALSE
	setmetatile 15, 4, METATILE_JohtoRadioTower_FloorTR, FALSE
	setmetatile 14, 5, METATILE_JohtoRadioTower_FloorBL, FALSE
	setmetatile 15, 5, METATILE_JohtoRadioTower_FloorBR, FALSE
	return

@ ============================================================================
@ D1/D3/D4/D5 -- THE CARD KEY SLOT.
@
@ D1  A bg_event on the collision-1 shutter head (14,2),
@     BG_EVENT_PLAYER_FACING_NORTH, read from (14,3) -- its ONLY reading tile
@     (S5's I1 rule: a facing bg_event on a collision-1 tile has exactly one,
@     and reach_check cannot see it). (14,3) decodes collision 0 elevation 3 and
@     is kept clear of objects. The warp the door leads to, 3F (17,0), already
@     exists in map.json -- warps cannot be created by script; what gates a warp
@     is the COLLISION of the block in front of it.
@ D3  The opening script repeats ON_TRANSITION's eight setmetatiles and THEN
@     calls DrawWholeMapView, which ON_TRANSITION does not need.
@ D4  FLAG_TRINITY_J_CARD_KEY_USED is the door's ONLY state and this script's
@     FIRST test, because a bg_event on a now-walkable tile is still triggerable
@     by pressing A while facing it. FLAG_TRINITY_J_CARD_KEY is an INPUT.
@ D5  Both whole GSC blocks are authored -- eight tiles, never three.
@ ============================================================================
RadioTower3F_EventScript_CardKeySlot::
	lockall
	goto_if_set FLAG_TRINITY_J_CARD_KEY_USED, RadioTower3F_EventScript_ShutterAlreadyOpen
	goto_if_unset FLAG_TRINITY_J_CARD_KEY, RadioTower3F_EventScript_NoCardKey
	msgbox RadioTower3F_Text_InsertedCardKey, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	call RadioTower3F_EventScript_OpenShutterTiles
	special DrawWholeMapView
	waitse
	setflag FLAG_TRINITY_J_CARD_KEY_USED
	releaseall
	end

RadioTower3F_EventScript_NoCardKey::
	msgbox RadioTower3F_Text_CardKeySlot, MSGBOX_DEFAULT
	releaseall
	end

RadioTower3F_EventScript_ShutterAlreadyOpen::
	msgbox RadioTower3F_Text_ShutterOpen, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@ R2 posts. (5,1) mt531 facing RIGHT sight 2 · (6,2) mt568 facing DOWN sight 3 ·
@ (9,6) mt517 facing UP sight 5 (the SCIENTIST) -- all in the WEST half, all
@ GSC tiles (RadioTower3F.asm:348-351), all collision 0 / elevation 3 /
@ MB_NORMAL. (16,6) mt516 is in the EAST strip and therefore only exists as an
@ obstacle AFTER the card key -- which is precisely why GSC gives that man the
@ line "Why did the shutter open?".
@ ============================================================================
RadioTower3F_EventScript_GruntA::
	trainerbattle_single TRAINER_JOHTO_ROCKET_RT3F_A, RadioTower3F_Text_GruntASeen, RadioTower3F_Text_GruntABeaten
	msgbox RadioTower3F_Text_GruntAAfter, MSGBOX_AUTOCLOSE
	end

RadioTower3F_EventScript_GruntB::
	trainerbattle_single TRAINER_JOHTO_ROCKET_RT3F_B, RadioTower3F_Text_GruntBSeen, RadioTower3F_Text_GruntBBeaten
	msgbox RadioTower3F_Text_GruntBAfter, MSGBOX_AUTOCLOSE
	end

RadioTower3F_EventScript_GruntC::
	trainerbattle_single TRAINER_JOHTO_ROCKET_RT3F_C, RadioTower3F_Text_GruntCSeen, RadioTower3F_Text_GruntCBeaten
	msgbox RadioTower3F_Text_GruntCAfter, MSGBOX_AUTOCLOSE
	end

RadioTower3F_EventScript_Marc::
	trainerbattle_single TRAINER_JOHTO_ROCKET_SCI_MARC, RadioTower3F_Text_MarcSeen, RadioTower3F_Text_MarcBeaten
	msgbox RadioTower3F_Text_MarcAfter, MSGBOX_AUTOCLOSE
	end

@ He rides S4's ARC != 6 flag, so he is NOT on the floor during the occupation
@ -- which is why his second state is keyed on ARC >= 7 (the morning after) and
@ not on ARC == 6 (GSC's, where he never leaves). Writing the guard as == 6
@ would have produced a branch no save can reach.
RadioTower3F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 7, RadioTower3F_EventScript_GymGuideAfter
	msgbox RadioTower3F_Text_GymGuide, MSGBOX_DEFAULT
	release
	end

RadioTower3F_EventScript_GymGuideAfter::
	msgbox RadioTower3F_Text_GymGuideAfter, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ GSC gives her the post-clear TM SUNNY DAY (RadioTower3F.asm:65-74). GYM
@ PATTERN G2 applies to the gift: FLAG_TRINITY_J_RADIO_TM11 is the award guard
@ and the retry path is her own re-talk.
@
@ S7's C1 RULE -- "the award guard must own the GIVER'S VISIBILITY as well as
@ the giver's script" -- is SATISFIED BY HER PREDICATE, not by an extra clause,
@ and that is worth writing down rather than leaving to be re-derived. She rides
@ S4's FLAG_TRINITY_J_RADIO_TOWER_PRE_HIDE, i.e. visible iff ARC != 6. The award
@ becomes available at ARC 7 and the arc is monotonic, so from the moment she
@ can offer the TM she can never disappear again. A player with a full bag walks
@ back to the same woman on the same tile.
@ ============================================================================
RadioTower3F_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_lt VAR_TRINITY_JOHTO_ARC, 6, RadioTower3F_EventScript_CooltrainerFIdle
	goto_if_eq VAR_TRINITY_JOHTO_ARC, 6, RadioTower3F_EventScript_CooltrainerFRockets
	goto_if_set FLAG_TRINITY_J_RADIO_TM11, RadioTower3F_EventScript_CooltrainerFThanked
	msgbox RadioTower3F_Text_CooltrainerFHero, MSGBOX_DEFAULT
	giveitem ITEM_TM_SUNNY_DAY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_J_RADIO_TM11
	msgbox RadioTower3F_Text_ExplainSunnyDay, MSGBOX_DEFAULT
	release
	end

RadioTower3F_EventScript_CooltrainerFIdle::
	msgbox RadioTower3F_Text_CooltrainerF, MSGBOX_DEFAULT
	release
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE -- at ARC == 6 this object is hidden by
@ FLAG_TRINITY_J_RADIO_TOWER_PRE_HIDE, so the branch can never be entered. It is
@ written because the guard has to test SOMETHING at ARC 6 and a fall-through
@ into the award path would be the wrong answer.
RadioTower3F_EventScript_CooltrainerFRockets::
	msgbox RadioTower3F_Text_CooltrainerFRockets, MSGBOX_DEFAULT
	release
	end

RadioTower3F_EventScript_CooltrainerFThanked::
	msgbox RadioTower3F_Text_CooltrainerFThanked, MSGBOX_DEFAULT
	release
	end

RadioTower3F_EventScript_SuperNerd::
	msgbox RadioTower3F_Text_SuperNerd, MSGBOX_NPC
	end

RadioTower3F_EventScript_PersonnelSign::
	msgbox RadioTower3F_Text_PersonnelSign, MSGBOX_SIGN
	end

RadioTower3F_EventScript_PokemonMusicSign::
	msgbox RadioTower3F_Text_PokemonMusicSign, MSGBOX_SIGN
	end

@ GSC RadioTower3FGymGuideText (the non-Rocket branch).
RadioTower3F_Text_GymGuide:
	.string "We run 24 hours a day to\n"
	.string "broadcast entertaining\l"
	.string "programs.\p"
	.string "I'll do my best to run around\n"
	.string "the clock too!$"

@ GSC gives her no pre-takeover line at all -- every one of hers is occupation
@ or post-rescue -- so this is written for Trinity.
RadioTower3F_Text_CooltrainerF:
	.string "PERSONNEL, third floor. If you\n"
	.string "work in this building, I have\l"
	.string "your file.\p"
	.string "Do you know how many people it\n"
	.string "takes to keep one radio signal\l"
	.string "on the air?\p"
	.string "Neither does anyone else. Only\n"
	.string "me.$"

@ GSC RadioTower3FSuperNerdText.
RadioTower3F_Text_SuperNerd:
	.string "We have recordings of the cries\n"
	.string "of all POKéMON that have been\l"
	.string "found.\p"
	.string "We must have about 200 kinds.\p"
	.string "There are a few on the shelf\n"
	.string "that nobody has ever matched to\l"
	.string "a POKéMON.\p"
	.string "Those ones I keep at the back.$"

RadioTower3F_Text_PersonnelSign:
	.string "3F PERSONNEL$"

RadioTower3F_Text_PokemonMusicSign:
	.string "POKéMON MUSIC with\nHost DJ BEN$"

@ ============================================================================
@ Trinity M4b S8 text.
@ ============================================================================
RadioTower3F_Text_CardKeySlot:
	.string "It's a CARD KEY slot.\p"
	.string "The shutter above it doesn't\n"
	.string "move.$"

RadioTower3F_Text_InsertedCardKey:
	.string "It's a CARD KEY slot.\p"
	.string "{PLAYER} slid the DIRECTOR's\n"
	.string "CARD KEY into the slot.$"

RadioTower3F_Text_ShutterOpen:
	.string "It's a CARD KEY slot.\p"
	.string "The shutter is already up.$"

RadioTower3F_Text_GymGuideAfter:
	.string "To a trainer, POKéMON are\n"
	.string "partners. Family, even.\p"
	.string "And that lot wanted to point a\n"
	.string "transmitter at them.\p"
	.string "I ran up and down these stairs\n"
	.string "all morning and couldn't do a\l"
	.string "thing about it.\p"
	.string "You went up them once.$"

RadioTower3F_Text_GruntASeen:
	.string "Orders are orders.\p"
	.string "Anyone on the stairs gets put\n"
	.string "back down them.$"

RadioTower3F_Text_GruntABeaten:
	.string "Off the stairs -- me?$"

RadioTower3F_Text_GruntAAfter:
	.string "There are two more floors above\n"
	.string "this one, and the boss is on\l"
	.string "the top of them.\p"
	.string "Good luck. I mean that badly.$"

RadioTower3F_Text_GruntBSeen:
	.string "It feels good, ordering POKéMON\n"
	.string "to do crimes.\p"
	.string "They never once ask why.$"

RadioTower3F_Text_GruntBBeaten:
	.string "You're kidding!$"

RadioTower3F_Text_GruntBAfter:
	.string "I hate losing.\p"
	.string "I hate useless POKéMON more.$"

RadioTower3F_Text_GruntCSeen:
	.string "Why did the shutter open?\p"
	.string "That shutter has ONE key and\n"
	.string "the DIRECTOR is tied up in a\l"
	.string "warehouse.\p"
	.string "…Did you have something to do\n"
	.string "with this?$"

RadioTower3F_Text_GruntCBeaten:
	.string "I'm done for!$"

RadioTower3F_Text_GruntCAfter:
	.string "You got past our men in the\n"
	.string "UNDERGROUND?\p"
	.string "How? There are eleven doors\n"
	.string "down there and three switches!$"

RadioTower3F_Text_MarcSeen:
	.string "An unknown child, wandering\n"
	.string "around up here.\p"
	.string "Who are you supposed to be?$"

RadioTower3F_Text_MarcBeaten:
	.string "Tch. I took you too lightly.$"

RadioTower3F_Text_MarcAfter:
	.string "Bwahaha…\p"
	.string "It doesn't matter. From this\n"
	.string "room I can push a signal as\l"
	.string "strong as I like, as far as I\l"
	.string "like.\p"
	.string "Strong enough to be heard from\n"
	.string "another region entirely.$"

RadioTower3F_Text_CooltrainerFRockets:
	.string "The TEAM ROCKET boss has locked\n"
	.string "himself into STUDIO 1.\p"
	.string "The DIRECTOR could open it --\n"
	.string "but they've taken him too.\p"
	.string "Please. Find him.$"

RadioTower3F_Text_CooltrainerFHero:
	.string "Thank you! You're my hero!\p"
	.string "I keep the personnel files, so\n"
	.string "I'm the only one who knows what\l"
	.string "was in this building today.\p"
	.string "Here. A token, from PERSONNEL.$"

RadioTower3F_Text_ExplainSunnyDay:
	.string "That's TM11. SUNNY DAY.\p"
	.string "It calls up hard sunlight and\n"
	.string "leaves it there for a while.\p"
	.string "Fire moves love it. Water moves\n"
	.string "hate it.\p"
	.string "Weather is just another kind of\n"
	.string "broadcast, if you think about\l"
	.string "it.$"

RadioTower3F_Text_CooltrainerFThanked:
	.string "You were simply marvellous.\p"
	.string "I'm putting today in the files\n"
	.string "under your name.$"
