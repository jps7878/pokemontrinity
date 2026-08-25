VermilionCity_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M5a T5 -- S.S. AQUA return leg, Kanto side. Dock tile decoded:
@ (23,33) MB_NORMAL elevation 3 collision 0, one tile north of the S.S. ANNE
@ dock's (22-24,34) MB_SOUTH_ARROW_WARP trio (see task-5-report.md). Same
@ gate as the OLIVINE PORT sailor's KANTO branch (FLAG_TRINITY_K_ARRIVED,
@ M5b S1's one writer) -- redundant-but-harmless here, since standing in
@ KANTO at all already implies the flag is set; kept for defensive symmetry
@ with that script. Fade-warp idiom only (YESNO -> warp -> waitstate).
@ ============================================================================
VermilionCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_unset FLAG_TRINITY_K_ARRIVED, VermilionCity_EventScript_SailorNotYet
	msgbox VermilionCity_Text_BackToOlivine, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_EventScript_SailorDecline
	closemessage
	setrespawn HEAL_LOCATION_OLIVINE_CITY
	warp MAP_OLIVINE_PORT, 7, 24
	waitstate
	release
	end

VermilionCity_EventScript_SailorDecline::
	msgbox VermilionCity_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

VermilionCity_EventScript_SailorNotYet::
	msgbox VermilionCity_Text_SailorNotYet, MSGBOX_DEFAULT
	release
	end

VermilionCity_Text_BackToOlivine:
	.string "Back to OLIVINE CITY, over in\n"
	.string "JOHTO?$"

VermilionCity_Text_SailAnotherTime:
	.string "Please sail with us another time!$"

VermilionCity_Text_SailorNotYet:
	.string "Give it time -- the crossing back\n"
	.string "to JOHTO isn't running yet.$"
