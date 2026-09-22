EcruteakGym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakGym_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S5 -- ECRUTEAK GYM. THE GYM PATTERN (G1-G7), copied from
@ data/maps/VioletGym/scripts.inc, whose header carries the full rationale.
@ Substituted here: MORTY, FLAG_TRINITY_BADGE12, TM30 SHADOW BALL, GHOST.
@
@ WHAT IS DIFFERENT ABOUT THIS GYM: its leader is not in it. GSC keeps MORTY at
@ the BURNED TOWER until the beasts wake and physically ejects the player from
@ the gym in the meantime (EcruteakGymClosed -> warp ECRUTEAK_CITY, 6, 27).
@ Trinity does not do hard doors -- the Johto gyms are open-order by contract --
@ so the gym stands OPEN with its four trainers fightable throughout, and a
@ greeter at the door explains where the leader is.
@
@ ON_TRANSITION is the SINGLE AUTHORITY for FLAG_TRINITY_J_MORTY_GYM_HIDE:
@   MORTY is visible iff FLAG_TRINITY_J_BEASTS_AWAKENED.
@ Nothing else in the tree writes that flag and no scene removeobject's MORTY,
@ so R1's removeobject co-sign cannot fire on him. The greeter carries no
@ visibility flag at all -- he never leaves, he just changes what he says.
@ ============================================================================
EcruteakGym_OnTransition:
	call EcruteakGym_EventScript_SetMortyVisibility
	end

EcruteakGym_EventScript_SetMortyVisibility::
	goto_if_set FLAG_TRINITY_J_BEASTS_AWAKENED, EcruteakGym_EventScript_ShowMorty
	setflag FLAG_TRINITY_J_MORTY_GYM_HIDE
	return

EcruteakGym_EventScript_ShowMorty::
	clearflag FLAG_TRINITY_J_MORTY_GYM_HIDE
	return

@ Trinity M4a Task 7: GSC pit-fall floor. The 30 hole tiles are wired as
@ coord_events (not setholewarp) because GSC's Ecruteak Gym falls land back
@ at the gym's own entrance, not at the hole's own x/y on another map.
EcruteakGym_EventScript_Fall::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_ECRUTEAK_GYM, 4, 15
	waitstate
	end

@ ============================================================================
@ G1/G2/G3 -- MORTY. Talk-triggered, TRAINER_TYPE_NONE, sight 0, appended to
@ object_events so M4a's local ids do not shift. GSC's tile (5,1), which decodes
@ MB_NORMAL collision 0 elevation 3 and is NOT one of the 30 pit cells (they all
@ live at y >= 4).
@ ============================================================================
EcruteakGym_EventScript_Morty::
	trainerbattle_single TRAINER_MORTY, EcruteakGym_Text_MortyIntro, EcruteakGym_Text_MortyDefeat, EcruteakGym_EventScript_MortyDefeated, NO_MUSIC
	@ Re-talk path only: the engine's trainer-defeated flag already gated the
	@ continuation above, so execution reaches here on a LATER talk. Retry the
	@ TM if the bag was full the first time, else the post-badge line.
	goto_if_unset FLAG_TRINITY_J_MORTY_TM30, EcruteakGym_EventScript_GiveShadowBall
	msgbox EcruteakGym_Text_MortyPostBattle, MSGBOX_DEFAULT
	release
	end

EcruteakGym_EventScript_MortyDefeated::
	message EcruteakGym_Text_ReceivedFogBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_TRINITY_BADGE12
	msgbox EcruteakGym_Text_FogBadgeInfo, MSGBOX_DEFAULT
	goto EcruteakGym_EventScript_GiveShadowBall
	end

EcruteakGym_EventScript_GiveShadowBall::
	giveitem ITEM_TM_SHADOW_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_J_MORTY_TM30
	msgbox EcruteakGym_Text_ExplainShadowBall, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ The greeter, at (5,14): MB_NORMAL, collision 0, elevation 3, NOT one of the 30
