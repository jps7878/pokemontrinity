ElmsLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ElmsLab_OnTransition
	.byte 0

@ Trinity M4b S1. Object visibility in this lab is driven entirely from
@ ON_TRANSITION (which runs before InitMap and before TrySpawnObjectEvents --
@ src/overworld.c:876/945), so the hide flags never need a new-game default:
@   - SILVER is a pure cutscene actor. He is ALWAYS hidden at map load and is
@     spawned mid-script with addobject (TrySpawnObjectEvent does not consult
@     the template flag, src/event_object_movement.c:1803), then removeobject'd
@     (which re-sets the flag itself, src/event_object_movement.c:1542).
@   - The OFFICER only exists in the window between beating SILVER on ROUTE 29
@     (scene 3) and the aftermath scene (scene 4).
ElmsLab_OnTransition:
	setflag FLAG_TRINITY_J_SILVER_LAB_HIDE
	goto_if_eq VAR_TRINITY_JOHTO_SCENE_NEWBARK, 3, ElmsLab_EventScript_ShowOfficer
	setflag FLAG_TRINITY_J_ELM_OFFICER_HIDE
	end

ElmsLab_EventScript_ShowOfficer::
	clearflag FLAG_TRINITY_J_ELM_OFFICER_HIDE
	end

@ ============================================================================
@ Scene B -- first meeting with PROF.ELM (coord triggers (4,8)/(5,8), scene 0)
@ Adapts pokecrystal ElmsLabWalkUpToElmScript + ElmText_Intro /
@ ElmText_ResearchAmbitions / ElmText_MissionFromMrPokemon. GSC's starter
@ choice and MYSTERY EGG errand are dropped: in Act II the player arrives as
@ the HOENN Champion with a full team.
@ Both triggers converge on (4,4), immediately east of ELM's resting tile
@ (3,4) -- decoded walkable, and he seals nothing there (row 4 is fully open).
@ ============================================================================
ElmsLab_EventScript_MeetElmWest::
	lockall
	applymovement LOCALID_PLAYER, ElmsLab_Movement_PlayerToElmWest
	waitmovement 0
	goto ElmsLab_EventScript_MeetElm
	end

ElmsLab_EventScript_MeetElmEast::
	lockall
	applymovement LOCALID_PLAYER, ElmsLab_Movement_PlayerToElmEast
	waitmovement 0
	goto ElmsLab_EventScript_MeetElm
	end

ElmsLab_EventScript_MeetElm::
	applymovement LOCALID_JOHTO_ELM, ElmsLab_Movement_ElmNotices
	waitmovement 0
	msgbox ElmsLab_Text_ElmIntro, MSGBOX_DEFAULT
	msgbox ElmsLab_Text_ElmStudiesYourTeam, MSGBOX_DEFAULT
	msgbox ElmsLab_Text_ElmRadioCard, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_J_RADIO_CARD
	msgbox ElmsLab_Text_ElmMrPokemon, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_J_MRPOKEMON_HOOK
	closemessage
	setvar VAR_TRINITY_JOHTO_ARC, 1
	setvar VAR_TRINITY_JOHTO_SCENE_NEWBARK, 1
	releaseall
	end

@ ============================================================================
@ Scene C -- the break-in (coord triggers (4,6)/(5,6), scene 1)
@ GSC robs the lab off-screen while the player is at MR.POKéMON's
@ (MrPokemonsHouse.asm:129, specialphonecall SPECIALCALL_ROBBED). Trinity
@ stages it live, keeping GSC's window entry (ElmsLabWindowText2) and its
@ shove (NewBarkTown_RivalShovesYouOutMovement: fixed facing + a one-tile
@ jump). The stolen POKéMON is ELM's adult research FERALIGATR -- the M4 spec's
@ founder decision (B) and TRAINER_SILVER_1's L60 ace.
@ The lab's only exit corridor is exactly two tiles wide ((4,6)/(5,6) with
@ walls either side), so this pair of triggers cannot be walked around. Both
@ converge on (5,6) so that column x=4 stays clear for the shove and column
@ x=5 stays clear for SILVER's run to the door.
@ ============================================================================
ElmsLab_EventScript_TheftWest::
	lockall
	applymovement LOCALID_PLAYER, ElmsLab_Movement_PlayerStepEast
	waitmovement 0
	goto ElmsLab_EventScript_Theft
	end

