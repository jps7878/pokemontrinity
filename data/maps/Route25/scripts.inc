Route25_MapScripts::
	.byte 0

Route25_EventScript_Franklin::
	trainerbattle_single TRAINER_KANTO_HIKER_FRANKLIN, Route25_Text_FranklinSeen, Route25_Text_FranklinBeaten
	msgbox Route25_Text_FranklinBeaten, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Joey::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_JOEY, Route25_Text_JoeySeen, Route25_Text_JoeyBeaten
	msgbox Route25_Text_JoeyBeaten, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Wayne::
	trainerbattle_single TRAINER_KANTO_HIKER_WAYNE, Route25_Text_WayneSeen, Route25_Text_WayneBeaten
	msgbox Route25_Text_WayneBeaten, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Dan::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_DAN, Route25_Text_DanSeen, Route25_Text_DanBeaten
	msgbox Route25_Text_DanBeaten, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Kelsey::
	trainerbattle_single TRAINER_KANTO_PICNICKER_KELSEY, Route25_Text_KelseySeen, Route25_Text_KelseyBeaten
	msgbox Route25_Text_KelseyBeaten, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Nob::
	trainerbattle_single TRAINER_KANTO_HIKER_NOB, Route25_Text_NobSeen, Route25_Text_NobBeaten
	msgbox Route25_Text_NobBeaten, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Flint::
	trainerbattle_single TRAINER_KANTO_CAMPER_FLINT, Route25_Text_FlintSeen, Route25_Text_FlintBeaten
	msgbox Route25_Text_FlintBeaten, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Chad::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_CHAD, Route25_Text_ChadSeen, Route25_Text_ChadBeaten
	msgbox Route25_Text_ChadBeaten, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Haley::
	trainerbattle_single TRAINER_KANTO_LASS_HALEY, Route25_Text_HaleySeen, Route25_Text_HaleyBeaten
	msgbox Route25_Text_HaleyBeaten, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Man::
	msgbox Route25_Text_Man, MSGBOX_NPC
	end

Route25_EventScript_SeaCottageSign::
	msgbox Route25_Text_SeaCottageSign, MSGBOX_SIGN
	end

Route25_Text_FranklinSeen:
	.string "This route runs right up to the\ncape. Good climbing, good\lbattling.$"

Route25_Text_FranklinBeaten:
	.string "Better climbing than my POKéMON\nbattled, apparently.$"

Route25_Text_JoeySeen:
	.string "I've got a RATTATA in the top\npercentage of RATTATA!$"

Route25_Text_JoeyBeaten:
	.string "Still top percentage. Just not\ntoday.$"

Route25_Text_WayneSeen:
	.string "The SEA COTTAGE is up ahead.\nSomeone smart lives there.$"

Route25_Text_WayneBeaten:
	.string "Should've asked him for battle\ntips first.$"

Route25_Text_DanSeen:
	.string "You look like you're headed to\nCERULEAN. Long way to come for\la badge.$"

Route25_Text_DanBeaten:
	.string "Guess it was worth the trip.$"

Route25_Text_KelseySeen:
	.string "Picnicking here beats picnicking\nanywhere else in KANTO.$"

Route25_Text_KelseyBeaten:
	.string "Even the sandwiches saw that\ncoming.$"

Route25_Text_NobSeen:
	.string "Climbed every hill on this route\ntwice. Never lost my footing.$"

Route25_Text_NobBeaten:
	.string "Lost something else, though.$"

Route25_Text_FlintSeen:
	.string "Set up camp right here. The view\nof the cape's worth the walk.$"

Route25_Text_FlintBeaten:
	.string "Worth the walk. Not worth the\nbattle, apparently.$"

Route25_Text_ChadSeen:
	.string "Two LEAGUES and you're still\nwalking this route on foot?$"

Route25_Text_ChadBeaten:
	.string "Fine. Foot traffic like that\nearns a loss.$"

Route25_Text_HaleySeen:
	.string "Last trainer before the cape.\nMake it count.$"

Route25_Text_HaleyBeaten:
	.string "It counted. Go see BILL.$"

Route25_Text_Man:
	.string "Hello, are you here alone?\pIf you're out at CERULEAN's cape…\nWell, it should be as a couple.$"

Route25_Text_SeaCottageSign:
	.string "SEA COTTAGE\nBILL lives here!$"
