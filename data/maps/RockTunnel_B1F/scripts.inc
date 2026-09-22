@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

RockTunnel_B1F_MapScripts::
	.byte 0

RockTunnel_B1F_EventScript_Cooper::
	trainerbattle_single TRAINER_KANTO_POKEMANIAC_COOPER, RockTunnel_B1F_Text_CooperSeen, RockTunnel_B1F_Text_CooperBeaten
	msgbox RockTunnel_B1F_Text_CooperPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Dudley::
	trainerbattle_single TRAINER_KANTO_HIKER_DUDLEY, RockTunnel_B1F_Text_DudleySeen, RockTunnel_B1F_Text_DudleyBeaten
	msgbox RockTunnel_B1F_Text_DudleyPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Sofia::
	trainerbattle_single TRAINER_KANTO_PICNICKER_SOFIA, RockTunnel_B1F_Text_SofiaSeen, RockTunnel_B1F_Text_SofiaBeaten
	msgbox RockTunnel_B1F_Text_SofiaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Allen::
	trainerbattle_single TRAINER_KANTO_HIKER_ALLEN, RockTunnel_B1F_Text_AllenSeen, RockTunnel_B1F_Text_AllenBeaten
	msgbox RockTunnel_B1F_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Eric::
	trainerbattle_single TRAINER_KANTO_HIKER_ERIC, RockTunnel_B1F_Text_EricSeen, RockTunnel_B1F_Text_EricBeaten
	msgbox RockTunnel_B1F_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Steve::
	trainerbattle_single TRAINER_KANTO_POKEMANIAC_STEVE, RockTunnel_B1F_Text_SteveSeen, RockTunnel_B1F_Text_SteveBeaten
	msgbox RockTunnel_B1F_Text_StevePostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Martha::
	trainerbattle_single TRAINER_KANTO_PICNICKER_MARTHA, RockTunnel_B1F_Text_MarthaSeen, RockTunnel_B1F_Text_MarthaBeaten
	msgbox RockTunnel_B1F_Text_MarthaPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_EventScript_Winston::
	trainerbattle_single TRAINER_KANTO_POKEMANIAC_WINSTON, RockTunnel_B1F_Text_WinstonSeen, RockTunnel_B1F_Text_WinstonBeaten
	msgbox RockTunnel_B1F_Text_WinstonPostBattle, MSGBOX_AUTOCLOSE
	end

RockTunnel_B1F_Text_CooperSeen:
	.string "You have a POKéDEX?\nI want one, too.$"

RockTunnel_B1F_Text_CooperBeaten:
	.string "Shoot!\nI am so jealous!$"

RockTunnel_B1F_Text_CooperPostBattle:
	.string "When you finish your POKéDEX,\ncan I have it?$"

RockTunnel_B1F_Text_DudleySeen:
	.string "Hahaha!\nCan you beat my power?$"

RockTunnel_B1F_Text_DudleyBeaten:
	.string "Oops!\nOutmuscled!$"

RockTunnel_B1F_Text_DudleyPostBattle:
	.string "I go for power because I hate\nthinking.$"

RockTunnel_B1F_Text_SofiaSeen:
	.string "Do you know how you can avoid\ngetting lost in the mountains?\pYou can bend twigs as trail\nmarkers.$"

RockTunnel_B1F_Text_SofiaBeaten:
	.string "Ohhh!\nI did my best!$"

RockTunnel_B1F_Text_SofiaPostBattle:
	.string "I want to go home!$"

RockTunnel_B1F_Text_AllenSeen:
	.string "My POKéMON techniques will leave\nyou crying!$"

RockTunnel_B1F_Text_AllenBeaten:
	.string "I give!\nYou're a better technician!$"

RockTunnel_B1F_Text_AllenPostBattle:
	.string "In mountains, you'll often find\nROCK-type POKéMON.$"

RockTunnel_B1F_Text_EricSeen:
	.string "Hit me with your best shot!$"

RockTunnel_B1F_Text_EricBeaten:
	.string "Fired away!$"

RockTunnel_B1F_Text_EricPostBattle:
	.string "I'll raise my POKéMON to beat\nyours, kid.$"

RockTunnel_B1F_Text_SteveSeen:
	.string "Um… Do you know about POKéMON\ncosplay?$"

RockTunnel_B1F_Text_SteveBeaten:
	.string "Well, that's that.$"

RockTunnel_B1F_Text_StevePostBattle:
	.string "POKéMON cosplay is dressing up as\nPOKéMON for fun.\pCLEFAIRY is a favorite.$"

RockTunnel_B1F_Text_MarthaSeen:
	.string "I don't often come here, but I will\nbattle you.$"

RockTunnel_B1F_Text_MarthaBeaten:
	.string "Oh!\nI lost!$"

RockTunnel_B1F_Text_MarthaPostBattle:
	.string "I like tiny POKéMON.\nBig ones are too scary!$"

RockTunnel_B1F_Text_WinstonSeen:
	.string "I draw illustrations of POKéMON\nwhen I'm home.$"

RockTunnel_B1F_Text_WinstonBeaten:
	.string "Whew…\nI'm exhausted…$"

RockTunnel_B1F_Text_WinstonPostBattle:
	.string "I'm an artist, not a fighter.\nI'll go home to draw.$"
