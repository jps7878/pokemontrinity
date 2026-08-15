EcruteakCity_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S5 -- ECRUTEAK CITY.
@
@ CRITICAL M4a DEFECT FIXED HERE. Object #4, the LASS, stood on (3,9) -- GSC's
@ own tile (EcruteakCity.asm:295) -- and in THIS port that tile is a cut vertex
@ that sealed the BURNED TOWER off from the entire city, i.e. from the whole S5
@ chapter, the FOGBADGE and the legendary arc.
@ DECODE: the only walk route from the plaza to the tower door at (5,5) is
@   (3,12) (3,11) (3,10) (3,9) (4,9) (5,9) (6,9) (6,8) (6,7) (5,7) (5,6) (5,5)
@ and EVERY tile of it is one tile wide. (4,10) and (5,10) decode MB_JUMP_SOUTH
@ and (8,10) MB_JUMP_SOUTHEAST, but all three land on row 11, which is collision
@ 1 at x=4..9, so no ledge hop offers a second way in or out. (2,10), (4,8) and
@ (7,6) are collision 1.
@ EVIDENCE (reach_check.py, per-entry table -- the union fill hides this because
@ it seeds from the tower door itself):
@   objects placed, from (0,18)->ROUTE_38 gate: 434 tiles,
@     SEALED OFF from here: (5,5)->MAP_BURNED_TOWER_1F   [and from all 9 other
@     city doors]
@   zero objects, same seed: 457 tiles, (5,5) reachable.
@ FIX: the LASS moved to (2,12), MOVEMENT_TYPE_FACE_UP -- the mouth of the tower
@ lane, looking up it. (2,11) stays reachable via (3,11), so she costs one tile.
@ This is the S3 ledger rule in action: decode the tile in front of every warp
@ before copying a GSC guard post, and expect to move it.
@ ============================================================================

EcruteakCity_EventScript_Gramps1::
	msgbox EcruteakCity_Text_Gramps1, MSGBOX_NPC
	end

EcruteakCity_EventScript_Gramps2::
	msgbox EcruteakCity_Text_Gramps2, MSGBOX_NPC
	end

EcruteakCity_EventScript_Lass1::
	msgbox EcruteakCity_Text_Lass1, MSGBOX_NPC
	end

EcruteakCity_EventScript_Lass2::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_BEASTS_AWAKENED, EcruteakCity_EventScript_Lass2Awake
	msgbox EcruteakCity_Text_Lass2, MSGBOX_DEFAULT
	release
	end

EcruteakCity_EventScript_Lass2Awake::
	msgbox EcruteakCity_Text_Lass2Awake, MSGBOX_DEFAULT
	release
	end

EcruteakCity_EventScript_Fisher::
	msgbox EcruteakCity_Text_Fisher, MSGBOX_NPC
	end

@ ============================================================================
@ TRAINER_SUMEET, on the BURNED TOWER approach. The M1 friend-reward mechanic,
@ copied clause for clause from GraniteCave_1F_EventScript_Harjot
@ (data/maps/GraniteCave_1F/scripts.inc:40-72) with its MULTI_FAMILY_REWARD
@ multichoice and its own one-time flag.
@
@ TILE (7,7), decoded collision 0 elevation 3. NO-SEAL: its only walkable
@ neighbours are (6,7) and (7,8) ((8,7) and (7,6) are collision 1), and (6,8)
@ provides a full parallel link between those same two tiles, so occupying (7,7)
@ costs exactly one tile -- its own. Every other tile on this approach is a cut
@ vertex (see the header block above) and is left clear; the (2,7)/(2,6)/(3,6)
@ nook stays open.
@
@ ONE DELIBERATE REFINEMENT OVER THE M1 ORIGINAL: NO_MUSIC. HARJOT and PRABHJIT
@ predate the GYM PATTERN's G3, which is written as a GENERAL rule -- any
@ talk-triggered `trainerbattle_*` passes NO_MUSIC, because
@ PlayTrainerEncounterMusic is not a jingle but a full map-BGM swap
@ (src/battle_setup.c:1441-1499) and that belongs to a sight line, not a
@ conversation. SUMEET is `Music: Hiker`; without this, walking up to him would
@ replace ECRUTEAK's theme for the whole exchange. The mechanic is verbatim; the
@ music clause is the ledger's, and it is mandatory for S3-S9.
@ ============================================================================
EcruteakCity_EventScript_Sumeet::
	trainerbattle_single TRAINER_SUMEET, EcruteakCity_Text_SumeetIntro, EcruteakCity_Text_SumeetDefeat, EcruteakCity_EventScript_SumeetReward, NO_MUSIC
	goto_if_unset FLAG_RECEIVED_REWARD_SUMEET, EcruteakCity_EventScript_SumeetReward
	msgbox EcruteakCity_Text_SumeetPostReward, MSGBOX_DEFAULT
	release
	end

EcruteakCity_EventScript_SumeetReward::
	msgbox EcruteakCity_Text_SumeetRewardOffer, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_FAMILY_REWARD, FALSE
	switch VAR_RESULT
	case 0, EcruteakCity_EventScript_SumeetMasterBalls
	case 1, EcruteakCity_EventScript_SumeetRareCandies
	case 2, EcruteakCity_EventScript_SumeetCancel
	case MULTI_B_PRESSED, EcruteakCity_EventScript_SumeetCancel
	end

