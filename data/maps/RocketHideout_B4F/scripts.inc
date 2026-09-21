@ ============================================================================
@ Trinity M5b S6 -- ROCKET HIDEOUT B4F, the inner floor: the two-grunt
@ barrier (D1-D5, mirrors pokefirered's own SetBarrier/RemoveBarrier at the
@ SAME coordinates), the lift-key grunt, and the evidence room (replacing
@ FRLG's Giovanni confrontation -- adapted away, see 06-celadon-chapter.md
@ section 7). Barrier gate: simpler than FR's own VAR_TEMP_1 tally -- each
@ door grunt's defeat script directly tests HasTrainerBeenFought on the
@ OTHER door grunt's id via call_if_defeated (an already-shipped Emerald
@ macro, asm/macros/event.inc:2031); FLAG_TRINITY_K_HIDEOUT_B4F_DOOR is set
@ once, the door's only state (D4).
@ ============================================================================
RocketHideout_B4F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B4F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, RocketHideout_B4F_OnTransition
	.byte 0

RocketHideout_B4F_OnLoad::
	call_if_unset FLAG_TRINITY_K_HIDEOUT_B4F_DOOR, RocketHideout_B4F_EventScript_SetBarrier
	end

RocketHideout_B4F_OnTransition::
	goto_if_ge VAR_TRINITY_KANTO_ARC, 3, RocketHideout_B4F_EventScript_HideRaidCast
	clearflag FLAG_TRINITY_K_HIDEOUT_RAID_HIDE
	end

RocketHideout_B4F_EventScript_HideRaidCast::
	setflag FLAG_TRINITY_K_HIDEOUT_RAID_HIDE
	end

RocketHideout_B4F_EventScript_SetBarrier::
	setmetatile 17, 12, 718, 1
	setmetatile 18, 12, 719, 1
	setmetatile 17, 13, 726, 1
	setmetatile 18, 13, 727, 1
	setmetatile 17, 14, 642, 0
	setmetatile 18, 14, 642, 0
	return

RocketHideout_B4F_EventScript_RemoveBarrier::
	setmetatile 17, 12, 642, 0
	setmetatile 18, 12, 641, 0
	setmetatile 17, 13, 642, 0
	setmetatile 18, 13, 641, 0
	setmetatile 17, 14, 642, 0
	setmetatile 18, 14, 641, 0
	return

@ F_2 -- the lift-key grunt. Key item as flag (M4b Card Key / Machine Part
@ precedent): a direct setflag on defeat, no separate addobject/pickup step.
RocketHideout_B4F_EventScript_Grunt1::
	trainerbattle_single TRAINER_K_GRUNT_F_2, RocketHideout_B4F_Text_Grunt1Seen, RocketHideout_B4F_Text_Grunt1Beaten, RocketHideout_B4F_EventScript_DefeatedGrunt1
	msgbox RocketHideout_B4F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_EventScript_DefeatedGrunt1::
	setflag FLAG_TRINITY_K_LIFT_KEY
	msgbox RocketHideout_B4F_Text_Grunt1FoundKey, MSGBOX_DEFAULT
	release
	end

RocketHideout_B4F_EventScript_Grunt2::
	trainerbattle_single TRAINER_K_GRUNT_M_6, RocketHideout_B4F_Text_Grunt2Seen, RocketHideout_B4F_Text_Grunt2Beaten, RocketHideout_B4F_EventScript_DefeatedGrunt2
	msgbox RocketHideout_B4F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_EventScript_DefeatedGrunt2::
	call_if_defeated TRAINER_K_GRUNT_M_7, RocketHideout_B4F_EventScript_OpenBarrier
	msgbox RocketHideout_B4F_Text_Grunt2PostBattle
	release
	end

RocketHideout_B4F_EventScript_Grunt3::
	trainerbattle_single TRAINER_K_GRUNT_M_7, RocketHideout_B4F_Text_Grunt3Seen, RocketHideout_B4F_Text_Grunt3Beaten, RocketHideout_B4F_EventScript_DefeatedGrunt3
	msgbox RocketHideout_B4F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_EventScript_DefeatedGrunt3::
	call_if_defeated TRAINER_K_GRUNT_M_6, RocketHideout_B4F_EventScript_OpenBarrier
	msgbox RocketHideout_B4F_Text_Grunt3PostBattle
	release
	end

RocketHideout_B4F_EventScript_OpenBarrier::
	setflag FLAG_TRINITY_K_HIDEOUT_B4F_DOOR
	call RocketHideout_B4F_EventScript_RemoveBarrier
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	return

