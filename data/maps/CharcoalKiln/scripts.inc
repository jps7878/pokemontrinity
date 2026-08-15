CharcoalKiln_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S3 -- CHARCOAL KILN flavour. Adapts pokecrystal
@ maps/CharcoalKiln.asm's CharcoalKilnBoss / CharcoalKilnApprentice, two states
@ each on EVENT_CLEARED_SLOWPOKE_WELL, which is VAR_TRINITY_JOHTO_ARC >= 3 here.
@ SKIPPED and logged: GSC's FARFETCH'D hunt, HM01 CUT and the CHARCOAL gift --
@ those belong to the ILEX FOREST CUT sidequest, not the AZALEA story chapter.
@ Both tiles are GSC's and both decode collision 0 in
@ LAYOUT_BILLS_FAMILYS_HOUSE_JOHTO; neither seals anything (rows 2 and 5 are
@ open across the full width).
@ ============================================================================
CharcoalKiln_EventScript_Master::
	lock
	faceplayer
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 3, CharcoalKiln_EventScript_MasterAfter
	msgbox CharcoalKiln_Text_MasterBefore, MSGBOX_DEFAULT
	release
	end

CharcoalKiln_EventScript_MasterAfter::
	msgbox CharcoalKiln_Text_MasterAfter, MSGBOX_DEFAULT
	release
	end

CharcoalKiln_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_ge VAR_TRINITY_JOHTO_ARC, 3, CharcoalKiln_EventScript_ApprenticeAfter
	msgbox CharcoalKiln_Text_ApprenticeBefore, MSGBOX_DEFAULT
	release
	end

CharcoalKiln_EventScript_ApprenticeAfter::
	msgbox CharcoalKiln_Text_ApprenticeAfter, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ Text
@ ============================================================================
@ GSC CharcoalKilnBossText1.
CharcoalKiln_Text_MasterBefore:
	.string "All the SLOWPOKE have gone from\n"
	.string "the town.\p"
	.string "The forest's protector may be\n"
	.string "angry with us…\p"
	.string "It's a bad omen. We've banked\n"
	.string "the kiln and we're staying in.$"

@ Adapts GSC CharcoalKilnBossText3 -- praise for chasing off TEAM ROCKET,
@ minus the ILEX FOREST / CUT thread.
CharcoalKiln_Text_MasterAfter:
	.string "The SLOWPOKE are back in the\n"
	.string "street, and I hear you're the\l"
	.string "reason.\p"
	.string "You went down that WELL alone,\n"
	.string "against TEAM ROCKET.\p"
	.string "That takes guts. I like that.\n"
	.string "Come and train with us sometime.\p"
	.string "We burn ILEX oak in here. Slow\n"
	.string "fire, six days. Nothing worth\l"
	.string "having is quick.$"

@ GSC CharcoalKilnApprenticeText1.
CharcoalKiln_Text_ApprenticeBefore:
	.string "Where have all the SLOWPOKE\n"
	.string "gone?\p"
	.string "Are they out playing somewhere?\p"
	.string "…The BOSS won't let me go and\n"
	.string "look. He says it's an omen.$"

CharcoalKiln_Text_ApprenticeAfter:
	.string "The SLOWPOKE came back!\p"
	.string "One of them sat down on my char-\n"
	.string "coal barrow and went to sleep.\p"
	.string "You're the coolest, man.$"
