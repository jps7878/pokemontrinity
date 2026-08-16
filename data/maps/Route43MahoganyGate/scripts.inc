Route43MahoganyGate_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S7. Adapts pokecrystal Route43MahoganyGate.asm -- one OFFICER
@ with an EVENT_CLEARED_ROCKET_HIDEOUT dialogue flip, here ARC >= 5.
@
@ This gate is the ONLY walkable link between MAHOGANY TOWN and ROUTE 43, and
@ therefore between the town and the LAKE OF RAGE. Its town-side door (9,1) was
@ unreachable from every MAHOGANY door until this slice's ledge fix -- see
@ MahoganyTown/scripts.inc for the full account.
@ ============================================================================
Route43MahoganyGate_EventScript_Officer::
	lock
	faceplayer
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 5, Route43MahoganyGate_EventScript_OfficerAfter
	msgbox Route43MahoganyGate_Text_Officer, MSGBOX_DEFAULT
	release
	end

Route43MahoganyGate_EventScript_OfficerAfter::
	msgbox Route43MahoganyGate_Text_OfficerAfter, MSGBOX_DEFAULT
	release
	end

Route43MahoganyGate_Text_Officer:
	.string "Only people headed up to the LAKE\n"
	.string "OF RAGE have come through here\l"
	.string "lately. Every one of them.\p"
	.string "Sightseers, mostly. And some who\n"
	.string "were not.$"

Route43MahoganyGate_Text_OfficerAfter:
	.string "Nobody goes up to the LAKE OF\n"
	.string "RAGE these days.\p"
	.string "Funny how quickly a place stops\n"
	.string "being interesting once it stops\l"
	.string "being frightening.$"
