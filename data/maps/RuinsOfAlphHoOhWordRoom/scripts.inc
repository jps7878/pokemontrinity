RuinsOfAlphHoOhWordRoom_MapScripts::
	.byte 0

@ Trinity M4a Task 7 fix: GSC pit-fall (ruling R2) -- word room hole -> Inner Chamber HoOh alcove (same target as HoOh's chamber hole). Naive same-xy landing on Inner Chamber is walkable-but-wrong-alcove for 3 of the 4 rooms and outright WALL-blocked for Omanyte's -- coord_event used for all 4 for consistency and correctness
RuinsOfAlphHoOhWordRoom_EventScript_Fall::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_RUINS_OF_ALPH_INNER_CHAMBER, 3, 15
	waitstate
	end
