@ GIOVANNI's office door, decoded from data/layouts/TeamRocketBaseB3F_Johto/
@ map.bin. 640-643 is GSC's SHUT door block on tiles (10,8) (11,8) (10,9)
@ (11,9); the BOTTOM half is the collision-1 pair, which is the mirror of B2F's
@ (there the top half is solid), so the two doors are approached from opposite
@ sides. 540-543 is the same plain FLOOR block B2F uses, taken here from
@ (10,6)/(10,7). Y-parity: 540/541 for the even row, 542/543 for the odd one.
	.set METATILE_JohtoRocketBase_FloorTL,        540
	.set METATILE_JohtoRocketBase_FloorTR,        541
	.set METATILE_JohtoRocketBase_FloorBL,        542
	.set METATILE_JohtoRocketBase_FloorBR,        543

TeamRocketBaseB3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TeamRocketBaseB3F_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TeamRocketBaseB3F_OnLoad
	.byte 0

@ ============================================================================
@ Trinity M4b S7 -- TEAM ROCKET BASE B3F. Adapts pokecrystal
@ maps/TeamRocketBaseB3F.asm. ROCKET-POST PATTERN R1-R5.
@
@ THE FLOOR IS THREE REGIONS, decoded with reach_check --dungeon:
@   EAST  212 tiles, stairs (27,2) and (27,14). The first place the player
@         reaches from B2F, and where LANCE, both password grunts and both
@         scientists are.
@   WEST   58 tiles, stairs (3,2) and (3,6). A single corridor, reached only by
@         going B2F -> B3F east -> B2F top strip -> B3F west. SILVER's cameo and
@         the office door are here.
@   OFFICE 51 tiles, walkable but UNREACHABLE in the shipped port -- GIOVANNI's
@         empty office, behind the door M4a never opened.
@ The base is a chain, not a corridor, and that is GSC's design; the survey's
@ "blocked warps" are these two sealed rooms, not sealed warps.
@
@ ON_TRANSITION authors four flags (S1 rule):
@   FLAG_TRINITY_J_BASE_CAST_HIDE       visible iff ARC == 4  (5 objects here)
@   FLAG_TRINITY_J_BASE_PETREL_HIDE     visible iff ARC == 4  (PETREL, MURKROW)
@   FLAG_TRINITY_J_BASE_LANCE_B3F_HIDE  visible iff ARC == 4
@   FLAG_TRINITY_J_BASE_SILVER_HIDE     SET on every transition -- SILVER is an
@                                       addobject-only cutscene actor (S1/S3
@                                       idiom), so he needs no new-game default
@                                       and can never spawn from the template.
@ PETREL and the MURKROW share a flag because they share a fate: GSC's exec runs
@ for the stairs and the bird stays, but the bird's whole function is to hand
@ over the password he was guarding, and a MURKROW alone in an empty office
@ after the base has fallen is set dressing nobody asked for.
@ ============================================================================
@ D2 SLOT NOTE (M4b S9 fix round -- systemic, applied to all eight Trinity
@ metatile authors). Metatile authoring MUST live in MAP_SCRIPT_ON_LOAD, never
@ MAP_SCRIPT_ON_TRANSITION. RunOnTransitionMapScript() runs IMMEDIATELY BEFORE
@ InitMap() on both map-load paths (src/overworld.c:876-877, :945-954), and
@ InitMap -> InitMapLayoutData (src/fieldmap.c:96-103) CpuFastFill16s the whole
@ backup grid to MAPGRID_UNDEFINED and CpuCopy16s the ROM layout back over it --
@ so a setmetatile issued from ON_TRANSITION is erased before a single frame is
@ drawn. ON_LOAD is the LAST statement of InitMap (src/fieldmap.c:71), i.e. it
@ runs once the grid exists, AND of InitMapFromSavedGame (:80), so it also
@ covers continue-from-save, which ON_TRANSITION never runs on at all. Vanilla's
@ own metatile authors use exactly this slot (MauvilleCity_Gym, ShoalCave_*,
@ SootopolisCity_Gym_1F, AncientTomb). Still no DrawWholeMapView needed:
@ InitViewGraphics -> InitMapView -> DrawWholeMapView (src/overworld.c:575-580,
@ :2368) runs later in the same load. qa_sweep.py check 7 is the regression gate.
TeamRocketBaseB3F_OnLoad:
	call TeamRocketBaseB3F_EventScript_AuthorDoor
	end

