SilphCo_1F_MapScripts::
	.byte 0

SilphCo_1F_EventScript_Receptionist::
	msgbox SilphCo_1F_Text_Receptionist, MSGBOX_NPC
	end

SilphCo_1F_EventScript_FloorSign::
	msgbox SilphCo_1F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_1F_Text_Receptionist:
	.string "Welcome.\pThe PRESIDENT is in the boardroom\non 11F.$"

SilphCo_1F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n1F$"
