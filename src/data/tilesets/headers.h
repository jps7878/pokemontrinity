#include "fieldmap.h"

// Whether a palette has a night version, located at ((x + 9) % 16).pal
#define SWAP_PAL(x) ((x) < NUM_PALS_IN_PRIMARY ? 1 << (x) : 1 << ((x) - NUM_PALS_IN_PRIMARY))

const struct Tileset gTileset_General =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_General,
    .palettes = gTilesetPalettes_General,
    .metatiles = gMetatiles_General,
    .metatileAttributes = gMetatileAttributes_General,
    .callback = InitTilesetAnim_General,
};

// M2 Kanto port (from pokefirered). callback = NULL: tile animation not ported.
const struct Tileset gTileset_GeneralKanto =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_GeneralKanto,
    .palettes = gTilesetPalettes_GeneralKanto,
    .metatiles = gMetatiles_GeneralKanto,
    .metatileAttributes = gMetatileAttributes_GeneralKanto,
    .callback = NULL,
};

const struct Tileset gTileset_PalletTownKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PalletTownKanto,
    .palettes = gTilesetPalettes_PalletTownKanto,
    .metatiles = gMetatiles_PalletTownKanto,
    .metatileAttributes = gMetatileAttributes_PalletTownKanto,
    .callback = NULL,
};

const struct Tileset gTileset_Petalburg =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Petalburg,
    .palettes = gTilesetPalettes_Petalburg,
    .metatiles = gMetatiles_Petalburg,
    .metatileAttributes = gMetatileAttributes_Petalburg,
    .callback = InitTilesetAnim_Petalburg,
};

const struct Tileset gTileset_Rustboro =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Rustboro,
    .palettes = gTilesetPalettes_Rustboro,
    .metatiles = gMetatiles_Rustboro,
    .metatileAttributes = gMetatileAttributes_Rustboro,
    .callback = InitTilesetAnim_Rustboro,
};

const struct Tileset gTileset_Dewford =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Dewford,
    .palettes = gTilesetPalettes_Dewford,
    .metatiles = gMetatiles_Dewford,
    .metatileAttributes = gMetatileAttributes_Dewford,
    .callback = InitTilesetAnim_Dewford,
};

const struct Tileset gTileset_Slateport =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Slateport,
    .palettes = gTilesetPalettes_Slateport,
    .metatiles = gMetatiles_Slateport,
    .metatileAttributes = gMetatileAttributes_Slateport,
    .callback = InitTilesetAnim_Slateport,
};

const struct Tileset gTileset_Mauville =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Mauville,
    .palettes = gTilesetPalettes_Mauville,
    .metatiles = gMetatiles_Mauville,
    .metatileAttributes = gMetatileAttributes_Mauville,
    .callback = InitTilesetAnim_Mauville,
};

const struct Tileset gTileset_Lavaridge =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lavaridge,
    .palettes = gTilesetPalettes_Lavaridge,
    .metatiles = gMetatiles_Lavaridge,
    .metatileAttributes = gMetatileAttributes_Lavaridge,
    .callback = InitTilesetAnim_Lavaridge,
};

const struct Tileset gTileset_Fallarbor =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Fallarbor,
    .palettes = gTilesetPalettes_Fallarbor,
    .metatiles = gMetatiles_Fallarbor,
    .metatileAttributes = gMetatileAttributes_Fallarbor,
    .callback = InitTilesetAnim_Fallarbor,
};

const struct Tileset gTileset_Fortree =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Fortree,
    .palettes = gTilesetPalettes_Fortree,
    .metatiles = gMetatiles_Fortree,
    .metatileAttributes = gMetatileAttributes_Fortree,
    .callback = InitTilesetAnim_Fortree,
};

const struct Tileset gTileset_Lilycove =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lilycove,
    .palettes = gTilesetPalettes_Lilycove,
    .metatiles = gMetatiles_Lilycove,
    .metatileAttributes = gMetatileAttributes_Lilycove,
    .callback = InitTilesetAnim_Lilycove,
};

const struct Tileset gTileset_Mossdeep =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Mossdeep,
    .palettes = gTilesetPalettes_Mossdeep,
    .metatiles = gMetatiles_Mossdeep,
    .metatileAttributes = gMetatileAttributes_Mossdeep,
    .callback = InitTilesetAnim_Mossdeep,
};

const struct Tileset gTileset_EverGrande =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EverGrande,
    .palettes = gTilesetPalettes_EverGrande,
    .metatiles = gMetatiles_EverGrande,
    .metatileAttributes = gMetatileAttributes_EverGrande,
    .callback = InitTilesetAnim_EverGrande,
};

const struct Tileset gTileset_Pacifidlog =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Pacifidlog,
    .palettes = gTilesetPalettes_Pacifidlog,
    .metatiles = gMetatiles_Pacifidlog,
    .metatileAttributes = gMetatileAttributes_Pacifidlog,
    .callback = InitTilesetAnim_Pacifidlog,
};

const struct Tileset gTileset_Sootopolis =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Sootopolis,
    .palettes = gTilesetPalettes_Sootopolis,
    .metatiles = gMetatiles_Sootopolis,
    .metatileAttributes = gMetatileAttributes_Sootopolis,
    .callback = InitTilesetAnim_Sootopolis,
};

const struct Tileset gTileset_BattleFrontierOutsideWest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontierOutsideWest,
    .palettes = gTilesetPalettes_BattleFrontierOutsideWest,
    .metatiles = gMetatiles_BattleFrontierOutsideWest,
    .metatileAttributes = gMetatileAttributes_BattleFrontierOutsideWest,
    .callback = InitTilesetAnim_BattleFrontierOutsideWest,
};

const struct Tileset gTileset_BattleFrontierOutsideEast =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontierOutsideEast,
    .palettes = gTilesetPalettes_BattleFrontierOutsideEast,
    .metatiles = gMetatiles_BattleFrontierOutsideEast,
    .metatileAttributes = gMetatileAttributes_BattleFrontierOutsideEast,
    .callback = InitTilesetAnim_BattleFrontierOutsideEast,
};

const struct Tileset gTileset_Building =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_InsideBuilding,
    .palettes = gTilesetPalettes_InsideBuilding,
    .metatiles = gMetatiles_InsideBuilding,
    .metatileAttributes = gMetatileAttributes_InsideBuilding,
    .callback = InitTilesetAnim_Building,
};

const struct Tileset gTileset_Shop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Shop,
    .palettes = gTilesetPalettes_Shop,
    .metatiles = gMetatiles_Shop,
    .metatileAttributes = gMetatileAttributes_Shop,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonCenter =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonCenter,
    .palettes = gTilesetPalettes_PokemonCenter,
    .metatiles = gMetatiles_PokemonCenter,
    .metatileAttributes = gMetatileAttributes_PokemonCenter,
    .callback = NULL,
};

