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
@ THE CONDITION. C-COUNT >= 7 AND arc >= 4 -- RAISED from S5's own original
@ arc >= 3 by S10 (the gate-timing decision, docs/superpowers/plans/m5b/
@ 10-viridian-climax.md section 5). The master plan's own S10 line read
@ "gates: 7 Kanto badges via C-COUNT + arc>=3", but arc reaches 3 the instant
@ Celadon's raid resolves (S6) -- well before S10's own rig scene -- so an
@ unmodified arc>=3 gate would let a player with 7 badges walk into an empty
@ gym (no Giovanni, no barrier, nothing) before ever finding the basement.
@ S10's OWN arc value 4 (written only at the rig scene's resolution) is the
@ correct threshold: by construction, the gym's interior can never be
@ observed before the rig has played, in EVERY reachable order, with zero
@ staging/branching needed inside the gym itself. `call
@ Trinity_EventScript_CountKantoBadges` + the two `goto_if_lt`s touch no
@ hardware register, so the pass-through path stays "free" (returns FALSE
@ from TryStartCoordEventScript, letting the SAME step's
@ TryStartWarpEventScript fire the real door warp) exactly like Route26's/
@ Cerulean's own bare `end` open branches -- this is what "the coord_event
@ gates entry, it doesn't replace the warp" means mechanically.
@
@ FIX ROUND 1 (review I1): THE BOUNCE MUST BE DIRECTION-AWARE, NOT walk_down.
@ (36,11) is a pure east-west thru-tile, not a dead end: north is the door
@ (36,10, collision 1, never actually stood on), and south is (36,12),
@ decoded col=1 elev=0 MB_JUMP_SOUTH -- a one-way ledge TOP, part of a whole
@ row-12 ledge band ((34,12)/(35,12)/(37,12)/(38,12) all the same behaviour).
@ `applymovement`'s walk_down ignores collision/ledge rules entirely (it is
@ forced movement), so the original `walk_down` bounce silently parked the
@ player ON that impassable ledge top -- and since a jump ledge only permits
@ entry FROM THE MATCHING DIRECTION, the only way off it again was a forced
@ south hop into the lower street, nowhere near where they started.
@ Because (36,11)'s only real neighbours are (35,11)/(37,11) (east-west),
@ EVERY arrival here -- ordinary lateral foot traffic included, not just a
@ genuine door attempt -- is lateral, and the fix must bounce the player back
@ toward the side they arrived from, not toward a fixed direction that
@ happens to be a ledge. GetPlayerFacingDirection() is reliable for this:
@ movement sets facing to the direction of travel, and TryStartCoordEventScript
@ runs on the SAME frame the step completes (see the I2 note above the sign
@ script) -- before any subsequent turn/input could change it. A player
@ facing EAST on arrival was walking east, i.e. came FROM THE WEST (35,11),
@ so they bounce WEST, back the way they came; anyone else (WEST -- came
@ from 37,11 -- or the defensive NORTH/SOUTH cases, which should not occur on
@ a lateral-only tile) bounces EAST to (37,11). Both landing tiles decoded
@ fresh: (35,11) col=0 elev=3 MB_NORMAL, (37,11) col=0 elev=3 MB_NORMAL --
@ both real, standable street tiles, neither the ledge, neither sealing
@ anything (reach_check.py re-run post-fix, see the fix report).
@ The seal itself stays airtight on purpose: a lateral entrant who then
@ turns to face the door and presses up would reach TryDoorWarp without
@ re-triggering the coord_event (coord_events fire on tile ENTRY, not on
@ turning in place) -- so the refusal must keep firing on every arrival
@ regardless of facing, exactly as shipped. Only the bounce direction was
@ wrong, not the "fire on every entry" design.
@ ============================================================================
ViridianCity_EventScript_GymDoorCheck::
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 7, ViridianCity_EventScript_GymDoorRefuse
	goto_if_lt VAR_TRINITY_KANTO_ARC, 4, ViridianCity_EventScript_GymDoorRefuse
	end

