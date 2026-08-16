@ ============================================================================
@ Trinity M4b S9 -- BLACKTHORN GYM 1F. THE GYM PATTERN (G1-G7), copied from
@ data/maps/VioletGym/scripts.inc, whose header carries the full rationale.
@ Substituted here: CLAIR, FLAG_TRINITY_BADGE16, DRAGON -- and ONE STRUCTURAL
@ VARIANT, G-VARIANT-S, described below.
@
@ ---------------------------------------------------------------------------
@ THE FLOOR IS A PUZZLE, AND WITHOUT IT THIS GYM CANNOT BE FINISHED.
@ ---------------------------------------------------------------------------
@ Decoded from data/layouts/BlackthornGym1F_Johto/map.bin, this floor is FOUR
@ disjoint regions, not one:
@
@   E  entrance   68 tiles  PAUL (1,14), the guide (7,15), both statues, the
@                           ladder (1,7), hole-landing (2,6)   <- the doors
@   R  right      13 tiles  MIKE (6,6), ladder (7,9), hole-landings (7,6)/(7,7)
@   X  east corr.  7 tiles  (9,2)-(9,8), LOLA (9,2)            <- nothing
@   C  chamber    13 tiles  rows 2-4, x 3-7, CLAIR (5,3)       <- nothing
@
@ `reach_check.py --dungeon BlackthornGym1F BlackthornGym2F` on the shipped ROM
@ reports "no sealed warps" and it is telling the truth -- no WARP lives in X
@ or C. CLAIR still cannot be reached from any door. That is not a port defect:
@ it is GSC's puzzle with only half of it wired.
@
@ GSC's other half: 2F carries six Strength boulders and three holes; pushing a
@ boulder into a hole `disappear`s it permanently and 1F's MAPCALLBACK_TILES
@ then `changeblock`s a fallen-boulder block into the floor BELOW it, at the
@ SAME (x,y). Those three blocks are the bridges:
@
@   (8,3) opens  ->  C <-> X   (GSC changeblock 8,2,$3b)   REQUIRED
@   (8,7) opens  ->  X <-> R   (GSC changeblock 8,6,$3b)   REQUIRED
@   (2,5) opens  ->  a one-tile alcove off E               THE RED HERRING
@
@ so the route to CLAIR is: 2F ladder (7,9) -> R -> (8,7) -> up the x=9
@ corridor -> (8,3) -> (7,3) -> (5,3). Two of the three boulders are mandatory.
@ The mechanic itself (the engine hook that notices a boulder landing on a
@ hole) lives in src/field_player_avatar.c's TryBoulderFallThroughHole and in
@ data/maps/BlackthornGym2F/scripts.inc; this file is only the door.
@
@ ---------------------------------------------------------------------------
@ D1-D5, THE SETMETATILE DOOR PATTERN, and the converter's block map (S8's pin)
@ ---------------------------------------------------------------------------
@ tools/johto_port/convert.py:97-107 writes every map cell as
@     metatile = 512 + 4*<GSC block id> + q,   q order [TL, TR, BL, BR]
@ with collision from pokecrystal's <tileset>_collision.asm row for that block,
@ same quadrant order. `changeblock x, y, $NN` addresses block (x/2, y/2) -- the
@ arguments are ordinary map step coordinates (Script_changeblock adds 4 and
@ GetBlockLocation halves against a buffer whose block (0,0) sits at
@ +3*(w+6)+3; solving the two gives back x/2, y/2). So the three callbacks are
@ mechanical:
@
@   block (4,1) = steps (8..9, 2..3)   $20 (W,F,W,F) -> $3b (W,F,F,F)  (8,3) opens
@   block (1,2) = steps (2..3, 4..5)   $1b (W,F,W,W) -> $3a (W,F,F,W)  (2,5) opens
@   block (4,3) = steps (8..9, 6..7)   $20 (W,F,W,F) -> $3b (W,F,F,F)  (8,7) opens
@
@ $3a -> metatiles 512+4*58+q = 744-747, $3b -> 512+4*59+q = 748-751. Verified
@ present: gTileset_EliteFourRoomIndoorJohto holds 256 metatiles and 744-751
@ all carry attribute byte 0x00 = MB_NORMAL.
@
@ D2: the shipped map.bin has all three holes SHUT, so the authoring direction
@ is OPEN, and ON_TRANSITION is the single authoring site. D3's DrawWholeMapView
@ IS DELIBERATELY ABSENT AND THAT IS SOUND HERE: the switch is on 2F and the
@ door is on 1F, so the player always crosses a map load between the push and
@ the platform, and ON_TRANSITION runs before InitMap draws anything.
@ setmetatile never touches elevation (src/fieldmap.c:383-393); all three
@ opened tiles decode elevation 0 = ELEVATION_TRANSITION, which
@ IsElevationMismatchAt always accepts (src/event_object_movement.c:9806-9822),
@ so the platform is walkable from its elevation-3 neighbors with no elevation
@ work. All FOUR quadrants of each block are written (D5) because the
@ fallen-boulder art occupies the whole block, not just the tile whose
@ collision changes.
@
@ ---------------------------------------------------------------------------
@ G-VARIANT-S -- THE BADGE IS AWARDED ON ANOTHER MAP
@ ---------------------------------------------------------------------------
@ G2 normally puts the badge inside <Leader>Defeated. GSC's CLAIR REFUSES the
@ badge after losing and sends the player to the DRAGON'S DEN, and the brief
@ pins badge 16 AND TM02 to the SHRINE. So here:
@   * <Leader>Defeated advances VAR_TRINITY_JOHTO_SCENE_BLACKTHORN 0 -> 1 under
@     the S1 monotonic guard and prints the refusal. It writes NOTHING failable.
@   * the re-talk path is a redirect to the Den until the test is passed, and a
@     league send-off afterwards.
@   * FLAG_TRINITY_BADGE16 and TM02 are written once, at DragonShrine.
@ G2's SAFETY clause is still honored across the map boundary: nothing
@ failable stands between beating CLAIR and the badge, and at the shrine the
@ badge is set BEFORE the TM. G7 still holds -- the shrine is the badge flag's
@ ONE writer; this file only reads it.
@
@ ---------------------------------------------------------------------------
@ ROSTER CHECK (the ledger's data-verification rule -- fourth occurrence of the
@ defect class it exists to prevent, so the derivation is written down):
@   ALTARIA   L69  MON_TYPES(TYPE_DRAGON, TYPE_FLYING)
@   FLYGON    L70  MON_TYPES(TYPE_GROUND, TYPE_DRAGON)
@   GYARADOS  L71  MON_TYPES(TYPE_WATER,  TYPE_FLYING)
@   DRAGONITE L70  MON_TYPES(TYPE_DRAGON, TYPE_FLYING)
@   KINGDRA   L72  MON_TYPES(TYPE_WATER,  TYPE_DRAGON)
@ From gTypeEffectivenessTable (src/data/types_info.h):
@   ICE      ->FLYING 2.0 ->GROUND 2.0 ->DRAGON 2.0 ->WATER 0.5
@            = 4x on ALTARIA, FLYGON, DRAGONITE; 1.0 (NEUTRAL) on GYARADOS and
@              KINGDRA, whose WATER half exactly cancels it. GSC's own guide
@              says "weak to ice" flat out, and for two of the five that is
@              FALSE. The guide below says which.
@   DRAGON   ->DRAGON 2.0, everything here else 1.0
@            = 2x on four; GYARADOS is the odd one out (no DRAGON half).
@   ELECTRIC ->WATER 2.0 ->FLYING 2.0 ->DRAGON 0.5 ->GROUND 0.0
@            = 4x on GYARADOS, 1.0 on KINGDRA/ALTARIA/DRAGONITE, and IMMUNE
@              against FLYGON. That immunity is the trap worth naming.
@ LEVEL BAND: CLAIR L69-72. Her five gym trainers are M4a's and are BELOW her,
@ so the ECRUTEAK/CIANWOOD inversion does not recur here.
@ ============================================================================

	.set METATILE_JohtoEliteFourRoom_BoulderInNookTL, 744  @ GSC $3a q0  WALL
	.set METATILE_JohtoEliteFourRoom_BoulderInNookTR, 745  @ GSC $3a q1  FLOOR
	.set METATILE_JohtoEliteFourRoom_BoulderInNookBL, 746  @ GSC $3a q2  FLOOR <- platform
	.set METATILE_JohtoEliteFourRoom_BoulderInNookBR, 747  @ GSC $3a q3  WALL
	.set METATILE_JohtoEliteFourRoom_BoulderInPitTL,  748  @ GSC $3b q0  WALL
	.set METATILE_JohtoEliteFourRoom_BoulderInPitTR,  749  @ GSC $3b q1  FLOOR
	.set METATILE_JohtoEliteFourRoom_BoulderInPitBL,  750  @ GSC $3b q2  FLOOR <- platform
	.set METATILE_JohtoEliteFourRoom_BoulderInPitBR,  751  @ GSC $3b q3  FLOOR

