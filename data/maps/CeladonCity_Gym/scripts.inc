CeladonCity_Gym_MapScripts::
	.byte 0

CeladonCity_Gym_EventScript_Kay::
	trainerbattle_single TRAINER_KANTO_LASS_KAY, CeladonCity_Gym_Text_KaySeen, CeladonCity_Gym_Text_KayBeaten
	msgbox CeladonCity_Gym_Text_KayBeaten, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_KANTO_BEAUTY_BRIDGET, CeladonCity_Gym_Text_BridgetSeen, CeladonCity_Gym_Text_BridgetBeaten
	msgbox CeladonCity_Gym_Text_BridgetBeaten, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Tina::
	trainerbattle_single TRAINER_KANTO_PICNICKER_TINA, CeladonCity_Gym_Text_TinaSeen, CeladonCity_Gym_Text_TinaBeaten
	msgbox CeladonCity_Gym_Text_TinaBeaten, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Tamia::
	trainerbattle_single TRAINER_KANTO_BEAUTY_TAMIA, CeladonCity_Gym_Text_TamiaSeen, CeladonCity_Gym_Text_TamiaBeaten
	msgbox CeladonCity_Gym_Text_TamiaBeaten, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Lori::
	trainerbattle_single TRAINER_KANTO_BEAUTY_LORI, CeladonCity_Gym_Text_LoriSeen, CeladonCity_Gym_Text_LoriBeaten
	msgbox CeladonCity_Gym_Text_LoriBeaten, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Lisa::
	trainerbattle_single TRAINER_KANTO_LASS_LISA, CeladonCity_Gym_Text_LisaSeen, CeladonCity_Gym_Text_LisaBeaten
	msgbox CeladonCity_Gym_Text_LisaBeaten, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Mary::
	trainerbattle_single TRAINER_KANTO_COOLTRAINER_MARY, CeladonCity_Gym_Text_MarySeen, CeladonCity_Gym_Text_MaryBeaten
	msgbox CeladonCity_Gym_Text_MaryBeaten, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_GymStatue::
	msgbox CeladonCity_Gym_Text_GymStatue, MSGBOX_SIGN
	end

CeladonCity_Gym_EventScript_GymStatue_2::
	msgbox CeladonCity_Gym_Text_GymStatue_2, MSGBOX_SIGN
	end

CeladonCity_Gym_Text_KaySeen:
	.string "…$"

CeladonCity_Gym_Text_KayBeaten:
	.string "…$"

CeladonCity_Gym_Text_BridgetSeen:
	.string "…$"

CeladonCity_Gym_Text_BridgetBeaten:
	.string "…$"

CeladonCity_Gym_Text_TinaSeen:
	.string "…$"

CeladonCity_Gym_Text_TinaBeaten:
	.string "…$"

CeladonCity_Gym_Text_TamiaSeen:
	.string "…$"

CeladonCity_Gym_Text_TamiaBeaten:
	.string "…$"

CeladonCity_Gym_Text_LoriSeen:
	.string "…$"

CeladonCity_Gym_Text_LoriBeaten:
	.string "…$"

CeladonCity_Gym_Text_LisaSeen:
	.string "…$"

CeladonCity_Gym_Text_LisaBeaten:
	.string "…$"

CeladonCity_Gym_Text_MarySeen:
	.string "…$"

CeladonCity_Gym_Text_MaryBeaten:
	.string "…$"

CeladonCity_Gym_Text_GymStatue:
	.string "I never put much stock in rumors,\nbut two Leagues cleared is two\lLeagues cleared. Impressive.$"

CeladonCity_Gym_Text_GymStatue_2:
	.string "I never put much stock in rumors,\nbut two Leagues cleared is two\lLeagues cleared. Impressive.$"
