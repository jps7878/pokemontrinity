@ ============================================================================
@ Trinity M5b S6 -- ROCKET HIDEOUT B2F, the first spin-maze floor. 1 grunt
@ (R2, matching pokefirered's own single-grunt B2F design -- a simple
@ encounter, not embedded in the pad field), same R1 shared raid-hide flag.
@ The 42 slide pads themselves need no scripting at all -- their behaviour is
@ tileset data (06-celadon-chapter.md section 1), not map script. See
@ section 1.4 for the full hand-verified per-pad routing table and section
@ 2.3 for placement.
@ ============================================================================
RocketHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RocketHideout_B2F_OnTransition
	.byte 0

RocketHideout_B2F_OnTransition::
	goto_if_ge VAR_TRINITY_KANTO_ARC, 3, RocketHideout_B2F_EventScript_HideRaidCast
	clearflag FLAG_TRINITY_K_HIDEOUT_RAID_HIDE
	end

RocketHideout_B2F_EventScript_HideRaidCast::
	setflag FLAG_TRINITY_K_HIDEOUT_RAID_HIDE
	end

RocketHideout_B2F_EventScript_Grunt::
	trainerbattle_single TRAINER_K_GRUNT_M_3, RocketHideout_B2F_Text_GruntSeen, RocketHideout_B2F_Text_GruntBeaten
	msgbox RocketHideout_B2F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B2F_Text_GruntSeen:
	.string "Watch your step. Those floor\ntiles aren't just decoration.$"

RocketHideout_B2F_Text_GruntBeaten:
	.string "Argh! Should've spun you into\na wall instead.$"

RocketHideout_B2F_Text_GruntPostBattle:
	.string "Go on, then. See how far the\nfloor gets you.$"
