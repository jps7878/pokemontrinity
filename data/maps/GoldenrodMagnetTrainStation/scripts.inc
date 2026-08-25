GoldenrodMagnetTrainStation_MapScripts::
	.byte 0

GoldenrodMagnetTrainStation_EventScript_Officer::
	msgbox GoldenrodMagnetTrainStation_Text_Officer, MSGBOX_NPC
	end

GoldenrodMagnetTrainStation_Text_Officer:
	.string "I've lived in JOHTO my whole life.\nNever thought I'd meet someone\lfrom HOENN way out here.$"

@ ============================================================================
@ Trinity M5a T5 -- GOLDENROD side of the MAGNET TRAIN, stubbed and gated OFF.
@ VERIFY (per this task's brief): grepping data/maps for TrainStation/
@ MagnetTrain turns up only this one map -- no SaffronCity_MagnetTrainStation
@ or any Kanto-side terminus exists among the 269 ported maps. The Kanto
@ terminus is therefore a NEW map, out of this task's scope; flagged to M5b
@ S2 in task-5-report.md, which also writes FLAG_TRINITY_K_TRAIN_PASS (this
@ task only reads it). Both existing platform doors (6,5)/(11,5) stay
@ self-warps (M3 port state, unchanged) since there is nowhere to send them.
@ ============================================================================
GoldenrodMagnetTrainStation_EventScript_Attendant::
	lock
	faceplayer
	goto_if_unset FLAG_TRINITY_K_TRAIN_PASS, GoldenrodMagnetTrainStation_EventScript_AttendantNoPass
	msgbox GoldenrodMagnetTrainStation_Text_AttendantUnderConstruction, MSGBOX_DEFAULT
	release
	end

GoldenrodMagnetTrainStation_EventScript_AttendantNoPass::
	msgbox GoldenrodMagnetTrainStation_Text_AttendantNoPass, MSGBOX_DEFAULT
	release
	end

GoldenrodMagnetTrainStation_Text_AttendantNoPass:
	.string "This is the MAGNET TRAIN, express\n"
	.string "to SAFFRON CITY, over in KANTO.\p"
	.string "You'll need a MAGNET TRAIN PASS\n"
	.string "before we can let you aboard.$"

GoldenrodMagnetTrainStation_Text_AttendantUnderConstruction:
	.string "PASS in hand, I see -- but the\n"
	.string "line's still being laid on the\l"
	.string "SAFFRON end.\p"
	.string "KANTO's not ready to receive us\n"
	.string "yet. Hang tight.$"
