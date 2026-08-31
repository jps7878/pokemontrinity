Route19_MapScripts::
	.byte 0

Route19_EventScript_Reece::
	trainerbattle_single TRAINER_KANTO_SWIMMER_M_REECE, Route19_Text_ReeceSeen, Route19_Text_ReeceBeaten
	msgbox Route19_Text_ReeceBeaten, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Richard::
	trainerbattle_single TRAINER_KANTO_SWIMMER_M_RICHARD, Route19_Text_RichardSeen, Route19_Text_RichardBeaten
	msgbox Route19_Text_RichardBeaten, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Tony::
	trainerbattle_single TRAINER_KANTO_SWIMMER_M_TONY, Route19_Text_TonySeen, Route19_Text_TonyBeaten
	msgbox Route19_Text_TonyBeaten, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Matthew::
	trainerbattle_single TRAINER_KANTO_SWIMMER_M_MATTHEW, Route19_Text_MatthewSeen, Route19_Text_MatthewBeaten
	msgbox Route19_Text_MatthewBeaten, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Douglas::
	trainerbattle_single TRAINER_KANTO_SWIMMER_M_DOUGLAS, Route19_Text_DouglasSeen, Route19_Text_DouglasBeaten
	msgbox Route19_Text_DouglasBeaten, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_David::
	trainerbattle_single TRAINER_KANTO_SWIMMER_M_DAVID, Route19_Text_DavidSeen, Route19_Text_DavidBeaten
	msgbox Route19_Text_DavidBeaten, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Axle::
	trainerbattle_single TRAINER_KANTO_SWIMMER_M_AXLE, Route19_Text_AxleSeen, Route19_Text_AxleBeaten
	msgbox Route19_Text_AxleBeaten, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Alice::
	trainerbattle_single TRAINER_KANTO_SWIMMER_F_ALICE, Route19_Text_AliceSeen, Route19_Text_AliceBeaten
	msgbox Route19_Text_AliceBeaten, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Connie::
	trainerbattle_single TRAINER_KANTO_SWIMMER_F_CONNIE, Route19_Text_ConnieSeen, Route19_Text_ConnieBeaten
	msgbox Route19_Text_ConnieBeaten, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Anya::
	trainerbattle_single TRAINER_KANTO_SWIMMER_F_ANYA, Route19_Text_AnyaSeen, Route19_Text_AnyaBeaten
	msgbox Route19_Text_AnyaBeaten, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Lia::
	trainerbattle_single TRAINER_KANTO_SIS_AND_BRO_LIA_LUC, Route19_Text_LiaSeen, Route19_Text_LiaBeaten
	msgbox Route19_Text_LiaBeaten, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Luc::
	trainerbattle_single TRAINER_KANTO_SIS_AND_BRO_LIA_LUC_2, Route19_Text_LucSeen, Route19_Text_LucBeaten
	msgbox Route19_Text_LucBeaten, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_RouteSign::
	msgbox Route19_Text_RouteSign, MSGBOX_SIGN
	end

Route19_Text_ReeceSeen:
	.string "The current between here and\nSEAFOAM gets rough. You ready\lfor it?$"

Route19_Text_ReeceBeaten:
	.string "Guess I wasn't ready for you.$"

Route19_Text_RichardSeen:
	.string "I swim this stretch every\nmorning. Keeps me sharp.$"

Route19_Text_RichardBeaten:
	.string "Not sharp enough, apparently.$"

Route19_Text_TonySeen:
	.string "You're a long way from shore\nfor a land trainer!$"

Route19_Text_TonyBeaten:
	.string "Glub. Didn't see that coming.$"

Route19_Text_MatthewSeen:
	.string "FUCHSIA behind us, SEAFOAM\nahead. Best part of the trip.$"

Route19_Text_MatthewBeaten:
	.string "Guess the trip has a low point\ntoo.$"

Route19_Text_DouglasSeen:
	.string "Water's my whole life. Always\nhas been.$"

Route19_Text_DouglasBeaten:
	.string "Well, that stung more than the\nsaltwater.$"

Route19_Text_DavidSeen:
	.string "Careful out here. The tide's got\na mind of its own.$"

Route19_Text_DavidBeaten:
	.string "Ha! Didn't expect to lose my\nfooting like that.$"

Route19_Text_AxleSeen:
	.string "Race you to SEAFOAM! ...After\nthis, I mean.$"

Route19_Text_AxleBeaten:
	.string "You'd win that race too.$"

Route19_Text_AliceSeen:
	.string "I love how quiet it gets out\nhere on the open water.$"

Route19_Text_AliceBeaten:
	.string "Oh! Well, that broke the quiet.$"

Route19_Text_ConnieSeen:
	.string "Watch for the rocks near\nSEAFOAM. They sneak up on you.$"

Route19_Text_ConnieBeaten:
	.string "You didn't need the warning at\nall, huh.$"

Route19_Text_AnyaSeen:
	.string "I train out here so my POKéMON\nget used to the waves.$"

Route19_Text_AnyaBeaten:
	.string "They're used to losing now,\ntoo, I guess.$"

Route19_Text_LiaSeen:
	.string "My brother and I never lose a\nbattle out here together!$"

Route19_Text_LiaBeaten:
	.string "First time for everything,\nLUC…$"

Route19_Text_LucSeen:
	.string "My sister's right behind me.\nDon't think this'll be easy!$"

Route19_Text_LucBeaten:
	.string "Aw, man. LIA's never going to\nlet me forget this.$"

Route19_Text_RouteSign:
	.string "SEA ROUTE 19\nFUCHSIA CITY - SEAFOAM ISLANDS$"
