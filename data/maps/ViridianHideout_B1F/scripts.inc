@ ============================================================================
@ Trinity M5b S10 -- VIRIDIAN HIDEOUT B1F, the outer raid floor. Full decode +
@ design: docs/superpowers/plans/m5b/10-viridian-climax.md.
@
@ Reuses RocketHideout_B1F's own LAYOUT_ROCKET_HIDEOUT_B1F_KANTO wholesale
@ (S2's registration precedent, forward-noted for this exact slice) -- zero
@ new tile art, zero new blockdata risk. Three raid posts sit at Celadon's
@ own proven-clear tile spots. Both basement exits are scripted bg_event
@ signs (the Magnet Train/Machine Part idiom), not warp_events -- this keeps
@ the whole basement connection graph check-8-transparent regardless of the
@ underlying tile behaviour at either end (see the sub-plan section 3.2/4.1
@ for why a genuine warp_events pair isn't available for the F1<->F2 leg).
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
@ clearing Celadon sees a locked stairwell, not raid content, matching the
@ same posture as ViridianCity's own grate sign). Open, this is the "way
@ back up" -- a plain scripted ride, the OlivinePort/SaffronMagnetTrain shape.
@ FIX ROUND 1 (review Minor 8/9): lockall/releaseall wrapping added
@ (matching CeladonCity_GameCorner_EventScript_Poster:48-58's own
@ precedent), and DescendToB2F below now carries the SAME defensive arc>=3
@ guard as this script -- both are unreachable below arc 3 in practice (the
@ grate itself gates entry to this whole floor), so the asymmetry was inert,
@ but the sealed-hatch flavour text implies a defensive posture that should
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
	.string "A service ladder, leading back\nup toward the street.\pClimb up?$"

ViridianHideout_B1F_Text_ExitSealed:
	.string "A rusted service hatch. It's\nbolted shut from this side.$"

ViridianHideout_B1F_Text_DescendToB2F:
	.string "The passage continues down,\ndeeper under the city.\pKeep going?$"
