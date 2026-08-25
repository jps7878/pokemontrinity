SaffronCity_Dojo_MapScripts::
	.byte 0

SaffronCity_Dojo_EventScript_Hitoshi::
	trainerbattle_single TRAINER_KANTO_BLACK_BELT_HITOSHI, SaffronCity_Dojo_Text_HitoshiSeen, SaffronCity_Dojo_Text_HitoshiBeaten
	msgbox SaffronCity_Dojo_Text_HitoshiBeaten, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Hideki::
	trainerbattle_single TRAINER_KANTO_BLACK_BELT_HIDEKI, SaffronCity_Dojo_Text_HidekiSeen, SaffronCity_Dojo_Text_HidekiBeaten
	msgbox SaffronCity_Dojo_Text_HidekiBeaten, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Aaron::
	trainerbattle_single TRAINER_KANTO_BLACK_BELT_AARON, SaffronCity_Dojo_Text_AaronSeen, SaffronCity_Dojo_Text_AaronBeaten
	msgbox SaffronCity_Dojo_Text_AaronBeaten, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Mike::
	trainerbattle_single TRAINER_KANTO_BLACK_BELT_MIKE, SaffronCity_Dojo_Text_MikeSeen, SaffronCity_Dojo_Text_MikeBeaten
	msgbox SaffronCity_Dojo_Text_MikeBeaten, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_MasterKoichi::
	trainerbattle_single TRAINER_KANTO_BLACK_BELT_KOICHI, SaffronCity_Dojo_Text_MasterKoichiSeen, SaffronCity_Dojo_Text_MasterKoichiBeaten
	msgbox SaffronCity_Dojo_Text_MasterKoichiBeaten, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Statue::
	msgbox SaffronCity_Dojo_Text_Statue, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_Statue_2::
	msgbox SaffronCity_Dojo_Text_Statue_2, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_LeftScroll::
	msgbox SaffronCity_Dojo_Text_LeftScroll, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_RightScroll::
	msgbox SaffronCity_Dojo_Text_RightScroll, MSGBOX_SIGN
	end

SaffronCity_Dojo_Text_HitoshiSeen:
	.string "…$"

SaffronCity_Dojo_Text_HitoshiBeaten:
	.string "…$"

SaffronCity_Dojo_Text_HidekiSeen:
	.string "…$"

SaffronCity_Dojo_Text_HidekiBeaten:
	.string "…$"

SaffronCity_Dojo_Text_AaronSeen:
	.string "…$"

SaffronCity_Dojo_Text_AaronBeaten:
	.string "…$"

SaffronCity_Dojo_Text_MikeSeen:
	.string "…$"

SaffronCity_Dojo_Text_MikeBeaten:
	.string "…$"

SaffronCity_Dojo_Text_MasterKoichiSeen:
	.string "…$"

SaffronCity_Dojo_Text_MasterKoichiBeaten:
	.string "…$"

SaffronCity_Dojo_Text_Statue:
	.string "FIGHTING DOJO$"

SaffronCity_Dojo_Text_Statue_2:
	.string "FIGHTING DOJO$"

SaffronCity_Dojo_Text_LeftScroll:
	.string "Enemies on every side!$"

SaffronCity_Dojo_Text_RightScroll:
	.string "What goes around comes around.$"
