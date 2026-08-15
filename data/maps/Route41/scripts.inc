Route41_MapScripts::
	.byte 0

Route41_EventScript_CHARLIE::
	trainerbattle_single TRAINER_JOHTO_SWIMMERM_CHARLIE, Route41_Text_CHARLIESeen, Route41_Text_CHARLIEBeaten
	msgbox Route41_Text_CHARLIEBeaten, MSGBOX_AUTOCLOSE
	end

Route41_EventScript_GEORGE::
	trainerbattle_single TRAINER_JOHTO_SWIMMERM_GEORGE, Route41_Text_GEORGESeen, Route41_Text_GEORGEBeaten
	msgbox Route41_Text_GEORGEBeaten, MSGBOX_AUTOCLOSE
	end

Route41_EventScript_BERKE::
	trainerbattle_single TRAINER_JOHTO_SWIMMERM_BERKE, Route41_Text_BERKESeen, Route41_Text_BERKEBeaten
	msgbox Route41_Text_BERKEBeaten, MSGBOX_AUTOCLOSE
	end

Route41_EventScript_KIRK::
	trainerbattle_single TRAINER_JOHTO_SWIMMERM_KIRK, Route41_Text_KIRKSeen, Route41_Text_KIRKBeaten
	msgbox Route41_Text_KIRKBeaten, MSGBOX_AUTOCLOSE
	end

Route41_EventScript_MATHEW::
	trainerbattle_single TRAINER_JOHTO_SWIMMERM_MATHEW, Route41_Text_MATHEWSeen, Route41_Text_MATHEWBeaten
	msgbox Route41_Text_MATHEWBeaten, MSGBOX_AUTOCLOSE
	end

Route41_EventScript_KAYLEE::
	trainerbattle_single TRAINER_JOHTO_SWIMMERF_KAYLEE, Route41_Text_KAYLEESeen, Route41_Text_KAYLEEBeaten
	msgbox Route41_Text_KAYLEEBeaten, MSGBOX_AUTOCLOSE
	end

Route41_EventScript_SUSIE::
	trainerbattle_single TRAINER_JOHTO_SWIMMERF_SUSIE, Route41_Text_SUSIESeen, Route41_Text_SUSIEBeaten
	msgbox Route41_Text_SUSIEBeaten, MSGBOX_AUTOCLOSE
	end

Route41_EventScript_DENISE::
	trainerbattle_single TRAINER_JOHTO_SWIMMERF_DENISE, Route41_Text_DENISESeen, Route41_Text_DENISEBeaten
	msgbox Route41_Text_DENISEBeaten, MSGBOX_AUTOCLOSE
	end

Route41_EventScript_KARA::
	trainerbattle_single TRAINER_JOHTO_SWIMMERF_KARA, Route41_Text_KARASeen, Route41_Text_KARABeaten
	msgbox Route41_Text_KARABeaten, MSGBOX_AUTOCLOSE
	end

Route41_EventScript_WENDY::
	trainerbattle_single TRAINER_JOHTO_SWIMMERF_WENDY, Route41_Text_WENDYSeen, Route41_Text_WENDYBeaten
	msgbox Route41_Text_WENDYBeaten, MSGBOX_AUTOCLOSE
	end

Route41_Text_CHARLIESeen:
	.string "The water's warm\nhere. I'm loose\land limber.\pSure, I'll take\nyou on!$"

Route41_Text_CHARLIEBeaten:
	.string "Yikes! I've got\nprune skin!$"

Route41_Text_GEORGESeen:
	.string "I'm a bit tired.\nIf I win, lend me\lyour POKéMON.$"

Route41_Text_GEORGEBeaten:
	.string "Pant, pant…$"

Route41_Text_BERKESeen:
	.string "See those islands\nthat are blocked\lby whirlpools?\pThere just has to\nbe a secret!$"

Route41_Text_BERKEBeaten:
	.string "What's the secret\nto your strength?$"

Route41_Text_KIRKSeen:
	.string "The waves are wild\nhere.\pThey tire you out\nwhile you swim.$"

Route41_Text_KIRKBeaten:
	.string "I'm beat!$"

Route41_Text_MATHEWSeen:
	.string "Are you seeking\nthe secrets of\lWHIRL ISLANDS?$"

Route41_Text_MATHEWBeaten:
	.string "Ooh, you've got\ngreat endurance!$"

Route41_Text_KAYLEESeen:
	.string "I'm on my way to\nWHIRL ISLANDS.\pI'm going explor-\ning with friends.$"

Route41_Text_KAYLEEBeaten:
	.string "Is that how you do\nit?$"

Route41_Text_SUSIESeen:
	.string "You look so ele-\ngant, riding your\lPOKéMON.$"

Route41_Text_SUSIEBeaten:
	.string "I'm crushed…$"

Route41_Text_DENISESeen:
	.string "The weather is so\nbeautiful, I'm in\la daze!$"

Route41_Text_DENISEBeaten:
	.string "Ohhh!$"

Route41_Text_KARASeen:
	.string "If you need to\nrest, just tread\lwater.\pYou'll get your\nwind back, so you\pcan keep on going\nstrong.$"

Route41_Text_KARABeaten:
	.string "Oh! You have more\nenergy than I do.$"

Route41_Text_WENDYSeen:
	.string "At night, STARYU\ngather near the\lwater's surface.$"

Route41_Text_WENDYBeaten:
	.string "Oh, dear…$"
