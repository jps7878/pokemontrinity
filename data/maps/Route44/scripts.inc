Route44_MapScripts::
	.byte 0

Route44_EventScript_WILTON1::
	trainerbattle_single TRAINER_JOHTO_FISHER_WILTON1, Route44_Text_WILTON1Seen, Route44_Text_WILTON1Beaten
	msgbox Route44_Text_WILTON1Beaten, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_EDGAR::
	trainerbattle_single TRAINER_JOHTO_FISHER_EDGAR, Route44_Text_EDGARSeen, Route44_Text_EDGARBeaten
	msgbox Route44_Text_EDGARBeaten, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_PHIL::
	trainerbattle_single TRAINER_JOHTO_PSYCHIC_T_PHIL, Route44_Text_PHILSeen, Route44_Text_PHILBeaten
	msgbox Route44_Text_PHILBeaten, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_ZACH::
	trainerbattle_single TRAINER_JOHTO_POKEMANIAC_ZACH, Route44_Text_ZACHSeen, Route44_Text_ZACHBeaten
	msgbox Route44_Text_ZACHBeaten, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_VANCE1::
	trainerbattle_single TRAINER_JOHTO_BIRD_KEEPER_VANCE1, Route44_Text_VANCE1Seen, Route44_Text_VANCE1Beaten
	msgbox Route44_Text_VANCE1Beaten, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_ALLEN::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERM_ALLEN, Route44_Text_ALLENSeen, Route44_Text_ALLENBeaten
	msgbox Route44_Text_ALLENBeaten, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_CYBIL::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_CYBIL, Route44_Text_CYBILSeen, Route44_Text_CYBILBeaten
	msgbox Route44_Text_CYBILBeaten, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Sign1::
	msgbox Route44_Text_Sign1, MSGBOX_SIGN
	end

Route44_EventScript_Sign2::
	msgbox Route44_Text_Sign2, MSGBOX_SIGN
	end

Route44_Text_WILTON1Seen:
	.string "Aack! You made me\nlose a POLIWAG!\pWhat are you going\nto do about it?$"

Route44_Text_WILTON1Beaten:
	.string "Just forget about\nit.$"

Route44_Text_EDGARSeen:
	.string "I fish until I\ncan't anymore.\pI also battle\nuntil I drop.\pThat's my\nrelationship\lwith my POKéMON.$"

Route44_Text_EDGARBeaten:
	.string "Hmmmm… \nThis isn't right.$"

Route44_Text_PHILSeen:
	.string "I'm gonna win,\nfor sure!$"

Route44_Text_PHILBeaten:
	.string "Arrgh… That's a\nshocking loss…$"

Route44_Text_ZACHSeen:
	.string "I'll do anything\nto get my hands on\lrare POKéMON!$"

Route44_Text_ZACHBeaten:
	.string "Oooh, your POKéMON\nare so appealing.$"

Route44_Text_VANCE1Seen:
	.string "Do you know about\nthe legendary bird\lPOKéMON?$"

Route44_Text_VANCE1Beaten:
	.string "Whew! You're hot\nstuff.$"

Route44_Text_ALLENSeen:
	.string "I can tell you're\na good trainer by\llooking at you.\pI'm good at POKé-\nMON, and I can see\lthat you are too.$"

Route44_Text_ALLENBeaten:
	.string "Tch! It's a total\nloss on my part.$"

Route44_Text_CYBILSeen:
	.string "You look strong.\pGood trainers seek\ntough opponents\linstinctively.$"

Route44_Text_CYBILBeaten:
	.string "Nope! This won't\ndo at all.$"

Route44_Text_Sign1:
	.string "ROUTE 44\nICE PATH AHEAD$"

Route44_Text_Sign2:
	.string "ROUTE 44\pMAHOGANY TOWN -\nBLACKTHORN CITY$"
