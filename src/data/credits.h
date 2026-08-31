// ============================================================================
// Trinity M5b S11 -- the TRUE ending credits.
//
// This table is reachable from exactly one path in the shipped game:
// `special GameClearKanto` (src/post_battle_event_funcs.c) is the only
// caller of SetHallOfFameTrueGameClear() (src/hall_of_fame.c), whose
// one-shot latch is what makes StartCredits() choose CB2_StartCreditsSequence
// over Act I/II's silent SoftReset. GameClear()/GameClearJohto() never set
// that latch, so this table can never be reached from Act I or Act II --
// confirmed by grepping every SetMainCallback2(CB2_StartCreditsSequence)
// call site in src/ (the only other one, src/debug.c, is an unrelated
// standalone dev-menu jump). Rewriting this table's content in place is
// therefore the correct minimal-cloned-delta: no branching logic needed
// anywhere in src/credits.c's engine machinery (the struct CreditsEntry /
// sCreditsEntryPointerTable shape below is completely unchanged).
//
// The vanilla POKéMON EMERALD staff roll this file used to hold (55 pages,
// the real Game Freak/Nintendo/NOA credits) has been replaced with Trinity's
// own -- a founder decision, explicit creative license granted (M5b S11
// brief). Charmap-safe: every string below uses characters already proven
// safe throughout this tree (é via the existing POKéMON convention, the
// ellipsis via the existing usage already shipped in dialogue like
// PokemonLeague_ChampionsRoom_Text_Defeat's "…It's over.").
//
// FIX ROUND 1 (review M1) -- PAGE_COUNT was 13, which collapses
// src/credits.c's own PAGE_INTERVAL (:821, `#define PAGE_INTERVAL
// (PAGE_COUNT / 9)`) from vanilla's 6 (55/9) down to 1 (13/9): the scene
// changed on every single page, eight consecutive transitions in the first
// ~30 seconds, instead of a deliberate multi-page-per-scene pace. PAGE_COUNT
// is now 36 -- a clean multiple of 9 (36/9 = 4 exactly, no truncation risk),
// restoring a real 4-pages-per-scene schedule: page 4 changes to scene 2,
// page 8 to scene 3, … page 32 to scene 9, pages 33-36 close out scene 9.
// The extra 23 pages are genuine content -- the founder's "get creative,
// honor the scale" license, used to give the three-region, three-league
// trilogy the credits roll its own brief asked for, not padding.
// ============================================================================

enum
{
    PAGE_TITLE,
    PAGE_DIRECTOR,
    PAGE_WORLD_DESIGN_HOENN,
    PAGE_WORLD_DESIGN_JOHTO,
    PAGE_WORLD_DESIGN_KANTO,
    PAGE_MAP_DESIGN,
    PAGE_PROGRAMMING,
    PAGE_ENGINE_AND_TOOLS,
    PAGE_STORY_ACT1,
    PAGE_STORY_ACT2,
    PAGE_STORY_ACT3,
    PAGE_SCRIPT_AND_DIALOGUE,
    PAGE_TRAINER_DESIGN,
    PAGE_ELITE_FOUR_AND_CHAMPIONS,
    PAGE_LEGENDARY_ENCOUNTERS,
    PAGE_RIVALS,
    PAGE_THE_CREW,
    PAGE_BOBBY,
    PAGE_TESTING_AND_VERIFICATION,
    PAGE_MUSIC_DIRECTION,
    PAGE_BUILT_ON,
    PAGE_SPECIAL_THANKS_1,
    PAGE_SPECIAL_THANKS_2,
    PAGE_SPECIAL_THANKS_3,
    PAGE_PRODUCER,
    PAGE_EXECUTIVE_PRODUCER,
    PAGE_CREATORS,
    PAGE_HOENN_RETROSPECTIVE,
    PAGE_JOHTO_RETROSPECTIVE,
    PAGE_KANTO_RETROSPECTIVE,
    PAGE_THE_CHAMPIONS,
    PAGE_THE_BADGES,
    PAGE_MT_SILVER_TEASE,
    PAGE_THANK_YOU_PLAYING,
    PAGE_ONE_MORE_THING,
    PAGE_CLOSE,
    PAGE_COUNT
};

