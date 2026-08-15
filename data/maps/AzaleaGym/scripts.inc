AzaleaGym_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S3 -- THE GYM PATTERN (G1-G7), copied verbatim from
@ game/data/maps/VioletGym/scripts.inc (S2), which is the canonical statement of
@ the clauses and carries the full rationale. Only the map name, leader, badge
@ flag, TM and type differ. Full write-up:
@ docs/superpowers/plans/m4b/02-violet-chapter.md section 2.
@
@ G1  Leader object: TRAINER_TYPE_NONE, sight 0, flag 0, at the GSC tile (5,7).
@     TALK-triggered, never sight-triggered -- both references agree (GSC's
@     BUGSY is OBJECTTYPE_SCRIPT, vanilla Roxanne is TRAINER_TYPE_NONE), and a
@     sight line here would fire mid-approach. Appended to object_events so
@     M4a's local ids do not shift. Decoded: (5,7) is collision 0, approached
@     from (5,8), and blocking it does not seal the hall -- (4,7) and (6,7) stay
@     connected through (4,8)-(5,8)-(6,8).
@
@ G2  Leader script = exactly three labels (below). Award idempotence, which
@     S8's seven-badge Radio Tower trigger depends on:
@       - trainerbattle_single's continuation runs ONLY on the battle actually
@         fought. On a later talk the engine takes the already-defeated branch:
@         EventScript_TryDoNormalTrainerBattle checks GetTrainerFlag and jumps
@         to EventScript_NoNormalTrainerBattle -> gotopostbattlescript
@         (data/scripts/trainer_battle.inc:10-24), which resolves to
@         sTrainerBattleEndScript (BattleSetup_GetScriptAddrAfterBattle,
@         src/battle_setup.c:1405) -- and that pointer is set by
@         TrainerBattleLoadArgs to the bytes immediately AFTER the trainerbattle
@         arguments (src/battle_setup.c:972), i.e. the next command in this
@         script. So the badge setflag runs at most once -- and setflag is
@         idempotent anyway, so the badge count can never be inflated.
@       - The TM is the ONLY failable gift (full bag), so it gets its own flag
@         and its own label, reached from both the award path (goto) and the
@         re-talk path (goto_if_unset). A full bag goes to
@         Common_EventScript_ShowBagIsFull, which releases and ends WITHOUT
@         setting the flag (data/event_scripts.s:1232) -- the next talk retries.
@       - The badge is set BEFORE the TM and nothing between them can fail, so
@         a bag-full player still keeps the badge. Progression is never lost to
@         inventory state.
@       - `release` (not releaseall): the trainerbattle command owns the lock.
@
@ G3  NO_MUSIC suppresses PlayTrainerEncounterMusic. That special is not a
@     jingle -- it calls PlayNewMapMusic() and SWAPS the whole map BGM to an
@     encounter track for the rest of the approach and intro text
@     (src/battle_setup.c:1451-1499). NO_MUSIC is the only way to stop it
@     (src/battle_setup.c:1451-1452). General rule: ANY talk-triggered
@     trainerbattle passes NO_MUSIC, because that swap belongs to a sight line,
@     not to a conversation.
@     Battle BGM still needs no scripting: GetBattleBGM()'s
@     TRAINER_CLASS_LEADER case carries a Trinity id-range guard -- trainer ids
@     TRAINER_FALKNER..TRAINER_CLAIR (1030-1037, the eight Johto leaders,
@     contiguous) return MUS_RG_VS_GYM_LEADER (src/pokemon.c). TRAINER_BUGSY is
@     1031, so this gym inherits the contract's music pin for free.
@
@ G4  Gym guide: the M4a OBJ_EVENT_GFX_EXPERT_M at (7,13), two states on the
@     badge flag, and the advice text states the leader's type, its weaknesses
@     AND the roster's level band (Act II opens at L58+).
@
@ G5  Gym statues: sign bg_events on the collision-1 statue tiles (3,13)/(6,13),
@     read facing north from (3,14)/(6,14) (both collision 0, elevation 3), two
@     states on the badge flag. Badges 9-16 have NO engine UI, so this in-world
@     readback is the only confirmation the player ever gets that the flag was
@     set. Identical geometry to VioletGym.
@
@ G6  M4a's five gym trainers keep their ids/tiles/seen+beaten text and gain a
@     distinct post-battle line (the port left them re-showing the defeat text).
@     GSC's own after-battle lines are used.
@
@ G7  Only AzaleaGym_EventScript_BugsyDefeated ever WRITES FLAG_TRINITY_BADGE10.
@     Everything else -- guide, statues, gate NPCs, S8's counter -- reads it only.
@ ============================================================================

