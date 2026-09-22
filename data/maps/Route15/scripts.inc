@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

Route15_MapScripts::
	.byte 0

Route15_EventScript_Yazmin::
	trainerbattle_single TRAINER_KANTO_PICNICKER_YAZMIN, Route15_Text_YazminSeen, Route15_Text_YazminBeaten
	msgbox Route15_Text_YazminPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Edwin::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_EDWIN, Route15_Text_EdwinSeen, Route15_Text_EdwinBeaten
	msgbox Route15_Text_EdwinPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Chester::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_CHESTER, Route15_Text_ChesterSeen, Route15_Text_ChesterBeaten
	msgbox Route15_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Kindra::
	trainerbattle_single TRAINER_KANTO_PICNICKER_KINDRA, Route15_Text_KindraSeen, Route15_Text_KindraBeaten
	msgbox Route15_Text_KindraPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Olivia::
	trainerbattle_single TRAINER_KANTO_BEAUTY_OLIVIA, Route15_Text_OliviaSeen, Route15_Text_OliviaBeaten
	msgbox Route15_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Alex::
	trainerbattle_single TRAINER_KANTO_BIKER_ALEX, Route15_Text_AlexSeen, Route15_Text_AlexBeaten
	msgbox Route15_Text_AlexPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Ernest::
	trainerbattle_single TRAINER_KANTO_BIKER_ERNEST, Route15_Text_ErnestSeen, Route15_Text_ErnestBeaten
	msgbox Route15_Text_ErnestPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Becky::
	trainerbattle_single TRAINER_KANTO_PICNICKER_BECKY, Route15_Text_BeckySeen, Route15_Text_BeckyBeaten
	msgbox Route15_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Grace::
	trainerbattle_single TRAINER_KANTO_BEAUTY_GRACE, Route15_Text_GraceSeen, Route15_Text_GraceBeaten
	msgbox Route15_Text_GracePostBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Celia::
	trainerbattle_single TRAINER_KANTO_PICNICKER_CELIA, Route15_Text_CeliaSeen, Route15_Text_CeliaBeaten
	msgbox Route15_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Ron::
	trainerbattle_single TRAINER_KANTO_CRUSH_KIN_RON_MYA, Route15_Text_RonSeen, Route15_Text_RonBeaten
	msgbox Route15_Text_RonPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Mya::
	trainerbattle_single TRAINER_KANTO_CRUSH_KIN_RON_MYA_2, Route15_Text_MyaSeen, Route15_Text_MyaBeaten
	msgbox Route15_Text_MyaPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_RouteSign::
	msgbox Route15_Text_RouteSign, MSGBOX_SIGN
	end

Route15_Text_YazminSeen:
	.string "Want to play with my POKéMON?$"

Route15_Text_YazminBeaten:
	.string "I was too impatient!$"

Route15_Text_YazminPostBattle:
	.string "I'll go train with weaker people.$"

Route15_Text_EdwinSeen:
	.string "When I whistle, I can summon bird\nPOKéMON.$"

Route15_Text_EdwinBeaten:
	.string "Ow!\nThat's tragic!$"

Route15_Text_EdwinPostBattle:
	.string "Maybe I'm not cut out for battles.\nI'm not the right type, I guess.$"

Route15_Text_ChesterSeen:
	.string "Hmm? My birds are shivering!\nYou're good, aren't you?$"

Route15_Text_ChesterBeaten:
	.string "Just as I thought!$"

Route15_Text_ChesterPostBattle:
	.string "This is so obvious, you should know\nthis, but…\pMoves like EARTHQUAKE and FISSURE\nhave no effect on bird POKéMON.$"

Route15_Text_KindraSeen:
	.string "I just got some POKéMON in trades.\nCan I try them out on you?$"

Route15_Text_KindraBeaten:
	.string "Not good enough!$"

Route15_Text_KindraPostBattle:
	.string "You can't change the nickname of\nany POKéMON you get in a trade.\pOnly the Original TRAINER can get\nthe nickname changed.$"

Route15_Text_OliviaSeen:
	.string "I raise POKéMON for protection\nbecause I live alone.$"

Route15_Text_OliviaBeaten:
	.string "POKéMON isn't about winning or\nlosing for me.$"

Route15_Text_OliviaPostBattle:
	.string "I love having my POKéMON greet me\nwhen I get home.\pIt's so reassuring.$"

Route15_Text_AlexSeen:
	.string "Fork over all your cash when you\nlose to me, kid!$"

Route15_Text_AlexBeaten:
	.string "That can't be true!$"

Route15_Text_AlexPostBattle:
	.string "I was just joking about the money.\nDon't take me all serious.$"

Route15_Text_ErnestSeen:
	.string "Hey, kid! C'mon!\nI just got these off some loser!$"

Route15_Text_ErnestBeaten:
	.string "Why not?$"

Route15_Text_ErnestPostBattle:
	.string "Life's too short.\nIt's cool to live as an outlaw.\lTEAM ROCKET RULES!$"

Route15_Text_BeckySeen:
	.string "You look gentle, so I think I can\nbeat you.\pI'll give it a go!$"

Route15_Text_BeckyBeaten:
	.string "No, wrong!$"

Route15_Text_BeckyPostBattle:
	.string "I'm afraid of BIKERS. They look so\nugly and mean!$"

Route15_Text_GraceSeen:
	.string "Oh, you're a little cutie!\nSo like a darling POKéMON!$"

Route15_Text_GraceBeaten:
	.string "You looked so cute, too!$"

Route15_Text_GracePostBattle:
	.string "I forgive you.\nI can take it.\lI'm a big girl now.$"

Route15_Text_CeliaSeen:
	.string "What's cool and happening?\nTrading POKéMON!$"

Route15_Text_CeliaBeaten:
	.string "I said trade!$"

Route15_Text_CeliaPostBattle:
	.string "I trade POKéMON with my friends\nall the time.$"

Route15_Text_RonSeen:
	.string "RON: My sister gets scary when we\nlose.$"

Route15_Text_RonBeaten:
	.string "RON: Oh, no, no…\nSis, I'm sorry!$"

Route15_Text_RonPostBattle:
	.string "RON: Oh, bleah…\nI wish I had a nice sister…$"

Route15_Text_MyaSeen:
	.string "MYA: You're perfect.\nHelp me train my little brother?$"

Route15_Text_MyaBeaten:
	.string "MYA: RON, you have to focus!\nConcentrate on what you're doing!$"

Route15_Text_MyaPostBattle:
	.string "MYA: Okay, we'll turn it up.\nI'll add to our training menu!$"

Route15_Text_RouteSign:
	.string "ROUTE 15\nWest to FUCHSIA CITY$"
