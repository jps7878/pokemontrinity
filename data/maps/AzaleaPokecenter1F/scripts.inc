@ M4b S11B: Johto Centers functional (heal + respawn). Vanilla nurse shape,
@ copied verbatim from OldaleTown_PokemonCenter_1F/scripts.inc. The old GSC
@ champion-gossip flavour line (retired here, see S11B report) is dropped --
@ the nurse's own object is now interaction-critical and out of scope for
@ narrative flavour per S11B's mandate.
AzaleaPokecenter1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaPokecenter1F_OnTransition
	.byte 0

AzaleaPokecenter1F_OnTransition:
	setrespawn HEAL_LOCATION_AZALEA_TOWN
	end

AzaleaPokecenter1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_JOHTO_AZALEA_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

@ M7b Task 14 (finding #9): this Center's standing guide. The shipped GSC
@ flavour line is unchanged; the arc-keyed next objective follows it.
@ MSGBOX_NPC becomes explicit lock/faceplayer + MSGBOX_DEFAULT because
@ MSGBOX_NPC releases (Std_MsgboxNPC, data/scripts/std_msgbox.inc) and so
@ cannot be chained. The ladder is data/scripts/trinity_johto.inc.
AzaleaPokecenter1F_EventScript_Gentleman::
	lock
	faceplayer
	msgbox AzaleaPokecenter1F_Text_Gentleman, MSGBOX_DEFAULT
	goto Trinity_EventScript_JohtoGuide
	end

AzaleaPokecenter1F_EventScript_FishingGuru::
	msgbox AzaleaPokecenter1F_Text_FishingGuru, MSGBOX_NPC
	end

AzaleaPokecenter1F_EventScript_PokefanF::
	msgbox AzaleaPokecenter1F_Text_PokefanF, MSGBOX_NPC
	end

AzaleaPokecenter1F_Text_Gentleman:
	.string "Do your POKéMON\nknow HM moves?\pThose moves can\nbe used even if\pyour POKéMON has\nfainted.$"

AzaleaPokecenter1F_Text_FishingGuru:
	.string "BILL's PC can\nstore up to 20\lPOKéMON per BOX.$"

AzaleaPokecenter1F_Text_PokefanF:
	.string "Do you know about\nAPRICORNS?\pCrack one open,\nhollow it out and\pfit it with a\nspecial device.\pThen you can catch\nPOKéMON with it.\pBefore POKé BALLS\nwere invented,\peveryone used\nAPRICORNS.$"
