@ ============================================================================
@ Trinity M5b S9 -- CINNABAR GYM. BLAINE, BADGE23, TM38.
@
@ Quiz doors: trivially portable, built (sub-plan section 7). FRLG's own shape
@ (~/decomps/pokefirered/data/maps/CinnabarIsland_Gym/scripts.inc, read in full):
@ six rooms, each gated on its own quiz-door flag. FRLG's own FLAG_CINNABAR_
@ GYM_QUIZ_N does NOT exist in this tree (pokeemerald-expansion carries no
@ FRLG-specific flags at all -- confirmed by grep across flags.h, zero hits for
@ FLAG_CINNABAR_*/FLAG_POKEMON_MANSION_*/FLAG_STOPPED_SEAFOAM_*/FLAG_HIDE_
@ SEAFOAM_*), so six fresh Trinity flags were claimed instead:
@ FLAG_TRINITY_K_BLAINE_QUIZ_1..6 (0x4DA-0x4DF). A sign pair asks a
@ YES/NO trivia question; correct answer opens the door (setmetatile); wrong
@ answer fights that room's named trainer (trainerbattle_no_intro, guarded by
@ goto_if_not_defeated so a beaten trainer is never refought -- one-fight-per-id);
@ winning that fight ALSO opens the door. Doors persist across reloads via
@ OnLoad re-applying every already-solved door's setmetatile set (session-RAM
@ edits, not saved -- required, not decoration, matching FRLG's own OnLoad shape).
@
@ Simplification, logged: FRLG's approach-walk flourish (player+trainer both take
@ a couple of scripted steps before the battle) is dropped -- it needs named
@ LOCALID_* object references this map.json doesn't carry, and adds no
@ mechanical value. Battles start directly from the standing position.
@
@ Metatile IDs: this Kanto tileset carries no symbolic METATILE_CinnabarGym_*
@ constants (grepped, zero hits -- unlike Hoenn's authored tilesets, Kanto's
@ ported tilesets use raw IDs, matching the established precedent in
@ VermilionCity_Gym/scripts.inc and RocketHideout_B4F/scripts.inc). Values below
@ are FRLG's own METATILE_CinnabarGym_* constants (metatile_labels.h), confirmed
@ transferable: FRLG's METATILE_VermilionGym_Floor and METATILE_CinnabarGym_Floor
@ are BOTH 0x281 (the 8 Kanto gym tilesets share one authoring template, semantic
@ tile at the same relative offset across all of them) -- and Trinity's own
@ CinnabarIsland_Gym map.bin already reads 0x289 (ShadeFull) at (26,10)/(27,10)/
@ (28,10), matching FRLG's own OpenDoor1 target for that row exactly, confirmed
@ by direct query, not assumed. Floor=0x281 ShadeDiagonal=0x282 ShadeFull=0x289
@ WallLeftCorner=0x2C7 WallLeftEdge=0x2CF WallRightCorner=0x2C6 WallRightEdge=0x2CE
@ Wall_RetractedBarrier=0x2D1.
@ ============================================================================

CinnabarIsland_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CinnabarIsland_Gym_OnLoad
	.byte 0

CinnabarIsland_Gym_OnLoad::
	goto_if_set FLAG_TRINITY_BADGE23, CinnabarIsland_Gym_OnLoadOpenAllDoors
	call_if_set FLAG_TRINITY_K_BLAINE_QUIZ_1, CinnabarIsland_Gym_EventScript_OpenDoor1
	call_if_set FLAG_TRINITY_K_BLAINE_QUIZ_2, CinnabarIsland_Gym_EventScript_OpenDoor2
	call_if_set FLAG_TRINITY_K_BLAINE_QUIZ_3, CinnabarIsland_Gym_EventScript_OpenDoor3
	call_if_set FLAG_TRINITY_K_BLAINE_QUIZ_4, CinnabarIsland_Gym_EventScript_OpenDoor4
	call_if_set FLAG_TRINITY_K_BLAINE_QUIZ_5, CinnabarIsland_Gym_EventScript_OpenDoor5
	call_if_set FLAG_TRINITY_K_BLAINE_QUIZ_6, CinnabarIsland_Gym_EventScript_OpenDoor6
	end

