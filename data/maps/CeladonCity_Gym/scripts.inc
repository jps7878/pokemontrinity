@ ============================================================================
@ Trinity M5b S6 -- THE GYM PATTERN (G1-G5), PewterCity_Gym/scripts.inc's own
@ canonical shape (Brock/S4), map/leader/badge/TM substituted. T10's 6
@ trainers (Kay/Bridget/Tina/Tamia/Lori/Lisa) reviewed, not re-placed --
@ their ids/coordinates/wiring are kept exactly as shipped, only their
@ placeholder text is replaced. See docs/superpowers/plans/m5b/
@ 06-celadon-chapter.md section 4.
@ ============================================================================
CeladonCity_Gym_MapScripts::
	.byte 0

@ ============================================================================
@ G1 -- ERIKA. (6,4), pokefirered's own coordinate (decoded col=0 elev=3
@ MB_NORMAL, free -- FR seats her directly between two of her own students,
@ Lori(5,4)/Lisa(7,4), a real FRLG "wall of trainers" shape, not accidental).
@ TRAINER_TYPE_NONE, MOVEMENT_TYPE_FACE_DOWN, NO_MUSIC (G3). OVERWORLD:
@ OBJ_EVENT_GFX_ERIKA, FR's own byte-identical overworld, ported by M7b
@ Task 11b. She previously wore OBJ_EVENT_GFX_PHOEBE, which she shared with
@ Hoenn E4 Phoebe herself plus Janine and Karen -- four named women on one
@ sheet, the exact misread finding #5 is about. PHOEBE still carries Janine
@ and Karen and remains open for Task 12's art decision.
@ ============================================================================
CeladonCity_Gym_EventScript_Erika::
	trainerbattle_single TRAINER_ERIKA, CeladonCity_Gym_Text_ErikaSeen, CeladonCity_Gym_Text_ErikaBeaten, CeladonCity_Gym_EventScript_ErikaDefeated, NO_MUSIC
	goto_if_unset FLAG_TRINITY_K_ERIKA_TM22, CeladonCity_Gym_EventScript_GiveTM22
	msgbox CeladonCity_Gym_Text_ErikaPostBattle, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_EventScript_ErikaDefeated::
	message CeladonCity_Gym_Text_ReceivedRainbowBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_TRINITY_BADGE20
	msgbox CeladonCity_Gym_Text_RainbowBadgeInfo, MSGBOX_DEFAULT
	goto CeladonCity_Gym_EventScript_GiveTM22
	end

CeladonCity_Gym_EventScript_GiveTM22::
	giveitem ITEM_TM22
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_K_ERIKA_TM22
	msgbox CeladonCity_Gym_Text_ExplainSolarBeam, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_EventScript_Kay::
	trainerbattle_single TRAINER_KANTO_LASS_KAY, CeladonCity_Gym_Text_KaySeen, CeladonCity_Gym_Text_KayBeaten
	msgbox CeladonCity_Gym_Text_KayBeaten, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_KANTO_BEAUTY_BRIDGET, CeladonCity_Gym_Text_BridgetSeen, CeladonCity_Gym_Text_BridgetBeaten
	msgbox CeladonCity_Gym_Text_BridgetBeaten, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Tina::
	trainerbattle_single TRAINER_KANTO_PICNICKER_TINA, CeladonCity_Gym_Text_TinaSeen, CeladonCity_Gym_Text_TinaBeaten
	msgbox CeladonCity_Gym_Text_TinaBeaten, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Tamia::
	trainerbattle_single TRAINER_KANTO_BEAUTY_TAMIA, CeladonCity_Gym_Text_TamiaSeen, CeladonCity_Gym_Text_TamiaBeaten
	msgbox CeladonCity_Gym_Text_TamiaBeaten, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Lori::
	trainerbattle_single TRAINER_KANTO_BEAUTY_LORI, CeladonCity_Gym_Text_LoriSeen, CeladonCity_Gym_Text_LoriBeaten
	msgbox CeladonCity_Gym_Text_LoriBeaten, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Lisa::
	trainerbattle_single TRAINER_KANTO_LASS_LISA, CeladonCity_Gym_Text_LisaSeen, CeladonCity_Gym_Text_LisaBeaten
	msgbox CeladonCity_Gym_Text_LisaBeaten, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Mary::
	trainerbattle_single TRAINER_KANTO_COOLTRAINER_MARY, CeladonCity_Gym_Text_MarySeen, CeladonCity_Gym_Text_MaryBeaten
	msgbox CeladonCity_Gym_Text_MaryBeaten, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ G4 -- the guide. T10 placed 7 trainers and no separate never-battling
