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
// brief). Charmap-safety: every string below uses characters already proven
// safe throughout this tree (é via the existing POKéMON convention, the em
// dash and ellipsis via the same usage already shipped in dialogue like
// PokemonLeague_ChampionsRoom_Text_Defeat's "…It's over.").
// ============================================================================

enum
{
    PAGE_TITLE,
    PAGE_DIRECTOR,
    PAGE_PROGRAMMING,
    PAGE_WORLD_DESIGN,
    PAGE_STORY,
    PAGE_TRAINERS,
    PAGE_QA,
    PAGE_CREW,
    PAGE_BUILT_ON,
    PAGE_PRODUCER,
    PAGE_EXECUTIVE,
    PAGE_CREATORS,
    PAGE_CLOSE,
    PAGE_COUNT
};

#define ENTRIES_PER_PAGE 5

static const u8 sCreditsText_EmptyString[]         = _("");
static const u8 sCreditsText_PkmnTrinityVersion[]  = _("POKéMON TRINITY");
static const u8 sCreditsText_IndigoLeague[]        = _("Indigo League");
static const u8 sCreditsText_Director[]            = _("Director");
static const u8 sCreditsText_Programming[]         = _("Programming");
static const u8 sCreditsText_WorldDesign[]         = _("World Design");
static const u8 sCreditsText_HoennJohtoKanto[]     = _("Hoenn, Johto, Kanto");
static const u8 sCreditsText_StoryAndDialogue[]    = _("Story & Dialogue");
static const u8 sCreditsText_TrainersAndBattle[]   = _("Trainers & Battle Design");
static const u8 sCreditsText_TestingVerify[]       = _("Testing & Verification");
static const u8 sCreditsText_SpecialThanks[]       = _("Special Thanks");
static const u8 sCreditsText_CrewNames1[]          = _("Harjot, Ivraj, Sumeet");
static const u8 sCreditsText_CrewNames2[]          = _("Prabhjit, Gurnav, Bobby");
static const u8 sCreditsText_CrewThanks[]          = _("for three regions of company");
static const u8 sCreditsText_BuiltWith[]           = _("Built With pokeemerald-expansion");
static const u8 sCreditsText_AndOriginal[]         = _("and the original POKéMON games");
static const u8 sCreditsText_ThanksCreators[]      = _("With thanks to their creators");
static const u8 sCreditsText_Producer[]            = _("Producer");
static const u8 sCreditsText_ExecutiveProducer[]   = _("Executive Producer");
static const u8 sCreditsText_CreatedBy[]           = _("Created by");
static const u8 sCreditsText_ClaudeAndJaspal[]     = _("Claude Code & Jaspal Singh");
static const u8 sCreditsText_ThreeRegions[]        = _("Three Regions.");
static const u8 sCreditsText_ThreeLeagues[]        = _("Three Leagues.");
static const u8 sCreditsText_OneJourney[]          = _("One Journey, Finished.");
static const u8 sCreditsText_ThankYouPlaying[]     = _("Thank you for playing.");
static const u8 sCreditsText_ClaudeCode[]          = _("Claude Code");
static const u8 sCreditsText_JaspalSingh[]         = _("Jaspal Singh");

