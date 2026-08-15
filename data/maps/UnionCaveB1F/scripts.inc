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
