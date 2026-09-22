OlivineGym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineGym_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S6 -- OLIVINE GYM. THE GYM PATTERN (G1-G7), copied from
@ data/maps/VioletGym/scripts.inc, whose header carries the full rationale.
@ Substituted here: JASMINE, FLAG_TRINITY_BADGE14, TM23 IRON TAIL, STEEL.
@
@ WHAT IS DIFFERENT ABOUT THIS GYM: like ECRUTEAK's, its leader is not in it --
@ she is at the top of the LIGHTHOUSE nursing a sick AMPHAROS, and GSC keeps
@ the gym shut until the SECRETPOTION reaches her. Trinity does not do hard
@ doors (the Johto gyms are open-order by contract), so the room stands open and
@ the GYM GUIDE carries the redirect. GSC wrote that line itself
@ (OlivineGymGuidePreText), so no new object is needed -- the guide simply has
@ three states instead of two.
@
@ THE GYM HAS NO TRAINERS. That is not an omission: GSC's OLIVINE GYM has none
@ either (JASMINE and a guide, nothing else), and M4a's port matched it. G6 has
@ nothing to act on here.
@
@ ON_TRANSITION is the SINGLE AUTHORITY for FLAG_TRINITY_J_JASMINE_GYM_HIDE:
@   JASMINE is visible iff FLAG_TRINITY_J_AMPHY_CURED.
@ OlivineLighthouse6F carries the exact complement. One boolean, one writer (the
@ 6F delivery beat), two single-authority ON_TRANSITIONs -- so there is no state
@ in which she is in both rooms or in neither. Nothing on this map ever
@ removeobject's her, so R1's flag co-sign cannot fire here at all.
@ ============================================================================
OlivineGym_OnTransition:
	call OlivineGym_EventScript_SetJasmineVisibility
	end

OlivineGym_EventScript_SetJasmineVisibility::
	goto_if_set FLAG_TRINITY_J_AMPHY_CURED, OlivineGym_EventScript_ShowJasmine
	setflag FLAG_TRINITY_J_JASMINE_GYM_HIDE
	return

OlivineGym_EventScript_ShowJasmine::
	clearflag FLAG_TRINITY_J_JASMINE_GYM_HIDE
	return

@ ============================================================================
@ G1/G2/G3 -- JASMINE. Talk-triggered, TRAINER_TYPE_NONE, sight 0, appended to
@ object_events so M4a's local id for the guide does not shift. GSC's tile
@ (5,3), decoded MB_NORMAL collision 0 elevation 3. (Row 2 immediately above her
@ is a band of MB_IMPASSABLE_NORTH at x=3..6; harmless -- it forbids LEAVING
@ row 2 northward, and she is reached from (5,4), (4,3) or (6,3).)
@ ============================================================================
OlivineGym_EventScript_Jasmine::
	trainerbattle_single TRAINER_JASMINE_LEADER, OlivineGym_Text_JasmineIntro, OlivineGym_Text_JasmineDefeat, OlivineGym_EventScript_JasmineDefeated, NO_MUSIC
	@ Re-talk path only: the engine's trainer-defeated flag already gated the
	@ continuation above, so execution reaches here on a LATER talk. Retry the
	@ TM if the bag was full the first time, else the post-badge line.
	goto_if_unset FLAG_TRINITY_J_JASMINE_TM23, OlivineGym_EventScript_GiveIronTail
	msgbox OlivineGym_Text_JasminePostBattle, MSGBOX_DEFAULT
	release
	end

OlivineGym_EventScript_JasmineDefeated::
	message OlivineGym_Text_ReceivedMineralBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_TRINITY_BADGE14
	msgbox OlivineGym_Text_MineralBadgeInfo, MSGBOX_DEFAULT
	goto OlivineGym_EventScript_GiveIronTail
	end

OlivineGym_EventScript_GiveIronTail::
	giveitem ITEM_TM_IRON_TAIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_J_JASMINE_TM23
	msgbox OlivineGym_Text_ExplainIronTail, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ G4 -- the gym guide, THREE states, which is GSC's own branch set
