Route31VioletGate_MapScripts::
	.byte 0

Route31VioletGate_EventScript_Officer::
	msgbox Route31VioletGate_Text_Officer, MSGBOX_NPC
	end

Route31VioletGate_EventScript_CooltrainerF::
	msgbox Route31VioletGate_Text_CooltrainerF, MSGBOX_NPC
	end

Route31VioletGate_Text_Officer:
	.string "Hi there!\nDid you visit\lSPROUT TOWER?$"

Route31VioletGate_Text_CooltrainerF:
	.string "I came too far\nout. I'd better\lphone home!$"
