EcruteakMart_MapScripts::
	.byte 0

EcruteakMart_EventScript_Clerk::
	msgbox EcruteakMart_Text_Clerk, MSGBOX_NPC
	end

EcruteakMart_EventScript_SuperNerd::
	msgbox EcruteakMart_Text_SuperNerd, MSGBOX_NPC
	end

EcruteakMart_EventScript_Granny::
	msgbox EcruteakMart_Text_Granny, MSGBOX_NPC
	end

EcruteakMart_Text_Clerk:
	.string "This route sure gets more foot\ntraffic now that HOENN trainers\lkeep showing up.$"

EcruteakMart_Text_SuperNerd:
	.string "My EEVEE evolved\ninto an ESPEON.\pBut my friend's\nEEVEE turned into\lan UMBREON.\pI wonder why? We\nboth were raising\pour EEVEE in the\nsame way…$"

EcruteakMart_Text_Granny:
	.string "If you use REVIVE,\na POKéMON that's\pfainted will wake\nright up.$"
