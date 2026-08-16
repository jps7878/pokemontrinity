Route26_MapScripts::
	.byte 0

Route26_EventScript_JAKE::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERM_JAKE, Route26_Text_JAKESeen, Route26_Text_JAKEBeaten
	msgbox Route26_Text_JAKEBeaten, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_GAVEN3::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERM_GAVEN3, Route26_Text_GAVEN3Seen, Route26_Text_GAVEN3Beaten
	msgbox Route26_Text_GAVEN3Beaten, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_JOYCE::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_JOYCE, Route26_Text_JOYCESeen, Route26_Text_JOYCEBeaten
	msgbox Route26_Text_JOYCEBeaten, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_BETH1::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_BETH1, Route26_Text_BETH1Seen, Route26_Text_BETH1Beaten
	msgbox Route26_Text_BETH1Beaten, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_RICHARD::
	trainerbattle_single TRAINER_JOHTO_PSYCHIC_T_RICHARD, Route26_Text_RICHARDSeen, Route26_Text_RICHARDBeaten
	msgbox Route26_Text_RICHARDBeaten, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_SCOTT::
	trainerbattle_single TRAINER_JOHTO_FISHER_SCOTT, Route26_Text_SCOTTSeen, Route26_Text_SCOTTBeaten
	msgbox Route26_Text_SCOTTBeaten, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Sign::
	msgbox Route26_Text_Sign, MSGBOX_SIGN
	end

Route26_Text_JAKESeen:
	.string "I'm making my\nfinal preparations\pfor the POKéMON\nLEAGUE.$"

Route26_Text_JAKEBeaten:
	.string "I blew it!$"

Route26_Text_GAVEN3Seen:
	.string "By experiencing\ntough battles, you\lgain power.$"

Route26_Text_GAVEN3Beaten:
	.string "Gaah! Life is even\ntougher!$"

Route26_Text_JOYCESeen:
	.string "Since you've come\nthis far, you must\lbe good.\pI'm going to give\nthis battle every-\lthing I've got!$"

Route26_Text_JOYCEBeaten:
	.string "No! I don't\nbelieve this!$"

Route26_Text_BETH1Seen:
	.string "I lost to a train-\ner named SILVER.\pHe was really\nstrong, but…\pIt was as if he\nabsolutely had to\lwin at any cost.\pI felt sorry for\nhis POKéMON.$"

Route26_Text_BETH1Beaten:
	.string "POKéMON aren't\ntools of war.$"

Route26_Text_RICHARDSeen:
	.string "Wow, look at all\nthose BADGES!\lI'm impressed.\pBut you're not\nsatisfied by just\pcollecting them,\nright?$"

Route26_Text_RICHARDBeaten:
	.string "Good battle!$"

Route26_Text_SCOTTSeen:
	.string "I'm feeling great\ntoday!\pI feel like I\ncould boot even\lthe LEAGUE CHAMP!$"

Route26_Text_SCOTTBeaten:
	.string "No! Not in this\nbattle!$"

Route26_Text_Sign:
	.string "ROUTE 26\pPOKéMON LEAGUE\nRECEPTION GATE$"

@ ============================================================================
@ M4b S11 -- the POKéMON LEAGUE RECEPTION GATE.
@
@ THE WARP. (7,5) has been a self-stub since M3 (`warp_def 7, 5, 0, 0,
@ MAP_ROUTE_26`). It decodes collision 0, elevation 3, MB_NON_ANIMATED_DOOR,
@ metatile 603 -- a live door tile that has been looping the player onto itself.
@ It now lands on KANTO VICTORY ROAD 1F's south entrance (11,20), and that warp
@ lands back here: the M4a-decided warp-gate staging (M4 spec judgment call C),
@ with no gate map in between and no overworld Kanto stitch until M5.
@
@ THE GATE. Eight JOHTO badges, counted with S8's C-COUNT
@ (data/scripts/trinity_johto.inc). NOT `VAR_TRINITY_JOHTO_ARC >= 9`: S10 writes
@ arc 9 for SUICUNE, SUICUNE is optional content behind an optional gate, and an
@ arc-9 league would make Act II unfinishable for a player who never presented
@ the CLEAR BELL. G7 discipline: this READS badges 09-16 and writes none.
@
@ THE TRIGGER TILE IS FORCED. (7,5)'s only walkable neighbour is (7,6) -- (6,5),
@ (8,5) and (7,4) all decode collision 1 -- so one coord_event on (7,6) cannot be
@ walked around. It is gated on VAR_TEMP_1 == 0, which ClearTempFieldEventData
@ resets on every map load and nothing on ROUTE 26 ever writes, so the refusal is
@ live on every crossing; the first line short-circuits once the gate is passed,
@ so the cost after that is one flag test and no lock.
@
@ THE OFFICER STANDS AT (6,6), NOT ON THE APPROACH. (6,6) is a one-tile nook
@ whose only walkable neighbours are (6,7) and (7,6), so he costs exactly his own
@ tile and cannot seal the door -- the S3/S6/S8/S9 "expect to move a GSC guard
@ post" rule applied before placement rather than after. GSC parks its own
@ officer beside the arch the same way (VictoryRoadGate.asm, SPRITE_OFFICER at
@ (8,11) with the coord_event two tiles east).
@ ============================================================================

