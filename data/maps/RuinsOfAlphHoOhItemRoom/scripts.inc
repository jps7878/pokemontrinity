RuinsOfAlphHoOhItemRoom_MapScripts::
	.byte 0

@ Trinity M4a Task 7 fix: GSC pit-fall (ruling R2) -- item room hole -> HoOh Word Room entry. Same shared-local-cell problem as the chambers (4 item rooms share one .blk) -- naive same-xy landing is walkable but lands in the wrong element's word room entry point; coord_event picks the correct one
RuinsOfAlphHoOhItemRoom_EventScript_Fall::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_RUINS_OF_ALPH_HO_OH_WORD_ROOM, 9, 9
	waitstate
	end

RuinsOfAlphHoOhItemRoom_EventScript_AncientReplica::
	msgbox RuinsOfAlphHoOhItemRoom_Text_AncientReplica, MSGBOX_SIGN
	end

RuinsOfAlphHoOhItemRoom_EventScript_AncientReplica_2::
	msgbox RuinsOfAlphHoOhItemRoom_Text_AncientReplica_2, MSGBOX_SIGN
	end

RuinsOfAlphHoOhItemRoom_Text_AncientReplica:
	.string "It's a replica of\nan ancient POKé-\lMON.$"

RuinsOfAlphHoOhItemRoom_Text_AncientReplica_2:
	.string "It's a replica of\nan ancient POKé-\lMON.$"
