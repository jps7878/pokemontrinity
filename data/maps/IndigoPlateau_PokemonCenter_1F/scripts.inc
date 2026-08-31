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
	map_script MAP_SCRIPT_ON_LOAD, IndigoPlateau_PokemonCenter_1F_OnLoad
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
	end

@ ============================================================================
@ Trinity M5b S11 -- the INDIGO II LOBBY. THE ROSTER SWITCH, object layer.
@
@ This room's own (4,1) warp goes straight into PokemonLeague_LoreleisRoom --
@ it is the league's real front door, not a metaphorical "lobby" (S11 sub-plan
@ §3.1). Below 8 KANTO badges this ON_LOAD is a no-op past the live count
@ (every one of the 7 objects below stays at its map.json-default visible
@ state, which is FALSE/hidden -- wait, no: flag:"0" objects default VISIBLE,
@ so the hide call below is what keeps this room byte-for-byte what M4
@ shipped for any save that hasn't finished KANTO -- confirmed by CHECKING,
@ not assuming: SetObjectInvisibility (src/scrcmd.c:1458-1477) is called
@ fresh every load here, unconditionally, before the first frame renders
@ (MAP_SCRIPT_ON_LOAD runs pre-render), so there is no visible flash and no
@ save-file dependency on the objects' own static template state.
@
@ ZERO PERSISTENT FLAGS for this switch (S11 sub-plan §0 point 2):
@ SetObjectInvisibility is SCREFF_HARDWARE only, no SCREFF_SAVE -- it mutates
@ the live object-event instance, not SaveBlock. Re-deriving live off
@ Trinity_EventScript_CountKantoBadges every load is strictly correct, not a
@ shortcut, because the underlying truth (8 badges or not) is itself already
@ persistent in FLAG_TRINITY_BADGE17..24.
@ ============================================================================
IndigoPlateau_PokemonCenter_1F_OnLoad:
	call Trinity_EventScript_CountKantoBadges
	goto_if_ge VAR_TEMP_A, 8, IndigoPlateau_PokemonCenter_1F_EventScript_ShowGauntletCast
	hideobjectat LOCALID_KANTO_INDIGO_BOBBY, MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F
	hideobjectat LOCALID_KANTO_INDIGO_HARJOT, MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F
	hideobjectat LOCALID_KANTO_INDIGO_IVRAJ, MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F
	hideobjectat LOCALID_KANTO_INDIGO_SUMEET, MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F
	hideobjectat LOCALID_KANTO_INDIGO_PRABHJIT, MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F
	hideobjectat LOCALID_KANTO_INDIGO_GURNAV, MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F
	hideobjectat LOCALID_KANTO_INDIGO_WALLY, MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F
	end

IndigoPlateau_PokemonCenter_1F_EventScript_ShowGauntletCast::
	showobjectat LOCALID_KANTO_INDIGO_BOBBY, MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F
	showobjectat LOCALID_KANTO_INDIGO_HARJOT, MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F
	showobjectat LOCALID_KANTO_INDIGO_IVRAJ, MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F
	showobjectat LOCALID_KANTO_INDIGO_SUMEET, MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F
	showobjectat LOCALID_KANTO_INDIGO_PRABHJIT, MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F
	showobjectat LOCALID_KANTO_INDIGO_GURNAV, MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F
	showobjectat LOCALID_KANTO_INDIGO_WALLY, MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F
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
@ "Full heal between": special HealPlayerParty runs in every fighter's own
@ post-battle handler -- on the first win AND on every later re-approach
@ (harmless no-op on an already-full party).
@ ============================================================================
IndigoPlateau_PokemonCenter_1F_EventScript_HarjotK::
	trainerbattle_single TRAINER_HARJOT_K, IndigoPlateau_PokemonCenter_1F_Text_HarjotKIntro, IndigoPlateau_PokemonCenter_1F_Text_HarjotKDefeat, IndigoPlateau_PokemonCenter_1F_EventScript_HarjotKAfter
	goto IndigoPlateau_PokemonCenter_1F_EventScript_HarjotKAfter
	end

IndigoPlateau_PokemonCenter_1F_EventScript_HarjotKAfter::
	special HealPlayerParty
	msgbox IndigoPlateau_PokemonCenter_1F_Text_HarjotKPost, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_IvrajK::
	trainerbattle_single TRAINER_IVRAJ_K, IndigoPlateau_PokemonCenter_1F_Text_IvrajKIntro, IndigoPlateau_PokemonCenter_1F_Text_IvrajKDefeat, IndigoPlateau_PokemonCenter_1F_EventScript_IvrajKAfter
	goto IndigoPlateau_PokemonCenter_1F_EventScript_IvrajKAfter
	end

IndigoPlateau_PokemonCenter_1F_EventScript_IvrajKAfter::
	special HealPlayerParty
	msgbox IndigoPlateau_PokemonCenter_1F_Text_IvrajKPost, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_SumeetK::
	trainerbattle_single TRAINER_SUMEET_K, IndigoPlateau_PokemonCenter_1F_Text_SumeetKIntro, IndigoPlateau_PokemonCenter_1F_Text_SumeetKDefeat, IndigoPlateau_PokemonCenter_1F_EventScript_SumeetKAfter
	goto IndigoPlateau_PokemonCenter_1F_EventScript_SumeetKAfter
	end

IndigoPlateau_PokemonCenter_1F_EventScript_SumeetKAfter::
	special HealPlayerParty
	msgbox IndigoPlateau_PokemonCenter_1F_Text_SumeetKPost, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_PrabhjitK::
	trainerbattle_single TRAINER_PRABHJIT_K, IndigoPlateau_PokemonCenter_1F_Text_PrabhjitKIntro, IndigoPlateau_PokemonCenter_1F_Text_PrabhjitKDefeat, IndigoPlateau_PokemonCenter_1F_EventScript_PrabhjitKAfter
	goto IndigoPlateau_PokemonCenter_1F_EventScript_PrabhjitKAfter
	end

IndigoPlateau_PokemonCenter_1F_EventScript_PrabhjitKAfter::
	special HealPlayerParty
	msgbox IndigoPlateau_PokemonCenter_1F_Text_PrabhjitKPost, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Gurnav::
	trainerbattle_single TRAINER_GURNAV, IndigoPlateau_PokemonCenter_1F_Text_GurnavIntro, IndigoPlateau_PokemonCenter_1F_Text_GurnavDefeat, IndigoPlateau_PokemonCenter_1F_EventScript_GurnavAfter
	goto IndigoPlateau_PokemonCenter_1F_EventScript_GurnavAfter
	end

IndigoPlateau_PokemonCenter_1F_EventScript_GurnavAfter::
	special HealPlayerParty
	msgbox IndigoPlateau_PokemonCenter_1F_Text_GurnavPost, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ BOBBY -- hosts, briefs, does NOT fight (brief item 4; his own farewell
@ battle is S13's, TRAINER_BOBBY stays unfought and unconsumed this slice).
@ His own script administers the ONE reward: 5x checktrainerflag, the exact
@ idiom Trinity_EventScript_CountKantoBadges already uses one level up
@ (call_if_set-per-flag -> here, goto_if FALSE-per-trainer), gated on
@ FLAG_TRINITY_K_GAUNTLET_REWARD for the claimed-once guard.
@ ============================================================================
IndigoPlateau_PokemonCenter_1F_EventScript_Bobby::
	lock
	faceplayer
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

IndigoPlateau_PokemonCenter_1F_EventScript_BobbyBriefing::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_BobbyBriefing, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_BobbyClaimed::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_BobbyPostReward, MSGBOX_DEFAULT
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
@ ============================================================================
IndigoPlateau_PokemonCenter_1F_EventScript_WallyK::
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
	.string "years I kept a secret up a tower.\p"
	.string "This one I'm keeping is just:\n"
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
	.string "I joined this lot partway through\n"
	.string "JOHTO -- somebody has to bring\l"
	.string "the DARK types.\p"
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
