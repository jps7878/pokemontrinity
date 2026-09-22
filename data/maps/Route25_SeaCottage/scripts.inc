Route25_SeaCottage_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M5b S3 -- BILL, at his SEA COTTAGE. Not the same BILL location as
@ BillsFamilysHouse (Goldenrod, M4b S4, JOHTO) -- KANTO's own Bill lives here,
@ FRLG's own tile (7,5) (pokefirered/data/maps/Route25_SeaCottage/map.json),
@ decoded col 0 elev 3 MB_NORMAL in this build too. FRLG's own beat here is a
@ whole Bill-turns-into-Clefairy sidequest (LOCALID_BILL_CLEFAIRY, its own
@ Cinnabar-lab detour) -- NOT ported; out of scope for a flavor pass. One
@ flavor-only NPC, OBJ_EVENT_GFX_SCIENTIST_1 (BillsFamilysHouse's own
@ no-dedicated-sprite substitution, reused for consistency).
@ ============================================================================
Route25_SeaCottage_EventScript_Bill::
	msgbox Route25_SeaCottage_Text_Bill, MSGBOX_NPC
	end

Route25_SeaCottage_EventScript_Computer::
	msgbox Route25_SeaCottage_Text_Computer, MSGBOX_SIGN
	end

Route25_SeaCottage_Text_Bill:
	.string "BILL: Oh -- hello! I don't get\n"
	.string "many visitors way out here.\p"
	.string "I split my time between this\n"
	.string "place and a house up in JOHTO.\l"
	.string "Something about the sea air\l"
	.string "helps me think.\p"
	.string "The STORAGE SYSTEM never really\n"
	.string "stops needing tinkering. Come\l"
	.string "back and see me anytime.$"

Route25_SeaCottage_Text_Computer:
	.string "TELEPORTER is displayed on the PC\nmonitor.$"
