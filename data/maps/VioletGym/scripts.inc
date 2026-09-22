VioletGym_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S2 -- THE GYM PATTERN (G1-G7). This map is the template for the
@ seven remaining Johto gyms (S3 BUGSY, S4 WHITNEY, S5 MORTY, S6 CHUCK +
@ JASMINE, S7 PRYCE, S9 CLAIR). Copy this file's shape verbatim, substituting
@ only the map name, leader, badge flag, TM and type. The full rationale lives
@ in docs/superpowers/plans/m4b/02-violet-chapter.md section 2.
@
@ G1  Leader object: TRAINER_TYPE_NONE, sight 0, flag 0, at the GSC tile.
@     TALK-triggered, never sight-triggered -- both references agree (GSC's
@     Falkner is OBJECTTYPE_SCRIPT, vanilla Roxanne is TRAINER_TYPE_NONE), and
@     a sight line here would fire mid-approach and could seal the gallery.
@     Appended to object_events so M4a's local ids do not shift.
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
@     trainerbattle passes NO_MUSIC, because that swap belongs to a sight
@     line, not to a conversation. Leaders are always talked to, so MUS_GYM
@     holds until the battle theme takes over.
@     Battle BGM still needs no scripting: GetBattleBGM()'s
@     TRAINER_CLASS_LEADER case carries a Trinity id-range guard -- trainer
@     ids TRAINER_FALKNER..TRAINER_CLAIR (1030-1037, the eight Johto leaders,
@     contiguous) return MUS_RG_VS_GYM_LEADER, everything else keeps Hoenn's
@     MUS_VS_GYM_LEADER (src/pokemon.c, GetBattleBGM). This satisfies the M4b
@     contract's gym-music pin for all eight gyms with zero per-map scripting,
@     and cannot touch Act I.
@
@ G4  Gym guide: OBJ_EVENT_GFX_EXPERT_M, two states on the badge flag, and the
@     advice text states the leader's type, its weaknesses AND the roster's
@     level band (Act II opens at L58+).
@     Tile: (7,12). M4a's port put him on (7,13), which is the mouth of the
@     (7,12)/(8,13)/(9,13) nook -- standing there sealed all three tiles off.
@     Found by the S3 backfill with tools/johto_port/reach_check.py and nudged
@     one tile north, which seals nothing (86 reachable tiles vs 83). The nook
@     is empty decorative floor, so nothing was lost while he stood there, but
@     G4 does not pin the tile and a guide should not be a wall.
@
@ G5  Gym statues: sign bg_events on the collision-1 statue tiles, read facing
@     north from the walkable row below, two states on the badge flag. Badges
@     9-16 have NO engine UI, so this in-world readback is the only
@     confirmation the player ever gets that the flag was set.
@
@ G6  M4a's gym trainers keep their ids/tiles/seen+beaten text and gain a
@     distinct post-battle line (the port left them re-showing the defeat text).
@
@ G7  Only <Leader>Defeated ever WRITES FLAG_TRINITY_BADGE09. Everything else
@     -- guide, statues, gate NPCs, S8's counter -- reads it only.
@ ============================================================================

VioletGym_EventScript_Falkner::
	trainerbattle_single TRAINER_FALKNER, VioletGym_Text_FalknerIntro, VioletGym_Text_FalknerDefeat, VioletGym_EventScript_FalknerDefeated, NO_MUSIC
	@ Re-talk path only: the engine's trainer-defeated flag already gated the
	@ continuation above, so execution reaches here on a LATER talk. Retry the
	@ TM if the bag was full the first time, else the post-badge line.
	goto_if_unset FLAG_TRINITY_J_FALKNER_TM40, VioletGym_EventScript_GiveAerialAce
	msgbox VioletGym_Text_FalknerPostBattle, MSGBOX_DEFAULT
	release
	end

VioletGym_EventScript_FalknerDefeated::
	message VioletGym_Text_ReceivedZephyrBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_TRINITY_BADGE09
	msgbox VioletGym_Text_ZephyrBadgeInfo, MSGBOX_DEFAULT
	goto VioletGym_EventScript_GiveAerialAce
	end

VioletGym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_J_FALKNER_TM40
	msgbox VioletGym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	release
	end

