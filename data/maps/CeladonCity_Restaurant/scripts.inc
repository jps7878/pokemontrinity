CeladonCity_Restaurant_MapScripts::
	.byte 0

CeladonCity_Restaurant_EventScript_Chef::
	msgbox CeladonCity_Restaurant_Text_Chef, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_Woman::
	msgbox CeladonCity_Restaurant_Text_Woman, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_FatMan::
	msgbox CeladonCity_Restaurant_Text_FatMan, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_CoinCaseMan::
	msgbox CeladonCity_Restaurant_Text_CoinCaseMan, MSGBOX_NPC
	end

CeladonCity_Restaurant_EventScript_WorkerM::
	msgbox CeladonCity_Restaurant_Text_WorkerM, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_Chef:
	.string "Hi!\pSorry, but we're taking a break\nright now.$"

CeladonCity_Restaurant_Text_Woman:
	.string "My POKéMON are weak, so I often\nhave to go to the DRUGSTORE.$"

CeladonCity_Restaurant_Text_FatMan:
	.string "Munch…\pThe man at that table lost it all\nat the slots.$"

CeladonCity_Restaurant_Text_CoinCaseMan:
	.string "I kept a COIN CASE for the GAME\nCORNER. The CORNER is dead.\lSo is the case.$"

CeladonCity_Restaurant_Text_WorkerM:
	.string "Psst! There's a basement under the\nGAME CORNER, I hear.$"
