Route20_MapScripts::
	.byte 0

Route20_EventScript_Melissa::
	trainerbattle_single TRAINER_KANTO_SWIMMER_F_MELISSA, Route20_Text_MelissaSeen, Route20_Text_MelissaBeaten
	msgbox Route20_Text_MelissaBeaten, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_Missy::
	trainerbattle_single TRAINER_KANTO_PICNICKER_MISSY, Route20_Text_MissySeen, Route20_Text_MissyBeaten
	msgbox Route20_Text_MissyBeaten, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_Nora::
	trainerbattle_single TRAINER_KANTO_SWIMMER_F_NORA, Route20_Text_NoraSeen, Route20_Text_NoraBeaten
	msgbox Route20_Text_NoraBeaten, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_Roger::
	trainerbattle_single TRAINER_KANTO_BIRD_KEEPER_ROGER, Route20_Text_RogerSeen, Route20_Text_RogerBeaten
	msgbox Route20_Text_RogerBeaten, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_Dean::
	trainerbattle_single TRAINER_KANTO_SWIMMER_M_DEAN, Route20_Text_DeanSeen, Route20_Text_DeanBeaten
	msgbox Route20_Text_DeanBeaten, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_Irene::
	trainerbattle_single TRAINER_KANTO_PICNICKER_IRENE, Route20_Text_IreneSeen, Route20_Text_IreneBeaten
	msgbox Route20_Text_IreneBeaten, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_Barry::
	trainerbattle_single TRAINER_KANTO_SWIMMER_M_BARRY, Route20_Text_BarrySeen, Route20_Text_BarryBeaten
	msgbox Route20_Text_BarryBeaten, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_Darrin::
	trainerbattle_single TRAINER_KANTO_SWIMMER_M_DARRIN, Route20_Text_DarrinSeen, Route20_Text_DarrinBeaten
	msgbox Route20_Text_DarrinBeaten, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_Shirley::
	trainerbattle_single TRAINER_KANTO_SWIMMER_F_SHIRLEY, Route20_Text_ShirleySeen, Route20_Text_ShirleyBeaten
	msgbox Route20_Text_ShirleyBeaten, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_Tiffany::
	trainerbattle_single TRAINER_KANTO_SWIMMER_F_TIFFANY, Route20_Text_TiffanySeen, Route20_Text_TiffanyBeaten
	msgbox Route20_Text_TiffanyBeaten, MSGBOX_AUTOCLOSE
	end

Route20_EventScript_SeafoamIslandsSign::
	msgbox Route20_Text_SeafoamIslandsSign, MSGBOX_SIGN
	end

Route20_EventScript_SeafoamIslandsSign_2::
	msgbox Route20_Text_SeafoamIslandsSign_2, MSGBOX_SIGN
	end

Route20_Text_MelissaSeen:
	.string "The water's calmer along this\nstretch. Good for practicing.$"

Route20_Text_MelissaBeaten:
	.string "Guess I need more practice.$"

Route20_Text_MissySeen:
	.string "Picnicking with a view of\nSEAFOAM. Doesn't get better.$"

Route20_Text_MissyBeaten:
	.string "Well, my picnic's ruined now.$"

Route20_Text_NoraSeen:
	.string "You look like you've swum some\ndistance already.$"

Route20_Text_NoraBeaten:
	.string "And you battle like it, too.$"

Route20_Text_RogerSeen:
	.string "My POKéMON love the sea breeze\nas much as I do!$"

Route20_Text_RogerBeaten:
	.string "Even the breeze couldn't save\nme from that.$"

Route20_Text_DeanSeen:
	.string "I dare you to out-swim me!\nBattle first, though.$"

Route20_Text_DeanBeaten:
	.string "Didn't even get to the swimming\npart.$"

Route20_Text_IreneSeen:
	.string "Care to join my picnic once\nwe're through here?$"

Route20_Text_IreneBeaten:
	.string "Oh dear. Let's get you a snack\nafter that.$"

Route20_Text_BarrySeen:
	.string "Nothing beats a swim before\na battle to warm up.$"

Route20_Text_BarryBeaten:
	.string "Guess I warmed up for nothing.$"

Route20_Text_DarrinSeen:
	.string "SEAFOAM's currents get faster\nthe closer you get. Ready?$"

Route20_Text_DarrinBeaten:
	.string "Not as ready as you, clearly.$"

Route20_Text_ShirleySeen:
	.string "I've swum this route a hundred\ntimes. Still love it.$"

Route20_Text_ShirleyBeaten:
	.string "A hundred and one, and I still\nlost.$"

Route20_Text_TiffanySeen:
	.string "Let's see what you've got\nbefore you reach the caves!$"

Route20_Text_TiffanyBeaten:
	.string "You've got plenty, it turns\nout.$"

Route20_Text_SeafoamIslandsSign:
	.string "SEAFOAM ISLANDS$"

Route20_Text_SeafoamIslandsSign_2:
	.string "SEAFOAM ISLANDS$"
