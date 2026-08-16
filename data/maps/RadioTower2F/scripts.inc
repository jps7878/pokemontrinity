RadioTower2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RadioTower2F_OnTransition
	.byte 0

@ Trinity M4b S4 -- RADIO TOWER 2F, pre-takeover. S8 FLIP CONTRACT: the shared
@ predicate lives in data/maps/RadioTower1F/scripts.inc
@ (RadioTower_EventScript_SetPreTakeoverVisibility) -- visible iff
@ VAR_TRINITY_JOHTO_ARC != 6. Every object on this floor carries
@ FLAG_TRINITY_J_RADIO_TOWER_PRE_HIDE, including the two M4a placed with flag 0.
@ The BLACK BELT at (1,1) is deliberately GSC's FRIENDLY one ("feel free to
@ look around anywhere"); GSC's other black belt at (0,1) is the takeover-time
@ stair blocker and belongs to S8.
RadioTower2F_OnTransition:
	call RadioTower_EventScript_SetPreTakeoverVisibility
	call RadioTower_EventScript_SetTakeoverVisibility
	end

RadioTower2F_EventScript_Teacher::
	msgbox RadioTower2F_Text_Teacher, MSGBOX_NPC
	end

RadioTower2F_EventScript_Buena::
	msgbox RadioTower2F_Text_Buena, MSGBOX_NPC
	end

RadioTower2F_EventScript_SuperNerd::
	msgbox RadioTower2F_Text_SuperNerd, MSGBOX_NPC
	end

RadioTower2F_EventScript_PrizeReceptionist::
	msgbox RadioTower2F_Text_PrizeReceptionist, MSGBOX_NPC
	end

RadioTower2F_EventScript_BlackBelt::
	msgbox RadioTower2F_Text_BlackBelt, MSGBOX_NPC
	end

RadioTower2F_EventScript_SalesSign::
	msgbox RadioTower2F_Text_SalesSign, MSGBOX_SIGN
	end

RadioTower2F_EventScript_OaksPKMNTalkSign::
	msgbox RadioTower2F_Text_OaksPKMNTalkSign, MSGBOX_SIGN
	end

RadioTower2F_EventScript_PokemonRadioSign::
	msgbox RadioTower2F_Text_PokemonRadioSign, MSGBOX_SIGN
	end

@ GSC RadioTower2FTeacherText.
RadioTower2F_Text_Teacher:
	.string "Lullabies on the radio may make\n"
	.string "POKéMON sleep.\p"
	.string "Not mine. Mine just stares at\n"
	.string "the speaker.$"

@ BUENA'S PASSWORD is a nightly show with a real prize system; not ported (see
@ the slice's skip log). She keeps the show.
RadioTower2F_Text_Buena:
	.string "BUENA: Hi! I'm BUENA! I do\n"
	.string "BUENA'S PASSWORD, nights, on\l"
	.string "CHANNEL 20!\p"
	.string "I say a password on the air,\n"
	.string "you come and tell it to me,\l"
	.string "and you win something.\p"
	.string "That's it. That's the whole\n"
	.string "show. It's been running for\l"
	.string "four years.$"

@ GSC RadioTower2FSuperNerdText.
RadioTower2F_Text_SuperNerd:
	.string "You can listen to the radio\n"
	.string "anywhere. Tune in!\p"
	.string "There's a set of frequencies\n"
	.string "we don't publish, too. Test\l"
	.string "tones, mostly.\p"
	.string "Mostly.$"

RadioTower2F_Text_PrizeReceptionist:
	.string "This is the prize counter for\n"
	.string "BUENA'S PASSWORD.\p"
	.string "You need the password, and you\n"
	.string "need to have heard it tonight.\p"
	.string "No, I can't just tell you it.\n"
	.string "I sit six feet from her and I\l"
	.string "still have to listen in.$"

@ GSC RadioTower2FBlackBelt2Text.
RadioTower2F_Text_BlackBelt:
	.string "Feel free to look around\n"
	.string "anywhere.\p"
	.string "The DIRECTOR likes an open\n"
	.string "building. Says a radio station\l"
	.string "that hides things stops being\l"
	.string "a radio station.\p"
	.string "Makes my job harder. He's\n"
	.string "right, though.$"