TeamRocketBaseB3F_OnTransition:
	setflag FLAG_TRINITY_J_BASE_SILVER_HIDE
	goto_if_eq VAR_TRINITY_JOHTO_ARC, 4, TeamRocketBaseB3F_EventScript_ShowRaid
	setflag FLAG_TRINITY_J_BASE_CAST_HIDE
	setflag FLAG_TRINITY_J_BASE_PETREL_HIDE
	setflag FLAG_TRINITY_J_BASE_LANCE_B3F_HIDE
	end

TeamRocketBaseB3F_EventScript_ShowRaid::
	clearflag FLAG_TRINITY_J_BASE_CAST_HIDE
	clearflag FLAG_TRINITY_J_BASE_PETREL_HIDE
	clearflag FLAG_TRINITY_J_BASE_LANCE_B3F_HIDE
	end

@ D2. The shipped map.bin has this door SHUT, so the authoring direction is
@ OPEN. Authored from ON_LOAD (see the slot note above); still no
@ DrawWholeMapView, because the view is drawn later in the same load.
TeamRocketBaseB3F_EventScript_AuthorDoor::
	goto_if_set FLAG_TRINITY_J_DOOR_B3F, TeamRocketBaseB3F_EventScript_OpenDoorTiles
	return

TeamRocketBaseB3F_EventScript_OpenDoorTiles::
	setmetatile 10, 8, METATILE_JohtoRocketBase_FloorTL, FALSE
	setmetatile 11, 8, METATILE_JohtoRocketBase_FloorTR, FALSE
	setmetatile 10, 9, METATILE_JohtoRocketBase_FloorBL, FALSE
	setmetatile 11, 9, METATILE_JohtoRocketBase_FloorBR, FALSE
	return

