AzaleaTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S3 -- AZALEA TOWN.
@ ON_TRANSITION is the SINGLE AUTHORITY for all three visibility flags (S1
@ rule); scene bodies only addobject/removeobject. It runs before InitMap and
@ object spawning, so no new-game flag defaults are needed.
@   ROCKET posts  : visible while VAR_TRINITY_JOHTO_ARC == 2 (raid live)
@   SLOWPOKE      : visible at ARC >= 3 (they came home)
@   SILVER        : visible while VAR_TRINITY_JOHTO_SCENE_AZALEA == 1
@ FLAG_TRINITY_J_AZALEA_SLOWPOKES_HIDE also covers KURT'S HOUSE's SLOWPOKE;
@ that map's ON_TRANSITION authors it from the same ARC >= 3 predicate, so the
@ two can never disagree.
@ ============================================================================
AzaleaTown_OnTransition:
	call AzaleaTown_EventScript_SetRocketVisibility
	call AzaleaTown_EventScript_SetSlowpokeVisibility
	call AzaleaTown_EventScript_SetSilverVisibility
	end

AzaleaTown_EventScript_SetRocketVisibility::
	goto_if_eq VAR_TRINITY_JOHTO_ARC, 2, AzaleaTown_EventScript_ShowRockets
	setflag FLAG_TRINITY_J_AZALEA_ROCKETS_HIDE
	return

AzaleaTown_EventScript_ShowRockets::
	clearflag FLAG_TRINITY_J_AZALEA_ROCKETS_HIDE
	return

AzaleaTown_EventScript_SetSlowpokeVisibility::
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 3, AzaleaTown_EventScript_ShowSlowpoke
	setflag FLAG_TRINITY_J_AZALEA_SLOWPOKES_HIDE
	return

AzaleaTown_EventScript_ShowSlowpoke::
	clearflag FLAG_TRINITY_J_AZALEA_SLOWPOKES_HIDE
	return

AzaleaTown_EventScript_SetSilverVisibility::
	goto_if_eq VAR_TRINITY_JOHTO_SCENE_AZALEA, 1, AzaleaTown_EventScript_ShowSilver
	setflag FLAG_TRINITY_J_SILVER_AZALEA_HIDE
	return

AzaleaTown_EventScript_ShowSilver::
	clearflag FLAG_TRINITY_J_SILVER_AZALEA_HIDE
	return

@ ============================================================================
@ TRAINER_SILVER_2 -- adapts pokecrystal AzaleaTownRivalBattleScene1/2
@ (AzaleaTown.asm:37-106), following S1's hardened SILVER pattern
@ (Route29/scripts.inc) clause for clause.
@
@ Trigger placement (decoded): column x=5 is collision 1 at EVERY row except
@ y=10 and y=11, and the only warps west of it are the two ILEX FOREST GATE
@ warps at (2,10)/(2,11); the (2..4, 8) pocket above them is sealed off by row
@ 9. So every path from AZALEA TOWN to ILEX FOREST crosses this pair -- it
@ cannot be walked around. These are GSC's own trigger tiles.
@
@ GSC runs two scene variants (one per approach row) so SILVER can take the
@ other row. Trinity collapses them: the south trigger normalises the player
@ one step north, so the shared body can assume (5,10) exactly, and SILVER
@ always walks row 11 and stops at (5,11), directly below the locked player.
@ Camera: player at (5,10) => rows 6..15, columns -2..12; SILVER's home (11,11),
@ his six-tile approach and his three-tile exit to (2,11) all sit inside it.
@ ============================================================================
AzaleaTown_EventScript_SilverSceneSouth::
	lockall
	applymovement LOCALID_PLAYER, AzaleaTown_Movement_PlayerStepNorth
	waitmovement 0
	goto AzaleaTown_EventScript_SilverScene
	end

AzaleaTown_EventScript_SilverSceneNorth::
	lockall
	goto AzaleaTown_EventScript_SilverScene
	end

AzaleaTown_EventScript_SilverScene::
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
	applymovement LOCALID_JOHTO_AZALEA_SILVER, AzaleaTown_Movement_SilverCutsYouOff
	waitmovement 0
	applymovement LOCALID_PLAYER, AzaleaTown_Movement_PlayerFaceSouth
	waitmovement 0
	call AzaleaTown_EventScript_SilverConfront
	applymovement LOCALID_JOHTO_AZALEA_SILVER, AzaleaTown_Movement_SilverLeavesWest
	waitmovement 0
	removeobject LOCALID_JOHTO_AZALEA_SILVER
	call AzaleaTown_EventScript_SilverAftermath
	releaseall
	end

