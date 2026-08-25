SaffronCity_Gym_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_Cameron::
	trainerbattle_single TRAINER_KANTO_PSYCHIC_CAMERON, SaffronCity_Gym_Text_CameronSeen, SaffronCity_Gym_Text_CameronBeaten
	msgbox SaffronCity_Gym_Text_CameronBeaten, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Johan::
	trainerbattle_single TRAINER_KANTO_PSYCHIC_JOHAN, SaffronCity_Gym_Text_JohanSeen, SaffronCity_Gym_Text_JohanBeaten
	msgbox SaffronCity_Gym_Text_JohanBeaten, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_KANTO_PSYCHIC_PRESTON, SaffronCity_Gym_Text_PrestonSeen, SaffronCity_Gym_Text_PrestonBeaten
	msgbox SaffronCity_Gym_Text_PrestonBeaten, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Amanda::
	trainerbattle_single TRAINER_KANTO_CHANNELER_AMANDA, SaffronCity_Gym_Text_AmandaSeen, SaffronCity_Gym_Text_AmandaBeaten
	msgbox SaffronCity_Gym_Text_AmandaBeaten, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Stacy::
	trainerbattle_single TRAINER_KANTO_CHANNELER_STACY, SaffronCity_Gym_Text_StacySeen, SaffronCity_Gym_Text_StacyBeaten
	msgbox SaffronCity_Gym_Text_StacyBeaten, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tasha::
	trainerbattle_single TRAINER_KANTO_CHANNELER_TASHA, SaffronCity_Gym_Text_TashaSeen, SaffronCity_Gym_Text_TashaBeaten
	msgbox SaffronCity_Gym_Text_TashaBeaten, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tyron::
	trainerbattle_single TRAINER_KANTO_PSYCHIC_TYRON, SaffronCity_Gym_Text_TyronSeen, SaffronCity_Gym_Text_TyronBeaten
	msgbox SaffronCity_Gym_Text_TyronBeaten, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_GymGuy::
	msgbox SaffronCity_Gym_Text_GymGuy, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_GymStatue::
	msgbox SaffronCity_Gym_Text_GymStatue, MSGBOX_SIGN
	end

SaffronCity_Gym_EventScript_GymStatue_2::
	msgbox SaffronCity_Gym_Text_GymStatue_2, MSGBOX_SIGN
	end

SaffronCity_Gym_Text_CameronSeen:
	.string "…$"

SaffronCity_Gym_Text_CameronBeaten:
	.string "…$"

SaffronCity_Gym_Text_JohanSeen:
	.string "…$"

SaffronCity_Gym_Text_JohanBeaten:
	.string "…$"

SaffronCity_Gym_Text_PrestonSeen:
	.string "…$"

SaffronCity_Gym_Text_PrestonBeaten:
	.string "…$"

SaffronCity_Gym_Text_AmandaSeen:
	.string "…$"

SaffronCity_Gym_Text_AmandaBeaten:
	.string "…$"

SaffronCity_Gym_Text_StacySeen:
	.string "…$"

SaffronCity_Gym_Text_StacyBeaten:
	.string "…$"

SaffronCity_Gym_Text_TashaSeen:
	.string "…$"

SaffronCity_Gym_Text_TashaBeaten:
	.string "…$"

SaffronCity_Gym_Text_TyronSeen:
	.string "…$"

SaffronCity_Gym_Text_TyronBeaten:
	.string "…$"

SaffronCity_Gym_Text_GymGuy:
	.string "I've fished this stretch of KANTO\nfor years. Lately it's all anyone\ltalks about -- some far-off champion.$"

SaffronCity_Gym_Text_GymStatue:
	.string "This route's seen more foot traffic\nlately. Something about a champion\lpassing through from JOHTO.$"

SaffronCity_Gym_Text_GymStatue_2:
	.string "This route's seen more foot traffic\nlately. Something about a champion\lpassing through from JOHTO.$"
