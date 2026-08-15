MountMortar1FInside_MapScripts::
	.byte 0

MountMortar1FInside_EventScript_MILLER::
	trainerbattle_single TRAINER_JOHTO_POKEMANIAC_MILLER, MountMortar1FInside_Text_MILLERSeen, MountMortar1FInside_Text_MILLERBeaten
	msgbox MountMortar1FInside_Text_MILLERBeaten, MSGBOX_AUTOCLOSE
	end

MountMortar1FInside_EventScript_MARKUS::
	trainerbattle_single TRAINER_JOHTO_SUPER_NERD_MARKUS, MountMortar1FInside_Text_MARKUSSeen, MountMortar1FInside_Text_MARKUSBeaten
	msgbox MountMortar1FInside_Text_MARKUSBeaten, MSGBOX_AUTOCLOSE
	end

MountMortar1FInside_Text_MILLERSeen:
	.string "I'm not losing\nthis time!$"

MountMortar1FInside_Text_MILLERBeaten:
	.string "I lost to some\nkid…?$"

MountMortar1FInside_Text_MARKUSSeen:
	.string "Hey! HUGH!$"

MountMortar1FInside_Text_MARKUSBeaten:
	.string "I mistook you for\nsomeone else…$"
