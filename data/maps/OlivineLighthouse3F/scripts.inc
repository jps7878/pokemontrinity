OlivineLighthouse3F_MapScripts::
	.byte 0

OlivineLighthouse3F_EventScript_TERRELL::
	trainerbattle_single TRAINER_JOHTO_SAILOR_TERRELL, OlivineLighthouse3F_Text_TERRELLSeen, OlivineLighthouse3F_Text_TERRELLBeaten
	msgbox OlivineLighthouse3F_Text_TERRELLBeaten, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse3F_EventScript_PRESTON::
	trainerbattle_single TRAINER_JOHTO_GENTLEMAN_PRESTON, OlivineLighthouse3F_Text_PRESTONSeen, OlivineLighthouse3F_Text_PRESTONBeaten
	msgbox OlivineLighthouse3F_Text_PRESTONBeaten, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse3F_EventScript_THEO::
	trainerbattle_single TRAINER_JOHTO_BIRD_KEEPER_THEO, OlivineLighthouse3F_Text_THEOSeen, OlivineLighthouse3F_Text_THEOBeaten
	msgbox OlivineLighthouse3F_Text_THEOBeaten, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse3F_Text_TERRELLSeen:
	.string "Sailors are both\nkind and strong.\lHow about you?$"

OlivineLighthouse3F_Text_TERRELLBeaten:
	.string "You are both kind\nand strong…$"

OlivineLighthouse3F_Text_PRESTONSeen:
	.string "I travel the world\nto train my POKé-\lMON. I wish to\lbattle with you.$"

OlivineLighthouse3F_Text_PRESTONBeaten:
	.string "…sigh… I must\ntrain some more…$"

OlivineLighthouse3F_Text_THEOSeen:
	.string "Why are you here?\nAre you just going\pto gawk? I suggest\nthat you leave!$"

OlivineLighthouse3F_Text_THEOBeaten:
	.string "You really are\nconcerned…$"