#define ENTRIES_PER_PAGE 5

static const u8 sCreditsText_EmptyString[]        = _("");
static const u8 sCreditsText_JaspalSingh[]        = _("Jaspal Singh");
static const u8 sCreditsText_ClaudeCode[]         = _("Claude Code");

static const u8 sCreditsText_PkmnTrinityVersion[] = _("POKéMON TRINITY");
static const u8 sCreditsText_TitleSubtitle[]      = _("Three Regions. One Journey.");

static const u8 sCreditsText_Director[]           = _("Director");

static const u8 sCreditsText_WorldDesign[]        = _("World Design");
static const u8 sCreditsText_Hoenn[]              = _("Hoenn");
static const u8 sCreditsText_Johto[]              = _("Johto");
static const u8 sCreditsText_Kanto[]              = _("Kanto");

static const u8 sCreditsText_MapAndRegionDesign[] = _("Map & Region Design");
static const u8 sCreditsText_Programming[]        = _("Programming");
static const u8 sCreditsText_EngineAndTools[]     = _("Engine & Verification Tools");

static const u8 sCreditsText_Story[]              = _("Story");
static const u8 sCreditsText_ActIHoenn[]          = _("Act I -- Hoenn");
static const u8 sCreditsText_ActIIJohto[]         = _("Act II -- Johto");
static const u8 sCreditsText_ActIIIKanto[]        = _("Act III -- Kanto");

static const u8 sCreditsText_ScriptAndDialogue[]  = _("Script & Dialogue");
static const u8 sCreditsText_TrainerAndBattle[]   = _("Trainer & Battle Design");
static const u8 sCreditsText_E4AndChampionDsgn[]  = _("Elite Four & Champion Design");
static const u8 sCreditsText_LegendaryEnctrs[]    = _("Legendary Encounters");
static const u8 sCreditsText_RivalDesign[]        = _("Rival Design");

static const u8 sCreditsText_SpecialThanks[]      = _("Special Thanks");
static const u8 sCreditsText_CrewNames1[]         = _("Harjot, Ivraj, Sumeet");
static const u8 sCreditsText_CrewNames2[]         = _("Prabhjit, Gurnav, Bobby");
static const u8 sCreditsText_CrewThanks[]         = _("for three regions of company");
static const u8 sCreditsText_BobbyName[]          = _("Bobby");
static const u8 sCreditsText_BobbyThanks[]        = _("for hosting, and for waiting");

static const u8 sCreditsText_TestingVerify[]      = _("Testing & Verification");
static const u8 sCreditsText_MusicDirection[]     = _("Music Direction");

static const u8 sCreditsText_BuiltWith[]          = _("Built With pokeemerald-expansion");
static const u8 sCreditsText_AndOriginal[]        = _("and the original POKéMON games");
static const u8 sCreditsText_ThanksCreators[]     = _("With thanks to their creators");

static const u8 sCreditsText_ThanksTrainers1[]    = _("Every trainer who picked up");
static const u8 sCreditsText_ThanksTrainers2[]    = _("a starter and kept going");
static const u8 sCreditsText_ThanksLeaders1[]     = _("The leaders of Hoenn, Johto");
static const u8 sCreditsText_ThanksLeaders2[]     = _("and Kanto -- twenty-four gyms");
static const u8 sCreditsText_ThanksLeaders3[]      = _("twenty-four battles remembered");
static const u8 sCreditsText_ThanksLegendary1[]   = _("Every legendary that flew,");
static const u8 sCreditsText_ThanksLegendary2[]   = _("swam, or slept until you found it");

