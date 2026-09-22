@ M4b S11B: Johto Centers functional (heal + respawn). Vanilla nurse shape,
@ copied verbatim from OldaleTown_PokemonCenter_1F/scripts.inc. The old GSC
@ champion-gossip flavour line (retired here, see S11B report) is dropped --
@ the nurse's own object is now interaction-critical and out of scope for
@ narrative flavour per S11B's mandate.
CianwoodPokecenter1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CianwoodPokecenter1F_OnTransition
	.byte 0

CianwoodPokecenter1F_OnTransition:
	setrespawn HEAL_LOCATION_CIANWOOD_CITY
	end

CianwoodPokecenter1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_JOHTO_CIANWOOD_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

CianwoodPokecenter1F_EventScript_Lass::
	msgbox CianwoodPokecenter1F_Text_Lass, MSGBOX_NPC
	end

@ CHUCK's gym guide, whom GSC stands in this Center rather than in CIANWOOD
@ GYM (that map.json casts four BLACK BELTs and CHUCK, no guide). M7b Task 14
@ leaves him ALONE on purpose: this Center's arc-keyed hub guide is the SUPER
@ NERD below at (8,6), across the room from his (5,3), who speaks the
@ objective in EVERY arc state -- so a badge-gated copy of it here would
@ print the same page twice in one room and would say strictly less than the
@ SUPER NERD is already saying unprompted.
CianwoodPokecenter1F_EventScript_CianwoodGymGuide::
	msgbox CianwoodPokecenter1F_Text_CianwoodGymGuide, MSGBOX_NPC
	end

@ M7b Task 14 (finding #9): this Center's standing guide. The shipped GSC
@ flavour line is unchanged; the arc-keyed next objective follows it.
@ MSGBOX_NPC becomes explicit lock/faceplayer + MSGBOX_DEFAULT because
@ MSGBOX_NPC releases (Std_MsgboxNPC, data/scripts/std_msgbox.inc) and so
@ cannot be chained. The ladder is data/scripts/trinity_johto.inc.
CianwoodPokecenter1F_EventScript_SuperNerd::
	lock
	faceplayer
	msgbox CianwoodPokecenter1F_Text_SuperNerd, MSGBOX_DEFAULT
	goto Trinity_EventScript_JohtoGuide
	end

CianwoodPokecenter1F_Text_Lass:
	.string "Did you meet the\nPOKéMANIAC?\pHe's always brag-\nging about his\lrare POKéMON.$"

CianwoodPokecenter1F_Text_CianwoodGymGuide:
	.string "My grandkids won't stop talking\nabout the new champion from over\lin HOENN. Kids these days!$"

CianwoodPokecenter1F_Text_SuperNerd:
	.string "I love showing off\nthe POKéMON that\pI've raised.\nDon't you?\pI'm going to get\ninto a bunch of\pbattles, and show\noff my POKéMON!$"
