SafariZone_East_MapScripts::
	.byte 0

SafariZone_East_EventScript_AreaSign::
	msgbox SafariZone_East_Text_AreaSign, MSGBOX_SIGN
	end

SafariZone_East_EventScript_RestHouseSign::
	msgbox SafariZone_East_Text_RestHouseSign, MSGBOX_SIGN
	end

SafariZone_East_EventScript_TrainerTips::
	msgbox SafariZone_East_Text_TrainerTips, MSGBOX_SIGN
	end

SafariZone_East_Text_AreaSign:
	.string "AREA 1\nWEST: CENTER AREA$"

SafariZone_East_Text_RestHouseSign:
	.string "REST HOUSE$"

SafariZone_East_Text_TrainerTips:
	.string "TRAINER TIPS\pThe remaining time declines only\nwhile you walk.$"
