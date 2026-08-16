@ M4b S11B: Johto Centers functional (heal + respawn). Vanilla nurse shape,
@ copied verbatim from OldaleTown_PokemonCenter_1F/scripts.inc. The old GSC
@ flavour line (retired here, see S11B report) is dropped -- the nurse's own
@ object is now interaction-critical and out of scope for narrative flavour
@ per S11B's mandate.
Route32Pokecenter1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32Pokecenter1F_OnTransition
	.byte 0

Route32Pokecenter1F_OnTransition:
	setrespawn HEAL_LOCATION_ROUTE32
	end

Route32Pokecenter1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_JOHTO_ROUTE32_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Route32Pokecenter1F_EventScript_FishingGuru::
	msgbox Route32Pokecenter1F_Text_FishingGuru, MSGBOX_NPC
	end

Route32Pokecenter1F_EventScript_CooltrainerF::
	msgbox Route32Pokecenter1F_Text_CooltrainerF, MSGBOX_NPC
	end

Route32Pokecenter1F_Text_FishingGuru:
	.string "Did you hear? A HOENN trainer\nbecame Champion, and now folks\lhere want to challenge them.$"

Route32Pokecenter1F_Text_CooltrainerF:
	.string "What should I make\nmy POKéMON hold?\pMaybe an item that\nincreases ATTACK\lpower…$"
