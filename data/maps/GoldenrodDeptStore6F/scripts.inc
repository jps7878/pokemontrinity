GoldenrodDeptStore6F_MapScripts::
	.byte 0

GoldenrodDeptStore6F_EventScript_Lass::
	msgbox GoldenrodDeptStore6F_Text_Lass, MSGBOX_NPC
	end

GoldenrodDeptStore6F_EventScript_SuperNerd::
	msgbox GoldenrodDeptStore6F_Text_SuperNerd, MSGBOX_NPC
	end

GoldenrodDeptStore6F_EventScript_Directory::
	msgbox GoldenrodDeptStore6F_Text_Directory, MSGBOX_SIGN
	end

GoldenrodDeptStore6F_Text_Lass:
	.string "Do you listen to\nLUCKY CHANNEL?\pIf you want to\nwin, trade POKéMON\pwith as many peo-\nple as possible to\pget different ID\nnumbers.$"

GoldenrodDeptStore6F_Text_SuperNerd:
	.string "If you're tired,\ntry the vending\lmachine's drinks.\pYour POKéMON will\nlove them too.$"

GoldenrodDeptStore6F_Text_Directory:
	.string "Take a Break from\nShopping!\p6F TRANQUIL SQUARE$"
