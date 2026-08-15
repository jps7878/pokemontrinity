GoldenrodDeptStore3F_MapScripts::
	.byte 0

GoldenrodDeptStore3F_EventScript_Clerk::
	msgbox GoldenrodDeptStore3F_Text_Clerk, MSGBOX_NPC
	end

GoldenrodDeptStore3F_EventScript_SuperNerd::
	msgbox GoldenrodDeptStore3F_Text_SuperNerd, MSGBOX_NPC
	end

GoldenrodDeptStore3F_EventScript_Rocker::
	msgbox GoldenrodDeptStore3F_Text_Rocker, MSGBOX_NPC
	end

GoldenrodDeptStore3F_EventScript_Directory::
	msgbox GoldenrodDeptStore3F_Text_Directory, MSGBOX_SIGN
	end

GoldenrodDeptStore3F_Text_Clerk:
	.string "Did you hear? A HOENN trainer\nbecame Champion, and now folks\lhere want to challenge them.$"

GoldenrodDeptStore3F_Text_SuperNerd:
	.string "I, I, I'm really\nimpatient!\pI use X SPEED in\nbattle to speed up\lmy POKéMON.$"

GoldenrodDeptStore3F_Text_Rocker:
	.string "Hey! When you bat-\ntle, do you use X\lSPECIAL?\pIt's awesome. It\nreally jacks up\lSPECIAL ATTACK!$"

GoldenrodDeptStore3F_Text_Directory:
	.string "For Victory\nSeekers\p3F BATTLE\n   COLLECTION$"