@ FIX ROUND 1 (review M3): the door-seal's OWN condition is C-COUNT>=7 AND
@ arc>=4, but nothing distinguished WHY a given refusal fired -- a player who
@ has already cleared the rig (arc>=4, Giovanni upstairs, "This floor's
@ finished... I'll be waiting upstairs" per ViridianHideout_B2F_Text_
@ GiovanniAftermath) but hasn't yet earned all 7 OTHER Kanto badges (a real,
@ normal-order state -- S6's own raid only requires 4 badges to reach arc 3)
@ would see the ORIGINAL "TEAM ROCKET doesn't take visitors" text, directly
@ contradicting what the player just did. Branch on arc alone (badge count
@ never distinguishes the TEXT, only whether the door opens at all).
ViridianCity_EventScript_GymDoorRefuse::
	lockall
	goto_if_ge VAR_TRINITY_KANTO_ARC, 4, ViridianCity_EventScript_GymDoorRefusePostRig
	msgbox ViridianCity_Text_GymDoorRefuse, MSGBOX_DEFAULT
	goto ViridianCity_EventScript_GymDoorRefuseBounce

ViridianCity_EventScript_GymDoorRefusePostRig::
	msgbox ViridianCity_Text_GymDoorRefusePostRig, MSGBOX_DEFAULT

ViridianCity_EventScript_GymDoorRefuseBounce::
	closemessage
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_EAST, ViridianCity_EventScript_GymDoorBounceWest
	applymovement LOCALID_PLAYER, ViridianCity_Movement_GymDoorBounceEast
	waitmovement 0
	releaseall
	end

@ Facing EAST on arrival == came from (35,11) -- bounce back west.
ViridianCity_EventScript_GymDoorBounceWest::
	applymovement LOCALID_PLAYER, ViridianCity_Movement_GymDoorBounceWest
	waitmovement 0
	releaseall
	end

@ Every other facing (WEST -- came from (37,11) -- and the defensive
@ NORTH/SOUTH default) bounces east. Falls through from GymDoorRefuse above.
ViridianCity_Movement_GymDoorBounceEast:
	walk_right
	step_end

ViridianCity_Movement_GymDoorBounceWest:
	walk_left
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

@ FIX ROUND 1 (review I2): this bg_event sign is at (36,10), read by facing
@ north from (36,11) and pressing A -- but TryStartCoordEventScript
@ (field_control_avatar.c:611-612, called from TryStartStepBasedScript, which
@ only runs `if (input->tookStep)`) fires on the SAME frame the player's step
@ onto (36,11) completes, strictly BEFORE ProcessPlayerFieldInput's later
@ `pressedAButton` check that would read this sign. While the gate refuses,
@ that coord_event ALWAYS resolves to a real effect (lockall+msgbox+bounce,
@ see GymDoorRefuse above) and immediately ejects the player back off the
@ tile -- so nobody sealed ever gets an idle frame standing on (36,11) to
@ face north and press A here. This sign is genuinely UNREACHABLE while
@ sealed, not merely "a separate input path" as originally (wrongly) claimed
@ in the sub-plan/report -- corrected there too. Its text is written for the
@ OPEN state only, where it IS reachable (the pass-through branch is a bare
@ `end`, so a player standing on (36,11) once open is never interrupted).
@ The sealed-state flavour this sign used to carry is folded into
@ GymDoorRefuse's own msgbox instead, since that is the ONLY text a sealed
@ player can actually see here.
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

@ FIX ROUND 1 (review M5): a precise in-world pointer to the grate. No
@ suitable pre-existing grate/manhole/drain metatile was found anywhere in
@ gTileset_GeneralKanto/gTileset_ViridianCityKanto (grepped
@ metatile_labels.h tree-wide for grate/manhole/drain/sewer/vent -- zero
@ hits anywhere in the ROM, not just this tileset), so per the ruling's own
@ fallback clause this relies on the text pointer alone -- logged, not
@ silently assumed. (30,11) is due west of the gym door (36,10), on the
@ SAME forecourt row (11) -- "west side of the yard" locates it precisely
@ without naming a coordinate the player can't see.
ViridianCity_Text_Youngster:
	.string "My dad says there's men in dark\nuniforms coming and going near\lthe gym at night.\pI snuck a look once -- there's a\nloose grate on the west side of\lthe yard. That's how they get in\land out without anyone seeing.$"

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

@ OPEN-state nameplate only (see the FIX ROUND 1 note on the script above) --
@ coordinated with, but not spoiling, S10's own GIOVANNI reveal.
ViridianCity_Text_GymDoor:
	.string "VIRIDIAN CITY POKéMON GYM\nThe leader's name isn't posted.\lEveryone who's been inside says\lit should be.$"