AzaleaGym_EventScript_Bugsy::
	trainerbattle_single TRAINER_BUGSY, AzaleaGym_Text_BugsyIntro, AzaleaGym_Text_BugsyDefeat, AzaleaGym_EventScript_BugsyDefeated, NO_MUSIC
	@ Re-talk path only: the engine's trainer-defeated flag already gated the
	@ continuation above, so execution reaches here on a LATER talk. Retry the
	@ TM if the bag was full the first time, else the post-badge line.
	goto_if_unset FLAG_TRINITY_J_BUGSY_TM19, AzaleaGym_EventScript_GiveGigaDrain
	msgbox AzaleaGym_Text_BugsyPostBattle, MSGBOX_DEFAULT
	release
	end

AzaleaGym_EventScript_BugsyDefeated::
	message AzaleaGym_Text_ReceivedHiveBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_TRINITY_BADGE10
	msgbox AzaleaGym_Text_HiveBadgeInfo, MSGBOX_DEFAULT
	goto AzaleaGym_EventScript_GiveGigaDrain
	end

AzaleaGym_EventScript_GiveGigaDrain::
	giveitem ITEM_TM_GIGA_DRAIN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_J_BUGSY_TM19
	msgbox AzaleaGym_Text_ExplainGigaDrain, MSGBOX_DEFAULT
	release
	end

AzaleaGym_EventScript_BUG_CATCHER_BENNY::
	trainerbattle_single TRAINER_JOHTO_BUG_CATCHER_BUG_CATCHER_BENNY, AzaleaGym_Text_BUG_CATCHER_BENNYSeen, AzaleaGym_Text_BUG_CATCHER_BENNYBeaten
	msgbox AzaleaGym_Text_BUG_CATCHER_BENNYAfterBattle, MSGBOX_AUTOCLOSE
	end

AzaleaGym_EventScript_AL::
	trainerbattle_single TRAINER_JOHTO_BUG_CATCHER_AL, AzaleaGym_Text_ALSeen, AzaleaGym_Text_ALBeaten
	msgbox AzaleaGym_Text_ALAfterBattle, MSGBOX_AUTOCLOSE
	end

AzaleaGym_EventScript_JOSH::
	trainerbattle_single TRAINER_JOHTO_BUG_CATCHER_JOSH, AzaleaGym_Text_JOSHSeen, AzaleaGym_Text_JOSHBeaten
	msgbox AzaleaGym_Text_JOSHAfterBattle, MSGBOX_AUTOCLOSE
	end

AzaleaGym_EventScript_AMYANDMAY1::
	trainerbattle_single TRAINER_JOHTO_TWINS_AMYANDMAY1, AzaleaGym_Text_AMYANDMAY1Seen, AzaleaGym_Text_AMYANDMAY1Beaten
	msgbox AzaleaGym_Text_AMYANDMAY1AfterBattle, MSGBOX_AUTOCLOSE
	end

AzaleaGym_EventScript_AMYANDMAY2::
	trainerbattle_single TRAINER_JOHTO_TWINS_AMYANDMAY2, AzaleaGym_Text_AMYANDMAY2Seen, AzaleaGym_Text_AMYANDMAY2Beaten
	msgbox AzaleaGym_Text_AMYANDMAY2AfterBattle, MSGBOX_AUTOCLOSE
	end

AzaleaGym_EventScript_Guide::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_BADGE10, AzaleaGym_EventScript_GuidePostVictory
	msgbox AzaleaGym_Text_GuideAdvice, MSGBOX_DEFAULT
	release
	end

AzaleaGym_EventScript_GuidePostVictory::
	msgbox AzaleaGym_Text_GuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ (3,13) and (6,13) decode collision-1 -- they are the statue wall tiles, read
