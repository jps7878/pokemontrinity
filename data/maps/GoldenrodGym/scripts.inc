GoldenrodGym_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S4 -- WHITNEY. THE GYM PATTERN (G1-G7) copied verbatim from
@ data/maps/VioletGym/scripts.inc; read that file's header for the full
@ rationale and the engine citations. Only the map, leader, badge, TM and type
@ change. The one addition is the crying beat, below.
@
@ G1  WHITNEY at (8,3) -- GSC's tile (GoldenrodGym.asm:395). TRAINER_TYPE_NONE,
@     sight 0, flag 0, TALK-triggered, APPENDED to object_events so M4a's five
@     local ids do not shift. Decoded: (8,2) and (7,3) are collision 1, so her
@     only approach tiles are (9,3) and (8,4) -- and BRIDGET at (9,6) is inside
@     the camera window from both, so the beat below needs no normalisation.
@
@ G3  NO_MUSIC on the talk-triggered battle. Battle BGM needs no scripting:
@     TRAINER_WHITNEY (1032) is inside the TRAINER_FALKNER..TRAINER_CLAIR guard
@     in GetBattleBGM(), so it plays MUS_RG_VS_GYM_LEADER.
@
@ G7  GoldenrodGym_EventScript_WhitneyDefeated is the ONLY writer of
@     FLAG_TRINITY_BADGE11. The guide and both statues read it only.
@
@ THE CRYING BEAT -- GSC adapted, deliberately collapsed to ONE scene.
@     GSC (GoldenrodGym.asm:22-115) withholds the badge: the battle sets
@     EVENT_MADE_WHITNEY_CRY, talking to her gets "…You meanie!", and only after
@     walking onto (8,5) -- which fires WhitneyCriesScript, where BRIDGET steps
@     over and consoles her -- does a re-talk pay out the badge and the TM.
@     Trinity does the whole thing inside the award continuation, because G2 is
@     a SAFETY clause, not a style clause: it exists so the badge is set before
@     the only failable gift and can never be lost to inventory or to a player
@     who walks away. Gating the badge behind a coord trigger AND a re-talk
@     re-opens exactly the hole G2 closes. Nothing dramatic is lost -- the loss
@     text IS the sobbing, BRIDGET reacts on the spot, and WHITNEY hands the
@     badge over mid-sniffle.
@     BRIDGET does not WALK (GSC steps her left onto (8,6)). The player's
@     post-battle tile is not pinned -- (8,4) or (9,3) -- and (8,5)/(8,6) can be
@     occupied by the player, so a scripted step could collide. She is already
@     MOVEMENT_TYPE_FACE_LEFT at (9,6), i.e. already facing the aisle, so she
@     gets an emote instead. `lock` (owned by trainerbattle_single) plus
@     applymovement on a DIFFERENT local id is the vanilla idiom -- see
@     RustboroCity_EventScript_LittleBoy (data/maps/RustboroCity/scripts.inc:220)
@     -- because ScriptMovement drives the object through its own task and
@     unfreezes it (src/script_movement.c:22-31, 236-248).
@ ============================================================================

GoldenrodGym_EventScript_Whitney::
	trainerbattle_single TRAINER_WHITNEY, GoldenrodGym_Text_WhitneyIntro, GoldenrodGym_Text_WhitneyDefeat, GoldenrodGym_EventScript_WhitneyDefeated, NO_MUSIC
	@ Re-talk path only: the engine's per-id defeated flag already gated the
	@ continuation above, so execution reaches here on a LATER talk. Retry the
	@ TM if the bag was full the first time, else the post-badge line.
	goto_if_unset FLAG_TRINITY_J_WHITNEY_TM45, GoldenrodGym_EventScript_GiveAttract
	msgbox GoldenrodGym_Text_WhitneyPostBattle, MSGBOX_DEFAULT
	release
	end

