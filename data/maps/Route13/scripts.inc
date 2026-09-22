@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

Route13_MapScripts::
	.byte 0

Route13_EventScript_Alma::
	trainerbattle_single TRAINER_KANTO_PICNICKER_ALMA, Route13_Text_AlmaSeen, Route13_Text_AlmaBeaten
	msgbox Route13_Text_AlmaPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Sebastian::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_SEBASTIAN, Route13_Text_SebastianSeen, Route13_Text_SebastianBeaten
	msgbox Route13_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Susie::
	trainerbattle_single TRAINER_KANTO_PICNICKER_SUSIE, Route13_Text_SusieSeen, Route13_Text_SusieBeaten
	msgbox Route13_Text_SusiePostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Sheila::
	trainerbattle_single TRAINER_KANTO_BEAUTY_SHEILA, Route13_Text_SheilaSeen, Route13_Text_SheilaBeaten
	msgbox Route13_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Lola::
	trainerbattle_single TRAINER_KANTO_BEAUTY_LOLA, Route13_Text_LolaSeen, Route13_Text_LolaBeaten
	msgbox Route13_Text_LolaPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Valerie::
	trainerbattle_single TRAINER_KANTO_PICNICKER_VALERIE, Route13_Text_ValerieSeen, Route13_Text_ValerieBeaten
	msgbox Route13_Text_ValeriePostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Gwen::
	trainerbattle_single TRAINER_KANTO_PICNICKER_GWEN, Route13_Text_GwenSeen, Route13_Text_GwenBeaten
	msgbox Route13_Text_GwenPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Robert::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_ROBERT, Route13_Text_RobertSeen, Route13_Text_RobertBeaten
	msgbox Route13_Text_RobertPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Perry::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_PERRY, Route13_Text_PerrySeen, Route13_Text_PerryBeaten
	msgbox Route13_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Jared::
	trainerbattle_single TRAINER_KANTO_BIKER_JARED, Route13_Text_JaredSeen, Route13_Text_JaredBeaten
	msgbox Route13_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_RouteSign::
	msgbox Route13_Text_RouteSign, MSGBOX_SIGN
	end

Route13_EventScript_TrainerTips2::
	msgbox Route13_Text_TrainerTips2, MSGBOX_SIGN
	end

Route13_EventScript_TrainerTips1::
	msgbox Route13_Text_TrainerTips1, MSGBOX_SIGN
	end

Route13_Text_AlmaSeen:
	.string "I found CARBOS in a cave once\nwhile I was spelunking.$"

Route13_Text_AlmaBeaten:
	.string "Oh, too bad!\nI just messed up!$"

Route13_Text_AlmaPostBattle:
	.string "CARBOS boosted the SPEED of my\nPOKéMON.$"

Route13_Text_SebastianSeen:
	.string "My bird POKéMON want to battle\nwith you!$"

Route13_Text_SebastianBeaten:
	.string "My PIDGEY and PIDGEOTTO combo\nlost?$"

Route13_Text_SebastianPostBattle:
	.string "My POKéMON look happy even though\nthey lost.$"

Route13_Text_SusieSeen:
	.string "I'm told I'm good for a kid.$"

Route13_Text_SusieBeaten:
	.string "Ohh!\nI lost!$"

Route13_Text_SusiePostBattle:
	.string "I want to become a good TRAINER.\nI'll train hard, just watch.$"

Route13_Text_SheilaSeen:
	.string "Do you want to battle some\nPOKéMON with me?$"

Route13_Text_SheilaBeaten:
	.string "It's over already?$"

Route13_Text_SheilaPostBattle:
	.string "I don't know anything about\nPOKéMON actually.\pThe ones I use… I picked them\nfor their looks!$"

Route13_Text_LolaSeen:
	.string "Sure, I'll play with you, sweetie.$"

Route13_Text_LolaBeaten:
	.string "Oh!\nYou little beast!$"

Route13_Text_LolaPostBattle:
	.string "I wonder which is stronger, male or\nfemale POKéMON?$"

Route13_Text_ValerieSeen:
	.string "Wow!\nYour BADGES are too cool!$"

Route13_Text_ValerieBeaten:
	.string "Not enough!$"

Route13_Text_ValeriePostBattle:
	.string "You got those BADGES from GYM\nLEADERS. I know!$"

Route13_Text_GwenSeen:
	.string "My cute POKéMON wish to make your\nacquaintance.$"

Route13_Text_GwenBeaten:
	.string "Good going!\nYou totally won!$"

Route13_Text_GwenPostBattle:
	.string "You have to make POKéMON battle\nto toughen them up.$"

Route13_Text_RobertSeen:
	.string "I always go with bird POKéMON.\nI've dedicated myself to them.$"

Route13_Text_RobertBeaten:
	.string "Out of power!$"

Route13_Text_RobertPostBattle:
	.string "I wish I could fly like PIDGEY and\nPIDGEOTTO…$"

Route13_Text_PerrySeen:
	.string "I'm not going to lose.\nNot when the wind's blowing my way!$"

Route13_Text_PerryBeaten:
	.string "The wind turned!$"

Route13_Text_PerryPostBattle:
	.string "I'm beat.\nI guess I'll FLY home.$"

Route13_Text_JaredSeen:
	.string "What're you lookin' at?$"

Route13_Text_JaredBeaten:
	.string "Dang!\nStripped gears!$"

Route13_Text_JaredPostBattle:
	.string "Get lost!$"

Route13_Text_RouteSign:
	.string "ROUTE 13\nNorth to SILENCE BRIDGE$"

Route13_Text_TrainerTips2:
	.string "TRAINER TIPS\pUse SELECT to switch items in the\nITEMS window.$"

Route13_Text_TrainerTips1:
	.string "TRAINER TIPS\pLook, look!\nLook to the left of that post!$"
