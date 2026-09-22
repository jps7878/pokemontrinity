LavenderTown_VolunteerPokemonHouse_MapScripts::
	.byte 0

@ M5b S7. GSC/FRLG Fuji reconciliation (docs/superpowers/plans/m5b/
@ 07-lavender-rock-tunnel.md #1-2): in FRLG, Fuji only reaches this house via
@ a ghost-Marowak/Rocket-captivity rescue scene -- that RBY-past plot was
@ never ported and isn't being added here. Fuji is simply present, tending
@ the house, matching both FRLG's own rescue destination and GSC's Soul
@ House assignment. No gating flag -- there is no rescue scene for one to
@ gate.
LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFuji, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_LittleBoy, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Youngster::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_LittleGirl, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_PokemonFanMagazine, MSGBOX_SIGN
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Bookshelf, MSGBOX_SIGN
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf_2::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Bookshelf_2, MSGBOX_SIGN
	end

LavenderTown_VolunteerPokemonHouse_Text_MrFuji:
	.string "Ah -- a trainer, and a friend to\nPOKéMON too, I'd wager.\pWe look after the ones who've\nlost their families here.\pQuiet work, but KANTO's calm\nnow. I think they rest easier.$"

LavenderTown_VolunteerPokemonHouse_Text_LittleBoy:
	.string "It's so warm!\nPOKéMON are so nice to hug.$"

LavenderTown_VolunteerPokemonHouse_Text_Youngster:
	.string "That's odd, MR. FUJI isn't here.\nWhere'd he go?$"

LavenderTown_VolunteerPokemonHouse_Text_LittleGirl:
	.string "This is really MR. FUJI's house.\pHe's really kind.\pHe looks after abandoned and\norphaned POKéMON.$"

LavenderTown_VolunteerPokemonHouse_Text_PokemonFanMagazine:
	.string "POKéMON FAN MAGAZINE\nMonthly Grand Prize Drawing!\pThe application form is…\pGone! It's been clipped out.\nSomeone must have applied already.$"

LavenderTown_VolunteerPokemonHouse_Text_Bookshelf:
	.string "POKéMON magazines line the shelf.\pPOKéMON INSIDER…\pPOKéMON FAN…$"

LavenderTown_VolunteerPokemonHouse_Text_Bookshelf_2:
	.string "POKéMON magazines line the shelf.\pPOKéMON INSIDER…\pPOKéMON FAN…$"
