CeladonCity_DepartmentStore_4F_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_4F_EventScript_Man::
	msgbox CeladonCity_DepartmentStore_4F_Text_Man, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox CeladonCity_DepartmentStore_4F_Text_Youngster, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_EventScript_Clerk::
	msgbox CeladonCity_DepartmentStore_4F_Text_Clerk, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_4F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_4F_Text_Man:
	.string "I'm getting a present for my\ngirlfriend.\pI guess a POKé DOLL will be it.\nIt's the popular thing.$"

CeladonCity_DepartmentStore_4F_Text_Youngster:
	.string "I heard something useful.\pIf a wild POKéMON appears, you can\ndistract it with a POKé DOLL.\pYou can run away while the wild\nPOKéMON is distracted.$"

CeladonCity_DepartmentStore_4F_Text_Clerk:
	.string "My grandkids keep going on about\nsome trainer from HOENN. Sounds\llike quite the journey so far.$"

CeladonCity_DepartmentStore_4F_Text_FloorSign:
	.string "Express yourself with gifts!\n4F: WISE MAN GIFTS\pEvolution Special!\nElement STONES on sale now!$"
