@ ============================================================================
@ Trinity M5b S8 -- THE GYM PATTERN (G1-G7), PewterCity_Gym/scripts.inc's own
@ canonical shape, map/leader/badge/TM substituted. T10's 6 trainers
@ (Kayden/Shawn/Kirk/Edgar/Phil/Nate) reviewed, not re-placed -- ids/tiles/
@ wiring kept exactly as shipped, only their placeholder text replaced (G6).
@ See docs/superpowers/plans/m5b/08-fuchsia-safari.md section 2.
@
@ THE MAZE, TRUE-DECODED (brief-premise correction): pokefirered's actual
@ FuchsiaCity_Gym places Koga openly, no disguise-swap script anywhere --
@ the real "invisible-leader" gimmick is the collision-only invisible-wall
@ maze (RBY-canon, carried through FRLG), not an identity-swap mechanic.
@ reach_check.py FuchsiaCity_Gym --grid confirms it ported correctly: 244
@ walkable tiles, 244/244 reachable with no objects (one winding, fully
@ solvable component, not a disconnect). The brief's "hides among disguised
@ trainers" framing is carried as FLAVOR banter below (each trainer plays
@ coy about being the leader), not as a built mechanic -- there is no source
@ mechanic to build.
@ ============================================================================
FuchsiaCity_Gym_MapScripts::
	.byte 0

@ ============================================================================
@ G1 -- JANINE. (7,13), pokefirered's own KOGA coordinate (decoded TRUE in
@ this tree's own bytes: col=0 elev=3 MB_NORMAL, all four neighbours open
@ floor -- deep in the maze interior, matching the "hard to find" framing
@ honestly, a real topological fact). Appended as the map's 8th object so no
@ existing local id shifts. TRAINER_TYPE_NONE, sight 0, flag 0,
@ MOVEMENT_TYPE_FACE_DOWN. No OBJ_EVENT_GFX_JANINE exists in this tree;
@ OBJ_EVENT_GFX_PHOEBE substitutes -- an EXACT match to TRAINER_JANINE's own
@ .trainerPic (TRAINER_PIC_ELITE_FOUR_PHOEBE, trainers.party:25551), the
@ same overworld/battle-identity-match rule Brock's OBJ_EVENT_GFX_ROXANNE
@ and Erika's own OBJ_EVENT_GFX_PHOEBE follow (this tree's own established
@ convention already reuses named female sprites across multiple leaders).
@ ============================================================================
FuchsiaCity_Gym_EventScript_Janine::
	trainerbattle_single TRAINER_JANINE, FuchsiaCity_Gym_Text_JanineSeen, FuchsiaCity_Gym_Text_JanineBeaten, FuchsiaCity_Gym_EventScript_JanineDefeated, NO_MUSIC
	goto_if_unset FLAG_TRINITY_K_JANINE_TM06, FuchsiaCity_Gym_EventScript_GiveTM06
	msgbox FuchsiaCity_Gym_Text_JaninePostBattle, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_EventScript_JanineDefeated::
	message FuchsiaCity_Gym_Text_ReceivedSoulBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_TRINITY_BADGE21
	msgbox FuchsiaCity_Gym_Text_SoulBadgeInfo, MSGBOX_DEFAULT
	goto FuchsiaCity_Gym_EventScript_GiveTM06
	end

FuchsiaCity_Gym_EventScript_GiveTM06::
	giveitem ITEM_TM_TOXIC
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_K_JANINE_TM06
	msgbox FuchsiaCity_Gym_Text_ExplainToxic, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ G6 -- the six gym trainers. T10 left them re-showing their own Beaten