Route26_EventScript_LeagueGateCheck::
	goto_if_set FLAG_TRINITY_J_INDIGO_GATE_PASSED, Route26_EventScript_LeagueGateOpen
	lockall
	call Trinity_EventScript_CountJohtoBadges
	goto_if_lt VAR_TEMP_A, 8, Route26_EventScript_LeagueGateRefuse
	msgbox Route26_Text_GateEightBadges, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_TRINITY_J_INDIGO_GATE_PASSED
	releaseall
	end

@ INTENTIONALLY EMPTY / DEFENSIVE. Once the gate is passed the trigger still
@ fires on every crossing -- that is what makes the refusal reliable -- and this
@ branch is what makes it free.
Route26_EventScript_LeagueGateOpen::
	end

Route26_EventScript_LeagueGateRefuse::
	msgbox Route26_Text_GateNotEnoughBadges, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route26_Movement_GateStepBack
	waitmovement 0
	releaseall
	end

Route26_EventScript_LeagueGateOfficer::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_INDIGO_GATE_PASSED, Route26_EventScript_OfficerPassed
	call Trinity_EventScript_CountJohtoBadges
	goto_if_lt VAR_TEMP_A, 8, Route26_EventScript_OfficerBlocking
	msgbox Route26_Text_OfficerReady, MSGBOX_DEFAULT
	release
	end

Route26_EventScript_OfficerBlocking::
	msgbox Route26_Text_OfficerBlocking, MSGBOX_DEFAULT
	release
	end

Route26_EventScript_OfficerPassed::
	msgbox Route26_Text_OfficerPassed, MSGBOX_DEFAULT
	release
	end

Route26_Movement_GateStepBack:
	walk_down
	step_end

@ GSC VictoryRoadGateOfficerText / VictoryRoadGateNotEnoughBadgesText /
@ VictoryRoadGateEightBadgesText, adapted: the challenger is already a CHAMPION
@ somewhere else, and the officer's whole job is that it does not count here.
Route26_Text_OfficerBlocking:
	.string "Only trainers who have proven\n"
	.string "themselves in JOHTO may pass.\p"
	.string "I know who you are. Everyone at\n"
	.string "this gate does.\p"
	.string "It doesn't work like that. Eight\n"
	.string "BADGES, from the eight JOHTO GYMS.\p"
	.string "Then the road is yours.$"

Route26_Text_OfficerReady:
	.string "All eight. I counted them twice.\p"
	.string "Through the gate, then up VICTORY\n"
	.string "ROAD. It's three floors and it is\l"
	.string "not kind to anybody.\p"
	.string "The PLATEAU is on the other side.$"

Route26_Text_OfficerPassed:
	.string "Go on through.\p"
	.string "Nobody here is going to ask you\n"
	.string "for your BADGES twice.$"

Route26_Text_GateNotEnoughBadges:
	.string "OFFICER: Hold on.\p"
	.string "You don't have all the GYM BADGES\n"
	.string "of JOHTO.\p"
	.string "I'm sorry, but I can't let you go\n"
	.string "through.$"

Route26_Text_GateEightBadges:
	.string "OFFICER: Oh! The eight BADGES\n"
	.string "of JOHTO!\p"
	.string "Please, go right on through.\p"
	.string "The POKéMON LEAGUE is expecting\n"
	.string "you.$"