static const u8 sCreditsText_Producer[]           = _("Producer");
static const u8 sCreditsText_ExecutiveProducer[]  = _("Executive Producer");
static const u8 sCreditsText_CreatedBy[]          = _("Created by");
static const u8 sCreditsText_ClaudeAndJaspal[]    = _("Claude Code & Jaspal Singh");

static const u8 sCreditsText_WhereItStarted[]     = _("Where it started");
static const u8 sCreditsText_WhereItContinued[]   = _("Where it continued");
static const u8 sCreditsText_WhereItFinished[]    = _("Where it finished");

static const u8 sCreditsText_TheChampions[]       = _("The Champions");
// FIX ROUND 2 (re-review NEW-1): was "Steven, Lance, Ash" -- Trinity's Act I
// Champion is WALLACE, not Steven. data/maps/EverGrandeCity_ChampionsRoom/
// scripts.inc:43 `trainerbattle_no_intro TRAINER_WALLACE, ...` is the only
// Act I champion battle; Steven is the optional, skippable MeteorFalls_
// StevensCave post-game fight, never a Champion the player dethrones (which
// also falsified "beat them all"). src/pokemon.c's own champion-theme
// comment already had this right ("MUS_VS_CHAMPION above by WALLACE/Act I").
static const u8 sCreditsText_WallaceLanceAsh[]    = _("Wallace, Lance, Ash");
static const u8 sCreditsText_AndTheTrainer[]      = _("and the trainer who beat them all");

static const u8 sCreditsText_TwentyFourBadges[]   = _("Twenty-Four Badges");
static const u8 sCreditsText_OneTrainer[]         = _("One Trainer");

static const u8 sCreditsText_SomewhereNorth[]     = _("Somewhere north of here");
static const u8 sCreditsText_MountainWaiting[]    = _("a mountain is still waiting");

static const u8 sCreditsText_HoweverFar[]         = _("However far you got");
static const u8 sCreditsText_ThanksForComing[]    = _("thank you for coming this far");

static const u8 sCreditsText_ThisHasBeen[]        = _("This has been");

static const u8 sCreditsText_ThreeRegions[]       = _("Three Regions.");
static const u8 sCreditsText_ThreeLeagues[]       = _("Three Leagues.");
static const u8 sCreditsText_OneJourney[]         = _("One Journey, Finished.");
static const u8 sCreditsText_ThankYouPlaying[]    = _("Thank you for playing.");

static const struct CreditsEntry sCreditsEntry_EmptyString        = { 0, FALSE, sCreditsText_EmptyString };
static const struct CreditsEntry sCreditsEntry_JaspalSingh        = {11, FALSE, sCreditsText_JaspalSingh };
static const struct CreditsEntry sCreditsEntry_ClaudeCode         = {11, FALSE, sCreditsText_ClaudeCode };

static const struct CreditsEntry sCreditsEntry_PkmnTrinityVersion = { 7,  TRUE, sCreditsText_PkmnTrinityVersion };
static const struct CreditsEntry sCreditsEntry_TitleSubtitle      = {11, FALSE, sCreditsText_TitleSubtitle };

static const struct CreditsEntry sCreditsEntry_Director           = {12,  TRUE, sCreditsText_Director };

static const struct CreditsEntry sCreditsEntry_WorldDesign        = {10,  TRUE, sCreditsText_WorldDesign };
static const struct CreditsEntry sCreditsEntry_Hoenn              = {11, FALSE, sCreditsText_Hoenn };
static const struct CreditsEntry sCreditsEntry_Johto              = {11, FALSE, sCreditsText_Johto };
static const struct CreditsEntry sCreditsEntry_Kanto              = {11, FALSE, sCreditsText_Kanto };