BlackthornGym1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornGym1F_OnTransition
	.byte 0

BlackthornGym1F_OnTransition:
	call BlackthornGym1F_EventScript_AuthorPlatforms
	end

@ D2. Three independent doors, one authoring site, authored OPEN because the
@ shipped map.bin is SHUT. Monotonic: a platform flag is only ever set.
BlackthornGym1F_EventScript_AuthorPlatforms::
	goto_if_unset FLAG_TRINITY_J_BGYM_PLATFORM_A, BlackthornGym1F_EventScript_SkipPlatformA
	setmetatile 2, 4, METATILE_JohtoEliteFourRoom_BoulderInNookTL, TRUE
	setmetatile 3, 4, METATILE_JohtoEliteFourRoom_BoulderInNookTR, FALSE
	setmetatile 2, 5, METATILE_JohtoEliteFourRoom_BoulderInNookBL, FALSE
	setmetatile 3, 5, METATILE_JohtoEliteFourRoom_BoulderInNookBR, TRUE
BlackthornGym1F_EventScript_SkipPlatformA::
	goto_if_unset FLAG_TRINITY_J_BGYM_PLATFORM_B, BlackthornGym1F_EventScript_SkipPlatformB
	setmetatile 8, 6, METATILE_JohtoEliteFourRoom_BoulderInPitTL, TRUE
	setmetatile 9, 6, METATILE_JohtoEliteFourRoom_BoulderInPitTR, FALSE
	setmetatile 8, 7, METATILE_JohtoEliteFourRoom_BoulderInPitBL, FALSE
	setmetatile 9, 7, METATILE_JohtoEliteFourRoom_BoulderInPitBR, FALSE
