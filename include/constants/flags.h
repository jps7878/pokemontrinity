#ifndef GUARD_CONSTANTS_FLAGS_H
#define GUARD_CONSTANTS_FLAGS_H

#include "constants/opponents.h"
#include "constants/rematches.h"

// Temporary Flags
// These temporary flags are are cleared every time a map is loaded. They are used
// for things like shortening an NPCs introduction text if the player already spoke
// to them once.
#define TEMP_FLAGS_START 0x0
#define FLAG_TEMP_1      (TEMP_FLAGS_START + 0x1)
#define FLAG_TEMP_2      (TEMP_FLAGS_START + 0x2)
#define FLAG_TEMP_3      (TEMP_FLAGS_START + 0x3)
#define FLAG_TEMP_4      (TEMP_FLAGS_START + 0x4)
#define FLAG_TEMP_5      (TEMP_FLAGS_START + 0x5)  // Unused Flag
#define FLAG_TEMP_6      (TEMP_FLAGS_START + 0x6)  // Unused Flag
#define FLAG_TEMP_7      (TEMP_FLAGS_START + 0x7)  // Unused Flag
#define FLAG_TEMP_8      (TEMP_FLAGS_START + 0x8)  // Unused Flag
#define FLAG_TEMP_9      (TEMP_FLAGS_START + 0x9)  // Unused Flag
#define FLAG_TEMP_A      (TEMP_FLAGS_START + 0xA)  // Unused Flag
#define FLAG_TEMP_B      (TEMP_FLAGS_START + 0xB)  // Unused Flag
#define FLAG_TEMP_C      (TEMP_FLAGS_START + 0xC)  // Unused Flag
#define FLAG_TEMP_D      (TEMP_FLAGS_START + 0xD)  // Unused Flag
#define FLAG_TEMP_E      (TEMP_FLAGS_START + 0xE)  // When set, follower pokemon won't be spawned
#define FLAG_TEMP_F      (TEMP_FLAGS_START + 0xF)  // Unused Flag
#define FLAG_TEMP_10     (TEMP_FLAGS_START + 0x10) // Unused Flag
#define FLAG_TEMP_11     (TEMP_FLAGS_START + 0x11)
#define FLAG_TEMP_12     (TEMP_FLAGS_START + 0x12)
#define FLAG_TEMP_13     (TEMP_FLAGS_START + 0x13)
#define FLAG_TEMP_14     (TEMP_FLAGS_START + 0x14)
#define FLAG_TEMP_15     (TEMP_FLAGS_START + 0x15)
#define FLAG_TEMP_16     (TEMP_FLAGS_START + 0x16)
#define FLAG_TEMP_17     (TEMP_FLAGS_START + 0x17)
#define FLAG_TEMP_18     (TEMP_FLAGS_START + 0x18)
#define FLAG_TEMP_19     (TEMP_FLAGS_START + 0x19)
#define FLAG_TEMP_1A     (TEMP_FLAGS_START + 0x1A)
#define FLAG_TEMP_1B     (TEMP_FLAGS_START + 0x1B)
#define FLAG_TEMP_1C     (TEMP_FLAGS_START + 0x1C)
#define FLAG_TEMP_1D     (TEMP_FLAGS_START + 0x1D)
#define FLAG_TEMP_1E     (TEMP_FLAGS_START + 0x1E)
#define FLAG_TEMP_1F     (TEMP_FLAGS_START + 0x1F)
#define TEMP_FLAGS_END   FLAG_TEMP_1F
#define NUM_TEMP_FLAGS   (TEMP_FLAGS_END - TEMP_FLAGS_START + 1)

#define FLAG_TRINITY_STARTER_GIFT_A    0x20 // Trinity: chosen-trio line-mate A gifted (Mauville, Badge 3)
#define FLAG_TRINITY_STARTER_GIFT_B    0x21 // Trinity: chosen-trio line-mate B gifted (Fortree, Badge 6)
#define FLAG_ENABLE_SHIP_JOHTO    0x22 // Trinity: gates the S.S. TIDAL Johto sea route. Stays UNSET in M1 (Johto is built in M3/M4). Was FLAG_UNUSED_0x022 (genuinely free).
#define FLAG_RECEIVED_REWARD_HARJOT    0x23 // Trinity: HARJOT (Granite Cave) friend-reward claimed. Was FLAG_UNUSED_0x023 (genuinely free).
#define FLAG_RECEIVED_REWARD_PRABHJIT  0x24 // Trinity: PRABHJIT (New Mauville) friend-reward claimed. Was FLAG_UNUSED_0x024 (genuinely free).
#define FLAG_TRINITY_BADGE09    0x25 // Trinity: was FLAG_UNUSED_0x025 — Falkner
#define FLAG_TRINITY_BADGE10    0x26 // Trinity: was FLAG_UNUSED_0x026 — Bugsy
#define FLAG_TRINITY_BADGE11    0x27 // Trinity: was FLAG_UNUSED_0x027 — Whitney
#define FLAG_TRINITY_BADGE12    0x28 // Trinity: was FLAG_UNUSED_0x028 — Morty
#define FLAG_TRINITY_BADGE13    0x29 // Trinity: was FLAG_UNUSED_0x029 — Chuck
#define FLAG_TRINITY_BADGE14    0x2A // Trinity: was FLAG_UNUSED_0x02A — Jasmine
#define FLAG_TRINITY_BADGE15    0x2B // Trinity: was FLAG_UNUSED_0x02B — Pryce
#define FLAG_TRINITY_BADGE16    0x2C // Trinity: was FLAG_UNUSED_0x02C — Clair
#define FLAG_TRINITY_ARRIVED_JOHTO    0x2D // Trinity: was FLAG_UNUSED_0x02D — S.S. TIDAL Johto arrival scene (Olivine Port aide) has run
// Trinity M4b S1 (New Bark & the Silver opener). The four _HIDE flags are pure
// object visibility, driven from each map's ON_TRANSITION off
// VAR_TRINITY_JOHTO_SCENE_NEWBARK; the other three are durable story state read
// by later M4b slices.
#define FLAG_TRINITY_J_SILVER_NEWBARK_HIDE    0x2E // Trinity: was FLAG_UNUSED_0x02E — New Bark SILVER (lurking outside the lab) hidden
#define FLAG_TRINITY_J_SILVER_LAB_HIDE    0x2F // Trinity: was FLAG_UNUSED_0x02F — ELM'S LAB SILVER (break-in cutscene actor) hidden
#define FLAG_TRINITY_J_SILVER_ROUTE29_HIDE    0x30 // Trinity: was FLAG_UNUSED_0x030 — Route 29 SILVER (TRAINER_SILVER_1) hidden
#define FLAG_TRINITY_J_ELM_OFFICER_HIDE    0x31 // Trinity: was FLAG_UNUSED_0x031 — ELM'S LAB OFFICER (theft report) hidden
#define FLAG_TRINITY_J_RADIO_CARD    0x32 // Trinity: was FLAG_UNUSED_0x032 — ELM granted the RADIO CARD PokeNav upgrade (flavor only; read by S4/S8 radio beats)
#define FLAG_TRINITY_J_SILVER1_BEATEN    0x33 // Trinity: was FLAG_UNUSED_0x033 — TRAINER_SILVER_1 (Route 29) defeated
#define FLAG_TRINITY_J_MRPOKEMON_HOOK    0x34 // Trinity: was FLAG_UNUSED_0x034 — ELM named MR.POKéMON; his Red Scale request is live (S7 pays it off)
#define FLAG_TRINITY_J_ELM_AFTERMATH    0x35 // Trinity: was FLAG_UNUSED_0x035 — New Bark chapter complete (ELM's aftermath ran, VIOLET pointer given). Terminal beat made observable to later slices; progression still gates on VAR_TRINITY_JOHTO_ARC >= 2, this is flavor-gating only.
#define FLAG_TRINITY_J_FALKNER_TM40    0x36 // Trinity: was FLAG_UNUSED_0x036 — TM40 AERIAL ACE handed over by FALKNER. Bag-full retry guard (GYM PATTERN G2): the badge flag is set first and unconditionally, this one only after the item actually lands.
#define FLAG_TRINITY_J_SPROUT_ELDER_GIFT    0x37 // Trinity: was FLAG_UNUSED_0x037 — SPROUT TOWER ELDER's reward (PP UP) handed over. Same bag-full retry guard, non-gym form.
// Trinity M4b S3 (the AZALEA chapter). The six _HIDE flags are pure object
// visibility, authored ONLY by each map's ON_TRANSITION off VAR_TRINITY_JOHTO_ARC /
// VAR_TRINITY_JOHTO_SCENE_AZALEA (single-authority rule); scene bodies use
// addobject/removeobject and never write them. The rest are durable story state.
#define FLAG_TRINITY_J_AZALEA_ROCKETS_HIDE    0x38 // Trinity: was FLAG_UNUSED_0x038 — AZALEA TOWN's two TEAM ROCKET posts hidden (visible only while ARC == 2)
#define FLAG_TRINITY_J_AZALEA_SLOWPOKES_HIDE    0x39 // Trinity: was FLAG_UNUSED_0x039 — the four AZALEA TOWN SLOWPOKE and KURT'S HOUSE SLOWPOKE hidden (visible at ARC >= 3). One flag, two maps, one predicate.
#define FLAG_TRINITY_J_SILVER_AZALEA_HIDE    0x3A // Trinity: was FLAG_UNUSED_0x03A — AZALEA TOWN SILVER (TRAINER_SILVER_2) hidden
#define FLAG_TRINITY_J_WELL_RAID_HIDE    0x3B // Trinity: was FLAG_UNUSED_0x03B — SLOWPOKE WELL raid cast (3 grunts, EXEC PROTON, hurt KURT, 2 tail-cut SLOWPOKE) hidden (visible only while ARC == 2)
#define FLAG_TRINITY_J_WELL_KURT_END_HIDE    0x3C // Trinity: was FLAG_UNUSED_0x03C — the rescued-KURT actor: always hidden, spawned mid-scene with addobject
#define FLAG_TRINITY_J_KURT_HOME_HIDE    0x3D // Trinity: was FLAG_UNUSED_0x03D — KURT at home hidden (visible at ARC >= 3, i.e. after the well)
#define FLAG_TRINITY_J_SILVER2_BEATEN    0x3E // Trinity: was FLAG_UNUSED_0x03E — TRAINER_SILVER_2 (AZALEA TOWN) defeated
#define FLAG_TRINITY_J_KURT_LURE_BALL    0x3F // Trinity: was FLAG_UNUSED_0x03F — KURT's thank-you LURE BALL handed over. Bag-full retry guard.
#define FLAG_TRINITY_J_BUGSY_TM19    0x40 // Trinity: was FLAG_UNUSED_0x040 — TM19 GIGA DRAIN handed over by BUGSY. Bag-full retry guard (GYM PATTERN G2): FLAG_TRINITY_BADGE10 is set first and unconditionally.
#define FLAG_TRINITY_J_AZALEA_APRICORN    0x41 // Trinity: was FLAG_UNUSED_0x041 — AZALEA TOWN's apricorn tree has been picked (one WHITE APRICORN, once)
// Trinity M4b S4 (the GOLDENROD chapter). The two _PRE_HIDE flags are pure object
// visibility for the PRE-takeover casts, authored ONLY by each map's ON_TRANSITION
// off VAR_TRINITY_JOHTO_ARC (single-authority rule). THE S8 FLIP CONTRACT: S8 writes
// ONE thing -- setvar VAR_TRINITY_JOHTO_ARC, 6 -- and never touches these flags.
// Predicate on all six maps: visible iff ARC != 6 (the occupation is a WINDOW, not a
// terminal state -- a liberated tower whose staff stayed deleted forever is worse than
// the bug that would avoid). S8's Rocket cast gets its OWN flag and appended objects,
// so no removeobject of S8's can co-sign an S4 civilian into permanent non-existence.
#define FLAG_TRINITY_J_WHITNEY_TM45    0x42 // Trinity: was FLAG_UNUSED_0x042 — TM45 ATTRACT handed over by WHITNEY. Bag-full retry guard (GYM PATTERN G2): FLAG_TRINITY_BADGE11 is set first and unconditionally.
#define FLAG_TRINITY_J_GOLDENROD_PRE_HIDE    0x43 // Trinity: was FLAG_UNUSED_0x043 — GOLDENROD CITY's pre-takeover cast (7 civilians + the ROCKET scout) hidden. Visible iff ARC != 6.
#define FLAG_TRINITY_J_RADIO_TOWER_PRE_HIDE    0x44 // Trinity: was FLAG_UNUSED_0x044 — the RADIO TOWER's pre-takeover cast (17 objects across 1F-5F) hidden. Visible iff ARC != 6. One flag, five maps, one predicate.
#define FLAG_TRINITY_J_GOLDENROD_SCOUT_HIDE    0x45 // Trinity: was FLAG_UNUSED_0x045 — the GOLDENROD ROCKET SCOUT hidden. Visible iff ARC < 6: he is the ONE member of the city cast who RETIRES PERMANENTLY (GSC never resets EVENT_GOLDENROD_CITY_ROCKET_SCOUT once the takeover clears it), so he cannot ride the shared ARC != 6 flag. This is R1's "if a beat needs one member to outlive the others, give that member its own flag" — and the worked example of the escape hatch the S8 flip contract advertises.
// (FLAG_UNUSED_0x045 deleted by M4b S5: 0x45 was claimed above as
// FLAG_TRINITY_J_GOLDENROD_SCOUT_HIDE in S4's fix round, but the old alias was left
// behind. Two names for one bit is a landmine for the next slice hunting a free flag.)
// Trinity M4b S5 (the ECRUTEAK chapter -- the legendary arc ignites). The four _HIDE
// flags are pure object visibility, authored ONLY by each map's ON_TRANSITION off
// VAR_TRINITY_JOHTO_SCENE_ECRUTEAK / FLAG_TRINITY_J_BEASTS_AWAKENED (single-authority
// rule). FLAG_TRINITY_J_BEASTS_AWAKENED is the chapter's durable cross-map fact and is
// written in exactly one place: BurnedTowerB1F's awakening cutscene.
#define FLAG_TRINITY_J_BEASTS_AWAKENED    0x46 // Trinity: was FLAG_UNUSED_0x046 — RAIKOU, ENTEI and SUICUNE have woken in the BURNED TOWER's basement and scattered. Story state, monotonic, never cleared. Read by ECRUTEAK GYM (MORTY comes home), the WISE TRIOS ROOM, ECRUTEAK CITY, and S10 (beast lairs / TIN TOWER).
#define FLAG_TRINITY_J_BEASTS_HIDE    0x47 // Trinity: was FLAG_UNUSED_0x047 — the three BURNED TOWER B1F beast objects hidden. Visible iff VAR_TRINITY_JOHTO_SCENE_ECRUTEAK == 1 (armed after SILVER 3, gone after the awakening). One flag for the whole cast is correct here because all three retire together and permanently (R1).
#define FLAG_TRINITY_J_SILVER_BURNED_HIDE    0x48 // Trinity: was FLAG_UNUSED_0x048 — BURNED TOWER 1F SILVER (TRAINER_SILVER_3) hidden. Visible iff SCENE == 0 AND VAR_TRINITY_JOHTO_ARC >= 2 (M7 Task 4, bug-test finding #2: he fields the FERALIGATR stolen at ARC 2, so he is not in the tower before the theft). Authored only by BurnedTower1F's ON_TRANSITION.
#define FLAG_TRINITY_J_SILVER3_BEATEN    0x49 // Trinity: was FLAG_UNUSED_0x049 — TRAINER_SILVER_3 (BURNED TOWER 1F) defeated.
#define FLAG_TRINITY_J_MORTY_TOWER_HIDE    0x4A // Trinity: was FLAG_UNUSED_0x04A — MORTY hidden in the BURNED TOWER. Visible iff SCENE < 2: he is investigating the tower until the beasts wake, then goes back to his GYM.
#define FLAG_TRINITY_J_MORTY_GYM_HIDE    0x4B // Trinity: was FLAG_UNUSED_0x04B — MORTY hidden in ECRUTEAK GYM. The exact complement: visible iff FLAG_TRINITY_J_BEASTS_AWAKENED. An object flag can only hide-when-set, so the two halves of one character need two flags.
#define FLAG_TRINITY_J_MORTY_TM30    0x4C // Trinity: was FLAG_UNUSED_0x04C — TM30 SHADOW BALL handed over by MORTY. Bag-full retry guard (GYM PATTERN G2): FLAG_TRINITY_BADGE12 is set first and unconditionally.
// THE M4b CONTRACT'S LOW STORY-FLAG BLOCK (0x2E-0x4C) IS NOW EXHAUSTED.
// 0x4D/0x4E/0x4F are genuinely free as well -- verified, the only reference to each in the
// whole tree is its own #define below -- and the contract was amended after S5's review to
// make them claimable. S6+ take those three first, then 0x264+.
// Trinity M4b S6 (the WEST COAST chapter) takes the last three of the low block.
// THE CHAPTER HAS ONE DURABLE PREDICATE, FLAG_TRINITY_J_AMPHY_CURED, and everything
// about JASMINE hangs off it: she is on the LIGHTHOUSE roof while it is clear and in
// her GYM once it is set. The other two are the errand's two halves.
#define FLAG_TRINITY_J_JASMINE_ASKED    0x4D // Trinity: was FLAG_UNUSED_0x04D — JASMINE has explained AMPHY's sickness at OLIVINE LIGHTHOUSE 6F and asked for medicine. Arms the CIANWOOD PHARMACIST; nothing else reads it.
#define FLAG_TRINITY_J_SECRET_POTION    0x4E // Trinity: was FLAG_UNUSED_0x04E — the SECRETPOTION is in hand. ITEM_SECRET_POTION does not exist in this build (verified: no reference anywhere in include/src/data), so the key item is carried as a flag, exactly as S1 carried MR. POKéMON's request. SET by the PHARMACIST, CLEARED by JASMINE on delivery (the takeitem analogue) — so this flag is NOT the durable record of the errand, FLAG_TRINITY_J_AMPHY_CURED is.
#define FLAG_TRINITY_J_AMPHY_CURED    0x4F // Trinity: was FLAG_UNUSED_0x04F — the SECRETPOTION reached AMPHY and the LIGHTHOUSE is lit again. Story state, monotonic, never cleared. ONE writer (the 6F delivery beat) and it drives BOTH halves of JASMINE plus the OLIVINE GYM greeter's redirect.

// Scripts
#define FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA_STILL  0x50
#define FLAG_SET_WALL_CLOCK                      0x51
#define FLAG_RESCUED_BIRCH                       0x52
#define FLAG_LEGENDARIES_IN_SOOTOPOLIS           0x53

#define FLAG_TRINITY_K_MYSTERIOUS_INVITATION 0x54  // Trinity M5b S13a: was FLAG_UNUSED_0x054 -- the "Mysterious Invitation" beat. Co-signed the moment MEWTWO's CeruleanCave_B1F contract resolves (WON or the CAUGHT fall-through); VermilionCity's own Sailor object is its sole reader, offering the fade-warp to NEW ISLAND once set. Never set anywhere else; no arc write.
#define FLAG_TRINITY_K_MEWTWO_HIDE            0x55  // Trinity M5b S13a: was FLAG_UNUSED_0x055 -- MEWTWO's own visibility flag, CeruleanCave_B1F's ON_TRANSITION (visible iff VAR_TRINITY_KANTO_ARC>=6 AND FLAG_TRINITY_K_MEWTWO_RESOLVED unset). Zapdos/Articuno/Moltres HIDE-flag shape verbatim.

#define FLAG_HIDE_CONTEST_POKE_BALL          0x56  // Always set after new game, object it hides is added directly
#define FLAG_MET_RIVAL_MOM                   0x57
#define FLAG_BIRCH_AIDE_MET                  0x58
#define FLAG_DECLINED_BIKE                   0x59
#define FLAG_RECEIVED_BIKE                   0x5A
#define FLAG_WATTSON_REMATCH_AVAILABLE       0x5B
#define FLAG_COLLECTED_ALL_SILVER_SYMBOLS    0x5C
#define FLAG_GOOD_LUCK_SAFARI_ZONE           0x5D // Set after talking to NPC blocking Safari Zone entrance/exit once.
#define FLAG_RECEIVED_WAILMER_PAIL           0x5E
#define FLAG_RECEIVED_POKEBLOCK_CASE         0x5F
#define FLAG_RECEIVED_SECRET_POWER           0x60
#define FLAG_MET_TEAM_AQUA_HARBOR            0x61
#define FLAG_TV_EXPLAINED                    0x62
#define FLAG_MAUVILLE_GYM_BARRIERS_STATE     0x63
#define FLAG_MOSSDEEP_GYM_SWITCH_1           0x64 // Leftover from the RS version of Mossdeep Gym, functionally unused
#define FLAG_MOSSDEEP_GYM_SWITCH_2           0x65 //
#define FLAG_MOSSDEEP_GYM_SWITCH_3           0x66 //
#define FLAG_MOSSDEEP_GYM_SWITCH_4           0x67 //

#define FLAG_TRINITY_K_MEWTWO_RESOLVED         0x68  // Trinity M5b S13a: was FLAG_UNUSED_0x068 -- terminal (legendary contract clause 3), set on WON and on the CAUGHT fall-through, CeruleanCave_B1F/scripts.inc.

#define FLAG_OCEANIC_MUSEUM_MET_REPORTER     0x69
#define FLAG_RECEIVED_HM_STRENGTH            0x6A
#define FLAG_RECEIVED_HM_ROCK_SMASH          0x6B
#define FLAG_WHITEOUT_TO_LAVARIDGE           0x6C // Set after defeating Flannery, so the player cant white out from poison before receiving Go Goggles
#define FLAG_RECEIVED_HM_FLASH               0x6D
#define FLAG_RECEIVED_HM_FLY                 0x6E
#define FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT  0x6F
#define FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE  0x70
#define FLAG_UNUSED_RS_LEGENDARY_BATTLE_DONE 0x71 // Unused Flag. Used in R/S to indicate whether player defeated or caught Groudon/Kyogre in Cave of Origin.
#define FLAG_SCOTT_CALL_BATTLE_FRONTIER      0x72 // Used in order to activate a phone call from Scott, inviting the player to the SS Tidal.
#define FLAG_RECEIVED_METEORITE              0x73
#define FLAG_ADVENTURE_STARTED               0x74 // RECEIVED Pokédex.
#define FLAG_DEFEATED_MAGMA_SPACE_CENTER     0x75 // Set when Team Magma is defeated at Mossdeep's Space Center.
#define FLAG_MET_HIDDEN_POWER_GIVER          0x76

#define FLAG_CANCEL_BATTLE_ROOM_CHALLENGE    0x77

