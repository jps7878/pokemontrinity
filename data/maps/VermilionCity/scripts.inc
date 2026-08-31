VermilionCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_OnFrame
	.byte 0

@ ============================================================================
@ Trinity M5b S1 -- the ONE arrival cutscene (spec decision 5): the first
@ S.S. AQUA crossing into KANTO. Two-step arm/fire idiom, copied from
@ OlivinePort_OnTransition/OnFrame (M4a's own S.S. TIDAL arrival template):
@ ON_TRANSITION runs before the frame loop starts, so the movement-heavy
@ scene itself waits for OnFrame.
@ ============================================================================
VermilionCity_OnTransition:
	@ BOBBY is addobject-only here (never a permanent occupant) -- unconditional
	@ setflag every load, exact precedent RadioTower5F_OnTransition's own
	@ treatment of its addobject-only GIOVANNI/BOBBY actors (setflag
	@ FLAG_TRINITY_J_TOWER_GIOVANNI_HIDE / _BOBBY_HIDE, unconditional).
	setflag FLAG_TRINITY_K_VERMILION_BOBBY_HIDE
	call_if_unset FLAG_TRINITY_K_ARRIVED, VermilionCity_EventScript_ArmArrival
	end

VermilionCity_EventScript_ArmArrival::
	setvar VAR_TEMP_1, 1
	return

VermilionCity_OnFrame:
	map_script_2 VAR_TEMP_1, 1, VermilionCity_EventScript_Arrival
	.2byte 0

@ Dock decode (task-5-report.md + this slice's own re-confirmation):
@ (22,33)/(23,33)/(24,33) col=0 elev=3 MB_NORMAL, a 3-tile-wide pier deck;
@ (22-24,34) is the S.S. ANNE dock's MB_SOUTH_ARROW_WARP trio one row south.
@ Player lands at (24,33) (M5a T5's shipped warp target, both the repeat-
@ crossing sailor branch and BOBBY's own Olivine departure script). The
@ permanent SAILOR stands at (23,33) facing down; BOBBY's session template
@ sits at (22,33), free, same row -- all three tiles read as one straight
@ line on the open deck, well inside the 15x10 camera window.
@ Fix round 1 (review Finding 1, CRITICAL): MAP_SCRIPT_ON_FRAME_TABLE fires
@ EVERY FRAME, not once (S7's own pin) -- VAR_TEMP_1 must be disarmed as the
@ scene's own SECOND instruction, exactly the OlivinePort template's shape
@ (OlivinePort_EventScript_AideArrival's `setvar VAR_TEMP_1, 0` immediately
@ after `lockall`). Without it, TryRunOnFrameMapScript re-evaluates the
@ table every frame after releaseall, VAR_TEMP_1 is still 1, and the whole
@ scene (including a bare addobject with no flag check) relaunches forever.
@ The corrected claim: once-only because arming ITSELF is now one-shot
@ (VAR_TEMP_1 disarmed here), AND FLAG_TRINITY_K_ARRIVED (set at the end)
@ keeps ON_TRANSITION from ever re-arming it on a later map load.
VermilionCity_EventScript_Arrival::
	lockall
	setvar VAR_TEMP_1, 0
	@ Fix round 1 (review Finding 3): R4 fade sandwich around the addobject,
	@ exact RadioTower5F precedent ("R4 fade: nothing pops",
	@ RadioTower5F/scripts.inc:368-374) -- BOBBY otherwise pops into existence
	@ two tiles from the player, camera-center, with no diegetic cover.
	fadescreen FADE_TO_BLACK
	addobject LOCALID_KANTO_VERMILION_BOBBY
	delay 20
	fadescreen FADE_FROM_BLACK
	turnobject LOCALID_KANTO_VERMILION_SAILOR, DIR_EAST
	turnobject LOCALID_KANTO_VERMILION_BOBBY, DIR_EAST
	msgbox VermilionCity_Text_SailorWelcome, MSGBOX_DEFAULT
	closemessage
	goto_if_unset FLAG_TRINITY_J_BOBBY_REVEALED, VermilionCity_EventScript_BobbyBriefGeneric
	goto VermilionCity_EventScript_BobbyBriefRevealed
	end

@ INTENTIONALLY UNREACHABLE / DEFENSIVE. This scene only plays once
@ FLAG_TRINITY_K_ARRIVED is armable, which requires BOBBY's Olivine post to
@ have been visible, which requires VAR_TRINITY_JOHTO_ARC >= 10 -- and
@ FLAG_TRINITY_J_BOBBY_REVEALED is set inside the SAME terminal RadioTower5F
@ scene that first writes arc-J to 7, well before arc-J can ever reach 10.
@ So this flag is always true here. Written as real (if unreachable)
@ dialogue anyway, matching GoldenrodCity_EventScript_Bobby/_BobbyUnrevealed.
VermilionCity_EventScript_BobbyBriefGeneric::
	msgbox VermilionCity_Text_BobbyBriefGeneric, MSGBOX_DEFAULT
	goto VermilionCity_EventScript_ArrivalTerminal

VermilionCity_EventScript_BobbyBriefRevealed::
	msgbox VermilionCity_Text_BobbyBriefRevealed, MSGBOX_DEFAULT
	goto VermilionCity_EventScript_ArrivalTerminal

VermilionCity_EventScript_ArrivalTerminal::
	closemessage
	setflag FLAG_TRINITY_K_ARRIVED
	setvar VAR_TRINITY_KANTO_ARC, 1
	applymovement LOCALID_KANTO_VERMILION_BOBBY, VermilionCity_Movement_BobbyLeaves
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject LOCALID_KANTO_VERMILION_BOBBY
	releaseall
	end

@ (22,33) -> north into town, off the dock. Diegetic exit covered by
@ SE_EXIT -- R4's documented deviation (a disappearance that never pops
@ does not need a fadescreen sandwich), matching RadioTower5F's own
@ GIOVANNI/BOBBY walk-off exits.
VermilionCity_Movement_BobbyLeaves:
	walk_up
	walk_up
	step_end

@ ============================================================================
@ Trinity M5a T5 -- S.S. AQUA return leg, Kanto side. Dock tile decoded:
@ (23,33) MB_NORMAL elevation 3 collision 0, one tile north of the S.S. ANNE
@ dock's (22-24,34) MB_SOUTH_ARROW_WARP trio (see task-5-report.md). Same
@ gate as the OLIVINE PORT sailor's KANTO branch (FLAG_TRINITY_K_ARRIVED,
@ M5b S1's one writer) -- redundant-but-harmless here, since standing in
@ KANTO at all already implies the flag is set; kept for defensive symmetry
@ with that script. Fade-warp idiom only (YESNO -> warp -> waitstate).
@
@ Fix round 1 (review Finding 1): lands at OLIVINE PORT (7,22), NOT (7,24).
@ (7,24) is a single-tile dead pocket -- (6,24) MB_POND_WATER, (8,24)/(7,25)
@ collision 1, and its only land exit (7,23) is permanently occupied by
@ LOCALID_OLIVINE_PORT_SAILOR (flag "0", never hidden) -- a scripted `warp`
@ places the player there regardless of IsWarpMetatileBehavior, but once
@ landed they could never walk away: a true softlock. (7,22) is the tile the
@ existing S.S. TIDAL Lilycove arrival scene already uses for the same
@ reason (OlivinePort_EventScript_AideArrival's own movement comment).
@ Re-decoded: (7,22) col=0 elev=3 MB_NORMAL. Confirmed two ways off it:
@ north to (7,21) col=0 elev=3 MB_NORMAL (plain foot exit, the corridor up
@ to the plaza); west to (6,22) MB_POND_WATER col=0 (a Surf exit -- Act III
@ players are Surf-capable, same assumption reach_check.py's default model
@ uses tree-wide). The sailor is adjacent, one tile south, for the return
@ trip (interact by facing him -- no need to stand on his tile).
@ ============================================================================
VermilionCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_unset FLAG_TRINITY_K_ARRIVED, VermilionCity_EventScript_SailorNotYet
	goto_if_set FLAG_TRINITY_K_MYSTERIOUS_INVITATION, VermilionCity_EventScript_SailorTwoDestinations
	msgbox VermilionCity_Text_BackToOlivine, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_EventScript_SailorDecline
	closemessage
	setrespawn HEAL_LOCATION_OLIVINE_CITY
	warp MAP_OLIVINE_PORT, 7, 22
	waitstate
	release
	end

VermilionCity_EventScript_SailorDecline::
	msgbox VermilionCity_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ Trinity M5b S13a fix round 1 (review M1(b)/(c), M5). Once FLAG_TRINITY_K_
@ MYSTERIOUS_INVITATION is set, this branch REPLACES the Olivine-only path
@ above at the top of the conversation -- both destinations are named in the
@ very FIRST thing the Sailor says, a genuinely visible choice, not something
@ that only surfaces after the player happens to decline Olivine blind (the
@ shipped-then-reviewed shape: New Island was reachable only via a NO to
@ "Back to Olivine?", with zero forewarning that saying no led anywhere).
@ Sequential YESNO -- the already-proven, already-shipped idiom throughout
@ this file -- not a true multichoice widget: `dynmultichoice` exists in the
@ engine (asm/macros/event.inc) but has zero precedent anywhere in this tree,
@ and the ruling's own "multichoice OR EQUIVALENT -- your mechanism" grants
@ this lower-risk choice.
@
@ FLAG_TRINITY_K_MYSTERIOUS_INVITATION is co-signed the moment MEWTWO's
@ contract resolves, in CeruleanCave_B1F_EventScript_MewtwoResolved
@ (data/maps/CeruleanCave_B1F/scripts.inc) -- it is never set here, only
@ read. (Corrected cross-reference: the pre-fix comment here named
@ "NewIsland/scripts.inc's own resolved handler", which does not exist and
@ was never the co-sign site -- review M5.)
@
@ Fade-warp only on both legs (YESNO -> warp -> waitstate), the exact idiom
@ the OLIVINE leg above already uses -- no ship-corridor map, per the
@ founder's decision. No setrespawn on the NEW ISLAND leg specifically: NEW
@ ISLAND has no PC, so a faint there must respawn the player at their
@ EXISTING Kanto respawn point, not strand them -- contrast the OLIVINE leg's
@ own setrespawn two screens up. (The pre-fix comment on this point lived in
@ NewIsland/scripts.inc pointing back at "this file's header comment", which
@ says nothing about setrespawn -- the real discussion is HERE; review M5.)
@ ============================================================================
VermilionCity_EventScript_SailorTwoDestinations::
	msgbox VermilionCity_Text_TwoDestinations, MSGBOX_DEFAULT
	msgbox VermilionCity_Text_NewIslandOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_EventScript_GoToNewIsland
	msgbox VermilionCity_Text_BackToOlivine, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_EventScript_SailAnotherTimeAfterAll
	closemessage
	setrespawn HEAL_LOCATION_OLIVINE_CITY
	warp MAP_OLIVINE_PORT, 7, 22
	waitstate
	release
	end

VermilionCity_EventScript_GoToNewIsland::
	closemessage
	warp MAP_NEW_ISLAND, 5, 7
	waitstate
	release
	end

VermilionCity_EventScript_SailAnotherTimeAfterAll::
	msgbox VermilionCity_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

VermilionCity_EventScript_SailorNotYet::
	msgbox VermilionCity_Text_SailorNotYet, MSGBOX_DEFAULT
	release
	end

VermilionCity_Text_BackToOlivine:
	.string "Back to OLIVINE CITY, over in\n"
	.string "JOHTO?$"

@ M1(c): this line must reference ONLY an invitation that actually exists.
@ CeruleanCave_B1F_Text_Invitation (data/maps/CeruleanCave_B1F/scripts.inc)
@ is the moment the player finds and takes the envelope this line points
@ back to -- the two texts are written to agree on what happened.
VermilionCity_Text_TwoDestinations:
	.string "That envelope you picked up at\n"
	.string "CERULEAN CAVE has sailing marks on\l"
	.string "it -- looks like an invitation. I\l"
	.string "could take you out to the island it\l"
	.string "points to, or back to OLIVINE CITY.$"

VermilionCity_Text_NewIslandOffer:
	.string "Out to the island, then?$"

VermilionCity_Text_SailAnotherTime:
	.string "Please sail with us another time!$"

VermilionCity_Text_SailorNotYet:
	.string "Give it time -- the crossing back\n"
	.string "to JOHTO isn't running yet.$"

@ ============================================================================
@ Trinity M5b S1 -- the arrival scene's own dialogue. BOBBY's voice matches
@ RadioTower5F_Text_Bobby1..3 / GoldenrodCity_Text_Bobby: terse, wry,
@ professional. "I'll be somewhere behind you" is the deliberate callback to
@ his GoldenrodCity coda line.
@ ============================================================================
VermilionCity_Text_SailorWelcome:
	.string "Welcome to VERMILION CITY, {PLAYER}!\p"
	.string "First stop in KANTO. Seven GYMS\n"
	.string "here, open in whatever order you\l"
	.string "like -- and not one of them's heard\l"
	.string "your name yet.$"

VermilionCity_Text_BobbyBriefRevealed:
	.string "BOBBY: KANTO's colder than it\n"
	.string "looks.\p"
	.string "Whatever GIOVANNI's building,\n"
	.string "VERMILION isn't it -- but SURGE\l"
	.string "runs this GYM, and he doesn't tip\l"
	.string "news for free. Beat him, you'll get\l"
	.string "further asking around.\p"
	.string "I've got my own leads to run down.\n"
	.string "Find the badges. I'll be somewhere\l"
	.string "behind you.$"

VermilionCity_Text_BobbyBriefGeneric:
	.string "BOBBY: KANTO's colder than it\n"
	.string "looks.\p"
	.string "SURGE runs the GYM here. Beat him,\n"
	.string "you'll get further asking around\l"
	.string "about what GIOVANNI's up to.\p"
	.string "I've got my own leads to run down.\n"
	.string "Find the badges. I'll be somewhere\l"
	.string "behind you.$"
