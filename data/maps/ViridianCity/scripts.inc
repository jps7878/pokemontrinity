ViridianCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M5b S5 -- VIRIDIAN WEST & THE SEALED GYM. Full decode + design:
@ docs/superpowers/plans/m5b/05-viridian-west.md.
@
@ BLUE's visibility. Single authority, copied verbatim from CeruleanCity_
@ OnTransition's own shape (M5b S3): visible iff VAR_TRINITY_KANTO_ARC < 2.
@ S5 is the ONE writer of arc value 2 (his own aftermath scene below), so this
@ predicate and the arc write can never disagree.
@ ============================================================================
ViridianCity_OnTransition::
	goto_if_ge VAR_TRINITY_KANTO_ARC, 2, ViridianCity_EventScript_HideBlue
	clearflag FLAG_TRINITY_K_BLUE_GRUDGE_HIDE
	end

ViridianCity_EventScript_HideBlue::
	setflag FLAG_TRINITY_K_BLUE_GRUDGE_HIDE
	end

@ ============================================================================
@ THE SEALED GYM DOOR. (36,10) is a real warp (ViridianCity warp[2] ->
@ MAP_VIRIDIAN_CITY_GYM#1) on a genuine MB_ANIMATED_DOOR/collision-1 tile --
@ TryDoorWarp's walk-into mechanism (src/field_control_avatar.c:1007-1035),
@ which fires on the heldDirection2 input branch independent of tookStep. A
@ coord_event authored literally on (36,10) would be dead code: coord_events
@ only fire via TryStartStepBasedScript, itself gated on input->tookStep,
@ which can never become true on a tile the player is never physically placed
@ on by ordinary movement. (36,11) is the door's SOLE walkable neighbour
@ (col=0 elev=3 MB_NORMAL; (35,10)/(37,10)/(36,9) are all collision 1) -- the
@ true chokepoint, and where the gate actually lives, mirroring Route26's own
@ (7,6) and CeruleanCity's own (1,13).
@
@ THE VAR_TEMP IDIOM. VAR_TEMP_1 == 0 is ClearTempFieldEventData's own default
@ (reset every map load); nothing below ever writes it, so the trigger is
@ live on every single crossing -- Route26_EventScript_LeagueGateCheck and
@ CeruleanCity_EventScript_CaveMouthCheck's own documented shape.
@ ELEVATION-TRUE: the coord_event's own elevation field is (36,11)'s real
@ decoded value, 3 -- not a wildcard, matching both existing precedents'
@ own JSON exactly.
@
@ THE CONDITION. C-COUNT >= 7 AND arc >= 3, verbatim from the master plan's
@ own S10 line ("gates: 7 Kanto badges via C-COUNT + arc>=3") -- no
@ contradiction with the brief, so S10 adds only its interior; this gate
@ script and coord_event need zero changes once S10 lands its own arc/badge
@ writes. `call Trinity_EventScript_CountKantoBadges` + the two `goto_if_lt`s
@ touch no hardware register, so the pass-through path stays "free" (returns
@ FALSE from TryStartCoordEventScript, letting the SAME step's
@ TryStartWarpEventScript fire the real door warp) exactly like Route26's/
@ Cerulean's own bare `end` open branches -- this is what "the coord_event
@ gates entry, it doesn't replace the warp" means mechanically.
@ ============================================================================
ViridianCity_EventScript_GymDoorCheck::
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 7, ViridianCity_EventScript_GymDoorRefuse
	goto_if_lt VAR_TRINITY_KANTO_ARC, 3, ViridianCity_EventScript_GymDoorRefuse
	end

ViridianCity_EventScript_GymDoorRefuse::
	lockall
	msgbox ViridianCity_Text_GymDoorRefuse, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, ViridianCity_Movement_GymDoorStepBack
	waitmovement 0
	releaseall
	end

ViridianCity_Movement_GymDoorStepBack:
	walk_down
	step_end

@ ============================================================================
@ BLUE's grudge battle. Talk-triggered (G-pattern R2-style, copied from
@ SlowpokeWellB1F_EventScript_Proton's exact shape): trainerbattle_single
@ supplies its own lock/faceplayer, so this script must NOT lock first.
@ NO_MUSIC selects TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC, the one mode
@ PlayTrainerEncounterMusic early-outs on, so the playbgm below survives into
@ the battle. Battle BGM needs no scripting beyond that: TRAINER_BLUE_GRUDGE
@ is TRAINER_CLASS_RIVAL with a name other than WALLY (src/data/trainers.h:
@ trainerName = "BLUE"), so GetBattleBGM() (src/pokemon.c:6187-6192) already
@ returns MUS_VS_RIVAL -- the SAME name-compare idiom every SILVER fight in
@ this tree already relies on, NOT an id-range (the brief's speculative
@ premise, checked and found false; no src/pokemon.c edit this slice).
@ ============================================================================
ViridianCity_EventScript_Blue::
	goto_if_ge VAR_TRINITY_KANTO_ARC, 2, ViridianCity_EventScript_BlueIdle
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
	trainerbattle_single TRAINER_BLUE_GRUDGE, ViridianCity_Text_BlueSeen, ViridianCity_Text_BlueBeaten, ViridianCity_EventScript_BlueAftermath, NO_MUSIC
	goto ViridianCity_EventScript_BlueIdle
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE. BlueAftermath removeobject's BLUE
@ and the arc write (VAR_TRINITY_KANTO_ARC -> 2) hides him via ON_TRANSITION
@ on every later entry -- there is never an object left to re-trigger this.
ViridianCity_EventScript_BlueIdle::
	lock
	faceplayer
	msgbox ViridianCity_Text_BlueIdle, MSGBOX_DEFAULT
	release
	end

@ The durable half first (S4's I3(b) ordering hazard), the arc write behind
@ the once-only redo-guard (PokemonLeague_HallOfFame_EventScript_
@ RecordTheLeague's own shape), THEN the R4 fade-wrapped departure (the
@ AzaleaTown_EventScript_Silver talk-path shape: the player's tile is unknown
@ for a talk-triggered boss, so no applymovement walk-off, just a fade
@ sandwich around removeobject).
ViridianCity_EventScript_BlueAftermath::
	msgbox ViridianCity_Text_BlueIntel, MSGBOX_DEFAULT
	closemessage
	goto_if_ge VAR_TRINITY_KANTO_ARC, 2, ViridianCity_EventScript_BlueDepart
	setvar VAR_TRINITY_KANTO_ARC, 2

ViridianCity_EventScript_BlueDepart::
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_KANTO_VIRIDIAN_BLUE
	fadescreen FADE_FROM_BLACK
	release
	end

ViridianCity_EventScript_DreamEaterTutor::
	msgbox ViridianCity_Text_DreamEaterTutor, MSGBOX_NPC
	end

ViridianCity_EventScript_OldMan::
	msgbox ViridianCity_Text_OldMan, MSGBOX_NPC
	end

ViridianCity_EventScript_TutorialOldMan::
	msgbox ViridianCity_Text_TutorialOldMan, MSGBOX_NPC
	end

ViridianCity_EventScript_Woman::
	msgbox ViridianCity_Text_Woman, MSGBOX_NPC
	end

ViridianCity_EventScript_Youngster::
	msgbox ViridianCity_Text_Youngster, MSGBOX_NPC
	end

ViridianCity_EventScript_Boy::
	msgbox ViridianCity_Text_Boy, MSGBOX_NPC
	end

ViridianCity_EventScript_TrainerTips1::
	msgbox ViridianCity_Text_TrainerTips1, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_TrainerTips2::
	msgbox ViridianCity_Text_TrainerTips2, MSGBOX_SIGN
	end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_CitySign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymDoor::
	msgbox ViridianCity_Text_GymDoor, MSGBOX_SIGN
	end

ViridianCity_Text_DreamEaterTutor:
	.string "I never put much stock in rumors,\nbut two Leagues cleared is two\lLeagues cleared. Impressive.$"

ViridianCity_Text_OldMan:
	.string "I've fished this stretch of KANTO\nfor years. Lately it's all anyone\ltalks about -- some far-off champion.$"

ViridianCity_Text_TutorialOldMan:
	.string "I've fished this stretch of KANTO\nfor years. Lately it's all anyone\ltalks about -- some far-off champion.$"

@ Trinity M5b S5: occupation-tension flavour pass. Rocket kept verbal, per the
@ brief -- no grunt objects in ViridianCity itself, S10 owns the basement.
ViridianCity_Text_Woman:
	.string "Ever since that gym went quiet,\nnobody in town will say why.\lFolks just look away and change\lthe subject.$"

ViridianCity_Text_Youngster:
	.string "My dad says there's men in dark\nuniforms coming and going near\lthe gym at night. He won't let me\lanywhere near it.$"

ViridianCity_Text_Boy:
	.string "Those POKé BALLS at your waist!\nYou have POKéMON, don't you?\pIt's great that you can carry and\nuse POKéMON anytime, anywhere.$"

ViridianCity_Text_TrainerTips1:
	.string "TRAINER TIPS\pCatch POKéMON and expand your\ncollection.\pThe more you have, the easier it\nis to battle.$"

ViridianCity_Text_GymSign:
	.string "VIRIDIAN CITY POKéMON GYM$"

ViridianCity_Text_TrainerTips2:
	.string "TRAINER TIPS\pThe battle moves of POKéMON are\nlimited by their POWER POINTS, PP.\pTo replenish PP, rest your tired\nPOKéMON at a POKéMON CENTER.$"

ViridianCity_Text_CitySign:
	.string "VIRIDIAN CITY \nThe Eternally Green Paradise$"

ViridianCity_Text_GymDoor:
	.string "VIRIDIAN GYM's doors are sealed\nshut. Whoever's in there isn't\lopen for business.$"

ViridianCity_Text_GymDoorRefuse:
	.string "Something slams against the door\nfrom the inside.\pA rough voice shouts for you to\nget lost -- TEAM ROCKET doesn't\ltake visitors.\pYou back away from the door.$"

ViridianCity_Text_BlueSeen:
	.string "So it's really you.\pTwo Leagues down and you show up\nHERE, of all places. Right in\lfront of my town's gym.\pI've got some things to settle\nbefore you go anywhere near that\ldoor.$"

ViridianCity_Text_BlueBeaten:
	.string "…Yeah. Figured as much.\pTwo regions clean and you're\nstill standing here mopping up\lmy team. Unreal.$"

ViridianCity_Text_BlueIntel:
	.string "Fine. You want in there? Not\nhappening -- not today, and not\lby beating me.\pBut I'll give you something for\nthe trouble. TEAM ROCKET's running\lthis city from the inside, and\lthis gym's their front door.\pTheir real business is in\nCELADON -- under the GAME CORNER.\lFollow the money and you'll find\lthe rest.\pDo what I couldn't.$"

ViridianCity_Text_BlueIdle:
	.string "…$"
