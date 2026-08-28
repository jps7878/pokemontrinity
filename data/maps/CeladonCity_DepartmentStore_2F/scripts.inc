CeladonCity_DepartmentStore_2F_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_2F_EventScript_Lass::
	msgbox CeladonCity_DepartmentStore_2F_Text_Lass, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_2F_EventScript_ClerkItems::
	msgbox CeladonCity_DepartmentStore_2F_Text_ClerkItems, MSGBOX_NPC
	end

@ ============================================================================
@ Trinity M5b S6 -- the premium TM mart, Celadon's top rung. Dedup derived
@ against the S2-era award lists (Hoenn/Johto/Kanto badge TMs, all unioned)
@ -- see 06-celadon-chapter.md section 6 for the full derivation. TM01-50
@ only: TM51-100 are unimplemented placeholder item entries (sQuestionMarksDesc,
@ src/data/items.h), confirmed by reading the data directly, not assumed.
@ ============================================================================
CeladonCity_DepartmentStore_2F_EventScript_ClerkTMs::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_2F_Pokemart_TMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
CeladonCity_DepartmentStore_2F_Pokemart_TMs:
	.2byte ITEM_TM13
	.2byte ITEM_TM14
	.2byte ITEM_TM15
	.2byte ITEM_TM16
	.2byte ITEM_TM17
	.2byte ITEM_TM25
	.2byte ITEM_TM33
	.2byte ITEM_TM35
	pokemartlistend

CeladonCity_DepartmentStore_2F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_2F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_2F_Text_Lass:
	.string "For long outings, you should buy\nREVIVE.$"

CeladonCity_DepartmentStore_2F_Text_ClerkItems:
	.string "Battle items, healing items, the\nusual essentials -- that's my\lcounter. TMs are over there.$"

CeladonCity_DepartmentStore_2F_Text_FloorSign:
	.string "Top-Grade Items for TRAINERS!\p2F: TRAINER'S MARKET$"
