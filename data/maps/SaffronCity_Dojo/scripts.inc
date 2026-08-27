SaffronCity_Dojo_MapScripts::
	.byte 0

SaffronCity_Dojo_EventScript_Hitoshi::
	trainerbattle_single TRAINER_KANTO_BLACK_BELT_HITOSHI, SaffronCity_Dojo_Text_HitoshiSeen, SaffronCity_Dojo_Text_HitoshiBeaten
	msgbox SaffronCity_Dojo_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Hideki::
	trainerbattle_single TRAINER_KANTO_BLACK_BELT_HIDEKI, SaffronCity_Dojo_Text_HidekiSeen, SaffronCity_Dojo_Text_HidekiBeaten
	msgbox SaffronCity_Dojo_Text_HidekiPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Aaron::
	trainerbattle_single TRAINER_KANTO_BLACK_BELT_AARON, SaffronCity_Dojo_Text_AaronSeen, SaffronCity_Dojo_Text_AaronBeaten
	msgbox SaffronCity_Dojo_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Mike::
	trainerbattle_single TRAINER_KANTO_BLACK_BELT_MIKE, SaffronCity_Dojo_Text_MikeSeen, SaffronCity_Dojo_Text_MikeBeaten
	msgbox SaffronCity_Dojo_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ Trinity M5b S2 -- KANTO's move relearner. FRLG's own Master Koichi gifts a
@ Hitmonlee/Hitmonchan choice via famechecker/showmonpic machinery this tree
@ doesn't have; that beat is deliberately DROPPED, not substituted (the
@ brief's scope names only the relearner for this map -- see
@ docs/superpowers/plans/m5b/02-saffron-chapter.md section 5.3). T10's
@ `trainerbattle_single` wiring (id, tile, seen/defeat text) is unchanged;
@ the continuation below is what used to be a bare "..." post-battle msgbox.
@
@ Idempotence, same mechanism S1 traced for SURGE: an already-beaten trainer
@ falls through EventScript_TryDoNormalTrainerBattle's GetTrainerFlag branch
@ straight to the bytes after trainerbattle_single's own arguments -- the
@ SAME address a fresh victory continues to. So this fires once on defeat
@ and again on every later re-talk, with no extra branching needed.
@ ============================================================================
SaffronCity_Dojo_EventScript_MasterKoichi::
	trainerbattle_single TRAINER_KANTO_BLACK_BELT_KOICHI, SaffronCity_Dojo_Text_MasterKoichiSeen, SaffronCity_Dojo_Text_MasterKoichiBeaten
	goto SaffronCity_Dojo_EventScript_MoveRelearner
	end

@ FallarborTown_MoveRelearnersHouse's own pattern, copied verbatim (labels/
@ text renamed): ITEM_HEART_SCALE economy kept exactly, cost unchanged per
@ the brief's explicit instruction. FLAG_TEMP_1 is transient (cleared every
@ map load by ClearTempFieldEventData, Fallarbor's own scratch flag) -- no
@ persistent scene-scratch var claimed.
SaffronCity_Dojo_EventScript_MoveRelearner::
	goto_if_set FLAG_TEMP_1, SaffronCity_Dojo_EventScript_AskTeachMove
	msgbox SaffronCity_Dojo_Text_ImTheDojoMaster, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto SaffronCity_Dojo_EventScript_AskTeachMove
	end

SaffronCity_Dojo_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Dojo_EventScript_ComeBackWithHeartScale
	msgbox SaffronCity_Dojo_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SaffronCity_Dojo_EventScript_ComeBackWithHeartScale
	goto SaffronCity_Dojo_EventScript_ChooseMon
	end

SaffronCity_Dojo_EventScript_ChooseMon::
	msgbox SaffronCity_Dojo_Text_TutorWhichMon, MSGBOX_DEFAULT
	setmoverelearnerstate MOVE_RELEARNER_LEVEL_UP_MOVES
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SaffronCity_Dojo_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, SaffronCity_Dojo_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, SaffronCity_Dojo_EventScript_NoMoveToTeachMon
	goto SaffronCity_Dojo_EventScript_ChooseMove
	end

SaffronCity_Dojo_EventScript_ChooseMove::
	msgbox SaffronCity_Dojo_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, SaffronCity_Dojo_EventScript_ChooseMon
	msgbox SaffronCity_Dojo_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto SaffronCity_Dojo_EventScript_ComeBackWithHeartScale
	end

SaffronCity_Dojo_EventScript_NoMoveToTeachMon::
	msgbox SaffronCity_Dojo_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto SaffronCity_Dojo_EventScript_ChooseMon
	end

SaffronCity_Dojo_EventScript_CantTeachEgg::
	msgbox SaffronCity_Dojo_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto SaffronCity_Dojo_EventScript_ChooseMon
	end