const struct Tileset gTileset_Cave =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Cave,
    .palettes = gTilesetPalettes_Cave,
    .metatiles = gMetatiles_Cave,
    .metatileAttributes = gMetatileAttributes_Cave,
    .callback = InitTilesetAnim_Cave,
};

const struct Tileset gTileset_PokemonSchool =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonSchool,
    .palettes = gTilesetPalettes_PokemonSchool,
    .metatiles = gMetatiles_PokemonSchool,
    .metatileAttributes = gMetatileAttributes_PokemonSchool,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonFanClub =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonFanClub,
    .palettes = gTilesetPalettes_PokemonFanClub,
    .metatiles = gMetatiles_PokemonFanClub,
    .metatileAttributes = gMetatileAttributes_PokemonFanClub,
    .callback = NULL,
};

const struct Tileset gTileset_Unused1 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Unused1,
    .palettes = gTilesetPalettes_Unused1,
    .metatiles = gMetatiles_Unused1,
    .metatileAttributes = gMetatileAttributes_Unused1,
    .callback = NULL,
};

const struct Tileset gTileset_MeteorFalls =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MeteorFalls,
    .palettes = gTilesetPalettes_MeteorFalls,
    .metatiles = gMetatiles_MeteorFalls,
    .metatileAttributes = gMetatileAttributes_MeteorFalls,
    .callback = NULL,
};

const struct Tileset gTileset_OceanicMuseum =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_OceanicMuseum,
    .palettes = gTilesetPalettes_OceanicMuseum,
    .metatiles = gMetatiles_OceanicMuseum,
    .metatileAttributes = gMetatileAttributes_OceanicMuseum,
    .callback = NULL,
};

const struct Tileset gTileset_CableClub =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CableClub,
    .palettes = gTilesetPalettes_CableClub,
    .metatiles = gMetatiles_CableClub,
    .metatileAttributes = gMetatileAttributes_CableClub,
    .callback = NULL,
};

const struct Tileset gTileset_SeashoreHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeashoreHouse,
    .palettes = gTilesetPalettes_SeashoreHouse,
    .metatiles = gMetatiles_SeashoreHouse,
    .metatileAttributes = gMetatileAttributes_SeashoreHouse,
    .callback = NULL,
};

const struct Tileset gTileset_PrettyPetalFlowerShop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PrettyPetalFlowerShop,
    .palettes = gTilesetPalettes_PrettyPetalFlowerShop,
    .metatiles = gMetatiles_PrettyPetalFlowerShop,
    .metatileAttributes = gMetatileAttributes_PrettyPetalFlowerShop,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonDayCare =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonDayCare,
    .palettes = gTilesetPalettes_PokemonDayCare,
    .metatiles = gMetatiles_PokemonDayCare,
    .metatileAttributes = gMetatileAttributes_PokemonDayCare,
    .callback = NULL,
};

const struct Tileset gTileset_Facility =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Facility,
    .palettes = gTilesetPalettes_Facility,
    .metatiles = gMetatiles_Facility,
    .metatileAttributes = gMetatileAttributes_Facility,
    .callback = NULL,
};

const struct Tileset gTileset_BikeShop =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BikeShop,
    .palettes = gTilesetPalettes_BikeShop,
    .metatiles = gMetatiles_BikeShop,
    .metatileAttributes = gMetatileAttributes_BikeShop,
    .callback = InitTilesetAnim_BikeShop,
};

const struct Tileset gTileset_RusturfTunnel =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RusturfTunnel,
    .palettes = gTilesetPalettes_RusturfTunnel,
    .metatiles = gMetatiles_RusturfTunnel,
    .metatileAttributes = gMetatileAttributes_RusturfTunnel,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseBrownCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseBrownCave,
    .palettes = gTilesetPalettes_SecretBaseBrownCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseTree =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseTree,
    .palettes = gTilesetPalettes_SecretBaseTree,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseShrub =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseShrub,
    .palettes = gTilesetPalettes_SecretBaseShrub,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseBlueCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseBlueCave,
    .palettes = gTilesetPalettes_SecretBaseBlueCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseYellowCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseYellowCave,
    .palettes = gTilesetPalettes_SecretBaseYellowCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBaseRedCave =
{
    .isCompressed = FALSE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SecretBaseRedCave,
    .palettes = gTilesetPalettes_SecretBaseRedCave,
    .metatiles = gMetatiles_SecretBaseSecondary,
    .metatileAttributes = gMetatileAttributes_SecretBaseSecondary,
    .callback = NULL,
};

const struct Tileset gTileset_InsideOfTruck =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_InsideOfTruck,
    .palettes = gTilesetPalettes_InsideOfTruck,
    .metatiles = gMetatiles_InsideOfTruck,
    .metatileAttributes = gMetatileAttributes_InsideOfTruck,
    .callback = NULL,
};

const struct Tileset gTileset_Unused2 =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Unused2,
    .palettes = gTilesetPalettes_Unused2,
    .metatiles = gMetatiles_Unused2,
    .metatileAttributes = gMetatileAttributes_Unused2,
    .callback = NULL,
};

const struct Tileset gTileset_Contest =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Contest,
    .palettes = gTilesetPalettes_Contest,
    .metatiles = gMetatiles_Contest,
    .metatileAttributes = gMetatileAttributes_Contest,
    .callback = NULL,
};

const struct Tileset gTileset_LilycoveMuseum =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LilycoveMuseum,
    .palettes = gTilesetPalettes_LilycoveMuseum,
    .metatiles = gMetatiles_LilycoveMuseum,
    .metatileAttributes = gMetatileAttributes_LilycoveMuseum,
    .callback = NULL,
};

const struct Tileset gTileset_BrendansMaysHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BrendansMaysHouse,
    .palettes = gTilesetPalettes_BrendansMaysHouse,
    .metatiles = gMetatiles_BrendansMaysHouse,
    .metatileAttributes = gMetatileAttributes_BrendansMaysHouse,
    .callback = NULL,
};

const struct Tileset gTileset_Lab =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Lab,
    .palettes = gTilesetPalettes_Lab,
    .metatiles = gMetatiles_Lab,
    .metatileAttributes = gMetatileAttributes_Lab,
    .callback = NULL,
};

const struct Tileset gTileset_Underwater =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_Underwater,
    .palettes = gTilesetPalettes_Underwater,
    .metatiles = gMetatiles_Underwater,
    .metatileAttributes = gMetatileAttributes_Underwater,
    .callback = InitTilesetAnim_Underwater,
};

