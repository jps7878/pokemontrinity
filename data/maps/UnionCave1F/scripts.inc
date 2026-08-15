UnionCave1F_MapScripts::
	.byte 0

UnionCave1F_EventScript_DANIEL::
	trainerbattle_single TRAINER_JOHTO_HIKER_DANIEL, UnionCave1F_Text_DANIELSeen, UnionCave1F_Text_DANIELBeaten
	msgbox UnionCave1F_Text_DANIELBeaten, MSGBOX_AUTOCLOSE
	end

UnionCave1F_EventScript_LARRY::
	trainerbattle_single TRAINER_JOHTO_POKEMANIAC_LARRY, UnionCave1F_Text_LARRYSeen, UnionCave1F_Text_LARRYBeaten
	msgbox UnionCave1F_Text_LARRYBeaten, MSGBOX_AUTOCLOSE
	end

UnionCave1F_EventScript_RUSSELL::
	trainerbattle_single TRAINER_JOHTO_HIKER_RUSSELL, UnionCave1F_Text_RUSSELLSeen, UnionCave1F_Text_RUSSELLBeaten
	msgbox UnionCave1F_Text_RUSSELLBeaten, MSGBOX_AUTOCLOSE
	end

UnionCave1F_EventScript_RAY::
	trainerbattle_single TRAINER_JOHTO_FIREBREATHER_RAY, UnionCave1F_Text_RAYSeen, UnionCave1F_Text_RAYBeaten
	msgbox UnionCave1F_Text_RAYBeaten, MSGBOX_AUTOCLOSE
	end

UnionCave1F_EventScript_BILL::
	trainerbattle_single TRAINER_JOHTO_FIREBREATHER_BILL, UnionCave1F_Text_BILLSeen, UnionCave1F_Text_BILLBeaten
	msgbox UnionCave1F_Text_BILLBeaten, MSGBOX_AUTOCLOSE
	end

UnionCave1F_Text_DANIELSeen:
	.string "Whoa! What a\nsurprise!\pI didn't expect to\nsee anyone here!$"

UnionCave1F_Text_DANIELBeaten:
	.string "Whoa! I'm beaten\nbig time!$"

UnionCave1F_Text_LARRYSeen:
	.string "I roam far and\nwide in search of\lPOKéMON.\pAre you looking\nfor POKéMON too?\pThen you're my\ncollecting rival!$"

UnionCave1F_Text_LARRYBeaten:
	.string "Ugh. My poor POKé-\nMON…$"

UnionCave1F_Text_RUSSELLSeen:
	.string "You're headed to\nAZALEA, are you?\pLet my POKéMON see\nif you are good\lenough to battle.$"

UnionCave1F_Text_RUSSELLBeaten:
	.string "Oh, oh, oh!$"

UnionCave1F_Text_RAYSeen:
	.string "If it's light, a\ncave isn't scary.\pIf you're strong,\nPOKéMON aren't\lscary.$"

UnionCave1F_Text_RAYBeaten:
	.string "FLASH!$"

UnionCave1F_Text_BILLSeen:
	.string "ZUBAT's SUPERSONIC\nkeeps confusing\lmy POKéMON.\pI'm seriously\nupset about that!$"

UnionCave1F_Text_BILLBeaten:
	.string "I flamed out!$"
