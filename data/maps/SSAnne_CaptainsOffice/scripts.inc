SSAnne_CaptainsOffice_MapScripts::
	.byte 0

SSAnne_CaptainsOffice_EventScript_Captain::
	msgbox SSAnne_CaptainsOffice_Text_Captain, MSGBOX_NPC
	end

SSAnne_CaptainsOffice_EventScript_Book::
	msgbox SSAnne_CaptainsOffice_Text_Book, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_EventScript_TrashCan::
	msgbox SSAnne_CaptainsOffice_Text_TrashCan, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_EventScript_Book_2::
	msgbox SSAnne_CaptainsOffice_Text_Book_2, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_Text_Captain:
	.string "Folks in KANTO don't get many\nvisitors from HOENN. Word is one\lof them cleaned up in JOHTO too.$"

SSAnne_CaptainsOffice_Text_Book:
	.string "How to Conquer Seasickness…\nThe CAPTAIN's reading this!$"

SSAnne_CaptainsOffice_Text_TrashCan:
	.string "Yuck!\nShouldn't have looked!$"

SSAnne_CaptainsOffice_Text_Book_2:
	.string "How to Conquer Seasickness…\nThe CAPTAIN's reading this!$"
