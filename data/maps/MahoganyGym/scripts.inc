MahoganyGym_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S7 -- MAHOGANY GYM. THE GYM PATTERN (G1-G7), copied from
@ data/maps/VioletGym/scripts.inc, whose header carries the full rationale.
@ Substituted here: PRYCE, FLAG_TRINITY_BADGE15, TM07 HAIL, ICE.
@
@ NO ON_TRANSITION AND NO VISIBILITY FLAG. PRYCE is in his gym from the moment
@ the player can reach MAHOGANY and he never leaves it; his object flag is 0
@ and nothing removeobject's him.
@
@ THE ICE PUZZLE IS TILESET COLLISION, NOT SCRIPT, in both games. GSC's
@ MahoganyGym.asm touches the floor exactly nowhere; the sliding comes from
@ blocks whose four quadrants are ICE (block $39) and the "stop" blocks that
@ carry one FLOOR quadrant ($2e/$2f/$31/$32). M4a's port carried it across
@ intact: decoded, rows 2-13 are MB_ICE with MB_NORMAL stop tiles at (3,4),
@ (5,4), (6,2), (6,5) and so on. Nothing to port, and nothing to script.
@
@ ROSTER CHECK (the ledger's data-verification rule -- this is the third
@ occurrence of the defect class it exists to prevent, so the derivation is
@ written down rather than trusted):
@   GLALIE    MON_TYPES(TYPE_ICE)
@   DEWGONG   MON_TYPES(TYPE_WATER, TYPE_ICE)
@   CLOYSTER  MON_TYPES(TYPE_WATER, TYPE_ICE)
@   LAPRAS    MON_TYPES(TYPE_WATER, TYPE_ICE)
@   PILOSWINE MON_TYPES(TYPE_ICE, TYPE_GROUND)
@ FIGHTING->ICE is 2.0 and FIGHTING is neutral into both WATER and GROUND, so
@ FIGHTING is 2x on ALL FIVE -- the only type that is. ELECTRIC is 2x on the
@ three WATER/ICE, NEUTRAL on GLALIE, and PILOSWINE's GROUND half makes it
@ IMMUNE, which is the trap worth warning about. ROCK is 2x on four and merely
@ neutral on PILOSWINE (ROCK->GROUND 0.5 cancels ROCK->ICE 2.0); FIRE and STEEL
@ are both cancelled to 1.0 on the three WATER/ICE. The guide says exactly this
@ and nothing more.
@ LEVEL BAND: PRYCE is L67-70 and his five gym trainers run L67-69, so for once
@ the leader is not below his own mooks (S5's ECRUTEAK inversion, S6's CIANWOOD
@ inversion). The guide states the band.
@ ============================================================================

@ ============================================================================
@ G1/G2/G3 -- PRYCE. Talk-triggered, TRAINER_TYPE_NONE, sight 0, APPENDED to
@ object_events so M4a's six local ids do not shift. GSC's tile (5,3), decoded
@ collision 0 elevation 3 MB_ICE. He stands ON the ice, as in GSC; the player
@ stops one tile south on (5,4), which decodes MB_NORMAL -- one of the puzzle's
@ own stop tiles -- and talks north. A resting NPC does not slide, and the
@ flood fill shows him costing exactly his own tile.
@ ============================================================================
MahoganyGym_EventScript_Pryce::
	trainerbattle_single TRAINER_PRYCE, MahoganyGym_Text_PryceIntro, MahoganyGym_Text_PryceDefeat, MahoganyGym_EventScript_PryceDefeated, NO_MUSIC
	@ Re-talk path only: the engine's per-id defeated flag already gated the
	@ continuation above, so execution reaches here on a LATER talk. Retry the
	@ TM if the bag was full the first time, else the post-badge line.
	goto_if_unset FLAG_TRINITY_J_PRYCE_TM07, MahoganyGym_EventScript_GiveHail
	msgbox MahoganyGym_Text_PrycePostBattle, MSGBOX_DEFAULT
	release
	end

@ G2/G7: the badge is set INSIDE the continuation and BEFORE the TM, so a full
@ bag or a player walking out can never cost progression, and this is the only
@ site in the game that WRITES FLAG_TRINITY_BADGE15.
MahoganyGym_EventScript_PryceDefeated::
	message MahoganyGym_Text_ReceivedGlacierBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_TRINITY_BADGE15
	msgbox MahoganyGym_Text_GlacierBadgeInfo, MSGBOX_DEFAULT
	goto MahoganyGym_EventScript_GiveHail
	end

MahoganyGym_EventScript_GiveHail::
	giveitem ITEM_TM_HAIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_J_PRYCE_TM07
	msgbox MahoganyGym_Text_ExplainHail, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ G6 -- M4a's five gym trainers keep their ids, GSC tiles and seen/beaten text,
