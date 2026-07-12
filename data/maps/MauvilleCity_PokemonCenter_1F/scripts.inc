MauvilleCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MauvilleCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
	call Common_EventScript_UpdateBrineyLocation
	goto MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx::
	special SetMauvilleOldManObjEventGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_MAUVILLE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman1::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman2::
	msgbox MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings:
	.string "That man over there, he says weird\n"
	.string "things!\p"
	.string "He's funny in a weird way.\n"
	.string "I doubt I'll forget about him!$"

MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner:
	.string "When I accessed the RECORD CORNER,\n"
	.string "the data for what's hot in DEWFORD\l"
	.string "got updated.\p"
	.string "Now that bit of data is the same\n"
	.string "as my friend's!$"

MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun:
	.string "A RECORD CORNER opened upstairs in\n"
	.string "the POKéMON CENTER.\p"
	.string "I don't know what it's about, but it\n"
	.string "sounds fun. I'll go check it out!$"

MauvilleCity_PokemonCenter_1F_EventScript_BirchAide::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_STARTER_GIFT_A, MauvilleCity_PokemonCenter_1F_EventScript_BirchAideDone
	goto_if_unset FLAG_BADGE03_GET, MauvilleCity_PokemonCenter_1F_EventScript_BirchAideNotYet
	msgbox MauvilleCity_PokemonCenter_1F_Text_BirchAideIntro, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 22
	special GiveChosenTrioLineMate
	copyvar VAR_0x8007, VAR_RESULT
	bufferspeciesname STR_VAR_1, VAR_0x8006
	goto_if_eq VAR_0x8007, MON_CANT_GIVE, MauvilleCity_PokemonCenter_1F_EventScript_BirchAideNoRoom
	playfanfare MUS_OBTAIN_ITEM
	msgbox MauvilleCity_PokemonCenter_1F_Text_BirchAideReceived, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_TRINITY_STARTER_GIFT_A
	goto_if_eq VAR_0x8007, MON_GIVEN_TO_PC, MauvilleCity_PokemonCenter_1F_EventScript_BirchAideToPC
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_BirchAideDone::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BirchAideDone, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_BirchAideToPC::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BirchAideToPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_BirchAideNoRoom::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BirchAideNoRoom, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_BirchAideNotYet::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BirchAideNotYet, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_BirchAideIntro:
	.string "Oh! You must be Prof. Birch's\n"
	.string "trainer! He raised your whole\l"
	.string "starter trio and wanted you to\l"
	.string "have this one.$"

MauvilleCity_PokemonCenter_1F_Text_BirchAideReceived:
	.string "You received {STR_VAR_1}!$"

MauvilleCity_PokemonCenter_1F_Text_BirchAideToPC:
	.string "Your party was full, so it was\n"
	.string "sent to your PC.$"

MauvilleCity_PokemonCenter_1F_Text_BirchAideNoRoom:
	.string "Hm, you've no room for it right\n"
	.string "now. Come back when you do!$"

MauvilleCity_PokemonCenter_1F_Text_BirchAideNotYet:
	.string "Prof. Birch asked me to wait\n"
	.string "for a trainer with three Gym\l"
	.string "Badges. Keep at it!$"

MauvilleCity_PokemonCenter_1F_Text_BirchAideDone:
	.string "Prof. Birch is counting on you.\n"
	.string "Raise that little one well!$"

