Route35_MapScripts::
	.byte 0

Route35_EventScript_IVAN::
	trainerbattle_single TRAINER_JOHTO_CAMPER_IVAN, Route35_Text_IVANSeen, Route35_Text_IVANBeaten
	msgbox Route35_Text_IVANBeaten, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_ELLIOT::
	trainerbattle_single TRAINER_JOHTO_CAMPER_ELLIOT, Route35_Text_ELLIOTSeen, Route35_Text_ELLIOTBeaten
	msgbox Route35_Text_ELLIOTBeaten, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BROOKE::
	trainerbattle_single TRAINER_JOHTO_PICNICKER_BROOKE, Route35_Text_BROOKESeen, Route35_Text_BROOKEBeaten
	msgbox Route35_Text_BROOKEBeaten, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_KIM::
	trainerbattle_single TRAINER_JOHTO_PICNICKER_KIM, Route35_Text_KIMSeen, Route35_Text_KIMBeaten
	msgbox Route35_Text_KIMBeaten, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BRYAN::
	trainerbattle_single TRAINER_JOHTO_BIRD_KEEPER_BRYAN, Route35_Text_BRYANSeen, Route35_Text_BRYANBeaten
	msgbox Route35_Text_BRYANBeaten, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_WALT::
	trainerbattle_single TRAINER_JOHTO_FIREBREATHER_WALT, Route35_Text_WALTSeen, Route35_Text_WALTBeaten
	msgbox Route35_Text_WALTBeaten, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_ARNIE1::
	trainerbattle_single TRAINER_JOHTO_BUG_CATCHER_ARNIE1, Route35_Text_ARNIE1Seen, Route35_Text_ARNIE1Beaten
	msgbox Route35_Text_ARNIE1Beaten, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_IRWIN1::
	trainerbattle_single TRAINER_JOHTO_JUGGLER_IRWIN1, Route35_Text_IRWIN1Seen, Route35_Text_IRWIN1Beaten
	msgbox Route35_Text_IRWIN1Beaten, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_TrainerOfficerDirk::
	msgbox Route35_Text_TrainerOfficerDirk, MSGBOX_NPC
	end

Route35_EventScript_Sign::
	msgbox Route35_Text_Sign, MSGBOX_SIGN
	end

Route35_EventScript_Sign_2::
	msgbox Route35_Text_Sign_2, MSGBOX_SIGN
	end

Route35_Text_IVANSeen:
	.string "I've been getting\nPOKéMON data off\pmy radio. I think\nI'm good.$"

Route35_Text_IVANBeaten:
	.string "I give!$"

Route35_Text_ELLIOTSeen:
	.string "I'm gonna show my\ngirlfriend I'm hot\lstuff!$"

Route35_Text_ELLIOTBeaten:
	.string "I wish you would\nhave lost for me…$"

Route35_Text_BROOKESeen:
	.string "My boyfriend's\nweak, so I can't\lrely on him.$"

Route35_Text_BROOKEBeaten:
	.string "Oh, my! You're so\nstrong!$"

Route35_Text_KIMSeen:
	.string "Are you going to\nthe GYM? Me too!$"

Route35_Text_KIMBeaten:
	.string "Oh. I couldn't\nwin…$"

Route35_Text_BRYANSeen:
	.string "What kinds of\nBALLS do you use?$"

Route35_Text_BRYANBeaten:
	.string "Yikes! Not fast\nenough!$"

Route35_Text_WALTSeen:
	.string "I'm practicing my\nfire breathing.$"

Route35_Text_WALTBeaten:
	.string "Ow! I scorched the\ntip of my nose!$"

Route35_Text_ARNIE1Seen:
	.string "I'll go anywhere\nif bug POKéMON\lappear there.$"

Route35_Text_ARNIE1Beaten:
	.string "Huh? I shouldn't\nhave lost that…$"

Route35_Text_IRWIN1Seen:
	.string "Behold my graceful\nBALL dexterity!$"

Route35_Text_IRWIN1Beaten:
	.string "Whew! That was a\njolt!$"

Route35_Text_TrainerOfficerDirk:
	.string "JOHTO's changed a lot since the\nHOENN champion opened the sea\lroutes here.$"

Route35_Text_Sign:
	.string "ROUTE 35$"

Route35_Text_Sign_2:
	.string "ROUTE 35$"
