ElmsLab_MapScripts::
	.byte 0

ElmsLab_EventScript_TravelTip1::
	msgbox ElmsLab_Text_TravelTip1, MSGBOX_SIGN
	end

ElmsLab_EventScript_TravelTip2::
	msgbox ElmsLab_Text_TravelTip2, MSGBOX_SIGN
	end

ElmsLab_EventScript_TravelTip3::
	msgbox ElmsLab_Text_TravelTip3, MSGBOX_SIGN
	end

ElmsLab_EventScript_TravelTip4::
	msgbox ElmsLab_Text_TravelTip4, MSGBOX_SIGN
	end

ElmsLab_EventScript_Trashcan::
	msgbox ElmsLab_Text_Trashcan, MSGBOX_SIGN
	end

ElmsLab_Text_TravelTip1:
	.string "{PLAYER} opened a\nbook.\pTravel Tip 1:\pPress START to\nopen the MENU.$"

ElmsLab_Text_TravelTip2:
	.string "{PLAYER} opened a\nbook.\pTravel Tip 2:\pRecord your trip\nwith SAVE!$"

ElmsLab_Text_TravelTip3:
	.string "{PLAYER} opened a\nbook.\pTravel Tip 3:\pOpen your PACK and\npress SELECT to\lmove items.$"

ElmsLab_Text_TravelTip4:
	.string "{PLAYER} opened a\nbook.\pTravel Tip 4:\pCheck your POKéMON\nmoves. Press the\pA Button to switch\nmoves.$"

ElmsLab_Text_Trashcan:
	.string "The wrapper from\nthe snack PROF.ELM\late is in there…$"
