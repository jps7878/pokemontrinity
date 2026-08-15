GoldenrodPPSpeechHouse_MapScripts::
	.byte 0

GoldenrodPPSpeechHouse_EventScript_Fisher::
	msgbox GoldenrodPPSpeechHouse_Text_Fisher, MSGBOX_NPC
	end

GoldenrodPPSpeechHouse_EventScript_Lass::
	msgbox GoldenrodPPSpeechHouse_Text_Lass, MSGBOX_NPC
	end

GoldenrodPPSpeechHouse_Text_Fisher:
	.string "Once while I was\nbattling, my\pPOKéMON couldn't\nmake any moves.\pThe POWER POINTS,\nor PP, of its\pmoves were all\ngone.$"

GoldenrodPPSpeechHouse_Text_Lass:
	.string "Sometimes, a\nhealthy POKéMON\pmay be unable to\nuse its moves.\pIf that happens,\nheal it at a POKé-\lMON CENTER or use\lan item.$"
