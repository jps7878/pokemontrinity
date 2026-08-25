LavenderTown_MapScripts::
	.byte 0

LavenderTown_EventScript_LittleGirl::
	msgbox LavenderTown_Text_LittleGirl, MSGBOX_NPC
	end

LavenderTown_EventScript_WorkerM::
	msgbox LavenderTown_Text_WorkerM, MSGBOX_NPC
	end

LavenderTown_EventScript_Boy::
	msgbox LavenderTown_Text_Boy, MSGBOX_NPC
	end

LavenderTown_EventScript_SilphScopeNotice::
	msgbox LavenderTown_Text_SilphScopeNotice, MSGBOX_SIGN
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_TownSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_PokemonTowerSign::
	msgbox LavenderTown_Text_PokemonTowerSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerHouseSign::
	msgbox LavenderTown_Text_VolunteerHouseSign, MSGBOX_SIGN
	end

LavenderTown_Text_LittleGirl:
	.string "KANTO's a long way from HOENN,\nbut word of that champion still\lmade it all the way here.$"

LavenderTown_Text_WorkerM:
	.string "This town is known as the grave\nsite of POKéMON.\pMemorial services are held in\nPOKéMON TOWER.$"

LavenderTown_Text_Boy:
	.string "Ghosts appeared in POKéMON TOWER.\pI think they're the spirits of\nPOKéMON that the ROCKETS killed.$"

LavenderTown_Text_SilphScopeNotice:
	.string "New SILPH SCOPE!\nMake the Invisible Plain to See!\pSILPH CO.$"

LavenderTown_Text_TownSign:
	.string "LAVENDER TOWN\nThe Noble Purple Town$"

LavenderTown_Text_PokemonTowerSign:
	.string "POKéMON TOWER\nBecalm the Spirits of POKéMON$"

LavenderTown_Text_VolunteerHouseSign:
	.string "LAVENDER VOLUNTEER\nPOKéMON HOUSE$"