@ `release`, not `releaseall`: this whole chain runs inside the single-object
@ lock `trainerbattle_single` itself established (G3: `trainerbattle_single`
@ supplies its own lock/faceplayer), never a lockall -- matching the G2
@ continuation idiom (SURGE/SABRINA's own giveitem tails always `release`).
SaffronCity_Dojo_EventScript_ComeBackWithHeartScale::
	msgbox SaffronCity_Dojo_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	release
	end

SaffronCity_Dojo_EventScript_Statue::
	msgbox SaffronCity_Dojo_Text_Statue, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_Statue_2::
	msgbox SaffronCity_Dojo_Text_Statue_2, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_LeftScroll::
	msgbox SaffronCity_Dojo_Text_LeftScroll, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_RightScroll::
	msgbox SaffronCity_Dojo_Text_RightScroll, MSGBOX_SIGN
	end

SaffronCity_Dojo_Text_HitoshiSeen:
	.string "A trainer who can't take a fall\n"
	.string "can't call themself a fighter.$"

SaffronCity_Dojo_Text_HitoshiBeaten:
	.string "Down I go.$"

SaffronCity_Dojo_Text_HitoshiPostBattle:
	.string "The MASTER trains upstairs. Down\n"
	.string "here we just soften you up.$"

SaffronCity_Dojo_Text_HidekiSeen:
	.string "We don't use POKé BALLS for\n"
	.string "sparring. Try telling my fists\l"
	.string "that.$"

SaffronCity_Dojo_Text_HidekiBeaten:
	.string "My fists heard you fine.$"

SaffronCity_Dojo_Text_HidekiPostBattle:
	.string "Beat the MASTER and he'll teach\n"
	.string "your POKéMON something new.$"

SaffronCity_Dojo_Text_AaronSeen:
	.string "This DOJO trained trainers before\n"
	.string "SAFFRON had a GYM at all.$"

SaffronCity_Dojo_Text_AaronBeaten:
	.string "Still true, apparently.$"

SaffronCity_Dojo_Text_AaronPostBattle:
	.string "SABRINA's GYM gets the badge.\n"
	.string "This place built her trainers'\l"
	.string "grit first.$"

SaffronCity_Dojo_Text_MikeSeen:
	.string "Last in line means I've watched\n"
	.string "how everyone before me lost.$"

SaffronCity_Dojo_Text_MikeBeaten:
	.string "Watching didn't help.$"

SaffronCity_Dojo_Text_MikePostBattle:
	.string "The MASTER's through there. Good\n"
	.string "luck -- he doesn't lose.$"

SaffronCity_Dojo_Text_MasterKoichiSeen:
	.string "Four of my students, and none of\n"
	.string "them slowed you down. Let's see\l"
	.string "if I do any better.$"

SaffronCity_Dojo_Text_MasterKoichiBeaten:
	.string "None better, it turns out.\p"
	.string "There's nothing left for me to\n"
	.string "teach a fighter like that in the\l"
	.string "ring. But my TECHNIQUE -- that,\l"
	.string "I can still pass on.$"

SaffronCity_Dojo_Text_ImTheDojoMaster:
	.string "I'm the DOJO MASTER.\p"
	.string "Fighting technique isn't just\n"
	.string "fists. It's old moves, half-\l"
	.string "forgotten ones, that some\l"
	.string "POKéMON never got taught.\p"
	.string "I can teach a move to a POKéMON\n"
	.string "of yours, if you'd like.\p"
	.string "I'll do it for a HEART SCALE.\n"
	.string "I'm collecting those now.$"

SaffronCity_Dojo_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "A HEART SCALE! Good.\p"
	.string "Let me guess -- you want me to\n"
	.string "teach a move?$"

SaffronCity_Dojo_Text_TutorWhichMon:
	.string "Which POKéMON needs tutoring?$"

SaffronCity_Dojo_Text_TeachWhichMove:
	.string "Which move should I teach?$"

SaffronCity_Dojo_Text_DontHaveMoveToTeachPokemon:
	.string "Hm.\p"
	.string "There isn't a single move I can\n"
	.string "teach that POKéMON.$"

SaffronCity_Dojo_Text_HandedOverHeartScale:
	.string "{PLAYER} handed over one HEART\n"
	.string "SCALE in exchange.$"

SaffronCity_Dojo_Text_ComeBackWithHeartScale:
	.string "If your POKéMON need to learn a\n"
	.string "move, come back with a HEART\l"
	.string "SCALE.$"

SaffronCity_Dojo_Text_CantTeachEgg:
	.string "Hunh? There isn't a single move\n"
	.string "I can teach an EGG.$"

SaffronCity_Dojo_Text_Statue:
	.string "FIGHTING DOJO$"

SaffronCity_Dojo_Text_Statue_2:
	.string "FIGHTING DOJO$"

SaffronCity_Dojo_Text_LeftScroll:
	.string "Enemies on every side!$"

SaffronCity_Dojo_Text_RightScroll:
	.string "What goes around comes around.$"
