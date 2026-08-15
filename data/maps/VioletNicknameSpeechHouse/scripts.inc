VioletNicknameSpeechHouse_MapScripts::
	.byte 0

VioletNicknameSpeechHouse_EventScript_Teacher::
	msgbox VioletNicknameSpeechHouse_Text_Teacher, MSGBOX_NPC
	end

VioletNicknameSpeechHouse_EventScript_Lass::
	msgbox VioletNicknameSpeechHouse_Text_Lass, MSGBOX_NPC
	end

VioletNicknameSpeechHouse_Text_Teacher:
	.string "She uses the names\nof her favorite\lthings to eat.\pFor the nicknames\nshe gives to her\lPOKéMON, I mean.$"

VioletNicknameSpeechHouse_Text_Lass:
	.string "I call my PIDGEY\nSTRAWBERRY!$"
