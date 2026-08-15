Route26_MapScripts::
	.byte 0

Route26_EventScript_JAKE::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERM_JAKE, Route26_Text_JAKESeen, Route26_Text_JAKEBeaten
	msgbox Route26_Text_JAKEBeaten, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_GAVEN3::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERM_GAVEN3, Route26_Text_GAVEN3Seen, Route26_Text_GAVEN3Beaten
	msgbox Route26_Text_GAVEN3Beaten, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_JOYCE::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_JOYCE, Route26_Text_JOYCESeen, Route26_Text_JOYCEBeaten
	msgbox Route26_Text_JOYCEBeaten, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_BETH1::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_BETH1, Route26_Text_BETH1Seen, Route26_Text_BETH1Beaten
	msgbox Route26_Text_BETH1Beaten, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_RICHARD::
	trainerbattle_single TRAINER_JOHTO_PSYCHIC_T_RICHARD, Route26_Text_RICHARDSeen, Route26_Text_RICHARDBeaten
	msgbox Route26_Text_RICHARDBeaten, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_SCOTT::
	trainerbattle_single TRAINER_JOHTO_FISHER_SCOTT, Route26_Text_SCOTTSeen, Route26_Text_SCOTTBeaten
	msgbox Route26_Text_SCOTTBeaten, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Sign::
	msgbox Route26_Text_Sign, MSGBOX_SIGN
	end

Route26_Text_JAKESeen:
	.string "I'm making my\nfinal preparations\pfor the POKéMON\nLEAGUE.$"

Route26_Text_JAKEBeaten:
	.string "I blew it!$"

Route26_Text_GAVEN3Seen:
	.string "By experiencing\ntough battles, you\lgain power.$"

Route26_Text_GAVEN3Beaten:
	.string "Gaah! Life is even\ntougher!$"

Route26_Text_JOYCESeen:
	.string "Since you've come\nthis far, you must\lbe good.\pI'm going to give\nthis battle every-\lthing I've got!$"

Route26_Text_JOYCEBeaten:
	.string "No! I don't\nbelieve this!$"

Route26_Text_BETH1Seen:
	.string "I lost to a train-\ner named SILVER.\pHe was really\nstrong, but…\pIt was as if he\nabsolutely had to\lwin at any cost.\pI felt sorry for\nhis POKéMON.$"

Route26_Text_BETH1Beaten:
	.string "POKéMON aren't\ntools of war.$"

Route26_Text_RICHARDSeen:
	.string "Wow, look at all\nthose BADGES!\lI'm impressed.\pBut you're not\nsatisfied by just\pcollecting them,\nright?$"

Route26_Text_RICHARDBeaten:
	.string "Good battle!$"

Route26_Text_SCOTTSeen:
	.string "I'm feeling great\ntoday!\pI feel like I\ncould boot even\lthe LEAGUE CHAMP!$"

Route26_Text_SCOTTBeaten:
	.string "No! Not in this\nbattle!$"

Route26_Text_Sign:
	.string "ROUTE 26\pPOKéMON LEAGUE\nRECEPTION GATE$"
