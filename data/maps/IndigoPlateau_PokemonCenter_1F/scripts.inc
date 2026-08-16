@ ============================================================================
@ M4b S11 -- the INDIGO PLATEAU POKéMON CENTER, and the ELITE FOUR reset.
@
@ THE RESPAWN HOLE THIS CLOSES. No Johto or Kanto POKéMON CENTER sets a
@ respawn: `setrespawn` appears on twenty HOENN maps and on none of the 217
@ Johto or 269 Kanto maps. FIX ROUND 1 (review I4): one Johto MAP does carry a
@ `setrespawn` outside the Center network -- OlivinePort's sailor script sets
@ HEAL_LOCATION_LILYCOVE_CITY, but only on the confirmed return-boat prompt
@ (a talk-triggered YES/NO, not anything that fires on arrival), so it never
@ contests a Center respawn and the "no Center sets one" claim above still
@ holds as written. Whiting out anywhere in Act II therefore returned the
@ player to their last HOENN heal location. For most of JOHTO that is an M4a
@ gap (measured and escalated to M6); for THIS map it is a slice requirement,
@ because "lose in the LEAGUE, restart from the Center" is vanilla's own ELITE
@ FOUR contract and vanilla implements it exactly here --
@ EverGrandeCity_PokemonLeague_1F_OnTransition's
@ `setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE`.
@ HEAL_LOCATION_INDIGO_PLATEAU is APPENDED to the enum, so no existing index
@ moves, and gSaveBlock1Ptr->lastHealLocation is a struct WarpData
@ (include/global.h:1073) written by SetLastHealLocationWarp
@ (src/overworld.c:734-738) -- the index itself is never stored, so this is
@ save-safe.
@
@ THE RESET IS GSC's OWN DESIGN, line for line:
@ IndigoPlateauPokecenter1FPrepareElite4Callback (pokecrystal/maps/
@ IndigoPlateauPokecenter1F.asm) clears every room scene, every door event and
@ all five EVENT_BEAT_ELITE_4_* on entering this Center. Putting it here rather
@ than in the tree-wide EventScript_WhiteOut (which is what vanilla HOENN does,
@ data/event_scripts.s:1084-1086) is narrower -- Act I's script is not touched.
@ FIX ROUND 1 (review M2): this comment previously also claimed the transition
@ "covers loading a save in the room" -- FALSE. CB2_ContinueSavedGame runs
@ MAP_SCRIPT_ON_LOAD, never MAP_SCRIPT_ON_TRANSITION (src/overworld.c:
@ 1972-2000), so simply continuing a save parked in this room does NOT re-run
@ this reset. Harmless in play: the Center is unreachable mid-gauntlet (the
@ league rooms are one-way, S11 report §6.2), so any save sitting here already
@ had the reset applied on the warp IN that put it there.
@
@ S6's CLEARED-FLAG RULE APPLIES AND IS THE REASON _LEAGUE_CLEARED EXISTS. Five
@ flags below are CLEARED, so the chain's terminal state can never be inferred
@ from them: they return to their starting values on every visit. The terminal
@ state is FLAG_TRINITY_J_LEAGUE_CLEARED (+ VAR_TRINITY_JOHTO_ARC == 10), which
@ nothing clears, ever.
@
@ ORDERING (S4's I3(b)): state writes first, and the arc var is deliberately NOT
@ among them -- arc 10 is written once, in the HALL OF FAME, under S1's monotonic
@ guard. This transition must never touch it.
@
@ THE CLERK IS AN MB_COUNTER NPC (S4's idiom, including the elevation half).
@ He stands on (0,7) at elevation 3, the counter (1,7) decodes MB_COUNTER at
@ elevation 0, and the player is served from (2,7) at elevation 3.
@ GetInteractedObjectEventScript looks one tile further through a counter
@ (src/field_control_avatar.c:387-396) and GetObjectEventIdByPosition compares
@ the PLAYER's elevation, not the counter's (src/event_object_movement.c:
@ 3352-3374) -- so the NPC must share the floor's elevation, not the counter's.
@ The NURSE at (13,10) is the same shape across the counter at (13,11).
@ reach_check reports both NPC tiles as unreachable and is right to; moving them
@ would be the bug (S4's rule).
@ ============================================================================

IndigoPlateau_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

IndigoPlateau_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU
	setvar VAR_TRINITY_JOHTO_SCENE_INDIGO, 0
	clearflag FLAG_TRINITY_J_E4_WILL_BEATEN
	clearflag FLAG_TRINITY_J_E4_KOGA_BEATEN
	clearflag FLAG_TRINITY_J_E4_BRUNO_BEATEN
	clearflag FLAG_TRINITY_J_E4_KAREN_BEATEN
	clearflag FLAG_TRINITY_J_E4_LANCE_BEATEN
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_JOHTO_INDIGO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

@ Vanilla's own league shelf, item for item
@ (EverGrandeCity_PokemonLeague_1F_Pokemart). Prices are global -- GetItemPrice
@ reads gItemsInfo[item].price and `pokemart` has no per-shop override (S4) --
@ so the list is the whole edit.
IndigoPlateau_PokemonCenter_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart IndigoPlateau_PokemonCenter_1F_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
IndigoPlateau_PokemonCenter_1F_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	pokemartlistend

IndigoPlateau_PokemonCenter_1F_EventScript_Receptionist::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_LEAGUE_CLEARED, IndigoPlateau_PokemonCenter_1F_EventScript_ReceptionistAfter
	msgbox IndigoPlateau_PokemonCenter_1F_Text_Receptionist, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_ReceptionistAfter::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_ReceptionistAfter, MSGBOX_DEFAULT
	release
	end

@ G4's rule for an advice NPC: state the real numbers. The five rosters are
@ L72-77 (WILL 72-73, KOGA 72-74, BRUNO 73-75, KAREN 73-75, LANCE 75-77), and
@ this line is checked against src/data/trainers.party, not remembered.
IndigoPlateau_PokemonCenter_1F_EventScript_Advisor::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_LEAGUE_CLEARED, IndigoPlateau_PokemonCenter_1F_EventScript_AdvisorAfter
	msgbox IndigoPlateau_PokemonCenter_1F_Text_Advisor, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_1F_EventScript_AdvisorAfter::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_AdvisorAfter, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_PokemonCenter_1F_Text_Receptionist:
	.string "Welcome to the POKéMON LEAGUE.\p"
	.string "Through that door are five rooms.\n"
	.string "You take them in order and the\l"
	.string "door shuts behind you each time.\p"
	.string "There is no coming back through\n"
	.string "for a POTION.\p"
	.string "If you lose, you'll wake up right\n"
	.string "here, and the LEAGUE will be\l"
	.string "waiting from the first room.\p"
	.string "Heal. Shop. Then go when you're\n"
	.string "ready -- not before.$"

IndigoPlateau_PokemonCenter_1F_Text_ReceptionistAfter:
	.string "CHAMPION of JOHTO.\p"
	.string "I've written it in the book\n"
	.string "three times now and it still\l"
	.string "looks wrong.\p"
	.string "The rooms are reset whenever you\n"
	.string "come through here. If you want\l"
	.string "them again, they're yours.$"

@ GSC IndigoPlateauPokecenter1FCooltrainerMText, with the level band added.
IndigoPlateau_PokemonCenter_1F_Text_Advisor:
	.string "At the POKéMON LEAGUE, you'll get\n"
	.string "tested by the ELITE FOUR.\p"
	.string "You have to beat them all. If you\n"
	.string "lose, you start all over.\p"
	.string "WILL is PSYCHIC, KOGA is POISON,\n"
	.string "BRUNO is FIGHTING, KAREN is DARK.\p"
	.string "They run from level 72 to 75.\p"
	.string "Then LANCE. Level 75 to 77, and\n"
	.string "six of them.$"

IndigoPlateau_PokemonCenter_1F_Text_AdvisorAfter:
	.string "You went through all five.\p"
	.string "…I've been giving that speech for\n"
	.string "eleven years. Nobody had ever\l"
	.string "come back out to hear the end\l"
	.string "of it.$"
