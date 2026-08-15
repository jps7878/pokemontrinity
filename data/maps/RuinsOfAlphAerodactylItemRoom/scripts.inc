RuinsOfAlphAerodactylItemRoom_MapScripts::
	.byte 0

@ Trinity M4a Task 7 fix: GSC pit-fall (ruling R2) -- item room hole -> Aerodactyl Word Room entry. Same shared-local-cell problem as the chambers (4 item rooms share one .blk) -- naive same-xy landing is walkable but lands in the wrong element's word room entry point; coord_event picks the correct one
@ FIX (re-review): each cell now gets its OWN destination script -- (3, 1)->FallToA (9, 5), (4, 1)->FallToB (10, 5) (Aerodactyl Word Room entry, GSC warp1/2 pair)
RuinsOfAlphAerodactylItemRoom_EventScript_FallToA::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_RUINS_OF_ALPH_AERODACTYL_WORD_ROOM, 9, 5
	waitstate
	end

RuinsOfAlphAerodactylItemRoom_EventScript_FallToB::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_RUINS_OF_ALPH_AERODACTYL_WORD_ROOM, 10, 5
	waitstate
	end

RuinsOfAlphAerodactylItemRoom_EventScript_AncientReplica::
	msgbox RuinsOfAlphAerodactylItemRoom_Text_AncientReplica, MSGBOX_SIGN
	end

RuinsOfAlphAerodactylItemRoom_EventScript_AncientReplica_2::
	msgbox RuinsOfAlphAerodactylItemRoom_Text_AncientReplica_2, MSGBOX_SIGN
	end

RuinsOfAlphAerodactylItemRoom_Text_AncientReplica:
	.string "It's a replica of\nan ancient POKé-\lMON.$"

RuinsOfAlphAerodactylItemRoom_Text_AncientReplica_2:
	.string "It's a replica of\nan ancient POKé-\lMON.$"
