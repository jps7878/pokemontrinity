DanceTheater_MapScripts::
	.byte 0

DanceTheater_EventScript_NAOKO::
	trainerbattle_single TRAINER_JOHTO_KIMONO_GIRL_NAOKO, DanceTheater_Text_NAOKOSeen, DanceTheater_Text_NAOKOBeaten
	msgbox DanceTheater_Text_NAOKOBeaten, MSGBOX_AUTOCLOSE
	end

DanceTheater_EventScript_SAYO::
	trainerbattle_single TRAINER_JOHTO_KIMONO_GIRL_SAYO, DanceTheater_Text_SAYOSeen, DanceTheater_Text_SAYOBeaten
	msgbox DanceTheater_Text_SAYOBeaten, MSGBOX_AUTOCLOSE
	end

DanceTheater_EventScript_ZUKI::
	trainerbattle_single TRAINER_JOHTO_KIMONO_GIRL_ZUKI, DanceTheater_Text_ZUKISeen, DanceTheater_Text_ZUKIBeaten
	msgbox DanceTheater_Text_ZUKIBeaten, MSGBOX_AUTOCLOSE
	end

DanceTheater_EventScript_KUNI::
	trainerbattle_single TRAINER_JOHTO_KIMONO_GIRL_KUNI, DanceTheater_Text_KUNISeen, DanceTheater_Text_KUNIBeaten
	msgbox DanceTheater_Text_KUNIBeaten, MSGBOX_AUTOCLOSE
	end

DanceTheater_EventScript_MIKI::
	trainerbattle_single TRAINER_JOHTO_KIMONO_GIRL_MIKI, DanceTheater_Text_MIKISeen, DanceTheater_Text_MIKIBeaten
	msgbox DanceTheater_Text_MIKIBeaten, MSGBOX_AUTOCLOSE
	end

DanceTheater_EventScript_SurfGuy::
	msgbox DanceTheater_Text_SurfGuy, MSGBOX_NPC
	end

DanceTheater_EventScript_CooltrainerM::
	msgbox DanceTheater_Text_CooltrainerM, MSGBOX_NPC
	end

DanceTheater_EventScript_Granny::
	msgbox DanceTheater_Text_Granny, MSGBOX_NPC
	end

DanceTheater_Text_NAOKOSeen:
	.string "You have lovely\nPOKéMON. May I see\lthem in battle?$"

DanceTheater_Text_NAOKOBeaten:
	.string "Oh, you are very\nstrong.$"

DanceTheater_Text_SAYOSeen:
	.string "I always dance\nwith my POKéMON.\pOf course, I also\ntrain them.$"

DanceTheater_Text_SAYOBeaten:
	.string "Oh, so close!\nI almost had you.$"

DanceTheater_Text_ZUKISeen:
	.string "Isn't my barrette\npretty?\pOh. A POKéMON\nbattle?$"

DanceTheater_Text_ZUKIBeaten:
	.string "I don't have any\nPOKéMON left…$"

DanceTheater_Text_KUNISeen:
	.string "Oh, you're a cute\ntrainer. Would you\llike to battle?$"

DanceTheater_Text_KUNIBeaten:
	.string "You're stronger\nthan you look.$"

DanceTheater_Text_MIKISeen:
	.string "Do you like my\ndancing? I'm good\lat POKéMON too.$"

DanceTheater_Text_MIKIBeaten:
	.string "Ooh, you're good\nat POKéMON too.$"

DanceTheater_Text_SurfGuy:
	.string "The old timers say JOHTO used to\nfeel far from everywhere. Not\lanymore, with HOENN so close now.$"

DanceTheater_Text_CooltrainerM:
	.string "That man's always\nwith his RHYDON.\pSays he wants a\nPOKéMON that can\lSURF and dance.\pIs he trying to\nmake a synchro-\lnized swimming\lPOKéMON?$"

DanceTheater_Text_Granny:
	.string "The KIMONO GIRLS\nare so beautiful…\pBut they have to\ngo through rigor-\lous training.\pAnd they have to\nlearn to follow\pcustoms before ap-\npearing in public.\pBut if you love\nsomething, any-\lthing is possible.$"
