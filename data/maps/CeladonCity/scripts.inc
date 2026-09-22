CeladonCity_MapScripts::
	.byte 0

CeladonCity_EventScript_FatMan::
	msgbox CeladonCity_Text_FatMan, MSGBOX_NPC
	end

CeladonCity_EventScript_LittleGirl::
	msgbox CeladonCity_Text_LittleGirl, MSGBOX_NPC
	end

CeladonCity_EventScript_Woman::
	msgbox CeladonCity_Text_Woman, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan2::
	msgbox CeladonCity_Text_OldMan2, MSGBOX_NPC
	end

CeladonCity_EventScript_SoftboiledTutor::
	msgbox CeladonCity_Text_SoftboiledTutor, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan1::
	msgbox CeladonCity_Text_OldMan1, MSGBOX_NPC
	end

CeladonCity_EventScript_Boy::
	msgbox CeladonCity_Text_Boy, MSGBOX_NPC
	end

CeladonCity_EventScript_SilphCoScientist::
	msgbox CeladonCity_Text_SilphCoScientist, MSGBOX_NPC
	end

CeladonCity_EventScript_TrainerTips2::
	msgbox CeladonCity_Text_TrainerTips2, MSGBOX_SIGN
	end

CeladonCity_EventScript_PrizeExchangeSign::
	msgbox CeladonCity_Text_PrizeExchangeSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_CitySign, MSGBOX_SIGN
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips1::
	msgbox CeladonCity_Text_TrainerTips1, MSGBOX_SIGN
	end

CeladonCity_EventScript_DeptStoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	msgbox CeladonCity_Text_GymSign, MSGBOX_SIGN
	end

CeladonCity_Text_FatMan:
	.string "This is my trusted pal, POLIWRATH.\pIt evolved from a POLIWHIRL when\nI used a WATER STONE.$"

CeladonCity_Text_LittleGirl:
	.string "I got my KOFFING in CINNABAR.\pIt's usually nice, but it breathes\npoison when it's angry.$"

@ M7b Task 14 (finding #9, the "Erika stalls" half of the WHERE gap). Both
@ original beats are kept; the pointer is appended. Measured with
@ tools/johto_port/reach_check.py CeladonCity: the CUTTABLE_TREE object at
@ (40,35) seals 158 tiles of southern CELADON, and the GYM warp (11,30) is
@ inside that seal -- ERIKA is unreachable until it is cut. Faithful to
@ FRLG, so not a bug; but the one object that should say so, the GYM sign
@ at (16,31), is itself inside the seal. This WOMAN_2 at (18,22) stands in
@ the pre-cut reachable region (her own cut-vertex loss is 1 tile, her own)
@ and her shipped line is already the city-beautification voice, so the
@ overgrown tree is her business. No object, coordinate or script changes.
CeladonCity_Text_Woman:
	.string "CELADON takes pride in its\n"
	.string "efforts to keep the city\l"
	.string "beautiful.\p"
	.string "That's why the new GAME CORNER\n"
	.string "is bad for our city's image.\p"
	.string "And that overgrown tree on the\n"
	.string "south-east edge of town is a\l"
	.string "disgrace.\p"
	.string "It has closed the only lane\n"
	.string "round to ERIKA's GYM.\p"
	.string "Bring a POKéMON that knows CUT\n"
	.string "and the lane opens again.$"

CeladonCity_Text_OldMan2:
	.string "Moan…\nI blew it all at the slots!\pI knew I should have cashed in my\nCOINS for prizes!$"

CeladonCity_Text_SoftboiledTutor:
	.string "I taught a move on this corner\nonce. My POKéMON's gone.\lSo is the move.$"

CeladonCity_Text_OldMan1:
	.string "Heheh! This GYM is great!\nIt's full of women!$"

CeladonCity_Text_Boy:
	.string "Aaaagh, ow…\nI scalded my tongue!\pThis nice old lady in the MANSION\ngave me some TEA.\pBut it was boiling hot!\nGotta cool it to drink it.$"

CeladonCity_Text_SilphCoScientist:
	.string "Oh, what am I to do…\pSomeone stole our SILPH SCOPE.\pThe thief came running this way,\nI'm sure of it.\pBut I lost sight of him!\nWhere'd he go?$"

CeladonCity_Text_TrainerTips2:
	.string "TRAINER TIPS\pGUARD SPEC. protects POKéMON\nfrom status-reduction moves during\lbattle.\pGet your items at the\nCELADON DEPT. STORE!$"

CeladonCity_Text_PrizeExchangeSign:
	.string "COINS exchanged for prizes!\nPRIZE EXCHANGE$"

CeladonCity_Text_GameCornerSign:
	.string "ROCKET GAME CORNER\nThe playground for grown-ups!$"

CeladonCity_Text_CitySign:
	.string "CELADON CITY\nThe City of Rainbow Dreams$"

CeladonCity_Text_MansionSign:
	.string "CELADON MANSION$"

CeladonCity_Text_TrainerTips1:
	.string "TRAINER TIPS\pX ACCURACY boosts the accuracy of\ntechniques.\pDIRE HIT jacks up the likelihood\nof critical hits.\pGet your items at the CELADON\nDEPT. STORE!$"

CeladonCity_Text_DeptStoreSign:
	.string "Find what you need at the\nCELADON DEPT. STORE!$"

CeladonCity_Text_GymSign:
	.string "CELADON CITY POKéMON GYM\nLEADER: ERIKA\lThe Nature-Loving Princess!$"
