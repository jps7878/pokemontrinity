SproutTower3F_MapScripts::
	.byte 0

SproutTower3F_EventScript_JIN::
	trainerbattle_single TRAINER_JOHTO_SAGE_JIN, SproutTower3F_Text_JINSeen, SproutTower3F_Text_JINBeaten
	msgbox SproutTower3F_Text_JINAfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower3F_EventScript_TROY::
	trainerbattle_single TRAINER_JOHTO_SAGE_TROY, SproutTower3F_Text_TROYSeen, SproutTower3F_Text_TROYBeaten
	msgbox SproutTower3F_Text_TROYAfterBattle, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ Trinity M4b S2 -- the SPROUT TOWER ELDER (adapts pokecrystal SageLiScript).
@ M4a ported this object as a flavor msgbox; S2 makes him the tower's boss,
@ TRAINER_JOHTO_SAGE_LI (id 1072, VICTREEBEL 59 / VICTREEBEL 59 / NOCTOWL 60 --
@ GSC's BELLSPROUT/BELLSPROUT/HOOTHOOT shape rescaled to Act II).
@
@ This is the NON-GYM form of the GYM PATTERN's award shape (see
@ data/maps/VioletGym/scripts.inc, G2): a failable gift gets its own flag and
@ its own label, reachable from both the just-won path (goto) and the re-talk
@ path (goto_if_unset), so a full bag retries instead of losing the reward.
@ No badge and no fanfare -- he is not a gym leader; his class (Expert)
@ resolves the ordinary trainer battle theme with no scripting. He DOES take
@ NO_MUSIC, for the same reason the leaders do: the general rule is that any
@ TALK-triggered trainerbattle passes NO_MUSIC, because
@ PlayTrainerEncounterMusic swaps the whole map BGM (PlayNewMapMusic) for the
@ approach and intro text -- that belongs to a sight line, not to a
@ conversation (src/battle_setup.c:1451-1499). The six sages below are
@ TRAINER_TYPE_NORMAL and keep it.
@
@ GSC hands out HM05 FLASH here. Trinity cannot: field HMs are automatic and
@ FLASH arrived in Act I. Replaced with a PP UP -- the one consumable that
@ permanently deepens a move the player already chose to keep, which is this
@ tower's whole stated theme. Logged in the slice plan section 6.
@ He stands at (10,2), unmoved from M4a: collision-0 elevation-3 MB_CAVE,
@ row 2 open x=5..14, and the (9,1)/(10,1) alcove behind him stays reachable
@ through (9,2), so he seals nothing.
@ ============================================================================
SproutTower3F_EventScript_Elder::
	trainerbattle_single TRAINER_JOHTO_SAGE_LI, SproutTower3F_Text_ElderIntro, SproutTower3F_Text_ElderDefeat, SproutTower3F_EventScript_ElderDefeated, NO_MUSIC
	@ Re-talk path only (the continuation above already ran on the fought
	@ battle). Retry the gift if the bag was full, else his idle line.
	goto_if_unset FLAG_TRINITY_J_SPROUT_ELDER_GIFT, SproutTower3F_EventScript_ElderGift
	msgbox SproutTower3F_Text_ElderAfterBattle, MSGBOX_DEFAULT
	release
	end

SproutTower3F_EventScript_ElderDefeated::
	msgbox SproutTower3F_Text_ElderTakeThis, MSGBOX_DEFAULT
	goto SproutTower3F_EventScript_ElderGift
	end

SproutTower3F_EventScript_ElderGift::
	giveitem ITEM_PP_UP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_TRINITY_J_SPROUT_ELDER_GIFT
	msgbox SproutTower3F_Text_ElderPPUp, MSGBOX_DEFAULT
	release
	end

SproutTower3F_EventScript_NEAL::
	trainerbattle_single TRAINER_JOHTO_SAGE_NEAL, SproutTower3F_Text_NEALSeen, SproutTower3F_Text_NEALBeaten
	msgbox SproutTower3F_Text_NEALAfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower3F_EventScript_Statue::
	msgbox SproutTower3F_Text_Statue, MSGBOX_SIGN
	end

SproutTower3F_EventScript_Statue_2::
	msgbox SproutTower3F_Text_Statue_2, MSGBOX_SIGN
	end

SproutTower3F_EventScript_Painting::
	msgbox SproutTower3F_Text_Painting, MSGBOX_SIGN
	end

SproutTower3F_EventScript_Painting_2::
	msgbox SproutTower3F_Text_Painting_2, MSGBOX_SIGN
	end