EcruteakCity_EventScript_SumeetMasterBalls::
	giveitem ITEM_MASTER_BALL, 2
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_REWARD_SUMEET
	msgbox EcruteakCity_Text_SumeetPostReward, MSGBOX_DEFAULT
	release
	end

EcruteakCity_EventScript_SumeetRareCandies::
	giveitem ITEM_RARE_CANDY, 99
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_REWARD_SUMEET
	msgbox EcruteakCity_Text_SumeetPostReward, MSGBOX_DEFAULT
	release
	end

EcruteakCity_EventScript_SumeetCancel::
	release
	end

EcruteakCity_EventScript_Youngster::
	msgbox EcruteakCity_Text_Youngster, MSGBOX_NPC
	end

EcruteakCity_EventScript_Sign::
	msgbox EcruteakCity_Text_Sign, MSGBOX_SIGN
	end

EcruteakCity_EventScript_TinTowerSign::
	msgbox EcruteakCity_Text_TinTowerSign, MSGBOX_SIGN
	end

EcruteakCity_EventScript_EcruteakGymSign::
	msgbox EcruteakCity_Text_EcruteakGymSign, MSGBOX_SIGN
	end

EcruteakCity_EventScript_EcruteakDanceTheaterSign::
	msgbox EcruteakCity_Text_EcruteakDanceTheaterSign, MSGBOX_SIGN
	end

EcruteakCity_EventScript_BurnedTowerSign::
	msgbox EcruteakCity_Text_BurnedTowerSign, MSGBOX_SIGN
	end

EcruteakCity_Text_Gramps1:
	.string "ECRUTEAK used to\nhave two towers:\pone each in the\neast and west.$"

EcruteakCity_Text_Gramps2:
	.string "Ah, child.\nHave you learned\pto dance like the\nKIMONO GIRLS?\pIf you go to their\nDANCE THEATER, an\podd old man will\ngive you something\lnice, I hear.$"

EcruteakCity_Text_Lass1:
	.string "I'm going to prac-\ntice at the DANCE\pTHEATER. Care to\njoin me?$"

@ GSC EcruteakCityLass2Text -- replaces an M4a filler line. She stands at the
@ mouth of the BURNED TOWER lane, so the tower is what she talks about.
EcruteakCity_Text_Lass2:
	.string "The tower that used to be here…\p"
	.string "My grandma told me it used to be\n"
	.string "much taller.$"

@ GSC EcruteakCityLass2Text_ReleasedBeasts.
EcruteakCity_Text_Lass2Awake:
	.string "Three big POKéMON ran off in\n"
	.string "different directions!\p"
	.string "What were they? Nobody will tell me\n"
	.string "anything.$"

@ GSC EcruteakCityFisherText -- replaces an M4a filler line, and seeds S6's
@ OLIVINE LIGHTHOUSE hook so it is live before S6 arrives.
EcruteakCity_Text_Fisher:
	.string "I heard a rumor about the OLIVINE\n"
	.string "LIGHTHOUSE.\p"
	.string "The POKéMON that serves as its\n"
	.string "beacon has fallen ill.\p"
	.string "Sounds like they're in real trouble\n"
	.string "over there.$"

EcruteakCity_Text_SumeetIntro:
	.string "SUMEET: Fifteen years I've kept a\n"
	.string "fire lit within sight of a tower\l"
	.string "that fire brought down.\p"
	.string "People call it disrespectful. I call\n"
	.string "it keeping watch.\p"
	.string "You're the one they're all shouting\n"
	.string "about. Show me the shouting was\l"
	.string "warranted.$"

EcruteakCity_Text_SumeetDefeat:
	.string "Ha! You put my own fire out and\n"
	.string "never once broke stride.$"

EcruteakCity_Text_SumeetRewardOffer:
	.string "SUMEET: You've earned something off\n"
	.string "me. Choose wisely -- I only carry so\l"
	.string "much up this hill.$"

EcruteakCity_Text_SumeetPostReward:
	.string "SUMEET: Go on up. Whatever sleeps\n"
	.string "under that tower is not going to\l"
	.string "wait forever.$"

EcruteakCity_Text_Youngster:
	.string "I hear POKéMON are\nrampaging at the\pLAKE OF RAGE. I'd\nlike to see that.$"

EcruteakCity_Text_Sign:
	.string "ECRUTEAK CITY\nA Historical City\pWhere the Past\nMeets the Present$"

EcruteakCity_Text_TinTowerSign:
	.string "TIN TOWER\pA legendary POKé-\nMON is said to\lroost here.$"

EcruteakCity_Text_EcruteakGymSign:
	.string "ECRUTEAK CITY\nPOKéMON GYM\lLEADER: MORTY\pThe Mystic Seer of\nthe Future$"

EcruteakCity_Text_EcruteakDanceTheaterSign:
	.string "ECRUTEAK DANCE\nTHEATER$"

EcruteakCity_Text_BurnedTowerSign:
	.string "BURNED TOWER\pIt was destroyed\nby a mysterious\lfire.\pPlease stay away,\nas it is unsafe.$"
