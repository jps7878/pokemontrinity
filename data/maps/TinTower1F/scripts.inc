TinTower1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TinTower1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, TinTower1F_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TinTower1F_OnFrame
	.byte 0

@ ============================================================================
@ Trinity M4b S10 -- THE SUICUNE SHOWDOWN. B1-B5 (S5's awakening template),
@ wrapped around the vanilla static-legendary skeleton
@ (NavelRock_Bottom_EventScript_Lugia, data/maps/NavelRock_Bottom/scripts.inc).
@
@ THE MAP, DECODED. 1F is 158 walkable / 120 reachable, and the difference is a
@ 24-tile INNER SANCTUM (x 7..12, y 5..9) walled on all four sides. That is not
@ a port defect: decoding pokecrystal's own TinTower1F.blk through
@ tower_collision.asm gives 120 of 158 as well, with the same box sealed. GSC's
@ beast tiles (9,9) SUICUNE / (7,9) RAIKOU / (12,9) ENTEI are INSIDE it, which
@ is exactly why GSC's SUICUNE is a scene and never a talk -- the player can
@ never stand next to it. All three therefore cost ZERO walkability.
@
@ B1  One OBJ_EVENT_GFX_SPECIES(...) object per beast, all on ONE _HIDE flag,
@     authored by ON_TRANSITION off the scene var with EXACT EQUALITY. A shared
@     cast flag is only correct while every member retires together (S4 C1);
@     these three do, permanently, in one scene.
@ B2  The trigger is MAP_SCRIPT_ON_FRAME_TABLE, not a coord_event, because the
@     arrival tile is PROVABLE: EcruteakCity (37,7) -> MAP_TIN_TOWER_1F#0 is the
@     ONLY door into this map and warp 0 is (9,15). S9's rule -- ON_FRAME is the
@     right trigger for an on-entry cutscene WHEN the scene advances the var it
@     is gated on, and it is the direct equivalent of GSC's scene_script.
@     The player is walked up 3 to (9,12): (9,14) (9,13) (9,12) all decode
@     collision 0 / elevation 3 / MB_NORMAL and are reachable.
@     CAMERA, checked once: the viewport is 15x10 with the player on the 5th
@     row, so at (9,12) it shows rows 8..17 and columns 2..16. RAIKOU (7,9),
@     SUICUNE (9,9) and ENTEI (12,9) are all inside it.
@ B3  Wake beat = emote -> playmoncry -> delay, one at a time. Flee beat =
@     applymovement on decoded floor -> playse SE_WARP_OUT -> removeobject.
@     SUICUNE's leap is ONE jump_2_down, which moves TWO tiles as two one-tile
@     shifts (S6: sJumpInitDisplacements[FAR] at Step0 + sJumpDisplacements[FAR]
@     at JUMP_HALFWAY, src/event_object_movement.c:7269-7285, 7343-7346), taking
@     it (9,9) -> (9,11) OVER the sanctum's south wall at (9,10) (collision 1).
@     Scripted movement ignores collision, water and elevation entirely
@     (InitNpcForMovement, :6872-6890), so the wall is scenery to it.
@     BEHAVIOUR-decoded, not just collision-decoded (S5 M2): (9,11) is
@     MB_NORMAL, elevation 3, collision 0, reachable, and row 11 is 12 tiles
@     wide (x 4..15) so standing there is not a cut vertex.
@ B4  The player is never moved once a beast starts moving -- only faced. The
@     walk-in happens first and crosses no hazard: 1F has no
@     MB_CRACKED_FLOOR_HOLE, no ledge and no water.
@ B5  The scene's only durable outputs are ONE monotonic scene-var advance and
@     the flag co-signs removeobject performs. ARC 9 belongs to the BATTLE.
@
@ THE STATE MACHINE (VAR_TRINITY_JOHTO_SCENE_TINTOWER, 0x40FF):
@   0  the sanctum tableau stands, the showdown is armed
@   1  the showdown has played. A SUICUNE that FLED leaves the var here, so
@      ON_TRANSITION puts the HALL object back at (9,11) on the next entry and
@      the talk path re-fights it -- the vanilla contract
@      (NavelRock_Bottom_OnTransition's call_if_unset is what makes a fled
@      legendary re-fightable).
@   2  SUICUNE beaten or caught. Both casts hidden forever; ARC := 9.
@
@ SHIPPED SHAPE vs THE PLAN, and the shipped one is better. The plan had the
@ cutscene end with `clearflag <hall hide>` + `addobject` so the hall SUICUNE
@ existed for the battle. It does not need to: the SANCTUM object is the one
@ already on screen, it is the one that leaps, and setting VAR_LAST_TALKED to it
@ makes it the one that fights -- so the scene needs NO addobject at all, and
@ the hall object is authored the ordinary way by ON_TRANSITION on the next map
@ load. One fewer session-only spawn (S7's trap: `addobject` does not clear the
@ visibility flag, so an addobject'ed actor persists only if ON_TRANSITION's
@ predicate is already true) and one fewer place for the two states to disagree.
@
@ WHY TWO SUICUNE OBJECTS AT ALL. Object positions NEVER persist:
@ LoadObjEventTemplatesFromHeader CpuCopy32s the ROM templates back on EVERY map
@ load (src/overworld.c:521-530, S9's finding). So the leap cannot be what puts
@ SUICUNE on the hall floor across a reload. One object per state, each with its
@ own exact-equality predicate, is the B1 shape.
@
@ SKIPPED FROM GSC, LOGGED: EUSINE's post-battle coda (no trainer id, no sprite
@ pin; the WISE TRIO already carry the lore) - TinTower1FStairsCallback's
@ changeblock, which deletes the 2F stairs until the RAINBOW WING (Trinity gates
@ HO-OH at the roof on the wing instead: same gate, no D1-D5 door) - GSC's
@ retroactive cancelling of the three roamer glimpses (Trinity has no roamers).
@ ============================================================================

TinTower1F_OnTransition::
	call_if_eq VAR_TRINITY_JOHTO_SCENE_TINTOWER, 0, TinTower1F_EventScript_ShowTableau
	call_if_ne VAR_TRINITY_JOHTO_SCENE_TINTOWER, 0, TinTower1F_EventScript_HideTableau
	call_if_eq VAR_TRINITY_JOHTO_SCENE_TINTOWER, 1, TinTower1F_EventScript_ShowHallSuicune
	call_if_ne VAR_TRINITY_JOHTO_SCENE_TINTOWER, 1, TinTower1F_EventScript_HideHallSuicune
	end

TinTower1F_EventScript_ShowTableau::
	clearflag FLAG_TRINITY_J_TT1_BEASTS_HIDE
	return

TinTower1F_EventScript_HideTableau::
	setflag FLAG_TRINITY_J_TT1_BEASTS_HIDE
	return

TinTower1F_EventScript_ShowHallSuicune::
	clearflag FLAG_TRINITY_J_SUICUNE_HALL_HIDE
	return

TinTower1F_EventScript_HideHallSuicune::
	setflag FLAG_TRINITY_J_SUICUNE_HALL_HIDE
	return

@ THE THIRD MANDATORY CLAUSE of the vanilla legendary contract. A CAUGHT
@ legendary never re-enters the talk script, so without this the object stands
@ there as a ghost. FLAG_SYS_CTRL_OBJ_DELETE is set around the battle and only
@ then does this fire.
TinTower1F_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TinTower1F_EventScript_TryRemoveSuicune
	end

TinTower1F_EventScript_TryRemoveSuicune::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

TinTower1F_OnFrame::
	map_script_2 VAR_TRINITY_JOHTO_SCENE_TINTOWER, 0, TinTower1F_EventScript_Showdown
	.2byte 0

TinTower1F_EventScript_Showdown::
	lockall
	applymovement LOCALID_PLAYER, TinTower1F_Movement_PlayerApproach
	waitmovement 0
	fadeoutbgm 4
	delay 40
	msgbox TinTower1F_Text_TheHallIsNotEmpty, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_JOHTO_TT1_RAIKOU, Common_Movement_ExclamationMark
	waitmovement 0
	playmoncry SPECIES_RAIKOU, CRY_MODE_NORMAL
	waitmoncry
	delay 15
	applymovement LOCALID_JOHTO_TT1_ENTEI, Common_Movement_ExclamationMark
	waitmovement 0
	playmoncry SPECIES_ENTEI, CRY_MODE_NORMAL
	waitmoncry
	delay 30

	@ The two escorts go. (7,9) west, (12,9) east -- both inside the sanctum,
	@ both covered by SE_WARP_OUT, which is GSC's own cover for this
	@ (playsound SFX_WARP_FROM / disappear) and the documented R4 deviation S5
	@ established: three fades to black inside a cutscene would destroy the beat
	@ R4 exists to protect.
	applymovement LOCALID_JOHTO_TT1_RAIKOU, TinTower1F_Movement_RaikouWithdraws
	waitmovement 0
	playse SE_WARP_OUT
	waitse
	removeobject LOCALID_JOHTO_TT1_RAIKOU
	applymovement LOCALID_JOHTO_TT1_ENTEI, TinTower1F_Movement_EnteiWithdraws
	waitmovement 0
	playse SE_WARP_OUT
	waitse
	removeobject LOCALID_JOHTO_TT1_ENTEI
	delay 20

	@ SUICUNE comes over the wall. (9,9) -> (9,11), one jump_2_down.
	msgbox TinTower1F_Text_SuicuneDoesNotRun, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JOHTO_TT1_SUICUNE, TinTower1F_Movement_SuicuneVaults
	waitmovement 0
	delay 30

	setvar VAR_TRINITY_JOHTO_SCENE_TINTOWER, 1
	setvar VAR_LAST_TALKED, LOCALID_JOHTO_TT1_SUICUNE
	goto TinTower1F_EventScript_SuicuneBattle

@ The HALL object -- the same fight, reached by talking, for a player whose
@ SUICUNE fled. S1's state guard: the object is only ever on stage at SCENE == 1,
@ but a visibility invariant is not a substitute for a state check.
TinTower1F_EventScript_SuicuneHall::
	lock
	faceplayer
	goto_if_ne VAR_TRINITY_JOHTO_SCENE_TINTOWER, 1, TinTower1F_EventScript_SuicuneIdle
	goto TinTower1F_EventScript_SuicuneBattle

@ INTENTIONALLY UNREACHABLE / DEFENSIVE. ON_TRANSITION is the single authoring
@ site for FLAG_TRINITY_J_SUICUNE_HALL_HIDE and it clears the flag on exactly
@ one value of the scene var, the same value this script tests. Written anyway,
@ per S1.
TinTower1F_EventScript_SuicuneIdle::
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	waitmoncry
	release
	end

@ ---------------------------------------------------------------------------
@ THE SHARED BATTLE BODY. Both the coord path and the talk path reach it by
@ `goto`, which is S1's call-ed-confrontation idiom in its simplest form: ONE
@ battle, two ways in.
@
@ `seteventmon` over `setwildbattle`: it is the NavelRock idiom and it sets the
@ modern-fateful-encounter bit, which is what a scripted legendary wants. It is
@ NOT a single opcode -- asm/macros/event.inc:2115-2121 expands it into three
@ setvars plus a special, so it CLOBBERS VAR_0x8004/5/6. That is why the flee
@ tail re-writes VAR_0x8004 before handing off.
@
@ `special BattleSetup_StartLegendaryBattle` is the ONLY route to the contract's
@ music pin: dowildbattle goes through BattleSetup_StartScriptedWildBattle,
@ which sets gBattleTypeFlags = 0 and passes song 0, so GetBattleBGM falls to
@ MUS_VS_WILD and a prior playbgm is wiped by PlayMapChosenOrBattleBGM's
@ ResetMapMusic/m4aMPlayAllStop (src/pokemon.c:6184-6192). The legendary path
@ also gives the legendary backdrop, the legendary encounter message and no
@ random held item. S10 added the SUICUNE/RAIKOU/ENTEI case to that switch
@ (src/battle_setup.c) -- required, because its `default:` sits on the GROUDON
@ body and an unlisted species silently got MUS_VS_KYOGRE_GROUDON.
@
@ releaseall on every tail: the coord path is lockall, and releaseall is a
@ superset of release, so one set of tails serves both entrances. Vanilla's Sky
@ Pillar hand-rolls the same duplication for the same reason.
@ ---------------------------------------------------------------------------
TinTower1F_EventScript_SuicuneBattle::
	waitse
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_SUICUNE, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TinTower1F_EventScript_SuicuneDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, TinTower1F_EventScript_SuicuneFled
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, TinTower1F_EventScript_SuicuneFled
	@ fall-through == B_OUTCOME_CAUGHT. ON_RESUME has already removed the object.
	call TinTower1F_EventScript_SuicuneResolved
	msgbox TinTower1F_Text_SuicuneCaught, MSGBOX_DEFAULT
	releaseall
	end

TinTower1F_EventScript_SuicuneDefeated::
	call TinTower1F_EventScript_SuicuneResolved
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreen FADE_FROM_BLACK
	msgbox TinTower1F_Text_SuicuneAccepts, MSGBOX_DEFAULT
	releaseall
	end

@ The arc write is MONOTONIC-GUARDED (S1's rule): this runs from a talk script
@ that a re-fight can reach, so a bare setvar would be re-runnable.
TinTower1F_EventScript_SuicuneResolved::
	setvar VAR_TRINITY_JOHTO_SCENE_TINTOWER, 2
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 9, TinTower1F_EventScript_ArcAlready
	setvar VAR_TRINITY_JOHTO_ARC, 9
	return

TinTower1F_EventScript_ArcAlready::
	return

TinTower1F_EventScript_SuicuneFled::
	setvar VAR_0x8004, SPECIES_SUICUNE
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreen FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	msgbox TinTower1F_Text_ItWillCircleBack, MSGBOX_DEFAULT
	releaseall
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE. The tableau stands inside a 24-tile box
@ that is sealed in the shipped map AND in pokecrystal, so no walk reaches it.
@ No faceplayer: they are not looking at the player, they are waiting.
TinTower1F_EventScript_Tableau::
	lock
	msgbox TinTower1F_Text_Tableau, MSGBOX_DEFAULT
	release
	end

@ ---------------------------------------------------------------------------
@ The three sages. GSC swaps two three-man casts on EVENT_FOUGHT_SUICUNE; one
@ cast with branching dialogue is the S4 lesson (a character who survives the
@ beat gets a new line, not a duplicate object on a second flag) and it saves
@ three flags and three objects. GSC tiles, all decoded collision 0 /
@ elevation 3 / MB_NORMAL / reachable: (5,9) (11,11) (14,6).
@ ---------------------------------------------------------------------------
TinTower1F_EventScript_SageA::
	lock
	faceplayer
	goto_if_ge VAR_TRINITY_JOHTO_SCENE_TINTOWER, 2, TinTower1F_EventScript_SageAAfter
	msgbox TinTower1F_Text_SageA, MSGBOX_DEFAULT
	release
	end

@ S13b: the Wise Trio battles, Johto backfill. All three sages gain a
@ TRAINER_SAGE_* fight (real party data, opponents.h, Wise Trio corps),
@ reached only through their existing SCENE_TINTOWER>=2 "After" branch --
@ Johto-local gating only (no VAR_TRINITY_KANTO_ARC read: this is backfill
@ content independent of the Kanto arc, matching every other purely-Johto
@ script in this file). One-fight-per-id via the engine trainer flag,
@ explicit top-of-branch guard (same reasoning as BOBBY/SILVER this slice:
@ a msgbox precedes the fight, so the guard must be explicit, not left to
@ trainerbattle's own internal fallthrough). trainerbattle_no_intro: a
@ custom challenge line plays first via msgbox.
TinTower1F_EventScript_SageAAfter::
	msgbox TinTower1F_Text_SageAAfter, MSGBOX_DEFAULT
	checktrainerflag TRAINER_SAGE_GAKU
	goto_if TRUE, TinTower1F_EventScript_SageABeaten
	msgbox TinTower1F_Text_SageAChallenge, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SAGE_GAKU, TinTower1F_Text_SageADefeat
	release
	end

TinTower1F_EventScript_SageABeaten::
	msgbox TinTower1F_Text_SageABeatenFlavor, MSGBOX_DEFAULT
	release
	end

TinTower1F_EventScript_SageB::
	lock
	faceplayer
	goto_if_ge VAR_TRINITY_JOHTO_SCENE_TINTOWER, 2, TinTower1F_EventScript_SageBAfter
	msgbox TinTower1F_Text_SageB, MSGBOX_DEFAULT
	release
	end

TinTower1F_EventScript_SageBAfter::
	msgbox TinTower1F_Text_SageBAfter, MSGBOX_DEFAULT
	checktrainerflag TRAINER_SAGE_MASA
	goto_if TRUE, TinTower1F_EventScript_SageBBeaten
	msgbox TinTower1F_Text_SageBChallenge, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SAGE_MASA, TinTower1F_Text_SageBDefeat
	release
	end

TinTower1F_EventScript_SageBBeaten::
	msgbox TinTower1F_Text_SageBBeatenFlavor, MSGBOX_DEFAULT
	release
	end

TinTower1F_EventScript_SageC::
	lock
	faceplayer
	goto_if_ge VAR_TRINITY_JOHTO_SCENE_TINTOWER, 2, TinTower1F_EventScript_SageCAfter
	msgbox TinTower1F_Text_SageC, MSGBOX_DEFAULT
	release
	end

TinTower1F_EventScript_SageCAfter::
	msgbox TinTower1F_Text_SageCAfter, MSGBOX_DEFAULT
	checktrainerflag TRAINER_SAGE_KOJI
	goto_if TRUE, TinTower1F_EventScript_SageCBeaten
	msgbox TinTower1F_Text_SageCChallenge, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SAGE_KOJI, TinTower1F_Text_SageCDefeat
	release
	end

TinTower1F_EventScript_SageCBeaten::
	msgbox TinTower1F_Text_SageCBeatenFlavor, MSGBOX_DEFAULT
	release
	end

@ --- movement ---------------------------------------------------------------

TinTower1F_Movement_PlayerApproach:
	walk_up
	walk_up
	walk_up
	step_end

@ (7,9) -> (7,7), inside the sanctum, away from the player.
TinTower1F_Movement_RaikouWithdraws:
	walk_fast_up
	walk_fast_up
	step_end

@ (12,9) -> (12,7), the mirror.
TinTower1F_Movement_EnteiWithdraws:
	walk_fast_up
	walk_fast_up
	step_end

@ (9,9) -> (9,11). jump_2_down clears (9,10), the sanctum's south wall.
TinTower1F_Movement_SuicuneVaults:
	jump_2_down
	face_down
	step_end

@ --- text -------------------------------------------------------------------

TinTower1F_Text_TheHallIsNotEmpty:
	.string "The hall is nine tiers of silence\n"
	.string "and every one of them is listening.\p"
	.string "Something is standing in the middle\n"
	.string "of it, and it is not alone.$"

TinTower1F_Text_SuicuneDoesNotRun:
	.string "The other two draw back.\p"
	.string "The third does not.$"

TinTower1F_Text_SuicuneAccepts:
	.string "SUICUNE holds your eye for a long\n"
	.string "moment, the way it did at the BURNED\l"
	.string "TOWER and on the CIANWOOD shore.\p"
	.string "Then it is gone, and the TOWER is\n"
	.string "only a tower again.$"

TinTower1F_Text_SuicuneCaught:
	.string "The hall is quiet.\p"
	.string "Nine tiers of it, and every one\n"
	.string "satisfied.$"

TinTower1F_Text_ItWillCircleBack:
	.string "It has not gone far. Whatever this\n"
	.string "was, it is not finished.$"

TinTower1F_Text_Tableau:
	.string "Three of them, waiting, and none of\n"
	.string "them surprised to see you.$"

TinTower1F_Text_SageA:
	.string "When the souls of POKéMON and\n"
	.string "people speak to one another, the\l"
	.string "legend says a POKéMON of rainbow\l"
	.string "colors comes down out of the sky.\p"
	.string "I used to think that was a promise.\p"
	.string "Lately I think it is a test.$"

TinTower1F_Text_SageAAfter:
	.string "It let you see it, and then it let\n"
	.string "you go.\p"
	.string "That is more than it has given\n"
	.string "anyone in a hundred years.$"

TinTower1F_Text_SageB:
	.string "When the BRASS TOWER burned, three\n"
	.string "nameless POKéMON died inside it.\p"
	.string "A rainbow-colored POKéMON came\n"
	.string "down and gave them their lives\l"
	.string "back. That is the story.\p"
	.string "SUICUNE. ENTEI. RAIKOU.\n"
	.string "That is what the story calls them.$"

TinTower1F_Text_SageBAfter:
	.string "One of the three has settled its\n"
	.string "account with you.\p"
	.string "The other two are still out there,\n"
	.string "and they have not settled theirs.$"

TinTower1F_Text_SageC:
	.string "Two towers were raised here seven\n"
	.string "hundred years ago, to keep faith\l"
	.string "between POKéMON and people.\p"
	.string "One of them is a ruin and the other\n"
	.string "one is this. The idea is older than\l"
	.string "both and it has not aged.$"

TinTower1F_Text_SageCAfter:
	.string "Look up, champion. Nine tiers, and\n"
	.string "a roof above them.\p"
	.string "The one that gave the three their\n"
	.string "lives back has been known to stand\l"
	.string "on it.$"

TinTower1F_Text_SageAChallenge:
	.string "A test, I said. Tests should not\n"
	.string "only run one direction.$"

TinTower1F_Text_SageADefeat:
	.string "…$"

TinTower1F_Text_SageABeatenFlavor:
	.string "The trees are still very quiet.\n"
	.string "You did not change that either.$"

TinTower1F_Text_SageBChallenge:
	.string "Two have not settled their account.\n"
	.string "Neither, I think, have we.$"

TinTower1F_Text_SageBDefeat:
	.string "…$"

TinTower1F_Text_SageBBeatenFlavor:
	.string "Settled. For whatever that is worth\n"
	.string "between us.$"

TinTower1F_Text_SageCChallenge:
	.string "Nine tiers, and I have climbed\n"
	.string "every one. Let us see about you.$"

TinTower1F_Text_SageCDefeat:
	.string "…$"

TinTower1F_Text_SageCBeatenFlavor:
	.string "Look up all you like now. You have\n"
	.string "earned the view.$"
