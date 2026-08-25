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
@
@ Fix round 1 (review Finding 1): lands at OLIVINE PORT (7,22), NOT (7,24).
@ (7,24) is a single-tile dead pocket -- (6,24) MB_POND_WATER, (8,24)/(7,25)
@ collision 1, and its only land exit (7,23) is permanently occupied by
@ LOCALID_OLIVINE_PORT_SAILOR (flag "0", never hidden) -- a scripted `warp`
@ places the player there regardless of IsWarpMetatileBehavior, but once
@ landed they could never walk away: a true softlock. (7,22) is the tile the
@ existing S.S. TIDAL Lilycove arrival scene already uses for the same
@ reason (OlivinePort_EventScript_AideArrival's own movement comment).
@ Re-decoded: (7,22) col=0 elev=3 MB_NORMAL. Confirmed two ways off it:
@ north to (7,21) col=0 elev=3 MB_NORMAL (plain foot exit, the corridor up
@ to the plaza); west to (6,22) MB_POND_WATER col=0 (a Surf exit -- Act III
@ players are Surf-capable, same assumption reach_check.py's default model
@ uses tree-wide). The sailor is adjacent, one tile south, for the return
@ trip (interact by facing him -- no need to stand on his tile).
@ ============================================================================
VermilionCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_unset FLAG_TRINITY_K_ARRIVED, VermilionCity_EventScript_SailorNotYet
	msgbox VermilionCity_Text_BackToOlivine, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_EventScript_SailorDecline
	closemessage
	setrespawn HEAL_LOCATION_OLIVINE_CITY
	warp MAP_OLIVINE_PORT, 7, 22
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
