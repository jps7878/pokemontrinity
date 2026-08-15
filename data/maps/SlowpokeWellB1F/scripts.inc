SlowpokeWellB1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlowpokeWellB1F_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S3 -- the SLOWPOKE WELL raid, the first TEAM ROCKET beat.
@ Adapts pokecrystal maps/SlowpokeWellB1F.asm (four grunt posts, the tail-cut
@ SLOWPOKE, and KURT's fall). GSC's raid-ender is a grunt; Act II promotes it
@ to TRAINER_EXEC_PROTON, with the three grunts demoted to optional sight
@ posts on the way in.
@
@ Arc gating. The contract's arc enum makes this raid the ONLY writer of
@ state 3 and puts nothing between 2 and 3, so "available at ARC >= 2, cleared
@ => ARC 3" is exactly the predicate ARC == 2. ON_TRANSITION is the SINGLE
@ AUTHORITY for FLAG_TRINITY_J_WELL_RAID_HIDE (S1 rule): the scene body only
@ ever addobject/removeobject, it never writes a visibility flag.
@ ============================================================================
SlowpokeWellB1F_OnTransition:
	@ The rescued-KURT actor is an addobject-only cutscene actor. Setting its
	@ flag on every transition (ON_TRANSITION runs before InitMap and object
	@ spawning) means no new-game flag default is needed -- S1's idiom.
	setflag FLAG_TRINITY_J_WELL_KURT_END_HIDE
	goto_if_eq VAR_TRINITY_JOHTO_ARC, 2, SlowpokeWellB1F_EventScript_ShowRaid
	setflag FLAG_TRINITY_J_WELL_RAID_HIDE
	end

SlowpokeWellB1F_EventScript_ShowRaid::
	clearflag FLAG_TRINITY_J_WELL_RAID_HIDE
	end

@ ============================================================================
@ KURT, at the foot of the entrance shaft. GSC canon verbatim: he shouted the
@ guard off the top, fell in after him and landed on his back.
@ ============================================================================
SlowpokeWellB1F_EventScript_KurtHurt::
	msgbox SlowpokeWellB1F_Text_KurtHurt, MSGBOX_NPC
	end

@ ============================================================================
@ The three optional grunt posts. Sight-triggered ordinary trainers, exactly
@ the M4a gym-trainer shape, so PlayTrainerEncounterMusic doing its map-BGM
@ swap is correct here -- that swap belongs to a sight line (GYM PATTERN G3).
@ Pool ids: S3 owns TRAINER_ROCKET_GRUNT_M_1 / M_2 / F_1 exclusively, because
@ the raid can be ended (see EventScript_RaidCleared) with these three still
@ unbeaten and their beaten-flags are per-id.
@ ============================================================================
SlowpokeWellB1F_EventScript_GruntA::
	trainerbattle_single TRAINER_ROCKET_GRUNT_M_1, SlowpokeWellB1F_Text_GruntASeen, SlowpokeWellB1F_Text_GruntABeaten
	msgbox SlowpokeWellB1F_Text_GruntAAfterBattle, MSGBOX_AUTOCLOSE
	end

SlowpokeWellB1F_EventScript_GruntB::
	trainerbattle_single TRAINER_ROCKET_GRUNT_F_1, SlowpokeWellB1F_Text_GruntBSeen, SlowpokeWellB1F_Text_GruntBBeaten
	msgbox SlowpokeWellB1F_Text_GruntBAfterBattle, MSGBOX_AUTOCLOSE
	end

SlowpokeWellB1F_EventScript_GruntC::
	trainerbattle_single TRAINER_ROCKET_GRUNT_M_2, SlowpokeWellB1F_Text_GruntCSeen, SlowpokeWellB1F_Text_GruntCBeaten
	msgbox SlowpokeWellB1F_Text_GruntCAfterBattle, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ EXEC PROTON -- talk-triggered boss.
@
@ Player-tile normalisation WITHOUT a movement script. (5,2)'s four neighbours
@ are (5,1) [collision 1], (4,2), (6,2) and (5,3). Both tail-cut SLOWPOKE rest
@ on (4,2) and (6,2) -- GSC already parks one of them at (6,2), beside the
@ ranking Rocket -- so (5,3) is the ONLY tile PROTON can be talked to from.
@ The scene body can therefore assume the player is standing at (5,3) facing
@ north, with the viewport covering rows -1..8 / columns -2..12.
@ (No-sealing check: with (4,2)/(5,2)/(6,2) occupied, (3,2) is still reached
@ via (2,2)<-(2,3) and (7,2) via (7,3); the chamber is open on rows 3-6.)
@
@ NO_MUSIC, not trainerbattle_no_intro. The contract pins MUS_RG_ENCOUNTER_
@ ROCKET for Rockets, and NO_MUSIC selects TRAINER_BATTLE_CONTINUE_SCRIPT_
@ NO_MUSIC, the one mode PlayTrainerEncounterMusic early-outs on
@ (src/battle_setup.c:1451-1452) -- so the playbgm below survives the intro
@ text and the battle transition. The `trainerbattle_no_intro` form would NOT --
@ it resolves to EventScript_DoNoIntroTrainerBattle, whose mode is
@ TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, so its `special PlayTrainerEncounterMusic`
@ (data/scripts/trainer_battle.inc:53) fires and swaps in the trainer's
@ `Music:` track instead.
@ Note that trainerbattle_single, unlike the no-intro form, supplies its own
@ lock/faceplayer (data/scripts/trainer_battle.inc:10-12), so this script must
@ NOT lock first;
@ only the idle branch locks, and the continuation ends with `release`.
@ ============================================================================
SlowpokeWellB1F_EventScript_Proton::
	@ Talk-guard rule (S1): a talk script that starts a battle and advances
	@ story state carries an explicit state check even when a visibility flag
	@ already makes the bad path unreachable.
	goto_if_ne VAR_TRINITY_JOHTO_ARC, 2, SlowpokeWellB1F_EventScript_ProtonIdle
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	trainerbattle_single TRAINER_EXEC_PROTON, SlowpokeWellB1F_Text_ProtonIntro, SlowpokeWellB1F_Text_ProtonDefeat, SlowpokeWellB1F_EventScript_RaidCleared, NO_MUSIC
	@ INTENTIONALLY UNREACHABLE / DEFENSIVE. This is the already-defeated
	@ fall-through, and it cannot be reached: RaidCleared removeobject's PROTON
	@ and drives VAR_TRINITY_JOHTO_ARC to 3, which makes ON_TRANSITION set the
	@ raid hide flag on every later entry, so there is never an object here to
	@ talk to a second time.
	goto SlowpokeWellB1F_EventScript_ProtonIdle
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE -- see above.
SlowpokeWellB1F_EventScript_ProtonIdle::
	lock
	faceplayer
	msgbox SlowpokeWellB1F_Text_ProtonIdle, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ Raid aftermath. Adapts SlowpokeWellB1F.asm:34-72 -- GSC fades to black,
@ disappears all four Rockets at once, then walks KURT in. Removing the three
@ grunts whether or not they were beaten is GSC's own behaviour (:41-44): the
@ raid ends when its leader breaks, and the side fights stay optional.
@ The two tail-cut SLOWPOKE are deliberately left standing for the rest of the
@ visit; ON_TRANSITION retires them on the next entry and KURT's line covers it.
@ ============================================================================
SlowpokeWellB1F_EventScript_RaidCleared::
	msgbox SlowpokeWellB1F_Text_ProtonRetreat, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_JOHTO_WELL_PROTON
	removeobject LOCALID_JOHTO_WELL_GRUNT_A
	removeobject LOCALID_JOHTO_WELL_GRUNT_B
	removeobject LOCALID_JOHTO_WELL_GRUNT_C
	@ The hurt KURT at the entrance shaft (16,14) is the SAME man who is about to
	@ walk in here, so he has to go in the same breath -- otherwise the player
	@ walks back out and finds him still lying at the bottom of the shaft after
	@ he has just said he was going home. Off-screen, so the removal is unseen.
	removeobject LOCALID_JOHTO_WELL_KURT
	@ S1's ElmsLab idiom: addobject the cutscene actor, then buffer a delay
	@ before the first applymovement. Done INSIDE the fade, so KURT is already
	@ standing at (6,6) when the screen comes back rather than popping in --
	@ GSC does the same (disappear/moveobject/appear all sit inside its fade).
	addobject LOCALID_JOHTO_WELL_KURT_END
	fadescreen FADE_FROM_BLACK
	delay 20
	applymovement LOCALID_JOHTO_WELL_KURT_END, SlowpokeWellB1F_Movement_KurtComesUp
	waitmovement 0
	applymovement LOCALID_PLAYER, SlowpokeWellB1F_Movement_PlayerFaceSouth
	waitmovement 0
	msgbox SlowpokeWellB1F_Text_KurtGratitude, MSGBOX_DEFAULT
	closemessage
	call SlowpokeWellB1F_EventScript_RaidAftermath
	applymovement LOCALID_JOHTO_WELL_KURT_END, SlowpokeWellB1F_Movement_KurtHeadsHome
	waitmovement 0
	removeobject LOCALID_JOHTO_WELL_KURT_END
	fadedefaultbgm
	special HealPlayerParty
	release
	end

@ Arc-var monotonic guard (S1 rule): every setvar on VAR_TRINITY_JOHTO_ARC sits
@ behind a goto_if_ge on the value it is about to write.
SlowpokeWellB1F_EventScript_RaidAftermath::
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 3, SlowpokeWellB1F_EventScript_RaidAftermathDone
	setvar VAR_TRINITY_JOHTO_ARC, 3
	setvar VAR_TRINITY_JOHTO_SCENE_AZALEA, 1
SlowpokeWellB1F_EventScript_RaidAftermathDone::
	return

@ (6,6) -> (5,6) -> (5,5) -> (5,4): one tile west onto the corridor GRUNT_C was
@ standing on (removed above), then two north to stop directly behind the player
@ at (5,3). Every tile decoded collision 0.
SlowpokeWellB1F_Movement_KurtComesUp:
	walk_left
	walk_up
	walk_up
	step_end

SlowpokeWellB1F_Movement_KurtHeadsHome:
	walk_down
	walk_down
	walk_right
	step_end

SlowpokeWellB1F_Movement_PlayerFaceSouth:
	face_down
	step_end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE. The rescued-KURT actor exists only
@ inside EventScript_RaidCleared, which holds the player lock from addobject to
@ removeobject, so this talk script can never run. It exists because every
@ object_event needs a resolvable script label.
SlowpokeWellB1F_EventScript_KurtRescued::
	msgbox SlowpokeWellB1F_Text_KurtGratitude, MSGBOX_NPC
	end

@ ============================================================================
@ The tail-cut SLOWPOKE. No faceplayer -- a SLOWPOKE does not turn for anybody.
@ ============================================================================
SlowpokeWellB1F_EventScript_Slowpoke::
	lock
	msgbox SlowpokeWellB1F_Text_Slowpoke, MSGBOX_DEFAULT
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
	waitmoncry
	release
	end

@ ============================================================================
@ Text
@ ============================================================================
@ GSC SlowpokeWellB1FKurtText, kept nearly verbatim -- this is the canon beat
@ (he shouted the guard off the top, fell in, landed on his back).
SlowpokeWellB1F_Text_KurtHurt:
	.string "KURT: Hey. You're the one from\n"
	.string "HOENN, aren't you.\p"
	.string "The lookout up top took off the\n"
	.string "second I started shouting.\p"
	.string "Then I came down after him and\n"
	.string "found the shaft the hard way.\p"
	.string "Landed flat on my back. I can't\n"
	.string "stand up straight, never mind\l"
	.string "throw a POKé BALL.\p"
	.string "Rats. Thirty years ago I'd have\n"
	.string "cleared this well myself.\p"
	.string "So do it for me, CHAMPION.\n"
	.string "Every SLOWPOKE down there is one\l"
	.string "of ours.$"

@ Adapts GSC GruntM29SeenText -- the grunt who got startled off the top by KURT.
SlowpokeWellB1F_Text_GruntASeen:
	.string "Some old man came roaring down\n"
	.string "the shaft at me and I bolted.\p"
	.string "Do you know how that looks?\p"
	.string "I'm taking it out on somebody,\n"
	.string "and you'll do.$"

SlowpokeWellB1F_Text_GruntABeaten:
	.string "Arrgh! This is NOT my day!$"

SlowpokeWellB1F_Text_GruntAAfterBattle:
	.string "Fine. Yes. We've been cutting\n"
	.string "the TAILS off SLOWPOKE and\l"
	.string "selling them.\p"
	.string "They grow back. Everything we do\n"
	.string "is for profit.\p"
	.string "That's TEAM ROCKET. We'll do\n"
	.string "anything for money.$"

@ Adapts GSC GruntF1SeenText.
SlowpokeWellB1F_Text_GruntBSeen:
	.string "Stop taking TAILS?\p"
	.string "There are four of us down here\n"
	.string "and one of you. Try it.$"

SlowpokeWellB1F_Text_GruntBBeaten:
	.string "You rotten -- \n"
	.string "…you're the CHAMPION.$"

SlowpokeWellB1F_Text_GruntBAfterBattle:
	.string "Nobody told me the HOENN LEAGUE\n"
	.string "was going to walk in here.\p"
	.string "Talk to PROTON. He's the one who\n"
	.string "gives the orders. Deepest part\l"
	.string "of the well, past the pools.$"

@ Adapts GSC GruntM2SeenText.
SlowpokeWellB1F_Text_GruntCSeen:
	.string "Quit taking SLOWPOKETAILS?\p"
	.string "If we did what people told us,\n"
	.string "TEAM ROCKET wouldn't be worth\l"
	.string "the name.$"

SlowpokeWellB1F_Text_GruntCBeaten:
	.string "Just… too strong…$"

SlowpokeWellB1F_Text_GruntCAfterBattle:
	.string "We need the money. But selling\n"
	.string "SLOWPOKETAILS?\p"
	.string "It's a hard living, being a\n"
	.string "ROCKET GRUNT.$"

@ PROTON has no GSC script (he is an HGSS character); this is written to Act II,
@ using GSC's SLOWPOKETAIL business and the three-years-underground line the
@ grunts deliver in TrainerGruntM1WhenTalkText.
SlowpokeWellB1F_Text_ProtonIntro:
	.string "…So the shouting was you.\p"
	.string "PROTON. I run this site.\p"
	.string "TEAM ROCKET was broken up three\n"
	.string "years ago. You'll find that a\l"
	.string "thing can be broken up and still\l"
	.string "be working.\p"
	.string "We were quiet. We were patient.\n"
	.string "We were profitable.\p"
	.string "And then a CHAMPION with nothing\n"
	.string "better to do walks into a well\l"
	.string "in JOHTO.\p"
	.string "Let's find out how much of your\n"
	.string "title is title.$"

SlowpokeWellB1F_Text_ProtonDefeat:
	.string "…Hm.\p"
	.string "That's a genuine record, then.$"

SlowpokeWellB1F_Text_ProtonRetreat:
	.string "PROTON: Pull out. All of you.\p"
	.string "Don't mistake this, CHAMPION.\n"
	.string "You cost us a warehouse and an\l"
	.string "afternoon.\p"
	.string "There is a great deal more of\n"
	.string "TEAM ROCKET than a hole full of\l"
	.string "SLOWPOKE.\p"
	.string "You'll meet it.$"

@ INTENTIONALLY UNREACHABLE / DEFENSIVE -- see EventScript_Proton.
SlowpokeWellB1F_Text_ProtonIdle:
	.string "PROTON: We're finished here.$"

@ Adapts GSC KurtLeaveSlowpokeWellText.
SlowpokeWellB1F_Text_KurtGratitude:
	.string "KURT: …Way to go.\p"
	.string "They went up the shaft like the\n"
	.string "floor was on fire. Every last\l"
	.string "one of them.\p"
	.string "Back's better too. Funny how\n"
	.string "that works.\p"
	.string "Leave the SLOWPOKE be -- they'll\n"
	.string "find their own way up. They\l"
	.string "always do. Slowly.\p"
	.string "I'm going home to my workbench.\p"
	.string "Come and see me there, {PLAYER}.\n"
	.string "I owe you a BALL, and I don't\l"
	.string "make the ordinary kind.$"

@ Adapts GSC SlowpokeWellB1FTaillessSlowpokeText.
SlowpokeWellB1F_Text_Slowpoke:
	.string "A SLOWPOKE with its TAIL cut\n"
	.string "off…\p"
	.string "It doesn't seem to have noticed\n"
	.string "yet.$"
