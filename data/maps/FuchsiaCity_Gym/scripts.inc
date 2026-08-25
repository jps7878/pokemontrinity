FuchsiaCity_Gym_MapScripts::
	.byte 0

FuchsiaCity_Gym_EventScript_Kayden::
	trainerbattle_single TRAINER_KANTO_JUGGLER_KAYDEN, FuchsiaCity_Gym_Text_KaydenSeen, FuchsiaCity_Gym_Text_KaydenBeaten
	msgbox FuchsiaCity_Gym_Text_KaydenBeaten, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_KANTO_JUGGLER_SHAWN, FuchsiaCity_Gym_Text_ShawnSeen, FuchsiaCity_Gym_Text_ShawnBeaten
	msgbox FuchsiaCity_Gym_Text_ShawnBeaten, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KANTO_JUGGLER_KIRK, FuchsiaCity_Gym_Text_KirkSeen, FuchsiaCity_Gym_Text_KirkBeaten
	msgbox FuchsiaCity_Gym_Text_KirkBeaten, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Edgar::
	trainerbattle_single TRAINER_KANTO_TAMER_EDGAR, FuchsiaCity_Gym_Text_EdgarSeen, FuchsiaCity_Gym_Text_EdgarBeaten
	msgbox FuchsiaCity_Gym_Text_EdgarBeaten, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Phil::
	trainerbattle_single TRAINER_KANTO_TAMER_PHIL, FuchsiaCity_Gym_Text_PhilSeen, FuchsiaCity_Gym_Text_PhilBeaten
	msgbox FuchsiaCity_Gym_Text_PhilBeaten, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_KANTO_JUGGLER_NATE, FuchsiaCity_Gym_Text_NateSeen, FuchsiaCity_Gym_Text_NateBeaten
	msgbox FuchsiaCity_Gym_Text_NateBeaten, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_GymGuy::
	msgbox FuchsiaCity_Gym_Text_GymGuy, MSGBOX_NPC
	end

FuchsiaCity_Gym_EventScript_GymStatue::
	msgbox FuchsiaCity_Gym_Text_GymStatue, MSGBOX_SIGN
	end

FuchsiaCity_Gym_EventScript_GymStatue_2::
	msgbox FuchsiaCity_Gym_Text_GymStatue_2, MSGBOX_SIGN
	end

FuchsiaCity_Gym_Text_KaydenSeen:
	.string "…$"

FuchsiaCity_Gym_Text_KaydenBeaten:
	.string "…$"

FuchsiaCity_Gym_Text_ShawnSeen:
	.string "…$"

FuchsiaCity_Gym_Text_ShawnBeaten:
	.string "…$"

FuchsiaCity_Gym_Text_KirkSeen:
	.string "…$"

FuchsiaCity_Gym_Text_KirkBeaten:
	.string "…$"

FuchsiaCity_Gym_Text_EdgarSeen:
	.string "…$"

FuchsiaCity_Gym_Text_EdgarBeaten:
	.string "…$"

FuchsiaCity_Gym_Text_PhilSeen:
	.string "…$"

FuchsiaCity_Gym_Text_PhilBeaten:
	.string "…$"

FuchsiaCity_Gym_Text_NateSeen:
	.string "…$"

FuchsiaCity_Gym_Text_NateBeaten:
	.string "…$"

FuchsiaCity_Gym_Text_GymGuy:
	.string "I never put much stock in rumors,\nbut two Leagues cleared is two\lLeagues cleared. Impressive.$"

FuchsiaCity_Gym_Text_GymStatue:
	.string "They say a trainer beat both the\nHOENN and JOHTO Leagues. Wonder\lif they'll try KANTO next.$"

FuchsiaCity_Gym_Text_GymStatue_2:
	.string "They say a trainer beat both the\nHOENN and JOHTO Leagues. Wonder\lif they'll try KANTO next.$"
