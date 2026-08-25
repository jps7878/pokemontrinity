SeafoamIslands_B4F_MapScripts::
	.byte 0

SeafoamIslands_B4F_EventScript_FastCurrentSign::
	msgbox SeafoamIslands_B4F_Text_FastCurrentSign, MSGBOX_SIGN
	end

SeafoamIslands_B4F_EventScript_BoulderHintSign::
	msgbox SeafoamIslands_B4F_Text_BoulderHintSign, MSGBOX_SIGN
	end

SeafoamIslands_B4F_Text_FastCurrentSign:
	.string "DANGER\nFast current!$"

SeafoamIslands_B4F_Text_BoulderHintSign:
	.string "Hint: Boulders might change the\nflow of water.$"
