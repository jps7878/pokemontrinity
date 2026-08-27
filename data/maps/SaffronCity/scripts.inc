SaffronCity_MapScripts::
	.byte 0

SaffronCity_EventScript_Youngster::
	msgbox SaffronCity_Text_Youngster, MSGBOX_NPC
	end

SaffronCity_EventScript_WorkerM::
	msgbox SaffronCity_Text_WorkerM, MSGBOX_NPC
	end

SaffronCity_EventScript_Man::
	msgbox SaffronCity_Text_Man, MSGBOX_NPC
	end

SaffronCity_EventScript_Boy::
	msgbox SaffronCity_Text_Boy, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass::
	msgbox SaffronCity_Text_Lass, MSGBOX_NPC
	end

SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_CitySign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_DojoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphProductSign::
	msgbox SaffronCity_Text_SilphProductSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerTips2::
	msgbox SaffronCity_Text_TrainerTips2, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerTips1::
	msgbox SaffronCity_Text_TrainerTips1, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	msgbox SaffronCity_Text_GymSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicsHouseSign::
	msgbox SaffronCity_Text_MrPsychicsHouseSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerFanClubSign::
	msgbox SaffronCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

@ Trinity M5b S2: the FRLG-ported lines here presupposed the SILPH CO. Rocket
@ takeover had already been cleared -- true in FRLG canon (beating Silph Co.
@ is a hard prerequisite to reaching Saffron there), false in Trinity's own
@ arc, where "Act III's raid is Celadon S6/Viridian S10" (no Saffron/Silph
@ raid exists yet at this point in the story). Rewritten to plain pre-raid
@ city-life flavor; see docs/superpowers/plans/m5b/02-saffron-chapter.md
@ section 5.4.
SaffronCity_Text_Youngster:
	.string "SAFFRON's the biggest city in\nKANTO. Get lost here once, you'll\lnever admit it.$"

SaffronCity_Text_WorkerM:
	.string "SILPH CO. keeps this whole city\nrunning. Half of KANTO's business\lgoes through their front door.$"

SaffronCity_Text_Man:
	.string "Word is a CHAMPION cleared JOHTO's\nLEAGUE. Now they're working their\lway through us too.$"

SaffronCity_Text_Boy:
	.string "I flew here on my PIDGEOT just to\nsee SAFFRON. It's noisier than I\lpictured.$"

SaffronCity_Text_Lass:
	.string "Everyone in SAFFRON's always in\na hurry. I like it that way.$"

SaffronCity_Text_CitySign:
	.string "SAFFRON CITY\nShining, Golden Land of Commerce$"

SaffronCity_Text_DojoSign:
	.string "FIGHTING DOJO$"

SaffronCity_Text_SilphProductSign:
	.string "SILPH's latest product!\nRelease to be determined…$"

SaffronCity_Text_TrainerTips2:
	.string "TRAINER TIPS\pThe new GREAT BALL offers improved\ncatching rates.\pTry it on those hard-to-catch\nPOKéMON.$"

SaffronCity_Text_SilphCoSign:
	.string "SILPH CO. OFFICE BUILDING$"

SaffronCity_Text_TrainerTips1:
	.string "TRAINER TIPS\pFULL HEAL cures all ailments like\nburns, paralysis, poisoning,\lfreezing, and sleep.\pIt costs a bit more, but it's more\nconvenient than buying other items.$"

SaffronCity_Text_GymSign:
	.string "Folks in KANTO don't get many\nvisitors from HOENN. Word is one\lof them cleaned up in JOHTO too.$"

SaffronCity_Text_MrPsychicsHouseSign:
	.string "MR. PSYCHIC'S HOUSE$"

SaffronCity_Text_TrainerFanClubSign:
	.string "POKéMON TRAINER FAN CLUB\pMany TRAINERS have scribbled their\nnames on this sign.$"