const struct Tileset gTileset_PetalburgGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PetalburgGym,
    .palettes = gTilesetPalettes_PetalburgGym,
    .metatiles = gMetatiles_PetalburgGym,
    .metatileAttributes = gMetatileAttributes_PetalburgGym,
    .callback = NULL,
};

const struct Tileset gTileset_SootopolisGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SootopolisGym,
    .palettes = gTilesetPalettes_SootopolisGym,
    .metatiles = gMetatiles_SootopolisGym,
    .metatileAttributes = gMetatileAttributes_SootopolisGym,
    .callback = InitTilesetAnim_SootopolisGym,
};

const struct Tileset gTileset_GenericBuilding =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GenericBuilding,
    .palettes = gTilesetPalettes_GenericBuilding,
    .metatiles = gMetatiles_GenericBuilding,
    .metatileAttributes = gMetatileAttributes_GenericBuilding,
    .callback = NULL,
};

const struct Tileset gTileset_MauvilleGameCorner =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MauvilleGameCorner,
    .palettes = gTilesetPalettes_MauvilleGameCorner,
    .metatiles = gMetatiles_MauvilleGameCorner,
    .metatileAttributes = gMetatileAttributes_MauvilleGameCorner,
    .callback = NULL,
};

const struct Tileset gTileset_RustboroGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RustboroGym,
    .palettes = gTilesetPalettes_RustboroGym,
    .metatiles = gMetatiles_RustboroGym,
    .metatileAttributes = gMetatileAttributes_RustboroGym,
    .callback = NULL,
};

const struct Tileset gTileset_DewfordGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_DewfordGym,
    .palettes = gTilesetPalettes_DewfordGym,
    .metatiles = gMetatiles_DewfordGym,
    .metatileAttributes = gMetatileAttributes_DewfordGym,
    .callback = NULL,
};

const struct Tileset gTileset_MauvilleGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MauvilleGym,
    .palettes = gTilesetPalettes_MauvilleGym,
    .metatiles = gMetatiles_MauvilleGym,
    .metatileAttributes = gMetatileAttributes_MauvilleGym,
    .callback = InitTilesetAnim_MauvilleGym,
};

const struct Tileset gTileset_LavaridgeGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LavaridgeGym,
    .palettes = gTilesetPalettes_LavaridgeGym,
    .metatiles = gMetatiles_LavaridgeGym,
    .metatileAttributes = gMetatileAttributes_LavaridgeGym,
    .callback = NULL,
};

const struct Tileset gTileset_TrickHousePuzzle =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TrickHousePuzzle,
    .palettes = gTilesetPalettes_TrickHousePuzzle,
    .metatiles = gMetatiles_TrickHousePuzzle,
    .metatileAttributes = gMetatileAttributes_TrickHousePuzzle,
    .callback = NULL,
};

const struct Tileset gTileset_FortreeGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FortreeGym,
    .palettes = gTilesetPalettes_FortreeGym,
    .metatiles = gMetatiles_FortreeGym,
    .metatileAttributes = gMetatileAttributes_FortreeGym,
    .callback = NULL,
};

const struct Tileset gTileset_MossdeepGym =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MossdeepGym,
    .palettes = gTilesetPalettes_MossdeepGym,
    .metatiles = gMetatiles_MossdeepGym,
    .metatileAttributes = gMetatileAttributes_MossdeepGym,
    .callback = NULL,
};

const struct Tileset gTileset_InsideShip =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_InsideShip,
    .palettes = gTilesetPalettes_InsideShip,
    .metatiles = gMetatiles_InsideShip,
    .metatileAttributes = gMetatileAttributes_InsideShip,
    .callback = NULL,
};

const struct Tileset gTileset_SecretBase =
{
    .isCompressed = FALSE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_SecretBase,
    .palettes = gTilesetPalettes_SecretBase,
    .metatiles = gMetatiles_SecretBasePrimary,
    .metatileAttributes = gMetatileAttributes_SecretBasePrimary,
    .callback = NULL,
};

const struct Tileset *const gTilesetPointer_SecretBase = &gTileset_SecretBase;
const struct Tileset *const gTilesetPointer_SecretBaseRedCave = &gTileset_SecretBaseRedCave;

const struct Tileset gTileset_EliteFour =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EliteFour,
    .palettes = gTilesetPalettes_EliteFour,
    .metatiles = gMetatiles_EliteFour,
    .metatileAttributes = gMetatileAttributes_EliteFour,
    .callback = InitTilesetAnim_EliteFour,
};

const struct Tileset gTileset_BattleFrontier =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontier,
    .palettes = gTilesetPalettes_BattleFrontier,
    .metatiles = gMetatiles_BattleFrontier,
    .metatileAttributes = gMetatileAttributes_BattleFrontier,
    .callback = NULL,
};

const struct Tileset gTileset_BattlePalace =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattlePalace,
    .palettes = gTilesetPalettes_BattlePalace,
    .metatiles = gMetatiles_BattlePalace,
    .metatileAttributes = gMetatileAttributes_BattlePalace,
    .callback = NULL,
};

const struct Tileset gTileset_BattleDome =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleDome,
    .palettes = gTilesetPalettes_BattleDome,
    .metatiles = gMetatiles_BattleDome,
    .metatileAttributes = gMetatileAttributes_BattleDome,
    .callback = InitTilesetAnim_BattleDome,
};

const struct Tileset gTileset_BattleFactory =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFactory,
    .palettes = gTilesetPalettes_BattleFactory,
    .metatiles = gMetatiles_BattleFactory,
    .metatileAttributes = gMetatileAttributes_BattleFactory,
    .callback = NULL,
};

const struct Tileset gTileset_BattlePike =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattlePike,
    .palettes = gTilesetPalettes_BattlePike,
    .metatiles = gMetatiles_BattlePike,
    .metatileAttributes = gMetatileAttributes_BattlePike,
    .callback = NULL,
};

const struct Tileset gTileset_BattleArena =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleArena,
    .palettes = gTilesetPalettes_BattleArena,
    .metatiles = gMetatiles_BattleArena,
    .metatileAttributes = gMetatileAttributes_BattleArena,
    .callback = NULL,
};

const struct Tileset gTileset_BattlePyramid =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattlePyramid,
    .palettes = gTilesetPalettes_BattlePyramid,
    .metatiles = gMetatiles_BattlePyramid,
    .metatileAttributes = gMetatileAttributes_BattlePyramid,
    .callback = InitTilesetAnim_BattlePyramid,
};

const struct Tileset gTileset_MirageTower =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MirageTower,
    .palettes = gTilesetPalettes_MirageTower,
    .metatiles = gMetatiles_MirageTower,
    .metatileAttributes = gMetatileAttributes_MirageTower,
    .callback = NULL,
};