@ facing north from (3,14)/(6,14), both collision-0 elevation-3.
AzaleaGym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_TRINITY_BADGE10, AzaleaGym_EventScript_GymStatueCertified
	goto AzaleaGym_EventScript_GymStatue
	end

AzaleaGym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_TRINITY_BADGE10, AzaleaGym_EventScript_GymStatueCertified
	goto AzaleaGym_EventScript_GymStatue
	end

AzaleaGym_EventScript_GymStatue::
	msgbox AzaleaGym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

AzaleaGym_EventScript_GymStatueCertified::
	msgbox AzaleaGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@ Text
@ ============================================================================
@ Adapts pokecrystal BugsyText_INeverLose -- the researcher's confidence is
@ GSC's, retargeted at a visiting CHAMPION.
AzaleaGym_Text_BugsyIntro:
	.string "BUGSY: I'm BUGSY.\p"
	.string "I never lose when it comes to\n"
	.string "bug POKéMON.\p"
	.string "…You're going to tell me you've\n"
	.string "seen everything JOHTO has and\l"
	.string "worse.\p"
	.string "Fine. Name me a bug type that\n"
	.string "isn't fragile.\p"
	.string "You can't, because everyone is\n"
	.string "taught they're all fragile, and\l"
	.string "nobody checks.\p"
	.string "I check. For a living.\p"
	.string "Let me show you what came out of\n"
	.string "the research.$"

@ GSC BugsyText_ResearchIncomplete.
AzaleaGym_Text_BugsyDefeat:
	.string "Whoa, amazing!\n"
	.string "You really are an expert.\p"
	.string "My research isn't complete yet.\p"
	.string "OK. You win. Take this BADGE.$"

AzaleaGym_Text_ReceivedHiveBadge:
	.string "{PLAYER} received the\n"
	.string "HIVEBADGE from BUGSY.$"

@ IMPORTANT adaptation. GSC's HIVEBADGE makes POKéMON up to L30 obey and
@ unlocks field CUT; in Trinity badges 9-16 are plain flags with no engine
@ effect at all, so this text must not promise one. It says so in character
@ instead, and points at the eight-badge INDIGO gate (S11).
AzaleaGym_Text_HiveBadgeInfo:
	.string "BUGSY: That's the HIVEBADGE.\p"
	.string "I'll skip the speech about how\n"
	.string "it makes traded POKéMON obey\l"
	.string "you. Yours already do.\p"
	.string "What it is, is data. Two of the\n"
	.string "eight, and INDIGO has to open\l"
	.string "the door.\p"
	.string "Here. Take this as well.$"

@ I_REUSABLE_TMS is TRUE in this build (include/config/item.h:25), so the
@ "won't wear out" line is accurate rather than GSC's "used only once".
@ S3-S9 RULE (pinned by S2): gym TM awards duplicate Act I sources, so award
@ dialogue must never presume the player has never seen the move.
AzaleaGym_Text_ExplainGigaDrain:
	.string "BUGSY: TM19. GIGA DRAIN.\p"
	.string "You may well have one already.\n"
	.string "Carry mine anyway.\p"
	.string "It's the move that made me stop\n"
	.string "thinking of bug and grass types\l"
	.string "as things that lose slowly.\p"
	.string "You don't out-damage anything\n"
	.string "with it. You out-last it. Half\l"
	.string "of what you take, you keep.\p"
	.string "Over enough turns that stops\n"
	.string "being a trick and starts being\l"
	.string "the reason you won.\p"
	.string "Teach it to whatever you like.\n"
	.string "It won't wear out.$"

@ Chapter pointer: S4 is GOLDENROD CITY / WHITNEY.
AzaleaGym_Text_BugsyPostBattle:
	.string "BUGSY: Write it down for me --\n"
	.string "which of mine gave you the most\l"
	.string "trouble? …SCIZOR. I thought so.\p"
	.string "Go west through ILEX FOREST and\n"
	.string "you'll come out on the road to\l"
	.string "GOLDENROD.\p"
	.string "WHITNEY keeps the GYM there.\n"
	.string "Don't let the smile fool you.$"

AzaleaGym_Text_BUG_CATCHER_BENNYSeen:
	.string "Bug POKéMON evolve\nyoung. So they get\pstronger that much\nfaster.$"

