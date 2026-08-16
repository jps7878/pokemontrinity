RuinsOfAlphOutside_MapScripts::
	.byte 0

RuinsOfAlphOutside_EventScript_NATHAN::
	trainerbattle_single TRAINER_JOHTO_PSYCHIC_T_NATHAN, RuinsOfAlphOutside_Text_NATHANSeen, RuinsOfAlphOutside_Text_NATHANBeaten
	msgbox RuinsOfAlphOutside_Text_NATHANBeaten, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ Trinity M4b S10 -- TRAINER_IVRAJ, the fourth M1 friend-reward post.
@
@ The mechanic is copied clause for clause from
@ GraniteCave_1F_EventScript_Harjot (data/maps/GraniteCave_1F/scripts.inc:40-90)
@ by way of S5's own copy, EcruteakCity_EventScript_Sumeet. It reuses
@ MULTI_FAMILY_REWARD (116), the same list HARJOT, PRABHJIT and SUMEET use, so
@ no new multichoice id is allocated.
@
@ NO NEW TRAINER ID. TRAINER_IVRAJ already exists at 1048
@ (include/constants/opponents.h:1080) -- Alakazam 65 / Espeon 63 / Slowking 62
@ / Xatu 62, Class Psychic, Pic Psychic M -- and until now was placed by
@ nothing. TRAINERS_COUNT stays 1100 and MAX_TRAINERS_COUNT is untouched, so no
@ fresh save. OBJ_EVENT_GFX_PSYCHIC_M matches the pic (S6's rule: pick the pic,
@ then match the sprite).
@
@ NO_MUSIC is mandatory, not stylistic. G3 is a GENERAL rule for any
@ talk-triggered trainerbattle: PlayTrainerEncounterMusic is not a jingle, it
@ calls PlayNewMapMusic and swaps the whole map BGM for the approach and the
@ intro text (src/battle_setup.c:1441-1499). HARJOT and PRABHJIT predate the
@ rule; S5 applied it to SUMEET and it applies here.
@
@ THE FLAG IS SET AFTER THE giveitem, so a full bag leaves the reward
@ reclaimable -- the G2 ordering, and the reason each gift branch owns its own
@ Common_EventScript_ShowBagIsFull exit.
@
@ TILE, DECODED: (15,15) collision 0, elevation 3, MB_NORMAL, reachable, costing
@ exactly one tile (its own). This map has ELEVEN warps and three signs; (15,15)
@ is none of them (S5: decode a guard post's OWN tile, not just the tile in
@ front of the warp), and all three bg_events are BG_EVENT_PLAYER_FACING_ANY, so
@ no sign has a single reading tile to block (S5's I1 rule does not bite here).
@ ============================================================================
RuinsOfAlphOutside_EventScript_Ivraj::
	trainerbattle_single TRAINER_IVRAJ, RuinsOfAlphOutside_Text_IvrajIntro, RuinsOfAlphOutside_Text_IvrajDefeat, RuinsOfAlphOutside_EventScript_IvrajReward, NO_MUSIC
	goto_if_unset FLAG_RECEIVED_REWARD_IVRAJ, RuinsOfAlphOutside_EventScript_IvrajReward
	msgbox RuinsOfAlphOutside_Text_IvrajPostReward, MSGBOX_DEFAULT
	release
	end

RuinsOfAlphOutside_EventScript_IvrajReward::
	msgbox RuinsOfAlphOutside_Text_IvrajRewardOffer, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_FAMILY_REWARD, FALSE
	switch VAR_RESULT
	case 0, RuinsOfAlphOutside_EventScript_IvrajMasterBalls
	case 1, RuinsOfAlphOutside_EventScript_IvrajRareCandies
	case 2, RuinsOfAlphOutside_EventScript_IvrajCancel
	case MULTI_B_PRESSED, RuinsOfAlphOutside_EventScript_IvrajCancel
	end

RuinsOfAlphOutside_EventScript_IvrajMasterBalls::
	giveitem ITEM_MASTER_BALL, 2
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_REWARD_IVRAJ
	msgbox RuinsOfAlphOutside_Text_IvrajPostReward, MSGBOX_DEFAULT
	release
	end

RuinsOfAlphOutside_EventScript_IvrajRareCandies::
	giveitem ITEM_RARE_CANDY, 99
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_REWARD_IVRAJ
	msgbox RuinsOfAlphOutside_Text_IvrajPostReward, MSGBOX_DEFAULT
	release
	end

RuinsOfAlphOutside_EventScript_IvrajCancel::
	release
	end

RuinsOfAlphOutside_EventScript_MysteryChamberSign::
	msgbox RuinsOfAlphOutside_Text_MysteryChamberSign, MSGBOX_SIGN
	end

RuinsOfAlphOutside_EventScript_RuinsOfAlphSign::
	msgbox RuinsOfAlphOutside_Text_RuinsOfAlphSign, MSGBOX_SIGN
	end

RuinsOfAlphOutside_EventScript_RuinsOfAlphResearchCenterSign::
	msgbox RuinsOfAlphOutside_Text_RuinsOfAlphResearchCenterSign, MSGBOX_SIGN
	end

RuinsOfAlphOutside_Text_NATHANSeen:
	.string "Hmmm… This is a\nstrange place.$"

RuinsOfAlphOutside_Text_NATHANBeaten:
	.string "…$"

RuinsOfAlphOutside_Text_MysteryChamberSign:
	.string "MYSTERY STONE\nPANEL CHAMBER$"

RuinsOfAlphOutside_Text_RuinsOfAlphSign:
	.string "RUINS OF ALPH\nVISITORS WELCOME$"

RuinsOfAlphOutside_Text_RuinsOfAlphResearchCenterSign:
	.string "RUINS OF ALPH\nRESEARCH CENTER\pTHE AUTHORITY ON\nTHE RUINS OF ALPH$"

RuinsOfAlphOutside_Text_IvrajIntro:
	.string "IVRAJ: I have been reading the same\n"
	.string "four walls for eleven years.\p"
	.string "Whoever carved them knew something\n"
	.string "about minds that we have forgotten.\p"
	.string "You are the one from HOENN. Good.\n"
	.string "Let me read yours instead.$"

RuinsOfAlphOutside_Text_IvrajDefeat:
	.string "Ah.\p"
	.string "You were three moves ahead the whole\n"
	.string "way and you never once looked it.$"

RuinsOfAlphOutside_Text_IvrajRewardOffer:
	.string "IVRAJ: Take something off me. I did\n"
	.string "not come out here empty-handed and\l"
	.string "I am not going home loaded.$"

RuinsOfAlphOutside_Text_IvrajPostReward:
	.string "IVRAJ: The stone panels are a puzzle\n"
	.string "with no reward at the end of it.\p"
	.string "Eleven years, and that is still the\n"
	.string "most interesting thing about them.$"
