@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

Route9_MapScripts::
	.byte 0

Route9_EventScript_Alicia::
	trainerbattle_single TRAINER_KANTO_PICNICKER_ALICIA, Route9_Text_AliciaSeen, Route9_Text_AliciaBeaten
	msgbox Route9_Text_AliciaPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Jeremy::
	trainerbattle_single TRAINER_KANTO_HIKER_JEREMY, Route9_Text_JeremySeen, Route9_Text_JeremyBeaten
	msgbox Route9_Text_JeremyPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Alan::
	trainerbattle_single TRAINER_KANTO_HIKER_ALAN, Route9_Text_AlanSeen, Route9_Text_AlanBeaten
	msgbox Route9_Text_AlanPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Chris::
	trainerbattle_single TRAINER_KANTO_CAMPER_CHRIS, Route9_Text_ChrisSeen, Route9_Text_ChrisBeaten
	msgbox Route9_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Brent::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_BRENT, Route9_Text_BrentSeen, Route9_Text_BrentBeaten
	msgbox Route9_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Conner::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_CONNER, Route9_Text_ConnerSeen, Route9_Text_ConnerBeaten
	msgbox Route9_Text_ConnerPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Brice::
	trainerbattle_single TRAINER_KANTO_HIKER_BRICE, Route9_Text_BriceSeen, Route9_Text_BriceBeaten
	msgbox Route9_Text_BricePostBattle, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Caitlin::
	trainerbattle_single TRAINER_KANTO_PICNICKER_CAITLIN, Route9_Text_CaitlinSeen, Route9_Text_CaitlinBeaten
	msgbox Route9_Text_CaitlinPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Drew::
	trainerbattle_single TRAINER_KANTO_CAMPER_DREW, Route9_Text_DrewSeen, Route9_Text_DrewBeaten
	msgbox Route9_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_RouteSign::
	msgbox Route9_Text_RouteSign, MSGBOX_SIGN
	end

Route9_Text_AliciaSeen:
	.string "You have POKéMON with you!\nYou're mine!$"

Route9_Text_AliciaBeaten:
	.string "You deceived me…$"

Route9_Text_AliciaPostBattle:
	.string "The tunnel coming up is pitch-black\ninside.\pYou'll need FLASH to get through\nthere.$"

Route9_Text_JeremySeen:
	.string "Bwahaha!\nGreat! I was bored, eh!$"

Route9_Text_JeremyBeaten:
	.string "Keep it coming, eh!\pOh wait.\nI'm out of POKéMON!$"

Route9_Text_JeremyPostBattle:
	.string "You sure had guts standing up to\nme there, eh?$"

Route9_Text_AlanSeen:
	.string "Hahahaha!\nBring it on!$"

Route9_Text_AlanBeaten:
	.string "Hahahaha!\nYou beat me fair!$"

Route9_Text_AlanPostBattle:
	.string "Hahahaha!\nUs hearty guys always laugh!$"

Route9_Text_ChrisSeen:
	.string "Who's that walking there with those\ngood-looking POKéMON?$"

Route9_Text_ChrisBeaten:
	.string "Out like a light!$"

Route9_Text_ChrisPostBattle:
	.string "Keep walking!$"

Route9_Text_BrentSeen:
	.string "I got up early every day to raise\nmy POKéMON from cocoons!$"

Route9_Text_BrentBeaten:
	.string "WHAT?\pWhat a total waste of time!$"

Route9_Text_BrentPostBattle:
	.string "I have to collect more than bugs\nto get stronger…$"

Route9_Text_ConnerSeen:
	.string "Go, my super BUG POKéMON!$"

Route9_Text_ConnerBeaten:
	.string "My bugs…$"

Route9_Text_ConnerPostBattle:
	.string "If you don't like BUG POKéMON,\nyou bug me!$"

Route9_Text_BriceSeen:
	.string "Hahaha!\nAren't you a little toughie!$"

Route9_Text_BriceBeaten:
	.string "What's that?$"

Route9_Text_BricePostBattle:
	.string "Hahaha!\nKids should be tough!$"

Route9_Text_CaitlinSeen:
	.string "Don't you dare patronize me!$"

Route9_Text_CaitlinBeaten:
	.string "No!\nYou're too much.$"

Route9_Text_CaitlinPostBattle:
	.string "You're obviously talented.\nGood luck to you!$"

Route9_Text_DrewSeen:
	.string "I'm taking the ROCK TUNNEL to\ngo to LAVENDER…$"

Route9_Text_DrewBeaten:
	.string "Can't measure up…$"

Route9_Text_DrewPostBattle:
	.string "Are you off to ROCK TUNNEL, too?$"

Route9_Text_RouteSign:
	.string "ROUTE 9\nCERULEAN CITY - ROCK TUNNEL$"
