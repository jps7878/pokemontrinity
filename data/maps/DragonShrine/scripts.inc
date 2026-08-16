@ ============================================================================
@ Trinity M4b S9 -- THE DRAGON SHRINE. The elder's test, badge 16 and TM02.
@ Adapts pokecrystal maps/DragonShrine.asm, movement for movement.
@
@ ---------------------------------------------------------------------------
@ G-VARIANT-S: THE BADGE IS AWARDED HERE, NOT IN THE GYM
@ ---------------------------------------------------------------------------
@ GSC's CLAIR refuses the RISINGBADGE after losing and sends the player to this
@ shrine; the brief pins TM02 DRAGON CLAW here too (GSC hands TM24
@ DRAGONBREATH back in the gym, and has a documented double-give bug doing it).
@ So this file is the ONE writer of FLAG_TRINITY_BADGE16 (G7), and
@ data/maps/BlackthornGym1F/scripts.inc only reads it.
@ G2's SAFETY clause holds across the map boundary: nothing failable stands
@ between beating CLAIR and the badge, and here the badge -- and the scene-var
@ advance that retires the whole chapter -- are both written BEFORE the TM.
@
@ ---------------------------------------------------------------------------
@ WHY ON_FRAME AND NOT A COORD_EVENT
@ ---------------------------------------------------------------------------
@ GSC uses a scene_script, which runs on map load. The Emerald equivalent is
@ MAP_SCRIPT_ON_FRAME_TABLE. S7's pin warns that ON_FRAME fires EVERY frame and
@ locks the player out of their own input -- but that warning is about an entry
@ gated on a var the scene does NOT advance. This one matches
@ VAR_TRINITY_JOHTO_SCENE_BLACKTHORN == 1 and the scene sets it to 2 before it
@ ends, so it fires exactly once per save, on entry, which is what a cutscene
@ wants. A coord_event would have been worse: the chamber's whole bottom row
@ (x 2-7, y 8) touches the entrance corridor, so there is no single chokepoint
@ to put one on.
@
@ THE ARRIVAL TILE IS PROVABLY (4,9). DragonsDenB1F's (19,29) targets
@ MAP_DRAGON_SHRINE warp 0, and warp 0 is (4,9). The map's second warp (5,9)
@ exists but nothing in the game targets it. So GSC's walk-in
@ (up,up,up,right,up,up,up) lands the player deterministically on (5,3), one
@ tile below the altar.
@
@ GEOMETRY, decoded from data/layouts/DragonShrine_Johto/map.bin: a 6-wide
@ chamber x 2-7, y 2-8, the altar tiles (4,1)/(5,1), and the full-width row 9
@ corridor. All 54 walkable tiles are collision 0 elevation 3 and all 54 are
@ reachable. Every choreography tile below is inside that block.
@
@ CAMERA, checked once against the whole scene: the viewport is 15x10 with the
@ player on the 5th row, so from (5,3) it covers y -1..8 and x -2..12. ELDER 1's
@ step to (5,2), ELDERS 2/3 at (2,4)/(7,4), CLAIR's spawn at (4,8) and her whole
@ path (4,3) -> (2,3) -> (4,3) -> (4,8) are all inside it.
@
@ ---------------------------------------------------------------------------
@ SKIPPED GSC BEAT, LOGGED: THE DRATINI
@ ---------------------------------------------------------------------------
@ GSC's ELDER 1 gives a level-15 DRATINI after the test, with a special that
@ tunes its DVs on whether you ever answered wrong. Act II opens at L58-75, so
@ that gift is dead on arrival, and it drags in givepoke plus a party-full
@ branch for no beat. His recognition speech stays; the gift is an M6
@ reward-balance item alongside the eight leader TMs.
@ Also skipped: GSC's specialphonecall (no phone system in this build).
@ ============================================================================

DragonShrine_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DragonShrine_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonShrine_OnFrame
	.byte 0

DragonShrine_OnFrame:
	map_script_2 VAR_TRINITY_JOHTO_SCENE_BLACKTHORN, 1, DragonShrine_EventScript_TakeTest
	.2byte 0

