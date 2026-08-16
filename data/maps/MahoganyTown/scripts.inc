MahoganyTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MahoganyTown_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S7 -- MAHOGANY TOWN. Adapts pokecrystal maps/MahoganyTown.asm.
@
@ ---------------------------------------------------------------------------
@ THE LEDGE THAT SEALED THE CHAPTER (read this before touching map.bin)
@ ---------------------------------------------------------------------------
@ Until this slice, `reach_check.py` reported that from EVERY door of this town
@ the ROUTE 43 gate warp at (9,1) was unreachable -- 112 tiles from each door,
@ and (9,1) in a 17-tile pocket of its own. The town's north edge is the only
@ other way out and its walkable columns are in that same pocket, so ROUTE 43,
@ the LAKE OF RAGE, LANCE, the RED GYARADOS and the whole TEAM ROCKET base were
@ cut off from the rest of the world.
@
@ Cause: GSC and HOENN put a ledge on DIFFERENT tiles. In GSC the ledge cell is
@ WALKABLE (CollisionPermissionTable marks COLL_HOP_* as LAND_TILE) and the hop
@ fires off the tile you are already standing on, landing L+2d; the tile at L+d
@ is the cliff FACE. In HOENN the ledge cell is collision 1, you stand at L-d
@ and land at L+d. M4a carried GSC's tile across unchanged, so every Johto
@ ledge's HOENN landing tile is GSC's cliff face -- a wall. Measured: HOENN and
@ KANTO have 1770 of 1896 cardinal ledges landing on a walkable tile; JOHTO had
@ 2 of 674. M4b S6's collision-1 pass was right for a tile in HOENN's ledge
@ position and turned all 672 into plain walls.
@
@ Here the load-bearing cell was (8,4): GSC's cliff edge, and the ONLY link
@ between (7,4) in the town and (8,3) on the gate plateau. (7,3) is a wall and
@ (8,5) is a wall, so nothing else joins the two halves.
@
@ Fixed by tools/johto_port/shift_ledges.py, which moves each cardinal ledge
@ one tile along its hop direction into HOENN's own position -- (8,4) becomes
@ the plateau's path metatile at collision 0 and (8,5) becomes the ledge at
@ collision 1, so the hop now lands on (8,6), exactly where GSC's landed.
@ Ten cells on this map. Result: 139 tiles from every door, and (9,1) reachable
@ from all four. Nine further Johto maps still carry the defect and are
@ escalated in the S7 report -- ROUTE 44 most urgently, since ICE PATH and
@ BLACKTHORN are still sealed from here.
@
@ ---------------------------------------------------------------------------
@ ON_TRANSITION is the SINGLE AUTHORITY for both visibility flags (S1 rule).
@     FISHER (1)  visible iff ARC <  5   -- GSC's ..._BLOCKS_GYM
@     LASS   (1)  visible iff ARC >= 5   -- GSC's EVENT_MAHOGANY_MART_OWNERS
@ The RAGECANDYBAR merchant deliberately has NO flag: GSC deletes him at the
@ RADIO TOWER takeover (RadioTowerRocketsScript), which is S8's beat. He ships
@ with a dialogue flip only, so S8 can claim a flag and add a predicate here
@ without disturbing a single S7 local id.
@ ============================================================================
MahoganyTown_OnTransition:
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 5, MahoganyTown_EventScript_AfterRaid
	clearflag FLAG_TRINITY_J_MAHOGANY_FISHER_HIDE
	setflag FLAG_TRINITY_J_MAHOGANY_LASS_HIDE
	end

MahoganyTown_EventScript_AfterRaid::
	setflag FLAG_TRINITY_J_MAHOGANY_FISHER_HIDE
	clearflag FLAG_TRINITY_J_MAHOGANY_LASS_HIDE
	end

@ ============================================================================
@ The FISHER, MOVED (6,14) -> (7,14). GSC parks him on (6,14), which is the
@ ONLY approach tile to the gym door at (6,13) -- row 13 decodes collision 1 at
@ x = 4, 5, 7 and 8 -- and uses him as a literal plug until the hideout falls.
@ The contract forbids sealing REQUIRED progression in any window, and a
@ Johto badge is required progression, so he moves one tile east onto the open
@ row-14 run and points at the LAKE by dialogue instead. This is the third
@ occurrence of S3's rule: decode the tile in front of every warp before
@ copying a GSC guard post, and expect to move it.
@ ============================================================================
MahoganyTown_EventScript_Fisher::
	msgbox MahoganyTown_Text_Fisher, MSGBOX_NPC
	end

