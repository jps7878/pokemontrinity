@ ============================================================================
@ M4b S11 -- HALL OF FAME II. The close of Act II.
@
@ UPDATE -- M5a Task 6: the door left open below has been walked through. This
@ room now calls `special GameClearJohto`, a purpose-built clone of GameClear()
@ that does the genuine PC-record append and retargets the continue-warp to
@ HEAL_LOCATION_INDIGO_PLATEAU -- and NOTHING else (no credits, no additional
@ game-clear state; see src/post_battle_event_funcs.c). It still touches
@ FLAG_SYS_GAME_CLEAR the same untouched-semantics way GameClear() always did
@ (already TRUE from Act I), and it still ends in Trinity's silent SoftReset
@ (src/hall_of_fame.c, StartCredits()) -- there is still no credits roll here.
@ The rest of this header is kept as the historical record of why the M4b
@ interim substitute (a plain heal, no real PC record) was chosen, and of
@ exactly which GameClear() behaviour GameClearJohto was built to reproduce.
@
@ THE ORIGINAL DECISION, AND IT WAS A DECISION: THIS WAS A SCENE, NOT
@ `special GameClear`. FLAG_SYS_GAME_CLEAR was neither read nor written here.
@ No soft reset. No credits. Reasoning, from the engine rather than from taste:
@
@ GameClear() (src/post_battle_event_funcs.c:12-86) would do four attractive
@ things and one disqualifying one.
@   + HealPlayerParty().
@   + FLAG_SYS_GAME_CLEAR is ALREADY set from Act I, so the else-branch never
@     runs and the flag's semantics really would be untouched (:23-31).
@   + GAME_STAT_FIRST_HOF_PLAY_TIME is guarded on == 0, so Act I's stamp
@     survives (:33-34).
@   + gHasHallOfFameRecords would be TRUE, so CB2_DoHallOfFameScreen would LOAD
@     the existing Hall of Fame save and APPEND this team to it
@     (src/hall_of_fame.c:483-513) -- a genuine second record on the PC.
@   - and then, unconditionally,
@     SetContinueGameWarpToHealLocation(HEAL_LOCATION_LITTLEROOT_TOWN_*_HOUSE_2F)
@     (:38-41). A HOENN bedroom. The script cannot undo it, because GameClear
@     hands off with SetMainCallback2(CB2_DoHallOfFameScreen) (:84) and never
@     returns -- `waitstate`, the Hall of Fame screen, then Trinity's
@     StartCredits(), which is already SoftReset(RESET_ALL)
@     (src/hall_of_fame.c:778-789). An Act II player's "Continue" would silently
@     become LITTLEROOT.
@
@ M1 could afford that shape because Act I ENDED. Act II hands straight to Act
@ III, and this slice's own staging wants the player standing in the INDIGO
@ Center. Fixing the continue-warp needs a new Trinity special, i.e. a new engine
@ entry point that saves and resets the console, under a gate with no play-tests
@ -- too much risk bought for one cosmetic PC entry. The door is left open: a
@ later milestone that wants the record adds `GameClearJohto` and calls it from
@ this exact script with nothing else changed.
@
@ So the League-2 record is FLAG_TRINITY_J_LEAGUE_CLEARED + arc 10 + the
@ ceremony, and the ceremony still ends on FLDEFF_HALL_OF_FAME_RECORD -- the same
@ field effect M1's Act-I ceremony uses, and the reason this reads as a Hall of
@ Fame at all.
@
@ NOTHING calls EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags. All of
@ that is HOENN's post-game bookkeeping (Southern Island, Mr. Briney, the Beldum,
@ the S.S. Ticket, Steven's house, and a reset of the HOENN Elite Four) and
@ re-running it in Act II would be a straightforward regression.
@
@ THIS ROOM IS A CLOSED BOX. Its single warp (5,12) decodes behaviour byte 0x23
@ -- MB_UNUSED_23 here, MB_ICE in pokefirered -- and neither is a warp behaviour,
@ so it never fires. FRLG walks the player out by script for exactly the same
@ reason. The ON_FRAME guard on SCENE_INDIGO == 5 is therefore the thing that
@ guarantees nobody can ever be stranded in here.
@ ============================================================================

PokemonLeague_HallOfFame_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonLeague_HallOfFame_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_HallOfFame_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_HallOfFame_OnFrame
	.byte 0