static const struct CreditsEntry sCreditsEntry_MapAndRegionDesign = {10,  TRUE, sCreditsText_MapAndRegionDesign };
static const struct CreditsEntry sCreditsEntry_Programming        = {12,  TRUE, sCreditsText_Programming };
static const struct CreditsEntry sCreditsEntry_EngineAndTools     = { 6,  TRUE, sCreditsText_EngineAndTools };

static const struct CreditsEntry sCreditsEntry_Story              = {13,  TRUE, sCreditsText_Story };
static const struct CreditsEntry sCreditsEntry_ActIHoenn          = {11, FALSE, sCreditsText_ActIHoenn };
static const struct CreditsEntry sCreditsEntry_ActIIJohto         = {11, FALSE, sCreditsText_ActIIJohto };
static const struct CreditsEntry sCreditsEntry_ActIIIKanto        = {11, FALSE, sCreditsText_ActIIIKanto };

static const struct CreditsEntry sCreditsEntry_ScriptAndDialogue  = {11,  TRUE, sCreditsText_ScriptAndDialogue };
static const struct CreditsEntry sCreditsEntry_TrainerAndBattle   = {10,  TRUE, sCreditsText_TrainerAndBattle };
static const struct CreditsEntry sCreditsEntry_E4AndChampionDsgn  = {10,  TRUE, sCreditsText_E4AndChampionDsgn };
static const struct CreditsEntry sCreditsEntry_LegendaryEnctrs    = {13,  TRUE, sCreditsText_LegendaryEnctrs };
static const struct CreditsEntry sCreditsEntry_RivalDesign        = {10,  TRUE, sCreditsText_RivalDesign };

static const struct CreditsEntry sCreditsEntry_SpecialThanks      = {10,  TRUE, sCreditsText_SpecialThanks };
static const struct CreditsEntry sCreditsEntry_CrewNames1         = {11, FALSE, sCreditsText_CrewNames1 };
static const struct CreditsEntry sCreditsEntry_CrewNames2         = {11, FALSE, sCreditsText_CrewNames2 };
static const struct CreditsEntry sCreditsEntry_CrewThanks         = {11, FALSE, sCreditsText_CrewThanks };
static const struct CreditsEntry sCreditsEntry_BobbyName          = {11, FALSE, sCreditsText_BobbyName };
static const struct CreditsEntry sCreditsEntry_BobbyThanks        = {11, FALSE, sCreditsText_BobbyThanks };

static const struct CreditsEntry sCreditsEntry_TestingVerify      = {11,  TRUE, sCreditsText_TestingVerify };
static const struct CreditsEntry sCreditsEntry_MusicDirection     = {13,  TRUE, sCreditsText_MusicDirection };

static const struct CreditsEntry sCreditsEntry_BuiltWith          = { 6,  TRUE, sCreditsText_BuiltWith };
static const struct CreditsEntry sCreditsEntry_AndOriginal        = { 6, FALSE, sCreditsText_AndOriginal };
static const struct CreditsEntry sCreditsEntry_ThanksCreators     = {11, FALSE, sCreditsText_ThanksCreators };

static const struct CreditsEntry sCreditsEntry_ThanksTrainers1    = {11, FALSE, sCreditsText_ThanksTrainers1 };
static const struct CreditsEntry sCreditsEntry_ThanksTrainers2    = {11, FALSE, sCreditsText_ThanksTrainers2 };
static const struct CreditsEntry sCreditsEntry_ThanksLeaders1     = {11, FALSE, sCreditsText_ThanksLeaders1 };
static const struct CreditsEntry sCreditsEntry_ThanksLeaders2     = {11, FALSE, sCreditsText_ThanksLeaders2 };
static const struct CreditsEntry sCreditsEntry_ThanksLeaders3     = {11, FALSE, sCreditsText_ThanksLeaders3 };
static const struct CreditsEntry sCreditsEntry_ThanksLegendary1   = {11, FALSE, sCreditsText_ThanksLegendary1 };
static const struct CreditsEntry sCreditsEntry_ThanksLegendary2   = {11, FALSE, sCreditsText_ThanksLegendary2 };

