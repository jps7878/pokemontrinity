CinnabarIsland_PokemonLab_Entrance_MapScripts::
	.byte 0

CinnabarIsland_PokemonLab_Entrance_EventScript_Scientist::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_Scientist, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_DrFujiPhoto::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_DrFujiPhoto, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_MeetingRoomSign::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_MeetingRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_RAndDRoomSign::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_RAndDRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_TestingRoomSign::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_TestingRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_Text_Scientist:
	.string "We study POKéMON extensively\nevery day.\pPeople often bring us rare POKéMON\nfor examination.$"

CinnabarIsland_PokemonLab_Entrance_Text_DrFujiPhoto:
	.string "A photo of the LAB's founder…\nDR. FUJI?!$"

CinnabarIsland_PokemonLab_Entrance_Text_MeetingRoomSign:
	.string "POKéMON LAB\nMeeting Room$"

CinnabarIsland_PokemonLab_Entrance_Text_RAndDRoomSign:
	.string "POKéMON LAB\nR & D Room$"

CinnabarIsland_PokemonLab_Entrance_Text_TestingRoomSign:
	.string "POKéMON LAB\nTesting Room$"
