CinnabarIsland_MapScripts::
	.byte 0

CinnabarIsland_EventScript_Woman::
	msgbox CinnabarIsland_Text_Woman, MSGBOX_NPC
	end

CinnabarIsland_EventScript_OldMan::
	msgbox CinnabarIsland_Text_OldMan, MSGBOX_NPC
	end

CinnabarIsland_EventScript_IslandSign::
	msgbox CinnabarIsland_Text_IslandSign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_PokemonLabSign::
	msgbox CinnabarIsland_Text_PokemonLabSign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_GymSign::
	msgbox CinnabarIsland_Text_GymSign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_PokemonLabSign_2::
	msgbox CinnabarIsland_Text_PokemonLabSign_2, MSGBOX_SIGN
	end

CinnabarIsland_Text_Woman:
	.string "This route's seen more foot traffic\nlately. Something about a champion\lpassing through from JOHTO.$"

CinnabarIsland_Text_OldMan:
	.string "Scientists conduct experiments \nin the burned-out building.\pYou know, the one they call the\nPOKéMON MANSION.$"

CinnabarIsland_Text_IslandSign:
	.string "CINNABAR ISLAND\nThe Fiery Town of Burning Desire$"

CinnabarIsland_Text_PokemonLabSign:
	.string "POKéMON LAB$"

CinnabarIsland_Text_GymSign:
	.string "KANTO's peaceful most days, but\neven here we've heard the stories\labout that HOENN trainer.$"

CinnabarIsland_Text_PokemonLabSign_2:
	.string "POKéMON LAB$"
