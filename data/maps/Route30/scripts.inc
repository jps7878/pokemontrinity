Route30_MapScripts::
	.byte 0

Route30_EventScript_MIKEY::
	trainerbattle_single TRAINER_JOHTO_YOUNGSTER_MIKEY, Route30_Text_MIKEYSeen, Route30_Text_MIKEYBeaten
	msgbox Route30_Text_MIKEYBeaten, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_DON::
	trainerbattle_single TRAINER_JOHTO_BUG_CATCHER_DON, Route30_Text_DONSeen, Route30_Text_DONBeaten
	msgbox Route30_Text_DONBeaten, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Youngster::
	msgbox Route30_Text_Youngster, MSGBOX_NPC
	end

Route30_EventScript_CooltrainerF::
	msgbox Route30_Text_CooltrainerF, MSGBOX_NPC
	end

Route30_EventScript_Sign::
	msgbox Route30_Text_Sign, MSGBOX_SIGN
	end

Route30_EventScript_MrPokemonsHouseDirectionsSign::
	msgbox Route30_Text_MrPokemonsHouseDirectionsSign, MSGBOX_SIGN
	end

Route30_EventScript_MrPokemonsHouseSign::
	msgbox Route30_Text_MrPokemonsHouseSign, MSGBOX_SIGN
	end

Route30_EventScript_TrainerTips::
	msgbox Route30_Text_TrainerTips, MSGBOX_SIGN
	end

Route30_Text_MIKEYSeen:
	.string "You're a POKéMON\ntrainer, right?\pThen you have to\nbattle!$"

Route30_Text_MIKEYBeaten:
	.string "That's strange.\nI won before.$"

Route30_Text_DONSeen:
	.string "Instead of a bug\nPOKéMON, I found\la trainer!$"

Route30_Text_DONBeaten:
	.string "Argh! You're too\nstrong!$"

Route30_Text_Youngster:
	.string "I've lived in JOHTO my whole life.\nNever thought I'd meet someone\lfrom HOENN way out here.$"

Route30_Text_CooltrainerF:
	.string "I'm not a trainer.\pBut if you look\none in the eyes,\lprepare to battle.$"

Route30_Text_Sign:
	.string "ROUTE 30\pVIOLET CITY -\nCHERRYGROVE CITY$"

Route30_Text_MrPokemonsHouseDirectionsSign:
	.string "MR.POKéMON'S HOUSE\nSTRAIGHT AHEAD!$"

Route30_Text_MrPokemonsHouseSign:
	.string "MR.POKéMON'S HOUSE$"

Route30_Text_TrainerTips:
	.string "TRAINER TIPS\pNo stealing other\npeople's POKéMON!\pPOKé BALLS are to\nbe thrown only at\lwild POKéMON!$"
