@ ============================================================================
@ Trinity M4b S9 -- DRAGON'S DEN B1F. The clan's four guards (M4a's, given
@ GSC's real after-battle lines), the DRAGON FANG, and SILVER's coda.
@
@ THE MAP: 1114 walkable tiles of which 819 are reachable from its two doors,
@ most of the rest being the outer pond (the brief's note -- B1F is largely
@ MB_POND_WATER, so every fill here is run WITH Surf, which the Act II player
@ has). All S9 tiles decode collision 0 elevation 3.
@
@ GSC ships the DRAGON FANG as a longhand script rather than an itemball only
@ because it is a G/S event leftover; functionally it is a plain ball, so it is
@ one here, on the JOHTO pickup block (index 216 -- 0-215 are M4a's, 320 exist).
@
@ SILVER: no battle. He has already been fought four times this act (S1, S3,
@ S5, S7's cameo, S8's SILVER 4) and S11 owns the fifth. GSC puts him here on
@ Tuesdays and Thursdays after MT. MOON, refusing to fight because his POKéMON
@ "aren't ready"; Trinity keeps the refusal, drops the weekday gate (this build
@ has no weekday story hooks -- SANTOS's Saturday gift was dropped for the same
@ reason), and gates him on FLAG_TRINITY_BADGE16 so the coda lands on the way
@ back out of the shrine.
@ ============================================================================

DragonsDenB1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DragonsDenB1F_OnTransition
	.byte 0

@ Single authoring site. SILVER is a plain flag-gated NPC, not an addobject
@ actor, so the predicate is all there is: visible iff badge 16 is won. Terminal
@ state -- he never leaves the den again this act.
DragonsDenB1F_OnTransition:
	goto_if_unset FLAG_TRINITY_BADGE16, DragonsDenB1F_EventScript_HideSilver
	clearflag FLAG_TRINITY_J_DEN_SILVER_HIDE
	end

DragonsDenB1F_EventScript_HideSilver::
	setflag FLAG_TRINITY_J_DEN_SILVER_HIDE
	end

@ ============================================================================
@ SILVER's coda. Talk-triggered, two states, GSC's shape (Training1/Training2).
@ (20,23) decodes collision 0 elevation 3 with all four orthogonal neighbors
@ walkable -- open floor, no cut vertex.
@ `playbgm` is a whole-map BGM swap, not a jingle (G3/S7's I5), so both paths
@ end with fadedefaultbgm; otherwise his encounter track would stick to the map
@ for the rest of the visit.
@ ============================================================================
DragonsDenB1F_EventScript_Silver::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_DEN_SILVER_MET, DragonsDenB1F_EventScript_SilverAgain
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
	msgbox DragonsDenB1F_Text_SilverTraining, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_J_DEN_SILVER_MET
	fadedefaultbgm
	release
	end

DragonsDenB1F_EventScript_SilverAgain::
	msgbox DragonsDenB1F_Text_SilverTrainingAgain, MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

@ ============================================================================
@ G6 -- M4a's four guards keep their ids, GSC tiles and seen/beaten text, and
@ each gains GSC's own distinct after-battle line (the port left all four
@ re-showing the beaten text). Sight-triggered, so G3's NO_MUSIC does not apply.
@ Every one of the four costs exactly its own tile in the flood fill.
@ ============================================================================
DragonsDenB1F_EventScript_DARIN::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERM_DARIN, DragonsDenB1F_Text_DARINSeen, DragonsDenB1F_Text_DARINBeaten
	msgbox DragonsDenB1F_Text_DARINAfterBattle, MSGBOX_AUTOCLOSE
	end

DragonsDenB1F_EventScript_CARA::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_CARA, DragonsDenB1F_Text_CARASeen, DragonsDenB1F_Text_CARABeaten
	msgbox DragonsDenB1F_Text_CARAAfterBattle, MSGBOX_AUTOCLOSE
	end

DragonsDenB1F_EventScript_LEAANDPIA1::
	trainerbattle_single TRAINER_JOHTO_TWINS_LEAANDPIA1, DragonsDenB1F_Text_LEAANDPIA1Seen, DragonsDenB1F_Text_LEAANDPIA1Beaten
	msgbox DragonsDenB1F_Text_LEAANDPIA1AfterBattle, MSGBOX_AUTOCLOSE
	end

DragonsDenB1F_EventScript_LEAANDPIA1_2::
	trainerbattle_single TRAINER_JOHTO_TWINS_LEAANDPIA1_2, DragonsDenB1F_Text_LEAANDPIA1Seen_2, DragonsDenB1F_Text_LEAANDPIA1Beaten_2
	msgbox DragonsDenB1F_Text_LEAANDPIA1AfterBattle_2, MSGBOX_AUTOCLOSE
	end

DragonsDenB1F_EventScript_DragonShrineSignpost::
	msgbox DragonsDenB1F_Text_DragonShrineSignpost, MSGBOX_SIGN
	end

DragonsDenB1F_Text_DARINSeen:
	.string "You! How dare you enter uninvited!$"

DragonsDenB1F_Text_DARINBeaten:
	.string "S-strong!$"

DragonsDenB1F_Text_DARINAfterBattle:
	.string "The SHRINE ahead is home to the\n"
	.string "MASTER of our dragon-user clan.\p"
	.string "You're not allowed to just go in!$"

DragonsDenB1F_Text_CARASeen:
	.string "You shouldn't be in here!$"

DragonsDenB1F_Text_CARABeaten:
	.string "Oh yikes, I lost!$"

DragonsDenB1F_Text_CARAAfterBattle:
	.string "Soon I'm going to get permission\n"
	.string "from our MASTER to use dragons.\p"
	.string "When I do, I'm going to become an\n"
	.string "admirable dragon trainer and gain\l"
	.string "our MASTER's approval.$"

DragonsDenB1F_Text_LEAANDPIA1Seen:
	.string "It's a stranger we don't know.$"

DragonsDenB1F_Text_LEAANDPIA1Beaten:
	.string "Ouchies.$"

DragonsDenB1F_Text_LEAANDPIA1AfterBattle:
	.string "It was like having to battle\n"
	.string "LANCE.$"

DragonsDenB1F_Text_LEAANDPIA1Seen_2:
	.string "Who are you?$"

DragonsDenB1F_Text_LEAANDPIA1Beaten_2:
	.string "Meanie.$"

DragonsDenB1F_Text_LEAANDPIA1AfterBattle_2:
	.string "We'll tell on you.\p"
	.string "MASTER will be angry with you.$"

@ The arc turn. He is not sulking and he is not threatening -- for the first
@ time he is describing a method instead of a result, and he names where the
@ next fight happens. S11 collects on this at VICTORY ROAD.
DragonsDenB1F_Text_SilverTraining:
	.string "…\p"
	.string "What? {PLAYER}?\p"
	.string "…No. I won't battle you here.\p"
	.string "Not because I'd lose. Because my\n"
	.string "team isn't ready to beat you, and\l"
	.string "I finally know the difference.\p"
	.string "The old men in this cave made me\n"
	.string "stand still for an hour. I hated\l"
	.string "every second of it.\p"
	.string "Then I stopped hating it.\p"
	.string "VICTORY ROAD. Before the PLATEAU.\n"
	.string "I'll be waiting, and I won't be\l"
	.string "the same.$"

DragonsDenB1F_Text_SilverTrainingAgain:
	.string "…\p"
	.string "Whew…\p"
	.string "Learn to stay out of my way until\n"
	.string "VICTORY ROAD.$"

DragonsDenB1F_Text_DragonShrineSignpost:
	.string "DRAGON SHRINE\pA shrine honoring\nthe dragon POKéMON\psaid to have lived\nin DRAGON'S DEN.$"
