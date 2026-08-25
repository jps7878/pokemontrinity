Route22_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M5a T5 -- flavour half of the ROUTE 28/KANTO land gate. The real
@ enforcement is the coord_event trigger on Route28's own (39,8) tile (see
@ that map's scripts.inc); by the time a player can stand here and talk to
@ this guard, they already crossed, which only happens once
@ FLAG_TRINITY_K_ARRIVED is set. He is deliberately redundant with that
@ trigger (same double-coverage shape as ROUTE26's LeagueGateOfficer), and
@ READ-ONLY: never sets the flag himself. Badge-agnostic dialogue -- he names
@ no count, just that the road is a League matter.
Route22_EventScript_KantoGateGuard::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_K_ARRIVED, Route22_EventScript_KantoGateGuardOpen
	msgbox Route22_Text_KantoGateGuardClosed, MSGBOX_DEFAULT
	release
	end

Route22_EventScript_KantoGateGuardOpen::
	msgbox Route22_Text_KantoGateGuardOpen, MSGBOX_DEFAULT
	release
	end

Route22_Text_KantoGateGuardClosed:
	.string "This road runs west out to JOHTO,\n"
	.string "but it isn't open for crossing.\p"
	.string "The LEAGUE office has to clear it\n"
	.string "first. Nothing I can do till then.$"

Route22_Text_KantoGateGuardOpen:
	.string "Road's open. Safe travels out to\n"
	.string "JOHTO.$"
