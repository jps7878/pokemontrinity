@ Metatile ids for the north-east corner block of the shop, decoded from
@ data/layouts/MahoganyMart1F_Johto/map.bin and the tileset's
@ metatile_attributes.bin. include/constants/metatile_labels.h has 692 entries
@ and not one of them is a Johto tileset, so these are named here rather than
@ there; a Johto block in metatile_labels.h is an M6 tidy-up.
@
@ 632-635 is GSC's STAIRS block: pokecrystal's `changeblock 6, 2, $1e ; stairs`
@ is block $1e = 30, and the M3 converter lays GSC block n out as Trinity
@ metatiles 512 + 4n + {0 TL, 1 TR, 2 BL, 3 BR} in gTileset_TraditionalHouseJohto,
@ so block 30 = 632/633/634/635. Three of the four are attribute 0x0000
@ (MB_NORMAL); the BR quadrant 635 is 0x0061 MB_LADDER -- the walk-on warp
@ behaviour every working Johto interior staircase in this tileset uses
@ (WiseTriosRoom's (1,4) on 741 is 0x61 too) -- and BR is exactly (7,3), the
@ warp tile. No layout on this tileset and no script uses 628-635, so the
@ block is free, pre-drawn (floor with a down-staircase bottom-right) and
@ needs no tileset edit. The SHIPPED map.bin holds the plain FLOOR block
@ 528-531 (all MB_NORMAL) on (6,2) (7,2) (6,3) (7,3) instead -- M4a dropped
@ the changeblock -- which is why the staircase never warped until M7 Task 2
@ (bug-test finding #1). That floor block is now never shown: ON_LOAD
@ overwrites it in both directions (D2).
@ 588-591 is the shop's own 2x2 BOOKSHELF block, lifted verbatim from the tiles
@ directly above it at (6,0) (7,0) (6,1) (7,1). Using an existing block means
@ the covered state cannot look wrong: it is literally more shelving. Its BR
@ quadrant 591 is 0x00E1 MB_BOOKSHELF, not a warp behaviour, so while the
@ block is down the warp_event cannot fire even if the collision were cleared.
	.set METATILE_JohtoMahoganyMart_StairsTL,     632
	.set METATILE_JohtoMahoganyMart_StairsTR,     633
	.set METATILE_JohtoMahoganyMart_StairsBL,     634
	.set METATILE_JohtoMahoganyMart_StairsBR,     635
	.set METATILE_JohtoMahoganyMart_ShelfTL,      588
	.set METATILE_JohtoMahoganyMart_ShelfTR,      589
	.set METATILE_JohtoMahoganyMart_ShelfBL,      590
	.set METATILE_JohtoMahoganyMart_ShelfBR,      591

MahoganyMart1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MahoganyMart1F_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MahoganyMart1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MahoganyMart1F_OnFrame
	.byte 0

@ ============================================================================
@ Trinity M4b S7 -- MAHOGANY MART 1F, populated from zero (M4a shipped this map
@ with no objects at all). Adapts pokecrystal maps/MahoganyMart1F.asm.
@
@ ---------------------------------------------------------------------------
@ THE SETMETATILE DOOR PATTERN (D1-D5) -- the template S8 copies for the
@ GOLDENROD UNDERGROUND shutters and the RADIO TOWER's Card Key door.
@ ---------------------------------------------------------------------------
@ D1  The door is a bg_event or a warp, never a scripted warp added at runtime:
@     warps cannot be created by script, so the warp must already exist in
@     map.json. It does -- `warp_event 7, 3 -> TEAM_ROCKET_BASE_B1F` has been in
@     this map since the M4a port. What gates it is the BEHAVIOUR of the
@     metatile underneath, NOT its collision: a walk-on warp_event fires only
@     when the tile's behaviour passes IsWarpMetatileBehavior
@     (src/field_control_avatar.c:891 in TryStartWarpEventScript; the list is
@     at :936 -- warp door, MB_LADDER, escalator, non-animated door, ...).
@     Collision only decides whether the player can step onto the tile at all.
@     That is why GSC's reveal is a changeblock to the STAIRS block and not a
@     changeblock to floor: the stairs block puts MB_LADDER on (7,3), the
@     floor block puts MB_NORMAL there, and on MB_NORMAL the warp never fires
@     however walkable the tile is.
@ D2  MAP_SCRIPT_ON_LOAD is the SINGLE AUTHORING SITE for the door's tiles.
@     (NOT ON_TRANSITION, which is right for visibility flags and fatal for
@     metatiles -- see the slot note above the handler.) It runs inside InitMap,
@     once the grid exists and before the map is drawn, so it needs NO
@     DrawWholeMapView. It authors in whichever direction the SHIPPED map.bin
@     is not -- and here that is BOTH, because the shipped block is NEITHER
@     state: it is the plain FLOOR 528-531 (walkable but MB_NORMAL, so the
@     warp is dead on it). Flag clear -> the SHELF block 588-591 (closed);
@     flag set -> the STAIRS block 632-635 (open, MB_LADDER at the warp). The
@     shipped floor block is never shown. B2F and B3F ship closed, so theirs
@     only ever OPEN.
@ D3  The opening script repeats the same setmetatile set and then calls
@     `special DrawWholeMapView`. Mid-scene the map is already on screen, so
@     that redraw is mandatory -- the ON_LOAD author's is not.
@ D4  The door flag is the door's ONLY state. Everything else (passwords, story
@     beats) is an INPUT to the script that sets it; the ON_LOAD author reads
@     the one flag and nothing else.
@ D5  A setmetatile block is authored as a WHOLE GSC block -- all four Hoenn
@     metatiles -- never a half, or the shutter is drawn half open.
@
@ ---------------------------------------------------------------------------
@ ON_TRANSITION also owns all three visibility flags (S1 rule):
@     ROCKET STAFF (2)   visible iff ARC <  5     GSC's ..._BASE_POPULATION
@     GRANNY       (1)   visible iff ARC >= 5     GSC's ..._MART_OWNERS
@     LANCE + DRAGONITE  addobject-only actors: their flag is SET on EVERY
@                        transition (S1/S3 idiom), so no new-game default is
@                        needed and they can never spawn from the template --
@                        which matters here, because their tiles (4,6) and
@                        (3,6) sit directly above the two door tiles.
@ ============================================================================
@ D2 SLOT NOTE (M4b S9 fix round -- systemic, applied to all eight Trinity
@ metatile authors). Metatile authoring MUST live in MAP_SCRIPT_ON_LOAD, never
@ MAP_SCRIPT_ON_TRANSITION. RunOnTransitionMapScript() runs IMMEDIATELY BEFORE
@ InitMap() on both map-load paths (src/overworld.c:876-877, :945-954), and
@ InitMap -> InitMapLayoutData (src/fieldmap.c:96-103) CpuFastFill16s the whole
@ backup grid to MAPGRID_UNDEFINED and CpuCopy16s the ROM layout back over it --
@ so a setmetatile issued from ON_TRANSITION is erased before a single frame is
@ drawn. ON_LOAD is the LAST statement of InitMap (src/fieldmap.c:71), i.e. it
@ runs once the grid exists, AND of InitMapFromSavedGame (:80), so it also
@ covers continue-from-save, which ON_TRANSITION never runs on at all. Vanilla's
@ own metatile authors use exactly this slot (MauvilleCity_Gym, ShoalCave_*,
@ SootopolisCity_Gym_1F, AncientTomb). Still no DrawWholeMapView needed:
@ InitViewGraphics -> InitMapView -> DrawWholeMapView (src/overworld.c:575-580,
@ :2368) runs later in the same load. qa_sweep.py check 7 is the regression gate.
MahoganyMart1F_OnLoad:
	call MahoganyMart1F_EventScript_AuthorStaircase
	end

MahoganyMart1F_OnTransition:
	setflag FLAG_TRINITY_J_MART_LANCE_HIDE
	call MahoganyMart1F_EventScript_SetStaffVisibility
	end

MahoganyMart1F_EventScript_SetStaffVisibility::
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 5, MahoganyMart1F_EventScript_ShowGranny
	clearflag FLAG_TRINITY_J_MART_ROCKETS_HIDE
	setflag FLAG_TRINITY_J_MART_GRANNY_HIDE
	return

MahoganyMart1F_EventScript_ShowGranny::
	setflag FLAG_TRINITY_J_MART_ROCKETS_HIDE
	clearflag FLAG_TRINITY_J_MART_GRANNY_HIDE
	return

@ D2 (authored from ON_LOAD -- see the slot note above).
@ The shipped map.bin has the staircase block as plain walkable floor with no
@ warp behaviour, which is neither state, so BOTH directions are authored:
@ while the staircase has not been uncovered, cover it with the shop's own
@ shelving (impassable); once it has, write GSC's stairs block, whose BR
@ quadrant 635 is MB_LADDER at the warp tile (7,3), passable. No
@ DrawWholeMapView here -- this runs before the map is drawn.
MahoganyMart1F_EventScript_AuthorStaircase::
	goto_if_set FLAG_TRINITY_J_MART_STAIRS, MahoganyMart1F_EventScript_StaircaseAlreadyOpen
	setmetatile 6, 2, METATILE_JohtoMahoganyMart_ShelfTL, TRUE
	setmetatile 7, 2, METATILE_JohtoMahoganyMart_ShelfTR, TRUE
	setmetatile 6, 3, METATILE_JohtoMahoganyMart_ShelfBL, TRUE
	setmetatile 7, 3, METATILE_JohtoMahoganyMart_ShelfBR, TRUE
	return

MahoganyMart1F_EventScript_StaircaseAlreadyOpen::
	setmetatile 6, 2, METATILE_JohtoMahoganyMart_StairsTL, FALSE
	setmetatile 7, 2, METATILE_JohtoMahoganyMart_StairsTR, FALSE
	setmetatile 6, 3, METATILE_JohtoMahoganyMart_StairsBL, FALSE
	setmetatile 7, 3, METATILE_JohtoMahoganyMart_StairsBR, FALSE
	return

@ ============================================================================
@ The staircase cutscene.
@
@ WHY ON_FRAME AND NOT A COORD TRIGGER. The shop's lower room is rows 6-7 all
@ eight columns wide with no chokepoint, so no coord pair can be made mandatory;
@ and the two tiles a coord pair would have to sit on, (3,6) and (4,6), are
@ DRAGONITE's and LANCE's own template tiles. ON_FRAME fires while the player is
@ still standing on the arrival warp.
@
@ THE PLAYER'S TILE IS PINNED, and that is checkable rather than assumed:
@ MAHOGANY TOWN has exactly one warp into this map (11,7 -> warp 0), and warp 0
@ here is (3,7). So the scene always opens with the player on (3,7), facing up,
@ with DRAGONITE materialising directly in their face at (3,6).
@
@ THE ON_FRAME ENTRY MATCHES A VAR THAT THE SCENE ITSELF ADVANCES.
@ TryRunOnFrameMapScript is called from ProcessPlayerFieldInput
@ (src/field_control_avatar.c:177) -- EVERY FRAME, not once per map load -- so a
@ table entry gated on a var that never changes re-arms itself forever and the
@ player never gets their input back. VAR_TRINITY_JOHTO_SCENE_MAHOGANY == 1 is
@ written by LANCE at the LAKE OF RAGE (GSC's setmapscene) and advanced to 2 by
@ the last line of this scene.
@
@ CAMERA. The viewport is 15x10 metatiles with the player on the 5th row, so at
@ (3,7) the visible rows are 3..7 -- and the staircase reveal is at y = 2, one
@ row ABOVE the window. The scene therefore walks the player up the corridor
@ behind LANCE to (4,5) before the reveal, which puts rows 1..7 on screen. That
@ is the same reason GSC uses `follow LANCE, PLAYER` here, done without moving
@ the player through an occupied tile (S4's failure mode): LANCE clears the
@ corridor first, and the PHARMACIST is shoved aside before either of them
@ walks through (4,3).
@
@ DECODES (map.bin + metatile_attributes.bin, all collision 0 elevation 3
@ unless stated): the shop is an upper room (rows 1-3), a TWO-TILE-WIDE corridor
@ at x = 4/5 rows 4-5, and a lower room (rows 6-7). (4,3) is the corridor mouth
@ and the PHARMACIST's tile; it is NOT a cut vertex, because (5,4)->(5,3) is a
@ second route into the upper room. (3,3) is his shoved-to tile, (0,6) is the
@ BLACK BELT's, and (7,3) is the staircase warp itself.
@ ============================================================================
MahoganyMart1F_OnFrame:
	map_script_2 VAR_TRINITY_JOHTO_SCENE_MAHOGANY, 1, MahoganyMart1F_EventScript_StaircaseScene
	.2byte 0

MahoganyMart1F_EventScript_StaircaseScene::
	lockall
	@ R4: both actors arrive inside the fade, so neither pops onto the floor.
	fadescreen FADE_TO_BLACK
	addobject LOCALID_JOHTO_MART_LANCE
	addobject LOCALID_JOHTO_MART_DRAGONITE
	fadescreen FADE_FROM_BLACK
	@ S1's ElmsLab idiom: buffer a delay between addobject and the first
	@ applymovement, so the sprite is fully set up before it is driven.
	delay 20
	msgbox MahoganyMart1F_Text_LanceHyperBeam, MSGBOX_DEFAULT
	closemessage
	playse SE_M_HYPER_BEAM
	applymovement LOCALID_JOHTO_MART_DRAGONITE, MahoganyMart1F_Movement_DragoniteTackle
	applymovement LOCALID_JOHTO_MART_BLACKBELT, MahoganyMart1F_Movement_BlackBeltKnockedBack
	waitmovement 0
	@ S6's cure-scene sandwich: a white flash, not a fade to black, for a
	@ POKéMON being recalled mid-scene.
	fadescreen FADE_TO_WHITE
	removeobject LOCALID_JOHTO_MART_DRAGONITE
	fadescreen FADE_FROM_WHITE
	applymovement LOCALID_JOHTO_MART_LANCE, MahoganyMart1F_Movement_LanceFaceDown
	waitmovement 0
	msgbox MahoganyMart1F_Text_LanceRadio, MSGBOX_DEFAULT
	closemessage
	@ Clear the corridor before anyone walks up it.
	applymovement LOCALID_JOHTO_MART_PHARMACIST, MahoganyMart1F_Movement_PharmacistShoved
	waitmovement 0
	applymovement LOCALID_JOHTO_MART_LANCE, MahoganyMart1F_Movement_LanceToCorner
	waitmovement 0
	applymovement LOCALID_PLAYER, MahoganyMart1F_Movement_PlayerFollows
	waitmovement 0
	msgbox MahoganyMart1F_Text_LanceStairs, MSGBOX_DEFAULT
	closemessage
	playse SE_BANG
	@ D3: the same four setmetatiles the ON_LOAD open path authors, plus the
	@ redraw that ON_LOAD does not need. StairsBR at (7,3) is MB_LADDER, the
	@ behaviour that lets warp_event 2 fire when the player steps onto it.
	setmetatile 6, 2, METATILE_JohtoMahoganyMart_StairsTL, FALSE
	setmetatile 7, 2, METATILE_JohtoMahoganyMart_StairsTR, FALSE
	setmetatile 6, 3, METATILE_JohtoMahoganyMart_StairsBL, FALSE
	setmetatile 7, 3, METATILE_JohtoMahoganyMart_StairsBR, FALSE
	special DrawWholeMapView
	delay 30
	setflag FLAG_TRINITY_J_MART_STAIRS
	msgbox MahoganyMart1F_Text_LanceSplitUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JOHTO_MART_LANCE, MahoganyMart1F_Movement_LanceDownStairs
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_JOHTO_MART_LANCE
	waitse
	@ Monotonic scene advance -- and the reason this ON_FRAME entry cannot
	@ re-fire.
	setvar VAR_TRINITY_JOHTO_SCENE_MAHOGANY, 2
	releaseall
	end

@ (3,6): a lunge west and back. GSC's fix_facing / big_step LEFT / big_step
@ RIGHT, minus the facing lock, which Emerald's walk_fast_* does not need.
MahoganyMart1F_Movement_DragoniteTackle:
	walk_fast_left
	walk_fast_right
	step_end

@ (1,6) -> (0,6), decoded collision 0, then a stunned look around.
MahoganyMart1F_Movement_BlackBeltKnockedBack:
	walk_fast_left
	face_down
	face_left
	face_up
	step_end

MahoganyMart1F_Movement_LanceFaceDown:
	face_down
	step_end

@ (4,3) -> (3,3). Decoded collision 0. Clears the corridor mouth.
MahoganyMart1F_Movement_PharmacistShoved:
	walk_fast_left
	face_right
	step_end

@ (4,6) -> (4,5) -> (4,4) -> (4,3) -> (5,3) -> (6,3), then face the corner.
@ Every tile decoded collision 0, elevation 3.
MahoganyMart1F_Movement_LanceToCorner:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

@ (3,7) -> (3,6) -> (4,6) -> (4,5). Puts the reveal at y = 2 inside the camera
@ window (rows 1..10 from y = 5).
@ DELIBERATELY UP-FIRST, and that ordering is the safety margin. The arrival
@ tile is pinned by construction -- MAHOGANY TOWN has exactly one warp into this
@ shop and it lands on warp 0, (3,7) -- but this milestone's gate is a clean
@ compile and a review, not a play-test, so the walk is written to survive being
@ wrong about it: from (4,7) the same three steps give (4,6) -> (5,6) -> (5,5),
@ every tile decoded collision 0, and (5,5) frames the reveal just as well as
@ (4,5) does. There is no start tile in this room from which this movement walks
@ into a wall.
MahoganyMart1F_Movement_PlayerFollows:
	walk_up
	walk_right
	walk_up
	face_up
	step_end

@ (6,3) -> (7,3), the staircase tile itself.
MahoganyMart1F_Movement_LanceDownStairs:
	walk_right
	step_end

@ ============================================================================
@ The shopkeepers. Both carry GSC's EVENT_TEAM_ROCKET_BASE_POPULATION, the same
@ flag as every grunt downstairs -- these two ARE hideout staff, and they go
@ when the hideout goes.
@
@ THE JUNK SHELF IS THE CLUE. GSC's MART_MAHOGANY_1 is TINYMUSHROOM,
@ SLOWPOKETAIL, POKé BALL, POTION -- a fence's inventory, and the tail is the
@ AZALEA poaching loot from S3's SLOWPOKE WELL. ITEM_SLOWPOKE_TAIL does not
@ exist in this build, so the shelf keeps the mushroom (the same loot class, and
@ a 500 price on a shelf next to a POTION is its own joke) and the BLACK BELT
@ carries the rest of the clue in dialogue. GRANNY's MART_MAHOGANY_2 is the real
@ shop, item for item.
@
@ PRICES NEED NO WORK: pokemart has no per-shop override and GetItemPrice reads
@ gItemsInfo[item].price (S4's Emporium lesson).
@ ============================================================================
MahoganyMart1F_EventScript_Pharmacist::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_MART_STAIRS, MahoganyMart1F_EventScript_PharmacistCaught
	msgbox MahoganyMart1F_Text_PharmacistWelcome, MSGBOX_DEFAULT
	message gText_HowMayIServeYou
	waitmessage
	pokemart MahoganyMart1F_PokemartFront
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

MahoganyMart1F_EventScript_PharmacistCaught::
	msgbox MahoganyMart1F_Text_PharmacistCaught, MSGBOX_DEFAULT
	release
	end

MahoganyMart1F_EventScript_BlackBelt::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_MART_STAIRS, MahoganyMart1F_EventScript_BlackBeltCaught
	msgbox MahoganyMart1F_Text_BlackBelt, MSGBOX_DEFAULT
	release
	end

MahoganyMart1F_EventScript_BlackBeltCaught::
	msgbox MahoganyMart1F_Text_BlackBeltCaught, MSGBOX_DEFAULT
	release
	end

@ GRANNY stands at (1,3), BEHIND the counter at (2,3) -- the MB_COUNTER idiom
@ (S4): GetInteractedObjectEventScript looks one tile further through a counter
@ (src/field_control_avatar.c:387-396). Her elevation is 3, the PLAYER's floor,
@ NOT the counter's 0; copying the counter's elevation makes an NPC both
@ unreachable and untalkable with nothing in any tool output to show for it.
MahoganyMart1F_EventScript_Granny::
	lock
	faceplayer
	msgbox MahoganyMart1F_Text_GrannyWelcome, MSGBOX_DEFAULT
	message gText_HowMayIServeYou
	waitmessage
	pokemart MahoganyMart1F_PokemartGranny
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE. LANCE and DRAGONITE are addobject-only
@ actors whose flag is set on every transition, and the scene that adds them
@ never releases the player until it has removed them again, so neither object
@ is ever standing on the map with the player free to walk up to it.
MahoganyMart1F_EventScript_LanceIdle::
	msgbox MahoganyMart1F_Text_LanceIdle, MSGBOX_NPC
	end

	.align 2
MahoganyMart1F_PokemartFront:
	.2byte ITEM_TINY_MUSHROOM
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	pokemartlistend

	.align 2
MahoganyMart1F_PokemartGranny:
	.2byte ITEM_RAGE_CANDY_BAR
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_REVIVE
	pokemartlistend

MahoganyMart1F_Text_PharmacistWelcome:
	.string "Souvenirs. Local specialities.\n"
	.string "Have a look, don't touch much.$"

MahoganyMart1F_Text_PharmacistCaught:
	.string "Arrgh… You found the secret\n"
	.string "stairway…$"

MahoganyMart1F_Text_BlackBelt:
	.string "Heheh. The experiment worked like\n"
	.string "a charm.\p"
	.string "MAGIKARP are worthless. GYARADOS\n"
	.string "are big moneymakers.\p"
	.string "Same fish. Costs us nothing but a\n"
	.string "little noise.$"

MahoganyMart1F_Text_BlackBeltCaught:
	.string "Urrgh…\p"
	.string "That guy's dragon POKéMON are\n"
	.string "tough…$"

MahoganyMart1F_Text_GrannyWelcome:
	.string "You're the one who cleared them\n"
	.string "out of my back room.\p"
	.string "Sixty years I've run this shop and\n"
	.string "they had it four months.\p"
	.string "Take a look at what it's supposed\n"
	.string "to sell.$"

MahoganyMart1F_Text_LanceHyperBeam:
	.string "LANCE: DRAGONITE, HYPER BEAM.$"

MahoganyMart1F_Text_LanceRadio:
	.string "What took you, {PLAYER}?\p"
	.string "Just as I thought. That strange\n"
	.string "radio signal is coming from here.$"

MahoganyMart1F_Text_LanceStairs:
	.string "The stairs are right here.$"

MahoganyMart1F_Text_LanceSplitUp:
	.string "LANCE: {PLAYER}, we should split\n"
	.string "up to check this place.\p"
	.string "I'll go first.$"

MahoganyMart1F_Text_LanceIdle:
	.string "LANCE: Down we go.$"
