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

@ ============================================================================
@ SELF-CAUGHT (reach_check.py per-map decode, before shipping): B4F's static
@ collision graph is TWO disconnected components -- byte-identical to
@ pokefirered's own shipped map.bin (decoded and diff'd directly, not
@ assumed), so this is a genuine FRLG geometry fact, not a T10 port defect.
@ The B3F stairway (11,15) lands in the LEFT component (138 tiles); the
@ barrier, both door grunts, and the evidence room all sit in the RIGHT
@ component, reachable in real FRLG only via the elevator. Since the full
@ elevator floor-select UI has no engine equivalent in this tree (section 7,
@ skipped), a minimal two-sign lift shuttle bridges exactly this one
@ required transition -- gated on FLAG_TRINITY_K_LIFT_KEY on the way in
@ (matching FRLG's own FLAG_CAN_USE_ROCKET_HIDEOUT_LIFT gate), ungated on
@ the way back (a player standing on the right side has necessarily already
@ used the key). `warp <map>, x, y` mid-script is the same primitive every
@ ordinary warp_event uses (BattleFrontier_BattleArenaCorridor/scripts.inc's
@ own shape, warp + waitstate + end, no manual fadescreen needed -- the
@ transition has its own built-in fade). Both landing tiles decoded fresh:
@ (17,18) col=0 elev=3 MB_NORMAL (right side, reachable only via this
@ shuttle); (11,17) col=0 elev=3 MB_NORMAL (left side, part of the 138-tile
@ stairway-reachable region).
@ ============================================================================
RocketHideout_B4F_EventScript_LiftPlatformLeft::
	lockall
	goto_if_unset FLAG_TRINITY_K_LIFT_KEY, RocketHideout_B4F_EventScript_LiftNeedsKey
	msgbox RocketHideout_B4F_Text_LiftPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RocketHideout_B4F_EventScript_LiftCancel
	warp MAP_ROCKET_HIDEOUT_B4F, 17, 18
	waitstate
	end

RocketHideout_B4F_EventScript_LiftNeedsKey::
	msgbox RocketHideout_B4F_Text_LiftNeedsKey, MSGBOX_DEFAULT
	releaseall
	end

RocketHideout_B4F_EventScript_LiftCancel::
	releaseall
	end

RocketHideout_B4F_EventScript_LiftPlatformRight::
	lockall
	msgbox RocketHideout_B4F_Text_LiftReturnPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RocketHideout_B4F_EventScript_LiftCancel
	warp MAP_ROCKET_HIDEOUT_B4F, 11, 17
	waitstate
	end

@ THE EVIDENCE ROOM. Replaces FRLG's Giovanni-in-the-Hideout confrontation
@ (adapted away, see section 7 -- Trinity's Giovanni stays hidden until
@ Viridian, S10). One combined interaction: the GS BALL seizure and the
@ Viridian-coordinates reveal are two narrated beats inside a single scene
@ (VAR_TRINITY_SCENE_HIDEOUT_EVIDENCE sequences them), not a two-prop
@ examine-in-order puzzle -- there is no gameplay reason to split them.
@ The durable write (arc->3) lands FIRST, S4's I3(b) ordering rule: once-only
@ guarded, HallOfFame's own shape (S5's own precedent for this exact idiom).
@ INTENTIONALLY DEFENSIVE: the goto_if_ge below is dead code in ordinary
@ play -- the object's own map.json "flag" field IS FLAG_TRINITY_K_GS_BALL,
@ so the engine auto-hides this prop the instant it is set (same idiom as
@ every other key-item-as-flag pickup this tree), and a hidden object can
@ never be walked up to and re-interacted. Kept anyway as a guard against
@ any future script elsewhere ever calling this label directly.
RocketHideout_B4F_EventScript_Evidence::
	lockall
	msgbox RocketHideout_B4F_Text_EvidenceSeized, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_K_GS_BALL
	msgbox RocketHideout_B4F_Text_EvidenceCoordinates, MSGBOX_DEFAULT
	goto_if_ge VAR_TRINITY_KANTO_ARC, 3, RocketHideout_B4F_EventScript_EvidenceDone
	setvar VAR_TRINITY_KANTO_ARC, 3
	setvar VAR_TRINITY_SCENE_HIDEOUT_EVIDENCE, 2

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
	.string "She was carrying a KEY.\pSomething for the restricted\nlift -- not that it'll do you\lmuch good from here.$"

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

RocketHideout_B4F_Text_LiftPrompt:
	.string "The old service lift hums to\nlife when you fit the key in.\pRide it down?$"

RocketHideout_B4F_Text_LiftNeedsKey:
	.string "An old service lift, powered\ndown. It needs a key you don't\lhave yet.$"

RocketHideout_B4F_Text_LiftReturnPrompt:
	.string "Ride the lift back up?$"
