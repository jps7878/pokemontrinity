Route7_EastEntrance_MapScripts::
	.byte 0

Route7_EastEntrance_EventScript_Guard::
	msgbox Route7_EastEntrance_Text_Guard, MSGBOX_NPC
	end

@ Trinity M5b S2: FRLG's tea-for-Flash guard quest was never wired in this
@ port (no item check, no warp gate -- confirmed, this NPC is already
@ open-passage). Skipped beat, logged; open-passage flavor only.
Route7_EastEntrance_Text_Guard:
	.string "Straight through to SAFFRON.\nMind the traffic.$"
