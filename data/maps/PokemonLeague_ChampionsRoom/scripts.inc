@ ============================================================================
@ M4b S11 -- the CHAMPION'S ROOM. LANCE. The Act II capstone.
@
@ NO DOOR MACHINERY HERE, AND THAT IS VANILLA IN BOTH PARENTS. This room's entry
@ warp (6,19) is MB_SOUTH_ARROW_WARP at collision 0 -- an ordinary two-way arrow
@ warp -- and its exit (6,2) is ALREADY metatile 0x296 (Door_Mid_Open, collision
@ 0, MB_NON_ANIMATED_DOOR) in the shipped blockdata. Neither
@ EverGrandeCity_ChampionsRoom nor pokefirered's PokemonLeague_ChampionsRoom has
@ an ON_LOAD or a CloseDoor; the battle is made unavoidable by the walk-in
@ instead, which goes straight into the champion.
@
@ The one change from both parents: the ON_FRAME is gated on
@ VAR_TRINITY_JOHTO_SCENE_INDIGO == 4 rather than on VAR_TEMP_1, so it cannot
@ re-fire after the win. LANCE's own script carries the flag guard anyway --
@ S1's rule that a story talk script tests its state explicitly even when an
@ invariant already makes the bad path unreachable.
@
@ THE WALK-IN is FRLG's: walk_up x10 from the (6,19) landing to (6,9), directly
@ below LANCE at (6,8). Camera window from there is x 0..12 (clipped), y 5..14 --
@ he is on screen before the first line.
@
@ HE IS NOT A STRANGER. The player met him at the LAKE OF RAGE (S7), fought
@ beside him through the MAHOGANY base (S7's B3F cameo, "The door is west and
@ down. Go."), and has twice been told by SILVER what LANCE said about love and
@ trust (S7, S8). So the pre-battle is short: GSC's own "There's no need for
@ words now" is literally his line.
@
@ HE WALKS THE PLAYER TO THE HALL OF FAME, which is GSC's staging (LancesRoom.asm
@ ends `warpfacing UP, HALL_OF_FAME, 4, 13`) and FRLG's (`warp
@ MAP_POKEMON_LEAGUE_HALL_OF_FAME, 5, 12`). The scripted warp is also the only
@ way in: the HALL OF FAME's single warp tile decodes MB_UNUSED_23, which is not
@ a warp behaviour, so that room is a closed box entered and left by script.
@ ============================================================================

PokemonLeague_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_ChampionsRoom_OnFrame
	.byte 0

PokemonLeague_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_ChampionsRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_ChampionsRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

PokemonLeague_ChampionsRoom_OnFrame:
	map_script_2 VAR_TRINITY_JOHTO_SCENE_INDIGO, 4, PokemonLeague_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerEnter
	waitmovement 0
	delay 20
	setvar VAR_TRINITY_JOHTO_SCENE_INDIGO, 5
	goto PokemonLeague_ChampionsRoom_EventScript_LanceBattle
	end

@ FIX ROUND 1 (review M5): this is the object's own `script` field, and it now
@ carries the standard lock/faceplayer template every sitter's talk script
@ uses -- unreachable today (the walk-in above always fires first, from
@ EnterRoom's own ON_FRAME guard, and sets SCENE_INDIGO to 5 before the player
@ could ever talk to Lance directly), but it is the shape a later slice copies,
@ so it has to be correct on its own. The room's one REACHABLE path is still
@ EnterRoom's `goto` directly into _LanceBattle below: it is already inside a
@ lockall and the walk-in movement already leaves the player facing Lance, so
@ it deliberately skips lock/faceplayer rather than re-entering through them
@ with a gSelectedObjectEvent a map-script-triggered goto never set.
PokemonLeague_ChampionsRoom_EventScript_Lance::
	lock
	faceplayer
	goto PokemonLeague_ChampionsRoom_EventScript_LanceBattle

PokemonLeague_ChampionsRoom_EventScript_LanceBattle::
	goto_if_set FLAG_TRINITY_J_E4_LANCE_BEATEN, PokemonLeague_ChampionsRoom_EventScript_PostBattleIdle
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox PokemonLeague_ChampionsRoom_Text_Intro, MSGBOX_DEFAULT
	setvar VAR_LAST_TALKED, LOCALID_JOHTO_E4_LANCE
	trainerbattle_no_intro TRAINER_LANCE, PokemonLeague_ChampionsRoom_Text_Defeat
	goto PokemonLeague_ChampionsRoom_EventScript_Defeated
	end

PokemonLeague_ChampionsRoom_EventScript_Defeated::
	setflag FLAG_TRINITY_J_E4_LANCE_BEATEN
	msgbox PokemonLeague_ChampionsRoom_Text_PostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JOHTO_E4_LANCE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	msgbox PokemonLeague_ChampionsRoom_Text_ComeWithMe, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	warp MAP_POKEMON_LEAGUE_HALL_OF_FAME, 0
	waitstate
	releaseall
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE. The walk-in is gated on SCENE_INDIGO
@ == 4 and advances it to 5 before this runs, and beating LANCE warps the player
@ out of the map entirely; the only way back into this room is to redo the whole
@ gauntlet, which the INDIGO Center's transition has already reset. Kept because
@ S1's rule is that a story talk script carries its own state guard regardless.
PokemonLeague_ChampionsRoom_EventScript_PostBattleIdle::
	msgbox PokemonLeague_ChampionsRoom_Text_PostBattle, MSGBOX_DEFAULT
	releaseall
	end

PokemonLeague_ChampionsRoom_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ GSC LanceBattleIntroText, cut to the bone. He has met this trainer twice.
PokemonLeague_ChampionsRoom_Text_Intro:
	.string "LANCE: I've been waiting for you.\p"
	.string "{PLAYER}.\p"
	.string "The last time we stood in the\n"
	.string "same room, we were pulling a\l"
	.string "building apart floor by floor.\p"
	.string "This is the other half of the\n"
	.string "job. It is not a smaller one.\p"
	.string "There's no need for words now.\p"
	.string "As the most powerful trainer, and\n"
	.string "as the POKéMON LEAGUE CHAMPION --\p"
	.string "I, LANCE the dragon master,\n"
	.string "accept your challenge!$"

@ GSC LanceBattleWinText.
PokemonLeague_ChampionsRoom_Text_Defeat:
	.string "…It's over.\p"
	.string "But it's an odd feeling.\p"
	.string "I'm not angry that I lost.\n"
	.string "In fact, I feel happy.\p"
	.string "Happy that I witnessed the rise\n"
	.string "of a great new CHAMPION!$"

@ THE ACT II CAPSTONE. GSC's LanceBattleAfterText opens it; the rest is the act
@ closing its own accounts -- the MAHOGANY raid, G walking out of the RADIO TOWER
@ east and unchallenged (RadioTower5F_Text_Giovanni2, "Come east when you're
@ finished"), and what a LEAGUE title is and is not.
@ BADGE-AGNOSTIC throughout (S8's I1): not one line counts badges.
PokemonLeague_ChampionsRoom_Text_PostBattle:
	.string "…Whew.\p"
	.string "You have become truly powerful,\n"
	.string "{PLAYER}.\p"
	.string "Your POKéMON have responded to\n"
	.string "your strong and upstanding\l"
	.string "nature.\p"
	.string "Now. The part you came for, and\n"
	.string "the part you didn't.\p"
	.string "We took MAHOGANY apart together.\n"
	.string "We took the RADIO TOWER back.\p"
	.string "And a man walked out of the fifth\n"
	.string "floor past two of us, gave you\l"
	.string "his name, and went east.\p"
	.string "I couldn't follow him.\n"
	.string "I want you to understand why.\p"
	.string "The LEAGUE is a jurisdiction. It\n"
	.string "ends at the border, and KANTO is\l"
	.string "on the other side of it.\p"
	.string "A CHAMPION's title is not a\n"
	.string "badge. It is a door that opens in\l"
	.string "places a badge doesn't.\p"
	.string "You just earned one.$"

PokemonLeague_ChampionsRoom_Text_ComeWithMe:
	.string "LANCE: Come with me.\p"
	.string "There's a room through here that\n"
	.string "only ever gets used twice a\l"
	.string "decade.\p"
	.string "Today it gets used once.$"
