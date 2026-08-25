Route3_MapScripts::
	.byte 0

Route3_EventScript_Youngster::
	msgbox Route3_Text_Youngster, MSGBOX_NPC
	end

Route3_EventScript_Robin::
	trainerbattle_single TRAINER_KANTO_LASS_ROBIN, Route3_Text_RobinSeen, Route3_Text_RobinBeaten
	msgbox Route3_Text_RobinBeaten, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_James::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_JAMES, Route3_Text_JamesSeen, Route3_Text_JamesBeaten
	msgbox Route3_Text_JamesBeaten, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Sally::
	trainerbattle_single TRAINER_KANTO_LASS_SALLY, Route3_Text_SallySeen, Route3_Text_SallyBeaten
	msgbox Route3_Text_SallyBeaten, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Greg::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_GREG, Route3_Text_GregSeen, Route3_Text_GregBeaten
	msgbox Route3_Text_GregBeaten, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Calvin::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_CALVIN, Route3_Text_CalvinSeen, Route3_Text_CalvinBeaten
	msgbox Route3_Text_CalvinBeaten, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Janice::
	trainerbattle_single TRAINER_KANTO_LASS_JANICE, Route3_Text_JaniceSeen, Route3_Text_JaniceBeaten
	msgbox Route3_Text_JaniceBeaten, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Colton::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_COLTON, Route3_Text_ColtonSeen, Route3_Text_ColtonBeaten
	msgbox Route3_Text_ColtonBeaten, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Ben::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_BEN, Route3_Text_BenSeen, Route3_Text_BenBeaten
	msgbox Route3_Text_BenBeaten, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_RouteSign::
	msgbox Route3_Text_RouteSign, MSGBOX_SIGN
	end

Route3_Text_Youngster:
	.string "Whew… I better take a rest…\nGroan…\pThat tunnel from CERULEAN takes a\nlot out of you!$"

Route3_Text_RobinSeen:
	.string "…$"

Route3_Text_RobinBeaten:
	.string "…$"

Route3_Text_JamesSeen:
	.string "…$"

Route3_Text_JamesBeaten:
	.string "…$"

Route3_Text_SallySeen:
	.string "…$"

Route3_Text_SallyBeaten:
	.string "…$"

Route3_Text_GregSeen:
	.string "…$"

Route3_Text_GregBeaten:
	.string "…$"

Route3_Text_CalvinSeen:
	.string "…$"

Route3_Text_CalvinBeaten:
	.string "…$"

Route3_Text_JaniceSeen:
	.string "…$"

Route3_Text_JaniceBeaten:
	.string "…$"

Route3_Text_ColtonSeen:
	.string "…$"

Route3_Text_ColtonBeaten:
	.string "…$"

Route3_Text_BenSeen:
	.string "…$"

Route3_Text_BenBeaten:
	.string "…$"

Route3_Text_RouteSign:
	.string "ROUTE 3\nMT. MOON AHEAD$"