BlackthornGym1F_EventScript_SkipPlatformB::
	goto_if_unset FLAG_TRINITY_J_BGYM_PLATFORM_C, BlackthornGym1F_EventScript_SkipPlatformC
	setmetatile 8, 2, METATILE_JohtoEliteFourRoom_BoulderInPitTL, TRUE
	setmetatile 9, 2, METATILE_JohtoEliteFourRoom_BoulderInPitTR, FALSE
	setmetatile 8, 3, METATILE_JohtoEliteFourRoom_BoulderInPitBL, FALSE
	setmetatile 9, 3, METATILE_JohtoEliteFourRoom_BoulderInPitBR, FALSE
BlackthornGym1F_EventScript_SkipPlatformC::
	return

@ ============================================================================
@ G1/G2/G3 -- CLAIR. Talk-triggered, TRAINER_TYPE_NONE, sight 0, flag 0,
@ APPENDED to object_events so M4a's four local ids do not shift. GSC's tile
@ (5,3), decoded collision 0 elevation 3 MB_NORMAL, in the middle of chamber C
@ with (5,4) below her and (4,3)/(6,3) either side -- she is not a cut vertex
@ of a 13-tile room whose rows 3 and 4 are both open across x 3-7.
@ NO_MUSIC per G3: PlayTrainerEncounterMusic is a whole-map BGM swap, not a
@ jingle, and that belongs to a sight line. Battle BGM needs no scripting --
@ TRAINER_CLAIR is 1037, the top of GetBattleBGM's Johto-leader range
@ (TRAINER_FALKNER..TRAINER_CLAIR, 1030-1037), so it is MUS_RG_VS_GYM_LEADER.
@ ============================================================================
BlackthornGym1F_EventScript_Clair::
	trainerbattle_single TRAINER_CLAIR, BlackthornGym1F_Text_ClairIntro, BlackthornGym1F_Text_ClairDefeat, BlackthornGym1F_EventScript_ClairDefeated, NO_MUSIC
	@ Re-talk path only: the engine's per-id defeated flag already gated the
	@ continuation above, so execution reaches here on a LATER talk.
	goto_if_set FLAG_TRINITY_BADGE16, BlackthornGym1F_EventScript_ClairLeague
	msgbox BlackthornGym1F_Text_ClairStillWaiting, MSGBOX_DEFAULT
	release
	end

