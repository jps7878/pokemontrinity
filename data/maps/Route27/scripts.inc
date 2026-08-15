Route27_MapScripts::
	.byte 0

Route27_EventScript_BLAKE::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERM_BLAKE, Route27_Text_BLAKESeen, Route27_Text_BLAKEBeaten
	msgbox Route27_Text_BLAKEBeaten, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_BRIAN::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERM_BRIAN, Route27_Text_BRIANSeen, Route27_Text_BRIANBeaten
	msgbox Route27_Text_BRIANBeaten, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_REENA1::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_REENA1, Route27_Text_REENA1Seen, Route27_Text_REENA1Beaten
	msgbox Route27_Text_REENA1Beaten, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_MEGAN::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_MEGAN, Route27_Text_MEGANSeen, Route27_Text_MEGANBeaten
	msgbox Route27_Text_MEGANBeaten, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_GILBERT::
	trainerbattle_single TRAINER_JOHTO_PSYCHIC_T_GILBERT, Route27_Text_GILBERTSeen, Route27_Text_GILBERTBeaten
	msgbox Route27_Text_GILBERTBeaten, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_JOSE2::
	trainerbattle_single TRAINER_JOHTO_BIRD_KEEPER_JOSE2, Route27_Text_JOSE2Seen, Route27_Text_JOSE2Beaten
	msgbox Route27_Text_JOSE2Beaten, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Fisher::
	msgbox Route27_Text_Fisher, MSGBOX_NPC
	end

Route27_EventScript_TohjoFallsSign::
	msgbox Route27_Text_TohjoFallsSign, MSGBOX_SIGN
	end

Route27_Text_BLAKESeen:
	.string "You look pretty\nstrong.\lLet me battle you!$"

Route27_Text_BLAKEBeaten:
	.string "Yow!$"

Route27_Text_BRIANSeen:
	.string "Hm? You're good,\naren't you?$"

Route27_Text_BRIANBeaten:
	.string "Just as I thought!$"

Route27_Text_REENA1Seen:
	.string "You shouldn't\nunderestimate the\pwild POKéMON in\nthese parts.$"

Route27_Text_REENA1Beaten:
	.string "Oh! You're much\ntoo strong!$"

Route27_Text_MEGANSeen:
	.string "It's rare to see\nanyone come here.\pAre you training\non your own?$"

Route27_Text_MEGANBeaten:
	.string "Oh! You're really\nstrong!$"

Route27_Text_GILBERTSeen:
	.string "Don't say a thing!\pLet me guess what\nyou're thinking.\pMmmmmmm…\pI got it! You're\non the POKéMON\lLEAGUE challenge!$"

Route27_Text_GILBERTBeaten:
	.string "You're too much!$"

Route27_Text_JOSE2Seen:
	.string "Tweet! Tweet!\nTetweet!$"

Route27_Text_JOSE2Beaten:
	.string "Tweet!$"

Route27_Text_Fisher:
	.string "Do you know what\nyou just did?\pYou've taken your\nfirst step into\lKANTO.\pCheck your POKé-\nGEAR MAP and see.$"

Route27_Text_TohjoFallsSign:
	.string "TOHJO FALLS\pTHE LINK BETWEEN\nKANTO AND JOHTO$"
