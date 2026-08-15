CianwoodLugiaSpeechHouse_MapScripts::
	.byte 0

CianwoodLugiaSpeechHouse_EventScript_Teacher::
	msgbox CianwoodLugiaSpeechHouse_Text_Teacher, MSGBOX_NPC
	end

CianwoodLugiaSpeechHouse_EventScript_Lass::
	msgbox CianwoodLugiaSpeechHouse_Text_Lass, MSGBOX_NPC
	end

CianwoodLugiaSpeechHouse_EventScript_Twin::
	msgbox CianwoodLugiaSpeechHouse_Text_Twin, MSGBOX_NPC
	end

CianwoodLugiaSpeechHouse_Text_Teacher:
	.string "You came from\nOLIVINE?\pDo you remember\nthe four islands\lalong the way?\pI heard that a \nmythical sea crea-\lture is hiding in\lthem.$"

CianwoodLugiaSpeechHouse_Text_Lass:
	.string "I heard that you\ncan only see it if\pyou have a SILVER\nWING.\pIt must have the\nsame scent as the\lcreature.$"

CianwoodLugiaSpeechHouse_Text_Twin:
	.string "I've heard that\nthe whirlpools\paround the islands\nare caused by the\lsea creature.\pYou might need a\nspecial move to\lget past them.$"