@ THE AWARD GUARD OWNS THE GIVER'S VISIBILITY (S7's C1 rule). CLAIR is an
@ addobject-only actor during the scene -- the flag is SET here whenever the
@ test is not yet passed, so her template can never spawn early, and addobject
@ does NOT clear a visibility flag (there is no FlagClear counterpart to
@ removeobject's FlagSet, src/event_object_movement.c:1803), so the spawn is
@ session-only. AFTERWARDS she is on stage at (4,8) if and only if the TM has
@ not been handed over, which is the retry path for a full bag. (4,8) is on the
@ chamber's bottom row, every tile of which touches the row-9 corridor, so she
@ seals nothing.
DragonShrine_OnTransition:
	goto_if_lt VAR_TRINITY_JOHTO_SCENE_BLACKTHORN, 2, DragonShrine_EventScript_HideClair
	goto_if_set FLAG_TRINITY_J_CLAIR_TM02, DragonShrine_EventScript_HideClair
	clearflag FLAG_TRINITY_J_SHRINE_CLAIR_HIDE
	end

DragonShrine_EventScript_HideClair::
	setflag FLAG_TRINITY_J_SHRINE_CLAIR_HIDE
	end

@ ============================================================================
@ THE TEST. GSC's five questions and all fifteen options, in GSC's order and
@ wording (re-cased to the tree's uppercase menu style); the accepted/rejected
@ split is GSC's (see src/data/script_menu.h). A
@ wrong answer plays GSC's two "I didn't quite catch that" lines and re-asks the
@ SAME question, so the test cannot be failed -- also GSC. That is why no state
@ var is needed: each question is a label and the retry is a goto.
@ multichoice's fourth argument is ignoreBPress; TRUE reproduces GSC's
@ STATICMENU_DISABLE_B, so an answer must actually be chosen.
@ ============================================================================
DragonShrine_EventScript_TakeTest::
	lockall
	applymovement LOCALID_PLAYER, DragonShrine_Movement_PlayerWalkIn
	waitmovement 0
	applymovement LOCALID_JOHTO_SHRINE_ELDER1, DragonShrine_Movement_ElderStepDown
	waitmovement 0
	msgbox DragonShrine_Text_ElderGreeting, MSGBOX_DEFAULT

DragonShrine_EventScript_Question1::
	msgbox DragonShrine_Text_Question1, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_DRAGON_TEST_1, TRUE
	switch VAR_RESULT
	case 0, DragonShrine_EventScript_Answer1Right
	case 1, DragonShrine_EventScript_Answer1Wrong
	case 2, DragonShrine_EventScript_Answer1Right
	@ INTENTIONALLY UNREACHABLE / DEFENSIVE: ignoreBPress is TRUE, so
	@ ScriptMenu_Multichoice can never return MULTI_B_PRESSED here.
	case MULTI_B_PRESSED, DragonShrine_EventScript_Answer1Wrong
	end

DragonShrine_EventScript_Answer1Wrong::
	call DragonShrine_EventScript_WrongAnswer
	goto DragonShrine_EventScript_Question1
	end

DragonShrine_EventScript_Answer1Right::
	msgbox DragonShrine_Text_RightAnswer, MSGBOX_DEFAULT

DragonShrine_EventScript_Question2::
	msgbox DragonShrine_Text_Question2, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_DRAGON_TEST_2, TRUE
	switch VAR_RESULT
	case 0, DragonShrine_EventScript_Answer2Right
	case 1, DragonShrine_EventScript_Answer2Right
	case 2, DragonShrine_EventScript_Answer2Wrong
	case MULTI_B_PRESSED, DragonShrine_EventScript_Answer2Wrong
	end

DragonShrine_EventScript_Answer2Wrong::
	call DragonShrine_EventScript_WrongAnswer
	goto DragonShrine_EventScript_Question2
	end

DragonShrine_EventScript_Answer2Right::
	msgbox DragonShrine_Text_RightAnswer, MSGBOX_DEFAULT

DragonShrine_EventScript_Question3::
	msgbox DragonShrine_Text_Question3, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_DRAGON_TEST_3, TRUE
	switch VAR_RESULT
	case 0, DragonShrine_EventScript_Answer3Wrong
	case 1, DragonShrine_EventScript_Answer3Right
	case 2, DragonShrine_EventScript_Answer3Right
	case MULTI_B_PRESSED, DragonShrine_EventScript_Answer3Wrong
	end

DragonShrine_EventScript_Answer3Wrong::
	call DragonShrine_EventScript_WrongAnswer
	goto DragonShrine_EventScript_Question3
	end

DragonShrine_EventScript_Answer3Right::
	msgbox DragonShrine_Text_RightAnswer, MSGBOX_DEFAULT

DragonShrine_EventScript_Question4::
	msgbox DragonShrine_Text_Question4, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_DRAGON_TEST_4, TRUE
	switch VAR_RESULT
	case 0, DragonShrine_EventScript_Answer4Right
	case 1, DragonShrine_EventScript_Answer4Wrong
	case 2, DragonShrine_EventScript_Answer4Right
	case MULTI_B_PRESSED, DragonShrine_EventScript_Answer4Wrong
	end

DragonShrine_EventScript_Answer4Wrong::
	call DragonShrine_EventScript_WrongAnswer
	goto DragonShrine_EventScript_Question4
	end

DragonShrine_EventScript_Answer4Right::
	msgbox DragonShrine_Text_RightAnswer, MSGBOX_DEFAULT

DragonShrine_EventScript_Question5::
	msgbox DragonShrine_Text_Question5, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_DRAGON_TEST_5, TRUE
	switch VAR_RESULT
	case 0, DragonShrine_EventScript_Answer5Wrong
	case 1, DragonShrine_EventScript_Answer5Right
	case 2, DragonShrine_EventScript_Answer5Wrong
	case MULTI_B_PRESSED, DragonShrine_EventScript_Answer5Wrong
	end

DragonShrine_EventScript_Answer5Wrong::
	call DragonShrine_EventScript_WrongAnswer
	goto DragonShrine_EventScript_Question5
	end

DragonShrine_EventScript_Answer5Right::
	goto DragonShrine_EventScript_PassedTheTest
	end

@ GSC turns the elder aside for the first line and back for the second -- he is
@ pretending not to have heard rather than marking you down.
DragonShrine_EventScript_WrongAnswer::
	applymovement LOCALID_JOHTO_SHRINE_ELDER1, DragonShrine_Movement_ElderFaceLeft
	waitmovement 0
	msgbox DragonShrine_Text_WrongAnswer1, MSGBOX_DEFAULT
	applymovement LOCALID_JOHTO_SHRINE_ELDER1, DragonShrine_Movement_ElderFaceDown
	waitmovement 0
	msgbox DragonShrine_Text_WrongAnswer2, MSGBOX_DEFAULT
	return

@ ============================================================================
@ THE AWARD SCENE. GSC's staging, movement for movement. CLAIR is addobject'd
@ at her template tile (4,8) -- free, because the player walked off it during
@ the walk-in and is now at (5,3).
@ ============================================================================
DragonShrine_EventScript_PassedTheTest::
	msgbox DragonShrine_Text_PassedTest, MSGBOX_DEFAULT
	playse SE_EXIT
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	addobject LOCALID_JOHTO_SHRINE_CLAIR
	delay 20
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, FALSE
	applymovement LOCALID_JOHTO_SHRINE_CLAIR, DragonShrine_Movement_ClairWalksIn
	waitmovement 0
	applymovement LOCALID_JOHTO_SHRINE_CLAIR, DragonShrine_Movement_ClairFaceRight
	applymovement LOCALID_PLAYER, DragonShrine_Movement_PlayerFaceLeft
	applymovement LOCALID_JOHTO_SHRINE_ELDER1, DragonShrine_Movement_ElderFaceLeft
	waitmovement 0
	msgbox DragonShrine_Text_ClairYouPassed, MSGBOX_DEFAULT
	applymovement LOCALID_JOHTO_SHRINE_CLAIR, DragonShrine_Movement_ClairRecoils
	waitmovement 0
	msgbox DragonShrine_Text_ClairThatCantBe, MSGBOX_DEFAULT
	applymovement LOCALID_JOHTO_SHRINE_CLAIR, DragonShrine_Movement_ClairBacksAway
	waitmovement 0
	msgbox DragonShrine_Text_ClairYoureLying, MSGBOX_DEFAULT
	applymovement LOCALID_JOHTO_SHRINE_ELDER1, DragonShrine_Movement_ElderWalksToClair
	waitmovement 0
	applymovement LOCALID_JOHTO_SHRINE_CLAIR, DragonShrine_Movement_ClairFaceUp
	waitmovement 0
	msgbox DragonShrine_Text_MustIInformLance, MSGBOX_DEFAULT
	applymovement LOCALID_JOHTO_SHRINE_CLAIR, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox DragonShrine_Text_IUnderstand, MSGBOX_DEFAULT
	applymovement LOCALID_JOHTO_SHRINE_CLAIR, DragonShrine_Movement_ClairStepsBack
	waitmovement 0
	msgbox DragonShrine_Text_HereRisingBadge, MSGBOX_DEFAULT
	message DragonShrine_Text_ReceivedRisingBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	@ G7: this is the badge flag's ONE writer. The scene-var advance rides with
	@ it, BEFORE the failable gift, so a full bag cannot hold the chapter open.
	setflag FLAG_TRINITY_BADGE16
	setvar VAR_TRINITY_JOHTO_SCENE_BLACKTHORN, 2
	msgbox DragonShrine_Text_RisingBadgeMeaning, MSGBOX_DEFAULT
	call DragonShrine_EventScript_AwardTM02
	fadedefaultbgm
	applymovement LOCALID_JOHTO_SHRINE_ELDER1, DragonShrine_Movement_ElderWalksAway
	waitmovement 0
	applymovement LOCALID_JOHTO_SHRINE_CLAIR, DragonShrine_Movement_ClairFaceUp
	applymovement LOCALID_PLAYER, DragonShrine_Movement_PlayerFaceUp
	waitmovement 0
	msgbox DragonShrine_Text_ElderScoldsClair, MSGBOX_DEFAULT
	msgbox DragonShrine_Text_Speechless, MSGBOX_DEFAULT
	applymovement LOCALID_JOHTO_SHRINE_CLAIR, DragonShrine_Movement_ClairWalksOut
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_JOHTO_SHRINE_CLAIR
	waitse
	releaseall
	end

@ G2: the TM is the only failable gift in the chapter, so it owns its own flag
@ and its own label, and it is reachable again from CLAIR's talk script for as
@ long as that flag is clear (which is also what keeps her on stage).
DragonShrine_EventScript_AwardTM02::
	giveitem ITEM_TM_DRAGON_CLAW
	goto_if_eq VAR_RESULT, FALSE, DragonShrine_EventScript_ClairBagFull
	setflag FLAG_TRINITY_J_CLAIR_TM02
	msgbox DragonShrine_Text_ExplainDragonClaw, MSGBOX_DEFAULT
	return

DragonShrine_EventScript_ClairBagFull::
	msgbox DragonShrine_Text_ClairNoRoom, MSGBOX_DEFAULT
	return

@ The retry giver. Reached only when the bag was full during the scene -- see
@ the ON_TRANSITION guard above.
DragonShrine_EventScript_ClairTM::
	lock
	faceplayer
	@ INTENTIONALLY UNREACHABLE / DEFENSIVE: ON_TRANSITION only spawns this
	@ object while the TM flag is clear, so this branch cannot be entered.
	goto_if_set FLAG_TRINITY_J_CLAIR_TM02, DragonShrine_EventScript_ClairIdle
	msgbox DragonShrine_Text_ClairKeptMeWaiting, MSGBOX_DEFAULT
	call DragonShrine_EventScript_AwardTM02
	release
	end

DragonShrine_EventScript_ClairIdle::
	msgbox DragonShrine_Text_ClairIdle, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ The elders. ELDER 1 has two states: before the test he is the examiner (the
@ scene owns him), afterwards he is CLAIR's grandfather.
@ ============================================================================
DragonShrine_EventScript_Elder1::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_BADGE16, DragonShrine_EventScript_Elder1AfterTest
	msgbox DragonShrine_Text_Elder1Waiting, MSGBOX_DEFAULT
	release
	end

DragonShrine_EventScript_Elder1AfterTest::
	msgbox DragonShrine_Text_Elder1Grandfather, MSGBOX_DEFAULT
	release
	end

DragonShrine_EventScript_Elder2::
	msgbox DragonShrine_Text_Elder2, MSGBOX_NPC
	end

DragonShrine_EventScript_Elder3::
	msgbox DragonShrine_Text_Elder3, MSGBOX_NPC
	end

@ ============================================================================
@ Movement. Every destination tile decodes collision 0 elevation 3.
@   player   (4,9) -> (4,6) -> (5,6) -> (5,3)
@   ELDER 1  (5,1) -> (5,2), then (5,2) -> (2,2), then back to (5,2)
@   CLAIR    (4,8) -> (4,3) -> (3,3) -> (2,3) -> (4,3) -> (4,8)
@ GSC's `big_step` is walk_fast_*, `slow_step` is walk_slow_*, `fix_facing` /
@ `remove_fixed_facing` are lock_facing_direction / unlock_facing_direction.
@ ============================================================================
DragonShrine_Movement_PlayerWalkIn:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_right
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

DragonShrine_Movement_PlayerFaceLeft:
	face_left
	step_end

DragonShrine_Movement_PlayerFaceUp:
	face_up
	step_end

DragonShrine_Movement_ElderStepDown:
	walk_slow_down
	step_end

DragonShrine_Movement_ElderFaceLeft:
	face_left
	step_end

DragonShrine_Movement_ElderFaceDown:
	face_down
	step_end

DragonShrine_Movement_ElderWalksToClair:
	walk_slow_left
	walk_slow_left
	walk_slow_left
	face_down
	step_end

DragonShrine_Movement_ElderWalksAway:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	face_down
	step_end

DragonShrine_Movement_ClairWalksIn:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

DragonShrine_Movement_ClairFaceRight:
	face_right
	step_end

DragonShrine_Movement_ClairFaceUp:
	face_up
	step_end

@ She flinches back a tile without turning away -- GSC's fix_facing + big_step.
DragonShrine_Movement_ClairRecoils:
	lock_facing_direction
	walk_fast_left
	step_end

DragonShrine_Movement_ClairBacksAway:
	walk_slow_left
	unlock_facing_direction
	step_end

DragonShrine_Movement_ClairStepsBack:
	walk_slow_right
	walk_slow_right
	step_end

DragonShrine_Movement_ClairWalksOut:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ ============================================================================
@ Text. GSC's, adapted to a challenger who is already a CHAMPION -- which is
@ the point the elder makes in his first breath, and the point CLAIR cannot
@ accept in her last.
@ ============================================================================
DragonShrine_Text_ElderGreeting:
	.string "Hm… Good to see you here.\p"
	.string "No need to explain why you came.\n"
	.string "CLAIR sent you, didn't she?\p"
	.string "That girl is a handful…\p"
	.string "I am sorry, but I must test you.\p"
	.string "Not your strength. A trophy from\n"
	.string "HOENN already answers that, and\l"
	.string "it is the least interesting thing\l"
	.string "about you.\p"
	.string "A few questions. That is all.\n"
	.string "Ready?$"

DragonShrine_Text_Question1:
	.string "What are POKéMON to you?$"

DragonShrine_Text_Question2:
	.string "What helps you to win battles?$"

DragonShrine_Text_Question3:
	.string "What kind of trainer do you wish\n"
	.string "to battle?$"

DragonShrine_Text_Question4:
	.string "What is most important for raising\n"
	.string "POKéMON?$"

DragonShrine_Text_Question5:
	.string "Strong POKéMON. Weak POKéMON.\p"
	.string "Which is more important?$"

DragonShrine_Text_RightAnswer:
	.string "Oh, I understand…$"

DragonShrine_Text_WrongAnswer1:
	.string "Hah? I didn't quite catch that…$"

DragonShrine_Text_WrongAnswer2:
	.string "What was it you said?$"

DragonShrine_Text_PassedTest:
	.string "Hm… I see…\p"
	.string "You care deeply for POKéMON.\p"
	.string "Very commendable.\p"
	.string "That conviction is what is\n"
	.string "important -- not the trophy.\p"
	.string "{PLAYER}, don't lose that belief.\p"
	.string "It will see you through at the\n"
	.string "POKéMON LEAGUE, as it has\l"
	.string "everywhere else.$"

DragonShrine_Text_ClairYouPassed:
	.string "So how did it go?\p"
	.string "I guess there's no point in\n"
	.string "asking. You did fail?\p"
	.string "……\p"
	.string "…What? You passed?$"

DragonShrine_Text_ClairThatCantBe:
	.string "That can't be!$"

DragonShrine_Text_ClairYoureLying:
	.string "You're lying!\p"
	.string "Even I haven't been approved!$"

DragonShrine_Text_MustIInformLance:
	.string "CLAIR!\p"
	.string "This one is impeccable, in skill\n"
	.string "and in spirit!\p"
	.string "Admit defeat and confer the\n"
	.string "RISINGBADGE!\p"
	.string "…Or must I inform LANCE of this?$"

DragonShrine_Text_IUnderstand:
	.string "I-I understand…$"

DragonShrine_Text_HereRisingBadge:
	.string "Here. This is the RISINGBADGE…\p"
	.string "Hurry up! Take it!$"

DragonShrine_Text_ReceivedRisingBadge:
	.string "{PLAYER} received the RISINGBADGE\n"
	.string "from CLAIR!$"

@ The badge-meaning line must not promise a mechanical effect: badges 9-16 are
@ plain flags with no engine UI (the ledger's rule). GSC's version promises
@ WATERFALL and obedience; neither is true here, so neither is claimed. It is
@ also badge-agnostic -- the JOHTO gyms are open-order, so no line counts.
DragonShrine_Text_RisingBadgeMeaning:
	.string "The RISINGBADGE will not make one\n"
	.string "of your POKéMON one point\l"
	.string "stronger.\p"
	.string "It is a record that the dragon\n"
	.string "clan weighed you and did not find\l"
	.string "you wanting.\p"
	.string "Eight of those and INDIGO PLATEAU\n"
	.string "opens its doors. That is what they\l"
	.string "are for.$"

@ TM award dialogue must never presume novelty (the S3-S9 rule): DRAGON CLAW
@ has Act I sources, so the player may already own a copy. She is handing on a
@ technique, not a present.
DragonShrine_Text_ExplainDragonClaw:
	.string "That's DRAGON CLAW.\p"
	.string "Whether it's your first copy or\n"
	.string "your fourth, it isn't the disc\l"
	.string "that matters.\p"
	.string "A dragon's claws go where the\n"
	.string "dragon has already decided to go.\p"
	.string "Teach it that way and I'll have\n"
	.string "lost twice today.$"

DragonShrine_Text_ClairNoRoom:
	.string "What is this? You don't have room?\p"
	.string "…Fine. I'll wait. Believe me, I've\n"
	.string "had worse days.$"

DragonShrine_Text_ClairKeptMeWaiting:
	.string "You've kept me waiting!\p"
	.string "Here. Take this.$"

DragonShrine_Text_ClairIdle:
	.string "Well? Go and win something that\n"
	.string "isn't a trophy.$"

DragonShrine_Text_Elder1Waiting:
	.string "Come again, if you so desire.$"

DragonShrine_Text_Elder1Grandfather:
	.string "CLAIR appears to have learned an\n"
	.string "invaluable lesson from you.\p"
	.string "I thank you as her grandfather.\p"
	.string "A boy about your age trains here\n"
	.string "now, too. He is much like CLAIR\l"
	.string "was. It is a little worrisome…$"

DragonShrine_Text_ElderScoldsClair:
	.string "CLAIR…\p"
	.string "Reflect upon what it is that you\n"
	.string "lack and this one has.$"

DragonShrine_Text_Speechless:
	.string "……$"

DragonShrine_Text_Elder2:
	.string "It's been quite some time since a\n"
	.string "trainer gained our MASTER's rare\l"
	.string "approval.\p"
	.string "In fact, not since Master LANCE.$"

DragonShrine_Text_Elder3:
	.string "You know young Master LANCE?\p"
	.string "He looks so much like our MASTER\n"
	.string "did in his youth.\p"
	.string "It's in their blood.$"
