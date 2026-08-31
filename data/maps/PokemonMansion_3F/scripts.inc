@ Trinity M5b S9 -- five MB_CRACKED_FLOOR_HOLE cells at (18,18)/(19,18)/(20,18)/
@ (23,18)/(24,18), unwired per check_holes.py --all. FRLG's own Mansion switch
@ puzzle (data/scripts/pokemon_mansion.inc) is out of this slice's scope (sub-plan
@ section 10, logged) -- these are wired as plain, always-live fall traps instead,
@ matching the classic Mansion "false floor" trope, safe regardless of whether the
@ switch mechanic is ever built later. Four of five land cleanly at their own
@ same-xy on 2F (decoded col0 walkable); (18,18) does not (col1, blocked) -- one
@ coord_event gives it the nearest walkable offset, (19,18), the Blackthorn "GSC
@ pit-fall ruling" precedent.
PokemonMansion_3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, PokemonMansion_3F_SetHoleWarp
	.byte 0

PokemonMansion_3F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_POKEMON_MANSION_2F
	end

PokemonMansion_3F_EventScript_FallToOffsetHole::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_POKEMON_MANSION_2F, 19, 18
	waitstate
	end

PokemonMansion_3F_EventScript_Simon::
	trainerbattle_single TRAINER_KANTO_BURGLAR_SIMON, PokemonMansion_3F_Text_SimonSeen, PokemonMansion_3F_Text_SimonBeaten
	msgbox PokemonMansion_3F_Text_SimonBeaten, MSGBOX_AUTOCLOSE
	end

PokemonMansion_3F_EventScript_Braydon::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_BRAYDON, PokemonMansion_3F_Text_BraydonSeen, PokemonMansion_3F_Text_BraydonBeaten
	msgbox PokemonMansion_3F_Text_BraydonBeaten, MSGBOX_AUTOCLOSE
	end

PokemonMansion_3F_EventScript_DiaryFeb6th::
	msgbox PokemonMansion_3F_Text_DiaryFeb6th, MSGBOX_SIGN
	end

PokemonMansion_3F_EventScript_Statue::
	msgbox PokemonMansion_3F_Text_Statue, MSGBOX_SIGN
	end

PokemonMansion_3F_Text_SimonSeen:
	.string "This place is, like, huge!$"

PokemonMansion_3F_Text_SimonBeaten:
	.string "Ayah!$"

PokemonMansion_3F_Text_BraydonSeen:
	.string "My mentor once lived here.$"

PokemonMansion_3F_Text_BraydonBeaten:
	.string "Whew! Overwhelming!$"

PokemonMansion_3F_Text_DiaryFeb6th:
	.string "Diary: Feb. 6\nMEW gave birth.\pWe named the newborn MEWTWO.$"

PokemonMansion_3F_Text_Statue:
	.string "Folks in KANTO don't get many\nvisitors from HOENN. Word is one\lof them cleaned up in JOHTO too.$"
