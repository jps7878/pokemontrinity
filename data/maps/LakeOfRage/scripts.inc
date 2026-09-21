LakeOfRage_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeOfRage_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S7 -- the LAKE OF RAGE. Adapts pokecrystal maps/LakeOfRage.asm.
@
@ ON_TRANSITION is the SINGLE AUTHORITY for all three visibility flags (S1
@ rule); the scene bodies only ever addobject / removeobject.
@     RED GYARADOS (1)  visible iff NOT FLAG_TRINITY_J_RED_GYARADOS_HIDE
@                       (the battle's own removeobject co-signs that flag -- R1).
@                       Visible from new game on purpose (foreshadowing); the
@                       ENCOUNTER is what is gated, on ARC >= 3, inside its talk
@                       script (M7 Task 4, bug-test finding #3)
@     LANCE        (1)  visible iff the GYARADOS is gone AND ARC < 4 -- and the
@                       fish cannot be gone before ARC 3 on a forward-running
@                       save, so he cannot appear early either (finding #3)
@     4 TRAINERS   (1 flag)  visible iff ARC >= 5
@
@ The four trainers are GSC's EVENT_LAKE_OF_RAGE_CIVILIANS, which is SET at new
@ game and cleared only by the raid's end (RocketBaseElectrodeScript). They are
@ a victory lap, not an obstacle -- which is why LOIS opens with "What happened
@ to the red GYARADOS? It's gone?".
@
@ THE LEDGE FIX TOUCHED THIS MAP. Six cardinal ledge cells in the south-west
@ (4,28) (5,28) (6,28) (4,30) (6,30) (7,30) were shifted one tile south by
@ tools/johto_port/shift_ledges.py; see MahoganyTown/scripts.inc for the full
@ account. Before the fix the ROUTE 43 arrival columns at x = 10/11 sat in an
@ 18-tile pocket that reached nothing. GSC's two-step cliff at x = 4 and x = 6
@ shifts as a PAIR and still lands exactly where GSC's hops landed.
@ ============================================================================
@ FLAG_TRINITY_J_RED_GYARADOS_HIDE is the one visibility flag on this map with
@ NO authoring clause, and deliberately so: it is written exactly once, by the
@ battle's own removeobject co-sign (R1), and it is monotonic. There is no arc
@ value that means "the GYARADOS is gone" -- the fish can be faced at any point
@ from ARC 3 onward (the talk script's lower bound, finding #3, is what makes
@ "from ARC 3" literally true; before M7 it could be faced at 0) and the arc
@ does not move until LANCE is agreed to -- so an authoring clause would have
@ nothing to author from. Its new-game default (clear = visible) is already
@ correct, and is kept: the red fish in the lake is the chapter's foreshadowing.
LakeOfRage_OnTransition:
	call LakeOfRage_EventScript_SetLanceVisibility
	call LakeOfRage_EventScript_SetCiviliansVisibility
	end

LakeOfRage_EventScript_SetLanceVisibility::
	goto_if_unset FLAG_TRINITY_J_RED_GYARADOS_HIDE, LakeOfRage_EventScript_HideLance
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 4, LakeOfRage_EventScript_HideLance
	clearflag FLAG_TRINITY_J_LANCE_LAKE_HIDE
	return

LakeOfRage_EventScript_HideLance::
	setflag FLAG_TRINITY_J_LANCE_LAKE_HIDE
	return

LakeOfRage_EventScript_SetCiviliansVisibility::
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 5, LakeOfRage_EventScript_ShowCivilians
	setflag FLAG_TRINITY_J_LAKE_CIVILIANS_HIDE
	return

LakeOfRage_EventScript_ShowCivilians::
	clearflag FLAG_TRINITY_J_LAKE_CIVILIANS_HIDE
	return

@ ============================================================================
@ THE RED GYARADOS. Adapts pokecrystal's `RedGyarados`.
@
@ STAGING. GSC's object sits on (18,22), and so does ours: the tile decodes
@ collision 0, elevation 1, MB_POND_WATER -- open water, deep inside the lake,
@ SURF-only. There is no whirlpool and no rock anywhere on this map in either
@ game (GSC's whirlpool block $07 does not occur once in LakeOfRage.blk), so
@ nothing is being skipped. Talk-triggered, sight 0, TRAINER_TYPE_NONE.
@ The object's ELEVATION IS 0 (ELEVATION_TRANSITION) on purpose:
@ ObjectEventDoesElevationMatch compares against the PLAYER's own elevation
@ (S4's MB_COUNTER pin -- position->elevation comes from PlayerGetElevation()),
@ and 0 is compatible with anything, so the fish is talkable from any surf tile
@ regardless of what elevation the water the player happens to be on carries.
@
@ THE RED IS TWO SEPARATE MECHANISMS, and both were investigated:
@
@ 1. THE OVERWORLD SPRITE is OBJ_EVENT_GFX_SPECIES_SHINY(GYARADOS).
@    include/constants/event_objects.h:286 defines it as SPECIES_## +
@    OBJ_EVENT_MON + OBJ_EVENT_MON_SHINY, and GetObjectEventGraphicsInfo
@    handles the OBJ_EVENT_MON bit (src/event_object_movement.c:3074-3075)
@    BEFORE the NUM_OBJ_EVENT_GFX clamp -- the same route S3 proved for the
@    plain form with the SLOWPOKE WELL. GSC needed SPRITE_GYARADOS plus
@    PAL_NPC_RED to get this; here it is one constant.
@
@ 2. THE BATTLE MON is forced shiny through P_FLAG_FORCE_SHINY
@    (include/config/pokemon.h), which this slice points at
@    FLAG_TRINITY_J_FORCE_SHINY. Three candidates were checked:
@      * `seteventmon` / CreateEnemyEventMon (src/pokemon.c:1587) -- the
@        NavelRock legendary idiom, but it has NO shiny control at all.
@      * `createmon ... shinyMode=SHINY_MODE_ALWAYS`
@        (ScriptGiveMonParameterized, src/script_pokemon_util.c:364) -- real
@        control, but it is the gift path with 28 parameters and would duplicate
@        what setwildbattle already does.
@      * P_FLAG_FORCE_SHINY -- read by CreateBoxMon's "Player is the OT" branch
@        (src/pokemon.c:1071-1077), which is exactly the branch setwildbattle
@        reaches: ScrCmd_setwildbattle -> CreateScriptedWildMon
@        (src/script_pokemon_util.c:113-127) -> CreateMonWithNature /
@        CreateMon(..., OT_ID_PLAYER_ID, 0).
@    setwildbattle builds the mon SYNCHRONOUSLY, so the flag is live for exactly
@    the one command between the setflag and the clearflag; there is no
@    waitstate and no message in that window, so no other wild or gift POKéMON
@    can be caught by it. The caught fish keeps its colour because it IS
@    gEnemyParty[0]. GSC's equivalent is BATTLETYPE_FORCESHINY.
@
@ Level 60, not GSC's 30: the Act II band.
@
@ BOTH OUTCOMES END THE BEAT. GSC only skips the `disappear` on a LOSS, so
@ catching the fish and knocking it out both retire it and both award the
@ scale. Kept: the RED SCALE is a one-shot payoff and must not be missable by
@ winning the wrong way. A loss leaves everything armed.
@
@ THE RED SCALE IS A FLAG. ITEM_RED_SCALE does not exist in this build -- the
@ ruling S1 handed to S7, discharged here and written up in
@ data/maps/MrPokemonsHouse/scripts.inc where the payoff lives. S6's three-part
@ rule for a flag-carried errand is honoured: the fanfare + "received" line
@ below, the item named at three separate sites, and MR.POKéMON's un-armed path
@ still doing something useful.
@ ============================================================================
LakeOfRage_EventScript_RedGyarados::
	lock
	@ M7 Task 4 (bug-test finding #3). The object is visible from new game, so
	@ before this read the fish could be fought at ARC 0; winning spawned LANCE,
	@ and agreeing with him wrote ARC 4 from 0 -- which ELM's unguarded write of
	@ 1 then REGRESSED on the player's first entry to ELM's LAB (its (4,8)/(5,8)
	@ triggers fire on SCENE_NEWBARK == 0). ARC 3 is the SLOWPOKE WELL cleared,
	@ the last write before LANCE's 4, so that is the lower bound: below it the
	@ fish refuses the encounter and nothing is written.
	goto_if_lt VAR_TRINITY_JOHTO_ARC, 3, LakeOfRage_EventScript_GyaradosNotYet
	msgbox LakeOfRage_Text_GyaradosCry, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_GYARADOS, CRY_MODE_NORMAL
	waitmoncry
	setflag FLAG_TRINITY_J_FORCE_SHINY
	setwildbattle SPECIES_GYARADOS, 60
	clearflag FLAG_TRINITY_J_FORCE_SHINY
	dowildbattle
	@ B_OUTCOME_WON and B_OUTCOME_CAUGHT both retire the fish; anything else
	@ (ran, teleported, lost -- a loss whites the player out and never returns
	@ here at all) leaves the object and the scale exactly as they were.
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, LakeOfRage_EventScript_GyaradosDone
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, LakeOfRage_EventScript_GyaradosDone
	release
	end

LakeOfRage_EventScript_GyaradosDone::
	@ R4: the disappearance and LANCE's arrival both happen inside one fade, so
	@ nothing pops. removeobject co-signs FLAG_TRINITY_J_RED_GYARADOS_HIDE
	@ (R1: RemoveObjectEventByLocalIdAndMap FlagSets before despawning,
	@ src/event_object_movement.c:1537-1545) -- intended, and it is also what
	@ makes ON_TRANSITION's LANCE predicate true from this moment on.
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_JOHTO_LAKE_GYARADOS
	@ addobject spawns for THIS session only -- it does not clear the flag
	@ (TrySpawnObjectEvent, src/event_object_movement.c:1803, has no FlagClear
	@ counterpart to removeobject's FlagSet). ON_TRANSITION clears LANCE's flag
	@ on every later entry, so the two paths agree.
	addobject LOCALID_JOHTO_LAKE_LANCE
	fadescreen FADE_FROM_BLACK
	delay 20
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox LakeOfRage_Text_GotRedScale, MSGBOX_DEFAULT
	setflag FLAG_TRINITY_J_RED_SCALE
	release
	end

@ Finding #3's pre-story refusal. The fish stays in the water and on the map;
@ no cry, no battle, no flag -- the encounter simply is not offered yet.
LakeOfRage_EventScript_GyaradosNotYet::
	msgbox LakeOfRage_Text_GyaradosNotYet, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ LANCE, on the south shore at GSC's own (21,28) -- collision 0, elevation 3.
@ The LAKE OF RAGE sign one tile north at (21,27) is BG_EVENT_PLAYER_FACING_ANY
@ and keeps (22,27) as a reading tile, so S5's one-reading-tile trap does not
@ apply here.
@
@ He has NO trainerbattle anywhere in this chapter; TRAINER_LANCE is S11's.
@
@ GSC speaks his first line with his BACK TURNED (writetext comes before
@ faceplayer) and only then turns to the player. Kept -- it is the whole
@ characterisation, a man talking to the water.
@
@ THE ARC WRITE. Agreeing is the single gate on the entire hideout arc, so this
@ is where ARC 3 -> 4 happens, under S1's monotonic guard and, since M7 Task 4
@ (finding #3), above an ARC >= 3 floor. Refusing leaves every flag and the arc
@ untouched and simply re-arms: GSC does the same with
@ EVENT_REFUSED_TO_HELP_LANCE_AT_LAKE_OF_RAGE, and that refusal path is exactly
@ why LANCE's object cannot retire on a talk count.
@
@ THE FLOOR (finding #3). With the GYARADOS encounter gated on ARC >= 3, a
@ forward-running save cannot show LANCE below 3 (his predicate needs the fish
@ gone). Nor can a fresh save reach this branch by REGRESSION: ELM's write of 1
@ fires once per save (its (4,8)/(5,8) triggers key on SCENE_NEWBARK == 0, a
@ value nothing writes back) and necessarily at ARC 0, because no fresh save
@ holds any arc value before it -- writers 2..9 each floor on their
@ predecessor, and 10 sits behind ROUTE 26's eight-badge count, whose FOG
@ BADGE is downstream of the SILVER 3 scene that BurnedTower1F floors at ARC 2
@ (its guard note carries the chain). So on this build the ARC < 3 branch is
@ reachable ONLY on a save made before M7 Task 4 that fought the fish early:
@ one that never agreed with LANCE (fish gone, arc still 0..2, LANCE on the
@ shore), or one that agreed at 0 -> 4 and then had ELM's write of 1 regress
@ it. On both he says "not yet" -- back still turned, no faceplayer, no YES/NO
@ -- and nothing is written or removed; once that save reaches ARC 3 the agree
@ path opens as normal. Otherwise the branch is defensive.
@ ============================================================================
LakeOfRage_EventScript_Lance::
	lock
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 4, LakeOfRage_EventScript_LanceIdle
	goto_if_lt VAR_TRINITY_JOHTO_ARC, 3, LakeOfRage_EventScript_LanceNotYet
	msgbox LakeOfRage_Text_LanceForcedToEvolve, MSGBOX_DEFAULT
	@ GSC speaks that first line BEFORE its faceplayer -- a man talking to the
	@ water with his back turned -- and only then turns round. `faceplayer`
	@ rather than a scripted turn, because his object rests MOVEMENT_TYPE_FACE_UP
	@ and the player can be standing on any of (20,28), (22,28) or (21,29); a
	@ fixed `face_down` would be wrong for two of the three.
	faceplayer
	msgbox LakeOfRage_Text_LanceIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LakeOfRage_EventScript_LanceRefused
	msgbox LakeOfRage_Text_LanceRadioSignal, MSGBOX_DEFAULT
	closemessage
	call LakeOfRage_EventScript_LanceAgreed
	@ GSC's teleport_from, covered by its own sound rather than a fade -- the
	@ documented R4 deviation S5 established for a diegetic disappearance.
	playse SE_WARP_OUT
	removeobject LOCALID_JOHTO_LAKE_LANCE
	waitse
	release
	end

@ Arc-var monotonic guard (S1 rule), plus finding #3's floor: this write is
@ 3 -> 4 and must not fire from anything below 3. The talk script above turns a
@ sub-3 player away before the YES/NO ever shows, so the floor read here is
@ INTENTIONALLY UNREACHABLE / DEFENSIVE (S1: a state write carries its own guard
@ even when the caller's already covers it).
LakeOfRage_EventScript_LanceAgreed::
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 4, LakeOfRage_EventScript_LanceAgreedDone
	goto_if_lt VAR_TRINITY_JOHTO_ARC, 3, LakeOfRage_EventScript_LanceAgreedDone
	setvar VAR_TRINITY_JOHTO_ARC, 4
	@ Arms the MAHOGANY MART staircase cutscene. This is GSC's own
	@ `setmapscene MAHOGANY_MART_1F, SCENE_MAHOGANYMART1F_LANCE_UNCOVERS_STAIRS`
	@ -- the scene value is the arming, and the cutscene advances it, which is
	@ the only thing that stops the mart's ON_FRAME entry re-firing every frame
	@ (TryRunOnFrameMapScript is called from ProcessPlayerFieldInput, not once
	@ per map load, so a table entry gated on a var that never changes locks
	@ the player out of their own input -- src/field_control_avatar.c:177).
	setvar VAR_TRINITY_JOHTO_SCENE_MAHOGANY, 1
LakeOfRage_EventScript_LanceAgreedDone::
	return

LakeOfRage_EventScript_LanceRefused::
	msgbox LakeOfRage_Text_LanceRefused, MSGBOX_DEFAULT
	release
	end

@ Finding #3's floor branch (see THE FLOOR above). No faceplayer: he is still
@ talking to the water.
LakeOfRage_EventScript_LanceNotYet::
	msgbox LakeOfRage_Text_LanceNotYet, MSGBOX_DEFAULT
	release
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE. Once the arc reaches 4 this map's
@ ON_TRANSITION sets FLAG_TRINITY_J_LANCE_LAKE_HIDE on every entry, and the
@ agree path removeobject's him in the same breath, so there is no object left
@ to talk to. Implemented anyway per S1: a talk script that advances story
@ state carries an explicit state guard even when a visibility invariant
@ already covers it.
LakeOfRage_EventScript_LanceIdle::
	faceplayer
	msgbox LakeOfRage_Text_LanceIdle, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ The four post-raid trainers. GSC's parties scaled to the Act II band; the
@ jokes are kept. RAYMOND still fishes up the same POKéMON over and over,
@ AARON still fields the three KANTO starters one stage further on, and LOIS
@ still came for the red GYARADOS and missed it.
@ ============================================================================
LakeOfRage_EventScript_Andre::
	trainerbattle_single TRAINER_JOHTO_FISHER_ANDRE, LakeOfRage_Text_AndreSeen, LakeOfRage_Text_AndreBeaten
	msgbox LakeOfRage_Text_AndreAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Raymond::
	trainerbattle_single TRAINER_JOHTO_FISHER_RAYMOND, LakeOfRage_Text_RaymondSeen, LakeOfRage_Text_RaymondBeaten
	msgbox LakeOfRage_Text_RaymondAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Aaron::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINER_AARON, LakeOfRage_Text_AaronSeen, LakeOfRage_Text_AaronBeaten
	msgbox LakeOfRage_Text_AaronAfter, MSGBOX_AUTOCLOSE
	end

LakeOfRage_EventScript_Lois::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINER_LOIS, LakeOfRage_Text_LoisSeen, LakeOfRage_Text_LoisBeaten
	msgbox LakeOfRage_Text_LoisAfter, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ M4a's three flavour NPCs, given GSC's own before/after states.
@ ============================================================================
LakeOfRage_EventScript_Gramps::
	lock
	faceplayer
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 5, LakeOfRage_EventScript_GrampsAfter
	msgbox LakeOfRage_Text_Gramps, MSGBOX_DEFAULT
	release
	end

LakeOfRage_EventScript_GrampsAfter::
	msgbox LakeOfRage_Text_GrampsAfter, MSGBOX_DEFAULT
	release
	end

LakeOfRage_EventScript_SuperNerd::
	msgbox LakeOfRage_Text_SuperNerd, MSGBOX_NPC
	end

LakeOfRage_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_RED_GYARADOS_HIDE, LakeOfRage_EventScript_CooltrainerFAfter
	msgbox LakeOfRage_Text_CooltrainerF, MSGBOX_DEFAULT
	release
	end

LakeOfRage_EventScript_CooltrainerFAfter::
	msgbox LakeOfRage_Text_CooltrainerFAfter, MSGBOX_DEFAULT
	release
	end

LakeOfRage_EventScript_Sign::
	msgbox LakeOfRage_Text_Sign, MSGBOX_SIGN
	end

LakeOfRage_Text_GyaradosCry:
	.string "The water heaves. Something long\n"
	.string "and red comes up out of it.\p"
	.string "GYARADOS: Gyashaa!$"

LakeOfRage_Text_GotRedScale:
	.string "{PLAYER} picked a RED SCALE off\n"
	.string "the surface of the water.\p"
	.string "It is still warm.$"

@ Finding #3's refusal, the plan's wording. Longest line 34 chars.
LakeOfRage_Text_GyaradosNotYet:
	.string "The water is churning violently.\n"
	.string "Something is agitating the lake --\l"
	.string "but it wants nothing to do with\l"
	.string "you yet.$"

LakeOfRage_Text_LanceForcedToEvolve:
	.string "This lake is full of GYARADOS and\n"
	.string "nothing else.\p"
	.string "So the MAGIKARP are being forced\n"
	.string "to evolve. All of them. At once.$"

LakeOfRage_Text_LanceIntro:
	.string "Did you come here because of the\n"
	.string "rumors?\p"
	.string "You're {PLAYER}. I'm LANCE.\n"
	.string "A trainer, like you.\p"
	.string "I know what you are, incidentally.\n"
	.string "HOENN's news reaches JOHTO.\p"
	.string "Which is why I'll ask plainly,\n"
	.string "champion to trainer.\p"
	.string "Something down in MAHOGANY is\n"
	.string "doing this. Will you help me?$"

LakeOfRage_Text_LanceRadioSignal:
	.string "LANCE: Good.\p"
	.string "It is a radio signal. Low, and\n"
	.string "constant, and coming out of\l"
	.string "MAHOGANY TOWN.\p"
	.string "The souvenir shop, I think.\n"
	.string "Nobody buys that many souvenirs.\p"
	.string "I'll be waiting for you there,\n"
	.string "{PLAYER}.$"

LakeOfRage_Text_LanceRefused:
	.string "Oh. Well.\p"
	.string "If you change your mind, come\n"
	.string "and find me. I'll be here.\p"
	.string "The lake isn't going anywhere,\n"
	.string "and neither are they.$"

LakeOfRage_Text_LanceIdle:
	.string "LANCE: MAHOGANY TOWN. The shop.\n"
	.string "I'll go on ahead.$"

@ Finding #3's floor line. Unnamed: on this branch he has not introduced
@ himself, and his back is turned.
LakeOfRage_Text_LanceNotYet:
	.string "…No. Not yet.\p"
	.string "This isn't your fight.\n"
	.string "Come back when it is.$"

LakeOfRage_Text_Gramps:
	.string "The GYARADOS are angry!\p"
	.string "It's a bad omen. My father said\n"
	.string "this lake was dug by their rage,\l"
	.string "and I never believed him until\l"
	.string "this week.$"

LakeOfRage_Text_GrampsAfter:
	.string "Hahah! The MAGIKARP are biting!\p"
	.string "A lake full of MAGIKARP is a\n"
	.string "boring lake, and I have never\l"
	.string "been so glad to be bored.$"

LakeOfRage_Text_SuperNerd:
	.string "I heard this lake was made by\n"
	.string "rampaging GYARADOS.\p"
	.string "I wonder if there's any connection\n"
	.string "to their mass outbreak now?$"

LakeOfRage_Text_CooltrainerF:
	.string "Did my eyes deceive me? I saw a\n"
	.string "red GYARADOS out in the LAKE.\p"
	.string "But I thought GYARADOS were\n"
	.string "usually blue?$"

LakeOfRage_Text_CooltrainerFAfter:
	.string "So it WAS red. I knew it.\p"
	.string "Nobody believed me, and now\n"
	.string "there's nothing left to point at.$"

LakeOfRage_Text_Sign:
	.string "LAKE OF RAGE,\nalso known as\lGYARADOS LAKE.$"

LakeOfRage_Text_AndreSeen:
	.string "Let me battle with the POKéMON\n"
	.string "I just caught!$"

LakeOfRage_Text_AndreBeaten:
	.string "I might be an expert angler, but\n"
	.string "I stink as a trainer…$"

LakeOfRage_Text_AndreAfter:
	.string "I won't lose as an angler! I catch\n"
	.string "POKéMON all day.\p"
	.string "Ever since the water cleared, I\n"
	.string "catch good ones, too.$"

LakeOfRage_Text_RaymondSeen:
	.string "No matter what I do, all I catch\n"
	.string "are the same POKéMON…$"

LakeOfRage_Text_RaymondBeaten:
	.string "My line's all tangled up…$"

LakeOfRage_Text_RaymondAfter:
	.string "Why can't I catch any good\n"
	.string "POKéMON?\p"
	.string "The last one did evolve, mind\n"
	.string "you. Eventually. On its own.$"

LakeOfRage_Text_AaronSeen:
	.string "If a trainer spots another\n"
	.string "trainer, he has to challenge them.\p"
	.string "That is our destiny.$"

LakeOfRage_Text_AaronBeaten:
	.string "Whew…\nGood battle.$"

LakeOfRage_Text_AaronAfter:
	.string "POKéMON and their trainer become\n"
	.string "powerful through constant\l"
	.string "battling.\p"
	.string "You didn't get where you are by\n"
	.string "standing on a shore.$"

LakeOfRage_Text_LoisSeen:
	.string "What happened to the red\n"
	.string "GYARADOS? It's gone?\p"
	.string "Oh, darn. I came all this way for\n"
	.string "nothing?\p"
	.string "I know -- let's battle!$"

LakeOfRage_Text_LoisBeaten:
	.string "Good going!$"

LakeOfRage_Text_LoisAfter:
	.string "Come to think of it, I've seen a\n"
	.string "pink BUTTERFREE.\p"
	.string "Nobody believes that one either.$"
