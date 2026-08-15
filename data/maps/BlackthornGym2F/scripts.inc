BlackthornGym2F_MapScripts::
	.byte 0

BlackthornGym2F_EventScript_CODY::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERM_CODY, BlackthornGym2F_Text_CODYSeen, BlackthornGym2F_Text_CODYBeaten
	msgbox BlackthornGym2F_Text_CODYBeaten, MSGBOX_AUTOCLOSE
	end

BlackthornGym2F_EventScript_FRAN::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_FRAN, BlackthornGym2F_Text_FRANSeen, BlackthornGym2F_Text_FRANBeaten
	msgbox BlackthornGym2F_Text_FRANBeaten, MSGBOX_AUTOCLOSE
	end

BlackthornGym2F_Text_CODYSeen:
	.string "It's not as if we\nall use dragon-\ltype POKéMON.$"

BlackthornGym2F_Text_CODYBeaten:
	.string "Rats! If only I\nhad a dragon!$"

BlackthornGym2F_Text_FRANSeen:
	.string "I can't allow a\nnameless trainer\lpast me!\pCLAIR would be\nlivid if I did!$"

BlackthornGym2F_Text_FRANBeaten:
	.string "Awww… I lost…$"