@ ============================================================================
@ D1/D3/D4/D5 -- GIOVANNI'S OFFICE DOOR. Two BG_EVENT_PLAYER_FACING_NORTH signs
@ on the collision-1 tiles (10,9) and (11,9), read from (10,10) and (11,10) --
@ each has exactly one reading tile, both decoded collision 0 elevation 3, both
@ kept clear of objects (S5's I1 pin).
@
@ TWO passwords, not one, and NEITHER CAN BE MISSED. GSC guards both with
@ `endifjustbattled`, so the flag is set only when the player walks back and
@ speaks to the grunt a SECOND time; beat her and walk away and the password is
@ simply not learnt. That is dropped. Here the flag sits in the post-battle
@ continuation -- the bytes after the trainerbattle args, which
@ BattleSetup_GetScriptAddrAfterBattle runs BOTH immediately after the win and
@ again on every later talk (src/battle_setup.c:1405, :972) -- so the password
@ arrives with the line that contains it, and re-reading it costs nothing.
@ ============================================================================
TeamRocketBaseB3F_EventScript_OfficeDoor::
	lockall
	goto_if_set FLAG_TRINITY_J_DOOR_B3F, TeamRocketBaseB3F_EventScript_DoorAlreadyOpen
	goto_if_unset FLAG_TRINITY_J_PASSWORD_SLOWPOKETAIL, TeamRocketBaseB3F_EventScript_DoorNoPassword
	goto_if_unset FLAG_TRINITY_J_PASSWORD_RATICATE, TeamRocketBaseB3F_EventScript_DoorNoPassword
	msgbox TeamRocketBaseB3F_Text_DoorPasswords, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	setmetatile 10, 8, METATILE_JohtoRocketBase_FloorTL, FALSE
	setmetatile 11, 8, METATILE_JohtoRocketBase_FloorTR, FALSE
	setmetatile 10, 9, METATILE_JohtoRocketBase_FloorBL, FALSE
	setmetatile 11, 9, METATILE_JohtoRocketBase_FloorBR, FALSE
	special DrawWholeMapView
	waitse
	setflag FLAG_TRINITY_J_DOOR_B3F
	releaseall
	end

TeamRocketBaseB3F_EventScript_DoorNoPassword::
	msgbox TeamRocketBaseB3F_Text_DoorNoPassword, MSGBOX_DEFAULT
	releaseall
	end

TeamRocketBaseB3F_EventScript_DoorAlreadyOpen::
	msgbox TeamRocketBaseB3F_Text_DoorOpen, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@ The two password grunts. Ordinary sight-triggered posts (R2); the password is
@ set by the G2-shaped continuation, which is the re-talk path.
@ ============================================================================
TeamRocketBaseB3F_EventScript_GruntF::
	trainerbattle_single TRAINER_ROCKET_GRUNT_F_2, TeamRocketBaseB3F_Text_GruntFSeen, TeamRocketBaseB3F_Text_GruntFBeaten
	setflag FLAG_TRINITY_J_PASSWORD_SLOWPOKETAIL
	msgbox TeamRocketBaseB3F_Text_GruntFAfterBattle, MSGBOX_AUTOCLOSE
	end

TeamRocketBaseB3F_EventScript_GruntM::
	trainerbattle_single TRAINER_ROCKET_GRUNT_M_7, TeamRocketBaseB3F_Text_GruntMSeen, TeamRocketBaseB3F_Text_GruntMBeaten
	setflag FLAG_TRINITY_J_PASSWORD_RATICATE
	msgbox TeamRocketBaseB3F_Text_GruntMAfterBattle, MSGBOX_AUTOCLOSE
	end

TeamRocketBaseB3F_EventScript_Ross::
	trainerbattle_single TRAINER_JOHTO_ROCKET_SCI_ROSS, TeamRocketBaseB3F_Text_RossSeen, TeamRocketBaseB3F_Text_RossBeaten
	msgbox TeamRocketBaseB3F_Text_RossAfterBattle, MSGBOX_AUTOCLOSE
	end

TeamRocketBaseB3F_EventScript_Mitch::
	trainerbattle_single TRAINER_JOHTO_ROCKET_SCI_MITCH, TeamRocketBaseB3F_Text_MitchSeen, TeamRocketBaseB3F_Text_MitchBeaten
	msgbox TeamRocketBaseB3F_Text_MitchAfterBattle, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ EXEC PETREL, TALK-TRIGGERED at (8,3) inside the office (R2, and the same shape
@ as S3's PROTON). He is NOT a fake GIOVANNI and never claims to be -- that beat
@ belongs to the RADIO TOWER and to S8. GSC's EXECUTIVEM_4 is standing guard
@ over an office its owner vacated three years ago, which is a better scene and
@ is what ships here.
@
@ THE MURKROW IS THE POINT OF THE ROOM. It has heard the password often enough
@ to repeat it, and it will repeat it to anyone -- including the person who has
@ just knocked its keeper down. Beating PETREL is not what unlocks it; walking
@ up to the bird is. That is GSC exactly.
@ ============================================================================
TeamRocketBaseB3F_EventScript_Petrel::
	goto_if_set FLAG_TRINITY_J_PASSWORD_GIOVANNI, TeamRocketBaseB3F_EventScript_PetrelIdle
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	trainerbattle_single TRAINER_EXEC_PETREL, TeamRocketBaseB3F_Text_PetrelIntro, TeamRocketBaseB3F_Text_PetrelDefeat, TeamRocketBaseB3F_EventScript_PetrelBeaten, NO_MUSIC
	@ Re-talk path: he stays in the room (unlike GSC, where he flees down a
	@ 25-step route), because the MURKROW's line is what the player actually
	@ came for and a guard who has lost still has something to say about it.
	goto TeamRocketBaseB3F_EventScript_PetrelIdle
	end

TeamRocketBaseB3F_EventScript_PetrelBeaten::
	msgbox TeamRocketBaseB3F_Text_PetrelAfter, MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

@ I5. `playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE` is a MAP-BGM swap, not a jingle
@ (S2's G3 finding), and the only thing that puts the map's own music back is
@ `fadedefaultbgm`. The win path does that in PetrelBeaten; the RE-TALK path
@ reaches this label with the encounter track already playing and, without the
@ line below, would leave it playing for the rest of the visit. Guarding the
@ playbgm on the trainer flag would work too, but restoring here is the smaller
@ change and it also covers the run-away case.
TeamRocketBaseB3F_EventScript_PetrelIdle::
	lock
	faceplayer
	fadedefaultbgm
	msgbox TeamRocketBaseB3F_Text_PetrelIdle, MSGBOX_DEFAULT
	release
	end

TeamRocketBaseB3F_EventScript_Murkrow::
	lock
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	waitmoncry
	msgbox TeamRocketBaseB3F_Text_Murkrow, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_J_PASSWORD_GIOVANNI
	release
	end

@ ============================================================================
@ LANCE's B3F cameo, at (25,14), two tiles from the (27,14) staircase the player
@ arrives on, standing over the ROCKET he has just beaten.
@
@ TALK-TRIGGERED, not GSC's `sdefer`-on-map-entry. GSC's version plays once and
@ deletes him; ours leaves him standing for the whole raid, because the two
@ passwords are the only thing in this base a player can genuinely forget, and
@ a man who will repeat them on request is worth more than a cutscene. His line
@ changes once both are known.
@ ============================================================================
TeamRocketBaseB3F_EventScript_Lance::
	lock
	faceplayer
	goto_if_unset FLAG_TRINITY_J_PASSWORD_SLOWPOKETAIL, TeamRocketBaseB3F_EventScript_LanceHunt
	goto_if_unset FLAG_TRINITY_J_PASSWORD_RATICATE, TeamRocketBaseB3F_EventScript_LanceHunt
	msgbox TeamRocketBaseB3F_Text_LanceBothPasswords, MSGBOX_DEFAULT
	release
	end

TeamRocketBaseB3F_EventScript_LanceHunt::
	msgbox TeamRocketBaseB3F_Text_LanceGetPasswords, MSGBOX_DEFAULT
	release
	end

TeamRocketBaseB3F_EventScript_BeatenRocket::
	msgbox TeamRocketBaseB3F_Text_BeatenRocket, MSGBOX_NPC
	end

@ ============================================================================
@ SILVER's cameo. Adapts pokecrystal's RocketBaseRival -- NO BATTLE. He has
@ already lost to LANCE off-screen, and the whole monologue is about what LANCE
@ said to him afterwards.
@
@ TRIGGER. (8,10) is GSC's own tile and it is a genuine one-tile chokepoint in
@ this port: the west region is the x=1..5 column plus the row-10 spur x=6..13,
@ row 9 decodes collision 1 across x=6..15 and row 11 across x=0..15, so every
@ route from the (3,2)/(3,6) stairs to the office door at (10,9) passes through
@ (8,10) and there is no second tile to pair it with (S5's BURNED TOWER
@ precedent: the coord-pair rule spans the full width of a chokepoint, and the
@ full width here is one).
@
@ SILVER'S TEMPLATE IS AT (4,6), NOT GSC's (4,5) -- a one-tile camera fix. The
@ viewport is 15x10 with the player on the 5th row, so from (8,10) the visible
@ rows are 6..15 and GSC's (4,5) would have had him walk in from one row above
@ the screen. (4,6) decodes collision 0 elevation 3, on the same column, and his
@ route (4,6) -> (4,10) -> (7,10) is entirely inside the window.
@
@ THE PLAYER IS SHOVED, NOT WALKED. GSC's `RocketBaseRivalShovesPlayerMovement`
@ is a fixed-facing big step east; (9,10) decodes collision 0 and is the tile
@ the player was heading for anyway, so the shove cannot put them anywhere they
@ could not already stand.
@ ============================================================================
TeamRocketBaseB3F_EventScript_SilverScene::
	goto_if_set FLAG_TRINITY_J_SILVER4_SEEN, TeamRocketBaseB3F_EventScript_SilverSceneDone
	lockall
	applymovement LOCALID_PLAYER, TeamRocketBaseB3F_Movement_PlayerFaceWest
	waitmovement 0
	fadeoutbgm 4
	@ R4: he arrives inside the fade.
	fadescreen FADE_TO_BLACK
	addobject LOCALID_JOHTO_TRB3F_SILVER
	fadescreen FADE_FROM_BLACK
	delay 20
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_JOHTO_TRB3F_SILVER, TeamRocketBaseB3F_Movement_SilverEnters
	waitmovement 0
	msgbox TeamRocketBaseB3F_Text_Silver, MSGBOX_DEFAULT
	closemessage
	playse SE_M_VITAL_THROW
	applymovement LOCALID_PLAYER, TeamRocketBaseB3F_Movement_PlayerShoved
	waitmovement 0
	applymovement LOCALID_JOHTO_TRB3F_SILVER, TeamRocketBaseB3F_Movement_SilverLeaves
	waitmovement 0
	removeobject LOCALID_JOHTO_TRB3F_SILVER
	setflag FLAG_TRINITY_J_SILVER4_SEEN
	fadedefaultbgm
	releaseall
	end

@ Reached whenever the player crosses (8,10) again. No lock, no message: it
@ falls straight through, which is why re-crossing costs nothing.
TeamRocketBaseB3F_EventScript_SilverSceneDone::
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE. SILVER is an addobject-only actor whose
@ flag is set on every transition, and the scene that adds him never releases
@ the player until it has removed him again, so there is no state in which he is
@ standing on this floor with the player free to walk up to him.
TeamRocketBaseB3F_EventScript_SilverIdle::
	msgbox TeamRocketBaseB3F_Text_SilverIdle, MSGBOX_NPC
	end

TeamRocketBaseB3F_Movement_PlayerFaceWest:
	face_left
	step_end

@ (4,6) -> (4,10) down the west column, then three east along the row-10 spur to
@ (7,10), one tile west of the player. Every tile decoded collision 0.
TeamRocketBaseB3F_Movement_SilverEnters:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	face_right
	step_end

TeamRocketBaseB3F_Movement_PlayerShoved:
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	step_end

@ Back west two and up the column he came down.
TeamRocketBaseB3F_Movement_SilverLeaves:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TeamRocketBaseB3F_EventScript_Oath::
	msgbox TeamRocketBaseB3F_Text_Oath, MSGBOX_SIGN
	end

TeamRocketBaseB3F_Text_DoorNoPassword:
	.string "The door's closed.\p"
	.string "It needs TWO passwords to open.$"

TeamRocketBaseB3F_Text_DoorPasswords:
	.string "The door's closed.\p"
	.string "{PLAYER} said: SLOWPOKETAIL.\n"
	.string "{PLAYER} said: RATICATE TAIL.\p"
	.string "The door opened.$"

TeamRocketBaseB3F_Text_DoorOpen:
	.string "The door to the boss's quarters\n"
	.string "stands open.$"

TeamRocketBaseB3F_Text_GruntFSeen:
	.string "Do I know the password?\p"
	.string "Maybe.\p"
	.string "But no weakling's going to get it\n"
	.string "out of me.$"

TeamRocketBaseB3F_Text_GruntFBeaten:
	.string "All right. Stop.\nI'll tell you.$"

TeamRocketBaseB3F_Text_GruntFAfterBattle:
	.string "The password to the boss's room is\n"
	.string "SLOWPOKETAIL.\p"
	.string "Yes. I know. Ask the man in\n"
	.string "AZALEA what he thinks of it.\p"
	.string "It's useless on its own. You need\n"
	.string "both of them.$"

TeamRocketBaseB3F_Text_GruntMSeen:
	.string "Hyuck-hyuck-hyuck!\p"
	.string "You're challenging ME to a battle?\n"
	.string "You're nuts, but you have guts!\p"
	.string "If you can beat me, I'll tell you\n"
	.string "a password to the boss's room!$"

TeamRocketBaseB3F_Text_GruntMBeaten:
	.string "Hyuck-hyuck-hyuck!\nYou're good!$"

TeamRocketBaseB3F_Text_GruntMAfterBattle:
	.string "Hyuck-hyuck-hyuck!\p"
	.string "The password to the boss's room…\p"
	.string "Uh. I think it is RATICATE TAIL.\p"
	.string "Pretty sure. Go on, try it.$"

TeamRocketBaseB3F_Text_RossSeen:
	.string "I used to work for SILPH, but now\n"
	.string "I run research for TEAM ROCKET.\p"
	.string "A meddlesome child like you needs\n"
	.string "to be punished.$"

TeamRocketBaseB3F_Text_RossBeaten:
	.string "A mere tactical error cost me…$"

TeamRocketBaseB3F_Text_RossAfterBattle:
	.string "A radio signal that drives POKéMON\n"
	.string "mad…\p"
	.string "My experiment is a complete\n"
	.string "success.\p"
	.string "My promotion is assured. This loss\n"
	.string "means absolutely nothing.$"

TeamRocketBaseB3F_Text_MitchSeen:
	.string "I don't care that POKéMON are hurt\n"
	.string "by our experiment.$"

TeamRocketBaseB3F_Text_MitchBeaten:
	.string "Thinking is my strong suit, not\n"
	.string "battling.$"

TeamRocketBaseB3F_Text_MitchAfterBattle:
	.string "If we turned up the power of our\n"
	.string "signal, and broadcast it\l"
	.string "nationwide…\p"
	.string "The very thought excites me.\p"
	.string "You've seen one lake. Imagine a\n"
	.string "region.$"

TeamRocketBaseB3F_Text_PetrelIntro:
	.string "What? Who are you?\p"
	.string "This is the office of our leader,\n"
	.string "GIOVANNI.\p"
	.string "Since disbanding TEAM ROCKET three\n"
	.string "years ago, he has been in\l"
	.string "training.\p"
	.string "But we're certain he'll be back\n"
	.string "some day to assume command again.\p"
	.string "That's why we're standing guard.\p"
	.string "I won't let anyone disturb this\n"
	.string "place!$"

TeamRocketBaseB3F_Text_PetrelDefeat:
	.string "I… I couldn't do a thing.\p"
	.string "GIOVANNI, please forgive me…$"

TeamRocketBaseB3F_Text_PetrelAfter:
	.string "No. I can't let this affect me.\p"
	.string "I have to inform the others.$"

TeamRocketBaseB3F_Text_PetrelIdle:
	.string "Three years I have kept this desk\n"
	.string "clean for a man who has not\l"
	.string "written once.\p"
	.string "He'll be back. You'll see.$"

TeamRocketBaseB3F_Text_Murkrow:
	.string "The MURKROW on the desk cocks its\n"
	.string "head at {PLAYER}.\p"
	.string "MURKROW: The password is…\p"
	.string "HAIL GIOVANNI.\p"
	.string "It says it again. And again. It has\n"
	.string "clearly been saying it for years.$"

TeamRocketBaseB3F_Text_LanceGetPasswords:
	.string "LANCE: It takes two passwords to\n"
	.string "get into the boss's quarters.\p"
	.string "Those passwords are known only to\n"
	.string "a few ROCKETS.\p"
	.string "That one there told me so, very\n"
	.string "graciously.\p"
	.string "{PLAYER}, let's go and get them.$"

TeamRocketBaseB3F_Text_LanceBothPasswords:
	.string "LANCE: SLOWPOKETAIL and RATICATE\n"
	.string "TAIL. Both of them.\p"
	.string "They name their locks after the\n"
	.string "things they've cut off POKéMON.\p"
	.string "The door is west and down. Go.$"

TeamRocketBaseB3F_Text_BeatenRocket:
	.string "Urrggh… The guy in the cape is\n"
	.string "incredibly tough…$"

TeamRocketBaseB3F_Text_Silver:
	.string "…\p"
	.string "Didn't I tell you I was going to\n"
	.string "destroy TEAM ROCKET?\p"
	.string "…Tell me. Who was the man in the\n"
	.string "cape with the dragon POKéMON?\p"
	.string "My POKéMON were no match at all.\p"
	.string "I don't care that I lost. I can\n"
	.string "beat him by getting stronger\l"
	.string "POKéMON.\p"
	.string "It's what he SAID that bothers me.\p"
	.string "He told me I don't love and trust\n"
	.string "my POKéMON enough.\p"
	.string "I'm furious that I lost to a\n"
	.string "bleeding heart like him.\p"
	.string "…Humph. I don't have time for the\n"
	.string "likes of you.$"

TeamRocketBaseB3F_Text_SilverIdle:
	.string "…Humph.$"

TeamRocketBaseB3F_Text_Oath:
	.string "TEAM ROCKET OATH\p"
	.string "Steal POKéMON for profit!\p"
	.string "Exploit POKéMON for profit!\p"
	.string "All POKéMON exist for the glory\n"
	.string "of TEAM ROCKET!$"

@ ============================================================================
@ Trinity M4b S8 -- THE EVIDENCE CRATE. A revisit beat: once the RADIO TOWER
@ has fallen (ARC >= 7) the seized paperwork in GIOVANNI's office is worth a
@ second look, and what is filed with it is the SILVER WING.
@
@ D1 GEOMETRY. bg_event at (12,3) -- metatile 582, collision 1, elevation 0, the
@ middle of the desk block (11,3)(12,3)(13,3) -- BG_EVENT_PLAYER_FACING_SOUTH,
@ read from (12,2) (metatile 580, collision 0, elevation 3), which is its ONLY
@ reading tile: (12,4) is collision 1 and the desk itself is solid. (12,2) is
@ inside the office and is reachable once S7's door is open (verified by
@ re-running reach_check with the door's two collision tiles opened); it is kept
@ clear of objects. S7 already owns the bookshelf at (10,1)-(13,1) with its
@ Oath bg_events, which is why this is the desk and not the shelf.
@
@ THE SILVER WING IS A FLAG, not an item (no ITEM_SILVER_WING in this build;
@ S1's ITEM_RED_SCALE and S6's ITEM_SECRET_POTION precedent). Fanfare + a
@ "received" line so it reads as a pickup, and no G2 guard because there is no
@ giveitem to fail.
@
@ GUARD ORDER. The office-door test is first and is UNREACHABLE-BY-CONSTRUCTION
@ (a player standing on (12,2) has already opened the door), but S7 owns that
@ door's state and writing the dependency down beats inheriting it silently.
@ ============================================================================
TeamRocketBaseB3F_EventScript_EvidenceCrate::
	lockall
	goto_if_unset FLAG_TRINITY_J_DOOR_B3F, TeamRocketBaseB3F_EventScript_CrateSealed
	goto_if_lt VAR_TRINITY_JOHTO_ARC, 7, TeamRocketBaseB3F_EventScript_CrateSealed
	goto_if_set FLAG_TRINITY_J_WING_SILVER, TeamRocketBaseB3F_EventScript_CrateEmptied
	msgbox TeamRocketBaseB3F_Text_EvidenceCrate, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox TeamRocketBaseB3F_Text_ReceivedSilverWing, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_J_WING_SILVER
	@ M7b Task 15 (finding #6c): the bag row is the player-visible TOKEN; the
	@ FLAG above stays the authored truth and every gate still reads it (see
	@ WhirlIslandLugiaChamber). setflag FIRST, and a full bag must NOT abort
	@ the scene -- Common_EventScript_BagIsFull is msgbox + return, unlike
	@ ShowBagIsFull which terminates. So the story advances either way and the
	@ two can never desync.
	giveitem ITEM_SILVER_WING
	goto_if_eq VAR_RESULT, FALSE, TeamRocketBaseB3F_EventScript_SilverWingBagFull
TeamRocketBaseB3F_EventScript_SilverWingAwarded::
	msgbox TeamRocketBaseB3F_Text_SilverWingFile, MSGBOX_DEFAULT
	releaseall
	end

TeamRocketBaseB3F_EventScript_SilverWingBagFull::
	msgbox TeamRocketBaseB3F_Text_SilverWingNoRoom, MSGBOX_DEFAULT
	goto TeamRocketBaseB3F_EventScript_SilverWingAwarded
	end

TeamRocketBaseB3F_EventScript_CrateSealed::
	msgbox TeamRocketBaseB3F_Text_CrateSealed, MSGBOX_DEFAULT
	releaseall
	end

TeamRocketBaseB3F_EventScript_CrateEmptied::
	msgbox TeamRocketBaseB3F_Text_CrateEmptied, MSGBOX_DEFAULT
	releaseall
	end

TeamRocketBaseB3F_Text_CrateSealed:
	.string "A steel crate under the desk.\p"
	.string "Banded, sealed and heavy. It\n"
	.string "doesn't move.$"

TeamRocketBaseB3F_Text_EvidenceCrate:
	.string "The bands on the crate have\n"
	.string "been cut. Someone came back for\l"
	.string "the contents and was in a\l"
	.string "hurry.\p"
	.string "Most of the folders are gone.\p"
	.string "One is left, because it is not\n"
	.string "paper.\p"
	.string "Catalogue tag. Valuation.\n"
	.string "Project number.\p"
	.string "And inside, wrapped twice, a\n"
	.string "long gray feather.$"

TeamRocketBaseB3F_Text_ReceivedSilverWing:
	.string "{PLAYER} received the\n"
	.string "SILVER WING.$"

TeamRocketBaseB3F_Text_SilverWingFile:
	.string "The tag reads: RECOVERED, WHIRL\n"
	.string "ISLANDS. HOLD PENDING PHASE\l"
	.string "TWO.\p"
	.string "The DIRECTOR gave you a feather\n"
	.string "because he loved POKéMON and\l"
	.string "didn't know what else to do\l"
	.string "with it.\p"
	.string "This one was inventory.$"

TeamRocketBaseB3F_Text_CrateEmptied:
	.string "The crate is empty now.\p"
	.string "Just the tag, and the shape in\n"
	.string "the packing where something\l"
	.string "used to lie.$"

TeamRocketBaseB3F_Text_SilverWingNoRoom:
	.string "Your KEY ITEMS pocket is full,\n"
	.string "so the feather stays in the file.\p"
	.string "You have seen it. That is what\n"
	.string "matters -- you know where it is.$"
