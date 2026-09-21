@ ============================================================================
@ Trinity M5b S10 -- VIRIDIAN HIDEOUT B1F, the outer raid floor. Full decode +
@ design: docs/superpowers/plans/m5b/10-viridian-climax.md.
@
@ Reuses RocketHideout_B1F's own LAYOUT_ROCKET_HIDEOUT_B1F_KANTO wholesale
@ (S2's registration precedent, forward-noted for this exact slice) -- zero
@ new tile art, zero new blockdata risk. Three raid posts sit at Celadon's
@ own proven-clear tile spots. M7 Task 9 (finding #18): both basement exits
@ are COORD TRIGGERS on the layout's own drawn FRLG staircase tiles --
@ (12,2) MB_UP_LEFT_STAIR_WARP up to the city, (17,2) MB_DOWN_RIGHT_STAIR_WARP
@ down to B2F -- VAR_TEMP_1 == 0, elevation-true (the ViridianCity (36,11)
@ shape). TryStartCoordEventScript runs BEFORE TryStartWarpEventScript
@ (src/field_control_avatar.c:620-625) and the stair behaviours only ever
@ intercept west/east presses into walls (field_screen_effect.c:1688), so a
@ declined prompt leaves the player free to step back off. (Pressing INTO
@ the stairs after declining is a silent face-only no-op -- no warp_event,
@ so TryArrowWarp returns FALSE; step off and back on to re-prompt. Known,
@ accepted, same as ViridianCity (36,11).) The landings
@ (12,3)/(17,3) are the stair BASES, one tile south, MB_NORMAL: a warp
@ landing never fires a trigger (tookStep needs runningState == MOVING).
@ Still not warp_events: the city side has no warp-behaviour tile and the
@ arc gate + YES/NO live in these scripts. AFFORDANCE RULE (M7): every
@ mandatory-path interactable sits on a visually distinct tile -- here the
@ staircases FRLG already drew. Do NOT add a warp_event on (12,2)/(17,2)
@ without removing the trigger: the trigger would shadow it.
@ ============================================================================
ViridianHideout_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianHideout_B1F_OnTransition
	.byte 0

ViridianHideout_B1F_OnTransition::
	goto_if_ne VAR_TRINITY_KANTO_ARC, 3, ViridianHideout_B1F_EventScript_HideRaidCast
	clearflag FLAG_TRINITY_K_VBASEMENT_RAID_HIDE
	end

ViridianHideout_B1F_EventScript_HideRaidCast::
	setflag FLAG_TRINITY_K_VBASEMENT_RAID_HIDE
	end

ViridianHideout_B1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_K_GRUNT_M_8, ViridianHideout_B1F_Text_Grunt1Seen, ViridianHideout_B1F_Text_Grunt1Beaten
	msgbox ViridianHideout_B1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

ViridianHideout_B1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_K_GRUNT_M_9, ViridianHideout_B1F_Text_Grunt2Seen, ViridianHideout_B1F_Text_Grunt2Beaten
	msgbox ViridianHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

ViridianHideout_B1F_EventScript_Scientist1::
	trainerbattle_single TRAINER_K_SCIENTIST_1, ViridianHideout_B1F_Text_Scientist1Seen, ViridianHideout_B1F_Text_Scientist1Beaten
	msgbox ViridianHideout_B1F_Text_Scientist1PostBattle, MSGBOX_AUTOCLOSE
	end

@ Sealed pre-arc3 (defensive -- a player who somehow reaches this floor before
@ clearing Celadon is turned back by the sealed-way line, not raid content,
@ matching the same posture as ViridianCity's own grate sign). Open, this is
@ the "way back up" -- a plain scripted ride, the OlivinePort /
@ SaffronMagnetTrain shape.
@ FIX ROUND 1 (review Minor 8/9): lockall/releaseall wrapping added
@ (matching CeladonCity_GameCorner_EventScript_Poster:48-58's own
@ precedent), and DescendToB2F below now carries the SAME defensive arc>=3
@ guard as this script -- both are unreachable below arc 3 in practice (the
@ grate itself gates entry to this whole floor), so the asymmetry was inert,
@ but the sealed-way flavour text implies a defensive posture that should
@ be applied consistently, not just on the way this script happens to be
@ reached first.
ViridianHideout_B1F_EventScript_ExitToCity::
	lockall
	goto_if_lt VAR_TRINITY_KANTO_ARC, 3, ViridianHideout_B1F_EventScript_ExitSealed
	msgbox ViridianHideout_B1F_Text_ExitToCity, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianHideout_B1F_EventScript_ExitDecline
	closemessage
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	warp MAP_VIRIDIAN_CITY, 30, 10  @ emerge north of the grate, facing it (ScrCmd_warp lands DIR_SOUTH)
	waitstate
	end

@ defensive: arc<3 cannot reach this floor (city grate gate); wording
@ deliberately names no visible object -- the staircases render normally,
@ so the line claims nothing the tile does not draw (AFFORDANCE RULE).
ViridianHideout_B1F_EventScript_ExitSealed::
	msgbox ViridianHideout_B1F_Text_ExitSealed, MSGBOX_DEFAULT
	releaseall
	end

ViridianHideout_B1F_EventScript_ExitDecline::
	closemessage
	releaseall
	end

ViridianHideout_B1F_EventScript_DescendToB2F::
	lockall
	goto_if_lt VAR_TRINITY_KANTO_ARC, 3, ViridianHideout_B1F_EventScript_ExitSealed
	msgbox ViridianHideout_B1F_Text_DescendToB2F, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianHideout_B1F_EventScript_ExitDecline
	closemessage
	warp MAP_VIRIDIAN_HIDEOUT_B2F, 18, 16
	waitstate
	end

ViridianHideout_B1F_Text_Grunt1Seen:
	.string "Nobody said the boss's OTHER\nhideout would need guarding too.$"

ViridianHideout_B1F_Text_Grunt1Beaten:
	.string "Ngh! How'd you even find this\nplace?$"

ViridianHideout_B1F_Text_Grunt1PostBattle:
	.string "Go on, then. Won't stop you\nmyself.$"

ViridianHideout_B1F_Text_Grunt2Seen:
	.string "This is a restricted area. Turn\naround while you still can.$"

ViridianHideout_B1F_Text_Grunt2Beaten:
	.string "Guh! Fine, get lost -- deeper\nin, I mean.$"

ViridianHideout_B1F_Text_Grunt2PostBattle:
	.string "Nothing left up here to stop\nyou.$"

ViridianHideout_B1F_Text_Scientist1Seen:
	.string "The boss doesn't like visitors\nnear the lab levels.$"

ViridianHideout_B1F_Text_Scientist1Beaten:
	.string "I'm just hired help! Don't tell\nhim I let you through!$"

ViridianHideout_B1F_Text_Scientist1PostBattle:
	.string "Just -- go. Quietly.$"

ViridianHideout_B1F_Text_ExitToCity:
	.string "The stairs lead back up toward\nthe street.\pClimb up?$"

ViridianHideout_B1F_Text_ExitSealed:
	.string "The way through is shut from\nthe other side. It won't give.$"

ViridianHideout_B1F_Text_DescendToB2F:
	.string "The stairs lead down, deeper\nunder the city.\pKeep going?$"
