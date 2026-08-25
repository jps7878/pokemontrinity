#ifndef GUARD_HALL_OF_FAME_H
#define GUARD_HALL_OF_FAME_H

struct HallofFameMon
{
    u32 tid;
    u32 personality;
    u16 isShiny:1;
    u16 species:15;
    u8 lvl;
    u8 nickname[POKEMON_NAME_LENGTH];
};

struct HallofFameTeam
{
    struct HallofFameMon mon[PARTY_SIZE];
};

extern struct HallofFameTeam *gHoFSaveBuffer;

void CB2_DoHallOfFameScreen(void);
void CB2_DoHallOfFameScreenDontSaveData(void);
void CB2_DoHallOfFamePC(void);

// Trinity: called by GameClearKanto (src/post_battle_event_funcs.c) before
// handing off to CB2_DoHallOfFameScreen. Tells the HoF screen's exit path
// (StartCredits() in src/hall_of_fame.c) that this is the true final-region
// game clear, so it should roll the real ending credits instead of the
// Act I/II silent SoftReset.
void SetHallOfFameTrueGameClear(void);

// hof_pc.c
void ReturnFromHallOfFamePC(void);

#endif // GUARD_HALL_OF_FAME_H
