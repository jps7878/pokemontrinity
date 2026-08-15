OlivineLighthouse2F_MapScripts::
	.byte 0

OlivineLighthouse2F_EventScript_HUEY1::
	trainerbattle_single TRAINER_JOHTO_SAILOR_HUEY1, OlivineLighthouse2F_Text_HUEY1Seen, OlivineLighthouse2F_Text_HUEY1Beaten
	msgbox OlivineLighthouse2F_Text_HUEY1Beaten, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse2F_EventScript_ALFRED::
	trainerbattle_single TRAINER_JOHTO_GENTLEMAN_ALFRED, OlivineLighthouse2F_Text_ALFREDSeen, OlivineLighthouse2F_Text_ALFREDBeaten
	msgbox OlivineLighthouse2F_Text_ALFREDBeaten, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse2F_Text_HUEY1Seen:
	.string "Men of the sea are\nalways spoiling\lfor a good fight!$"

OlivineLighthouse2F_Text_HUEY1Beaten:
	.string "Urf!\nI lose!$"

OlivineLighthouse2F_Text_ALFREDSeen:
	.string "Hm? This is no\nplace for playing.$"

OlivineLighthouse2F_Text_ALFREDBeaten:
	.string "Ah! I can see that\nyou're serious.$"
