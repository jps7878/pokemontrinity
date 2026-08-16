RadioTower5F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RadioTower5F_OnTransition
	.byte 0

@ Trinity M4b S4 -- RADIO TOWER 5F, pre-takeover. S8 FLIP CONTRACT: shared
@ predicate in data/maps/RadioTower1F/scripts.inc -- visible iff
@ VAR_TRINITY_JOHTO_ARC != 6. The DIRECTOR and DJ BEN carry
@ FLAG_TRINITY_J_RADIO_TOWER_PRE_HIDE; the ITEM_ULTRA_BALL ball at (8,5) keeps
@ its own pickup flag and is not part of the cast.
@
@ FOR S8: this DIRECTOR object at (3,6) is GSC's tile, and GSC reuses ONE
@ director object -- during the occupation it IS the imposter, with scene
@ scripts swapping the script rather than the sprite. Trinity's is simply
@ hidden while ARC == 6 and returns at ARC 7. S8 may either follow GSC (drop
@ the shared hide on this one object and give it a branching script, which
@ means claiming a flag for it and adding a call to the ON_TRANSITION below --
@ i.e. EDITING THIS FILE; the contract's escape hatch is a second pass over an
@ S4 file, and no promise to the contrary is made) or append a separate
@ imposter object, which touches nothing here. GoldenrodCity's ROCKET SCOUT is
@ the worked example of the hatch.
@ His post-rescue speech -- the CLEAR BELL, the old tower, the TIN TOWER tip --
@ is S8's payload and is deliberately NOT written here.
@
@ TWO MORE THINGS S8 NEEDS ON THIS FLOOR (full list in RadioTower1F's header):
@   - DJ BEN at (13,5) is GSC's POST-CLEAR cast (EVENT_RADIO_TOWER_CIVILIANS_
@     AFTER), brought forward by S4. Appending GSC's after-set wholesale would
@     double-place him.
@   - (13,5) is ALSO GSC's 5F takeover-Rocket tile. Opposite predicates make a
@     stack safe, but offset it or accept it knowingly.
@ DECODE NOTE: two components, PRE-EXISTING and object-independent (the office
@ half and the studio half join through 4F). See RadioTower3F's header.
@ ============================================================================
@ Trinity M4b S8 -- HOW THE ESCAPE HATCH WAS TAKEN, and the two stacks.
@
@ THE DIRECTOR OBJECT AT (3,6) NOW CARRIES `flag: 0` -- always visible -- with a
@ three-branch script. That is not an invention: it is GSC's own object
@ (RadioTower5F.asm:440, event flag -1) and GSC's own trick of swapping the
@ SCRIPT, never the sprite. The imposter wears the director's face because he
@ has been wearing it for weeks. Cost: one map.json line and one script, no new
@ flag, no stacked object. Branches:
@     ARC <  6  the real DIRECTOR, at work            (S4's line)
@     ARC == 6  the IMPOSTER -- EXEC PETREL, round two
@     ARC >= 7  the rescued DIRECTOR -- the RAINBOW WING and the CLEAR BELL
@
@ THE (13,5) STACK IS ACCEPTED KNOWINGLY, as the contract permits. Three objects
@ share that tile and no two can ever render together:
@     DJ BEN     FLAG_TRINITY_J_RADIO_TOWER_PRE_HIDE   visible iff ARC != 6
@     EXEC ARCHER FLAG_TRINITY_J_TOWER_5F_ROCKETS_HIDE visible iff ARC == 6
@     GIOVANNI   FLAG_TRINITY_J_TOWER_GIOVANNI_HIDE    ALWAYS hidden; the scene
@                                                      addobject's him there
@ Offsetting ARCHER was considered and rejected: (13,5) is the only tile that
@ keeps GSC's one-tile adjacency with the player's normalised (14,5), and the
@ image the cameo wants is GIOVANNI standing exactly where his lieutenant did.
@
@ ADDOBJECT-ONLY ACTORS. GIOVANNI and BOBBY have their visibility flags SET
@ unconditionally on every transition, so their templates can never spawn.
@ addobject does NOT clear a visibility flag -- there is no FlagClear
@ counterpart to removeobject's FlagSet (src/event_object_movement.c:1803 vs
@ :1537-1545) -- so a spawn is session-only and cannot outlive the scene.
@ ============================================================================
RadioTower5F_OnTransition:
	call RadioTower_EventScript_SetPreTakeoverVisibility
	call RadioTower_EventScript_SetTakeoverVisibility
	call RadioTower5F_EventScript_SetBossVisibility
	end

