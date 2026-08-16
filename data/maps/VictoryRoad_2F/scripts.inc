@ ============================================================================
@ M4b S11 -- VICTORY ROAD 2F: two league-run trainers and SILVER's fifth and
@ last battle.
@
@ WHY HERE. S9's DRAGON'S DEN coda ends "VICTORY ROAD. Before the PLATEAU. /
@ I'll be waiting, and I won't be the same."
@ (data/maps/DragonsDenB1F/scripts.inc:141-153, written for S11 to collect on.)
@ 2F's north-east chamber is the last room in the dungeon; through (48,12) is
@ ROUTE 23 and then the PLATEAU.
@
@ THE TRIGGER TILE IS FORCED, AND THE PROOF IS THE BEHAVIOUR, NOT THE SHAPE.
@ The exit warp (48,12) is MB_SOUTH_ARROW_WARP. IsArrowWarpMetatileBehavior
@ (src/field_control_avatar.c:941) only fires on a move in the arrow's own
@ direction, so although (47,12) and (49,12) are walkable, stepping onto (48,12)
@ from either side warps nothing. (48,11) -- directly north of it -- is the ONLY
@ tile from which the player can leave this dungeon, so one coord_event there is
@ unavoidable. Camera: with the player pinned on (48,11) the window is
@ x 36..50, y 7..16, and every tile the choreography touches is inside it.
@
@ EVERY COORD_EVENT MUST OWN THE STATE IT CONSUMES (S8). The var is
@ VAR_TRINITY_JOHTO_SCENE_INDIGO == 0, which is the value every save that can
@ stand here actually holds (the ELITE FOUR machine has not started), and the
@ once-only guard is the flag on line one -- the scene's own durable output --
@ not the var, because the var is RESET to 0 every time the player enters the
@ INDIGO Center.
@
@ SILVER's visibility has ONE authoring site, below, keyed on the same flag. The
@ removeobject in the scene co-signs that flag (R1;
@ RemoveObjectEventByLocalIdAndMap -> FlagSet, src/event_object_movement.c:
@ 1537-1545), which is intended here: he is a cast of one and he retires for good.
@ ============================================================================

VictoryRoad_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_2F_OnTransition
	.byte 0

VictoryRoad_2F_OnTransition:
	goto_if_set FLAG_TRINITY_J_SILVER5_BEATEN, VictoryRoad_2F_EventScript_HideSilver
	clearflag FLAG_TRINITY_J_VR_SILVER_HIDE
	end

VictoryRoad_2F_EventScript_HideSilver::
	setflag FLAG_TRINITY_J_VR_SILVER_HIDE
	end

VictoryRoad_2F_EventScript_SilverScene::
	goto_if_set FLAG_TRINITY_J_SILVER5_BEATEN, VictoryRoad_2F_EventScript_SilverDone
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_JOHTO_VR2F_SILVER, VictoryRoad_2F_Movement_SilverApproach
	waitmovement 0
	msgbox VictoryRoad_2F_Text_SilverBefore, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_JOHTO_VR2F_SILVER
	trainerbattle_no_intro TRAINER_SILVER_5, VictoryRoad_2F_Text_SilverDefeat
	msgbox VictoryRoad_2F_Text_SilverAfter, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_TRINITY_J_SILVER5_BEATEN
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_JOHTO_VR2F_SILVER
	fadescreen FADE_FROM_BLACK
	fadedefaultbgm
	releaseall
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE. The coord_event is gated on
@ SCENE_INDIGO == 0, and the scene's own flag short-circuits it here, so a save
@ that has beaten SILVER 5 never reaches the body below this label. Kept because
@ the var is reset by the INDIGO Center and a flag is the only durable guard.
VictoryRoad_2F_EventScript_SilverDone::
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE. SILVER's object is TRAINER_TYPE_NONE
@ with sight 0 and rests at (45,11), three tiles west of the only approach; the
@ coord_event fires before the player can reach him. S1's rule: a story object
@ still carries a script rather than 0x0.
VictoryRoad_2F_EventScript_SilverIdle::
	msgbox VictoryRoad_2F_Text_SilverIdle, MSGBOX_NPC
	end

