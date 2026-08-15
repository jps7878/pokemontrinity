RuinsOfAlphKabutoChamber_MapScripts::
	.byte 0

@ Trinity M4a Task 7 fix: GSC pit-fall (ruling R2) -- chamber hole -> Inner Chamber Kabuto alcove. GSC's own warp_events route each element's chamber hole to a DIFFERENT Inner Chamber alcove, but all 4 chambers share this same local (3,3)/(4,3) cell (shared .blk) -- a plain setholewarp can't disambiguate between siblings, so coord_event gives each chamber its own correct per-element destination
RuinsOfAlphKabutoChamber_EventScript_Fall::
	lockall
	delay 20
	playse SE_FALL
	warp MAP_RUINS_OF_ALPH_INNER_CHAMBER, 15, 3
	waitstate
	end

RuinsOfAlphKabutoChamber_EventScript_Scientist::
	msgbox RuinsOfAlphKabutoChamber_Text_Scientist, MSGBOX_NPC
	end

RuinsOfAlphKabutoChamber_EventScript_AncientReplica::
	msgbox RuinsOfAlphKabutoChamber_Text_AncientReplica, MSGBOX_SIGN
	end

RuinsOfAlphKabutoChamber_EventScript_AncientReplica_2::
	msgbox RuinsOfAlphKabutoChamber_Text_AncientReplica_2, MSGBOX_SIGN
	end

RuinsOfAlphKabutoChamber_Text_Scientist:
	.string "My grandkids won't stop talking\nabout the new champion from over\lin HOENN. Kids these days!$"

RuinsOfAlphKabutoChamber_Text_AncientReplica:
	.string "It's a replica of\nan ancient POKé-\lMON.$"

RuinsOfAlphKabutoChamber_Text_AncientReplica_2:
	.string "It's a replica of\nan ancient POKé-\lMON.$"