CinnabarIsland_Gym_OnLoadOpenAllDoors::
	call CinnabarIsland_Gym_EventScript_OpenDoor1
	call CinnabarIsland_Gym_EventScript_OpenDoor2
	call CinnabarIsland_Gym_EventScript_OpenDoor3
	call CinnabarIsland_Gym_EventScript_OpenDoor4
	call CinnabarIsland_Gym_EventScript_OpenDoor5
	call CinnabarIsland_Gym_EventScript_OpenDoor6
	end

@ ============================================================================
@ BLAINE. G1-G7 pattern verbatim. FRLG position (5,4) decoded col0/elev3/
@ MB_NORMAL -- dry, matches.
@ ============================================================================
@ Trinity M5b S9 fix round (review I5): badge-award flow reshaped to the
@ exact shipped Pewter pattern (PewterCity_Gym_EventScript_Brock/
@ BrockDefeated/GiveTM37) rather than the first pass's own ad hoc shape.
CinnabarIsland_Gym_EventScript_Blaine::
	trainerbattle_single TRAINER_BLAINE, CinnabarIsland_Gym_Text_BlaineIntro, CinnabarIsland_Gym_Text_BlaineDefeat, CinnabarIsland_Gym_EventScript_BlaineDefeated, NO_MUSIC
	goto_if_unset FLAG_TRINITY_K_BLAINE_TM38, CinnabarIsland_Gym_EventScript_GiveTM38
	msgbox CinnabarIsland_Gym_Text_BlainePostBattle, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_Gym_EventScript_BlaineDefeated::
	message CinnabarIsland_Gym_Text_ReceivedVolcanoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_TRINITY_BADGE23
	msgbox CinnabarIsland_Gym_Text_ExplainVolcanoBadge, MSGBOX_DEFAULT
	goto CinnabarIsland_Gym_EventScript_GiveTM38
	end

CinnabarIsland_Gym_EventScript_GiveTM38::
	giveitem ITEM_TM38
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_K_BLAINE_TM38
	msgbox CinnabarIsland_Gym_Text_FireBlastIsUltimateFireMove, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ Statues, GymGuy.
@ ============================================================================
@ Trinity M5b S9 fix round (review I5): statue text re-shaped to the Trinity
@ epithet form the other five (six, counting Sabrina) already-shipped Kanto
@ leaders use ("LEADER: X\pThe ___$", e.g. Brock "The Rock-Solid Trainer,"
@ Misty "The Tomboyish Mermaid," Surge "The Lightning American," Erika "The
@ Nature-Loving Trainer," Sabrina "The Master of Psychic Pokémon," Janine
@ "Master of Poison POKéMON") -- the first pass instead invented a
@ "WINNING TRAINERS: none yet." tracker matching FRLG's own real statue text
@ but NOT this milestone's own established convention. Blaine's epithet,
@ "The Fire-and-Brimstone Trainer," is his real canonical title (same
@ register as the other five/six). Post-badge branch and label name
@ (`GymStatueCertified`, `MSGBOX_DEFAULT`) also matched to the sibling shape
@ exactly (`PewterCity_Gym_EventScript_GymStatueCertified`).
CinnabarIsland_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_TRINITY_BADGE23, CinnabarIsland_Gym_EventScript_GymStatueCertified
	msgbox CinnabarIsland_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

CinnabarIsland_Gym_EventScript_GymStatue_2::
	lockall
	goto_if_set FLAG_TRINITY_BADGE23, CinnabarIsland_Gym_EventScript_GymStatueCertified
	msgbox CinnabarIsland_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

CinnabarIsland_Gym_EventScript_GymStatueCertified::
	msgbox CinnabarIsland_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

CinnabarIsland_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_BADGE23, CinnabarIsland_Gym_EventScript_GymGuyPostVictory
	msgbox CinnabarIsland_Gym_Text_GymGuyAdvice, MSGBOX_DEFAULT
	release
	end

