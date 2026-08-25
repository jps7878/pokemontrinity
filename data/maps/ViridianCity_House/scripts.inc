ViridianCity_House_MapScripts::
	.byte 0

ViridianCity_House_EventScript_BaldingMan::
	msgbox ViridianCity_House_Text_BaldingMan, MSGBOX_NPC
	end

ViridianCity_House_EventScript_LittleGirl::
	msgbox ViridianCity_House_Text_LittleGirl, MSGBOX_NPC
	end

ViridianCity_House_EventScript_NicknameSign::
	msgbox ViridianCity_House_Text_NicknameSign, MSGBOX_SIGN
	end

ViridianCity_House_Text_BaldingMan:
	.string "Coming up with nicknames is fun,\nbut it's not so easy to do.\pClever names are nice, but simple\nnames are easier to remember.$"

ViridianCity_House_Text_LittleGirl:
	.string "My daddy loves POKéMON, too.$"

ViridianCity_House_Text_NicknameSign:
	.string "SPEAROW\nName: SPEARY$"
