DanceTheater_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S5 -- THE ECRUTEAK DANCE THEATER.
@
@ FOUND M4a DEFECT, WORKED AROUND HERE AND ESCALATED FOR M6.
@ Tile row y=3 of this map is MB_JUMP_SOUTH across its ENTIRE width (metatiles
@ 690/691, all twelve columns). Ledges are one-way: a ledge may be hopped DOWN,
@ never walked up. The only landings are (1,4) and (10,4), because row 4 decodes
@ collision 1 everywhere else. Rows 1-3 -- the whole stage -- are therefore a
@ sealed island that the player can never set foot on:
@     walkable 137, reachable from the two door tiles 101,
@     grid rows 1..3 entirely unreachable.
@ All five KIMONO GIRLS are real wired trainers with sight radius 0, i.e.
@ talk-only, and they were standing on that island. Five trainer ids of dead
@ content. GSC's sight radius is 0 as well (DanceTheater.asm:284-288), so GSC
@ reaches them on foot; the two 2x2 stair blocks at (0..1,4..5) and (10..11,4..5)
@ are where GSC's stairs are, and the port mapped the stage-front block to a
@ ledge metatile instead of a walkable riser.
@ S5 fixes the SYMPTOM in map.json only -- the five girls now rehearse on the
@ theatre floor at (2,5)/(4,5)/(7,5)/(9,5)/(11,5), with (1,5) and (10,5) left
@ clear so the two stair stubs stay reachable. The LAYOUT bug
@ (data/layouts/DanceTheater_Johto/map.bin row 3) is an M6 port item: M4b has
@ never edited blockdata and a blind metatile substitution is a rendering gamble
@ with no play-test gate.
@ ============================================================================

DanceTheater_EventScript_NAOKO::
	trainerbattle_single TRAINER_JOHTO_KIMONO_GIRL_NAOKO, DanceTheater_Text_NAOKOSeen, DanceTheater_Text_NAOKOBeaten
	msgbox DanceTheater_Text_NAOKOAfterBattle, MSGBOX_AUTOCLOSE
	end

DanceTheater_EventScript_SAYO::
	trainerbattle_single TRAINER_JOHTO_KIMONO_GIRL_SAYO, DanceTheater_Text_SAYOSeen, DanceTheater_Text_SAYOBeaten
	msgbox DanceTheater_Text_SAYOAfterBattle, MSGBOX_AUTOCLOSE
	end

DanceTheater_EventScript_ZUKI::
	trainerbattle_single TRAINER_JOHTO_KIMONO_GIRL_ZUKI, DanceTheater_Text_ZUKISeen, DanceTheater_Text_ZUKIBeaten
	msgbox DanceTheater_Text_ZUKIAfterBattle, MSGBOX_AUTOCLOSE
	end

DanceTheater_EventScript_KUNI::
	trainerbattle_single TRAINER_JOHTO_KIMONO_GIRL_KUNI, DanceTheater_Text_KUNISeen, DanceTheater_Text_KUNIBeaten
	msgbox DanceTheater_Text_KUNIAfterBattle, MSGBOX_AUTOCLOSE
	end

DanceTheater_EventScript_MIKI::
	trainerbattle_single TRAINER_JOHTO_KIMONO_GIRL_MIKI, DanceTheater_Text_MIKISeen, DanceTheater_Text_MIKIBeaten
	msgbox DanceTheater_Text_MIKIAfterBattle, MSGBOX_AUTOCLOSE
	end

@ ============================================================================
@ GSC's DANCETHEATER_COOLTRAINER_M, promoted to a real fight
@ (TRAINER_JOHTO_COOLTRAINER_KENJI, id 1073). His roster is his own dialogue
@ made literal: GSC's line about the man who wants "a POKéMON that can SURF and
@ dance" becomes the team he built trying to keep up with the KIMONO GIRLS --
@ VAPOREON L63, LUDICOLO L62, BELLOSSOM L62.
@ G3: NO_MUSIC, because this is a talk-triggered battle and
@ PlayTrainerEncounterMusic is a full map-BGM swap, not a jingle.
@ (10,10) decodes collision 0 elevation 3 in the open lower hall; it is GSC's
@ own tile and it costs exactly one tile of reachability, its own.
@ ============================================================================
DanceTheater_EventScript_KENJI::
	trainerbattle_single TRAINER_JOHTO_COOLTRAINER_KENJI, DanceTheater_Text_KENJIIntro, DanceTheater_Text_KENJIDefeat, DanceTheater_EventScript_KENJIRematchTalk, NO_MUSIC
	goto DanceTheater_EventScript_KENJIRematchTalk
	end

DanceTheater_EventScript_KENJIRematchTalk::
	msgbox DanceTheater_Text_KENJIAfterBattle, MSGBOX_DEFAULT
	release
	end

@ GSC DanceTheaterRhydon. The theatre's own dialogue already refers to "that
@ man's RHYDON"; until now there was no RHYDON in the map for it to refer to.
DanceTheater_EventScript_Rhydon::
	lock
	msgbox DanceTheater_Text_Rhydon, MSGBOX_DEFAULT
	playmoncry SPECIES_RHYDON, CRY_MODE_NORMAL
	waitmoncry
	release
	end

