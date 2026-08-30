@ FIX ROUND (review C1, CRITICAL): both exit warps used to target THIS
@ SAME MAP with WARP_ID_DYNAMIC while never having a MAP_DYNAMIC dest_map --
@ SetupWarp (src/field_control_avatar.c:990-1002) takes the non-dynamic
@ path on that mismatch, resolves warpId 0x7F against this map's own
@ 2-entry warp array (out of range), and drops the player at the map's
@ undefined fallback position with no way out (allow_escaping FALSE +
@ MAP_TYPE_INDOOR = no Escape Rope/Dig/Teleport either). Confirmed by
@ comparing against LilycoveCity_DepartmentStoreElevator's own CORRECT
@ shipped shape (dest_map: MAP_DYNAMIC, the real sentinel,
@ include/constants/maps.h:10) -- this tree's own working reference for the
@ mechanism. Both exits now point at fixed, decoded landings on
@ RocketHideout_B1F (see that map's own warp_events 6/7, added this round).
@ M6 note: this is still not a real multi-floor elevator -- no floor-select
@ UI exists in this engine at all (see 06-celadon-chapter.md section 7);
@ the fix only makes the door safe to walk through, matching
@ CeladonCity_DepartmentStore_Elevator's and SilphCo_Elevator's own
@ identical fix this same round.
RocketHideout_Elevator_MapScripts::
	.byte 0

RocketHideout_Elevator_EventScript_FloorSelect::
	msgbox RocketHideout_Elevator_Text_FloorSelect, MSGBOX_SIGN
	end

RocketHideout_Elevator_Text_FloorSelect:
	.string "The control panel is dark.\nWhatever ran this lift, it isn't\lrunning anymore.$"
