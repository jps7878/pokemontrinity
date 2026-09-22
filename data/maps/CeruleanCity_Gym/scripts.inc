CeruleanCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CeruleanCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeruleanCity_Gym_OnFrame
	.byte 0

@ M7 Task 9 (HOW gap): the Machine Part's tile ripples while the part is in the
@ pool. D2: ON_LOAD is the author (covers continue-from-save); no
@ DrawWholeMapView here. D3: the two in-map state changers (SaboteurScene sets
@ SABOTEUR_DONE, MachinePartPickup sets MACHINE_PART) repeat the write in
@ their direction and redraw. PLANT_RESTORED is written in the Power Plant, so
@ the guard below alone covers it. Same three-flag order as MachinePartPickup.
CeruleanCity_Gym_OnLoad::
	goto_if_set FLAG_TRINITY_K_PLANT_RESTORED, CeruleanCity_Gym_EventScript_OnLoadDone
	goto_if_set FLAG_TRINITY_K_MACHINE_PART, CeruleanCity_Gym_EventScript_OnLoadDone
	goto_if_unset FLAG_TRINITY_K_SABOTEUR_DONE, CeruleanCity_Gym_EventScript_OnLoadDone
	setmetatile 3, 8, METATILE_CeruleanGymKanto_PoolWater_Ripple, FALSE
CeruleanCity_Gym_EventScript_OnLoadDone::
	end

CeruleanCity_Gym_EventScript_Luis::
	trainerbattle_single TRAINER_KANTO_SWIMMER_M_LUIS, CeruleanCity_Gym_Text_LuisSeen, CeruleanCity_Gym_Text_LuisBeaten
	msgbox CeruleanCity_Gym_Text_LuisBeaten, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_Diana::
	trainerbattle_single TRAINER_KANTO_PICNICKER_DIANA, CeruleanCity_Gym_Text_DianaSeen, CeruleanCity_Gym_Text_DianaBeaten
	msgbox CeruleanCity_Gym_Text_DianaBeaten, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_Text_LuisSeen:
	.string "Every SWIMMER on this dock's\ntried the pool. Nobody's beaten\lMISTY yet.$"

CeruleanCity_Gym_Text_LuisBeaten:
	.string "Glub… you're stronger than the\ncurrent.$"

CeruleanCity_Gym_Text_DianaSeen:
	.string "Two LEAGUES down and you still\nwant a third badge? Prove it.$"

CeruleanCity_Gym_Text_DianaBeaten:
	.string "Ooh, you calmly disposed of me…\nMISTY won't go that easy.$"

