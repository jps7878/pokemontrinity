CianwoodCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodCity_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S6 -- CIANWOOD CITY. SUICUNE, GLIMPSE 2.
@
@ THE BEAST-CUTSCENE SHAPE (B1-B5) from data/maps/BurnedTowerB1F/scripts.inc,
@ whose header carries the clauses. Applied here:
@
@ B1  ONE OBJ_EVENT_GFX_SPECIES(SUICUNE) object on ONE _HIDE flag, its window
@     authored by ON_TRANSITION off a scene var with EXACT equality:
@       SUICUNE is visible iff VAR_TRINITY_JOHTO_SCENE_WESTCOAST == 1.
@     The arming write 0 -> 1 lives in the SAME transition and runs FIRST, per
@     S4's ordering pin (a var write placed after a visibility call reads stale
@     and lags the flip by a whole map load). It is guarded twice: goto_if_ge
@     makes it once-only and monotonic (the S1 arc-write rule -- never a bare
@     re-runnable setvar), and FLAG_TRINITY_J_BEASTS_AWAKENED means GLIMPSE 2
@     CAN NEVER PRECEDE GLIMPSE 1. The scene itself writes 1 -> 2 and is gated
@     on == 1, so it disarms itself and cannot re-fire.
@
@ B2  THE TRIGGER AND THE CAMERA. GSC uses one coord_event at (11,16). S6 uses
@     two -- (11,16) and (11,15) -- both on the same var/value, both entering
@     the same body. (11,15) is the ONE-TILE-WIDE neck into the lookout nook
@     ((10,15) and (12,15) decode collision 1), so every path into (11,14)
@     crosses it, and (11,16) is that neck's mouth and GSC's own tile. The
@     player's tile is therefore one of exactly two, and the camera window
@     (rows playerY-4..playerY+5, columns playerX-7..playerX+7) is checked for
@     both: from (11,15) rows 11..20 columns 4..18, from (11,16) rows 12..21
@     columns 4..18. Every choreography tile below is y in {14,16,17} and
@     x in {10..15}. Inside both.
@     HONEST NOTE ON MISSABILITY: the north beach is optional in this build --
@     the only thing up here is the POKé SEER'S HOUSE at (5,17), approached from
@     (5,18) along row 18 without ever touching row 16. GSC's single-tile
@     trigger is equally optional. Rather than paper over that with a six-tile
@     bank across row 16 (which would shrink the shared camera window to
@     x in [6,15] and force the flee path off the water), the POKéFAN M below
@     gains a beasts-awakened branch pointing at the north rocks.
@
@ B3  DECODE THE BEHAVIOUR, NOT JUST THE COLLISION BIT, for every tile the
@     choreography touches:
@       (10,14) col 0 elev 3 MB_JUMP_SOUTH   SUICUNE's perch -- GSC's own tile
@       (10,15) col 1                        the ledge face -- JUMPED OVER, never occupied
@       (10,16) col 0 elev 3 MB_NORMAL       the landing
@       (10,17) (11,17) (12,17) (13,17)      col 0 elev 3 MB_NORMAL
@       (14,17) (15,17)                      col 0 elev 1 MB_POND_WATER
@     Flee beat = applymovement -> playse SE_WARP_OUT -> removeobject, and the
@     R4 fade is deliberately NOT used: the disappearance is diegetic and GSC
@     covers it with exactly this sound (S5's documented deviation).
@
@ B4  The player is NEVER moved, only faced.
@ B5  The scene's only durable outputs are one story flag and one monotonic
@     scene-var advance. No roamer, no encounter, no lair -- S10 owns those.
@
@ WHY (10,14) IS SAFE TO STAND A LEGENDARY ON. It is CIANWOOD's single ledge
@ cell (MB_JUMP_SOUTH), and after the S6 fix round every Johto ledge carries
@ COLLISION 1, as vanilla HOENN's 1973 ledge cells always have. So the tile is
@ impassable outright: the only thing that can ever put the player on a ledge is
@ ShouldJumpLedge, which fires only for a hop in the tile's own direction, and
@ the tile the southward hop would come FROM -- (10,13) -- is itself collision 1.
@ No approach exists, walking or hopping. reach_check agrees and reports (10,14)
@ UNREACHABLE with ZERO objects placed, so the beast costs 0 tiles of
@ walkability.
@ (Historical note, because the first version of this comment leaned on the
@ weaker fact: before that fix Johto's ledges shipped at collision 0, so the
@ player COULD have walked onto (10,14) laterally, and the invariant that
@ actually protected the beat was the coord-neck removal -- the scene fires and
@ removeobject's SUICUNE before the player can round the cliff. That invariant
@ still stands; it is simply no longer the load-bearing one.)
@
@ THREE ENGINE FACTS THIS SCENE DEPENDS ON, source-verified rather than assumed:
@  1. Scripted movement ignores collision, water and elevation ENTIRELY.
@     InitNpcForMovement (src/event_object_movement.c:6872-6890) is
@     SetObjectEventDirection -> MoveCoords -> ShiftObjectEventCoords ->
@     SetSpriteDataForNormalStep: no collision test, no AreElevationsCompatible,
@     no surf check. InitJump (:7232-7250) is the same shape with a displacement
@     table. That is what lets SUICUNE start on a COLLISION-1 ledge tile, leave
@     it, and run out onto MB_POND_WATER at elevation 1 from land at elevation 3
@     -- and it is the general form of the narrower fact S5 recorded when its own
@     SUICUNE stepped onto MB_IMPASSABLE_NORTH.
@  2. jump_2_down moves TWO tiles in an arc, as two separate one-tile shifts:
@     MovementAction_Jump2Down_Step0 calls InitJumpRegular(..., DIR_SOUTH,
@     JUMP_DISTANCE_FAR, JUMP_TYPE_HIGH) (src/event_object_movement.c:7343-7346),
@     which shifts sJumpInitDisplacements[JUMP_DISTANCE_FAR] = 1 tile up front,
@     and UpdateJumpAnim shifts sJumpDisplacements[JUMP_DISTANCE_FAR] = 1 more
@     at JUMP_HALFWAY (:7269-7285; tables at
@     src/data/object_events/movement_action_func_tables.h:786-795). Net (10,14)
@     -> (10,16), so the ledge face (10,15) is passed over and never occupied.
@     GSC does the same descent as TWO `fast_jump_step DOWN` commands in
@     CianwoodCitySuicuneApproachMovement off this very ledge; the net
@     displacement is identical.
@  3. The player is never on the flee path. Trigger tiles {(11,15),(11,16)};
@     path {(10,16),(10,17),(11,17),(12,17),(13,17),(14,17),(15,17)}. Disjoint
@     by construction -- the route was taken through row 17 for that reason.
@
@ EUSINE IS OUT OF CAST for this slice (S10 owns him), so GSC's `appear
@ CIANWOODCITY_EUSINE` and the MYSTICALMAN battle that follows the glimpse are
@ skipped; the scene ends where the beast leaves.
@ ============================================================================
CianwoodCity_OnTransition:
	call CianwoodCity_EventScript_ArmSuicune
	call CianwoodCity_EventScript_SetSuicuneVisibility
	end

CianwoodCity_EventScript_ArmSuicune::
	goto_if_ge VAR_TRINITY_JOHTO_SCENE_WESTCOAST, 1, CianwoodCity_EventScript_TransitionReturn
	goto_if_unset FLAG_TRINITY_J_BEASTS_AWAKENED, CianwoodCity_EventScript_TransitionReturn
	setvar VAR_TRINITY_JOHTO_SCENE_WESTCOAST, 1
	return

CianwoodCity_EventScript_TransitionReturn::
	return

CianwoodCity_EventScript_SetSuicuneVisibility::
	goto_if_eq VAR_TRINITY_JOHTO_SCENE_WESTCOAST, 1, CianwoodCity_EventScript_ShowSuicune
	setflag FLAG_TRINITY_J_SUICUNE_CIANWOOD_HIDE
	return

CianwoodCity_EventScript_ShowSuicune::
	clearflag FLAG_TRINITY_J_SUICUNE_CIANWOOD_HIDE
	return

CianwoodCity_EventScript_SuicuneGlimpse::
	lockall
	applymovement LOCALID_PLAYER, CianwoodCity_Movement_PlayerFaceNorth
	waitmovement 0
	fadeoutbgm 4
	delay 40
	msgbox CianwoodCity_Text_SomethingOnTheRocks, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JOHTO_CIANWOOD_SUICUNE, Common_Movement_ExclamationMark
	waitmovement 0
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	waitmoncry
	delay 40
	msgbox CianwoodCity_Text_ItLooksAtYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JOHTO_CIANWOOD_SUICUNE, CianwoodCity_Movement_SuicuneFlees
	waitmovement 0
	playse SE_WARP_OUT
	waitse
	removeobject LOCALID_JOHTO_CIANWOOD_SUICUNE
	setflag FLAG_TRINITY_J_SUICUNE_CIANWOOD
	setvar VAR_TRINITY_JOHTO_SCENE_WESTCOAST, 2
	delay 30
	fadedefaultbgm
	msgbox CianwoodCity_Text_GoneOverOpenWater, MSGBOX_DEFAULT
	releaseall
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE. SUICUNE only exists while
@ VAR_TRINITY_JOHTO_SCENE_WESTCOAST == 1, and it stands on (10,14), which
@ decodes MB_JUMP_SOUTH with collision 1 at (10,13): the tool reports it
@ unreachable with zero objects placed, so no walk puts the player adjacent
@ enough to face it. Written anyway, per S1 -- a legendary should never read as
@ scenery if a later slice re-opens this window. No faceplayer: it is watching
@ the sea.
CianwoodCity_EventScript_ShoreSuicune::
	lockall
	msgbox CianwoodCity_Text_ShoreSuicune, MSGBOX_DEFAULT
	releaseall
	end

CianwoodCity_Movement_PlayerFaceNorth:
	face_up
	step_end

@ (10,14) -> (10,16) over the ledge face, down to (10,17), then five tiles east
@ along the beach and out onto the open water at (15,17). See B3 above for the
@ per-tile decode.
CianwoodCity_Movement_SuicuneFlees:
	jump_2_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

CianwoodCity_EventScript_Youngster::
	msgbox CianwoodCity_Text_Youngster, MSGBOX_NPC
	end

@ GSC's own line is about the north of town, so it is the natural place to put
@ a pointer at the north-shore lookout once the beasts are loose (see B2's
@ missability note).
CianwoodCity_EventScript_PokefanM::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_BEASTS_AWAKENED, CianwoodCity_EventScript_PokefanMBeasts
	msgbox CianwoodCity_Text_PokefanM, MSGBOX_DEFAULT
	release
	end

CianwoodCity_EventScript_PokefanMBeasts::
	msgbox CianwoodCity_Text_PokefanMBeasts, MSGBOX_DEFAULT
	release
	end

CianwoodCity_EventScript_Lass::
	msgbox CianwoodCity_Text_Lass, MSGBOX_NPC
	end

@ GSC's CHUCK's wife hands over HM02 FLY once CHUCK is beaten. The Act II player
@ is the HOENN Champion and already has FLY, so the gift is skipped (logged) and
@ the beat becomes a badge-aware flavour branch on FLAG_TRINITY_BADGE13 -- a
@ read only; G7 says the badge flag has exactly one writer, and that is
@ CianwoodGym_EventScript_ChuckDefeated.
CianwoodCity_EventScript_ChucksWife::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_BADGE13, CianwoodCity_EventScript_ChucksWifeBeaten
	msgbox CianwoodCity_Text_ChucksWife, MSGBOX_DEFAULT
	release
	end

CianwoodCity_EventScript_ChucksWifeBeaten::
	msgbox CianwoodCity_Text_ChucksWifeBeaten, MSGBOX_DEFAULT
	release
	end

CianwoodCity_EventScript_Sign::
	msgbox CianwoodCity_Text_Sign, MSGBOX_SIGN
	end

CianwoodCity_EventScript_CianwoodGymSign::
	msgbox CianwoodCity_Text_CianwoodGymSign, MSGBOX_SIGN
	end

CianwoodCity_EventScript_CianwoodPharmacySign::
	msgbox CianwoodCity_Text_CianwoodPharmacySign, MSGBOX_SIGN
	end

CianwoodCity_EventScript_CianwoodPhotoStudioSign::
	msgbox CianwoodCity_Text_CianwoodPhotoStudioSign, MSGBOX_SIGN
	end

CianwoodCity_EventScript_CianwoodPokeSeerSign::
	msgbox CianwoodCity_Text_CianwoodPokeSeerSign, MSGBOX_SIGN
	end

CianwoodCity_Text_Youngster:
	.string "If you use FLY,\nyou can get back\pto OLIVINE in-\nstantly.$"

CianwoodCity_Text_PokefanM:
	.string "Boulders to the\nnorth of town can\lbe crushed.\pThey may be hiding\nsomething.\pYour POKéMON could\nuse ROCK SMASH to\lbreak them.$"

CianwoodCity_Text_PokefanMBeasts:
	.string "Forget the boulders. Listen.\p"
	.string "Something came off the north rocks\n"
	.string "at dawn and went across the water.\p"
	.string "Not swimming. Across it.\p"
	.string "Go north up the beach. Northeast of\n"
	.string "the SEER's door there's a notch cut\l"
	.string "into the cliff, right at the top of\l"
	.string "the sand.\p"
	.string "Stand in it a while. See if I'm a\n"
	.string "liar.$"

CianwoodCity_Text_Lass:
	.string "Did you hear? A HOENN trainer\nbecame Champion, and now folks\lhere want to challenge them.$"

@ GSC ChucksWifeEasierToFlyText + ChucksWifeBeatChuckText.
CianwoodCity_Text_ChucksWife:
	.string "You crossed the sea to get here?\n"
	.string "You could have flown, dear.\p"
	.string "My husband's in the GYM. He's been\n"
	.string "under that waterfall since sunup\l"
	.string "and he'll be insufferable about it.\p"
	.string "Go and take him down a peg.$"

@ GSC ChucksWifeChubbyText, with the HM02 gift skipped (the Act II player has
@ FLY already).
CianwoodCity_Text_ChucksWifeBeaten:
	.string "You beat him! Oh, that's marvellous.\p"
	.string "He's been chubby lately, so all that\n"
	.string "training is finally paying off --\l"
	.string "even if it took losing to do it.\p"
	.string "Don't tell him I said so.$"

CianwoodCity_Text_Sign:
	.string "CIANWOOD CITY\pA Port Surrounded\nby Rough Seas$"

CianwoodCity_Text_CianwoodGymSign:
	.string "CIANWOOD CITY\nPOKéMON GYM\pLEADER: CHUCK\pHis Roaring Fists\nDo the Talking$"

CianwoodCity_Text_CianwoodPharmacySign:
	.string "500 Years of\nTradition\pCIANWOOD CITY\nPHARMACY\pWe Await Your\nMedicinal Queries$"

CianwoodCity_Text_CianwoodPhotoStudioSign:
	.string "CIANWOOD CITY\nPHOTO STUDIO\pTake a Snapshot as\na Keepsake!$"

CianwoodCity_Text_CianwoodPokeSeerSign:
	.string "THE POKé SEER\nAHEAD$"

CianwoodCity_Text_SomethingOnTheRocks:
	.string "The gulls went quiet all at once.\p"
	.string "Out on the rocks above the beach,\n"
	.string "something was standing very still.$"

CianwoodCity_Text_ItLooksAtYou:
	.string "It turned its head and looked\n"
	.string "straight at you.\p"
	.string "It did not run.$"

CianwoodCity_Text_GoneOverOpenWater:
	.string "It came down off the rocks in one\n"
	.string "bound, crossed the beach, and kept\l"
	.string "going -- out over open water,\l"
	.string "without ever breaking the surface.\p"
	.string "By the time the gulls started up\n"
	.string "again there was nothing to see.$"

CianwoodCity_Text_ShoreSuicune:
	.string "It has not noticed you.\p"
	.string "It is watching the sea.$"
