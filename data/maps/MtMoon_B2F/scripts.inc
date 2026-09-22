@ ============================================================================
@ Trinity M5b S4 fix round -- CRITICAL FIX C1 (review, ruling attached).
@
@ T10 ported FRLG's Mt. Moon wall geometry but dropped its DOOR: FRLG's own
@ two fossils (pokefirered/data/maps/MtMoon_B2F/scripts.inc:1-12,53-106) sit
@ in the ONLY gap between the Route3/Pewter-side and Route4/Cerulean-side
@ halves of the whole 5-map complex, each behind its OWN hide flag
@ (FLAG_HIDE_DOME_FOSSIL/FLAG_HIDE_HELIX_FOSSIL) that a real pickup clears
@ them out of. T10 shipped both flag:"0" (always spawned, permanent,
@ un-removable) -- the reviewer's ablation proved this seals the corridor
@ tree-wide: with all objects present the Pewter-side component is 2992
@ tiles; removing EITHER fossil object alone grows it past 3780+.
@
@ Ported FRLG's real mechanism (the classic take-one-fossil choice),
@ simplified: no Miguel-takes-the-other-one choreography and no Team Rocket
@ grunt guard-post subplot -- T10 never placed the FRLG Rocket objects on
@ this map either, matching this hack's already-established "the Rocket
@ arc stays Celadon/Viridian" convention (S3's own skip log). Each fossil
@ keeps its OWN hide flag (they retire together but are read separately
@ pre-pickup -- the exact shape FRLG itself uses, not a shared-cast flag);
@ `removeobject` co-signs each one's own flag as an engine side effect
@ (RemoveObjectEventByLocalIdAndMap -> FlagSet, the R1 mechanism), so
@ neither object needs an explicit `setflag` of its own. Both objects are
@ removed on either pickup (you can only carry one), the removal pair is
@ R4-fade-sandwiched (nothing pops off-screen for the un-picked fossil),
@ and one terminal flag (FLAG_TRINITY_K_MTMOON_FOSSIL_TAKEN) gates the
@ ON_TRANSITION re-show clause below, mirroring FRLG's own
@ FLAG_GOT_FOSSIL_FROM_MT_MOON exactly. ON_TRANSITION is single-occupancy
@ (this map had no MapScripts table before this fix -- a fresh add, no
@ conflict).
@
@ S9 HANDOFF: fossils are now obtainable here (ITEM_DOME_FOSSIL /
@ ITEM_HELIX_FOSSIL, real bag items via `giveitem`). S9's Cinnabar Lab owns
@ REVIVING them (per the M5b master plan's own S9 line) -- nothing here
@ builds any revival mechanic, only the pickup.
@ ============================================================================
MtMoon_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_B2F_OnTransition
	.byte 0

MtMoon_B2F_OnTransition::
	call_if_unset FLAG_TRINITY_K_MTMOON_FOSSIL_TAKEN, MtMoon_B2F_EventScript_ShowFossils
	end

MtMoon_B2F_EventScript_ShowFossils::
	clearflag FLAG_TRINITY_K_MTMOON_DOME_FOSSIL_HIDE
	clearflag FLAG_TRINITY_K_MTMOON_HELIX_FOSSIL_HIDE
	return

MtMoon_B2F_EventScript_DomeFossil::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_K_MTMOON_FOSSIL_TAKEN, MtMoon_B2F_EventScript_FossilGone
	msgbox MtMoon_B2F_Text_YouWantDomeFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtMoon_B2F_EventScript_DontTakeFossil
	giveitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_KANTO_MTMOON_B2F_DOME_FOSSIL
	removeobject LOCALID_KANTO_MTMOON_B2F_HELIX_FOSSIL
	delay 20
	fadescreen FADE_FROM_BLACK
	setflag FLAG_TRINITY_K_MTMOON_FOSSIL_TAKEN
	msgbox MtMoon_B2F_Text_OtherFossilCrumbles, MSGBOX_DEFAULT
	release
	end

MtMoon_B2F_EventScript_HelixFossil::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_K_MTMOON_FOSSIL_TAKEN, MtMoon_B2F_EventScript_FossilGone
	msgbox MtMoon_B2F_Text_YouWantHelixFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtMoon_B2F_EventScript_DontTakeFossil
	giveitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_KANTO_MTMOON_B2F_HELIX_FOSSIL
	removeobject LOCALID_KANTO_MTMOON_B2F_DOME_FOSSIL
	delay 20
	fadescreen FADE_FROM_BLACK
	setflag FLAG_TRINITY_K_MTMOON_FOSSIL_TAKEN
	msgbox MtMoon_B2F_Text_OtherFossilCrumbles, MSGBOX_DEFAULT
	release
	end

MtMoon_B2F_EventScript_DontTakeFossil::
	release
	end

MtMoon_B2F_EventScript_FossilGone::
	msgbox MtMoon_B2F_Text_FossilAlreadyGone, MSGBOX_DEFAULT
	release
	end

MtMoon_B2F_EventScript_Miguel::
	msgbox MtMoon_B2F_Text_Miguel, MSGBOX_NPC
	end

MtMoon_B2F_Text_YouWantDomeFossil:
	.string "A DOME FOSSIL.\nA piece of an ancient POKéMON's\lshell.\pTake it?$"

MtMoon_B2F_Text_YouWantHelixFossil:
	.string "A HELIX FOSSIL.\nA piece of an ancient POKéMON's\lshell.\pTake it?$"

MtMoon_B2F_Text_OtherFossilCrumbles:
	.string "The other fossil crumbles to dust\nthe moment it's disturbed.\pYou can only carry one.$"

MtMoon_B2F_Text_FossilAlreadyGone:
	.string "Just an empty patch of rock where\na fossil used to be.$"

MtMoon_B2F_Text_Miguel:
	.string "Both fossils are mine. I don't\ncare what you've won elsewhere.$"