@ ============================================================================
@ Trinity M5b S11 fix round 1 (review C1) -- roster-switch flag authoring,
@ added fresh (this map previously had no ON_TRANSITION). Belt-and-braces
@ with the Ceremony script's own runtime showobjectat/hideobjectat below
@ (R1's "redundant but harmless" pattern, same class as removeobject
@ co-signing a hide flag): this ON_TRANSITION is what makes LANCE's/ASH's
@ map.json flag fields (FLAG_TRINITY_K_JOHTO_SITTER_HIDE /
@ FLAG_TRINITY_K_KANTO_CAST_HIDE) correct at spawn time (TrySpawnObjectEvents,
@ state 3), before Ceremony's own runtime call ever runs; Ceremony's call
@ remains the belt that was already independently correct (review: "the only
@ correct one" of the seven original sites) and needs no change.
@ ============================================================================
PokemonLeague_HallOfFame_OnTransition::
	call Trinity_EventScript_CountKantoBadges
	goto_if_ge VAR_TEMP_A, 8, PokemonLeague_HallOfFame_EventScript_ArmKantoCast
	setflag FLAG_TRINITY_K_KANTO_CAST_HIDE
	clearflag FLAG_TRINITY_K_JOHTO_SITTER_HIDE
	end

PokemonLeague_HallOfFame_EventScript_ArmKantoCast::
	clearflag FLAG_TRINITY_K_KANTO_CAST_HIDE
	setflag FLAG_TRINITY_K_JOHTO_SITTER_HIDE
	end

PokemonLeague_HallOfFame_OnWarp:
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_HallOfFame_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_HallOfFame_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

PokemonLeague_HallOfFame_OnFrame:
	map_script_2 VAR_TRINITY_JOHTO_SCENE_INDIGO, 5, PokemonLeague_HallOfFame_EventScript_Ceremony
	.2byte 0

PokemonLeague_HallOfFame_EventScript_Ceremony::
	lockall
	@ Trinity M5b S11 -- roster switch, object layer. Both HoF objects share
	@ the same tile (6,4); without this they would render stacked. Runs
	@ before anything else in this script, and the screen arrives here
	@ already faded to black (both ChampionsRoom defeat scripts fade out
	@ before their `warp` into this room), so there is no visible flash.
	call Trinity_EventScript_CountKantoBadges
	goto_if_ge VAR_TEMP_A, 8, PokemonLeague_HallOfFame_EventScript_ShowAshHof
	showobjectat LOCALID_JOHTO_HOF_LANCE, MAP_POKEMON_LEAGUE_HALL_OF_FAME
	hideobjectat LOCALID_KANTO_HOF_ASH, MAP_POKEMON_LEAGUE_HALL_OF_FAME
	goto PokemonLeague_HallOfFame_EventScript_CeremonyJohto
PokemonLeague_HallOfFame_EventScript_ShowAshHof::
	hideobjectat LOCALID_JOHTO_HOF_LANCE, MAP_POKEMON_LEAGUE_HALL_OF_FAME
	showobjectat LOCALID_KANTO_HOF_ASH, MAP_POKEMON_LEAGUE_HALL_OF_FAME
	goto PokemonLeague_HallOfFame_EventScript_CeremonyKanto
	end

PokemonLeague_HallOfFame_EventScript_CeremonyJohto::
	applymovement LOCALID_PLAYER, PokemonLeague_HallOfFame_Movement_WalkIn
	waitmovement 0
	applymovement LOCALID_JOHTO_HOF_LANCE, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 18
	msgbox PokemonLeague_HallOfFame_Text_LanceCeremony, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JOHTO_HOF_LANCE, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
	delay 40
	msgbox PokemonLeague_HallOfFame_Text_ActIIComplete, MSGBOX_DEFAULT
	closemessage
	call PokemonLeague_HallOfFame_EventScript_RecordTheLeague
	@ M5a Task 6: the interim heal-only substitute (no real PC record, and the
	@ engine continue-warp was never fixed off HOENN -- see the room-header
	@ comment above) is replaced by the real special this room was always
	@ waiting for. One-line revert if GameClearJohto ever needs to be pulled:
	@ call Common_EventScript_OutOfCenterPartyHeal
	special GameClearJohto
	waitstate
	fadescreenspeed FADE_TO_BLACK, 24
	warp MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F, 0
	waitstate
	releaseall
	end

@ ============================================================================
@ Trinity M5b S11 -- HALL OF FAME III. THE TRUE ENDING.
@
@ special GameClearKanto is already fully built (src/post_battle_event_funcs.c,
@ M5a Task 6) -- SetHallOfFameTrueGameClear() is the one-shot latch StartCredits()
@ (src/hall_of_fame.c) checks to roll the real credits (CB2_StartCreditsSequence)
@ instead of Act I/II's silent SoftReset. This call site is the ONLY reachable
@ path to it (sub-plan §6.1) -- so src/credits.c/data/credits.h needed no
@ branching logic of its own, just new content.
@
@ FLAG_TRINITY_K_LEAGUE_CLEARED is NOT allocated -- the economy itself stands
@ (fix round 1, review C3: zero readers anywhere need a Kanto-clear predicate
@ this slice), but the ORIGINAL justification for it was FALSE and is
@ corrected here rather than repeated. FLAG_IS_CHAMPION is NOT a "this save
@ has reached Kanto's true ending" signal -- it has been TRUE since ACT I:
@ EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags (data/scripts/
@ hall_of_fame.inc:1-3) sets it at the HOENN Hall of Fame, hundreds of hours
@ before Act III even exists on a Trinity save. GameClearJohto
@ (src/post_battle_event_funcs.c) does NOT set it; GameClearKanto (:272)
@ merely re-sets it idempotently, the same way it always has been since Act I.
@ Its only tree-wide readers (src/link.c:323, src/link_rfu_3.c:679, national
@ link-cable compatibility; src/caps.c, EV/level caps) carry no Kanto
@ semantics at all.
@
@ WARNING FOR S12/S13: FLAG_IS_CHAMPION is NOT a Kanto-clear predicate. Do
@ NOT read it to gate anything post-game. The real, correct, and already-
@ wired signal is VAR_TRINITY_KANTO_ARC >= 6 (this slice's own arc write,
@ monotonic-guarded, one writer -- PokemonLeague_HallOfFame_EventScript_
@ RecordTheKantoLeague below) -- CeruleanCity_OnTransition already uses
@ exactly this idiom (`goto_if_ge VAR_TRINITY_KANTO_ARC, 6, ...`) for an
@ unrelated Kanto-clear gate, proving the arc is the tree's own established
@ answer to "has this save finished Kanto," not FLAG_IS_CHAMPION. If a future
@ slice genuinely needs a dedicated flag instead of an arc comparison, one
@ must be freshly hex-audited -- the 0x4E9-0x4EF run this slice's registry
@ used is fully spent, and the roster-switch fix (see C1 above and
@ FLAG_TRINITY_K_JOHTO_SITTER_HIDE/FLAG_TRINITY_K_KANTO_CAST_HIDE,
@ include/constants/flags.h) has now also spent 0x1DE/0x1DF.
@ ============================================================================
PokemonLeague_HallOfFame_EventScript_CeremonyKanto::
	applymovement LOCALID_PLAYER, PokemonLeague_HallOfFame_Movement_WalkIn
	waitmovement 0
	applymovement LOCALID_KANTO_HOF_ASH, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 18
	msgbox PokemonLeague_HallOfFame_Text_AshCeremony, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_KANTO_HOF_ASH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
	delay 40
	msgbox PokemonLeague_HallOfFame_Text_ActIIIComplete, MSGBOX_DEFAULT
	closemessage
	call PokemonLeague_HallOfFame_EventScript_RecordTheKantoLeague
	special GameClearKanto
	waitstate
	fadescreenspeed FADE_TO_BLACK, 24
	warp MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F, 0
	waitstate
	releaseall
	end

@ Same shape as RecordTheLeague below, minus a terminal setflag (GameClearKanto,
@ called immediately after this returns, already sets FLAG_IS_CHAMPION
@ natively -- see the header comment above). State write first (S4's I3(b)
@ ordering hazard), arc write behind the monotonic guard, VAR_TRINITY_KANTO_ARC
@ -> 6, the ONE writer of that value.
PokemonLeague_HallOfFame_EventScript_RecordTheKantoLeague::
	goto_if_ge VAR_TRINITY_KANTO_ARC, 6, PokemonLeague_HallOfFame_EventScript_KantoArcAlreadySet
	setvar VAR_TRINITY_KANTO_ARC, 6
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU
	return

PokemonLeague_HallOfFame_EventScript_KantoArcAlreadySet::
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU
	return

@ GSC HallOfFame_LanceText's own shape, kept: ASH leads the new CHAMPION in
@ and reads the dedication. PIKACHU is on his shoulder, exactly as it was
@ in the ChampionsRoom -- ASH never returns it to a POKé BALL to walk in here.
PokemonLeague_HallOfFame_Text_AshCeremony:
	.string "ASH: PIKACHU and I have stood in\n"
	.string "here more times than I can\l"
	.string "count, watching somebody else get\l"
	.string "the record book.\p"
	.string "This is where we induct LEAGUE\n"
	.string "CHAMPIONS. Their partners are\l"
	.string "recorded with them.\p"
	.string "Today we record a trainer who\n"
	.string "crossed three regions that were\l"
	.string "never home, and never once asked\l"
	.string "what the job would pay before\l"
	.string "finishing it.\p"
	.string "{PLAYER}, allow me and PIKACHU to\n"
	.string "register you and your team.$"

@ THE TRUE ENDING. HOENN, JOHTO, KANTO -- the trilogy closes here. Mt. Silver
@ hint: text-only tease (S11 sub-plan §6.3), no map, no mechanical promise.
@ FIX (S14 final-review F2): this comment previously said TRAINER_RED was
@ "deliberately NOT wired to anything this slice -- forward-hook for a
@ later milestone." Stale -- S12 wired him for real, at
@ SilverCaveRoom3/scripts.inc:37 (arc>=7 gated, per the arc-spine census).
@ This text is the tease pointing at that fight, not an unfulfilled hook.
PokemonLeague_HallOfFame_Text_ActIIIComplete:
	.string "Three leagues.\p"
	.string "HOENN. JOHTO. And now KANTO --\n"
	.string "and the board on the wall has\l"
	.string "run out of room to write more\l"
	.string "names under yours.\p"
	.string "Somewhere north of here there's a\n"
	.string "mountain that doesn't have a gym,\l"
	.string "a LEAGUE, or a reason for anybody\l"
	.string "to climb it.\p"
	.string "People still do. They say there's\n"
	.string "someone at the top who hasn't\l"
	.string "lost since before this record\l"
	.string "book existed.\p"
	.string "MT. SILVER.\p"
	.string "Not today. Today, this is enough.\p"
	.string "Three regions. Three leagues.\n"
	.string "One journey, finished.\p"
	.string "Congratulations, CHAMPION.$"

@ The durable half. State writes first (S4's I3(b) ordering hazard), the arc
@ write behind S1's monotonic guard, and the respawn set to the PLATEAU so the
@ post-league player wakes up where they finished rather than in HOENN.
@ FLAG_TRINITY_J_LEAGUE_CLEARED is the act's TERMINAL state and is never cleared
@ by anything -- the five FLAG_TRINITY_J_E4_*_BEATEN flags are cleared on every
@ INDIGO Center visit, so they cannot carry it (S6's cleared-flag rule).
PokemonLeague_HallOfFame_EventScript_RecordTheLeague::
	setflag FLAG_TRINITY_J_LEAGUE_CLEARED
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 10, PokemonLeague_HallOfFame_EventScript_ArcAlreadySet
	setvar VAR_TRINITY_JOHTO_ARC, 10
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU
	return

PokemonLeague_HallOfFame_EventScript_ArcAlreadySet::
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU
	return

@ (5,12) landing -> (5,4), beside LANCE at (6,4).
PokemonLeague_HallOfFame_Movement_WalkIn:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ GSC HallOfFame_LanceText, adapted -- in GSC it is LANCE who leads the new
@ CHAMPION into this room and reads the dedication, and Trinity keeps him in that
@ job because PROF. OAK and MARY do not exist in Act II.
PokemonLeague_HallOfFame_Text_LanceCeremony:
	.string "LANCE: It's been a long time\n"
	.string "since I last came in here.\p"
	.string "This is where we honor the LEAGUE\n"
	.string "CHAMPIONS. Their courageous\l"
	.string "POKéMON are inducted with them.\p"
	.string "Today we record a trainer who\n"
	.string "came to a region that was not\l"
	.string "home, walked into every fight it\l"
	.string "had, and did not once ask what\l"
	.string "the job would pay for it.\p"
	.string "{PLAYER}, allow me to register\n"
	.string "you and your partners.$"

@ THE ACT II CLOSE. M1's reframe pattern (EverGrandeCity_HallOfFame's
@ Text_ActIComplete): name the league, name the act, hand to the next one, and
@ do NOT roll credits -- the true ending belongs to the final KANTO victory,
@ which is what src/hall_of_fame.c's StartCredits comment already says.
PokemonLeague_HallOfFame_Text_ActIIComplete:
	.string "Two leagues.\p"
	.string "HOENN, and now JOHTO -- and the\n"
	.string "board on the wall has room for\l"
	.string "one more name.\p"
	.string "Somewhere east of here a man is\n"
	.string "already home, unpacking, certain\l"
	.string "that a border is a wall.\p"
	.string "Act II of your journey is\n"
	.string "complete…\p"
	.string "To be continued in Act III --\n"
	.string "KANTO.$"
