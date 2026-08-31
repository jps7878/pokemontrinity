SilverCaveRoom3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SilverCaveRoom3_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M5b S12 -- RED, the summit. Full decode: docs/superpowers/plans/
@ m5b/12-mt-silver-red.md section 3. Wordless (GSC's own register -- RED never
@ speaks a real line, before or after), 2 lines of staging total.
@
@ VISIBILITY. Single authority, copied verbatim from Route1_OnTransition's own
@ shape (S10, SILVER's final fight): visible while VAR_TRINITY_KANTO_ARC < 7,
@ hidden once S12 (the ONE writer of arc value 7, below) sets it. No arc>=6
@ floor guard is needed here the way Route1 needed FLAG_TRINITY_BADGE24 --
@ this room is only reachable at all via Route28's own arc>=6 entrance gate
@ (Route28/scripts.inc, SilverCaveGateCheck), and arc is monotonic, so nothing
@ this map's script could ever branch on wrong content the way S11's
@ dual-roster league rooms could.
@ ============================================================================
SilverCaveRoom3_OnTransition::
	goto_if_ge VAR_TRINITY_KANTO_ARC, 7, SilverCaveRoom3_EventScript_HideRed
	clearflag FLAG_TRINITY_K_RED_HIDE
	end

SilverCaveRoom3_EventScript_HideRed::
	setflag FLAG_TRINITY_K_RED_HIDE
	end

@ Talk-triggered standing NPC, Route1_EventScript_Silver's own shape (not
@ Ash's ON_FRAME walk-in -- the wordless 2-line budget has no room for a
@ scripted approach, and RED has always been "just there" in GSC canon). The
@ battle-start command below supplies its own lock/faceplayer, so this script
@ must NOT lock first. No music override: RED is TRAINER_CLASS_RIVAL with a
@ name other than WALLY, so GetBattleBGM() already returns MUS_VS_RIVAL, zero
@ code change (the same name-compare idiom every prior RIVAL-class fight in
@ this tree relies on -- see the sub-plan section 4 for the full design call).
SilverCaveRoom3_EventScript_Red::
	trainerbattle_single TRAINER_RED, SilverCaveRoom3_Text_RedSeen, SilverCaveRoom3_Text_RedDefeated, SilverCaveRoom3_EventScript_RedAftermath
	goto SilverCaveRoom3_EventScript_RedIdle
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE -- RedAftermath removeobject's RED and
@ the ON_TRANSITION above hides him permanently once arc>=7 -- there is never
@ an object left to re-trigger this talk. Same class as Route1_EventScript_
@ SilverIdle / PokemonLeague_ChampionsRoom's own Lance guard.
SilverCaveRoom3_EventScript_RedIdle::
	lock
	faceplayer
	msgbox SilverCaveRoom3_Text_RedIdle, MSGBOX_DEFAULT
	release
	end

@ The durable half first (S4's I3(b) ordering rule), the arc write behind the
@ once-only redo-guard (HallOfFame's own shape), THEN the R4 fade-wrapped
@ departure + removeobject co-sign -- Route1_EventScript_SilverAftermath's
@ exact shape, minus the extra Aftermath speech line (RED's own 2-line
@ ceiling is already spent by Seen + Defeated).
SilverCaveRoom3_EventScript_RedAftermath::
	closemessage
	goto_if_ge VAR_TRINITY_KANTO_ARC, 7, SilverCaveRoom3_EventScript_RedDepart
	setvar VAR_TRINITY_KANTO_ARC, 7

SilverCaveRoom3_EventScript_RedDepart::
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_KANTO_SILVERCAVE_RED
	fadescreen FADE_FROM_BLACK
	release
	end

SilverCaveRoom3_Text_RedSeen:
	.string "……$"

SilverCaveRoom3_Text_RedDefeated:
	.string "……$"

SilverCaveRoom3_Text_RedIdle:
	.string "……$"
