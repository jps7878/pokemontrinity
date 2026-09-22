SilphCo_11F_MapScripts::
	.byte 0

SilphCo_11F_EventScript_President::
	msgbox SilphCo_11F_Text_President, MSGBOX_NPC
	end

SilphCo_11F_EventScript_Secretary::
	msgbox SilphCo_11F_Text_Secretary, MSGBOX_NPC
	end

SilphCo_11F_EventScript_FloorSign::
	msgbox SilphCo_11F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_11F_Text_President:
	.string "SILPH is mine again.\nI don't owe you for that.\lGood day.$"

SilphCo_11F_Text_Secretary:
	.string "SECRETARY: Thank you for rescuing\nall of us.\pWe, from the PRESIDENT down,\nare indebted to you.$"

SilphCo_11F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n11F$"