GoldenrodGym_EventScript_WhitneyDefeated::
	applymovement LOCALID_JOHTO_GGYM_BRIDGET, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox GoldenrodGym_Text_BridgetConsoles, MSGBOX_DEFAULT
	message GoldenrodGym_Text_ReceivedPlainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_TRINITY_BADGE11
	msgbox GoldenrodGym_Text_PlainBadgeInfo, MSGBOX_DEFAULT
	goto GoldenrodGym_EventScript_GiveAttract
	end

GoldenrodGym_EventScript_GiveAttract::
	giveitem ITEM_TM_ATTRACT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_J_WHITNEY_TM45
	msgbox GoldenrodGym_Text_ExplainAttract, MSGBOX_DEFAULT
	release
	end

@ G6: M4a's four gym trainers keep their ids, tiles and seen/beaten text, and
@ each gains its GSC after-battle line (the port left all four re-showing the
@ beaten text).
GoldenrodGym_EventScript_CARRIE::
	trainerbattle_single TRAINER_JOHTO_LASS_CARRIE, GoldenrodGym_Text_CARRIESeen, GoldenrodGym_Text_CARRIEBeaten
	msgbox GoldenrodGym_Text_CARRIEAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodGym_EventScript_BRIDGET::
	trainerbattle_single TRAINER_JOHTO_LASS_BRIDGET, GoldenrodGym_Text_BRIDGETSeen, GoldenrodGym_Text_BRIDGETBeaten
	msgbox GoldenrodGym_Text_BRIDGETAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodGym_EventScript_VICTORIA::
	trainerbattle_single TRAINER_JOHTO_BEAUTY_VICTORIA, GoldenrodGym_Text_VICTORIASeen, GoldenrodGym_Text_VICTORIABeaten
	msgbox GoldenrodGym_Text_VICTORIAAfterBattle, MSGBOX_AUTOCLOSE
	end

GoldenrodGym_EventScript_SAMANTHA::
	trainerbattle_single TRAINER_JOHTO_BEAUTY_SAMANTHA, GoldenrodGym_Text_SAMANTHASeen, GoldenrodGym_Text_SAMANTHABeaten
	msgbox GoldenrodGym_Text_SAMANTHAAfterBattle, MSGBOX_AUTOCLOSE
	end

@ G4: two states on the badge flag; the advice names the type, its one real
@ weakness, the GHOST immunity and the level band. Tile (5,15) is GSC's and
@ M4a's; it seals (5,14), a 1-tile dead-end alcove containing nothing.
GoldenrodGym_EventScript_Guide::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_BADGE11, GoldenrodGym_EventScript_GuidePostVictory
	msgbox GoldenrodGym_Text_GuideAdvice, MSGBOX_DEFAULT
	release
	end

GoldenrodGym_EventScript_GuidePostVictory::
	msgbox GoldenrodGym_Text_GuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ G5: (1,15) and (4,15) decode collision 1 -- they are the statue wall tiles,
@ read facing north from (1,16)/(4,16), both collision 0 elevation 3.
GoldenrodGym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_TRINITY_BADGE11, GoldenrodGym_EventScript_GymStatueCertified
	goto GoldenrodGym_EventScript_GymStatue
	end

GoldenrodGym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_TRINITY_BADGE11, GoldenrodGym_EventScript_GymStatueCertified
	goto GoldenrodGym_EventScript_GymStatue
	end

GoldenrodGym_EventScript_GymStatue::
	msgbox GoldenrodGym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

GoldenrodGym_EventScript_GymStatueCertified::
	msgbox GoldenrodGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@ Text
@ ============================================================================
@ Adapts pokecrystal WhitneyBeforeText. GSC opens with the bubbly "everyone was
@ into POKéMON so I got into it too" line; Act II keeps it, then has her drop it
@ because the person in front of her is the HOENN CHAMPION.
GoldenrodGym_Text_WhitneyIntro:
	.string "WHITNEY: Hi! I'm WHITNEY!\p"
	.string "Everyone was into POKéMON, so\n"
	.string "I got into it too!\p"
	.string "…That's how I open. It's cute.\n"
	.string "It works on everybody.\p"
	.string "Then the HOENN CHAMPION walks\n"
	.string "into my GYM, and suddenly it\l"
	.string "sounds like an excuse.\p"
	.string "Fine. The true version, then.\p"
	.string "NORMAL types get nothing free.\n"
	.string "No resistances to hide behind,\l"
	.string "no type that folds to them.\p"
	.string "Everything mine can do, I had\n"
	.string "to build. I built a lot.\p"
	.string "You want to battle? I'm\n"
	.string "warning you -- I'm good!$"

