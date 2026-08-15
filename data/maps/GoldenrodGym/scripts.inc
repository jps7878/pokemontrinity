GoldenrodGym_MapScripts::
	.byte 0

GoldenrodGym_EventScript_CARRIE::
	trainerbattle_single TRAINER_JOHTO_LASS_CARRIE, GoldenrodGym_Text_CARRIESeen, GoldenrodGym_Text_CARRIEBeaten
	msgbox GoldenrodGym_Text_CARRIEBeaten, MSGBOX_AUTOCLOSE
	end

GoldenrodGym_EventScript_BRIDGET::
	trainerbattle_single TRAINER_JOHTO_LASS_BRIDGET, GoldenrodGym_Text_BRIDGETSeen, GoldenrodGym_Text_BRIDGETBeaten
	msgbox GoldenrodGym_Text_BRIDGETBeaten, MSGBOX_AUTOCLOSE
	end

GoldenrodGym_EventScript_VICTORIA::
	trainerbattle_single TRAINER_JOHTO_BEAUTY_VICTORIA, GoldenrodGym_Text_VICTORIASeen, GoldenrodGym_Text_VICTORIABeaten
	msgbox GoldenrodGym_Text_VICTORIABeaten, MSGBOX_AUTOCLOSE
	end

GoldenrodGym_EventScript_SAMANTHA::
	trainerbattle_single TRAINER_JOHTO_BEAUTY_SAMANTHA, GoldenrodGym_Text_SAMANTHASeen, GoldenrodGym_Text_SAMANTHABeaten
	msgbox GoldenrodGym_Text_SAMANTHABeaten, MSGBOX_AUTOCLOSE
	end

GoldenrodGym_EventScript_Guide::
	msgbox GoldenrodGym_Text_Guide, MSGBOX_NPC
	end

GoldenrodGym_Text_CARRIESeen:
	.string "Don't let my\nPOKéMON's cute\plooks fool you.\nThey can whip you!$"

GoldenrodGym_Text_CARRIEBeaten:
	.string "Darn… I thought\nyou were weak…$"

GoldenrodGym_Text_BRIDGETSeen:
	.string "I like cute POKé-\nMON better than\lstrong POKéMON.\pBut I have strong\nand cute POKéMON!$"

GoldenrodGym_Text_BRIDGETBeaten:
	.string "Oh, no, no, no!$"

GoldenrodGym_Text_VICTORIASeen:
	.string "Oh, you are a cute\nlittle trainer! \pI like you, but I\nwon't hold back!$"

GoldenrodGym_Text_VICTORIABeaten:
	.string "Let's see… Oops,\nit's over?$"

GoldenrodGym_Text_SAMANTHASeen:
	.string "Give it your best\nshot, or I'll take\lyou down!$"

GoldenrodGym_Text_SAMANTHABeaten:
	.string "No! Oh, MEOWTH,\nI'm so sorry!$"

GoldenrodGym_Text_Guide:
	.string "My grandkids won't stop talking\nabout the new champion from over\lin HOENN. Kids these days!$"
