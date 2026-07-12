FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FORTREE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Listen, kid, are you working\n"
	.string "on a POKéDEX?\p"
	.string "Hmm… Go to the SAFARI ZONE.\n"
	.string "That's my suggestion.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Have you done anything at\n"
	.string "the RECORD CORNER?\p"
	.string "It's pretty neat. It mixes and matches\n"
	.string "the records of TRAINERS.\p"
	.string "I don't know quite how it works,\n"
	.string "but it's cool. It's exciting, even!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Oh, wow, you have a POKéNAV!\n"
	.string "And it's just like mine!\p"
	.string "Do you know about POKéNAV's\n"
	.string "MATCH CALL system?\p"
	.string "Access it, and you can chat with\n"
	.string "registered TRAINERS anytime.\p"
	.string "It also shows you which TRAINERS\n"
	.string "want a rematch with you.\p"
	.string "It's really nifty! Those DEVON guys\n"
	.string "sure know what they're doing!$"

FortreeCity_PokemonCenter_1F_EventScript_BirchAide::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_STARTER_GIFT_B, FortreeCity_PokemonCenter_1F_EventScript_BirchAideDone
	goto_if_unset FLAG_BADGE06_GET, FortreeCity_PokemonCenter_1F_EventScript_BirchAideNotYet
	msgbox FortreeCity_PokemonCenter_1F_Text_BirchAideIntro, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 32
	special GiveChosenTrioLineMate
	copyvar VAR_0x8007, VAR_RESULT
	bufferspeciesname STR_VAR_1, VAR_0x8006
	goto_if_eq VAR_0x8007, MON_CANT_GIVE, FortreeCity_PokemonCenter_1F_EventScript_BirchAideNoRoom
	playfanfare MUS_OBTAIN_ITEM
	msgbox FortreeCity_PokemonCenter_1F_Text_BirchAideReceived, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_TRINITY_STARTER_GIFT_B
	goto_if_eq VAR_0x8007, MON_GIVEN_TO_PC, FortreeCity_PokemonCenter_1F_EventScript_BirchAideToPC
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_BirchAideDone::
	msgbox FortreeCity_PokemonCenter_1F_Text_BirchAideDone, MSGBOX_DEFAULT
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_BirchAideToPC::
	msgbox FortreeCity_PokemonCenter_1F_Text_BirchAideToPC, MSGBOX_DEFAULT
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_BirchAideNoRoom::
	msgbox FortreeCity_PokemonCenter_1F_Text_BirchAideNoRoom, MSGBOX_DEFAULT
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_BirchAideNotYet::
	msgbox FortreeCity_PokemonCenter_1F_Text_BirchAideNotYet, MSGBOX_DEFAULT
	release
	end

FortreeCity_PokemonCenter_1F_Text_BirchAideIntro:
	.string "There you are! Prof. Birch sent\n"
	.string "me with the last member of your\l"
	.string "starter trio. Take good care of\l"
	.string "it!$"

FortreeCity_PokemonCenter_1F_Text_BirchAideReceived:
	.string "You received {STR_VAR_1}!$"

FortreeCity_PokemonCenter_1F_Text_BirchAideToPC:
	.string "Your party was full, so it was\n"
	.string "sent to your PC.$"

FortreeCity_PokemonCenter_1F_Text_BirchAideNoRoom:
	.string "You've no room for it right now.\n"
	.string "Come find me when you do!$"

FortreeCity_PokemonCenter_1F_Text_BirchAideNotYet:
	.string "Prof. Birch asked me to wait for\n"
	.string "a trainer with six Gym Badges.$"

FortreeCity_PokemonCenter_1F_Text_BirchAideDone:
	.string "That's your whole starter trio\n"
	.string "together now. Prof. Birch will be\l"
	.string "thrilled!$"
