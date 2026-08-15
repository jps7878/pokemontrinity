AzaleaMart_MapScripts::
	.byte 0

AzaleaMart_EventScript_Clerk::
	msgbox AzaleaMart_Text_Clerk, MSGBOX_NPC
	end

AzaleaMart_EventScript_CooltrainerM::
	msgbox AzaleaMart_Text_CooltrainerM, MSGBOX_NPC
	end

AzaleaMart_EventScript_BugCatcher::
	msgbox AzaleaMart_Text_BugCatcher, MSGBOX_NPC
	end

AzaleaMart_Text_Clerk:
	.string "Word is a strong trainer crossed\nthe sea from HOENN. I wonder if\lthey'll pass through JOHTO too.$"

AzaleaMart_Text_CooltrainerM:
	.string "There's no GREAT\nBALL here. POKé\pBALLS will have\nto do.\pI wish KURT would\nmake me some of\lhis custom BALLS.$"

AzaleaMart_Text_BugCatcher:
	.string "A GREAT BALL is\nbetter for catch-\ling POKéMON than a\lPOKé BALL.\pBut KURT's might\nbe better some-\ltimes.$"
