@ M4b S11B: Johto Centers functional (heal + respawn). Vanilla nurse shape,
@ copied verbatim from OldaleTown_PokemonCenter_1F/scripts.inc. The old GSC
@ champion-gossip flavour line (retired here, see S11B report) is dropped --
@ the nurse's own object is now interaction-critical and out of scope for
@ narrative flavour per S11B's mandate.
EcruteakPokecenter1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakPokecenter1F_OnTransition
	.byte 0

EcruteakPokecenter1F_OnTransition:
	setrespawn HEAL_LOCATION_ECRUTEAK_CITY
	end

EcruteakPokecenter1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_JOHTO_ECRUTEAK_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EcruteakPokecenter1F_EventScript_PokefanM::
	msgbox EcruteakPokecenter1F_Text_PokefanM, MSGBOX_NPC
	end

EcruteakPokecenter1F_EventScript_CooltrainerF::
	msgbox EcruteakPokecenter1F_Text_CooltrainerF, MSGBOX_NPC
	end

EcruteakPokecenter1F_EventScript_GymGuide::
	msgbox EcruteakPokecenter1F_Text_GymGuide, MSGBOX_NPC
	end

EcruteakPokecenter1F_Text_PokefanM:
	.string "This route sure gets more foot\ntraffic now that HOENN trainers\lkeep showing up.$"

EcruteakPokecenter1F_Text_CooltrainerF:
	.string "MORTY, the GYM\nLEADER, is soooo\lcool.\pHis POKéMON are\nreally tough too.$"

EcruteakPokecenter1F_Text_GymGuide:
	.string "LAKE OF RAGE…\pThe appearance of\na GYARADOS swarm…\pI smell a conspir-\nacy. I know it!$"