@ Talk path. Reachable if the player walks up to SILVER at his resting tile
@ instead of crossing the gateway pair, or after a white-out. The player's tile
@ is therefore unknown, so this path uses lock/faceplayer (works from any
@ approach direction) and runs NO movement script -- walking SILVER into or out
@ of an unknown tile could deadlock waitmovement.
@ The scene-var guard is the S1 talk-guard rule: a talk script that starts a
@ battle and advances story state carries an explicit state check even when the
@ visibility flag already makes the bad path unreachable.
AzaleaTown_EventScript_Silver::
	lock
	faceplayer
	goto_if_ne VAR_TRINITY_JOHTO_SCENE_AZALEA, 1, AzaleaTown_EventScript_SilverIdle
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
	call AzaleaTown_EventScript_SilverConfront
	@ Talk path: the player's tile is unknown, so SILVER cannot be walked off
	@ screen the way the coord path walks him west. Cover the removal with the
	@ same fade the well aftermath uses, so he leaves rather than blinking out.
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_JOHTO_AZALEA_SILVER
	fadescreen FADE_FROM_BLACK
	call AzaleaTown_EventScript_SilverAftermath
	release
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE: the aftermath removeobject's SILVER and
@ advances the scene var to 2, after which ON_TRANSITION hides him on every
@ later entry -- there is no object left to talk to.
AzaleaTown_EventScript_SilverIdle::
	msgbox AzaleaTown_Text_SilverIdle, MSGBOX_DEFAULT
	release
	end

@ Shared by both paths. Calling `trainerbattle_no_intro` from a call-ed subscript
@ of a lockall-ed scene is vanilla -- MauvilleCity_EventScript_BattleWally is
@ likewise driven from a lockall cutscene. And unlike trainerbattle_single, this
@ form does NOT supply its own lock, which is what makes it correct here.
@ setvar VAR_LAST_TALKED pins the engine's Movement_RevealTrainer emote on
@ SILVER rather than on whatever object the player last spoke to; GSC does the
@ same thing with `setlasttalked AZALEATOWN_RIVAL` (AzaleaTown.asm:68).
@ Battle BGM needs no scripting: TRAINER_SILVER_2 is TRAINER_CLASS_RIVAL with a
@ name other than WALLY, so GetBattleBGM() returns MUS_VS_RIVAL.
AzaleaTown_EventScript_SilverConfront::
	msgbox AzaleaTown_Text_SilverIntro, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LAST_TALKED, LOCALID_JOHTO_AZALEA_SILVER
	trainerbattle_no_intro TRAINER_SILVER_2, AzaleaTown_Text_SilverDefeat
	setflag FLAG_TRINITY_J_SILVER2_BEATEN
	playbgm MUS_RG_ENCOUNTER_RIVAL, FALSE
	msgbox AzaleaTown_Text_SilverAfter, MSGBOX_DEFAULT
	closemessage
	return

AzaleaTown_EventScript_SilverAftermath::
	setvar VAR_TRINITY_JOHTO_SCENE_AZALEA, 2
	fadedefaultbgm
	special HealPlayerParty
	return

@ (5,11) -> (5,10): normalise onto the north row of the gateway pair.
AzaleaTown_Movement_PlayerStepNorth:
	walk_up
	step_end

AzaleaTown_Movement_PlayerFaceSouth:
	face_down
	step_end

@ (11,11) -> (5,11): six tiles west along row 11 (every tile decoded collision
@ 0), stopping directly below the player at (5,10).
AzaleaTown_Movement_SilverCutsYouOff:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

@ (5,11) -> (2,11): GSC's three-tile exit west, toward the ILEX FOREST gate.
AzaleaTown_Movement_SilverLeavesWest:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

@ ============================================================================
@ TEAM ROCKET street posts. Both are MOVED off GSC's tiles because GSC uses
@ them as gates and the M4b contract forbids a resting NPC sealing a corridor:
@   GSC (31,9) seals the SLOWPOKE WELL -- (31,7) is the well warp and (31,8) is
@     its only walkable neighbour ((30,8)/(32,8) decode collision 1). Moved one
@     tile west to (30,9), inside the open y=9/y=10 two-row corridor.
@   GSC (10,16) seals AZALEA GYM -- (10,15) is the gym warp and (10,16) is its
@     only walkable neighbour ((9,15)/(11,15)/(10,14) all collision 1). The
@     contract makes the Johto gyms open-order and gives BUGSY no arc gate, so
@     this post moved to (11,16), inside the open y=16/y=17 two-row corridor.
@ ============================================================================
AzaleaTown_EventScript_RocketWellPost::
	msgbox AzaleaTown_Text_RocketWellPost, MSGBOX_NPC
	end

