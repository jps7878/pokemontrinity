SilphCo_7F_MapScripts::
	.byte 0

SilphCo_7F_EventScript_LaprasGuy::
	msgbox SilphCo_7F_Text_LaprasGuy, MSGBOX_NPC
	end

SilphCo_7F_EventScript_WorkerF::
	msgbox SilphCo_7F_Text_WorkerF, MSGBOX_NPC
	end

SilphCo_7F_EventScript_WorkerM1::
	msgbox SilphCo_7F_Text_WorkerM1, MSGBOX_NPC
	end

SilphCo_7F_EventScript_WorkerM2::
	msgbox SilphCo_7F_Text_WorkerM2, MSGBOX_NPC
	end

SilphCo_7F_EventScript_Joshua::
	trainerbattle_single TRAINER_KANTO_SCIENTIST_JOSHUA, SilphCo_7F_Text_JoshuaSeen, SilphCo_7F_Text_JoshuaBeaten
	msgbox SilphCo_7F_Text_JoshuaBeaten, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_FloorSign::
	msgbox SilphCo_7F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_7F_Text_LaprasGuy:
	.string "KANTO's a long way from HOENN,\nbut word of that champion still\lmade it all the way here.$"

SilphCo_7F_Text_WorkerF:
	.string "This route's seen more foot traffic\nlately. Something about a champion\lpassing through from JOHTO.$"

SilphCo_7F_Text_WorkerM1:
	.string "I never put much stock in rumors,\nbut two Leagues cleared is two\lLeagues cleared. Impressive.$"

SilphCo_7F_Text_WorkerM2:
	.string "I never put much stock in rumors,\nbut two Leagues cleared is two\lLeagues cleared. Impressive.$"

SilphCo_7F_Text_JoshuaSeen:
	.string "…$"

SilphCo_7F_Text_JoshuaBeaten:
	.string "…$"

SilphCo_7F_Text_FloorSign:
	.string "SILPH CO. HEAD OFFICE\n7F$"