@ G-VARIANT-S: no badge here. The ONLY durable write is the monotonic scene
@ advance that arms the DRAGON'S DEN, and it carries S1's goto_if_ge guard even
@ though the continuation is structurally once-per-save -- the arc/scene
@ write-discipline rule takes no exceptions.
BlackthornGym1F_EventScript_ClairDefeated::
	goto_if_ge VAR_TRINITY_JOHTO_SCENE_BLACKTHORN, 1, BlackthornGym1F_EventScript_ClairRefusal
	setvar VAR_TRINITY_JOHTO_SCENE_BLACKTHORN, 1
BlackthornGym1F_EventScript_ClairRefusal::
	msgbox BlackthornGym1F_Text_ClairRefusesTheBadge, MSGBOX_DEFAULT
	release
	end

BlackthornGym1F_EventScript_ClairLeague::
	msgbox BlackthornGym1F_Text_ClairLeague, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ G6 -- M4a's three 1F gym trainers keep their ids, GSC tiles and seen/beaten
@ text, and each gains GSC's own distinct after-battle line (the port left all
@ three re-showing the beaten text). Sight-triggered, so G3's NO_MUSIC does not
@ apply.
@
@ LOLA at (9,2) is a POST-PUZZLE trainer by GSC's own geometry -- she stands at
@ the top of corridor X, which nothing reaches until hole C is plugged. Her
@ sight radius is 1, so her post-battle resting set is exactly {(9,2)} (S8's
@ approach-path rule: P .. P+(r-1)*d), and (9,2) is a dead end whose only
@ neighbor is (9,3). She costs nothing.
@
@ GSC's CLAIR also `setevent`s all five gym trainers as beaten the moment she
@ loses. NOT PORTED: a trainer id carries ONE permanent per-id flag (R3b), so
@ pre-setting five would silently delete five battles -- and here it would
@ delete them for a player who reached CLAIR the intended way, since the route
@ to her runs past MIKE and skips nobody else.
@ ============================================================================
BlackthornGym1F_EventScript_MIKE::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERM_MIKE, BlackthornGym1F_Text_MIKESeen, BlackthornGym1F_Text_MIKEBeaten
	msgbox BlackthornGym1F_Text_MIKEAfterBattle, MSGBOX_AUTOCLOSE
	end

BlackthornGym1F_EventScript_PAUL::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERM_PAUL, BlackthornGym1F_Text_PAULSeen, BlackthornGym1F_Text_PAULBeaten
	msgbox BlackthornGym1F_Text_PAULAfterBattle, MSGBOX_AUTOCLOSE
	end

