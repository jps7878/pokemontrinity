@ M4b S11B: Johto Centers functional (heal + respawn). Vanilla nurse shape,
@ copied verbatim from OldaleTown_PokemonCenter_1F/scripts.inc. The old GSC
@ champion-gossip flavour line (retired here, see S11B report) is dropped --
@ the nurse's own object is now interaction-critical and out of scope for
@ narrative flavour per S11B's mandate.
VioletPokecenter1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletPokecenter1F_OnTransition
	.byte 0

VioletPokecenter1F_OnTransition:
	setrespawn HEAL_LOCATION_VIOLET_CITY
	end

VioletPokecenter1F_EventScript_VioletPokecenterNurse::
	setvar VAR_0x800B, LOCALID_JOHTO_VIOLET_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VioletPokecenter1F_EventScript_Gentleman::
	msgbox VioletPokecenter1F_Text_Gentleman, MSGBOX_NPC
	end

VioletPokecenter1F_EventScript_Youngster::
	msgbox VioletPokecenter1F_Text_Youngster, MSGBOX_NPC
	end

VioletPokecenter1F_Text_Gentleman:
	.string "It was around\nthree years ago.\pTEAM ROCKET was up\nto no good with\lPOKéMON.\pBut justice pre-\nvailed--a young\lkid broke 'em up.$"

VioletPokecenter1F_Text_Youngster:
	.string "POKéMON are smart.\nThey won't obey a\ptrainer they don't\nrespect.\pWithout the right\nGYM BADGES, they\pwill just do as\nthey please.$"
