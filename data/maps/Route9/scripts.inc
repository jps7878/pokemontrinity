Route9_MapScripts::
	.byte 0

Route9_EventScript_Alicia::
	trainerbattle_single TRAINER_KANTO_PICNICKER_ALICIA, Route9_Text_AliciaSeen, Route9_Text_AliciaBeaten
	msgbox Route9_Text_AliciaBeaten, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Jeremy::
	trainerbattle_single TRAINER_KANTO_HIKER_JEREMY, Route9_Text_JeremySeen, Route9_Text_JeremyBeaten
	msgbox Route9_Text_JeremyBeaten, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Alan::
	trainerbattle_single TRAINER_KANTO_HIKER_ALAN, Route9_Text_AlanSeen, Route9_Text_AlanBeaten
	msgbox Route9_Text_AlanBeaten, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Chris::
	trainerbattle_single TRAINER_KANTO_CAMPER_CHRIS, Route9_Text_ChrisSeen, Route9_Text_ChrisBeaten
	msgbox Route9_Text_ChrisBeaten, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Brent::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_BRENT, Route9_Text_BrentSeen, Route9_Text_BrentBeaten
	msgbox Route9_Text_BrentBeaten, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Conner::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_CONNER, Route9_Text_ConnerSeen, Route9_Text_ConnerBeaten
	msgbox Route9_Text_ConnerBeaten, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Brice::
	trainerbattle_single TRAINER_KANTO_HIKER_BRICE, Route9_Text_BriceSeen, Route9_Text_BriceBeaten
	msgbox Route9_Text_BriceBeaten, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Caitlin::
	trainerbattle_single TRAINER_KANTO_PICNICKER_CAITLIN, Route9_Text_CaitlinSeen, Route9_Text_CaitlinBeaten
	msgbox Route9_Text_CaitlinBeaten, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Drew::
	trainerbattle_single TRAINER_KANTO_CAMPER_DREW, Route9_Text_DrewSeen, Route9_Text_DrewBeaten
	msgbox Route9_Text_DrewBeaten, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_RouteSign::
	msgbox Route9_Text_RouteSign, MSGBOX_SIGN
	end

Route9_Text_AliciaSeen:
	.string "…$"

Route9_Text_AliciaBeaten:
	.string "…$"

Route9_Text_JeremySeen:
	.string "…$"

Route9_Text_JeremyBeaten:
	.string "…$"

Route9_Text_AlanSeen:
	.string "…$"

Route9_Text_AlanBeaten:
	.string "…$"

Route9_Text_ChrisSeen:
	.string "…$"

Route9_Text_ChrisBeaten:
	.string "…$"

Route9_Text_BrentSeen:
	.string "…$"

Route9_Text_BrentBeaten:
	.string "…$"

Route9_Text_ConnerSeen:
	.string "…$"

Route9_Text_ConnerBeaten:
	.string "…$"

Route9_Text_BriceSeen:
	.string "…$"

Route9_Text_BriceBeaten:
	.string "…$"

Route9_Text_CaitlinSeen:
	.string "…$"

Route9_Text_CaitlinBeaten:
	.string "…$"

Route9_Text_DrewSeen:
	.string "…$"

Route9_Text_DrewBeaten:
	.string "…$"

Route9_Text_RouteSign:
	.string "ROUTE 9\nCERULEAN CITY - ROCK TUNNEL$"
