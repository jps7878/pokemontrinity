@ ============================================================================
@ M7b Task 18 (finding #13, WHERE): the Act I rival, cameo 1 of 4.
@
@ VISIBILITY, ZERO NEW FLAGS. FLAG_TEMP_5 is the object's hide flag and this
@ handler is its only writer in the tree. On every map ENTRY the engine runs
@ ClearTempFieldEventData() and then RunOnTransitionMapScript() before InitMap
@ spawns the object templates -- LoadMapFromWarp (src/overworld.c:924 then
@ :945, :954) and LoadMapFromCameraTransition (:860, :876, :877) -- so the flag
@ is CLEAR (object VISIBLE) by default on entry and this handler's setflag is
@ what hides her. Vanilla's Route130_OnTransition hides Mirage Island the same
@ way. CONTINUE-FROM-SAVE IS NOT ONE OF THOSE PATHS and the sub-plan was wrong
@ to say it was: CB2_ContinueSavedGame (src/overworld.c:1972) calls
@ InitMapFromSavedGame (src/fieldmap.c:74), which runs RunOnLoadMapScript, not
@ the transition script, and clears no temp flag. It is still safe, for a
@ different reason: that path never calls TrySpawnObjectEvents -- it restores
@ the saved gObjectEvents array (src/load_save.c:218) and re-sprites only the
@ entries already `active` (InitObjectEventsReturnToField, :2460 ->
@ SpawnObjectEventsOnReturnToField, src/event_object_movement.c:2856) -- so a
@ template added by this commit cannot appear on a Continue at all. She first
@ spawns on the next real map entry, where this handler has run.
@
@ SPRITE: OBJ_EVENT_GFX_VAR_0 + Common_EventScript_SetupRivalGfxId, the vanilla
@ rival idiom (Route110_OnTransition). The rival is the player's OPPOSITE --
@ MAY for a male player, BRENDAN for a female one. VAR_OBJ_GFX_ID_0 is 0x4010,
@ a SAVED var, so it MUST be re-seeded on every map that shows the object; an
@ unseeded VAR gfx slot is what produced bug-test finding #16. The two values
@ written here are exactly the two the vanilla helper writes everywhere else,
@ so no consumer of VAR_OBJ_GFX_ID_0 can see a value it could not see already.
@
@ WINDOW: KANTO arrival done AND fewer than 3 KANTO badges. The arrival test is
@ the bug-test's own P1 rule (findings #2/#3) -- no story object may be reached
@ before its act starts. The four windows are disjoint (badges <3 / 3-5 / >=6
@ with arc <6 / arc >=6), so exactly one sighting is ever live.
@
@ PLACEMENT (17,33): col 0, elev 3, MB_CAVE, decoded from this map's own
@ map.bin. Column 17 of the 3-wide ROUTE 4 entrance corridor (cols 17-19, rows
@ 32-37; (16,33) is col 1 wall), 4 tiles from the door at (18,37) and out of
@ the walking lane. reach_check flood fill 1142 -> 1141: delta 1, her own tile.
@ ============================================================================
MtMoon_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_1F_OnTransition
	.byte 0

MtMoon_1F_OnTransition::
	call Common_EventScript_SetupRivalGfxId
	goto_if_unset FLAG_TRINITY_K_ARRIVED, MtMoon_1F_EventScript_HideRival
	call Trinity_EventScript_CountKantoBadges
	goto_if_ge VAR_TEMP_A, 3, MtMoon_1F_EventScript_HideRival
	clearflag FLAG_TEMP_5
	end

MtMoon_1F_EventScript_HideRival::
	setflag FLAG_TEMP_5
	end

MtMoon_1F_EventScript_Iris::
	trainerbattle_single TRAINER_KANTO_LASS_IRIS, MtMoon_1F_Text_IrisSeen, MtMoon_1F_Text_IrisBeaten
	msgbox MtMoon_1F_Text_IrisBeaten, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Robby::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_ROBBY, MtMoon_1F_Text_RobbySeen, MtMoon_1F_Text_RobbyBeaten
	msgbox MtMoon_1F_Text_RobbyBeaten, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Jovan::
	trainerbattle_single TRAINER_KANTO_SUPER_NERD_JOVAN, MtMoon_1F_Text_JovanSeen, MtMoon_1F_Text_JovanBeaten
	msgbox MtMoon_1F_Text_JovanBeaten, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Miriam::
	trainerbattle_single TRAINER_KANTO_LASS_MIRIAM, MtMoon_1F_Text_MiriamSeen, MtMoon_1F_Text_MiriamBeaten
	msgbox MtMoon_1F_Text_MiriamBeaten, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Kent::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_KENT, MtMoon_1F_Text_KentSeen, MtMoon_1F_Text_KentBeaten
	msgbox MtMoon_1F_Text_KentBeaten, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Josh::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_JOSH, MtMoon_1F_Text_JoshSeen, MtMoon_1F_Text_JoshBeaten
	msgbox MtMoon_1F_Text_JoshBeaten, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Marcos::
	trainerbattle_single TRAINER_KANTO_HIKER_MARCOS, MtMoon_1F_Text_MarcosSeen, MtMoon_1F_Text_MarcosBeaten
	msgbox MtMoon_1F_Text_MarcosBeaten, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_ZubatSign::
	msgbox MtMoon_1F_Text_ZubatSign, MSGBOX_SIGN
	end

MtMoon_1F_Text_IrisSeen:
	.string "…$"

MtMoon_1F_Text_IrisBeaten:
	.string "…$"

MtMoon_1F_Text_RobbySeen:
	.string "…$"

MtMoon_1F_Text_RobbyBeaten:
	.string "…$"

MtMoon_1F_Text_JovanSeen:
	.string "…$"

MtMoon_1F_Text_JovanBeaten:
	.string "…$"

MtMoon_1F_Text_MiriamSeen:
	.string "…$"

MtMoon_1F_Text_MiriamBeaten:
	.string "…$"

MtMoon_1F_Text_KentSeen:
	.string "…$"

MtMoon_1F_Text_KentBeaten:
	.string "…$"

MtMoon_1F_Text_JoshSeen:
	.string "…$"

MtMoon_1F_Text_JoshBeaten:
	.string "…$"

MtMoon_1F_Text_MarcosSeen:
	.string "…$"

MtMoon_1F_Text_MarcosBeaten:
	.string "…$"

MtMoon_1F_Text_ZubatSign:
	.string "Beware!\nZUBAT is a bloodsucker!$"

@ ============================================================================
@ Trinity M5b S13b -- SILVER, the Mt. Moon rematch. TRAINER_SILVER_MTMOON
@ (real party data, opponents.h), confirmed unconsumed by every prior slice.
@ ALWAYS-AVAILABLE per the founder decision: no arc gate, no story flag on
@ the object's own visibility (flag "0" -- unconditionally present in the
@ map data from a new save, the SAME as this map's other ungated flavour
@ trainers; in actual play Mt. Moon is only reachable after Act II, so no
@ save ever really stands here before then -- fix round 1, review m8, the
@ earlier "fresh save" wording described the flag's own state, not a real
@ play sequence). "Always-available" names the RE-APPROACH, not a bypass
@ of one-fight-per-id: the fight itself is still gated by the engine's own
@ per-trainer flag (`checktrainerflag TRAINER_SILVER_MTMOON`,
@ TRAINER_FLAGS_START + id, structurally reserved, zero registry cost) --
@ explicit top-of-script guard here rather than relying on trainerbattle's
@ own internal post-battle-address fallthrough, because a msgbox precedes
@ the trainerbattle call. CORRECTED (fix round 1, review m1): for
@ `trainerbattle_no_intro` specifically there is NO internal idempotence at
@ all (`EventScript_DoNoIntroTrainerBattle`, data/scripts/
@ trainer_battle.inc, has no `GetTrainerFlag` check and calls
@ `dotrainerbattle` unconditionally) -- the explicit guard is not skipping
@ a msgbox an existing fallthrough would otherwise replay, it is the ONLY
@ thing standing between this NPC and being infinitely re-fightable.
@ Same shape as BOBBY's farewell and the Wise Trio, this same slice.
@ `trainerbattle_no_intro` (not trainerbattle_single): a custom challenge
@ line already plays via msgbox,
@ matching TRAINER_SILVER_2's own established idiom (AzaleaTown/
@ scripts.inc). Placement (20,25): col=0 elev=3 MB_CAVE, decoded directly
@ from MtMoon_1F's own map.bin, clear of every existing object/item ball on
@ this floor.
@ ============================================================================
MtMoon_1F_EventScript_Silver::
	lock
	faceplayer
	checktrainerflag TRAINER_SILVER_MTMOON
	goto_if TRUE, MtMoon_1F_EventScript_SilverAfter
	msgbox MtMoon_1F_Text_SilverIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SILVER_MTMOON, MtMoon_1F_Text_SilverDefeat
	msgbox MtMoon_1F_Text_SilverPostBattle, MSGBOX_DEFAULT
	release
	end

