MtMoon_1F_MapScripts::
	.byte 0

MtMoon_1F_EventScript_Iris::
	trainerbattle_single TRAINER_KANTO_LASS_IRIS, MtMoon_1F_Text_IrisSeen, MtMoon_1F_Text_IrisBeaten
	msgbox MtMoon_1F_Text_IrisBeaten, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Robby::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_ROBBY, MtMoon_1F_Text_RobbySeen, MtMoon_1F_Text_RobbyBeaten
	msgbox MtMoon_1F_Text_RobbyBeaten, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Jovan::
	trainerbattle_single TRAINER_KANTO_SUPER_NERD_JOVAN, MtMoon_1F_Text_JovanSeen, MtMoon_1F_Text_JovanBeaten
	msgbox MtMoon_1F_Text_JovanBeaten, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Miriam::
	trainerbattle_single TRAINER_KANTO_LASS_MIRIAM, MtMoon_1F_Text_MiriamSeen, MtMoon_1F_Text_MiriamBeaten
	msgbox MtMoon_1F_Text_MiriamBeaten, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Kent::
	trainerbattle_single TRAINER_KANTO_BUG_CATCHER_KENT, MtMoon_1F_Text_KentSeen, MtMoon_1F_Text_KentBeaten
	msgbox MtMoon_1F_Text_KentBeaten, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Josh::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_JOSH, MtMoon_1F_Text_JoshSeen, MtMoon_1F_Text_JoshBeaten
	msgbox MtMoon_1F_Text_JoshBeaten, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_Marcos::
	trainerbattle_single TRAINER_KANTO_HIKER_MARCOS, MtMoon_1F_Text_MarcosSeen, MtMoon_1F_Text_MarcosBeaten
	msgbox MtMoon_1F_Text_MarcosBeaten, MSGBOX_AUTOCLOSE
	end

MtMoon_1F_EventScript_ZubatSign::
	msgbox MtMoon_1F_Text_ZubatSign, MSGBOX_SIGN
	end

MtMoon_1F_Text_IrisSeen:
	.string "…$"

MtMoon_1F_Text_IrisBeaten:
	.string "…$"

MtMoon_1F_Text_RobbySeen:
	.string "…$"

MtMoon_1F_Text_RobbyBeaten:
	.string "…$"

MtMoon_1F_Text_JovanSeen:
	.string "…$"

MtMoon_1F_Text_JovanBeaten:
	.string "…$"

MtMoon_1F_Text_MiriamSeen:
	.string "…$"

MtMoon_1F_Text_MiriamBeaten:
	.string "…$"

MtMoon_1F_Text_KentSeen:
	.string "…$"

MtMoon_1F_Text_KentBeaten:
	.string "…$"

MtMoon_1F_Text_JoshSeen:
	.string "…$"

MtMoon_1F_Text_JoshBeaten:
	.string "…$"

MtMoon_1F_Text_MarcosSeen:
	.string "…$"

MtMoon_1F_Text_MarcosBeaten:
	.string "…$"

MtMoon_1F_Text_ZubatSign:
	.string "Beware!\nZUBAT is a bloodsucker!$"