AzaleaTown_EventScript_RocketTownPost::
	msgbox AzaleaTown_Text_RocketTownPost, MSGBOX_NPC
	end

@ Adapts GSC AzaleaTownSlowpokeScript: a beat of silence, then the yawn.
@ No faceplayer -- a SLOWPOKE does not turn for anybody.
AzaleaTown_EventScript_Slowpoke::
	lock
	msgbox AzaleaTown_Text_Slowpoke1, MSGBOX_DEFAULT
	delay 60
	msgbox AzaleaTown_Text_Slowpoke2, MSGBOX_DEFAULT
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
	waitmoncry
	release
	end

@ ============================================================================
@ The APRICORN tree at GSC's WhiteApricornTree tile (AzaleaTown.asm:493).
@ This build compiles the apricorn-TREE system out (APRICORN_TREE_COUNT 0 drops
@ the SaveBlock3 field entirely, and raising it breaks existing saves), so this
@ is a hand-written one-time pick rather than the engine's ApricornTreeScript.
@ It exists so KURT's apricorn exchange is not dead content -- apricorns have no
@ other source in this build. A real apricorn economy is an M6 balance item.
@ ============================================================================
AzaleaTown_EventScript_ApricornTree::
	lock
	goto_if_set FLAG_TRINITY_J_AZALEA_APRICORN, AzaleaTown_EventScript_ApricornTreeBare
	msgbox AzaleaTown_Text_ApricornTree, MSGBOX_DEFAULT
	giveitem ITEM_WHITE_APRICORN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_J_AZALEA_APRICORN
	msgbox AzaleaTown_Text_ApricornTreePicked, MSGBOX_DEFAULT
	release
	end

AzaleaTown_EventScript_ApricornTreeBare::
	msgbox AzaleaTown_Text_ApricornTreeBare, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ GSC AzaleaTownGrampsScript -- two states on EVENT_CLEARED_SLOWPOKE_WELL,
@ which is VAR_TRINITY_JOHTO_ARC >= 3 here.
@ ============================================================================
AzaleaTown_EventScript_Gramps::
	lock
	faceplayer
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 3, AzaleaTown_EventScript_GrampsAfter
	msgbox AzaleaTown_Text_GrampsBefore, MSGBOX_DEFAULT
	release
	end

AzaleaTown_EventScript_GrampsAfter::
	msgbox AzaleaTown_Text_GrampsAfter, MSGBOX_DEFAULT
	release
	end

AzaleaTown_EventScript_Teacher::
	msgbox AzaleaTown_Text_Teacher, MSGBOX_NPC
	end

AzaleaTown_EventScript_Youngster::
	msgbox AzaleaTown_Text_Youngster, MSGBOX_NPC
	end

AzaleaTown_EventScript_Sign::
	msgbox AzaleaTown_Text_Sign, MSGBOX_SIGN
	end

AzaleaTown_EventScript_KurtsHouseSign::
	msgbox AzaleaTown_Text_KurtsHouseSign, MSGBOX_SIGN
	end

AzaleaTown_EventScript_AzaleaGymSign::
	msgbox AzaleaTown_Text_AzaleaGymSign, MSGBOX_SIGN
	end

AzaleaTown_EventScript_SlowpokeWellSign::
	msgbox AzaleaTown_Text_SlowpokeWellSign, MSGBOX_SIGN
	end

AzaleaTown_EventScript_CharcoalKilnSign::
	msgbox AzaleaTown_Text_CharcoalKilnSign, MSGBOX_SIGN
	end

AzaleaTown_EventScript_IlextForestSign::
	msgbox AzaleaTown_Text_IlextForestSign, MSGBOX_SIGN
	end

@ ============================================================================
@ Text
@ ============================================================================
@ Adapts GSC AzaleaTownRivalBeforeText. GSC's SILVER has not yet met TEAM
@ ROCKET; Act II's has just watched the CHAMPION break them in a well.
AzaleaTown_Text_SilverIntro:
	.string "SILVER: Stop there.\p"
	.string "…Tell me something.\p"
	.string "Is it true TEAM ROCKET has come\n"
	.string "back?\p"
	.string "And that you went down that WELL\n"
	.string "and put them out of it in an\l"
	.string "afternoon.\p"
	.string "Hah. Don't lie to me.\p"
	.string "…You're not lying.\p"
	.string "Then let's see it. Not the badge\n"
	.string "count. You.$"

