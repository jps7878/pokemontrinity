RuinsOfAlphOmanyteItemRoom_MapScripts::
	.byte 0

@ Trinity M4a Task 7 fix: GSC pit-fall (ruling R2) -- item room hole -> Omanyte Word Room entry. Same shared-local-cell problem as the chambers (4 item rooms share one .blk) -- naive same-xy landing is walkable but lands in the wrong element's word room entry point; coord_event picks the correct one
@ FIX (re-review): each cell now gets its OWN destination script -- (3, 1)->FallToA (9, 7), (4, 1)->FallToB (10, 7) (Omanyte Word Room entry, GSC warp1/2 pair)
RuinsOfAlphOmanyteItemRoom_EventScript_FallToA::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_RUINS_OF_ALPH_OMANYTE_WORD_ROOM, 9, 7
	waitstate
	end

RuinsOfAlphOmanyteItemRoom_EventScript_FallToB::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_RUINS_OF_ALPH_OMANYTE_WORD_ROOM, 10, 7
	waitstate
	end

RuinsOfAlphOmanyteItemRoom_EventScript_AncientReplica::
	msgbox RuinsOfAlphOmanyteItemRoom_Text_AncientReplica, MSGBOX_SIGN
	end

RuinsOfAlphOmanyteItemRoom_EventScript_AncientReplica_2::
	msgbox RuinsOfAlphOmanyteItemRoom_Text_AncientReplica_2, MSGBOX_SIGN
	end

RuinsOfAlphOmanyteItemRoom_Text_AncientReplica:
	.string "It's a replica of\nan ancient POKé-\lMON.$"

RuinsOfAlphOmanyteItemRoom_Text_AncientReplica_2:
	.string "It's a replica of\nan ancient POKé-\lMON.$"
