RadioTower3F_MapScripts::
	.byte 0

RadioTower3F_EventScript_GymGuide::
	msgbox RadioTower3F_Text_GymGuide, MSGBOX_NPC
	end

RadioTower3F_EventScript_CooltrainerF::
	msgbox RadioTower3F_Text_CooltrainerF, MSGBOX_NPC
	end

RadioTower3F_EventScript_PersonnelSign::
	msgbox RadioTower3F_Text_PersonnelSign, MSGBOX_SIGN
	end

RadioTower3F_EventScript_PokemonMusicSign::
	msgbox RadioTower3F_Text_PokemonMusicSign, MSGBOX_SIGN
	end

RadioTower3F_Text_GymGuide:
	.string "I've lived in JOHTO my whole life.\nNever thought I'd meet someone\lfrom HOENN way out here.$"

RadioTower3F_Text_CooltrainerF:
	.string "Did you hear? A HOENN trainer\nbecame Champion, and now folks\lhere want to challenge them.$"

RadioTower3F_Text_PersonnelSign:
	.string "3F PERSONNEL$"

RadioTower3F_Text_PokemonMusicSign:
	.string "POKéMON MUSIC with\nHost DJ BEN$"
