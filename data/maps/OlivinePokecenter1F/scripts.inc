@ M4b S11B: Johto Centers functional (heal + respawn). Vanilla nurse shape,
@ copied verbatim from OldaleTown_PokemonCenter_1F/scripts.inc. The old GSC
@ flavour line (retired here, see S11B report) is dropped -- the nurse's own
@ object is now interaction-critical and out of scope for narrative flavour
@ per S11B's mandate.
OlivinePokecenter1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivinePokecenter1F_OnTransition
	.byte 0

OlivinePokecenter1F_OnTransition:
	setrespawn HEAL_LOCATION_OLIVINE_CITY
	end

OlivinePokecenter1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_JOHTO_OLIVINE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OlivinePokecenter1F_EventScript_FishingGuru::
	msgbox OlivinePokecenter1F_Text_FishingGuru, MSGBOX_NPC
	end

OlivinePokecenter1F_EventScript_Fisher::
	msgbox OlivinePokecenter1F_Text_Fisher, MSGBOX_NPC
	end

@ M7b Task 14 (finding #9): this Center's standing guide. The shipped GSC
@ flavour line is unchanged; the arc-keyed next objective follows it.
@ MSGBOX_NPC becomes explicit lock/faceplayer + MSGBOX_DEFAULT because
@ MSGBOX_NPC releases (Std_MsgboxNPC, data/scripts/std_msgbox.inc) and so
@ cannot be chained. The ladder is data/scripts/trinity_johto.inc.
OlivinePokecenter1F_EventScript_Teacher::
	lock
	faceplayer
	msgbox OlivinePokecenter1F_Text_Teacher, MSGBOX_DEFAULT
	goto Trinity_EventScript_JohtoGuide
	end

OlivinePokecenter1F_Text_FishingGuru:
	.string "The old timers say JOHTO used to\nfeel far from everywhere. Not\lanymore, with HOENN so close now.$"

OlivinePokecenter1F_Text_Fisher:
	.string "The SAILOR in the\nOLIVINE CAFE next\pdoor is really\ngenerous.\pHe taught my\nPOKéMON STRENGTH.\pNow it can move\nbig boulders.$"

OlivinePokecenter1F_Text_Teacher:
	.string "There's a person\nin CIANWOOD CITY\lacross the sea.\pI heard him brag-\nging about his\lrare POKéMON.$"
