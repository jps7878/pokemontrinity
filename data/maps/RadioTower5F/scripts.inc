RadioTower5F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RadioTower5F_OnTransition
	.byte 0

@ Trinity M4b S4 -- RADIO TOWER 5F, pre-takeover. S8 FLIP CONTRACT: shared
@ predicate in data/maps/RadioTower1F/scripts.inc -- visible iff
@ VAR_TRINITY_JOHTO_ARC != 6. The DIRECTOR and DJ BEN carry
@ FLAG_TRINITY_J_RADIO_TOWER_PRE_HIDE; the ITEM_ULTRA_BALL ball at (8,5) keeps
@ its own pickup flag and is not part of the cast.
@
@ FOR S8: this DIRECTOR object at (3,6) is GSC's tile, and GSC reuses ONE
@ director object -- during the occupation it IS the imposter, with scene
@ scripts swapping the script rather than the sprite. Trinity's is simply
@ hidden while ARC == 6 and returns at ARC 7. S8 may either follow GSC (drop
@ the shared hide on this one object and give it a branching script, which
@ means claiming a flag for it) or append a separate imposter object. Both work
@ against the contract and neither requires editing this file.
@ His post-rescue speech -- the CLEAR BELL, the old tower, the TIN TOWER tip --
@ is S8's payload and is deliberately NOT written here.
@ DECODE NOTE: two components, PRE-EXISTING and object-independent (the office
@ half and the studio half join through 4F). See RadioTower3F's header.
RadioTower5F_OnTransition:
	call RadioTower_EventScript_SetPreTakeoverVisibility
	end

RadioTower5F_EventScript_Director::
	msgbox RadioTower5F_Text_Director, MSGBOX_NPC
	end

RadioTower5F_EventScript_Ben::
	msgbox RadioTower5F_Text_Ben, MSGBOX_NPC
	end

RadioTower5F_EventScript_DirectorsOfficeSign::
	msgbox RadioTower5F_Text_DirectorsOfficeSign, MSGBOX_SIGN
	end

RadioTower5F_EventScript_Studio1Sign::
	msgbox RadioTower5F_Text_Studio1Sign, MSGBOX_SIGN
	end

RadioTower5F_EventScript_Studio1Sign_2::
	msgbox RadioTower5F_Text_Studio1Sign_2, MSGBOX_SIGN
	end

@ GSC RadioTower5FDirectorText.
RadioTower5F_Text_Director:
	.string "DIRECTOR: Hello!\p"
	.string "You know, I love POKéMON.\p"
	.string "I built this RADIO TOWER so I\n"
	.string "could express my love of\l"
	.string "POKéMON.\p"
	.string "It would be nice if people\n"
	.string "enjoyed our programs.\p"
	.string "Anyone may walk in here. That\n"
	.string "was the whole idea.\p"
	.string "My security man thinks I'm a\n"
	.string "fool about it. Perhaps he's\l"
	.string "right.$"

@ GSC BenText.
RadioTower5F_Text_Ben:
	.string "BEN: Do you listen to our\n"
	.string "music?\p"
	.string "STUDIO 1, every evening. Just\n"
	.string "me and a stack of records and\l"
	.string "whoever's still awake.\p"
	.string "…You're the HOENN CHAMPION,\n"
	.string "aren't you. Would you come on\l"
	.string "the show? Ten minutes.\p"
	.string "No? Worth asking.$"

RadioTower5F_Text_DirectorsOfficeSign:
	.string "5F DIRECTOR'S\n   OFFICE$"

RadioTower5F_Text_Studio1Sign:
	.string "5F STUDIO 1$"

RadioTower5F_Text_Studio1Sign_2:
	.string "5F STUDIO 1$"
