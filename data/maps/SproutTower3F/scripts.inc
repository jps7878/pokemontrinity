SproutTower3F_MapScripts::
	.byte 0

SproutTower3F_EventScript_JIN::
	trainerbattle_single TRAINER_JOHTO_SAGE_JIN, SproutTower3F_Text_JINSeen, SproutTower3F_Text_JINBeaten
	msgbox SproutTower3F_Text_JINBeaten, MSGBOX_AUTOCLOSE
	end

SproutTower3F_EventScript_TROY::
	trainerbattle_single TRAINER_JOHTO_SAGE_TROY, SproutTower3F_Text_TROYSeen, SproutTower3F_Text_TROYBeaten
	msgbox SproutTower3F_Text_TROYBeaten, MSGBOX_AUTOCLOSE
	end

SproutTower3F_EventScript_SageLi::
	msgbox SproutTower3F_Text_SageLi, MSGBOX_NPC
	end

SproutTower3F_EventScript_NEAL::
	trainerbattle_single TRAINER_JOHTO_SAGE_NEAL, SproutTower3F_Text_NEALSeen, SproutTower3F_Text_NEALBeaten
	msgbox SproutTower3F_Text_NEALBeaten, MSGBOX_AUTOCLOSE
	end

SproutTower3F_EventScript_Statue::
	msgbox SproutTower3F_Text_Statue, MSGBOX_SIGN
	end

SproutTower3F_EventScript_Statue_2::
	msgbox SproutTower3F_Text_Statue_2, MSGBOX_SIGN
	end

SproutTower3F_EventScript_Painting::
	msgbox SproutTower3F_Text_Painting, MSGBOX_SIGN
	end

SproutTower3F_EventScript_Painting_2::
	msgbox SproutTower3F_Text_Painting_2, MSGBOX_SIGN
	end

SproutTower3F_EventScript_Statue_3::
	msgbox SproutTower3F_Text_Statue_3, MSGBOX_SIGN
	end

SproutTower3F_EventScript_Statue_4::
	msgbox SproutTower3F_Text_Statue_4, MSGBOX_SIGN
	end

SproutTower3F_Text_JINSeen:
	.string "I train to find\nenlightenment in\lPOKéMON!$"

SproutTower3F_Text_JINBeaten:
	.string "My training is\nincomplete…$"

SproutTower3F_Text_TROYSeen:
	.string "Let me see how\nmuch you trust\lyour POKéMON.$"

SproutTower3F_Text_TROYBeaten:
	.string "Yes, your trust is\nreal!$"

SproutTower3F_Text_SageLi:
	.string "This route sure gets more foot\ntraffic now that HOENN trainers\lkeep showing up.$"

SproutTower3F_Text_NEALSeen:
	.string "The ELDER's HM\nlights even pitch-\lblack darkness.$"

SproutTower3F_Text_NEALBeaten:
	.string "It is my head that\nis bright!$"

SproutTower3F_Text_Statue:
	.string "A POKéMON statue…\pIt looks very\ndistinguished.$"

SproutTower3F_Text_Statue_2:
	.string "A POKéMON statue…\pIt looks very\ndistinguished.$"

SproutTower3F_Text_Painting:
	.string "It's a powerful\npainting of a\lBELLSPROUT.$"

SproutTower3F_Text_Painting_2:
	.string "It's a powerful\npainting of a\lBELLSPROUT.$"

SproutTower3F_Text_Statue_3:
	.string "A POKéMON statue…\pIt looks very\ndistinguished.$"

SproutTower3F_Text_Statue_4:
	.string "A POKéMON statue…\pIt looks very\ndistinguished.$"
