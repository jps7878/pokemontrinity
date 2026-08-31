@ ============================================================================
@ Trinity M5b S10 -- VIRIDIAN GYM, Giovanni/BADGE24/TM26. Full decode + design:
@ docs/superpowers/plans/m5b/10-viridian-climax.md.
@
@ No MapScripts/ON_TRANSITION table needed: S10's own gate-timing decision
@ (raising ViridianCity's door-seal to arc>=4) makes this whole map
@ unconditionally post-rig by construction -- Giovanni's object, the guide,
@ and both statues are all `flag: "0"`, unconditionally present, since by the
@ time this map can load at all, every precondition already holds.
@ ============================================================================
ViridianCity_Gym_MapScripts::
	.byte 0

@ ----------------------------------------------------------------------------
@ G1-G7. TRAINER_GIOVANNI (1397), inside S1's GetBattleBGM leader-range guard
@ -> MUS_RG_VS_GYM_LEADER, zero code change. No dedicated Giovanni sprite
@ exists (grep, 0 hits) -- OBJ_EVENT_GFX_MAXIE substitutes (the closest
@ available thematic match, a calculating besuited crime-boss archetype;
@ disclosed M6 art debt, same class as every other leader substitution this
@ milestone -- see the sub-plan section 6 for the full reasoning).
@ ----------------------------------------------------------------------------
ViridianCity_Gym_EventScript_Giovanni::
	trainerbattle_single TRAINER_GIOVANNI, ViridianCity_Gym_Text_GiovanniSeen, ViridianCity_Gym_Text_GiovanniBeaten, ViridianCity_Gym_EventScript_GiovanniDefeated, NO_MUSIC
	goto_if_unset FLAG_TRINITY_K_GIOVANNI_TM26, ViridianCity_Gym_EventScript_GiveEarthquake
	msgbox ViridianCity_Gym_Text_GiovanniPostBattle, MSGBOX_DEFAULT
	release
	end

ViridianCity_Gym_EventScript_GiovanniDefeated::
	msgbox ViridianCity_Gym_Text_GiovanniDefeated, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_TRINITY_BADGE24
	msgbox ViridianCity_Gym_Text_BadgeMeaning, MSGBOX_DEFAULT
	goto ViridianCity_Gym_EventScript_GiveEarthquake
	end

ViridianCity_Gym_EventScript_GiveEarthquake::
	giveitem ITEM_TM_EARTHQUAKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_K_GIOVANNI_TM26
	msgbox ViridianCity_Gym_Text_ExplainEarthquake, MSGBOX_DEFAULT
	release
	end

@ ----------------------------------------------------------------------------
@ G6 -- eight existing trainers, real dialogue (ids/tiles/wiring reviewed,
@ unchanged).
@ ----------------------------------------------------------------------------
ViridianCity_Gym_EventScript_Takashi::
	trainerbattle_single TRAINER_KANTO_BLACK_BELT_TAKASHI, ViridianCity_Gym_Text_TakashiSeen, ViridianCity_Gym_Text_TakashiBeaten
	msgbox ViridianCity_Gym_Text_TakashiBeaten, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Yuji::
	trainerbattle_single TRAINER_KANTO_COOLTRAINER_YUJI, ViridianCity_Gym_Text_YujiSeen, ViridianCity_Gym_Text_YujiBeaten
	msgbox ViridianCity_Gym_Text_YujiBeaten, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Atsushi::
	trainerbattle_single TRAINER_KANTO_BLACK_BELT_ATSUSHI, ViridianCity_Gym_Text_AtsushiSeen, ViridianCity_Gym_Text_AtsushiBeaten
	msgbox ViridianCity_Gym_Text_AtsushiBeaten, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Jason::
	trainerbattle_single TRAINER_KANTO_TAMER_JASON, ViridianCity_Gym_Text_JasonSeen, ViridianCity_Gym_Text_JasonBeaten
	msgbox ViridianCity_Gym_Text_JasonBeaten, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Cole::
	trainerbattle_single TRAINER_KANTO_TAMER_COLE, ViridianCity_Gym_Text_ColeSeen, ViridianCity_Gym_Text_ColeBeaten
	msgbox ViridianCity_Gym_Text_ColeBeaten, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Kiyo::
	trainerbattle_single TRAINER_KANTO_BLACK_BELT_KIYO, ViridianCity_Gym_Text_KiyoSeen, ViridianCity_Gym_Text_KiyoBeaten
	msgbox ViridianCity_Gym_Text_KiyoBeaten, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Samuel::
	trainerbattle_single TRAINER_KANTO_COOLTRAINER_SAMUEL, ViridianCity_Gym_Text_SamuelSeen, ViridianCity_Gym_Text_SamuelBeaten
	msgbox ViridianCity_Gym_Text_SamuelBeaten, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Warren::
	trainerbattle_single TRAINER_KANTO_COOLTRAINER_WARREN, ViridianCity_Gym_Text_WarrenSeen, ViridianCity_Gym_Text_WarrenBeaten
	msgbox ViridianCity_Gym_Text_WarrenBeaten, MSGBOX_AUTOCLOSE
	end

@ ----------------------------------------------------------------------------
@ G4 -- the guide, roster-verified fresh against src/data/pokemon/
@ species_info/gen_1_families.h + src/data/types_info.h (unconditional, no
@ P_UPDATED_TYPES branch on any of the six). Persian NORMAL; Dugtrio GROUND;
@ Rhydon GROUND/ROCK; Marowak GROUND; Nidoqueen POISON/GROUND; Nidoking
@ POISON/GROUND. WATER: Ground column 2.0, Rock column 2.0, Poison column 1.0,
@ Normal column 1.0 -- per-mon product gives Rhydon 4x (both halves double),
@ four more at 2x, Persian neutral (1x). The exception is named, not
@ blanket-claimed (the S2 Mr. Mime lesson).
@ ----------------------------------------------------------------------------
ViridianCity_Gym_EventScript_GymGuy::
	msgbox ViridianCity_Gym_Text_GymGuy, MSGBOX_NPC
	end

ViridianCity_Gym_EventScript_GymStatue::
	goto_if_unset FLAG_TRINITY_BADGE24, ViridianCity_Gym_EventScript_GymStatuePreBadge
	msgbox ViridianCity_Gym_Text_GymStatueCertified, MSGBOX_SIGN
	end

ViridianCity_Gym_EventScript_GymStatuePreBadge::
	msgbox ViridianCity_Gym_Text_GymStatue, MSGBOX_SIGN
	end

ViridianCity_Gym_EventScript_GymStatue_2::
	goto_if_unset FLAG_TRINITY_BADGE24, ViridianCity_Gym_EventScript_GymStatue2PreBadge
	msgbox ViridianCity_Gym_Text_GymStatueCertified, MSGBOX_SIGN
	end

ViridianCity_Gym_EventScript_GymStatue2PreBadge::
	msgbox ViridianCity_Gym_Text_GymStatue_2, MSGBOX_SIGN
	end

ViridianCity_Gym_Text_GiovanniSeen:
	.string "Team Rocket's business here is\nfinished -- but VIRIDIAN's gym\lstill answers to me.\pOne of the strongest circuits\nin KANTO. Show me you've earned\lthe right to challenge it.$"

ViridianCity_Gym_Text_GiovanniBeaten:
	.string "…Heh. Twice in one day, I lose\neverything that mattered to me.\pAt least this time it's to\nsomeone who deserves it.$"

ViridianCity_Gym_Text_GiovanniDefeated:
	.string "GIOVANNI hands over the EARTH\nBADGE.$"

ViridianCity_Gym_Text_BadgeMeaning:
	.string "The EARTH BADGE. One of seven --\nand VIRIDIAN opens the door.\pWhatever I was underneath all\nthis, the gym itself was always\lreal. Wear it proudly.$"

ViridianCity_Gym_Text_ExplainEarthquake:
	.string "Take TM26 as well -- EARTHQUAKE.\nGround-type, and it won't wear\lout with use.$"

ViridianCity_Gym_Text_GiovanniPostBattle:
	.string "The gym's circuit stands, badge\nor no badge. That's the one\lthing I never faked.$"

ViridianCity_Gym_Text_TakashiSeen:
	.string "You made it past the basement?\nThen you've earned this fight.$"

ViridianCity_Gym_Text_TakashiBeaten:
	.string "Hah! Strong.$"

ViridianCity_Gym_Text_YujiSeen:
	.string "Half this gym used to be a\nfront. The battling was always\lreal, though.$"

ViridianCity_Gym_Text_YujiBeaten:
	.string "Guess the boss picked his last\nfight poorly.$"

ViridianCity_Gym_Text_AtsushiSeen:
	.string "GIOVANNI trained every one of\nus himself. Don't expect this\lto be easy.$"

ViridianCity_Gym_Text_AtsushiBeaten:
	.string "Ugh! He'll want to hear about\nthis.$"

ViridianCity_Gym_Text_JasonSeen:
	.string "Rocket or gym, doesn't matter --\nwe still fight for VIRIDIAN.$"

ViridianCity_Gym_Text_JasonBeaten:
	.string "Tough. Real tough.$"

ViridianCity_Gym_Text_ColeSeen:
	.string "You cleared out the basement AND\nyou're still standing? Fine.$"

ViridianCity_Gym_Text_ColeBeaten:
	.string "Whew. That settles that.$"

ViridianCity_Gym_Text_KiyoSeen:
	.string "GIOVANNI doesn't lose challengers\noften. Let's see why you're\ldifferent.$"

ViridianCity_Gym_Text_KiyoBeaten:
	.string "Hah! Not bad at all.$"

ViridianCity_Gym_Text_SamuelSeen:
	.string "Word is you cleaned up two other\nregions before this one. We'll\lsee.$"

ViridianCity_Gym_Text_SamuelBeaten:
	.string "Guess the rumors were true.$"

ViridianCity_Gym_Text_WarrenSeen:
	.string "Last trainer before the boss\nhimself. Make it count.$"

ViridianCity_Gym_Text_WarrenBeaten:
	.string "He's all yours now. Good luck.$"

ViridianCity_Gym_Text_GymGuy:
	.string "GIOVANNI's team is almost all\nGROUND-type -- Dugtrio, Rhydon,\lMarowak, both Nido, and Persian.\pWATER moves are your best bet:\nquadruple effective on RHYDON,\ldouble on four of the rest.\pOnly PERSIAN shrugs it off --\nplain NORMAL, no Ground half\lto exploit.$"

ViridianCity_Gym_Text_GymStatue:
	.string "They say a trainer beat both the\nHOENN and JOHTO Leagues. Wonder\lif they'll try KANTO next.$"

ViridianCity_Gym_Text_GymStatue_2:
	.string "They say a trainer beat both the\nHOENN and JOHTO Leagues. Wonder\lif they'll try KANTO next.$"

ViridianCity_Gym_Text_GymStatueCertified:
	.string "VIRIDIAN CITY POKéMON GYM\nLEADER: GIOVANNI\lWinning Trainers: CERTIFIED$"
