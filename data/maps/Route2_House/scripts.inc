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
	.string "Folks in KANTO don't get many\nvisitors from HOENN. Word is one\lof them cleaned up in JOHTO too.$"