DanceTheater_EventScript_SurfGuy::
	msgbox DanceTheater_Text_SurfGuy, MSGBOX_NPC
	end

DanceTheater_EventScript_Granny::
	msgbox DanceTheater_Text_Granny, MSGBOX_NPC
	end

@ (5,6) and (6,6) decode collision 1 -- the decorated panels behind the stage
@ floor, read facing north from (5,7)/(6,7). GSC's own bg_events.
DanceTheater_EventScript_FancyPanel::
	msgbox DanceTheater_Text_FancyPanel, MSGBOX_SIGN
	end

@ ============================================================================
@ Text
@ ============================================================================
DanceTheater_Text_NAOKOSeen:
	.string "You have lovely\nPOKéMON. May I see\lthem in battle?$"

DanceTheater_Text_NAOKOBeaten:
	.string "Oh, you are very\nstrong.$"

@ GSC KimonoGirlNaokoAfterBattleText.
DanceTheater_Text_NAOKOAfterBattle:
	.string "I enjoyed that bout. I would like to\n"
	.string "see you again.$"

DanceTheater_Text_SAYOSeen:
	.string "I always dance\nwith my POKéMON.\pOf course, I also\ntrain them.$"

DanceTheater_Text_SAYOBeaten:
	.string "Oh, so close!\nI almost had you.$"

@ GSC KimonoGirlSayoAfterBattleText.
DanceTheater_Text_SAYOAfterBattle:
	.string "Rhythm is important for both dancing\n"
	.string "and POKéMON.$"

DanceTheater_Text_ZUKISeen:
	.string "Isn't my barrette\npretty?\pOh. A POKéMON\nbattle?$"

DanceTheater_Text_ZUKIBeaten:
	.string "I don't have any\nPOKéMON left…$"

@ GSC KimonoGirlZukiAfterBattleText.
DanceTheater_Text_ZUKIAfterBattle:
	.string "I put a different flower in my\n"
	.string "barrette every month.$"

DanceTheater_Text_KUNISeen:
	.string "Oh, you're a cute\ntrainer. Would you\llike to battle?$"

DanceTheater_Text_KUNIBeaten:
	.string "You're stronger\nthan you look.$"

@ GSC KimonoGirlKuniAfterBattleText.
DanceTheater_Text_KUNIAfterBattle:
	.string "I trained a lot, so I thought I was\n"
	.string "a capable trainer.\p"
	.string "I suppose I am not.$"

DanceTheater_Text_MIKISeen:
	.string "Do you like my\ndancing? I'm good\lat POKéMON too.$"

DanceTheater_Text_MIKIBeaten:
	.string "Ooh, you're good\nat POKéMON too.$"

@ GSC KimonoGirlMikiAfterBattleText.
DanceTheater_Text_MIKIAfterBattle:
	.string "I can keep dancing because there are\n"
	.string "people who enjoy what I do.\p"
	.string "My POKéMON keep my spirits up too.$"

DanceTheater_Text_KENJIIntro:
	.string "KENJI: I come here every single day\n"
	.string "and I challenge all five of them,\l"
	.string "and I have never taken a round.\p"
	.string "Water that moves like water. A\n"
	.string "dancer. A flower that keeps time.\p"
	.string "That is what I have been building.\n"
	.string "Judge it for me, CHAMPION.$"

DanceTheater_Text_KENJIDefeat:
	.string "Ah. Beaten by someone who does not\n"
	.string "even live here.$"

DanceTheater_Text_KENJIAfterBattle:
	.string "KENJI: No, do not apologise. That is\n"
	.string "the closest I have come to the way\l"
	.string "the KIMONO GIRLS battle.\p"
	.string "Same time tomorrow. They will say no\n"
	.string "again, and I will ask again.$"

@ GSC RhydonText.
DanceTheater_Text_Rhydon:
	.string "RHYDON: Gugooh gugogooh!$"

@ Adapts GSC SurfGuyNeverLeftAScratchText. The HM03 SURF gift is dropped: the
@ Act II player already has SURF, so the beat is the man, not the item. Per the
@ "never presume novelty" rule the line makes no claim about the player's bag.
DanceTheater_Text_SurfGuy:
	.string "Not only are the KIMONO GIRLS great\n"
	.string "dancers, they're also skilled at\l"
	.string "POKéMON.\p"
	.string "I challenge them constantly. I have\n"
	.string "never even left a scratch.\p"
	.string "My RHYDON does not have the feet for\n"
	.string "it. I keep telling him. He keeps\l"
	.string "disagreeing.$"

DanceTheater_Text_Granny:
	.string "The KIMONO GIRLS\nare so beautiful…\pBut they have to\ngo through rigor-\lous training.\pAnd they have to\nlearn to follow\pcustoms before ap-\npearing in public.\pBut if you love\nsomething, any-\lthing is possible.$"

@ GSC DanceTheaterFancyPanelText.
DanceTheater_Text_FancyPanel:
	.string "It's a fancy panel that's decorated\n"
	.string "with flowers.$"