@ (OlivineGymGuideScript): the LIGHTHOUSE redirect while AMPHY is sick, the type
@ advice once JASMINE is home, the win line after the badge.
@
@ MOVED (7,13) -> (7,12), and this is the VioletGym fix again. (7,12)/(7,13) is
@ a two-tile dead-end column -- (7,11), (6,12), (8,12), (6,13) and (8,13) all
@ decode collision 1, so the pair hangs off (7,14). Standing on (7,13) SEALS
@ (7,12) (reach_check: 58 of 60 with the guide there, two tiles lost); standing
@ on (7,12) loses only his own tile. Identical shape and identical one-tile diff
@ to S3's fix-round nudge of VioletGym's guide, (7,13) -> (7,12).
@ ============================================================================
OlivineGym_EventScript_Guide::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_BADGE14, OlivineGym_EventScript_GuidePostVictory
	goto_if_unset FLAG_TRINITY_J_AMPHY_CURED, OlivineGym_EventScript_GuideJasmineAway
	msgbox OlivineGym_Text_GuideAdvice, MSGBOX_DEFAULT
	release
	end

OlivineGym_EventScript_GuideJasmineAway::
	msgbox OlivineGym_Text_GuideJasmineAway, MSGBOX_DEFAULT
	release
	end

@ M7b Task 15 (finding #6): the guide states the player's LIVE badge count.
@ The tally reads the flags and buffers the number itself -- see
@ data/scripts/trinity_johto.inc.
OlivineGym_EventScript_GuidePostVictory::
	msgbox OlivineGym_Text_GuidePostVictory, MSGBOX_DEFAULT
	call Trinity_EventScript_JohtoBadgeTally
	@ M7b Task 14 (finding #9): once the badge is won this guide doubles as
	@ a pointer. The branch above is already the badge flag, so nothing new
	@ is read or written here; the ladder releases for us.
	goto Trinity_EventScript_JohtoGuide
	end

@ ============================================================================
@ G5 -- (3,13) and (6,13) decode collision 1: they are GSC's two statue wall
@ tiles, read facing north from (3,14)/(6,14), both collision 0 elevation 3.
@ Those two reading tiles are the ONLY way to read these panels (S5's I1 pin:
@ a BG_EVENT_PLAYER_FACING_NORTH on a collision-1 tile has exactly one reading
@ tile, and reach_check cannot see it), so both are deliberately left clear --
@ this map's only objects are the guide at (7,12) and JASMINE at (5,3).
@ ONE entry script for BOTH bg_events, per S5's statue dedupe.
@ ============================================================================
OlivineGym_EventScript_GymStatues::
	lockall
	goto_if_set FLAG_TRINITY_BADGE14, OlivineGym_EventScript_GymStatueCertified
	msgbox OlivineGym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

OlivineGym_EventScript_GymStatueCertified::
	msgbox OlivineGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@ Text
@ ============================================================================
@ Adapts pokecrystal Jasmine_SteelTypeIntro. GSC's opening line thanks the
@ player for the LIGHTHOUSE, and in Trinity that is literally the only way to
@ meet her here, so it stays.
OlivineGym_Text_JasmineIntro:
	.string "JASMINE: …Thank you for what you\n"
	.string "did at the LIGHTHOUSE.\p"
	.string "But this is different. Please let\n"
	.string "me introduce myself properly.\p"
	.string "I am JASMINE. I am a GYM LEADER and\n"
	.string "I use the steel-type.\p"
	.string "It is a young type. Hardly anyone\n"
	.string "has worked out what to do about it\l"
	.string "yet -- and I would rather they\l"
	.string "didn't.\p"
	.string "…Um. May I begin?$"

@ GSC Jasmine_BetterTrainer.
OlivineGym_Text_JasmineDefeat:
	.string "…You are a better trainer than me.\p"
	.string "In skill, and in the other thing.$"

OlivineGym_Text_ReceivedMineralBadge:
	.string "{PLAYER} received the MINERALBADGE\n"
	.string "from JASMINE!$"

@ Badges 9-16 are plain flags with no engine UI, so this text must promise no
@ mechanical effect (GSC's own line promises a DEFENSE boost -- dropped), and it
@ must not COUNT badges: the Johto gyms are open-order in Trinity.
OlivineGym_Text_MineralBadgeInfo:
	.string "JASMINE: The MINERALBADGE will not\n"
	.string "make your POKéMON any tougher.\p"
	.string "It only says that someone got\n"
	.string "through a wall I built. That is one\l"
	.string "more than most people manage.\p"
	.string "Eight from JOHTO and INDIGO opens\n"
	.string "its doors to you.$"

@ TM award dialogue must never presume novelty (S3-S9 rule): gym TM awards
@ duplicate Act I sources, so the player may already own IRON TAIL.
OlivineGym_Text_ExplainIronTail:
	.string "JASMINE: …Um. Please take this too.\p"
	.string "IRON TAIL. It hits like a dropped\n"
	.string "anchor and it can dent what it\l"
	.string "hits, though it does miss.\p"
	.string "You may well have a copy already.\n"
	.string "Take mine anyway. It is the move I\l"
	.string "learned first and I still lead\l"
	.string "with it.$"

@ GSC Jasmine_GoodLuck.
OlivineGym_Text_JasminePostBattle:
	.string "JASMINE: Um… I don't know how to\n"
	.string "say this properly, but…\p"
	.string "good luck. Truly.$"

@ GSC OlivineGymGuidePreText.
OlivineGym_Text_GuideJasmineAway:
	.string "JASMINE, the GYM LEADER, is not\n"
	.string "here. She's up the LIGHTHOUSE.\p"
	.string "There's a POKéMON up there that's\n"
	.string "been sick for weeks, and she has\l"
	.string "not come down once.\p"
	.string "A strong trainer has to be kind\n"
	.string "first. Go up and see her.$"

@ G4 -- VERIFIED AGAINST THE DATA BEFORE IT WAS WRITTEN. Roster from
@ src/data/trainers.party; typings from src/data/pokemon/species_info/;
@ multipliers from gTypeEffectivenessTable (src/data/types_info.h).
@   FORRETRESS MON_TYPES(TYPE_BUG, TYPE_STEEL)
@   MAGNETON   MON_TYPES(TYPE_ELECTRIC, MAGNEMITE_FAMILY_TYPE2)
@              MAGNEMITE_FAMILY_TYPE2 = (P_UPDATED_TYPES >= GEN_2 ? TYPE_STEEL
@              : TYPE_ELECTRIC) and P_UPDATED_TYPES is GEN_LATEST here, so
@              ELECTRIC / STEEL.
@   SKARMORY   MON_TYPES(TYPE_STEEL, TYPE_FLYING)
@   AGGRON     MON_TYPES(TYPE_STEEL, TYPE_ROCK)
@   STEELIX    MON_TYPES(TYPE_STEEL, TYPE_GROUND)
@                    FORRETRESS  MAGNETON  SKARMORY  AGGRON  STEELIX
@   FIRE            2.0x2.0=4.0  1.0x2.0=2.0  2.0x1.0=2.0  2.0x0.5=1.0  2.0x1.0=2.0
@   FIGHTING        0.5x2.0=1.0  1.0x2.0=2.0  2.0x0.5=1.0  2.0x2.0=4.0  2.0x1.0=2.0
@   GROUND          0.5x2.0=1.0  2.0x2.0=4.0  2.0x0.0=0.0  2.0x1.0=2.0  2.0x1.0=2.0
@ So: FIRE is the broad answer (four of five, quadruple on FORRETRESS) and
@ AGGRON is the one exception, because its ROCK half halves fire straight back
@ to neutral; FIGHTING is what quadruples AGGRON; GROUND quadruples MAGNETON and
@ does literally nothing to SKARMORY (GROUND->FLYING is 0.0).
@ LEVEL BAND, stated honestly: JASMINE runs L65-68 and this gym has no other
@ trainers.
OlivineGym_Text_GuideAdvice:
	.string "CHAMPION! Right, listen -- steel is\n"
	.string "the newest type and nobody has the\l"
	.string "hang of it yet, so here it is.\p"
	.string "FIRE burns four of her five, and it\n"
	.string "hits FORRETRESS four times over.\p"
	.string "The exception is AGGRON. It's part\n"
	.string "ROCK, so fire drops back to an\l"
	.string "ordinary hit -- FIGHTING is what\l"
	.string "takes AGGRON apart, four times over.\p"
	.string "GROUND quadruples MAGNETON, but\n"
	.string "don't aim it at SKARMORY. SKARMORY\l"
	.string "flies. It does nothing at all.\p"
	.string "She opens at L65 and finishes at\n"
	.string "L68. Bring the fire.$"

@ GSC OlivineGymGuideWinText.
OlivineGym_Text_GuidePostVictory:
	.string "That was awesome.\p"
	.string "The steel-type, huh? That was a\n"
	.string "close encounter of an unknown kind!$"

OlivineGym_Text_GymStatue:
	.string "OLIVINE POKéMON GYM\n"
	.string "LEADER: JASMINE\p"
	.string "The Steel-Clad Defense Girl$"

OlivineGym_Text_GymStatueCertified:
	.string "OLIVINE POKéMON GYM\n"
	.string "LEADER: JASMINE\p"
	.string "The Steel-Clad Defense Girl\p"
	.string "{PLAYER} won the MINERALBADGE here.$"
