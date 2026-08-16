MahoganyRedGyaradosSpeechHouse_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S7. Adapts pokecrystal MahoganyRedGyaradosSpeechHouse.asm.
@
@ The BLACK BELT's second state is one of the three sites that NAME the RED
@ SCALE (S6's rule for an errand carried by a flag instead of a key item: the
@ item must be findable in dialogue wherever the player might look for it).
@ The other two are the LAKE OF RAGE beat itself and MR.POKéMON's house.
@ ============================================================================
MahoganyRedGyaradosSpeechHouse_EventScript_BlackBelt::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_RED_GYARADOS_HIDE, MahoganyRedGyaradosSpeechHouse_EventScript_BlackBeltAfter
	msgbox MahoganyRedGyaradosSpeechHouse_Text_BlackBelt, MSGBOX_DEFAULT
	release
	end

MahoganyRedGyaradosSpeechHouse_EventScript_BlackBeltAfter::
	msgbox MahoganyRedGyaradosSpeechHouse_Text_BlackBeltAfter, MSGBOX_DEFAULT
	release
	end

@ GSC's TEACHER flips on ENGINE_ROCKETS_IN_RADIO_TOWER, which is S8's state.
@ Her pre-takeover line is the one that ships now; S8 owns the creepy-laughter
@ variant and can add it without touching this map's local ids.
MahoganyRedGyaradosSpeechHouse_EventScript_Teacher::
	msgbox MahoganyRedGyaradosSpeechHouse_Text_Teacher, MSGBOX_NPC
	end

MahoganyRedGyaradosSpeechHouse_Text_BlackBelt:
	.string "I heard that a red GYARADOS\n"
	.string "appeared at the LAKE.\p"
	.string "That's odd, since even ordinary\n"
	.string "GYARADOS are rare in that lake.$"

MahoganyRedGyaradosSpeechHouse_Text_BlackBeltAfter:
	.string "So you faced it. The red one.\p"
	.string "They say it shed a scale --\n"
	.string "a RED SCALE, warm to the touch.\p"
	.string "There are collectors in JOHTO who\n"
	.string "would trade a great deal for it.$"

MahoganyRedGyaradosSpeechHouse_Text_Teacher:
	.string "My favourite radio programme?\n"
	.string "POKéMON MUSIC, without question.\p"
	.string "Though the signal out here has\n"
	.string "been dreadful lately.$"