#define FLAG_LANDMARK_MIRAGE_TOWER           0x78
#define FLAG_RECEIVED_TM_BRICK_BREAK         0x79
#define FLAG_RECEIVED_HM_SURF                0x7A
#define FLAG_RECEIVED_HM_DIVE                0x7B
#define FLAG_REGISTER_RIVAL_POKENAV          0x7C
#define FLAG_DEFEATED_RIVAL_ROUTE_104        0x7D
#define FLAG_DEFEATED_WALLY_VICTORY_ROAD     0x7E
#define FLAG_MET_PRETTY_PETAL_SHOP_OWNER     0x7F
#define FLAG_ENABLE_ROXANNE_FIRST_CALL       0x80 // Set after defeating Brawly. This will activate a call with Roxanne in order to register her.
#define FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN  0x81
#define FLAG_DEFEATED_RIVAL_ROUTE103         0x82
#define FLAG_RECEIVED_DOLL_LANETTE           0x83
#define FLAG_RECEIVED_POTION_OLDALE          0x84
#define FLAG_RECEIVED_AMULET_COIN            0x85
#define FLAG_PENDING_DAYCARE_EGG             0x86
#define FLAG_THANKED_FOR_PLAYING_WITH_WALLY  0x87
#define FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL 0x88 // Set after defeating Wally outside Mauville Gym. Will activate a call later to register Wally.
#define FLAG_RECEIVED_HM_CUT                 0x89
#define FLAG_SCOTT_CALL_FORTREE_GYM          0x8A // Triggers call from Scott after defeating Winona
#define FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY   0x8B
#define FLAG_RECEIVED_6_SODA_POP             0x8C
#define FLAG_DEFEATED_SEASHORE_HOUSE         0x8D
#define FLAG_DEVON_GOODS_STOLEN              0x8E
#define FLAG_RECOVERED_DEVON_GOODS           0x8F
#define FLAG_RETURNED_DEVON_GOODS            0x90
#define FLAG_CAUGHT_LUGIA                    0x91
#define FLAG_CAUGHT_HO_OH                    0x92
#define FLAG_MR_BRINEY_SAILING_INTRO         0x93
#define FLAG_DOCK_REJECTED_DEVON_GOODS       0x94
#define FLAG_DELIVERED_DEVON_GOODS           0x95
#define FLAG_RECEIVED_CONTEST_PASS           0x96 // Unused, leftover from R/S
#define FLAG_RECEIVED_CASTFORM               0x97
#define FLAG_RECEIVED_SUPER_ROD              0x98
#define FLAG_RUSTBORO_NPC_TRADE_COMPLETED    0x99
#define FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED  0x9A
#define FLAG_FORTREE_NPC_TRADE_COMPLETED     0x9B
#define FLAG_BATTLE_FRONTIER_TRADE_DONE      0x9C
#define FLAG_FORCE_MIRAGE_TOWER_VISIBLE      0x9D
#define FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE   0x9E
#define FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN 0x9F
#define FLAG_COOL_PAINTING_MADE              0xA0
#define FLAG_BEAUTY_PAINTING_MADE            0xA1
#define FLAG_CUTE_PAINTING_MADE              0xA2
#define FLAG_SMART_PAINTING_MADE             0xA3
#define FLAG_TOUGH_PAINTING_MADE             0xA4
#define FLAG_RECEIVED_TM_ROCK_TOMB           0xA5
#define FLAG_RECEIVED_TM_BULK_UP             0xA6
#define FLAG_RECEIVED_TM_SHOCK_WAVE          0xA7
#define FLAG_RECEIVED_TM_OVERHEAT            0xA8
#define FLAG_RECEIVED_TM_FACADE              0xA9
#define FLAG_RECEIVED_TM_AERIAL_ACE          0xAA
#define FLAG_RECEIVED_TM_CALM_MIND           0xAB
#define FLAG_RECEIVED_TM_WATER_PULSE         0xAC
#define FLAG_HIDE_SECRET_BASE_TRAINER        0xAD
#define FLAG_DECORATION_1                    0xAE
#define FLAG_DECORATION_2                    0xAF
#define FLAG_DECORATION_3                    0xB0
#define FLAG_DECORATION_4                    0xB1
#define FLAG_DECORATION_5                    0xB2
#define FLAG_DECORATION_6                    0xB3
#define FLAG_DECORATION_7                    0xB4
#define FLAG_DECORATION_8                    0xB5
#define FLAG_DECORATION_9                    0xB6
#define FLAG_DECORATION_10                   0xB7
#define FLAG_DECORATION_11                   0xB8
#define FLAG_DECORATION_12                   0xB9
#define FLAG_DECORATION_13                   0xBA
#define FLAG_DECORATION_14                   0xBB
#define FLAG_RECEIVED_POKENAV                0xBC
#define FLAG_DELIVERED_STEVEN_LETTER         0xBD
#define FLAG_DEFEATED_WALLY_MAUVILLE         0xBE
#define FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F  0xBF
#define FLAG_RECEIVED_SUN_STONE_MOSSDEEP     0xC0
#define FLAG_WALLY_SPEECH                    0xC1
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1   0xC2 // Leftover from the RS version of Puzzle Room 7, functionally unused
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2   0xC3 //
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3   0xC4 //
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4   0xC5 //
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5   0xC6 //
#define FLAG_RUSTURF_TUNNEL_OPENED           0xC7
#define FLAG_RECEIVED_RED_SCARF              0xC8
#define FLAG_RECEIVED_BLUE_SCARF             0xC9
#define FLAG_RECEIVED_PINK_SCARF             0xCA
#define FLAG_RECEIVED_GREEN_SCARF            0xCB
#define FLAG_RECEIVED_YELLOW_SCARF           0xCC
#define FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER    0xCD
#define FLAG_ENCOUNTERED_LATIAS_OR_LATIOS    0xCE
#define FLAG_MET_ARCHIE_METEOR_FALLS         0xCF
#define FLAG_GOT_BASEMENT_KEY_FROM_WATTSON   0xD0
#define FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON 0xD1
#define FLAG_FAN_CLUB_STRENGTH_SHARED        0xD2 // Set when you rate the strength of another trainer in Lilycove's Trainer Fan Club.
#define FLAG_DEFEATED_RIVAL_RUSTBORO         0xD3
#define FLAG_RECEIVED_RED_OR_BLUE_ORB        0xD4
#define FLAG_RECEIVED_PREMIER_BALL_RUSTBORO  0xD5
#define FLAG_ENABLE_WALLY_MATCH_CALL         0xD6
#define FLAG_ENABLE_SCOTT_MATCH_CALL         0xD7
#define FLAG_ENABLE_MOM_MATCH_CALL           0xD8
#define FLAG_MET_DIVING_TREASURE_HUNTER      0xD9
#define FLAG_MET_WAILMER_TRAINER             0xDA
#define FLAG_EVIL_LEADER_PLEASE_STOP         0xDB

#define FLAG_NEVER_SET_0x0DC                 0xDC // This flag is read, but never written to

#define FLAG_RECEIVED_GO_GOGGLES             0xDD
#define FLAG_WINGULL_SENT_ON_ERRAND          0xDE
#define FLAG_RECEIVED_MENTAL_HERB            0xDF
#define FLAG_WINGULL_DELIVERED_MAIL          0xE0
#define FLAG_RECEIVED_20_COINS               0xE1
#define FLAG_RECEIVED_STARTER_DOLL           0xE2
#define FLAG_RECEIVED_GOOD_ROD               0xE3
#define FLAG_REGI_DOORS_OPENED               0xE4
#define FLAG_RECEIVED_TM_RETURN              0xE5
#define FLAG_RECEIVED_TM_SLUDGE_BOMB         0xE6
#define FLAG_RECEIVED_TM_ROAR                0xE7
#define FLAG_RECEIVED_TM_GIGA_DRAIN          0xE8

#define FLAG_TRINITY_J_CELEBI_HIDE            0xE9 // Trinity M5b S13b: was FLAG_UNUSED_0x0E9 -- CELEBI's own visibility flag, IlexForest's shrine scene (visible iff VAR_TRINITY_KANTO_ARC>=6 AND FLAG_TRINITY_K_GS_BALL set AND FLAG_TRINITY_J_CELEBI_RESOLVED unset). J-prefixed: physically and narratively a Johto-side scene (Ilex Shrine, GSC lore), matching TinTower1F's own FLAG_TRINITY_J_SUICUNE_HALL_HIDE precedent -- NOT the _K_JOHTO_SITTER_HIDE exception (that flag's subject is the Kanto-arc roster switch; this one's subject is a self-contained Johto beat that unlocks late). Flagged for reviewer scrutiny, sub-plan §3.5.

#define FLAG_RECEIVED_TM_REST                0xEA
#define FLAG_RECEIVED_TM_ATTRACT             0xEB
#define FLAG_RECEIVED_GLASS_ORNAMENT         0xEC
#define FLAG_RECEIVED_SILVER_SHIELD          0xED
#define FLAG_RECEIVED_GOLD_SHIELD            0xEE
#define FLAG_USED_STORAGE_KEY                0xEF
#define FLAG_USED_ROOM_1_KEY                 0xF0
#define FLAG_USED_ROOM_2_KEY                 0xF1
#define FLAG_USED_ROOM_4_KEY                 0xF2
#define FLAG_USED_ROOM_6_KEY                 0xF3
#define FLAG_MET_PROF_COZMO                  0xF4
#define FLAG_RECEIVED_WAILMER_DOLL           0xF5
#define FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104 0xF6
#define FLAG_DEFEATED_SS_TIDAL_TRAINERS      0xF7
#define FLAG_RECEIVED_SPELON_BERRY           0xF8
#define FLAG_RECEIVED_PAMTRE_BERRY           0xF9
#define FLAG_RECEIVED_WATMEL_BERRY           0xFA
#define FLAG_RECEIVED_DURIN_BERRY            0xFB
#define FLAG_RECEIVED_BELUE_BERRY            0xFC
#define FLAG_ENABLE_RIVAL_MATCH_CALL         0xFD
#define FLAG_RECEIVED_CHARCOAL               0xFE
#define FLAG_LATIOS_OR_LATIAS_ROAMING        0xFF
#define FLAG_RECEIVED_REPEAT_BALL            0x100
#define FLAG_RECEIVED_OLD_ROD                0x101
#define FLAG_RECEIVED_COIN_CASE              0x102
#define FLAG_RETURNED_RED_OR_BLUE_ORB        0x103
#define FLAG_RECEIVED_TM_SNATCH              0x104
#define FLAG_RECEIVED_TM_DIG                 0x105
#define FLAG_RECEIVED_TM_BULLET_SEED         0x106
#define FLAG_ENTERED_ELITE_FOUR              0x107
#define FLAG_RECEIVED_TM_HIDDEN_POWER        0x108
#define FLAG_RECEIVED_TM_TORMENT             0x109
#define FLAG_RECEIVED_LAVARIDGE_EGG          0x10A
#define FLAG_RECEIVED_REVIVED_FOSSIL_MON     0x10B
#define FLAG_SECRET_BASE_REGISTRY_ENABLED    0x10C
#define FLAG_RECEIVED_TM_THIEF               0x10D
#define FLAG_CONTEST_SKETCH_CREATED          0x10E  // Set but never read
#define FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE   0x10F
#define FLAG_RECEIVED_EXP_SHARE              0x110
#define FLAG_POKERUS_EXPLAINED               0x111
#define FLAG_RECEIVED_RUNNING_SHOES          0x112
#define FLAG_RECEIVED_QUICK_CLAW             0x113
#define FLAG_RECEIVED_KINGS_ROCK             0x114
#define FLAG_RECEIVED_MACHO_BRACE            0x115
#define FLAG_RECEIVED_SOOTHE_BELL            0x116
#define FLAG_RECEIVED_WHITE_HERB             0x117
#define FLAG_RECEIVED_SOFT_SAND              0x118
#define FLAG_ENABLE_PROF_BIRCH_MATCH_CALL    0x119
#define FLAG_RECEIVED_CLEANSE_TAG            0x11A
#define FLAG_RECEIVED_FOCUS_BAND             0x11B
#define FLAG_DECLINED_WALLY_BATTLE_MAUVILLE  0x11C
#define FLAG_RECEIVED_DEVON_SCOPE            0x11D
#define FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE  0x11E
#define FLAG_MET_DEVON_EMPLOYEE              0x11F
#define FLAG_MET_RIVAL_RUSTBORO              0x120
#define FLAG_RECEIVED_SILK_SCARF             0x121
#define FLAG_NOT_READY_FOR_BATTLE_ROUTE_120  0x122
#define FLAG_RECEIVED_SS_TICKET              0x123
#define FLAG_MET_RIVAL_LILYCOVE              0x124
#define FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE 0x125
#define FLAG_EXCHANGED_SCANNER               0x126
#define FLAG_KECLEON_FLED_FORTREE            0x127
#define FLAG_PETALBURG_MART_EXPANDED_ITEMS   0x128
#define FLAG_RECEIVED_MIRACLE_SEED           0x129
#define FLAG_RECEIVED_BELDUM                 0x12A
#define FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK   0x12B
#define FLAG_MET_FANCLUB_YOUNGER_BROTHER     0x12C
#define FLAG_RIVAL_LEFT_FOR_ROUTE103         0x12D
#define FLAG_OMIT_DIVE_FROM_STEVEN_LETTER    0x12E
#define FLAG_HAS_MATCH_CALL                  0x12F
#define FLAG_ADDED_MATCH_CALL_TO_POKENAV     0x130
#define FLAG_REGISTERED_STEVEN_POKENAV       0x131
#define FLAG_ENABLE_NORMAN_MATCH_CALL        0x132
#define FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN 0x133 // Set after you follow Steven to the entrance of the Cave of Origin.
#define FLAG_MET_ARCHIE_SOOTOPOLIS           0x134
#define FLAG_MET_MAXIE_SOOTOPOLIS            0x135
#define FLAG_MET_SCOTT_RUSTBORO              0x136
#define FLAG_WALLACE_GOES_TO_SKY_PILLAR      0x137 // Set after speaking to Wallace within the Cave of Origin.
#define FLAG_RECEIVED_HM_WATERFALL           0x138
#define FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS    0x139
#define FLAG_RECEIVED_AURORA_TICKET          0x13A
#define FLAG_RECEIVED_MYSTIC_TICKET          0x13B
#define FLAG_RECEIVED_OLD_SEA_MAP            0x13C
#define FLAG_WONDER_CARD_UNUSED_1            0x13D // These Wonder Card flags are referenced but never set
#define FLAG_WONDER_CARD_UNUSED_2            0x13E
#define FLAG_WONDER_CARD_UNUSED_3            0x13F
#define FLAG_WONDER_CARD_UNUSED_4            0x140
#define FLAG_WONDER_CARD_UNUSED_5            0x141
#define FLAG_WONDER_CARD_UNUSED_6            0x142
#define FLAG_WONDER_CARD_UNUSED_7            0x143
#define FLAG_WONDER_CARD_UNUSED_8            0x144
#define FLAG_WONDER_CARD_UNUSED_9            0x145
#define FLAG_WONDER_CARD_UNUSED_10           0x146
#define FLAG_WONDER_CARD_UNUSED_11           0x147
#define FLAG_WONDER_CARD_UNUSED_12           0x148
#define FLAG_WONDER_CARD_UNUSED_13           0x149
#define FLAG_WONDER_CARD_UNUSED_14           0x14A
#define FLAG_WONDER_CARD_UNUSED_15           0x14B
#define FLAG_WONDER_CARD_UNUSED_16           0x14C
#define FLAG_WONDER_CARD_UNUSED_17           0x14D
#define NUM_WONDER_CARD_FLAGS                (1 + FLAG_WONDER_CARD_UNUSED_17 - FLAG_RECEIVED_AURORA_TICKET)

#define FLAG_MIRAGE_TOWER_VISIBLE            0x14E
#define FLAG_CHOSE_ROOT_FOSSIL               0x14F
#define FLAG_CHOSE_CLAW_FOSSIL               0x150
#define FLAG_RECEIVED_POWDER_JAR             0x151

#define FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER 0x152

#define FLAG_MET_BATTLE_FRONTIER_BREEDER     0x153
#define FLAG_MET_BATTLE_FRONTIER_MANIAC      0x154
#define FLAG_ENTERED_CONTEST                 0x155
#define FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN  0x156
#define FLAG_MET_BATTLE_FRONTIER_GAMBLER     0x157
#define FLAG_ENABLE_MR_STONE_POKENAV         0x158
#define FLAG_NURSE_MENTIONS_GOLD_CARD        0x159
#define FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR  0x15A
#define FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR 0x15B

// Flags for whether a rematchable trainer has been registered in the player's Match Call.
// Most are used implicitly by adding their REMATCH_* id to TRAINER_REGISTERED_FLAGS_START.
// Some Match Call entries (like those for gym leaders, Wally, and all non-trainer NPCs like Prof. Birch)
// have their own separate flag that needs to be set to be enabled; see src/pokenav_match_call_data.c
#define TRAINER_REGISTERED_FLAGS_START       0x15C
#define FLAG_REGISTERED_ROSE                 (TRAINER_REGISTERED_FLAGS_START + REMATCH_ROSE)
#define FLAG_REGISTERED_ANDRES               (TRAINER_REGISTERED_FLAGS_START + REMATCH_ANDRES)
#define FLAG_REGISTERED_DUSTY                (TRAINER_REGISTERED_FLAGS_START + REMATCH_DUSTY)
#define FLAG_REGISTERED_LOLA                 (TRAINER_REGISTERED_FLAGS_START + REMATCH_LOLA)
#define FLAG_REGISTERED_RICKY                (TRAINER_REGISTERED_FLAGS_START + REMATCH_RICKY)
#define FLAG_REGISTERED_LILA_AND_ROY         (TRAINER_REGISTERED_FLAGS_START + REMATCH_LILA_AND_ROY)
#define FLAG_REGISTERED_CRISTIN              (TRAINER_REGISTERED_FLAGS_START + REMATCH_CRISTIN)
#define FLAG_REGISTERED_BROOKE               (TRAINER_REGISTERED_FLAGS_START + REMATCH_BROOKE)
#define FLAG_REGISTERED_WILTON               (TRAINER_REGISTERED_FLAGS_START + REMATCH_WILTON)
#define FLAG_REGISTERED_VALERIE              (TRAINER_REGISTERED_FLAGS_START + REMATCH_VALERIE)
#define FLAG_REGISTERED_CINDY                (TRAINER_REGISTERED_FLAGS_START + REMATCH_CINDY)
#define FLAG_REGISTERED_THALIA               (TRAINER_REGISTERED_FLAGS_START + REMATCH_THALIA)
#define FLAG_REGISTERED_JESSICA              (TRAINER_REGISTERED_FLAGS_START + REMATCH_JESSICA)
#define FLAG_REGISTERED_WINSTON              (TRAINER_REGISTERED_FLAGS_START + REMATCH_WINSTON)
#define FLAG_REGISTERED_STEVE                (TRAINER_REGISTERED_FLAGS_START + REMATCH_STEVE)
#define FLAG_REGISTERED_TONY                 (TRAINER_REGISTERED_FLAGS_START + REMATCH_TONY)
#define FLAG_REGISTERED_NOB                  (TRAINER_REGISTERED_FLAGS_START + REMATCH_NOB)
#define FLAG_REGISTERED_KOJI                 (TRAINER_REGISTERED_FLAGS_START + REMATCH_KOJI)
#define FLAG_REGISTERED_FERNANDO             (TRAINER_REGISTERED_FLAGS_START + REMATCH_FERNANDO)
#define FLAG_REGISTERED_DALTON               (TRAINER_REGISTERED_FLAGS_START + REMATCH_DALTON)
#define FLAG_REGISTERED_BERNIE               (TRAINER_REGISTERED_FLAGS_START + REMATCH_BERNIE)
#define FLAG_REGISTERED_ETHAN                (TRAINER_REGISTERED_FLAGS_START + REMATCH_ETHAN)
#define FLAG_REGISTERED_JOHN_AND_JAY         (TRAINER_REGISTERED_FLAGS_START + REMATCH_JOHN_AND_JAY)
#define FLAG_REGISTERED_JEFFREY              (TRAINER_REGISTERED_FLAGS_START + REMATCH_JEFFREY)
#define FLAG_REGISTERED_CAMERON              (TRAINER_REGISTERED_FLAGS_START + REMATCH_CAMERON)
#define FLAG_REGISTERED_JACKI                (TRAINER_REGISTERED_FLAGS_START + REMATCH_JACKI)
#define FLAG_REGISTERED_WALTER               (TRAINER_REGISTERED_FLAGS_START + REMATCH_WALTER)
#define FLAG_REGISTERED_KAREN                (TRAINER_REGISTERED_FLAGS_START + REMATCH_KAREN)
#define FLAG_REGISTERED_JERRY                (TRAINER_REGISTERED_FLAGS_START + REMATCH_JERRY)
#define FLAG_REGISTERED_ANNA_AND_MEG         (TRAINER_REGISTERED_FLAGS_START + REMATCH_ANNA_AND_MEG)
#define FLAG_REGISTERED_ISABEL               (TRAINER_REGISTERED_FLAGS_START + REMATCH_ISABEL)
#define FLAG_REGISTERED_MIGUEL               (TRAINER_REGISTERED_FLAGS_START + REMATCH_MIGUEL)
#define FLAG_REGISTERED_TIMOTHY              (TRAINER_REGISTERED_FLAGS_START + REMATCH_TIMOTHY)
#define FLAG_REGISTERED_SHELBY               (TRAINER_REGISTERED_FLAGS_START + REMATCH_SHELBY)
#define FLAG_REGISTERED_CALVIN               (TRAINER_REGISTERED_FLAGS_START + REMATCH_CALVIN)
#define FLAG_REGISTERED_ELLIOT               (TRAINER_REGISTERED_FLAGS_START + REMATCH_ELLIOT)
#define FLAG_REGISTERED_ISAIAH               (TRAINER_REGISTERED_FLAGS_START + REMATCH_ISAIAH)
#define FLAG_REGISTERED_MARIA                (TRAINER_REGISTERED_FLAGS_START + REMATCH_MARIA)
#define FLAG_REGISTERED_ABIGAIL              (TRAINER_REGISTERED_FLAGS_START + REMATCH_ABIGAIL)
#define FLAG_REGISTERED_DYLAN                (TRAINER_REGISTERED_FLAGS_START + REMATCH_DYLAN)
#define FLAG_REGISTERED_KATELYN              (TRAINER_REGISTERED_FLAGS_START + REMATCH_KATELYN)
#define FLAG_REGISTERED_BENJAMIN             (TRAINER_REGISTERED_FLAGS_START + REMATCH_BENJAMIN)
#define FLAG_REGISTERED_PABLO                (TRAINER_REGISTERED_FLAGS_START + REMATCH_PABLO)
#define FLAG_REGISTERED_NICOLAS              (TRAINER_REGISTERED_FLAGS_START + REMATCH_NICOLAS)
#define FLAG_REGISTERED_ROBERT               (TRAINER_REGISTERED_FLAGS_START + REMATCH_ROBERT)
#define FLAG_REGISTERED_LAO                  (TRAINER_REGISTERED_FLAGS_START + REMATCH_LAO)
#define FLAG_REGISTERED_CYNDY                (TRAINER_REGISTERED_FLAGS_START + REMATCH_CYNDY)
#define FLAG_REGISTERED_MADELINE             (TRAINER_REGISTERED_FLAGS_START + REMATCH_MADELINE)
#define FLAG_REGISTERED_JENNY                (TRAINER_REGISTERED_FLAGS_START + REMATCH_JENNY)
#define FLAG_REGISTERED_DIANA                (TRAINER_REGISTERED_FLAGS_START + REMATCH_DIANA)
#define FLAG_REGISTERED_AMY_AND_LIV          (TRAINER_REGISTERED_FLAGS_START + REMATCH_AMY_AND_LIV)
#define FLAG_REGISTERED_ERNEST               (TRAINER_REGISTERED_FLAGS_START + REMATCH_ERNEST)
#define FLAG_REGISTERED_CORY                 (TRAINER_REGISTERED_FLAGS_START + REMATCH_CORY)
#define FLAG_REGISTERED_EDWIN                (TRAINER_REGISTERED_FLAGS_START + REMATCH_EDWIN)
#define FLAG_REGISTERED_LYDIA                (TRAINER_REGISTERED_FLAGS_START + REMATCH_LYDIA)
#define FLAG_REGISTERED_ISAAC                (TRAINER_REGISTERED_FLAGS_START + REMATCH_ISAAC)
#define FLAG_REGISTERED_GABRIELLE            (TRAINER_REGISTERED_FLAGS_START + REMATCH_GABRIELLE)
#define FLAG_REGISTERED_CATHERINE            (TRAINER_REGISTERED_FLAGS_START + REMATCH_CATHERINE)
#define FLAG_REGISTERED_JACKSON              (TRAINER_REGISTERED_FLAGS_START + REMATCH_JACKSON)
#define FLAG_REGISTERED_HALEY                (TRAINER_REGISTERED_FLAGS_START + REMATCH_HALEY)
#define FLAG_REGISTERED_JAMES                (TRAINER_REGISTERED_FLAGS_START + REMATCH_JAMES)
#define FLAG_REGISTERED_TRENT                (TRAINER_REGISTERED_FLAGS_START + REMATCH_TRENT)
#define FLAG_REGISTERED_SAWYER               (TRAINER_REGISTERED_FLAGS_START + REMATCH_SAWYER)
#define FLAG_REGISTERED_KIRA_AND_DAN         (TRAINER_REGISTERED_FLAGS_START + REMATCH_KIRA_AND_DAN)
#define FLAG_REGISTERED_WALLY                (TRAINER_REGISTERED_FLAGS_START + REMATCH_WALLY_VR)
#define FLAG_REGISTERED_ROXANNE              (TRAINER_REGISTERED_FLAGS_START + REMATCH_ROXANNE)
#define FLAG_REGISTERED_BRAWLY               (TRAINER_REGISTERED_FLAGS_START + REMATCH_BRAWLY)
#define FLAG_REGISTERED_WATTSON              (TRAINER_REGISTERED_FLAGS_START + REMATCH_WATTSON)
#define FLAG_REGISTERED_FLANNERY             (TRAINER_REGISTERED_FLAGS_START + REMATCH_FLANNERY)
#define FLAG_REGISTERED_NORMAN               (TRAINER_REGISTERED_FLAGS_START + REMATCH_NORMAN)
#define FLAG_REGISTERED_WINONA               (TRAINER_REGISTERED_FLAGS_START + REMATCH_WINONA)
#define FLAG_REGISTERED_TATE_AND_LIZA        (TRAINER_REGISTERED_FLAGS_START + REMATCH_TATE_AND_LIZA)
#define FLAG_REGISTERED_JUAN                 (TRAINER_REGISTERED_FLAGS_START + REMATCH_JUAN)
#define FLAG_REGISTERED_SIDNEY               (TRAINER_REGISTERED_FLAGS_START + REMATCH_SIDNEY)
#define FLAG_REGISTERED_PHOEBE               (TRAINER_REGISTERED_FLAGS_START + REMATCH_PHOEBE)
#define FLAG_REGISTERED_GLACIA               (TRAINER_REGISTERED_FLAGS_START + REMATCH_GLACIA)
#define FLAG_REGISTERED_DRAKE                (TRAINER_REGISTERED_FLAGS_START + REMATCH_DRAKE)
#define FLAG_REGISTERED_WALLACE              (TRAINER_REGISTERED_FLAGS_START + REMATCH_WALLACE)

#define FLAG_TRINITY_J_CELEBI_RESOLVED        0x1AA // Trinity M5b S13b: was FLAG_UNUSED_0x1AA -- terminal (legendary contract clause 3), set on WON and on the CAUGHT fall-through, IlexForest/scripts.inc.
#define FLAG_TRINITY_K_JIRACHI_HIDE           0x1AB // Trinity M5b S13b: was FLAG_UNUSED_0x1AB -- JIRACHI's own visibility flag, MossdeepCity's comet scene (visible iff VAR_TRINITY_KANTO_ARC>=6 AND FLAG_TRINITY_K_JIRACHI_RESOLVED unset). K-prefixed per this milestone's own "Act III postgame content" convention (subject, not physical map region -- Mossdeep is Hoenn) -- flagged for reviewer scrutiny, sub-plan §3.6.

