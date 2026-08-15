GoldenrodUnderground_MapScripts::
	.byte 0

GoldenrodUnderground_EventScript_ERIC::
	trainerbattle_single TRAINER_JOHTO_SUPER_NERD_ERIC, GoldenrodUnderground_Text_ERICSeen, GoldenrodUnderground_Text_ERICBeaten
	msgbox GoldenrodUnderground_Text_ERICBeaten, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_TERU::
	trainerbattle_single TRAINER_JOHTO_SUPER_NERD_TERU, GoldenrodUnderground_Text_TERUSeen, GoldenrodUnderground_Text_TERUBeaten
	msgbox GoldenrodUnderground_Text_TERUBeaten, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_ISSAC::
	trainerbattle_single TRAINER_JOHTO_POKEMANIAC_ISSAC, GoldenrodUnderground_Text_ISSACSeen, GoldenrodUnderground_Text_ISSACBeaten
	msgbox GoldenrodUnderground_Text_ISSACBeaten, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_DONALD::
	trainerbattle_single TRAINER_JOHTO_POKEMANIAC_DONALD, GoldenrodUnderground_Text_DONALDSeen, GoldenrodUnderground_Text_DONALDBeaten
	msgbox GoldenrodUnderground_Text_DONALDBeaten, MSGBOX_AUTOCLOSE
	end

GoldenrodUnderground_EventScript_NoEntrySign::
	msgbox GoldenrodUnderground_Text_NoEntrySign, MSGBOX_SIGN
	end

GoldenrodUnderground_Text_ERICSeen:
	.string "I got booted out\nof the GAME COR-\lNER.\pI was trying to\ncheat using my\lPOKéMON…$"

GoldenrodUnderground_Text_ERICBeaten:
	.string "…Grumble…$"

GoldenrodUnderground_Text_TERUSeen:
	.string "Do you consider\ntype alignments in\lbattle?\pIf you know your\ntype advantages,\pyou'll do better\nin battle.$"

GoldenrodUnderground_Text_TERUBeaten:
	.string "Ow, ow, ow!$"

GoldenrodUnderground_Text_ISSACSeen:
	.string "My POKéMON just\ngot a haircut!\pI'll show you how\nstrong it is!$"

GoldenrodUnderground_Text_ISSACBeaten:
	.string "Aiyeeee!$"

GoldenrodUnderground_Text_DONALDSeen:
	.string "I think you have\nsome rare POKéMON\lwith you.\pLet me see them!$"

GoldenrodUnderground_Text_DONALDBeaten:
	.string "Gaah! I lost!\nThat makes me mad!$"

GoldenrodUnderground_Text_NoEntrySign:
	.string "NO ENTRY BEYOND\nTHIS POINT$"
