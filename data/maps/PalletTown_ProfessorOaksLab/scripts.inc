PalletTown_ProfessorOaksLab_MapScripts::
	.byte 0

PalletTown_ProfessorOaksLab_EventScript_Aide1::
	msgbox PalletTown_ProfessorOaksLab_Text_Aide1, MSGBOX_NPC
	end

PalletTown_ProfessorOaksLab_EventScript_Aide3::
	msgbox PalletTown_ProfessorOaksLab_Text_Aide3, MSGBOX_NPC
	end

PalletTown_ProfessorOaksLab_EventScript_Aide2::
	msgbox PalletTown_ProfessorOaksLab_Text_Aide2, MSGBOX_NPC
	end

@ ============================================================================
@ Trinity M5b S5 -- OAK himself. T10's port dropped him entirely (no object at
@ all, not merely hidden) along with FRLG's whole VAR_MAP_SCENE_PALLET_TOWN_
@ PROFESSOR_OAKS_LAB state machine (starter selection values 1-6, National Dex
@ ceremony values 7-9) -- both skipped per the brief, an Act III player already
@ has a starter and a Pokedex. This is a plain, permanent, ungated flavour NPC:
@ a dex-praise beat for a three-region trainer, nothing else. (6,3) is his own
@ FRLG idle-desk coordinate (pokefirered's own map.json), re-decoded fresh
@ against this tree: col=0 elev=3 MB_NORMAL, free. No OBJ_EVENT_GFX_PROF_OAK
@ exists in this tree (grep, 0 hits) -- OBJ_EVENT_GFX_PROF_BIRCH substitutes,
@ the same cross-professor substitution already shipped once in this tree
@ (ElmsLab uses BIRCH for ELM). No local_id needed: nothing scripts
@ removeobject/applymovement against him (S4's Brock precedent).
@ ============================================================================
PalletTown_ProfessorOaksLab_EventScript_Oak::
	msgbox PalletTown_ProfessorOaksLab_Text_Oak, MSGBOX_NPC
	end

PalletTown_ProfessorOaksLab_EventScript_Computer::
	msgbox PalletTown_ProfessorOaksLab_Text_Computer, MSGBOX_SIGN
	end

PalletTown_ProfessorOaksLab_EventScript_Computer_2::
	msgbox PalletTown_ProfessorOaksLab_Text_Computer_2, MSGBOX_SIGN
	end

PalletTown_ProfessorOaksLab_EventScript_LeftSign::
	msgbox PalletTown_ProfessorOaksLab_Text_LeftSign, MSGBOX_SIGN
	end

PalletTown_ProfessorOaksLab_EventScript_RightSign::
	msgbox PalletTown_ProfessorOaksLab_Text_RightSign, MSGBOX_SIGN
	end

PalletTown_ProfessorOaksLab_Text_Aide1:
	.string "My grandkids keep going on about\nsome trainer from HOENN. Sounds\llike quite the journey so far.$"

PalletTown_ProfessorOaksLab_Text_Aide3:
	.string "KANTO's peaceful most days, but\neven here we've heard the stories\labout that HOENN trainer.$"

PalletTown_ProfessorOaksLab_Text_Aide2:
	.string "Never met the champion myself.\nHeard they came up through HOENN\land JOHTO before setting foot here.$"

PalletTown_ProfessorOaksLab_Text_Computer:
	.string "There's an e-mail message here.\p…\pFinally!\nThe ultimate TRAINERS of the\lPOKéMON LEAGUE are ready to\ltake on all comers!\pBring your best POKéMON and see\nhow you rate as a TRAINER!\pPOKéMON LEAGUE HQ\nINDIGO PLATEAU\pPROF. OAK, please visit us!\n…$"

PalletTown_ProfessorOaksLab_Text_Computer_2:
	.string "There's an e-mail message here.\p…\pFinally!\nThe ultimate TRAINERS of the\lPOKéMON LEAGUE are ready to\ltake on all comers!\pBring your best POKéMON and see\nhow you rate as a TRAINER!\pPOKéMON LEAGUE HQ\nINDIGO PLATEAU\pPROF. OAK, please visit us!\n…$"

PalletTown_ProfessorOaksLab_Text_LeftSign:
	.string "Press START to open the MENU!$"

@ Trinity M5b S5: was a verbatim, out-of-context copy of Aide1's own
@ "grandkids" gossip line on what reads as a lab bookshelf/terminal sign --
@ same defect class as S4's Pewter museum fix (exact-duplicate boilerplate
@ stuck somewhere it doesn't fit). Replaced with real in-context lab flavour.
PalletTown_ProfessorOaksLab_Text_RightSign:
	.string "A bookshelf packed with research\nnotes on POKéMON from three\lregions.$"

@ FIX ROUND 1 (review M2, folded minor): "a full HOENN register, a full JOHTO
@ register" was an underived factual claim about the player's own POKéDEX --
@ nothing in this tree gates or checks dex completion. Reworded to praise the
@ journey itself, not an unverified completion state.
PalletTown_ProfessorOaksLab_Text_Oak:
	.string "Ah, {PLAYER}! I've had my eye on\nyour POKéDEX data since the HOENN\lsurvey started forwarding it here.\pHOENN's entries, JOHTO's entries,\nand now you're walking KANTO's\lroutes with the same POKé BALLS\lon your belt.\pI won't pretend I'm not curious\nhow far you'll take it. Three\lregions, one TRAINER. Remarkable\lwork.$"
