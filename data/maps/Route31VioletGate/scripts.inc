Route31VioletGate_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S2. The M4b story-object inventory is EMPTY for this gate -- GSC
@ has no flag-gated objects here, so M4a already ported both NPCs verbatim at
@ their GSC tiles ((5,2) and (1,2), both re-decoded collision-0 elevation-3
@ MB_NORMAL). S2 adds no objects; the deliverable is chapter-aware dialogue.
@ The officer is a READER of FLAG_TRINITY_BADGE09 (GYM PATTERN G7 -- only
@ FALKNER writes it), which is what makes a plain-flag badge observable
@ outside the gym itself.
@ ============================================================================
Route31VioletGate_EventScript_Officer::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_BADGE09, Route31VioletGate_EventScript_OfficerPostBadge
	msgbox Route31VioletGate_Text_Officer, MSGBOX_DEFAULT
	release
	end

Route31VioletGate_EventScript_OfficerPostBadge::
	msgbox Route31VioletGate_Text_OfficerPostBadge, MSGBOX_DEFAULT
	release
	end

Route31VioletGate_EventScript_CooltrainerF::
	msgbox Route31VioletGate_Text_CooltrainerF, MSGBOX_NPC
	end

Route31VioletGate_Text_Officer:
	.string "Hi there! Did you visit SPROUT\n"
	.string "TOWER?\p"
	.string "Climb to the top floor and the\n"
	.string "ELDER will test you himself.\p"
	.string "Good practice before you knock\n"
	.string "on FALKNER's door.$"

Route31VioletGate_Text_OfficerPostBadge:
	.string "You took the ZEPHYRBADGE off\n"
	.string "FALKNER? On your first day here?\p"
	.string "…Right. Of course you did.\p"
	.string "ROUTE 31 runs east from that\n"
	.string "door. Mind the mouth of DARK\l"
	.string "CAVE -- it is black as pitch in\l"
	.string "there and it doesn't care who\l"
	.string "you are.$"

Route31VioletGate_Text_CooltrainerF:
	.string "I came too far out. I'd better\n"
	.string "phone home!\p"
	.string "…Assuming the RADIO TOWER hasn't\n"
	.string "eaten the signal again.$"
