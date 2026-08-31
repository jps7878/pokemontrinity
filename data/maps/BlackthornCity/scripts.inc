@ ============================================================================
@ Trinity M4b S9 -- BLACKTHORN CITY. Two beats: the DRAGON'S DEN gate and the
@ GYM's doorman.
@
@ ---------------------------------------------------------------------------
@ THE DEN GATE IS FLAVOR, NOT A SEAL -- MEASURED, NOT ASSUMED
@ ---------------------------------------------------------------------------
@ GSC parks its GRAMPS on (20,2) and swaps him for a second object at (21,2)
@ once CLAIR sends the player to the shrine. The plan for this slice predicted
@ he would genuinely seal the DRAGON'S DEN and wrote the R5 disclosure for it.
@ THE MEASUREMENT SAYS OTHERWISE, and the measurement wins.
@
@ Decoded from data/layouts/BlackthornCity_Johto/map.bin: (20,1) is the
@ DRAGON'S DEN door (MB_NON_ANIMATED_DOOR) and its only walkable neighbor at
@ ground level is (20,2) -- (19,1), (21,1) and (19,2) all decode collision 1.
@ BUT THE TOWN'S ROW 0 IS WALKABLE, 38 of its 40 tiles, and (20,0) sits
@ directly above the door. That is not a port artifact: pokecrystal's
@ maps/BlackthornCity.blk block row 0 is almost entirely block $71, which
@ data/tilesets/johto_collision.asm gives as FLOOR,FLOOR,FLOOR,FLOOR. The strip
@ is drawn as clifftop and is walkable in GSC too.
@
@ MEASURED, per door (the union fill is useless for this question -- a warp is
@ always reachable from its own seed):
@   GRAMPS BLOCKING: 910/1014 reachable, he costs 2 tiles ((20,2) and the
@     (21,2) alcove behind it), and (20,1) is REACHABLE FROM ALL SEVEN other
@     doors -- an 81-step detour up the left side and along row 0.
@   GRAMPS ASIDE:    911/1014, every object costs exactly its own tile, all 8
@     doors mutually reachable.
@ So no R5 exception is needed and none is claimed: nothing is sealed in either
@ state. He is kept at GSC's tile as characterization -- he tells you to leave,
@ and the game does not enforce it. Walking in early is harmless: the shrine
@ scene is gated on VAR_TRINITY_JOHTO_SCENE_BLACKTHORN == 1, SILVER on badge 16,
@ and ELDER 1's pre-test line is GSC's own "Come again, if you so desire."
@
@ ---------------------------------------------------------------------------
@ THE GYM DOORMAN MOVED -- FOURTH OCCURRENCE OF THE "EXPECT TO MOVE A GSC GUARD
@ POST" RULE (S3, S6, S8, now S9)
@ ---------------------------------------------------------------------------
@ GSC's two SUPER NERD objects stand on (18,12)/(19,12). (18,12) is the ONLY
@ walkable neighbor of the GYM door (18,11) -- (17,11), (19,11) and (18,10) all
@ decode collision 1, and unlike the DEN door there is no clifftop above it --
@ so a resting NPC there seals BLACKTHORN GYM. S9 ships ONE doorman, at
@ (19,12), in the open plaza (rows 12-13, x 17-20 all walkable).
@ MEASURED, and this is ALSO a live instance of the union-vs-per-door trap S8
@ pinned -- the union fill reports the gym door reachable in both stagings,
@ because it is its own seed:
@   on GSC's (18,12): per-door 746 tiles and (18,11) SEALED from all 7 other
@     doors.
@   on S9's (19,12):  per-door 747 tiles and (18,11) reachable from all 7.
@ He is also NOT a gate. GSC hides CLAIR until EVENT_CLEARED_RADIO_TOWER; the
@ M4b contract makes the JOHTO gyms open-order and S8's fix round already ruled
@ CLAIR reachable pre-tower, so his GSC "CLAIR is out" state is dropped and he
@ keeps the two states that are still true.
@ ============================================================================

BlackthornCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_OnTransition
	.byte 0

@ The single authoring site for both GRAMPS flags. Exact complements, one
@ predicate: SCENE_BLACKTHORN == 0 means CLAIR has not been beaten.
BlackthornCity_OnTransition:
	goto_if_ge VAR_TRINITY_JOHTO_SCENE_BLACKTHORN, 1, BlackthornCity_EventScript_DenOpen
	clearflag FLAG_TRINITY_J_DEN_GRAMPS_BLOCK_HIDE
	setflag FLAG_TRINITY_J_DEN_GRAMPS_ASIDE_HIDE
	end

