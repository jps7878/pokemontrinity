@ M5a T4: Kanto Centers functional (heal + respawn). Vanilla nurse shape,
@ copied verbatim from AzaleaPokecenter1F/scripts.inc (M4b S11B's own
@ template). Nurse (7,2), counter (7,3) and respawn/interact tile (7,4) are
@ walkability-decoded from LAYOUT_POKEMON_CENTER_1F_KANTO's map.bin +
@ metatile_attributes.bin, shared verbatim by all 11 Kanto Centers this task
@ ports -- see task-4-report.md for the decode.
CeruleanCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_1F_OnTransition
	.byte 0

CeruleanCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end

CeruleanCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_KANTO_CERULEAN_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
