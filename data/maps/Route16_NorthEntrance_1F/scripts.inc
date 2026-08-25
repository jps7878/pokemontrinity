Route16_NorthEntrance_1F_MapScripts::
	.byte 0

Route16_NorthEntrance_1F_EventScript_Guard::
	msgbox Route16_NorthEntrance_1F_Text_Guard, MSGBOX_NPC
	end

Route16_NorthEntrance_1F_EventScript_OldMan::
	msgbox Route16_NorthEntrance_1F_Text_OldMan, MSGBOX_NPC
	end

Route16_NorthEntrance_1F_Text_Guard:
	.string "CYCLING ROAD is a downhill course\nby the sea. It's a great ride.$"

Route16_NorthEntrance_1F_Text_OldMan:
	.string "How'd you get in?\nGood effort!$"
