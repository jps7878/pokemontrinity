OlivinePunishmentSpeechHouse_MapScripts::
	.byte 0

OlivinePunishmentSpeechHouse_EventScript_Dad::
	msgbox OlivinePunishmentSpeechHouse_Text_Dad, MSGBOX_NPC
	end

OlivinePunishmentSpeechHouse_EventScript_Daughter::
	msgbox OlivinePunishmentSpeechHouse_Text_Daughter, MSGBOX_NPC
	end

OlivinePunishmentSpeechHouse_Text_Dad:
	.string "Along the way to\nCIANWOOD, there\pare four deserted\nislands.\pBad kids are taken\nto the islands as\lpunishment!$"

OlivinePunishmentSpeechHouse_Text_Daughter:
	.string "Whenever I get in\ntrouble, Daddy\lalways scares me.$"
