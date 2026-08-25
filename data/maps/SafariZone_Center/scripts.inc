SafariZone_Center_MapScripts::
	.byte 0

SafariZone_Center_EventScript_RestHouseSign::
	msgbox SafariZone_Center_Text_RestHouseSign, MSGBOX_SIGN
	end

SafariZone_Center_EventScript_TrainerTips::
	msgbox SafariZone_Center_Text_TrainerTips, MSGBOX_SIGN
	end

SafariZone_Center_EventScript_AreaSign::
	msgbox SafariZone_Center_Text_AreaSign, MSGBOX_SIGN
	end

SafariZone_Center_Text_RestHouseSign:
	.string "REST HOUSE$"

SafariZone_Center_Text_TrainerTips:
	.string "TRAINER TIPS\pPress START to check\nremaining time.$"

SafariZone_Center_Text_AreaSign:
	.string "CENTER AREA$"
