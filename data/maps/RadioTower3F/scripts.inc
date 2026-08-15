RadioTower3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RadioTower3F_OnTransition
	.byte 0

@ Trinity M4b S4 -- RADIO TOWER 3F, pre-takeover. S8 FLIP CONTRACT: shared
@ predicate in data/maps/RadioTower1F/scripts.inc -- visible iff
@ VAR_TRINITY_JOHTO_ARC != 6. All three objects carry
@ FLAG_TRINITY_J_RADIO_TOWER_PRE_HIDE.
@ DECODE NOTE: this floor reads as TWO components to reach_check.py, and that
@ is PRE-EXISTING and object-independent (identical with zero objects placed).
@ The tower has two staircases per floor and the halves join through 4F, which
@ a single-map tool cannot see -- the SPROUT TOWER limitation pinned in the S3
@ ledger. The CARD KEY shutter that GSC opens at (14,2) is S8's.
RadioTower3F_OnTransition:
	call RadioTower_EventScript_SetPreTakeoverVisibility
	end

RadioTower3F_EventScript_GymGuide::
	msgbox RadioTower3F_Text_GymGuide, MSGBOX_NPC
	end

RadioTower3F_EventScript_CooltrainerF::
	msgbox RadioTower3F_Text_CooltrainerF, MSGBOX_NPC
	end

RadioTower3F_EventScript_SuperNerd::
	msgbox RadioTower3F_Text_SuperNerd, MSGBOX_NPC
	end

RadioTower3F_EventScript_PersonnelSign::
	msgbox RadioTower3F_Text_PersonnelSign, MSGBOX_SIGN
	end

RadioTower3F_EventScript_PokemonMusicSign::
	msgbox RadioTower3F_Text_PokemonMusicSign, MSGBOX_SIGN
	end

@ GSC RadioTower3FGymGuideText (the non-Rocket branch).
RadioTower3F_Text_GymGuide:
	.string "We run 24 hours a day to\n"
	.string "broadcast entertaining\l"
	.string "programs.\p"
	.string "I'll do my best to run around\n"
	.string "the clock too!$"

@ GSC gives her no pre-takeover line at all -- every one of hers is occupation
@ or post-rescue -- so this is written for Trinity.
RadioTower3F_Text_CooltrainerF:
	.string "PERSONNEL, third floor. If you\n"
	.string "work in this building, I have\l"
	.string "your file.\p"
	.string "Do you know how many people it\n"
	.string "takes to keep one radio signal\l"
	.string "on the air?\p"
	.string "Neither does anyone else. Only\n"
	.string "me.$"

@ GSC RadioTower3FSuperNerdText.
RadioTower3F_Text_SuperNerd:
	.string "We have recordings of the cries\n"
	.string "of all POKéMON that have been\l"
	.string "found.\p"
	.string "We must have about 200 kinds.\p"
	.string "There are a few on the shelf\n"
	.string "that nobody has ever matched to\l"
	.string "a POKéMON.\p"
	.string "Those ones I keep at the back.$"

RadioTower3F_Text_PersonnelSign:
	.string "3F PERSONNEL$"

RadioTower3F_Text_PokemonMusicSign:
	.string "POKéMON MUSIC with\nHost DJ BEN$"
