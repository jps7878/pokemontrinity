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
	msgbox ViridianForest_Text_RickBeaten, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Doug::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_DOUG, ViridianForest_Text_DougSeen, ViridianForest_Text_DougBeaten
	msgbox ViridianForest_Text_DougBeaten, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Sammy::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_SAMMY, ViridianForest_Text_SammySeen, ViridianForest_Text_SammyBeaten
	msgbox ViridianForest_Text_SammyBeaten, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Anthony::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonySeen, ViridianForest_Text_AnthonyBeaten
	msgbox ViridianForest_Text_AnthonyBeaten, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Charlie::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieSeen, ViridianForest_Text_CharlieBeaten
	msgbox ViridianForest_Text_CharlieBeaten, MSGBOX_AUTOCLOSE
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
	.string "…$"

ViridianForest_Text_RickBeaten:
	.string "…$"

ViridianForest_Text_DougSeen:
	.string "…$"

ViridianForest_Text_DougBeaten:
	.string "…$"

ViridianForest_Text_SammySeen:
	.string "…$"

ViridianForest_Text_SammyBeaten:
	.string "…$"

ViridianForest_Text_AnthonySeen:
	.string "…$"

ViridianForest_Text_AnthonyBeaten:
	.string "…$"

ViridianForest_Text_CharlieSeen:
	.string "…$"

ViridianForest_Text_CharlieBeaten:
	.string "…$"

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