@ pit cells, and talkable from (5,15) facing north.
@
@ MOVED ONE TILE EAST OF GSC'S GRAMPS TILE (4,14), AND THIS IS THE WORKED
@ EXAMPLE OF A RULE WORTH KEEPING: an NPC does not rest on a warp tile.
@ (4,14) carries one of this map's stale warp_events -- M4a's dead G/S
@ leftovers. It is inert (the metatile decodes MB_NORMAL, which carries no warp
@ behaviour, so nothing would ever have fired) but reach_check reported "warps
@ inside the sealed region" for his resting tile, and the M4b contract's
@ coordinate rule does not carve out an exception for warps that happen to be
@ dead. The move costs nothing, so there is no reason to argue the exception.
@ S5 did the same for MORTY on BURNED TOWER 1F ((14,14) -> (13,14)).
@ NO-SEAL DECODE: the lobby (rows 14-17) reaches row 13 through THREE
@ independent columns -- x=2 ((2,14)->(2,13)), x=4/5, and x=7 ((7,14)->(7,13)).
@ Standing on (5,14) closes one of three and seals nothing; reach_check confirms
@ a one-tile loss (his own).
@ ============================================================================
EcruteakGym_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_BEASTS_AWAKENED, EcruteakGym_EventScript_GreeterMortyBack
	msgbox EcruteakGym_Text_GreeterMortyAway, MSGBOX_DEFAULT
	release
	end

EcruteakGym_EventScript_GreeterMortyBack::
	msgbox EcruteakGym_Text_GreeterMortyBack, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ G6 -- M4a's four gym trainers keep their ids, tiles and seen/beaten text, and
@ each gains a distinct post-battle line (the port left all four re-showing the
@ beaten text). Lines are GSC's own; GRACE's is kept intact because it is the
@ only in-world explanation of the invisible floor.
@ ============================================================================
EcruteakGym_EventScript_JEFFREY::
	trainerbattle_single TRAINER_JOHTO_SAGE_JEFFREY, EcruteakGym_Text_JEFFREYSeen, EcruteakGym_Text_JEFFREYBeaten
	msgbox EcruteakGym_Text_JEFFREYAfterBattle, MSGBOX_AUTOCLOSE
	end

EcruteakGym_EventScript_PING::
	trainerbattle_single TRAINER_JOHTO_SAGE_PING, EcruteakGym_Text_PINGSeen, EcruteakGym_Text_PINGBeaten
	msgbox EcruteakGym_Text_PINGAfterBattle, MSGBOX_AUTOCLOSE
	end

EcruteakGym_EventScript_MARTHA::
	trainerbattle_single TRAINER_JOHTO_MEDIUM_MARTHA, EcruteakGym_Text_MARTHASeen, EcruteakGym_Text_MARTHABeaten
	msgbox EcruteakGym_Text_MARTHAAfterBattle, MSGBOX_AUTOCLOSE
	end

EcruteakGym_EventScript_GRACE::
	trainerbattle_single TRAINER_JOHTO_MEDIUM_GRACE, EcruteakGym_Text_GRACESeen, EcruteakGym_Text_GRACEBeaten
	msgbox EcruteakGym_Text_GRACEAfterBattle, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ G4 -- the gym guide, two states on the badge flag.
@ ============================================================================
EcruteakGym_EventScript_Guide::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_BADGE12, EcruteakGym_EventScript_GuidePostVictory
	msgbox EcruteakGym_Text_GuideAdvice, MSGBOX_DEFAULT
	release
	end