@ GSC WhitneyShouldntBeSoSeriousText, verbatim in spirit. This IS the crying
@ beat's first half -- `trainerbattle_single` shows it automatically. (Backticks
@ are mandatory: qa_sweep's TRAINERBATTLE_RE matches `trainerbattle_\w+\s+(\w+)`
@ in comments too, and would read the next word as a trainer constant.)
GoldenrodGym_Text_WhitneyDefeat:
	.string "…Sob.\p"
	.string "…Waaaaaaah! You're mean!\p"
	.string "You shouldn't be so serious!\n"
	.string "You… you child, you!$"

@ Adapts GSC BridgetWhitneyCriesText (spoken there by LASS2 = BRIDGET after she
@ steps over). Trinity keeps the speaker and the content and drops the step.
GoldenrodGym_Text_BridgetConsoles:
	.string "BRIDGET: Oh, no. You made\n"
	.string "WHITNEY cry.\p"
	.string "It's OK. She'll stop soon. She\n"
	.string "always cries when she loses.\p"
	.string "…She just doesn't lose very\n"
	.string "often. So. Congratulations, I\l"
	.string "suppose.$"

GoldenrodGym_Text_ReceivedPlainBadge:
	.string "{PLAYER} received the\n"
	.string "PLAINBADGE from WHITNEY.$"

@ IMPORTANT adaptation. GSC's PLAINBADGE boosts SPEED and unlocks field
@ STRENGTH; in Trinity badges 9-16 are plain flags with no engine effect, so
@ this text must not promise one. It also must NOT count badges -- the Johto
@ gyms are open-order in Trinity, so no line may assume an ordering.
GoldenrodGym_Text_PlainBadgeInfo:
	.string "WHITNEY: …Sniff.\p"
	.string "What? What do you want? A\n"
	.string "BADGE?\p"
	.string "Oh. Right. I did say I'd hand\n"
	.string "one over.\p"
	.string "There. PLAINBADGE.\p"
	.string "It won't make your POKéMON\n"
	.string "faster and it won't move a\l"
	.string "single boulder for you.\p"
	.string "It means you beat me, and that\n"
	.string "the LEAGUE at INDIGO has to\l"
	.string "count it. Eight of them and\l"
	.string "they open the door.\p"
	.string "That's one more.\n"
	.string "…Here. Take this as well.$"

@ I_REUSABLE_TMS is TRUE in this build, so "it won't wear out" is accurate.
@ S3-S9 RULE: gym TM awards duplicate Act I sources, so the dialogue must never
@ presume the player has never seen the move.
GoldenrodGym_Text_ExplainAttract:
	.string "WHITNEY: TM45. ATTRACT.\p"
	.string "Go ahead and laugh. Everyone\n"
	.string "laughs, right up until MILTANK\l"
	.string "has their best POKéMON just\l"
	.string "standing there.\p"
	.string "You may own one already.\n"
	.string "Carry mine anyway.\p"
	.string "Know what it can't do. It needs\n"
	.string "the opposite gender, and it\l"
	.string "does nothing at all to anything\l"
	.string "with no gender. Read the field\l"
	.string "before you spend a turn on it.\p"
	.string "When it lands, it isn't damage.\n"
	.string "It's their turn, taken from\l"
	.string "them, for free.\p"
	.string "It won't wear out.$"

