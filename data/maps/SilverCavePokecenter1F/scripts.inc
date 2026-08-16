@ M4b S11B: Johto Centers functional (heal + respawn). Vanilla nurse shape,
@ copied verbatim from OldaleTown_PokemonCenter_1F/scripts.inc. The old GSC
@ champion-gossip flavour line (retired here, see S11B report) is dropped --
@ the nurse's own object is now interaction-critical and out of scope for
@ narrative flavour per S11B's mandate.
SilverCavePokecenter1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SilverCavePokecenter1F_OnTransition
	.byte 0

SilverCavePokecenter1F_OnTransition:
	setrespawn HEAL_LOCATION_SILVER_CAVE
	end

SilverCavePokecenter1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_JOHTO_SILVERCAVE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SilverCavePokecenter1F_EventScript_Granny::
	msgbox SilverCavePokecenter1F_Text_Granny, MSGBOX_NPC
	end

SilverCavePokecenter1F_Text_Granny:
	.string "Trainers who seek\npower climb MT.\pSILVER despite its\nmany dangers…\pWith their trusted\nPOKéMON, they must\pfeel they can go\nanywhere…$"
