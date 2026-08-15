OlivineCafe_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S6 -- the OLIVINE CAFE. GSC's three regulars, with one skip
@ logged: OlivineCafeStrengthSailorScript hands over HM04 STRENGTH, and the
@ Act II player is the HOENN Champion and has had it since RUSTBORO. The gift
@ is dropped; the sailor keeps his character and reacts to a trainer who
@ already carries it. (Same call as the GOOD ROD house next door.)
@ ============================================================================
OlivineCafe_EventScript_StrengthSailor::
	msgbox OlivineCafe_Text_StrengthSailor, MSGBOX_NPC
	end

OlivineCafe_EventScript_FishingGuru::
	msgbox OlivineCafe_Text_FishingGuru, MSGBOX_NPC
	end

OlivineCafe_EventScript_Sailor::
	msgbox OlivineCafe_Text_Sailor, MSGBOX_NPC
	end

@ Adapts OlivineCafeStrengthSailorText + OlivineCafeStrengthSailorText_GotStrength.
OlivineCafe_Text_StrengthSailor:
	.string "Hah! Let's see your POKéMON, then.\p"
	.string "…Hmph. All right. Those ones could\n"
	.string "shift a boulder without being asked\l"
	.string "twice, couldn't they.\p"
	.string "Out on the sea the only thing you\n"
	.string "can count on is your own good self.\p"
	.string "I'm very proud of my buff bod!$"

OlivineCafe_Text_FishingGuru:
	.string "OLIVINE CAFE's\nmenu is chock full\pof hearty fare for\nbeefy SAILORS!$"

OlivineCafe_Text_Sailor:
	.string "Whenever I roll\ninto this town, I\palways visit the\nOLIVINE CAFE.\pEverything on the\nmenu makes me feel\pstronger. I can't\nstop eating!$"
