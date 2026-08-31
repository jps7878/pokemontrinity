PewterCity_Museum_1F_MapScripts::
	.byte 0

PewterCity_Museum_1F_EventScript_Scientist1::
	msgbox PewterCity_Museum_1F_Text_Scientist1, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_OldMan::
	msgbox PewterCity_Museum_1F_Text_OldMan, MSGBOX_NPC
	end

@ Trinity M5b S9 -- Old Amber acquisition, paying off S4's own planted hook
@ verbatim ("There's a lab down on CINNABAR that specializes in old fossils.
@ They're the ones to ask."). Pewter Museum, matching both FRLG canon and S4's
@ own text (sub-plan section 3). No badge/story gate -- FRLG's real hand-off
@ carries none either.
PewterCity_Museum_1F_EventScript_OldAmberScientist::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_K_OLD_AMBER, PewterCity_Museum_1F_EventScript_OldAmberAlreadyGiven
	msgbox PewterCity_Museum_1F_Text_OldAmberScientist, MSGBOX_DEFAULT
	giveitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_TRINITY_K_OLD_AMBER
	release
	end

PewterCity_Museum_1F_EventScript_OldAmberAlreadyGiven::
	msgbox PewterCity_Museum_1F_Text_OldAmberGone, MSGBOX_DEFAULT
	release
	end

@ Trinity M5b S9 fix round (minor): display-case text now reflects the
@ handover -- the case reads empty once FLAG_TRINITY_K_OLD_AMBER is set,
@ instead of still describing amber that's no longer there.
PewterCity_Museum_1F_EventScript_OldAmber::
	goto_if_set FLAG_TRINITY_K_OLD_AMBER, PewterCity_Museum_1F_EventScript_OldAmberCaseEmpty
	msgbox PewterCity_Museum_1F_Text_OldAmber, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_OldAmberCaseEmpty::
	msgbox PewterCity_Museum_1F_Text_OldAmberCaseEmpty, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Scientist2::
	msgbox PewterCity_Museum_1F_Text_Scientist2, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_AerodactylFossil::
	msgbox PewterCity_Museum_1F_Text_AerodactylFossil, MSGBOX_SIGN
	end

PewterCity_Museum_1F_EventScript_KabutopsFossil::
	msgbox PewterCity_Museum_1F_Text_KabutopsFossil, MSGBOX_SIGN
	end

PewterCity_Museum_1F_Text_Scientist1:
	.string "Welcome to the PEWTER MUSEUM OF\nSCIENCE.\pTake your time. We've got fossils,\nspace history, and a real MOON\lSTONE upstairs.$"

PewterCity_Museum_1F_Text_OldMan:
	.string "I should be grateful for my long\nlife.\pNever did I think I would get to\nsee the bones of a dragon!$"

PewterCity_Museum_1F_Text_OldAmberScientist:
	.string "That AMBER's been sitting here\nlonger than I have.\pWe don't have the equipment to do\nanything with it.\pThere's a lab down on CINNABAR\nthat specializes in old fossils.\lThey're the ones to ask.\pHere, take it -- it's no use to\nus just sitting in a case.$"

PewterCity_Museum_1F_Text_OldAmberGone:
	.string "Good luck with that lab down on\nCINNABAR.$"

PewterCity_Museum_1F_Text_OldAmber:
	.string "A beautiful piece of AMBER, clear\ngold, with something ancient\lsealed inside it.$"

PewterCity_Museum_1F_Text_OldAmberCaseEmpty:
	.string "The display case sits empty now\nwhere the AMBER used to be.$"

PewterCity_Museum_1F_Text_Scientist2:
	.string "We have two fossils of rare,\nprehistoric POKéMON on exhibit.$"

PewterCity_Museum_1F_Text_AerodactylFossil:
	.string "AERODACTYL FOSSIL\pA prehistoric flying POKéMON,\nsaid to be restorable from\lwell-preserved amber.$"

PewterCity_Museum_1F_Text_KabutopsFossil:
	.string "KABUTOPS FOSSIL\pAn ancient POKéMON that once\nlurked in shallow seas, long\lbefore they dried up.$"
