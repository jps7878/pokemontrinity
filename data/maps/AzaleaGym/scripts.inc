AzaleaGym_MapScripts::
	.byte 0

AzaleaGym_EventScript_BUG_CATCHER_BENNY::
	trainerbattle_single TRAINER_JOHTO_BUG_CATCHER_BUG_CATCHER_BENNY, AzaleaGym_Text_BUG_CATCHER_BENNYSeen, AzaleaGym_Text_BUG_CATCHER_BENNYBeaten
	msgbox AzaleaGym_Text_BUG_CATCHER_BENNYBeaten, MSGBOX_AUTOCLOSE
	end

AzaleaGym_EventScript_AL::
	trainerbattle_single TRAINER_JOHTO_BUG_CATCHER_AL, AzaleaGym_Text_ALSeen, AzaleaGym_Text_ALBeaten
	msgbox AzaleaGym_Text_ALBeaten, MSGBOX_AUTOCLOSE
	end

AzaleaGym_EventScript_JOSH::
	trainerbattle_single TRAINER_JOHTO_BUG_CATCHER_JOSH, AzaleaGym_Text_JOSHSeen, AzaleaGym_Text_JOSHBeaten
	msgbox AzaleaGym_Text_JOSHBeaten, MSGBOX_AUTOCLOSE
	end

AzaleaGym_EventScript_AMYANDMAY1::
	trainerbattle_single TRAINER_JOHTO_TWINS_AMYANDMAY1, AzaleaGym_Text_AMYANDMAY1Seen, AzaleaGym_Text_AMYANDMAY1Beaten
	msgbox AzaleaGym_Text_AMYANDMAY1Beaten, MSGBOX_AUTOCLOSE
	end

AzaleaGym_EventScript_AMYANDMAY2::
	trainerbattle_single TRAINER_JOHTO_TWINS_AMYANDMAY2, AzaleaGym_Text_AMYANDMAY2Seen, AzaleaGym_Text_AMYANDMAY2Beaten
	msgbox AzaleaGym_Text_AMYANDMAY2Beaten, MSGBOX_AUTOCLOSE
	end

AzaleaGym_EventScript_Guide::
	msgbox AzaleaGym_Text_Guide, MSGBOX_NPC
	end

AzaleaGym_Text_BUG_CATCHER_BENNYSeen:
	.string "Bug POKéMON evolve\nyoung. So they get\pstronger that much\nfaster.$"

AzaleaGym_Text_BUG_CATCHER_BENNYBeaten:
	.string "Just evolving\nisn't enough!$"

AzaleaGym_Text_ALSeen:
	.string "Bug POKéMON are\ncool and tough!\pI'll prove it to\nyou!$"

AzaleaGym_Text_ALBeaten:
	.string "You proved how\ntough you are…$"

AzaleaGym_Text_JOSHSeen:
	.string "You saved all the\nSLOWPOKE? Whew,\lyou're mighty!\pBut my grown-up\nPOKéMON are pretty\ltough too!$"

AzaleaGym_Text_JOSHBeaten:
	.string "Urrgggh!$"

AzaleaGym_Text_AMYANDMAY1Seen:
	.string "AMY: Hi! Are you\nchallenging the\lLEADER? No way!$"

AzaleaGym_Text_AMYANDMAY1Beaten:
	.string "AMY & MAY: Oh,\ndouble goodness!$"

AzaleaGym_Text_AMYANDMAY2Seen:
	.string "MAY: You want to\nsee the LEADER?\lWe come first!$"

AzaleaGym_Text_AMYANDMAY2Beaten:
	.string "AMY & MAY: Oh,\ndouble goodness!$"

AzaleaGym_Text_Guide:
	.string "The old timers say JOHTO used to\nfeel far from everywhere. Not\lanymore, with HOENN so close now.$"