@ guide NPC at all (unlike Brock's GymGuy) -- MARY doubles as the gym's
@ advice-giver: her own post-battle text (shown both right after her defeat
@ and on every later revisit, the SAME fallthrough shape as the other 5
@ static trainers) carries the type-advice payload instead of a second,
@ separate script. Roster TANGELA79/JUMPLUFF79/VICTREEBEL80/BELLOSSOM80/
@ VILEPLUME81 verified against trainers.h directly. FIRE is the honest
@ universal call -- all five are pure or dual GRASS (Tangela; Jumpluff
@ Grass/Flying; Victreebel/Bellossom/Vileplume Grass/Poison), so GRASS moves
@ are actually a BAD matchup here (every one of them RESISTS Grass), the
@ opposite of the usual "type X hits everything" gym-guide line -- stated
@ honestly, not glossed into the usual shape. JUMPLUFF's own Flying typing
@ no-sells Ground entirely, the guide's second honest clause.
@ ============================================================================

@ ============================================================================
@ G5 -- the statues. (4,16)/(8,16), T10-placed col=1 MB_SIGNPOST (unmoved).
@ Both were verbatim-duplicate placeholder text (the S1/S4 defect class) --
@ given distinct text, badge-gated continuation added, PewterCity_Gym's own
@ G5 template. Approach constraint checked against Pewter's own finding:
@ BG_EVENT_PLAYER_FACING_* reads the PLAYER's own facing at interact time,
@ i.e. the tile SOUTH of the sign -- both (4,17)/(8,17) decode dry MB_NORMAL
@ (no water/hazard gimmick here either, CUT trees are Celadon's own
@ gimmick), so T10's shipped ANY is a pure house-convention match, not a
@ hazard-driven choice -- stated honestly per the S3 false-decode lesson.
@ ============================================================================
CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_TRINITY_BADGE20, CeladonCity_Gym_EventScript_GymStatueCertified
	msgbox CeladonCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatue_2::
	lockall
	goto_if_set FLAG_TRINITY_BADGE20, CeladonCity_Gym_EventScript_GymStatueCertified
	msgbox CeladonCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatueCertified::
	msgbox CeladonCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@ G2 -- three labels. No FRLG source for this (pokefirered's own
@ CeladonCity_Gym carries only the 2 statue signs, confirmed by decode) and
@ no prior Trinity gym precedent either (grep across all 4 prior gyms: 0
@ hits for "label") -- an original, brief-underspecified addition, resolved
@ as three small flavour signs through the garden-maze interior, placed on
@ open non-blocking tiles, distinct from the 2 entrance statues.
@ ============================================================================
CeladonCity_Gym_EventScript_Label1::
	msgbox CeladonCity_Gym_Text_Label1, MSGBOX_SIGN
	end

CeladonCity_Gym_EventScript_Label2::
	msgbox CeladonCity_Gym_Text_Label2, MSGBOX_SIGN
	end

CeladonCity_Gym_EventScript_Label3::
	msgbox CeladonCity_Gym_Text_Label3, MSGBOX_SIGN
	end

CeladonCity_Gym_Text_ErikaSeen:
	.string "So. Two other regions' worth of\n"
	.string "badges, and you still tracked mud\l"
	.string "onto my garden floor.\p"
	.string "I'm ERIKA. My POKéMON have been\n"
	.string "patient with worse than you.\p"
	.string "Let's see if that patience holds.$"

CeladonCity_Gym_Text_ErikaBeaten:
	.string "Oh, my. How unbecoming -- of\n"
	.string "me, to have underestimated you.$"

CeladonCity_Gym_Text_ReceivedRainbowBadge:
	.string "{PLAYER} received the\n"
	.string "RAINBOWBADGE from ERIKA.$"

CeladonCity_Gym_Text_RainbowBadgeInfo:
	.string "ERIKA: The RAINBOWBADGE.\p"
	.string "Doesn't make you stronger. Just\n"
	.string "means KANTO's noticed you.\p"
	.string "Seven of these, and VIRIDIAN opens\n"
	.string "the door.\p"
	.string "Take this too -- you've earned it.$"

CeladonCity_Gym_Text_ExplainSolarBeam:
	.string "ERIKA: TM22. SOLAR BEAM.\p"
	.string "Gathers light for a turn, then\n"
	.string "unleashes it all at once. Slow,\l"
	.string "but devastating when it lands.\p"
	.string "Teach it to whoever you like.\n"
	.string "It won't wear out.$"

CeladonCity_Gym_Text_ErikaPostBattle:
	.string "The GAME CORNER's been quieter\n"
	.string "than usual lately. I'd rather\l"
	.string "not know why.$"

CeladonCity_Gym_Text_KaySeen:
	.string "Ever tried a POKéMON garden?\nIt's harder than it looks.$"

CeladonCity_Gym_Text_KayBeaten:
	.string "The garden wins again, I guess.$"

CeladonCity_Gym_Text_BridgetSeen:
	.string "ERIKA's POKéMON smell better\nthan mine ever will.$"

CeladonCity_Gym_Text_BridgetBeaten:
	.string "Even my perfume couldn't save\nme there.$"

CeladonCity_Gym_Text_TinaSeen:
	.string "Cutting through hedges to reach\na gym leader. Very dignified.$"

CeladonCity_Gym_Text_TinaBeaten:
	.string "Guess the hedges did more work\nthan I did.$"

CeladonCity_Gym_Text_TamiaSeen:
	.string "ERIKA once dozed off mid-battle.\nStill won.$"

CeladonCity_Gym_Text_TamiaBeaten:
	.string "And here I was wide awake for\nthat loss.$"

CeladonCity_Gym_Text_LoriSeen:
	.string "You're standing right where\nERIKA likes to greet challengers.$"

CeladonCity_Gym_Text_LoriBeaten:
	.string "She'll greet you properly in\na moment, then.$"

CeladonCity_Gym_Text_LisaSeen:
	.string "This close to the leader, and\nyou still have to get through me.$"

CeladonCity_Gym_Text_LisaBeaten:
	.string "Fine. Go on. She's right there.$"

CeladonCity_Gym_Text_MarySeen:
	.string "I stand a little apart from the\nrest -- someone has to give the\ladvice around here.$"

CeladonCity_Gym_Text_MaryBeaten:
	.string "Advice-giving and battling\n"
	.string "don't always mix, apparently.\p"
	.string "Since you're here anyway: TANGELA,\n"
	.string "JUMPLUFF, VICTREEBEL, BELLOSSOM,\l"
	.string "VILEPLUME -- all GRASS, some part\l"
	.string "POISON, one part FLYING. LEVEL 79\l"
	.string "to 81.\p"
	.string "Here's the twist: GRASS moves are\n"
	.string "a BAD idea against her. Every one\l"
	.string "of them resists its own type.\p"
	.string "FIRE is your safest bet across\n"
	.string "the whole team, no exceptions.\p"
	.string "Don't reach for GROUND, either --\n"
	.string "JUMPLUFF is part FLYING. It won't\l"
	.string "even feel it.$"

CeladonCity_Gym_Text_GymStatue:
	.string "CELADON CITY POKéMON GYM\n"
	.string "LEADER: ERIKA\p"
	.string "The Nature-Loving Trainer$"

CeladonCity_Gym_Text_GymStatueCertified:
	.string "CELADON CITY POKéMON GYM\n"
	.string "LEADER: ERIKA\p"
	.string "ERIKA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

CeladonCity_Gym_Text_Label1:
	.string "A hand-lettered card sits among\nthe leaves, asking visitors not\lto pick the POKéMON.$"

CeladonCity_Gym_Text_Label2:
	.string "The hedges are trimmed into the\nshape of a VILEPLUME. Mostly.$"

CeladonCity_Gym_Text_Label3:
	.string "A small plaque reads: grown, not\nbought. Every leaf of it.$"