ElmsLab_EventScript_TheftEast::
	lockall
	goto ElmsLab_EventScript_Theft
	end

ElmsLab_EventScript_Theft::
	applymovement LOCALID_PLAYER, ElmsLab_Movement_PlayerFaceNorth
	waitmovement 0
	playse SE_GLASS_FLUTE
	waitse
	delay 30
	applymovement LOCALID_JOHTO_ELM, ElmsLab_Movement_ElmAlarmed
	waitmovement 0
	msgbox ElmsLab_Text_ElmWhatWasThat, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
	clearflag FLAG_TRINITY_J_SILVER_LAB_HIDE
	addobject LOCALID_JOHTO_LAB_SILVER
	delay 20
	applymovement LOCALID_JOHTO_LAB_SILVER, ElmsLab_Movement_SilverDropsIn
	waitmovement 0
	msgbox ElmsLab_Text_SilverTakesFeraligatr, MSGBOX_DEFAULT
	msgbox ElmsLab_Text_ElmPutThatDown, MSGBOX_DEFAULT
	msgbox ElmsLab_Text_SilverMove, MSGBOX_DEFAULT
	closemessage
	playse SE_MUD_BALL
	applymovement LOCALID_PLAYER, ElmsLab_Movement_PlayerShovedAside
	waitmovement 0
	applymovement LOCALID_JOHTO_LAB_SILVER, ElmsLab_Movement_SilverBoltsForTheDoor
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject LOCALID_JOHTO_LAB_SILVER
	fadedefaultbgm
	msgbox ElmsLab_Text_ElmHeTookFeraligatr, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TRINITY_JOHTO_ARC, 2
	setvar VAR_TRINITY_JOHTO_SCENE_NEWBARK, 2
	releaseall
	end

@ ============================================================================
@ Scene E -- the OFFICER's report + ELM's aftermath (triggers (4,4)/(5,4),
@ scene 3). Adapts pokecrystal CopScript / ElmsLabOfficerText1-2 and the
@ "closest GYM is VIOLET CITY" pointer out of ElmAfterTheftText5-6. GSC's
@ `special NameRival` is dropped -- SILVER is a fixed literal in Trinity.
@ Staging after normalisation: ELM (3,4) -- player (4,4) -- OFFICER (5,4).
@ ============================================================================
ElmsLab_EventScript_AftermathEast::
	lockall
	applymovement LOCALID_PLAYER, ElmsLab_Movement_PlayerStepWest
	waitmovement 0
	goto ElmsLab_EventScript_Aftermath
	end

ElmsLab_EventScript_AftermathWest::
	lockall
	goto ElmsLab_EventScript_Aftermath
	end

ElmsLab_EventScript_Aftermath::
	applymovement LOCALID_JOHTO_ELM_OFFICER, ElmsLab_Movement_OfficerApproaches
	waitmovement 0
	applymovement LOCALID_PLAYER, ElmsLab_Movement_PlayerFaceEast
	waitmovement 0
	msgbox ElmsLab_Text_OfficerQuestions, MSGBOX_DEFAULT
	msgbox ElmsLab_Text_OfficerGotTheName, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_JOHTO_ELM_OFFICER, ElmsLab_Movement_OfficerLeaves
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject LOCALID_JOHTO_ELM_OFFICER
	applymovement LOCALID_PLAYER, ElmsLab_Movement_PlayerFaceWest
	waitmovement 0
	msgbox ElmsLab_Text_ElmAftermath, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TRINITY_JOHTO_SCENE_NEWBARK, 4
	releaseall
	end

