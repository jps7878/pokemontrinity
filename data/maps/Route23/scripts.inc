Route23_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M5a T5 -- the seven ROUTE 23 badge-check policemen, ported from
@ pokefirered's data/maps/Route23/map.json (7 OBJ_EVENT_GFX_POLICEMAN objects,
@ all y>=35; FRLG x/y coordinates kept verbatim -- LOCALID_CASCADE_BADGE_GUARD
@ (15,149), _THUNDER_ (8,140), _RAINBOW_ (14,123), _SOUL_ (16,112), _MARSH_
@ (10,94), _VOLCANO_ (14,61), _EARTH_ (6,35)). OBJ_EVENT_GFX_POLICEMAN does
@ not exist in this tree (include/constants/event_objects.h has no such
@ define); every guard below uses the documented fallback OBJ_EVENT_GFX_MAN_5.
@
@ They check ASCENDING KANTO BADGE COUNTS by route position, not by the FRLG
@ badge name at that slot: guard 1 (southernmost, nearest ROUTE 22) wants
@ >=1 badge, guard 7 (northernmost, nearest VICTORY ROAD) wants >=7, via
@ Trinity_EventScript_CountKantoBadges (data/scripts/trinity_kanto.inc,
@ mirrors trinity_johto.inc's C-COUNT verbatim). Dialogue is deliberately
@ badge-agnostic -- it names the count needed, never which specific badges
@ the player holds.
@
@ Guards 4 and 5 (SOUL/16,112 and MARSH/10,94) stand on MB_SHALLOW_WATER at
@ the edge of ROUTE 23's river, one tile north of MB_OCEAN_WATER -- FRLG
@ fidelity, not a placement bug (decode: tools/johto_port/reach_check.py,
@ see task-5-report.md). The river itself stays Surf-only per founder
@ decision 8; these two guards are reachable on foot from either bank.
@
@ G7 DISCIPLINE: reads FLAG_TRINITY_BADGE17..24 only, never writes one.
@ ============================================================================
Route23_EventScript_Guard1::
	lock
	faceplayer
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 1, Route23_EventScript_Guard1Refuse
	msgbox Route23_Text_Guard1Pass, MSGBOX_DEFAULT
	release
	end

Route23_EventScript_Guard1Refuse::
	msgbox Route23_Text_Guard1Refuse, MSGBOX_DEFAULT
	release
	end

Route23_EventScript_Guard2::
	lock
	faceplayer
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 2, Route23_EventScript_Guard2Refuse
	msgbox Route23_Text_Guard2Pass, MSGBOX_DEFAULT
	release
	end

Route23_EventScript_Guard2Refuse::
	msgbox Route23_Text_Guard2Refuse, MSGBOX_DEFAULT
	release
	end

Route23_EventScript_Guard3::
	lock
	faceplayer
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 3, Route23_EventScript_Guard3Refuse
	msgbox Route23_Text_Guard3Pass, MSGBOX_DEFAULT
	release
	end

Route23_EventScript_Guard3Refuse::
	msgbox Route23_Text_Guard3Refuse, MSGBOX_DEFAULT
	release
	end

Route23_EventScript_Guard4::
	lock
	faceplayer
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 4, Route23_EventScript_Guard4Refuse
	msgbox Route23_Text_Guard4Pass, MSGBOX_DEFAULT
	release
	end

Route23_EventScript_Guard4Refuse::
	msgbox Route23_Text_Guard4Refuse, MSGBOX_DEFAULT
	release
	end

Route23_EventScript_Guard5::
	lock
	faceplayer
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 5, Route23_EventScript_Guard5Refuse
	msgbox Route23_Text_Guard5Pass, MSGBOX_DEFAULT
	release
	end

Route23_EventScript_Guard5Refuse::
	msgbox Route23_Text_Guard5Refuse, MSGBOX_DEFAULT
	release
	end

Route23_EventScript_Guard6::
	lock
	faceplayer
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 6, Route23_EventScript_Guard6Refuse
	msgbox Route23_Text_Guard6Pass, MSGBOX_DEFAULT
	release
	end

Route23_EventScript_Guard6Refuse::
	msgbox Route23_Text_Guard6Refuse, MSGBOX_DEFAULT
	release
	end

Route23_EventScript_Guard7::
	lock
	faceplayer
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 7, Route23_EventScript_Guard7Refuse
	msgbox Route23_Text_Guard7Pass, MSGBOX_DEFAULT
	release
	end

Route23_EventScript_Guard7Refuse::
	msgbox Route23_Text_Guard7Refuse, MSGBOX_DEFAULT
	release
	end

Route23_Text_Guard1Refuse:
	.string "Whoa there, TRAINER! This road's\n"
	.string "KANTO LEAGUE territory from here\l"
	.string "on.\p"
	.string "Come back when you've got 1 KANTO\n"
	.string "BADGE. Just the one, to start.$"

Route23_Text_Guard1Pass:
	.string "Got your first BADGE? Go on,\n"
	.string "then.$"

Route23_Text_Guard2Refuse:
	.string "Hold it. Nobody gets further up\n"
	.string "this road without proving\l"
	.string "themselves first.\p"
	.string "Come back when you've got 2 KANTO\n"
	.string "BADGES.$"

Route23_Text_Guard2Pass:
	.string "2 BADGES. Not bad. Through you\n"
	.string "go.$"

Route23_Text_Guard3Refuse:
	.string "This stretch's mine to watch, and\n"
	.string "I'm not waving you past on\l"
	.string "nothing.\p"
	.string "Come back when you've got 3 KANTO\n"
	.string "BADGES.$"

Route23_Text_Guard3Pass:
	.string "3 BADGES, confirmed. Carry on.$"

Route23_Text_Guard4Refuse:
	.string "Careful of the water there. And\n"
	.string "careful of me, too -- I don't let\l"
	.string "just anybody through.\p"
	.string "Come back when you've got 4 KANTO\n"
	.string "BADGES.$"

Route23_Text_Guard4Pass:
	.string "4 BADGES. You're making good\n"
	.string "time. Go on ahead.$"

Route23_Text_Guard5Refuse:
	.string "This close to VICTORY ROAD, we\n"
	.string "check everybody twice.\p"
	.string "Come back when you've got 5 KANTO\n"
	.string "BADGES.$"

Route23_Text_Guard5Pass:
	.string "5 BADGES. Half the LEAGUE's gyms,\n"
	.string "at least. Through you go.$"

Route23_Text_Guard6Refuse:
	.string "Not much further to VICTORY ROAD\n"
	.string "now, but you're not ready yet.\p"
	.string "Come back when you've got 6 KANTO\n"
	.string "BADGES.$"

Route23_Text_Guard6Pass:
	.string "6 BADGES. Almost there. Go on.$"

Route23_Text_Guard7Refuse:
	.string "Last checkpoint before VICTORY\n"
	.string "ROAD itself, and the strictest\l"
	.string "one.\p"
	.string "Come back when you've got 7 KANTO\n"
	.string "BADGES. All of them but the last.$"

Route23_Text_Guard7Pass:
	.string "All 7. That's every gym but\n"
	.string "VIRIDIAN.\p"
	.string "VICTORY ROAD's ahead. Good luck\n"
	.string "in there.$"
