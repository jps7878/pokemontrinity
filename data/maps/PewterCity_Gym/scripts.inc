@ ============================================================================
@ Trinity M5b S4 -- THE GYM PATTERN (G1-G7), canonical file VermilionCity_Gym/
@ scripts.inc (S1 Surge, the brief's own cited canonical). Map/leader/badge/TM
@ substituted; no puzzle, no cutscene -- this is the plan's lightest gym.
@ See docs/superpowers/plans/m5b/04-pewter-mt-moon.md section 6-7.
@ ============================================================================
PewterCity_Gym_MapScripts::
	.byte 0

@ ============================================================================
@ G1-G7 -- BROCK. G1: TRAINER_TYPE_NONE, sight 0, flag 0,
@ MOVEMENT_TYPE_FACE_DOWN, at the FRLG tile (6,5) (decoded col=0 elev=3
@ MB_NORMAL, free), appended to map.json after Liam/GymGuy so neither of
@ T10's existing indices shift. OVERWORLD: OBJ_EVENT_GFX_BROCK, FR's own
@ byte-identical overworld, ported by M7b Task 11b -- he previously wore
@ OBJ_EVENT_GFX_ROXANNE, which he shared with Hoenn's Roxanne and Johto's
@ Jasmine. NOTE his BATTLE pic is still TRAINER_PIC_LEADER_ROXANNE (an M5a
@ T11 boss-corps choice); overworld and battle identity no longer agree, and
@ the front-pic half is Task 12's call, not this task's.
@ ============================================================================
PewterCity_Gym_EventScript_Brock::
	trainerbattle_single TRAINER_BROCK, PewterCity_Gym_Text_BrockSeen, PewterCity_Gym_Text_BrockBeaten, PewterCity_Gym_EventScript_BrockDefeated, NO_MUSIC
	goto_if_unset FLAG_TRINITY_K_BROCK_TM37, PewterCity_Gym_EventScript_GiveTM37
	msgbox PewterCity_Gym_Text_BrockPostBattle, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_EventScript_BrockDefeated::
	message PewterCity_Gym_Text_ReceivedBoulderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_TRINITY_BADGE17
	msgbox PewterCity_Gym_Text_BoulderBadgeInfo, MSGBOX_DEFAULT
	goto PewterCity_Gym_EventScript_GiveTM37
	end

PewterCity_Gym_EventScript_GiveTM37::
	giveitem ITEM_TM_SANDSTORM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_K_BROCK_TM37
	msgbox PewterCity_Gym_Text_ExplainSandstorm, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ G6 -- Liam, T10's id/tile/wiring reviewed and kept (unmoved -- not a cut
@ vertex, matches the established "review, don't re-place" rule). Placeholder
@ "..." replaced with real dialogue, adapting FRLG's own iconic
@ "ten thousand light-years" joke (losslessly portable, genuinely good).
@ ============================================================================
PewterCity_Gym_EventScript_Liam::
	trainerbattle_single TRAINER_KANTO_CAMPER_LIAM, PewterCity_Gym_Text_LiamSeen, PewterCity_Gym_Text_LiamBeaten
	msgbox PewterCity_Gym_Text_LiamBeaten, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ G4 -- the guide. (7,12), T10-placed, unmoved (reach_check: 1-tile self-cost,
@ not a cut vertex). Roster GOLEM74/OMASTAR74/ONIX75/KABUTOPS75/RHYDON76
@ verified against trainers.h + species_info.h + types_info.h's own
@ gTypeEffectivenessTable -- see the sub-plan section 7 for the full table.
@ GRASS: 4x on all FIVE (Rock+Grass 2x stacks with either Ground+Grass 2x or
@ Water+Grass 2x -- no exception). WATER: 4x on GOLEM/ONIX/RHYDON (Rock+Water
@ 2x stacks with Ground+Water 2x) but only 1x/NEUTRAL on OMASTAR/KABUTOPS
@ (Rock+Water 2x is cancelled by their own Water+Water 0.5x resist). The
@ guide states both halves honestly.
@ ============================================================================
PewterCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_BADGE17, PewterCity_Gym_EventScript_GymGuyPostVictory
	msgbox PewterCity_Gym_Text_GymGuyAdvice, MSGBOX_DEFAULT
	release
	end