@ ============================================================================
@ Talk scripts
@ ============================================================================
ElmsLab_EventScript_Elm::
	lock
	faceplayer
	goto_if_eq VAR_TRINITY_JOHTO_SCENE_NEWBARK, 1, ElmsLab_EventScript_ElmPostIntro
	goto_if_eq VAR_TRINITY_JOHTO_SCENE_NEWBARK, 2, ElmsLab_EventScript_ElmUrgent
	msgbox ElmsLab_Text_ElmIdle, MSGBOX_DEFAULT
	release
	end

ElmsLab_EventScript_ElmPostIntro::
	msgbox ElmsLab_Text_ElmPostIntro, MSGBOX_DEFAULT
	release
	end

ElmsLab_EventScript_ElmUrgent::
	msgbox ElmsLab_Text_ElmUrgent, MSGBOX_DEFAULT
	release
	end

@ Three states, adapted from GSC's AideText_AlwaysBusy / AideText_TheftTestimony
@ / AideText_AfterTheft.
ElmsLab_EventScript_Aide::
	lock
	faceplayer
	goto_if_eq VAR_TRINITY_JOHTO_SCENE_NEWBARK, 2, ElmsLab_EventScript_AideTestimony
	goto_if_eq VAR_TRINITY_JOHTO_SCENE_NEWBARK, 3, ElmsLab_EventScript_AideTestimony
	goto_if_eq VAR_TRINITY_JOHTO_SCENE_NEWBARK, 4, ElmsLab_EventScript_AideAfter
	msgbox ElmsLab_Text_AideBusy, MSGBOX_DEFAULT
	release
	end

ElmsLab_EventScript_AideTestimony::
	msgbox ElmsLab_Text_AideTestimony, MSGBOX_DEFAULT
	release
	end

ElmsLab_EventScript_AideAfter::
	msgbox ElmsLab_Text_AideAfter, MSGBOX_DEFAULT
	release
	end

@ Talking to the OFFICER before stepping onto the aftermath trigger.
ElmsLab_EventScript_Officer::
	msgbox ElmsLab_Text_OfficerWaiting, MSGBOX_NPC
	end

@ GSC ElmsLabWindow: two states either side of the break-in.
ElmsLab_EventScript_Window::
	goto_if_ge VAR_TRINITY_JOHTO_SCENE_NEWBARK, 2, ElmsLab_EventScript_WindowBroken
	msgbox ElmsLab_Text_Window, MSGBOX_SIGN
	end

ElmsLab_EventScript_WindowBroken::
	msgbox ElmsLab_Text_WindowBroken, MSGBOX_SIGN
	end

ElmsLab_EventScript_TravelTip1::
	msgbox ElmsLab_Text_TravelTip1, MSGBOX_SIGN
	end

ElmsLab_EventScript_TravelTip2::
	msgbox ElmsLab_Text_TravelTip2, MSGBOX_SIGN
	end

ElmsLab_EventScript_TravelTip3::
	msgbox ElmsLab_Text_TravelTip3, MSGBOX_SIGN
	end

ElmsLab_EventScript_TravelTip4::
	msgbox ElmsLab_Text_TravelTip4, MSGBOX_SIGN
	end

ElmsLab_EventScript_Trashcan::
	msgbox ElmsLab_Text_Trashcan, MSGBOX_SIGN
	end

@ ============================================================================
@ Movement
@ ============================================================================
@ (4,8) -> (4,4): four tiles up the two-wide exit corridor, ending east of ELM
@ and turned to face him.
ElmsLab_Movement_PlayerToElmWest:
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

@ (5,8) -> (5,4) -> (4,4), already facing west.
ElmsLab_Movement_PlayerToElmEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

ElmsLab_Movement_ElmNotices:
	emote_exclamation_mark
	delay_16
	face_right
	step_end

@ (4,6) -> (5,6): normalise into SILVER's shove lane.
ElmsLab_Movement_PlayerStepEast:
	walk_right
	step_end

@ (5,4) -> (4,4): normalise between ELM and the arriving OFFICER.
ElmsLab_Movement_PlayerStepWest:
	walk_left
	step_end

ElmsLab_Movement_PlayerFaceNorth:
	face_up
	step_end

ElmsLab_Movement_PlayerFaceEast:
	face_right
	step_end