@ and each gains GSC's own distinct after-battle line (the port left all five
@ re-showing the beaten text as their post-battle line). Sight-triggered, so
@ G3's NO_MUSIC does not apply -- the encounter BGM swap is what a sight line
@ is for.
@
@ GSC's PRYCE also `setevent`s all five as beaten the moment he loses, so they
@ never re-challenge on the way out. NOT ported: a trainer id carries ONE
@ permanent per-id flag (R3b), and pre-setting five of them would silently
@ delete five battles for a player who fought PRYCE first -- which the ice
@ puzzle makes perfectly possible. Sliding past a trainer is a reward for
@ solving the floor, not a bug to paper over.
@ ============================================================================
MahoganyGym_EventScript_ROXANNE::
	trainerbattle_single TRAINER_JOHTO_SKIER_ROXANNE, MahoganyGym_Text_ROXANNESeen, MahoganyGym_Text_ROXANNEBeaten
	msgbox MahoganyGym_Text_ROXANNEAfterBattle, MSGBOX_AUTOCLOSE
	end

MahoganyGym_EventScript_RONALD::
	trainerbattle_single TRAINER_JOHTO_BOARDER_RONALD, MahoganyGym_Text_RONALDSeen, MahoganyGym_Text_RONALDBeaten
	msgbox MahoganyGym_Text_RONALDAfterBattle, MSGBOX_AUTOCLOSE
	end

MahoganyGym_EventScript_CLARISSA::
	trainerbattle_single TRAINER_JOHTO_SKIER_CLARISSA, MahoganyGym_Text_CLARISSASeen, MahoganyGym_Text_CLARISSABeaten
	msgbox MahoganyGym_Text_CLARISSAAfterBattle, MSGBOX_AUTOCLOSE
	end

MahoganyGym_EventScript_BRAD::
	trainerbattle_single TRAINER_JOHTO_BOARDER_BRAD, MahoganyGym_Text_BRADSeen, MahoganyGym_Text_BRADBeaten
	msgbox MahoganyGym_Text_BRADAfterBattle, MSGBOX_AUTOCLOSE
	end

MahoganyGym_EventScript_DOUGLAS::
	trainerbattle_single TRAINER_JOHTO_BOARDER_DOUGLAS, MahoganyGym_Text_DOUGLASSeen, MahoganyGym_Text_DOUGLASBeaten
	msgbox MahoganyGym_Text_DOUGLASAfterBattle, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ G4 -- the guide, two states on the badge flag. He is at M4a's (7,15), which
@ is the BOTTOM of the x=7 column (rows 13-15, walls at x=6 and x=8) -- but
@ unlike VIOLET's and OLIVINE's guides he is not a cut vertex, because that
@ column is open at BOTH ends: (7,16) is walkable and so is (7,13). The flood
@ fill confirms it, one tile lost, his own. The S6 pin says to check the column
@ before placing a guide; this is that check.
@ ============================================================================
MahoganyGym_EventScript_Guide::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_BADGE15, MahoganyGym_EventScript_GuideWin
	msgbox MahoganyGym_Text_Guide, MSGBOX_DEFAULT
	release
	end

