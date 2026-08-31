@ ============================================================================
@ Trinity M5b S10 -- SILVER's final battle. Blue's exact shape (S5), copied
@ verbatim with SILVER's own names/ids substituted. Gate is FLAG_TRINITY_
@ BADGE24, NOT arc==4 -- arc reaches 4 at the RIG scene's own resolution,
@ well before Giovanni's badge fight, so an arc-only gate would let Silver
@ appear before the badge is even won, contradicting the brief's own explicit
@ sequential order ("badge 24, TM26 ... -> Silver's final battle").
@ ============================================================================
Route1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
	.byte 0

Route1_OnTransition::
	goto_if_unset FLAG_TRINITY_BADGE24, Route1_EventScript_HideSilver
	goto_if_ge VAR_TRINITY_KANTO_ARC, 5, Route1_EventScript_HideSilver
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
@ SILVER and the ON_TRANSITION hides him permanently once arc>=5 -- there is
@ never an object left to re-trigger this talk.
Route1_EventScript_SilverIdle::
	lock
	faceplayer
	msgbox Route1_Text_SilverIdle, MSGBOX_DEFAULT
	release
	end

@ The durable half first (S4's I3(b) ordering rule), the arc write behind the
@ once-only redo-guard (HallOfFame's own shape), THEN the R4 fade-wrapped
@ departure.
Route1_EventScript_SilverAftermath::
	msgbox Route1_Text_SilverAftermath, MSGBOX_DEFAULT
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
