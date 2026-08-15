EcruteakGym_MapScripts::
	.byte 0

EcruteakGym_EventScript_JEFFREY::
	trainerbattle_single TRAINER_JOHTO_SAGE_JEFFREY, EcruteakGym_Text_JEFFREYSeen, EcruteakGym_Text_JEFFREYBeaten
	msgbox EcruteakGym_Text_JEFFREYBeaten, MSGBOX_AUTOCLOSE
	end

EcruteakGym_EventScript_PING::
	trainerbattle_single TRAINER_JOHTO_SAGE_PING, EcruteakGym_Text_PINGSeen, EcruteakGym_Text_PINGBeaten
	msgbox EcruteakGym_Text_PINGBeaten, MSGBOX_AUTOCLOSE
	end

EcruteakGym_EventScript_MARTHA::
	trainerbattle_single TRAINER_JOHTO_MEDIUM_MARTHA, EcruteakGym_Text_MARTHASeen, EcruteakGym_Text_MARTHABeaten
	msgbox EcruteakGym_Text_MARTHABeaten, MSGBOX_AUTOCLOSE
	end

EcruteakGym_EventScript_GRACE::
	trainerbattle_single TRAINER_JOHTO_MEDIUM_GRACE, EcruteakGym_Text_GRACESeen, EcruteakGym_Text_GRACEBeaten
	msgbox EcruteakGym_Text_GRACEBeaten, MSGBOX_AUTOCLOSE
	end

EcruteakGym_EventScript_Guide::
	msgbox EcruteakGym_Text_Guide, MSGBOX_NPC
	end

EcruteakGym_Text_JEFFREYSeen:
	.string "I spent the spring\nwith my POKéMON.\pThen summer, fall\nand winter…\pThen spring came\nagain. We have\plived together\nfor a long time.$"

EcruteakGym_Text_JEFFREYBeaten:
	.string "Wins and losses, I\nexperienced both.$"

EcruteakGym_Text_PINGSeen:
	.string "Can you inflict\nany damage on our\lPOKéMON?$"

EcruteakGym_Text_PINGBeaten:
	.string "Ah! Well done!$"

EcruteakGym_Text_MARTHASeen:
	.string "I shall win!$"

EcruteakGym_Text_MARTHABeaten:
	.string "I, I, I lost!$"

EcruteakGym_Text_GRACESeen:
	.string "Stumped by our in-\nvisible floor?\pDefeat me if you\nwant a hint!$"

EcruteakGym_Text_GRACEBeaten:
	.string "Wha-what?$"

EcruteakGym_Text_Guide:
	.string "I've lived in JOHTO my whole life.\nNever thought I'd meet someone\lfrom HOENN way out here.$"
