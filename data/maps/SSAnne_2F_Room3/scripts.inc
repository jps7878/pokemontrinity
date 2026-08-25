SSAnne_2F_Room3_MapScripts::
	.byte 0

SSAnne_2F_Room3_EventScript_Gentleman::
	msgbox SSAnne_2F_Room3_Text_Gentleman, MSGBOX_NPC
	end

SSAnne_2F_Room3_EventScript_OldMan::
	msgbox SSAnne_2F_Room3_Text_OldMan, MSGBOX_NPC
	end

SSAnne_2F_Room3_Text_Gentleman:
	.string "Ah, yes, I have seen some POKéMON\nferry people across the water!$"

SSAnne_2F_Room3_Text_OldMan:
	.string "Small trees can be chopped down\nusing the move CUT.\pBut remember this!\nCUT is an HM technique.\pOnce learned, it is not so easily\ndiscarded.$"
