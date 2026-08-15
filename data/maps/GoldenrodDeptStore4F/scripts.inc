GoldenrodDeptStore4F_MapScripts::
	.byte 0

GoldenrodDeptStore4F_EventScript_Clerk::
	msgbox GoldenrodDeptStore4F_Text_Clerk, MSGBOX_NPC
	end

GoldenrodDeptStore4F_EventScript_CooltrainerM::
	msgbox GoldenrodDeptStore4F_Text_CooltrainerM, MSGBOX_NPC
	end

GoldenrodDeptStore4F_EventScript_BugCatcher::
	msgbox GoldenrodDeptStore4F_Text_BugCatcher, MSGBOX_NPC
	end

GoldenrodDeptStore4F_EventScript_Directory::
	msgbox GoldenrodDeptStore4F_Text_Directory, MSGBOX_SIGN
	end

GoldenrodDeptStore4F_Text_Clerk:
	.string "My grandkids won't stop talking\nabout the new champion from over\lin HOENN. Kids these days!$"

GoldenrodDeptStore4F_Text_CooltrainerM:
	.string "Hey. I love strong\nPOKéMON.\pI feed them PRO-\nTEIN to crank up\ltheir ATTACK.$"

GoldenrodDeptStore4F_Text_BugCatcher:
	.string "IRON adds to your\nPOKéMON's DEFENSE.$"

GoldenrodDeptStore4F_Text_Directory:
	.string "Let Us Pump Up\nYour POKéMON!\p4F MEDICINE BOX$"
