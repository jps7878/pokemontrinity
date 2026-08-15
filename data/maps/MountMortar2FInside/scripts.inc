MountMortar2FInside_MapScripts::
	.byte 0

MountMortar2FInside_EventScript_HUGH::
	trainerbattle_single TRAINER_JOHTO_SUPER_NERD_HUGH, MountMortar2FInside_Text_HUGHSeen, MountMortar2FInside_Text_HUGHBeaten
	msgbox MountMortar2FInside_Text_HUGHBeaten, MSGBOX_AUTOCLOSE
	end

MountMortar2FInside_Text_HUGHSeen:
	.string "Yo! MARKUS!$"

MountMortar2FInside_Text_HUGHBeaten:
	.string "Sorry, my mistake.$"
