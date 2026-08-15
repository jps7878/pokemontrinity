Route40_MapScripts::
	.byte 0

Route40_EventScript_SIMON::
	trainerbattle_single TRAINER_JOHTO_SWIMMERM_SIMON, Route40_Text_SIMONSeen, Route40_Text_SIMONBeaten
	msgbox Route40_Text_SIMONBeaten, MSGBOX_AUTOCLOSE
	end

Route40_EventScript_RANDALL::
	trainerbattle_single TRAINER_JOHTO_SWIMMERM_RANDALL, Route40_Text_RANDALLSeen, Route40_Text_RANDALLBeaten
	msgbox Route40_Text_RANDALLBeaten, MSGBOX_AUTOCLOSE
	end

Route40_EventScript_ELAINE::
	trainerbattle_single TRAINER_JOHTO_SWIMMERF_ELAINE, Route40_Text_ELAINESeen, Route40_Text_ELAINEBeaten
	msgbox Route40_Text_ELAINEBeaten, MSGBOX_AUTOCLOSE
	end

Route40_EventScript_PAULA::
	trainerbattle_single TRAINER_JOHTO_SWIMMERF_PAULA, Route40_Text_PAULASeen, Route40_Text_PAULABeaten
	msgbox Route40_Text_PAULABeaten, MSGBOX_AUTOCLOSE
	end

Route40_EventScript_Lass1::
	msgbox Route40_Text_Lass1, MSGBOX_NPC
	end

Route40_EventScript_PokefanM::
	msgbox Route40_Text_PokefanM, MSGBOX_NPC
	end

Route40_EventScript_Lass2::
	msgbox Route40_Text_Lass2, MSGBOX_NPC
	end

Route40_EventScript_Sign::
	msgbox Route40_Text_Sign, MSGBOX_SIGN
	end

Route40_Text_SIMONSeen:
	.string "You have to warm\nup before going\linto the water.\pThat's basic.$"

Route40_Text_SIMONBeaten:
	.string "OK! Uncle! I give!$"

Route40_Text_RANDALLSeen:
	.string "Hey, you're young\nand fit!\pDon't ride your\nPOKéMON! Swim!$"

Route40_Text_RANDALLBeaten:
	.string "Uh-oh. I lost…$"

Route40_Text_ELAINESeen:
	.string "Are you going to\nCIANWOOD?\pHow about a quick\nbattle first?$"

Route40_Text_ELAINEBeaten:
	.string "I lost that one!$"

Route40_Text_PAULASeen:
	.string "No inner tube for\nme.\pI'm hanging on to\na sea POKéMON!$"

Route40_Text_PAULABeaten:
	.string "Ooh, I'm feeling\ndizzy!$"

Route40_Text_Lass1:
	.string "Although you can't\nsee it from here,\pCIANWOOD is across\nthe sea.$"

Route40_Text_PokefanM:
	.string "I've lived in JOHTO my whole life.\nNever thought I'd meet someone\lfrom HOENN way out here.$"

Route40_Text_Lass2:
	.string "I came to OLIVINE\nby ship to see the\psights and soak up\nthe atmosphere.\pBeing a port, it\nfeels so different\lfrom a big city.$"

Route40_Text_Sign:
	.string "ROUTE 40\pCIANWOOD CITY -\nOLIVINE CITY$"