const struct Tileset gTileset_MossdeepGameCorner =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MossdeepGameCorner,
    .palettes = gTilesetPalettes_MossdeepGameCorner,
    .metatiles = gMetatiles_MossdeepGameCorner,
    .metatileAttributes = gMetatileAttributes_MossdeepGameCorner,
    .callback = NULL,
};

const struct Tileset gTileset_IslandHarbor =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_IslandHarbor,
    .palettes = gTilesetPalettes_IslandHarbor,
    .metatiles = gMetatiles_IslandHarbor,
    .metatileAttributes = gMetatileAttributes_IslandHarbor,
    .callback = NULL,
};

const struct Tileset gTileset_TrainerHill =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TrainerHill,
    .palettes = gTilesetPalettes_TrainerHill,
    .metatiles = gMetatiles_TrainerHill,
    .metatileAttributes = gMetatileAttributes_TrainerHill,
    .callback = NULL,
};

const struct Tileset gTileset_NavelRock =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_NavelRock,
    .palettes = gTilesetPalettes_NavelRock,
    .metatiles = gMetatiles_NavelRock,
    .metatileAttributes = gMetatileAttributes_NavelRock,
    .callback = NULL,
};

const struct Tileset gTileset_BattleFrontierRankingHall =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleFrontierRankingHall,
    .palettes = gTilesetPalettes_BattleFrontierRankingHall,
    .metatiles = gMetatiles_BattleFrontierRankingHall,
    .metatileAttributes = gMetatileAttributes_BattleFrontierRankingHall,
    .callback = NULL,
};

const struct Tileset gTileset_BattleTent =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BattleTent,
    .palettes = gTilesetPalettes_BattleTent,
    .metatiles = gMetatiles_BattleTent,
    .metatileAttributes = gMetatileAttributes_BattleTent,
    .callback = NULL,
};

const struct Tileset gTileset_MysteryEventsHouse =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MysteryEventsHouse,
    .palettes = gTilesetPalettes_MysteryEventsHouse,
    .metatiles = gMetatiles_MysteryEventsHouse,
    .metatileAttributes = gMetatileAttributes_MysteryEventsHouse,
    .callback = NULL,
};

const struct Tileset gTileset_UnionRoom =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_UnionRoom,
    .palettes = gTilesetPalettes_UnionRoom,
    .metatiles = gMetatiles_UnionRoom,
    .metatileAttributes = gMetatileAttributes_UnionRoom,
    .callback = NULL,
};

// M2 Phase 1 Kanto tileset library
const struct Tileset gTileset_BuildingKanto =
{
    .isCompressed = TRUE,
    .isSecondary = FALSE,
    .tiles = gTilesetTiles_BuildingKanto,
    .palettes = gTilesetPalettes_BuildingKanto,
    .metatiles = gMetatiles_BuildingKanto,
    .metatileAttributes = gMetatileAttributes_BuildingKanto,
    .callback = NULL,
};

const struct Tileset gTileset_BikeShopKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BikeShopKanto,
    .palettes = gTilesetPalettes_BikeShopKanto,
    .metatiles = gMetatiles_BikeShopKanto,
    .metatileAttributes = gMetatileAttributes_BikeShopKanto,
    .callback = NULL,
};

const struct Tileset gTileset_BurgledHouseKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_BurgledHouseKanto,
    .palettes = gTilesetPalettes_BurgledHouseKanto,
    .metatiles = gMetatiles_BurgledHouseKanto,
    .metatileAttributes = gMetatileAttributes_BurgledHouseKanto,
    .callback = NULL,
};

const struct Tileset gTileset_CableClubKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CableClubKanto,
    .palettes = gTilesetPalettes_CableClubKanto,
    .metatiles = gMetatiles_CableClubKanto,
    .metatileAttributes = gMetatileAttributes_CableClubKanto,
    .callback = NULL,
};

const struct Tileset gTileset_CeladonGymKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeladonGymKanto,
    .palettes = gTilesetPalettes_CeladonGymKanto,
    .metatiles = gMetatiles_CeladonGymKanto,
    .metatileAttributes = gMetatileAttributes_CeladonGymKanto,
    .callback = NULL,
};

const struct Tileset gTileset_CeruleanGymKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeruleanGymKanto,
    .palettes = gTilesetPalettes_CeruleanGymKanto,
    .metatiles = gMetatiles_CeruleanGymKanto,
    .metatileAttributes = gMetatileAttributes_CeruleanGymKanto,
    .callback = NULL,
};

const struct Tileset gTileset_CinnabarGymKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CinnabarGymKanto,
    .palettes = gTilesetPalettes_CinnabarGymKanto,
    .metatiles = gMetatiles_CinnabarGymKanto,
    .metatileAttributes = gMetatileAttributes_CinnabarGymKanto,
    .callback = NULL,
};

const struct Tileset gTileset_CondominiumsKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CondominiumsKanto,
    .palettes = gTilesetPalettes_CondominiumsKanto,
    .metatiles = gMetatiles_CondominiumsKanto,
    .metatileAttributes = gMetatileAttributes_CondominiumsKanto,
    .callback = NULL,
};

const struct Tileset gTileset_FanClubDaycareKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FanClubDaycareKanto,
    .palettes = gTilesetPalettes_FanClubDaycareKanto,
    .metatiles = gMetatiles_FanClubDaycareKanto,
    .metatileAttributes = gMetatileAttributes_FanClubDaycareKanto,
    .callback = NULL,
};

const struct Tileset gTileset_FuchsiaGymKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FuchsiaGymKanto,
    .palettes = gTilesetPalettes_FuchsiaGymKanto,
    .metatiles = gMetatiles_FuchsiaGymKanto,
    .metatileAttributes = gMetatileAttributes_FuchsiaGymKanto,
    .callback = NULL,
};

const struct Tileset gTileset_GameCornerKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GameCornerKanto,
    .palettes = gTilesetPalettes_GameCornerKanto,
    .metatiles = gMetatiles_GameCornerKanto,
    .metatileAttributes = gMetatileAttributes_GameCornerKanto,
    .callback = NULL,
};

const struct Tileset gTileset_GenericBuilding2Kanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GenericBuilding2Kanto,
    .palettes = gTilesetPalettes_GenericBuilding2Kanto,
    .metatiles = gMetatiles_GenericBuilding2Kanto,
    .metatileAttributes = gMetatileAttributes_GenericBuilding2Kanto,
    .callback = NULL,
};

const struct Tileset gTileset_HallOfFameKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_HallOfFameKanto,
    .palettes = gTilesetPalettes_HallOfFameKanto,
    .metatiles = gMetatiles_HallOfFameKanto,
    .metatileAttributes = gMetatileAttributes_HallOfFameKanto,
    .callback = NULL,
};