@ M7 Task 9 (finding #17): S6's two invisible "lift platform" signs at
@ (11,16)/(17,17), their crate landmarks, and the "elevator UI has no engine
@ equivalent" premise are gone. The RIGHT component (barrier, door grunts,
@ evidence room) is reached the FRLG way: Lift Key from F_2 (4,2) -> stairs
@ up -> the car on B1F/B2F -> RocketHideout_Elevator's panel -> this floor's
@ door (20,23), emerging on (20,24). See RocketHideout_Elevator/scripts.inc.

@ THE EVIDENCE ROOM. Replaces FRLG's Giovanni-in-the-Hideout confrontation
@ (adapted away, see section 7 -- Trinity's Giovanni stays hidden until
@ Viridian, S10). One combined interaction: the GS BALL seizure and the
@ Viridian-coordinates reveal are two narrated beats inside a single,
@ strictly-linear scene -- no scene var. FIX ROUND (review I4): the original
@ draft claimed a VAR_TRINITY_SCENE_HIDEOUT_EVIDENCE 0/1/2 sequence but never
@ actually branched on it or wrote 1 anywhere -- a dead claim. Un-claimed
@ (var restored to VAR_UNUSED_0x409B, see vars.h) rather than built out for
@ its own sake: the object's own map.json "flag" field IS
@ FLAG_TRINITY_K_GS_BALL, so the engine auto-hides this prop the instant it
@ is set (same idiom as every other key-item-as-flag pickup this tree), and
@ a hidden object can never be walked up to and re-interacted -- there is no
@ real "re-entry" case for a scene var to disambiguate. The durable write
@ (arc->3) lands FIRST, S4's I3(b) ordering rule: once-only guarded,
@ HallOfFame's own shape (S5's own precedent for this exact idiom).
@ INTENTIONALLY DEFENSIVE: the goto_if_ge below is dead code in ordinary
@ play, for the same reason (nothing can ever re-trigger this label after
@ the object hides) -- kept as a guard against any future script elsewhere
@ ever calling this label directly.
RocketHideout_B4F_EventScript_Evidence::
	lockall
	msgbox RocketHideout_B4F_Text_EvidenceSeized, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_K_GS_BALL
	msgbox RocketHideout_B4F_Text_EvidenceCoordinates, MSGBOX_DEFAULT
	goto_if_ge VAR_TRINITY_KANTO_ARC, 3, RocketHideout_B4F_EventScript_EvidenceDone
	setvar VAR_TRINITY_KANTO_ARC, 3

RocketHideout_B4F_EventScript_EvidenceDone::
	releaseall
	end

RocketHideout_B4F_Text_Grunt1Seen:
	.string "This corner's mine. Nobody\ntouches the boss's mail.$"

RocketHideout_B4F_Text_Grunt1Beaten:
	.string "Ngh! Fine, take it. Wasn't\nsupposed to be carrying it\lon me anyway.$"

RocketHideout_B4F_Text_Grunt1PostBattle:
	.string "Go on. Not like it matters\nnow.$"

RocketHideout_B4F_Text_Grunt1FoundKey:
	.string "She was carrying a KEY.\pIt fits the lift -- the elevator\nup on B1F and B2F. Ride it\ldown to reach the rest of this\lfloor.$"

RocketHideout_B4F_Text_Grunt2Seen:
	.string "Nobody gets past this door\nwithout my say-so.$"

RocketHideout_B4F_Text_Grunt2Beaten:
	.string "Guh! One of us isn't enough\nto hold this door, huh.$"

RocketHideout_B4F_Text_Grunt2PostBattle:
	.string "Go find my partner, then. Won't\nmatter till you've beaten us both.$"

RocketHideout_B4F_Text_Grunt3Seen:
	.string "Two of us on this door. You'll\nneed to beat us both.$"

RocketHideout_B4F_Text_Grunt3Beaten:
	.string "Argh! That's... both of us,\nthen. Door's yours.$"

RocketHideout_B4F_Text_Grunt3PostBattle:
	.string "Go on. Nothing left to stop\nyou here.$"

RocketHideout_B4F_Text_EvidenceSeized:
	.string "A locked case sits open on the\ndesk -- someone left in a hurry.\pInside: a strange, round POKé\nBALL unlike anything you've seen.\lYou take the GS BALL.$"

RocketHideout_B4F_Text_EvidenceCoordinates:
	.string "Papers scattered across the desk\nname a warehouse under VIRIDIAN\lCITY -- coordinates, shift\lschedules, a chain of command.\pWhoever runs this operation\nanswers to someone in VIRIDIAN.$"