RadioTower5F_EventScript_SetBossVisibility::
	setflag FLAG_TRINITY_J_TOWER_GIOVANNI_HIDE
	setflag FLAG_TRINITY_J_TOWER_BOBBY_HIDE
	goto_if_ne VAR_TRINITY_JOHTO_ARC, 6, RadioTower5F_EventScript_Hide5FRockets
	clearflag FLAG_TRINITY_J_TOWER_5F_ROCKETS_HIDE
	return

RadioTower5F_EventScript_Hide5FRockets::
	setflag FLAG_TRINITY_J_TOWER_5F_ROCKETS_HIDE
	return

@ ============================================================================
@ THE DIRECTOR -- one object, three lives.
@ ============================================================================
RadioTower5F_EventScript_Director::
	goto_if_eq VAR_TRINITY_JOHTO_ARC, 6, RadioTower5F_EventScript_Imposter
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 7, RadioTower5F_EventScript_RescuedDirector
	msgbox RadioTower5F_Text_Director, MSGBOX_NPC
	end

@ ============================================================================
@ THE IMPOSTER. R2 shape: TALK-triggered, playbgm before the battle,
@ `trainerbattle_single` ... NO_MUSIC (which supplies its own lock/faceplayer, so
@ this script must not lock first -- the state guards above are bare gotos and
@ only the idle branches lock).
@
@ DEVIATION FROM GSC, and the reason for it. GSC fires this from a coord_event
@ at (0,3) and walks the fake director LEFT x3, UP x2 from (3,6) to (0,4)
@ (RadioTower5F.asm:26-50, 154-160). Both tiles decode fine here, but (0,4) is a
@ CUT VERTEX: x=0 is single-file for y=3..5 ((1,3) (2,3) and (3,4) are all
@ collision 1), so an exec resting on (0,4) seals the entire west office region
@ -- (0..5, 5..7), the DIRECTOR's own desk included -- for the rest of the
@ visit. The contract forbids a resting NPC sealing a corridor and R5 sanctions
@ sealing only OPTIONAL content with a flood-fill-verified disclosure. Making
@ him talk-triggered at (3,6) moves nothing, seals nothing ((2,6) and (4,6) stay
@ joined through row 7) and plays the fake-out better as a conversation.
@
@ (3,6) has three approach tiles -- (2,6) (4,6) (3,7), all decoded collision 0
@ elevation 3 -- so no R5 geometry normalisation is needed or wanted.
@
@ THE BASEMENT KEY CANNOT BE MISSED. It is set in the trainerbattle
@ continuation, which BattleSetup_GetScriptAddrAfterBattle runs BOTH immediately
@ after the win and again on every later talk (src/battle_setup.c:1405, :972).
@ GSC guards its equivalent with endifjustbattled, so a player who beats the
@ exec and walks away never learns where the DIRECTOR is; that trap is dropped,
@ exactly as S7 dropped it for the base passwords.
@ ============================================================================
RadioTower5F_EventScript_Imposter::
	goto_if_ge VAR_TRINITY_JOHTO_SCENE_GOLDENROD, 1, RadioTower5F_EventScript_ImposterBeaten
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	trainerbattle_single TRAINER_JOHTO_EXEC_PETREL_2, RadioTower5F_Text_ImposterIntro, RadioTower5F_Text_ImposterDefeat, RadioTower5F_EventScript_ImposterConfession, NO_MUSIC
	@ INTENTIONALLY UNREACHABLE / DEFENSIVE -- the continuation advances the
	@ scene var, and the guard above catches every later talk before it reaches
	@ these bytes.
	goto RadioTower5F_EventScript_ImposterBeaten
	end

