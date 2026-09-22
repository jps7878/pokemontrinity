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
	.string "SILPH is rebuilt and busy.\pI don't need a CHAMPION in my\nboardroom. Good day.$"

SilphCo_11F_Text_Secretary:
	.string "SECRETARY: The PRESIDENT is in.\pHe is in for SILPH business.\nYou have none.$"

SilphCo_11F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n11F$"
