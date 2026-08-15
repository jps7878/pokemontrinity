RuinsOfAlphHoOhChamber_MapScripts::
	.byte 0

@ Trinity M4a Task 7 fix: GSC pit-fall (ruling R2) -- chamber hole -> Inner Chamber HoOh alcove. GSC's own warp_events route each element's chamber hole to a DIFFERENT Inner Chamber alcove, but all 4 chambers share this same local (3,3)/(4,3) cell (shared .blk) -- a plain setholewarp can't disambiguate between siblings, so coord_event gives each chamber its own correct per-element destination
RuinsOfAlphHoOhChamber_EventScript_Fall::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_RUINS_OF_ALPH_INNER_CHAMBER, 3, 15
	waitstate
	end

RuinsOfAlphHoOhChamber_EventScript_AncientReplica::
	msgbox RuinsOfAlphHoOhChamber_Text_AncientReplica, MSGBOX_SIGN
	end

RuinsOfAlphHoOhChamber_EventScript_AncientReplica_2::
	msgbox RuinsOfAlphHoOhChamber_Text_AncientReplica_2, MSGBOX_SIGN
	end

RuinsOfAlphHoOhChamber_Text_AncientReplica:
	.string "It's a replica of\nan ancient POKé-\lMON.$"

RuinsOfAlphHoOhChamber_Text_AncientReplica_2:
	.string "It's a replica of\nan ancient POKé-\lMON.$"
