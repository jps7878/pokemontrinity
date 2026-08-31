@ ============================================================================
@ Trinity M5b S9 -- CINNABAR FOSSIL LAB. Fossil revival, script-driven, ZERO
@ engine C changes (sub-plan section 2).
@
@ Traced from Hoenn's own Rustboro/Devon chain (data/maps/RustboroCity_DevonCorp_
@ 2F/scripts.inc): VAR_FOSSIL_RESURRECTION_STATE (0 idle / 1 regenerating / 2
@ ready) is the pending-fossil state var; VAR_WHICH_FOSSIL_REVIVED is the species
@ selector, purely `goto_if_eq` branches into plain `givemon` calls -- no special,
@ no C table. Both vars are global (not Hoenn-scoped) and safe to reuse here:
@ strict act linearity (Hoenn -> Johto -> Kanto, spec decision 7) means a Kanto
@ player can never arrive with Hoenn's own fossil quest still mid-state, and the
@ state resets to 0 after every give, so a second revival (Mt. Moon's fossil,
@ then later Old Amber) needs nothing extra -- the machine is naturally
@ re-entrant. FLAG_RECEIVED_REVIVED_FOSSIL_MON is NOT reused (it's Hoenn-scoped,
@ 0x10B, would false-positive if the player already ran Hoenn's own quest).
@
@ Extension: species branch widened 2 -> 3 (1=Omanyte, 2=Kabuto, 3=Aerodactyl).
@ No multichoice extension needed -- Mt. Moon's take-one rule (S4 handoff) plus a
@ single Old Amber source means the player holds at most two fossil items at
@ once; checked in priority order instead (Helix, then Dome, then Amber).
@ ============================================================================

CinnabarIsland_PokemonLab_ExperimentRoom_MapScripts::
	.byte 0

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_Garett::
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_Garett, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist::
	lock
	faceplayer
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilMonReady
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_StillRegenerating
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NoticeHelixFossil
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NoticeDomeFossil
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NoticeOldAmber
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_DevelopedFossilDevice, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NoticeHelixFossil::
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineGiveFossil
	removeitem ITEM_HELIX_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NoticeDomeFossil::
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineGiveFossil
	removeitem ITEM_DOME_FOSSIL
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NoticeOldAmber::
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineGiveFossil
	removeitem ITEM_OLD_AMBER
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	setvar VAR_WHICH_FOSSIL_REVIVED, 3
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineGiveFossil::
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_OhIsThatSo, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_StillRegenerating::
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilMonReady::
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_OmanyteReady
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 2, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_KabutoReady
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_AerodactylReady
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_OmanyteReady::
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceiveOmanyte
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_KabutoReady::
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceiveKabuto
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_AerodactylReady::
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceiveAerodactyl
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceiveOmanyte::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_OMANYTE
	givemon SPECIES_OMANYTE, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceiveOmanyteParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceiveOmanytePC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceiveOmanyteParty::
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceivedOmanyteFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FinishReceivingFossilMon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FinishReceivingFossilMon

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceiveOmanytePC::
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceivedOmanyteFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_TransferFossilMonToPC
	call Common_EventScript_NameReceivedBoxMon
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_TransferFossilMonToPC

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceivedOmanyteFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	playfanfare MUS_OBTAIN_ITEM
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
	return

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceiveKabuto::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_KABUTO
	givemon SPECIES_KABUTO, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceiveKabutoParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceiveKabutoPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceiveKabutoParty::
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceivedKabutoFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FinishReceivingFossilMon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FinishReceivingFossilMon

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceiveKabutoPC::
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceivedKabutoFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_TransferFossilMonToPC
	call Common_EventScript_NameReceivedBoxMon
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_TransferFossilMonToPC

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceivedKabutoFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
	playfanfare MUS_OBTAIN_ITEM
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
	return

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceiveAerodactyl::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_AERODACTYL
	givemon SPECIES_AERODACTYL, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceiveAerodactylParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceiveAerodactylPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceiveAerodactylParty::
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceivedAerodactylFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FinishReceivingFossilMon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FinishReceivingFossilMon

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceiveAerodactylPC::
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceivedAerodactylFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_TransferFossilMonToPC
	call Common_EventScript_NameReceivedBoxMon
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_TransferFossilMonToPC

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ReceivedAerodactylFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	playfanfare MUS_OBTAIN_ITEM
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
	return

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_TransferFossilMonToPC::
	call Common_EventScript_TransferredToPC
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FinishReceivingFossilMon

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FinishReceivingFossilMon::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_Text_Garett:
	.string "I never put much stock in rumors,\nbut two Leagues cleared is two\lLeagues cleared. Impressive.$"

CinnabarIsland_PokemonLab_ExperimentRoom_Text_DevelopedFossilDevice:
	.string "We can bring a fossilized POKéMON\nback to life -- if you've got one\lon you.$"

CinnabarIsland_PokemonLab_ExperimentRoom_Text_WantToBringFossilBackToLife:
	.string "Ooh, a fossil! Want me to bring\nit back to life?$"

CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToResearcher:
	.string "OK! Leave it to me. Come back\nin a bit.$"

CinnabarIsland_PokemonLab_ExperimentRoom_Text_OhIsThatSo:
	.string "Oh, is that so?$"

CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilRegeneratorTakesTime:
	.string "The FOSSIL REGENERATOR, which I\nmade, is at work.\pPlease wait a while longer.$"

CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilizedMonBroughtBackToLife:
	.string "Your fossilized POKéMON is done!\nIt's alive!$"

CinnabarIsland_PokemonLab_ExperimentRoom_Text_ReceivedMonFromResearcher:
	.string "{PLAYER} received {STR_VAR_1}\nfrom the researcher.$"
