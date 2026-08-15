WiseTriosRoom_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S5 -- THE WISE TRIO'S HALL, the antechamber between ECRUTEAK CITY
@ and the TIN TOWER. Three flavour sages, no visibility flags, no state.
@ Every line branches on FLAG_TRINITY_J_BEASTS_AWAKENED.
@
@ WHY NO BATTLES. GSC's fightable trio (SAGE GAKU / MASA / KOJI) only spawns
@ once the player carries the CLEAR BELL or KOJI has already granted passage
@ (WiseTriosRoomWiseTrioCallback) -- a gate that does not exist yet and belongs
@ to S10. Allocating three trainer ids for content whose trigger is a slice away
@ would burn a third of the remaining budget under R3b.
@
@ TILE DECODES (map.bin + metatile_attributes.bin).
@   (6,2) GSC's own tile for SAGE 1. Collision 0, elevation 3.
@   (6,6) SAGE 2. GSC puts him on (6,7), which in this port is the map's bottom
@         padding row; (6,6) is the same corner of the east chamber, inside it.
@   (1,5) SAGE 3. GSC puts him on (7,5) -- WHICH IS THE CITY WARP ITSELF
@         (MB_EAST_ARROW_WARP). That is GSC's doorway-blocker idiom and the M4b
@         contract forbids it, so the TIN TOWER's guardian is moved to the tile
@         beside the ladder he actually guards.
@ NO-SEAL: (1,4) is the TIN TOWER ladder (MB_LADDER) and it keeps three free
@ neighbours -- (0,4), (2,4) and (1,3) -- with (1,5) occupied, so this post does
@ NOT gate the TIN TOWER. It must not: S10 owns that gate.
@ ============================================================================
WiseTriosRoom_EventScript_SageA::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_BEASTS_AWAKENED, WiseTriosRoom_EventScript_SageAAwake
	msgbox WiseTriosRoom_Text_SageA, MSGBOX_DEFAULT
	release
	end

WiseTriosRoom_EventScript_SageAAwake::
	msgbox WiseTriosRoom_Text_SageAAwake, MSGBOX_DEFAULT
	release
	end

WiseTriosRoom_EventScript_SageB::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_BEASTS_AWAKENED, WiseTriosRoom_EventScript_SageBAwake
	msgbox WiseTriosRoom_Text_SageB, MSGBOX_DEFAULT
	release
	end

WiseTriosRoom_EventScript_SageBAwake::
	msgbox WiseTriosRoom_Text_SageBAwake, MSGBOX_DEFAULT
	release
	end

WiseTriosRoom_EventScript_SageC::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_BEASTS_AWAKENED, WiseTriosRoom_EventScript_SageCAwake
	msgbox WiseTriosRoom_Text_SageC, MSGBOX_DEFAULT
	release
	end

WiseTriosRoom_EventScript_SageCAwake::
	msgbox WiseTriosRoom_Text_SageCAwake, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ Text
@ ============================================================================
@ Adapts pokecrystal WiseTriosRoomSage3Text.
WiseTriosRoom_Text_SageA:
	.string "We, the WISE TRIO, are the\n"
	.string "protectors of the legendary POKéMON.\p"
	.string "We have protected an empty tower and\n"
	.string "a burned one for three generations.\p"
	.string "It is quiet work.$"

@ GSC WiseTriosRoomSage1Text.
WiseTriosRoom_Text_SageAAwake:
	.string "Astounding…\p"
	.string "SUICUNE, ENTEI and RAIKOU have\n"
	.string "arisen from their sleep.\p"
	.string "Is the legend coming true?$"

WiseTriosRoom_Text_SageB:
	.string "We train at the BURNED TOWER. Ash,\n"
	.string "prayer, and a floor you must not\l"
	.string "trust.\p"
	.string "Nothing has happened there in a\n"
	.string "hundred and fifty years.$"

@ GSC WiseTriosRoomSage2Text, plus the substance of SageMasaAfterBattleText --
@ the BRASS TOWER / TIN TOWER history, the best piece of lore in this chapter.
@ GSC hides it behind a battle S5 is not shipping, so it is given to SAGE B
@ rather than lost.
WiseTriosRoom_Text_SageBAwake:
	.string "We train at the BURNED TOWER, but\n"
	.string "we have never heard of a hole\l"
	.string "opening up there before.\p"
	.string "It must have been made deliberately,\n"
	.string "by someone.\p"
	.string "Listen. In the past there were two\n"
	.string "nine-tier towers here. The BRASS\l"
	.string "TOWER, said to awaken POKéMON, and\l"
	.string "the TIN TOWER, where they rested.\p"
	.string "An immense silver-colored POKéMON\n"
	.string "roosted atop the BRASS TOWER.\p"
	.string "About a hundred and fifty years ago\n"
	.string "lightning struck one of them. It\l"
	.string "burned for three days.\p"
	.string "A sudden downpour put the blaze out.\n"
	.string "That is how the BURNED TOWER came\l"
	.string "to be.\p"
	.string "Three POKéMON died in that fire, and\n"
	.string "a rainbow-colored POKéMON came down\l"
	.string "from the sky and gave them back\l"
	.string "their lives.\p"
	.string "You met all three this morning.$"

WiseTriosRoom_Text_SageC:
	.string "Behind me is the TIN TOWER.\p"
	.string "It may be entered by those bearing\n"
	.string "ECRUTEAK's own GYM BADGE, and by no\l"
	.string "one else.\p"
	.string "Nothing has answered at the top of\n"
	.string "it in my lifetime, CHAMPION. Do not\l"
	.string "climb it expecting to be the first.$"

@ Adapts GSC WiseTriosRoomSage3BlocksExitText -- GSC's sage physically blocks
@ the stair here. Trinity's does not: the TIN TOWER gate is S10's to build, and
@ a resting NPC may not seal anything.
WiseTriosRoom_Text_SageCAwake:
	.string "Now that SUICUNE, RAIKOU and ENTEI\n"
	.string "have arisen, I would normally ask\l"
	.string "you to refrain from entering.\p"
	.string "I find that I cannot.\p"
	.string "They woke for you. Whatever waits at\n"
	.string "the top of the TIN TOWER is not\l"
	.string "waiting for me.$"