ElmsLab_Movement_PlayerFaceWest:
	face_left
	step_end

ElmsLab_Movement_ElmAlarmed:
	emote_exclamation_mark
	delay_16
	face_up
	step_end

@ (5,1) -> (5,5): down the window alcove and the open lab floor, stopping one
@ tile north of the player at (5,6). ELM rests at (3,4), so this column is
@ clear end to end.
ElmsLab_Movement_SilverDropsIn:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ GSC's shove (fix_facing + jump_step): the player is knocked sideways out of
@ the corridor lane, still facing SILVER. (5,6) -> (4,6), both decoded walkable.
ElmsLab_Movement_PlayerShovedAside:
	lock_facing_direction
	jump_left
	unlock_facing_direction
	step_end

@ (5,5) -> (5,11): straight down the now-clear column and out the lab door.
ElmsLab_Movement_SilverBoltsForTheDoor:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

@ (5,3) -> (5,4): steps down beside the player at (4,4) and turns to face them.
ElmsLab_Movement_OfficerApproaches:
	walk_down
	face_left
	step_end

@ (5,4) -> (5,11): out through the lab door.
ElmsLab_Movement_OfficerLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ ============================================================================
@ Text
@ ============================================================================
ElmsLab_Text_ElmIntro:
	.string "ELM: You're here. You're actually\n"
	.string "here.\p"
	.string "I'm PROF.ELM -- forgive the\n"
	.string "shouting, I've been waiting on\l"
	.string "this all month.\p"
	.string "I study how POKéMON grow strong.\n"
	.string "Not numbers on a chart. Strength.\l"
	.string "The kind that wins a LEAGUE.\p"
	.string "And you walked out of HOENN with\n"
	.string "it, {PLAYER}.$"

ElmsLab_Text_ElmStudiesYourTeam:
	.string "ELM: May I? Just a look.\p"
	.string "………\p"
	.string "Extraordinary. Every one of them\n"
	.string "reads higher than my best case.\p"
	.string "Whatever you did out there, you\n"
	.string "did it right. Thank you.$"

ElmsLab_Text_ElmRadioCard:
	.string "ELM: I can't pay you for your\n"
	.string "time, but I can be useful.\p"
	.string "Hand me your POKéNAV a moment.\p"
	.string "…There. A RADIO CARD.\p"
	.string "Every JOHTO broadcast, straight to\n"
	.string "your device. LEAGUE results, the\l"
	.string "GOLDENROD talk shows, storm\l"
	.string "warnings.\p"
	.string "This region runs on its radio.\n"
	.string "If something ever goes wrong in\l"
	.string "JOHTO, you'll hear it there first.$"

ElmsLab_Text_ElmMrPokemon:
	.string "ELM: Oh -- one more thing.\p"
	.string "A friend of mine, MR.POKéMON,\n"
	.string "keeps a house up on ROUTE 30,\l"
	.string "past CHERRYGROVE.\p"
	.string "He collects oddities, and he's\n"
	.string "been writing to me about one for\l"
	.string "weeks now.\p"
	.string "If you pass by, humor him. He\n"
	.string "gets very few visitors.$"

ElmsLab_Text_ElmPostIntro:
	.string "ELM: Take your time. I'll be here\n"
	.string "writing this up.$"

ElmsLab_Text_ElmWhatWasThat:
	.string "ELM: …What was that?$"

ElmsLab_Text_SilverTakesFeraligatr:
	.string "SILVER: ………\p"
	.string "A FERALIGATR. Fully raised.\p"
	.string "Wasted on a man who writes papers\n"
	.string "about it.$"

ElmsLab_Text_ElmPutThatDown:
	.string "ELM: Stop -- that's eleven years\n"
	.string "of work! Put that BALL down!$"

ElmsLab_Text_SilverMove:
	.string "SILVER: The CHAMPION. Of course.\p"
	.string "Move.$"