const struct Tileset gTileset_LabKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LabKanto,
    .palettes = gTilesetPalettes_LabKanto,
    .metatiles = gMetatiles_LabKanto,
    .metatileAttributes = gMetatileAttributes_LabKanto,
    .callback = NULL,
};

const struct Tileset gTileset_MartKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MartKanto,
    .palettes = gTilesetPalettes_MartKanto,
    .metatiles = gMetatiles_MartKanto,
    .metatileAttributes = gMetatileAttributes_MartKanto,
    .callback = NULL,
};

const struct Tileset gTileset_MuseumKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MuseumKanto,
    .palettes = gTilesetPalettes_MuseumKanto,
    .metatiles = gMetatiles_MuseumKanto,
    .metatileAttributes = gMetatileAttributes_MuseumKanto,
    .callback = NULL,
};

const struct Tileset gTileset_PewterGymKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PewterGymKanto,
    .palettes = gTilesetPalettes_PewterGymKanto,
    .metatiles = gMetatiles_PewterGymKanto,
    .metatileAttributes = gMetatileAttributes_PewterGymKanto,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonCenterKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonCenterKanto,
    .palettes = gTilesetPalettes_PokemonCenterKanto,
    .metatiles = gMetatiles_PokemonCenterKanto,
    .metatileAttributes = gMetatileAttributes_PokemonCenterKanto,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonLeagueKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonLeagueKanto,
    .palettes = gTilesetPalettes_PokemonLeagueKanto,
    .metatiles = gMetatiles_PokemonLeagueKanto,
    .metatileAttributes = gMetatileAttributes_PokemonLeagueKanto,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonMansionKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonMansionKanto,
    .palettes = gTilesetPalettes_PokemonMansionKanto,
    .metatiles = gMetatiles_PokemonMansionKanto,
    .metatileAttributes = gMetatileAttributes_PokemonMansionKanto,
    .callback = NULL,
};

const struct Tileset gTileset_PokemonTowerKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokemonTowerKanto,
    .palettes = gTilesetPalettes_PokemonTowerKanto,
    .metatiles = gMetatiles_PokemonTowerKanto,
    .metatileAttributes = gMetatileAttributes_PokemonTowerKanto,
    .callback = NULL,
};

const struct Tileset gTileset_PowerPlantKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PowerPlantKanto,
    .palettes = gTilesetPalettes_PowerPlantKanto,
    .metatiles = gMetatiles_PowerPlantKanto,
    .metatileAttributes = gMetatileAttributes_PowerPlantKanto,
    .callback = NULL,
};

const struct Tileset gTileset_RestaurantHotelKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RestaurantHotelKanto,
    .palettes = gTilesetPalettes_RestaurantHotelKanto,
    .metatiles = gMetatiles_RestaurantHotelKanto,
    .metatileAttributes = gMetatileAttributes_RestaurantHotelKanto,
    .callback = NULL,
};

const struct Tileset gTileset_SafariZoneBuildingKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SafariZoneBuildingKanto,
    .palettes = gTilesetPalettes_SafariZoneBuildingKanto,
    .metatiles = gMetatiles_SafariZoneBuildingKanto,
    .metatileAttributes = gMetatileAttributes_SafariZoneBuildingKanto,
    .callback = NULL,
};

const struct Tileset gTileset_SaffronGymKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SaffronGymKanto,
    .palettes = gTilesetPalettes_SaffronGymKanto,
    .metatiles = gMetatiles_SaffronGymKanto,
    .metatileAttributes = gMetatileAttributes_SaffronGymKanto,
    .callback = NULL,
};

const struct Tileset gTileset_SchoolKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SchoolKanto,
    .palettes = gTilesetPalettes_SchoolKanto,
    .metatiles = gMetatiles_SchoolKanto,
    .metatileAttributes = gMetatileAttributes_SchoolKanto,
    .callback = NULL,
};

const struct Tileset gTileset_SeaCottageKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeaCottageKanto,
    .palettes = gTilesetPalettes_SeaCottageKanto,
    .metatiles = gMetatiles_SeaCottageKanto,
    .metatileAttributes = gMetatileAttributes_SeaCottageKanto,
    .callback = NULL,
};

const struct Tileset gTileset_UndergroundPathKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_UndergroundPathKanto,
    .palettes = gTilesetPalettes_UndergroundPathKanto,
    .metatiles = gMetatiles_UndergroundPathKanto,
    .metatileAttributes = gMetatileAttributes_UndergroundPathKanto,
    .callback = NULL,
};

const struct Tileset gTileset_VermilionGymKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_VermilionGymKanto,
    .palettes = gTilesetPalettes_VermilionGymKanto,
    .metatiles = gMetatiles_VermilionGymKanto,
    .metatileAttributes = gMetatileAttributes_VermilionGymKanto,
    .callback = NULL,
};

const struct Tileset gTileset_ViridianGymKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ViridianGymKanto,
    .palettes = gTilesetPalettes_ViridianGymKanto,
    .metatiles = gMetatiles_ViridianGymKanto,
    .metatileAttributes = gMetatileAttributes_ViridianGymKanto,
    .callback = NULL,
};

// M2 Phase 1 Kanto tileset library
const struct Tileset gTileset_DepartmentStoreKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_DepartmentStoreKanto,
    .palettes = gTilesetPalettes_DepartmentStoreKanto,
    .metatiles = gMetatiles_DepartmentStoreKanto,
    .metatileAttributes = gMetatileAttributes_DepartmentStoreKanto,
    .callback = NULL,
};

const struct Tileset gTileset_GenericBuilding1Kanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GenericBuilding1Kanto,
    .palettes = gTilesetPalettes_GenericBuilding1Kanto,
    .metatiles = gMetatiles_GenericBuilding1Kanto,
    .metatileAttributes = gMetatileAttributes_GenericBuilding1Kanto,
    .callback = NULL,
};

const struct Tileset gTileset_CaveKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CaveKanto,
    .palettes = gTilesetPalettes_CaveKanto,
    .metatiles = gMetatiles_CaveKanto,
    .metatileAttributes = gMetatileAttributes_CaveKanto,
    .callback = NULL,
};

const struct Tileset gTileset_CeladonCityKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeladonCityKanto,
    .palettes = gTilesetPalettes_CeladonCityKanto,
    .metatiles = gMetatiles_CeladonCityKanto,
    .metatileAttributes = gMetatileAttributes_CeladonCityKanto,
    .callback = NULL,
};

const struct Tileset gTileset_CeruleanCaveKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeruleanCaveKanto,
    .palettes = gTilesetPalettes_CeruleanCaveKanto,
    .metatiles = gMetatiles_CeruleanCaveKanto,
    .metatileAttributes = gMetatileAttributes_CeruleanCaveKanto,
    .callback = NULL,
};