VioletGym_EventScript_ROD::
	trainerbattle_single TRAINER_JOHTO_BIRD_KEEPER_ROD, VioletGym_Text_RODSeen, VioletGym_Text_RODBeaten
	msgbox VioletGym_Text_RODAfterBattle, MSGBOX_AUTOCLOSE
	end

VioletGym_EventScript_ABE::
	trainerbattle_single TRAINER_JOHTO_BIRD_KEEPER_ABE, VioletGym_Text_ABESeen, VioletGym_Text_ABEBeaten
	msgbox VioletGym_Text_ABEAfterBattle, MSGBOX_AUTOCLOSE
	end

VioletGym_EventScript_Guide::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_BADGE09, VioletGym_EventScript_GuidePostVictory
	msgbox VioletGym_Text_GuideAdvice, MSGBOX_DEFAULT
	release
	end

@ M7b Task 15 (finding #6): the guide states the player's LIVE badge count.
@ The tally reads the flags and buffers the number itself -- see
@ data/scripts/trinity_johto.inc.
VioletGym_EventScript_GuidePostVictory::
	msgbox VioletGym_Text_GuidePostVictory, MSGBOX_DEFAULT
	call Trinity_EventScript_JohtoBadgeTally
	@ M7b Task 14 (finding #9): once the badge is won this guide doubles as
	@ a pointer. The branch above is already the badge flag, so nothing new
	@ is read or written here; the ladder releases for us.
	goto Trinity_EventScript_JohtoGuide
	end

@ (3,13) and (6,13) decode collision-1 -- they are the statue wall tiles, read
@ facing north from (3,14)/(6,14), both collision-0 elevation-3.
VioletGym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_TRINITY_BADGE09, VioletGym_EventScript_GymStatueCertified
	goto VioletGym_EventScript_GymStatue
	end

VioletGym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_TRINITY_BADGE09, VioletGym_EventScript_GymStatueCertified
	goto VioletGym_EventScript_GymStatue
	end

VioletGym_EventScript_GymStatue::
	msgbox VioletGym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

VioletGym_EventScript_GymStatueCertified::
	msgbox VioletGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@ Text
@ ============================================================================
@ Adapts pokecrystal FalknerIntroText -- the "clip a flying type's wings with
@ electricity" insult is GSC's, retargeted at a visiting CHAMPION.
VioletGym_Text_FalknerIntro:
	.string "FALKNER: So it's true.\p"
	.string "The HOENN CHAMPION, standing in\n"
	.string "my father's GYM.\p"
	.string "People say you can clip a flying\n"
	.string "type's wings with one jolt of\l"
	.string "electricity.\p"
	.string "People say a great many things\n"
	.string "about bird POKéMON. Most of it\l"
	.string "is an insult.\p"
	.string "I'm FALKNER. I keep the first\n"
	.string "GYM in JOHTO, and I have never\l"
	.string "once opened it easy.\p"
	.string "Let me show you what the sky is\n"
	.string "actually worth.$"

@ GSC FalknerWinLossText.
VioletGym_Text_FalknerDefeat:
	.string "…Darn.\p"
	.string "My father's cherished bird\n"
	.string "POKéMON…\p"
	.string "All right. Take this.\n"
	.string "You earned it in front of them.$"

VioletGym_Text_ReceivedZephyrBadge:
	.string "{PLAYER} received the\n"
	.string "ZEPHYRBADGE from FALKNER.$"

@ IMPORTANT adaptation. GSC's ZEPHYRBADGE raises ATTACK and unlocks field
@ FLASH; in Trinity badges 9-16 are plain flags with no engine effect at all,
@ so this text must not promise one. It says so in character instead, and
@ seeds the seven-badge Radio Tower beat (S8) and the eight-badge INDIGO
@ gate (S11).
VioletGym_Text_ZephyrBadgeInfo:
	.string "FALKNER: That's the ZEPHYRBADGE.\p"
	.string "It won't make your POKéMON hit\n"
	.string "harder. You are long past the\l"
	.string "point where a badge could.\p"
	.string "Here it means something simpler.\n"
	.string "Eight of them, and the LEAGUE at\l"
	.string "INDIGO has to open the door.\p"
	.string "That's one.\n"
	.string "Here -- take this as well.$"

@ I_REUSABLE_TMS is TRUE in this build (include/config/item.h:25), so the
@ "won't wear out" line is accurate rather than GSC's "used only once".
@ S3-S9 RULE: gym TM awards duplicate Act I sources, so award dialogue must
@ never presume the player has never seen the move. Frame the leader as a
@ master handing on their own technique, which reads correctly whether this
@ is the player's first copy or their fourth.
VioletGym_Text_ExplainAerialAce:
	.string "FALKNER: TM40. AERIAL ACE.\p"
	.string "You may well have one already.\n"
	.string "Carry mine anyway.\p"
	.string "My father taught it as a matter\n"
	.string "of patience. You don't chase the\l"
	.string "opening -- you wait, and the sky\l"
	.string "gives you one.\p"
	.string "Struck that way it does not miss.\n"
	.string "Not through sand, not through\l"
	.string "smoke, not against anything that\l"
	.string "thinks dodging is a strategy.\p"
	.string "Teach it to whatever you like.\n"
	.string "It won't wear out.$"

@ Chapter pointer: S3 is AZALEA TOWN / BUGSY.
VioletGym_Text_FalknerPostBattle:
	.string "FALKNER: Seven more GYMS between\n"
	.string "here and INDIGO, and not one of\l"
	.string "them will be as polite as I was.\p"
	.string "BUGSY is next. AZALEA TOWN,\n"
	.string "south past the RUINS OF ALPH.\p"
	.string "I'll keep training. One day\n"
	.string "someone will say bird master and\l"
	.string "mean it.$"

VioletGym_Text_RODSeen:
	.string "The keyword is\nguts!\pThose here are\ntraining night and\pday to become bird\nPOKéMON masters.\pCome on!$"

VioletGym_Text_RODBeaten:
	.string "Gaaah!$"

VioletGym_Text_RODAfterBattle:
	.string "FALKNER's skills are for real.\p"
	.string "Don't get cocky just because you\n"
	.string "went through me!$"

VioletGym_Text_ABESeen:
	.string "Let me see if you\nare good enough to\lface FALKNER!$"

VioletGym_Text_ABEBeaten:
	.string "This can't be\ntrue!$"

VioletGym_Text_ABEAfterBattle:
	.string "This is pathetic. Losing to some\n"
	.string "rookie…\p"
	.string "…To the CHAMPION.\n"
	.string "Fine. That one's allowed.$"

@ Adapts VioletGymGuideText + vanilla RustboroCity_Gym_Text_GymGuideAdvice.
@ The level warning is a Trinity addition -- Act II opens at L58+ and this is
@ the first Johto gym a player will walk into.
VioletGym_Text_GuideAdvice:
	.string "Hey! I'm no TRAINER, but giving\n"
	.string "advice is a job too.\p"
	.string "…Hold on. I know that jacket.\p"
	.string "You're the HOENN CHAMPION and\n"
	.string "I'm about to explain type\l"
	.string "matchups to you.\p"
	.string "I'll do it anyway. It's my job.\p"
	.string "FALKNER uses FLYING types. They\n"
	.string "beat GRASS, BUG and FIGHTING.\p"
	.string "They fall to ELECTRIC, ICE and\n"
	.string "ROCK.\p"
	.string "And his birds are LEVEL 58 and\n"
	.string "up. JOHTO doesn't start you\l"
	.string "gentle.\p"
	.string "Come see me after. I want to be\n"
	.string "able to say I helped.$"

VioletGym_Text_GuidePostVictory:
	.string "Whoa! Straight through FALKNER!\p"
	.string "The ZEPHYRBADGE is yours.\n"
	.string "One of eight.\p"
	.string "I helped.\n"
	.string "I'm telling everyone I helped.$"

VioletGym_Text_GymStatue:
	.string "VIOLET CITY POKéMON GYM\n"
	.string "LEADER: FALKNER\p"
	.string "The Elegant Master of\n"
	.string "Flying POKéMON$"

VioletGym_Text_GymStatueCertified:
	.string "VIOLET CITY POKéMON GYM\n"
	.string "LEADER: FALKNER\p"
	.string "FALKNER'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
