Route29Route46Gate_MapScripts::
	.byte 0

Route29Route46Gate_EventScript_Officer::
	msgbox Route29Route46Gate_Text_Officer, MSGBOX_NPC
	end

Route29Route46Gate_EventScript_Youngster::
	msgbox Route29Route46Gate_Text_Youngster, MSGBOX_NPC
	end

Route29Route46Gate_Text_Officer:
	.string "You can't climb\nledges.\pBut you can jump\ndown from them to\ltake a shortcut.$"

Route29Route46Gate_Text_Youngster:
	.string "Different kinds of\nPOKéMON appear\lpast here.\pIf you want to\ncatch them all,\pyou have to look\neverywhere.$"