@ M7b Task 15 (finding #6): the guide states the player's LIVE badge count.
@ The tally reads the flags and buffers the number itself -- see
@ data/scripts/trinity_johto.inc.
EcruteakGym_EventScript_GuidePostVictory::
	msgbox EcruteakGym_Text_GuidePostVictory, MSGBOX_DEFAULT
	call Trinity_EventScript_JohtoBadgeTally
	@ M7b Task 14 (finding #9): once the badge is won this guide doubles as
	@ a pointer. The branch above is already the badge flag, so nothing new
	@ is read or written here; the ladder releases for us.
	goto Trinity_EventScript_JohtoGuide
	end

@ ============================================================================
@ G5 -- (3,15) and (6,15) decode collision 1: they are the statue wall tiles,
@ read facing north from (3,16)/(6,16), both collision 0 elevation 3.
@ ============================================================================
@ ONE entry script for BOTH bg_events. VioletGym has a Left/Right pair because
@ S2 copied vanilla's shape, but neither branch ever differed -- the statues are
@ identical and read identically. Two bg_events, one script.
EcruteakGym_EventScript_GymStatues::
	lockall
	goto_if_set FLAG_TRINITY_BADGE12, EcruteakGym_EventScript_GymStatueCertified
	goto EcruteakGym_EventScript_GymStatue
	end

EcruteakGym_EventScript_GymStatue::
	msgbox EcruteakGym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

EcruteakGym_EventScript_GymStatueCertified::
	msgbox EcruteakGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@ Text
@ ============================================================================
@ Adapts pokecrystal MortyIntroText. GSC's MORTY has trained his whole life to
@ be worthy of the rainbow POKéMON; Act II gives him a reason to think the wait
@ is over, because the player has just watched the three beasts wake.
EcruteakGym_Text_MortyIntro:
	.string "MORTY: Good of you to have come.\p"
	.string "Here in ECRUTEAK, POKéMON have been\n"
	.string "revered for a very long time.\p"
	.string "It is said a rainbow-colored POKéMON\n"
	.string "comes down to a truly powerful\l"
	.string "trainer. I believed that tale, so I\l"
	.string "have trained here all my life.\p"
	.string "As a result I can see what others\n"
	.string "cannot. Just a bit more…\p"
	.string "For a hundred and fifty years those\n"
	.string "three slept, and they woke for YOU.\p"
	.string "So let me see what the sky is\n"
	.string "waiting for. Do not hold back.$"

@ GSC MortyWinLossText.
EcruteakGym_Text_MortyDefeat:
	.string "I'm not good enough yet…\p"
	.string "All right. This BADGE is yours.$"

EcruteakGym_Text_ReceivedFogBadge:
	.string "{PLAYER} received the FOGBADGE from\n"
	.string "MORTY!$"

@ Badges 9-16 are plain flags with no engine UI, so this text must promise no
@ mechanical effect. It also must not COUNT badges: the Johto gyms are
@ open-order in Trinity, so "that's your fourth" is wrong for most playthroughs.
EcruteakGym_Text_FogBadgeInfo:
	.string "MORTY: The FOGBADGE is not a key and\n"
	.string "it will not make your POKéMON obey.\p"
	.string "It is a record. It says a trainer\n"
	.string "stood in this room and was not\l"
	.string "afraid of what could not be seen.\p"
	.string "Gather eight from JOHTO and INDIGO\n"
	.string "will open its doors to you.$"

@ TM award dialogue must never presume novelty (S3-S9 rule): gym TM awards
@ duplicate Act I sources, so the player may already own SHADOW BALL.
EcruteakGym_Text_ExplainShadowBall:
	.string "MORTY: SHADOW BALL. It throws a\n"
	.string "piece of the dark at an opponent,\l"
	.string "and it can leave them slower to\l"
	.string "shrug off what follows.\p"
	.string "Every ghost trainer worth the name\n"
	.string "teaches it. Mine is not the first\l"
	.string "copy you will have been handed and\l"
	.string "it will not be the last.\p"
	.string "Use it the way I would.$"

@ GSC MortyFightDoneText.
EcruteakGym_Text_MortyPostBattle:
	.string "MORTY: I see…\p"
	.string "Your journey has taken you to\n"
	.string "far-away places, and you have\l"
	.string "witnessed much more than I.\p"
	.string "I envy you for that.$"

EcruteakGym_Text_GreeterMortyAway:
	.string "Hohohoho. You want MORTY?\p"
	.string "MORTY is at the BURNED TOWER. He is\n"
	.string "always at the BURNED TOWER.\p"
	.string "Go on in and take on the others if\n"
	.string "you like -- nobody here is going to\l"
	.string "stop you.\p"
	.string "Mind the floor. It is not all there.$"

EcruteakGym_Text_GreeterMortyBack:
	.string "Hohohoho! MORTY came back from the\n"
	.string "BURNED TOWER in a great hurry, and\l"
	.string "he has not sat down since.\p"
	.string "He is at the far end. Whatever you\n"
	.string "did up there, he wants a word.$"

EcruteakGym_Text_JEFFREYSeen:
	.string "I spent the spring\nwith my POKéMON.\pThen summer, fall\nand winter…\pThen spring came\nagain. We have\plived together\nfor a long time.$"

EcruteakGym_Text_JEFFREYBeaten:
	.string "Wins and losses, I\nexperienced both.$"

@ GSC SageJeffreyAfterBattleText.
EcruteakGym_Text_JEFFREYAfterBattle:
	.string "Where did POKéMON come from?$"

EcruteakGym_Text_PINGSeen:
	.string "Can you inflict\nany damage on our\lPOKéMON?$"

EcruteakGym_Text_PINGBeaten:
	.string "Ah! Well done!$"

@ GSC SagePingAfterBattleText. True in this build: every mon in this room is
@ part GHOST, and gTypeEffectivenessTable[TYPE_NORMAL][TYPE_GHOST] is 0.0.
EcruteakGym_Text_PINGAfterBattle:
	.string "We use only ghost-type POKéMON.\p"
	.string "No normal-type attack can harm them.$"

EcruteakGym_Text_MARTHASeen:
	.string "I shall win!$"

EcruteakGym_Text_MARTHABeaten:
	.string "I, I, I lost!$"

@ GSC MediumMarthaAfterBattleText.
EcruteakGym_Text_MARTHAAfterBattle:
	.string "The one who wants to win most--will!$"

EcruteakGym_Text_GRACESeen:
	.string "Stumped by our in-\nvisible floor?\pDefeat me if you\nwant a hint!$"

EcruteakGym_Text_GRACEBeaten:
	.string "Wha-what?$"

@ GSC MediumGraceAfterBattleText -- the only in-world explanation of the pit
@ maze, so it is kept whole.
EcruteakGym_Text_GRACEAfterBattle:
	.string "Fine. I shall tell you the secret of\n"
	.string "the invisible floor.\p"
	.string "The path is right before our eyes!$"

@ G4 -- VERIFIED AGAINST THE DATA BEFORE IT WAS WRITTEN. Rosters from
@ src/data/trainers.party; typings from src/data/pokemon/species_info/;
@ multipliers from gTypeEffectivenessTable (src/data/types_info.h:14).
@   SABLEYE    MON_TYPES(TYPE_DARK, TYPE_GHOST)
@   BANETTE    MON_TYPES(TYPE_GHOST)
@   MISDREAVUS MON_TYPES(TYPE_GHOST)
@   DUSCLOPS   MON_TYPES(TYPE_GHOST)
@   GENGAR     MON_TYPES(TYPE_GHOST, TYPE_POISON)
@ GHOST->GHOST 2.0, GHOST->DARK 0.5, GHOST->POISON 1.0
@ DARK ->GHOST 2.0, DARK ->DARK 0.5, DARK ->POISON 1.0
@ so DARK and GHOST are 2.0 on BANETTE / MISDREAVUS / DUSCLOPS / GENGAR and
@ exactly 1.0 on SABLEYE (0.5 x 2.0). NORMAL->GHOST and FIGHTING->GHOST are
@ both 0.0, so neither touches anything in this gym.
@ SABLEYE's only 2.0 in this build is FAIRY (FAIRY->DARK 2.0, FAIRY->GHOST 1.0).
@ LEVEL BAND, checked and stated honestly: MORTY is L61-65; the four trainers in
@ this room are L64-68 (PING's fifth GENGAR is L68, three levels above the
@ leader's ace). That inversion is an M4a port artifact, logged as an M6 balance
@ item -- until it is tuned, the guide should not pretend otherwise.
EcruteakGym_Text_GuideAdvice:
	.string "Hey, CHAMPION! Listen close, this\n"
	.string "one is not obvious.\p"
	.string "Every POKéMON in here is part GHOST,\n"
	.string "so NORMAL and FIGHTING moves do\l"
	.string "nothing at all. Not weak. Nothing.\p"
	.string "DARK and GHOST moves hit four of\n"
	.string "MORTY's five for double.\p"
	.string "The fifth is SABLEYE, and SABLEYE is\n"
	.string "part DARK itself, so both of those\l"
	.string "land as ordinary hits. FAIRY is what\l"
	.string "actually dents it.\p"
	.string "One more thing. The trainers in this\n"
	.string "room run L64 and up -- MORTY is not\l"
	.string "the hardest fight in his own GYM.$"

@ GSC EcruteakGymGuideWinText.
EcruteakGym_Text_GuidePostVictory:
	.string "Whew, {PLAYER}. You did great!\p"
	.string "I was cowering in the corner out of\n"
	.string "pure terror the whole time!$"

EcruteakGym_Text_GymStatue:
	.string "ECRUTEAK POKéMON GYM\n"
	.string "LEADER: MORTY\p"
	.string "The Mystic Seer of the Future$"

EcruteakGym_Text_GymStatueCertified:
	.string "ECRUTEAK POKéMON GYM\n"
	.string "LEADER: MORTY\p"
	.string "The Mystic Seer of the Future\p"
	.string "{PLAYER} won the FOGBADGE here.$"
