MahoganyGym_MapScripts::
	.byte 0

MahoganyGym_EventScript_ROXANNE::
	trainerbattle_single TRAINER_JOHTO_SKIER_ROXANNE, MahoganyGym_Text_ROXANNESeen, MahoganyGym_Text_ROXANNEBeaten
	msgbox MahoganyGym_Text_ROXANNEBeaten, MSGBOX_AUTOCLOSE
	end

MahoganyGym_EventScript_RONALD::
	trainerbattle_single TRAINER_JOHTO_BOARDER_RONALD, MahoganyGym_Text_RONALDSeen, MahoganyGym_Text_RONALDBeaten
	msgbox MahoganyGym_Text_RONALDBeaten, MSGBOX_AUTOCLOSE
	end

MahoganyGym_EventScript_CLARISSA::
	trainerbattle_single TRAINER_JOHTO_SKIER_CLARISSA, MahoganyGym_Text_CLARISSASeen, MahoganyGym_Text_CLARISSABeaten
	msgbox MahoganyGym_Text_CLARISSABeaten, MSGBOX_AUTOCLOSE
	end

MahoganyGym_EventScript_BRAD::
	trainerbattle_single TRAINER_JOHTO_BOARDER_BRAD, MahoganyGym_Text_BRADSeen, MahoganyGym_Text_BRADBeaten
	msgbox MahoganyGym_Text_BRADBeaten, MSGBOX_AUTOCLOSE
	end

MahoganyGym_EventScript_DOUGLAS::
	trainerbattle_single TRAINER_JOHTO_BOARDER_DOUGLAS, MahoganyGym_Text_DOUGLASSeen, MahoganyGym_Text_DOUGLASBeaten
	msgbox MahoganyGym_Text_DOUGLASBeaten, MSGBOX_AUTOCLOSE
	end

MahoganyGym_EventScript_Guide::
	msgbox MahoganyGym_Text_Guide, MSGBOX_NPC
	end

MahoganyGym_Text_ROXANNESeen:
	.string "To get to PRYCE,\nour GYM LEADER,\pyou need to think\nbefore you skate.$"

MahoganyGym_Text_ROXANNEBeaten:
	.string "I wouldn't lose to\nyou in skiing!$"

MahoganyGym_Text_RONALDSeen:
	.string "I'll freeze your\nPOKéMON, so you\lcan't do a thing!$"

MahoganyGym_Text_RONALDBeaten:
	.string "Darn. I couldn't\ndo a thing.$"

MahoganyGym_Text_CLARISSASeen:
	.string "Check out my\nparallel turn!$"

MahoganyGym_Text_CLARISSABeaten:
	.string "No! You made me\nwipe out!$"

MahoganyGym_Text_BRADSeen:
	.string "This GYM has a\nslippery floor.\pIt's fun, isn't\nit?\pBut hey--we're\nnot playing games\lhere!$"

MahoganyGym_Text_BRADBeaten:
	.string "Do you see how\nserious we are?$"

MahoganyGym_Text_DOUGLASSeen:
	.string "I know PRYCE's\nsecret.$"

MahoganyGym_Text_DOUGLASBeaten:
	.string "OK. I'll tell you\nPRYCE's secret.$"

MahoganyGym_Text_Guide:
	.string "They say the HOENN champion's\njourney is just getting started.\lWonder where they'll go next.$"
