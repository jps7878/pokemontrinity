@ M4b S11B: Johto Centers functional (heal + respawn). Vanilla nurse shape,
@ copied verbatim from OldaleTown_PokemonCenter_1F/scripts.inc. The old GSC
@ champion-gossip flavour line (retired here, see S11B report) is dropped --
@ the nurse's own object is now interaction-critical and out of scope for
@ narrative flavour per S11B's mandate.
BlackthornPokecenter1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornPokecenter1F_OnTransition
	.byte 0

BlackthornPokecenter1F_OnTransition:
	setrespawn HEAL_LOCATION_BLACKTHORN_CITY
	end

BlackthornPokecenter1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_JOHTO_BLACKTHORN_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BlackthornPokecenter1F_EventScript_Gentleman::
	msgbox BlackthornPokecenter1F_Text_Gentleman, MSGBOX_NPC
	end

BlackthornPokecenter1F_EventScript_Twin::
	msgbox BlackthornPokecenter1F_Text_Twin, MSGBOX_NPC
	end

BlackthornPokecenter1F_EventScript_CooltrainerM::
	msgbox BlackthornPokecenter1F_Text_CooltrainerM, MSGBOX_NPC
	end

BlackthornPokecenter1F_Text_Gentleman:
	.string "Deep inside far-\noff INDIGO PLATEAU\pis the POKéMON\nLEAGUE.\pI hear the best\ntrainers gather\pthere from around\nthe country.$"

BlackthornPokecenter1F_Text_Twin:
	.string "There was this\nmove I just had\pto teach my POKé-\nMON.\pSo I got the MOVE\nDELETER to make it\lforget an HM move.$"

BlackthornPokecenter1F_Text_CooltrainerM:
	.string "Did you hear? A HOENN trainer\nbecame Champion, and now folks\lhere want to challenge them.$"
