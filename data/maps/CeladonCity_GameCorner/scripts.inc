@ ============================================================================
@ Trinity M5b S6 -- THE POSTER SWITCH (D1-D3), pokefirered's own
@ RocketHideout entrance mechanism, adapted to this tree's metatile ids.
@ D1: the (15,2) stair warp to RocketHideout_B1F already exists in map.json
@ (T10 shipped it open) -- the poster gate is the STORY seal this slice adds,
@ not a new warp. D2: ON_LOAD is the single authoring site for the sealed
@ state (setmetatile only, no DrawWholeMapView -- InitMap draws fresh on
@ every load). D3: the poster's own opening script repeats the same
@ setmetatiles AND calls DrawWholeMapView (the mid-scene redraw D2 alone
@ cannot provide). D4: FLAG_TRINITY_K_HIDEOUT_OPENED is the door's only
@ state. Metatile ids resolved from pokefirered's own
@ include/constants/metatile_labels.h raw values, which transfer 1:1 into
@ this tree's own BuildingKanto/GameCornerKanto combo (repartition_tileset.py
@ preserves absolute metatile ids exactly within a combo -- see
@ 06-celadon-chapter.md section 2.1): Floor_ShadeFull=658,
@ Floor_StairsTop=669, PurpleWall_Floor=719, PurpleWall_StairsTop=678,
@ PurpleWall_stairsBottom=679, StairsBottom=671, StairsTop=670.
@ ============================================================================
CeladonCity_GameCorner_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CeladonCity_GameCorner_OnLoad
	.byte 0

CeladonCity_GameCorner_OnLoad::
	call_if_unset FLAG_TRINITY_K_HIDEOUT_OPENED, CeladonCity_GameCorner_EventScript_SealHideoutStairs
	end

CeladonCity_GameCorner_EventScript_SealHideoutStairs::
	setmetatile 15, 2, 658, 0
	setmetatile 16, 2, 658, 0
	setmetatile 17, 2, 658, 0
	setmetatile 16, 3, 719, 1
	setmetatile 17, 3, 719, 1
	return

@ FIX ROUND (review C2, CRITICAL): the poster carried zero arc reads --
@ clearing Celadon at arc==1 (before ViridianCity's Blue grudge battle, the
@ ONE writer of VAR_TRINITY_KANTO_ARC value 2) could open the hideout and
@ reach the evidence room, setting arc straight to 3 and PERMANENTLY hiding
@ Blue (ViridianCity_OnTransition: visible iff ARC < 2). Fixed: the poster
@ refuses below arc 2, the refusal text saying so in-world (the switch means
@ nothing until Blue's own intel names the Game Corner, S5's own scene).
@ This is the SOLE entrance to RocketHideout_B1F-B4F (verified: every other
@ warp into those maps originates FROM inside the raid itself -- B2F's own
@ two up-warps and both RocketHideout_Elevator exits all require having
@ already entered via this door) -- so the raid cast's own visibility
@ predicate (ON_TRANSITION, visible iff arc < 3) needs no change: arc is
@ provably >= 2 on every load of every raid map once this gate is live.
CeladonCity_GameCorner_EventScript_Poster::
	lockall
	goto_if_lt VAR_TRINITY_KANTO_ARC, 2, CeladonCity_GameCorner_EventScript_PosterTooEarly
	msgbox CeladonCity_GameCorner_Text_Poster, MSGBOX_DEFAULT
	call_if_unset FLAG_TRINITY_K_HIDEOUT_OPENED, CeladonCity_GameCorner_EventScript_OpenHideoutStairs
	releaseall
	end

CeladonCity_GameCorner_EventScript_PosterTooEarly::
	msgbox CeladonCity_GameCorner_Text_PosterTooEarly, MSGBOX_DEFAULT
	releaseall
	end

CeladonCity_GameCorner_EventScript_OpenHideoutStairs::
	playse SE_UNLOCK
	setmetatile 15, 2, 669, 0
	setmetatile 16, 2, 670, 1
	setmetatile 17, 2, 671, 1
	setmetatile 16, 3, 678, 1
	setmetatile 17, 3, 679, 1
	special DrawWholeMapView
	setflag FLAG_TRINITY_K_HIDEOUT_OPENED
	return

CeladonCity_GameCorner_EventScript_InfoClerk::
	msgbox CeladonCity_GameCorner_Text_InfoClerk, MSGBOX_NPC
	end

CeladonCity_GameCorner_EventScript_CoinsClerk::
	msgbox CeladonCity_GameCorner_Text_CoinsClerk, MSGBOX_NPC
	end

CeladonCity_GameCorner_EventScript_BaldingMan::
	msgbox CeladonCity_GameCorner_Text_BaldingMan, MSGBOX_NPC
	end