@ string verbatim on re-talk (the trainerbattle_single-fallthrough msgbox
@ reused the same string as the macro's own post-victory text). Each gets a
@ genuinely distinct third (_PostBattle) string. Flavor plays "claims to be
@ the leader" honestly as banter -- no type claims made for any of them
@ (rosters are Hypno/Alakazam/Arbok/Sandslash, unrelated to Janine's
@ Poison line, so no matchup assertion is warranted).
@ ============================================================================
FuchsiaCity_Gym_EventScript_Kayden::
	trainerbattle_single TRAINER_KANTO_JUGGLER_KAYDEN, FuchsiaCity_Gym_Text_KaydenSeen, FuchsiaCity_Gym_Text_KaydenBeaten
	msgbox FuchsiaCity_Gym_Text_KaydenPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_KANTO_JUGGLER_SHAWN, FuchsiaCity_Gym_Text_ShawnSeen, FuchsiaCity_Gym_Text_ShawnBeaten
	msgbox FuchsiaCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KANTO_JUGGLER_KIRK, FuchsiaCity_Gym_Text_KirkSeen, FuchsiaCity_Gym_Text_KirkBeaten
	msgbox FuchsiaCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Edgar::
	trainerbattle_single TRAINER_KANTO_TAMER_EDGAR, FuchsiaCity_Gym_Text_EdgarSeen, FuchsiaCity_Gym_Text_EdgarBeaten
	msgbox FuchsiaCity_Gym_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Phil::
	trainerbattle_single TRAINER_KANTO_TAMER_PHIL, FuchsiaCity_Gym_Text_PhilSeen, FuchsiaCity_Gym_Text_PhilBeaten
	msgbox FuchsiaCity_Gym_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_KANTO_JUGGLER_NATE, FuchsiaCity_Gym_Text_NateSeen, FuchsiaCity_Gym_Text_NateBeaten
	msgbox FuchsiaCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ G4 -- the guide. (11,19), T10-placed OBJ_EVENT_GFX_EXPERT_M, unmoved (its
@ own 1-tile self-cost only, not a cut vertex). Roster ARIADOS80/VENOMOTH80/
@ WEEZING81/MUK81/CROBAT82 verified against trainers.party + species_info +
@ types_info.h's own gTypeEffectivenessTable -- full derivation in the
@ sub-plan section 2.3. GROUND: only MUK takes the clean 2x (pure Poison, no
@ Levitate). ARIADOS/VENOMOTH (Bug/Poison) take it NEUTRAL -- their Bug half
@ resists exactly enough to cancel the Poison weakness (0.5 x 2.0 = 1.0).
@ WEEZING is immune via its Levitate ability (verified: no .ability override
@ in trainers.h, B_TRAINER_MON_RANDOM_ABILITY FALSE, so abilityNum defaults
@ to slot 0 = ABILITY_LEVITATE, src/battle_main.c:1925-1972). CROBAT is
@ immune via its own Flying typing (0x). PSYCHIC: a clean 2x on all FIVE, no
@ exceptions (Bug does not resist Psychic in this chart).
@ ============================================================================
FuchsiaCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_BADGE21, FuchsiaCity_Gym_EventScript_GymGuyPostVictory
	msgbox FuchsiaCity_Gym_Text_GymGuyAdvice, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_EventScript_GymGuyPostVictory::
	msgbox FuchsiaCity_Gym_Text_GymGuyPostVictory, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ G5 -- the statues. (4,19)/(10,19) decode col=1 MB_SIGNPOST (T10-placed,
@ correct), both north/south neighbours open floor. BG_EVENT_PLAYER_FACING_
@ NORTH set in map.json (the south-approach tile) -- matches the milestone's
@ own established two-statue convention (Vermilion/Cerulean/Pewter), a
@ house-convention match, not hazard-driven (this gym has no water/hazard
@ gimmick either).
@ ============================================================================
FuchsiaCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_TRINITY_BADGE21, FuchsiaCity_Gym_EventScript_GymStatueCertified
	msgbox FuchsiaCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FuchsiaCity_Gym_EventScript_GymStatue_2::
	lockall
	goto_if_set FLAG_TRINITY_BADGE21, FuchsiaCity_Gym_EventScript_GymStatueCertified
	msgbox FuchsiaCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FuchsiaCity_Gym_EventScript_GymStatueCertified::
	msgbox FuchsiaCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@ Text
@ ============================================================================
FuchsiaCity_Gym_Text_JanineSeen:
	.string "Two Leagues down, and you still\n"
	.string "walked into my gym like it was\l"
	.string "nothing.\p"
	.string "I'm JANINE. My POKéMON don't miss\n"
	.string "when they strike -- and neither\l"
	.string "do I.\p"
	.string "Let's see how you handle POISON.$"

FuchsiaCity_Gym_Text_JanineBeaten:
	.string "…Not bad. Not many make it\n"
	.string "through my gym at all, let alone\l"
	.string "through me.$"

FuchsiaCity_Gym_Text_ReceivedSoulBadge:
	.string "{PLAYER} received the\n"
	.string "SOULBADGE from JANINE.$"

FuchsiaCity_Gym_Text_SoulBadgeInfo:
	.string "JANINE: The SOULBADGE.\p"
	.string "Doesn't make you stronger. Just\n"
	.string "means KANTO's noticed you.\p"
	.string "Seven of these, and VIRIDIAN opens\n"
	.string "the door.\p"
	.string "Take this too -- you earned it.$"

FuchsiaCity_Gym_Text_ExplainToxic:
	.string "JANINE: TM06. TOXIC.\p"
	.string "Badly poisons whatever it hits.\n"
	.string "The longer the fight drags on,\l"
	.string "the worse it gets.\p"
	.string "Teach it to whoever you like.\n"
	.string "It won't wear out.$"

FuchsiaCity_Gym_Text_JaninePostBattle:
	.string "You've got good instincts. Sharp\n"
	.string "ones, even.\p"
	.string "FUCHSIA doesn't get many visitors\n"
	.string "worth remembering. You're one.$"

FuchsiaCity_Gym_Text_KaydenSeen:
	.string "You looking for the real gym\n"
	.string "leader? Might be me. Might not.$"

FuchsiaCity_Gym_Text_KaydenBeaten:
	.string "…Wasn't me. Guess you'll have\n"
	.string "to keep guessing.$"

FuchsiaCity_Gym_Text_KaydenPostBattle:
	.string "Still not the leader. Still not\n"
	.string "telling you who is.$"

FuchsiaCity_Gym_Text_ShawnSeen:
	.string "Every one of us dresses the same\n"
	.string "on purpose. Confusing, isn't it?$"

FuchsiaCity_Gym_Text_ShawnBeaten:
	.string "Confusing AND losing, apparently.$"

FuchsiaCity_Gym_Text_ShawnPostBattle:
	.string "The real one's still out there.\n"
	.string "Somewhere.$"

FuchsiaCity_Gym_Text_KirkSeen:
	.string "Four POKéMON, one ninja. None of\n"
	.string "them are lying about who's in\l"
	.string "charge.$"

FuchsiaCity_Gym_Text_KirkBeaten:
	.string "Fine, fine. Not the leader.\n"
	.string "Never claimed to be, really.$"

FuchsiaCity_Gym_Text_KirkPostBattle:
	.string "These walls fooled better\n"
	.string "trainers than you. Eventually.$"

FuchsiaCity_Gym_Text_EdgarSeen:
	.string "COOLTRAINERs get lost in this gym\n"
	.string "as much as anyone. Ready?$"

FuchsiaCity_Gym_Text_EdgarBeaten:
	.string "Lost the battle too, then.\n"
	.string "Story of my week.$"

FuchsiaCity_Gym_Text_EdgarPostBattle:
	.string "Still haven't found the way out\n"
	.string "myself, half the time.$"

FuchsiaCity_Gym_Text_PhilSeen:
	.string "My partner EDGAR and I trade wins\n"
	.string "around here. Your turn to lose\l"
	.string "one.$"

FuchsiaCity_Gym_Text_PhilBeaten:
	.string "Guess that's a win for you and a\n"
	.string "story for me.$"

FuchsiaCity_Gym_Text_PhilPostBattle:
	.string "Tell EDGAR I put up a fight, at\n"
	.string "least.$"

FuchsiaCity_Gym_Text_NateSeen:
	.string "Last one standing between you and\n"
	.string "whoever's actually in charge.\l"
	.string "Or is that me?$"

FuchsiaCity_Gym_Text_NateBeaten:
	.string "It's not me. Sorry to disappoint\n"
	.string "-- she's further in.$"

FuchsiaCity_Gym_Text_NatePostBattle:
	.string "Careful in there. The walls\n"
	.string "don't announce themselves.$"

FuchsiaCity_Gym_Text_GymGuyAdvice:
	.string "Hiya! Here to challenge JANINE?\p"
	.string "ARIADOS, VENOMOTH, WEEZING, MUK,\n"
	.string "CROBAT -- LEVEL 82 to 84, all\l"
	.string "carrying POISON.\p"
	.string "PSYCHIC's your cleanest answer.\n"
	.string "Every one of them takes it hard.\p"
	.string "GROUND looks tempting, but only\n"
	.string "MUK really feels it. The other\l"
	.string "four shrug it off, each for its\l"
	.string "own reason.$"

FuchsiaCity_Gym_Text_GymGuyPostVictory:
	.string "Straight through JANINE! Figured\n"
	.string "as much.\p"
	.string "SOULBADGE. One of seven.$"

FuchsiaCity_Gym_Text_GymStatue:
	.string "FUCHSIA CITY POKéMON GYM\n"
	.string "LEADER: JANINE\p"
	.string "Master of Poison POKéMON$"

FuchsiaCity_Gym_Text_GymStatueCertified:
	.string "FUCHSIA CITY POKéMON GYM\n"
	.string "LEADER: JANINE\p"
	.string "JANINE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
