CeruleanCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_OnTransition
	.byte 0

@ ============================================================================
@ Trinity M5b S3 -- CERULEAN CAVE MOUTH. Full decode:
@ docs/superpowers/plans/m5b/03-cerulean-power-plant.md section 3.
@
@ The cave door (warp_events[7], (1,12)->MAP_CERULEAN_CAVE_1F#0) has exactly
@ ONE walkable neighbour, (1,13) directly south (north/east/west all collision
@ 1) -- a true one-tile chokepoint. T10 placed the guard object RIGHT ON that
@ tile with flag "0" (always present, unconditional) -- the cave was
@ permanently sealed in the shipped tree, a T10 placeholder state, not a
@ finished gate.
@
@ THE CONTRACT'S COORDINATE RULE FORBIDS A RESTING NPC SEALING A CORRIDOR
@ (established twice already: AZALEA's two chokepoint guards were moved one
@ tile in M4b S4's fix round for exactly this; Route43Gate's own header states
@ it as a rule, "a gate NPC never blocks the gate"). So the guard moves
@ (1,13) -> (2,13) -- decoded col 0 elev 3 MB_NORMAL, adjacent, off the
@ chokepoint, same one-tile-relocation shape as the AZALEA fix. He becomes
@ pure flavour/warning; a coord_event at the now-empty (1,13) is the actual
@ gate, mirroring Route28_EventScript_KantoGateCheck (this hack's established
@ "story-gated one-way passage, no resting NPC" pattern) -- VAR_TEMP_1 == 0 is
@ the "always fires" idiom (cleared to 0 by ClearTempFieldEventData on every
@ map load, consumed synchronously in the same script run; trinity_kanto.inc's
@ own C-COUNT header cites the identical reasoning for its scratch var).
@
@ Visibility: single-writer discipline -- S3 reads VAR_TRINITY_KANTO_ARC,
@ writes nothing to it. Visible pre-arc6 (warning, backed up by the
@ coord_event regardless of whether the player detours around him);
@ hidden at arc>=6 ("he steps aside/vanishes").
@ ============================================================================
CeruleanCity_OnTransition::
	goto_if_ge VAR_TRINITY_KANTO_ARC, 6, CeruleanCity_EventScript_HideCaveGuard
	clearflag FLAG_TRINITY_K_CAVE_GUARD_HIDE
	end

CeruleanCity_EventScript_HideCaveGuard::
	setflag FLAG_TRINITY_K_CAVE_GUARD_HIDE
	end

CeruleanCity_EventScript_CaveMouthCheck::
	goto_if_ge VAR_TRINITY_KANTO_ARC, 6, CeruleanCity_EventScript_CaveMouthOpen
	lockall
	msgbox CeruleanCity_Text_CaveMouthNotYet, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_CaveMouthStepBack
	waitmovement 0
	releaseall
	end

CeruleanCity_EventScript_CaveMouthOpen::
	end

CeruleanCity_Movement_CaveMouthStepBack:
	walk_down
	step_end

CeruleanCity_Text_CaveMouthNotYet:
	.string "The air past here feels wrong\nfor you -- like the cave itself\lis waiting on somebody else\lfirst.$"

CeruleanCity_EventScript_Policeman::
	msgbox CeruleanCity_Text_Policeman, MSGBOX_NPC
	end

CeruleanCity_EventScript_LittleBoy::
	msgbox CeruleanCity_Text_LittleBoy, MSGBOX_NPC
	end

CeruleanCity_EventScript_BaldingMan::
	msgbox CeruleanCity_Text_BaldingMan, MSGBOX_NPC
	end

CeruleanCity_EventScript_Lass::
	msgbox CeruleanCity_Text_Lass, MSGBOX_NPC
	end

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_Youngster, MSGBOX_NPC
	end

CeruleanCity_EventScript_Woman::
	msgbox CeruleanCity_Text_Woman, MSGBOX_NPC
	end

CeruleanCity_EventScript_CeruleanCaveGuard::
	msgbox CeruleanCity_Text_CeruleanCaveGuard, MSGBOX_NPC
	end

CeruleanCity_EventScript_CitySign::
	msgbox CeruleanCity_Text_CitySign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign::
	msgbox CeruleanCity_Text_GymSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_TrainerTips::
	msgbox CeruleanCity_Text_TrainerTips, MSGBOX_SIGN
	end

CeruleanCity_Text_Policeman:
	.string "My grandkids keep going on about\nsome trainer from HOENN. Sounds\llike quite the journey so far.$"

CeruleanCity_Text_LittleBoy:
	.string "They say a trainer beat both the\nHOENN and JOHTO Leagues. Wonder\lif they'll try KANTO next.$"

CeruleanCity_Text_BaldingMan:
	.string "You're making an encyclopedia on\nPOKéMON? That sounds amusing.$"

CeruleanCity_Text_Lass:
	.string "Never met the champion myself.\nHeard they came up through HOENN\land JOHTO before setting foot here.$"

CeruleanCity_Text_Youngster:
	.string "You're a TRAINER, too?\pCollecting, battling…\nIt's a tough life, isn't it?$"

CeruleanCity_Text_Woman:
	.string "KANTO's peaceful most days, but\neven here we've heard the stories\labout that HOENN trainer.$"

CeruleanCity_Text_CeruleanCaveGuard:
	.string "This is CERULEAN CAVE.\pHorribly strong POKéMON live inside\nthere.\pIt takes a very special TRAINER to\nbe allowed inside there.\pYou'd have to be strong enough to\nbecome the POKéMON LEAGUE\lCHAMPION for starters.\pAnd, you would have to have\nmade a great achievement.$"

CeruleanCity_Text_CitySign:
	.string "CERULEAN CITY\nA Mysterious, Blue Aura Surrounds\lIt$"

CeruleanCity_Text_GymSign:
	.string "They say a trainer beat both the\nHOENN and JOHTO Leagues. Wonder\lif they'll try KANTO next.$"

CeruleanCity_Text_BikeShopSign:
	.string "Grass and caves handled easily!\nBIKE SHOP$"

CeruleanCity_Text_TrainerTips:
	.string "TRAINER TIPS\pA POKéMON can be made to hold\nan item.\pSome items can even be used by\nthe holding POKéMON in battle.$"
