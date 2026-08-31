SafariZone_West_MapScripts::
	.byte 0

SafariZone_West_EventScript_LostTeethNotice::
	msgbox SafariZone_West_Text_LostTeethNotice, MSGBOX_SIGN
	end

SafariZone_West_EventScript_TrainerTips::
	msgbox SafariZone_West_Text_TrainerTips, MSGBOX_SIGN
	end

SafariZone_West_EventScript_AreaSign::
	msgbox SafariZone_West_Text_AreaSign, MSGBOX_SIGN
	end

SafariZone_West_EventScript_RestHouseSign::
	msgbox SafariZone_West_Text_RestHouseSign, MSGBOX_SIGN
	end

SafariZone_West_Text_LostTeethNotice:
	.string "NOTICE\pThe SAFARI WARDEN lost his GOLD\nTEETH out here somewhere.\lProbably still around, if anyone's\lcurious.$"

SafariZone_West_Text_TrainerTips:
	.string "TRAINER TIPS\pZone Exploration Campaign!\nThe Search for the SECRET HOUSE!$"

SafariZone_West_Text_AreaSign:
	.string "AREA 3\nEAST: CENTER AREA$"

SafariZone_West_Text_RestHouseSign:
	.string "REST HOUSE$"
