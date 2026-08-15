Route32Pokecenter1F_MapScripts::
	.byte 0

Route32Pokecenter1F_EventScript_Nurse::
	msgbox Route32Pokecenter1F_Text_Nurse, MSGBOX_NPC
	end

Route32Pokecenter1F_EventScript_FishingGuru::
	msgbox Route32Pokecenter1F_Text_FishingGuru, MSGBOX_NPC
	end

Route32Pokecenter1F_EventScript_CooltrainerF::
	msgbox Route32Pokecenter1F_Text_CooltrainerF, MSGBOX_NPC
	end

Route32Pokecenter1F_Text_Nurse:
	.string "Did you hear? A HOENN trainer\nbecame Champion, and now folks\lhere want to challenge them.$"

Route32Pokecenter1F_Text_FishingGuru:
	.string "Did you hear? A HOENN trainer\nbecame Champion, and now folks\lhere want to challenge them.$"

Route32Pokecenter1F_Text_CooltrainerF:
	.string "What should I make\nmy POKéMON hold?\pMaybe an item that\nincreases ATTACK\lpower…$"
