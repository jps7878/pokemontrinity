Route43_MapScripts::
	.byte 0

Route43_EventScript_BEN::
	trainerbattle_single TRAINER_JOHTO_POKEMANIAC_BEN, Route43_Text_BENSeen, Route43_Text_BENBeaten
	msgbox Route43_Text_BENBeaten, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_BRENT1::
	trainerbattle_single TRAINER_JOHTO_POKEMANIAC_BRENT1, Route43_Text_BRENT1Seen, Route43_Text_BRENT1Beaten
	msgbox Route43_Text_BRENT1Beaten, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_RON::
	trainerbattle_single TRAINER_JOHTO_POKEMANIAC_RON, Route43_Text_RONSeen, Route43_Text_RONBeaten
	msgbox Route43_Text_RONBeaten, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_MARVIN::
	trainerbattle_single TRAINER_JOHTO_FISHER_MARVIN, Route43_Text_MARVINSeen, Route43_Text_MARVINBeaten
	msgbox Route43_Text_MARVINBeaten, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_TIFFANY3::
	trainerbattle_single TRAINER_JOHTO_PICNICKER_TIFFANY3, Route43_Text_TIFFANY3Seen, Route43_Text_TIFFANY3Beaten
	msgbox Route43_Text_TIFFANY3Beaten, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_SPENCER::
	trainerbattle_single TRAINER_JOHTO_CAMPER_SPENCER, Route43_Text_SPENCERSeen, Route43_Text_SPENCERBeaten
	msgbox Route43_Text_SPENCERBeaten, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Sign1::
	msgbox Route43_Text_Sign1, MSGBOX_SIGN
	end

Route43_EventScript_Sign2::
	msgbox Route43_Text_Sign2, MSGBOX_SIGN
	end

Route43_EventScript_TrainerTips::
	msgbox Route43_Text_TrainerTips, MSGBOX_SIGN
	end

Route43_Text_BENSeen:
	.string "I love POKéMON!\pThat's why I\nstarted--and why\pI'll keep on col-\nlecting POKéMON!$"

Route43_Text_BENBeaten:
	.string "How could you do\nthis to me?$"

Route43_Text_BRENT1Seen:
	.string "Hey! Do you have\nany rare POKéMON?$"

Route43_Text_BRENT1Beaten:
	.string "Oh, my poor POKé-\nMON! Darlings!$"

Route43_Text_RONSeen:
	.string "Would you get\nthis?\pSome SILVER guy\nmade fun of my\lPOKéMON!\pDarn it! My POKé-\nMON's great!$"

Route43_Text_RONBeaten:
	.string "My NIDOKING did\npretty right on!$"

Route43_Text_MARVINSeen:
	.string "I'm in a slump.\pMaybe it's the\ngear I'm using.\pLet's battle for a\nchange of pace!$"

Route43_Text_MARVINBeaten:
	.string "I lost, but I feel\nbetter anyway.$"

Route43_Text_TIFFANY3Seen:
	.string "Are you going to\nLAKE OF RAGE too?\pLet's play for a \nlittle while!$"

Route43_Text_TIFFANY3Beaten:
	.string "I played too much!$"

Route43_Text_SPENCERSeen:
	.string "I can do so much\nwith my POKéMON--\lit's super-fun!$"

Route43_Text_SPENCERBeaten:
	.string "Losing isn't fun\nat all…$"

Route43_Text_Sign1:
	.string "ROUTE 43\pLAKE OF RAGE -\nMAHOGANY TOWN$"

Route43_Text_Sign2:
	.string "ROUTE 43\pLAKE OF RAGE -\nMAHOGANY TOWN$"

Route43_Text_TrainerTips:
	.string "TRAINER TIPS\pAll POKéMON have\npros and cons\pdepending on their\ntypes.\pIf their types\ndiffer, a higher-\plevel POKéMON may\nlose in battle.\pLearn which types\nare strong and\pweak against your\nPOKéMON's type.$"
