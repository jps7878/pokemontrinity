GoldenrodDeptStore5F_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S4 -- MARGINS AND CO. PREMIUM, the GOLDENROD branch.
@ Mirror of data/maps/LilycoveCity_DepartmentStore_5F/scripts.inc's
@ …_EventScript_MarginsClerk / …_Pokemart_MarginsPremium, item for item and
@ order for order. PRICES NEED NO WORK AND MUST NOT BE TOUCHED: pokemart has no
@ per-shop price override -- GetItemPrice reads gItemsInfo[item].price
@ (src/item.c), which M1 already set to the spec values. Same list, same
@ prices, by construction.
@
@ Tile (7,5). It and (8,5) (M4a's 5F clerk) are a two-slot booth: collision 0,
@ elevation 3, UNREACHABLE on foot, enclosed by MB_COUNTER tiles at (6,5),
@ (7,4), (8,4) and (9,5) (behaviour 128, decoded). Counters are talk-through:
@ GetInteractedObjectEventScript finds nothing on the faced tile, sees
@ MetatileBehavior_IsCounter and looks one tile further in the same direction
@ (src/field_control_avatar.c:387-396). So MARGINS is served facing EAST from
@ (5,5), or SOUTH from (7,3). Placing an object on an already-unreachable tile
@ changes walkability by exactly nothing.
@
@ ELEVATION NUANCE -- the part that silently breaks a counter NPC.
@ The lookup is GetObjectEventIdByPosition(x, y, position->elevation), and it
@ requires ObjectEventDoesElevationMatch (src/event_object_movement.c:3352-3374).
@ `position->elevation` is the PLAYER'S OWN elevation, NOT the faced tile's --
@ GetInFrontOfPlayerPosition sets it from PlayerGetElevation()
@ (src/field_control_avatar.c:264-274). So the NPC behind the counter must
@ share the elevation of the FLOOR THE PLAYER STANDS ON, and the counter tile's
@ own elevation is never compared at all. Here: service tile (5,5) elev 3,
@ MARGINS (7,5) elev 3 -- match. The counter at (6,5) decodes elev 0, which is
@ irrelevant. Copying that 0 onto the NPC would make him unreachable AND
@ untalkable, with nothing in any tool output to show for it.
@ ============================================================================
GoldenrodDeptStore5F_EventScript_MarginsClerk::
	lock
	faceplayer
	msgbox GoldenrodDeptStore5F_Text_MarginsWelcome, MSGBOX_DEFAULT
	message gText_HowMayIServeYou
	waitmessage
	pokemart GoldenrodDeptStore5F_Pokemart_MarginsPremium
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GoldenrodDeptStore5F_Pokemart_MarginsPremium:
	.2byte ITEM_RARE_CANDY
	.2byte ITEM_MASTER_BALL
	.2byte ITEM_PP_MAX
	.2byte ITEM_HP_UP
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CALCIUM
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HEART_SCALE
	.2byte ITEM_ABILITY_CAPSULE
	pokemartlistend

GoldenrodDeptStore5F_EventScript_Clerk::
	msgbox GoldenrodDeptStore5F_Text_Clerk, MSGBOX_NPC
	end

GoldenrodDeptStore5F_EventScript_Lass::
	msgbox GoldenrodDeptStore5F_Text_Lass, MSGBOX_NPC
	end

GoldenrodDeptStore5F_EventScript_Mike::
	msgbox GoldenrodDeptStore5F_Text_Mike, MSGBOX_NPC
	end

GoldenrodDeptStore5F_EventScript_PokefanM::
	msgbox GoldenrodDeptStore5F_Text_PokefanM, MSGBOX_NPC
	end

GoldenrodDeptStore5F_EventScript_Carrie::
	msgbox GoldenrodDeptStore5F_Text_Carrie, MSGBOX_NPC
	end

GoldenrodDeptStore5F_EventScript_Directory::
	msgbox GoldenrodDeptStore5F_Text_Directory, MSGBOX_SIGN
	end

@ The M1 Mr. Margins voice: booming, delighted, entirely unembarrassed about
@ the markup. The GOLDENROD branch exists because crossing a sea costs money he
@ has no intention of absorbing.
GoldenrodDeptStore5F_Text_MarginsWelcome:
	.string "OH ho ho! MARGINS and CO.\n"
	.string "PREMIUM -- GOLDENROD branch!\p"
	.string "Same shelf as LILYCOVE. Same\n"
	.string "beautiful, beautiful prices.\p"
	.string "People ask why they aren't\n"
	.string "cheaper closer to the source.\p"
	.string "Closer to the source of WHAT,\n"
	.string "I ask them. Every one of these\l"
	.string "crossed a sea in a crate that\l"
	.string "I paid for.\p"
	.string "Anything a champion could want\n"
	.string "-- for the right price!$"

GoldenrodDeptStore5F_Text_Clerk:
	.string "5F is the TM CORNER.\p"
	.string "And the gentleman behind the\n"
	.string "far counter is… a tenant.\p"
	.string "Head office approved it. I'm\n"
	.string "told his margins are excellent.$"

GoldenrodDeptStore5F_Text_Lass:
	.string "On Sundays, a lady\ncomes to check out\lPOKéMON.\pShe even gives\naway TMs!$"

GoldenrodDeptStore5F_Text_Mike:
	.string "A TM used to vanish after one\n"
	.string "use, you know.\p"
	.string "These days you can teach the\n"
	.string "same disc to a whole team.\p"
	.string "No wonder trainers are getting\n"
	.string "frightening.$"

GoldenrodDeptStore5F_Text_PokefanM:
	.string "You can't rename a\nPOKéMON you get in\la trade.\pThe name is a re-\nflection of the\poriginal trainer's\nfeelings for it.$"

GoldenrodDeptStore5F_Text_Carrie:
	.string "I came up for one TM and I've\n"
	.string "been reading the shelf for an\l"
	.string "hour.\p"
	.string "That's how they get you.$"

GoldenrodDeptStore5F_Text_Directory:
	.string "Customize Your\nPOKéMON\p5F TM CORNER$"