@ M7b Task 15 (finding #6): the guide states the player's LIVE badge count.
@ The tally reads the flags and buffers the number itself -- see
@ data/scripts/trinity_johto.inc.
MahoganyGym_EventScript_GuideWin::
	msgbox MahoganyGym_Text_GuideWin, MSGBOX_DEFAULT
	call Trinity_EventScript_JohtoBadgeTally
	@ M7b Task 14 (finding #9): once the badge is won this guide doubles as
	@ a pointer. The branch above is already the badge flag, so nothing new
	@ is read or written here; the ladder releases for us.
	goto Trinity_EventScript_JohtoGuide
	end

@ ============================================================================
@ G5 -- (3,15) and (6,15) decode collision 1: GSC's two statue tiles, read
@ facing north from (3,16) and (6,16), both collision 0 elevation 3 and both
@ left clear of objects (S5's I1 pin -- a facing bg_event on a collision-1 tile
@ has exactly one reading tile and reach_check cannot see it).
@ ONE entry script for BOTH bg_events, per S5's statue dedupe.
@ ============================================================================
MahoganyGym_EventScript_GymStatues::
	lockall
	goto_if_set FLAG_TRINITY_BADGE15, MahoganyGym_EventScript_GymStatueCertified
	msgbox MahoganyGym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MahoganyGym_EventScript_GymStatueCertified::
	msgbox MahoganyGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@ Text. GSC's PryceText_Intro is kept almost whole -- it is the best-written
@ leader speech in JOHTO -- with its two stray trailing spaces removed.
@ ============================================================================
MahoganyGym_Text_PryceIntro:
	.string "POKéMON have many experiences in\n"
	.string "their lives, just as we do.\p"
	.string "I, too, have seen and suffered\n"
	.string "much in mine.\p"
	.string "Since I am your elder, let me show\n"
	.string "you what I mean.\p"
	.string "I have been with POKéMON since\n"
	.string "before you were born. Before your\l"
	.string "parents were born.\p"
	.string "I do not lose easily.\p"
	.string "I, PRYCE -- the winter trainer --\n"
	.string "shall demonstrate my power!$"

MahoganyGym_Text_PryceDefeat:
	.string "Ah. I am impressed by your\n"
	.string "prowess.\p"
	.string "With a will like that, I know you\n"
	.string "will overcome all life's\l"
	.string "obstacles.\p"
	.string "You are worthy of this BADGE.$"

MahoganyGym_Text_ReceivedGlacierBadge:
	.string "{PLAYER} received the\n"
	.string "GLACIERBADGE from PRYCE!$"

@ The badge-meaning line must not promise a mechanical effect: badges 9-16 are
@ plain flags with no engine UI (the ledger's rule). GSC's version here also
@ promises WHIRLPOOL, which does not exist in this build at all -- so the
@ promise is dropped entirely rather than quietly falsified.
MahoganyGym_Text_GlacierBadgeInfo:
	.string "The GLACIERBADGE will not make\n"
	.string "your POKéMON one point stronger.\p"
	.string "It is a record that an old man in\n"
	.string "a cold town could not stop you.\p"
	.string "Eight of those and INDIGO PLATEAU\n"
	.string "will open its doors. That is what\l"
	.string "they are for.$"

@ TM award dialogue must never presume novelty (the S3-S9 rule): every gym TM
@ duplicates an Act I source, so this reads correctly whether it is the
@ player's first copy or their fourth.
MahoganyGym_Text_ExplainHail:
	.string "That TM is HAIL.\p"
	.string "It calls the weather I have spent\n"
	.string "fifty years standing in.\p"
	.string "It wears at everything on the\n"
	.string "field except the ones built for\l"
	.string "it. Ice-types do not feel it.\p"
	.string "Bring the winter with you and you\n"
	.string "choose who has to endure it.$"

MahoganyGym_Text_PrycePostBattle:
	.string "When the ice and snow melt, spring\n"
	.string "arrives.\p"
	.string "You and your POKéMON will be\n"
	.string "together for many years to come.\p"
	.string "Cherish your time together.$"

MahoganyGym_Text_Guide:
	.string "PRYCE has trained POKéMON for some\n"
	.string "fifty years. Fifty!\p"
	.string "Every one of his is part ICE, and\n"
	.string "they run from level 67 up to a\l"
	.string "PILOSWINE at 70.\p"
	.string "FIGHTING moves hit all five of\n"
	.string "them hard. That's the clean answer.\p"
	.string "ELECTRIC looks clever -- three of\n"
	.string "them are half WATER -- but that\l"
	.string "PILOSWINE is half GROUND and won't\l"
	.string "feel a spark of it.\p"
	.string "So melt him with your burning\n"
	.string "ambition!$"

MahoganyGym_Text_GuideWin:
	.string "PRYCE is something, but you're\n"
	.string "something else!\p"
	.string "That was a hot battle that bridged\n"
	.string "the generation gap!$"

MahoganyGym_Text_GymStatue:
	.string "MAHOGANY TOWN POKéMON GYM\n"
	.string "LEADER: PRYCE\p"
	.string "The Teacher of Winter's Harshness$"

MahoganyGym_Text_GymStatueCertified:
	.string "MAHOGANY TOWN POKéMON GYM\n"
	.string "LEADER: PRYCE\p"
	.string "WINNING TRAINERS:\n"
	.string "{PLAYER}$"

MahoganyGym_Text_ROXANNESeen:
	.string "To get to PRYCE, our GYM LEADER,\n"
	.string "you need to think before you\l"
	.string "skate.$"

MahoganyGym_Text_ROXANNEBeaten:
	.string "I wouldn't lose to you in skiing!$"

MahoganyGym_Text_ROXANNEAfterBattle:
	.string "If you don't skate with precision,\n"
	.string "you won't get far in this GYM.$"

MahoganyGym_Text_RONALDSeen:
	.string "I'll freeze your POKéMON, so you\n"
	.string "can't do a thing!$"

MahoganyGym_Text_RONALDBeaten:
	.string "Darn. I couldn't do a thing.$"

MahoganyGym_Text_RONALDAfterBattle:
	.string "I think there's a move a POKéMON\n"
	.string "can use while it's frozen.$"

MahoganyGym_Text_CLARISSASeen:
	.string "Check out my parallel turn!$"

MahoganyGym_Text_CLARISSABeaten:
	.string "No! You made me wipe out!$"

MahoganyGym_Text_CLARISSAAfterBattle:
	.string "I shouldn't have been bragging\n"
	.string "about my skiing…$"

MahoganyGym_Text_BRADSeen:
	.string "This GYM has a slippery floor.\n"
	.string "It's fun, isn't it?\p"
	.string "But hey -- we're not playing games\n"
	.string "here!$"

MahoganyGym_Text_BRADBeaten:
	.string "Do you see how serious we are?$"

MahoganyGym_Text_BRADAfterBattle:
	.string "This GYM is great. I love boarding\n"
	.string "with my POKéMON!$"

MahoganyGym_Text_DOUGLASSeen:
	.string "I know PRYCE's secret.$"

MahoganyGym_Text_DOUGLASBeaten:
	.string "OK. I'll tell you PRYCE's secret.$"

MahoganyGym_Text_DOUGLASAfterBattle:
	.string "The secret behind PRYCE's power…\p"
	.string "He meditates under a waterfall\n"
	.string "daily to strengthen his mind and\l"
	.string "body.\p"
	.string "In JOHTO. In winter.$"