AzaleaGym_Text_BUG_CATCHER_BENNYBeaten:
	.string "Just evolving\nisn't enough!$"

AzaleaGym_Text_BUG_CATCHER_BENNYAfterBattle:
	.string "POKéMON get stronger if they\n"
	.string "evolve. Really!\p"
	.string "…Mine did. It just wasn't\n"
	.string "enough today.$"

AzaleaGym_Text_ALSeen:
	.string "Bug POKéMON are\ncool and tough!\pI'll prove it to\nyou!$"

AzaleaGym_Text_ALBeaten:
	.string "You proved how\ntough you are…$"

AzaleaGym_Text_ALAfterBattle:
	.string "They're so cool, but most people\n"
	.string "don't like bug POKéMON.\p"
	.string "I don't know why. You do,\n"
	.string "though. You looked happy the\l"
	.string "whole way through that.$"

AzaleaGym_Text_JOSHSeen:
	.string "You saved all the\nSLOWPOKE? Whew,\lyou're mighty!\pBut my grown-up\nPOKéMON are pretty\ltough too!$"

AzaleaGym_Text_JOSHBeaten:
	.string "Urrgggh!$"

AzaleaGym_Text_JOSHAfterBattle:
	.string "I guess I should teach them\n"
	.string "better moves…\p"
	.string "BUGSY writes down every match he\n"
	.string "loses. Maybe I should start.$"

AzaleaGym_Text_AMYANDMAY1Seen:
	.string "AMY: Hi! Are you\nchallenging the\lLEADER? No way!$"

AzaleaGym_Text_AMYANDMAY1Beaten:
	.string "AMY & MAY: Oh,\ndouble goodness!$"

AzaleaGym_Text_AMYANDMAY1AfterBattle:
	.string "AMY: You're really strong.\p"
	.string "Are all HOENN trainers like\n"
	.string "that? …Oh. Just you.$"

AzaleaGym_Text_AMYANDMAY2Seen:
	.string "MAY: You want to\nsee the LEADER?\lWe come first!$"

AzaleaGym_Text_AMYANDMAY2Beaten:
	.string "AMY & MAY: Oh,\ndouble goodness!$"

AzaleaGym_Text_AMYANDMAY2AfterBattle:
	.string "MAY: Our bug POKéMON lost.\n"
	.string "Oh, what a shame.\p"
	.string "Go on then. He's waiting.$"

@ Adapts AzaleaGymGuideText + vanilla RustboroCity_Gym_Text_GymGuideAdvice.
@ The level warning is a Trinity addition -- Act II opens at L58+.
AzaleaGym_Text_GuideAdvice:
	.string "Yo, challenger!\p"
	.string "BUGSY's young, but his knowledge\n"
	.string "of bug POKéMON is for real.\p"
	.string "…And you're the HOENN CHAMPION,\n"
	.string "and I'm about to explain type\l"
	.string "matchups to you. I'll do it\l"
	.string "anyway. It's my job.\p"
	.string "BUG types fall to FIRE, FLYING\n"
	.string "and ROCK.\p"
	.string "But watch the second type. Not\n"
	.string "one of his five is only BUG.\p"
	.string "SHUCKLE is part ROCK, so fire\n"
	.string "lands on it for ordinary damage\l"
	.string "instead of double -- and good\l"
	.string "luck denting it either way.\p"
	.string "They're LEVEL 58 and up. JOHTO\n"
	.string "doesn't start you gentle.$"

AzaleaGym_Text_GuidePostVictory:
	.string "Whoa! Straight through BUGSY!\p"
	.string "The HIVEBADGE is yours.\n"
	.string "Two of eight.\p"
	.string "I mentioned the second type.\n"
	.string "I'm counting that as helping.$"

AzaleaGym_Text_GymStatue:
	.string "AZALEA TOWN POKéMON GYM\n"
	.string "LEADER: BUGSY\p"
	.string "The Walking Bug POKéMON\n"
	.string "Encyclopedia$"

AzaleaGym_Text_GymStatueCertified:
	.string "AZALEA TOWN POKéMON GYM\n"
	.string "LEADER: BUGSY\p"
	.string "BUGSY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
