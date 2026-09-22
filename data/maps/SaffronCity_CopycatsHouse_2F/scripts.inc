SaffronCity_CopycatsHouse_2F_MapScripts::
	.byte 0

SaffronCity_CopycatsHouse_2F_EventScript_Doll::
	msgbox SaffronCity_CopycatsHouse_2F_Text_Doll, MSGBOX_NPC
	end

SaffronCity_CopycatsHouse_2F_EventScript_Copycat::
	msgbox SaffronCity_CopycatsHouse_2F_Text_Copycat, MSGBOX_NPC
	end

SaffronCity_CopycatsHouse_2F_EventScript_Computer::
	msgbox SaffronCity_CopycatsHouse_2F_Text_Computer, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_EventScript_Game::
	msgbox SaffronCity_CopycatsHouse_2F_Text_Game, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_Text_Doll:
	.string "This is a rare POKéMON!\nHuh? It's only a doll!$"

SaffronCity_CopycatsHouse_2F_Text_Copycat:
	.string "I copy people. You're easy --\nyou walk like you own the road.$"

SaffronCity_CopycatsHouse_2F_Text_Computer:
	.string "…\pMy Secrets!\pSkill: Mimicry!\nHobby: Collecting dolls!\lFavorite POKéMON: CLEFAIRY!$"

SaffronCity_CopycatsHouse_2F_Text_Game:
	.string "A game with MARIO wearing a bucket\non his head!$"