@ M7b Task 15 (finding #6): the guide states the player's LIVE badge count.
@ The tally reads the flags and buffers the number itself -- see
@ data/scripts/trinity_kanto.inc.
CinnabarIsland_Gym_EventScript_GymGuyPostVictory::
	msgbox CinnabarIsland_Gym_Text_GymGuyPostVictory, MSGBOX_DEFAULT
	call Trinity_EventScript_KantoBadgeTally
	@ M7b Task 14 (finding #9): once the badge is won this guide doubles as
	@ a pointer. The branch above is already the badge flag, so nothing new
	@ is read or written here; the ladder releases for us.
	goto Trinity_EventScript_KantoGuide
	end

@ ============================================================================
@ The seven named trainers. ERIK carries no quiz door -- a standalone encounter,
@ matching FRLG's own roster (7 trainers, 6 doors).
@ ============================================================================
CinnabarIsland_Gym_EventScript_Erik::
	trainerbattle_single TRAINER_KANTO_SUPER_NERD_ERIK, CinnabarIsland_Gym_Text_ErikSeen, CinnabarIsland_Gym_Text_ErikBeaten
	end

CinnabarIsland_Gym_EventScript_Quinn::
	trainerbattle_single TRAINER_KANTO_BURGLAR_QUINN, CinnabarIsland_Gym_Text_QuinnSeen, CinnabarIsland_Gym_Text_QuinnBeaten, CinnabarIsland_Gym_EventScript_DefeatedQuinn
	end

CinnabarIsland_Gym_EventScript_DefeatedQuinn::
	call_if_unset FLAG_TRINITY_K_BLAINE_QUIZ_1, CinnabarIsland_Gym_EventScript_Quiz1Complete
	release
	end

CinnabarIsland_Gym_EventScript_Avery::
	trainerbattle_single TRAINER_KANTO_SUPER_NERD_AVERY, CinnabarIsland_Gym_Text_AverySeen, CinnabarIsland_Gym_Text_AveryBeaten, CinnabarIsland_Gym_EventScript_DefeatedAvery
	end

CinnabarIsland_Gym_EventScript_DefeatedAvery::
	call_if_unset FLAG_TRINITY_K_BLAINE_QUIZ_2, CinnabarIsland_Gym_EventScript_Quiz2Complete
	release
	end

CinnabarIsland_Gym_EventScript_Ramon::
	trainerbattle_single TRAINER_KANTO_BURGLAR_RAMON, CinnabarIsland_Gym_Text_RamonSeen, CinnabarIsland_Gym_Text_RamonBeaten, CinnabarIsland_Gym_EventScript_DefeatedRamon
	end

CinnabarIsland_Gym_EventScript_DefeatedRamon::
	call_if_unset FLAG_TRINITY_K_BLAINE_QUIZ_3, CinnabarIsland_Gym_EventScript_Quiz3Complete
	release
	end

CinnabarIsland_Gym_EventScript_Derek::
	trainerbattle_single TRAINER_KANTO_SUPER_NERD_DEREK, CinnabarIsland_Gym_Text_DerekSeen, CinnabarIsland_Gym_Text_DerekBeaten, CinnabarIsland_Gym_EventScript_DefeatedDerek
	end

CinnabarIsland_Gym_EventScript_DefeatedDerek::
	call_if_unset FLAG_TRINITY_K_BLAINE_QUIZ_4, CinnabarIsland_Gym_EventScript_Quiz4Complete
	release
	end

CinnabarIsland_Gym_EventScript_Dusty::
	trainerbattle_single TRAINER_KANTO_BURGLAR_DUSTY, CinnabarIsland_Gym_Text_DustySeen, CinnabarIsland_Gym_Text_DustyBeaten, CinnabarIsland_Gym_EventScript_DefeatedDusty
	end

CinnabarIsland_Gym_EventScript_DefeatedDusty::
	call_if_unset FLAG_TRINITY_K_BLAINE_QUIZ_5, CinnabarIsland_Gym_EventScript_Quiz5Complete
	release
	end

CinnabarIsland_Gym_EventScript_Zac::
	trainerbattle_single TRAINER_KANTO_SUPER_NERD_ZAC, CinnabarIsland_Gym_Text_ZacSeen, CinnabarIsland_Gym_Text_ZacBeaten, CinnabarIsland_Gym_EventScript_DefeatedZac
	end

CinnabarIsland_Gym_EventScript_DefeatedZac::
	call_if_unset FLAG_TRINITY_K_BLAINE_QUIZ_6, CinnabarIsland_Gym_EventScript_Quiz6Complete
	release
	end

@ ============================================================================
@ Shared quiz plumbing.
@ ============================================================================
CinnabarIsland_Gym_EventScript_CorrectAnswer::
	playfanfare MUS_LEVEL_UP
	waitfanfare
	msgbox CinnabarIsland_Gym_Text_CorrectGoOnThrough, MSGBOX_DEFAULT
	return

CinnabarIsland_Gym_EventScript_IncorrectAnswer::
	waitse
	playse SE_BOO
	waitse
	msgbox CinnabarIsland_Gym_Text_SorryBadCall, MSGBOX_DEFAULT
	closemessage
	return

CinnabarIsland_Gym_EventScript_DoorAlreadyOpen::
	releaseall
	end

@ ---- Room 1 (Quinn) ----
CinnabarIsland_Gym_EventScript_Quiz1Left::
	lockall
	msgbox CinnabarIsland_Gym_Text_PokemonQuizRules, MSGBOX_DEFAULT
	msgbox CinnabarIsland_Gym_Text_QuizQuestion1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CinnabarIsland_Gym_EventScript_Quiz1Correct
	goto CinnabarIsland_Gym_EventScript_Quiz1Incorrect
	end

CinnabarIsland_Gym_EventScript_Quiz1Right::
	goto CinnabarIsland_Gym_EventScript_Quiz1Left
	end

CinnabarIsland_Gym_EventScript_Quiz1Correct::
	call CinnabarIsland_Gym_EventScript_CorrectAnswer
	goto_if_set FLAG_TRINITY_K_BLAINE_QUIZ_1, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz1Complete
	releaseall
	end

CinnabarIsland_Gym_EventScript_Quiz1Complete::
	playse SE_UNLOCK
	waitse
	call CinnabarIsland_Gym_EventScript_OpenDoor1
	special DrawWholeMapView
	setflag FLAG_TRINITY_K_BLAINE_QUIZ_1
	return

CinnabarIsland_Gym_EventScript_Quiz1Incorrect::
	call CinnabarIsland_Gym_EventScript_IncorrectAnswer
	goto_if_not_defeated TRAINER_KANTO_BURGLAR_QUINN, CinnabarIsland_Gym_EventScript_BattleQuinn
	releaseall
	end

CinnabarIsland_Gym_EventScript_BattleQuinn::
	trainerbattle_no_intro TRAINER_KANTO_BURGLAR_QUINN, CinnabarIsland_Gym_Text_QuinnBeaten
	goto_if_set FLAG_TRINITY_K_BLAINE_QUIZ_1, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz1Complete
	releaseall
	end

@ ---- Room 2 (Avery) ----
CinnabarIsland_Gym_EventScript_Quiz2Left::
	lockall
	msgbox CinnabarIsland_Gym_Text_PokemonQuizRules, MSGBOX_DEFAULT
	msgbox CinnabarIsland_Gym_Text_QuizQuestion2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_Gym_EventScript_Quiz2Correct
	goto CinnabarIsland_Gym_EventScript_Quiz2Incorrect
	end

CinnabarIsland_Gym_EventScript_Quiz2Right::
	goto CinnabarIsland_Gym_EventScript_Quiz2Left
	end

CinnabarIsland_Gym_EventScript_Quiz2Correct::
	call CinnabarIsland_Gym_EventScript_CorrectAnswer
	goto_if_set FLAG_TRINITY_K_BLAINE_QUIZ_2, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz2Complete
	releaseall
	end

CinnabarIsland_Gym_EventScript_Quiz2Complete::
	playse SE_UNLOCK
	waitse
	call CinnabarIsland_Gym_EventScript_OpenDoor2
	special DrawWholeMapView
	setflag FLAG_TRINITY_K_BLAINE_QUIZ_2
	return

CinnabarIsland_Gym_EventScript_Quiz2Incorrect::
	call CinnabarIsland_Gym_EventScript_IncorrectAnswer
	goto_if_not_defeated TRAINER_KANTO_SUPER_NERD_AVERY, CinnabarIsland_Gym_EventScript_BattleAvery
	releaseall
	end

CinnabarIsland_Gym_EventScript_BattleAvery::
	trainerbattle_no_intro TRAINER_KANTO_SUPER_NERD_AVERY, CinnabarIsland_Gym_Text_AveryBeaten
	goto_if_set FLAG_TRINITY_K_BLAINE_QUIZ_2, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz2Complete
	releaseall
	end

@ ---- Room 3 (Ramon) ----
CinnabarIsland_Gym_EventScript_Quiz3Left::
	lockall
	msgbox CinnabarIsland_Gym_Text_PokemonQuizRules, MSGBOX_DEFAULT
	msgbox CinnabarIsland_Gym_Text_QuizQuestion3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_Gym_EventScript_Quiz3Correct
	goto CinnabarIsland_Gym_EventScript_Quiz3Incorrect
	end

CinnabarIsland_Gym_EventScript_Quiz3Right::
	goto CinnabarIsland_Gym_EventScript_Quiz3Left
	end

CinnabarIsland_Gym_EventScript_Quiz3Correct::
	call CinnabarIsland_Gym_EventScript_CorrectAnswer
	goto_if_set FLAG_TRINITY_K_BLAINE_QUIZ_3, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz3Complete
	releaseall
	end

CinnabarIsland_Gym_EventScript_Quiz3Complete::
	playse SE_UNLOCK
	waitse
	call CinnabarIsland_Gym_EventScript_OpenDoor3
	special DrawWholeMapView
	setflag FLAG_TRINITY_K_BLAINE_QUIZ_3
	return

CinnabarIsland_Gym_EventScript_Quiz3Incorrect::
	call CinnabarIsland_Gym_EventScript_IncorrectAnswer
	goto_if_not_defeated TRAINER_KANTO_BURGLAR_RAMON, CinnabarIsland_Gym_EventScript_BattleRamon
	releaseall
	end

CinnabarIsland_Gym_EventScript_BattleRamon::
	trainerbattle_no_intro TRAINER_KANTO_BURGLAR_RAMON, CinnabarIsland_Gym_Text_RamonBeaten
	goto_if_set FLAG_TRINITY_K_BLAINE_QUIZ_3, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz3Complete
	releaseall
	end

@ ---- Room 4 (Derek) ----
CinnabarIsland_Gym_EventScript_Quiz4Left::
	lockall
	msgbox CinnabarIsland_Gym_Text_PokemonQuizRules, MSGBOX_DEFAULT
	msgbox CinnabarIsland_Gym_Text_QuizQuestion4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_Gym_EventScript_Quiz4Correct
	goto CinnabarIsland_Gym_EventScript_Quiz4Incorrect
	end

CinnabarIsland_Gym_EventScript_Quiz4Right::
	goto CinnabarIsland_Gym_EventScript_Quiz4Left
	end

CinnabarIsland_Gym_EventScript_Quiz4Correct::
	call CinnabarIsland_Gym_EventScript_CorrectAnswer
	goto_if_set FLAG_TRINITY_K_BLAINE_QUIZ_4, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz4Complete
	releaseall
	end

CinnabarIsland_Gym_EventScript_Quiz4Complete::
	playse SE_UNLOCK
	waitse
	call CinnabarIsland_Gym_EventScript_OpenDoor4
	special DrawWholeMapView
	setflag FLAG_TRINITY_K_BLAINE_QUIZ_4
	return

CinnabarIsland_Gym_EventScript_Quiz4Incorrect::
	call CinnabarIsland_Gym_EventScript_IncorrectAnswer
	goto_if_not_defeated TRAINER_KANTO_SUPER_NERD_DEREK, CinnabarIsland_Gym_EventScript_BattleDerek
	releaseall
	end

CinnabarIsland_Gym_EventScript_BattleDerek::
	trainerbattle_no_intro TRAINER_KANTO_SUPER_NERD_DEREK, CinnabarIsland_Gym_Text_DerekBeaten
	goto_if_set FLAG_TRINITY_K_BLAINE_QUIZ_4, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz4Complete
	releaseall
	end

@ ---- Room 5 (Dusty) ----
CinnabarIsland_Gym_EventScript_Quiz5Left::
	lockall
	msgbox CinnabarIsland_Gym_Text_PokemonQuizRules, MSGBOX_DEFAULT
	msgbox CinnabarIsland_Gym_Text_QuizQuestion5, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CinnabarIsland_Gym_EventScript_Quiz5Correct
	goto CinnabarIsland_Gym_EventScript_Quiz5Incorrect
	end

CinnabarIsland_Gym_EventScript_Quiz5Right::
	goto CinnabarIsland_Gym_EventScript_Quiz5Left
	end

CinnabarIsland_Gym_EventScript_Quiz5Correct::
	call CinnabarIsland_Gym_EventScript_CorrectAnswer
	goto_if_set FLAG_TRINITY_K_BLAINE_QUIZ_5, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz5Complete
	releaseall
	end

CinnabarIsland_Gym_EventScript_Quiz5Complete::
	playse SE_UNLOCK
	waitse
	call CinnabarIsland_Gym_EventScript_OpenDoor5
	special DrawWholeMapView
	setflag FLAG_TRINITY_K_BLAINE_QUIZ_5
	return

CinnabarIsland_Gym_EventScript_Quiz5Incorrect::
	call CinnabarIsland_Gym_EventScript_IncorrectAnswer
	goto_if_not_defeated TRAINER_KANTO_BURGLAR_DUSTY, CinnabarIsland_Gym_EventScript_BattleDusty
	releaseall
	end

CinnabarIsland_Gym_EventScript_BattleDusty::
	trainerbattle_no_intro TRAINER_KANTO_BURGLAR_DUSTY, CinnabarIsland_Gym_Text_DustyBeaten
	goto_if_set FLAG_TRINITY_K_BLAINE_QUIZ_5, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz5Complete
	releaseall
	end

@ ---- Room 6 (Zac) ----
CinnabarIsland_Gym_EventScript_Quiz6Left::
	lockall
	msgbox CinnabarIsland_Gym_Text_PokemonQuizRules, MSGBOX_DEFAULT
	msgbox CinnabarIsland_Gym_Text_QuizQuestion6, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_Gym_EventScript_Quiz6Correct
	goto CinnabarIsland_Gym_EventScript_Quiz6Incorrect
	end

CinnabarIsland_Gym_EventScript_Quiz6Right::
	goto CinnabarIsland_Gym_EventScript_Quiz6Left
	end

CinnabarIsland_Gym_EventScript_Quiz6Correct::
	call CinnabarIsland_Gym_EventScript_CorrectAnswer
	goto_if_set FLAG_TRINITY_K_BLAINE_QUIZ_6, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz6Complete
	releaseall
	end

CinnabarIsland_Gym_EventScript_Quiz6Complete::
	playse SE_UNLOCK
	waitse
	call CinnabarIsland_Gym_EventScript_OpenDoor6
	special DrawWholeMapView
	setflag FLAG_TRINITY_K_BLAINE_QUIZ_6
	return

CinnabarIsland_Gym_EventScript_Quiz6Incorrect::
	call CinnabarIsland_Gym_EventScript_IncorrectAnswer
	goto_if_not_defeated TRAINER_KANTO_SUPER_NERD_ZAC, CinnabarIsland_Gym_EventScript_BattleZac
	releaseall
	end

CinnabarIsland_Gym_EventScript_BattleZac::
	trainerbattle_no_intro TRAINER_KANTO_SUPER_NERD_ZAC, CinnabarIsland_Gym_Text_ZacBeaten
	goto_if_set FLAG_TRINITY_K_BLAINE_QUIZ_6, CinnabarIsland_Gym_EventScript_DoorAlreadyOpen
	call CinnabarIsland_Gym_EventScript_Quiz6Complete
	releaseall
	end

@ ============================================================================
@ Door-open metatile sets. FRLG's own shape (sub-plan section 7).
@ ============================================================================
CinnabarIsland_Gym_EventScript_OpenDoor1::
	setmetatile 26,  8, 0x2C7, 0
	setmetatile 27,  8, 0x2C6, 0
	setmetatile 26,  9, 0x2CF, 0
	setmetatile 27,  9, 0x2CE, 0
	setmetatile 26, 10, 0x289, 0
	setmetatile 27, 10, 0x281, 0
	setmetatile 28, 10, 0x282, 0
	return

CinnabarIsland_Gym_EventScript_OpenDoor2::
	setmetatile 17,  8, 0x2C7, 0
	setmetatile 18,  8, 0x2C6, 0
	setmetatile 17,  9, 0x2CF, 0
	setmetatile 18,  9, 0x2CE, 0
	setmetatile 17, 10, 0x289, 0
	setmetatile 18, 10, 0x281, 0
	setmetatile 19, 10, 0x282, 0
	return

CinnabarIsland_Gym_EventScript_OpenDoor3::
	setmetatile 17, 15, 0x2C7, 0
	setmetatile 18, 15, 0x2C6, 0
	setmetatile 17, 16, 0x2CF, 0
	setmetatile 18, 16, 0x2CE, 0
	setmetatile 17, 17, 0x289, 0
	setmetatile 18, 17, 0x281, 0
	setmetatile 19, 17, 0x282, 0
	return

CinnabarIsland_Gym_EventScript_OpenDoor4::
	setmetatile 11, 21, 0x2D1, 1
	setmetatile 11, 22, 0x289, 0
	setmetatile 11, 23, 0x281, 0
	return

CinnabarIsland_Gym_EventScript_OpenDoor5::
	setmetatile  5, 16, 0x2C7, 0
	setmetatile  6, 16, 0x2C6, 0
	setmetatile  5, 17, 0x2CF, 0
	setmetatile  6, 17, 0x2CE, 0
	setmetatile  5, 18, 0x289, 0
	setmetatile  6, 18, 0x281, 0
	setmetatile  7, 18, 0x282, 0
	return

CinnabarIsland_Gym_EventScript_OpenDoor6::
	setmetatile  5,  8, 0x2C7, 0
	setmetatile  6,  8, 0x2C6, 0
	setmetatile  5,  9, 0x2CF, 0
	setmetatile  6,  9, 0x2CE, 0
	setmetatile  5, 10, 0x289, 0
	setmetatile  6, 10, 0x281, 0
	setmetatile  7, 10, 0x282, 0
	return

@ ============================================================================
@ Text.
@ ============================================================================
CinnabarIsland_Gym_Text_BlaineIntro:
	.string "Hah!\pI am BLAINE, the red-hot LEADER\nof CINNABAR GYM!\pMy fiery POKéMON are all rough\land tumble!$"

CinnabarIsland_Gym_Text_BlaineDefeat:
	.string "I have burned down to nothing!\nNot even ashes remain!$"

CinnabarIsland_Gym_Text_BlainePostBattle:
	.string "Hah! Come back when you've got\nmore fire in you.$"

@ Trinity M5b S9 fix round (review I5): the "heightens the SPECIAL stats"
@ claim is killed -- no such engine boost exists (badges carry no stat
@ modifier in this tree, grepped: no GetBadgeBoost-class function touches
@ Special/SpAttack/SpDefense anywhere). Pinned shape restored verbatim from
@ PewterCity_Gym_Text_BoulderBadgeInfo, the milestone's own established
@ badge-explanation text.
CinnabarIsland_Gym_Text_ReceivedVolcanoBadge:
	.string "{PLAYER} received the\nVOLCANOBADGE from BLAINE.$"

CinnabarIsland_Gym_Text_ExplainVolcanoBadge:
	.string "BLAINE: The VOLCANOBADGE.\pDoesn't make you stronger. Just\nmeans KANTO's noticed you.\pSeven of these, and VIRIDIAN opens\nthe door.\pTake this too -- you earned it.$"

CinnabarIsland_Gym_Text_FireBlastIsUltimateFireMove:
	.string "FIRE BLAST is the ultimate fire\ntechnique.\pIt won't wear out, so don't waste\nit on WATER POKéMON.$"

CinnabarIsland_Gym_Text_GymStatue:
	.string "CINNABAR POKéMON GYM\nLEADER: BLAINE\pThe Fire-and-Brimstone Trainer$"

CinnabarIsland_Gym_Text_GymStatueCertified:
	.string "CINNABAR POKéMON GYM\nLEADER: BLAINE\pBLAINE'S CERTIFIED TRAINERS:\n{PLAYER}$"

CinnabarIsland_Gym_Text_GymGuyAdvice:
	.string "Yo! Champ in the making!\pThe hotheaded BLAINE is a FIRE\nPOKéMON pro.\pWater AND Ground both land clean\non every one of his six -- no\lexceptions. His MAGCARGO eats it\lworst of all, being ROCK too.$"

@ Trinity M5b S9 fix round (review I5): restored to the milestone's own
@ pinned "<BADGE>. One of seven." close (PewterCity_Gym_Text_
@ GymGuyPostVictory's own shape, confirmed against 3 other siblings, S7's
@ own fold precedent) -- never counts the player's own badges, just names
@ this one's place in the set of seven Kanto badges.
CinnabarIsland_Gym_Text_GymGuyPostVictory:
	.string "Straight through BLAINE! Figured\nas much.\pVOLCANOBADGE. One of seven.$"

CinnabarIsland_Gym_Text_PokemonQuizRules:
	.string "POKéMON Quiz!\pGet it right, and the door opens to\nthe next room.\pGet it wrong, and face a TRAINER!$"

CinnabarIsland_Gym_Text_QuizQuestion1:
	.string "CATERPIE evolves into METAPOD?$"

CinnabarIsland_Gym_Text_QuizQuestion2:
	.string "There are nine certified POKéMON\nLEAGUE BADGES in KANTO?$"

CinnabarIsland_Gym_Text_QuizQuestion3:
	.string "POLIWAG evolves three times?$"

CinnabarIsland_Gym_Text_QuizQuestion4:
	.string "Are electric moves effective\nagainst GROUND-type POKéMON?$"

CinnabarIsland_Gym_Text_QuizQuestion5:
	.string "POKéMON of the same kind and level\nare not identical?$"

CinnabarIsland_Gym_Text_QuizQuestion6:
	.string "TM28 contains TOMBSTONY?$"

CinnabarIsland_Gym_Text_CorrectGoOnThrough:
	.string "You're absolutely correct!\pGo on through!$"

CinnabarIsland_Gym_Text_SorryBadCall:
	.string "Sorry!\nBad call!$"

CinnabarIsland_Gym_Text_QuinnSeen:
	.string "I was a thief, but I went straight\nas a TRAINER.$"

CinnabarIsland_Gym_Text_QuinnBeaten:
	.string "I surrender!$"

CinnabarIsland_Gym_Text_ErikSeen:
	.string "Do you know how hot POKéMON fire\nbreath can get?$"

CinnabarIsland_Gym_Text_ErikBeaten:
	.string "Yow! Hot, hot, hot!$"

CinnabarIsland_Gym_Text_AverySeen:
	.string "I've studied POKéMON thoroughly.\nYou can't win!$"

CinnabarIsland_Gym_Text_AveryBeaten:
	.string "Waah! My studies were\ninsufficient!$"

CinnabarIsland_Gym_Text_RamonSeen:
	.string "I like using FIRE-type POKéMON.\nI just do.$"

CinnabarIsland_Gym_Text_RamonBeaten:
	.string "Too hot to handle!$"

CinnabarIsland_Gym_Text_DerekSeen:
	.string "I know why BLAINE became a\nTRAINER.$"

CinnabarIsland_Gym_Text_DerekBeaten:
	.string "Ow!$"

CinnabarIsland_Gym_Text_DustySeen:
	.string "I've been to many GYMS, but this\none best suits my style.$"

CinnabarIsland_Gym_Text_DustyBeaten:
	.string "Yowza! Too hot!$"

CinnabarIsland_Gym_Text_ZacSeen:
	.string "Fire is weak against H2O.$"

CinnabarIsland_Gym_Text_ZacBeaten:
	.string "Oh! Snuffed out!$"
