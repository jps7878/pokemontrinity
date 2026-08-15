BillsFamilysHouse_MapScripts::
	.byte 0

BillsFamilysHouse_EventScript_BillsMom::
	msgbox BillsFamilysHouse_Text_BillsMom, MSGBOX_NPC
	end

BillsFamilysHouse_EventScript_BillsYoungerSister::
	msgbox BillsFamilysHouse_Text_BillsYoungerSister, MSGBOX_NPC
	end

BillsFamilysHouse_Text_BillsMom:
	.string "I've been wandering these routes\nfor years. Lately there's talk of\lnothing but the HOENN champion.$"

BillsFamilysHouse_Text_BillsYoungerSister:
	.string "I've lived in JOHTO my whole life.\nNever thought I'd meet someone\lfrom HOENN way out here.$"
