@ ============================================================================
@ Trinity M5b S2 -- G1-G7. Canonical file: VermilionCity_Gym/scripts.inc (the
@ Act III idiom precedent). Warp-tile maze (30 internal self-warps + 3 exit
@ warps) is FRLG's own layout, ported byte-identical by M5a T2/T7 -- untouched
@ by this slice. Warp-graph proof it routes to SABRINA:
@ docs/superpowers/plans/m5b/02-saffron-chapter.md section 6
@ (`reach_check.py --dungeon SaffronCity_Gym`, re-run with SABRINA placed:
@ all 33 warps mutually reachable, 475/484; single-map mode: 484/484 with no
@ objects -- the whole floor is one open room, the warp tiles are invisible
@ relocate-traps on it, not partitions).
@ G1: SABRINA appended (T10 never placed her -- leaders are TRAINER_TYPE_NONE,
@ not the normal gym-trainer population pass). (14,11), col=0 elev=3
@ MB_NORMAL, free. OBJ_EVENT_GFX_LIZA (Hoenn's female PSYCHIC-type leader --
@ type+gender match, TRAINER_SABRINA.Pic is "Psychic M" pre-existing/
@ untouched, M6 art item, same defect class as Falkner/Winona inverted).
@ ============================================================================
SaffronCity_Gym_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_Sabrina::
	trainerbattle_single TRAINER_SABRINA, SaffronCity_Gym_Text_SabrinaSeen, SaffronCity_Gym_Text_SabrinaDefeat, SaffronCity_Gym_EventScript_SabrinaDefeated, NO_MUSIC
	goto_if_unset FLAG_TRINITY_K_SABRINA_TM29, SaffronCity_Gym_EventScript_GivePsychic
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_EventScript_SabrinaDefeated::
	message SaffronCity_Gym_Text_ReceivedMarshBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_TRINITY_BADGE22
	msgbox SaffronCity_Gym_Text_MarshBadgeInfo, MSGBOX_DEFAULT
	goto SaffronCity_Gym_EventScript_GivePsychic
	end

SaffronCity_Gym_EventScript_GivePsychic::
	giveitem ITEM_TM_PSYCHIC
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_K_SABRINA_TM29
	msgbox SaffronCity_Gym_Text_ExplainPsychic, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ G6 -- T10's gym trainers, ids/tiles/wiring reviewed and kept, placeholder
@ "..." text replaced with real dialogue + a distinct post-battle line each.
@ ============================================================================
SaffronCity_Gym_EventScript_Cameron::
	trainerbattle_single TRAINER_KANTO_PSYCHIC_CAMERON, SaffronCity_Gym_Text_CameronSeen, SaffronCity_Gym_Text_CameronBeaten
	msgbox SaffronCity_Gym_Text_CameronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Johan::
	trainerbattle_single TRAINER_KANTO_PSYCHIC_JOHAN, SaffronCity_Gym_Text_JohanSeen, SaffronCity_Gym_Text_JohanBeaten
	msgbox SaffronCity_Gym_Text_JohanPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_KANTO_PSYCHIC_PRESTON, SaffronCity_Gym_Text_PrestonSeen, SaffronCity_Gym_Text_PrestonBeaten
	msgbox SaffronCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Amanda::
	trainerbattle_single TRAINER_KANTO_CHANNELER_AMANDA, SaffronCity_Gym_Text_AmandaSeen, SaffronCity_Gym_Text_AmandaBeaten
	msgbox SaffronCity_Gym_Text_AmandaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Stacy::
	trainerbattle_single TRAINER_KANTO_CHANNELER_STACY, SaffronCity_Gym_Text_StacySeen, SaffronCity_Gym_Text_StacyBeaten
	msgbox SaffronCity_Gym_Text_StacyPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tasha::
	trainerbattle_single TRAINER_KANTO_CHANNELER_TASHA, SaffronCity_Gym_Text_TashaSeen, SaffronCity_Gym_Text_TashaBeaten
	msgbox SaffronCity_Gym_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tyron::
	trainerbattle_single TRAINER_KANTO_PSYCHIC_TYRON, SaffronCity_Gym_Text_TyronSeen, SaffronCity_Gym_Text_TyronBeaten
	msgbox SaffronCity_Gym_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ G4 -- the guide. Roster re-verified against trainers.party +
