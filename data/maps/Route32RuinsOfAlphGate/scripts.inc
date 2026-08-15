Route32RuinsOfAlphGate_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S2. As with Route31VioletGate, the M4b story-object inventory is
@ EMPTY for this gate -- all three GSC NPCs were ported verbatim by M4a at
@ their GSC tiles ((5,2), (8,2), (1,6), all re-decoded collision-0 elevation-3
@ MB_NORMAL). S2 adds no objects. The officer gains a post-badge branch that
@ points the player south toward AZALEA TOWN, which is S3's chapter.
@ ============================================================================
Route32RuinsOfAlphGate_EventScript_Officer::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_BADGE09, Route32RuinsOfAlphGate_EventScript_OfficerPostBadge
	msgbox Route32RuinsOfAlphGate_Text_Officer, MSGBOX_DEFAULT
	release
	end

Route32RuinsOfAlphGate_EventScript_OfficerPostBadge::
	msgbox Route32RuinsOfAlphGate_Text_OfficerPostBadge, MSGBOX_DEFAULT
	release
	end

Route32RuinsOfAlphGate_EventScript_PokefanM::
	msgbox Route32RuinsOfAlphGate_Text_PokefanM, MSGBOX_NPC
	end

Route32RuinsOfAlphGate_EventScript_Youngster::
	msgbox Route32RuinsOfAlphGate_Text_Youngster, MSGBOX_NPC
	end

Route32RuinsOfAlphGate_Text_Officer:
	.string "RUINS OF ALPH\p"
	.string "A Look-and-Touch Tourist Site\p"
	.string "Try the sliding stone panels!$"

Route32RuinsOfAlphGate_Text_OfficerPostBadge:
	.string "RUINS OF ALPH\p"
	.string "A Look-and-Touch Tourist Site\p"
	.string "…You're the one who beat FALKNER,\n"
	.string "aren't you.\p"
	.string "Then you'll be wanting BUGSY.\p"
	.string "ROUTE 32 stretches south -- take\n"
	.string "the east door.\p"
	.string "Follow it down to UNION CAVE and\n"
	.string "you come out at AZALEA TOWN.\p"
	.string "Long walk. Take the panels in on\n"
	.string "your way past.$"

Route32RuinsOfAlphGate_Text_PokefanM:
	.string "You're studying\nthe RUINS?\pI see a scientist\nin the making.$"

Route32RuinsOfAlphGate_Text_Youngster:
	.string "There are drawings\non stone panels.\pI tried moving\nthem. I wonder\lwhat they are.$"
