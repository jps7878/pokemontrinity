BlackthornMart_MapScripts::
	.byte 0

BlackthornMart_EventScript_Clerk::
	msgbox BlackthornMart_Text_Clerk, MSGBOX_NPC
	end

BlackthornMart_EventScript_CooltrainerM::
	msgbox BlackthornMart_Text_CooltrainerM, MSGBOX_NPC
	end

BlackthornMart_EventScript_BlackBelt::
	msgbox BlackthornMart_Text_BlackBelt, MSGBOX_NPC
	end

BlackthornMart_Text_Clerk:
	.string "The old timers say JOHTO used to\nfeel far from everywhere. Not\lanymore, with HOENN so close now.$"

BlackthornMart_Text_CooltrainerM:
	.string "You can't buy MAX\nREVIVE, but it\pfully restores a\nfainted POKéMON.\pBeware--it won't\nrestore PP, the\pPOWER POINTS\nneeded for moves.$"

BlackthornMart_Text_BlackBelt:
	.string "MAX REPEL keeps\nweak POKéMON away\lfrom you.\pIt's the longest\nlasting of the\lREPEL sprays.$"
