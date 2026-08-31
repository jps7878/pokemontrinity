MtMoon_1F_MapScripts::
	.byte 0

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