#define FLAG_DEFEATED_DEOXYS                 0x1AC
#define FLAG_BATTLED_DEOXYS                  0x1AD
#define FLAG_SHOWN_EON_TICKET                0x1AE
#define FLAG_SHOWN_AURORA_TICKET             0x1AF
#define FLAG_SHOWN_OLD_SEA_MAP               0x1B0
#define FLAG_MOVE_TUTOR_TAUGHT_SWAGGER       0x1B1
#define FLAG_MOVE_TUTOR_TAUGHT_ROLLOUT       0x1B2
#define FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER   0x1B3
#define FLAG_MOVE_TUTOR_TAUGHT_MIMIC         0x1B4
#define FLAG_MOVE_TUTOR_TAUGHT_METRONOME     0x1B5
#define FLAG_MOVE_TUTOR_TAUGHT_SLEEP_TALK    0x1B6
#define FLAG_MOVE_TUTOR_TAUGHT_SUBSTITUTE    0x1B7
#define FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH  0x1B8
#define FLAG_MOVE_TUTOR_TAUGHT_DOUBLE_EDGE   0x1B9
#define FLAG_MOVE_TUTOR_TAUGHT_EXPLOSION     0x1BA
#define FLAG_DEFEATED_REGIROCK               0x1BB
#define FLAG_DEFEATED_REGICE                 0x1BC
#define FLAG_DEFEATED_REGISTEEL              0x1BD
#define FLAG_DEFEATED_KYOGRE                 0x1BE
#define FLAG_DEFEATED_GROUDON                0x1BF
#define FLAG_DEFEATED_RAYQUAZA               0x1C0
#define FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE 0x1C1
#define FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE 0x1C2
#define FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE 0x1C3
#define FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT 0x1C4
#define FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT 0x1C5
#define FLAG_DEFEATED_SUDOWOODO              0x1C6
#define FLAG_DEFEATED_MEW                    0x1C7
#define FLAG_DEFEATED_LATIAS_OR_LATIOS       0x1C8
#define FLAG_CAUGHT_LATIAS_OR_LATIOS         0x1C9
#define FLAG_CAUGHT_MEW                      0x1CA
#define FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE 0x1CB
#define FLAG_MET_SCOTT_IN_VERDANTURF         0x1CC
#define FLAG_MET_SCOTT_IN_FALLARBOR          0x1CD
#define FLAG_MET_SCOTT_IN_LILYCOVE           0x1CE
#define FLAG_MET_SCOTT_IN_EVERGRANDE         0x1CF
#define FLAG_MET_SCOTT_ON_SS_TIDAL           0x1D0
#define FLAG_SCOTT_GIVES_BATTLE_POINTS       0x1D1
#define FLAG_COLLECTED_ALL_GOLD_SYMBOLS      0x1D2
#define FLAG_ENABLE_ROXANNE_MATCH_CALL       0x1D3
#define FLAG_ENABLE_BRAWLY_MATCH_CALL        0x1D4
#define FLAG_ENABLE_WATTSON_MATCH_CALL       0x1D5
#define FLAG_ENABLE_FLANNERY_MATCH_CALL      0x1D6
#define FLAG_ENABLE_WINONA_MATCH_CALL        0x1D7
#define FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL 0x1D8
#define FLAG_ENABLE_JUAN_MATCH_CALL          0x1D9

#define FLAG_TRINITY_K_JIRACHI_RESOLVED       0x1DA // Trinity M5b S13b: was FLAG_UNUSED_0x1DA -- terminal (legendary contract clause 3), set on WON and on the CAUGHT fall-through, MossdeepCity/scripts.inc.

#define FLAG_SHOWN_MYSTIC_TICKET             0x1DB
#define FLAG_DEFEATED_HO_OH                  0x1DC
#define FLAG_DEFEATED_LUGIA                  0x1DD

#define FLAG_TRINITY_K_JOHTO_SITTER_HIDE    0x1DE // Trinity M5b S11 fix round 1: was FLAG_UNUSED_0x1DE -- roster-switch C1 fix (0x4E9-0x4EF exhausted, fresh hex-audit of this isolated 6-slot vanilla run, bounded by FLAG_DEFEATED_LUGIA 0x1DD before and the Mystery Gift block 0x1E4+ after). Shared by all 6 M4 Johto E4/Champion sitter objects (fix round 2, re-review NEW-2: corrected from "5" -- Will/Koga/Bruno/Karen/Lance in their own rooms PLUS Lance's second object in the Hall of Fame, LOCALID_JOHTO_HOF_LANCE) -- hidden (SET) once 8 Kanto badges via C-COUNT; authored fresh from each affected map's ON_TRANSITION (CeruleanCity_OnTransition/FLAG_TRINITY_K_CAVE_GUARD_HIDE idiom), never from ON_LOAD (TrySpawnObjectEvents reads this at spawn time, which is AFTER ON_TRANSITION but object-instance calls like showobjectat cannot work that early -- see the C1 postmortem).
#define FLAG_TRINITY_K_KANTO_CAST_HIDE    0x1DF // Trinity M5b S11 fix round 1: was FLAG_UNUSED_0x1DF -- the complement of 0x1DE. Shared by all 13 Kanto objects this slice added (7 Indigo II lobby, 4 E4-II sitters, Ash's ChampionsRoom + HallOfFame objects) -- hidden (SET) below 8 Kanto badges, cleared once the threshold is reached. Same ON_TRANSITION authoring site as 0x1DE (one live C-COUNT check drives both).
#define FLAG_TRINITY_K_E4_ASH_BEATEN    0x1E0 // Trinity M5b S11 fix round 1: was FLAG_UNUSED_0x1E0 -- roster-switch C2 fix, same free run as 0x1DE/0x1DF. ASH's own re-fight guard in PokemonLeague_ChampionsRoom (replaces the false "provably unreachable" checktrainerflag TRAINER_ASH guard, which nothing in the tree ever clears) -- the exact FLAG_TRINITY_J_E4_LANCE_BEATEN shape, cleared by IndigoPlateau_PokemonCenter_1F_OnTransition beside the nine existing E4 clears.
#define FLAG_TRINITY_K_RED_HIDE    0x1E1 // Trinity M5b S12: was FLAG_UNUSED_0x1E1 -- RED's own object-visibility flag, SilverCaveRoom3's ON_TRANSITION. Visible while VAR_TRINITY_KANTO_ARC < 7, hidden (SET) once RED is beaten (arc reaches 7, S12's own single-writer arc write). Mirrors FLAG_TRINITY_K_SILVER_FINAL_HIDE's exact shape (Route1, S10).
#define FLAG_UNUSED_0x1E2                    0x1E2 // Unused Flag
#define FLAG_UNUSED_0x1E3                    0x1E3 // Unused Flag

// Mystery Gift Flags (Unknown)
#define FLAG_MYSTERY_GIFT_DONE               0x1E4
#define FLAG_MYSTERY_GIFT_1                  0x1E5
#define FLAG_MYSTERY_GIFT_2                  0x1E6
#define FLAG_MYSTERY_GIFT_3                  0x1E7
#define FLAG_MYSTERY_GIFT_4                  0x1E8
#define FLAG_MYSTERY_GIFT_5                  0x1E9
#define FLAG_MYSTERY_GIFT_6                  0x1EA
#define FLAG_MYSTERY_GIFT_7                  0x1EB
#define FLAG_MYSTERY_GIFT_8                  0x1EC
#define FLAG_MYSTERY_GIFT_9                  0x1ED
#define FLAG_MYSTERY_GIFT_10                 0x1EE
#define FLAG_MYSTERY_GIFT_11                 0x1EF
#define FLAG_MYSTERY_GIFT_12                 0x1F0
#define FLAG_MYSTERY_GIFT_13                 0x1F1
#define FLAG_MYSTERY_GIFT_14                 0x1F2
#define FLAG_MYSTERY_GIFT_15                 0x1F3

// Hidden Items
#define FLAG_HIDDEN_ITEMS_START                                                         0x1F4
#define FLAG_HIDDEN_ITEM_LAVARIDGE_TOWN_ICE_HEAL             (FLAG_HIDDEN_ITEMS_START + 0x00)
#define FLAG_HIDDEN_ITEM_TRICK_HOUSE_NUGGET                  (FLAG_HIDDEN_ITEMS_START + 0x01)
#define FLAG_HIDDEN_ITEM_ROUTE_111_STARDUST                  (FLAG_HIDDEN_ITEMS_START + 0x02)
#define FLAG_HIDDEN_ITEM_ROUTE_113_ETHER                     (FLAG_HIDDEN_ITEMS_START + 0x03)
#define FLAG_HIDDEN_ITEM_ROUTE_114_CARBOS                    (FLAG_HIDDEN_ITEMS_START + 0x04)
#define FLAG_HIDDEN_ITEM_ROUTE_119_CALCIUM                   (FLAG_HIDDEN_ITEMS_START + 0x05)
#define FLAG_HIDDEN_ITEM_ROUTE_119_ULTRA_BALL                (FLAG_HIDDEN_ITEMS_START + 0x06)
#define FLAG_HIDDEN_ITEM_ROUTE_123_SUPER_REPEL               (FLAG_HIDDEN_ITEMS_START + 0x07)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_CARBOS               (FLAG_HIDDEN_ITEMS_START + 0x08)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_GREEN_SHARD          (FLAG_HIDDEN_ITEMS_START + 0x09)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_PEARL                (FLAG_HIDDEN_ITEMS_START + 0x0A)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_BIG_PEARL            (FLAG_HIDDEN_ITEMS_START + 0x0B)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_BLUE_SHARD           (FLAG_HIDDEN_ITEMS_START + 0x0C)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_HEART_SCALE_1        (FLAG_HIDDEN_ITEMS_START + 0x0D)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_HEART_SCALE          (FLAG_HIDDEN_ITEMS_START + 0x0E)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_ULTRA_BALL           (FLAG_HIDDEN_ITEMS_START + 0x0F)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_STARDUST             (FLAG_HIDDEN_ITEMS_START + 0x10)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_PEARL                (FLAG_HIDDEN_ITEMS_START + 0x11)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_YELLOW_SHARD         (FLAG_HIDDEN_ITEMS_START + 0x12)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_IRON                 (FLAG_HIDDEN_ITEMS_START + 0x13)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_BIG_PEARL            (FLAG_HIDDEN_ITEMS_START + 0x14)
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_STAR_PIECE           (FLAG_HIDDEN_ITEMS_START + 0x15)
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_HP_UP                (FLAG_HIDDEN_ITEMS_START + 0x16)
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_HEART_SCALE          (FLAG_HIDDEN_ITEMS_START + 0x17)
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_RED_SHARD            (FLAG_HIDDEN_ITEMS_START + 0x18)
#define FLAG_HIDDEN_ITEM_UNDERWATER_128_PROTEIN              (FLAG_HIDDEN_ITEMS_START + 0x19)
#define FLAG_HIDDEN_ITEM_UNDERWATER_128_PEARL                (FLAG_HIDDEN_ITEMS_START + 0x1A)
#define FLAG_HIDDEN_ITEM_LILYCOVE_CITY_HEART_SCALE           (FLAG_HIDDEN_ITEMS_START + 0x1B)
#define FLAG_HIDDEN_ITEM_FALLARBOR_TOWN_NUGGET               (FLAG_HIDDEN_ITEMS_START + 0x1C)
#define FLAG_HIDDEN_ITEM_MT_PYRE_EXTERIOR_ULTRA_BALL         (FLAG_HIDDEN_ITEMS_START + 0x1D)
#define FLAG_HIDDEN_ITEM_ROUTE_113_TM_DOUBLE_TEAM            (FLAG_HIDDEN_ITEMS_START + 0x1E)
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_1_KEY             (FLAG_HIDDEN_ITEMS_START + 0x1F)
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_2_KEY             (FLAG_HIDDEN_ITEMS_START + 0x20)
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_4_KEY             (FLAG_HIDDEN_ITEMS_START + 0x21)
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_6_KEY             (FLAG_HIDDEN_ITEMS_START + 0x22)
#define FLAG_HIDDEN_ITEM_SS_TIDAL_LOWER_DECK_LEFTOVERS       (FLAG_HIDDEN_ITEMS_START + 0x23)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_CALCIUM              (FLAG_HIDDEN_ITEMS_START + 0x24)
#define FLAG_HIDDEN_ITEM_ROUTE_104_POTION                    (FLAG_HIDDEN_ITEMS_START + 0x25)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_HEART_SCALE_2        (FLAG_HIDDEN_ITEMS_START + 0x26)
#define FLAG_HIDDEN_ITEM_ROUTE_121_HP_UP                     (FLAG_HIDDEN_ITEMS_START + 0x27)
#define FLAG_HIDDEN_ITEM_ROUTE_121_NUGGET                    (FLAG_HIDDEN_ITEMS_START + 0x28)
#define FLAG_HIDDEN_ITEM_ROUTE_123_REVIVE                    (FLAG_HIDDEN_ITEMS_START + 0x29)
#define FLAG_HIDDEN_ITEM_ROUTE_114_REVIVE                    (FLAG_HIDDEN_ITEMS_START + 0x2A)
#define FLAG_HIDDEN_ITEM_LILYCOVE_CITY_PP_UP                 (FLAG_HIDDEN_ITEMS_START + 0x2B)
#define FLAG_HIDDEN_ITEM_ROUTE_104_SUPER_POTION              (FLAG_HIDDEN_ITEMS_START + 0x2C)
#define FLAG_HIDDEN_ITEM_ROUTE_116_SUPER_POTION              (FLAG_HIDDEN_ITEMS_START + 0x2D)
#define FLAG_HIDDEN_ITEM_ROUTE_106_STARDUST                  (FLAG_HIDDEN_ITEMS_START + 0x2E)
#define FLAG_HIDDEN_ITEM_ROUTE_106_HEART_SCALE               (FLAG_HIDDEN_ITEMS_START + 0x2F)
#define FLAG_HIDDEN_ITEM_GRANITE_CAVE_B2F_EVERSTONE_1        (FLAG_HIDDEN_ITEMS_START + 0x30)
#define FLAG_HIDDEN_ITEM_GRANITE_CAVE_B2F_EVERSTONE_2        (FLAG_HIDDEN_ITEMS_START + 0x31)
#define FLAG_HIDDEN_ITEM_ROUTE_109_REVIVE                    (FLAG_HIDDEN_ITEMS_START + 0x32)
#define FLAG_HIDDEN_ITEM_ROUTE_109_GREAT_BALL                (FLAG_HIDDEN_ITEMS_START + 0x33)
#define FLAG_HIDDEN_ITEM_ROUTE_109_HEART_SCALE_1             (FLAG_HIDDEN_ITEMS_START + 0x34)
#define FLAG_HIDDEN_ITEM_ROUTE_110_GREAT_BALL                (FLAG_HIDDEN_ITEMS_START + 0x35)
#define FLAG_HIDDEN_ITEM_ROUTE_110_REVIVE                    (FLAG_HIDDEN_ITEMS_START + 0x36)
#define FLAG_HIDDEN_ITEM_ROUTE_110_FULL_HEAL                 (FLAG_HIDDEN_ITEMS_START + 0x37)
#define FLAG_HIDDEN_ITEM_ROUTE_111_PROTEIN                   (FLAG_HIDDEN_ITEMS_START + 0x38)
#define FLAG_HIDDEN_ITEM_ROUTE_111_RARE_CANDY                (FLAG_HIDDEN_ITEMS_START + 0x39)
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_POTION              (FLAG_HIDDEN_ITEMS_START + 0x3A)
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_TINY_MUSHROOM_1     (FLAG_HIDDEN_ITEMS_START + 0x3B)
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_TINY_MUSHROOM_2     (FLAG_HIDDEN_ITEMS_START + 0x3C)
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_POKE_BALL           (FLAG_HIDDEN_ITEMS_START + 0x3D)
#define FLAG_HIDDEN_ITEM_ROUTE_104_POKE_BALL                 (FLAG_HIDDEN_ITEMS_START + 0x3E)
#define FLAG_HIDDEN_ITEM_ROUTE_106_POKE_BALL                 (FLAG_HIDDEN_ITEMS_START + 0x3F)
#define FLAG_HIDDEN_ITEM_ROUTE_109_ETHER                     (FLAG_HIDDEN_ITEMS_START + 0x40)
#define FLAG_HIDDEN_ITEM_ROUTE_110_POKE_BALL                 (FLAG_HIDDEN_ITEMS_START + 0x41)
#define FLAG_HIDDEN_ITEM_ROUTE_118_HEART_SCALE               (FLAG_HIDDEN_ITEMS_START + 0x42)
#define FLAG_HIDDEN_ITEM_ROUTE_118_IRON                      (FLAG_HIDDEN_ITEMS_START + 0x43)
#define FLAG_HIDDEN_ITEM_ROUTE_119_FULL_HEAL                 (FLAG_HIDDEN_ITEMS_START + 0x44)
#define FLAG_HIDDEN_ITEM_ROUTE_120_RARE_CANDY_2              (FLAG_HIDDEN_ITEMS_START + 0x45)
#define FLAG_HIDDEN_ITEM_ROUTE_120_ZINC                      (FLAG_HIDDEN_ITEMS_START + 0x46)
#define FLAG_HIDDEN_ITEM_ROUTE_120_RARE_CANDY_1              (FLAG_HIDDEN_ITEMS_START + 0x47)
#define FLAG_HIDDEN_ITEM_ROUTE_117_REPEL                     (FLAG_HIDDEN_ITEMS_START + 0x48)
#define FLAG_HIDDEN_ITEM_ROUTE_121_FULL_HEAL                 (FLAG_HIDDEN_ITEMS_START + 0x49)
#define FLAG_HIDDEN_ITEM_ROUTE_123_HYPER_POTION              (FLAG_HIDDEN_ITEMS_START + 0x4A)
#define FLAG_HIDDEN_ITEM_LILYCOVE_CITY_POKE_BALL             (FLAG_HIDDEN_ITEMS_START + 0x4B)
#define FLAG_HIDDEN_ITEM_JAGGED_PASS_GREAT_BALL              (FLAG_HIDDEN_ITEMS_START + 0x4C)
#define FLAG_HIDDEN_ITEM_JAGGED_PASS_FULL_HEAL               (FLAG_HIDDEN_ITEMS_START + 0x4D)
#define FLAG_HIDDEN_ITEM_MT_PYRE_EXTERIOR_MAX_ETHER          (FLAG_HIDDEN_ITEMS_START + 0x4E)
#define FLAG_HIDDEN_ITEM_MT_PYRE_SUMMIT_ZINC                 (FLAG_HIDDEN_ITEMS_START + 0x4F)
#define FLAG_HIDDEN_ITEM_MT_PYRE_SUMMIT_RARE_CANDY           (FLAG_HIDDEN_ITEMS_START + 0x50)
#define FLAG_HIDDEN_ITEM_VICTORY_ROAD_1F_ULTRA_BALL          (FLAG_HIDDEN_ITEMS_START + 0x51)
#define FLAG_HIDDEN_ITEM_VICTORY_ROAD_B2F_ELIXIR             (FLAG_HIDDEN_ITEMS_START + 0x52)
#define FLAG_HIDDEN_ITEM_VICTORY_ROAD_B2F_MAX_REPEL          (FLAG_HIDDEN_ITEMS_START + 0x53)
#define FLAG_HIDDEN_ITEM_ROUTE_120_REVIVE                    (FLAG_HIDDEN_ITEMS_START + 0x54)
#define FLAG_HIDDEN_ITEM_ROUTE_104_ANTIDOTE                  (FLAG_HIDDEN_ITEMS_START + 0x55)
#define FLAG_HIDDEN_ITEM_ROUTE_108_RARE_CANDY                (FLAG_HIDDEN_ITEMS_START + 0x56)
#define FLAG_HIDDEN_ITEM_ROUTE_119_MAX_ETHER                 (FLAG_HIDDEN_ITEMS_START + 0x57)
#define FLAG_HIDDEN_ITEM_ROUTE_104_HEART_SCALE               (FLAG_HIDDEN_ITEMS_START + 0x58)
#define FLAG_HIDDEN_ITEM_ROUTE_105_HEART_SCALE               (FLAG_HIDDEN_ITEMS_START + 0x59)
#define FLAG_HIDDEN_ITEM_ROUTE_109_HEART_SCALE_2             (FLAG_HIDDEN_ITEMS_START + 0x5A)
#define FLAG_HIDDEN_ITEM_ROUTE_109_HEART_SCALE_3             (FLAG_HIDDEN_ITEMS_START + 0x5B)
#define FLAG_HIDDEN_ITEM_ROUTE_128_HEART_SCALE_1             (FLAG_HIDDEN_ITEMS_START + 0x5C)
#define FLAG_HIDDEN_ITEM_ROUTE_128_HEART_SCALE_2             (FLAG_HIDDEN_ITEMS_START + 0x5D)
#define FLAG_HIDDEN_ITEM_ROUTE_128_HEART_SCALE_3             (FLAG_HIDDEN_ITEMS_START + 0x5E)
#define FLAG_HIDDEN_ITEM_PETALBURG_CITY_RARE_CANDY           (FLAG_HIDDEN_ITEMS_START + 0x5F)
#define FLAG_HIDDEN_ITEM_ROUTE_116_BLACK_GLASSES             (FLAG_HIDDEN_ITEMS_START + 0x60)
#define FLAG_HIDDEN_ITEM_ROUTE_115_HEART_SCALE               (FLAG_HIDDEN_ITEMS_START + 0x61)
#define FLAG_HIDDEN_ITEM_ROUTE_113_NUGGET                    (FLAG_HIDDEN_ITEMS_START + 0x62)
#define FLAG_HIDDEN_ITEM_ROUTE_123_PP_UP                     (FLAG_HIDDEN_ITEMS_START + 0x63)
#define FLAG_HIDDEN_ITEM_ROUTE_121_MAX_REVIVE                (FLAG_HIDDEN_ITEMS_START + 0x64)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_CALCIUM            (FLAG_HIDDEN_ITEMS_START + 0x65)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_ZINC               (FLAG_HIDDEN_ITEMS_START + 0x66)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_PROTEIN            (FLAG_HIDDEN_ITEMS_START + 0x67)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_IRON               (FLAG_HIDDEN_ITEMS_START + 0x68)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_SOUTH_EAST_FULL_RESTORE (FLAG_HIDDEN_ITEMS_START + 0x69)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_NORTH_EAST_RARE_CANDY   (FLAG_HIDDEN_ITEMS_START + 0x6A)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_NORTH_EAST_ZINC         (FLAG_HIDDEN_ITEMS_START + 0x6B)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_SOUTH_EAST_PP_UP        (FLAG_HIDDEN_ITEMS_START + 0x6C)
#define FLAG_HIDDEN_ITEM_NAVEL_ROCK_TOP_SACRED_ASH           (FLAG_HIDDEN_ITEMS_START + 0x6D)
#define FLAG_HIDDEN_ITEM_ROUTE_123_RARE_CANDY                (FLAG_HIDDEN_ITEMS_START + 0x6E)
#define FLAG_HIDDEN_ITEM_ROUTE_105_BIG_PEARL                 (FLAG_HIDDEN_ITEMS_START + 0x6F)

