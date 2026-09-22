@ M7b T17.1: trainer intro/defeat/post-battle text ported verbatim from
@ pokefirered by tools/kanto_port/port_frlg_text.py (mapping key: this
@ map's <Map>_EventScript_<Name> == FRLG's <Map>_EventScript_<Name>).
@ EXCEPT 10 string(s) on this map, which are hand-authored overlays
@ declared in tools/kanto_port/frlg_text_overrides.json -- the cold
@ KANTO voice of finding #14.  `--verify` checks those against the
@ manifest instead of against pokefirered.
@ Levels, parties, trainer ids and battle kinds are untouched.
@ Re-verify with `port_frlg_text.py trainers --verify`.

Route11_MapScripts::
	.byte 0

Route11_EventScript_Eddie::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_EDDIE, Route11_Text_EddieSeen, Route11_Text_EddieBeaten
	msgbox Route11_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Hugo::
	trainerbattle_single TRAINER_KANTO_GAMER_HUGO, Route11_Text_HugoSeen, Route11_Text_HugoBeaten
	msgbox Route11_Text_HugoPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Dillon::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_DILLON, Route11_Text_DillonSeen, Route11_Text_DillonBeaten
	msgbox Route11_Text_DillonPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Dave::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_DAVE, Route11_Text_DaveSeen, Route11_Text_DaveBeaten
	msgbox Route11_Text_DavePostBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Jasper::
	trainerbattle_single TRAINER_KANTO_GAMER_JASPER, Route11_Text_JasperSeen, Route11_Text_JasperBeaten
	msgbox Route11_Text_JasperPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Darian::
	trainerbattle_single TRAINER_KANTO_GAMER_DARIAN, Route11_Text_DarianSeen, Route11_Text_DarianBeaten
	msgbox Route11_Text_DarianPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Braxton::
	trainerbattle_single TRAINER_KANTO_ENGINEER_BRAXTON, Route11_Text_BraxtonSeen, Route11_Text_BraxtonBeaten
	msgbox Route11_Text_BraxtonPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Yasu::
	trainerbattle_single TRAINER_KANTO_YOUNGSTER_YASU, Route11_Text_YasuSeen, Route11_Text_YasuBeaten
	msgbox Route11_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Dirk::
	trainerbattle_single TRAINER_KANTO_GAMER_DIRK, Route11_Text_DirkSeen, Route11_Text_DirkBeaten
	msgbox Route11_Text_DirkPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_Bernie::
	trainerbattle_single TRAINER_KANTO_ENGINEER_BERNIE, Route11_Text_BernieSeen, Route11_Text_BernieBeaten
	msgbox Route11_Text_BerniePostBattle, MSGBOX_AUTOCLOSE
	end

Route11_EventScript_DiglettsCaveSign::
	msgbox Route11_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

Route11_Text_EddieSeen:
	.string "You're the HOENN one.\nWalk on, then.$"

Route11_Text_EddieBeaten:
	.string "Huh?\nThat's not right!$"

Route11_Text_EddiePostBattle:
	.string "I did my best.\nI have no regrets.$"

Route11_Text_HugoSeen:
	.string "Two Leagues, off somewhere\nelse. ROUTE 11 doesn't\lcount them.$"

Route11_Text_HugoBeaten:
	.string "Atcha!\nDidn't go my way!$"

Route11_Text_HugoPostBattle:
	.string "POKéMON is life!\nAnd to live is to play games!$"

Route11_Text_DillonSeen:
	.string "Heard about you in VERMILION.\nWasn't impressed there either.$"

Route11_Text_DillonBeaten:
	.string "My POKéMON couldn't win…\nHaven't they grown enough?$"

Route11_Text_DillonPostBattle:
	.string "What now?\nLeave me alone!$"

Route11_Text_DaveSeen:
	.string "ROUTE 11 is where I battle.\nYour record stays outside.$"

Route11_Text_DaveBeaten:
	.string "Bye-bye!\nThank you, and good-bye!$"

Route11_Text_DavePostBattle:
	.string "Tch…\nI better go find stronger ones!$"

Route11_Text_JasperSeen:
	.string "I count wins, not titles.\nShow me a win.$"

Route11_Text_JasperBeaten:
	.string "I had a chance!$"

Route11_Text_JasperPostBattle:
	.string "You can't be a coward in the world\nof POKéMON!$"

Route11_Text_DarianSeen:
	.string "A champion, out here. Fine.\nLet's see you play it out.$"

Route11_Text_DarianBeaten:
	.string "I saw this coming…$"

Route11_Text_DarianPostBattle:
	.string "I was unlucky, as always.$"

Route11_Text_BraxtonSeen:
	.string "Mind the cables.\nThey don't care whose\lrecord it is.$"

Route11_Text_BraxtonBeaten:
	.string "That was electric!$"

Route11_Text_BraxtonPostBattle:
	.string "Spread the word to save energy!$"

Route11_Text_YasuSeen:
	.string "My brother says you're good.\nMy brother says a lot.$"

Route11_Text_YasuBeaten:
	.string "Darn!\nMy POKéMON need to be stronger!$"

Route11_Text_YasuPostBattle:
	.string "There's a fat POKéMON that comes\ndown from the mountains.\pI bet it'd be strong if you can\ncatch it.$"

Route11_Text_DirkSeen:
	.string "KANTO keeps its own scores.\nYours isn't on the board.$"

Route11_Text_DirkBeaten:
	.string "My first loss!$"

Route11_Text_DirkPostBattle:
	.string "You were just lucky, that's all.$"

Route11_Text_BernieSeen:
	.string "DIGLETT'S CAVE is ahead.\nSo am I. In that order.$"

Route11_Text_BernieBeaten:
	.string "Whoa!\nYou spark plug!$"

Route11_Text_BerniePostBattle:
	.string "Well, better get back to work.$"

Route11_Text_DiglettsCaveSign:
	.string "DIGLETT'S CAVE$"