@ Chapter pointer: S5 is ECRUTEAK CITY / MORTY. Adapts WhitneyGoodCryText.
GoldenrodGym_Text_WhitneyPostBattle:
	.string "WHITNEY: Ah, that was a good\n"
	.string "cry.\p"
	.string "Try MORTY next. ECRUTEAK CITY,\n"
	.string "north up ROUTE 35 and 36.\p"
	.string "He does GHOSTS, and he'll be\n"
	.string "very calm about beating you.\p"
	.string "I hope he isn't.\p"
	.string "Come for a visit again!\n"
	.string "Bye-bye!$"

GoldenrodGym_Text_CARRIESeen:
	.string "Don't let my\nPOKéMON's cute\plooks fool you.\nThey can whip you!$"

GoldenrodGym_Text_CARRIEBeaten:
	.string "Darn… I thought\nyou were weak…$"

GoldenrodGym_Text_CARRIEAfterBattle:
	.string "Do my POKéMON think I'm cute?\p"
	.string "Be honest. Actually, no.\n"
	.string "Don't be honest.$"

GoldenrodGym_Text_BRIDGETSeen:
	.string "I like cute POKé-\nMON better than\lstrong POKéMON.\pBut I have strong\nand cute POKéMON!$"

GoldenrodGym_Text_BRIDGETBeaten:
	.string "Oh, no, no, no!$"

GoldenrodGym_Text_BRIDGETAfterBattle:
	.string "I'm trying to beat WHITNEY,\n"
	.string "but… it's depressing.\p"
	.string "I'm okay! If I lose, I'll just\n"
	.string "try harder next time!$"

GoldenrodGym_Text_VICTORIASeen:
	.string "Oh, you are a cute\nlittle trainer!\pI like you, but I\nwon't hold back!$"

GoldenrodGym_Text_VICTORIABeaten:
	.string "Let's see… Oops,\nit's over?$"

GoldenrodGym_Text_VICTORIAAfterBattle:
	.string "Wow, you must be good to beat\n"
	.string "me! Keep it up!$"

GoldenrodGym_Text_SAMANTHASeen:
	.string "Give it your best\nshot, or I'll take\lyou down!$"

GoldenrodGym_Text_SAMANTHABeaten:
	.string "No! Oh, MEOWTH,\nI'm so sorry!$"

GoldenrodGym_Text_SAMANTHAAfterBattle:
	.string "I taught MEOWTH moves for\n"
	.string "taking on any type…\p"
	.string "Any type but yours, apparently.$"

@ Adapts GoldenrodGymGuideText. The level warning and the GHOST note are
@ Trinity additions -- WHITNEY's roster runs L60-63 and MILTANK is the wall.
GoldenrodGym_Text_GuideAdvice:
	.string "Yo! CHAMP in the making--\p"
	.string "…That line isn't going to work\n"
	.string "on you, is it.\p"
	.string "WHITNEY runs NORMAL types.\p"
	.string "There is exactly one type that\n"
	.string "beats them straight, and it's\l"
	.string "FIGHTING. Nothing else gets a\l"
	.string "bonus at all.\p"
	.string "And don't reach for GHOST. Your\n"
	.string "GHOST moves won't even touch\l"
	.string "them.\p"
	.string "Her team is LEVEL 60 and up.\n"
	.string "The MILTANK she finishes with\l"
	.string "is LEVEL 63, and it is the one\l"
	.string "that ends people.\p"
	.string "Come see me after.$"

GoldenrodGym_Text_GuidePostVictory:
	.string "You won? Through the MILTANK?\p"
	.string "The PLAINBADGE is yours.\p"
	.string "I'll be honest, I was busy\n"
	.string "admiring the ladies here.\p"
	.string "But I saw the end bit, and the\n"
	.string "end bit was something.$"

GoldenrodGym_Text_GymStatue:
	.string "GOLDENROD CITY POKéMON GYM\n"
	.string "LEADER: WHITNEY\p"
	.string "The Incredibly Pretty Girl$"

GoldenrodGym_Text_GymStatueCertified:
	.string "GOLDENROD CITY POKéMON GYM\n"
	.string "LEADER: WHITNEY\p"
	.string "WHITNEY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
