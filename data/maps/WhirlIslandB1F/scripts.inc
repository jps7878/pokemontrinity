WhirlIslandB1F_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S10 -- GSC's Strength boulder at (23,26) (WhirlIslandB1F.asm:68), placed as
@ OBJ_EVENT_GFX_PUSHABLE_BOULDER with vanilla's own EventScript_StrengthBoulder.
@ Decoded collision 0 / elevation 3 / MB_NORMAL / reachable, costing exactly one
@ tile (its own); the complex re-reports NO SEALED WARPS with it placed.
@
@ IT CARRIES A FLAG_TEMP, LIKE VANILLA'S OWN 59 BOULDERS, and that is the right
@ choice rather than laziness: object template positions never persist
@ (LoadObjEventTemplatesFromHeader CpuCopy32s the ROM templates back on every
@ map load, src/overworld.c:521-530), so a permanent flag on a boulder that can
@ only be SHOVED would be dead weight -- and if a removeobject ever ran on one it
@ would co-sign that flag and delete the boulder for good. Only the ICE PATH
@ four, which fall down holes, take permanent flags.
@
@ STRENGTH IS AVAILABLE: IsFieldMoveUnlocked_Strength is FlagGet(FLAG_BADGE04_GET)
@ (src/field_move.c:26-29) -- the HOENN Heat Badge, which the Act II player holds
@ as Champion. No config exists to change that and none is needed.
@ ============================================================================
