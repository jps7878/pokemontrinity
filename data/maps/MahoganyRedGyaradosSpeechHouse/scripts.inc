MahoganyRedGyaradosSpeechHouse_MapScripts::
	.byte 0

MahoganyRedGyaradosSpeechHouse_EventScript_BlackBelt::
	msgbox MahoganyRedGyaradosSpeechHouse_Text_BlackBelt, MSGBOX_NPC
	end

MahoganyRedGyaradosSpeechHouse_EventScript_Teacher::
	msgbox MahoganyRedGyaradosSpeechHouse_Text_Teacher, MSGBOX_NPC
	end

MahoganyRedGyaradosSpeechHouse_Text_BlackBelt:
	.string "I heard that a red\nGYARADOS appeared\lat the LAKE.\pThat's odd, since\neven ordinary\pGYARADOS are rare\nin that lake…$"

MahoganyRedGyaradosSpeechHouse_Text_Teacher:
	.string "I've lived in JOHTO my whole life.\nNever thought I'd meet someone\lfrom HOENN way out here.$"
