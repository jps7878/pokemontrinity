@ M4b S11B: Johto Centers functional (heal + respawn). Vanilla nurse shape,
@ copied verbatim from OldaleTown_PokemonCenter_1F/scripts.inc. The old GSC
@ champion-gossip flavour line (retired here, see S11B report) is dropped --
@ the nurse's own object is now interaction-critical and out of scope for
@ narrative flavour per S11B's mandate.
GoldenrodPokecenter1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodPokecenter1F_OnTransition
	.byte 0

GoldenrodPokecenter1F_OnTransition:
	setrespawn HEAL_LOCATION_GOLDENROD_CITY
	end

GoldenrodPokecenter1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_JOHTO_GOLDENROD_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

GoldenrodPokecenter1F_EventScript_ObjectEvent::
	msgbox GoldenrodPokecenter1F_Text_ObjectEvent, MSGBOX_NPC
	end

GoldenrodPokecenter1F_EventScript_Lass::
	msgbox GoldenrodPokecenter1F_Text_Lass, MSGBOX_NPC
	end

@ M7b Task 14 (finding #9): this Center's standing guide. The shipped GSC
@ flavour line is unchanged; the arc-keyed next objective follows it.
@ MSGBOX_NPC becomes explicit lock/faceplayer + MSGBOX_DEFAULT because
@ MSGBOX_NPC releases (Std_MsgboxNPC, data/scripts/std_msgbox.inc) and so
@ cannot be chained. The ladder is data/scripts/trinity_johto.inc.
GoldenrodPokecenter1F_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodPokecenter1F_Text_PokefanF, MSGBOX_DEFAULT
	goto Trinity_EventScript_JohtoGuide
	end

GoldenrodPokecenter1F_Text_ObjectEvent:
	.string "This route sure gets more foot\ntraffic now that HOENN trainers\lkeep showing up.$"

GoldenrodPokecenter1F_Text_Lass:
	.string "A higher level\nPOKéMON doesn't\lalways win.\pAfter all, it may\nhave a type dis-\ladvantage.\pI don't think\nthere is a single\pPOKéMON that is\nthe toughest.$"

GoldenrodPokecenter1F_Text_PokefanF:
	.string "I've been wandering these routes\nfor years. Lately there's talk of\lnothing but the HOENN champion.$"
