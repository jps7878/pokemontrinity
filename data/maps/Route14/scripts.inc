@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

Route14_MapScripts::
	.byte 0

Route14_EventScript_Gerald::
	trainerbattle_single TRAINER_KANTO_BIKER_GERALD, Route14_Text_GeraldSeen, Route14_Text_GeraldBeaten
	msgbox Route14_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Donald::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_DONALD, Route14_Text_DonaldSeen, Route14_Text_DonaldBeaten
	msgbox Route14_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Beck::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_BECK, Route14_Text_BeckSeen, Route14_Text_BeckBeaten
	msgbox Route14_Text_BeckPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Marlon::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_MARLON, Route14_Text_MarlonSeen, Route14_Text_MarlonBeaten
	msgbox Route14_Text_MarlonPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Isaac::
	trainerbattle_single TRAINER_KANTO_BIKER_ISAAC, Route14_Text_IsaacSeen, Route14_Text_IsaacBeaten
	msgbox Route14_Text_IsaacPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Malik::
	trainerbattle_single TRAINER_KANTO_BIKER_MALIK, Route14_Text_MalikSeen, Route14_Text_MalikBeaten
	msgbox Route14_Text_MalikPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Mitch::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_MITCH, Route14_Text_MitchSeen, Route14_Text_MitchBeaten
	msgbox Route14_Text_MitchPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Carter::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_CARTER, Route14_Text_CarterSeen, Route14_Text_CarterBeaten
	msgbox Route14_Text_CarterPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Lukas::
	trainerbattle_single TRAINER_KANTO_BIKER_LUKAS, Route14_Text_LukasSeen, Route14_Text_LukasBeaten
	msgbox Route14_Text_LukasPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Benny::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_BENNY, Route14_Text_BennySeen, Route14_Text_BennyBeaten
	msgbox Route14_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Jan::
	trainerbattle_single TRAINER_KANTO_TWINS_KIRI_JAN, Route14_Text_JanSeen, Route14_Text_JanBeaten
	msgbox Route14_Text_JanPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Kiri::
	trainerbattle_single TRAINER_KANTO_TWINS_KIRI_JAN_2, Route14_Text_KiriSeen, Route14_Text_KiriBeaten
	msgbox Route14_Text_KiriPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_RouteSign::
	msgbox Route14_Text_RouteSign, MSGBOX_SIGN
	end

Route14_Text_GeraldSeen:
	.string "We ride out here because of the\nwide-open spaces.$"

Route14_Text_GeraldBeaten:
	.string "Wipeout!$"

Route14_Text_GeraldPostBattle:
	.string "It's cool you made your POKéMON so\nstrong.\pMight is right!\nAnd you know it!$"

Route14_Text_DonaldSeen:
	.string "Have you heard the legend of the\nwinged mirages?$"

Route14_Text_DonaldBeaten:
	.string "Why?\nWhy'd I lose?$"

Route14_Text_DonaldPostBattle:
	.string "Well, the winged mirages are the\nlegendary bird POKéMON.\pThere are three of them: ARTICUNO,\nZAPDOS, and MOLTRES.$"

Route14_Text_BeckSeen:
	.string "They have TMs on sale at the\nCELADON DEPT. STORE.\pTMs aren't really rare, but not\nmany people have HMs.$"

Route14_Text_BeckBeaten:
	.string "Aww, bummer!$"

Route14_Text_BeckPostBattle:
	.string "Try teaching POKéMON a move that's\nthe same type as it.\pThat apparently boosts the power\nof the move.$"

Route14_Text_MarlonSeen:
	.string "Have you taught your bird POKéMON\nhow to FLY?\pYou'll be able to soar with it into\nthe sky!$"

Route14_Text_MarlonBeaten:
	.string "Shot down in flames!$"

Route14_Text_MarlonPostBattle:
	.string "Bird POKéMON are my one true love.\nI don't want to raise anything else.$"

Route14_Text_IsaacSeen:
	.string "I need to burn some time.\nShut up and battle.$"

Route14_Text_IsaacBeaten:
	.string "What?\nYou!?$"

Route14_Text_IsaacPostBattle:
	.string "Raising POKéMON is a drag, man.$"

Route14_Text_MalikSeen:
	.string "POKéMON battle?\nCool! Rumble!$"

Route14_Text_MalikBeaten:
	.string "Blown away!$"

Route14_Text_MalikPostBattle:
	.string "You know who'd win, you and me\none-on-one!$"

Route14_Text_MitchSeen:
	.string "My bird POKéMON should be ready\nfor battle.$"

Route14_Text_MitchBeaten:
	.string "Not ready yet!$"

Route14_Text_MitchPostBattle:
	.string "My bird POKéMON need to learn\nbetter moves.$"

Route14_Text_CarterSeen:
	.string "You need to use TMs to teach good\nmoves to POKéMON.$"

Route14_Text_CarterBeaten:
	.string "Not good enough quite yet.$"

Route14_Text_CarterPostBattle:
	.string "You have some HMs, right? POKéMON\ncan't forget those moves easily.$"

Route14_Text_LukasSeen:
	.string "C'mon, c'mon.\nLet's go, let's go, let's go!$"

Route14_Text_LukasBeaten:
	.string "Arrg!\nLost! Get lost!$"

Route14_Text_LukasPostBattle:
	.string "What, what, what?\nWhat do you want still?$"

Route14_Text_BennySeen:
	.string "I'm not into it, but okay.\nLet's go!$"

Route14_Text_BennyBeaten:
	.string "I knew it!$"

Route14_Text_BennyPostBattle:
	.string "Winning, losing… It's insignificant\nunder this huge sky.$"

Route14_Text_JanSeen:
	.string "JAN: KIRI, here we go!\nWe have to try hard!$"

Route14_Text_JanBeaten:
	.string "JAN: Eeeeh!\nNo fair!$"

Route14_Text_JanPostBattle:
	.string "JAN: KIRI, don't cry!\nWe'll just try harder next time.$"

Route14_Text_KiriSeen:
	.string "KIRI: JAN, let's try really,\nreally hard together.$"

Route14_Text_KiriBeaten:
	.string "KIRI: Whimper…\nWe lost, didn't we?$"

Route14_Text_KiriPostBattle:
	.string "KIRI: Did we lose because of me?$"

Route14_Text_RouteSign:
	.string "ROUTE 14\nWest to FUCHSIA CITY$"