ElmsLab_Text_ElmHeTookFeraligatr:
	.string "ELM: He took it. He took\n"
	.string "FERALIGATR.\p"
	.string "Out my own window.\p"
	.string "{PLAYER} -- he went west, toward\n"
	.string "CHERRYGROVE. Please.\p"
	.string "I'm not asking you as a\n"
	.string "researcher.$"

ElmsLab_Text_ElmUrgent:
	.string "ELM: West. He went west.\n"
	.string "Please hurry.$"

ElmsLab_Text_ElmAftermath:
	.string "ELM: You went after him. You\n"
	.string "didn't have to.\p"
	.string "I can't get FERALIGATR back with\n"
	.string "a report and a badge number, but\l"
	.string "you can go where I can't.\p"
	.string "He's climbing. Boys like that\n"
	.string "always climb.\p"
	.string "So climb faster. Start at VIOLET\n"
	.string "CITY -- FALKNER's GYM is the\l"
	.string "closest one, up past CHERRYGROVE.\p"
	.string "Eight badges in JOHTO. You'll\n"
	.string "meet him again long before the\l"
	.string "eighth.$"

ElmsLab_Text_ElmIdle:
	.string "ELM: Eight GYMS, {PLAYER}. Every\n"
	.string "one of them will tell you JOHTO\l"
	.string "trains differently than HOENN.\p"
	.string "They're right, annoyingly.$"

ElmsLab_Text_AideBusy:
	.string "There are only two of us in this\n"
	.string "LAB, so we're always busy.\p"
	.string "The PROFESSOR hasn't slept right\n"
	.string "since your ship docked at OLIVINE.$"

ElmsLab_Text_AideTestimony:
	.string "There was a crash, and then he was\n"
	.string "just… in the room.\p"
	.string "He went straight to the case. He\n"
	.string "knew exactly which BALL he wanted.\p"
	.string "…That FERALIGATR trusted people.\n"
	.string "I hope it still does.$"

ElmsLab_Text_AideAfter:
	.string "They say a POKéMON raised by a\n"
	.string "bad person turns out bad too.\p"
	.string "I don't believe it. Not that one.$"

ElmsLab_Text_OfficerWaiting:
	.string "OFFICER: A theft. In NEW BARK.\p"
	.string "Give me a moment with the\n"
	.string "PROFESSOR and I'll want a word\l"
	.string "with you.$"

ElmsLab_Text_OfficerQuestions:
	.string "OFFICER: A POKéMON stolen out of\n"
	.string "a research lab. In NEW BARK.\p"
	.string "Young man. Long red hair. Very\n"
	.string "poor manners.\p"
	.string "…You battled him? Did you happen\n"
	.string "to get a name?$"

ElmsLab_Text_OfficerGotTheName:
	.string "OFFICER: SILVER. Right.\p"
	.string "That's more than PROF.ELM could\n"
	.string "give me. Thank you.\p"
	.string "We'll circulate it. Though if he\n"
	.string "puts real road behind him on that\l"
	.string "FERALIGATR, he stops being NEW\l"
	.string "BARK's problem and starts being\l"
	.string "all of JOHTO's.$"

ElmsLab_Text_Window:
	.string "The window is open.\p"
	.string "A pleasant breeze is blowing in.$"

ElmsLab_Text_WindowBroken:
	.string "He came in through here.$"

ElmsLab_Text_TravelTip1:
	.string "{PLAYER} opened a\nbook.\pTravel Tip 1:\pPress START to\nopen the MENU.$"

ElmsLab_Text_TravelTip2:
	.string "{PLAYER} opened a\nbook.\pTravel Tip 2:\pRecord your trip\nwith SAVE!$"

ElmsLab_Text_TravelTip3:
	.string "{PLAYER} opened a\nbook.\pTravel Tip 3:\pOpen your PACK and\npress SELECT to\lmove items.$"

ElmsLab_Text_TravelTip4:
	.string "{PLAYER} opened a\nbook.\pTravel Tip 4:\pCheck your POKéMON\nmoves. Press the\pA Button to switch\nmoves.$"

ElmsLab_Text_Trashcan:
	.string "The wrapper from\nthe snack PROF.ELM\late is in there…$"
