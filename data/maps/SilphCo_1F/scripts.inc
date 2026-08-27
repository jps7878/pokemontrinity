SilphCo_1F_MapScripts::
	.byte 0

SilphCo_1F_EventScript_Receptionist::
	msgbox SilphCo_1F_Text_Receptionist, MSGBOX_NPC
	end

SilphCo_1F_EventScript_FloorSign::
	msgbox SilphCo_1F_Text_FloorSign, MSGBOX_SIGN
	end

@ Trinity M5b S2: rebuilding-company flavor pass (post-RBY, no raid here --
@ Act III's raid is Celadon S6/Viridian S10). See section 5.4 of
@ docs/superpowers/plans/m5b/02-saffron-chapter.md.
SilphCo_1F_Text_Receptionist:
	.string "Welcome to SILPH CO.\pWe've spent years rebuilding since\nour last rough patch. The\lPRESIDENT's in the boardroom on\l11F if you have business with us.$"

SilphCo_1F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n1F\pPioneering POKé BALL technology\nsince before you were born.$"
