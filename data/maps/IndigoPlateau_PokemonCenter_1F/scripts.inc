@ ============================================================================
@ M4b S11 -- the INDIGO PLATEAU POKéMON CENTER, and the ELITE FOUR reset.
@
@ THE RESPAWN HOLE THIS CLOSES. No Johto or Kanto POKéMON CENTER sets a
@ respawn: `setrespawn` appears on twenty HOENN maps and on none of the 217
@ Johto or 269 Kanto maps. FIX ROUND 1 (review I4): one Johto MAP does carry a
@ `setrespawn` outside the Center network -- OlivinePort's sailor script sets
@ HEAL_LOCATION_LILYCOVE_CITY, but only on the confirmed return-boat prompt
@ (a talk-triggered YES/NO, not anything that fires on arrival), so it never
@ contests a Center respawn and the "no Center sets one" claim above still
@ holds as written. Whiting out anywhere in Act II therefore returned the
@ player to their last HOENN heal location. For most of JOHTO that WAS an M4a
@ gap (measured here) -- S11B closed it tree-wide: all 11 JOHTO POKéMON
@ CENTERS now carry their own setrespawn. THIS map's respawn was never
@ contingent on that fix; it is a slice requirement in its own right,
@ because "lose in the LEAGUE, restart from the Center" is vanilla's own ELITE
@ FOUR contract and vanilla implements it exactly here --
@ EverGrandeCity_PokemonLeague_1F_OnTransition's
@ `setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE`.
@ HEAL_LOCATION_INDIGO_PLATEAU is APPENDED to the enum, so no existing index
@ moves, and gSaveBlock1Ptr->lastHealLocation is a struct WarpData
@ (include/global.h:1073) written by SetLastHealLocationWarp
@ (src/overworld.c:734-738) -- the index itself is never stored, so this is
@ save-safe.
@
@ THE RESET IS GSC's OWN DESIGN, line for line:
@ IndigoPlateauPokecenter1FPrepareElite4Callback (pokecrystal/maps/
@ IndigoPlateauPokecenter1F.asm) clears every room scene, every door event and
@ all five EVENT_BEAT_ELITE_4_* on entering this Center. Putting it here rather
@ than in the tree-wide EventScript_WhiteOut (which is what vanilla HOENN does,
@ data/event_scripts.s:1084-1086) is narrower -- Act I's script is not touched.
@ FIX ROUND 1 (review M2): this comment previously also claimed the transition
@ "covers loading a save in the room" -- FALSE. CB2_ContinueSavedGame runs
@ MAP_SCRIPT_ON_LOAD, never MAP_SCRIPT_ON_TRANSITION (src/overworld.c:
@ 1972-2000), so simply continuing a save parked in this room does NOT re-run
@ this reset. Harmless in play: the Center is unreachable mid-gauntlet (the
@ league rooms are one-way, S11 report §6.2), so any save sitting here already
@ had the reset applied on the warp IN that put it there.
@
@ S6's CLEARED-FLAG RULE APPLIES AND IS THE REASON _LEAGUE_CLEARED EXISTS. Five
@ flags below are CLEARED, so the chain's terminal state can never be inferred
@ from them: they return to their starting values on every visit. The terminal
@ state is FLAG_TRINITY_J_LEAGUE_CLEARED (+ VAR_TRINITY_JOHTO_ARC == 10), which
@ nothing clears, ever.
@
@ ORDERING (S4's I3(b)): state writes first, and the arc var is deliberately NOT
@ among them -- arc 10 is written once, in the HALL OF FAME, under S1's monotonic
@ guard. This transition must never touch it.
@
@ THE CLERK IS AN MB_COUNTER NPC (S4's idiom, including the elevation half).
@ He stands on (0,7) at elevation 3, the counter (1,7) decodes MB_COUNTER at
@ elevation 0, and the player is served from (2,7) at elevation 3.
@ GetInteractedObjectEventScript looks one tile further through a counter
@ (src/field_control_avatar.c:387-396) and GetObjectEventIdByPosition compares
@ the PLAYER's elevation, not the counter's (src/event_object_movement.c:
@ 3352-3374) -- so the NPC must share the floor's elevation, not the counter's.
@ The NURSE at (13,10) is the same shape across the counter at (13,11).
@ reach_check reports both NPC tiles as unreachable and is right to; moving them
@ would be the bug (S4's rule).
@ ============================================================================

IndigoPlateau_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

IndigoPlateau_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU
	setvar VAR_TRINITY_JOHTO_SCENE_INDIGO, 0
	clearflag FLAG_TRINITY_J_E4_WILL_BEATEN
	clearflag FLAG_TRINITY_J_E4_KOGA_BEATEN
	clearflag FLAG_TRINITY_J_E4_BRUNO_BEATEN
	clearflag FLAG_TRINITY_J_E4_KAREN_BEATEN
	clearflag FLAG_TRINITY_J_E4_LANCE_BEATEN
	@ Trinity M5b S11 -- the SAME reset, carried over to the Kanto (E4-II)
	@ roster. Harmless for a save that never fought this roster (a flag that
	@ was never set clears to no effect); §1.1/§4 of the S11 sub-plan.
	clearflag FLAG_TRINITY_K_E4_LORELEI_BEATEN
	clearflag FLAG_TRINITY_K_E4_AGATHA_BEATEN
	clearflag FLAG_TRINITY_K_E4_BRUNOII_BEATEN
	clearflag FLAG_TRINITY_K_E4_BLUE_BEATEN
	@ Trinity M5b S11 fix round 1 (review C2) -- ASH's own re-fight guard,
	@ cleared beside the four E4-II flags just above; the exact
	@ FLAG_TRINITY_J_E4_LANCE_BEATEN shape, one line down.
	clearflag FLAG_TRINITY_K_E4_ASH_BEATEN
	@ Trinity M5b S11 fix round 1 (review C1) -- the roster switch, object
	@ layer, moved here from a broken MAP_SCRIPT_ON_LOAD (removed entirely).
	@ POSTMORTEM: ON_LOAD runs at CB2_LoadMap state 0, before
	@ InitObjectEventsLocal spawns any object at state 3
	@ (src/overworld.c:2160-2180, :2435-2450); SetObjectInvisibility silently
	@ fails against a target that has no live instance yet
	@ (src/event_object_movement.c:3089-3094), so the original showobjectat/
	@ hideobjectat calls here were guaranteed no-ops -- every one of the 7
	@ lobby objects spawned unconditionally (flag:"0"), fightable from any
	@ Act II save. THE FIX is the tree's own hide-flag idiom
	@ (CeruleanCity_OnTransition/FLAG_TRINITY_K_CAVE_GUARD_HIDE,
	@ data/maps/CeruleanCity/scripts.inc:34-41): all 7 lobby objects now carry
	@ FLAG_TRINITY_K_KANTO_CAST_HIDE in their map.json flag field (the same
	@ flag the 4 E4-II sitters and Ash's two objects use -- one shared flag,
	@ 13 objects, one live check), authored here because ON_TRANSITION runs
	@ before spawn too, but a FLAG is SaveBlock state TrySpawnObjectEvents
	@ reads AT spawn time, not a live-instance call attempted too early. Both
	@ flags hex-audited fresh at 0x1DE/0x1DF (include/constants/flags.h) --
	@ the original 0x4E9-0x4EF registry run is fully spent.
	call Trinity_EventScript_CountKantoBadges
	goto_if_ge VAR_TEMP_A, 8, IndigoPlateau_PokemonCenter_1F_EventScript_ArmKantoCast
	setflag FLAG_TRINITY_K_KANTO_CAST_HIDE
	clearflag FLAG_TRINITY_K_JOHTO_SITTER_HIDE
	end

IndigoPlateau_PokemonCenter_1F_EventScript_ArmKantoCast::
	clearflag FLAG_TRINITY_K_KANTO_CAST_HIDE
	setflag FLAG_TRINITY_K_JOHTO_SITTER_HIDE
	end

@ ============================================================================
@ THE CREW GAUNTLET (M1 mechanic, reused -- S11 sub-plan §3.2/§3.3). Each
@ fighter is an independent, talk-triggered post built on trainerbattle_single
@ (the exact 4-arg CONTINUE_SCRIPT shape GraniteCave_1F's own HARJOT uses),
@ (event_script continuation on win). "Already beaten" idempotency for a
@ re-approach needs no new flag: checktrainerflag reads what
@ SetBattledTrainersFlags (src/battle_setup.c:1193-1198) already set natively
@ on any win, regardless of trainerbattle variant.
@
@ GURNAV DEBUTS HERE -- his first appearance anywhere in the game. Team
@ (Houndoom/Absol/Sableye/Mightyena/Umbreon, src/data/trainers.party) is
@ Dark-leaning; his own line about it is the factual claim his roster backs.
@
@ FIX ROUND 1 (review M3) -- each fighter's own script now re-derives the
@ live 8-badge C-COUNT at its own top, the S1 house rule ("a story talk
@ script carries its own state guard regardless") applied here the same way
@ it already is for ASH. This is now provably unreachable in play (the
@ object cannot even spawn below 8 badges -- FLAG_TRINITY_K_KANTO_CAST_HIDE,
@ see OnTransition above), which is exactly the class of defensive
@ redundancy S1 asks for, not dead weight: the C1 fix means the object layer
@ SHOULD make this unreachable, and the inline check proves the script does
@ not silently rely on that alone.
@
@ FIX ROUND 1 (review Minor 9) -- special HealPlayerParty removed. Matching
@ M1's own original behaviour exactly, no innovation: GraniteCave_1F_
@ EventScript_HarjotReward/_HarjotPostReward (M1's HARJOT, the template this
@ whole mechanic reuses) never calls HealPlayerParty in any branch, ever --
@ M1 has no heal mechanic at all, first win or re-approach alike. "Full heal
@ between" is satisfied by staging, not a scripted call: this gauntlet
@ (unlike M1's four scattered posts) is fought entirely inside the INDIGO
@ PLATEAU POKéMON CENTER, with the NURSE a few tiles away at all times.
@ ============================================================================
IndigoPlateau_PokemonCenter_1F_EventScript_HarjotK::
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 8, IndigoPlateau_PokemonCenter_1F_EventScript_GauntletNotYet
	trainerbattle_single TRAINER_HARJOT_K, IndigoPlateau_PokemonCenter_1F_Text_HarjotKIntro, IndigoPlateau_PokemonCenter_1F_Text_HarjotKDefeat, IndigoPlateau_PokemonCenter_1F_EventScript_HarjotKAfter
	goto IndigoPlateau_PokemonCenter_1F_EventScript_HarjotKAfter
	end

IndigoPlateau_PokemonCenter_1F_EventScript_HarjotKAfter::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_HarjotKPost, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_IvrajK::
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 8, IndigoPlateau_PokemonCenter_1F_EventScript_GauntletNotYet
	trainerbattle_single TRAINER_IVRAJ_K, IndigoPlateau_PokemonCenter_1F_Text_IvrajKIntro, IndigoPlateau_PokemonCenter_1F_Text_IvrajKDefeat, IndigoPlateau_PokemonCenter_1F_EventScript_IvrajKAfter
	goto IndigoPlateau_PokemonCenter_1F_EventScript_IvrajKAfter
	end

IndigoPlateau_PokemonCenter_1F_EventScript_IvrajKAfter::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_IvrajKPost, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_SumeetK::
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 8, IndigoPlateau_PokemonCenter_1F_EventScript_GauntletNotYet
	trainerbattle_single TRAINER_SUMEET_K, IndigoPlateau_PokemonCenter_1F_Text_SumeetKIntro, IndigoPlateau_PokemonCenter_1F_Text_SumeetKDefeat, IndigoPlateau_PokemonCenter_1F_EventScript_SumeetKAfter
	goto IndigoPlateau_PokemonCenter_1F_EventScript_SumeetKAfter
	end

IndigoPlateau_PokemonCenter_1F_EventScript_SumeetKAfter::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_SumeetKPost, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_PrabhjitK::
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 8, IndigoPlateau_PokemonCenter_1F_EventScript_GauntletNotYet
	trainerbattle_single TRAINER_PRABHJIT_K, IndigoPlateau_PokemonCenter_1F_Text_PrabhjitKIntro, IndigoPlateau_PokemonCenter_1F_Text_PrabhjitKDefeat, IndigoPlateau_PokemonCenter_1F_EventScript_PrabhjitKAfter
	goto IndigoPlateau_PokemonCenter_1F_EventScript_PrabhjitKAfter
	end

IndigoPlateau_PokemonCenter_1F_EventScript_PrabhjitKAfter::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_PrabhjitKPost, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Gurnav::
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 8, IndigoPlateau_PokemonCenter_1F_EventScript_GauntletNotYet
	trainerbattle_single TRAINER_GURNAV, IndigoPlateau_PokemonCenter_1F_Text_GurnavIntro, IndigoPlateau_PokemonCenter_1F_Text_GurnavDefeat, IndigoPlateau_PokemonCenter_1F_EventScript_GurnavAfter
	goto IndigoPlateau_PokemonCenter_1F_EventScript_GurnavAfter
	end

IndigoPlateau_PokemonCenter_1F_EventScript_GurnavAfter::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_GurnavPost, MSGBOX_DEFAULT
	release
	end

@ Shared bail for all 7 lobby scripts (5 crew + BOBBY + WALLY_K) -- provably
@ unreachable in play (see the header above), a silent release matches S1's
@ own precedent for a defensive branch with nothing narratively to say
@ (PokemonLeague_ChampionsRoom_EventScript_PostBattleIdle is the same class
@ of "kept correct, never seen" branch).
IndigoPlateau_PokemonCenter_1F_EventScript_GauntletNotYet::
	release
	end

@ ============================================================================
@ BOBBY -- hosts, briefs, does NOT fight (brief item 4; his own farewell
@ battle is S13b's -- TRAINER_BOBBY, real party data, confirmed unfought
@ and unconsumed by every prior slice). His own script administers the ONE
@ reward: 5x checktrainerflag, the exact idiom Trinity_EventScript_
@ CountKantoBadges already uses one level up (call_if_set-per-flag -> here,
@ goto_if FALSE-per-trainer), gated on FLAG_TRINITY_K_GAUNTLET_REWARD for
@ the claimed-once guard. FIX ROUND 1 (review M3): own inline 8-badge check
@ restored at the top, same S1 house rule and same provably-unreachable
@ status as the 5 fighters above.
@
@ S13b addition: the FAREWELL, gated arc>=6 (world-tour postgame, the same
@ VAR_TRINITY_KANTO_ARC read every other package in this milestone uses)
@ AND `checktrainerflag TRAINER_BOBBY` unset -- a NEW branch prepended
@ before the badge-count check. `lock`/`faceplayer` moved up into this new
@ entry point; the original body (now `BobbyRewardFlow`) is reached only
@ by `goto` from here, so it is BEHAVIOURALLY unaffected, not byte-for-byte
@ identical (fix round 1, review m6 -- the earlier "byte-for-byte" wording
@ was imprecise). One real, disclosed side effect (review m5): an arc>=6
@ player who has NOT yet claimed the gauntlet reward is routed past
@ `BobbyRewardFlow` straight into the farewell every visit until it is won
@ -- the reward becomes reachable again only after beating BOBBY once. This
@ is a deferral, not a loss (`FLAG_TRINITY_K_GAUNTLET_REWARD` is untouched,
@ a whiteout just re-offers the farewell), ruled coherent by the controller
@ and kept as-is, not "every existing behaviour... completely unaffected"
@ as originally claimed.
@
@ One-fight-per-id via the engine's own trainer flag
@ (checktrainerflag TRAINER_BOBBY), same semantics as SILVER_MTMOON/SAGE_*
@ elsewhere in this slice -- no new custom flag. CORRECTED (fix round 1,
@ review C3): `trainerbattle_no_intro` is NOT "the identical mechanism
@ WALLY_K and the five gauntlet fighters already use in this same room" --
@ that claim was FALSE. Census of this file: all six existing fights
@ (HARJOT_K/IVRAJ_K/SUMEET_K/PRABHJIT_K/GURNAV/WALLY_K) use
@ `trainerbattle_single`; BOBBY's is the ONLY `trainerbattle_no_intro` here.
@ The two macros are not interchangeable: `trainerbattle_single` ->
@ `EventScript_TryDoNormalTrainerBattle` supplies its own `lock`/
@ `faceplayer` AND a `GetTrainerFlag` idempotence check;
@ `trainerbattle_no_intro` -> `EventScript_DoNoIntroTrainerBattle` supplies
@ NEITHER and calls `dotrainerbattle` unconditionally (data/scripts/
@ trainer_battle.inc). The explicit `checktrainerflag TRAINER_BOBBY` guard
@ two lines below is therefore the LOAD-BEARING mechanism, not a mirror of
@ a room precedent that does not exist -- without it, BOBBY would be
@ infinitely re-fightable. Loss/whiteout: resolves through the engine's
@ own standard trainer-battle-loss path (return to the last Pokémon
@ Center), the same as any trainer fight; BOBBY's own object/hosting logic
@ is untouched either way -- his farewell state is gated purely on the
@ engine trainer flag, which a whiteout does not clear.
@ ============================================================================
IndigoPlateau_PokemonCenter_1F_EventScript_Bobby::
	lock
	faceplayer
	goto_if_lt VAR_TRINITY_KANTO_ARC, 6, IndigoPlateau_PokemonCenter_1F_EventScript_BobbyRewardFlow
	checktrainerflag TRAINER_BOBBY
	goto_if TRUE, IndigoPlateau_PokemonCenter_1F_EventScript_BobbyRewardFlow
	msgbox IndigoPlateau_PokemonCenter_1F_Text_BobbyFarewellIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BOBBY, IndigoPlateau_PokemonCenter_1F_Text_BobbyFarewellDefeat
	msgbox IndigoPlateau_PokemonCenter_1F_Text_BobbyFarewellAfter, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_BobbyRewardFlow::
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 8, IndigoPlateau_PokemonCenter_1F_EventScript_BobbyNotYet
	goto_if_set FLAG_TRINITY_K_GAUNTLET_REWARD, IndigoPlateau_PokemonCenter_1F_EventScript_BobbyClaimed
	checktrainerflag TRAINER_HARJOT_K
	goto_if FALSE, IndigoPlateau_PokemonCenter_1F_EventScript_BobbyBriefing
	checktrainerflag TRAINER_IVRAJ_K
	goto_if FALSE, IndigoPlateau_PokemonCenter_1F_EventScript_BobbyBriefing
	checktrainerflag TRAINER_SUMEET_K
	goto_if FALSE, IndigoPlateau_PokemonCenter_1F_EventScript_BobbyBriefing
	checktrainerflag TRAINER_PRABHJIT_K
	goto_if FALSE, IndigoPlateau_PokemonCenter_1F_EventScript_BobbyBriefing
	checktrainerflag TRAINER_GURNAV
	goto_if FALSE, IndigoPlateau_PokemonCenter_1F_EventScript_BobbyBriefing
	msgbox IndigoPlateau_PokemonCenter_1F_Text_BobbyRewardOffer, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_FAMILY_REWARD, FALSE
	switch VAR_RESULT
	case 0, IndigoPlateau_PokemonCenter_1F_EventScript_BobbyMasterBalls
	case 1, IndigoPlateau_PokemonCenter_1F_EventScript_BobbyRareCandies
	case 2, IndigoPlateau_PokemonCenter_1F_EventScript_BobbyCancel
	case MULTI_B_PRESSED, IndigoPlateau_PokemonCenter_1F_EventScript_BobbyCancel
	end

IndigoPlateau_PokemonCenter_1F_EventScript_BobbyMasterBalls::
	giveitem ITEM_MASTER_BALL, 2
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_K_GAUNTLET_REWARD
	msgbox IndigoPlateau_PokemonCenter_1F_Text_BobbyPostReward, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_BobbyRareCandies::
	giveitem ITEM_RARE_CANDY, 99
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_K_GAUNTLET_REWARD
	msgbox IndigoPlateau_PokemonCenter_1F_Text_BobbyPostReward, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_BobbyCancel::
	release
	end

@ M7b Task 13 (finding #9c, the state-aware half): BOBBY's two TERMINAL repeat
@ lines become his standing objective board -- he names every JOHTO thread the
@ player has not closed, or says the desk is clear. Both branches are reached
@ from 8 KANTO badges onward (his object's own spawn condition,
@ FLAG_TRINITY_K_KANTO_CAST_HIDE) and BobbyBriefing in particular is the branch
@ a player who has NOT taken the family gauntlet lands on, so the reference is
@ not behind the gauntlet, the reward, or the farewell battle. The report
@ script lives in data/scripts/trinity_navigator.inc and ends in `return`; the
@ lock is this file's, taken at EventScript_Bobby. Nothing else in his script
@ changes -- not the reward flow, not the farewell battle, not BobbyNotYet.
IndigoPlateau_PokemonCenter_1F_EventScript_BobbyBriefing::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_BobbyBriefing, MSGBOX_DEFAULT
	call Trinity_EventScript_BobbyLegendaryReport
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_BobbyClaimed::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_BobbyPostReward, MSGBOX_DEFAULT
	call Trinity_EventScript_BobbyLegendaryReport
	release
	end

@ Provably unreachable (BOBBY's own object cannot spawn below 8 badges --
@ FLAG_TRINITY_K_KANTO_CAST_HIDE), kept per S1's rule; own lock/faceplayer
@ above needs its own release, unlike the bare-trainerbattle fighters' shared
@ GauntletNotYet.
IndigoPlateau_PokemonCenter_1F_EventScript_BobbyNotYet::
	release
	end

@ ============================================================================
@ WALLY -- "the last challenger" (brief). Bare 3-arg trainerbattle_single,
@ the same minimal shape every plain VR_COOLTRAINER post in this tree already
@ uses (e.g. KantoVictoryRoad_1F_EventScript_DARNELL) -- no manual lock/
@ faceplayer wrapper needed, EventScript_TryDoNormalTrainerBattle already
@ provides lock/faceplayer/reveal/GetTrainerFlag-idempotency internally; the
@ line after that macro call is what a re-approach (or a post-win talk)
@ falls through to. WALLY_K music: CONFIRMED, no override -- S11 sub-plan §7.
@ FIX ROUND 1 (review M3): own inline 8-badge check restored at the top,
@ sharing the crew's GauntletNotYet bail (same provably-unreachable status).
@ ============================================================================
IndigoPlateau_PokemonCenter_1F_EventScript_WallyK::
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 8, IndigoPlateau_PokemonCenter_1F_EventScript_GauntletNotYet
	trainerbattle_single TRAINER_WALLY_K, IndigoPlateau_PokemonCenter_1F_Text_WallyKIntro, IndigoPlateau_PokemonCenter_1F_Text_WallyKDefeat
	msgbox IndigoPlateau_PokemonCenter_1F_Text_WallyKPost, MSGBOX_AUTOCLOSE
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_JOHTO_INDIGO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

@ Vanilla's own league shelf, item for item
@ (EverGrandeCity_PokemonLeague_1F_Pokemart). Prices are global -- GetItemPrice
@ reads gItemsInfo[item].price and `pokemart` has no per-shop override (S4) --
@ so the list is the whole edit.
IndigoPlateau_PokemonCenter_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart IndigoPlateau_PokemonCenter_1F_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
IndigoPlateau_PokemonCenter_1F_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	pokemartlistend

IndigoPlateau_PokemonCenter_1F_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_LEAGUE_CLEARED, IndigoPlateau_PokemonCenter_1F_EventScript_ReceptionistAfter
	msgbox IndigoPlateau_PokemonCenter_1F_Text_Receptionist, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_ReceptionistAfter::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_ReceptionistAfter, MSGBOX_DEFAULT
	release
	end

@ G4's rule for an advice NPC: state the real numbers. The five rosters are
@ L72-77 (WILL 72-73, KOGA 72-74, BRUNO 73-75, KAREN 73-75, LANCE 75-77), and
@ this line is checked against src/data/trainers.party, not remembered.
IndigoPlateau_PokemonCenter_1F_EventScript_Advisor::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_LEAGUE_CLEARED, IndigoPlateau_PokemonCenter_1F_EventScript_AdvisorAfter
	msgbox IndigoPlateau_PokemonCenter_1F_Text_Advisor, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_AdvisorAfter::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_AdvisorAfter, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_1F_Text_Receptionist:
	.string "Welcome to the POKéMON LEAGUE.\p"
	.string "Through that door are five rooms.\n"
	.string "You take them in order and the\l"
	.string "door shuts behind you each time.\p"
	.string "There is no coming back through\n"
	.string "for a POTION.\p"
	.string "If you lose, you'll wake up right\n"
	.string "here, and the LEAGUE will be\l"
	.string "waiting from the first room.\p"
	.string "Heal. Shop. Then go when you're\n"
	.string "ready -- not before.$"

IndigoPlateau_PokemonCenter_1F_Text_ReceptionistAfter:
	.string "CHAMPION of JOHTO.\p"
	.string "I've written it in the book\n"
	.string "three times now and it still\l"
	.string "looks wrong.\p"
	.string "The rooms are reset whenever you\n"
	.string "come through here. If you want\l"
	.string "them again, they're yours.$"

@ GSC IndigoPlateauPokecenter1FCooltrainerMText, with the level band added.
IndigoPlateau_PokemonCenter_1F_Text_Advisor:
	.string "At the POKéMON LEAGUE, you'll get\n"
	.string "tested by the ELITE FOUR.\p"
	.string "You have to beat them all. If you\n"
	.string "lose, you start all over.\p"
	.string "WILL is PSYCHIC, KOGA is POISON,\n"
	.string "BRUNO is FIGHTING, KAREN is DARK.\p"
	.string "They run from level 72 to 75.\p"
	.string "Then LANCE. Level 75 to 77, and\n"
	.string "six of them.$"

IndigoPlateau_PokemonCenter_1F_Text_AdvisorAfter:
	.string "You went through all five.\p"
	.string "…I've been giving that speech for\n"
	.string "eleven years. Nobody had ever\l"
	.string "come back out to hear the end\l"
	.string "of it.$"

@ ============================================================================
@ CREW GAUNTLET TEXT.
@ ============================================================================
IndigoPlateau_PokemonCenter_1F_Text_HarjotKIntro:
	.string "GRANITE CAVE was the first time.\n"
	.string "This is the last.$"

IndigoPlateau_PokemonCenter_1F_Text_HarjotKDefeat:
	.string "Still fighting like one of us.\n"
	.string "Good.$"

IndigoPlateau_PokemonCenter_1F_Text_HarjotKPost:
	.string "HARJOT: Go on. We'll be right\n"
	.string "here.$"

IndigoPlateau_PokemonCenter_1F_Text_IvrajKIntro:
	.string "The RUINS taught me patience.\n"
	.string "You've taught me the rest.$"

IndigoPlateau_PokemonCenter_1F_Text_IvrajKDefeat:
	.string "…Some things you don't need\n"
	.string "PSYCHIC POWER to see coming.$"

IndigoPlateau_PokemonCenter_1F_Text_IvrajKPost:
	.string "IVRAJ: Three regions, and you\n"
	.string "still hit harder every time.$"

IndigoPlateau_PokemonCenter_1F_Text_SumeetKIntro:
	.string "ECRUTEAK, remember? Fifteen\n"
	.string "years I kept a fire lit within\l"
	.string "sight of the tower that fire\l"
	.string "brought down.\p"
	.string "This one's easier to keep:\n"
	.string "you're not ready for me.$"

IndigoPlateau_PokemonCenter_1F_Text_SumeetKDefeat:
	.string "…Apparently I was wrong about\n"
	.string "that.$"

IndigoPlateau_PokemonCenter_1F_Text_SumeetKPost:
	.string "SUMEET: Go on up. Whatever's\n"
	.string "waiting for you, it isn't us.$"

IndigoPlateau_PokemonCenter_1F_Text_PrabhjitKIntro:
	.string "Migs, it's time to Duel! Again!\n"
	.string "Higher voltage this time!$"

IndigoPlateau_PokemonCenter_1F_Text_PrabhjitKDefeat:
	.string "PHATASE! Still!$"

IndigoPlateau_PokemonCenter_1F_Text_PrabhjitKPost:
	.string "PRABHJIT: Next region, I'll have\n"
	.string "an even bigger amp.$"

@ FACTUAL-CLAIM DISCIPLINE: his line about his own team is checked against his
@ actual roster (Houndoom/Absol/Sableye/Mightyena/Umbreon, src/data/
@ trainers.party) -- Dark-leaning, and his line says so honestly.
IndigoPlateau_PokemonCenter_1F_Text_GurnavIntro:
	.string "You haven't met me yet. GURNAV.\p"
	.string "I'm the newest one -- joined up\n"
	.string "for the KANTO stretch. Somebody\l"
	.string "has to bring the DARK types.\p"
	.string "Introductions are for after.$"

IndigoPlateau_PokemonCenter_1F_Text_GurnavDefeat:
	.string "Good. Now we've actually met.$"

IndigoPlateau_PokemonCenter_1F_Text_GurnavPost:
	.string "GURNAV: HARJOT talks about you\n"
	.string "constantly. Now I understand why.$"

@ M1 mechanic, reused: BOBBY administers the ONE combined reward, once, via
@ MULTI_FAMILY_REWARD -- same list HARJOT/IVRAJ/SUMEET/PRABHJIT's own posts
@ use.
IndigoPlateau_PokemonCenter_1F_Text_BobbyBriefing:
	.string "BOBBY: I'm not fighting you --\n"
	.string "that's not my job today.\p"
	.string "Beat the four of them and\n"
	.string "GURNAV, back to back, and I'll\l"
	.string "have something for you.\p"
	.string "Go on. They're waiting.$"

IndigoPlateau_PokemonCenter_1F_Text_BobbyRewardOffer:
	.string "BOBBY: All five. Nicely done.\p"
	.string "You've earned a reward.\n"
	.string "Choose wisely.$"

IndigoPlateau_PokemonCenter_1F_Text_BobbyPostReward:
	.string "BOBBY: Through that door's a\n"
	.string "league that's beaten people\l"
	.string "twice as ready as you.\p"
	.string "I don't think that's going to\n"
	.string "matter.$"

@ S13b: the farewell. FIX ROUND 1 (review m4): "I told you" was rewritten
@ timeless -- the original wording presumed the player had seen
@ Text_BobbyBriefing's own "not my job today" line, but that branch only
@ fires while the gauntlet is incomplete (a player who clears all five
@ crew fighters before ever talking to BOBBY never sees it), so "I told
@ you" could be false. No conditional added -- rephrased instead, per the
@ simpler of the ruling's two options.
IndigoPlateau_PokemonCenter_1F_Text_BobbyFarewellIntro:
	.string "BOBBY: Wasn't my job, back at the\n"
	.string "gauntlet.\p"
	.string "Today's different. Come on,\n"
	.string "then.$"

IndigoPlateau_PokemonCenter_1F_Text_BobbyFarewellDefeat:
	.string "BOBBY: There it is.$"

IndigoPlateau_PokemonCenter_1F_Text_BobbyFarewellAfter:
	.string "BOBBY: I'll stick around here.\n"
	.string "Somebody's got to run the door.$"

@ ============================================================================
@ WALLY -- last challenger before the E4-II corridor.
@ ============================================================================
IndigoPlateau_PokemonCenter_1F_Text_WallyKIntro:
	.string "WALLY: I told you at the VICTORY\n"
	.string "ROAD gate I'd catch up.\p"
	.string "This is me catching up.$"

IndigoPlateau_PokemonCenter_1F_Text_WallyKDefeat:
	.string "…I'm still not as strong as you.\n"
	.string "But I'm not far off, am I?$"

IndigoPlateau_PokemonCenter_1F_Text_WallyKPost:
	.string "WALLY: Go. I'll be right behind\n"
	.string "you, the way I always am.$"
