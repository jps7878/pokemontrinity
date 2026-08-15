NewBarkTown_MapScripts::
	.byte 0

NewBarkTown_EventScript_Teacher::
	msgbox NewBarkTown_Text_Teacher, MSGBOX_NPC
	end

NewBarkTown_EventScript_Fisher::
	msgbox NewBarkTown_Text_Fisher, MSGBOX_NPC
	end

NewBarkTown_EventScript_Sign::
	msgbox NewBarkTown_Text_Sign, MSGBOX_SIGN
	end

NewBarkTown_EventScript_PlayersHouseSign::
	msgbox NewBarkTown_Text_PlayersHouseSign, MSGBOX_SIGN
	end

NewBarkTown_EventScript_ElmsLabSign::
	msgbox NewBarkTown_Text_ElmsLabSign, MSGBOX_SIGN
	end

NewBarkTown_EventScript_ElmsHouseSign::
	msgbox NewBarkTown_Text_ElmsHouseSign, MSGBOX_SIGN
	end

NewBarkTown_Text_Teacher:
	.string "Did you hear? A HOENN trainer\nbecame Champion, and now folks\lhere want to challenge them.$"

NewBarkTown_Text_Fisher:
	.string "Yo, {PLAYER}!\pI hear PROF.ELM\ndiscovered some\lnew POKéMON.$"

NewBarkTown_Text_Sign:
	.string "NEW BARK TOWN\pThe Town Where the\nWinds of a New\lBeginning Blow$"

NewBarkTown_Text_PlayersHouseSign:
	.string "{PLAYER}'s House$"

NewBarkTown_Text_ElmsLabSign:
	.string "ELM POKéMON LAB$"

NewBarkTown_Text_ElmsHouseSign:
	.string "ELM'S HOUSE$"
