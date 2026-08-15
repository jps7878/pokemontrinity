Route39_MapScripts::
	.byte 0

Route39_EventScript_EUGENE::
	trainerbattle_single TRAINER_JOHTO_SAILOR_EUGENE, Route39_Text_EUGENESeen, Route39_Text_EUGENEBeaten
	msgbox Route39_Text_EUGENEBeaten, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_DEREK1::
	trainerbattle_single TRAINER_JOHTO_POKEFANM_DEREK1, Route39_Text_DEREK1Seen, Route39_Text_DEREK1Beaten
	msgbox Route39_Text_DEREK1Beaten, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_RUTH::
	trainerbattle_single TRAINER_JOHTO_POKEFANF_RUTH, Route39_Text_RUTHSeen, Route39_Text_RUTHBeaten
	msgbox Route39_Text_RUTHBeaten, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_NORMAN::
	trainerbattle_single TRAINER_JOHTO_PSYCHIC_T_NORMAN, Route39_Text_NORMANSeen, Route39_Text_NORMANBeaten
	msgbox Route39_Text_NORMANBeaten, MSGBOX_AUTOCLOSE
	end

Route39_EventScript_TrainerPokefanfJaime::
	msgbox Route39_Text_TrainerPokefanfJaime, MSGBOX_NPC
	end

Route39_EventScript_TrainerTips::
	msgbox Route39_Text_TrainerTips, MSGBOX_SIGN
	end

Route39_EventScript_MoomooFarmSign::
	msgbox Route39_Text_MoomooFarmSign, MSGBOX_SIGN
	end

Route39_EventScript_Sign::
	msgbox Route39_Text_Sign, MSGBOX_SIGN
	end

Route39_Text_EUGENESeen:
	.string "I just got back to\nOLIVINE.\pSo how about a\nPOKéMON battle?$"

Route39_Text_EUGENEBeaten:
	.string "Awaaargh!$"

Route39_Text_DEREK1Seen:
	.string "This is a good\ntime to brag about\lmy PIKACHU!$"

Route39_Text_DEREK1Beaten:
	.string "I had no time to\nshow off PIKACHU…$"

Route39_Text_RUTHSeen:
	.string "Such darling\nPOKéMON.\pLet's show our\nPOKéMON together\lat the same time.$"

Route39_Text_RUTHBeaten:
	.string "I don't mind\nlosing.$"

Route39_Text_NORMANSeen:
	.string "Let me see what\nyour POKéMON are\lcapable of.$"

Route39_Text_NORMANBeaten:
	.string "Ooh, your POKéMON\nhave potential.$"

Route39_Text_TrainerPokefanfJaime:
	.string "Nothing much happens around here,\nbut ever since that ferry started\lrunning to HOENN, who knows.$"

Route39_Text_TrainerTips:
	.string "TRAINER TIPS\pUse HEADBUTT on\ntrees to shake\lPOKéMON out.\pDifferent kinds of\nPOKéMON drop out\lof trees.\pUse HEADBUTT on\nany tree you see!$"

Route39_Text_MoomooFarmSign:
	.string "MOOMOO FARM\pEnjoy Our Fresh\nand Tasty Milk$"

Route39_Text_Sign:
	.string "ROUTE 39\pOLIVINE CITY -\nECRUTEAK CITY$"
