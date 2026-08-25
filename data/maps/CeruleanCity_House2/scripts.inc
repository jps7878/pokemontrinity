CeruleanCity_House2_MapScripts::
	.byte 0

CeruleanCity_House2_EventScript_Hiker::
	msgbox CeruleanCity_House2_Text_Hiker, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_Lass::
	msgbox CeruleanCity_House2_Text_Lass, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_WallHole::
	msgbox CeruleanCity_House2_Text_WallHole, MSGBOX_SIGN
	end

CeruleanCity_House2_Text_Hiker:
	.string "My grandkids keep going on about\nsome trainer from HOENN. Sounds\llike quite the journey so far.$"

CeruleanCity_House2_Text_Lass:
	.string "TEAM ROCKET must be trying to DIG\ntheir way into no good!$"

CeruleanCity_House2_Text_WallHole:
	.string "TEAM ROCKET left a way out!$"
