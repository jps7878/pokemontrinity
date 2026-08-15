VioletGym_MapScripts::
	.byte 0

VioletGym_EventScript_ROD::
	trainerbattle_single TRAINER_JOHTO_BIRD_KEEPER_ROD, VioletGym_Text_RODSeen, VioletGym_Text_RODBeaten
	msgbox VioletGym_Text_RODBeaten, MSGBOX_AUTOCLOSE
	end

VioletGym_EventScript_ABE::
	trainerbattle_single TRAINER_JOHTO_BIRD_KEEPER_ABE, VioletGym_Text_ABESeen, VioletGym_Text_ABEBeaten
	msgbox VioletGym_Text_ABEBeaten, MSGBOX_AUTOCLOSE
	end

VioletGym_EventScript_Guide::
	msgbox VioletGym_Text_Guide, MSGBOX_NPC
	end

VioletGym_Text_RODSeen:
	.string "The keyword is\nguts!\pThose here are\ntraining night and\pday to become bird\nPOKéMON masters.\pCome on!$"

VioletGym_Text_RODBeaten:
	.string "Gaaah!$"

VioletGym_Text_ABESeen:
	.string "Let me see if you\nare good enough to\lface FALKNER!$"

VioletGym_Text_ABEBeaten:
	.string "This can't be\ntrue!$"

VioletGym_Text_Guide:
	.string "Nothing much happens around here,\nbut ever since that ferry started\lrunning to HOENN, who knows.$"