VictoryRoad_2F_EventScript_TERRELL::
	trainerbattle_single TRAINER_VR_COOLTRAINER_M_2, VictoryRoad_2F_Text_TERRELLSeen, VictoryRoad_2F_Text_TERRELLBeaten
	msgbox VictoryRoad_2F_Text_TERRELLAfter, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_EventScript_KYRA::
	trainerbattle_single TRAINER_VR_COOLTRAINER_F_2, VictoryRoad_2F_Text_KYRASeen, VictoryRoad_2F_Text_KYRABeaten
	msgbox VictoryRoad_2F_Text_KYRAAfter, MSGBOX_AUTOCLOSE
	end

VictoryRoad_2F_Movement_SilverApproach:
	walk_right
	walk_right
	step_end

@ GSC's VictoryRoadRivalBeforeText is a boast ("You're so much weaker than I am.
@ I'm invincible!"). Trinity's SILVER cannot be: S9's DRAGON'S DEN coda already
@ turned him, and S8's RADIO TOWER told the whole region whose name was on the
@ paperwork. He is early, he is calm, and he says exactly what he came to say.
VictoryRoad_2F_Text_SilverBefore:
	.string "…You took your time.\p"
	.string "I've been up here four days. I\n"
	.string "wanted the last room, so I'd know\l"
	.string "you couldn't walk past me.\p"
	.string "I'm not going to tell you I'm\n"
	.string "invincible. I used to say that.\p"
	.string "Here's what I'll say instead.\p"
	.string "I trained. I know what I have and\n"
	.string "what I don't.\p"
	.string "Now show me the difference.$"

@ GSC VictoryRoadRivalDefeatText, kept almost whole. LANCE is four rooms away
@ and the callback lands.
VictoryRoad_2F_Text_SilverDefeat:
	.string "…I couldn't win.\p"
	.string "I gave it everything I had.\p"
	.string "What you have, and what I don't…\p"
	.string "I'm beginning to understand what\n"
	.string "that dragon master said to me.$"

@ THE ARC TURN, and the act's hand-off to Act III. The design spec: SILVER is
@ GIOVANNI's son, the RADIO TOWER reveal detonates his storyline, and he hunts
@ GIOVANNI into KANTO. GIOVANNI's own exit line was "Come east when you're
@ finished" (RadioTower5F_Text_Giovanni2); this is what it cost somebody.
VictoryRoad_2F_Text_SilverAfter:
	.string "SILVER: Don't say anything.\p"
	.string "…\p"
	.string "You were in that room. On the\n"
	.string "fifth floor. You heard the name\l"
	.string "he gave you.\p"
	.string "I heard it on the radio, in a\n"
	.string "POKéMON CENTER, standing up.\p"
	.string "GIOVANNI.\p"
	.string "Three years he's been gone. Three\n"
	.string "years I've been telling people I\l"
	.string "don't have a father.\p"
	.string "…He told you to come east.\p"
	.string "So go. Take the LEAGUE first --\n"
	.string "you've earned that, and I'm not\l"
	.string "going to stand in the door.\p"
	.string "But I'll be over the border\n"
	.string "before you are.\p"
	.string "He's mine to find.$"

VictoryRoad_2F_Text_SilverIdle:
	.string "…$"

VictoryRoad_2F_Text_TERRELLSeen:
	.string "Second floor. Halfway.\p"
	.string "Everybody who quits, quits here.$"

VictoryRoad_2F_Text_TERRELLBeaten:
	.string "…And that's why they quit.$"

VictoryRoad_2F_Text_TERRELLAfter:
	.string "The way out is the far end of\n"
	.string "this floor -- but you can't reach\l"
	.string "it from this side.\p"
	.string "Up to the third floor, across,\n"
	.string "and back down. That's the road.$"

VictoryRoad_2F_Text_KYRASeen:
	.string "You're not lost, are you.\p"
	.string "People come up here on purpose\n"
	.string "and I never understand it.$"

VictoryRoad_2F_Text_KYRABeaten:
	.string "Right. On purpose.$"

VictoryRoad_2F_Text_KYRAAfter:
	.string "Heal up before the last stretch.\p"
	.string "There's a POKéMON CENTER at the\n"
	.string "PLATEAU, but once you're through\l"
	.string "the LEAGUE's front door there\l"
	.string "isn't another one.$"