@ GSC folds the fake-out into two textboxes before the fight; ours goes into the
@ single intro-text argument (S6's CHUCK precedent), which keeps R2's shape and
@ costs nothing but paragraph breaks.
RadioTower5F_EventScript_ImposterConfession::
	msgbox RadioTower5F_Text_ImposterWhereHeIs, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox RadioTower5F_Text_ReceivedBasementKey, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_J_BASEMENT_KEY
	call RadioTower5F_EventScript_AdvanceToScene1
	fadedefaultbgm
	release
	end

RadioTower5F_EventScript_AdvanceToScene1::
	goto_if_ge VAR_TRINITY_JOHTO_SCENE_GOLDENROD, 1, RadioTower5F_EventScript_SceneAlreadyAdvanced
	setvar VAR_TRINITY_JOHTO_SCENE_GOLDENROD, 1
RadioTower5F_EventScript_SceneAlreadyAdvanced::
	return

RadioTower5F_EventScript_ImposterBeaten::
	lock
	faceplayer
	msgbox RadioTower5F_Text_ImposterWhereHeIs, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ THE RESCUED DIRECTOR. The chapter's payload, and S10's brief.
@
@ The RAINBOW WING and the CLEAR BELL are FLAGS, not items -- neither
@ ITEM_RAINBOW_WING nor ITEM_CLEAR_BELL exists in this build (S1's
@ ITEM_RED_SCALE and S6's ITEM_SECRET_POTION precedent). Consequences, handled
@ per S6's three-part rule: each reads as a pickup (fanfare + a "received"
@ line), each is named at every site that refers to it, and the giver's already-
@ given path still does something useful. There is NO giveitem here, so there is
@ no VAR_RESULT == FALSE branch and therefore NO G2 award guard -- G2 exists for
@ a failable gift and this is not one.
@ ============================================================================
RadioTower5F_EventScript_RescuedDirector::
	lock
	faceplayer
	goto_if_ge VAR_TRINITY_JOHTO_SCENE_GOLDENROD, 5, RadioTower5F_EventScript_DirectorIdle
	msgbox RadioTower5F_Text_DirectorThankYou, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox RadioTower5F_Text_ReceivedRainbowWing, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_J_WING_RAINBOW
	msgbox RadioTower5F_Text_DescribeRainbowWing, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox RadioTower5F_Text_ReceivedClearBell, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_J_CLEAR_BELL
	msgbox RadioTower5F_Text_DescribeClearBell, MSGBOX_DEFAULT
	setvar VAR_TRINITY_JOHTO_SCENE_GOLDENROD, 5
	setvar VAR_TRINITY_JOHTO_ARC, 8
	release
	end

RadioTower5F_EventScript_DirectorIdle::
	msgbox RadioTower5F_Text_DirectorAfter, MSGBOX_DEFAULT
	release
	end

RadioTower5F_EventScript_Ben::
	msgbox RadioTower5F_Text_Ben, MSGBOX_NPC
	end

RadioTower5F_EventScript_DirectorsOfficeSign::
	msgbox RadioTower5F_Text_DirectorsOfficeSign, MSGBOX_SIGN
	end

RadioTower5F_EventScript_Studio1Sign::
	msgbox RadioTower5F_Text_Studio1Sign, MSGBOX_SIGN
	end

RadioTower5F_EventScript_Studio1Sign_2::
	msgbox RadioTower5F_Text_Studio1Sign_2, MSGBOX_SIGN
	end

@ GSC RadioTower5FDirectorText.
RadioTower5F_Text_Director:
	.string "DIRECTOR: Hello!\p"
	.string "You know, I love POKéMON.\p"
	.string "I built this RADIO TOWER so I\n"
	.string "could express my love of\l"
	.string "POKéMON.\p"
	.string "It would be nice if people\n"
	.string "enjoyed our programs.\p"
	.string "Anyone may walk in here. That\n"
	.string "was the whole idea.\p"
	.string "My security man thinks I'm a\n"
	.string "fool about it. Perhaps he's\l"
	.string "right.$"

@ GSC BenText.
RadioTower5F_Text_Ben:
	.string "BEN: Do you listen to our\n"
	.string "music?\p"
	.string "STUDIO 1, every evening. Just\n"
	.string "me and a stack of records and\l"
	.string "whoever's still awake.\p"
	.string "…You're the HOENN CHAMPION,\n"
	.string "aren't you. Would you come on\l"
	.string "the show? Ten minutes.\p"
	.string "No? Worth asking.$"

RadioTower5F_Text_DirectorsOfficeSign:
	.string "5F DIRECTOR'S\n   OFFICE$"

RadioTower5F_Text_Studio1Sign:
	.string "5F STUDIO 1$"

RadioTower5F_Text_Studio1Sign_2:
	.string "5F STUDIO 1$"

@ ============================================================================
@ EXEC ARIANA -- SIGHT-triggered at (17,2) with RADIUS 1, and both halves of that
@ are load-bearing.
@
@ WHY SIGHT, against R2's "the exec is talk-triggered". R2 makes execs
@ talk-triggered so playbgm MUS_RG_ENCOUNTER_ROCKET survives to the battle, and
@ S7 accepted the cost that PETREL and ARIANA became walk-past-able. Here the
@ geometry gives the better answer for free: (17,2) is a dead-end nook at the
@ east end of the 5F north corridor, and the ONLY descent into STUDIO 1 is the
@ one-tile column x=16, y=3..7 (rows 3 and 4 are solid from x=6 to x=15). Every
@ player must stand on (16,2) to turn down it, so a west-facing cone that
@ contains (16,2) is unmissable.
@
@ WHY RADIUS 1, AND NOT 3 (review C1 -- this was a REAL, SHIPPED-IN-DRAFT DEFECT).
@ A sight post does NOT rest on its template tile after the battle. The approach
@ task walks it toward the player and leaves it ADJACENT to wherever the player
@ stood when the cone fired, so for a post at P facing d with radius r the set of
@ possible RESTING tiles is P, P+d, ... P+(r-1)*d. At radius 3 hers was
@ {(17,2), (16,2), (15,2)} -- and (16,2) is the mouth of the descent column.
@ An ARIANA who fought at maximum range would spend the rest of the visit
@ standing in the ONLY doorway to STUDIO 1, sealing ARCHER, GIOVANNI and the G
@ reveal behind her. Measured, per-door: template 35/39, resting on (16,2)
@ 15/35, resting on (15,2) 14/35.
@
@ At radius 1 the cone is exactly {(16,2)} -- still the provably-crossed tile,
@ so she is still unmissable -- and the resting set collapses to {(17,2)}, her
@ own dead end, which costs zero walkability because nothing else needs it.
@
@ THE RULE THIS COST US, now in the ledger: a sight post's cut-vertex audit runs
@ over its WHOLE APPROACH PATH P..P+(r-1)*d, never over the template tile alone.
@ Every other sight post in this slice was re-audited that way and is clean.
@
@ Her battle BGM is unaffected: GetBattleBGM()'s TEAM ROCKET case takes
@ TRAINER_JOHTO_EXEC_PETREL_2..._ARIANA_2 (1081-1082) to MUS_VS_AQUA_MAGMA by id
@ range. The encounter swap she does get -- MUS_ENCOUNTER_AQUA, from her
@ `Music: Aqua` -- is the correct sound for a sight line.
@ ============================================================================
RadioTower5F_EventScript_Ariana::
	trainerbattle_single TRAINER_JOHTO_EXEC_ARIANA_2, RadioTower5F_Text_ArianaSeen, RadioTower5F_Text_ArianaBeaten
	msgbox RadioTower5F_Text_ArianaAfter, MSGBOX_AUTOCLOSE
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE. ARCHER is TRAINER_TYPE_NONE with sight
@ 0 and the coord_event at (16,5) fires before the player can ever stand next to
@ him: (16,5) is on the single-file descent column and the scene walks the player
@ two tiles west of it. Written so a debug-menu warp cannot find a mute object.
RadioTower5F_EventScript_ArcherIdle::
	msgbox RadioTower5F_Text_ArcherIdle, MSGBOX_NPC
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE -- addobject-only actors whose flags are
@ set on every transition. Neither template can spawn.
RadioTower5F_EventScript_GiovanniIdle::
	msgbox RadioTower5F_Text_GiovanniIdle, MSGBOX_NPC
	end

RadioTower5F_EventScript_BobbyIdle::
	msgbox RadioTower5F_Text_BobbyIdle, MSGBOX_NPC
	end

@ ============================================================================
@ THE G REVEAL -- the act's centrepiece.
@
@ TRIGGER. coord_event (16,5), gated on VAR_TRINITY_JOHTO_SCENE_GOLDENROD == 3
@ (GSC's own tile, RadioTower5F.asm:430). One coord_event is enough where S1's
@ rule normally wants a pair, because the chokepoint is ONE tile wide: x=16,
@ y=3..7 is the only descent from the north corridor into STUDIO 1. The scene
@ advances the var to 4, so it can never re-fire.
@
@ NORMALISATION AND CAMERA. Two scripted steps west pin the player on (14,5)
@ (mt730, collision 0, elevation 3, MB_NORMAL), so the viewport is x 7..21,
@ y 1..10 (15x10 with the player on the 5th row). Every tile the choreography
@ touches is inside it and every one is decoded:
@     ARCHER    (13,5) mt719   ARIANA   (17,2) mt757
@     GIOVANNI  (13,5) -> (13,6) mt721 -> (13,7) mt723 -> (14,7) mt726
@                      -> (15,7) mt727 -> (16,7) mt762
@     BOBBY     (16,5) mt762 -> (15,5) mt731
@ all collision 0, elevation 3, MB_NORMAL.
@
@ FADES. ARCHER's and ARIANA's removal and GIOVANNI's arrival sit inside an R4
@ FADE_TO_BLACK sandwich, because nothing about them is diegetic. GIOVANNI's and
@ BOBBY's exits are walks off the far side of the studio covered by a door
@ sound, which is S5's documented R4 deviation: a disappearance that never pops
@ does not need a fade, and three fades inside one scene would destroy the beat
@ R4 exists to protect.
@
@ THE REMOVEOBJECT PAIR. ARCHER and ARIANA share
@ FLAG_TRINITY_J_TOWER_5F_ROCKETS_HIDE, so removing one co-signs the other
@ (RemoveObjectEventByLocalIdAndMap -> FlagSet). That is INTENDED -- GSC retires
@ the pair in one breath -- and it is exactly why they are not on the 13-object
@ tower flag, where the same co-sign would delete every post in the building.
@
@ TERMINAL WRITES. FLAG_TRINITY_J_BOBBY_REVEALED, then SCENE 3, then ARC 7 --
@ both var writes behind goto_if_ge guards even though the coord gate already
@ makes the scene once-only.
@ ============================================================================
RadioTower5F_EventScript_ArcherScene::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, RadioTower5F_Movement_PlayerTwoWest
	waitmovement 0
	turnobject LOCALID_JOHTO_RT5F_ARCHER, DIR_EAST
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	msgbox RadioTower5F_Text_ArcherBefore, MSGBOX_DEFAULT
	closemessage
	@ `trainerbattle_no_intro`, NOT `trainerbattle_single`: this scene has already
	@ lockall'd, and the _single form supplies its OWN lock (S5's pin, and
	@ MauvilleCity_EventScript_BattleWally is the vanilla precedent for calling
	@ the no-intro form inside a locked scene). The cost is S1's known open item
	@ -- EventScript_DoNoIntroTrainerBattle calls PlayTrainerEncounterMusic
	@ unconditionally (data/scripts/trainer_battle.inc:53), so the last moment
	@ before the transition is MUS_ENCOUNTER_AQUA rather than the playbgm above.
	@ The playbgm is placed where it matters instead: under ARCHER's speech.
	@ setvar VAR_LAST_TALKED pins the engine's reveal emote on ARCHER rather than
	@ on whatever object was spoken to last; GSC does the same with
	@ `setlasttalked RADIOTOWER5F_ROCKET` (RadioTower5F.asm:88).
	setvar VAR_LAST_TALKED, LOCALID_JOHTO_RT5F_ARCHER
	trainerbattle_no_intro TRAINER_EXEC_ARCHER, RadioTower5F_Text_ArcherDefeat
	goto RadioTower5F_EventScript_ArcherBeaten
	end

RadioTower5F_EventScript_ArcherBeaten::
	msgbox RadioTower5F_Text_ArcherAfter, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	@ ---- THE DOCUMENTS. Act I's loose thread, closed. ----
	msgbox RadioTower5F_Text_Documents1, MSGBOX_DEFAULT
	msgbox RadioTower5F_Text_Documents2, MSGBOX_DEFAULT
	closemessage
	@ ---- THE CAMEO. R4 fade: nothing pops. ----
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_JOHTO_RT5F_ARCHER
	removeobject LOCALID_JOHTO_RT5F_ARIANA
	addobject LOCALID_JOHTO_RT5F_GIOVANNI
	delay 20
	fadescreen FADE_FROM_BLACK
	turnobject LOCALID_JOHTO_RT5F_GIOVANNI, DIR_EAST
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	msgbox RadioTower5F_Text_Giovanni1, MSGBOX_DEFAULT
	msgbox RadioTower5F_Text_Giovanni2, MSGBOX_DEFAULT
	closemessage
	@ ---- BOBBY INTERRUPTS. "Let him walk." has to land while G is still ON
	@ SCREEN, or it is not an interruption -- it is a man narrating an empty
	@ doorway. So BOBBY spawns and speaks FIRST, G finishes his exit AFTER, and
	@ the player turns to face the voice behind them in between.
	addobject LOCALID_JOHTO_RT5F_BOBBY
	applymovement LOCALID_JOHTO_RT5F_BOBBY, RadioTower5F_Movement_BobbyEnters
	waitmovement 0
	msgbox RadioTower5F_Text_BobbyInterrupt, MSGBOX_DEFAULT
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	@ G leaves unhurried, and unchallenged, which is the point of the beat.
	applymovement LOCALID_JOHTO_RT5F_GIOVANNI, RadioTower5F_Movement_GiovanniLeaves
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject LOCALID_JOHTO_RT5F_GIOVANNI
	fadedefaultbgm
	delay 30
	msgbox RadioTower5F_Text_Bobby1, MSGBOX_DEFAULT
	closemessage
	@ The badge. A white flash is this repo's own idiom for a beat that has to
	@ read as an object being held up (S6's AMPHY cure uses the same sandwich).
	fadescreen FADE_TO_WHITE
	delay 20
	fadescreen FADE_FROM_WHITE
	msgbox RadioTower5F_Text_Bobby2, MSGBOX_DEFAULT
	msgbox RadioTower5F_Text_Bobby3, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_TRINITY_J_BOBBY_REVEALED
	applymovement LOCALID_JOHTO_RT5F_BOBBY, RadioTower5F_Movement_BobbyLeaves
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject LOCALID_JOHTO_RT5F_BOBBY
	call RadioTower5F_EventScript_AdvanceToScene4
	releaseall
	end

RadioTower5F_EventScript_AdvanceToScene4::
	goto_if_ge VAR_TRINITY_JOHTO_SCENE_GOLDENROD, 4, RadioTower5F_EventScript_Scene4AlreadySet
	setvar VAR_TRINITY_JOHTO_SCENE_GOLDENROD, 4
RadioTower5F_EventScript_Scene4AlreadySet::
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 7, RadioTower5F_EventScript_Arc7AlreadySet
	setvar VAR_TRINITY_JOHTO_ARC, 7
RadioTower5F_EventScript_Arc7AlreadySet::
	return

RadioTower5F_Movement_PlayerTwoWest:
	walk_left
	walk_left
	step_end

@ (13,5) -> (13,6) -> (13,7) -> (14,7) -> (15,7) -> (16,7). All decoded
@ collision 0, elevation 3, MB_NORMAL, all inside the camera window.
RadioTower5F_Movement_GiovanniLeaves:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

@ (16,5) -> (15,5): one step, so he ends adjacent to the player on (14,5).
RadioTower5F_Movement_BobbyEnters:
	walk_left
	step_end

RadioTower5F_Movement_BobbyLeaves:
	walk_right
	walk_up
	walk_up
	step_end

@ ============================================================================
@ Trinity M4b S8 text. The imposter, the tower's fall, and the two reveals.
@ ============================================================================
RadioTower5F_Text_ImposterIntro:
	.string "Y-you! You came to rescue me?\p"
	.string "…Is that what you were\n"
	.string "expecting?\p"
	.string "Wrong. I'm an imposter.\p"
	.string "I have sat at this desk for\n"
	.string "eleven days. I signed for the\l"
	.string "post. I approved the schedule.\p"
	.string "Nobody looks at a DIRECTOR\n"
	.string "twice, {PLAYER}. That's the trick\l"
	.string "of it.\p"
	.string "Want to know where we put the\n"
	.string "real one?\p"
	.string "Certainly. Beat it out of me.$"

RadioTower5F_Text_ImposterDefeat:
	.string "All right. All right.\n"
	.string "I'll tell you where he is.$"

RadioTower5F_Text_ImposterWhereHeIs:
	.string "We stashed your DIRECTOR in the\n"
	.string "UNDERGROUND WAREHOUSE.\p"
	.string "Far end of the UNDERGROUND,\n"
	.string "past the locked door.\p"
	.string "You'll want this, then. Not\n"
	.string "that it'll help.\p"
	.string "Eleven doors and three switches\n"
	.string "between you and him, and men on\l"
	.string "every one.$"

RadioTower5F_Text_ReceivedBasementKey:
	.string "{PLAYER} received the\n"
	.string "BASEMENT KEY.$"

RadioTower5F_Text_ArianaSeen:
	.string "Remember me? MAHOGANY TOWN.\n"
	.string "The room with the machine.\p"
	.string "I lost that day. I've thought\n"
	.string "about it since.\p"
	.string "Nobody goes down that corridor.$"

RadioTower5F_Text_ArianaBeaten:
	.string "This can't be happening.\p"
	.string "I fought hard, and I still\n"
	.string "lost…$"

RadioTower5F_Text_ArianaAfter:
	.string "{PLAYER}, isn't it.\p"
	.string "A brat like you will never\n"
	.string "appreciate the magnificence of\l"
	.string "TEAM ROCKET.\p"
	.string "That's the sad part. I do\n"
	.string "admire your power.$"

@ INTENTIONALLY UNREACHABLE / DEFENSIVE -- see the idle scripts above.
RadioTower5F_Text_ArcherIdle:
	.string "…$"

RadioTower5F_Text_GiovanniIdle:
	.string "…$"

RadioTower5F_Text_BobbyIdle:
	.string "…$"

@ GSC RadioTower5FRocketBossBeforeText, adapted: in Trinity the broadcast is not
@ a summons into the dark, it is a signal to a man who is already listening.
RadioTower5F_Text_ArcherBefore:
	.string "ARCHER: Oh? You got this far.\p"
	.string "Then you're quite the trainer.\n"
	.string "I'll try to remember that.\p"
	.string "We intend to take this station\n"
	.string "and announce that TEAM ROCKET\l"
	.string "is standing again.\p"
	.string "Every set in JOHTO. Every set\n"
	.string "in KANTO. Anyone in range of a\l"
	.string "signal, hearing it at once.\p"
	.string "That should bring our boss back\n"
	.string "from his solo training.\p"
	.string "…No. That is what I tell the\n"
	.string "men.\p"
	.string "The truth is he has been back\n"
	.string "for three years, and he has not\l"
	.string "once called.\p"
	.string "Tonight he will have to.$"

RadioTower5F_Text_ArcherDefeat:
	.string "No. Forgive me, GIOVANNI!$"

@ GSC RadioTower5FRocketBossAfterText, adapted: he still disbands, but the crack
@ is Trinity's -- he is not afraid of the CHAMPION, he is afraid of the invoice.
RadioTower5F_Text_ArcherAfter:
	.string "ARCHER: How could this be?\p"
	.string "Our dreams have come to\n"
	.string "nothing. I wasn't up to it\l"
	.string "after all.\p"
	.string "Like GIOVANNI before me, I will\n"
	.string "disband TEAM ROCKET, here,\l"
	.string "today.\p"
	.string "…Understand something,\n"
	.string "{PLAYER}. This was never our\l"
	.string "money.\p"
	.string "The machine at MAHOGANY. The\n"
	.string "men. This tower.\p"
	.string "Somebody paid for all of it,\n"
	.string "and I have never once been told\l"
	.string "his name to my face.\p"
	.string "Farewell.$"

@ THE DOCUMENTS. SlateportCity_Harbor already ships a sailor who says "A
@ financier. 'G,' the papers said." This is the other end of that sentence.
RadioTower5F_Text_Documents1:
	.string "A printer was still running by\n"
	.string "the console.\p"
	.string "{PLAYER} pulled the top sheets\n"
	.string "off the tray.$"

RadioTower5F_Text_Documents2:
	.string "Transfer ledgers. Three years\n"
	.string "of them.\p"
	.string "Two accounts in HOENN, drawn\n"
	.string "the same week: one to a group\l"
	.string "that wanted the sea, one to a\l"
	.string "group that wanted the land.\p"
	.string "Both bankrupt within a month of\n"
	.string "SOOTOPOLIS. Neither ever knew\l"
	.string "about the other.\p"
	.string "Then MAHOGANY. Then this\n"
	.string "building.\p"
	.string "Every page authorized by one\n"
	.string "signature.\p"
	.string "A single letter.\p"
	.string "G.$"

RadioTower5F_Text_Giovanni1:
	.string "?: Put it down, please.\p"
	.string "You've read it. Reading it\n"
	.string "twice will not make it smaller.\p"
	.string "GIOVANNI: You may as well have\n"
	.string "the name too. It's on the paper\l"
	.string "in your hand.\p"
	.string "I am GIOVANNI.\p"
	.string "Three years ago I walked away\n"
	.string "from a gym, a hideout and eight\l"
	.string "hundred people, and I have been\l"
	.string "working ever since.\p"
	.string "HOENN was work. Two teams, one\n"
	.string "budget, a great deal learned\l"
	.string "about what a legendary POKéMON\l"
	.string "does when it is pushed.\p"
	.string "MAHOGANY was work. The LAKE was\n"
	.string "work.\p"
	.string "This --\p"
	.string "This was ARCHER missing me.$"

RadioTower5F_Text_Giovanni2:
	.string "GIOVANNI: I came to see the\n"
	.string "trainer who kept ending my\l"
	.string "experiments early.\p"
	.string "You are shorter than the file\n"
	.string "suggested.\p"
	.string "…Don't. There is nothing here\n"
	.string "to arrest and nothing here to\l"
	.string "battle. Not tonight.\p"
	.string "There is a LEAGUE waiting for\n"
	.string "you, and whatever you still owe\l"
	.string "it, and by the time you are\l"
	.string "done I will be home.\p"
	.string "Come east when you're finished,\n"
	.string "{PLAYER}.\p"
	.string "I'd like to see what you do\n"
	.string "with the rest of it.$"

RadioTower5F_Text_BobbyInterrupt:
	.string "?: Let him walk.$"

RadioTower5F_Text_Bobby1:
	.string "BOBBY: Hey. Long way from\n"
	.string "HOENN.\p"
	.string "Don't look at me like that. I\n"
	.string "know exactly who just left.$"

RadioTower5F_Text_Bobby2:
	.string "BOBBY: INTERNATIONAL POLICE.\p"
	.string "Four years on this file. Two of\n"
	.string "them in a windbreaker,\l"
	.string "pretending to lose to you on\l"
	.string "ROUTE 118.\p"
	.string "HARJOT knows. The others don't,\n"
	.string "and you're going to leave it\l"
	.string "that way.$"

RadioTower5F_Text_Bobby3:
	.string "BOBBY: We could have taken him\n"
	.string "on those ledgers tonight.\p"
	.string "We'd have got a financier, a\n"
	.string "fine, and a very good lawyer.\p"
	.string "I want the whole thing. The\n"
	.string "hideout, the science, whatever\l"
	.string "he's been building under that\l"
	.string "gym.\p"
	.string "So he walks, and I follow, and\n"
	.string "you finish what you came to\l"
	.string "JOHTO to do.\p"
	.string "You've been a very useful\n"
	.string "friend, {PLAYER}. I'm sorry\l"
	.string "about the useful part.$"

@ GSC RadioTower5FDirectorThankYouText + …DescribeClearBellText, extended:
@ Trinity's director hands over BOTH the RAINBOW WING and the CLEAR BELL, and
@ his speech is S10's brief -- TIN TOWER, and the whispering about the WHIRL
@ ISLANDS.
RadioTower5F_Text_DirectorThankYou:
	.string "DIRECTOR: {PLAYER}. Thank you.\p"
	.string "Your courage has saved POKéMON\n"
	.string "nationwide, and one middle-aged\l"
	.string "man in a warehouse.\p"
	.string "I know it isn't much, but I'd\n"
	.string "like you to have these.\p"
	.string "They came out of the ground\n"
	.string "under this building and I have\l"
	.string "never known what to do with\l"
	.string "them.$"

RadioTower5F_Text_ReceivedRainbowWing:
	.string "{PLAYER} received the\n"
	.string "RAINBOW WING.$"

RadioTower5F_Text_DescribeRainbowWing:
	.string "DIRECTOR: A feather. It has\n"
	.string "held its color for however\l"
	.string "long it has been down there.\p"
	.string "The old people in ECRUTEAK say\n"
	.string "a bird burned with the BRASS\l"
	.string "TOWER and never came back.\p"
	.string "They also say it would come\n"
	.string "back for the right person.\p"
	.string "I am a radio man. I only repeat\n"
	.string "what I'm told.$"

RadioTower5F_Text_ReceivedClearBell:
	.string "{PLAYER} received the\n"
	.string "CLEAR BELL.$"

RadioTower5F_Text_DescribeClearBell:
	.string "DIRECTOR: There used to be a\n"
	.string "tower right here in GOLDENROD.\p"
	.string "Old, and creaky, and beloved.\n"
	.string "We replaced it with this one.\p"
	.string "We dug that bell out of the\n"
	.string "foundation.\p"
	.string "I've always thought it belonged\n"
	.string "with the TIN TOWER in ECRUTEAK\l"
	.string "CITY. Ring it there, perhaps.\p"
	.string "…Ah. That reminds me.\p"
	.string "I overheard TEAM ROCKET\n"
	.string "whispering while they had me.\p"
	.string "Something is happening at the\n"
	.string "TIN TOWER. And they had a man\l"
	.string "watching the WHIRL ISLANDS, of\l"
	.string "all the useless places.\p"
	.string "I have no idea what any of it\n"
	.string "means. You might look into it.\p"
	.string "Now. I have an OFFICE to get\n"
	.string "back to.$"

RadioTower5F_Text_DirectorAfter:
	.string "DIRECTOR: Hello again!\p"
	.string "We're back on the air. Music\n"
	.string "this hour, then the POKéMON\l"
	.string "CHANNEL.\p"
	.string "Nobody in JOHTO heard a single\n"
	.string "word those people wanted said.\p"
	.string "That's down to you.$"
