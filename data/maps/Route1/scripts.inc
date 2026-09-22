@ ============================================================================
@ Trinity M5b S10 -- SILVER's final battle. Blue's exact shape (S5), copied
@ verbatim with SILVER's own names/ids substituted. Gate is FLAG_TRINITY_
@ BADGE24, NOT arc==4 -- arc reaches 4 at the RIG scene's own resolution,
@ well before Giovanni's badge fight, so an arc-only gate would let Silver
@ appear before the badge is even won, contradicting the brief's own explicit
@ sequential order ("badge 24, TM26 ... -> Silver's final battle").
@
@ FIX (S14 final-review F1, Major): the hide half of this gate was
@ originally `arc >= 5`. Route 1 sits OFF the mandatory post-badge path
@ (Viridian -> Route 22/23 -> league), and a tree-wide grep found no NPC,
@ sign, or scene anywhere that points the player here -- so the DEFAULT
@ player reaches the league, arc jumps 4->6 at the Hall of Fame having
@ never fought Silver, and the old `arc >= 5` condition then hides him
@ forever. No `==5` reader exists anywhere in the tree (verified fresh),
@ so this was silent content deletion, not a soft-lock. Fixed per the
@ review's option (a): the hide condition now reads SILVER's own
@ fought-state via the engine's per-trainer flag, `checktrainerflag
@ TRAINER_SILVER_FINAL` (same idiom as TRAINER_SILVER_MTMOON's own guard,
@ MtMoon_1F/scripts.inc, and TRAINER_BOBBY's, IndigoPlateau_
@ PokemonCenter_1F/scripts.inc:270-271) -- Silver now stays visible/
@ re-fightable across the league regardless of arc, and disappears only
@ once he has actually been beaten. The BADGE24 half is unchanged.
@ ============================================================================
Route1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
	.byte 0

Route1_OnTransition::
	goto_if_unset FLAG_TRINITY_BADGE24, Route1_EventScript_HideSilver
	checktrainerflag TRAINER_SILVER_FINAL
	goto_if TRUE, Route1_EventScript_HideSilver
	clearflag FLAG_TRINITY_K_SILVER_FINAL_HIDE
	end

Route1_EventScript_HideSilver::
	setflag FLAG_TRINITY_K_SILVER_FINAL_HIDE
	end

@ Talk-triggered (G-pattern R2-style; the battle macro below already
@ supplies its own lock/faceplayer, so this script must NOT lock first).
@ NO_MUSIC selects
@ TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC, so the playbgm below survives into
@ the battle -- TRAINER_SILVER_FINAL is TRAINER_CLASS_RIVAL with a name other
@ than WALLY, so GetBattleBGM() already returns MUS_VS_RIVAL, zero code
@ change (the same name-compare idiom every prior SILVER fight in this tree
@ relies on).
Route1_EventScript_Silver::
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
	trainerbattle_single TRAINER_SILVER_FINAL, Route1_Text_SilverSeen, Route1_Text_SilverBeaten, Route1_EventScript_SilverAftermath, NO_MUSIC
	goto Route1_EventScript_SilverIdle
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE -- SilverAftermath removeobject's
@ SILVER and the ON_TRANSITION hides him permanently once he's been fought
@ (checktrainerflag TRAINER_SILVER_FINAL, S14 fix) -- there is never an
@ object left to re-trigger this talk.
Route1_EventScript_SilverIdle::
	lock
	faceplayer
	msgbox Route1_Text_SilverIdle, MSGBOX_DEFAULT
	release
	end

@ The durable half first (S4's I3(b) ordering rule), the arc write behind the
@ once-only redo-guard (HallOfFame's own shape), THEN the R4 fade-wrapped
@ departure.
@ M7b Task 18 (#13): the ONE connective line the founder asked for -- a single
@ branch around the existing message, inside the existing spine. No new object,
@ no new trainer id, no new scene, no new flag, no restructuring of his arc.
@
@ IT REFERENCES THE BASEMENT FINAL, and the guard is the flag that scene sets.
@ The founder's words were "the basement final vs his father's shadow", and
@ there are two candidate basements in this tree. The Rocket Base B3F scene
@ under MAHOGANY (FLAG_TRINITY_J_SILVER4_SEEN) is a monologue about LANCE with
@ no battle in it. The GOLDENROD UNDERGROUND scene
@ (GoldenrodUndergroundSwitchRoomEntrances_EventScript_SilverBattle) is the
@ actual final: a basement, TEAM ROCKET's own, a fight -- TRAINER_SILVER_4 --
@ and Silver's own "Why do I lose? … Is what that LANCE said true?" It sets
@ FLAG_TRINITY_J_SILVER4_BEATEN, so that is what this line is guarded on, and
@ a player who somehow never fought it still gets the shipped text unchanged.
@ (The sub-plan named the MAHOGANY flag; this is a disclosed correction.)
@
@ THE ARC WRITE BELOW IS UNTOUCHED: still exactly one
@ `setvar VAR_TRINITY_KANTO_ARC, 5` in the tree, still after the message and
@ still behind the same redo guard (story_audit.py check (a)).
Route1_EventScript_SilverAftermath::
	goto_if_set FLAG_TRINITY_J_SILVER4_BEATEN, Route1_EventScript_SilverAftermathBasement
	msgbox Route1_Text_SilverAftermath, MSGBOX_DEFAULT
	goto Route1_EventScript_SilverAftermathEnd

Route1_EventScript_SilverAftermathBasement::
	msgbox Route1_Text_SilverAftermathBasement, MSGBOX_DEFAULT

Route1_EventScript_SilverAftermathEnd::
	closemessage
	goto_if_ge VAR_TRINITY_KANTO_ARC, 5, Route1_EventScript_SilverDepart
	setvar VAR_TRINITY_KANTO_ARC, 5

Route1_EventScript_SilverDepart::
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_KANTO_ROUTE1_SILVER
	fadescreen FADE_FROM_BLACK
	release
	end

Route1_Text_SilverSeen:
	.string "…So you actually did it. Earth\nBadge and all.\pThree regions, two Leagues, and\nnow KANTO's own boss trainer.\lFigures it'd be you.$"

Route1_Text_SilverBeaten:
	.string "…Tch. Of course.\pI've been chasing you across\nthree regions and I still can't\lclose the gap.$"

Route1_Text_SilverAftermath:
	.string "Whatever. I didn't need to win.\nI needed to know where I stood.\pNow I know. Get stronger. I'll\nbe watching, wherever you go\lnext.$"

Route1_Text_SilverAftermathBasement:
	.string "Whatever. I didn't need to win.\nI needed to know where I stood.\pIn that basement under GOLDENROD\nI asked why I keep losing.\lLANCE's answer made me angry.\pI've stopped arguing with it.\pNow I know. Get stronger. I'll\nbe watching, wherever you go\lnext.$"

Route1_Text_SilverIdle:
	.string "…$"

Route1_EventScript_MartClerk::
	msgbox Route1_Text_MartClerk, MSGBOX_NPC
	end

Route1_EventScript_Boy::
	msgbox Route1_Text_Boy, MSGBOX_NPC
	end

Route1_EventScript_RouteSign::
	msgbox Route1_Text_RouteSign, MSGBOX_SIGN
	end

Route1_Text_MartClerk:
	.string "KANTO's got its own trainers worth\nwatching, but even we're curious\labout this HOENN-JOHTO champion.$"

Route1_Text_Boy:
	.string "See those ledges along the road?\pIt's a bit scary, but you can jump\nfrom them.\pYou can get back to PALLET TOWN\nquicker that way.$"

Route1_Text_RouteSign:
	.string "ROUTE 1\nPALLET TOWN - VIRIDIAN CITY$"