@ ============================================================================
@ Trinity M5b S3 -- THE GYM PATTERN (G1-G7). Canonical file: VioletGym/scripts.inc,
@ copied verbatim by S1's VermilionCity_Gym and S2's SaffronCity_Gym; this is the
@ third mirror. Full design/decode: docs/superpowers/plans/m5b/03-cerulean-power-plant.md
@ section 1.
@
@ G1 MISTY: OBJ_EVENT_GFX_MISTY, FR's own byte-identical overworld, ported by
@ M7b Task 11b. She previously wore OBJ_EVENT_GFX_SWIMMER_F -- thematically apt
@ but shared with 16 unnamed NPCs, so she read as gym population rather than as
@ the leader. Her own sprite is not shared with this map's other swimmer-family
@ NPCs either (Luis is SWIMMER_M, Diana is PICNICKER). Placed at FRLG's own
@ tile (8,6) -- decoded col 0 elev 3 MB_NORMAL,
@ a dry-land island reachable by the winding land path traced in the sub-plan
@ (no Surf gimmick on Misty herself; only Luis and the pool pickup below are
@ water-gated). Appended idx4, TRAINER_TYPE_NONE (talk-triggered, never a sight
@ line on a tight platform), no fixed local_id (script is self-contained).
@
@ G3 NO_MUSIC: map music is MUS_RG_GYM already; NO_MUSIC on the trainerbattle
@ suppresses PlayTrainerEncounterMusic's swap. Battle BGM needs no scripting --
@ TRAINER_MISTY (1391) is inside S1's GetBattleBGM leader guard (TRAINER_BROCK..
@ TRAINER_GIOVANNI, src/pokemon.c) -> MUS_RG_VS_GYM_LEADER.
@
@ G4 THE GUIDE (idx3, unmoved -- reach_check shows exactly 1-tile self-cost, not
@ a cut vertex, "review wiring, don't re-place"), roster-verified. TRAINER_MISTY's
@ party (src/data/trainers.h): GOLDUCK 76 (WATER), QUAGSIRE 76 (WATER/GROUND),
@ LAPRAS 77 (WATER/ICE), GYARADOS 77 (WATER/FLYING), STARMIE 78 (WATER/PSYCHIC) --
@ confirmed against species_info.h, no P_UPDATED_STATS branch on any of the
@ five. Full table, re-verified against src/data/types_info.h's
@ gTypeEffectivenessTable directly (per-mon = product of the two component
@ single-type multipliers; fix round I3 caught GRASS-vs-ICE being misread as a
@ 2.0x weakness when the table row is X(1.0), neutral):
@   ELECTRIC: Golduck 2x, Quagsire 0x (immune, GROUND row col ELECTRIC = X(0.0)),
@             Lapras 2x, Gyarados 4x (FLYING row col ELECTRIC = X(2.0), stacks
@             with WATER's own 2x), Starmie 2x.
@   GRASS:    Golduck 2x, Quagsire 4x (GROUND row col GRASS = X(2.0), stacks),
@             Lapras 2x (ICE row col GRASS = X(1.0), neutral -- WATER's 2x is
@             the only contribution), Gyarados 1x (FLYING row col GRASS =
@             X(0.5), cancels WATER's 2x back to neutral), Starmie 2x.
@ No single type hits the whole roster for at least double (the S2 Mr. Mime
@ lesson): ELECTRIC misses QUAGSIRE (immune); GRASS misses GYARADOS (merely
@ neutral). Guide states both floors with their one exception each, not a
@ blanket claim.
@
@ G5 THE STATUES: facing constraint ANY -> NORTH in map.json (matches VioletGym's/
@ VermilionCity_Gym's own two-statue convention -- a facing-constraint fix, the
@ tiles themselves are untouched; both (6,16)/(10,16) north of the statues AND
@ (6,18)/(10,18) south of them decode col 0 elev 3 MB_NORMAL dry walkway --
@ fix round I2 corrected an earlier false claim that the north side "sits
@ inside the pool"; it does not, the whole row 16 is dry, and NORTH is simply
@ the established two-statue convention, not a Surf-access requirement).
@
@ G6 LUIS and DIANA: T10 placeholder "..." text replaced above.
@
@ G7 DISCIPLINE: only MistyDefeated ever writes FLAG_TRINITY_BADGE18.
@ ============================================================================
CeruleanCity_Gym_EventScript_Misty::
	trainerbattle_single TRAINER_MISTY, CeruleanCity_Gym_Text_MistyIntro, CeruleanCity_Gym_Text_MistyDefeat, CeruleanCity_Gym_EventScript_MistyDefeated, NO_MUSIC
	goto_if_unset FLAG_TRINITY_K_MISTY_TM18, CeruleanCity_Gym_EventScript_GiveRainDance
	msgbox CeruleanCity_Gym_Text_MistyPostBattle, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_EventScript_MistyDefeated::
	message CeruleanCity_Gym_Text_ReceivedCascadeBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_TRINITY_BADGE18
	msgbox CeruleanCity_Gym_Text_CascadeBadgeInfo, MSGBOX_DEFAULT
	goto CeruleanCity_Gym_EventScript_GiveRainDance
	end

CeruleanCity_Gym_EventScript_GiveRainDance::
	giveitem ITEM_TM_RAIN_DANCE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_K_MISTY_TM18
	msgbox CeruleanCity_Gym_Text_ExplainRainDance, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_BADGE18, CeruleanCity_Gym_EventScript_GymGuyPostVictory
	msgbox CeruleanCity_Gym_Text_GymGuyAdvice, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_EventScript_GymGuyPostVictory::
	msgbox CeruleanCity_Gym_Text_GymGuyPostVictory, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_TRINITY_BADGE18, CeruleanCity_Gym_EventScript_GymStatueCertified
	msgbox CeruleanCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

CeruleanCity_Gym_EventScript_GymStatue_2::
	lockall
	goto_if_set FLAG_TRINITY_BADGE18, CeruleanCity_Gym_EventScript_GymStatueCertified
	msgbox CeruleanCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

CeruleanCity_Gym_EventScript_GymStatueCertified::
	msgbox CeruleanCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

CeruleanCity_Gym_Text_MistyIntro:
	.string "MISTY: I was expecting you.\p"
	.string "You've got two LEAGUES behind\n"
	.string "you. Don't think that impresses\l"
	.string "my POKéMON any.\p"
	.string "Water always wins.$"

CeruleanCity_Gym_Text_MistyDefeat:
	.string "MISTY: You really are good…\p"
	.string "Water didn't win that one.$"

CeruleanCity_Gym_Text_ReceivedCascadeBadge:
	.string "{PLAYER} received the\n"
	.string "CASCADEBADGE from MISTY.$"

CeruleanCity_Gym_Text_CascadeBadgeInfo:
	.string "MISTY: CASCADEBADGE.\p"
	.string "Seven of these, and VIRIDIAN has\n"
	.string "to open the door.\p"
	.string "That's the CASCADEBADGE.\n"
	.string "Take this too.$"

CeruleanCity_Gym_Text_ExplainRainDance:
	.string "MISTY: TM18. RAIN DANCE.\p"
	.string "Bring the storm with you. My\n"
	.string "whole team loves it -- yours\l"
	.string "might too.$"

CeruleanCity_Gym_Text_MistyPostBattle:
	.string "MISTY: Go find some tougher\n"
	.string "trainers to bother.$"

CeruleanCity_Gym_Text_GymGuyAdvice:
	.string "Hey, CHAMPION! Word travels fast\n"
	.string "on this dock.\p"
	.string "MISTY runs WATER types --\n"
	.string "GOLDUCK, QUAGSIRE, LAPRAS,\l"
	.string "GYARADOS, STARMIE. LEVEL 76 to\l"
	.string "78.\p"
	.string "ELECTRIC handles four of the\n"
	.string "five -- but not QUAGSIRE. GROUND\l"
	.string "typing eats an ELECTRIC hit whole.\p"
	.string "GRASS handles four of the five\n"
	.string "too -- but not GYARADOS. FLYING\l"
	.string "typing cancels the advantage\l"
	.string "right back to neutral.\p"
	.string "Pick your poison. Neither one\n"
	.string "covers all five alone.$"

CeruleanCity_Gym_Text_GymGuyPostVictory:
	.string "Straight through MISTY! CASCADE-\n"
	.string "BADGE. One of seven.$"

CeruleanCity_Gym_Text_GymStatue:
	.string "CERULEAN CITY POKéMON GYM\n"
	.string "LEADER: MISTY\p"
	.string "The Tomboyish Mermaid$"

CeruleanCity_Gym_Text_GymStatueCertified:
	.string "CERULEAN CITY POKéMON GYM\n"
	.string "LEADER: MISTY\p"
	.string "MISTY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

@ ============================================================================
@ Trinity M5b S3 -- THE SABOTEUR (GSC CeruleanGymGruntRunsOutScene, adapted).
@ Full decode: docs/superpowers/plans/m5b/03-cerulean-power-plant.md section 1.
@
@ VAR_TRINITY_SCENE_CERULEAN_SABOTEUR: 0 unarmed / 1 armed (PowerPlant's manager
@ sets this on the post-badge first meet) / 2 done. ON_TRANSITION authors the
@ saboteur's own FLAG_TRINITY_K_SABOTEUR_HIDE (R1 single-member-cast shape):
@ visible iff var == 1. ON_FRAME fires the scene the next time the var reads 1
@ -- the direct engine equivalent of GSC's own scene-callback auto-fire.
@
@ DISARM (S1 lesson): the Showdown script's SECOND instruction, right after
@ lockall, is the setvar that moves the var off 1 -- so even though a lockall
@ already blocks TryRunOnFrameMapScript from re-firing mid-scene (it only runs
@ from ProcessPlayerFieldInput), the trigger condition is dead before anything
@ else runs, matching the pin's letter exactly.
@
@ Player is never moved (GSC's own grunt never moves the player either, only
@ itself). Object: OBJ_EVENT_GFX_ROCKET_M, FRLG's own Team Rocket grunt sprite
@ (M7b Task 11 ported it in; this was OBJ_EVENT_GFX_AQUA_MEMBER_M, the Team AQUA
@ stand-in, up to that point -- every Rocket grunt object moved together).
@ Starts (9,10)
@ (fix round M1: originally (9,8), whose approach path crossed the single water
@ cell (9,9) -- scripted movement ignores collision/water entirely, S6's pin,
@ so nothing would have blocked it, but the actor would have visibly strode on
@ the pool surface; moved off it rather than merely noting the engine permits
@ it). (9,10)-(9,18) decodes col 0 elev 3 MB_NORMAL end to end, dry the whole
@ way -- runs down to (9,14), bumps, then continues to (9,18) and out.
@ removeobject at the end co-signs the HIDE flag permanently (R1). Working
@ state machine (var states, disarm timing, R1 co-sign) unchanged by this fix.
@
@ DISCOVERABILITY (fix round I1): the Machine Part sits on 1 of 123 Surf-
@ reachable pool tiles, and BG_EVENT_HIDDEN_ITEM is the only kind the
@ Itemfinder actually scans (src/item_use.c:452,481 both gate on `kind ==
@ BG_EVENT_HIDDEN_ITEM`; this is a plain sign-kind bg_event, invisible to it,
@ by the mechanism decision in section 1 of the sub-plan). Since the mechanism
@ itself is staying (a real hidden_item would drop the saboteur-done gate and
@ the key-item-as-flag shape), the fixes are dialogue and, since M7 Task 9, a
@ drawn one: the saboteur's own apology names the tile's corner of the pool
@ (below), the manager's waiting line (PowerPlant_Text_
@ ManagerIWontForgiveHim) points at "the CERULEAN GYM's pool" explicitly, and
@ (3,8) itself ripples for exactly the window in which the part is there (the
@ ON_LOAD author at the top of this file).
@
@ Skipped from GSC, logged: the Route 24/25 flag entanglement (Act III's Rocket
@ arc is Celadon/Viridian, this stays self-contained); the four-part apology/
@ threat/goodbye exchange compressed to two lines.
@ ============================================================================
CeruleanCity_Gym_OnTransition::
	call_if_eq VAR_TRINITY_SCENE_CERULEAN_SABOTEUR, 1, CeruleanCity_Gym_EventScript_ShowSaboteur
	call_if_ne VAR_TRINITY_SCENE_CERULEAN_SABOTEUR, 1, CeruleanCity_Gym_EventScript_HideSaboteur
	end

CeruleanCity_Gym_EventScript_ShowSaboteur::
	clearflag FLAG_TRINITY_K_SABOTEUR_HIDE
	return

CeruleanCity_Gym_EventScript_HideSaboteur::
	setflag FLAG_TRINITY_K_SABOTEUR_HIDE
	return

CeruleanCity_Gym_OnFrame::
	map_script_2 VAR_TRINITY_SCENE_CERULEAN_SABOTEUR, 1, CeruleanCity_Gym_EventScript_SaboteurScene
	.2byte 0

@ The object's own interaction script -- ON_FRAME fires the scene on the very
@ first frame the player has field control after this map loads (S8's pin:
@ TryRunOnFrameMapScript runs from ProcessPlayerFieldInput), well before a talk
@ could beat it there, but every object needs a real script, so a direct talk
@ just runs the identical scene.
CeruleanCity_Gym_EventScript_Saboteur::
	goto CeruleanCity_Gym_EventScript_SaboteurScene
	end

CeruleanCity_Gym_EventScript_SaboteurScene::
	lockall
	setvar VAR_TRINITY_SCENE_CERULEAN_SABOTEUR, 2
	applymovement LOCALID_KANTO_CERULEAN_GYM_SABOTEUR, CeruleanCity_Gym_Movement_SaboteurApproach
	waitmovement 0
	applymovement LOCALID_KANTO_CERULEAN_GYM_SABOTEUR, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox CeruleanCity_Gym_Text_SaboteurApology, MSGBOX_DEFAULT
	closemessage
	msgbox CeruleanCity_Gym_Text_SaboteurSpotted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_KANTO_CERULEAN_GYM_SABOTEUR, CeruleanCity_Gym_Movement_SaboteurFlees
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_KANTO_CERULEAN_GYM_SABOTEUR
	setflag FLAG_TRINITY_K_SABOTEUR_DONE
	setmetatile 3, 8, METATILE_CeruleanGymKanto_PoolWater_Ripple, FALSE
	special DrawWholeMapView
	releaseall
	end

CeruleanCity_Gym_Movement_SaboteurApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Gym_Movement_SaboteurFlees:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Gym_Text_SaboteurApology:
	.string "Oof -- sorry! Didn't see you\n"
	.string "there. You just about caught me\l"
	.string "mid-splash, crouched at the\l"
	.string "pool's west edge -- right under\l"
	.string "the PICNICKER's platform.$"

CeruleanCity_Gym_Text_SaboteurSpotted:
	.string "Wait -- you're the one MISTY's\n"
	.string "been talking about. This is a\l"
	.string "big mistake. Forget you saw me\l"
	.string "-- forget the water, too!$"

@ ============================================================================
@ Trinity M5b S3 -- THE POOL PICKUP. Full mechanism decision (option 1 hidden_
@ item vs option 2 custom sign vs option 3 coord_event) and the (3,8) tile
@ derivation: docs/superpowers/plans/m5b/03-cerulean-power-plant.md section 1.
@ (3,8) is fully surrounded by water (every cardinal neighbour also decodes
@ MB_OCEAN_WATER), reachable with Surf and unreachable without -- and matches
@ GSC's own CeruleanGymHiddenMachinePart coordinate, independently derived.
@
@ FLAG_TRINITY_K_MACHINE_PART is a flag, not a real item (M4b CianwoodPharmacy/
@ SECRETPOTION precedent, cited by name in the sub-plan). Guards are
@ MOST-ADVANCED-FIRST (Cianwood's own lesson: an intermediate flag that later
@ gets CONSUMED must never be read before the terminal state that consumes it
@ -- FLAG_TRINITY_K_PLANT_RESTORED clears FLAG_TRINITY_K_MACHINE_PART on
@ turn-in, so without the RESTORED check first, a post-restoration re-poke here
@ would look like "never found" and hand out a second one).
@ ============================================================================
CeruleanCity_Gym_EventScript_MachinePartPickup::
	lock
	goto_if_set FLAG_TRINITY_K_PLANT_RESTORED, CeruleanCity_Gym_EventScript_PoolEmpty
	goto_if_set FLAG_TRINITY_K_MACHINE_PART, CeruleanCity_Gym_EventScript_PoolEmpty
	goto_if_unset FLAG_TRINITY_K_SABOTEUR_DONE, CeruleanCity_Gym_EventScript_PoolEmpty
	msgbox CeruleanCity_Gym_Text_FoundMachinePart, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox CeruleanCity_Gym_Text_ReceivedMachinePart, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_K_MACHINE_PART
	setmetatile 3, 8, METATILE_CeruleanGymKanto_PoolWater, FALSE
	special DrawWholeMapView
	release
	end

CeruleanCity_Gym_EventScript_PoolEmpty::
	msgbox CeruleanCity_Gym_Text_PoolEmpty, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_FoundMachinePart:
	.string "Something's wedged against the\n"
	.string "tile down here -- a heavy, oddly\l"
	.string "shaped MACHINE PART.$"

CeruleanCity_Gym_Text_ReceivedMachinePart:
	.string "{PLAYER} received the\n"
	.string "MACHINE PART.$"

CeruleanCity_Gym_Text_PoolEmpty:
	.string "Just water down here.$"
