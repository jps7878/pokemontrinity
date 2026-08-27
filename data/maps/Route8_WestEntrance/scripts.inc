Route8_WestEntrance_MapScripts::
	.byte 0

Route8_WestEntrance_EventScript_Guard::
	msgbox Route8_WestEntrance_Text_Guard, MSGBOX_NPC
	end

@ Trinity M5b S2: same open-passage guard idiom as Route7_EastEntrance --
@ skipped beat logged there.
Route8_WestEntrance_Text_Guard:
	.string "SAFFRON's just west of here.\nBusiest city in KANTO.$"
