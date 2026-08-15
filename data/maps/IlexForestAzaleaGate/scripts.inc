IlexForestAzaleaGate_MapScripts::
	.byte 0

IlexForestAzaleaGate_EventScript_Officer::
	msgbox IlexForestAzaleaGate_Text_Officer, MSGBOX_NPC
	end

IlexForestAzaleaGate_EventScript_Granny::
	msgbox IlexForestAzaleaGate_Text_Granny, MSGBOX_NPC
	end

IlexForestAzaleaGate_Text_Officer:
	.string "ILEX FOREST is\nbig. Be careful!\lDon't get lost.$"

IlexForestAzaleaGate_Text_Granny:
	.string "The FOREST is\nwatched over by\lits protector.\pStay out of\nmischief!$"
