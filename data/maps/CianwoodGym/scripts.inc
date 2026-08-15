CianwoodGym_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S6 -- CIANWOOD GYM. THE GYM PATTERN (G1-G7), copied from
@ data/maps/VioletGym/scripts.inc, whose header carries the full rationale.
@ Substituted here: CHUCK, FLAG_TRINITY_BADGE13, TM01 FOCUS PUNCH, FIGHTING.
@
@ NO ON_TRANSITION AND NO VISIBILITY FLAG. CHUCK is in his gym from the moment
@ the player can reach CIANWOOD and he never leaves it, so there is nothing for
@ a transition to author. His object flag is 0 and nothing removeobject's him.
@
@ GSC BEAT DELIBERATELY SKIPPED, logged per the contract: the four STRENGTH
@ boulders at (5,1) (3,7) (4,7) (5,7) and CHUCK's boulder-hurling intro
@ (applymovement CIANWOODGYM_BOULDER1 / playsound SFX_STRENGTH / earthquake 80 /
@ disappear). M4a never ported the boulders, and a one-shot prop would need its
@ own visibility flag -- removeobject FlagSet's the object's flag
@ (src/event_object_movement.c:1537-1545) and `flag: 0` would set flag 0 -- so
@ that is a whole registry claim spent on one sound effect. Per the slice brief,
@ CHUCK's theatre becomes a FLAVOUR LINE, never a mechanic: GSC's three intro
@ texts are folded into the single intro-text argument of `trainerbattle_single`
@ (backticked -- qa_sweep's TRAINERBATTLE_RE reads bare tokens in comments too),
@ so G2's "exactly three labels" is untouched, and the boulder is
@ replaced by the thing CHUCK is actually famous for -- standing under the falls
@ north of town.
@
@ ROSTER CHECK (the ledger's data-verification rule), recorded even though no
@ NPC in this room states a matchup, so that nothing written here can drift:
@ CHUCK is HITMONCHAN 63 / HITMONLEE 63 / HARIYAMA 64 / MACHAMP 65 /
@ POLIWRATH 66. The first four are MON_TYPES(TYPE_FIGHTING); POLIWRATH is
@ MON_TYPES(TYPE_WATER, TYPE_FIGHTING). FLYING->FIGHTING, PSYCHIC->FIGHTING and
@ FAIRY->FIGHTING are each 2.0 and WATER resists none of them (all 1.0), so
@ FLYING, PSYCHIC and FAIRY are 2x on ALL FIVE -- the only clean sweep in the
@ gym. LEVEL BAND, honestly: CHUCK's ace is L66 and his four BLACK BELTs run
@ L66-68 (YOSHI 68, LAO 68, NOB 67/68, LUNG 66/67/68), the same
@ leader-below-mook inversion S5 found in ECRUTEAK. M6 balance item.
@ ============================================================================

@ ============================================================================
@ G1/G2/G3 -- CHUCK. Talk-triggered, TRAINER_TYPE_NONE, sight 0, appended to
@ object_events so M4a's four BLACK BELT local ids do not shift. GSC's tile
@ (4,1), decoded MB_NORMAL collision 0 elevation 3. (4,1)/(5,1) is a two-tile
@ alcove hanging off row 2 (row 1 decodes collision 1 at x=3 and x=6), so
@ standing on (4,1) leaves (5,1) reachable from (5,2): a one-tile loss, his own.
@ ============================================================================
CianwoodGym_EventScript_Chuck::
	trainerbattle_single TRAINER_CHUCK, CianwoodGym_Text_ChuckIntro, CianwoodGym_Text_ChuckDefeat, CianwoodGym_EventScript_ChuckDefeated, NO_MUSIC
	@ Re-talk path only: the engine's trainer-defeated flag already gated the
	@ continuation above, so execution reaches here on a LATER talk. Retry the
	@ TM if the bag was full the first time, else the post-badge line.
	goto_if_unset FLAG_TRINITY_J_CHUCK_TM01, CianwoodGym_EventScript_GiveFocusPunch
	msgbox CianwoodGym_Text_ChuckPostBattle, MSGBOX_DEFAULT
	release
	end

CianwoodGym_EventScript_ChuckDefeated::
	message CianwoodGym_Text_ReceivedStormBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_TRINITY_BADGE13
	msgbox CianwoodGym_Text_StormBadgeInfo, MSGBOX_DEFAULT
	goto CianwoodGym_EventScript_GiveFocusPunch
	end

CianwoodGym_EventScript_GiveFocusPunch::
	giveitem ITEM_TM_FOCUS_PUNCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_J_CHUCK_TM01
	msgbox CianwoodGym_Text_ExplainFocusPunch, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ G6 -- M4a's four gym trainers keep their ids, GSC tiles ((2,12) (7,12) (3,9)
@ (5,5)), GSC sight radii (3/3/2/1) and seen/beaten text, and each gains GSC's
@ own distinct after-battle line (the port left all four re-showing the beaten
@ text). They are sight-triggered, so G3's NO_MUSIC does not apply -- the
@ encounter BGM swap is exactly what a sight line is for.
@ ============================================================================
CianwoodGym_EventScript_YOSHI::
	trainerbattle_single TRAINER_JOHTO_BLACKBELT_T_YOSHI, CianwoodGym_Text_YOSHISeen, CianwoodGym_Text_YOSHIBeaten
	msgbox CianwoodGym_Text_YOSHIAfterBattle, MSGBOX_AUTOCLOSE
	end

CianwoodGym_EventScript_LAO::
	trainerbattle_single TRAINER_JOHTO_BLACKBELT_T_LAO, CianwoodGym_Text_LAOSeen, CianwoodGym_Text_LAOBeaten
	msgbox CianwoodGym_Text_LAOAfterBattle, MSGBOX_AUTOCLOSE
	end

CianwoodGym_EventScript_NOB::
	trainerbattle_single TRAINER_JOHTO_BLACKBELT_T_NOB, CianwoodGym_Text_NOBSeen, CianwoodGym_Text_NOBBeaten
	msgbox CianwoodGym_Text_NOBAfterBattle, MSGBOX_AUTOCLOSE
	end

CianwoodGym_EventScript_LUNG::
	trainerbattle_single TRAINER_JOHTO_BLACKBELT_T_LUNG, CianwoodGym_Text_LUNGSeen, CianwoodGym_Text_LUNGBeaten
	msgbox CianwoodGym_Text_LUNGAfterBattle, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ G5 -- (3,15) and (6,15) decode collision 1: GSC's two statue wall tiles, read
@ facing north from (3,16)/(6,16), both collision 0 elevation 3 and both left
@ clear of objects (S5's I1 pin -- a facing bg_event on a collision-1 tile has
@ exactly one reading tile and reach_check cannot see it).
@ ONE entry script for BOTH bg_events, per S5's statue dedupe.
@ ============================================================================
CianwoodGym_EventScript_GymStatues::
	lockall
	goto_if_set FLAG_TRINITY_BADGE13, CianwoodGym_EventScript_GymStatueCertified
	msgbox CianwoodGym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

CianwoodGym_EventScript_GymStatueCertified::
	msgbox CianwoodGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@ Text
@ ============================================================================
@ Folds GSC's ChuckIntroText1/2/3 into one string. The boulder CHUCK throws in
@ GSC does not exist in this port, so the demonstration becomes the waterfall he
@ trains under -- flavour, not a mechanic (see the header).
CianwoodGym_Text_ChuckIntro:
	.string "WAHAHAH! So you've come this far!\p"
	.string "Let me tell you something about me.\n"
	.string "I'm tough. My POKéMON crush stones\l"
	.string "and shatter bones!\p"
	.string "See the falls north of town? I stand\n"
	.string "under them. Every morning. All year.\p"
	.string "What? It has nothing to do with\n"
	.string "POKéMON?\p"
	.string "WAHAHAH! That's true! Come on then.\n"
	.string "We shall do battle!$"

@ GSC ChuckLossText.
CianwoodGym_Text_ChuckDefeat:
	.string "Wha? Huh? I lost?\p"
	.string "How about that! You're worthy of\n"
	.string "the STORMBADGE!$"

CianwoodGym_Text_ReceivedStormBadge:
	.string "{PLAYER} received the STORMBADGE\n"
	.string "from CHUCK!$"

@ Badges 9-16 are plain flags with no engine UI, so this must promise no
@ mechanical effect -- GSC's "makes POKéMON up to L70 obey and lets you use FLY"
@ is dropped outright. It must also not COUNT badges: the Johto gyms are
@ open-order in Trinity.
CianwoodGym_Text_StormBadgeInfo:
	.string "CHUCK: The STORMBADGE won't make\n"
	.string "one POKéMON of yours hit harder.\p"
	.string "It's a mark. It says you stood in\n"
	.string "front of me and didn't step back.\p"
	.string "Get eight out of JOHTO and INDIGO\n"
	.string "has to let you in. That's the rule\l"
	.string "and I didn't write it.$"

@ TM award dialogue must never presume novelty (S3-S9 rule): gym TM awards
@ duplicate Act I sources, so the player may already own FOCUS PUNCH.
CianwoodGym_Text_ExplainFocusPunch:
	.string "CHUCK: Take this too!\p"
	.string "FOCUS PUNCH. You plant your feet\n"
	.string "and you wind up, and if anything\l"
	.string "touches you first it all comes to\l"
	.string "nothing.\p"
	.string "Every fighting man hands this on,\n"
	.string "so mine may not be your first copy.\p"
	.string "Doesn't matter. Throw it like you\n"
	.string "mean it!$"

@ GSC ChuckAfterText.
CianwoodGym_Text_ChuckPostBattle:
	.string "WAHAHAH! I enjoyed battling you!\p"
	.string "But a loss is a loss. From now on\n"
	.string "I'm training twenty-four hours a\l"
	.string "day. Come back and find out!$"

CianwoodGym_Text_YOSHISeen:
	.string "My POKéMON and I\nare bound togeth-\ler by friendship.\pOur bond will\nnever be broken!$"

CianwoodGym_Text_YOSHIBeaten:
	.string "This isn't real!$"

@ GSC BlackbeltYoshiAfterText.
CianwoodGym_Text_YOSHIAfterBattle:
	.string "You seem to have a strong bond with\n"
	.string "your POKéMON too.$"

CianwoodGym_Text_LAOSeen:
	.string "We martial artists\nfear nothing!$"

CianwoodGym_Text_LAOBeaten:
	.string "That's shocking!$"

@ GSC BlackbeltLaoAfterText. True in this build: every mon in this room is
@ FIGHTING, and gTypeEffectivenessTable[TYPE_PSYCHIC][TYPE_FIGHTING] is 2.0.
CianwoodGym_Text_LAOAfterBattle:
	.string "Fighting POKéMON are afraid of\n"
	.string "psychics…$"

CianwoodGym_Text_NOBSeen:
	.string "Words are useless.\nLet your fists do\lthe talking!$"

CianwoodGym_Text_NOBBeaten:
	.string "…$"

@ GSC BlackbeltNobAfterText.
CianwoodGym_Text_NOBAfterBattle:
	.string "I lost! I'm speechless!$"

CianwoodGym_Text_LUNGSeen:
	.string "My raging fists\nwill shatter your\lPOKéMON!$"

CianwoodGym_Text_LUNGBeaten:
	.string "I got shattered!$"

@ GSC BlackbeltLungAfterText.
CianwoodGym_Text_LUNGAfterBattle:
	.string "My POKéMON lost… My… my pride is\n"
	.string "shattered…$"

CianwoodGym_Text_GymStatue:
	.string "CIANWOOD POKéMON GYM\n"
	.string "LEADER: CHUCK\p"
	.string "His Roaring Fists Do the Talking$"

CianwoodGym_Text_GymStatueCertified:
	.string "CIANWOOD POKéMON GYM\n"
	.string "LEADER: CHUCK\p"
	.string "His Roaring Fists Do the Talking\p"
	.string "{PLAYER} won the STORMBADGE here.$"
