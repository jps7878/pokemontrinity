@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

RockTunnel_1F_MapScripts::
	.byte 0

RockTunnel_1F_EventScript_Dana::
	trainerbattle_single TRAINER_KANTO_PICNICKER_DANA, RockTunnel_1F_Text_DanaSeen, RockTunnel_1F_Text_DanaBeaten
	msgbox RockTunnel_1F_Text_DanaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ariana::
	trainerbattle_single TRAINER_KANTO_PICNICKER_ARIANA, RockTunnel_1F_Text_ArianaSeen, RockTunnel_1F_Text_ArianaBeaten
	msgbox RockTunnel_1F_Text_ArianaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Leah::
	trainerbattle_single TRAINER_KANTO_PICNICKER_LEAH, RockTunnel_1F_Text_LeahSeen, RockTunnel_1F_Text_LeahBeaten
	msgbox RockTunnel_1F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Lucas::
	trainerbattle_single TRAINER_KANTO_HIKER_LUCAS, RockTunnel_1F_Text_LucasSeen, RockTunnel_1F_Text_LucasBeaten
	msgbox RockTunnel_1F_Text_LucasPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Oliver::
	trainerbattle_single TRAINER_KANTO_HIKER_OLIVER, RockTunnel_1F_Text_OliverSeen, RockTunnel_1F_Text_OliverBeaten
	msgbox RockTunnel_1F_Text_OliverPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Lenny::
	trainerbattle_single TRAINER_KANTO_HIKER_LENNY, RockTunnel_1F_Text_LennySeen, RockTunnel_1F_Text_LennyBeaten
	msgbox RockTunnel_1F_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_Ashton::
	trainerbattle_single TRAINER_KANTO_POKEMANIAC_ASHTON, RockTunnel_1F_Text_AshtonSeen, RockTunnel_1F_Text_AshtonBeaten
	msgbox RockTunnel_1F_Text_AshtonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_1F_EventScript_RouteSign::
	msgbox RockTunnel_1F_Text_RouteSign, MSGBOX_SIGN
	end

RockTunnel_1F_Text_DanaSeen:
	.string "I came this far looking for wild\nPOKéMON.$"

RockTunnel_1F_Text_DanaBeaten:
	.string "I'm out of POKéMON!$"

RockTunnel_1F_Text_DanaPostBattle:
	.string "You looked cute and harmless.\nWas I ever wrong!$"

RockTunnel_1F_Text_ArianaSeen:
	.string "You have POKéMON!\nLet's start!$"

RockTunnel_1F_Text_ArianaBeaten:
	.string "You play hard!$"

RockTunnel_1F_Text_ArianaPostBattle:
	.string "Whew!\nI'm all sweaty now.$"

RockTunnel_1F_Text_LeahSeen:
	.string "Eek!\pDon't try anything funny in the\ndark!$"

RockTunnel_1F_Text_LeahBeaten:
	.string "It was too dark…$"

RockTunnel_1F_Text_LeahPostBattle:
	.string "I saw a MACHOP in this tunnel.$"

RockTunnel_1F_Text_LucasSeen:
	.string "Outsiders like you need to show me\nsome respect!$"

RockTunnel_1F_Text_LucasBeaten:
	.string "I give!$"

RockTunnel_1F_Text_LucasPostBattle:
	.string "You're talented enough to hike!$"

RockTunnel_1F_Text_OliverSeen:
	.string "Hmm.\nMaybe I'm lost in here…$"

RockTunnel_1F_Text_OliverBeaten:
	.string "Ease up!\nWhat am I doing?\lWhich way is out?$"

RockTunnel_1F_Text_OliverPostBattle:
	.string "That sleeping POKéMON on ROUTE 12\nforced me to take this detour.$"

RockTunnel_1F_Text_LennySeen:
	.string "This tunnel goes a long way, kid!$"

RockTunnel_1F_Text_LennyBeaten:
	.string "Doh!\nYou win!$"

RockTunnel_1F_Text_LennyPostBattle:
	.string "Watch for ONIX.\nThey appear only occasionally.\pHigh-level ones can put the\nsqueeze on you!$"

RockTunnel_1F_Text_AshtonSeen:
	.string "POKéMON fight!\nReady, go!$"

RockTunnel_1F_Text_AshtonBeaten:
	.string "Game over!$"

RockTunnel_1F_Text_AshtonPostBattle:
	.string "Oh well, I'll get a ZUBAT as I go!$"

RockTunnel_1F_Text_RouteSign:
	.string "ROCK TUNNEL\nCERULEAN CITY - LAVENDER TOWN$"
