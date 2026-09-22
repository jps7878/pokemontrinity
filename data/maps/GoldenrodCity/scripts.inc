GoldenrodCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M4b S4 -- GOLDENROD CITY, pre-takeover.
@
@ THE S8 FLIP CONTRACT (also in include/constants/flags.h and in each RADIO
@ TOWER floor's header). S8 writes ONE thing -- setvar VAR_TRINITY_JOHTO_ARC, 6
@ -- and never touches either _HIDE flag. This ON_TRANSITION is both flags'
@ SINGLE AUTHORING SITE (S1 rule); it runs before InitMap and object spawning,
@ so no new-game flag defaults are needed.
@
@   civilians (7 objects)  visible iff VAR_TRINITY_JOHTO_ARC != 6
@   ROCKET SCOUT (1)       visible iff VAR_TRINITY_JOHTO_ARC <  6
@
@ DELIBERATE AMENDMENT, LEDGERED: the S4 brief proposed "hidden at ARC >= 6".
@ S4 ships "!= 6" for the CIVILIANS, because the occupation is a WINDOW, not a
@ terminal state -- ARC 7 is "Tower cleared", and a liberated city whose entire
@ civilian population stayed deleted forever is worse than the bug that would
@ avoid.
@
@ THE SCOUT IS THE EXCEPTION, AND IT IS THE WORKED EXAMPLE OF THE ESCAPE HATCH
@ THIS CONTRACT ADVERTISES TO S8. He RETIRES PERMANENTLY: GSC clears
@ EVENT_GOLDENROD_CITY_ROCKET_SCOUT at the takeover and never sets it again, so
@ riding the shared "!= 6" flag would resurrect him at ARC >= 7 -- a Rocket
@ still casing a tower his own organisation already stormed and lost. R1 names
@ the fix ("if a beat needs one member to outlive the others, give that member
@ its own flag"), so he has FLAG_TRINITY_J_GOLDENROD_SCOUT_HIDE and his own
@ predicate, authored in this same ON_TRANSITION. S8 does EXACTLY THIS whenever
@ it wants a member of an S4 cast on a different schedule: claim a flag, add a
@ call here, leave everything else alone.
@
@ S8's own Rocket cast gets its OWN flag and APPENDED objects, so (a) S4's
@ local ids never shift and (b) a removeobject in S8's liberation scene cannot
@ co-sign one of these civilians into permanent non-existence (R1's trap).
@
@ HAZARD FOR S8 (a): the ON_TRANSITION slot is SINGLE-OCCUPANCY.
@ MapHeaderGetScriptTable walks the map-script table and RETURNS ON THE FIRST
@ entry matching the tag (src/script.c:302-321), so a second
@ `map_script MAP_SCRIPT_ON_TRANSITION` on this map is silently dead code. S8's
@ arc-6 setvar must live in a coord_event, an ON_FRAME table, another map --
@ or S8 edits THIS script.
@ HAZARD FOR S8 (b): if the arc write ever lands in the same transition, put it
@ BEFORE the visibility calls. These calls read VAR_TRINITY_JOHTO_ARC at the
@ moment they run; an arc write after them leaves the flags describing the
@ PREVIOUS state until the next map load, i.e. the flip lags by one entry.
@ ============================================================================
@ ============================================================================
@ Trinity M4b S8 -- THE TAKEOVER FIRES HERE, and it is the FIRST thing this
@ transition does.
@
@ AMENDMENT TO THE S8 BRIEF, deliberate and controller-visible. The brief asked
@ for "a coord/ON_FRAME in GOLDENROD, NOT inside the flip ON_TRANSITIONs". Both
@ of those are unsafe, and the flip contract in this very file names editing
@ this script as the third, sanctioned option ("or S8 edits these scripts"):
@
@   * ON_FRAME is disqualified by S7's own pin. TryRunOnFrameMapScript fires
@     from ProcessPlayerFieldInput EVERY FRAME while its gating var matches and
@     returns TRUE, aborting player input (src/field_control_avatar.c:177). An
@     entry gated on ARC == 5 fires forever for a player who has only six
@     badges, because the script cannot advance the var it is gated on. That is
@     a hard input lock.
@   * A coord_event is disqualified by hazard (b) below -- the city's and the
@     tower's visibility calls read VAR_TRINITY_JOHTO_ARC during ON_TRANSITION,
@     i.e. before the player is standing anywhere. A write that lands after the
@     map has loaded leaves the player in a city whose population describes the
@     PREVIOUS state until the next map load.
@   * The write as the first line of this transition is exactly what hazard (b)
@     prescribes: "Arc write first."
@
@ EVERY route into the occupied area passes through GOLDENROD CITY -- the tower
@ door (5,15), both UNDERGROUND stairwells (9,5)/(11,29), the dept store, the
@ gym, the Pokecentre and the Magnet Train station are all warps FROM this map,
@ and ROUTE 34 / the ROUTE 35 gate are its only other entrances. So the flip is
@ always coherent by the time any occupied map loads.
@
@ ONE WRITE, ONCE. `goto_if_ne ... 5` is both the monotonic guard and the
@ once-only guard: ARC 5 is written exactly once (by S7's base terminator) and
@ this is its only consumer.
@ ============================================================================
GoldenrodCity_OnTransition:
	call GoldenrodCity_EventScript_TryRocketTakeover
	call GoldenrodCity_EventScript_SetPreTakeoverVisibility
	call GoldenrodCity_EventScript_SetScoutVisibility
	call GoldenrodCity_EventScript_SetTakeoverVisibility
	call GoldenrodCity_EventScript_SetBobbyVisibility
	end

GoldenrodCity_EventScript_TryRocketTakeover::
	goto_if_ne VAR_TRINITY_JOHTO_ARC, 5, GoldenrodCity_EventScript_NoTakeover
	call Trinity_EventScript_CountJohtoBadges
	goto_if_lt VAR_TEMP_A, 7, GoldenrodCity_EventScript_NoTakeover
	setvar VAR_TRINITY_JOHTO_ARC, 6
GoldenrodCity_EventScript_NoTakeover::
	return

@ S8's own cast, its own flag, appended objects -- so no S4 local id shifts and
@ no removeobject here can co-sign an S4 civilian into permanent non-existence.
GoldenrodCity_EventScript_SetTakeoverVisibility::
	goto_if_ne VAR_TRINITY_JOHTO_ARC, 6, GoldenrodCity_EventScript_HideTakeover
	clearflag FLAG_TRINITY_J_GOLDENROD_ROCKETS_HIDE
	return

GoldenrodCity_EventScript_HideTakeover::
	setflag FLAG_TRINITY_J_GOLDENROD_ROCKETS_HIDE
	return

@ BOBBY's coda post. Terminal state -- once the tower falls he stays.
GoldenrodCity_EventScript_SetBobbyVisibility::
	goto_if_lt VAR_TRINITY_JOHTO_ARC, 7, GoldenrodCity_EventScript_HideBobby
	clearflag FLAG_TRINITY_J_GOLDENROD_BOBBY_HIDE
	return

GoldenrodCity_EventScript_HideBobby::
	setflag FLAG_TRINITY_J_GOLDENROD_BOBBY_HIDE
	return

GoldenrodCity_EventScript_SetPreTakeoverVisibility::
	goto_if_eq VAR_TRINITY_JOHTO_ARC, 6, GoldenrodCity_EventScript_HidePreTakeover
	clearflag FLAG_TRINITY_J_GOLDENROD_PRE_HIDE
	return

GoldenrodCity_EventScript_HidePreTakeover::
	setflag FLAG_TRINITY_J_GOLDENROD_PRE_HIDE
	return

@ The scout's own predicate -- ARC < 6, i.e. he never comes back.
GoldenrodCity_EventScript_SetScoutVisibility::
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 6, GoldenrodCity_EventScript_HideScout
	clearflag FLAG_TRINITY_J_GOLDENROD_SCOUT_HIDE
	return

GoldenrodCity_EventScript_HideScout::
	setflag FLAG_TRINITY_J_GOLDENROD_SCOUT_HIDE
	return

GoldenrodCity_EventScript_PokefanM::
	msgbox GoldenrodCity_Text_PokefanM, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Youngster1::
	msgbox GoldenrodCity_Text_Youngster1, MSGBOX_NPC
	end

@ Her line points AT the ROCKET SCOUT, so it has to follow his retirement or it
@ becomes a woman describing an empty pavement. Same predicate as his object
@ (ARC >= 6 == retired), so the two can never disagree. GSC has both halves:
@ GoldenrodCityCooltrainerF1Text and …Text_ClearedRadioTower.
@ NOTE on the ARC == 6 case: she is herself hidden then (she is on the
@ civilians' "!= 6" flag), so the retired branch is only ever SEEN at ARC >= 7.
@ The guard is still written on ARC >= 6 so it matches the scout's predicate
@ exactly rather than relying on her visibility to cover the gap.
GoldenrodCity_EventScript_CooltrainerF1::
	lock
	faceplayer
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 6, GoldenrodCity_EventScript_CooltrainerF1ScoutGone
	msgbox GoldenrodCity_Text_CooltrainerF1, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_CooltrainerF1ScoutGone::
	msgbox GoldenrodCity_Text_CooltrainerF1ScoutGone, MSGBOX_DEFAULT
	release
	end

@ Branches on S1's RADIO CARD flag: ELM already fitted the POKéNAV as a radio,
@ so the campaign line has to acknowledge it.
@ INTENTIONALLY UNREACHABLE / DEFENSIVE -- the unset branch below
@ (…_Text_CooltrainerF2) cannot be reached in a normal save. ELM sets
@ FLAG_TRINITY_J_RADIO_CARD in the New Bark chapter (data/maps/ElmsLab/
@ scripts.inc:53), and that chapter is what drives VAR_TRINITY_JOHTO_ARC to 2;
@ nothing lets a player stand in GOLDENROD at ARC < 2. It is written as real
@ dialogue rather than an assert because a flavour NPC must never dead-end.
GoldenrodCity_EventScript_CooltrainerF2::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_RADIO_CARD, GoldenrodCity_EventScript_CooltrainerF2GotCard
	msgbox GoldenrodCity_Text_CooltrainerF2, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_CooltrainerF2GotCard::
	msgbox GoldenrodCity_Text_CooltrainerF2GotCard, MSGBOX_DEFAULT
	@ M7b Task 14 (finding #9): the RADIO CARD is the channel, so the person
	@ who fits it reads the player today's bulletin -- the same arc-keyed
	@ ladder every JOHTO hub guide reads. Reached only through the existing
	@ goto_if_set FLAG_TRINITY_J_RADIO_CARD branch above.
	goto Trinity_EventScript_JohtoGuide
	end

GoldenrodCity_EventScript_Youngster2::
	msgbox GoldenrodCity_Text_Youngster2, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Lass::
	msgbox GoldenrodCity_Text_Lass, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Gramps::
	msgbox GoldenrodCity_Text_Gramps, MSGBOX_NPC
	end

GoldenrodCity_EventScript_RocketScout::
	msgbox GoldenrodCity_Text_RocketScout, MSGBOX_NPC
	end

@ ============================================================================
@ Trinity M4b S8 -- the occupation cast. Talk-only set dressing, no trainer ids
@ (the 22-post budget is spent inside the tower and the UNDERGROUND). Adapts
@ pokecrystal GoldenrodCityRocket1..6Text; GSC's sixth man at (31,10) is
@ dropped -- he stands one tile from the PP SPEECH HOUSE door and buys nothing.
@ ============================================================================
GoldenrodCity_EventScript_Rocket1::
	msgbox GoldenrodCity_Text_Rocket1, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Rocket2::
	msgbox GoldenrodCity_Text_Rocket2, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Rocket3::
	msgbox GoldenrodCity_Text_Rocket3, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Rocket4::
	msgbox GoldenrodCity_Text_Rocket4, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Rocket5::
	msgbox GoldenrodCity_Text_Rocket5, MSGBOX_NPC
	end

@ BOBBY's coda. He is DIALOGUE-ONLY this act (the design spec puts his battle in
@ the KANTO Crew Gauntlet), and this post is the reason the reveal is not a
@ character who appears once and evaporates. Two states on the flag the 5F scene
@ sets, so a player who somehow reads him first is never told the twist twice.
GoldenrodCity_EventScript_Bobby::
	lock
	faceplayer
	goto_if_unset FLAG_TRINITY_J_BOBBY_REVEALED, GoldenrodCity_EventScript_BobbyUnrevealed
	msgbox GoldenrodCity_Text_Bobby, MSGBOX_DEFAULT
	release
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE. This object is visible iff ARC >= 7,
@ and the only writer of ARC 7 is the 5F scene, whose last acts are setting
@ FLAG_TRINITY_J_BOBBY_REVEALED and then the arc -- so the flag is always set
@ before this object can spawn. Written as real dialogue anyway, because a
@ flavour NPC must never dead-end.
GoldenrodCity_EventScript_BobbyUnrevealed::
	msgbox GoldenrodCity_Text_BobbyUnrevealed, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_EventScript_StationSign::
	msgbox GoldenrodCity_Text_StationSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_RadioTowerSign::
	msgbox GoldenrodCity_Text_RadioTowerSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_GoldenrodDeptStoreSign::
	msgbox GoldenrodCity_Text_GoldenrodDeptStoreSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_GoldenrodGymSign::
	msgbox GoldenrodCity_Text_GoldenrodGymSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_Sign::
	msgbox GoldenrodCity_Text_Sign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_BikeShopSign::
	msgbox GoldenrodCity_Text_BikeShopSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_GameCornerSign::
	msgbox GoldenrodCity_Text_GameCornerSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_NameRaterSign::
	msgbox GoldenrodCity_Text_NameRaterSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_UndergroundSignNorth::
	msgbox GoldenrodCity_Text_UndergroundSignNorth, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_UndergroundSignSouth::
	msgbox GoldenrodCity_Text_UndergroundSignSouth, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_FlowerShopSign::
	msgbox GoldenrodCity_Text_FlowerShopSign, MSGBOX_SIGN
	end

@ ============================================================================
@ Text -- adapts pokecrystal GoldenrodCity.asm's civilian lines.
@ ============================================================================
GoldenrodCity_Text_PokefanM:
	.string "They built the new RADIO TOWER\n"
	.string "to replace the old, creaky one.\p"
	.string "Whole city runs on it now.\n"
	.string "Shows, weather, the LUCKY\l"
	.string "CHANNEL draw -- all of it out\l"
	.string "of that one building.\p"
	.string "Bit of a lot to hang on one\n"
	.string "building, if you ask me.$"

GoldenrodCity_Text_Youngster1:
	.string "I know there's a new BIKE SHOP,\n"
	.string "but I can't find it anywhere.\p"
	.string "It's a big city! Everything is\n"
	.string "behind something else!$"

@ GSC GoldenrodCityCooltrainerF1Text.
GoldenrodCity_Text_CooltrainerF1:
	.string "Is that man in black dressed up\n"
	.string "like a TEAM ROCKET member?\p"
	.string "How silly! They've been gone\n"
	.string "for years.\p"
	.string "…He's been looking at the RADIO\n"
	.string "TOWER for about an hour, mind.$"

@ GSC GoldenrodCityCooltrainerF1Text_ClearedRadioTower. Past tense, and no
@ pointing: there is nobody on that pavement any more.
GoldenrodCity_Text_CooltrainerF1ScoutGone:
	.string "There was a man in black who\n"
	.string "used to stand out here, dressed\l"
	.string "up like a TEAM ROCKET member.\p"
	.string "I laughed about it.\p"
	.string "Was he really one of them? I\n"
	.string "can't believe it.\p"
	.string "He hasn't been back.$"

GoldenrodCity_Text_CooltrainerF2:
	.string "The RADIO TOWER in GOLDENROD\n"
	.string "CITY is a landmark.\p"
	.string "They're running a promotional\n"
	.string "campaign right now.\p"
	.string "They'll modify your POKéNAV so\n"
	.string "it can also serve as a radio.$"

GoldenrodCity_Text_CooltrainerF2GotCard:
	.string "The RADIO TOWER is running a\n"
	.string "campaign -- they'll fit your\l"
	.string "POKéNAV to pick up the radio--\p"
	.string "Oh. Yours already does.\p"
	.string "Who did that for you? A\n"
	.string "PROFESSOR? In NEW BARK?\p"
	.string "Honestly. We advertise for\n"
	.string "weeks and he just does it.$"

GoldenrodCity_Text_Youngster2:
	.string "E-he-he-he…\p"
	.string "I got in trouble for playing in\n"
	.string "the basement of the DEPT.STORE.\p"
	.string "There's a door down there that\n"
	.string "goes somewhere. A man shouted\l"
	.string "at me about it.$"

GoldenrodCity_Text_Lass:
	.string "The man at that house rates\n"
	.string "your POKéMON names.\p"
	.string "He can even rename your\n"
	.string "POKéMON.\p"
	.string "Not the traded ones, though.\n"
	.string "He's very firm about that.$"

GoldenrodCity_Text_Gramps:
	.string "Whew! This is one big town.\n"
	.string "I don't know where anything is.\p"
	.string "There's a whole second town\n"
	.string "under this one, they tell me.\p"
	.string "I'm not going down there.$"

@ GSC GoldenrodCityRocketScoutText1. He is casing the tower. S8 collects.
GoldenrodCity_Text_RocketScout:
	.string "So this is the RADIO TOWER…\p"
	.string "…What? No, I don't need\n"
	.string "anything. I'm looking at a\l"
	.string "building. People look at\l"
	.string "buildings.\p"
	.string "Move along.$"

GoldenrodCity_Text_StationSign:
	.string "GOLDENROD CITY\nSTATION$"

GoldenrodCity_Text_RadioTowerSign:
	.string "GOLDENROD CITY\nRADIO TOWER$"

GoldenrodCity_Text_GoldenrodDeptStoreSign:
	.string "Full Selection of\nPOKéMON Goods!\pGOLDENROD CITY\nDEPT.STORE$"

GoldenrodCity_Text_GoldenrodGymSign:
	.string "GOLDENROD CITY\nPOKéMON GYM\lLEADER: WHITNEY\pThe Incredibly\nPretty Girl!$"

GoldenrodCity_Text_Sign:
	.string "GOLDENROD CITY\pThe Festive City\nof Opulent Charm$"

GoldenrodCity_Text_BikeShopSign:
	.string "The World is a\nCycle Path!\lBIKE SHOP$"

GoldenrodCity_Text_GameCornerSign:
	.string "Your Playground!\pGOLDENROD CITY\nGAME CORNER$"

GoldenrodCity_Text_NameRaterSign:
	.string "NAME RATER\pGet Your POKéMON\nNicknames Rated$"

GoldenrodCity_Text_UndergroundSignNorth:
	.string "UNDERGROUND\nENTRANCE$"

GoldenrodCity_Text_UndergroundSignSouth:
	.string "UNDERGROUND\nENTRANCE$"

GoldenrodCity_Text_FlowerShopSign:
	.string "Blooming Beautiful\nFLOWER SHOP$"

@ ============================================================================
@ Trinity M4b S8 -- occupation text. GSC's lines, kept short and unpleasant.
@ ============================================================================
GoldenrodCity_Text_Rocket1:
	.string "Stay out of the way.\p"
	.string "The street's ours this morning.$"

GoldenrodCity_Text_Rocket2:
	.string "The TOWER? Company business.\p"
	.string "Take one more step toward that\n"
	.string "door and it'll be my business.$"

GoldenrodCity_Text_Rocket3:
	.string "POKéMON are tools. Tools make\n"
	.string "money. That's the whole of it.\p"
	.string "Anyone who tells you different\n"
	.string "is selling something.$"

GoldenrodCity_Text_Rocket4:
	.string "Three years we waited.\p"
	.string "Three years of odd jobs and\n"
	.string "keeping our heads down.\p"
	.string "Tonight it goes out on the air.$"

GoldenrodCity_Text_Rocket5:
	.string "Hey. Champion.\p"
	.string "HOENN was a long swim from\n"
	.string "here. Go home.$"

GoldenrodCity_Text_Bobby:
	.string "BOBBY: Funny how it works.\p"
	.string "Six of us kept turning up on\n"
	.string "your road since HOENN, and you\l"
	.string "never once asked why.\p"
	.string "I'm not sorry. You were the\n"
	.string "fastest way to him, {PLAYER}, and\l"
	.string "you didn't need handling.\p"
	.string "He's gone east. INDIGO first,\n"
	.string "then home -- and home for that\l"
	.string "man is VIRIDIAN.\p"
	.string "Go and finish the badges. I'll\n"
	.string "be somewhere behind you.$"

GoldenrodCity_Text_BobbyUnrevealed:
	.string "BOBBY: Long way from HOENN,\n"
	.string "isn't it.\p"
	.string "Don't mind me. I'm just\n"
	.string "watching the door.$"
