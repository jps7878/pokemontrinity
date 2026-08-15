BillsFamilysHouse_MapScripts::
	.byte 0

@ Trinity M4b S4. BILL added at (2,3) -- GSC's tile
@ (BillsFamilysHouse.asm object list). SPRITE_BILL has no Emerald mapping (it
@ is on build_events.py's STORY_SKIP_SPRITES), so he wears
@ OBJ_EVENT_GFX_SCIENTIST_1: the man who built the STORAGE SYSTEM reads
@ correctly as a scientist. M6 ART ITEM.
@ GSC's EEVEE gift is deliberately NOT ported -- a gift-Pokémon beat is not
@ this slice's mandate. Logged in the slice plan's skip table.
BillsFamilysHouse_EventScript_Bill::
	msgbox BillsFamilysHouse_Text_Bill, MSGBOX_NPC
	end

BillsFamilysHouse_EventScript_BillsMom::
	msgbox BillsFamilysHouse_Text_BillsMom, MSGBOX_NPC
	end

BillsFamilysHouse_EventScript_BillsYoungerSister::
	msgbox BillsFamilysHouse_Text_BillsYoungerSister, MSGBOX_NPC
	end

@ Adapts BillPopWontWorkText + BillEeveeMayEvolveText's TIME CAPSULE framing.
BillsFamilysHouse_Text_Bill:
	.string "BILL: Hi. I'm BILL.\p"
	.string "I built the STORAGE SYSTEM.\n"
	.string "The one every trainer uses and\l"
	.string "nobody thinks about.\p"
	.string "I've been adjusting the TIME\n"
	.string "CAPSULE lately. Things come\l"
	.string "through it that I did not put\l"
	.string "in it.\p"
	.string "…You came over from HOENN,\n"
	.string "didn't you. Different boxes,\l"
	.string "same idea.\p"
	.string "I'd love to compare notes. I'd\n"
	.string "love it more from indoors.$"

@ GSC BillsMomText.
BillsFamilysHouse_Text_BillsMom:
	.string "Oh, you collect POKéMON?\n"
	.string "My son BILL is an expert.\p"
	.string "He built the system the whole\n"
	.string "world stores POKéMON in, and he\l"
	.string "still won't tidy his room.$"

@ GSC BillPopWontWorkText, from the sister's side.
BillsFamilysHouse_Text_BillsYoungerSister:
	.string "My pop, he won't work. All he\n"
	.string "does is goof off all day long.\p"
	.string "My brother's worse. He works\n"
	.string "all day and all night and calls\l"
	.string "it goofing off.$"