// M4b S5: the FIRST claim from the high block. The low story-flag block (0x2E-0x4C) is
// exhausted; the M4b contract directs later claims here. This one is a Trinity
// friend-reward guard, sibling of FLAG_RECEIVED_REWARD_HARJOT (0x23) / _PRABHJIT (0x24).
#define FLAG_RECEIVED_REWARD_SUMEET  0x264 // Trinity: was FLAG_UNUSED_0x264 — SUMEET (BURNED TOWER approach, ECRUTEAK CITY) friend-reward claimed. One-time; the giveitem branches only set it once the item actually lands, so a full bag retries on the next talk.
// M4b S6 (the WEST COAST chapter). The low block ran out mid-slice, so the remaining six
// claims come from here. The two JASMINE flags are EXACT COMPLEMENTS of one boolean
// (FLAG_TRINITY_J_AMPHY_CURED) and are authored ONLY by their own map's ON_TRANSITION --
// an object flag can only hide-when-set, so the two halves of one character need two
// flags (the same shape S5 used for MORTY's tower/gym split).
#define FLAG_TRINITY_J_JASMINE_LIGHTHOUSE_HIDE  0x265 // Trinity: was FLAG_UNUSED_0x265 — JASMINE hidden on OLIVINE LIGHTHOUSE 6F. Visible iff NOT FLAG_TRINITY_J_AMPHY_CURED. Also co-signed by the delivery beat's removeobject (R1), which is what makes her exit stick for the rest of the session.
#define FLAG_TRINITY_J_JASMINE_GYM_HIDE  0x266 // Trinity: was FLAG_UNUSED_0x266 — JASMINE hidden in OLIVINE GYM. The exact complement: visible iff FLAG_TRINITY_J_AMPHY_CURED.
#define FLAG_TRINITY_J_CHUCK_TM01  0x267 // Trinity: was FLAG_UNUSED_0x267 — TM01 FOCUS PUNCH handed over by CHUCK. Bag-full retry guard (GYM PATTERN G2): FLAG_TRINITY_BADGE13 is set first and unconditionally.
#define FLAG_TRINITY_J_JASMINE_TM23  0x268 // Trinity: was FLAG_UNUSED_0x268 — TM23 IRON TAIL handed over by JASMINE. Same G2 guard; FLAG_TRINITY_BADGE14 is set first.
#define FLAG_TRINITY_J_SUICUNE_CIANWOOD_HIDE  0x269 // Trinity: was FLAG_UNUSED_0x269 — the CIANWOOD CITY SUICUNE object hidden. Visible iff VAR_TRINITY_JOHTO_SCENE_WESTCOAST == 1 (armed once the beasts are awake, gone once the glimpse has played). Authored only by CianwoodCity's ON_TRANSITION.
#define FLAG_TRINITY_J_SUICUNE_CIANWOOD  0x26A // Trinity: was FLAG_UNUSED_0x26A — SUICUNE glimpse 2 (the CIANWOOD shore) has played. Story state, monotonic, never cleared. [S12 correction] Comment previously claimed S10 reads this flag alongside FLAG_TRINITY_J_BEASTS_AWAKENED; it does not -- this flag has no script reader today. The shipped gate for the equivalent CIANWOOD/beast-lair content is FLAG_TRINITY_J_BEASTS_AWAKENED alone.
#define FLAG_TRINITY_J_FORCE_SHINY       0x26B // Trinity: was FLAG_UNUSED_0x26B -- engine hook. include/config/pokemon.h's P_FLAG_FORCE_SHINY points at THIS flag, so while it is set every wild/gift POKeMON is forced shiny (src/pokemon.c:1071-1077, src/script_pokemon_util.c:364). Set and cleared inside one three-command window around the RED GYARADOS setwildbattle -- nothing can interleave, and an unsaved setflag cannot survive a reset.
#define FLAG_TRINITY_J_RED_GYARADOS_HIDE 0x26C // Trinity: was FLAG_UNUSED_0x26C -- visibility - the LAKE OF RAGE RED GYARADOS. THIS FLAG HAS NO AUTHORING CLAUSE, deliberately: it has exactly ONE writer (the battle script's removeobject co-sign, R1), it is monotonic, and its new-game default of clear = visible is already correct. There is no arc or scene value that means "the fish is gone" -- it can be faced any time from ARC 3 and the arc does not move until LANCE is agreed to -- so an ON_TRANSITION predicate would have nothing to author from and would resurrect a beaten GYARADOS. LakeOfRage_OnTransition says so at the definition.
#define FLAG_TRINITY_J_RED_SCALE         0x26D // Trinity: was FLAG_UNUSED_0x26D -- story, CONSUMABLE. ITEM_RED_SCALE does not exist in this build (S1's open item, ruled here), so the scale is a flag: SET by the RED GYARADOS beat, CLEARED by MR.POKeMON on the trade. Because it is cleared, every reader must test the TERMINAL flag first -- S6's rule.
#define FLAG_TRINITY_J_EXP_SHARE         0x26E // Trinity: was FLAG_UNUSED_0x26E -- story TERMINAL + G2 award guard - MR.POKeMON has handed over the EXP.SHARE. Tested BEFORE FLAG_TRINITY_J_RED_SCALE, because the scale returns to its starting value on the trade.
#define FLAG_TRINITY_J_LANCE_LAKE_HIDE   0x26F // Trinity: was FLAG_UNUSED_0x26F -- visibility - LANCE on the LAKE OF RAGE shore. Visible iff FLAG_TRINITY_J_RED_GYARADOS_HIDE (the fish is gone) and ARC < 4.
#define FLAG_TRINITY_J_LAKE_CIVILIANS_HIDE 0x270 // Trinity: was FLAG_UNUSED_0x270 -- visibility (4 trainers) - GSC's EVENT_LAKE_OF_RAGE_CIVILIANS. Visible iff ARC >= 5: they are the raid's victory lap, not an obstacle.
#define FLAG_TRINITY_J_MART_ROCKETS_HIDE 0x271 // Trinity: was FLAG_UNUSED_0x271 -- visibility (2) - the MAHOGANY MART PHARMACIST and BLACK BELT, GSC's EVENT_TEAM_ROCKET_BASE_POPULATION. Visible iff ARC < 5.
#define FLAG_TRINITY_J_MART_LANCE_HIDE   0x272 // Trinity: was FLAG_UNUSED_0x272 -- visibility (2) - LANCE and his DRAGONITE in the MART. addobject-only cutscene actors: the flag is SET on every transition (S1/S3 idiom) so no new-game default is needed.
#define FLAG_TRINITY_J_MART_GRANNY_HIDE  0x273 // Trinity: was FLAG_UNUSED_0x273 -- visibility - the real shop owner behind the counter. Visible iff ARC >= 5.
#define FLAG_TRINITY_J_MART_STAIRS       0x274 // Trinity: was FLAG_UNUSED_0x274 -- story - LANCE's DRAGONITE has uncovered the staircase. The ONLY input to MahoganyMart1F's setmetatile door authoring (D4); while it is clear the shop's 2x2 BOOKSHELF block covers the warp at (7,3).
#define FLAG_TRINITY_J_BASE_CAST_HIDE    0x275 // Trinity: was FLAG_UNUSED_0x275 -- visibility (10 objects, 3 maps) - every grunt/scientist post in the TEAM ROCKET BASE plus the beaten ROCKET on B3F. Visible iff ARC == 4. The two execs and LANCE carry their own flags so that an exec's removeobject cannot co-sign the whole base away (R1's trap).
#define FLAG_TRINITY_J_BASE_ARIANA_HIDE  0x276 // Trinity: was FLAG_UNUSED_0x276 -- visibility - EXEC ARIANA on B2F. Visible iff ARC == 4 and SCENE_MAHOGANY == 0.
#define FLAG_TRINITY_J_BASE_PETREL_HIDE  0x277 // Trinity: was FLAG_UNUSED_0x277 -- visibility (2) - EXEC PETREL and the MURKROW in GIOVANNI's office. visible iff ARC == 4. They share a flag because they share a fate: nothing removeobject's either of them, so the shared flag is never co-signed and both simply retire with the rest of the raid at ARC 5.
#define FLAG_TRINITY_J_BASE_LANCE_B2F_HIDE 0x278 // Trinity: was FLAG_UNUSED_0x278 -- visibility - LANCE at the B2F stairs. visible iff (ARC == 4 and SCENE_MAHOGANY < 4) OR (ARC >= 5 and NOT FLAG_TRINITY_J_LANCE_TM15). The second clause is not decoration: TM15 is the raid's only failable gift and G2 puts the arc write in FRONT of the giveitem, so the raid can be over with the TM still owed -- the award guard therefore owns the giver's visibility too.
#define FLAG_TRINITY_J_BASE_LANCE_B3F_HIDE 0x279 // Trinity: was FLAG_UNUSED_0x279 -- visibility - LANCE's B3F password cameo. Visible iff ARC == 4 and NOT FLAG_TRINITY_J_DOOR_B3F.
#define FLAG_TRINITY_J_BASE_SILVER_HIDE  0x27A // Trinity: was FLAG_UNUSED_0x27A -- visibility - SILVER's B3F cameo actor. addobject-only: SET on every transition.
#define FLAG_TRINITY_J_SILVER4_SEEN      0x27B // Trinity: was FLAG_UNUSED_0x27B -- story - SILVER's TEAM ROCKET BASE monologue has played. Writer only in S7; S8/S11 may read it.
#define FLAG_TRINITY_J_PASSWORD_SLOWPOKETAIL 0x27C // Trinity: was FLAG_UNUSED_0x27C -- story - the first office password, learnt by RE-TALKING to the B3F female grunt after beating her (GSC's endifjustbattled gating, ported faithfully).
#define FLAG_TRINITY_J_PASSWORD_RATICATE 0x27D // Trinity: was FLAG_UNUSED_0x27D -- story - the second office password, same shape, from the B3F male grunt.
#define FLAG_TRINITY_J_PASSWORD_GIOVANNI 0x27E // Trinity: was FLAG_UNUSED_0x27E -- story - HAIL GIOVANNI, from the MURKROW inside the office. Opens the B2F transmitter door.
#define FLAG_TRINITY_J_DOOR_B3F          0x27F // Trinity: was FLAG_UNUSED_0x27F -- door state - GIOVANNI's office door on B3F is open. The single input to TeamRocketBaseB3F's setmetatile authoring (D2/D4).
#define FLAG_TRINITY_J_DOOR_B2F          0x280 // Trinity: was FLAG_UNUSED_0x280 -- door state - the transmitter door on B2F is open. Same shape.
#define FLAG_TRINITY_J_ELECTRODE_1       0x281 // Trinity: was FLAG_UNUSED_0x281 -- visibility (2 objects) - the first ELECTRODE and its twin on LANCE's side. Like the RED GYARADOS flag this has NO authoring clause and must not acquire one: it is a pure DEFEAT MARKER with a single writer (removeobject's co-sign, which retires the pair together) and a correct default. The hall it stands in cannot be entered until the transmitter door opens, so "visible by default" is safe, and any scene predicate would resurrect a beaten ELECTRODE on the next map load -- the flag is already doing double duty as "the phase is live" and "this one is down".
#define FLAG_TRINITY_J_ELECTRODE_2       0x282 // Trinity: was FLAG_UNUSED_0x282 -- visibility (2 objects) - the second ELECTRODE pair.
#define FLAG_TRINITY_J_ELECTRODE_3       0x283 // Trinity: was FLAG_UNUSED_0x283 -- visibility (2 objects) - the third ELECTRODE pair.
#define FLAG_TRINITY_J_LANCE_TM15        0x284 // Trinity: was FLAG_UNUSED_0x284 -- G2 award guard - TM15 HYPER BEAM handed over by LANCE. Substitutes GSC's HM06 WHIRLPOOL, which does not exist in this build.
#define FLAG_TRINITY_J_PRYCE_TM07        0x285 // Trinity: was FLAG_UNUSED_0x285 -- G2 award guard - TM07 HAIL handed over by PRYCE. FLAG_TRINITY_BADGE15 is set first and unconditionally.
#define FLAG_TRINITY_J_R43_ROCKETS_HIDE  0x286 // Trinity: was FLAG_UNUSED_0x286 -- visibility (2) - the ROUTE 43 GATE toll ROCKETS. Visible iff ARC < 5.
#define FLAG_TRINITY_J_R43_OFFICER_HIDE  0x287 // Trinity: was FLAG_UNUSED_0x287 -- visibility - the OFFICER the toll ROCKETS chased off his post. Visible iff ARC >= 5 (the exact complement).
#define FLAG_TRINITY_J_R43_OFFICER_TM    0x288 // Trinity: was FLAG_UNUSED_0x288 -- G2 award guard - TM36 SLUDGE BOMB, left behind by the ROCKETS.
#define FLAG_TRINITY_J_R43_TOLL          0x289 // Trinity: was FLAG_UNUSED_0x289 -- story - the ROUTE 43 toll has been paid once. GSC re-arms per direction; S7 makes it one-shot.
#define FLAG_TRINITY_J_MAHOGANY_FISHER_HIDE 0x28A // Trinity: was FLAG_UNUSED_0x28A -- visibility - the FISHER who points at the LAKE. Visible iff ARC < 5, GSC's EVENT_MAHOGANY_TOWN_POKEFAN_M_BLOCKS_GYM. He is moved OFF the gym door (see MahoganyTown/scripts.inc).
#define FLAG_TRINITY_J_MAHOGANY_LASS_HIDE 0x28B // Trinity: was FLAG_UNUSED_0x28B -- visibility - the LASS who points at GRANNY's real shop. Visible iff ARC >= 5.
#define FLAG_TRINITY_J_TOWER_ROCKETS_HIDE   0x28C // Trinity: was FLAG_UNUSED_0x28C -- visibility (13 objects, RADIO TOWER 1F-4F + 5F's ARIANA's floor-mates). Visible iff VAR_TRINITY_JOHTO_ARC == 6. THE OCCUPATION IS A WINDOW: at ARC 7 the tower repopulates with S4's staff (that cast rides FLAG_TRINITY_J_RADIO_TOWER_PRE_HIDE, the exact complement).
#define FLAG_TRINITY_J_TOWER_5F_ROCKETS_HIDE 0x28D // Trinity: was FLAG_UNUSED_0x28D -- visibility (2 objects: EXEC ARCHER at 5F (13,5) and EXEC ARIANA at 5F (17,2)). Visible iff ARC == 6. These two have their OWN flag because the liberation scene removeobject's them, and removeobject CO-SIGNS the flag (RemoveObjectEventByLocalIdAndMap -> FlagSet, src/event_object_movement.c:1537-1545) -- on the shared tower flag that one tidy-up would delete all 15 posts. R1's rule: anything that must be removed gets its own flag. The co-sign BETWEEN these two is intended; GSC retires the pair in one breath.
#define FLAG_TRINITY_J_GOLDENROD_ROCKETS_HIDE 0x28E // Trinity: was FLAG_UNUSED_0x28E -- visibility (5 objects) - the ROCKETS holding GOLDENROD's pavement during the takeover. Visible iff ARC == 6. Distinct from S4's FLAG_TRINITY_J_GOLDENROD_SCOUT_HIDE, whose man is retired permanently at the takeover.
#define FLAG_TRINITY_J_UNDERGROUND_ROCKETS_HIDE 0x28F // Trinity: was FLAG_UNUSED_0x28F -- visibility (7 objects, 2 maps: 4 in the SWITCH ROOMS, 3 in the WAREHOUSE). Visible iff ARC == 6. One predicate, authored once per map. No member is ever removeobject'd (S7's rule: a shared cast flag across maps forbids it).
#define FLAG_TRINITY_J_WAREHOUSE_DIRECTOR_HIDE 0x290 // Trinity: was FLAG_UNUSED_0x290 -- visibility - the real DIRECTOR, tied up in the UNDERGROUND WAREHOUSE. Visible iff ARC == 6; at ARC >= 7 he is back at his 5F desk, which is the SAME character on a different object (RadioTower5F's (3,6), flag 0).
#define FLAG_TRINITY_J_UG_SILVER_HIDE       0x291 // Trinity: was FLAG_UNUSED_0x291 -- visibility - SILVER in the SWITCH ROOMS. An addobject-ONLY cutscene actor: the ON_TRANSITION SETS this flag unconditionally, so the template can never spawn, and the scene addobject's him. addobject does NOT clear a visibility flag (there is no FlagClear counterpart to removeobject's FlagSet, src/event_object_movement.c:1803), so the spawn is session-only and cannot outlive the scene.
#define FLAG_TRINITY_J_TOWER_GIOVANNI_HIDE  0x292 // Trinity: was FLAG_UNUSED_0x292 -- visibility - GIOVANNI's cameo on RADIO TOWER 5F. addobject-only, same shape as SILVER above.
#define FLAG_TRINITY_J_TOWER_BOBBY_HIDE     0x293 // Trinity: was FLAG_UNUSED_0x293 -- visibility - BOBBY on RADIO TOWER 5F. addobject-only, same shape.
#define FLAG_TRINITY_J_GOLDENROD_BOBBY_HIDE 0x294 // Trinity: was FLAG_UNUSED_0x294 -- visibility - BOBBY's coda post outside the RADIO TOWER. Visible iff ARC >= 7. Terminal state: he never leaves again this act.
#define FLAG_TRINITY_J_BASEMENT_KEY         0x295 // Trinity: was FLAG_UNUSED_0x295 -- key-as-flag (GSC's BASEMENT_KEY; ITEM_BASEMENT_KEY exists but is Act I's New Mauville key and must not be reused). Handed over by the 5F imposter. An INPUT to the door, never the door's state (D4).
#define FLAG_TRINITY_J_BASEMENT_DOOR        0x296 // Trinity: was FLAG_UNUSED_0x296 -- door state (D4) - the GOLDENROD UNDERGROUND door at (18,6) is unlocked. The single input to that map's setmetatile authoring. Monotonic: once open, always open.
#define FLAG_TRINITY_J_CARD_KEY             0x297 // Trinity: was FLAG_UNUSED_0x297 -- key-as-flag (GSC's CARD_KEY; ITEM_CARD_KEY exists but is KANTO's SILPH CO key, reserved for M5). Handed over by the rescued DIRECTOR. Also the predicate for the DEPT. STORE B1F crate that opens the WAREHOUSE shortcut, exactly as GSC keys it on EVENT_RECEIVED_CARD_KEY.
#define FLAG_TRINITY_J_CARD_KEY_USED        0x298 // Trinity: was FLAG_UNUSED_0x298 -- door state (D4) - the RADIO TOWER 3F shutter is open. The single input to RadioTower3F's setmetatile authoring, and the FIRST test in the slot script (a bg_event on a now-walkable tile is still triggerable).
#define FLAG_TRINITY_J_SILVER4_BEATEN       0x299 // Trinity: was FLAG_UNUSED_0x299 -- story - SILVER 4 beaten in the GOLDENROD UNDERGROUND. [S12 correction] Comment previously claimed this flag is read by S9's DRAGON'S DEN coda; it is not -- that coda (DragonsDenB1F_EventScript_HideSilver) gates on FLAG_TRINITY_BADGE16, not on this flag. This flag has no script reader today; it stands as a pure story marker for Act III.
#define FLAG_TRINITY_J_WING_RAINBOW         0x29A // Trinity: was FLAG_UNUSED_0x29A -- story CLAIM - the RAINBOW WING, from the rescued DIRECTOR. Shipped as a flag, not an item (no ITEM_RAINBOW_WING in this build; S1's ITEM_RED_SCALE and S6's ITEM_SECRET_POTION precedent). S10 consumes it at the TIN TOWER summit.
#define FLAG_TRINITY_J_WING_SILVER          0x29B // Trinity: was FLAG_UNUSED_0x29B -- story CLAIM - the SILVER WING, seized from GIOVANNI's office in the TEAM ROCKET BASE (B3F, ARC >= 7). Flag, not item. S10 consumes it at the WHIRL ISLANDS.
#define FLAG_TRINITY_J_CLEAR_BELL           0x29C // Trinity: was FLAG_UNUSED_0x29C -- story CLAIM - the CLEAR BELL, from the rescued DIRECTOR. Flag, not item. S10 consumes it at the ECRUTEAK TIN TOWER ENTRANCE gate. Its award is what writes VAR_TRINITY_JOHTO_ARC = 8.
#define FLAG_TRINITY_J_BOBBY_REVEALED       0x29D // Trinity: was FLAG_UNUSED_0x29D -- story - BOBBY has shown the INTERNATIONAL POLICE badge. Terminal marker for the act's second reveal; M5 (Act III) consumes it.
#define FLAG_TRINITY_J_RADIO_TM11           0x29E // Trinity: was FLAG_UNUSED_0x29E -- G2 award guard - TM11 SUNNY DAY from the 3F COOLTRAINER F after the tower is freed. Her visibility rides S4's ARC != 6, which is permanently true from ARC 7 on, so she can never vanish owing the TM (S7's C1 rule is satisfied by the predicate, not by an extra clause).
#define FLAG_TRINITY_J_MARY_SCARF           0x29F // Trinity: was FLAG_UNUSED_0x29F -- G2 award guard - the SILK SCARF from DJ MARY on 4F (substitutes GSC's PINK BOW, which does not exist in this build). Same visibility argument as the TM above.
#define FLAG_TRINITY_J_UG_SWITCH_1          0x2A0 // Trinity: was FLAG_UNUSED_0x2A0 -- puzzle input - UNDERGROUND SWITCH 1. Contributes 1 to the switch position.
#define FLAG_TRINITY_J_UG_SWITCH_2          0x2A1 // Trinity: was FLAG_UNUSED_0x2A1 -- puzzle input - UNDERGROUND SWITCH 2. Contributes 2.
#define FLAG_TRINITY_J_UG_SWITCH_3          0x2A2 // Trinity: was FLAG_UNUSED_0x2A2 -- puzzle input - UNDERGROUND SWITCH 3. Contributes 3. position = 1*S1 + 2*S2 + 3*S3, range 0-6, GSC's own arithmetic.
#define FLAG_TRINITY_J_UG_EMERGENCY         0x2A3 // Trinity: was FLAG_UNUSED_0x2A3 -- puzzle input - the EMERGENCY panel's own read-out. Turning it ON forces switches 1-3 on and doors 3/5/6 open + 1/2/4 shut, which is the ONE configuration that reaches the WAREHOUSE; turning it OFF resets everything to position 0. Any individual switch toggle clears it, so the panel never lies about the configuration (a small, deliberate improvement on GSC, which leaves it stale).
#define FLAG_TRINITY_J_UG_DOOR_1            0x2A4 // Trinity: was FLAG_UNUSED_0x2A4 -- door state (D4) - UNDERGROUND door 1, top corridor <-> shaft 3 upper. Doors 1-6 are STICKY: a switch position only opens the one door it names and shuts the one it names (position N shuts door 7-N), so their state is history, not a function of the position. Doors 7-11 ARE a pure function of the position and therefore carry no flag at all.
#define FLAG_TRINITY_J_UG_DOOR_2            0x2A5 // Trinity: was FLAG_UNUSED_0x2A5 -- door state - door 2, top corridor <-> shaft 2 upper.
#define FLAG_TRINITY_J_UG_DOOR_3            0x2A6 // Trinity: was FLAG_UNUSED_0x2A6 -- door state - door 3, top corridor <-> shaft 1 upper.
#define FLAG_TRINITY_J_UG_DOOR_4            0x2A7 // Trinity: was FLAG_UNUSED_0x2A7 -- door state - door 4, shaft 1 upper <-> lower.
#define FLAG_TRINITY_J_UG_DOOR_5            0x2A8 // Trinity: was FLAG_UNUSED_0x2A8 -- door state - door 5, shaft 2 upper <-> lower.
#define FLAG_TRINITY_J_UG_DOOR_6            0x2A9 // Trinity: was FLAG_UNUSED_0x2A9 -- door state - door 6, shaft 3 upper <-> lower.
#define FLAG_TRINITY_J_BGYM_BOULDER_1       0x2AA // Trinity: was FLAG_UNUSED_0x2AA -- visibility - BLACKTHORN GYM 2F Strength boulder 1, GSC (8,2). SET ONLY by removeobject (RemoveObjectEventByLocalIdAndMap -> FlagSet, src/event_object_movement.c:1537-1545) when the boulder drops through a hole -- this is GSC's own EVENT_BOULDER_IN_BLACKTHORN_GYM_1 semantics. ONE writer + correct default (clear = on the floor), so it carries NO ON_TRANSITION authoring clause; giving it one would resurrect a fallen boulder (S7's rule).
#define FLAG_TRINITY_J_BGYM_BOULDER_2       0x2AB // Trinity: was FLAG_UNUSED_0x2AB -- visibility - boulder 2, GSC (2,3). Same shape.
#define FLAG_TRINITY_J_BGYM_BOULDER_3       0x2AC // Trinity: was FLAG_UNUSED_0x2AC -- visibility - boulder 3, GSC (6,16). Same shape.
#define FLAG_TRINITY_J_BGYM_BOULDER_4       0x2AD // Trinity: was FLAG_UNUSED_0x2AD -- visibility - boulder 4, GSC (3,3). Same shape. NOT A DECOY, despite carrying no event in GSC: measured, it is the single obstacle on the approach to hole A's push tile (2,2) -- clearing it takes the fill from 96 to 103 tiles. Push it NORTH x2 before boulder 2 can be moved at all. Trinity's hole hook is generic (any boulder plugs any hole), so if it ends up in a hole itself that hole is plugged, not wasted.
#define FLAG_TRINITY_J_BGYM_BOULDER_5       0x2AE // Trinity: was FLAG_UNUSED_0x2AE -- visibility - boulder 5, GSC (6,1). Same shape, and likewise NOT a decoy: it is the single link along row 1 between the middle of the floor and the north-east pocket, so it alone gates hole C's push tile (8,1) -- clearing it takes the fill from 96 to 105. Push it EAST x3 (twice is not enough: it would come to rest ON (8,1)).
#define FLAG_TRINITY_J_BGYM_BOULDER_6       0x2AF // Trinity: was FLAG_UNUSED_0x2AF -- visibility - boulder 6, GSC (8,14). Same shape, and likewise NOT a decoy: it plugs the (8,15)/(8,16) column that is the only way into the bottom-right pocket, so it alone gates hole B's approach tile (6,17) -- 96 to 103. Push it SOUTH x3.
#define FLAG_TRINITY_J_BGYM_PLATFORM_A      0x2B0 // Trinity: was FLAG_UNUSED_0x2B0 -- door state (D4) - a boulder has plugged BLACKTHORN GYM 2F's hole A (2,5), so 1F (2,5) is a walkable platform. GSC's changeblock 2,4,$3a. THE ONE HOLE THAT BUYS NOTHING: (2,5)'s only walkable neighbour is (2,6) in the entrance region ((2,4), (1,5) and (3,5) all decode collision 1 both before and after), so plugging it opens a one-tile alcove and no route. GSC's own red herring, kept. Sole input to BlackthornGym1F's ON_LOAD setmetatile authoring.
#define FLAG_TRINITY_J_BGYM_PLATFORM_B      0x2B1 // Trinity: was FLAG_UNUSED_0x2B1 -- door state (D4) - hole B (8,7) plugged, so 1F (8,7) is walkable. GSC's changeblock 8,6,$3b. Consumed by BlackthornGym1F's ON_LOAD author. REQUIRED for badge 16: it is the only link from the hole-landing island to the east corridor.
#define FLAG_TRINITY_J_BGYM_PLATFORM_C      0x2B2 // Trinity: was FLAG_UNUSED_0x2B2 -- door state (D4) - hole C (8,3) plugged, so 1F (8,3) is walkable. GSC's changeblock 8,2,$3b. Consumed by BlackthornGym1F's ON_LOAD author. REQUIRED for badge 16: the only link from the east corridor to CLAIR's chamber.
#define FLAG_TRINITY_J_DEN_GRAMPS_BLOCK_HIDE 0x2B3 // Trinity: was FLAG_UNUSED_0x2B3 -- visibility - the GRAMPS standing IN the DRAGON'S DEN doorway at BLACKTHORN (20,2). Visible iff VAR_TRINITY_JOHTO_SCENE_BLACKTHORN == 0. He genuinely seals the den (see the R5 disclosure in BlackthornCity/scripts.inc); that is GSC's own gate and it opens the moment CLAIR is beaten.
#define FLAG_TRINITY_J_DEN_GRAMPS_ASIDE_HIDE 0x2B4 // Trinity: was FLAG_UNUSED_0x2B4 -- visibility - the same character stood aside at (21,2), a dead-end alcove. Exact complement: visible iff SCENE_BLACKTHORN >= 1. Both authored in one ON_TRANSITION.
#define FLAG_TRINITY_J_SHRINE_CLAIR_HIDE    0x2B5 // Trinity: was FLAG_UNUSED_0x2B5 -- visibility - CLAIR at the DRAGON SHRINE. addobject-only during the test scene, and afterwards OWNED BY THE AWARD GUARD (S7's C1 rule): she stays on stage at (4,8) iff the test is passed and FLAG_TRINITY_J_CLAIR_TM02 is still clear, so a full bag can never cost the TM.
#define FLAG_TRINITY_J_CLAIR_TM02           0x2B6 // Trinity: was FLAG_UNUSED_0x2B6 -- G2 award guard - TM02 DRAGON CLAW. Awarded AT THE SHRINE with badge 16 (the brief's pin; GSC hands TM24 DRAGONBREATH back in the gym and has a documented double-give bug doing it). The badge is set BEFORE the TM, so the failable gift can never hold progression.
#define FLAG_TRINITY_J_DEN_SILVER_HIDE      0x2B7 // Trinity: was FLAG_UNUSED_0x2B7 -- visibility - SILVER training in DRAGON'S DEN B1F (20,23). Visible iff FLAG_TRINITY_BADGE16. No battle: this is the arc-turn coda that seeds S11's VICTORY ROAD fight.
#define FLAG_TRINITY_J_DEN_SILVER_MET       0x2B8 // Trinity: was FLAG_UNUSED_0x2B8 -- story - SILVER's Den coda has been heard once (his second line differs, as in GSC).
#define FLAG_TRINITY_J_TIN_TOWER_OPEN              0x2B9 // Trinity M4b S10: was FLAG_UNUSED_0x2B9 -- story - the ECRUTEAK gatehouse sage has heard the CLEAR BELL and stood aside. Written ONCE, by the sage; read by his own ON_TRANSITION (the LEFT sage is visible iff this is CLEAR) and by both sages' talk script.
#define FLAG_TRINITY_J_TIN_GATE_SAGE_HIDE          0x2BA // Trinity M4b S10: was FLAG_UNUSED_0x2BA -- visibility - the LEFT gatehouse sage at (4,6). The gate is TWO objects on the building's 2-wide waist; retiring this one reopens it. removeobject co-signs this flag (R1).
#define FLAG_TRINITY_J_TT1_BEASTS_HIDE             0x2BB // Trinity M4b S10: was FLAG_UNUSED_0x2BB -- visibility - the three-beast tableau in TIN TOWER 1F's sealed sanctum (SUICUNE 9,9 / RAIKOU 7,9 / ENTEI 12,9). Authored by ON_TRANSITION on SCENE_TINTOWER == 0, exact equality; all three retire together, which is what makes ONE shared flag correct (S4 C1).

