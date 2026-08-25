Route14_MapScripts::
	.byte 0

Route14_EventScript_Gerald::
	trainerbattle_single TRAINER_KANTO_BIKER_GERALD, Route14_Text_GeraldSeen, Route14_Text_GeraldBeaten
	msgbox Route14_Text_GeraldBeaten, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Donald::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_DONALD, Route14_Text_DonaldSeen, Route14_Text_DonaldBeaten
	msgbox Route14_Text_DonaldBeaten, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Beck::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_BECK, Route14_Text_BeckSeen, Route14_Text_BeckBeaten
	msgbox Route14_Text_BeckBeaten, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Marlon::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_MARLON, Route14_Text_MarlonSeen, Route14_Text_MarlonBeaten
	msgbox Route14_Text_MarlonBeaten, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Isaac::
	trainerbattle_single TRAINER_KANTO_BIKER_ISAAC, Route14_Text_IsaacSeen, Route14_Text_IsaacBeaten
	msgbox Route14_Text_IsaacBeaten, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Malik::
	trainerbattle_single TRAINER_KANTO_BIKER_MALIK, Route14_Text_MalikSeen, Route14_Text_MalikBeaten
	msgbox Route14_Text_MalikBeaten, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Mitch::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_MITCH, Route14_Text_MitchSeen, Route14_Text_MitchBeaten
	msgbox Route14_Text_MitchBeaten, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Carter::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_CARTER, Route14_Text_CarterSeen, Route14_Text_CarterBeaten
	msgbox Route14_Text_CarterBeaten, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Lukas::
	trainerbattle_single TRAINER_KANTO_BIKER_LUKAS, Route14_Text_LukasSeen, Route14_Text_LukasBeaten
	msgbox Route14_Text_LukasBeaten, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Benny::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_BENNY, Route14_Text_BennySeen, Route14_Text_BennyBeaten
	msgbox Route14_Text_BennyBeaten, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Jan::
	trainerbattle_single TRAINER_KANTO_TWINS_KIRI_JAN, Route14_Text_JanSeen, Route14_Text_JanBeaten
	msgbox Route14_Text_JanBeaten, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_Kiri::
	trainerbattle_single TRAINER_KANTO_TWINS_KIRI_JAN_2, Route14_Text_KiriSeen, Route14_Text_KiriBeaten
	msgbox Route14_Text_KiriBeaten, MSGBOX_AUTOCLOSE
	end

Route14_EventScript_RouteSign::
	msgbox Route14_Text_RouteSign, MSGBOX_SIGN
	end

Route14_Text_GeraldSeen:
	.string "…$"

Route14_Text_GeraldBeaten:
	.string "…$"

Route14_Text_DonaldSeen:
	.string "…$"

Route14_Text_DonaldBeaten:
	.string "…$"

Route14_Text_BeckSeen:
	.string "…$"

Route14_Text_BeckBeaten:
	.string "…$"

Route14_Text_MarlonSeen:
	.string "…$"

Route14_Text_MarlonBeaten:
	.string "…$"

Route14_Text_IsaacSeen:
	.string "…$"

Route14_Text_IsaacBeaten:
	.string "…$"

Route14_Text_MalikSeen:
	.string "…$"

Route14_Text_MalikBeaten:
	.string "…$"

Route14_Text_MitchSeen:
	.string "…$"

Route14_Text_MitchBeaten:
	.string "…$"

Route14_Text_CarterSeen:
	.string "…$"

Route14_Text_CarterBeaten:
	.string "…$"

Route14_Text_LukasSeen:
	.string "…$"

Route14_Text_LukasBeaten:
	.string "…$"

Route14_Text_BennySeen:
	.string "…$"

Route14_Text_BennyBeaten:
	.string "…$"

Route14_Text_JanSeen:
	.string "…$"

Route14_Text_JanBeaten:
	.string "…$"

Route14_Text_KiriSeen:
	.string "…$"

Route14_Text_KiriBeaten:
	.string "…$"

Route14_Text_RouteSign:
	.string "ROUTE 14\nWest to FUCHSIA CITY$"
