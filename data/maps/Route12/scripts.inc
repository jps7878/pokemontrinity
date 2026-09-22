@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

Route12_MapScripts::
	.byte 0

Route12_EventScript_Ned::
	trainerbattle_single TRAINER_KANTO_FISHERMAN_NED, Route12_Text_NedSeen, Route12_Text_NedBeaten
	msgbox Route12_Text_NedPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Chip::
	trainerbattle_single TRAINER_KANTO_FISHERMAN_CHIP, Route12_Text_ChipSeen, Route12_Text_ChipBeaten
	msgbox Route12_Text_ChipPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Hank::
	trainerbattle_single TRAINER_KANTO_FISHERMAN_HANK, Route12_Text_HankSeen, Route12_Text_HankBeaten
	msgbox Route12_Text_HankPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Elliot::
	trainerbattle_single TRAINER_KANTO_FISHERMAN_ELLIOT, Route12_Text_ElliotSeen, Route12_Text_ElliotBeaten
	msgbox Route12_Text_ElliotPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Luca::
	trainerbattle_single TRAINER_KANTO_ROCKER_LUCA, Route12_Text_LucaSeen, Route12_Text_LucaBeaten
	msgbox Route12_Text_LucaPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Justin::
	trainerbattle_single TRAINER_KANTO_CAMPER_JUSTIN, Route12_Text_JustinSeen, Route12_Text_JustinBeaten
	msgbox Route12_Text_JustinPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Andrew::
	trainerbattle_single TRAINER_KANTO_FISHERMAN_ANDREW, Route12_Text_AndrewSeen, Route12_Text_AndrewBeaten
	msgbox Route12_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Gia::
	trainerbattle_single TRAINER_KANTO_YOUNG_COUPLE_GIA_JES, Route12_Text_GiaSeen, Route12_Text_GiaBeaten
	msgbox Route12_Text_GiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_Jes::
	trainerbattle_single TRAINER_KANTO_YOUNG_COUPLE_GIA_JES_2, Route12_Text_JesSeen, Route12_Text_JesBeaten
	msgbox Route12_Text_JesPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_EventScript_RouteSign::
	msgbox Route12_Text_RouteSign, MSGBOX_SIGN
	end

Route12_EventScript_FishingSign::
	msgbox Route12_Text_FishingSign, MSGBOX_SIGN
	end

Route12_Text_NedSeen:
	.string "Yeah!\nI got a bite here!$"

Route12_Text_NedBeaten:
	.string "Tch!\nJust a small fry…$"

Route12_Text_NedPostBattle:
	.string "Hang on!\nMy line's snagged!$"

Route12_Text_ChipSeen:
	.string "Be patient.\nFishing is a waiting game.$"

Route12_Text_ChipBeaten:
	.string "That one got away!$"

Route12_Text_ChipPostBattle:
	.string "With a better ROD, I could catch\nbetter POKéMON…$"

Route12_Text_HankSeen:
	.string "The FISHING FOOL versus POKéMON\nKID!$"

Route12_Text_HankBeaten:
	.string "Touch too much!$"

Route12_Text_HankPostBattle:
	.string "I guess you get to be good at\nwhat you like.\pWell, you beat me at POKéMON,\nbut you can't top me at fishing.$"

Route12_Text_ElliotSeen:
	.string "I love fishing, don't get me wrong.\pBut it'd be best if I also had more\nwork.$"

Route12_Text_ElliotBeaten:
	.string "It's not easy…$"

Route12_Text_ElliotPostBattle:
	.string "It's all right.\nLosing doesn't bug me anymore.$"

Route12_Text_LucaSeen:
	.string "Electricity is my specialty.\pI don't know a thing about POKéMON\nof the sea, though.$"

Route12_Text_LucaBeaten:
	.string "Unplugged!$"

Route12_Text_LucaPostBattle:
	.string "Water conducts electricity, so you\nshould zap sea POKéMON.$"

Route12_Text_JustinSeen:
	.string "I'm searching for a MOON STONE.\nHave you found one?$"

Route12_Text_JustinBeaten:
	.string "Oww!$"

Route12_Text_JustinPostBattle:
	.string "I could have made my POKéMON\nevolve with a MOON STONE.\pI would have won then, I bet.$"

Route12_Text_AndrewSeen:
	.string "What's catching?\pYou never know what you could\ncatch!$"

Route12_Text_AndrewBeaten:
	.string "Lost it!$"

Route12_Text_AndrewPostBattle:
	.string "What, MAGIKARP?\pI catch them all the time, sure.\nBut, boy are they wimpy.$"

Route12_Text_GiaSeen:
	.string "GIA: Hey, JES…\pIf we win, I'll marry you!$"

Route12_Text_GiaBeaten:
	.string "GIA: Oh, but why?$"

Route12_Text_GiaPostBattle:
	.string "GIA: JES, you silly!\nYou ruined this!$"

Route12_Text_JesSeen:
	.string "JES: If I win, I'm going to\npropose to GIA.$"

Route12_Text_JesBeaten:
	.string "JES: Oh, please, why couldn't you\nlet us win?$"

Route12_Text_JesPostBattle:
	.string "JES: Oh, GIA, forgive me,\nmy love!$"

Route12_Text_RouteSign:
	.string "ROUTE 12 \nNorth to LAVENDER$"

Route12_Text_FishingSign:
	.string "SPORTFISHING AREA$"