static const struct CreditsEntry sCreditsEntry_Producer           = {11,  TRUE, sCreditsText_Producer };
static const struct CreditsEntry sCreditsEntry_ExecutiveProducer  = { 7,  TRUE, sCreditsText_ExecutiveProducer };
static const struct CreditsEntry sCreditsEntry_CreatedBy          = {12,  TRUE, sCreditsText_CreatedBy };
static const struct CreditsEntry sCreditsEntry_ClaudeAndJaspal    = {11, FALSE, sCreditsText_ClaudeAndJaspal };

static const struct CreditsEntry sCreditsEntry_WhereItStarted     = {11, FALSE, sCreditsText_WhereItStarted };
static const struct CreditsEntry sCreditsEntry_WhereItContinued   = {11, FALSE, sCreditsText_WhereItContinued };
static const struct CreditsEntry sCreditsEntry_WhereItFinished    = {11, FALSE, sCreditsText_WhereItFinished };

static const struct CreditsEntry sCreditsEntry_TheChampions       = {10,  TRUE, sCreditsText_TheChampions };
static const struct CreditsEntry sCreditsEntry_WallaceLanceAsh    = {11, FALSE, sCreditsText_WallaceLanceAsh };
static const struct CreditsEntry sCreditsEntry_AndTheTrainer      = {11, FALSE, sCreditsText_AndTheTrainer };

static const struct CreditsEntry sCreditsEntry_TwentyFourBadges   = {12,  TRUE, sCreditsText_TwentyFourBadges };
static const struct CreditsEntry sCreditsEntry_OneTrainer         = {12,  TRUE, sCreditsText_OneTrainer };

static const struct CreditsEntry sCreditsEntry_SomewhereNorth     = {11, FALSE, sCreditsText_SomewhereNorth };
static const struct CreditsEntry sCreditsEntry_MountainWaiting    = {11, FALSE, sCreditsText_MountainWaiting };

static const struct CreditsEntry sCreditsEntry_HoweverFar         = {11, FALSE, sCreditsText_HoweverFar };
static const struct CreditsEntry sCreditsEntry_ThanksForComing    = {11, FALSE, sCreditsText_ThanksForComing };

static const struct CreditsEntry sCreditsEntry_ThisHasBeen        = {11, FALSE, sCreditsText_ThisHasBeen };
static const struct CreditsEntry sCreditsEntry_PkmnTrinityAgain   = { 7,  TRUE, sCreditsText_PkmnTrinityVersion };

static const struct CreditsEntry sCreditsEntry_ThreeRegions       = {12,  TRUE, sCreditsText_ThreeRegions };
static const struct CreditsEntry sCreditsEntry_ThreeLeagues       = {12,  TRUE, sCreditsText_ThreeLeagues };
static const struct CreditsEntry sCreditsEntry_OneJourney         = {12,  TRUE, sCreditsText_OneJourney };
static const struct CreditsEntry sCreditsEntry_ThankYouPlaying    = {11, FALSE, sCreditsText_ThankYouPlaying };

