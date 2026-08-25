Route11_MapScripts::
	.byte 0

Route11_EventScript_Eddie::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_EDDIE, Route11_Text_EddieSeen, Route11_Text_EddieBeaten
	msgbox Route11_Text_EddieBeaten, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Hugo::
	trainerbattle_single TRAINER_KANTO_GAMER_HUGO, Route11_Text_HugoSeen, Route11_Text_HugoBeaten
	msgbox Route11_Text_HugoBeaten, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Dillon::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_DILLON, Route11_Text_DillonSeen, Route11_Text_DillonBeaten
	msgbox Route11_Text_DillonBeaten, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Dave::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_DAVE, Route11_Text_DaveSeen, Route11_Text_DaveBeaten
	msgbox Route11_Text_DaveBeaten, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Jasper::
	trainerbattle_single TRAINER_KANTO_GAMER_JASPER, Route11_Text_JasperSeen, Route11_Text_JasperBeaten
	msgbox Route11_Text_JasperBeaten, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Darian::
	trainerbattle_single TRAINER_KANTO_GAMER_DARIAN, Route11_Text_DarianSeen, Route11_Text_DarianBeaten
	msgbox Route11_Text_DarianBeaten, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Braxton::
	trainerbattle_single TRAINER_KANTO_ENGINEER_BRAXTON, Route11_Text_BraxtonSeen, Route11_Text_BraxtonBeaten
	msgbox Route11_Text_BraxtonBeaten, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Yasu::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_YASU, Route11_Text_YasuSeen, Route11_Text_YasuBeaten
	msgbox Route11_Text_YasuBeaten, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Dirk::
	trainerbattle_single TRAINER_KANTO_GAMER_DIRK, Route11_Text_DirkSeen, Route11_Text_DirkBeaten
	msgbox Route11_Text_DirkBeaten, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Bernie::
	trainerbattle_single TRAINER_KANTO_ENGINEER_BERNIE, Route11_Text_BernieSeen, Route11_Text_BernieBeaten
	msgbox Route11_Text_BernieBeaten, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_DiglettsCaveSign::
	msgbox Route11_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

Route11_Text_EddieSeen:
	.string "…$"

Route11_Text_EddieBeaten:
	.string "…$"

Route11_Text_HugoSeen:
	.string "…$"

Route11_Text_HugoBeaten:
	.string "…$"

Route11_Text_DillonSeen:
	.string "…$"

Route11_Text_DillonBeaten:
	.string "…$"

Route11_Text_DaveSeen:
	.string "…$"

Route11_Text_DaveBeaten:
	.string "…$"

Route11_Text_JasperSeen:
	.string "…$"

Route11_Text_JasperBeaten:
	.string "…$"

Route11_Text_DarianSeen:
	.string "…$"

Route11_Text_DarianBeaten:
	.string "…$"

Route11_Text_BraxtonSeen:
	.string "…$"

Route11_Text_BraxtonBeaten:
	.string "…$"

Route11_Text_YasuSeen:
	.string "…$"

Route11_Text_YasuBeaten:
	.string "…$"

Route11_Text_DirkSeen:
	.string "…$"

Route11_Text_DirkBeaten:
	.string "…$"

Route11_Text_BernieSeen:
	.string "…$"

Route11_Text_BernieBeaten:
	.string "…$"

Route11_Text_DiglettsCaveSign:
	.string "DIGLETT'S CAVE$"
