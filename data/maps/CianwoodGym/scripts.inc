CianwoodGym_MapScripts::
	.byte 0

CianwoodGym_EventScript_YOSHI::
	trainerbattle_single TRAINER_JOHTO_BLACKBELT_T_YOSHI, CianwoodGym_Text_YOSHISeen, CianwoodGym_Text_YOSHIBeaten
	msgbox CianwoodGym_Text_YOSHIBeaten, MSGBOX_AUTOCLOSE
	end

CianwoodGym_EventScript_LAO::
	trainerbattle_single TRAINER_JOHTO_BLACKBELT_T_LAO, CianwoodGym_Text_LAOSeen, CianwoodGym_Text_LAOBeaten
	msgbox CianwoodGym_Text_LAOBeaten, MSGBOX_AUTOCLOSE
	end

CianwoodGym_EventScript_NOB::
	trainerbattle_single TRAINER_JOHTO_BLACKBELT_T_NOB, CianwoodGym_Text_NOBSeen, CianwoodGym_Text_NOBBeaten
	msgbox CianwoodGym_Text_NOBBeaten, MSGBOX_AUTOCLOSE
	end

CianwoodGym_EventScript_LUNG::
	trainerbattle_single TRAINER_JOHTO_BLACKBELT_T_LUNG, CianwoodGym_Text_LUNGSeen, CianwoodGym_Text_LUNGBeaten
	msgbox CianwoodGym_Text_LUNGBeaten, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_YOSHISeen:
	.string "My POKéMON and I\nare bound togeth-\ler by friendship.\pOur bond will\nnever be broken!$"

CianwoodGym_Text_YOSHIBeaten:
	.string "This isn't real!$"

CianwoodGym_Text_LAOSeen:
	.string "We martial artists\nfear nothing!$"

CianwoodGym_Text_LAOBeaten:
	.string "That's shocking!$"

CianwoodGym_Text_NOBSeen:
	.string "Words are useless.\nLet your fists do\lthe talking!$"

CianwoodGym_Text_NOBBeaten:
	.string "…$"

CianwoodGym_Text_LUNGSeen:
	.string "My raging fists\nwill shatter your\lPOKéMON!$"

CianwoodGym_Text_LUNGBeaten:
	.string "I got shattered!$"
