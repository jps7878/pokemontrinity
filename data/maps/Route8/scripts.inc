@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

Route8_MapScripts::
	.byte 0

Route8_EventScript_Julia::
	trainerbattle_single TRAINER_KANTO_LASS_JULIA, Route8_Text_JuliaSeen, Route8_Text_JuliaBeaten
	msgbox Route8_Text_JuliaPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Rich::
	trainerbattle_single TRAINER_KANTO_GAMER_RICH, Route8_Text_RichSeen, Route8_Text_RichBeaten
	msgbox Route8_Text_RichPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Glenn::
	trainerbattle_single TRAINER_KANTO_SUPER_NERD_GLENN, Route8_Text_GlennSeen, Route8_Text_GlennBeaten
	msgbox Route8_Text_GlennPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Paige::
	trainerbattle_single TRAINER_KANTO_LASS_PAIGE, Route8_Text_PaigeSeen, Route8_Text_PaigeBeaten
	msgbox Route8_Text_PaigePostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Leslie::
	trainerbattle_single TRAINER_KANTO_SUPER_NERD_LESLIE, Route8_Text_LeslieSeen, Route8_Text_LeslieBeaten
	msgbox Route8_Text_LesliePostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Andrea::
	trainerbattle_single TRAINER_KANTO_LASS_ANDREA, Route8_Text_AndreaSeen, Route8_Text_AndreaBeaten
	msgbox Route8_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Megan::
	trainerbattle_single TRAINER_KANTO_LASS_MEGAN, Route8_Text_MeganSeen, Route8_Text_MeganBeaten
	msgbox Route8_Text_MeganPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Stan::
	trainerbattle_single TRAINER_KANTO_GAMER_STAN, Route8_Text_StanSeen, Route8_Text_StanBeaten
	msgbox Route8_Text_StanPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Aidan::
	trainerbattle_single TRAINER_KANTO_SUPER_NERD_AIDAN, Route8_Text_AidanSeen, Route8_Text_AidanBeaten
	msgbox Route8_Text_AidanPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Eli::
	trainerbattle_single TRAINER_KANTO_TWINS_ELI_ANNE, Route8_Text_EliSeen, Route8_Text_EliBeaten
	msgbox Route8_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Anne::
	trainerbattle_single TRAINER_KANTO_TWINS_ELI_ANNE_2, Route8_Text_AnneSeen, Route8_Text_AnneBeaten
	msgbox Route8_Text_AnnePostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Ricardo::
	trainerbattle_single TRAINER_KANTO_BIKER_RICARDO, Route8_Text_RicardoSeen, Route8_Text_RicardoBeaten
	msgbox Route8_Text_RicardoPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Jaren::
	trainerbattle_single TRAINER_KANTO_BIKER_JAREN, Route8_Text_JarenSeen, Route8_Text_JarenBeaten
	msgbox Route8_Text_JarenPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_UndergroundPathSign::
	msgbox Route8_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route8_Text_JuliaSeen:
	.string "What's a cute, round, and fluffy\nPOKéMON?$"

Route8_Text_JuliaBeaten:
	.string "Stop!\pDon't be so mean to my CLEFAIRY!$"

Route8_Text_JuliaPostBattle:
	.string "I read that CLEFAIRY evolves when\nit's exposed to a MOON STONE.\pI read that in a POKéMON JOURNAL.\nI wonder if it's true?$"

Route8_Text_RichSeen:
	.string "I'm a rambling, gaming dude!$"

Route8_Text_RichBeaten:
	.string "Missed the big chance!$"

Route8_Text_RichPostBattle:
	.string "Playing games and POKéMON are like\neating peanuts! I just can't stop!$"

Route8_Text_GlennSeen:
	.string "You should be informed.\nYou need strategy to win at this!$"

Route8_Text_GlennBeaten:
	.string "It's not logical!$"

Route8_Text_GlennPostBattle:
	.string "Go with GRIMER first…and…\n…and…then…$"

Route8_Text_PaigeSeen:
	.string "I like NIDORAN, so I collect them!$"

Route8_Text_PaigeBeaten:
	.string "Why?\nWhy??$"

Route8_Text_PaigePostBattle:
	.string "When POKéMON grow up, they get\nugly! They shouldn't evolve.$"

Route8_Text_LeslieSeen:
	.string "School is fun, but so are POKéMON.$"

Route8_Text_LeslieBeaten:
	.string "You made it clear to me that\nI should stick with school.$"

Route8_Text_LesliePostBattle:
	.string "I was planning on getting some\nfresh air for a change, but…\pWe're stuck here because of the\ngates at SAFFRON.$"

Route8_Text_AndreaSeen:
	.string "MEOWTH is so cute, meow, meow,\nmeow!$"

Route8_Text_AndreaBeaten:
	.string "Meeeeyow!$"

Route8_Text_AndreaPostBattle:
	.string "I think PIDGEY and RATTATA are\ncute, too!$"

Route8_Text_MeganSeen:
	.string "We must look silly standing here\nlike this.$"

Route8_Text_MeganBeaten:
	.string "Look what you did to my poor, cute\nPOKéMON!$"

Route8_Text_MeganPostBattle:
	.string "SAFFRON's gatekeeper won't let us\ngo through.\pI know he's doing his job, but I\nthink he's mean.$"

Route8_Text_StanSeen:
	.string "All right!\nLet's play a game!$"

Route8_Text_StanBeaten:
	.string "Drat!\nCame up short!$"

Route8_Text_StanPostBattle:
	.string "Things didn't work today.$"

Route8_Text_AidanSeen:
	.string "You look good at POKéMON, but how\nis your chemistry grade?$"

Route8_Text_AidanBeaten:
	.string "Ow!\nMeltdown!$"

Route8_Text_AidanPostBattle:
	.string "I am better at school than this!$"

Route8_Text_EliSeen:
	.string "ELI: Twin power is fantastic.\nDid you know?$"

Route8_Text_EliBeaten:
	.string "ELI: But…\nWe used our twin power…$"

Route8_Text_EliPostBattle:
	.string "ELI: I caught my POKéMON with\nANNE!$"

Route8_Text_AnneSeen:
	.string "ANNE: We'll shock you with our twin\npower!$"

Route8_Text_AnneBeaten:
	.string "ANNE: Our twin power…$"

Route8_Text_AnnePostBattle:
	.string "ANNE: I'm raising POKéMON with\nELI.$"

Route8_Text_RicardoSeen:
	.string "My bike's acting up, man.$"

Route8_Text_RicardoBeaten:
	.string "Aww, man.\nI'm not into this.$"

Route8_Text_RicardoPostBattle:
	.string "I got grass caught up in my\nspokes, man.$"

Route8_Text_JarenSeen:
	.string "Clear the way, or I'll run you\ndown!$"

Route8_Text_JarenBeaten:
	.string "You for real, kid?$"

Route8_Text_JarenPostBattle:
	.string "Don't think you're all special and\nall just because of this.$"

Route8_Text_UndergroundPathSign:
	.string "UNDERGROUND PATH\nCELADON CITY - LAVENDER TOWN$"
