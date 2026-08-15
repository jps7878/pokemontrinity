DragonsDenB1F_MapScripts::
	.byte 0

DragonsDenB1F_EventScript_DARIN::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERM_DARIN, DragonsDenB1F_Text_DARINSeen, DragonsDenB1F_Text_DARINBeaten
	msgbox DragonsDenB1F_Text_DARINBeaten, MSGBOX_AUTOCLOSE
	end

DragonsDenB1F_EventScript_CARA::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_CARA, DragonsDenB1F_Text_CARASeen, DragonsDenB1F_Text_CARABeaten
	msgbox DragonsDenB1F_Text_CARABeaten, MSGBOX_AUTOCLOSE
	end

DragonsDenB1F_EventScript_LEAANDPIA1::
	trainerbattle_single TRAINER_JOHTO_TWINS_LEAANDPIA1, DragonsDenB1F_Text_LEAANDPIA1Seen, DragonsDenB1F_Text_LEAANDPIA1Beaten
	msgbox DragonsDenB1F_Text_LEAANDPIA1Beaten, MSGBOX_AUTOCLOSE
	end

DragonsDenB1F_EventScript_LEAANDPIA1_2::
	trainerbattle_single TRAINER_JOHTO_TWINS_LEAANDPIA1_2, DragonsDenB1F_Text_LEAANDPIA1Seen_2, DragonsDenB1F_Text_LEAANDPIA1Beaten_2
	msgbox DragonsDenB1F_Text_LEAANDPIA1Beaten_2, MSGBOX_AUTOCLOSE
	end

DragonsDenB1F_EventScript_DragonShrineSignpost::
	msgbox DragonsDenB1F_Text_DragonShrineSignpost, MSGBOX_SIGN
	end

DragonsDenB1F_Text_DARINSeen:
	.string "You! How dare you\nenter uninvited!$"

DragonsDenB1F_Text_DARINBeaten:
	.string "S-strong!$"

DragonsDenB1F_Text_CARASeen:
	.string "You shouldn't be\nin here!$"

DragonsDenB1F_Text_CARABeaten:
	.string "Oh yikes, I lost!$"

DragonsDenB1F_Text_LEAANDPIA1Seen:
	.string "It's a stranger we\ndon't know.$"

DragonsDenB1F_Text_LEAANDPIA1Beaten:
	.string "Ouchies.$"

DragonsDenB1F_Text_LEAANDPIA1Seen_2:
	.string "Who are you?$"

DragonsDenB1F_Text_LEAANDPIA1Beaten_2:
	.string "Meanie.$"

DragonsDenB1F_Text_DragonShrineSignpost:
	.string "DRAGON SHRINE\pA shrine honoring\nthe dragon POKéMON\psaid to have lived\nin DRAGON'S DEN.$"
