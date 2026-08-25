Route12_FishingHouse_MapScripts::
	.byte 0

Route12_FishingHouse_EventScript_FishingGuruBrother::
	msgbox Route12_FishingHouse_Text_FishingGuruBrother, MSGBOX_NPC
	end

Route12_FishingHouse_EventScript_MagikarpRecordSign::
	msgbox Route12_FishingHouse_Text_MagikarpRecordSign, MSGBOX_SIGN
	end

Route12_FishingHouse_Text_FishingGuruBrother:
	.string "KANTO's peaceful most days, but\neven here we've heard the stories\labout that HOENN trainer.$"

Route12_FishingHouse_Text_MagikarpRecordSign:
	.string "I never put much stock in rumors,\nbut two Leagues cleared is two\lLeagues cleared. Impressive.$"
