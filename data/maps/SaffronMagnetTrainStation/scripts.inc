@ ============================================================================
@ Trinity M5b S2 -- the KANTO terminus of the MAGNET TRAIN. New map.
@
@ CORRECTED from the sub-plan's original choice: this map first reused
@ GoldenrodMagnetTrainStation's own LAYOUT_GOLDENROD_MAGNET_TRAIN_STATION_JOHTO
@ wholesale (mirrored-architecture termini). Implementation caught a real
@ tooling conflict that reasoning missed: `gTileset_TrainStationJohto` is
@ used by exactly one map today (GoldenrodMagnetTrainStation, Johto), and
@ tools/kanto_port/fix_behaviors.py's `eligible_tilesets()` classifies a
@ tileset as "Kanto" the moment ANY Kanto map references it -- a tileset
@ used by both a Kanto map and a non-Kanto map is REJECTED outright (its own
@ safety comment: "if this ever fails the tool refuses to run"), because the
@ FRLG-vs-GSC metatile_behaviors.h enum remap that tool performs must never
@ touch a Johto (GSC-correct) tileset. Sharing the Johto station layout broke
@ that safety partition (`test_no_kanto_tileset_is_shared_with_a_non_kanto_map`
@ + the Census "298 -> 300" cell-count regression, tools/kanto_port/tests/
@ test_fix_behaviors.py). No runtime bug -- the byte data was never touched
@ -- but a real, disclosed test-suite regression that had to be fixed at the
@ source, not patched over.
@
@ Fix: reuse LAYOUT_HOUSE1_KANTO instead -- a small generic building interior
@ ALREADY Kanto-exclusive (8 existing users: VermilionCity_House1/2/3,
@ FuchsiaCity_House1/3, Route16_House, CeruleanCity_House3/4, all Kanto,
@ confirmed via `fix_behaviors.eligible_tilesets()` before switching). Same
@ "zero new tile art, decode-proven" property the sub-plan's design decision
@ was built on -- just a different, correctly-partitioned, already-shared
@ layout. Decoded via VermilionCity_House1 (an existing user of the same
@ layout) this session: 11x9 room, open floor `col=0 elev=3` throughout
@ except a small counter obstruction at (5-6,4-5); door band (3,7)/(4,7)/(5,7)
@ (the layout's own built-in 3-wide exit, (4,7) itself `MB_SOUTH_ARROW_WARP`,
@ matching Goldenrod's own south-exit idiom); attendant placed at (4,5),
@ VermilionCity_House1's own precedent tile for its one NPC. The cosmetic
@ "mirrored double platform doors" flourish is dropped with it -- it was
@ decorative self-warp dressing even on the Goldenrod side, never the real
@ ride mechanism, so nothing functional is lost.
@
@ Ride mechanism unchanged: talk-triggered, flag-gated, no lockall -- "every
@ Magnet Train ride is a ticket-check fade-warp" (spec decision 5). The shape
@ is OlivinePort_EventScript_SailorToVermilion's own (closemessage /
@ setrespawn / warp / waitstate / release, no explicit fadescreen -- the
@ engine's own transition already covers it).
@ ============================================================================
SaffronMagnetTrainStation_MapScripts::
	.byte 0

SaffronMagnetTrainStation_EventScript_Attendant::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_K_TRAIN_PASS, SaffronMagnetTrainStation_EventScript_OfferRide
	msgbox SaffronMagnetTrainStation_Text_AttendantGrantPass, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_K_TRAIN_PASS
	goto SaffronMagnetTrainStation_EventScript_OfferRide
	end

SaffronMagnetTrainStation_EventScript_OfferRide::
	msgbox SaffronMagnetTrainStation_Text_AttendantOfferRide, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SaffronMagnetTrainStation_EventScript_RideToGoldenrod
	msgbox SaffronMagnetTrainStation_Text_AttendantDecline, MSGBOX_DEFAULT
	release
	end

SaffronMagnetTrainStation_EventScript_RideToGoldenrod::
	closemessage
	setrespawn HEAL_LOCATION_GOLDENROD_CITY
	warp MAP_GOLDENROD_MAGNET_TRAIN_STATION, 9, 8
	waitstate
	release
	end

SaffronMagnetTrainStation_Text_AttendantGrantPass:
	.string "Welcome to SAFFRON STATION.\p"
	.string "The line to GOLDENROD's just gone\n"
	.string "live -- you're one of the first\l"
	.string "riders through.\p"
	.string "Here, take a MAGNET TRAIN PASS.\n"
	.string "Show it here or on the JOHTO end\l"
	.string "and you're aboard.\p"
	.string "{PLAYER} received the MAGNET\n"
	.string "TRAIN PASS.$"

SaffronMagnetTrainStation_Text_AttendantOfferRide:
	.string "Ready to ride to GOLDENROD?$"

SaffronMagnetTrainStation_Text_AttendantDecline:
	.string "Whenever you're ready. The train\n"
	.string "isn't going anywhere.$"
