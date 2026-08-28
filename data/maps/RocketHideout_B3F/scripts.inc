@ ============================================================================
@ Trinity M5b S6 -- ROCKET HIDEOUT B3F, the second spin-maze floor. 2 grunts
@ (R2), same R1 shared raid-hide flag. 16 slide pads, tileset data only --
@ see 06-celadon-chapter.md section 1.4 for the full routing table.
@ ============================================================================
RocketHideout_B3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RocketHideout_B3F_OnTransition
	.byte 0

RocketHideout_B3F_OnTransition::
	goto_if_ge VAR_TRINITY_KANTO_ARC, 3, RocketHideout_B3F_EventScript_HideRaidCast
	clearflag FLAG_TRINITY_K_HIDEOUT_RAID_HIDE
	end

RocketHideout_B3F_EventScript_HideRaidCast::
	setflag FLAG_TRINITY_K_HIDEOUT_RAID_HIDE
	end

RocketHideout_B3F_EventScript_Grunt1::
	trainerbattle_single TRAINER_K_GRUNT_M_4, RocketHideout_B3F_Text_Grunt1Seen, RocketHideout_B3F_Text_Grunt1Beaten
	msgbox RocketHideout_B3F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_EventScript_Grunt2::
	trainerbattle_single TRAINER_K_GRUNT_M_5, RocketHideout_B3F_Text_Grunt2Seen, RocketHideout_B3F_Text_Grunt2Beaten
	msgbox RocketHideout_B3F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_Text_Grunt1Seen:
	.string "Boss is right below us. You're\nnot getting there.$"

RocketHideout_B3F_Text_Grunt1Beaten:
	.string "H-hey! That's not fair!$"

RocketHideout_B3F_Text_Grunt1PostBattle:
	.string "Whatever. There's still the\ndoor grunts downstairs.$"

RocketHideout_B3F_Text_Grunt2Seen:
	.string "You're deeper than most\ntrainers get. Not deep enough.$"

RocketHideout_B3F_Text_Grunt2Beaten:
	.string "Ngh! Fine, go. Not like I\nwas guarding anything good.$"

RocketHideout_B3F_Text_Grunt2PostBattle:
	.string "Just go. Down the stairs,\nif you're that desperate.$"
