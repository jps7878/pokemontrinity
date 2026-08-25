CeladonCity_DepartmentStore_1F_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_1F_EventScript_Receptionist::
	msgbox CeladonCity_DepartmentStore_1F_Text_Receptionist, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_1F_EventScript_LayoutSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_LayoutSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_1F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_1F_Text_Receptionist:
	.string "Hello!\nWelcome to CELADON DEPT. STORE.\pThe board on the right describes\nthe store layout.$"

CeladonCity_DepartmentStore_1F_Text_LayoutSign:
	.string "1F: SERVICE COUNTER\p2F: TRAINER'S MARKET\p3F: TV GAME SHOP\p4F: WISE MAN GIFTS\p5F: DRUGSTORE\pROOFTOP SQUARE: VENDING MACHINES$"

CeladonCity_DepartmentStore_1F_Text_FloorSign:
	.string "1F: SERVICE COUNTER$"