const struct Tileset gTileset_CeruleanCityKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CeruleanCityKanto,
    .palettes = gTilesetPalettes_CeruleanCityKanto,
    .metatiles = gMetatiles_CeruleanCityKanto,
    .metatileAttributes = gMetatileAttributes_CeruleanCityKanto,
    .callback = NULL,
};

const struct Tileset gTileset_CinnabarIslandKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CinnabarIslandKanto,
    .palettes = gTilesetPalettes_CinnabarIslandKanto,
    .metatiles = gMetatiles_CinnabarIslandKanto,
    .metatileAttributes = gMetatileAttributes_CinnabarIslandKanto,
    .callback = NULL,
};

const struct Tileset gTileset_DiglettsCaveKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_DiglettsCaveKanto,
    .palettes = gTilesetPalettes_DiglettsCaveKanto,
    .metatiles = gMetatiles_DiglettsCaveKanto,
    .metatileAttributes = gMetatileAttributes_DiglettsCaveKanto,
    .callback = NULL,
};

const struct Tileset gTileset_FuchsiaCityKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FuchsiaCityKanto,
    .palettes = gTilesetPalettes_FuchsiaCityKanto,
    .metatiles = gMetatiles_FuchsiaCityKanto,
    .metatileAttributes = gMetatileAttributes_FuchsiaCityKanto,
    .callback = NULL,
};

const struct Tileset gTileset_IndigoPlateauKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_IndigoPlateauKanto,
    .palettes = gTilesetPalettes_IndigoPlateauKanto,
    .metatiles = gMetatiles_IndigoPlateauKanto,
    .metatileAttributes = gMetatileAttributes_IndigoPlateauKanto,
    .callback = NULL,
};

const struct Tileset gTileset_LavenderTownKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LavenderTownKanto,
    .palettes = gTilesetPalettes_LavenderTownKanto,
    .metatiles = gMetatiles_LavenderTownKanto,
    .metatileAttributes = gMetatileAttributes_LavenderTownKanto,
    .callback = NULL,
};

const struct Tileset gTileset_MtEmberKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MtEmberKanto,
    .palettes = gTilesetPalettes_MtEmberKanto,
    .metatiles = gMetatiles_MtEmberKanto,
    .metatileAttributes = gMetatileAttributes_MtEmberKanto,
    .callback = NULL,
};

const struct Tileset gTileset_PewterCityKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PewterCityKanto,
    .palettes = gTilesetPalettes_PewterCityKanto,
    .metatiles = gMetatiles_PewterCityKanto,
    .metatileAttributes = gMetatileAttributes_PewterCityKanto,
    .callback = NULL,
};

const struct Tileset gTileset_RockTunnelKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RockTunnelKanto,
    .palettes = gTilesetPalettes_RockTunnelKanto,
    .metatiles = gMetatiles_RockTunnelKanto,
    .metatileAttributes = gMetatileAttributes_RockTunnelKanto,
    .callback = NULL,
};

const struct Tileset gTileset_SSAnneKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SSAnneKanto,
    .palettes = gTilesetPalettes_SSAnneKanto,
    .metatiles = gMetatiles_SSAnneKanto,
    .metatileAttributes = gMetatileAttributes_SSAnneKanto,
    .callback = NULL,
};

const struct Tileset gTileset_SaffronCityKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SaffronCityKanto,
    .palettes = gTilesetPalettes_SaffronCityKanto,
    .metatiles = gMetatiles_SaffronCityKanto,
    .metatileAttributes = gMetatileAttributes_SaffronCityKanto,
    .callback = NULL,
};

const struct Tileset gTileset_SeafoamIslandsKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeafoamIslandsKanto,
    .palettes = gTilesetPalettes_SeafoamIslandsKanto,
    .metatiles = gMetatiles_SeafoamIslandsKanto,
    .metatileAttributes = gMetatileAttributes_SeafoamIslandsKanto,
    .callback = NULL,
};

const struct Tileset gTileset_SeviiIslands123Kanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SeviiIslands123Kanto,
    .palettes = gTilesetPalettes_SeviiIslands123Kanto,
    .metatiles = gMetatiles_SeviiIslands123Kanto,
    .metatileAttributes = gMetatileAttributes_SeviiIslands123Kanto,
    .callback = NULL,
};

const struct Tileset gTileset_VermilionCityKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_VermilionCityKanto,
    .palettes = gTilesetPalettes_VermilionCityKanto,
    .metatiles = gMetatiles_VermilionCityKanto,
    .metatileAttributes = gMetatileAttributes_VermilionCityKanto,
    .callback = NULL,
};

const struct Tileset gTileset_ViridianCityKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ViridianCityKanto,
    .palettes = gTilesetPalettes_ViridianCityKanto,
    .metatiles = gMetatiles_ViridianCityKanto,
    .metatileAttributes = gMetatileAttributes_ViridianCityKanto,
    .callback = NULL,
};

const struct Tileset gTileset_ViridianForestKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ViridianForestKanto,
    .palettes = gTilesetPalettes_ViridianForestKanto,
    .metatiles = gMetatiles_ViridianForestKanto,
    .metatileAttributes = gMetatileAttributes_ViridianForestKanto,
    .callback = NULL,
};

const struct Tileset gTileset_SilphCoKanto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_SilphCoKanto,
    .palettes = gTilesetPalettes_SilphCoKanto,
    .metatiles = gMetatiles_SilphCoKanto,
    .metatileAttributes = gMetatileAttributes_SilphCoKanto,
    .callback = NULL,
};

// M3 Johto tileset library
const struct Tileset gTileset_AerodactylWordRoomJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_AerodactylWordRoomJohto,
    .palettes = gTilesetPalettes_AerodactylWordRoomJohto,
    .metatiles = gMetatiles_AerodactylWordRoomJohto,
    .metatileAttributes = gMetatileAttributes_AerodactylWordRoomJohto,
    .callback = NULL,
};

const struct Tileset gTileset_CaveJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_CaveJohto,
    .palettes = gTilesetPalettes_CaveJohto,
    .metatiles = gMetatiles_CaveJohto,
    .metatileAttributes = gMetatileAttributes_CaveJohto,
    .callback = NULL,
};

const struct Tileset gTileset_ChampionsRoomJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ChampionsRoomJohto,
    .palettes = gTilesetPalettes_ChampionsRoomJohto,
    .metatiles = gMetatiles_ChampionsRoomJohto,
    .metatileAttributes = gMetatileAttributes_ChampionsRoomJohto,
    .callback = NULL,
};

const struct Tileset gTileset_DarkCaveJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_DarkCaveJohto,
    .palettes = gTilesetPalettes_DarkCaveJohto,
    .metatiles = gMetatiles_DarkCaveJohto,
    .metatileAttributes = gMetatileAttributes_DarkCaveJohto,
    .callback = NULL,
};