static const struct CreditsEntry sCreditsEntry_EmptyString        = { 0, FALSE, sCreditsText_EmptyString };
static const struct CreditsEntry sCreditsEntry_PkmnTrinityVersion = { 7,  TRUE, sCreditsText_PkmnTrinityVersion };
static const struct CreditsEntry sCreditsEntry_IndigoLeague       = {11,  TRUE, sCreditsText_IndigoLeague };
static const struct CreditsEntry sCreditsEntry_Director           = {12,  TRUE, sCreditsText_Director };
static const struct CreditsEntry sCreditsEntry_Programming        = {12,  TRUE, sCreditsText_Programming };
static const struct CreditsEntry sCreditsEntry_WorldDesign        = {10,  TRUE, sCreditsText_WorldDesign };
static const struct CreditsEntry sCreditsEntry_HoennJohtoKanto    = {11, FALSE, sCreditsText_HoennJohtoKanto };
static const struct CreditsEntry sCreditsEntry_StoryAndDialogue   = {11,  TRUE, sCreditsText_StoryAndDialogue };
static const struct CreditsEntry sCreditsEntry_TrainersAndBattle  = {10,  TRUE, sCreditsText_TrainersAndBattle };
static const struct CreditsEntry sCreditsEntry_TestingVerify      = {11,  TRUE, sCreditsText_TestingVerify };
static const struct CreditsEntry sCreditsEntry_SpecialThanks      = {10,  TRUE, sCreditsText_SpecialThanks };
static const struct CreditsEntry sCreditsEntry_CrewNames1         = {11, FALSE, sCreditsText_CrewNames1 };
static const struct CreditsEntry sCreditsEntry_CrewNames2         = {11, FALSE, sCreditsText_CrewNames2 };
static const struct CreditsEntry sCreditsEntry_CrewThanks         = {11, FALSE, sCreditsText_CrewThanks };
static const struct CreditsEntry sCreditsEntry_BuiltWith          = { 6,  TRUE, sCreditsText_BuiltWith };
static const struct CreditsEntry sCreditsEntry_AndOriginal        = { 6, FALSE, sCreditsText_AndOriginal };
static const struct CreditsEntry sCreditsEntry_ThanksCreators     = {11, FALSE, sCreditsText_ThanksCreators };
static const struct CreditsEntry sCreditsEntry_Producer           = {11,  TRUE, sCreditsText_Producer };
static const struct CreditsEntry sCreditsEntry_ExecutiveProducer  = { 7,  TRUE, sCreditsText_ExecutiveProducer };
static const struct CreditsEntry sCreditsEntry_CreatedBy          = {12,  TRUE, sCreditsText_CreatedBy };
static const struct CreditsEntry sCreditsEntry_ClaudeAndJaspal    = {11, FALSE, sCreditsText_ClaudeAndJaspal };
static const struct CreditsEntry sCreditsEntry_ThreeRegions       = {12,  TRUE, sCreditsText_ThreeRegions };
static const struct CreditsEntry sCreditsEntry_ThreeLeagues       = {12,  TRUE, sCreditsText_ThreeLeagues };
static const struct CreditsEntry sCreditsEntry_OneJourney         = {12,  TRUE, sCreditsText_OneJourney };
static const struct CreditsEntry sCreditsEntry_ThankYouPlaying    = {11, FALSE, sCreditsText_ThankYouPlaying };
static const struct CreditsEntry sCreditsEntry_ClaudeCode         = {11, FALSE, sCreditsText_ClaudeCode };
static const struct CreditsEntry sCreditsEntry_JaspalSingh        = {11, FALSE, sCreditsText_JaspalSingh };

#define _ &sCreditsEntry_EmptyString
static const struct CreditsEntry *const sCreditsEntryPointerTable[PAGE_COUNT][ENTRIES_PER_PAGE] =
{
    [PAGE_TITLE] = {
        _,
        &sCreditsEntry_PkmnTrinityVersion,
        &sCreditsEntry_IndigoLeague,
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
    [PAGE_PROGRAMMING] = {
        &sCreditsEntry_Programming,
        &sCreditsEntry_ClaudeCode,
        &sCreditsEntry_JaspalSingh,
        _,
        _,
    },
    [PAGE_WORLD_DESIGN] = {
        &sCreditsEntry_WorldDesign,
        &sCreditsEntry_HoennJohtoKanto,
        &sCreditsEntry_JaspalSingh,
        &sCreditsEntry_ClaudeCode,
        _,
    },
    [PAGE_STORY] = {
        &sCreditsEntry_StoryAndDialogue,
        &sCreditsEntry_JaspalSingh,
        &sCreditsEntry_ClaudeCode,
        _,
        _,
    },
    [PAGE_TRAINERS] = {
        &sCreditsEntry_TrainersAndBattle,
        &sCreditsEntry_JaspalSingh,
        &sCreditsEntry_ClaudeCode,
        _,
        _,
    },
    [PAGE_QA] = {
        &sCreditsEntry_TestingVerify,
        &sCreditsEntry_JaspalSingh,
        &sCreditsEntry_ClaudeCode,
        _,
        _,
    },
    [PAGE_CREW] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_CrewNames1,
        &sCreditsEntry_CrewNames2,
        &sCreditsEntry_CrewThanks,
        _,
    },
    [PAGE_BUILT_ON] = {
        &sCreditsEntry_BuiltWith,
        &sCreditsEntry_AndOriginal,
        &sCreditsEntry_ThanksCreators,
        _,
        _,
    },
    [PAGE_PRODUCER] = {
        _,
        &sCreditsEntry_Producer,
        &sCreditsEntry_JaspalSingh,
        _,
        _,
    },
    [PAGE_EXECUTIVE] = {
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
    [PAGE_CLOSE] = {
        &sCreditsEntry_ThreeRegions,
        &sCreditsEntry_ThreeLeagues,
        &sCreditsEntry_OneJourney,
        _,
        &sCreditsEntry_ThankYouPlaying,
    },
};
#undef _
