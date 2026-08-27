GoldenrodMagnetTrainStation_MapScripts::
	.byte 0

GoldenrodMagnetTrainStation_EventScript_Officer::
	msgbox GoldenrodMagnetTrainStation_Text_Officer, MSGBOX_NPC
	end

GoldenrodMagnetTrainStation_Text_Officer:
	.string "I've lived in JOHTO my whole life.\nNever thought I'd meet someone\lfrom HOENN way out here.$"

@ ============================================================================
@ Trinity M5a T5 stubbed this attendant, gated OFF, and flagged the Kanto
@ terminus forward to M5b S2 (task-5-report.md): no Saffron-side station
@ existed among the 269 ported maps, so the pass-holder branch was a literal
@ placeholder. M5b S2 builds SaffronMagnetTrainStation and writes
@ FLAG_TRINITY_K_TRAIN_PASS's one setflag site there -- this MUST-REPLACE
@ edit is that placeholder becoming the real service. The platform doors
@ (6,5)/(11,5) stay the shipped decorative self-warp (M3 port state,
@ unchanged) -- the ride mechanism is this attendant's own scripted warp,
@ not a raw door tile. This map's own layout is untouched throughout; the
@ Saffron terminus reuses a DIFFERENT, Kanto-exclusive layout
@ (LAYOUT_HOUSE1_KANTO, not this map's own Johto one -- see
@ SaffronMagnetTrainStation/scripts.inc's header for the full reasoning,
@ a tooling-safety correction caught during implementation), landing tile
@ (7,3), decoded col=0 elev=3 MB_NORMAL, clear of that map's attendant and
@ door band.
@ ============================================================================
GoldenrodMagnetTrainStation_EventScript_Attendant::
	lock
	faceplayer
	goto_if_unset FLAG_TRINITY_K_TRAIN_PASS, GoldenrodMagnetTrainStation_EventScript_AttendantNoPass
	msgbox GoldenrodMagnetTrainStation_Text_AttendantOfferRide, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodMagnetTrainStation_EventScript_RideToSaffron
	msgbox GoldenrodMagnetTrainStation_Text_AttendantDecline, MSGBOX_DEFAULT
	release
	end

GoldenrodMagnetTrainStation_EventScript_RideToSaffron::
	closemessage
	setrespawn HEAL_LOCATION_SAFFRON_CITY
	warp MAP_SAFFRON_MAGNET_TRAIN_STATION, 7, 3
	waitstate
	release
	end

GoldenrodMagnetTrainStation_EventScript_AttendantNoPass::
	msgbox GoldenrodMagnetTrainStation_Text_AttendantNoPass, MSGBOX_DEFAULT
	release
	end

GoldenrodMagnetTrainStation_Text_AttendantNoPass:
	.string "This is the MAGNET TRAIN, express\n"
	.string "to SAFFRON CITY, over in KANTO.\p"
	.string "You'll need a MAGNET TRAIN PASS\n"
	.string "before we can let you aboard.$"

GoldenrodMagnetTrainStation_Text_AttendantOfferRide:
	.string "PASS in hand -- the line to\n"
	.string "SAFFRON's live now.\p"
	.string "Ready to ride?$"

GoldenrodMagnetTrainStation_Text_AttendantDecline:
	.string "Whenever you're ready. The train\n"
	.string "isn't going anywhere.$"
