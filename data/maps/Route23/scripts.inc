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
@ >=2 badges, guard 7 (northernmost, nearest VICTORY ROAD) wants >=8 (ALL
@ EIGHT), via Trinity_EventScript_CountKantoBadges (data/scripts/
@ trinity_kanto.inc, mirrors trinity_johto.inc's C-COUNT verbatim). Dialogue
@ is deliberately badge-agnostic -- it names the count needed, never which
@ specific badges the player holds.
@
@ THRESHOLDS 2..8, not 1..7 (founder decision, resolved 2026-08-26, final
@ review finding 1): guard N requires N+1 badges, matching pokefirered's own
@ Cascade-through-Earth checkpoint ladder (FRLG indices 2..8 -- FRLG's
@ Route 23 has no 1-badge checkpoint at all). The check stays COUNT-based,
@ not badge-specific -- open gym order is unaffected, only the numbers
@ guards 1-7 compare against moved up by one, with guard 7 now the true
@ 8-badge/all-badges gate. Talk scripts and coord_event nets share the same
@ threshold per guard (see the fix-round-1 net block below) -- both paths
@ were updated together.
@
@ Guards 4 and 5 (SOUL/16,112 and MARSH/10,94) stand on MB_SHALLOW_WATER at
@ the edge of ROUTE 23's river, one tile north of MB_OCEAN_WATER -- FRLG
@ fidelity, not a placement bug (decode: tools/johto_port/reach_check.py,
@ see task-5-report.md). The river itself stays Surf-only per founder
@ decision 8; these two guards are reachable on foot from either bank.
@
@ G7 DISCIPLINE: reads FLAG_TRINITY_BADGE17..24 only, never writes one.
@
@ M7b Task 15 (finding #6): every refusal now ENDS on the player's own count.
@ Each guard already named the number he wants; what was missing was the number
@ the player has. {STR_VAR_1} is live -- Trinity_EventScript_CountKantoBadges
@ buffers its own result (data/scripts/trinity_kanto.inc), and BOTH readers of
@ each Refuse string call it first: the talk script Route23_EventScript_Guard<N>
@ and the coord net Route23_EventScript_Guard<N>Net below.
@ ============================================================================
Route23_EventScript_Guard1::
	lock
	faceplayer
	call Trinity_EventScript_CountKantoBadges
	goto_if_lt VAR_TEMP_A, 2, Route23_EventScript_Guard1Refuse
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
	goto_if_lt VAR_TEMP_A, 3, Route23_EventScript_Guard2Refuse
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
	goto_if_lt VAR_TEMP_A, 4, Route23_EventScript_Guard3Refuse
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
	goto_if_lt VAR_TEMP_A, 5, Route23_EventScript_Guard4Refuse
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
	goto_if_lt VAR_TEMP_A, 6, Route23_EventScript_Guard5Refuse
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
	goto_if_lt VAR_TEMP_A, 7, Route23_EventScript_Guard6Refuse
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
	goto_if_lt VAR_TEMP_A, 8, Route23_EventScript_Guard7Refuse
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
	.string "Come back when you've got 2 KANTO\n"
	.string "BADGES. That's the going rate\l"
	.string "out here.\p"
	.string "You're carrying {STR_VAR_1}.$"

Route23_Text_Guard1Pass:
	.string "2 BADGES on you? Go on, then.$"

Route23_Text_Guard2Refuse:
	.string "Hold it. Nobody gets further up\n"
	.string "this road without proving\l"
	.string "themselves first.\p"
	.string "Come back when you've got 3 KANTO\n"
	.string "BADGES.\p"
	.string "You're carrying {STR_VAR_1}.$"

Route23_Text_Guard2Pass:
	.string "3 BADGES. Not bad. Through you\n"
	.string "go.$"

Route23_Text_Guard3Refuse:
	.string "This stretch's mine to watch, and\n"
	.string "I'm not waving you past on\l"
	.string "nothing.\p"
	.string "Come back when you've got 4 KANTO\n"
	.string "BADGES.\p"
	.string "You're carrying {STR_VAR_1}.$"

Route23_Text_Guard3Pass:
	.string "4 BADGES, confirmed. Carry on.$"

Route23_Text_Guard4Refuse:
	.string "Careful of the water there. And\n"
	.string "careful of me, too -- I don't let\l"
	.string "just anybody through.\p"
	.string "Come back when you've got 5 KANTO\n"
	.string "BADGES.\p"
	.string "You're carrying {STR_VAR_1}.$"

Route23_Text_Guard4Pass:
	.string "5 BADGES. You're making good\n"
	.string "time. Go on ahead.$"

Route23_Text_Guard5Refuse:
	.string "This close to VICTORY ROAD, we\n"
	.string "check everybody twice.\p"
	.string "Come back when you've got 6 KANTO\n"
	.string "BADGES.\p"
	.string "You're carrying {STR_VAR_1}.$"

Route23_Text_Guard5Pass:
	.string "6 BADGES. Three-quarters of the\n"
	.string "LEAGUE's gyms. Through you go.$"

Route23_Text_Guard6Refuse:
	.string "Not much further to VICTORY ROAD\n"
	.string "now, but you're not ready yet.\p"
	.string "Come back when you've got 7 KANTO\n"
	.string "BADGES.\p"
	.string "You're carrying {STR_VAR_1}.$"

Route23_Text_Guard6Pass:
	.string "7 BADGES. Almost there. Go on.$"

Route23_Text_Guard7Refuse:
	.string "Last checkpoint before VICTORY\n"
	.string "ROAD itself, and the strictest\l"
	.string "one.\p"
	.string "Come back when you've got 8 KANTO\n"
	.string "BADGES. Every last one of them.\p"
	.string "You're carrying {STR_VAR_1}.$"

Route23_Text_Guard7Pass:
	.string "All 8. Every gym in KANTO,\n"
	.string "beaten.\p"
	.string "VICTORY ROAD's ahead. Good luck\n"
	.string "in there.$"

@ ============================================================================
@ Trinity M5a T5 fix round 1 -- PHYSICAL badge-count nets (controller ruling,
@ Finding 4). The talk-triggered Guard1..7 scripts above are informational
@ only and do not block a walk-around; Route 23 is wide at each guard's row
@ (up to 18 walkable tiles), so a badgeless flood fill from the KANTO door
@ reaches (5,28) untouched. reach_check.py's Map class, used as a library
@ (not the CLI, which can't model coord_events), found the EXACT set of
@ "individually sufficient" bypass columns per row -- the columns that, left
@ open alone with everything else in the row blocked, still bridge south to
@ north -- and confirmed netting only those (plus the guard's own standing
@ tile) fully disconnects (5,28) from the south door with all 7 guards' nets
@ active and zero badges: see task-5-report.md fix round 1 for the flood-fill
@ evidence and t5-reach/route23-badgeless.txt for the saved run.
@
@ Guards 4/5 sit at the river (MB_SHALLOW_WATER); their nets are on the
@ MB_OCEAN_WATER surf lane one row over, at elevation 1 (decoded, matching
@ the water tiles' own elevation) -- a surfing player is caught exactly the
@ same way a walking one is, `applymovement` + `walk_down` works while
@ surfing (ordinary directional movement, not a forced-current tile).
@
@ Refusal step-back mirrors ROUTE26's LeagueGateOfficer idiom exactly
@ (data/maps/Route26/scripts.inc Route26_EventScript_LeagueGateRefuse):
@ msgbox -> closemessage -> applymovement LOCALID_PLAYER walk_down ->
@ waitmovement -> releaseall. The "NetOpen" branches are INTENTIONALLY EMPTY,
@ same idiom as Route26_EventScript_LeagueGateOpen: the trigger fires on
@ every crossing regardless of badge count (that is what makes the refusal
@ reliable), and an empty branch is what makes an already-qualified crossing
@ free. Refusal text is reused from each guard's own talk script above --
@ same tone, same count-not-name framing.
@ ============================================================================
Route23_Movement_NetStepBack:
	walk_down
	step_end

Route23_EventScript_Guard1Net::
	lockall
	call Trinity_EventScript_CountKantoBadges
	goto_if_ge VAR_TEMP_A, 2, Route23_EventScript_Guard1NetOpen
	msgbox Route23_Text_Guard1Refuse, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route23_Movement_NetStepBack
	waitmovement 0
	releaseall
	end

Route23_EventScript_Guard1NetOpen::
	end

Route23_EventScript_Guard2Net::
	lockall
	call Trinity_EventScript_CountKantoBadges
	goto_if_ge VAR_TEMP_A, 3, Route23_EventScript_Guard2NetOpen
	msgbox Route23_Text_Guard2Refuse, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route23_Movement_NetStepBack
	waitmovement 0
	releaseall
	end

Route23_EventScript_Guard2NetOpen::
	end

Route23_EventScript_Guard3Net::
	lockall
	call Trinity_EventScript_CountKantoBadges
	goto_if_ge VAR_TEMP_A, 4, Route23_EventScript_Guard3NetOpen
	msgbox Route23_Text_Guard3Refuse, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route23_Movement_NetStepBack
	waitmovement 0
	releaseall
	end

Route23_EventScript_Guard3NetOpen::
	end

Route23_EventScript_Guard4Net::
	lockall
	call Trinity_EventScript_CountKantoBadges
	goto_if_ge VAR_TEMP_A, 5, Route23_EventScript_Guard4NetOpen
	msgbox Route23_Text_Guard4Refuse, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route23_Movement_NetStepBack
	waitmovement 0
	releaseall
	end

Route23_EventScript_Guard4NetOpen::
	end

Route23_EventScript_Guard5Net::
	lockall
	call Trinity_EventScript_CountKantoBadges
	goto_if_ge VAR_TEMP_A, 6, Route23_EventScript_Guard5NetOpen
	msgbox Route23_Text_Guard5Refuse, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route23_Movement_NetStepBack
	waitmovement 0
	releaseall
	end

Route23_EventScript_Guard5NetOpen::
	end

Route23_EventScript_Guard6Net::
	lockall
	call Trinity_EventScript_CountKantoBadges
	goto_if_ge VAR_TEMP_A, 7, Route23_EventScript_Guard6NetOpen
	msgbox Route23_Text_Guard6Refuse, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route23_Movement_NetStepBack
	waitmovement 0
	releaseall
	end

Route23_EventScript_Guard6NetOpen::
	end

Route23_EventScript_Guard7Net::
	lockall
	call Trinity_EventScript_CountKantoBadges
	goto_if_ge VAR_TEMP_A, 8, Route23_EventScript_Guard7NetOpen
	msgbox Route23_Text_Guard7Refuse, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route23_Movement_NetStepBack
	waitmovement 0
	releaseall
	end

Route23_EventScript_Guard7NetOpen::
	end