ViridianCity_Text_GymDoorRefuse:
	.string "VIRIDIAN GYM's doors are sealed\nshut. Something slams against them\lfrom the inside.\pA rough voice shouts for you to\nget lost -- TEAM ROCKET doesn't\ltake visitors.\pYou back away from the door.$"

@ FIX ROUND 1 (review M3): the post-rig branch -- Team Rocket is gone, the
@ door itself is quiet, but Giovanni's own line
@ (ViridianHideout_B2F_Text_GiovanniAftermath: "I'll be waiting upstairs")
@ still needs seven badges honoured before he opens up.
ViridianCity_Text_GymDoorRefusePostRig:
	.string "VIRIDIAN GYM's doors sit quiet now\n-- no more shouting, no more\lslamming.\pA note is pinned beside the handle:\nseven badges, then he'll talk.\lYou're not there yet.$"

ViridianCity_Text_BlueSeen:
	.string "So it's really you.\pTwo Leagues down and you show up\nHERE, of all places. Right in\lfront of my town's gym.\pI've got some things to settle\nbefore you go anywhere near that\ldoor.$"

ViridianCity_Text_BlueBeaten:
	.string "…Yeah. Figured as much.\pTwo regions clean and you're\nstill standing here mopping up\lmy team. Unreal.$"

ViridianCity_Text_BlueIntel:
	.string "Fine. You want in there? Not\nhappening -- not today, and not\lby beating me.\pBut I'll give you something for\nthe trouble. TEAM ROCKET's running\lthis city from the inside, and\lthis gym's their front door.\pTheir real business is in\nCELADON -- under the GAME CORNER.\lFollow the money and you'll find\lthe rest.\pDo what I couldn't.$"

ViridianCity_Text_BlueIdle:
	.string "…$"

@ ============================================================================
@ Trinity M5b S10 -- the hidden basement entrance. No FRLG door exists here to
@ "unseal" (unlike Celadon's own Game Corner staircase) -- this is a wholly
@ Trinity-original location, authored as a scripted bg_event sign rather than
@ a new door tile or warp_event (zero new art, zero new metatile placement,
@ and check-8-transparent by construction -- see docs/superpowers/plans/m5b/
@ 10-viridian-climax.md section 2). (30,11) decoded col=0 elev=3 MB_NORMAL,
@ clear of every existing object/bg_event/warp. Gated on arc>=3 (Celadon
@ cleared) -- defensive: the door-seal's own arc>=4 gate (above) already makes
@ the gym itself unreachable this early, but a player who somehow reaches
@ Viridian before Celadon should not stumble into raid content early either.
@ ============================================================================
@ FIX ROUND 1 (review Minor 8): lockall/releaseall wrapping added, matching
@ the in-tree bg_event precedent (CeladonCity_GameCorner_EventScript_
@ Poster:48-58) instead of running unlocked with a bare `release` on
@ decline (harmless in practice -- ScriptContext_SetupScript already calls
@ LockPlayerFieldControls -- but NPCs kept walking through the prompt and it
@ diverged from the shipped idiom).
ViridianCity_EventScript_HideoutGrate::
	lockall
	goto_if_lt VAR_TRINITY_KANTO_ARC, 3, ViridianCity_EventScript_HideoutGrateSealed
	msgbox ViridianCity_Text_HideoutGrate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_HideoutGrateDecline
	closemessage
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	setescapewarp MAP_VIRIDIAN_CITY, 30, 11
	warp MAP_VIRIDIAN_HIDEOUT_B1F, 12, 3
	waitstate
	end

ViridianCity_EventScript_HideoutGrateSealed::
	msgbox ViridianCity_Text_HideoutGrateSealed, MSGBOX_DEFAULT
	releaseall
	end

ViridianCity_EventScript_HideoutGrateDecline::
	closemessage
	releaseall
	end

ViridianCity_Text_HideoutGrate:
	.string "A loose service grate at the\nside of the gym. Whatever's\ldown there, it doesn't look like\lcity maintenance.\pClimb down?$"

ViridianCity_Text_HideoutGrateSealed:
	.string "A rusted grate, bolted flush\nto the ground. It hasn't been\lmoved in years -- probably.$"
