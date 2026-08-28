@ ============================================================================
@ Trinity M5b S6 -- ROCKET HIDEOUT B1F. R1-R5 raid pattern (SlowpokeWellB1F's
@ own canonical, extended to Kanto): 3 grunts, ONE shared visibility flag
@ (FLAG_TRINITY_K_HIDEOUT_RAID_HIDE), sight-triggered TRAINER_TYPE_NORMAL
@ (R2). The B1F barrier (D1-D5) mirrors pokefirered's own SetBarrier/
@ RemoveBarrier block shape exactly, at the SAME coordinates, using this
@ tree's own BuildingKanto/SilphCoKanto metatile ids (absolute ids transfer
@ 1:1 from pokefirered's own metatile_labels.h within a combo): Floor=641,
@ Floor_ShadeFull=642, TopLeft_Floor=718, TopRight_Floor=719,
@ BottomLeft=726, BottomRight=727. See 06-celadon-chapter.md section 2.2.
@ ============================================================================
RocketHideout_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, RocketHideout_B1F_OnTransition
	.byte 0

RocketHideout_B1F_OnLoad::
	call_if_unset FLAG_TRINITY_K_HIDEOUT_B1F_DOOR, RocketHideout_B1F_EventScript_SetBarrier
	end

RocketHideout_B1F_OnTransition::
	goto_if_ge VAR_TRINITY_KANTO_ARC, 3, RocketHideout_B1F_EventScript_HideRaidCast
	clearflag FLAG_TRINITY_K_HIDEOUT_RAID_HIDE
	end

RocketHideout_B1F_EventScript_HideRaidCast::
	setflag FLAG_TRINITY_K_HIDEOUT_RAID_HIDE
	end

RocketHideout_B1F_EventScript_SetBarrier::
	setmetatile 20, 19, 718, 1
	setmetatile 21, 19, 719, 1
	setmetatile 20, 20, 726, 1
	setmetatile 21, 20, 727, 1
	setmetatile 20, 21, 642, 0
	setmetatile 21, 21, 642, 0
	return

RocketHideout_B1F_EventScript_RemoveBarrier::
	setmetatile 20, 19, 642, 0
	setmetatile 21, 19, 641, 0
	setmetatile 20, 20, 642, 0
	setmetatile 21, 20, 641, 0
	setmetatile 20, 21, 642, 0
	setmetatile 21, 21, 641, 0
	return

RocketHideout_B1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_K_GRUNT_M_1, RocketHideout_B1F_Text_Grunt1Seen, RocketHideout_B1F_Text_Grunt1Beaten
	msgbox RocketHideout_B1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_K_GRUNT_M_2, RocketHideout_B1F_Text_Grunt2Seen, RocketHideout_B1F_Text_Grunt2Beaten
	msgbox RocketHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

@ F_1 -- the barrier grunt. Her defeat is the B1F door's only trigger (D4);
@ the other two posts carry no barrier logic at all.
RocketHideout_B1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_K_GRUNT_F_1, RocketHideout_B1F_Text_Grunt3Seen, RocketHideout_B1F_Text_Grunt3Beaten, RocketHideout_B1F_EventScript_DefeatedGrunt3
	msgbox RocketHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_EventScript_DefeatedGrunt3::
	setflag FLAG_TRINITY_K_HIDEOUT_B1F_DOOR
	call RocketHideout_B1F_EventScript_RemoveBarrier
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	release
	end

RocketHideout_B1F_Text_Grunt1Seen:
	.string "Two Leagues and you still think\nyou can walk in here?$"

RocketHideout_B1F_Text_Grunt1Beaten:
	.string "Guh! Boss never said anything\nabout THIS.$"

RocketHideout_B1F_Text_Grunt1PostBattle:
	.string "Go on, then. Won't matter --\nthere's more of us below.$"

RocketHideout_B1F_Text_Grunt2Seen:
	.string "This whole floor's ours. Turn\naround while you still can.$"

RocketHideout_B1F_Text_Grunt2Beaten:
	.string "Tch. Lucky hit.$"

RocketHideout_B1F_Text_Grunt2PostBattle:
	.string "Whatever. Go get yourself lost\ndownstairs.$"

RocketHideout_B1F_Text_Grunt3Seen:
	.string "Nobody gets past me without\nthe boss's say-so.$"

RocketHideout_B1F_Text_Grunt3Beaten:
	.string "Fine! FINE! Take the stupid\nbarrier down yourself, then!$"

RocketHideout_B1F_Text_Grunt3PostBattle:
	.string "Go on. Door's open. Doesn't\nmean the rest of us will roll\lover like I did.$"