SproutTower3F_EventScript_Statue_3::
	msgbox SproutTower3F_Text_Statue_3, MSGBOX_SIGN
	end

SproutTower3F_EventScript_Statue_4::
	msgbox SproutTower3F_Text_Statue_4, MSGBOX_SIGN
	end

SproutTower3F_Text_JINSeen:
	.string "I train to find\nenlightenment in\lPOKéMON!$"

SproutTower3F_Text_JINBeaten:
	.string "My training is\nincomplete…$"

@ GSC SageJinAfterBattleText.
SproutTower3F_Text_JINAfterBattle:
	.string "As POKéMON grow stronger, so\n"
	.string "does the trainer.\p"
	.string "No -- wait. As the trainer grows\n"
	.string "stronger, so do the POKéMON.$"

SproutTower3F_Text_TROYSeen:
	.string "Let me see how\nmuch you trust\lyour POKéMON.$"

SproutTower3F_Text_TROYBeaten:
	.string "Yes, your trust is\nreal!$"

@ GSC SageTroyAfterBattleText.
SproutTower3F_Text_TROYAfterBattle:
	.string "It is not far to the ELDER now.\p"
	.string "He has been waiting all week for\n"
	.string "someone worth testing.$"

@ HM-era line repaired (slice plan section 6): M4a shipped GSC's "The ELDER's
@ HM lights even pitch-black darkness", which promises a reward Trinity does
@ not give -- field HMs are automatic here and FLASH arrived in Act I.
SproutTower3F_Text_NEALSeen:
	.string "Beyond me stands the ELDER.\n"
	.string "He is the last test in this\l"
	.string "tower, and the oldest.$"

SproutTower3F_Text_NEALBeaten:
	.string "It is my head that\nis bright!$"

@ GSC SageNealAfterBattleText.
SproutTower3F_Text_NEALAfterBattle:
	.string "Let there be light on your\n"
	.string "journey.$"

@ ============================================================================
@ ELDER (adapts SageLiSeenText / SageLiBeatenText / SageLiTakeThisFlashText /
@ SageLiFlashExplanationText / SageLiAfterBattleText). GSC's "you need
@ VIOLET's BADGE to use FLASH" beat is dropped whole -- see the script header.
@ ============================================================================
SproutTower3F_Text_ElderIntro:
	.string "ELDER: So good of you to come.\p"
	.string "SPROUT TOWER is a place of\n"
	.string "training. People and POKéMON\l"
	.string "test the ties between them here.\p"
	.string "You have already tested yours\n"
	.string "further than anyone who climbs\l"
	.string "these stairs ever will.\p"
	.string "Test them once more anyway.\n"
	.string "I am the last step.$"

SproutTower3F_Text_ElderDefeat:
	.string "Ah.\nExcellent.$"

SproutTower3F_Text_ElderTakeThis:
	.string "ELDER: The ties held. I did not\n"
	.string "doubt it, but seeing is better\l"
	.string "than believing.\p"
	.string "We used to send travellers down\n"
	.string "these stairs with an HM.\p"
	.string "You came up carrying moves my\n"
	.string "sages will never learn.\p"
	.string "So take something you can\n"
	.string "actually use.$"

SproutTower3F_Text_ElderPPUp:
	.string "ELDER: A move you have kept this\n"
	.string "long deserves to last longer.\p"
	.string "That is the whole teaching of\n"
	.string "this tower, in one small jar.\p"
	.string "Now go. VIOLET's GYM is waiting,\n"
	.string "and FALKNER is not a patient\l"
	.string "young man.$"

SproutTower3F_Text_ElderAfterBattle:
	.string "ELDER: I hope you learn and grow\n"
	.string "from your journey.\p"
	.string "Even at the top, {PLAYER}.\n"
	.string "Especially at the top.$"

SproutTower3F_Text_Statue:
	.string "A POKéMON statue…\pIt looks very\ndistinguished.$"

SproutTower3F_Text_Statue_2:
	.string "A POKéMON statue…\pIt looks very\ndistinguished.$"

SproutTower3F_Text_Painting:
	.string "It's a powerful\npainting of a\lBELLSPROUT.$"

SproutTower3F_Text_Painting_2:
	.string "It's a powerful\npainting of a\lBELLSPROUT.$"

SproutTower3F_Text_Statue_3:
	.string "A POKéMON statue…\pIt looks very\ndistinguished.$"

SproutTower3F_Text_Statue_4:
	.string "A POKéMON statue…\pIt looks very\ndistinguished.$"