@ src/data/pokemon/species_info/gen_1_families.h + src/data/types_info.h,
@ ALL SIX individually (fix round: the first pass wrongly called MR. MIME
@ pure PSYCHIC by assumption instead of checking its own .types line).
@
@ Per-mon .types, checked for #if P_UPDATED_TYPES conditionals on every one:
@   ESPEON (18212)   PSYCHIC only, unconditional
@   MR. MIME (15761) #if P_UPDATED_TYPES >= GEN_6: PSYCHIC/FAIRY -- and this
@                     build's config/pokemon.h sets P_UPDATED_TYPES GEN_LATEST,
@                     so the FAIRY branch is what's actually compiled
@   JYNX (16372)     ICE/PSYCHIC, unconditional
@   HYPNO (12505)    PSYCHIC only, unconditional
@   SLOWBRO (10192)  WATER/PSYCHIC, unconditional
@   ALAKAZAM (8491)  PSYCHIC only, unconditional
@ All L82-84.
@
@ TYPE_BUG row col=PSYCHIC(15) = X(2.0); TYPE_DARK row col=PSYCHIC(15) =
@ X(2.0) -- both flat/unconditional. TYPE_BUG row col=FAIRY(19) = X(0.5);
@ TYPE_DARK row col=FAIRY(19) = X(0.5) -- ALSO both flat. Per mon:
@   ESPEON/HYPNO/ALAKAZAM (no 2nd type): BUG 2.0x1=2.0, DARK 2.0x1=2.0
@   JYNX (ICE 2nd type, BUG/DARK vs ICE both neutral): BUG 2.0, DARK 2.0
@   SLOWBRO (WATER 2nd type, BUG/DARK vs WATER both neutral): BUG 2.0, DARK 2.0
@   MR. MIME (FAIRY 2nd type): BUG 2.0x0.5=1.0 (NEUTRAL), DARK 2.0x0.5=1.0
@     (NEUTRAL) -- FAIRY's resistance to both exactly cancels PSYCHIC's own
@     weakness to them. The ONE exception in the whole six; named in the
@     guide's own text below, not hedged into invisibility.
@ TYPE_GHOST's column is a conditional macro (PSY_RS) in this build, so it is
@ deliberately NOT claimed here (the S3/S4 "verify every factual claim"
@ lesson -- state only what was actually checked, not assumed).
@ ============================================================================
SaffronCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_BADGE22, SaffronCity_Gym_EventScript_GymGuyPostVictory
	msgbox SaffronCity_Gym_Text_GymGuyAdvice, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_EventScript_GymGuyPostVictory::
	msgbox SaffronCity_Gym_Text_GymGuyPostVictory, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ G5 -- the statues. (12,20)/(16,20), BG_EVENT_PLAYER_FACING_ANY -- verified