const struct Tileset gTileset_EliteFourRoomDungeonJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EliteFourRoomDungeonJohto,
    .palettes = gTilesetPalettes_EliteFourRoomDungeonJohto,
    .metatiles = gMetatiles_EliteFourRoomDungeonJohto,
    .metatileAttributes = gMetatileAttributes_EliteFourRoomDungeonJohto,
    .callback = NULL,
};

const struct Tileset gTileset_EliteFourRoomIndoorJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_EliteFourRoomIndoorJohto,
    .palettes = gTilesetPalettes_EliteFourRoomIndoorJohto,
    .metatiles = gMetatiles_EliteFourRoomIndoorJohto,
    .metatileAttributes = gMetatileAttributes_EliteFourRoomIndoorJohto,
    .callback = NULL,
};

const struct Tileset gTileset_FacilityDungeonJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FacilityDungeonJohto,
    .palettes = gTilesetPalettes_FacilityDungeonJohto,
    .metatiles = gMetatiles_FacilityDungeonJohto,
    .metatileAttributes = gMetatileAttributes_FacilityDungeonJohto,
    .callback = NULL,
};

const struct Tileset gTileset_FacilityIndoorJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_FacilityIndoorJohto,
    .palettes = gTilesetPalettes_FacilityIndoorJohto,
    .metatiles = gMetatiles_FacilityIndoorJohto,
    .metatileAttributes = gMetatileAttributes_FacilityIndoorJohto,
    .callback = NULL,
};

const struct Tileset gTileset_ForestJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ForestJohto,
    .palettes = gTilesetPalettes_ForestJohto,
    .metatiles = gMetatiles_ForestJohto,
    .metatileAttributes = gMetatileAttributes_ForestJohto,
    .callback = NULL,
};

const struct Tileset gTileset_GameCornerJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GameCornerJohto,
    .palettes = gTilesetPalettes_GameCornerJohto,
    .metatiles = gMetatiles_GameCornerJohto,
    .metatileAttributes = gMetatileAttributes_GameCornerJohto,
    .callback = NULL,
};

const struct Tileset gTileset_GateDungeonJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GateDungeonJohto,
    .palettes = gTilesetPalettes_GateDungeonJohto,
    .metatiles = gMetatiles_GateDungeonJohto,
    .metatileAttributes = gMetatileAttributes_GateDungeonJohto,
    .callback = NULL,
};

const struct Tileset gTileset_GateIndoorJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_GateIndoorJohto,
    .palettes = gTilesetPalettes_GateIndoorJohto,
    .metatiles = gMetatiles_GateIndoorJohto,
    .metatileAttributes = gMetatileAttributes_GateIndoorJohto,
    .callback = NULL,
};

const struct Tileset gTileset_HoOhWordRoomJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_HoOhWordRoomJohto,
    .palettes = gTilesetPalettes_HoOhWordRoomJohto,
    .metatiles = gMetatiles_HoOhWordRoomJohto,
    .metatileAttributes = gMetatileAttributes_HoOhWordRoomJohto,
    .callback = NULL,
};

const struct Tileset gTileset_HouseJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_HouseJohto,
    .palettes = gTilesetPalettes_HouseJohto,
    .metatiles = gMetatiles_HouseJohto,
    .metatileAttributes = gMetatileAttributes_HouseJohto,
    .callback = NULL,
};

const struct Tileset gTileset_IcePathJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_IcePathJohto,
    .palettes = gTilesetPalettes_IcePathJohto,
    .metatiles = gMetatiles_IcePathJohto,
    .metatileAttributes = gMetatileAttributes_IcePathJohto,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoBlackthorn =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoBlackthorn,
    .palettes = gTilesetPalettes_JohtoBlackthorn,
    .metatiles = gMetatiles_JohtoBlackthorn,
    .metatileAttributes = gMetatileAttributes_JohtoBlackthorn,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoCherrygrove =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoCherrygrove,
    .palettes = gTilesetPalettes_JohtoCherrygrove,
    .metatiles = gMetatiles_JohtoCherrygrove,
    .metatileAttributes = gMetatileAttributes_JohtoCherrygrove,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoCianwood =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoCianwood,
    .palettes = gTilesetPalettes_JohtoCianwood,
    .metatiles = gMetatiles_JohtoCianwood,
    .metatileAttributes = gMetatileAttributes_JohtoCianwood,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoDungeon =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoDungeon,
    .palettes = gTilesetPalettes_JohtoDungeon,
    .metatiles = gMetatiles_JohtoDungeon,
    .metatileAttributes = gMetatileAttributes_JohtoDungeon,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoDungeons =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoDungeons,
    .palettes = gTilesetPalettes_JohtoDungeons,
    .metatiles = gMetatiles_JohtoDungeons,
    .metatileAttributes = gMetatileAttributes_JohtoDungeons,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoEcruteak =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoEcruteak,
    .palettes = gTilesetPalettes_JohtoEcruteak,
    .metatiles = gMetatiles_JohtoEcruteak,
    .metatileAttributes = gMetatileAttributes_JohtoEcruteak,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoLakeofrage =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoLakeofrage,
    .palettes = gTilesetPalettes_JohtoLakeofrage,
    .metatiles = gMetatiles_JohtoLakeofrage,
    .metatileAttributes = gMetatileAttributes_JohtoLakeofrage,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoMahogany =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoMahogany,
    .palettes = gTilesetPalettes_JohtoMahogany,
    .metatiles = gMetatiles_JohtoMahogany,
    .metatileAttributes = gMetatileAttributes_JohtoMahogany,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoModernAzalea =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoModernAzalea,
    .palettes = gTilesetPalettes_JohtoModernAzalea,
    .metatiles = gMetatiles_JohtoModernAzalea,
    .metatileAttributes = gMetatileAttributes_JohtoModernAzalea,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoModernGoldenrod =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoModernGoldenrod,
    .palettes = gTilesetPalettes_JohtoModernGoldenrod,
    .metatiles = gMetatiles_JohtoModernGoldenrod,
    .metatileAttributes = gMetatileAttributes_JohtoModernGoldenrod,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoNewbark =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoNewbark,
    .palettes = gTilesetPalettes_JohtoNewbark,
    .metatiles = gMetatiles_JohtoNewbark,
    .metatileAttributes = gMetatileAttributes_JohtoNewbark,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoOlivine =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoOlivine,
    .palettes = gTilesetPalettes_JohtoOlivine,
    .metatiles = gMetatiles_JohtoOlivine,
    .metatileAttributes = gMetatileAttributes_JohtoOlivine,
    .callback = NULL,
};

