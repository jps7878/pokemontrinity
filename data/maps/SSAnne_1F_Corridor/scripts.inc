SSAnne_1F_Corridor_MapScripts::
	.byte 0

SSAnne_1F_Corridor_EventScript_Sailor::
	msgbox SSAnne_1F_Corridor_Text_Sailor, MSGBOX_NPC
	end

SSAnne_1F_Corridor_EventScript_WorkerM::
	msgbox SSAnne_1F_Corridor_Text_WorkerM, MSGBOX_NPC
	end

SSAnne_1F_Corridor_Text_Sailor:
	.string "The passengers are restless from\nthis long voyage.\pYou might be challenged by the\nmore bored ones!$"

SSAnne_1F_Corridor_Text_WorkerM:
	.string "Bonjour!\nI am le waiter on this ship!\pI will be happy to serve you\nanything you please!\p… … …\nAh! Le strong silent type!$"