CeladonCity_GameCorner_EventScript_Woman1::
	msgbox CeladonCity_GameCorner_Text_Woman1, MSGBOX_NPC
	end

CeladonCity_GameCorner_EventScript_Fisher::
	msgbox CeladonCity_GameCorner_Text_Fisher, MSGBOX_NPC
	end

CeladonCity_GameCorner_EventScript_GymGuy::
	msgbox CeladonCity_GameCorner_Text_GymGuy, MSGBOX_NPC
	end

CeladonCity_GameCorner_EventScript_Woman2::
	msgbox CeladonCity_GameCorner_Text_Woman2, MSGBOX_NPC
	end

CeladonCity_GameCorner_EventScript_OldMan::
	msgbox CeladonCity_GameCorner_Text_OldMan, MSGBOX_NPC
	end

CeladonCity_GameCorner_EventScript_Scientist::
	msgbox CeladonCity_GameCorner_Text_Scientist, MSGBOX_NPC
	end

CeladonCity_GameCorner_EventScript_Gentleman::
	msgbox CeladonCity_GameCorner_Text_Gentleman, MSGBOX_NPC
	end

CeladonCity_GameCorner_EventScript_SlotMachine0::
	msgbox CeladonCity_GameCorner_Text_SlotMachine0, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_SlotMachine1::
	msgbox CeladonCity_GameCorner_Text_SlotMachine1, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_SlotMachine2::
	msgbox CeladonCity_GameCorner_Text_SlotMachine2, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_SlotMachine3::
	msgbox CeladonCity_GameCorner_Text_SlotMachine3, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_UnusableSlotMachine1::
	msgbox CeladonCity_GameCorner_Text_UnusableSlotMachine1, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_SlotMachine5::
	msgbox CeladonCity_GameCorner_Text_SlotMachine5, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_SlotMachine6::
	msgbox CeladonCity_GameCorner_Text_SlotMachine6, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_SlotMachine7::
	msgbox CeladonCity_GameCorner_Text_SlotMachine7, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_SlotMachine8::
	msgbox CeladonCity_GameCorner_Text_SlotMachine8, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_SlotMachine9::
	msgbox CeladonCity_GameCorner_Text_SlotMachine9, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_SlotMachine10::
	msgbox CeladonCity_GameCorner_Text_SlotMachine10, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_SlotMachine11::
	msgbox CeladonCity_GameCorner_Text_SlotMachine11, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_SlotMachine12::
	msgbox CeladonCity_GameCorner_Text_SlotMachine12, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_SlotMachine13::
	msgbox CeladonCity_GameCorner_Text_SlotMachine13, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_SlotMachine14::
	msgbox CeladonCity_GameCorner_Text_SlotMachine14, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_UnusableSlotMachine2::
	msgbox CeladonCity_GameCorner_Text_UnusableSlotMachine2, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_SlotMachine16::
	msgbox CeladonCity_GameCorner_Text_SlotMachine16, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_SlotMachine17::
	msgbox CeladonCity_GameCorner_Text_SlotMachine17, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_UnusableSlotMachine3::
	msgbox CeladonCity_GameCorner_Text_UnusableSlotMachine3, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_SlotMachine19::
	msgbox CeladonCity_GameCorner_Text_SlotMachine19, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_SlotMachine20::
	msgbox CeladonCity_GameCorner_Text_SlotMachine20, MSGBOX_SIGN
	end

CeladonCity_GameCorner_EventScript_SlotMachine21::
	msgbox CeladonCity_GameCorner_Text_SlotMachine21, MSGBOX_SIGN
	end

CeladonCity_GameCorner_Text_InfoClerk:
	.string "Welcome!\pYou can exchange your COINS for\nfabulous prizes next door.$"

CeladonCity_GameCorner_Text_CoinsClerk:
	.string "KANTO's a long way from HOENN,\nbut word of that champion still\lmade it all the way here.$"

CeladonCity_GameCorner_Text_BaldingMan:
	.string "KANTO's peaceful most days, but\neven here we've heard the stories\labout that HOENN trainer.$"

CeladonCity_GameCorner_Text_Woman1:
	.string "Folks in KANTO don't get many\nvisitors from HOENN. Word is one\lof them cleaned up in JOHTO too.$"

CeladonCity_GameCorner_Text_Fisher:
	.string "Folks in KANTO don't get many\nvisitors from HOENN. Word is one\lof them cleaned up in JOHTO too.$"

CeladonCity_GameCorner_Text_GymGuy:
	.string "My grandkids keep going on about\nsome trainer from HOENN. Sounds\llike quite the journey so far.$"

