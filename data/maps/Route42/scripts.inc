Route42_MapScripts::
	.byte 0

Route42_EventScript_TULLY1::
	trainerbattle_single TRAINER_JOHTO_FISHER_TULLY1, Route42_Text_TULLY1Seen, Route42_Text_TULLY1Beaten
	msgbox Route42_Text_TULLY1Beaten, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_BENJAMIN::
	trainerbattle_single TRAINER_JOHTO_HIKER_BENJAMIN, Route42_Text_BENJAMINSeen, Route42_Text_BENJAMINBeaten
	msgbox Route42_Text_BENJAMINBeaten, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_SHANE::
	trainerbattle_single TRAINER_JOHTO_POKEMANIAC_SHANE, Route42_Text_SHANESeen, Route42_Text_SHANEBeaten
	msgbox Route42_Text_SHANEBeaten, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Sign1::
	msgbox Route42_Text_Sign1, MSGBOX_SIGN
	end

Route42_EventScript_MtMortarSign1::
	msgbox Route42_Text_MtMortarSign1, MSGBOX_SIGN
	end

Route42_EventScript_MtMortarSign2::
	msgbox Route42_Text_MtMortarSign2, MSGBOX_SIGN
	end

Route42_EventScript_Sign2::
	msgbox Route42_Text_Sign2, MSGBOX_SIGN
	end

Route42_Text_TULLY1Seen:
	.string "Let me demonstrate\nthe power of the\lPOKéMON I caught!$"

Route42_Text_TULLY1Beaten:
	.string "What? That's not\nright.$"

Route42_Text_BENJAMINSeen:
	.string "Ah, it's good to\nbe outside!\lI feel so free!$"

Route42_Text_BENJAMINBeaten:
	.string "Gahahah!$"

Route42_Text_SHANESeen:
	.string "HEY!\pThis is my secret\nplace! Get lost,\lyou outsider!$"

Route42_Text_SHANEBeaten:
	.string "I should have used\nmy MOON STONE…$"

Route42_Text_Sign1:
	.string "ROUTE 42\pECRUTEAK CITY -\nMAHOGANY TOWN$"

Route42_Text_MtMortarSign1:
	.string "MT.MORTAR\pWATERFALL CAVE\nINSIDE$"

Route42_Text_MtMortarSign2:
	.string "MT.MORTAR\pWATERFALL CAVE\nINSIDE$"

Route42_Text_Sign2:
	.string "ROUTE 42\pECRUTEAK CITY -\nMAHOGANY TOWN$"
