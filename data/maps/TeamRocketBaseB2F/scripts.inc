@ The transmitter door block, decoded from data/layouts/TeamRocketBaseB2F_Johto/
@ map.bin. 636-639 is GSC's SHUT shutter block on tiles (14,12) (15,12) (14,13)
@ (15,13) -- the top half collision 1, the bottom half collision 0, which is why
@ the room above it is walkable-but-unreachable in the shipped port.
@ 540-543 is the plain FLOOR block, lifted from (14,10) (15,10) (14,11) (15,11)
@ directly above. Y-PARITY MATTERS: 540/541 is a floor block's TOP row (y even)
@ and 542/543 its BOTTOM row (y odd); swapping them draws a seam.
@ Named here because include/constants/metatile_labels.h has no Johto entries.
	.set METATILE_JohtoRocketBase_FloorTL,        540
	.set METATILE_JohtoRocketBase_FloorTR,        541
	.set METATILE_JohtoRocketBase_FloorBL,        542
	.set METATILE_JohtoRocketBase_FloorBR,        543

TeamRocketBaseB2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TeamRocketBaseB2F_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S7 -- TEAM ROCKET BASE B2F. Adapts pokecrystal
@ maps/TeamRocketBaseB2F.asm. ROCKET-POST PATTERN R1-R5.
@
@ THE FLOOR IS TWO ROOMS AND A LOCKED DOOR. Decoded with reach_check --dungeon:
@ the entry room (105 tiles, the B1F stairs at (3,14) and the B3F stairs at
@ (27,14)) and the TRANSMITTER HALL (85 tiles: the machine, the six ELECTRODE,
@ and nothing else) which is walkable but UNREACHABLE in the shipped port,
@ because M4a carried GSC's shut-shutter block across and never ported the
@ changeblock that opens it. That is the "blocked warp behind a never-opened
@ door" the M4a survey reported: no warp is sealed, but 85 tiles of story are.
@ Opening the door is this slice's job.
@
@ ON_TRANSITION authors three things (S1's single-authority rule):
@   FLAG_TRINITY_J_BASE_CAST_HIDE        visible iff ARC == 4   (3 posts here)
@   FLAG_TRINITY_J_BASE_ARIANA_HIDE      visible iff ARC == 4 and SCENE < 3
@   FLAG_TRINITY_J_BASE_LANCE_B2F_HIDE   visible iff ARC == 4 and SCENE < 4
@ and, per the SETMETATILE DOOR PATTERN's clause D2, the door's own four tiles.
@
@ THE SIX ELECTRODE ARE DELIBERATELY NOT AUTHORED. Their three flags are pure
@ DEFEAT MARKERS, written once each by the beat's own removeobject co-sign (R1),
@ and their new-game default (clear = present) is already correct because the
@ hall they stand in cannot be entered until the door opens. Authoring them from
@ a scene predicate would resurrect a defeated ELECTRODE on the next map load,
@ since the predicate cannot distinguish "the phase is live" from "this one is
@ already down" -- the flag is doing both jobs. This is the one case on the map
@ where R1's single-authority rule is answered by having NO authority rather
@ than one: a flag with exactly one writer and a correct default does not need
@ an author.
@
@ THREE PAIRS, THREE FLAGS. Objects 6/7/8 at (7,5) (7,7) (7,9) are the player's
@ side; objects 9/10/11 at (22,5) (22,7) (22,9) are LANCE's, and each twin
@ shares its partner's flag. Removing one therefore co-signs the other on the
@ next load, which is GSC's own trick for selling "we split the job" at zero
@ scripting cost -- and here the scene removes both explicitly so the twin goes
@ in the same breath rather than a map load later.
@ ============================================================================
TeamRocketBaseB2F_OnTransition:
	call TeamRocketBaseB2F_EventScript_SetCastVisibility
	call TeamRocketBaseB2F_EventScript_AuthorDoor
	end

TeamRocketBaseB2F_EventScript_SetCastVisibility::
	goto_if_ne VAR_TRINITY_JOHTO_ARC, 4, TeamRocketBaseB2F_EventScript_HideAll
	clearflag FLAG_TRINITY_J_BASE_CAST_HIDE
	goto_if_ge VAR_TRINITY_JOHTO_SCENE_MAHOGANY, 3, TeamRocketBaseB2F_EventScript_HideAriana
	clearflag FLAG_TRINITY_J_BASE_ARIANA_HIDE
	clearflag FLAG_TRINITY_J_BASE_LANCE_B2F_HIDE
	return

TeamRocketBaseB2F_EventScript_HideAriana::
	setflag FLAG_TRINITY_J_BASE_ARIANA_HIDE
	goto_if_ge VAR_TRINITY_JOHTO_SCENE_MAHOGANY, 4, TeamRocketBaseB2F_EventScript_HideLance
	clearflag FLAG_TRINITY_J_BASE_LANCE_B2F_HIDE
	return

TeamRocketBaseB2F_EventScript_HideLance::
	setflag FLAG_TRINITY_J_BASE_LANCE_B2F_HIDE
	return

TeamRocketBaseB2F_EventScript_HideAll::
	setflag FLAG_TRINITY_J_BASE_CAST_HIDE
	setflag FLAG_TRINITY_J_BASE_ARIANA_HIDE
	setflag FLAG_TRINITY_J_BASE_LANCE_B2F_HIDE
	return

@ D2. The shipped map.bin has this door SHUT, so the authoring direction is
@ OPEN. No DrawWholeMapView -- ON_TRANSITION runs before the map is drawn.
TeamRocketBaseB2F_EventScript_AuthorDoor::
	goto_if_set FLAG_TRINITY_J_DOOR_B2F, TeamRocketBaseB2F_EventScript_OpenDoorTiles
	return

TeamRocketBaseB2F_EventScript_OpenDoorTiles::
	setmetatile 14, 12, METATILE_JohtoRocketBase_FloorTL, FALSE
	setmetatile 15, 12, METATILE_JohtoRocketBase_FloorTR, FALSE
	setmetatile 14, 13, METATILE_JohtoRocketBase_FloorBL, FALSE
	setmetatile 15, 13, METATILE_JohtoRocketBase_FloorBR, FALSE
	return

@ ============================================================================
@ D1/D3/D4 -- THE TRANSMITTER DOOR, and the template S8 copies for the RADIO
@ TOWER's Card Key and the GOLDENROD UNDERGROUND's shutters.
@
@ D1  Two BG_EVENT_PLAYER_FACING_NORTH signs on the two collision-1 door tiles
@     (14,12) and (15,12), read from (14,13) and (15,13) -- each has EXACTLY ONE
@     reading tile (S5's I1 pin), both decoded collision 0 elevation 3, both
@     kept clear of objects.
@ D3  The opening script repeats ON_TRANSITION's four setmetatiles and then
@     calls `special DrawWholeMapView`, which ON_TRANSITION does not need.
@ D4  FLAG_TRINITY_J_DOOR_B2F is the door's ONLY state; the password flag is an
@     INPUT. The script's first line tests the door flag, because a bg_event on
@     a now-walkable tile is still triggerable by pressing A while facing it.
@ D5  All four metatiles of the GSC block are authored, never two of them.
@
@ The password is HAIL GIOVANNI, learnt from the MURKROW in GIOVANNI's office
@ on B3F -- so this door, which is two steps from the B1F staircase, is the LAST
@ thing the player opens. That is GSC's shape and it is why the base reads as a
@ maze rather than a corridor.
@ ============================================================================
TeamRocketBaseB2F_EventScript_TransmitterDoor::
	lockall
	goto_if_set FLAG_TRINITY_J_DOOR_B2F, TeamRocketBaseB2F_EventScript_DoorAlreadyOpen
	goto_if_unset FLAG_TRINITY_J_PASSWORD_GIOVANNI, TeamRocketBaseB2F_EventScript_DoorNoPassword
	msgbox TeamRocketBaseB2F_Text_DoorPassword, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	setmetatile 14, 12, METATILE_JohtoRocketBase_FloorTL, FALSE
	setmetatile 15, 12, METATILE_JohtoRocketBase_FloorTR, FALSE
	setmetatile 14, 13, METATILE_JohtoRocketBase_FloorBL, FALSE
	setmetatile 15, 13, METATILE_JohtoRocketBase_FloorBR, FALSE
	special DrawWholeMapView
	waitse
	setflag FLAG_TRINITY_J_DOOR_B2F
	releaseall
	end

TeamRocketBaseB2F_EventScript_DoorNoPassword::
	msgbox TeamRocketBaseB2F_Text_DoorNoPassword, MSGBOX_DEFAULT
	releaseall
	end

TeamRocketBaseB2F_EventScript_DoorAlreadyOpen::
	msgbox TeamRocketBaseB2F_Text_DoorOpen, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@ R2 -- the three grunt posts, ordinary sight-triggered trainers.
@ ============================================================================
TeamRocketBaseB2F_EventScript_GruntA::
	trainerbattle_single TRAINER_ROCKET_GRUNT_M_4, TeamRocketBaseB2F_Text_GruntASeen, TeamRocketBaseB2F_Text_GruntABeaten
	msgbox TeamRocketBaseB2F_Text_GruntAAfterBattle, MSGBOX_AUTOCLOSE
	end

TeamRocketBaseB2F_EventScript_GruntB::
	trainerbattle_single TRAINER_ROCKET_GRUNT_M_5, TeamRocketBaseB2F_Text_GruntBSeen, TeamRocketBaseB2F_Text_GruntBBeaten
	msgbox TeamRocketBaseB2F_Text_GruntBAfterBattle, MSGBOX_AUTOCLOSE
	end

TeamRocketBaseB2F_EventScript_GruntC::
	trainerbattle_single TRAINER_ROCKET_GRUNT_M_6, TeamRocketBaseB2F_Text_GruntCSeen, TeamRocketBaseB2F_Text_GruntCBeaten
	msgbox TeamRocketBaseB2F_Text_GruntCAfterBattle, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ R2/R3 -- EXEC ARIANA, TALK-TRIGGERED at (15,11), one tile inside the door.
@
@ AMENDMENT TO GSC, declared: GSC stages her as a 30-step ambush (two Rockets
@ teleported in behind the player, DRAGONITE knocking her sideways, LANCE
@ walking in on a `moveobject` mirrored per approach tile). S7 ships her in the
@ R2 shape instead -- TRAINER_TYPE_NONE, talk-triggered, `trainerbattle_single
@ ... NO_MUSIC` behind `playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE` -- because that
@ is the ONLY shape in which the contract's Rocket-music pin is audible: the
@ coord-triggered alternative has to reach the battle through
@ `trainerbattle_no_intro`, whose EventScript_DoNoIntroTrainerBattle calls
@ `special PlayTrainerEncounterMusic` unconditionally (data/scripts/
@ trainer_battle.inc:53) and swaps the approach BGM out from under the playbgm.
@ `trainerbattle_single` supplies its own lock/faceplayer, so this script must
@ NOT lock first; only the idle branch locks, and the continuation releases.
@
@ R5, DISCLOSED. (15,11) sits in the maze's southern corridor, row 11, which
@ runs unbroken from x=7 to x=22 and opens upward into row 10 at x=10..19. She
@ is therefore NOT a cut vertex: (14,11) -> (14,10) -> (16,10) -> (16,11) walks
@ around her. The flood fill is in the slice report. She seals nothing and no
@ approach tile of hers is contrived; she is placed at the threshold because
@ that is where the ambush happened, not to gate anything.
@
@ THE ELECTRODE ARE REACHABLE WITHOUT FIGHTING HER, and that is accepted rather
@ than papered over -- it is the cost of dropping the ambush. The payoff below
@ needs BOTH her scene advance and all three ELECTRODE down, in either order,
@ so no ordering can strand the raid.
@ ============================================================================
TeamRocketBaseB2F_EventScript_Ariana::
	goto_if_ne VAR_TRINITY_JOHTO_SCENE_MAHOGANY, 2, TeamRocketBaseB2F_EventScript_ArianaIdle
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	trainerbattle_single TRAINER_EXEC_ARIANA, TeamRocketBaseB2F_Text_ArianaIntro, TeamRocketBaseB2F_Text_ArianaDefeat, TeamRocketBaseB2F_EventScript_ArianaBeaten, NO_MUSIC
	@ INTENTIONALLY UNREACHABLE / DEFENSIVE. The continuation removeobject's her
	@ and advances the scene var, and ON_TRANSITION hides her from SCENE 3 on, so
	@ there is never an object here to talk to a second time.
	goto TeamRocketBaseB2F_EventScript_ArianaIdle
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE -- see above.
TeamRocketBaseB2F_EventScript_ArianaIdle::
	lock
	faceplayer
	msgbox TeamRocketBaseB2F_Text_ArianaIdle, MSGBOX_DEFAULT
	release
	end

TeamRocketBaseB2F_EventScript_ArianaBeaten::
	msgbox TeamRocketBaseB2F_Text_ArianaRetreat, MSGBOX_DEFAULT
	closemessage
	@ R4: the disappearance happens inside a fade, so nothing pops.
	@ ONLY ARIANA is removed. The nine posts sharing FLAG_TRINITY_J_BASE_CAST_
	@ HIDE are left standing for ON_TRANSITION to retire at ARC 5 -- GSC clears
	@ the floor here, but with one flag across three maps a removeobject would
	@ co-sign nine objects on two other floors out of existence (R1's trap).
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_JOHTO_TRB2F_ARIANA
	fadescreen FADE_FROM_BLACK
	call TeamRocketBaseB2F_EventScript_AdvanceToElectrodes
	fadedefaultbgm
	release
	end

@ Monotonic scene advance (S1's rule applied to the scene var as well as the
@ arc var).
TeamRocketBaseB2F_EventScript_AdvanceToElectrodes::
	goto_if_ge VAR_TRINITY_JOHTO_SCENE_MAHOGANY, 3, TeamRocketBaseB2F_EventScript_AdvanceDone
	setvar VAR_TRINITY_JOHTO_SCENE_MAHOGANY, 3
TeamRocketBaseB2F_EventScript_AdvanceDone::
	return

@ ============================================================================
@ THE ELECTRODE ROOM. GSC's `RocketElectrode1/2/3`: a plain wild battle each
@ (loadwildmon ELECTRODE, 23 -- NOT the trap battletype the B1F floor uses),
@ and the machine only stops when all three are down.
@
@ R5 FOR FREE. Each of the player's three ELECTRODE has EXACTLY ONE walkable
@ neighbour, decoded: (7,5) -> (8,5); (7,7) -> (8,7); (7,9) -> (8,9). The tiles
@ north, south and west of each are collision 1. So the scene always knows where
@ the player is standing without moving them, which is R5's whole point, and
@ none of the three can seal anything -- they are in dead-end alcoves.
@
@ Each script removes BOTH halves of its pair. removeobject co-signs the shared
@ flag either way (R1), so the twin on LANCE's side would vanish on the next map
@ load regardless; removing it explicitly just means the player sees LANCE keep
@ his side of the bargain in real time.
@ ============================================================================
TeamRocketBaseB2F_EventScript_Electrode1::
	lock
	call TeamRocketBaseB2F_EventScript_ElectrodeBattle
	goto_if_eq VAR_RESULT, FALSE, TeamRocketBaseB2F_EventScript_ElectrodeStanding
	removeobject LOCALID_JOHTO_TRB2F_ELECTRODE_1
	removeobject LOCALID_JOHTO_TRB2F_ELECTRODE_4
	goto TeamRocketBaseB2F_EventScript_ElectrodeCheck
	end

TeamRocketBaseB2F_EventScript_Electrode2::
	lock
	call TeamRocketBaseB2F_EventScript_ElectrodeBattle
	goto_if_eq VAR_RESULT, FALSE, TeamRocketBaseB2F_EventScript_ElectrodeStanding
	removeobject LOCALID_JOHTO_TRB2F_ELECTRODE_2
	removeobject LOCALID_JOHTO_TRB2F_ELECTRODE_5
	goto TeamRocketBaseB2F_EventScript_ElectrodeCheck
	end

TeamRocketBaseB2F_EventScript_Electrode3::
	lock
	call TeamRocketBaseB2F_EventScript_ElectrodeBattle
	goto_if_eq VAR_RESULT, FALSE, TeamRocketBaseB2F_EventScript_ElectrodeStanding
	removeobject LOCALID_JOHTO_TRB2F_ELECTRODE_3
	removeobject LOCALID_JOHTO_TRB2F_ELECTRODE_6
	goto TeamRocketBaseB2F_EventScript_ElectrodeCheck
	end

@ Returns VAR_RESULT TRUE if the ELECTRODE is down (beaten or caught), FALSE if
@ the player ran or teleported out.
TeamRocketBaseB2F_EventScript_ElectrodeBattle::
	msgbox TeamRocketBaseB2F_Text_ElectrodeApproach, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_ELECTRODE, CRY_MODE_NORMAL
	waitmoncry
	setwildbattle SPECIES_ELECTRODE, 62
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TeamRocketBaseB2F_EventScript_ElectrodeDown
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TeamRocketBaseB2F_EventScript_ElectrodeDown
	setvar VAR_RESULT, FALSE
	return

TeamRocketBaseB2F_EventScript_ElectrodeDown::
	setvar VAR_RESULT, TRUE
	return

TeamRocketBaseB2F_EventScript_ElectrodeStanding::
	release
	end

@ All three down? Then the machine dies. LANCE's payoff is NOT staged here:
@ which ELECTRODE the player finishes on is not knowable, GSC solves that with
@ three different forced walks back to a common tile, and a forced walk with an
@ unpinned destination is the documented failure mode (S4). Instead the machine
@ falls silent where the player is standing and LANCE -- who has been at the
@ stairs the whole raid -- hands over the reward when spoken to. The raid does
@ not end until he does, so nothing is skippable.
TeamRocketBaseB2F_EventScript_ElectrodeCheck::
	goto_if_unset FLAG_TRINITY_J_ELECTRODE_1, TeamRocketBaseB2F_EventScript_ElectrodeMore
	goto_if_unset FLAG_TRINITY_J_ELECTRODE_2, TeamRocketBaseB2F_EventScript_ElectrodeMore
	goto_if_unset FLAG_TRINITY_J_ELECTRODE_3, TeamRocketBaseB2F_EventScript_ElectrodeMore
	delay 30
	playse SE_FALL
	waitse
	msgbox TeamRocketBaseB2F_Text_MachineStops, MSGBOX_DEFAULT
	release
	end

TeamRocketBaseB2F_EventScript_ElectrodeMore::
	msgbox TeamRocketBaseB2F_Text_ElectrodeMore, MSGBOX_DEFAULT
	release
	end

@ LANCE's three twins on the far side of the machine. GSC spends three coord
@ events on an invisible wall that pushes the player back and prints this line;
@ S7 puts the line on the objects the wall was describing, which is both fewer
@ moving parts and better staging.
TeamRocketBaseB2F_EventScript_LanceSide::
	msgbox TeamRocketBaseB2F_Text_LancesSide, MSGBOX_NPC
	end

@ ============================================================================
@ LANCE at the B1F stairs (5,13). Three states, and a REPEATABLE free heal.
@
@ GSC gates its heal on a coord pair at (5,14)/(4,13) and makes it one-shot,
@ using it as the trigger that arms the ARIANA ambush. Neither survives here:
@ the entry room is rows 13-14 by twenty-two columns with no chokepoint, so no
@ coord pair can be made mandatory, and with the ambush gone the heal has
@ nothing to arm. It becomes what it always was in spirit -- the older trainer
@ handing over his own medicine -- and it repeats, because a missable heal in a
@ raid this long is a trap, not a reward.
@
@ THE RAID ENDS HERE. Both the arc write (4 -> 5) and the scene write (3 -> 4)
@ sit in the payoff below, each behind its own monotonic guard.
@ ============================================================================
TeamRocketBaseB2F_EventScript_Lance::
	lock
	faceplayer
	goto_if_ne VAR_TRINITY_JOHTO_SCENE_MAHOGANY, 3, TeamRocketBaseB2F_EventScript_LanceEarly
	goto_if_unset FLAG_TRINITY_J_ELECTRODE_1, TeamRocketBaseB2F_EventScript_LanceElectrodes
	goto_if_unset FLAG_TRINITY_J_ELECTRODE_2, TeamRocketBaseB2F_EventScript_LanceElectrodes
	goto_if_unset FLAG_TRINITY_J_ELECTRODE_3, TeamRocketBaseB2F_EventScript_LanceElectrodes
	goto TeamRocketBaseB2F_EventScript_RaidCleared
	end

@ Before ARIANA: the heal, and the hint that the door needs a password.
TeamRocketBaseB2F_EventScript_LanceEarly::
	msgbox TeamRocketBaseB2F_Text_LanceHeal, MSGBOX_DEFAULT
	call TeamRocketBaseB2F_EventScript_DoHeal
	msgbox TeamRocketBaseB2F_Text_LanceHint, MSGBOX_DEFAULT
	release
	end

@ After ARIANA, while the machine still runs.
TeamRocketBaseB2F_EventScript_LanceElectrodes::
	msgbox TeamRocketBaseB2F_Text_LanceHeal, MSGBOX_DEFAULT
	call TeamRocketBaseB2F_EventScript_DoHeal
	msgbox TeamRocketBaseB2F_Text_LanceElectrodePlan, MSGBOX_DEFAULT
	release
	end

TeamRocketBaseB2F_EventScript_DoHeal::
	fadescreen FADE_TO_WHITE
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_WHITE
	return

@ ============================================================================
@ The raid's terminator. GSC's RocketBaseElectrodeScript does everything here in
@ one script: the reward, the speech, EVENT_CLEARED_ROCKET_HIDEOUT, the radio
@ signal, the ROUTE 43 gate ROCKETS, the MAHOGANY gym blocker and the LAKE OF
@ RAGE civilians. In Trinity all of that hangs off ONE arc write: every affected
@ map authors its own visibility from VAR_TRINITY_JOHTO_ARC >= 5 in its own
@ ON_TRANSITION (S4's flip-contract shape), so this script writes the arc and
@ nothing else.
@
@ THE REWARD IS TM15 HYPER BEAM, not GSC's HM06 WHIRLPOOL. There is no
@ WHIRLPOOL HM and no WHIRLPOOL TM in this build (FOREACH_HM is CUT / FLY /
@ SURF / STRENGTH / FLASH / ROCK SMASH / WATERFALL / DIVE), so the gift has to
@ change. HYPER BEAM is the callback: it is the move LANCE opened this whole
@ raid with, one floor up, through a shop wall.
@ G2 award discipline: the TM is the only failable gift, so it owns its own
@ flag and its own label, and the arc write happens BEFORE it -- a full bag can
@ never cost progression.
@ ============================================================================
TeamRocketBaseB2F_EventScript_RaidCleared::
	msgbox TeamRocketBaseB2F_Text_LanceSignalStopped, MSGBOX_DEFAULT
	call TeamRocketBaseB2F_EventScript_ClearRaidState
	goto TeamRocketBaseB2F_EventScript_GiveHyperBeam
	end

TeamRocketBaseB2F_EventScript_ClearRaidState::
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 5, TeamRocketBaseB2F_EventScript_ClearRaidStateDone
	setvar VAR_TRINITY_JOHTO_ARC, 5
	setvar VAR_TRINITY_JOHTO_SCENE_MAHOGANY, 4
TeamRocketBaseB2F_EventScript_ClearRaidStateDone::
	return

TeamRocketBaseB2F_EventScript_GiveHyperBeam::
	goto_if_set FLAG_TRINITY_J_LANCE_TM15, TeamRocketBaseB2F_EventScript_LanceFarewell
	giveitem ITEM_TM_HYPER_BEAM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_J_LANCE_TM15
	msgbox TeamRocketBaseB2F_Text_LanceHyperBeam, MSGBOX_DEFAULT
	goto TeamRocketBaseB2F_EventScript_LanceFarewell
	end

TeamRocketBaseB2F_EventScript_LanceFarewell::
	msgbox TeamRocketBaseB2F_Text_LanceMonMaster, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	removeobject LOCALID_JOHTO_TRB2F_LANCE
	waitse
	release
	end

@ ============================================================================
@ The transmitter itself: twenty readable tiles forming the perimeter of the
@ machine, x = 12..17 by y = 4..9, exactly GSC's bg_event ring. Every one of
@ them decodes collision 1 and every one has at least one walkable neighbour in
@ the surrounding corridor, which is why they are BG_EVENT_PLAYER_FACING_ANY
@ rather than a fixed facing.
@ ============================================================================
TeamRocketBaseB2F_EventScript_Transmitter::
	goto_if_set FLAG_TRINITY_J_ELECTRODE_3, TeamRocketBaseB2F_EventScript_TransmitterCheckDead
	msgbox TeamRocketBaseB2F_Text_TransmitterLive, MSGBOX_SIGN
	end

TeamRocketBaseB2F_EventScript_TransmitterCheckDead::
	goto_if_unset FLAG_TRINITY_J_ELECTRODE_1, TeamRocketBaseB2F_EventScript_TransmitterStillLive
	goto_if_unset FLAG_TRINITY_J_ELECTRODE_2, TeamRocketBaseB2F_EventScript_TransmitterStillLive
	msgbox TeamRocketBaseB2F_Text_TransmitterDead, MSGBOX_SIGN
	end

TeamRocketBaseB2F_EventScript_TransmitterStillLive::
	msgbox TeamRocketBaseB2F_Text_TransmitterLive, MSGBOX_SIGN
	end

TeamRocketBaseB2F_Text_DoorNoPassword:
	.string "The door's closed.\p"
	.string "It needs a password to open, and\n"
	.string "{PLAYER} does not have one.$"

TeamRocketBaseB2F_Text_DoorPassword:
	.string "The door's closed.\p"
	.string "{PLAYER} said: HAIL GIOVANNI.\p"
	.string "The door opened.$"

TeamRocketBaseB2F_Text_DoorOpen:
	.string "The door stands open. Whatever is\n"
	.string "humming in there is louder now.$"

TeamRocketBaseB2F_Text_GruntASeen:
	.string "The door won't open?\p"
	.string "Well, duh. It has a password that\n"
	.string "only TEAM ROCKET knows.$"

TeamRocketBaseB2F_Text_GruntABeaten:
	.string "What? I lost?$"

TeamRocketBaseB2F_Text_GruntAAfterBattle:
	.string "Heh. I'm just a GRUNT.\p"
	.string "I don't know the password. Too bad\n"
	.string "for you.$"

TeamRocketBaseB2F_Text_GruntBSeen:
	.string "Oh, a kid? I don't really like\n"
	.string "this, but eliminate you I must.$"

TeamRocketBaseB2F_Text_GruntBBeaten:
	.string "I knew I'd lose…$"

TeamRocketBaseB2F_Text_GruntBAfterBattle:
	.string "I got wiped out on the last\n"
	.string "mission by a kid too.\p"
	.string "When we were abducting POKéMON,\n"
	.string "this kid with long red hair and\l"
	.string "mean-looking eyes just creamed me.\p"
	.string "You people keep coming.$"

TeamRocketBaseB2F_Text_GruntCSeen:
	.string "You rotten little pest!$"

TeamRocketBaseB2F_Text_GruntCBeaten:
	.string "Grrrr…$"

TeamRocketBaseB2F_Text_GruntCAfterBattle:
	.string "Heh. Only the boss knows the\n"
	.string "password for that door.\p"
	.string "Where's the boss? Who knows. Go\n"
	.string "look for yourself.$"

TeamRocketBaseB2F_Text_ArianaIntro:
	.string "Hold it right there!\p"
	.string "We can't have a champion on the\n"
	.string "loose down here. It's bad for\l"
	.string "TEAM ROCKET's pride.\p"
	.string "What? You had an accomplice?\n"
	.string "The man with the dragons?\p"
	.string "Where is your sense of honour?\p"
	.string "As the interim boss in place of\n"
	.string "GIOVANNI, I'll show you how wrong\l"
	.string "it is to meddle with us!$"

TeamRocketBaseB2F_Text_ArianaDefeat:
	.string "Tch. You really are strong.\p"
	.string "It's too bad. If you were to join\n"
	.string "TEAM ROCKET, you could be an\l"
	.string "EXECUTIVE inside a year.$"

TeamRocketBaseB2F_Text_ArianaRetreat:
	.string "…This hideout is done for.\p"
	.string "But that's fine. The broadcast\n"
	.string "experiment was a total success.\p"
	.string "It doesn't matter what happens to\n"
	.string "this place now. We have much\l"
	.string "bigger plans.\p"
	.string "You'll come to appreciate TEAM\n"
	.string "ROCKET's true power soon enough.\p"
	.string "Enjoy yourself while you can.\n"
	.string "Fufufufu…$"

TeamRocketBaseB2F_Text_ArianaIdle:
	.string "…This hideout is done for.$"

TeamRocketBaseB2F_Text_ElectrodeApproach:
	.string "An ELECTRODE is wired into the\n"
	.string "machine. It is very warm.\p"
	.string "ELECTRODE: Rooo!$"

TeamRocketBaseB2F_Text_ElectrodeMore:
	.string "The machine hums on. There are\n"
	.string "others still feeding it.$"

TeamRocketBaseB2F_Text_MachineStops:
	.string "The last of them goes quiet.\p"
	.string "The hum drops away, and for the\n"
	.string "first time since MAHOGANY the room\l"
	.string "is only a room.$"

TeamRocketBaseB2F_Text_LancesSide:
	.string "LANCE: Leave this side to me.$"

TeamRocketBaseB2F_Text_LanceHeal:
	.string "LANCE: Are you all right?\p"
	.string "Your POKéMON are hurt and tired.\n"
	.string "Here. Take some of my medicine.$"

TeamRocketBaseB2F_Text_LanceHint:
	.string "That door needs a password, and a\n"
	.string "GRUNT will not have it.\p"
	.string "Go down. Find someone who thinks\n"
	.string "they matter, and ask them.$"

TeamRocketBaseB2F_Text_LanceElectrodePlan:
	.string "It's this machine causing all the\n"
	.string "problems, and I can't find a\l"
	.string "switch on it anywhere.\p"
	.string "We have no choice. We have to make\n"
	.string "all the ELECTRODE faint.\p"
	.string "It's no fault of the POKéMON,\n"
	.string "which makes me feel guilty.\p"
	.string "{PLAYER}, let's split the job.$"

TeamRocketBaseB2F_Text_LanceSignalStopped:
	.string "LANCE: That odd signal has finally\n"
	.string "stopped.\p"
	.string "The LAKE should go back to normal.\n"
	.string "The MAGIKARP will come back.\p"
	.string "You're the hero. Let me thank you\n"
	.string "on behalf of all the POKéMON.\p"
	.string "Oh, yes. You should take this.\p"
	.string "I found it down here, and I have\n"
	.string "no need for it.$"

TeamRocketBaseB2F_Text_LanceHyperBeam:
	.string "That's HYPER BEAM.\p"
	.string "You've seen what it does. It came\n"
	.string "through the shop wall upstairs.\p"
	.string "It leaves the user wide open for a\n"
	.string "turn, so spend it on something\l"
	.string "that deserves it.$"

TeamRocketBaseB2F_Text_LanceMonMaster:
	.string "{PLAYER}…\p"
	.string "The journey to becoming a POKéMON\n"
	.string "MASTER is long and difficult.\p"
	.string "You are further along it than most\n"
	.string "and it is still long.\p"
	.string "Knowing that, will you keep going?\p"
	.string "…\p"
	.string "I see. No, you're right. If you'd\n"
	.string "give up that easily you would\l"
	.string "never have chased it in the first\l"
	.string "place.\p"
	.string "I look forward to seeing you\n"
	.string "again.$"

TeamRocketBaseB2F_Text_TransmitterLive:
	.string "The radio transmitter sending the\n"
	.string "sinister signal.\p"
	.string "It's working at full capacity.$"

TeamRocketBaseB2F_Text_TransmitterDead:
	.string "The radio transmitter has finally\n"
	.string "stopped its evil broadcast.$"
