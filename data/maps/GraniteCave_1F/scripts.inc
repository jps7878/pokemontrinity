GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Hey, you.\n"
	.string "It gets awfully dark ahead.\l"
	.string "It'll be tough trying to explore.\p"
	.string "That guy who came by earlier…\n"
	.string "STEVEN, I think it was.\p"
	.string "He knew how to use FLASH, so he ought\n"
	.string "to be all right, but…\p"
	.string "Well, for us HIKERS, helping out those\n"
	.string "that we meet is our motto.\p"
	.string "Here you go, I'll pass this on to you.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Teach that hidden move FLASH to\n"
	.string "a POKéMON and use it.\p"
	.string "It lights up even the inky darkness\n"
	.string "of caves.\p"
	.string "But, to use it, you need the GYM BADGE\n"
	.string "from DEWFORD's POKéMON GYM.$"

GraniteCave_1F_EventScript_Harjot::
	trainerbattle_single TRAINER_HARJOT, GraniteCave_1F_Text_HarjotIntro, GraniteCave_1F_Text_HarjotDefeat, GraniteCave_1F_EventScript_HarjotReward
	goto_if_unset FLAG_RECEIVED_REWARD_HARJOT, GraniteCave_1F_EventScript_HarjotReward
	msgbox GraniteCave_1F_Text_HarjotPostReward, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_HarjotReward::
	msgbox GraniteCave_1F_Text_HarjotRewardOffer, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_FAMILY_REWARD, FALSE
	switch VAR_RESULT
	case 0, GraniteCave_1F_EventScript_HarjotMasterBalls
	case 1, GraniteCave_1F_EventScript_HarjotRareCandies
	case 2, GraniteCave_1F_EventScript_HarjotCancel
	case MULTI_B_PRESSED, GraniteCave_1F_EventScript_HarjotCancel
	end

GraniteCave_1F_EventScript_HarjotMasterBalls::
	giveitem ITEM_MASTER_BALL, 2
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_REWARD_HARJOT
	msgbox GraniteCave_1F_Text_HarjotPostReward, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_HarjotRareCandies::
	giveitem ITEM_RARE_CANDY, 99
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_REWARD_HARJOT
	msgbox GraniteCave_1F_Text_HarjotPostReward, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_HarjotCancel::
	release
	end

GraniteCave_1F_Text_HarjotIntro:
	.string "You think you can challenge the\n"
	.string "Champion's family?\l"
	.string "These fists say otherwise!$"

GraniteCave_1F_Text_HarjotDefeat:
	.string "No wonder you're headed for\n"
	.string "the top. You fight like one of us!$"

GraniteCave_1F_Text_HarjotRewardOffer:
	.string "You've earned a reward.\n"
	.string "Choose wisely.$"

GraniteCave_1F_Text_HarjotPostReward:
	.string "Keep training. GRANITE CAVE\n"
	.string "makes warriors out of everyone.$"