// Event Flags
#define FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG                      0x2BC
#define FLAG_HIDE_APPRENTICE                                        0x2BD
#define FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN                0x2BE
#define FLAG_HIDE_UNION_ROOM_PLAYER_1                               0x2BF
#define FLAG_HIDE_UNION_ROOM_PLAYER_2                               0x2C0
#define FLAG_HIDE_UNION_ROOM_PLAYER_3                               0x2C1
#define FLAG_HIDE_UNION_ROOM_PLAYER_4                               0x2C2
#define FLAG_HIDE_UNION_ROOM_PLAYER_5                               0x2C3
#define FLAG_HIDE_UNION_ROOM_PLAYER_6                               0x2C4
#define FLAG_HIDE_UNION_ROOM_PLAYER_7                               0x2C5
#define FLAG_HIDE_UNION_ROOM_PLAYER_8                               0x2C6
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1               0x2C7
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2               0x2C8
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3               0x2C9
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4               0x2CA
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5               0x2CB
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6               0x2CC
#define FLAG_HIDE_SAFARI_ZONE_SOUTH_CONSTRUCTION_WORKERS            0x2CD
#define FLAG_HIDE_MEW                                               0x2CE
#define FLAG_HIDE_ROUTE_104_RIVAL                                   0x2CF
#define FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE                  0x2D0
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH                  0x2D1
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM          0x2D2
#define FLAG_HIDE_ROUTE_103_RIVAL                                   0x2D3
#define FLAG_HIDE_PETALBURG_WOODS_DEVON_EMPLOYEE                    0x2D4
#define FLAG_HIDE_PETALBURG_WOODS_AQUA_GRUNT                        0x2D5
#define FLAG_HIDE_PETALBURG_CITY_WALLY                              0x2D6
#define FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_INVISIBLE_NINJA_BOY   0x2D7
#define FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM                         0x2D8

#define FLAG_TRINITY_J_SUICUNE_HALL_HIDE           0x2D9 // Trinity M4b S10: was FLAG_UNUSED_0x2D9 -- visibility - SUICUNE on the 1F hall floor at (9,11), after the showdown cutscene. Authored on SCENE_TINTOWER == 1, exact equality: a SUICUNE that FLED leaves the scene at 1 and is therefore standing there again on the next map load; a beaten or caught one moves the scene to 2 and is gone for good.

#define FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER                     0x2DA
#define FLAG_HIDE_RUSTBORO_CITY_AQUA_GRUNT                          0x2DB
#define FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1                    0x2DC
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE_ASLEEP              0x2DD
#define FLAG_HIDE_PLAYERS_HOUSE_DAD                                 0x2DE
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING      0x2DF
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING          0x2E0
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_MAGMA_NOTE             0x2E1
#define FLAG_HIDE_ROUTE_104_MR_BRINEY                               0x2E2
#define FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY                           0x2E3
#define FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN                            0x2E4
#define FLAG_HIDE_ROUTE_109_MR_BRINEY                               0x2E5
#define FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT                          0x2E6
#define FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN                       0x2E7
#define FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT                          0x2E8
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN            0x2E9
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY                    0x2EA
#define FLAG_HIDE_SAFARI_ZONE_SOUTH_EAST_EXPANSION                  0x2EB
#define FLAG_HIDE_LILYCOVE_HARBOR_EVENT_TICKET_TAKER                0x2EC
#define FLAG_HIDE_SLATEPORT_CITY_SCOTT                              0x2ED
#define FLAG_HIDE_ROUTE_101_ZIGZAGOON                               0x2EE
#define FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY                           0x2EF
#define FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE                       0x2F0
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN              0x2F1
#define FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1          0x2F2
#define FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2          0x2F3
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA          0x2F4
#define FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_BEDROOM_MOM               0x2F5
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM                0x2F6
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM                    0x2F7
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM      0x2F8
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK              0x2F9
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK                  0x2FA
#define FLAG_HIDE_DEOXYS                                            0x2FB
#define FLAG_HIDE_BIRTH_ISLAND_DEOXYS_TRIANGLE                      0x2FC
#define FLAG_HIDE_MAUVILLE_CITY_SCOTT                               0x2FD
#define FLAG_HIDE_VERDANTURF_TOWN_SCOTT                             0x2FE
#define FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT                  0x2FF
#define FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE                        0x300
#define FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE                      0x301
#define FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE                          0x302
#define FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE                         0x303
#define FLAG_HIDE_PETALBURG_GYM_NORMAN                              0x304
#define FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA                           0x305
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_CONTEST_ATTENDANT_1         0x306
#define FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR                           0x307
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_1                          0x308
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_2                          0x309
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_3                          0x30A
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_4                          0x30B
#define FLAG_HIDE_LILYCOVE_MUSEUM_TOURISTS                          0x30C
#define FLAG_HIDE_PETALBURG_GYM_GREETER                             0x30D
#define FLAG_HIDE_MARINE_CAVE_KYOGRE                                0x30E
#define FLAG_HIDE_TERRA_CAVE_GROUDON                                0x30F
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM          0x310
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM              0x311
#define FLAG_HIDE_ROUTE_119_SCOTT                                   0x312
#define FLAG_HIDE_LILYCOVE_MOTEL_SCOTT                              0x313
#define FLAG_HIDE_MOSSDEEP_CITY_SCOTT                               0x314
#define FLAG_HIDE_FANCLUB_OLD_LADY                                  0x315
#define FLAG_HIDE_FANCLUB_BOY                                       0x316
#define FLAG_HIDE_FANCLUB_LITTLE_BOY                                0x317
#define FLAG_HIDE_FANCLUB_LADY                                      0x318
#define FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT               0x319
#define FLAG_HIDE_LITTLEROOT_TOWN_RIVAL                             0x31A
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCH                             0x31B
#define FLAG_HIDE_ROUTE_111_GABBY_AND_TY_1                          0x31C
#define FLAG_HIDE_ROUTE_118_GABBY_AND_TY_1                          0x31D
#define FLAG_HIDE_ROUTE_120_GABBY_AND_TY_1                          0x31E
#define FLAG_HIDE_ROUTE_111_GABBY_AND_TY_2                          0x31F
#define FLAG_HIDE_LUGIA                                             0x320
#define FLAG_HIDE_HO_OH                                             0x321
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER                    0x322
#define FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER                   0x323
#define FLAG_HIDE_MAUVILLE_CITY_WALLY                               0x324
#define FLAG_HIDE_MAUVILLE_CITY_WALLYS_UNCLE                        0x325
#define FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY                0x326
#define FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND                   0x327
#define FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDAS_BOYFRIEND     0x328
#define FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE         0x329
#define FLAG_HIDE_SS_TIDAL_CORRIDOR_SCOTT                           0x32A
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CYNDAQUIL     0x32B
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_TOTODILE      0x32C
#define FLAG_HIDE_ROUTE_116_DROPPED_GLASSES_MAN                     0x32D
#define FLAG_HIDE_RUSTBORO_CITY_RIVAL                               0x32E
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL     0x32F
#define FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE                           0x330
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL       0x331
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL           0x332
#define FLAG_HIDE_ROUTE_112_TEAM_MAGMA                              0x333
#define FLAG_HIDE_CAVE_OF_ORIGIN_B1F_WALLACE                        0x334
#define FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE         0x335
#define FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE         0x336
#define FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA                          0x337
#define FLAG_HIDE_PETALBURG_GYM_WALLYS_DAD                          0x338
#define FLAG_HIDE_LEGEND_MON_CAVE_OF_ORIGIN                         0x339 // Unused, leftover from R/S
#define FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE                            0x33A
#define FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE                             0x33B
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE                     0x33C
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE                      0x33D
#define FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD                         0x33E
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS               0x33F
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER                0x340
#define FLAG_HIDE_GRANITE_CAVE_STEVEN                               0x341
#define FLAG_HIDE_ROUTE_128_STEVEN                                  0x342
#define FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY                       0x343
#define FLAG_HIDE_BATTLE_FRONTIER_RECEPTION_GATE_SCOTT              0x344
#define FLAG_HIDE_ROUTE_110_BIRCH                                   0x345
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CHIKORITA     0x346
#define FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1                             0x347
#define FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN                      0x348
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN               0x349
#define FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO                         0x34A
#define FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY                      0x34B
#define FLAG_HIDE_RUSTBORO_CITY_SCIENTIST                           0x34C
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT                  0x34D
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE                      0x34E
#define FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD                           0x34F
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW            0x350
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL          0x351
#define FLAG_HIDE_MAGMA_HIDEOUT_4F_GROUDON_ASLEEP                   0x352
#define FLAG_HIDE_ROUTE_119_RIVAL                                   0x353
#define FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS                         0x354
#define FLAG_HIDE_MAGMA_HIDEOUT_4F_GROUDON                          0x355
#define FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS                         0x356
#define FLAG_HIDE_SKY_PILLAR_WALLACE                                0x357
#define FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE                              0x358
#define FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS                              0x359
#define FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY                       0x35A
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE                     0x35B
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL                    0x35C
#define FLAG_HIDE_LILYCOVE_HARBOR_SSTIDAL                           0x35D
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA          0x35E
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN              0x35F
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1           0x360
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2           0x361
#define FLAG_HIDE_PETALBURG_GYM_WALLY                               0x362
#define FLAG_UNKNOWN_0x363                                          0x363 // Set, however has no purpose.
#define FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN                           0x364
#define FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY          0x365
#define FLAG_HIDE_LANETTES_HOUSE_LANETTE                            0x366
#define FLAG_HIDE_FALLARBOR_POKEMON_CENTER_LANETTE                  0x367
#define FLAG_HIDE_TRICK_HOUSE_ENTRANCE_MAN                          0x368
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER_REPLACEMENT    0x369
#define FLAG_HIDE_DESERT_UNDERPASS_FOSSIL                           0x36A
#define FLAG_HIDE_ROUTE_111_PLAYER_DESCENT                          0x36B
#define FLAG_HIDE_ROUTE_111_DESERT_FOSSIL                           0x36C
#define FLAG_HIDE_MT_CHIMNEY_TRAINERS                               0x36D
#define FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT                         0x36E
#define FLAG_HIDE_RUSTURF_TUNNEL_BRINEY                             0x36F
#define FLAG_HIDE_RUSTURF_TUNNEL_PEEKO                              0x370
#define FLAG_HIDE_BRINEYS_HOUSE_PEEKO                               0x371
#define FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA                          0x372
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS         0x373
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_1     0x374
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_2     0x375
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_ARCHIE           0x376
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_CAPTAIN_STERN    0x377
#define FLAG_HIDE_BATTLE_TOWER_OPPONENT                             0x378
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL                  0x379
#define FLAG_HIDE_ROUTE_119_TEAM_AQUA                               0x37A
#define FLAG_HIDE_ROUTE_116_MR_BRINEY                               0x37B
#define FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS                      0x37C
#define FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS                      0x37D
#define FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND                        0x37E
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_CONTEST_ATTENDANT_2         0x37F
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380          0x380
#define FLAG_HIDE_ROUTE_101_BIRCH                                   0x381
#define FLAG_HIDE_ROUTE_103_BIRCH                                   0x382
#define FLAG_HIDE_TRICK_HOUSE_END_MAN                               0x383
#define FLAG_HIDE_ROUTE_110_TEAM_AQUA                               0x384
#define FLAG_HIDE_ROUTE_118_GABBY_AND_TY_2                          0x385
#define FLAG_HIDE_ROUTE_120_GABBY_AND_TY_2                          0x386
#define FLAG_HIDE_ROUTE_111_GABBY_AND_TY_3                          0x387
#define FLAG_HIDE_ROUTE_118_GABBY_AND_TY_3                          0x388
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS                     0x389
#define FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST                      0x38A
#define FLAG_HIDE_FALLARBOR_AZURILL                                 0x38B
#define FLAG_HIDE_LILYCOVE_HARBOR_FERRY_ATTENDANT                   0x38C
#define FLAG_HIDE_LILYCOVE_HARBOR_FERRY_SAILOR                      0x38D
#define FLAG_HIDE_SOUTHERN_ISLAND_EON_STONE                         0x38E
#define FLAG_HIDE_SOUTHERN_ISLAND_UNCHOSEN_EON_DUO_MON              0x38F
#define FLAG_HIDE_MAUVILLE_CITY_WATTSON                             0x390
#define FLAG_HIDE_MAUVILLE_GYM_WATTSON                              0x391
#define FLAG_HIDE_ROUTE_121_TEAM_AQUA_GRUNTS                        0x392
#define FLAG_UNKNOWN_0x393                                          0x393 // Set, however has no purpose.
#define FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE                             0x394
#define FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA                          0x395
#define FLAG_HIDE_BATTLE_TOWER_REPORTER                             0x396
#define FLAG_HIDE_ROUTE_110_RIVAL                                   0x397
#define FLAG_HIDE_CHAMPIONS_ROOM_RIVAL                              0x398
#define FLAG_HIDE_CHAMPIONS_ROOM_BIRCH                              0x399
#define FLAG_HIDE_ROUTE_110_RIVAL_ON_BIKE                           0x39A
#define FLAG_HIDE_ROUTE_119_RIVAL_ON_BIKE                           0x39B
#define FLAG_HIDE_AQUA_HIDEOUT_GRUNTS                               0x39C
#define FLAG_HIDE_LILYCOVE_MOTEL_GAME_DESIGNERS                     0x39D
#define FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA                              0x39E
#define FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA                             0x39F
#define FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO                        0x3A0
#define FLAG_HIDE_LAVARIDGE_TOWN_RIVAL                              0x3A1
#define FLAG_HIDE_LAVARIDGE_TOWN_RIVAL_ON_BIKE                      0x3A2
#define FLAG_HIDE_RUSTURF_TUNNEL_ROCK_1                             0x3A3
#define FLAG_HIDE_RUSTURF_TUNNEL_ROCK_2                             0x3A4
#define FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL                      0x3A5
#define FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL                     0x3A6
#define FLAG_HIDE_REGIROCK                                          0x3A7
#define FLAG_HIDE_REGICE                                            0x3A8
#define FLAG_HIDE_REGISTEEL                                         0x3A9
#define FLAG_HIDE_METEOR_FALLS_TEAM_AQUA                            0x3AA
#define FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA                           0x3AB
#define FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN                      0x3AC
#define FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT               0x3AD
#define FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO                          0x3AE
#define FLAG_HIDE_AQUA_HIDEOUT_B2F_SUBMARINE_SHADOW                 0x3AF
#define FLAG_HIDE_ROUTE_128_ARCHIE                                  0x3B0
#define FLAG_HIDE_ROUTE_128_MAXIE                                   0x3B1
#define FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS                       0x3B2
#define FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE                          0x3B3
#define FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN                        0x3B4
#define FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE              0x3B5
#define FLAG_HIDE_SS_TIDAL_CORRIDOR_MR_BRINEY                       0x3B6
#define FLAG_HIDE_SS_TIDAL_ROOMS_SNATCH_GIVER                       0x3B7
#define FLAG_RECEIVED_SHOAL_SALT_1                                  0x3B8
#define FLAG_RECEIVED_SHOAL_SALT_2                                  0x3B9
#define FLAG_RECEIVED_SHOAL_SALT_3                                  0x3BA
#define FLAG_RECEIVED_SHOAL_SALT_4                                  0x3BB
#define FLAG_RECEIVED_SHOAL_SHELL_1                                 0x3BC
#define FLAG_RECEIVED_SHOAL_SHELL_2                                 0x3BD
#define FLAG_RECEIVED_SHOAL_SHELL_3                                 0x3BE
#define FLAG_RECEIVED_SHOAL_SHELL_4                                 0x3BF
#define FLAG_HIDE_ROUTE_111_SECRET_POWER_MAN                        0x3C0
#define FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION                       0x3C1
#define FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN      0x3C2
#define FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL                          0x3C3
#define FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL                          0x3C4
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT 0x3C5
#define FLAG_HIDE_ROUTE_118_STEVEN                                  0x3C6
#define FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN                0x3C7
#define FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL       0x3C8
#define FLAG_HIDE_FORTREE_CITY_KECLEON                              0x3C9
#define FLAG_HIDE_ROUTE_120_KECLEON_BRIDGE                          0x3CA
#define FLAG_HIDE_LILYCOVE_CITY_RIVAL                               0x3CB
#define FLAG_HIDE_ROUTE_120_STEVEN                                  0x3CC
#define FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN                            0x3CD
#define FLAG_HIDE_NEW_MAUVILLE_VOLTORB_1                            0x3CE
#define FLAG_HIDE_NEW_MAUVILLE_VOLTORB_2                            0x3CF
#define FLAG_HIDE_NEW_MAUVILLE_VOLTORB_3                            0x3D0
#define FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_1                      0x3D1
#define FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_2                      0x3D2
#define FLAG_HIDE_OLDALE_TOWN_RIVAL                                 0x3D3
#define FLAG_HIDE_UNDERWATER_SEA_FLOOR_CAVERN_STOLEN_SUBMARINE      0x3D4
#define FLAG_HIDE_ROUTE_120_KECLEON_BRIDGE_SHADOW                   0x3D5
#define FLAG_HIDE_ROUTE_120_KECLEON_1                               0x3D6
#define FLAG_HIDE_RUSTURF_TUNNEL_WANDA                              0x3D7
#define FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDA                0x3D8
#define FLAG_HIDE_ROUTE_120_KECLEON_2                               0x3D9
#define FLAG_HIDE_ROUTE_120_KECLEON_3                               0x3DA
#define FLAG_HIDE_ROUTE_120_KECLEON_4                               0x3DB
#define FLAG_HIDE_ROUTE_120_KECLEON_5                               0x3DC
#define FLAG_HIDE_ROUTE_119_KECLEON_1                               0x3DD
#define FLAG_HIDE_ROUTE_119_KECLEON_2                               0x3DE
#define FLAG_HIDE_ROUTE_101_BOY                                     0x3DF
#define FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M                 0x3E0
#define FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON          0x3E1
#define FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY                       0x3E2
#define FLAG_HIDE_PETALBURG_CITY_SCOTT                              0x3E3
#define FLAG_HIDE_SOOTOPOLIS_CITY_RAYQUAZA                          0x3E4
#define FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE                            0x3E5
#define FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON                           0x3E6
#define FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT                0x3E7