#define _ &sCreditsEntry_EmptyString
static const struct CreditsEntry *const sCreditsEntryPointerTable[PAGE_COUNT][ENTRIES_PER_PAGE] =
{
    // --- scene 1 (pages 1-4) ---
    [PAGE_TITLE] = {
        _,
        &sCreditsEntry_PkmnTrinityVersion,
        &sCreditsEntry_TitleSubtitle,
        _,
        _,
    },
    [PAGE_DIRECTOR] = {
        _,
        &sCreditsEntry_Director,
        &sCreditsEntry_JaspalSingh,
        _,
        _,
    },
    [PAGE_WORLD_DESIGN_HOENN] = {
        &sCreditsEntry_WorldDesign,
        &sCreditsEntry_Hoenn,
        &sCreditsEntry_JaspalSingh,
        &sCreditsEntry_ClaudeCode,
        _,
    },
    [PAGE_WORLD_DESIGN_JOHTO] = {
        &sCreditsEntry_WorldDesign,
        &sCreditsEntry_Johto,
        &sCreditsEntry_JaspalSingh,
        &sCreditsEntry_ClaudeCode,
        _,
    },

    // --- scene 2 (pages 5-8) ---
    [PAGE_WORLD_DESIGN_KANTO] = {
        &sCreditsEntry_WorldDesign,
        &sCreditsEntry_Kanto,
        &sCreditsEntry_JaspalSingh,
        &sCreditsEntry_ClaudeCode,
        _,
    },
    [PAGE_MAP_DESIGN] = {
        &sCreditsEntry_MapAndRegionDesign,
        &sCreditsEntry_JaspalSingh,
        &sCreditsEntry_ClaudeCode,
        _,
        _,
    },
    [PAGE_PROGRAMMING] = {
        &sCreditsEntry_Programming,
        &sCreditsEntry_ClaudeCode,
        &sCreditsEntry_JaspalSingh,
        _,
        _,
    },
    [PAGE_ENGINE_AND_TOOLS] = {
        _,
        &sCreditsEntry_EngineAndTools,
        &sCreditsEntry_ClaudeCode,
        &sCreditsEntry_JaspalSingh,
        _,
    },

    // --- scene 3 (pages 9-12) ---
    [PAGE_STORY_ACT1] = {
        &sCreditsEntry_Story,
        &sCreditsEntry_ActIHoenn,
        &sCreditsEntry_JaspalSingh,
        &sCreditsEntry_ClaudeCode,
        _,
    },
    [PAGE_STORY_ACT2] = {
        &sCreditsEntry_Story,
        &sCreditsEntry_ActIIJohto,
        &sCreditsEntry_JaspalSingh,
        &sCreditsEntry_ClaudeCode,
        _,
    },
    [PAGE_STORY_ACT3] = {
        &sCreditsEntry_Story,
        &sCreditsEntry_ActIIIKanto,
        &sCreditsEntry_JaspalSingh,
        &sCreditsEntry_ClaudeCode,
        _,
    },
    [PAGE_SCRIPT_AND_DIALOGUE] = {
        &sCreditsEntry_ScriptAndDialogue,
        &sCreditsEntry_JaspalSingh,
        &sCreditsEntry_ClaudeCode,
        _,
        _,
    },

    // --- scene 4 (pages 13-16) ---
    [PAGE_TRAINER_DESIGN] = {
        &sCreditsEntry_TrainerAndBattle,
        &sCreditsEntry_JaspalSingh,
        &sCreditsEntry_ClaudeCode,
        _,
        _,
    },
    [PAGE_ELITE_FOUR_AND_CHAMPIONS] = {
        &sCreditsEntry_E4AndChampionDsgn,
        &sCreditsEntry_JaspalSingh,
        &sCreditsEntry_ClaudeCode,
        _,
        _,
    },
    [PAGE_LEGENDARY_ENCOUNTERS] = {
        &sCreditsEntry_LegendaryEnctrs,
        &sCreditsEntry_JaspalSingh,
        &sCreditsEntry_ClaudeCode,
        _,
        _,
    },
    [PAGE_RIVALS] = {
        &sCreditsEntry_RivalDesign,
        &sCreditsEntry_JaspalSingh,
        &sCreditsEntry_ClaudeCode,
        _,
        _,
    },

    // --- scene 5 (pages 17-20) ---
    [PAGE_THE_CREW] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_CrewNames1,
        &sCreditsEntry_CrewNames2,
        &sCreditsEntry_CrewThanks,
        _,
    },
    [PAGE_BOBBY] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_BobbyName,
        &sCreditsEntry_BobbyThanks,
        _,
        _,
    },
    [PAGE_TESTING_AND_VERIFICATION] = {
        &sCreditsEntry_TestingVerify,
        &sCreditsEntry_JaspalSingh,
        &sCreditsEntry_ClaudeCode,
        _,
        _,
    },
    [PAGE_MUSIC_DIRECTION] = {
        &sCreditsEntry_MusicDirection,
        &sCreditsEntry_JaspalSingh,
        &sCreditsEntry_ClaudeCode,
        _,
        _,
    },

    // --- scene 6 (pages 21-24) ---
    [PAGE_BUILT_ON] = {
        &sCreditsEntry_BuiltWith,
        &sCreditsEntry_AndOriginal,
        &sCreditsEntry_ThanksCreators,
        _,
        _,
    },
    [PAGE_SPECIAL_THANKS_1] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_ThanksTrainers1,
        &sCreditsEntry_ThanksTrainers2,
        _,
        _,
    },
    [PAGE_SPECIAL_THANKS_2] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_ThanksLeaders1,
        &sCreditsEntry_ThanksLeaders2,
        &sCreditsEntry_ThanksLeaders3,
        _,
    },
    [PAGE_SPECIAL_THANKS_3] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_ThanksLegendary1,
        &sCreditsEntry_ThanksLegendary2,
        _,
        _,
    },

    // --- scene 7 (pages 25-28) ---
    [PAGE_PRODUCER] = {
        _,
        &sCreditsEntry_Producer,
        &sCreditsEntry_JaspalSingh,
        _,
        _,
    },
    [PAGE_EXECUTIVE_PRODUCER] = {
        _,
        &sCreditsEntry_ExecutiveProducer,
        &sCreditsEntry_JaspalSingh,
        _,
        _,
    },
    [PAGE_CREATORS] = {
        _,
        &sCreditsEntry_CreatedBy,
        &sCreditsEntry_ClaudeAndJaspal,
        _,
        _,
    },
    [PAGE_HOENN_RETROSPECTIVE] = {
        &sCreditsEntry_Hoenn,
        &sCreditsEntry_WhereItStarted,
        _,
        _,
        _,
    },

    // --- scene 8 (pages 29-32) ---
    [PAGE_JOHTO_RETROSPECTIVE] = {
        &sCreditsEntry_Johto,
        &sCreditsEntry_WhereItContinued,
        _,
        _,
        _,
    },
    [PAGE_KANTO_RETROSPECTIVE] = {
        &sCreditsEntry_Kanto,
        &sCreditsEntry_WhereItFinished,
        _,
        _,
        _,
    },
    [PAGE_THE_CHAMPIONS] = {
        &sCreditsEntry_TheChampions,
        &sCreditsEntry_WallaceLanceAsh,
        &sCreditsEntry_AndTheTrainer,
        _,
        _,
    },
    [PAGE_THE_BADGES] = {
        _,
        &sCreditsEntry_TwentyFourBadges,
        &sCreditsEntry_OneTrainer,
        _,
        _,
    },

    // --- scene 9 (pages 33-36) ---
    [PAGE_MT_SILVER_TEASE] = {
        _,
        &sCreditsEntry_SomewhereNorth,
        &sCreditsEntry_MountainWaiting,
        _,
        _,
    },
    [PAGE_THANK_YOU_PLAYING] = {
        _,
        &sCreditsEntry_HoweverFar,
        &sCreditsEntry_ThanksForComing,
        _,
        _,
    },
    [PAGE_ONE_MORE_THING] = {
        _,
        &sCreditsEntry_ThisHasBeen,
        &sCreditsEntry_PkmnTrinityAgain,
        _,
        _,
    },
    [PAGE_CLOSE] = {
        &sCreditsEntry_ThreeRegions,
        &sCreditsEntry_ThreeLeagues,
        &sCreditsEntry_OneJourney,
        _,
        &sCreditsEntry_ThankYouPlaying,
    },
};
#undef _
