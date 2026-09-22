@ M4b S11B: Johto Centers functional (heal + respawn). Vanilla nurse shape,
@ copied verbatim from OldaleTown_PokemonCenter_1F/scripts.inc. The old GSC
@ champion-gossip flavour line (retired here, see S11B report) is dropped --
@ the nurse's own object is now interaction-critical and out of scope for
@ narrative flavour per S11B's mandate.
CherrygrovePokecenter1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CherrygrovePokecenter1F_OnTransition
	.byte 0

CherrygrovePokecenter1F_OnTransition:
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY
	end

CherrygrovePokecenter1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_JOHTO_CHERRYGROVE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

CherrygrovePokecenter1F_EventScript_Fisher::
	msgbox CherrygrovePokecenter1F_Text_Fisher, MSGBOX_NPC
	end

@ M7b Task 14 (finding #9): this Center's standing guide. The shipped GSC
@ flavour line is unchanged; the arc-keyed next objective follows it.
@ MSGBOX_NPC becomes explicit lock/faceplayer + MSGBOX_DEFAULT because
@ MSGBOX_NPC releases (Std_MsgboxNPC, data/scripts/std_msgbox.inc) and so
@ cannot be chained. The ladder is data/scripts/trinity_johto.inc.
CherrygrovePokecenter1F_EventScript_Gentleman::
	lock
	faceplayer
	msgbox CherrygrovePokecenter1F_Text_Gentleman, MSGBOX_DEFAULT
	goto Trinity_EventScript_JohtoGuide
	end

CherrygrovePokecenter1F_EventScript_Teacher::
	msgbox CherrygrovePokecenter1F_Text_Teacher, MSGBOX_NPC
	end

CherrygrovePokecenter1F_Text_Fisher:
	.string "It's great. I can\nstore any number\pof POKéMON, and\nit's all free.$"

CherrygrovePokecenter1F_Text_Gentleman:
	.string "That PC is free\nfor any trainer\lto use.$"

CherrygrovePokecenter1F_Text_Teacher:
	.string "JOHTO's changed a lot since the\nHOENN champion opened the sea\lroutes here.$"