// Item Ball Flags
#define FLAG_ITEM_ROUTE_102_POTION                                  0x3E8
#define FLAG_ITEM_ROUTE_116_X_SPECIAL                               0x3E9
#define FLAG_ITEM_ROUTE_104_PP_UP                                   0x3EA
#define FLAG_ITEM_ROUTE_105_IRON                                    0x3EB
#define FLAG_ITEM_ROUTE_106_PROTEIN                                 0x3EC
#define FLAG_ITEM_ROUTE_109_PP_UP                                   0x3ED
#define FLAG_ITEM_ROUTE_110_RARE_CANDY                              0x3EE
#define FLAG_ITEM_ROUTE_110_DIRE_HIT                                0x3EF
#define FLAG_ITEM_ROUTE_111_TM_SANDSTORM                            0x3F0
#define FLAG_ITEM_ROUTE_111_STARDUST                                0x3F1
#define FLAG_ITEM_ROUTE_111_HP_UP                                   0x3F2
#define FLAG_ITEM_ROUTE_112_NUGGET                                  0x3F3
#define FLAG_ITEM_ROUTE_113_MAX_ETHER                               0x3F4
#define FLAG_ITEM_ROUTE_113_SUPER_REPEL                             0x3F5
#define FLAG_ITEM_ROUTE_114_RARE_CANDY                              0x3F6
#define FLAG_ITEM_ROUTE_114_PROTEIN                                 0x3F7
#define FLAG_ITEM_ROUTE_115_SUPER_POTION                            0x3F8
#define FLAG_ITEM_ROUTE_115_TM_FOCUS_PUNCH                          0x3F9
#define FLAG_ITEM_ROUTE_115_IRON                                    0x3FA
#define FLAG_ITEM_ROUTE_116_ETHER                                   0x3FB
#define FLAG_ITEM_ROUTE_116_REPEL                                   0x3FC
#define FLAG_ITEM_ROUTE_116_HP_UP                                   0x3FD
#define FLAG_ITEM_ROUTE_117_GREAT_BALL                              0x3FE
#define FLAG_ITEM_ROUTE_117_REVIVE                                  0x3FF
#define FLAG_ITEM_ROUTE_119_SUPER_REPEL                             0x400
#define FLAG_ITEM_ROUTE_119_ZINC                                    0x401
#define FLAG_ITEM_ROUTE_119_ELIXIR_1                                0x402
#define FLAG_ITEM_ROUTE_119_LEAF_STONE                              0x403
#define FLAG_ITEM_ROUTE_119_RARE_CANDY                              0x404
#define FLAG_ITEM_ROUTE_119_HYPER_POTION_1                          0x405
#define FLAG_ITEM_ROUTE_120_NUGGET                                  0x406
#define FLAG_ITEM_ROUTE_120_FULL_HEAL                               0x407
#define FLAG_ITEM_ROUTE_123_CALCIUM                                 0x408
#define FLAG_ITEM_ROUTE_123_RARE_CANDY                              0x409 // Unused Flag, leftover from R/S. In Emerald this is a hidden item and uses a different flag
#define FLAG_ITEM_ROUTE_127_ZINC                                    0x40A
#define FLAG_ITEM_ROUTE_127_CARBOS                                  0x40B
#define FLAG_ITEM_ROUTE_132_RARE_CANDY                              0x40C
#define FLAG_ITEM_ROUTE_133_BIG_PEARL                               0x40D
#define FLAG_ITEM_ROUTE_133_STAR_PIECE                              0x40E
#define FLAG_ITEM_PETALBURG_CITY_MAX_REVIVE                         0x40F
#define FLAG_ITEM_PETALBURG_CITY_ETHER                              0x410
#define FLAG_ITEM_RUSTBORO_CITY_X_DEFEND                            0x411
#define FLAG_ITEM_LILYCOVE_CITY_MAX_REPEL                           0x412
#define FLAG_ITEM_MOSSDEEP_CITY_NET_BALL                            0x413
#define FLAG_ITEM_METEOR_FALLS_1F_1R_TM_IRON_TAIL                   0x414
#define FLAG_ITEM_METEOR_FALLS_1F_1R_FULL_HEAL                      0x415
#define FLAG_ITEM_METEOR_FALLS_1F_1R_MOON_STONE                     0x416
#define FLAG_ITEM_METEOR_FALLS_1F_1R_PP_UP                          0x417
#define FLAG_ITEM_RUSTURF_TUNNEL_POKE_BALL                          0x418
#define FLAG_ITEM_RUSTURF_TUNNEL_MAX_ETHER                          0x419
#define FLAG_ITEM_GRANITE_CAVE_1F_ESCAPE_ROPE                       0x41A
#define FLAG_ITEM_GRANITE_CAVE_B1F_POKE_BALL                        0x41B
#define FLAG_ITEM_MT_PYRE_5F_LAX_INCENSE                            0x41C
#define FLAG_ITEM_GRANITE_CAVE_B2F_REPEL                            0x41D
#define FLAG_ITEM_GRANITE_CAVE_B2F_RARE_CANDY                       0x41E
#define FLAG_ITEM_PETALBURG_WOODS_X_ATTACK                          0x41F
#define FLAG_ITEM_PETALBURG_WOODS_GREAT_BALL                        0x420
#define FLAG_ITEM_ROUTE_104_POKE_BALL                               0x421
#define FLAG_ITEM_PETALBURG_WOODS_ETHER                             0x422
#define FLAG_ITEM_MAGMA_HIDEOUT_3F_3R_ECAPE_ROPE                    0x423
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_1_ORANGE_MAIL                  0x424
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_2_HARBOR_MAIL                  0x425
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_2_WAVE_MAIL                    0x426
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_3_SHADOW_MAIL                  0x427
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_3_WOOD_MAIL                    0x428
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_4_MECH_MAIL                    0x429
#define FLAG_ITEM_ROUTE_124_YELLOW_SHARD                            0x42A
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_6_GLITTER_MAIL                 0x42B
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_7_TROPIC_MAIL                  0x42C
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_8_BEAD_MAIL                    0x42D
#define FLAG_ITEM_JAGGED_PASS_BURN_HEAL                             0x42E
#define FLAG_ITEM_AQUA_HIDEOUT_B1F_MAX_ELIXIR                       0x42F
#define FLAG_ITEM_AQUA_HIDEOUT_B2F_NEST_BALL                        0x430
#define FLAG_ITEM_MT_PYRE_EXTERIOR_MAX_POTION                       0x431
#define FLAG_ITEM_MT_PYRE_EXTERIOR_TM_SKILL_SWAP                    0x432
#define FLAG_ITEM_NEW_MAUVILLE_ULTRA_BALL                           0x433
#define FLAG_ITEM_NEW_MAUVILLE_ESCAPE_ROPE                          0x434
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_6_LUXURY_BALL    0x435
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER        0x436
#define FLAG_ITEM_SCORCHED_SLAB_TM_SUNNY_DAY                        0x437
#define FLAG_ITEM_METEOR_FALLS_B1F_2R_TM_DRAGON_CLAW                0x438
#define FLAG_ITEM_SHOAL_CAVE_ENTRANCE_BIG_PEARL                     0x439
#define FLAG_ITEM_SHOAL_CAVE_INNER_ROOM_RARE_CANDY                  0x43A
#define FLAG_ITEM_SHOAL_CAVE_STAIRS_ROOM_ICE_HEAL                   0x43B
#define FLAG_ITEM_VICTORY_ROAD_1F_MAX_ELIXIR                        0x43C
#define FLAG_ITEM_VICTORY_ROAD_1F_PP_UP                             0x43D
#define FLAG_ITEM_VICTORY_ROAD_B1F_TM_PSYCHIC                       0x43E
#define FLAG_ITEM_VICTORY_ROAD_B1F_FULL_RESTORE                     0x43F
#define FLAG_ITEM_VICTORY_ROAD_B2F_FULL_HEAL                        0x440
#define FLAG_ITEM_MT_PYRE_6F_TM_SHADOW_BALL                         0x441
#define FLAG_ITEM_SEAFLOOR_CAVERN_ROOM_9_TM_EARTHQUAKE              0x442
#define FLAG_ITEM_FIERY_PATH_TM_TOXIC                               0x443
#define FLAG_ITEM_ROUTE_124_RED_SHARD                               0x444
#define FLAG_ITEM_ROUTE_124_BLUE_SHARD                              0x445
#define FLAG_ITEM_SAFARI_ZONE_NORTH_WEST_TM_SOLAR_BEAM              0x446
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_1F_HARBOR_MAIL               0x447
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_B1F_ESCAPE_ROPE              0x448
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_B1F_DIVE_BALL              0x449
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_B1F_TM_ICE_BEAM              0x44A
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_1F_REVIVE                  0x44B
#define FLAG_ITEM_ABANDONED_SHIP_CAPTAINS_OFFICE_STORAGE_KEY        0x44C
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_3_WATER_STONE    0x44D
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_1_TM_RAIN_DANCE  0x44E
#define FLAG_ITEM_ROUTE_121_CARBOS                                  0x44F
#define FLAG_ITEM_ROUTE_123_ULTRA_BALL                              0x450
#define FLAG_ITEM_ROUTE_126_GREEN_SHARD                             0x451
#define FLAG_ITEM_ROUTE_119_HYPER_POTION_2                          0x452
#define FLAG_ITEM_ROUTE_120_HYPER_POTION                            0x453
#define FLAG_ITEM_ROUTE_120_NEST_BALL                               0x454
#define FLAG_ITEM_ROUTE_123_ELIXIR                                  0x455
#define FLAG_ITEM_NEW_MAUVILLE_THUNDER_STONE                        0x456
#define FLAG_ITEM_FIERY_PATH_FIRE_STONE                             0x457
#define FLAG_ITEM_SHOAL_CAVE_ICE_ROOM_TM_HAIL                       0x458
#define FLAG_ITEM_SHOAL_CAVE_ICE_ROOM_NEVER_MELT_ICE                0x459
#define FLAG_ITEM_ROUTE_103_GUARD_SPEC                              0x45A
#define FLAG_ITEM_ROUTE_104_X_ACCURACY                              0x45B
#define FLAG_ITEM_MAUVILLE_CITY_X_SPEED                             0x45C
#define FLAG_ITEM_PETALBURG_WOODS_PARALYZE_HEAL                     0x45D
#define FLAG_ITEM_ROUTE_115_GREAT_BALL                              0x45E
#define FLAG_ITEM_SAFARI_ZONE_NORTH_CALCIUM                         0x45F
#define FLAG_ITEM_MT_PYRE_3F_SUPER_REPEL                            0x460
#define FLAG_ITEM_ROUTE_118_HYPER_POTION                            0x461
#define FLAG_ITEM_NEW_MAUVILLE_FULL_HEAL                            0x462
#define FLAG_ITEM_NEW_MAUVILLE_PARALYZE_HEAL                        0x463
#define FLAG_ITEM_AQUA_HIDEOUT_B1F_MASTER_BALL                      0x464
#define FLAG_ITEM_OLD_MAGMA_HIDEOUT_B1F_MASTER_BALL                 0x465 // Unused Flag, leftover from the Ruby Magma hideout
#define FLAG_ITEM_OLD_MAGMA_HIDEOUT_B1F_MAX_ELIXIR                  0x466 // Unused Flag, leftover from the Ruby Magma hideout
#define FLAG_ITEM_OLD_MAGMA_HIDEOUT_B2F_NEST_BALL                   0x467 // Unused Flag, leftover from the Ruby Magma hideout
#define FLAG_UNUSED_0x468                                           0x468 // Unused Flag
#define FLAG_ITEM_MT_PYRE_2F_ULTRA_BALL                             0x469
#define FLAG_ITEM_MT_PYRE_4F_SEA_INCENSE                            0x46A
#define FLAG_ITEM_SAFARI_ZONE_SOUTH_WEST_MAX_REVIVE                 0x46B
#define FLAG_ITEM_AQUA_HIDEOUT_B1F_NUGGET                           0x46C
#define FLAG_ITEM_MOSSDEEP_STEVENS_HOUSE_HM08                       0x46D // Unused Flag, leftover from R/S. HM08 is given to the player directly in Emerald
#define FLAG_ITEM_ROUTE_119_NUGGET                                  0x46E
#define FLAG_ITEM_ROUTE_104_POTION                                  0x46F
#define FLAG_UNUSED_0x470                                           0x470 // Unused Flag
#define FLAG_ITEM_ROUTE_103_PP_UP                                   0x471
#define FLAG_UNUSED_0x472                                           0x472 // Unused Flag
#define FLAG_ITEM_ROUTE_108_STAR_PIECE                              0x473
#define FLAG_ITEM_ROUTE_109_POTION                                  0x474
#define FLAG_ITEM_ROUTE_110_ELIXIR                                  0x475
#define FLAG_ITEM_ROUTE_111_ELIXIR                                  0x476
#define FLAG_ITEM_ROUTE_113_HYPER_POTION                            0x477
#define FLAG_ITEM_ROUTE_115_HEAL_POWDER                             0x478
#define FLAG_UNUSED_0x479                                           0x479 // Unused Flag
#define FLAG_ITEM_ROUTE_116_POTION                                  0x47A
#define FLAG_ITEM_ROUTE_119_ELIXIR_2                                0x47B
#define FLAG_ITEM_ROUTE_120_REVIVE                                  0x47C
#define FLAG_ITEM_ROUTE_121_REVIVE                                  0x47D
#define FLAG_ITEM_ROUTE_121_ZINC                                    0x47E
#define FLAG_ITEM_MAGMA_HIDEOUT_1F_RARE_CANDY                       0x47F
#define FLAG_ITEM_ROUTE_123_PP_UP                                   0x480
#define FLAG_ITEM_ROUTE_123_REVIVAL_HERB                            0x481
#define FLAG_ITEM_ROUTE_125_BIG_PEARL                               0x482
#define FLAG_ITEM_ROUTE_127_RARE_CANDY                              0x483
#define FLAG_ITEM_ROUTE_132_PROTEIN                                 0x484
#define FLAG_ITEM_ROUTE_133_MAX_REVIVE                              0x485
#define FLAG_ITEM_ROUTE_134_CARBOS                                  0x486
#define FLAG_ITEM_ROUTE_134_STAR_PIECE                              0x487
#define FLAG_ITEM_ROUTE_114_ENERGY_POWDER                           0x488
#define FLAG_ITEM_ROUTE_115_PP_UP                                   0x489
#define FLAG_ITEM_ARTISAN_CAVE_B1F_HP_UP                            0x48A
#define FLAG_ITEM_ARTISAN_CAVE_1F_CARBOS                            0x48B
#define FLAG_ITEM_MAGMA_HIDEOUT_2F_2R_MAX_ELIXIR                    0x48C
#define FLAG_ITEM_MAGMA_HIDEOUT_2F_2R_FULL_RESTORE                  0x48D
#define FLAG_ITEM_MAGMA_HIDEOUT_3F_1R_NUGGET                        0x48E
#define FLAG_ITEM_MAGMA_HIDEOUT_3F_2R_PP_MAX                        0x48F
#define FLAG_ITEM_MAGMA_HIDEOUT_4F_MAX_REVIVE                       0x490
#define FLAG_ITEM_SAFARI_ZONE_NORTH_EAST_NUGGET                     0x491
#define FLAG_ITEM_SAFARI_ZONE_SOUTH_EAST_BIG_PEARL                  0x492