@ against FRLG source this session (SaffronCity_Gym/map.json ships ANY for
@ both, unlike VermilionCity_Gym's genuine ANY->NORTH Johto-convention fix);
@ no facing-constraint change made here, it is already faithful.
@ ============================================================================
SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_TRINITY_BADGE22, SaffronCity_Gym_EventScript_GymStatueCertified
	msgbox SaffronCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatue_2::
	lockall
	goto_if_set FLAG_TRINITY_BADGE22, SaffronCity_Gym_EventScript_GymStatueCertified
	msgbox SaffronCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatueCertified::
	msgbox SaffronCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@ Text
@ ============================================================================
SaffronCity_Gym_Text_SabrinaSeen:
	.string "SABRINA: I already know why\n"
	.string "you're here. I knew before you\l"
	.string "did.$"

SaffronCity_Gym_Text_SabrinaDefeat:
	.string "I saw this coming. I just didn't\n"
	.string "believe it.$"

SaffronCity_Gym_Text_ReceivedMarshBadge:
	.string "{PLAYER} received the\n"
	.string "MARSHBADGE from SABRINA.$"

SaffronCity_Gym_Text_MarshBadgeInfo:
	.string "SABRINA: MARSHBADGE.\p"
	.string "It won't sharpen your mind. Yours\n"
	.string "is already sharp enough to reach\l"
	.string "this room.\p"
	.string "It just means KANTO's noticed.\n"
	.string "Seven of these, and VIRIDIAN has\l"
	.string "to open the door.\p"
	.string "That's the MARSHBADGE.\n"
	.string "Take this too.$"

SaffronCity_Gym_Text_ExplainPsychic:
	.string "SABRINA: TM29. PSYCHIC.\p"
	.string "You may already carry this move.\n"
	.string "It doesn't matter -- mine's been\l"
	.string "refined past what any TM box\l"
	.string "explains.\p"
	.string "Teach it to whatever you like.\n"
	.string "It will not fail you.$"

SaffronCity_Gym_Text_SabrinaPostBattle:
	.string "SABRINA: You already knew I'd\n"
	.string "say that.$"

SaffronCity_Gym_Text_CameronSeen:
	.string "I can read your next move before\n"
	.string "you make it.$"

SaffronCity_Gym_Text_CameronBeaten:
	.string "...I did not see that coming.$"

SaffronCity_Gym_Text_CameronPostBattle:
	.string "SABRINA doesn't need to read\n"
	.string "minds. She's just always right.$"

SaffronCity_Gym_Text_JohanSeen:
	.string "This GYM tests more than your\n"
	.string "POKéMON. It tests your nerve.$"

SaffronCity_Gym_Text_JohanBeaten:
	.string "My nerve, apparently, folds\n"
	.string "faster than yours.$"

SaffronCity_Gym_Text_JohanPostBattle:
	.string "Keep walking. SABRINA's through\n"
	.string "the far door.$"

SaffronCity_Gym_Text_PrestonSeen:
	.string "Half of trainers who walk in here\n"
	.string "never find the second switch.$"

SaffronCity_Gym_Text_PrestonBeaten:
	.string "You found more than a switch\n"
	.string "just now.$"

SaffronCity_Gym_Text_PrestonPostBattle:
	.string "The floor plays tricks. SABRINA\n"
	.string "doesn't need to.$"

SaffronCity_Gym_Text_AmandaSeen:
	.string "I channel more than POKéMON in\n"
	.string "this GYM. Don't ask what else.$"

SaffronCity_Gym_Text_AmandaBeaten:
	.string "Something in the room went very\n"
	.string "quiet just now.$"

SaffronCity_Gym_Text_AmandaPostBattle:
	.string "SAFFRON's older than KANTO's\n"
	.string "other cities. Some of it lingers.$"

SaffronCity_Gym_Text_StacySeen:
	.string "GHOST types don't scare me.\n"
	.string "Losing does.$"

SaffronCity_Gym_Text_StacyBeaten:
	.string "There it is. The scary part.$"

SaffronCity_Gym_Text_StacyPostBattle:
	.string "Find both switches yet? I never\n"
	.string "do on the first try.$"

SaffronCity_Gym_Text_TashaSeen:
	.string "I've heard three languages spoken\n"
	.string "in this lobby today. None of them\l"
	.string "POKéMON.$"

SaffronCity_Gym_Text_TashaBeaten:
	.string "Lost in translation, that one.$"

SaffronCity_Gym_Text_TashaPostBattle:
	.string "SABRINA runs this GYM like she\n"
	.string "runs everything else. Quietly.$"

SaffronCity_Gym_Text_TyronSeen:
	.string "This close to SABRINA, and you\n"
	.string "still think you'll win?$"

SaffronCity_Gym_Text_TyronBeaten:
	.string "...Yes. Apparently you will.$"

SaffronCity_Gym_Text_TyronPostBattle:
	.string "SABRINA's waiting. She's been\n"
	.string "waiting since before you arrived.$"

SaffronCity_Gym_Text_GymGuyAdvice:
	.string "Champion, is it? Word travels\n"
	.string "fast through a psychic building.\p"
	.string "SABRINA runs PSYCHIC types --\n"
	.string "ESPEON, MR. MIME, JYNX, HYPNO,\l"
	.string "SLOWBRO, ALAKAZAM. LEVEL 83 to\l"
	.string "85.\p"
	.string "BUG and DARK-type moves hit five\n"
	.string "of the six hard. MR. MIME's\l"
	.string "FAIRY half shrugs both off.\p"
	.string "Oh -- and the floor isn't just a\n"
	.string "floor. Watch your step.$"

SaffronCity_Gym_Text_GymGuyPostVictory:
	.string "Straight through SABRINA! Didn't\n"
	.string "even look surprised, did she.\p"
	.string "MARSHBADGE. One of seven.$"

SaffronCity_Gym_Text_GymStatue:
	.string "SAFFRON CITY POKéMON GYM\n"
	.string "LEADER: SABRINA\p"
	.string "The Master of Psychic Pokémon$"

SaffronCity_Gym_Text_GymStatueCertified:
	.string "SAFFRON CITY POKéMON GYM\n"
	.string "LEADER: SABRINA\p"
	.string "SABRINA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