const struct Tileset gTileset_JohtoViolet =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_JohtoViolet,
    .palettes = gTilesetPalettes_JohtoViolet,
    .metatiles = gMetatiles_JohtoViolet,
    .metatileAttributes = gMetatileAttributes_JohtoViolet,
    .callback = NULL,
};

const struct Tileset gTileset_KabutoWordRoomJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KabutoWordRoomJohto,
    .palettes = gTilesetPalettes_KabutoWordRoomJohto,
    .metatiles = gMetatiles_KabutoWordRoomJohto,
    .metatileAttributes = gMetatileAttributes_KabutoWordRoomJohto,
    .callback = NULL,
};

const struct Tileset gTileset_KantoJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_KantoJohto,
    .palettes = gTilesetPalettes_KantoJohto,
    .metatiles = gMetatiles_KantoJohto,
    .metatileAttributes = gMetatileAttributes_KantoJohto,
    .callback = NULL,
};

const struct Tileset gTileset_LabJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LabJohto,
    .palettes = gTilesetPalettes_LabJohto,
    .metatiles = gMetatiles_LabJohto,
    .metatileAttributes = gMetatileAttributes_LabJohto,
    .callback = NULL,
};

const struct Tileset gTileset_LighthouseJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_LighthouseJohto,
    .palettes = gTilesetPalettes_LighthouseJohto,
    .metatiles = gMetatiles_LighthouseJohto,
    .metatileAttributes = gMetatileAttributes_LighthouseJohto,
    .callback = NULL,
};

const struct Tileset gTileset_MartJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_MartJohto,
    .palettes = gTilesetPalettes_MartJohto,
    .metatiles = gMetatiles_MartJohto,
    .metatileAttributes = gMetatileAttributes_MartJohto,
    .callback = NULL,
};

const struct Tileset gTileset_OmanyteWordRoomJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_OmanyteWordRoomJohto,
    .palettes = gTilesetPalettes_OmanyteWordRoomJohto,
    .metatiles = gMetatiles_OmanyteWordRoomJohto,
    .metatileAttributes = gMetatileAttributes_OmanyteWordRoomJohto,
    .callback = NULL,
};

const struct Tileset gTileset_ParkJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_ParkJohto,
    .palettes = gTilesetPalettes_ParkJohto,
    .metatiles = gMetatiles_ParkJohto,
    .metatileAttributes = gMetatileAttributes_ParkJohto,
    .callback = NULL,
};

const struct Tileset gTileset_PlayersHouseJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PlayersHouseJohto,
    .palettes = gTilesetPalettes_PlayersHouseJohto,
    .metatiles = gMetatiles_PlayersHouseJohto,
    .metatileAttributes = gMetatileAttributes_PlayersHouseJohto,
    .callback = NULL,
};

const struct Tileset gTileset_PlayersRoomJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PlayersRoomJohto,
    .palettes = gTilesetPalettes_PlayersRoomJohto,
    .metatiles = gMetatiles_PlayersRoomJohto,
    .metatileAttributes = gMetatileAttributes_PlayersRoomJohto,
    .callback = NULL,
};

const struct Tileset gTileset_PokecenterJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PokecenterJohto,
    .palettes = gTilesetPalettes_PokecenterJohto,
    .metatiles = gMetatiles_PokecenterJohto,
    .metatileAttributes = gMetatileAttributes_PokecenterJohto,
    .callback = NULL,
};

const struct Tileset gTileset_PortJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_PortJohto,
    .palettes = gTilesetPalettes_PortJohto,
    .metatiles = gMetatiles_PortJohto,
    .metatileAttributes = gMetatileAttributes_PortJohto,
    .callback = NULL,
};

const struct Tileset gTileset_RadioTowerJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RadioTowerJohto,
    .palettes = gTilesetPalettes_RadioTowerJohto,
    .metatiles = gMetatiles_RadioTowerJohto,
    .metatileAttributes = gMetatileAttributes_RadioTowerJohto,
    .callback = NULL,
};

const struct Tileset gTileset_RuinsOfAlphJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_RuinsOfAlphJohto,
    .palettes = gTilesetPalettes_RuinsOfAlphJohto,
    .metatiles = gMetatiles_RuinsOfAlphJohto,
    .metatileAttributes = gMetatileAttributes_RuinsOfAlphJohto,
    .callback = NULL,
};

const struct Tileset gTileset_TowerDungeonJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TowerDungeonJohto,
    .palettes = gTilesetPalettes_TowerDungeonJohto,
    .metatiles = gMetatiles_TowerDungeonJohto,
    .metatileAttributes = gMetatileAttributes_TowerDungeonJohto,
    .callback = NULL,
};

const struct Tileset gTileset_TowerFastshipJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TowerFastshipJohto,
    .palettes = gTilesetPalettes_TowerFastshipJohto,
    .metatiles = gMetatiles_TowerFastshipJohto,
    .metatileAttributes = gMetatileAttributes_TowerFastshipJohto,
    .callback = NULL,
};

const struct Tileset gTileset_TowerIndoorJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TowerIndoorJohto,
    .palettes = gTilesetPalettes_TowerIndoorJohto,
    .metatiles = gMetatiles_TowerIndoorJohto,
    .metatileAttributes = gMetatileAttributes_TowerIndoorJohto,
    .callback = NULL,
};

const struct Tileset gTileset_TraditionalHouseJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TraditionalHouseJohto,
    .palettes = gTilesetPalettes_TraditionalHouseJohto,
    .metatiles = gMetatiles_TraditionalHouseJohto,
    .metatileAttributes = gMetatileAttributes_TraditionalHouseJohto,
    .callback = NULL,
};

const struct Tileset gTileset_TrainStationJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_TrainStationJohto,
    .palettes = gTilesetPalettes_TrainStationJohto,
    .metatiles = gMetatiles_TrainStationJohto,
    .metatileAttributes = gMetatileAttributes_TrainStationJohto,
    .callback = NULL,
};

const struct Tileset gTileset_UndergroundDungeonJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_UndergroundDungeonJohto,
    .palettes = gTilesetPalettes_UndergroundDungeonJohto,
    .metatiles = gMetatiles_UndergroundDungeonJohto,
    .metatileAttributes = gMetatileAttributes_UndergroundDungeonJohto,
    .callback = NULL,
};

const struct Tileset gTileset_UndergroundIndoorJohto =
{
    .isCompressed = TRUE,
    .isSecondary = TRUE,
    .tiles = gTilesetTiles_UndergroundIndoorJohto,
    .palettes = gTilesetPalettes_UndergroundIndoorJohto,
    .metatiles = gMetatiles_UndergroundIndoorJohto,
    .metatileAttributes = gMetatileAttributes_UndergroundIndoorJohto,
    .callback = NULL,
};
