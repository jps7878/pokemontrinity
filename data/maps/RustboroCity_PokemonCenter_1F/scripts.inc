RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "My POKéMON has a NAIVE nature, and my\n"
	.string "friend's has a JOLLY nature.\p"
	.string "It's fascinating how POKéMON have\n"
	.string "personalities!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Just like people, there are male and\n"
	.string "female POKéMON.\p"
	.string "But no one seems to have any idea how\n"
	.string "they're different.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "The man next door gave me an HM!\p"
	.string "I used it to teach my POKéMON how to\n"
	.string "CUT down skinny trees.$"

RustboroCity_PokemonCenter_1F_EventScript_StarterRumor::
	lock
	faceplayer
	goto_if_eq VAR_STARTER_TRIO, 0, RustboroCity_PokemonCenter_1F_EventScript_StarterRumorHoenn
	msgbox RustboroCity_PokemonCenter_1F_Text_StarterRumor, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_StarterRumorHoenn::
	msgbox RustboroCity_PokemonCenter_1F_Text_StarterRumorHoenn, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonCenter_1F_Text_StarterRumor:
	.string "Rumor is the little Pokémon that\n"
	.string "trainers start with turn up wild\l"
	.string "in Hoenn--but they're shy!\p"
	.string "I've heard of TREECKO on Route\n"
	.string "102, MUDKIP down on Route 104,\l"
	.string "and TORCHIC up on Route 112.$"

RustboroCity_PokemonCenter_1F_Text_StarterRumorHoenn:
	.string "You started with a Hoenn Pokémon,\n"
	.string "so you know how rare they can be\l"
	.string "in the tall grass!$"

