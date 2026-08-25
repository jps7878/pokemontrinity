CeruleanCity_Gym_MapScripts::
	.byte 0

CeruleanCity_Gym_EventScript_Luis::
	trainerbattle_single TRAINER_KANTO_SWIMMER_M_LUIS, CeruleanCity_Gym_Text_LuisSeen, CeruleanCity_Gym_Text_LuisBeaten
	msgbox CeruleanCity_Gym_Text_LuisBeaten, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_Diana::
	trainerbattle_single TRAINER_KANTO_PICNICKER_DIANA, CeruleanCity_Gym_Text_DianaSeen, CeruleanCity_Gym_Text_DianaBeaten
	msgbox CeruleanCity_Gym_Text_DianaBeaten, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_GymGuy::
	msgbox CeruleanCity_Gym_Text_GymGuy, MSGBOX_NPC
	end

CeruleanCity_Gym_EventScript_GymStatue::
	msgbox CeruleanCity_Gym_Text_GymStatue, MSGBOX_SIGN
	end

CeruleanCity_Gym_EventScript_GymStatue_2::
	msgbox CeruleanCity_Gym_Text_GymStatue_2, MSGBOX_SIGN
	end

CeruleanCity_Gym_Text_LuisSeen:
	.string "…$"

CeruleanCity_Gym_Text_LuisBeaten:
	.string "…$"

CeruleanCity_Gym_Text_DianaSeen:
	.string "…$"

CeruleanCity_Gym_Text_DianaBeaten:
	.string "…$"

CeruleanCity_Gym_Text_GymGuy:
	.string "Never met the champion myself.\nHeard they came up through HOENN\land JOHTO before setting foot here.$"

CeruleanCity_Gym_Text_GymStatue:
	.string "KANTO's a long way from HOENN,\nbut word of that champion still\lmade it all the way here.$"

CeruleanCity_Gym_Text_GymStatue_2:
	.string "KANTO's a long way from HOENN,\nbut word of that champion still\lmade it all the way here.$"
