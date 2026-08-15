RuinsOfAlphAerodactylChamber_MapScripts::
	.byte 0

@ Trinity M4a Task 7 fix: GSC pit-fall (ruling R2) -- chamber hole -> Inner Chamber Aerodactyl alcove. GSC's own warp_events route each element's chamber hole to a DIFFERENT Inner Chamber alcove, but all 4 chambers share this same local (3,3)/(4,3) cell (shared .blk) -- a plain setholewarp can't disambiguate between siblings, so coord_event gives each chamber its own correct per-element destination
@ FIX (re-review): each cell now gets its OWN destination script -- (3, 3)->FallToA (15, 24), (4, 3)->FallToB (16, 24) (Inner Chamber Aerodactyl alcove, GSC warp8/9-equivalent pair)
RuinsOfAlphAerodactylChamber_EventScript_FallToA::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_RUINS_OF_ALPH_INNER_CHAMBER, 15, 24
	waitstate
	end

RuinsOfAlphAerodactylChamber_EventScript_FallToB::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_RUINS_OF_ALPH_INNER_CHAMBER, 16, 24
	waitstate
	end

RuinsOfAlphAerodactylChamber_EventScript_AncientReplica::
	msgbox RuinsOfAlphAerodactylChamber_Text_AncientReplica, MSGBOX_SIGN
	end

RuinsOfAlphAerodactylChamber_EventScript_AncientReplica_2::
	msgbox RuinsOfAlphAerodactylChamber_Text_AncientReplica_2, MSGBOX_SIGN
	end

RuinsOfAlphAerodactylChamber_Text_AncientReplica:
	.string "It's a replica of\nan ancient POKé-\lMON.$"

RuinsOfAlphAerodactylChamber_Text_AncientReplica_2:
	.string "It's a replica of\nan ancient POKé-\lMON.$"