AzaleaTown_Text_SilverDefeat:
	.string "…Humph!\n"
	.string "Useless POKéMON!$"

@ Adapts GSC AzaleaTownRivalAfterText, cut down and pointed at TEAM ROCKET.
AzaleaTown_Text_SilverAfter:
	.string "SILVER: I hate the weak.\p"
	.string "POKéMON, trainers -- it doesn't\n"
	.string "matter which.\p"
	.string "That goes for TEAM ROCKET too.\p"
	.string "They're big and loud in a group.\n"
	.string "Get one of them alone in a hole\l"
	.string "in the ground and he's nothing.\p"
	.string "I'm going to get strong enough\n"
	.string "that none of it matters.\p"
	.string "Stay out of my way until then.$"

@ INTENTIONALLY UNREACHABLE / DEFENSIVE -- see EventScript_SilverIdle.
AzaleaTown_Text_SilverIdle:
	.string "SILVER: Don't follow me.$"

@ Adapts GSC AzaleaTownRocket1Text.
AzaleaTown_Text_RocketWellPost:
	.string "It's unsafe down that WELL, so\n"
	.string "I'm standing here keeping folks\l"
	.string "out of it.\p"
	.string "Aren't I a good Samaritan?\p"
	.string "…Go on in if you like. I'm not\n"
	.string "paid enough to stop a CHAMPION.$"

@ Adapts GSC AzaleaTownRocket2Text.
AzaleaTown_Text_RocketTownPost:
	.string "Do you know about SLOWPOKETAIL?\n"
	.string "I hear it's tasty.\p"
	.string "Aren't you glad I told you that?$"

AzaleaTown_Text_Slowpoke1:
	.string "SLOWPOKE: …\p"
	.string "……   ……   ……$"

AzaleaTown_Text_Slowpoke2:
	.string "……   ……Yawn?$"

AzaleaTown_Text_ApricornTree:
	.string "A gnarled little tree, heavy\n"
	.string "with hard white fruit.\p"
	.string "APRICORNS. KURT makes his BALLS\n"
	.string "out of them.$"

AzaleaTown_Text_ApricornTreePicked:
	.string "{PLAYER} twisted one loose.\p"
	.string "It doesn't smell like anything\n"
	.string "at all.$"

AzaleaTown_Text_ApricornTreeBare:
	.string "The branches are bare now.\p"
	.string "They'll come back. Trees in this\n"
	.string "town keep their own schedule.$"

@ GSC AzaleaTownGrampsTextBefore.
AzaleaTown_Text_GrampsBefore:
	.string "The SLOWPOKE have disappeared\n"
	.string "from town…\p"
	.string "I heard their TAILS are being\n"
	.string "sold somewhere.\p"
	.string "Four hundred years they've sat\n"
	.string "in these streets. Four hundred.$"

@ GSC AzaleaTownGrampsTextAfter.
AzaleaTown_Text_GrampsAfter:
	.string "The SLOWPOKE have returned.\p"
	.string "Knowing them, they could've just\n"
	.string "been goofing off somewhere.\p"
	.string "…Thank you. Whatever it was you\n"
	.string "did down there.$"

AzaleaTown_Text_Teacher:
	.string "Did you come to\nget KURT to make\lsome BALLS?\pA lot of people do\njust that.$"

AzaleaTown_Text_Youngster:
	.string "Cut through AZALEA\nand you'll be in\lILEX FOREST.\pBut these skinny\ntrees make it\pimpossible to get\nthrough.\pThe CHARCOAL MAN's\nPOKéMON can CUT\ldown trees.$"

AzaleaTown_Text_Sign:
	.string "AZALEA TOWN\nWhere People and\pPOKéMON Live in\nHappy Harmony$"

AzaleaTown_Text_KurtsHouseSign:
	.string "KURT'S HOUSE$"

AzaleaTown_Text_AzaleaGymSign:
	.string "AZALEA TOWN\nPOKéMON GYM\lLEADER: BUGSY\pThe Walking\nBug POKéMON\lEncyclopedia$"

AzaleaTown_Text_SlowpokeWellSign:
	.string "SLOWPOKE WELL\pAlso known as the\nRAINMAKER WELL.\pLocals believe\nthat a SLOWPOKE's\lyawn summons rain.\pRecords show that\na SLOWPOKE's yawn\pended a drought\n400 years ago.$"

AzaleaTown_Text_CharcoalKilnSign:
	.string "CHARCOAL KILN$"

AzaleaTown_Text_IlextForestSign:
	.string "ILEX FOREST\pEnter through the\ngate.$"