CeladonCity_GameCorner_Text_Woman2:
	.string "KANTO's got its own trainers worth\nwatching, but even we're curious\labout this HOENN-JOHTO champion.$"

CeladonCity_GameCorner_Text_OldMan:
	.string "KANTO's got its own trainers worth\nwatching, but even we're curious\labout this HOENN-JOHTO champion.$"

CeladonCity_GameCorner_Text_Scientist:
	.string "KANTO's got its own trainers worth\nwatching, but even we're curious\labout this HOENN-JOHTO champion.$"

CeladonCity_GameCorner_Text_Gentleman:
	.string "Never met the champion myself.\nHeard they came up through HOENN\land JOHTO before setting foot here.$"

CeladonCity_GameCorner_Text_SlotMachine0:
	.string "Never met the champion myself.\nHeard they came up through HOENN\land JOHTO before setting foot here.$"

CeladonCity_GameCorner_Text_SlotMachine1:
	.string "KANTO's a long way from HOENN,\nbut word of that champion still\lmade it all the way here.$"

CeladonCity_GameCorner_Text_SlotMachine2:
	.string "My grandkids keep going on about\nsome trainer from HOENN. Sounds\llike quite the journey so far.$"

CeladonCity_GameCorner_Text_SlotMachine3:
	.string "Never met the champion myself.\nHeard they came up through HOENN\land JOHTO before setting foot here.$"

CeladonCity_GameCorner_Text_UnusableSlotMachine1:
	.string "OUT OF ORDER\nThis is broken.$"

CeladonCity_GameCorner_Text_SlotMachine5:
	.string "I never put much stock in rumors,\nbut two Leagues cleared is two\lLeagues cleared. Impressive.$"

CeladonCity_GameCorner_Text_SlotMachine6:
	.string "Folks in KANTO don't get many\nvisitors from HOENN. Word is one\lof them cleaned up in JOHTO too.$"

CeladonCity_GameCorner_Text_SlotMachine7:
	.string "They say a trainer beat both the\nHOENN and JOHTO Leagues. Wonder\lif they'll try KANTO next.$"

CeladonCity_GameCorner_Text_SlotMachine8:
	.string "My grandkids keep going on about\nsome trainer from HOENN. Sounds\llike quite the journey so far.$"

CeladonCity_GameCorner_Text_SlotMachine9:
	.string "My grandkids keep going on about\nsome trainer from HOENN. Sounds\llike quite the journey so far.$"

CeladonCity_GameCorner_Text_SlotMachine10:
	.string "My grandkids keep going on about\nsome trainer from HOENN. Sounds\llike quite the journey so far.$"

CeladonCity_GameCorner_Text_SlotMachine11:
	.string "My grandkids keep going on about\nsome trainer from HOENN. Sounds\llike quite the journey so far.$"

CeladonCity_GameCorner_Text_SlotMachine12:
	.string "I've fished this stretch of KANTO\nfor years. Lately it's all anyone\ltalks about -- some far-off champion.$"

CeladonCity_GameCorner_Text_SlotMachine13:
	.string "KANTO's a long way from HOENN,\nbut word of that champion still\lmade it all the way here.$"

CeladonCity_GameCorner_Text_SlotMachine14:
	.string "I never put much stock in rumors,\nbut two Leagues cleared is two\lLeagues cleared. Impressive.$"

CeladonCity_GameCorner_Text_UnusableSlotMachine2:
	.string "OUT TO LUNCH\nThis is reserved.$"

CeladonCity_GameCorner_Text_SlotMachine16:
	.string "This route's seen more foot traffic\nlately. Something about a champion\lpassing through from JOHTO.$"

CeladonCity_GameCorner_Text_SlotMachine17:
	.string "I never put much stock in rumors,\nbut two Leagues cleared is two\lLeagues cleared. Impressive.$"

CeladonCity_GameCorner_Text_UnusableSlotMachine3:
	.string "Someone's keys!\nThey'll be back.$"

CeladonCity_GameCorner_Text_SlotMachine19:
	.string "Never met the champion myself.\nHeard they came up through HOENN\land JOHTO before setting foot here.$"

CeladonCity_GameCorner_Text_SlotMachine20:
	.string "Folks in KANTO don't get many\nvisitors from HOENN. Word is one\lof them cleaned up in JOHTO too.$"

CeladonCity_GameCorner_Text_SlotMachine21:
	.string "I never put much stock in rumors,\nbut two Leagues cleared is two\lLeagues cleared. Impressive.$"

CeladonCity_GameCorner_Text_Poster:
	.string "There's a switch hidden behind\nthis poster.\pYou push it.$"

CeladonCity_GameCorner_Text_PosterTooEarly:
	.string "Just an old poster.\pWhatever's behind it, you have no\nreason yet to go looking.$"
