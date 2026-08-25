PewterCity_Gym_MapScripts::
	.byte 0

PewterCity_Gym_EventScript_Liam::
	trainerbattle_single TRAINER_KANTO_CAMPER_LIAM, PewterCity_Gym_Text_LiamSeen, PewterCity_Gym_Text_LiamBeaten
	msgbox PewterCity_Gym_Text_LiamBeaten, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_GymGuy::
	msgbox PewterCity_Gym_Text_GymGuy, MSGBOX_NPC
	end

PewterCity_Gym_EventScript_GymStatue::
	msgbox PewterCity_Gym_Text_GymStatue, MSGBOX_SIGN
	end

PewterCity_Gym_EventScript_GymStatue_2::
	msgbox PewterCity_Gym_Text_GymStatue_2, MSGBOX_SIGN
	end

PewterCity_Gym_Text_LiamSeen:
	.string "…$"

PewterCity_Gym_Text_LiamBeaten:
	.string "…$"

PewterCity_Gym_Text_GymGuy:
	.string "KANTO's peaceful most days, but\neven here we've heard the stories\labout that HOENN trainer.$"

PewterCity_Gym_Text_GymStatue:
	.string "This route's seen more foot traffic\nlately. Something about a champion\lpassing through from JOHTO.$"

PewterCity_Gym_Text_GymStatue_2:
	.string "This route's seen more foot traffic\nlately. Something about a champion\lpassing through from JOHTO.$"
