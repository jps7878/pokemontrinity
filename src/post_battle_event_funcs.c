#include "global.h"
#include "main.h"
#include "credits.h"
#include "event_data.h"
#include "hall_of_fame.h"
#include "load_save.h"
#include "overworld.h"
#include "save_location.h"
#include "script_pokemon_util.h"
#include "tv.h"
#include "constants/heal_locations.h"

int GameClear(void)
{
    int i;
    bool32 ribbonGet;
    struct RibbonCounter {
        u8 partyIndex;
        u8 count;
    } ribbonCounts[6];

    HealPlayerParty();

    if (FlagGet(FLAG_SYS_GAME_CLEAR) == TRUE)
    {
        gHasHallOfFameRecords = TRUE;
    }
    else
    {
        gHasHallOfFameRecords = FALSE;
        FlagSet(FLAG_SYS_GAME_CLEAR);
    }

    if (GetGameStat(GAME_STAT_FIRST_HOF_PLAY_TIME) == 0)
        SetGameStat(GAME_STAT_FIRST_HOF_PLAY_TIME, (gSaveBlock2Ptr->playTimeHours << 16) | (gSaveBlock2Ptr->playTimeMinutes << 8) | gSaveBlock2Ptr->playTimeSeconds);

    SetContinueGameWarpStatus();

    if (gSaveBlock2Ptr->playerGender == MALE)
        SetContinueGameWarpToHealLocation(HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F);
    else
        SetContinueGameWarpToHealLocation(HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F);

    ribbonGet = FALSE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];

        ribbonCounts[i].partyIndex = i;
        ribbonCounts[i].count = 0;

        if (GetMonData(mon, MON_DATA_SANITY_HAS_SPECIES)
         && !GetMonData(mon, MON_DATA_SANITY_IS_EGG)
         && !GetMonData(mon, MON_DATA_CHAMPION_RIBBON))
        {
            u8 val[1] = {TRUE};
            SetMonData(mon, MON_DATA_CHAMPION_RIBBON, val);
            ribbonCounts[i].count = GetRibbonCount(mon);
            ribbonGet = TRUE;
        }
    }

    if (ribbonGet == TRUE)
    {
        IncrementGameStat(GAME_STAT_RECEIVED_RIBBONS);
        FlagSet(FLAG_SYS_RIBBON_GET);

        for (i = 1; i < 6; i++)
        {
            if (ribbonCounts[i].count > ribbonCounts[0].count)
            {
                struct RibbonCounter prevBest = ribbonCounts[0];
                ribbonCounts[0] = ribbonCounts[i];
                ribbonCounts[i] = prevBest;
            }
        }

        if (ribbonCounts[0].count > NUM_CUTIES_RIBBONS)
        {
            TryPutSpotTheCutiesOnAir(&gPlayerParty[ribbonCounts[0].partyIndex], MON_DATA_CHAMPION_RIBBON);
        }
    }

    SetMainCallback2(CB2_DoHallOfFameScreen);
    return 0;
}

// ============================================================================
// Trinity M5a Task 6 -- GameClearJohto / GameClearKanto.
//
// Both are minimal clones of GameClear() above with exactly one shared delta
// (the continue-game-warp target, since both leagues live at Indigo Plateau,
// not a Hoenn bedroom -- see data/maps/PokemonLeague_HallOfFame/scripts.inc
// for the full reasoning this closes out) and, for GameClearKanto only, two
// further additions. Everything else -- HealPlayerParty(), the FLAG_SYS_
// GAME_CLEAR check (already TRUE from Act I, so its semantics are untouched),
// the guarded GAME_STAT_FIRST_HOF_PLAY_TIME stamp, the champion-ribbon award
// loop, and the CB2_DoHallOfFameScreen handoff that IS the genuine PC-record
// append -- is cloned verbatim. Neither function touches any of Act I's
// EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags bookkeeping (Southern
// Island, Mr. Briney, the Beldum, the S.S. Ticket, Steven's house, the Hoenn
// Elite Four reset) -- that script is never called from here.
// ============================================================================

