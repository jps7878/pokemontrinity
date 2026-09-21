BurnedTower1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, BurnedTower1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, BurnedTower1F_SetHoleWarp
	.byte 0

BurnedTower1F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_BURNED_TOWER_B1F
	end

@ ============================================================================
@ Trinity M4b S5 -- THE BURNED TOWER, 1F.
@
@ ON_TRANSITION is the SINGLE AUTHORITY for both visibility flags (S1 rule);
@ the scene body never writes them, and it never removeobject's either actor,
@ so R1's removeobject flag co-sign cannot fire on this map at all.
@   SILVER : visible while VAR_TRINITY_JOHTO_SCENE_ECRUTEAK == 0
@            AND VAR_TRINITY_JOHTO_ARC >= 2 (M7 Task 4, bug-test finding #2)
@   MORTY  : visible while VAR_TRINITY_JOHTO_SCENE_ECRUTEAK <  2
@
@ THE SLOT WAS ALREADY OCCUPIED. This map's ON_TRANSITION used to point straight
@ at CaveHole_FixCrackedGround (data/scripts/cave_hole.inc:5), and the slot is
@ SINGLE-OCCUPANCY -- MapHeaderGetScriptTable returns on the FIRST entry matching
@ the tag (src/script.c:302-321), so adding a second map_script line would have
@ been silent dead code (S4 pin I3(a)). The entry is therefore replaced by the
@ script below, which tails into the vanilla one with `goto` (not `call`:
@ CaveHole_FixCrackedGround ends with `end`, not `return`).
@ ============================================================================
BurnedTower1F_OnTransition:
	call BurnedTower1F_EventScript_SetSilverVisibility
	call BurnedTower1F_EventScript_SetMortyVisibility
	goto CaveHole_FixCrackedGround

@ M7 Task 4 (bug-test finding #2). The scene var alone is 0 from the moment of
@ arrival in JOHTO, so SILVER 3 -- who is fielding the FERALIGATR he stole from
@ ELM's lab -- used to fire for a player who walked to ECRUTEAK before ever
@ meeting ELM. ARC 2 is the theft (ElmsLab's second arc write), so the lower
@ bound is ARC >= 2: below it he is not in the tower at all. The same read
@ guards both script entries below (the coord scene and the talk script), so a
@ save that holds scene 0 with ARC < 2 sees no SILVER and runs no scene.
BurnedTower1F_EventScript_SetSilverVisibility::
	goto_if_lt VAR_TRINITY_JOHTO_ARC, 2, BurnedTower1F_EventScript_HideSilver
	goto_if_eq VAR_TRINITY_JOHTO_SCENE_ECRUTEAK, 0, BurnedTower1F_EventScript_ShowSilver
BurnedTower1F_EventScript_HideSilver::
	setflag FLAG_TRINITY_J_SILVER_BURNED_HIDE
	return

BurnedTower1F_EventScript_ShowSilver::
	clearflag FLAG_TRINITY_J_SILVER_BURNED_HIDE
	return

BurnedTower1F_EventScript_SetMortyVisibility::
	goto_if_ge VAR_TRINITY_JOHTO_SCENE_ECRUTEAK, 2, BurnedTower1F_EventScript_HideMorty
	clearflag FLAG_TRINITY_J_MORTY_TOWER_HIDE
	return

BurnedTower1F_EventScript_HideMorty::
	setflag FLAG_TRINITY_J_MORTY_TOWER_HIDE
	return

@ ============================================================================
@ TRAINER_SILVER_3 -- adapts pokecrystal BurnedTowerRivalBattleScript
@ (BurnedTower1F.asm:41-102), following S1's hardened SILVER pattern and S3's
@ AzaleaTown implementation clause for clause.
@
@ TRIGGER PLACEMENT (decoded from map.bin + metatile_attributes.bin). The hole
@ chamber is row 9 x=7..12 plus row 10 x=7..11. Its ONLY entrance is
@ (12,9) -> (11,9): (12,10) and (10,8) decode collision 1, and the (7,5..9)
@ column is a dead-end spur hanging off the room. So (11,9) is a mandatory tile
@ AND a cut vertex for the hole at (10,9) itself -- it cannot be walked around,
@ and it is GSC's own trigger tile. The chokepoint is one tile wide, so this
@ trigger needs no partner (S1's coord-pair rule spans the full width, and the
@ full width here is 1).
@
@ THE PLAYER IS NEVER MOVED. GSC walks the player one step left, onto (10,9) --
@ which in THIS build is the live MB_CRACKED_FLOOR_HOLE tile with
@ STEP_CB_CRACKED_FLOOR armed by BurnedTower1F_SetHoleWarp above. Stepping a
@ locked player onto an armed hole tile is precisely the interaction this
@ milestone's gate (clean compile + review, no play-tests) cannot check, so the
@ scene keeps the player on (11,9) and walks SILVER one tile east to (9,9)
@ instead. The crack then sits between them, which is better staging anyway.
@
@ CAMERA: player locked at (11,9) => rows 5..14, columns 4..18. SILVER's home
@ tile (8,9) and his single step to (9,9) are both inside it.
@
@ M7 Task 4 (finding #2), THE THIRD SITE. The coord_event at (11,9) keys on
@ VAR_TRINITY_JOHTO_SCENE_ECRUTEAK == 0 alone (a map.json trigger tests one
@ var), so without the read below a pre-theft player stepping onto the
@ chokepoint would run the confrontation against a SILVER that ON_TRANSITION
@ has just hidden -- a trainer battle with nobody on screen. Below ARC 2 the
@ trigger is a silent no-op: no lock, no text, nothing written. It re-tests on
@ every step onto the tile, which costs nothing.
@ ============================================================================
BurnedTower1F_EventScript_SilverScene::
	goto_if_lt VAR_TRINITY_JOHTO_ARC, 2, BurnedTower1F_EventScript_SilverNotYet
	lockall
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_JOHTO_BT1F_SILVER, BurnedTower1F_Movement_SilverTurnsOnYou
	waitmovement 0
	call BurnedTower1F_EventScript_SilverConfront
	@ `goto`, not `call`: the aftermath ends in a warp, so it never returns.
	goto BurnedTower1F_EventScript_SilverAftermath
	end

@ Finding #2's pre-theft landing for the coord trigger: SILVER is hidden, so
@ there is nothing to stage. Deliberately no message -- a coord script re-fires
@ on every step onto its tile, and a line here would nag.
BurnedTower1F_EventScript_SilverNotYet::
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE. SILVER rests at (8,9), inside the hole
@ chamber whose sole entrance is (12,9) -> (11,9), and (11,9) carries the coord
@ trigger above. There is no approach that reaches him with the scene var still
@ 0 without firing the scene first -- including after a white-out, which returns
@ the player to a POKEMON CENTER outside the tower entirely. Implemented anyway
@ per S1: a talk script that starts a battle and advances story state carries an
@ explicit state guard even when a visibility invariant already covers it.
@ The ARC < 2 read is finding #2's guard at its second site: ON_TRANSITION
@ already hides him below ARC 2, so this too is defensive, and it routes to the
@ neutral idle line rather than a new one.
@ No movement script here: on this path the player's tile is unknown, and
@ walking SILVER into an occupied tile is the documented failure mode (S4).
BurnedTower1F_EventScript_Silver::
	lock
	faceplayer
	goto_if_ne VAR_TRINITY_JOHTO_SCENE_ECRUTEAK, 0, BurnedTower1F_EventScript_SilverIdle
	goto_if_lt VAR_TRINITY_JOHTO_ARC, 2, BurnedTower1F_EventScript_SilverIdle
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
	call BurnedTower1F_EventScript_SilverConfront
	@ `goto`, not `call`: the aftermath ends in a warp, so it never returns.
	goto BurnedTower1F_EventScript_SilverAftermath
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE: once the aftermath advances the scene
@ var, ON_TRANSITION hides SILVER on every later entry, and below ARC 2 it never
@ showed him (finding #2), so on neither route is there an object to talk to.
BurnedTower1F_EventScript_SilverIdle::
	msgbox BurnedTower1F_Text_SilverIdle, MSGBOX_DEFAULT
	release
	end

@ Shared by both paths. Calling `trainerbattle_no_intro` from a call-ed subscript
@ of a lockall-ed scene is vanilla (MauvilleCity_EventScript_BattleWally does the
@ same), and unlike `trainerbattle_single` this form does NOT supply its own lock,
@ which is what makes it correct inside a scene that already locked.
@ setvar VAR_LAST_TALKED pins the engine's Movement_RevealTrainer emote on SILVER
@ rather than on whatever object was last spoken to; GSC does the same with
@ `setlasttalked BURNEDTOWER1F_RIVAL` (BurnedTower1F.asm:66).
@ Battle BGM needs no scripting: TRAINER_SILVER_3 is TRAINER_CLASS_RIVAL with a
@ name other than WALLY, so GetBattleBGM() returns MUS_VS_RIVAL.
BurnedTower1F_EventScript_SilverConfront::
	msgbox BurnedTower1F_Text_SilverIntro, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_JOHTO_BT1F_SILVER
	trainerbattle_no_intro TRAINER_SILVER_3, BurnedTower1F_Text_SilverDefeat
	setflag FLAG_TRINITY_J_SILVER3_BEATEN
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
	msgbox BurnedTower1F_Text_SilverAfter, MSGBOX_DEFAULT
	closemessage
	return

@ The floor gives way -- GSC's beat, minus GSC's changeblock (M4a baked the hole
@ metatile in permanently, so there is nothing to open).
@ ORDERING: the scene var is written BEFORE the warp, so BurnedTowerB1F's
@ ON_TRANSITION spawns the beast cast on the very map load the player falls into
@ (S4 pin I3(b) read forwards -- a state write after a visibility call lags the
@ flip by a whole map load).
@ SILVER is deliberately NOT removeobject'd: the scene var is already 1, so
@ ON_TRANSITION hides him on the next entry to 1F. That sidesteps R1's
@ removeobject flag co-sign completely.
@ The scripted fall copies M4a's own in-repo precedent verbatim
@ (EcruteakGym_EventScript_Fall): delay, SE_FALL, warp, waitstate. It lands on
@ (10,9), GSC's landing tile, which decodes collision 0 elevation 3 on B1F.
BurnedTower1F_EventScript_SilverAftermath::
	setvar VAR_TRINITY_JOHTO_SCENE_ECRUTEAK, 1
	fadedefaultbgm
	special HealPlayerParty
	delay 30
	playse SE_M_EARTHQUAKE
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BurnedTower1F_Text_FloorGivesWay, MSGBOX_DEFAULT
	msgbox BurnedTower1F_Text_SilverParting, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_FALL
	warp MAP_BURNED_TOWER_B1F, 10, 9
	waitstate
	end

@ (8,9) -> (9,9): one tile east along row 9, every tile decoded collision 0,
@ stopping with the crack at (10,9) between SILVER and the player at (11,9).
BurnedTower1F_Movement_SilverTurnsOnYou:
	face_right
	delay_16
	walk_right
	step_end

@ ============================================================================
@ MORTY, in the tower he has been studying all his life. GSC's tile (14,14),
@ GSC's role (BurnedTower1FMortyScript). EUSINE is skipped this slice -- he is
@ the SUICUNE-chase character and his payoff is S10's -- so MORTY carries the
@ whole "someone is watching this tower" thread on his own.
@ MOVEMENT_TYPE_LOOK_AROUND rather than GSC's WANDER 1,1: a wandering NPC
@ defeats reach_check (which models a resting tile) and could drift onto one of
@ this floor's dead G/S warp tiles.
@ ============================================================================
BurnedTower1F_EventScript_Morty::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_SILVER3_BEATEN, BurnedTower1F_EventScript_MortyAfterSilver
	msgbox BurnedTower1F_Text_Morty, MSGBOX_DEFAULT
	release
	end

BurnedTower1F_EventScript_MortyAfterSilver::
	msgbox BurnedTower1F_Text_MortyAfterSilver, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ Text
@ ============================================================================
@ Adapts pokecrystal BurnedTowerRival_BeforeText. GSC's SILVER came here hunting
@ the legendary POKeMON and found nothing; Act II keeps the grievance and swaps
@ the target -- the person he cannot get past is standing in front of him.
BurnedTower1F_Text_SilverIntro:
	.string "…\p"
	.string "Of course it's you.\p"
	.string "They say something legendary roosts\n"
	.string "in these towers. I came to take it.\p"
	.string "There is NOTHING here. Ash and a\n"
	.string "hole in the floor.\p"
	.string "All that trouble, and the only thing\n"
	.string "in this dump worth beating is you.$"

@ GSC BurnedTowerRival_WinText.
BurnedTower1F_Text_SilverDefeat:
	.string "…Humph!\p"
	.string "This is why I hate battling wimps.\n"
	.string "There's no challenge in it.$"

@ GSC BurnedTowerRival_AfterText1.
BurnedTower1F_Text_SilverAfter:
	.string "…Aw, whatever.\p"
	.string "You would never be able to catch a\n"
	.string "legendary POKéMON anyway.$"

BurnedTower1F_Text_FloorGivesWay:
	.string "The whole tower shuddered.\p"
	.string "The burned floor split open under\n"
	.string "{PLAYER}'s feet!$"

@ GSC BurnedTowerRival_AfterText2.
BurnedTower1F_Text_SilverParting:
	.string "SILVER: Humph!\p"
	.string "What are you doing falling into a\n"
	.string "hole? Some genius you are!\p"
	.string "Serves you right!$"

BurnedTower1F_Text_SilverIdle:
	.string "SILVER: Don't waste my time.$"

@ Adapts pokecrystal BurnedTower1FMortyText. GSC's MORTY is investigating the
@ tower with EUSINE; with EUSINE deferred to S10, the same information comes
@ from MORTY alone.
BurnedTower1F_Text_Morty:
	.string "MORTY: ECRUTEAK's GYM LEADER has to\n"
	.string "study what are said to be the\l"
	.string "legendary POKéMON.\p"
	.string "SUICUNE, ENTEI and RAIKOU.\p"
	.string "Three lives that ended in this tower\n"
	.string "and did not stay ended.\p"
	.string "They are down there. Under the ash,\n"
	.string "under the floor, asleep.\p"
	.string "I have never once been able to see\n"
	.string "them. Perhaps I am not the one who\l"
	.string "is meant to.$"

BurnedTower1F_Text_MortyAfterSilver:
	.string "MORTY: That boy came through here in\n"
	.string "a temper and left in a worse one.\p"
	.string "He is looking for the same thing I\n"
	.string "am, and he is looking at it wrong.\p"
	.string "Mind the floor, CHAMPION. This place\n"
	.string "has been waiting a long time.$"
