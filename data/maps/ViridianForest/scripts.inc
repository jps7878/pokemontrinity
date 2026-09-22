@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

ViridianForest_MapScripts::
	.byte 0

ViridianForest_EventScript_Youngster::
	msgbox ViridianForest_Text_Youngster, MSGBOX_NPC
	end

ViridianForest_EventScript_Boy::
	msgbox ViridianForest_Text_Boy, MSGBOX_NPC
	end

ViridianForest_EventScript_Rick::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_RICK, ViridianForest_Text_RickSeen, ViridianForest_Text_RickBeaten
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Doug::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_DOUG, ViridianForest_Text_DougSeen, ViridianForest_Text_DougBeaten
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Sammy::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_SAMMY, ViridianForest_Text_SammySeen, ViridianForest_Text_SammyBeaten
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Anthony::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonySeen, ViridianForest_Text_AnthonyBeaten
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Charlie::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieSeen, ViridianForest_Text_CharlieBeaten
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_TrainerTips1::
	msgbox ViridianForest_Text_TrainerTips1, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips3::
	msgbox ViridianForest_Text_TrainerTips3, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips4::
	msgbox ViridianForest_Text_TrainerTips4, MSGBOX_SIGN
	end

ViridianForest_EventScript_ExitSign::
	msgbox ViridianForest_Text_ExitSign, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips2::
	msgbox ViridianForest_Text_TrainerTips2, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips5::
	msgbox ViridianForest_Text_TrainerTips5, MSGBOX_SIGN
	end

ViridianForest_Text_Youngster:
	.string "I came here with some friends to\ncatch us some BUG POKéMON!\pThey're all itching to get into\nsome POKéMON battles!$"

ViridianForest_Text_Boy:
	.string "I was throwing POKé BALLS to\ncatch POKéMON, and I ran out.\pThat's why you can never have too\nmany POKé BALLS.$"

ViridianForest_Text_RickSeen:
	.string "Hey! You have POKéMON!\nCome on!\lLet's battle 'em!$"

ViridianForest_Text_RickBeaten:
	.string "No!\nCATERPIE can't hack it!$"

ViridianForest_Text_RickPostBattle:
	.string "Ssh! You'll scare the bugs away.\nAnother time, okay?$"

ViridianForest_Text_DougSeen:
	.string "Yo!\nYou can't jam out if you're a\lPOKéMON TRAINER!$"

ViridianForest_Text_DougBeaten:
	.string "Huh?\nI ran out of POKéMON!$"

ViridianForest_Text_DougPostBattle:
	.string "That totally stinks! I'm going to\ncatch some stronger ones!$"

ViridianForest_Text_SammySeen:
	.string "Hey, wait up!\nWhat's the hurry? Why the rush?$"

ViridianForest_Text_SammyBeaten:
	.string "I give!\nYou're good at this!$"

ViridianForest_Text_SammyPostBattle:
	.string "Sometimes, you can find stuff on\nthe ground.\pI'm looking for the stuff I\ndropped. Can you help me?$"

ViridianForest_Text_AnthonySeen:
	.string "I might be little, but I won't like\nit if you go easy on me!$"

ViridianForest_Text_AnthonyBeaten:
	.string "Oh, boo.\nNothing went right.$"

ViridianForest_Text_AnthonyPostBattle:
	.string "I lost some of my allowance…$"

ViridianForest_Text_CharlieSeen:
	.string "Did you know that POKéMON evolve?$"

ViridianForest_Text_CharlieBeaten:
	.string "Oh!\nI lost!$"

ViridianForest_Text_CharliePostBattle:
	.string "BUG POKéMON evolve quickly.\nThey're a lot of fun!$"

ViridianForest_Text_TrainerTips1:
	.string "TRAINER TIPS\pIf your POKéMON are weak and you\nwant to avoid battles, stay away\lfrom grassy areas!$"

ViridianForest_Text_TrainerTips3:
	.string "TRAINER TIPS\pContact PROF. OAK via a PC to\nget your POKéDEX evaluated!$"

ViridianForest_Text_TrainerTips4:
	.string "TRAINER TIPS\pYou can't catch a POKéMON that\nbelongs to someone else.\pThrow POKé BALLS only at wild\nPOKéMON to catch them!$"

ViridianForest_Text_ExitSign:
	.string "LEAVING VIRIDIAN FOREST\nPEWTER CITY AHEAD$"

ViridianForest_Text_TrainerTips2:
	.string "For poison, use ANTIDOTE!\nGet it at POKéMON MARTS!$"

ViridianForest_Text_TrainerTips5:
	.string "TRAINER TIPS\pWeaken POKéMON before attempting\ncapture!\pWhen healthy, they may escape!$"
