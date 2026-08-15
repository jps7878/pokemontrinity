Route32RuinsOfAlphGate_MapScripts::
	.byte 0

Route32RuinsOfAlphGate_EventScript_Officer::
	msgbox Route32RuinsOfAlphGate_Text_Officer, MSGBOX_NPC
	end

Route32RuinsOfAlphGate_EventScript_PokefanM::
	msgbox Route32RuinsOfAlphGate_Text_PokefanM, MSGBOX_NPC
	end

Route32RuinsOfAlphGate_EventScript_Youngster::
	msgbox Route32RuinsOfAlphGate_Text_Youngster, MSGBOX_NPC
	end

Route32RuinsOfAlphGate_Text_Officer:
	.string "RUINS OF ALPH\pA Look-and-Touch\nTourist Site\pTry the sliding\nstone panels!$"

Route32RuinsOfAlphGate_Text_PokefanM:
	.string "You're studying\nthe RUINS?\pI see a scientist\nin the making.$"

Route32RuinsOfAlphGate_Text_Youngster:
	.string "There are drawings\non stone panels.\pI tried moving\nthem. I wonder\lwhat they are.$"