int GameClearJohto(void)
{
    int i;
    bool32 ribbonGet;
    struct RibbonCounter {
        u8 partyIndex;
        u8 count;
    } ribbonCounts[6];

    HealPlayerParty();

    if (FlagGet(FLAG_SYS_GAME_CLEAR) == TRUE)
    {
        gHasHallOfFameRecords = TRUE;
    }
    else
    {
        gHasHallOfFameRecords = FALSE;
        FlagSet(FLAG_SYS_GAME_CLEAR);
    }

    if (GetGameStat(GAME_STAT_FIRST_HOF_PLAY_TIME) == 0)
        SetGameStat(GAME_STAT_FIRST_HOF_PLAY_TIME, (gSaveBlock2Ptr->playTimeHours << 16) | (gSaveBlock2Ptr->playTimeMinutes << 8) | gSaveBlock2Ptr->playTimeSeconds);

    SetContinueGameWarpStatus();

    // Trinity delta (the only one in this function): both the Johto and Kanto
    // Leagues live at Indigo Plateau, so there is no gender-based house to pick
    // between -- one unconditional target replaces vanilla's two-branch call.
    SetContinueGameWarpToHealLocation(HEAL_LOCATION_INDIGO_PLATEAU);

    ribbonGet = FALSE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];

        ribbonCounts[i].partyIndex = i;
        ribbonCounts[i].count = 0;

        if (GetMonData(mon, MON_DATA_SANITY_HAS_SPECIES)
         && !GetMonData(mon, MON_DATA_SANITY_IS_EGG)
         && !GetMonData(mon, MON_DATA_CHAMPION_RIBBON))
        {
            u8 val[1] = {TRUE};
            SetMonData(mon, MON_DATA_CHAMPION_RIBBON, val);
            ribbonCounts[i].count = GetRibbonCount(mon);
            ribbonGet = TRUE;
        }
    }

    if (ribbonGet == TRUE)
    {
        IncrementGameStat(GAME_STAT_RECEIVED_RIBBONS);
        FlagSet(FLAG_SYS_RIBBON_GET);

        for (i = 1; i < 6; i++)
        {
            if (ribbonCounts[i].count > ribbonCounts[0].count)
            {
                struct RibbonCounter prevBest = ribbonCounts[0];
                ribbonCounts[0] = ribbonCounts[i];
                ribbonCounts[i] = prevBest;
            }
        }

        if (ribbonCounts[0].count > NUM_CUTIES_RIBBONS)
        {
            TryPutSpotTheCutiesOnAir(&gPlayerParty[ribbonCounts[0].partyIndex], MON_DATA_CHAMPION_RIBBON);
        }
    }

    // No credits, no additional game-clear state -- Act III (Kanto) is still to
    // come. This handoff is identical to GameClear()'s: CB2_DoHallOfFameScreen
    // performs the actual PC-record append (src/hall_of_fame.c:483-513) and,
    // on exit, StartCredits() (src/hall_of_fame.c) sees no true-game-clear
    // signal and falls back to the same silent SoftReset Act I already uses.
    SetMainCallback2(CB2_DoHallOfFameScreen);
    return 0;
}

