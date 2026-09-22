Route2_House_MapScripts::
	.byte 0

Route2_House_EventScript_Scientist::
	msgbox Route2_House_Text_Scientist, MSGBOX_NPC
	end

Route2_House_EventScript_Reyley::
	msgbox Route2_House_Text_Reyley, MSGBOX_NPC
	end

Route2_House_Text_Scientist:
	.string "A fainted POKéMON just has no\nenergy left to battle.\pIt can still use moves like CUT\noutside of battle.$"

Route2_House_Text_Reyley:
	.string "I only trade with people I know.\nI don't know you.$"
