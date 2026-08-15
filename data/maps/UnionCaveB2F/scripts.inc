UnionCaveB2F_MapScripts::
	.byte 0

UnionCaveB2F_EventScript_NICK::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERM_NICK, UnionCaveB2F_Text_NICKSeen, UnionCaveB2F_Text_NICKBeaten
	msgbox UnionCaveB2F_Text_NICKBeaten, MSGBOX_AUTOCLOSE
	end

UnionCaveB2F_EventScript_GWEN::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_GWEN, UnionCaveB2F_Text_GWENSeen, UnionCaveB2F_Text_GWENBeaten
	msgbox UnionCaveB2F_Text_GWENBeaten, MSGBOX_AUTOCLOSE
	end

UnionCaveB2F_EventScript_EMMA::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_EMMA, UnionCaveB2F_Text_EMMASeen, UnionCaveB2F_Text_EMMABeaten
	msgbox UnionCaveB2F_Text_EMMABeaten, MSGBOX_AUTOCLOSE
	end

UnionCaveB2F_Text_NICKSeen:
	.string "There are two\nkinds of people.\pThose who have\nstyle, and those\lwho don't.\pWhat kind of\nperson are you?$"

UnionCaveB2F_Text_NICKBeaten:
	.string "You've got\ndazzling style!$"

UnionCaveB2F_Text_GWENSeen:
	.string "I'm in training.\nCare for a round?$"

UnionCaveB2F_Text_GWENBeaten:
	.string "Aww, no! You're\ntoo good for me.$"

UnionCaveB2F_Text_EMMASeen:
	.string "If the POKéMON I\nliked were there,\lI'd go anywhere.\pThat's what a real\ntrainer does.$"

UnionCaveB2F_Text_EMMABeaten:
	.string "I'd rather pet my\nbabies than this!$"