MtMoon_1F_EventScript_SilverAfter::
	msgbox MtMoon_1F_Text_SilverAfter, MSGBOX_DEFAULT
	release
	end

MtMoon_1F_Text_SilverIntro:
	.string "SILVER: Still crawling through\n"
	.string "caves, I see.\p"
	.string "Fine. Prove you're worth\n"
	.string "following down one.$"

MtMoon_1F_Text_SilverDefeat:
	.string "SILVER: …$"

MtMoon_1F_Text_SilverPostBattle:
	.string "SILVER: Better than last time.\n"
	.string "Don't get used to it.$"

MtMoon_1F_Text_SilverAfter:
	.string "SILVER: Go on. I've got nothing\n"
	.string "left to prove down here.$"

@ ============================================================================
@ M7b Task 18 (#13): cameo 1's line. Talk-only -- a pure msgbox is idempotent,
@ so no "already seen" bit is needed and the whole feature costs zero flags.
@
@ EVERY POINTER IN IT IS TRUE WHEN IT IS SPOKEN, which is the entire point of
@ the charter's WHERE lane. SILVER really is on this floor and really is NORTH:
@ LOCALID_KANTO_MTMOON_SILVER stands at (20,25), 8 rows up from her, and his
@ object carries flag "0" so he is present whenever she is. His hair is NOT
@ described -- his overworld is OBJ_EVENT_GFX_RICH_BOY, so "the red-haired boy"
@ would have been a claim about art this task does not own. And the SAFARI
@ pointer is stated as a CONDITION ("when you've three KANTO badges") rather
@ than as a present fact, because cameo 2 does not exist until badge 3: a
@ player who walks to FUCHSIA on the strength of this line would otherwise find
@ an empty gate, which is the information failure the charter exists to kill.
@ ============================================================================
MtMoon_1F_EventScript_Rival::
	msgbox MtMoon_1F_Text_Rival, MSGBOX_NPC
	end

MtMoon_1F_Text_Rival:
	.string "{RIVAL}: {PLAYER}! Of course it's\n"
	.string "you.\p"
	.string "I'm filling in the KANTO pages.\n"
	.string "Nobody back home has seen half\l"
	.string "of what lives in this cave.\p"
	.string "Somebody else is in here, north\n"
	.string "of the door. He never said a\l"
	.string "word to me.\p"
	.string "When you've three KANTO badges,\n"
	.string "look for me at the SAFARI ZONE\l"
	.string "outside FUCHSIA.$"
