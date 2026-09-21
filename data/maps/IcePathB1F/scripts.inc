IcePathB1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, IcePathB1F_SetHoleWarp
	.byte 0

IcePathB1F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_ICE_PATH_B2F_MAHOGANY_SIDE
	end

@ ============================================================================
@ Trinity M4b S10 -- GSC's ICE PATH B1F BOULDER PUZZLE, on S9's engine hook.
@
@ This is the one boulder beat in JOHTO that is a PUZZLE rather than scenery,
@ and it is the payoff of the C hook S9 shipped and never got to use twice.
@ GSC drives it from a MAPCALLBACK_CMDQUEUE stonetable (IcePathB1F.asm):
@     stonetable 3, BOULDER1, .Boulder1   ; warp id 3 == the hole at (11,2)
@     stonetable 4, BOULDER2, .Boulder2   ; == (4,7)
@     stonetable 5, BOULDER3, .Boulder3   ; == (5,12)
@     stonetable 6, BOULDER4, .Boulder4   ; == (12,13)
@ -- push a boulder onto a hole, it falls, and its counterpart APPEARS on B2F
@ MAHOGANY SIDE. One boolean, two complementary objects on two floors.
@
@ M4a PORT NOTE, recorded not fixed: GSC's B1F has EIGHT warps, four of them the
@ hole warps above; this port has FOUR. M4a Task 7 replaced them with
@ setholewarp + STEP_CB_CRACKED_FLOOR (the ON_RESUME above), which lands the
@ player at the same (x,y) on B2F. That is why the four hole tiles below are
@ MB_CRACKED_FLOOR_HOLE with no warp_event of their own, and it is why the
@ coord_events here are the ONLY thing that can notice a boulder landing on one.
@
@ THE HOOK, and why the coord_events cannot fire for the PLAYER.
@ TryBoulderFallThroughHole (src/field_player_avatar.c, S9) runs as the last
@ statement of PushBoulder_End. It returns immediately unless the tile the
@ boulder came to rest on is MB_CRACKED_FLOOR_HOLE *and* this map declares a
@ coord_event at that tile tagged BOULDER_HOLE_COORD_EVENT_ELEVATION
@ (ELEVATION_MULTI_LEVEL, 15). The player can never fire such an entry:
@ GetCoordEventScriptAtPosition requires elevation == the PLAYER's own or
@ ELEVATION_TRANSITION (src/field_control_avatar.c:1085-1097). Belt and braces,
@ per S9's I1 correction (the "scan returns on the first match" claim was FALSE
@ -- the loop continues on NULL, so ordering is NOT a guard): each entry also
@ carries a var_value VAR_TEMP_0 never holds. Either guard alone suffices.
@
@ ONE fall script serves all four holes. The hook sets
@ gSpecialVar_LastTalked = boulder->localId before it runs the script, so
@ `removeobject VAR_LAST_TALKED` names the right boulder on the engine path
@ (where it is already a no-op -- removeobject is idempotent, because
@ RemoveObjectEventByLocalIdAndMap skips its body when the object is gone,
@ src/event_object_movement.c:1537-1545) AND on the talk backstop, where it does
@ the work. Its FlagSet is what sets FLAG_TRINITY_J_ICE_BOULDER_n, which is what
@ B2F MAHOGANY SIDE's ON_TRANSITION reads to put the landing on stage.
@
@ THE BACKSTOP is S9's rule, verbatim: a new runtime hook under a no-play-test
@ gate ships with a script-only second path. Every boulder's talk script asks
@ getobjectxy whether it is standing on one of the four holes and runs the same
@ fall script if so; otherwise it falls through to vanilla
@ EventScript_StrengthBoulder. That fall-through is MANDATORY -- FLAG_SYS_USE_
@ STRENGTH is cleared on every map load (ClearTempFieldEventData,
@ src/event_data.c:64, from src/overworld.c:860 and :924), so the vanilla prompt
@ is the only thing that re-arms Strength on this floor.
@
@ NOT PUZZLE-CRITICAL, and measured: the four holes are the PLAYER's own route
@ to B2F MAHOGANY SIDE and they work with no boulder pushed at all. Nothing in
@ S10 or any other slice is behind this puzzle. Boulder positions never persist
@ (LoadObjEventTemplatesFromHeader re-copies the ROM templates on every map
@ load, src/overworld.c:521-530), so it cannot be soft-locked either.
@
@ NO visibility authoring for the four boulder flags: each has exactly one
@ writer (removeobject's FlagSet) and the correct default, clear == on the floor
@ (S7's rule -- an authoring clause would resurrect a fallen boulder).
@
@ TILE DECODES: boulders (11,7) (7,8) (8,9) (17,7), all GSC's own
@ (IcePathB1F.asm:95-98), all collision 0 / elevation 3 / MB_CAVE / reachable.
@ Holes (11,2) (4,7) (5,12) (12,13), all MB_CRACKED_FLOOR_HOLE.
@ ============================================================================

IcePathB1F_EventScript_Boulder::
	@ The 0 is CURRENT_POSITION, spelled as a literal because that name is an
	@ ENUM member, not a #define, so the assembler cannot see it (S9's pin).
	getobjectxy VAR_LAST_TALKED, 0, VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 11, IcePathB1F_EventScript_BoulderColumn11
	goto_if_eq VAR_0x8004, 4, IcePathB1F_EventScript_BoulderColumn4
	goto_if_eq VAR_0x8004, 5, IcePathB1F_EventScript_BoulderColumn5
	goto_if_eq VAR_0x8004, 12, IcePathB1F_EventScript_BoulderColumn12
	goto EventScript_StrengthBoulder
	end

IcePathB1F_EventScript_BoulderColumn11::
	goto_if_eq VAR_0x8005, 2, IcePathB1F_EventScript_BoulderFellThrough
	goto EventScript_StrengthBoulder
	end

IcePathB1F_EventScript_BoulderColumn4::
	goto_if_eq VAR_0x8005, 7, IcePathB1F_EventScript_BoulderFellThrough
	goto EventScript_StrengthBoulder
	end

IcePathB1F_EventScript_BoulderColumn5::
	goto_if_eq VAR_0x8005, 12, IcePathB1F_EventScript_BoulderFellThrough
	goto EventScript_StrengthBoulder
	end

IcePathB1F_EventScript_BoulderColumn12::
	goto_if_eq VAR_0x8005, 13, IcePathB1F_EventScript_BoulderFellThrough
	goto EventScript_StrengthBoulder
	end

@ Entered from EITHER the engine hook (object already gone, LastTalked set from
@ C) or the talk backstop (object still there). removeobject is idempotent, so
@ one script serves both. GSC's own beat: pause, SFX_STRENGTH + earthquake, and
@ the line about hearing it land.
IcePathB1F_EventScript_BoulderFellThrough::
	lockall
	delay 30
	playse SE_FALL
	waitse
	removeobject VAR_LAST_TALKED
	msgbox IcePathB1F_Text_BoulderFellThrough, MSGBOX_DEFAULT
	releaseall
	end

IcePathB1F_Text_BoulderFellThrough:
	.string "The boulder dropped through the\n"
	.string "hole in the ice.\p"
	.string "It landed a long way down.$"