BlackthornCity_EventScript_DenOpen::
	setflag FLAG_TRINITY_J_DEN_GRAMPS_BLOCK_HIDE
	clearflag FLAG_TRINITY_J_DEN_GRAMPS_ASIDE_HIDE
	end

BlackthornCity_EventScript_GrampsBlocking::
	msgbox BlackthornCity_Text_GrampsRefusesEntry, MSGBOX_NPC
	end

BlackthornCity_EventScript_GrampsAside::
	msgbox BlackthornCity_Text_GrampsGrantsEntry, MSGBOX_NPC
	end

BlackthornCity_EventScript_SuperNerd::
	lock
	faceplayer
	goto_if_ge VAR_TRINITY_JOHTO_SCENE_BLACKTHORN, 1, BlackthornCity_EventScript_SuperNerdBeaten
	msgbox BlackthornCity_Text_SuperNerdClairIsIn, MSGBOX_DEFAULT
	release
	end

BlackthornCity_EventScript_SuperNerdBeaten::
	msgbox BlackthornCity_Text_SuperNerdClairIsBeaten, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ Trinity M5b S13b -- the BLACKTHORN move relearner, Johto backfill. The
@ Fallarbor pattern, copied VERBATIM per S2's own established instruction
@ ("framing changes, mechanism copied verbatim") -- re-read this session
@ from FallarborTown_MoveRelearnersHouse/scripts.inc: intro text gated by
@ transient FLAG_TEMP_1 (cleared every map load, no persistent claim,
@ confirmed unused elsewhere on this map by grep) -> `checkitem
@ ITEM_HEART_SCALE` gate -> `ChooseMonForMoveRelearner`/
@ `TeachMoveRelearnerMove` specials -> `removeitem ITEM_HEART_SCALE` on
@ success. Host: this BLACK BELT (24,31), the thinnest, most replaceable
@ content in the city (a single throwaway MSGBOX_NPC line) -- reframed
@ rather than the two flavour-house NPCs (Granny/Emy, single-purpose) or
@ SuperNerd (already carries live CLAIR-gym-status state, overloading him
@ risks contradicting it). "Move mastery" framing fits a Black Belt
@ naturally; his own MOVEMENT_TYPE_WALK_LEFT_AND_RIGHT range is left
@ untouched, only his facing is corrected at interaction time.
@ ============================================================================
BlackthornCity_EventScript_BlackthornBlackBelt::
	lock
	applymovement LOCALID_BLACKTHORNCITY_BLACKBELT, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, BlackthornCity_EventScript_BlackBeltAskTeachMove
	msgbox BlackthornCity_Text_BlackBeltImTheTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto BlackthornCity_EventScript_BlackBeltAskTeachMove
	end

BlackthornCity_EventScript_BlackBeltAskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, BlackthornCity_EventScript_BlackBeltComeBack
	msgbox BlackthornCity_Text_BlackBeltThatsAHeartScale, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BlackthornCity_EventScript_BlackBeltComeBack
	goto BlackthornCity_EventScript_BlackBeltChooseMon
	end

BlackthornCity_EventScript_BlackBeltChooseMon::
	msgbox BlackthornCity_Text_BlackBeltWhichMon, MSGBOX_DEFAULT
	setmoverelearnerstate MOVE_RELEARNER_LEVEL_UP_MOVES
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BlackthornCity_EventScript_BlackBeltComeBack
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BlackthornCity_EventScript_BlackBeltCantTeachEgg
	goto_if_eq VAR_0x8005, 0, BlackthornCity_EventScript_BlackBeltNoMoveToTeach
	goto BlackthornCity_EventScript_BlackBeltChooseMove
	end

BlackthornCity_EventScript_BlackBeltChooseMove::
	msgbox BlackthornCity_Text_BlackBeltWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, BlackthornCity_EventScript_BlackBeltChooseMon
	msgbox BlackthornCity_Text_BlackBeltHandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto BlackthornCity_EventScript_BlackBeltComeBack
	end

BlackthornCity_EventScript_BlackBeltNoMoveToTeach::
	msgbox BlackthornCity_Text_BlackBeltNoMoveToTeach, MSGBOX_DEFAULT
	goto BlackthornCity_EventScript_BlackBeltChooseMon
	end

BlackthornCity_EventScript_BlackBeltCantTeachEgg::
	msgbox BlackthornCity_Text_BlackBeltCantTeachEgg, MSGBOX_DEFAULT
	goto BlackthornCity_EventScript_BlackBeltChooseMon
	end