BlackthornGym1F_EventScript_LOLA::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINERF_LOLA, BlackthornGym1F_Text_LOLASeen, BlackthornGym1F_Text_LOLABeaten
	msgbox BlackthornGym1F_Text_LOLAAfterBattle, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ G4 -- the guide, two states on the badge flag. He is at M4a's (7,15), GSC's
@ own tile. THE S6 COLUMN CHECK: (7,14)/(7,15) is a two-tile column hanging off
@ (7,16), with walls at (6,14)/(6,15) -- but (8,14)/(8,15) are BOTH walkable
@ and open to row 16, so the column is not single-file and standing at its foot
@ seals nothing. The flood fill agrees: one tile lost, his own. (VIOLET's and
@ OLIVINE's guides on GSC's (7,13) were cut vertices and had to move; this one
@ does not.)
@ His advice states CLAIR's type, the honest weaknesses and the level band --
@ and, because this floor cannot be crossed without it, STRENGTH.
@ ============================================================================
BlackthornGym1F_EventScript_BlackthornGymGuide::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_BADGE16, BlackthornGym1F_EventScript_GuideWin
	msgbox BlackthornGym1F_Text_BlackthornGymGuide, MSGBOX_DEFAULT
	release
	end

BlackthornGym1F_EventScript_GuideWin::
	msgbox BlackthornGym1F_Text_GuideWin, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ G5 -- (3,15) and (6,15) decode collision 1: GSC's two statue tiles, read
@ facing north from (3,16) and (6,16), both collision 0 elevation 3 and both
@ left clear of objects (S5's I1 pin -- a facing bg_event on a collision-1 tile
@ has exactly one reading tile and reach_check cannot see it). One entry script
@ for both bg_events, per S5's statue dedupe. Badges 9-16 have no engine UI, so
@ this is the only in-world confirmation the player gets.
@ ============================================================================
BlackthornGym1F_EventScript_Statue::
	lockall
	goto_if_set FLAG_TRINITY_BADGE16, BlackthornGym1F_EventScript_StatueCertified
	msgbox BlackthornGym1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

BlackthornGym1F_EventScript_StatueCertified::
	msgbox BlackthornGym1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

@ ============================================================================
@ Text. CLAIR's speeches are GSC's, tightened for Act II: she is not meeting a
@ beginner, she is meeting the HOENN CHAMPION, and her whole character is that
@ this makes it worse rather than better.
@ ============================================================================
BlackthornGym1F_Text_ClairIntro:
	.string "I am CLAIR. The world's best\n"
	.string "dragon master.\p"
	.string "I can hold my own against the\n"
	.string "ELITE FOUR, and I have.\p"
	.string "So spare me the HOENN trophy.\n"
	.string "A title is somebody else's\l"
	.string "opinion of you.\p"
	.string "Do you still want to take me on?\p"
	.string "…Fine. Let's do it.\p"
	.string "I am a GYM LEADER. I use my full\n"
	.string "power against every opponent, and\l"
	.string "today that is not a courtesy.$"

BlackthornGym1F_Text_ClairDefeat:
	.string "I lost?\p"
	.string "I don't believe it. There must be\n"
	.string "some mistake…$"

BlackthornGym1F_Text_ClairRefusesTheBadge:
	.string "I won't admit this.\p"
	.string "You may have won, but you are\n"
	.string "still not ready for the LEAGUE.\l"
	.string "A trophy is not a temperament.\p"
	.string "I know. Take the dragon user's\n"
	.string "challenge.\p"
	.string "Behind this GYM is a place called\n"
	.string "DRAGON'S DEN. There is a small\l"
	.string "shrine at its center. Go there.\p"
	.string "If you can prove you have lost\n"
	.string "your lazy ideals, I will recognize\l"
	.string "you as a trainer worthy of a\l"
	.string "BADGE.$"

