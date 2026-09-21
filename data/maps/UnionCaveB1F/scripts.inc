UnionCaveB1F_MapScripts::
	.byte 0

UnionCaveB1F_EventScript_PHILLIP::
	trainerbattle_single TRAINER_JOHTO_HIKER_PHILLIP, UnionCaveB1F_Text_PHILLIPSeen, UnionCaveB1F_Text_PHILLIPBeaten
	msgbox UnionCaveB1F_Text_PHILLIPBeaten, MSGBOX_AUTOCLOSE
	end

UnionCaveB1F_EventScript_LEONARD::
	trainerbattle_single TRAINER_JOHTO_HIKER_LEONARD, UnionCaveB1F_Text_LEONARDSeen, UnionCaveB1F_Text_LEONARDBeaten
	msgbox UnionCaveB1F_Text_LEONARDBeaten, MSGBOX_AUTOCLOSE
	end

UnionCaveB1F_EventScript_ANDREW::
	trainerbattle_single TRAINER_JOHTO_POKEMANIAC_ANDREW, UnionCaveB1F_Text_ANDREWSeen, UnionCaveB1F_Text_ANDREWBeaten
	msgbox UnionCaveB1F_Text_ANDREWBeaten, MSGBOX_AUTOCLOSE
	end

UnionCaveB1F_EventScript_CALVIN::
	trainerbattle_single TRAINER_JOHTO_POKEMANIAC_CALVIN, UnionCaveB1F_Text_CALVINSeen, UnionCaveB1F_Text_CALVINBeaten
	msgbox UnionCaveB1F_Text_CALVINBeaten, MSGBOX_AUTOCLOSE
	end

UnionCaveB1F_Text_PHILLIPSeen:
	.string "It's been a while\nsince I last saw\lanother person.\pDon't be shy.\nLet's battle!$"

UnionCaveB1F_Text_PHILLIPBeaten:
	.string "Uurggh…$"

UnionCaveB1F_Text_LEONARDSeen:
	.string "What do you know!\nA visitor!$"

UnionCaveB1F_Text_LEONARDBeaten:
	.string "Wahahah! You're a\nfeisty one!$"

UnionCaveB1F_Text_ANDREWSeen:
	.string "Who's there?\pLeave me and my\nPOKéMON alone!$"

UnionCaveB1F_Text_ANDREWBeaten:
	.string "Go…\nGo away!$"

UnionCaveB1F_Text_CALVINSeen:
	.string "I came all the way\nhere to conduct my\lPOKéMON research.\pLet me demonstrate\nmy findings in a\lreal battle!$"

UnionCaveB1F_Text_CALVINBeaten:
	.string "You demonstrated\non me!$"

@ ============================================================================
@ Trinity M4b S10 -- GSC's Strength boulder at (7,10) (UnionCaveB1F.asm:173), placed as
@ OBJ_EVENT_GFX_PUSHABLE_BOULDER with vanilla's own EventScript_StrengthBoulder.
@ Decoded collision 0 / elevation 3 / MB_CAVE / reachable, costing exactly one
@ tile (its own); the complex re-reports NO SEALED WARPS with it placed.
@
@ IT CARRIES A FLAG_TEMP, LIKE VANILLA'S OWN 59 BOULDERS, and that is the right
@ choice rather than laziness: object template positions never persist
@ (LoadObjEventTemplatesFromHeader CpuCopy32s the ROM templates back on every
@ map load, src/overworld.c:521-530), so a permanent flag on a boulder that can
@ only be SHOVED would be dead weight -- and if a removeobject ever ran on one it
@ would co-sign that flag and delete the boulder for good. Only the ICE PATH
@ four, which fall down holes, take permanent flags.
@
@ STRENGTH IS AVAILABLE: IsFieldMoveUnlocked_Strength is FlagGet(FLAG_BADGE04_GET)
@ (src/field_move.c:26-29) -- the HOENN Heat Badge, which the Act II player holds
@ as Champion. No config exists to change that and none is needed.
@ ============================================================================