#define FLAG_TRINITY_J_HOOH_HIDE                   0x493 // Trinity M4b S10: was FLAG_UNUSED_0x493 -- visibility - HO-OH on TIN TOWER ROOF (9,5). visible iff RAINBOW WING and SCENE_TINTOWER >= 2 and not _HOOH_RESOLVED.
#define FLAG_TRINITY_J_HOOH_RESOLVED               0x494 // Trinity M4b S10: was FLAG_UNUSED_0x494 -- story - HO-OH beaten or caught. Terminal; the ONLY thing that stops ON_TRANSITION putting it back.
#define FLAG_TRINITY_J_LUGIA_HIDE                  0x495 // Trinity M4b S10: was FLAG_UNUSED_0x495 -- visibility - LUGIA in the WHIRL ISLAND chamber (9,5), on the water. visible iff SILVER WING and not _LUGIA_RESOLVED.
#define FLAG_TRINITY_J_LUGIA_RESOLVED              0x496 // Trinity M4b S10: was FLAG_UNUSED_0x496 -- story - LUGIA beaten or caught. Terminal.
#define FLAG_TRINITY_J_RAIKOU_HIDE                 0x497 // Trinity M4b S10: was FLAG_UNUSED_0x497 -- visibility - RAIKOU in MT MORTAR B1F (3,18). visible iff _BEASTS_AWAKENED and not _RAIKOU_RESOLVED.
#define FLAG_TRINITY_J_RAIKOU_RESOLVED             0x498 // Trinity M4b S10: was FLAG_UNUSED_0x498 -- story - RAIKOU beaten or caught. Terminal.
#define FLAG_TRINITY_J_ENTEI_HIDE                  0x499 // Trinity M4b S10: was FLAG_UNUSED_0x499 -- visibility - ENTEI in DARK CAVE, BLACKTHORN side (21,27). visible iff _BEASTS_AWAKENED and not _ENTEI_RESOLVED.
#define FLAG_TRINITY_J_ENTEI_RESOLVED              0x49A // Trinity M4b S10: was FLAG_UNUSED_0x49A -- story - ENTEI beaten or caught. Terminal.
#define FLAG_RECEIVED_REWARD_IVRAJ                 0x49B // Trinity M4b S10: was FLAG_UNUSED_0x49B -- award guard - IVRAJ at the RUINS OF ALPH, the fourth M1 friend-reward post (HARJOT 0x23, PRABHJIT 0x24, SUMEET 0x264). Set AFTER the giveitem so a full bag leaves the reward reclaimable.
#define FLAG_TRINITY_J_ICE_BOULDER_1               0x49C // Trinity M4b S10: was FLAG_UNUSED_0x49C -- visibility - ICE PATH B1F boulder at GSC (11,7). Sole writer is removeobject, which FlagSets before despawning (src/event_object_movement.c:1537-1545), so a boulder dropped down its hole stays dropped. NO authoring clause: one writer, correct default (S7 rule).
#define FLAG_TRINITY_J_ICE_BOULDER_2               0x49D // Trinity M4b S10: was FLAG_UNUSED_0x49D -- visibility - ICE PATH B1F boulder at GSC (7,8). See _ICE_BOULDER_1.
#define FLAG_TRINITY_J_ICE_BOULDER_3               0x49E // Trinity M4b S10: was FLAG_UNUSED_0x49E -- visibility - ICE PATH B1F boulder at GSC (8,9). See _ICE_BOULDER_1.
#define FLAG_TRINITY_J_ICE_BOULDER_4               0x49F // Trinity M4b S10: was FLAG_UNUSED_0x49F -- visibility - ICE PATH B1F boulder at GSC (17,7). See _ICE_BOULDER_1.
#define FLAG_TRINITY_J_ICE_LANDING_1               0x4A0 // Trinity M4b S10: was FLAG_UNUSED_0x4A0 -- visibility - the B2F MAHOGANY SIDE copy of boulder 1, at GSC (11,3). EXACT COMPLEMENT of _ICE_BOULDER_1: GSC ships EVENT_BOULDER_IN_ICE_PATH_1 set and _1A clear, and the fall inverts both. NOT touched by the fall script -- the fall only sets _ICE_BOULDER_1 (via removeobject's FlagSet); this flag's SINGLE authoring site is IcePathB2FMahoganySide_OnTransition, which clears it iff _ICE_BOULDER_1 is set.
#define FLAG_TRINITY_J_ICE_LANDING_2               0x4A1 // Trinity M4b S10: was FLAG_UNUSED_0x4A1 -- visibility - the B2F copy of boulder 2, at GSC (4,7). See _ICE_LANDING_1.
#define FLAG_TRINITY_J_ICE_LANDING_3               0x4A2 // Trinity M4b S10: was FLAG_UNUSED_0x4A2 -- visibility - the B2F copy of boulder 3, at GSC (3,12). See _ICE_LANDING_1.
#define FLAG_TRINITY_J_ICE_LANDING_4               0x4A3 // Trinity M4b S10: was FLAG_UNUSED_0x4A3 -- visibility - the B2F copy of boulder 4, at GSC (12,13). See _ICE_LANDING_1.
#define FLAG_TRINITY_J_INDIGO_GATE_PASSED          0x4A4 // Trinity M4b S11: was FLAG_UNUSED_0x4A4 -- story - the ROUTE 26 league gate has been passed once (8 Johto badges, via C-COUNT). Latch only: it silences the pass line, it never re-opens the gate. G7: the gate READS badges 09-16 and writes none.
#define FLAG_TRINITY_J_VR_SILVER_HIDE              0x4A5 // Trinity M4b S11: was FLAG_UNUSED_0x4A5 -- visibility - SILVER on VICTORY ROAD 2F (45,11). Single authoring site VictoryRoad_2F_OnTransition: visible iff NOT _SILVER5_BEATEN.
#define FLAG_TRINITY_J_SILVER5_BEATEN              0x4A6 // Trinity M4b S11: was FLAG_UNUSED_0x4A6 -- story - SILVER 5 beaten, the rival arc closes. Set by the VICTORY ROAD scene; read by his visibility predicate and by the coord trigger guard.
#define FLAG_TRINITY_J_E4_WILL_BEATEN              0x4A7 // Trinity M4b S11: was FLAG_UNUSED_0x4A7 -- ELITE FOUR run state - WILL (in LORELEI'S ROOM). CLEARED by IndigoPlateau_PokemonCenter_1F_OnTransition, so it is NOT the terminal state: see _LEAGUE_CLEARED.
#define FLAG_TRINITY_J_E4_KOGA_BEATEN              0x4A8 // Trinity M4b S11: was FLAG_UNUSED_0x4A8 -- ELITE FOUR run state - KOGA (in BRUNO'S ROOM). Cleared on entering the INDIGO Center.
#define FLAG_TRINITY_J_E4_BRUNO_BEATEN             0x4A9 // Trinity M4b S11: was FLAG_UNUSED_0x4A9 -- ELITE FOUR run state - BRUNO (in AGATHA'S ROOM). Cleared on entering the INDIGO Center.
#define FLAG_TRINITY_J_E4_KAREN_BEATEN             0x4AA // Trinity M4b S11: was FLAG_UNUSED_0x4AA -- ELITE FOUR run state - KAREN (in LANCE'S ROOM). Cleared on entering the INDIGO Center.
#define FLAG_TRINITY_J_E4_LANCE_BEATEN             0x4AB // Trinity M4b S11: was FLAG_UNUSED_0x4AB -- ELITE FOUR run state - LANCE (in the CHAMPION'S ROOM). Cleared on entering the INDIGO Center.
#define FLAG_TRINITY_J_LEAGUE_CLEARED              0x4AC // Trinity M4b S11: was FLAG_UNUSED_0x4AC -- story, TERMINAL and never cleared - the JOHTO LEAGUE has been won at least once. S6's rule: a chain containing a clearflag must test its TERMINAL state explicitly, because the five _BEATEN flags above return to their starting values on every Center visit. Paired with VAR_TRINITY_JOHTO_ARC == 10.
#define FLAG_TRINITY_BADGE17    0x4AD // Trinity: was FLAG_UNUSED_0x4AD — Brock
#define FLAG_TRINITY_BADGE18    0x4AE // Trinity: was FLAG_UNUSED_0x4AE — Misty
#define FLAG_TRINITY_BADGE19    0x4AF // Trinity: was FLAG_UNUSED_0x4AF — Surge
#define FLAG_TRINITY_BADGE20    0x4B0 // Trinity: was FLAG_UNUSED_0x4B0 — Erika
#define FLAG_TRINITY_BADGE21    0x4B1 // Trinity: was FLAG_UNUSED_0x4B1 — Janine
#define FLAG_TRINITY_BADGE22    0x4B2 // Trinity: was FLAG_UNUSED_0x4B2 — Sabrina
#define FLAG_TRINITY_BADGE23    0x4B3 // Trinity: was FLAG_UNUSED_0x4B3 — Blaine
#define FLAG_TRINITY_BADGE24    0x4B4 // Trinity: was FLAG_UNUSED_0x4B4 — Giovanni
#define FLAG_TRINITY_K_ARRIVED    0x4B5 // Trinity M5a: was FLAG_UNUSED_0x4B5 — KANTO arrival gate (S.S. AQUA / VERMILION dock, Goldenrod<->Saffron MAGNET TRAIN pass on 0x4B6). M5b S1 is the one writer; this task (M5a T5) only reads it.
#define FLAG_TRINITY_K_TRAIN_PASS    0x4B6 // Trinity M5a: was FLAG_UNUSED_0x4B6 — MAGNET TRAIN pass (Goldenrod<->Saffron). M5b S2 is the one writer; this task (M5a T5) only reads it.
#define FLAG_TRINITY_K_AQUA_TICKET    0x4B7 // Trinity M5b S1: was FLAG_UNUSED_0x4B7 -- key item as flag (M4b precedent). BOBBY's Olivine summons issues it; his own departure script reads it to gate the S.S. AQUA crossing. One writer (OlivinePort_EventScript_Bobby).
#define FLAG_TRINITY_K_VERMGYM_SWITCHES_FOUND    0x4B8 // Trinity M5b S1: was FLAG_UNUSED_0x4B8 -- VERMILION GYM trash-can switch puzzle, solved state. Persists across sessions (unlike the puzzle's own transient VAR_TEMP_*/FLAG_TEMP_1 scratch). One writer (VermilionCity_Gym_EventScript_FoundSwitchTwo).
#define FLAG_TRINITY_K_SURGE_TM24    0x4B9 // Trinity M5b S1: was FLAG_UNUSED_0x4B9 -- G2 TM award guard (bag-full retry), VioletGym's FLAG_TRINITY_J_FALKNER_TM40 pattern.
#define FLAG_TRINITY_K_OLIVINE_BOBBY_HIDE    0x4BA // Trinity M5b S1: was FLAG_UNUSED_0x4BA -- object-visibility plumbing, OlivinePort's BOBBY. Dynamic, ON_TRANSITION-authored every load (GoldenrodCity_EventScript_SetBobbyVisibility pattern): visible iff FLAG_TRINITY_J_LEAGUE_CLEARED set AND VAR_TRINITY_JOHTO_ARC >= 10 AND FLAG_TRINITY_K_ARRIVED unset.
#define FLAG_TRINITY_K_VERMILION_BOBBY_HIDE    0x4BB // Trinity M5b S1: was FLAG_UNUSED_0x4BB -- object-visibility plumbing, VermilionCity's addobject-only BOBBY session actor (the one arrival cutscene). Unconditionally setflag'd every VermilionCity_OnTransition (RadioTower5F_OnTransition's own Giovanni/Bobby treatment) so he never auto-spawns from his template; only the arrival scene's addobject ever shows him.
#define FLAG_TRINITY_K_SABRINA_TM29    0x4BC // Trinity M5b S2: was FLAG_UNUSED_0x4BC -- G2 TM award guard (bag-full retry), FLAG_TRINITY_K_SURGE_TM24's pattern verbatim.
#define FLAG_TRINITY_K_MISTY_TM18    0x4BD // Trinity M5b S3: was FLAG_UNUSED_0x4BD -- G2 TM award guard (bag-full retry), FLAG_TRINITY_K_SURGE_TM24's pattern verbatim.
#define FLAG_TRINITY_K_MACHINE_PART    0x4BE // Trinity M5b S3: was FLAG_UNUSED_0x4BE -- key-item-as-flag (M4b CianwoodPharmacy/SECRETPOTION precedent). Set on the CeruleanCity_Gym pool pickup, cleared when handed to the PowerPlant manager.
#define FLAG_TRINITY_K_SABOTEUR_HIDE    0x4BF // Trinity M5b S3: was FLAG_UNUSED_0x4BF -- object-visibility plumbing, CeruleanCity_Gym's fleeing saboteur (R1 single-member cast shape). Dynamic, ON_TRANSITION-authored off VAR_TRINITY_SCENE_CERULEAN_SABOTEUR.
#define FLAG_TRINITY_K_SABOTEUR_DONE    0x4C0 // Trinity M5b S3: was FLAG_UNUSED_0x4C0 -- terminal, the CeruleanCity_Gym saboteur scene has played. Gates the pool pickup.
#define FLAG_TRINITY_K_ZAPDOS_HIDE    0x4C1 // Trinity M5b S3: was FLAG_UNUSED_0x4C1 -- object-visibility plumbing, PowerPlant's ZAPDOS (static-legendary contract clause 1).
#define FLAG_TRINITY_K_ZAPDOS_RESOLVED    0x4C2 // Trinity M5b S3: was FLAG_UNUSED_0x4C2 -- terminal, static-legendary contract clause 3 (written on WON and on the CAUGHT fall-through).
#define FLAG_TRINITY_K_PLANT_RESTORED    0x4C3 // Trinity M5b S3: was FLAG_UNUSED_0x4C3 -- terminal, the PowerPlant manager has the MACHINE PART back. Gates ZAPDOS.
#define FLAG_TRINITY_K_CAVE_GUARD_HIDE    0x4C4 // Trinity M5b S3: was FLAG_UNUSED_0x4C4 -- object-visibility plumbing, CeruleanCity's Cerulean Cave mouth guard. Dynamic, ON_TRANSITION-authored: visible iff VAR_TRINITY_KANTO_ARC < 6.
#define FLAG_TRINITY_K_BROCK_TM37    0x4C5 // Trinity M5b S4: was FLAG_UNUSED_0x4C5 -- PewterCity_Gym Brock's TM37 (Sandstorm) award guard, bag-full retry.
#define FLAG_TRINITY_K_MTMOON_DOME_FOSSIL_HIDE    0x4C6 // Trinity M5b S4 fix round (review C1): was FLAG_UNUSED_0x4C6 -- object-visibility plumbing, MtMoon_B2F's DOME FOSSIL. SET by removeobject's own engine co-sign (RemoveObjectEventByLocalIdAndMap -> FlagSet, src/event_object_movement.c:1537-1545) when either fossil is taken; CLEARED by MtMoon_B2F_OnTransition while unset. Mirrors pokefirered's own FLAG_HIDE_DOME_FOSSIL.
#define FLAG_TRINITY_K_MTMOON_HELIX_FOSSIL_HIDE    0x4C7 // Trinity M5b S4 fix round (review C1): was FLAG_UNUSED_0x4C7 -- object-visibility plumbing, MtMoon_B2F's HELIX FOSSIL. SET by removeobject's own engine co-sign (RemoveObjectEventByLocalIdAndMap -> FlagSet, src/event_object_movement.c:1537-1545) when either fossil is taken; CLEARED by MtMoon_B2F_OnTransition while unset. Mirrors pokefirered's own FLAG_HIDE_HELIX_FOSSIL.
#define FLAG_TRINITY_K_MTMOON_FOSSIL_TAKEN    0x4C8 // Trinity M5b S4 fix round (review C1): was FLAG_UNUSED_0x4C8 -- terminal, either fossil has been taken (both objects removed). Mirrors pokefirered's own FLAG_GOT_FOSSIL_FROM_MT_MOON.
#define FLAG_TRINITY_K_BLUE_GRUDGE_HIDE    0x4C9 // Trinity M5b S5: was FLAG_UNUSED_0x4C9 -- object-visibility plumbing, ViridianCity's BLUE grudge battle. ON_TRANSITION single authority: visible iff VAR_TRINITY_KANTO_ARC < 2 (mirrors CeruleanCity_OnTransition's cave-guard shape). Terminal state is the arc value itself (S5 is the ONE writer of VAR_TRINITY_KANTO_ARC == 2) -- this flag exists only for the object's own native "flag" visibility field, not as a second record of "defeated".
#define FLAG_TRINITY_K_ERIKA_TM22    0x4CA // Trinity M5b S6: was FLAG_UNUSED_0x4CA -- CeladonCity_Gym Erika's TM22 (Solar Beam) award guard, bag-full retry, FLAG_TRINITY_K_BROCK_TM37's pattern verbatim.
#define FLAG_TRINITY_K_HIDEOUT_RAID_HIDE    0x4CB // Trinity M5b S6: was FLAG_UNUSED_0x4CB -- object-visibility plumbing, ROCKET HIDEOUT's whole raid cast (9 grunts, B1F-B4F, R1 shared-flag pattern). ON_TRANSITION-authored per floor: visible iff VAR_TRINITY_KANTO_ARC == 2.
#define FLAG_TRINITY_K_LIFT_KEY    0x4CC // Trinity M5b S6: was FLAG_UNUSED_0x4CC -- key item as flag (M4b Card Key precedent). Set on F_2's defeat, RocketHideout_B4F. No further mechanical gate this slice (elevator UI skipped, see 06-celadon-chapter.md section 7) -- a collectible/narrative beat.
#define FLAG_TRINITY_K_GS_BALL    0x4CD // Trinity M5b S6: was FLAG_UNUSED_0x4CD -- key item as flag. Set on the evidence-room pickup, RocketHideout_B4F. WRITER LANDS HERE; S13's Celebi chain is the eventual reader (handoff noted, no FORTHCOMING_KANTO_FLAG_WRITERS entry needed -- the writer exists from this commit forward).
#define FLAG_TRINITY_K_HIDEOUT_OPENED    0x4CE // Trinity M5b S6: was FLAG_UNUSED_0x4CE -- CeladonCity_GameCorner's poster-switch state (mirrors pokefirered's own FLAG_OPENED_ROCKET_HIDEOUT). The door's only state (D4).
#define FLAG_TRINITY_K_HIDEOUT_B1F_DOOR    0x4CF // Trinity M5b S6: was FLAG_UNUSED_0x4CF -- RocketHideout_B1F's single-grunt barrier, its only state (D4). Set on F_1's defeat.
#define FLAG_TRINITY_K_HIDEOUT_B4F_DOOR    0x4D0 // Trinity M5b S6: was FLAG_UNUSED_0x4D0 -- RocketHideout_B4F's two-grunt barrier, its only state (D4). Set once both M_6 and M_7 are defeated.
#define FLAG_TRINITY_K_JANINE_TM06    0x4D1 // Trinity M5b S8: was FLAG_UNUSED_0x4D1 -- FuchsiaCity_Gym Janine's TM06 (Toxic) award guard, bag-full retry, FLAG_TRINITY_K_BROCK_TM37's pattern verbatim.
#define FLAG_TRINITY_K_BLAINE_TM38    0x4D2 // Trinity M5b S9: was FLAG_UNUSED_0x4D2 -- CinnabarIsland_Gym Blaine's TM38 (Fire Blast) award guard, bag-full retry, FLAG_TRINITY_K_BROCK_TM37's pattern verbatim.
#define FLAG_TRINITY_K_SEAFOAM_B3F_BOULDER_1    0x4D3 // Trinity M5b S9: was FLAG_UNUSED_0x4D3 -- SeafoamIslands_B3F boulder at (9,16), falls into hole (9,18). Correct default (clear=present), one writer (removeobject), no authoring clause -- Blackthorn pin.
#define FLAG_TRINITY_K_SEAFOAM_B3F_BOULDER_2    0x4D4 // Trinity M5b S9: was FLAG_UNUSED_0x4D4 -- SeafoamIslands_B3F boulder relocated to (6,17), falls into hole (6,18). Same shape as BOULDER_1.
#define FLAG_TRINITY_K_SEAFOAM_B4F_BOULDER_1    0x4D5 // Trinity M5b S9: was FLAG_UNUSED_0x4D5 -- SeafoamIslands_B4F boulder revealed at (9,18) once B3F_BOULDER_1 falls; wrong default (should start hidden), re-hidden every ON_TRANSITION load unless the B3F source flag is set.
#define FLAG_TRINITY_K_SEAFOAM_B4F_BOULDER_2    0x4D6 // Trinity M5b S9: was FLAG_UNUSED_0x4D6 -- SeafoamIslands_B4F boulder revealed at (8,18) once B3F_BOULDER_2 falls. Same shape as BOULDER_1.
#define FLAG_TRINITY_K_ARTICUNO_HIDE    0x4D7 // Trinity M5b S9: was FLAG_UNUSED_0x4D7 -- legendary contract clause 1, SeafoamIslands_B4F. Gate: both B4F boulder flags set (current stopped) -- the puzzle IS the gate, no story flag.
#define FLAG_TRINITY_K_ARTICUNO_RESOLVED    0x4D8 // Trinity M5b S9: was FLAG_UNUSED_0x4D8 -- legendary contract clause 3 (terminal), set on WON and CAUGHT.
#define FLAG_TRINITY_K_OLD_AMBER    0x4D9 // Trinity M5b S9: was FLAG_UNUSED_0x4D9 -- PewterCity_Museum_1F Old Amber pickup guard, bag-full retry, S4's planted "ask Cinnabar" hook paid off here.
#define FLAG_TRINITY_K_BLAINE_QUIZ_1    0x4DA // Trinity M5b S9: was FLAG_UNUSED_0x4DA -- CinnabarIsland_Gym quiz door 1 (Quinn's room). FRLG's own FLAG_CINNABAR_GYM_QUIZ_1 does not exist in this tree (pokeemerald-expansion carries no FRLG-specific flags at all -- confirmed by grep, zero FLAG_CINNABAR_*/FLAG_POKEMON_MANSION_*/FLAG_STOPPED_SEAFOAM_*/FLAG_HIDE_SEAFOAM_* hits anywhere in this header), so this is claimed fresh rather than reused.
#define FLAG_TRINITY_K_BLAINE_QUIZ_2    0x4DB // Trinity M5b S9: was FLAG_UNUSED_0x4DB -- CinnabarIsland_Gym quiz door 2 (Avery's room). Same shape as QUIZ_1.
#define FLAG_TRINITY_K_BLAINE_QUIZ_3    0x4DC // Trinity M5b S9: was FLAG_UNUSED_0x4DC -- CinnabarIsland_Gym quiz door 3 (Ramon's room). Same shape as QUIZ_1.
#define FLAG_TRINITY_K_BLAINE_QUIZ_4    0x4DD // Trinity M5b S9: was FLAG_UNUSED_0x4DD -- CinnabarIsland_Gym quiz door 4 (Derek's room). Same shape as QUIZ_1.
#define FLAG_TRINITY_K_BLAINE_QUIZ_5    0x4DE // Trinity M5b S9: was FLAG_UNUSED_0x4DE -- CinnabarIsland_Gym quiz door 5 (Dusty's room). Same shape as QUIZ_1.
#define FLAG_TRINITY_K_BLAINE_QUIZ_6    0x4DF // Trinity M5b S9: was FLAG_UNUSED_0x4DF -- CinnabarIsland_Gym quiz door 6 (Zac's room). Same shape as QUIZ_1.
#define FLAG_TRINITY_K_SEAFOAM_B3F_LOCK_1    0x4E0 // Trinity M5b S9 fix round (review C2): was FLAG_UNUSED_0x4E0 -- SeafoamIslands_B3F lock/decoy boulder at (9,16), TRAINER_TYPE_NONE, no B4F reveal target -- FRLG's own "clear the lock, then push the payload" shape. Object-visibility plumbing only; if it ever falls into a hole the generic engine hook still needs a real flag to removeobject-cosign.
#define FLAG_TRINITY_K_GIOVANNI_TM26    0x4E1 // Trinity M5b S10: was FLAG_UNUSED_0x4E1 -- ViridianCity_Gym G2 TM award guard (bag-full retry), FLAG_TRINITY_K_BLAINE_QUIZ pattern class.
#define FLAG_TRINITY_K_VBASEMENT_RAID_HIDE    0x4E2 // Trinity M5b S10: was FLAG_UNUSED_0x4E2 -- R1 shared cast-hide, all 6 Viridian basement raid posts (3 per floor); visible iff VAR_TRINITY_KANTO_ARC == 3.
#define FLAG_TRINITY_K_VBASEMENT_B2F_DOOR    0x4E3 // Trinity M5b S10: was FLAG_UNUSED_0x4E3 -- ViridianHideout_B2F barrier's ONLY state (D1-D5), independent of RocketHideout_B4F's own FLAG_TRINITY_K_HIDEOUT_B4F_DOOR.
#define FLAG_TRINITY_K_RIG_MEWTWO_HIDE    0x4E4 // Trinity M5b S10: was FLAG_UNUSED_0x4E4 -- Mewtwo's own visibility flag in the rig room; visible iff arc==3 AND FLAG_TRINITY_K_RIG_RESOLVED unset.
#define FLAG_TRINITY_K_RIG_MEW_HIDE    0x4E5 // Trinity M5b S10: was FLAG_UNUSED_0x4E5 -- Mew's own visibility flag; unconditionally set every ON_TRANSITION (pure addobject-spawned session actor, never visible on a fresh load).
#define FLAG_TRINITY_K_RIG_RESOLVED    0x4E6 // Trinity M5b S10: was FLAG_UNUSED_0x4E6 -- terminal, the rig scene has played. Corroboration: setflag site removeobject's both legendaries.
#define FLAG_TRINITY_K_GIOVANNI_BASEMENT_HIDE    0x4E7 // Trinity M5b S10: was FLAG_UNUSED_0x4E7 -- Giovanni's BASEMENT object's own hide flag (R1 co-sign on removeobject); separate from his unconditional gym-state object, no template-position reuse across states.
#define FLAG_TRINITY_K_SILVER_FINAL_HIDE    0x4E8 // Trinity M5b S10: was FLAG_UNUSED_0x4E8 -- Route1 SILVER's own visibility flag; visible iff FLAG_TRINITY_BADGE24 set AND VAR_TRINITY_KANTO_ARC < 5.
#define FLAG_TRINITY_K_MOLTRES_HIDE    0x4E9 // Trinity M5b S11: was FLAG_UNUSED_0x4E9 -- MOLTRES's own visibility flag (Zapdos/Articuno contract clause 1), VictoryRoad_3F (fix round 1, review Minor 7: corrected from "KantoVictoryRoad_3F" -- no such map exists, KantoVictoryRoad_1F is a different, separate floor). Ungated: clears unconditionally every ON_TRANSITION unless FLAG_TRINITY_K_MOLTRES_RESOLVED is set.
#define FLAG_TRINITY_K_MOLTRES_RESOLVED    0x4EA // Trinity M5b S11: was FLAG_UNUSED_0x4EA -- terminal (contract clause 3), written on WON and on the CAUGHT fall-through.
#define FLAG_TRINITY_K_E4_LORELEI_BEATEN    0x4EB // Trinity M5b S11: was FLAG_UNUSED_0x4EB -- PokemonLeague_LoreleisRoom's Kanto-roster (E4-II) door/idempotency flag, FLAG_TRINITY_J_E4_WILL_BEATEN's pattern verbatim, cleared on every INDIGO Center visit alongside it.
#define FLAG_TRINITY_K_E4_AGATHA_BEATEN    0x4EC // Trinity M5b S11: was FLAG_UNUSED_0x4EC -- PokemonLeague_BrunosRoom's Kanto-roster (AGATHA occupies this room) door/idempotency flag.
#define FLAG_TRINITY_K_E4_BRUNOII_BEATEN    0x4ED // Trinity M5b S11: was FLAG_UNUSED_0x4ED -- PokemonLeague_AgathasRoom's Kanto-roster (BRUNO-II occupies this room) door/idempotency flag. Distinct name from Johto's own FLAG_TRINITY_J_E4_BRUNO_BEATEN (different room, different character).
#define FLAG_TRINITY_K_E4_BLUE_BEATEN    0x4EE // Trinity M5b S11: was FLAG_UNUSED_0x4EE -- PokemonLeague_LancesRoom's Kanto-roster (BLUE holds the 4th E4-II seat here) door/idempotency flag.
#define FLAG_TRINITY_K_GAUNTLET_REWARD    0x4EF // Trinity M5b S11: was FLAG_UNUSED_0x4EF -- Indigo II lobby Crew Gauntlet's ONE combined reward, claimed-once guard. BOBBY's own script is the only setter, after a genuinely successful giveitem (bag-full retry pattern).

#define FLAG_DEFEATED_RUSTBORO_GYM                                  0x4F0
#define FLAG_DEFEATED_DEWFORD_GYM                                   0x4F1
#define FLAG_DEFEATED_MAUVILLE_GYM                                  0x4F2
#define FLAG_DEFEATED_LAVARIDGE_GYM                                 0x4F3
#define FLAG_DEFEATED_PETALBURG_GYM                                 0x4F4
#define FLAG_DEFEATED_FORTREE_GYM                                   0x4F5
#define FLAG_DEFEATED_MOSSDEEP_GYM                                  0x4F6
#define FLAG_DEFEATED_SOOTOPOLIS_GYM                                0x4F7
#define FLAG_DEFEATED_METEOR_FALLS_STEVEN                           0x4F8

#define FLAG_UNUSED_0x4F9                                           0x4F9 // Unused Flag
#define FLAG_UNUSED_0x4FA                                           0x4FA // Unused Flag

#define FLAG_DEFEATED_ELITE_4_SIDNEY                                0x4FB
#define FLAG_DEFEATED_ELITE_4_PHOEBE                                0x4FC
#define FLAG_DEFEATED_ELITE_4_GLACIA                                0x4FD
#define FLAG_DEFEATED_ELITE_4_DRAKE                                 0x4FE

#define FLAG_UNUSED_0x4FF                                           0x4FF // Unused Flag

// Trainer Flags
// Trainer flags occupy 0x500 - 0x85F, the last 9 of which are unused
// See constants/opponents.h. The values there + FLAG_TRAINER_FLAG_START are the flag IDs

#define TRAINER_FLAGS_START                                         0x500
#define TRAINER_FLAGS_END                                           (TRAINER_FLAGS_START + MAX_TRAINERS_COUNT - 1) // 0x85F

// System Flags

#define SYSTEM_FLAGS                                   (TRAINER_FLAGS_END + 1) // 0x860

#define FLAG_SYS_POKEMON_GET                         (SYSTEM_FLAGS + 0x0) // FLAG_0x860
#define FLAG_SYS_POKEDEX_GET                         (SYSTEM_FLAGS + 0x1)
#define FLAG_SYS_POKENAV_GET                         (SYSTEM_FLAGS + 0x2)
#define FLAG_UNUSED_0x863                            (SYSTEM_FLAGS + 0x3) // Unused Flag
#define FLAG_SYS_GAME_CLEAR                          (SYSTEM_FLAGS + 0x4)
#define FLAG_SYS_CHAT_USED                           (SYSTEM_FLAGS + 0x5)
#define FLAG_UNLOCKED_TRENDY_SAYINGS                 (SYSTEM_FLAGS + 0x6)

// Badges
#define FLAG_BADGE01_GET                             (SYSTEM_FLAGS + 0x7)
#define FLAG_BADGE02_GET                             (SYSTEM_FLAGS + 0x8)
#define FLAG_BADGE03_GET                             (SYSTEM_FLAGS + 0x9)
#define FLAG_BADGE04_GET                             (SYSTEM_FLAGS + 0xA)
#define FLAG_BADGE05_GET                             (SYSTEM_FLAGS + 0xB)
#define FLAG_BADGE06_GET                             (SYSTEM_FLAGS + 0xC)
#define FLAG_BADGE07_GET                             (SYSTEM_FLAGS + 0xD)
#define FLAG_BADGE08_GET                             (SYSTEM_FLAGS + 0xE)
#define NUM_BADGES                                   (1 + FLAG_BADGE08_GET - FLAG_BADGE01_GET)

// Towns and Cities
#define FLAG_VISITED_LITTLEROOT_TOWN                (SYSTEM_FLAGS + 0xF)
#define FLAG_VISITED_OLDALE_TOWN                    (SYSTEM_FLAGS + 0x10)
#define FLAG_VISITED_DEWFORD_TOWN                   (SYSTEM_FLAGS + 0x11)
#define FLAG_VISITED_LAVARIDGE_TOWN                 (SYSTEM_FLAGS + 0x12)
#define FLAG_VISITED_FALLARBOR_TOWN                 (SYSTEM_FLAGS + 0x13)
#define FLAG_VISITED_VERDANTURF_TOWN                (SYSTEM_FLAGS + 0x14)
#define FLAG_VISITED_PACIFIDLOG_TOWN                (SYSTEM_FLAGS + 0x15)
#define FLAG_VISITED_PETALBURG_CITY                 (SYSTEM_FLAGS + 0x16)
#define FLAG_VISITED_SLATEPORT_CITY                 (SYSTEM_FLAGS + 0x17)
#define FLAG_VISITED_MAUVILLE_CITY                  (SYSTEM_FLAGS + 0x18)
#define FLAG_VISITED_RUSTBORO_CITY                  (SYSTEM_FLAGS + 0x19)
#define FLAG_VISITED_FORTREE_CITY                   (SYSTEM_FLAGS + 0x1A)
#define FLAG_VISITED_LILYCOVE_CITY                  (SYSTEM_FLAGS + 0x1B)
#define FLAG_VISITED_MOSSDEEP_CITY                  (SYSTEM_FLAGS + 0x1C)
#define FLAG_VISITED_SOOTOPOLIS_CITY                (SYSTEM_FLAGS + 0x1D)
#define FLAG_VISITED_EVER_GRANDE_CITY               (SYSTEM_FLAGS + 0x1E)

#define FLAG_IS_CHAMPION                            (SYSTEM_FLAGS + 0x1F) // Seems to be related to linking.
#define FLAG_NURSE_UNION_ROOM_REMINDER              (SYSTEM_FLAGS + 0x20)

#define FLAG_UNUSED_0x881                           (SYSTEM_FLAGS + 0x21) // Unused Flag
#define FLAG_UNUSED_0x882                           (SYSTEM_FLAGS + 0x22) // Unused Flag
#define FLAG_UNUSED_0x883                           (SYSTEM_FLAGS + 0x23) // Unused Flag
#define FLAG_UNUSED_0x884                           (SYSTEM_FLAGS + 0x24) // Unused Flag
#define FLAG_UNUSED_0x885                           (SYSTEM_FLAGS + 0x25) // Unused Flag
#define FLAG_UNUSED_0x886                           (SYSTEM_FLAGS + 0x26) // Unused Flag
#define FLAG_UNUSED_0x887                           (SYSTEM_FLAGS + 0x27) // Unused Flag

#define FLAG_SYS_USE_FLASH                          (SYSTEM_FLAGS + 0x28)
#define FLAG_SYS_USE_STRENGTH                       (SYSTEM_FLAGS + 0x29)
// Sets abnormal weather on maps that check for it
#define FLAG_SYS_WEATHER_CTRL                       (SYSTEM_FLAGS + 0x2A)
#define FLAG_SYS_CYCLING_ROAD                       (SYSTEM_FLAGS + 0x2B)
#define FLAG_SYS_SAFARI_MODE                        (SYSTEM_FLAGS + 0x2C)
#define FLAG_SYS_CRUISE_MODE                        (SYSTEM_FLAGS + 0x2D)

#define FLAG_UNUSED_0x88E                           (SYSTEM_FLAGS + 0x2E) // Unused Flag
#define FLAG_UNUSED_0x88F                           (SYSTEM_FLAGS + 0x2F) // Unused Flag

#define FLAG_SYS_TV_HOME                            (SYSTEM_FLAGS + 0x30)
#define FLAG_SYS_TV_WATCH                           (SYSTEM_FLAGS + 0x31)
#define FLAG_SYS_TV_START                           (SYSTEM_FLAGS + 0x32)
#define FLAG_SYS_CHANGED_DEWFORD_TREND              (SYSTEM_FLAGS + 0x33)
#define FLAG_SYS_MIX_RECORD                         (SYSTEM_FLAGS + 0x34)
#define FLAG_SYS_CLOCK_SET                          (SYSTEM_FLAGS + 0x35)
#define FLAG_SYS_NATIONAL_DEX                       (SYSTEM_FLAGS + 0x36)
#define FLAG_SYS_CAVE_SHIP                          (SYSTEM_FLAGS + 0x37) // Unused Flag, leftover from R/S debug, presumably used by Emerald's debug too
#define FLAG_SYS_CAVE_WONDER                        (SYSTEM_FLAGS + 0x38) // Unused Flag, same as above
#define FLAG_SYS_CAVE_BATTLE                        (SYSTEM_FLAGS + 0x39) // Unused Flag, same as above
#define FLAG_SYS_SHOAL_TIDE                         (SYSTEM_FLAGS + 0x3A)
#define FLAG_SYS_RIBBON_GET                         (SYSTEM_FLAGS + 0x3B)

#define FLAG_LANDMARK_FLOWER_SHOP                   (SYSTEM_FLAGS + 0x3C)
#define FLAG_LANDMARK_MR_BRINEY_HOUSE               (SYSTEM_FLAGS + 0x3D)
#define FLAG_LANDMARK_ABANDONED_SHIP                (SYSTEM_FLAGS + 0x3E)
#define FLAG_LANDMARK_SEASHORE_HOUSE                (SYSTEM_FLAGS + 0x3F)
#define FLAG_LANDMARK_NEW_MAUVILLE                  (SYSTEM_FLAGS + 0x40)
#define FLAG_LANDMARK_OLD_LADY_REST_SHOP            (SYSTEM_FLAGS + 0x41)
#define FLAG_LANDMARK_TRICK_HOUSE                   (SYSTEM_FLAGS + 0x42)
#define FLAG_LANDMARK_WINSTRATE_FAMILY              (SYSTEM_FLAGS + 0x43)
#define FLAG_LANDMARK_GLASS_WORKSHOP                (SYSTEM_FLAGS + 0x44)
#define FLAG_LANDMARK_LANETTES_HOUSE                (SYSTEM_FLAGS + 0x45)
#define FLAG_LANDMARK_POKEMON_DAYCARE               (SYSTEM_FLAGS + 0x46)
#define FLAG_LANDMARK_SEAFLOOR_CAVERN               (SYSTEM_FLAGS + 0x47)
#define FLAG_LANDMARK_BATTLE_FRONTIER               (SYSTEM_FLAGS + 0x48)
#define FLAG_LANDMARK_SOUTHERN_ISLAND               (SYSTEM_FLAGS + 0x49)
#define FLAG_LANDMARK_FIERY_PATH                    (SYSTEM_FLAGS + 0x4A)

