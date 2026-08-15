BlackthornGym1F_MapScripts::
	.byte 0

BlackthornGym1F_EventScript_MIKE::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERM_MIKE, BlackthornGym1F_Text_MIKESeen, BlackthornGym1F_Text_MIKEBeaten
	msgbox BlackthornGym1F_Text_MIKEBeaten, MSGBOX_AUTOCLOSE
	end

BlackthornGym1F_EventScript_PAUL::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERM_PAUL, BlackthornGym1F_Text_PAULSeen, BlackthornGym1F_Text_PAULBeaten
	msgbox BlackthornGym1F_Text_PAULBeaten, MSGBOX_AUTOCLOSE
	end

BlackthornGym1F_EventScript_LOLA::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_LOLA, BlackthornGym1F_Text_LOLASeen, BlackthornGym1F_Text_LOLABeaten
	msgbox BlackthornGym1F_Text_LOLABeaten, MSGBOX_AUTOCLOSE
	end

BlackthornGym1F_EventScript_BlackthornGymGuide::
	msgbox BlackthornGym1F_Text_BlackthornGymGuide, MSGBOX_NPC
	end

BlackthornGym1F_Text_MIKESeen:
	.string "My chance of\nlosing? Not even\lone percent!$"

BlackthornGym1F_Text_MIKEBeaten:
	.string "That's odd.$"

BlackthornGym1F_Text_PAULSeen:
	.string "Your first battle\nagainst dragons?\pI'll show you how\ntough they are!$"

BlackthornGym1F_Text_PAULBeaten:
	.string "My dragon POKéMON\nlost?$"

BlackthornGym1F_Text_LOLASeen:
	.string "Dragons are sacred\nPOKéMON.\pThey are full of\nlife energy.\pIf you're not\nserious, you won't\pbe able to beat\nthem.$"

BlackthornGym1F_Text_LOLABeaten:
	.string "Way to go!$"

BlackthornGym1F_Text_BlackthornGymGuide:
	.string "Nothing much happens around here,\nbut ever since that ferry started\lrunning to HOENN, who knows.$"
