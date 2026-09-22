CeruleanCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M5b S3 -- CERULEAN CAVE MOUTH. Full decode:
@ docs/superpowers/plans/m5b/03-cerulean-power-plant.md section 3.
@
@ The cave door (warp_events[7], (1,12)->MAP_CERULEAN_CAVE_1F#0) has exactly
@ ONE walkable neighbour, (1,13) directly south (north/east/west all collision
@ 1) -- a true one-tile chokepoint. T10 placed the guard object RIGHT ON that
@ tile with flag "0" (always present, unconditional) -- the cave was
@ permanently sealed in the shipped tree, a T10 placeholder state, not a
@ finished gate.
@
@ THE CONTRACT'S COORDINATE RULE FORBIDS A RESTING NPC SEALING A CORRIDOR
@ (established twice already: AZALEA's two chokepoint guards were moved one
@ tile in M4b S4's fix round for exactly this; Route43Gate's own header states
@ it as a rule, "a gate NPC never blocks the gate"). So the guard moves
@ (1,13) -> (2,13) -- decoded col 0 elev 3 MB_NORMAL, adjacent, off the
@ chokepoint, same one-tile-relocation shape as the AZALEA fix. He becomes
@ pure flavour/warning; a coord_event at the now-empty (1,13) is the actual
@ gate, mirroring Route28_EventScript_KantoGateCheck (this hack's established
@ "story-gated one-way passage, no resting NPC" pattern) -- VAR_TEMP_1 == 0 is
@ the "always fires" idiom (cleared to 0 by ClearTempFieldEventData on every
@ map load, consumed synchronously in the same script run; trinity_kanto.inc's
@ own C-COUNT header cites the identical reasoning for its scratch var).
@
@ Visibility: single-writer discipline -- S3 reads VAR_TRINITY_KANTO_ARC,
@ writes nothing to it. Visible pre-arc6 (warning, backed up by the
@ coord_event regardless of whether the player detours around him);
@ hidden at arc>=6 ("he steps aside/vanishes").
@ ============================================================================
@ M7b Task 18 (#13, WHERE): the guard's visibility is unchanged in behaviour;
@ it only moves into a call-ed subroutine so this map can keep exactly ONE
@ ON_TRANSITION entry while the rival's predicate joins it. The two `end`s
@ below become `return`s for the same reason. Nothing else in the tree
@ references CeruleanCity_EventScript_HideCaveGuard.
CeruleanCity_OnTransition::
	call Common_EventScript_SetupRivalGfxId
	call CeruleanCity_EventScript_SetCaveGuardVisibility
	call CeruleanCity_EventScript_SetRivalVisibility
	end

CeruleanCity_EventScript_SetCaveGuardVisibility::
	goto_if_ge VAR_TRINITY_KANTO_ARC, 6, CeruleanCity_EventScript_HideCaveGuard
	clearflag FLAG_TRINITY_K_CAVE_GUARD_HIDE
	return

CeruleanCity_EventScript_HideCaveGuard::
	setflag FLAG_TRINITY_K_CAVE_GUARD_HIDE
	return

@ ============================================================================
@ M7b Task 18 (#13, WHERE): the Act I rival, cameo 4 of 4 -- the exact
@ complement of the guard above. He turns people away until the player is
@ CHAMPION; from VAR_TRINITY_KANTO_ARC 6 he is gone and she is standing one
@ tile south of his post, PERMANENTLY. That permanence is what stops the thread
@ ever being lost: the other three sightings close, this one never does.
@
@ Mechanism and sprite seeding as MtMoon_1F_OnTransition, whose header carries
@ the full rationale (FLAG_TEMP_5, the two map-load paths, and why the
@ Continue-from-save path cannot show her out of window).
@ FLAG_TRINITY_K_ARRIVED is deliberately NOT re-tested here: arc >= 6 is only
@ reached at the HALL OF FAME and already implies arrival.
@
@ PLACEMENT (2,14): col 0, elev 3, MB_NORMAL. On the Surf-only west-shore
@ shelf, one tile SOUTH of the guard's own tile rather than on it -- stacking
@ two complementary objects on (2,13) would make every future reach_check
@ report count two blockers on one tile and mislead the next reviewer. It is
@ off the (1,13) door chokepoint and off the column-3 surf landings, so
@ surfing in and walking to the cave door is never blocked. reach_check
@ 1038 -> 1037: delta 1, her own tile. (The tool places every template
@ regardless of flags, so it counts the guard and the rival at once even
@ though they are exact complements; real in-game reach is 1038 in both
@ states.)
@ ============================================================================
CeruleanCity_EventScript_SetRivalVisibility::
	goto_if_lt VAR_TRINITY_KANTO_ARC, 6, CeruleanCity_EventScript_HideRival
	clearflag FLAG_TEMP_5
	return

CeruleanCity_EventScript_HideRival::
	setflag FLAG_TEMP_5
	return

CeruleanCity_EventScript_CaveMouthCheck::
	goto_if_ge VAR_TRINITY_KANTO_ARC, 6, CeruleanCity_EventScript_CaveMouthOpen
	lockall
	msgbox CeruleanCity_Text_CaveMouthNotYet, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_CaveMouthStepBack
	waitmovement 0
	releaseall
	end

CeruleanCity_EventScript_CaveMouthOpen::
	end

CeruleanCity_Movement_CaveMouthStepBack:
	walk_down
	step_end

CeruleanCity_Text_CaveMouthNotYet:
	.string "The air past here feels wrong\nfor you -- like the cave itself\lis waiting on somebody else\lfirst.$"

CeruleanCity_EventScript_Policeman::
	msgbox CeruleanCity_Text_Policeman, MSGBOX_NPC
	end

CeruleanCity_EventScript_LittleBoy::
	msgbox CeruleanCity_Text_LittleBoy, MSGBOX_NPC
	end

CeruleanCity_EventScript_BaldingMan::
	msgbox CeruleanCity_Text_BaldingMan, MSGBOX_NPC
	end

CeruleanCity_EventScript_Lass::
	msgbox CeruleanCity_Text_Lass, MSGBOX_NPC
	end

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_Youngster, MSGBOX_NPC
	end

CeruleanCity_EventScript_Woman::
	msgbox CeruleanCity_Text_Woman, MSGBOX_NPC
	end

CeruleanCity_EventScript_CeruleanCaveGuard::
	msgbox CeruleanCity_Text_CeruleanCaveGuard, MSGBOX_NPC
	end

CeruleanCity_EventScript_CitySign::
	msgbox CeruleanCity_Text_CitySign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign::
	msgbox CeruleanCity_Text_GymSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_TrainerTips::
	msgbox CeruleanCity_Text_TrainerTips, MSGBOX_SIGN
	end

CeruleanCity_Text_Policeman:
	.string "My grandkids keep going on about\nsome trainer from HOENN. Sounds\llike quite the journey so far.$"

CeruleanCity_Text_LittleBoy:
	.string "They say a trainer beat both the\nHOENN and JOHTO Leagues. Wonder\lif they'll try KANTO next.$"

CeruleanCity_Text_BaldingMan:
	.string "You're making an encyclopedia on\nPOKéMON? That sounds amusing.$"

CeruleanCity_Text_Lass:
	.string "Never met the champion myself.\nHeard they came up through HOENN\land JOHTO before setting foot here.$"

CeruleanCity_Text_Youngster:
	.string "You're a TRAINER, too?\pCollecting, battling…\nIt's a tough life, isn't it?$"

CeruleanCity_Text_Woman:
	.string "KANTO's peaceful most days, but\neven here we've heard the stories\labout that HOENN trainer.$"

CeruleanCity_Text_CeruleanCaveGuard:
	.string "This is CERULEAN CAVE.\pHorribly strong POKéMON live inside\nthere.\pIt takes a very special TRAINER to\nbe allowed inside there.\pYou'd have to be strong enough to\nbecome the POKéMON LEAGUE\lCHAMPION for starters.\pAnd, you would have to have\nmade a great achievement.$"

CeruleanCity_Text_CitySign:
	.string "CERULEAN CITY\nA Mysterious, Blue Aura Surrounds\lIt$"

CeruleanCity_Text_GymSign:
	.string "They say a trainer beat both the\nHOENN and JOHTO Leagues. Wonder\lif they'll try KANTO next.$"

CeruleanCity_Text_BikeShopSign:
	.string "Grass and caves handled easily!\nBIKE SHOP$"

CeruleanCity_Text_TrainerTips:
	.string "TRAINER TIPS\pA POKéMON can be made to hold\nan item.\pSome items can even be used by\nthe holding POKéMON in battle.$"

@ ============================================================================
@ M7b Task 18 (#13): the rival's ONE high-level rematch.
@
@ OPTIONAL CONTENT, and that is the whole licence for it. The CERULEAN CAVE
@ mouth is a Surf-only shelf that leads nowhere but CERULEAN CAVE, itself
@ entirely optional postgame, so nothing on the mandatory path touches this
@ fight and nothing anywhere is gated on winning it. The difficulty freeze is
@ intact: no existing roster, level, moveset, held item or gauntlet rule is
@ changed -- this is a new trainer, added beside the path, not a change to one.
@
@ IT CANNOT AMBUSH ANYONE. The object is TRAINER_TYPE_NONE, so there is no
@ sight range, and the fight is behind an explicit MSGBOX_YESNO: a player who
@ surfs the shelf heading for the cave door and talks to her out of curiosity
@ is asked first and can decline. (MtMoon_1F_EventScript_Silver, the closest
@ precedent, has no such prompt; the charter's "more ways to be player
@ friendly" is why this one does, and it costs nothing.)
@
@ TWO trainer ids, one per player gender: the rival is the player's OPPOSITE
@ (ExpandPlaceholder_RivalName, src/string_util.c; rival_graphics.inc), so a
@ MALE player fights MAY and a FEMALE player fights BRENDAN. Exactly one of the
@ two is reachable in any save.
@
@ ONE FIGHT PER ID, and the checktrainerflag guard is load-bearing: the
@ no-intro battle macro has NO internal idempotence
@ (EventScript_DoNoIntroTrainerBattle, data/scripts/trainer_battle.inc, has no
@ GetTrainerFlag check and calls dotrainerbattle unconditionally), so the guard
@ is the only thing between this NPC and an infinitely re-fightable fight. Same
@ discipline, same reasoning, as MtMoon_1F_EventScript_Silver.
@
@ THE ARC TEST AT THE TOP IS DEFENCE IN DEPTH. Her ON_TRANSITION predicate
@ already keeps her hidden below arc 6, and no load path can spawn her without
@ it having run; the test means correctness does not DEPEND on that argument.
@ Out of window she speaks the postgame rule instead -- a true line in every
@ state, and one more place the CERULEAN CAVE gate is stated out loud.
@
@ NO playbgm: both ids are TRAINER_CLASS_RIVAL with a name other than WALLY, so
@ GetBattleBGM (src/pokemon.c) already returns MUS_VS_RIVAL, and not overriding
@ the map music means CERULEAN's own track is not left replaced afterwards.
@ ============================================================================
CeruleanCity_EventScript_RivalCaveMouth::
	lock
	faceplayer
	goto_if_lt VAR_TRINITY_KANTO_ARC, 6, CeruleanCity_EventScript_RivalCaveMouthNotYet
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, CeruleanCity_EventScript_RivalCaveMouthMay
	goto CeruleanCity_EventScript_RivalCaveMouthBrendan
	end

CeruleanCity_EventScript_RivalCaveMouthMay::
	checktrainerflag TRAINER_MAY_KANTO
	goto_if TRUE, CeruleanCity_EventScript_RivalCaveMouthDone
	msgbox CeruleanCity_Text_RivalCaveMouthIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_EventScript_RivalCaveMouthDecline
	closemessage
	trainerbattle_no_intro TRAINER_MAY_KANTO, CeruleanCity_Text_RivalCaveMouthDefeat
	goto CeruleanCity_EventScript_RivalCaveMouthAfter
	end

CeruleanCity_EventScript_RivalCaveMouthBrendan::
	checktrainerflag TRAINER_BRENDAN_KANTO
	goto_if TRUE, CeruleanCity_EventScript_RivalCaveMouthDone
	msgbox CeruleanCity_Text_RivalCaveMouthIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_EventScript_RivalCaveMouthDecline
	closemessage
	trainerbattle_no_intro TRAINER_BRENDAN_KANTO, CeruleanCity_Text_RivalCaveMouthDefeat
	goto CeruleanCity_EventScript_RivalCaveMouthAfter
	end

CeruleanCity_EventScript_RivalCaveMouthAfter::
	msgbox CeruleanCity_Text_RivalCaveMouthAfter, MSGBOX_DEFAULT
	release
	end

CeruleanCity_EventScript_RivalCaveMouthDecline::
	msgbox CeruleanCity_Text_RivalCaveMouthDecline, MSGBOX_DEFAULT
	release
	end

CeruleanCity_EventScript_RivalCaveMouthDone::
	msgbox CeruleanCity_Text_RivalCaveMouthDone, MSGBOX_DEFAULT
	release
	end

CeruleanCity_EventScript_RivalCaveMouthNotYet::
	msgbox CeruleanCity_Text_RivalCaveMouthNotYet, MSGBOX_DEFAULT
	release
	end

@ "I still can't follow you in there" is the guard's own shipped rule in her
@ words (CeruleanCity_Text_CeruleanCaveGuard). "Whatever is in there has been
@ waiting" is true: MEWTWO becomes visible at arc >= 6 via
@ FLAG_TRINITY_K_MEWTWO_HIDE in CeruleanCave_B1F's ON_TRANSITION.
CeruleanCity_Text_RivalCaveMouthIntro:
	.string "{RIVAL}: There you are.\p"
	.string "CHAMPION of HOENN. CHAMPION of\n"
	.string "JOHTO. And now KANTO too.\p"
	.string "I've filled every page I can\n"
	.string "reach, and I still can't follow\l"
	.string "you in there.\p"
	.string "So before you go in -- once,\n"
	.string "just to see the distance?$"

CeruleanCity_Text_RivalCaveMouthDefeat:
	.string "That's the distance, then.$"

CeruleanCity_Text_RivalCaveMouthAfter:
	.string "{RIVAL}: Thank you. Really.\p"
	.string "Go on in. Whatever is in there\n"
	.string "has been waiting a long time.\p"
	.string "I'll be out here, writing it\n"
	.string "all down.$"

CeruleanCity_Text_RivalCaveMouthDecline:
	.string "{RIVAL}: Then go. I'll be here\n"
	.string "either way.$"

CeruleanCity_Text_RivalCaveMouthDone:
	.string "{RIVAL}: Go on. I'll be here.\n"
	.string "Somebody has to write it down.$"

CeruleanCity_Text_RivalCaveMouthNotYet:
	.string "{RIVAL}: Not yet. They only open\n"
	.string "that cave for a CHAMPION.$"