#define FLAG_SYS_PC_LANETTE                         (SYSTEM_FLAGS + 0x4B)
#define FLAG_SYS_MYSTERY_EVENT_ENABLE               (SYSTEM_FLAGS + 0x4C)
#define FLAG_SYS_ENC_UP_ITEM                        (SYSTEM_FLAGS + 0x4D)
#define FLAG_SYS_ENC_DOWN_ITEM                      (SYSTEM_FLAGS + 0x4E)
#define FLAG_SYS_BRAILLE_DIG                        (SYSTEM_FLAGS + 0x4F)
#define FLAG_SYS_REGIROCK_PUZZLE_COMPLETED          (SYSTEM_FLAGS + 0x50)
#define FLAG_SYS_BRAILLE_REGICE_COMPLETED           (SYSTEM_FLAGS + 0x51)
#define FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED         (SYSTEM_FLAGS + 0x52)
#define FLAG_ENABLE_SHIP_SOUTHERN_ISLAND            (SYSTEM_FLAGS + 0x53)

#define FLAG_LANDMARK_POKEMON_LEAGUE                (SYSTEM_FLAGS + 0x54)
#define FLAG_LANDMARK_ISLAND_CAVE                   (SYSTEM_FLAGS + 0x55)
#define FLAG_LANDMARK_DESERT_RUINS                  (SYSTEM_FLAGS + 0x56)
#define FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE          (SYSTEM_FLAGS + 0x57)
#define FLAG_LANDMARK_SCORCHED_SLAB                 (SYSTEM_FLAGS + 0x58)
#define FLAG_LANDMARK_ANCIENT_TOMB                  (SYSTEM_FLAGS + 0x59)
#define FLAG_LANDMARK_TUNNELERS_REST_HOUSE          (SYSTEM_FLAGS + 0x5A)
#define FLAG_LANDMARK_HUNTERS_HOUSE                 (SYSTEM_FLAGS + 0x5B)
#define FLAG_LANDMARK_SEALED_CHAMBER                (SYSTEM_FLAGS + 0x5C)

#define FLAG_SYS_TV_LATIAS_LATIOS                   (SYSTEM_FLAGS + 0x5D)

#define FLAG_LANDMARK_SKY_PILLAR                    (SYSTEM_FLAGS + 0x5E)

#define FLAG_SYS_SHOAL_ITEM                         (SYSTEM_FLAGS + 0x5F)
#define FLAG_SYS_B_DASH                             (SYSTEM_FLAGS + 0x60) // RECEIVED Running Shoes
#define FLAG_SYS_CTRL_OBJ_DELETE                    (SYSTEM_FLAGS + 0x61)
#define FLAG_SYS_RESET_RTC_ENABLE                   (SYSTEM_FLAGS + 0x62)

#define FLAG_LANDMARK_BERRY_MASTERS_HOUSE           (SYSTEM_FLAGS + 0x63)

#define FLAG_SYS_TOWER_SILVER                       (SYSTEM_FLAGS + 0x64)
#define FLAG_SYS_TOWER_GOLD                         (SYSTEM_FLAGS + 0x65)
#define FLAG_SYS_DOME_SILVER                        (SYSTEM_FLAGS + 0x66)
#define FLAG_SYS_DOME_GOLD                          (SYSTEM_FLAGS + 0x67)
#define FLAG_SYS_PALACE_SILVER                      (SYSTEM_FLAGS + 0x68)
#define FLAG_SYS_PALACE_GOLD                        (SYSTEM_FLAGS + 0x69)
#define FLAG_SYS_ARENA_SILVER                       (SYSTEM_FLAGS + 0x6A)
#define FLAG_SYS_ARENA_GOLD                         (SYSTEM_FLAGS + 0x6B)
#define FLAG_SYS_FACTORY_SILVER                     (SYSTEM_FLAGS + 0x6C)
#define FLAG_SYS_FACTORY_GOLD                       (SYSTEM_FLAGS + 0x6D)
#define FLAG_SYS_PIKE_SILVER                        (SYSTEM_FLAGS + 0x6E)
#define FLAG_SYS_PIKE_GOLD                          (SYSTEM_FLAGS + 0x6F)
#define FLAG_SYS_PYRAMID_SILVER                     (SYSTEM_FLAGS + 0x70)
#define FLAG_SYS_PYRAMID_GOLD                       (SYSTEM_FLAGS + 0x71)
#define FLAG_SYS_FRONTIER_PASS                      (SYSTEM_FLAGS + 0x72)

#define FLAG_MAP_SCRIPT_CHECKED_DEOXYS              (SYSTEM_FLAGS + 0x73)
#define FLAG_DEOXYS_ROCK_COMPLETE                   (SYSTEM_FLAGS + 0x74)
#define FLAG_ENABLE_SHIP_BIRTH_ISLAND               (SYSTEM_FLAGS + 0x75)
#define FLAG_ENABLE_SHIP_FARAWAY_ISLAND             (SYSTEM_FLAGS + 0x76)

#define FLAG_SHOWN_BOX_WAS_FULL_MESSAGE             (SYSTEM_FLAGS + 0x77)

#define FLAG_ARRIVED_ON_FARAWAY_ISLAND              (SYSTEM_FLAGS + 0x78)
#define FLAG_ARRIVED_AT_MARINE_CAVE_EMERGE_SPOT     (SYSTEM_FLAGS + 0x79)
#define FLAG_ARRIVED_AT_TERRA_CAVE_ENTRANCE         (SYSTEM_FLAGS + 0x7A)

#define FLAG_SYS_MYSTERY_GIFT_ENABLE                (SYSTEM_FLAGS + 0x7B)

#define FLAG_ENTERED_MIRAGE_TOWER                   (SYSTEM_FLAGS + 0x7C)
#define FLAG_LANDMARK_ALTERING_CAVE                 (SYSTEM_FLAGS + 0x7D)
#define FLAG_LANDMARK_DESERT_UNDERPASS              (SYSTEM_FLAGS + 0x7E)
#define FLAG_LANDMARK_ARTISAN_CAVE                  (SYSTEM_FLAGS + 0x7F)
#define FLAG_ENABLE_SHIP_NAVEL_ROCK                 (SYSTEM_FLAGS + 0x80)
#define FLAG_ARRIVED_AT_NAVEL_ROCK                  (SYSTEM_FLAGS + 0x81)
#define FLAG_LANDMARK_TRAINER_HILL                  (SYSTEM_FLAGS + 0x82)

#define FLAG_UNUSED_0x8E3                           (SYSTEM_FLAGS + 0x83) // Unused Flag

#define FLAG_RECEIVED_POKEDEX_FROM_BIRCH            (SYSTEM_FLAGS + 0x84)

#define FLAG_UNUSED_0x8E5                           (SYSTEM_FLAGS + 0x85) // Unused Flag
#define FLAG_UNUSED_0x8E6                           (SYSTEM_FLAGS + 0x86) // Unused Flag
#define FLAG_UNUSED_0x8E7                           (SYSTEM_FLAGS + 0x87) // Unused Flag
#define FLAG_UNUSED_0x8E8                           (SYSTEM_FLAGS + 0x88) // Unused Flag
#define FLAG_UNUSED_0x8E9                           (SYSTEM_FLAGS + 0x89) // Unused Flag
#define FLAG_UNUSED_0x8EA                           (SYSTEM_FLAGS + 0x8A) // Unused Flag
#define FLAG_UNUSED_0x8EB                           (SYSTEM_FLAGS + 0x8B) // Unused Flag
#define FLAG_UNUSED_0x8EC                           (SYSTEM_FLAGS + 0x8C) // Unused Flag
#define FLAG_UNUSED_0x8ED                           (SYSTEM_FLAGS + 0x8D) // Unused Flag
#define FLAG_UNUSED_0x8EE                           (SYSTEM_FLAGS + 0x8E) // Unused Flag
#define FLAG_UNUSED_0x8EF                           (SYSTEM_FLAGS + 0x8F) // Unused Flag
#define FLAG_UNUSED_0x8F0                           (SYSTEM_FLAGS + 0x90) // Unused Flag
#define FLAG_UNUSED_0x8F1                           (SYSTEM_FLAGS + 0x91) // Unused Flag
#define FLAG_UNUSED_0x8F2                           (SYSTEM_FLAGS + 0x92) // Unused Flag
#define FLAG_UNUSED_0x8F3                           (SYSTEM_FLAGS + 0x93) // Unused Flag
#define FLAG_UNUSED_0x8F4                           (SYSTEM_FLAGS + 0x94) // Unused Flag
#define FLAG_UNUSED_0x8F5                           (SYSTEM_FLAGS + 0x95) // Unused Flag
#define FLAG_UNUSED_0x8F6                           (SYSTEM_FLAGS + 0x96) // Unused Flag
#define FLAG_UNUSED_0x8F7                           (SYSTEM_FLAGS + 0x97) // Unused Flag
#define FLAG_UNUSED_0x8F8                           (SYSTEM_FLAGS + 0x98) // Unused Flag
#define FLAG_UNUSED_0x8F9                           (SYSTEM_FLAGS + 0x99) // Unused Flag
#define FLAG_UNUSED_0x8FA                           (SYSTEM_FLAGS + 0x9A) // Unused Flag
#define FLAG_UNUSED_0x8FB                           (SYSTEM_FLAGS + 0x9B) // Unused Flag
#define FLAG_UNUSED_0x8FC                           (SYSTEM_FLAGS + 0x9C) // Unused Flag
#define FLAG_UNUSED_0x8FD                           (SYSTEM_FLAGS + 0x9D) // Unused Flag
#define FLAG_UNUSED_0x8FE                           (SYSTEM_FLAGS + 0x9E) // Unused Flag
#define FLAG_UNUSED_0x8FF                           (SYSTEM_FLAGS + 0x9F) // Unused Flag
#define FLAG_UNUSED_0x900                           (SYSTEM_FLAGS + 0xA0) // Unused Flag
#define FLAG_UNUSED_0x901                           (SYSTEM_FLAGS + 0xA1) // Unused Flag
#define FLAG_UNUSED_0x902                           (SYSTEM_FLAGS + 0xA2) // Unused Flag
#define FLAG_UNUSED_0x903                           (SYSTEM_FLAGS + 0xA3) // Unused Flag
#define FLAG_UNUSED_0x904                           (SYSTEM_FLAGS + 0xA4) // Unused Flag
#define FLAG_UNUSED_0x905                           (SYSTEM_FLAGS + 0xA5) // Unused Flag
#define FLAG_UNUSED_0x906                           (SYSTEM_FLAGS + 0xA6) // Unused Flag
#define FLAG_UNUSED_0x907                           (SYSTEM_FLAGS + 0xA7) // Unused Flag
#define FLAG_UNUSED_0x908                           (SYSTEM_FLAGS + 0xA8) // Unused Flag
#define FLAG_UNUSED_0x909                           (SYSTEM_FLAGS + 0xA9) // Unused Flag
#define FLAG_UNUSED_0x90A                           (SYSTEM_FLAGS + 0xAA) // Unused Flag
#define FLAG_UNUSED_0x90B                           (SYSTEM_FLAGS + 0xAB) // Unused Flag
#define FLAG_UNUSED_0x90C                           (SYSTEM_FLAGS + 0xAC) // Unused Flag
#define FLAG_UNUSED_0x90D                           (SYSTEM_FLAGS + 0xAD) // Unused Flag
#define FLAG_UNUSED_0x90E                           (SYSTEM_FLAGS + 0xAE) // Unused Flag
#define FLAG_UNUSED_0x90F                           (SYSTEM_FLAGS + 0xAF) // Unused Flag
#define FLAG_UNUSED_0x910                           (SYSTEM_FLAGS + 0xB0) // Unused Flag
#define FLAG_UNUSED_0x911                           (SYSTEM_FLAGS + 0xB1) // Unused Flag
#define FLAG_UNUSED_0x912                           (SYSTEM_FLAGS + 0xB2) // Unused Flag
#define FLAG_UNUSED_0x913                           (SYSTEM_FLAGS + 0xB3) // Unused Flag
#define FLAG_UNUSED_0x914                           (SYSTEM_FLAGS + 0xB4) // Unused Flag
#define FLAG_UNUSED_0x915                           (SYSTEM_FLAGS + 0xB5) // Unused Flag
#define FLAG_UNUSED_0x916                           (SYSTEM_FLAGS + 0xB6) // Unused Flag
#define FLAG_UNUSED_0x917                           (SYSTEM_FLAGS + 0xB7) // Unused Flag
#define FLAG_UNUSED_0x918                           (SYSTEM_FLAGS + 0xB8) // Unused Flag
#define FLAG_UNUSED_0x919                           (SYSTEM_FLAGS + 0xB9) // Unused Flag
#define FLAG_UNUSED_0x91A                           (SYSTEM_FLAGS + 0xBA) // Unused Flag
#define FLAG_UNUSED_0x91B                           (SYSTEM_FLAGS + 0xBB) // Unused Flag
#define FLAG_UNUSED_0x91C                           (SYSTEM_FLAGS + 0xBC) // Unused Flag
#define FLAG_UNUSED_0x91D                           (SYSTEM_FLAGS + 0xBD) // Unused Flag
#define FLAG_UNUSED_0x91E                           (SYSTEM_FLAGS + 0xBE) // Unused Flag
#define FLAG_UNUSED_0x91F                           (SYSTEM_FLAGS + 0xBF) // Unused Flag

// Daily Flags
// These flags are cleared once per day
// The start and end are byte-aligned because the flags are cleared in byte increments
#define DAILY_FLAGS_START                           (FLAG_UNUSED_0x91F + (8 - FLAG_UNUSED_0x91F % 8))
#define FLAG_UNUSED_0x920                           (DAILY_FLAGS_START + 0x0)  // Unused Flag
#define FLAG_DAILY_CONTEST_LOBBY_RECEIVED_BERRY     (DAILY_FLAGS_START + 0x1)
#define FLAG_DAILY_SECRET_BASE                      (DAILY_FLAGS_START + 0x2)
#define FLAG_UNUSED_0x923                           (DAILY_FLAGS_START + 0x3)  // Unused Flag
#define FLAG_UNUSED_0x924                           (DAILY_FLAGS_START + 0x4)  // Unused Flag
#define FLAG_UNUSED_0x925                           (DAILY_FLAGS_START + 0x5)  // Unused Flag
#define FLAG_UNUSED_0x926                           (DAILY_FLAGS_START + 0x6)  // Unused Flag
#define FLAG_UNUSED_0x927                           (DAILY_FLAGS_START + 0x7)  // Unused Flag
#define FLAG_UNUSED_0x928                           (DAILY_FLAGS_START + 0x8)  // Unused Flag
#define FLAG_UNUSED_0x929                           (DAILY_FLAGS_START + 0x9)  // Unused Flag
#define FLAG_DAILY_PICKED_LOTO_TICKET               (DAILY_FLAGS_START + 0xA)
#define FLAG_DAILY_ROUTE_114_RECEIVED_BERRY         (DAILY_FLAGS_START + 0xB)
#define FLAG_DAILY_ROUTE_111_RECEIVED_BERRY         (DAILY_FLAGS_START + 0xC)
#define FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY      (DAILY_FLAGS_START + 0xD)
#define FLAG_DAILY_ROUTE_120_RECEIVED_BERRY         (DAILY_FLAGS_START + 0xE)
#define FLAG_DAILY_LILYCOVE_RECEIVED_BERRY          (DAILY_FLAGS_START + 0xF)
#define FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY       (DAILY_FLAGS_START + 0x10)
#define FLAG_DAILY_BERRY_MASTERS_WIFE               (DAILY_FLAGS_START + 0x11)
#define FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY        (DAILY_FLAGS_START + 0x12)
#define FLAG_UNUSED_0x933                           (DAILY_FLAGS_START + 0x13) // Unused Flag
#define FLAG_DAILY_APPRENTICE_LEAVES                (DAILY_FLAGS_START + 0x14)

#define FLAG_UNUSED_0x935                           (DAILY_FLAGS_START + 0x15) // Unused Flag
#define FLAG_UNUSED_0x936                           (DAILY_FLAGS_START + 0x16) // Unused Flag
#define FLAG_UNUSED_0x937                           (DAILY_FLAGS_START + 0x17) // Unused Flag
#define FLAG_UNUSED_0x938                           (DAILY_FLAGS_START + 0x18) // Unused Flag
#define FLAG_UNUSED_0x939                           (DAILY_FLAGS_START + 0x19) // Unused Flag
#define FLAG_UNUSED_0x93A                           (DAILY_FLAGS_START + 0x1A) // Unused Flag
#define FLAG_UNUSED_0x93B                           (DAILY_FLAGS_START + 0x1B) // Unused Flag
#define FLAG_UNUSED_0x93C                           (DAILY_FLAGS_START + 0x1C) // Unused Flag
#define FLAG_UNUSED_0x93D                           (DAILY_FLAGS_START + 0x1D) // Unused Flag
#define FLAG_UNUSED_0x93E                           (DAILY_FLAGS_START + 0x1E) // Unused Flag
#define FLAG_UNUSED_0x93F                           (DAILY_FLAGS_START + 0x1F) // Unused Flag
#define FLAG_UNUSED_0x940                           (DAILY_FLAGS_START + 0x20) // Unused Flag
#define FLAG_UNUSED_0x941                           (DAILY_FLAGS_START + 0x21) // Unused Flag
#define FLAG_UNUSED_0x942                           (DAILY_FLAGS_START + 0x22) // Unused Flag
#define FLAG_UNUSED_0x943                           (DAILY_FLAGS_START + 0x23) // Unused Flag
#define FLAG_UNUSED_0x944                           (DAILY_FLAGS_START + 0x24) // Unused Flag
#define FLAG_UNUSED_0x945                           (DAILY_FLAGS_START + 0x25) // Unused Flag
#define FLAG_UNUSED_0x946                           (DAILY_FLAGS_START + 0x26) // Unused Flag
#define FLAG_UNUSED_0x947                           (DAILY_FLAGS_START + 0x27) // Unused Flag
#define FLAG_UNUSED_0x948                           (DAILY_FLAGS_START + 0x28) // Unused Flag
#define FLAG_UNUSED_0x949                           (DAILY_FLAGS_START + 0x29) // Unused Flag
#define FLAG_UNUSED_0x94A                           (DAILY_FLAGS_START + 0x2A) // Unused Flag
#define FLAG_UNUSED_0x94B                           (DAILY_FLAGS_START + 0x2B) // Unused Flag
#define FLAG_UNUSED_0x94C                           (DAILY_FLAGS_START + 0x2C) // Unused Flag
#define FLAG_UNUSED_0x94D                           (DAILY_FLAGS_START + 0x2D) // Unused Flag
#define FLAG_UNUSED_0x94E                           (DAILY_FLAGS_START + 0x2E) // Unused Flag
#define FLAG_UNUSED_0x94F                           (DAILY_FLAGS_START + 0x2F) // Unused Flag
#define FLAG_UNUSED_0x950                           (DAILY_FLAGS_START + 0x30) // Unused Flag
#define FLAG_UNUSED_0x951                           (DAILY_FLAGS_START + 0x31) // Unused Flag
#define FLAG_UNUSED_0x952                           (DAILY_FLAGS_START + 0x32) // Unused Flag
#define FLAG_UNUSED_0x953                           (DAILY_FLAGS_START + 0x33) // Unused Flag
#define FLAG_UNUSED_0x954                           (DAILY_FLAGS_START + 0x34) // Unused Flag
#define FLAG_UNUSED_0x955                           (DAILY_FLAGS_START + 0x35) // Unused Flag
#define FLAG_UNUSED_0x956                           (DAILY_FLAGS_START + 0x36) // Unused Flag
#define FLAG_UNUSED_0x957                           (DAILY_FLAGS_START + 0x37) // Unused Flag
#define FLAG_UNUSED_0x958                           (DAILY_FLAGS_START + 0x38) // Unused Flag
#define FLAG_UNUSED_0x959                           (DAILY_FLAGS_START + 0x39) // Unused Flag
#define FLAG_UNUSED_0x95A                           (DAILY_FLAGS_START + 0x3A) // Unused Flag
#define FLAG_UNUSED_0x95B                           (DAILY_FLAGS_START + 0x3B) // Unused Flag
#define FLAG_UNUSED_0x95C                           (DAILY_FLAGS_START + 0x3C) // Unused Flag
#define FLAG_UNUSED_0x95D                           (DAILY_FLAGS_START + 0x3D) // Unused Flag
#define FLAG_UNUSED_0x95E                           (DAILY_FLAGS_START + 0x3E) // Unused Flag
#define FLAG_UNUSED_0x95F                           (DAILY_FLAGS_START + 0x3F) // Unused Flag
#define DAILY_FLAGS_END                             (FLAG_UNUSED_0x95F + (7 - FLAG_UNUSED_0x95F % 8))
#define NUM_DAILY_FLAGS                             (DAILY_FLAGS_END - DAILY_FLAGS_START + 1)

// Trinity: Johto pickup flags
// 320 flags reserved for Johto overworld item/hidden-item pickups, appended at the very
// end of persisted flag space (after Daily Flags). Allocated sequentially by the M4a
// Task 2 map converter — one flag per Johto pickup, in map-processing order.
#define FLAG_TRINITY_JOHTO_PICKUPS_START            (DAILY_FLAGS_END + 1)
#define FLAG_TRINITY_JOHTO_PICKUPS_END              (FLAG_TRINITY_JOHTO_PICKUPS_START + 319)
#define NUM_TRINITY_JOHTO_PICKUP_FLAGS               (FLAG_TRINITY_JOHTO_PICKUPS_END - FLAG_TRINITY_JOHTO_PICKUPS_START + 1)

// Trinity: Kanto pickup flags
// 320 flags reserved for Kanto overworld item/hidden-item pickups, appended at the very
// end of persisted flag space (after the Johto pickup block). Allocated sequentially by
// the M5a Task 10 map converter — one flag per Kanto pickup, in map-processing order.
#define FLAG_TRINITY_KANTO_PICKUPS_START            (FLAG_TRINITY_JOHTO_PICKUPS_END + 1)
#define FLAG_TRINITY_KANTO_PICKUPS_END              (FLAG_TRINITY_KANTO_PICKUPS_START + 319)
#define NUM_TRINITY_KANTO_PICKUP_FLAGS               (FLAG_TRINITY_KANTO_PICKUPS_END - FLAG_TRINITY_KANTO_PICKUPS_START + 1)

#define FLAGS_COUNT (FLAG_TRINITY_KANTO_PICKUPS_END + 1)

// Special Flags (Stored in EWRAM (sSpecialFlags), not in the SaveBlock)
#define SPECIAL_FLAGS_START                     0x4000
#define FLAG_HIDE_MAP_NAME_POPUP                (SPECIAL_FLAGS_START + 0x0)
#define FLAG_DONT_TRANSITION_MUSIC              (SPECIAL_FLAGS_START + 0x1)
#define FLAG_ENABLE_MULTI_CORRIDOR_DOOR         (SPECIAL_FLAGS_START + 0x2)
#define FLAG_SPECIAL_FLAG_UNUSED_0x4003         (SPECIAL_FLAGS_START + 0x3) // Unused Flag
#define FLAG_STORING_ITEMS_IN_PYRAMID_BAG       (SPECIAL_FLAGS_START + 0x4)
#define FLAG_SAFE_FOLLOWER_MOVEMENT             (SPECIAL_FLAGS_START + 0x5) // When set, applymovement does not put the follower inside a pokeball
                                                                            // Also, scripted movements on the player will move follower(s), too
// FLAG_SPECIAL_FLAG_0x4005 - 0x407F also exist and are unused
#define SPECIAL_FLAGS_END                       (SPECIAL_FLAGS_START + 0x7F)
#define NUM_SPECIAL_FLAGS                       (SPECIAL_FLAGS_END - SPECIAL_FLAGS_START + 1)

// Temp flag aliases
#define FLAG_TEMP_SKIP_GABBY_INTERVIEW          FLAG_TEMP_1
#define FLAG_TEMP_REGICE_PUZZLE_STARTED         FLAG_TEMP_2
#define FLAG_TEMP_REGICE_PUZZLE_FAILED          FLAG_TEMP_3
#define FLAG_TEMP_HIDE_FOLLOWER                 FLAG_TEMP_E
#define FLAG_TEMP_HIDE_MIRAGE_ISLAND_BERRY_TREE FLAG_TEMP_11

#if TESTING
#define TESTING_FLAGS_START                     0x5000
#define TESTING_FLAG_SLEEP_CLAUSE               (TESTING_FLAGS_START + 0x0)
#define TESTING_FLAG_INVERSE_BATTLE             (TESTING_FLAGS_START + 0x1)
#define TESTING_FLAG_UNUSED_2                   (TESTING_FLAGS_START + 0x2)
#define TESTING_FLAG_UNUSED_3                   (TESTING_FLAGS_START + 0x3)
#define TESTING_FLAG_UNUSED_4                   (TESTING_FLAGS_START + 0x4)
#define TESTING_FLAG_UNUSED_5                   (TESTING_FLAGS_START + 0x5)
#define TESTING_FLAG_UNUSED_6                   (TESTING_FLAGS_START + 0x6)
#define TESTING_FLAG_UNUSED_7                   (TESTING_FLAGS_START + 0x7)
#endif // TESTING

#endif // GUARD_CONSTANTS_FLAGS_H
