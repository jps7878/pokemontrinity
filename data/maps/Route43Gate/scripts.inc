Route43Gate_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route43Gate_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S7 -- the ROUTE 43 toll booth. Adapts pokecrystal
@ maps/Route43Gate.asm.
@
@ ON_TRANSITION is the SINGLE AUTHORITY for both visibility flags (S1 rule).
@ The two casts are exact complements and they retire together, so one flag
@ each is correct (S4's C1 lesson -- check every member's lifecycle, not just
@ the beat's):
@     toll ROCKETS (2)  visible iff ARC <  5
@     OFFICER      (1)  visible iff ARC >= 5
@
@ PLACEMENT. The gate's walking column is x = 2..7 across rows 1..6; the two
@ doors sit at x = 4/5 on rows 0 and 7. The ROCKETS rest on (2,4) and (7,4),
@ the two outermost columns, so four clear columns remain between them and
@ neither door column is touched -- a gate NPC never blocks the gate (the
@ contract's coordinate rule, and S3's AZALEA lesson). The OFFICER is at (0,4),
@ BEHIND the left counter: (1,4) decodes MB_COUNTER, and
@ GetInteractedObjectEventScript looks one tile further through a counter
@ (src/field_control_avatar.c:387-396). His elevation is 3 -- the PLAYER'S
@ floor, not the counter's 0 -- because position->elevation is taken from
@ PlayerGetElevation() (S4's pin; copying the counter's elevation makes an NPC
@ both unreachable AND untalkable with nothing in any tool output to show).
@ ============================================================================
Route43Gate_OnTransition:
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 5, Route43Gate_EventScript_ShowOfficer
	clearflag FLAG_TRINITY_J_R43_ROCKETS_HIDE
	setflag FLAG_TRINITY_J_R43_OFFICER_HIDE
	end

Route43Gate_EventScript_ShowOfficer::
	setflag FLAG_TRINITY_J_R43_ROCKETS_HIDE
	clearflag FLAG_TRINITY_J_R43_OFFICER_HIDE
	end

@ ============================================================================
@ The toll. GSC reads VAR_FACING and mirrors two whole movement sets so the
@ pair steps aside in the right direction, and it re-arms once per direction;
@ it also takes the money whether or not the player can pay (`takemoney`
@ clamps at zero, so "pay what you have" empties the wallet).
@
@ S7 ships ONE script and ONE one-shot guard, and drops the forced-poverty
@ branch: an Act II CHAMPION being shaken down for a thousand is a joke, not a
@ threat, and a beat that can zero the player's money without warning is not a
@ joke worth porting. If the player cannot pay, the ROCKETS sneer and wave them
@ through -- which is also why nothing here needs to move an object.
@ ============================================================================
Route43Gate_EventScript_TollRocket::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_R43_TOLL, Route43Gate_EventScript_TollPaid
	msgbox Route43Gate_Text_TollDemand, MSGBOX_DEFAULT
	checkmoney 1000
	goto_if_eq VAR_RESULT, FALSE, Route43Gate_EventScript_TollBroke
	removemoney 1000
	playse SE_SHOP
	msgbox Route43Gate_Text_TollThanks, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_J_R43_TOLL
	release
	end

Route43Gate_EventScript_TollBroke::
	msgbox Route43Gate_Text_TollBroke, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_J_R43_TOLL
	release
	end

Route43Gate_EventScript_TollPaid::
	msgbox Route43Gate_Text_TollPaid, MSGBOX_DEFAULT
	release
	end

Route43Gate_EventScript_TollRocketB::
	msgbox Route43Gate_Text_MakingABundle, MSGBOX_NPC
	end

@ ============================================================================
@ The OFFICER, once the base has fallen. GSC's beat exactly: the ROCKETS
@ chased him off his post and left a TM behind. G2 award discipline -- the TM
@ is the only failable gift, so it owns its own flag and its own label, and a
@ full bag simply re-offers it.
@ ============================================================================
Route43Gate_EventScript_Officer::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_R43_OFFICER_TM, Route43Gate_EventScript_OfficerDone
	msgbox Route43Gate_Text_OfficerFoundTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_J_R43_OFFICER_TM
	msgbox Route43Gate_Text_OfficerExplainTM, MSGBOX_DEFAULT
	release
	end

Route43Gate_EventScript_OfficerDone::
	msgbox Route43Gate_Text_OfficerDone, MSGBOX_DEFAULT
	release
	end

Route43Gate_Text_TollDemand:
	.string "Hold it right there.\p"
	.string "The toll is 1000 to go through.\n"
	.string "Gate's ours today.$"

Route43Gate_Text_TollThanks:
	.string "Thank you very much!\p"
	.string "He-he. Everyone wants to see\n"
	.string "what's going on up at the LAKE.$"

Route43Gate_Text_TollBroke:
	.string "Nothing? A trainer with a badge\n"
	.string "case that full and no money?\p"
	.string "…Go on. Get out of my sight.$"

Route43Gate_Text_TollPaid:
	.string "You've paid. Move along.\p"
	.string "And don't go poking around the\n"
	.string "LAKE, hear?$"

Route43Gate_Text_MakingABundle:
	.string "He-he-he. We're making a bundle.\p"
	.string "Everyone wants to see what's\n"
	.string "going on up at the LAKE OF RAGE.$"

Route43Gate_Text_OfficerFoundTM:
	.string "I got chased off my own post by\n"
	.string "those thugs in black.\p"
	.string "They left this behind.\p"
	.string "It makes me uncomfortable.\n"
	.string "Could you take it away?$"

Route43Gate_Text_OfficerExplainTM:
	.string "SLUDGE BOMB. Poison, and it turns\n"
	.string "stomachs on the way through.\p"
	.string "Says everything about the people\n"
	.string "who left it lying in my gate.$"

Route43Gate_Text_OfficerDone:
	.string "Use this gate to avoid walking in\n"
	.string "the grass.\p"
	.string "That's the whole job. It's a good\n"
	.string "job when nobody's standing in it.$"
