RadioTower4F_MapScripts::
	.byte 0

RadioTower4F_EventScript_DJMary::
	msgbox RadioTower4F_Text_DJMary, MSGBOX_NPC
	end

RadioTower4F_EventScript_ProductionSign::
	msgbox RadioTower4F_Text_ProductionSign, MSGBOX_SIGN
	end

RadioTower4F_EventScript_Studio2Sign::
	msgbox RadioTower4F_Text_Studio2Sign, MSGBOX_SIGN
	end

RadioTower4F_Text_DJMary:
	.string "They say the HOENN champion's\njourney is just getting started.\lWonder where they'll go next.$"

RadioTower4F_Text_ProductionSign:
	.string "4F PRODUCTION$"

RadioTower4F_Text_Studio2Sign:
	.string "4F STUDIO 2$"
