@ M4b S11B: Johto Centers functional (heal + respawn). Vanilla nurse shape,
@ copied verbatim from OldaleTown_PokemonCenter_1F/scripts.inc. The old GSC
@ champion-gossip flavour line (retired here, see S11B report) is dropped --
@ the nurse's own object is now interaction-critical and out of scope for
@ narrative flavour per S11B's mandate.
MahoganyPokecenter1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MahoganyPokecenter1F_OnTransition
	.byte 0

MahoganyPokecenter1F_OnTransition:
	setrespawn HEAL_LOCATION_MAHOGANY_TOWN
	end

MahoganyPokecenter1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_JOHTO_MAHOGANY_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MahoganyPokecenter1F_EventScript_PokefanM::
	msgbox MahoganyPokecenter1F_Text_PokefanM, MSGBOX_NPC
	end

MahoganyPokecenter1F_EventScript_Youngster::
	msgbox MahoganyPokecenter1F_Text_Youngster, MSGBOX_NPC
	end

@ M7b Task 14 (finding #9): this Center's standing guide. The shipped GSC
@ flavour line is unchanged; the arc-keyed next objective follows it.
@ MSGBOX_NPC becomes explicit lock/faceplayer + MSGBOX_DEFAULT because
@ MSGBOX_NPC releases (Std_MsgboxNPC, data/scripts/std_msgbox.inc) and so
@ cannot be chained. The ladder is data/scripts/trinity_johto.inc.
MahoganyPokecenter1F_EventScript_CooltrainerF::
	lock
	faceplayer
	msgbox MahoganyPokecenter1F_Text_CooltrainerF, MSGBOX_DEFAULT
	goto Trinity_EventScript_JohtoGuide
	end

MahoganyPokecenter1F_Text_PokefanM:
	.string "What's this? TEAM\nROCKET has come\lback?\pI saw some men in\nblack at LAKE OF\lRAGE…$"

MahoganyPokecenter1F_Text_Youngster:
	.string "I stop my POKéMON\nfrom evolving too\learly.\pI make them learn\ncertain moves be-\lfore I let them\levolve.$"

MahoganyPokecenter1F_Text_CooltrainerF:
	.string "POKéMON do become\nstronger when they\pevolve, but they\nalso learn moves\lmore slowly.$"