RadioTower2F_Text_SalesSign:
	.string "2F SALES$"

RadioTower2F_Text_OaksPKMNTalkSign:
	.string "PROF.OAK'S POKéMON\nTALK\pThe Hottest Show\non the Air!$"

RadioTower2F_Text_PokemonRadioSign:
	.string "Anywhere, Anytime\nPOKéMON Radio$"

@ ============================================================================
@ Trinity M4b S8 -- 2F, the SALES floor under occupation. Four R2 posts on
@ GSC's own tiles (RadioTower2F.asm:646-651), all decoded collision 0 /
@ elevation 3 / MB_NORMAL:
@   (1,4) mt705 facing UP  sight 3 -- covers the west column up to the 3F door
@   (8,4) mt516 facing DOWN sight 3
@   (4,1) mt522 facing DOWN sight 2
@   (10,5) mt642 facing UP sight 3
@ GSC's fifth man is dropped: the 22-post budget spends its 2F share on four.
@ ============================================================================
RadioTower2F_EventScript_GruntA::
	trainerbattle_single TRAINER_JOHTO_ROCKET_RT2F_A, RadioTower2F_Text_GruntASeen, RadioTower2F_Text_GruntABeaten
	msgbox RadioTower2F_Text_GruntAAfter, MSGBOX_AUTOCLOSE
	end

RadioTower2F_EventScript_GruntB::
	trainerbattle_single TRAINER_JOHTO_ROCKET_RT2F_B, RadioTower2F_Text_GruntBSeen, RadioTower2F_Text_GruntBBeaten
	msgbox RadioTower2F_Text_GruntBAfter, MSGBOX_AUTOCLOSE
	end

RadioTower2F_EventScript_GruntC::
	trainerbattle_single TRAINER_JOHTO_ROCKET_RT2F_C, RadioTower2F_Text_GruntCSeen, RadioTower2F_Text_GruntCBeaten
	msgbox RadioTower2F_Text_GruntCAfter, MSGBOX_AUTOCLOSE
	end

RadioTower2F_EventScript_GruntF::
	trainerbattle_single TRAINER_ROCKET_GRUNT_F_3, RadioTower2F_Text_GruntFSeen, RadioTower2F_Text_GruntFBeaten
	msgbox RadioTower2F_Text_GruntFAfter, MSGBOX_AUTOCLOSE
	end

RadioTower2F_Text_GruntASeen:
	.string "This floor sells the air time.\p"
	.string "Do you know what an hour of\n"
	.string "JOHTO's attention is worth?\p"
	.string "We're about to find out.$"

RadioTower2F_Text_GruntABeaten:
	.string "That wasn't in the budget!$"

RadioTower2F_Text_GruntAAfter:
	.string "Fine. Go up. See how far the\n"
	.string "stairs get you.$"

RadioTower2F_Text_GruntBSeen:
	.string "Hey! Nobody comes up here!$"

RadioTower2F_Text_GruntBBeaten:
	.string "Nobody comes up here…$"

RadioTower2F_Text_GruntBAfter:
	.string "I only took this job for the\n"
	.string "uniform. It's a good uniform.$"

RadioTower2F_Text_GruntCSeen:
	.string "I've had strict orders.\p"
	.string "Anyone who challenges TEAM\n"
	.string "ROCKET gets crushed.$"

RadioTower2F_Text_GruntCBeaten:
	.string "What?!$"

RadioTower2F_Text_GruntCAfter:
	.string "I failed in my duties…\p"
	.string "That's coming out of my pay.$"

RadioTower2F_Text_GruntFSeen:
	.string "Don't I think POKéMON are cute?\p"
	.string "I'll think mine are cute --\n"
	.string "right after they beat yours.$"

RadioTower2F_Text_GruntFBeaten:
	.string "Oh, no! They're useless!$"

RadioTower2F_Text_GruntFAfter:
	.string "I love my beautiful self.\p"
	.string "Who cares about POKéMON?$"