int GameClearKanto(void)
{
    int i;
    bool32 ribbonGet;
    struct RibbonCounter {
        u8 partyIndex;
        u8 count;
    } ribbonCounts[6];

    HealPlayerParty();

    if (FlagGet(FLAG_SYS_GAME_CLEAR) == TRUE)
    {
        gHasHallOfFameRecords = TRUE;
    }
    else
    {
        gHasHallOfFameRecords = FALSE;
        FlagSet(FLAG_SYS_GAME_CLEAR);
    }

    if (GetGameStat(GAME_STAT_FIRST_HOF_PLAY_TIME) == 0)
        SetGameStat(GAME_STAT_FIRST_HOF_PLAY_TIME, (gSaveBlock2Ptr->playTimeHours << 16) | (gSaveBlock2Ptr->playTimeMinutes << 8) | gSaveBlock2Ptr->playTimeSeconds);

    SetContinueGameWarpStatus();

    // Same delta as GameClearJohto: Indigo Plateau, no gender branch.
    SetContinueGameWarpToHealLocation(HEAL_LOCATION_INDIGO_PLATEAU);

    ribbonGet = FALSE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gPlayerParty[i];

        ribbonCounts[i].partyIndex = i;
        ribbonCounts[i].count = 0;

        if (GetMonData(mon, MON_DATA_SANITY_HAS_SPECIES)
         && !GetMonData(mon, MON_DATA_SANITY_IS_EGG)
         && !GetMonData(mon, MON_DATA_CHAMPION_RIBBON))
        {
            u8 val[1] = {TRUE};
            SetMonData(mon, MON_DATA_CHAMPION_RIBBON, val);
            ribbonCounts[i].count = GetRibbonCount(mon);
            ribbonGet = TRUE;
        }
    }

    if (ribbonGet == TRUE)
    {
        IncrementGameStat(GAME_STAT_RECEIVED_RIBBONS);
        FlagSet(FLAG_SYS_RIBBON_GET);

        for (i = 1; i < 6; i++)
        {
            if (ribbonCounts[i].count > ribbonCounts[0].count)
            {
                struct RibbonCounter prevBest = ribbonCounts[0];
                ribbonCounts[0] = ribbonCounts[i];
                ribbonCounts[i] = prevBest;
            }
        }

        if (ribbonCounts[0].count > NUM_CUTIES_RIBBONS)
        {
            TryPutSpotTheCutiesOnAir(&gPlayerParty[ribbonCounts[0].partyIndex], MON_DATA_CHAMPION_RIBBON);
        }
    }

    // Trinity: the only two lines of EverGrandeCity_HallOfFame_EventScript_
    // SetGameClearFlags (data/scripts/hall_of_fame.inc:1-3) that are genuine
    // "you are a League Champion" engine semantics rather than Hoenn-region
    // post-game world state. Both are idempotent (Act I's Hoenn ceremony
    // already set them) -- restating them here is what makes Kanto's ending
    // the TRUE game-clear rather than a re-run of Act I's Hoenn bookkeeping,
    // which is never called from here:
    //   - SetChampionSaveWarp() sets specialSaveWarpFlags |= CHAMPION_SAVEWARP
    //     (src/save_location.c:136), consumed by the GCN link/Union Room
    //     save-warp system (src/union_room.c:1271) -- not Hoenn map state.
    //   - FLAG_IS_CHAMPION gates national link-cable compatibility
    //     (src/link.c:323, src/link_rfu_3.c:679) and gen-3 EV/level caps
    //     (src/caps.c) -- "seems to be related to linking"
    //     (include/constants/flags.h:1427), not a Hoenn flag.
    SetChampionSaveWarp();
    FlagSet(FLAG_IS_CHAMPION);

    // Trinity: this is the true ending. Tell StartCredits() (src/hall_of_fame.c)
    // to roll the real credits (CB2_StartCreditsSequence) once the Hall of Fame
    // PC-append screen this hands off to finishes, instead of the Act I/II
    // silent SoftReset. See that function for exactly what happens next --
    // CB2_StartCreditsSequence itself ends in a SoftReset once the credits
    // finish, so this special never returns to its caller; Continue lands the
    // player at the continue-warp set above (Indigo Plateau).
    SetHallOfFameTrueGameClear();

    SetMainCallback2(CB2_DoHallOfFameScreen);
    return 0;
}

bool8 SetCB2WhiteOut(void)
{
    SetMainCallback2(CB2_WhiteOut);
    return FALSE;
}