BlackthornCity_EventScript_BlackBeltComeBack::
	msgbox BlackthornCity_Text_BlackBeltComeBack, MSGBOX_DEFAULT
	release
	end

BlackthornCity_Text_BlackBeltImTheTutor:
	.string "Every technique a POKéMON forgets\n"
	.string "is still in there somewhere.\p"
	.string "Bring me a HEART SCALE and I'll\n"
	.string "help you dig one back out.$"

BlackthornCity_Text_BlackBeltThatsAHeartScale:
	.string "That's a HEART SCALE. Want me to\ntry?$"

BlackthornCity_Text_BlackBeltWhichMon:
	.string "Which POKéMON?$"

BlackthornCity_Text_BlackBeltWhichMove:
	.string "Which move?$"

BlackthornCity_Text_BlackBeltNoMoveToTeach:
	.string "That one's got nothing left to\nremember.$"

BlackthornCity_Text_BlackBeltCantTeachEgg:
	.string "That's not hatched yet. Ask me\nagain later.$"

BlackthornCity_Text_BlackBeltHandedOverHeartScale:
	.string "There. Some things you don't\nforget twice.$"

BlackthornCity_Text_BlackBeltComeBack:
	.string "Come back with a HEART SCALE if\nyou want another dug out.$"

BlackthornCity_EventScript_BlackthornCooltrainerF1::
	msgbox BlackthornCity_Text_BlackthornCooltrainerF1, MSGBOX_NPC
	end

BlackthornCity_EventScript_BlackthornYoungster::
	msgbox BlackthornCity_Text_BlackthornYoungster, MSGBOX_NPC
	end

BlackthornCity_EventScript_BlackthornCooltrainerF2::
	msgbox BlackthornCity_Text_BlackthornCooltrainerF2, MSGBOX_NPC
	end

BlackthornCity_EventScript_Sign::
	msgbox BlackthornCity_Text_Sign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_BlackthornGymSign::
	msgbox BlackthornCity_Text_BlackthornGymSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_MoveDeletersHouseSign::
	msgbox BlackthornCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_DragonDensSign::
	msgbox BlackthornCity_Text_DragonDensSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_TrainerTips::
	msgbox BlackthornCity_Text_TrainerTips, MSGBOX_SIGN
	end

BlackthornCity_Text_BlackthornBlackBelt:
	.string "I've been wandering these routes\nfor years. Lately there's talk of\lnothing but the HOENN champion.$"

BlackthornCity_Text_BlackthornCooltrainerF1:
	.string "Are you going to\nmake your POKéMON\lforget some moves?$"

BlackthornCity_Text_BlackthornYoungster:
	.string "Dragon masters all\ncome from the city\lof BLACKTHORN.$"

BlackthornCity_Text_BlackthornCooltrainerF2:
	.string "Wow, you came\nthrough the ICE\lPATH?\pYou must be a real\nhotshot trainer!$"

BlackthornCity_Text_Sign:
	.string "BLACKTHORN CITY\pA Quiet Mountain\nRetreat$"

BlackthornCity_Text_BlackthornGymSign:
	.string "BLACKTHORN CITY\nPOKéMON GYM\lLEADER: CLAIR\pThe Blessed User\nof Dragon POKéMON$"

BlackthornCity_Text_MoveDeletersHouseSign:
	.string "MOVE DELETER'S\nHOUSE$"

BlackthornCity_Text_DragonDensSign:
	.string "DRAGON'S DEN\nAHEAD$"

BlackthornCity_Text_TrainerTips:
	.string "TRAINER TIPS\pA POKéMON holding\na MIRACLEBERRY\pwill cure itself\nof any status\lproblem.$"

BlackthornCity_Text_GrampsRefusesEntry:
	.string "No. Only chosen trainers may train\n"
	.string "here.\p"
	.string "It does not matter what you won\n"
	.string "somewhere else. Please leave.$"

BlackthornCity_Text_GrampsGrantsEntry:
	.string "If CLAIR allows it, her\n"
	.string "grandfather -- our MASTER -- will\l"
	.string "also allow it.\p"
	.string "You may enter.$"

BlackthornCity_Text_SuperNerdClairIsIn:
	.string "CLAIR, our GYM LEADER, is waiting\n"
	.string "for you.\p"
	.string "I know what they call you in\n"
	.string "HOENN. So does she. It will not\l"
	.string "help you in there.$"

BlackthornCity_Text_SuperNerdClairIsBeaten:
	.string "You defeated CLAIR?\p"
	.string "That's amazing!\p"
	.string "I've never heard of her losing to\n"
	.string "anyone other than LANCE.$"
