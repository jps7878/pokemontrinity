ViridianCity_School_MapScripts::
	.byte 0

ViridianCity_School_EventScript_Woman::
	msgbox ViridianCity_School_Text_Woman, MSGBOX_NPC
	end

ViridianCity_School_EventScript_Lass::
	msgbox ViridianCity_School_Text_Lass, MSGBOX_NPC
	end

ViridianCity_School_EventScript_Notebook::
	msgbox ViridianCity_School_Text_Notebook, MSGBOX_SIGN
	end

ViridianCity_School_EventScript_Blackboard::
	msgbox ViridianCity_School_Text_Blackboard, MSGBOX_SIGN
	end

ViridianCity_School_EventScript_Blackboard_2::
	msgbox ViridianCity_School_Text_Blackboard_2, MSGBOX_SIGN
	end

ViridianCity_School_Text_Woman:
	.string "Okay!\pBe sure to read what's on the\nblackboard carefully!$"

ViridianCity_School_Text_Lass:
	.string "Whew! I'm trying to memorize all my\nnotes.$"

ViridianCity_School_Text_Notebook:
	.string "A notebook left open on the\ndesk. The page will not turn.$"

ViridianCity_School_Text_Blackboard:
	.string "The blackboard lists POKéMON\nSTATUS problems during battles.$"

ViridianCity_School_Text_Blackboard_2:
	.string "The blackboard lists POKéMON\nSTATUS problems during battles.$"
