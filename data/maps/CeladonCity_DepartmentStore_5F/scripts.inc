CeladonCity_DepartmentStore_5F_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_5F_EventScript_Gentleman::
	msgbox CeladonCity_DepartmentStore_5F_Text_Gentleman, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_5F_EventScript_Sailor::
	msgbox CeladonCity_DepartmentStore_5F_Text_Sailor, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_5F_EventScript_ClerkXItems::
	msgbox CeladonCity_DepartmentStore_5F_Text_ClerkXItems, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_5F_EventScript_ClerkVitamins::
	msgbox CeladonCity_DepartmentStore_5F_Text_ClerkVitamins, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_5F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_5F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_5F_Text_Gentleman:
	.string "POKéMON stat enhancers can be\nbought only here.\pHP UP increases the base HP of a\nPOKéMON.\pCALCIUM raises the base SP. ATK\nstat of one POKéMON.\pZINC boosts the base SP. DEF stat\nof one POKéMON.\pCARBOS enhances the base SPEED\nstat.$"

CeladonCity_DepartmentStore_5F_Text_Sailor:
	.string "I'm here for POKéMON stat\nenhancers.\pPROTEIN increases the base ATTACK\npower.\pIRON increases the base DEFENSE\nstat.$"

CeladonCity_DepartmentStore_5F_Text_ClerkXItems:
	.string "Folks in KANTO don't get many\nvisitors from HOENN. Word is one\lof them cleaned up in JOHTO too.$"

CeladonCity_DepartmentStore_5F_Text_ClerkVitamins:
	.string "KANTO's peaceful most days, but\neven here we've heard the stories\labout that HOENN trainer.$"

CeladonCity_DepartmentStore_5F_Text_FloorSign:
	.string "5F: DRUGSTORE$"