@ M7b Task 15 (finding #6): the guide states the player's LIVE badge count.
@ The tally reads the flags and buffers the number itself -- see
@ data/scripts/trinity_kanto.inc.
PewterCity_Gym_EventScript_GymGuyPostVictory::
	msgbox PewterCity_Gym_Text_GymGuyPostVictory, MSGBOX_DEFAULT
	call Trinity_EventScript_KantoBadgeTally
	release
	end

@ ============================================================================
@ G5 -- the statues. (4,12)/(8,12) decode col=1 MB_SIGNPOST (T10-placed,
@ correct). FIX ROUND (review M4): the two candidate approach tiles were
@ mislabeled. `BG_EVENT_PLAYER_FACING_NORTH` requires the PLAYER's own
@ facing direction to be DIR_NORTH at interact time
@ (GetInteractedBackgroundEventScript, src/field_control_avatar.c:430) --
@ i.e. the player must be standing SOUTH of the sign, looking up at it. So
@ the tile this constraint actually uses is the SOUTH one, (4,13)/(8,13);
@ the NORTH one, (4,11)/(8,11), plays no role under this constraint (it
@ would need FACING_SOUTH instead). Both decode dry MB_NORMAL either way --
@ Pewter has no water/hazard gimmick at all, so restricting ANY -> NORTH in
@ map.json is a pure house-convention match (VioletGym's/VermilionCity_
@ Gym's/CeruleanCity_Gym's own two-statue pattern), NOT a hazard-driven
@ choice. FRLG's own source for all three ported Kanto gyms ships ANY --
@ stated honestly, not invented as a false geometry reason (the S3
@ false-decode lesson).
@ ============================================================================
PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_TRINITY_BADGE17, PewterCity_Gym_EventScript_GymStatueCertified
	msgbox PewterCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

PewterCity_Gym_EventScript_GymStatue_2::
	lockall
	goto_if_set FLAG_TRINITY_BADGE17, PewterCity_Gym_EventScript_GymStatueCertified
	msgbox PewterCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

PewterCity_Gym_EventScript_GymStatueCertified::
	msgbox PewterCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@ Text
@ ============================================================================
PewterCity_Gym_Text_BrockSeen:
	.string "So. Two other regions' worth of\n"
	.string "badges, and you still walked in\l"
	.string "here like PEWTER was an afterthought.\p"
	.string "I'm BROCK. My POKéMON don't move\n"
	.string "for anybody -- ROCK doesn't.\p"
	.string "Let's see if you do.$"

PewterCity_Gym_Text_BrockBeaten:
	.string "Hah. Took you for granted, and\n"
	.string "paid for it.$"

PewterCity_Gym_Text_ReceivedBoulderBadge:
	.string "{PLAYER} received the\n"
	.string "BOULDERBADGE from BROCK.$"

PewterCity_Gym_Text_BoulderBadgeInfo:
	.string "BROCK: The BOULDERBADGE.\p"
	.string "Doesn't make you stronger. Just\n"
	.string "means KANTO's noticed you.\p"
	.string "Seven of these, and VIRIDIAN opens\n"
	.string "the door.\p"
	.string "Take this too -- you earned it.$"

PewterCity_Gym_Text_ExplainSandstorm:
	.string "BROCK: TM37. SANDSTORM.\p"
	.string "Whips up a storm that batters\n"
	.string "anything that isn't ROCK, GROUND,\l"
	.string "or STEEL. My kind of weather.\p"
	.string "Teach it to whoever you like.\n"
	.string "It won't wear out.$"

PewterCity_Gym_Text_BrockPostBattle:
	.string "There are all kinds of TRAINERS out\n"
	.string "there. You've got the makings of a\l"
	.string "good one.\p"
	.string "CERULEAN's GYM is worth your time\n"
	.string "next.$"

PewterCity_Gym_Text_LiamSeen:
	.string "Stop right there, kid!\n"
	.string "You're ten thousand light-years\l"
	.string "from facing BROCK!$"

PewterCity_Gym_Text_LiamBeaten:
	.string "Darn! Light-years isn't time --\n"
	.string "it measures distance!$"

PewterCity_Gym_Text_GymGuyAdvice:
	.string "Hiya! Here to challenge BROCK?\p"
	.string "GOLEM, OMASTAR, ONIX, KABUTOPS,\n"
	.string "RHYDON -- all ROCK type. LEVEL 74\l"
	.string "to 76.\p"
	.string "GRASS moves are your best bet.\n"
	.string "Every one of them takes four times\l"
	.string "the damage from GRASS.\p"
	.string "WATER's trickier than it looks --\n"
	.string "OMASTAR and KABUTOPS carry WATER\l"
	.string "themselves and shrug it right off.$"

PewterCity_Gym_Text_GymGuyPostVictory:
	.string "Straight through BROCK! Figured\n"
	.string "as much.\p"
	.string "BOULDERBADGE. One of seven.$"

PewterCity_Gym_Text_GymStatue:
	.string "PEWTER CITY POKéMON GYM\n"
	.string "LEADER: BROCK\p"
	.string "The Rock-Solid Trainer$"

PewterCity_Gym_Text_GymStatueCertified:
	.string "PEWTER CITY POKéMON GYM\n"
	.string "LEADER: BROCK\p"
	.string "BROCK'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
