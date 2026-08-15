RuinsOfAlphKabutoItemRoom_MapScripts::
	.byte 0

@ Trinity M4a Task 7 fix: GSC pit-fall (ruling R2) -- item room hole -> Kabuto Word Room entry. Same shared-local-cell problem as the chambers (4 item rooms share one .blk) -- naive same-xy landing is walkable but lands in the wrong element's word room entry point; coord_event picks the correct one
@ FIX (re-review): each cell now gets its OWN destination script -- (3, 1)->FallToA (9, 5), (4, 1)->FallToB (10, 5) (Kabuto Word Room entry, GSC warp1/2 pair)
RuinsOfAlphKabutoItemRoom_EventScript_FallToA::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_RUINS_OF_ALPH_KABUTO_WORD_ROOM, 9, 5
	waitstate
	end

RuinsOfAlphKabutoItemRoom_EventScript_FallToB::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_RUINS_OF_ALPH_KABUTO_WORD_ROOM, 10, 5
	waitstate
	end

RuinsOfAlphKabutoItemRoom_EventScript_AncientReplica::
	msgbox RuinsOfAlphKabutoItemRoom_Text_AncientReplica, MSGBOX_SIGN
	end

RuinsOfAlphKabutoItemRoom_EventScript_AncientReplica_2::
	msgbox RuinsOfAlphKabutoItemRoom_Text_AncientReplica_2, MSGBOX_SIGN
	end

RuinsOfAlphKabutoItemRoom_Text_AncientReplica:
	.string "It's a replica of\nan ancient POKé-\lMON.$"

RuinsOfAlphKabutoItemRoom_Text_AncientReplica_2:
	.string "It's a replica of\nan ancient POKé-\lMON.$"