BlackthornGym1F_Text_ClairStillWaiting:
	.string "What's the matter?\p"
	.string "Is the DRAGON'S DEN too much to\n"
	.string "expect of you?\p"
	.string "The shrine. At its center. Go.$"

@ Badge-agnostic (the ledger's rule: the Johto gyms are open-order, so no line
@ may count badges) and no directions to a place the player cannot yet stand.
BlackthornGym1F_Text_ClairLeague:
	.string "Aren't you headed for the LEAGUE?\p"
	.string "INDIGO PLATEAU is west of here,\n"
	.string "past VICTORY ROAD, and the road is\l"
	.string "as tough as anything in JOHTO.\p"
	.string "Don't you dare lose there.\p"
	.string "If you do, I'll feel even worse\n"
	.string "about having lost to you.\p"
	.string "Give it everything you have.$"

BlackthornGym1F_Text_MIKESeen:
	.string "My chance of losing? Not even one\n"
	.string "percent!$"

BlackthornGym1F_Text_MIKEBeaten:
	.string "That's odd.$"

BlackthornGym1F_Text_MIKEAfterBattle:
	.string "I know my shortcomings now.\p"
	.string "Thanks for showing me!$"

BlackthornGym1F_Text_PAULSeen:
	.string "Your first battle against dragons?\p"
	.string "I'll show you how tough they are!$"

BlackthornGym1F_Text_PAULBeaten:
	.string "My dragon POKéMON lost?$"

BlackthornGym1F_Text_PAULAfterBattle:
	.string "LANCE told you he'd like to see\n"
	.string "you again? Not a chance!$"

BlackthornGym1F_Text_LOLASeen:
	.string "Dragons are sacred POKéMON.\p"
	.string "They are full of life energy.\p"
	.string "If you're not serious, you won't\n"
	.string "be able to beat them.$"

BlackthornGym1F_Text_LOLABeaten:
	.string "Way to go!$"

BlackthornGym1F_Text_LOLAAfterBattle:
	.string "Dragons are weak against\n"
	.string "dragon-type moves.$"

@ Every claim below is derived in the ROSTER CHECK at the top of this file.
BlackthornGym1F_Text_BlackthornGymGuide:
	.string "Yo! CHAMP in making!\p"
	.string "Two things before you go up.\p"
	.string "One: this floor is a puzzle. The\n"
	.string "gaps only close when a boulder\l"
	.string "drops through from 2F, so bring a\l"
	.string "POKéMON that knows STRENGTH or you\l"
	.string "will never reach her.\p"
	.string "Two: everyone tells you dragons\n"
	.string "hate ice. Half true.\p"
	.string "Ice hits her ALTARIA, FLYGON and\n"
	.string "DRAGONITE four times over -- but\l"
	.string "her GYARADOS and KINGDRA shrug it\l"
	.string "off. They're part water.\p"
	.string "Save an electric move for the\n"
	.string "GYARADOS. Don't aim one at the\l"
	.string "FLYGON, it won't feel a thing.\p"
	.string "Dragon moves land on four of the\n"
	.string "five. She's L69 to L72. Count on\l"
	.string "me!$"

BlackthornGym1F_Text_GuideWin:
	.string "You were great to beat CLAIR!\p"
	.string "Though I hear she still wouldn't\n"
	.string "hand over the BADGE. That's CLAIR.\p"
	.string "All that's left after that is the\n"
	.string "LEAGUE challenge itself!$"

BlackthornGym1F_Text_GymStatue:
	.string "BLACKTHORN CITY POKéMON GYM\n"
	.string "LEADER: CLAIR\p"
	.string "The Blessed User of Dragon\n"
	.string "POKéMON$"

BlackthornGym1F_Text_GymStatueCertified:
	.string "BLACKTHORN CITY POKéMON GYM\n"
	.string "LEADER: CLAIR\p"
	.string "The Blessed User of Dragon\n"
	.string "POKéMON\p"
	.string "{PLAYER} won the RISINGBADGE --\n"
	.string "at the shrine, not in this room.$"