@ ============================================================================
@ The RAGECANDYBAR merchant. GSC wraps this in a coord-triggered cut-off
@ (showemote, applymovement, follow PLAYER, one forced step left) that needs a
@ scene variable of its own; S7 ships the sales pitch on his talk script, which
@ is GSC's own second entry point into the same body (RageCandyBarMerchantScript
@ is reached both by fallthrough from MahoganyTownPokefanMScript and by scall).
@ MOVED (19,8) -> (18,8). GSC parks him on (19,8) to BLOCK the east exit until
@ the hideout falls (his event is literally ..._BLOCKS_EAST), and x=19 is this
@ map's right-edge CONNECTION BORDER COLUMN -- the tiles a player walking west
@ out of ROUTE 44 arrives on. An NPC resting there is the connection-edge
@ version of the "never rest on a warp" rule: the neighbouring map's objects do
@ not exist until the transition, so the arrival tile can be occupied at the
@ moment the player lands on it. One tile west costs nothing (row 8 is open from
@ x=2 to x=19), keeps him in the road as GSC intends, and leaves every border
@ tile clear. The tree-wide per-door sweep is what surfaced it: he was the only
@ object in JOHTO standing on a door.
@ ============================================================================
MahoganyTown_EventScript_Merchant::
	lock
	faceplayer
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 5, MahoganyTown_EventScript_MerchantSoldOut
	msgbox MahoganyTown_Text_MerchantPitch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MahoganyTown_EventScript_MerchantRefused
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, MahoganyTown_EventScript_MerchantNoMoney
	giveitem ITEM_RAGE_CANDY_BAR
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removemoney 300
	playse SE_SHOP
	msgbox MahoganyTown_Text_MerchantSavorIt, MSGBOX_DEFAULT
	release
	end

MahoganyTown_EventScript_MerchantRefused::
	msgbox MahoganyTown_Text_MerchantRefused, MSGBOX_DEFAULT
	release
	end

MahoganyTown_EventScript_MerchantNoMoney::
	msgbox MahoganyTown_Text_MerchantNoMoney, MSGBOX_DEFAULT
	release
	end

MahoganyTown_EventScript_MerchantSoldOut::
	msgbox MahoganyTown_Text_MerchantSoldOut, MSGBOX_DEFAULT
	release
	end

@ The LASS points at GRANNY's real shop, which only opens once the ROCKETS who
@ were running the front are gone. GSC keeps her hidden until BLACKTHORN GYM /
@ RADIO TOWER 5F; S7 brings her forward to the raid's end, because a shop that
@ nobody in town mentions is a shop nobody finds.
MahoganyTown_EventScript_Lass::
	msgbox MahoganyTown_Text_Lass, MSGBOX_NPC
	end

MahoganyTown_EventScript_Gramps::
	lock
	faceplayer
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 5, MahoganyTown_EventScript_GrampsAfter
	msgbox MahoganyTown_Text_Gramps, MSGBOX_DEFAULT
	release
	end

MahoganyTown_EventScript_GrampsAfter::
	msgbox MahoganyTown_Text_GrampsAfter, MSGBOX_DEFAULT
	release
	end

MahoganyTown_EventScript_Sign::
	msgbox MahoganyTown_Text_Sign, MSGBOX_SIGN
	end

MahoganyTown_EventScript_RagecandybarSign::
	msgbox MahoganyTown_Text_RagecandybarSign, MSGBOX_SIGN
	end

MahoganyTown_EventScript_MahoganyGymSign::
	msgbox MahoganyTown_Text_MahoganyGymSign, MSGBOX_SIGN
	end

MahoganyTown_EventScript_PokecenterSign::
	msgbox MahoganyTown_Text_PokecenterSign, MSGBOX_SIGN
	end

MahoganyTown_Text_Gramps:
	.string "Are you off to see the GYARADOS\n"
	.string "rampage at the LAKE?\p"
	.string "It's a bad omen. The old stories\n"
	.string "say that lake was DUG by angry\l"
	.string "GYARADOS. Dug, mind you.$"

MahoganyTown_Text_GrampsAfter:
	.string "The MAGIKARP have come back to\n"
	.string "the LAKE OF RAGE.\p"
	.string "That's good news for the anglers,\n"
	.string "and better news for my nerves.$"

MahoganyTown_Text_Fisher:
	.string "Since you came this far, take the\n"
	.string "time to do some sightseeing.\p"
	.string "Head north and look at the LAKE\n"
	.string "OF RAGE. Right now.\p"
	.string "The water up there has gone\n"
	.string "wrong, and nobody will say how.$"

MahoganyTown_Text_Lass:
	.string "Visit Grandma's shop. She sells\n"
	.string "things nobody else has.\p"
	.string "She's been shut for months. Those\n"
	.string "men were minding it for her, she\l"
	.string "said. Minding it.$"

MahoganyTown_Text_MerchantPitch:
	.string "Hiya! New in MAHOGANY TOWN?\p"
	.string "Then you should try a yummy\n"
	.string "RAGECANDYBAR!\p"
	.string "Right now it can be yours for\n"
	.string "just 300. Want one?$"

MahoganyTown_Text_MerchantSavorIt:
	.string "Good! Savor it!$"

MahoganyTown_Text_MerchantRefused:
	.string "Oh, fine then…$"

MahoganyTown_Text_MerchantNoMoney:
	.string "You don't have enough money.$"

MahoganyTown_Text_MerchantSoldOut:
	.string "RAGECANDYBAR's sold out.\p"
	.string "Word got round about the LAKE and\n"
	.string "the whole street bought me out.\p"
	.string "I'm packing up. Don't bother me,\n"
	.string "kiddo.$"

MahoganyTown_Text_Sign:
	.string "MAHOGANY TOWN\pWelcome to the\nHome of the Ninja$"

MahoganyTown_Text_RagecandybarSign:
	.string "While visiting\nMAHOGANY TOWN, try\la RAGECANDYBAR!$"

MahoganyTown_Text_MahoganyGymSign:
	.string "MAHOGANY TOWN\nPOKéMON GYM\lLEADER: PRYCE\pThe Teacher of\nWinter's Harshness$"

MahoganyTown_Text_PokecenterSign:
	.string "Heal Your POKéMON!\nPOKéMON CENTER$"
