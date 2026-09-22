Route12_FishingHouse_MapScripts::
	.byte 0

Route12_FishingHouse_EventScript_FishingGuruBrother::
	msgbox Route12_FishingHouse_Text_FishingGuruBrother, MSGBOX_NPC
	end

Route12_FishingHouse_EventScript_MagikarpRecordSign::
	msgbox Route12_FishingHouse_Text_MagikarpRecordSign, MSGBOX_SIGN
	end

Route12_FishingHouse_Text_FishingGuruBrother:
	.string "I've fished this stretch of KANTO\nfor years. Lately the talk is all\labout some far-off champion.$"

Route12_FishingHouse_Text_MagikarpRecordSign:
	.string "It's a blank chart of some sort.\pIt has spaces for writing in\nrecords of some kind.$"
