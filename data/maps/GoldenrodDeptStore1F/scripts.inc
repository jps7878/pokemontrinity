GoldenrodDeptStore1F_MapScripts::
	.byte 0

GoldenrodDeptStore1F_EventScript_Receptionist::
	msgbox GoldenrodDeptStore1F_Text_Receptionist, MSGBOX_NPC
	end

GoldenrodDeptStore1F_EventScript_PokefanF::
	msgbox GoldenrodDeptStore1F_Text_PokefanF, MSGBOX_NPC
	end

GoldenrodDeptStore1F_EventScript_BugCatcher::
	msgbox GoldenrodDeptStore1F_Text_BugCatcher, MSGBOX_NPC
	end

GoldenrodDeptStore1F_EventScript_Gentleman::
	msgbox GoldenrodDeptStore1F_Text_Gentleman, MSGBOX_NPC
	end

GoldenrodDeptStore1F_EventScript_Directory::
	msgbox GoldenrodDeptStore1F_Text_Directory, MSGBOX_SIGN
	end

GoldenrodDeptStore1F_Text_Receptionist:
	.string "Welcome to GOLDENROD\n"
	.string "DEPT.STORE.\p"
	.string "The directory is on the wall.\n"
	.string "5F has a new tenant this\l"
	.string "season -- do brace yourself.$"

GoldenrodDeptStore1F_Text_PokefanF:
	.string "I'm raring to shop\nagain today!$"

GoldenrodDeptStore1F_Text_BugCatcher:
	.string "Mom's good at\nbargain hunting.\pShe always buys\nstuff at lower\lprices.$"

GoldenrodDeptStore1F_Text_Gentleman:
	.string "The DEPT.STORE\nhas a decent se-\llection.\pBut some items\nare only available\pas GAME CORNER\nprizes.$"

GoldenrodDeptStore1F_Text_Directory:
	.string "1F SERVICE COUNTER\p2F TRAINER'S\n   MARKET\p3F BATTLE\n   COLLECTION\p4F MEDICINE BOX\p5F TM CORNER\p6F TRANQUIL SQUARE\pROOFTOP LOOKOUT$"
