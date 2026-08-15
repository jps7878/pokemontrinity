DanceTheater_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S5 -- THE ECRUTEAK DANCE THEATER.
@
@ FOUND M4a DEFECT, WORKED AROUND HERE AND ESCALATED FOR M6. THIS BLOCK IS THE
@ DOCUMENTATION OF RECORD FOR THAT LAYOUT FIX -- keep it true.
@ Tile row y=3 of this map is MB_JUMP_SOUTH across its ENTIRE width (metatiles
@ 690/691, all twelve columns). Ledges are one-way: a ledge may be hopped DOWN,
@ never walked up. The only landings are (1,4) and (10,4), because row 4 decodes
@ collision 1 everywhere else. Rows 1-3 -- the whole stage, 36 tiles -- are
@ therefore a sealed island the player can never set foot on. reach_check.py:
@     walkable 144, reachable with NO objects 108, with all 9 objects 99
@     (grid rows 1..3 entirely X; every object costs exactly its own tile)
@ All five KIMONO GIRLS are real wired trainers with sight radius 0, i.e.
@ talk-only, and they were standing on that island. Five trainer ids of dead
@ content. GSC's sight radius is 0 as well (DanceTheater.asm:284-288), so GSC
@ reaches them on foot; the two 2x2 stair blocks at (0..1,4..5) and (10..11,4..5)
@ are where GSC's stairs are, and the port mapped the stage-front block to a
@ ledge metatile instead of a walkable riser.
@
@ SYMPTOM FIX (map.json only): the five girls rehearse on the theatre floor at
@ (1,7) (3,7) (4,7) (8,7) (10,7).
@   Row 7 was chosen over the front row after reach_check REJECTED row 5: row 5's
@   only vertical links run through row 6, which is collision 1 at x=5,6 (the
@   decorated panels), so (5,5)/(6,5) hang off row 5 alone and any bracketing
@   pair traps them -- that attempt lost 4, 3, 2 and 2 tiles. Row 7 is fully open
@   x=0..11 and row 8 parallels it completely, so each girl costs one tile.
@   (1,5) and (10,5) are also left clear so the two stair stubs (1,4)/(10,4) stay
@   reachable.
@   ZUKI sits on (4,7), NOT (5,7): (5,7) is the ONLY tile from which the (5,6)
@   fancy panel can be read (BG_EVENT_PLAYER_FACING_NORTH onto a collision-1
@   tile), and a girl standing there made that bg_event dead. (6,7), the twin's
@   reading tile, is likewise kept clear. (4,7) decodes MB_NORMAL collision 0
@   elevation 3 and still costs one tile.
@ LAYOUT FIX (M6, NOT done here): restore GSC's two stair risers at (1,3)/(10,3)
@ in data/layouts/DanceTheater_Johto/map.bin, then restage the girls on the
@ stage. M4b has never edited blockdata and a blind metatile substitution is a
@ rendering gamble under a gate with no play-tests.
@
@ G3 applies to all six battles in this room: every one of them is TALK-
@ triggered (the girls' sight radius is 0, KENJI is TRAINER_TYPE_NONE), so each
@ passes NO_MUSIC -- PlayTrainerEncounterMusic is a full map-BGM swap, not a
@ jingle, and that swap belongs to a sight line, not a conversation.
@ ============================================================================

DanceTheater_EventScript_NAOKO::
	trainerbattle_single TRAINER_JOHTO_KIMONO_GIRL_NAOKO, DanceTheater_Text_NAOKOSeen, DanceTheater_Text_NAOKOBeaten, DanceTheater_EventScript_NAOKOAfterBattle, NO_MUSIC
	goto DanceTheater_EventScript_NAOKOAfterBattle
	end

DanceTheater_EventScript_NAOKOAfterBattle::
	msgbox DanceTheater_Text_NAOKOAfterBattle, MSGBOX_DEFAULT
	release
	end

DanceTheater_EventScript_SAYO::
	trainerbattle_single TRAINER_JOHTO_KIMONO_GIRL_SAYO, DanceTheater_Text_SAYOSeen, DanceTheater_Text_SAYOBeaten, DanceTheater_EventScript_SAYOAfterBattle, NO_MUSIC
	goto DanceTheater_EventScript_SAYOAfterBattle
	end

DanceTheater_EventScript_SAYOAfterBattle::
	msgbox DanceTheater_Text_SAYOAfterBattle, MSGBOX_DEFAULT
	release
	end

DanceTheater_EventScript_ZUKI::
	trainerbattle_single TRAINER_JOHTO_KIMONO_GIRL_ZUKI, DanceTheater_Text_ZUKISeen, DanceTheater_Text_ZUKIBeaten, DanceTheater_EventScript_ZUKIAfterBattle, NO_MUSIC
	goto DanceTheater_EventScript_ZUKIAfterBattle
	end

DanceTheater_EventScript_ZUKIAfterBattle::
	msgbox DanceTheater_Text_ZUKIAfterBattle, MSGBOX_DEFAULT
	release
	end

DanceTheater_EventScript_KUNI::
	trainerbattle_single TRAINER_JOHTO_KIMONO_GIRL_KUNI, DanceTheater_Text_KUNISeen, DanceTheater_Text_KUNIBeaten, DanceTheater_EventScript_KUNIAfterBattle, NO_MUSIC
	goto DanceTheater_EventScript_KUNIAfterBattle
	end

DanceTheater_EventScript_KUNIAfterBattle::
	msgbox DanceTheater_Text_KUNIAfterBattle, MSGBOX_DEFAULT
	release
	end

DanceTheater_EventScript_MIKI::
	trainerbattle_single TRAINER_JOHTO_KIMONO_GIRL_MIKI, DanceTheater_Text_MIKISeen, DanceTheater_Text_MIKIBeaten, DanceTheater_EventScript_MIKIAfterBattle, NO_MUSIC
	goto DanceTheater_EventScript_MIKIAfterBattle
	end

DanceTheater_EventScript_MIKIAfterBattle::
	msgbox DanceTheater_Text_MIKIAfterBattle, MSGBOX_DEFAULT
	release
	end

@ ============================================================================
@ GSC's DANCETHEATER_COOLTRAINER_M, promoted to a real fight
@ (TRAINER_JOHTO_COOLTRAINER_KENJI, id 1073).
@ CHARACTER SEPARATION, per GSC. GSC gives this room TWO men, and they are not
@ the same man: the GENTLEMAN is the one who challenges the KIMONO GIRLS daily
@ and has "never even left a scratch" (SurfGuyNeverLeftAScratchText), and the
@ COOLTRAINER M is the bystander who WATCHES him and comments -- "That man's
@ always with his RHYDON… says he wants a POKéMON that can SURF and dance"
@ (DanceTheaterCooltrainerMText). KENJI keeps that observer role: the daily
@ losing challenge belongs to the GENTLEMAN alone, and KENJI's angle is that he
@ went and actually BUILT the team the other man only talks about --
@ VAPOREON L63 (surfs), LUDICOLO L62 (dances), BELLOSSOM L62 (dances).
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

@ Adapts GSC DanceTheaterCooltrainerMText -- the observer's line about the
@ GENTLEMAN and his RHYDON, now with a challenge attached to it.
DanceTheater_Text_KENJIIntro:
	.string "KENJI: See that fellow with the\n"
	.string "RHYDON? He asks the KIMONO GIRLS\l"
	.string "for a bout every single day.\p"
	.string "Says he wants a POKéMON that can\n"
	.string "SURF and dance. Been saying it for\l"
	.string "years without raising one.\p"
	.string "So I raised them. Water that moves\n"
	.string "like water. A dancer. A flower that\l"
	.string "keeps time.\p"
	.string "He can keep asking them. I would\n"
	.string "rather be judged by a CHAMPION.$"

DanceTheater_Text_KENJIDefeat:
	.string "Ah. Beaten by someone who does not\n"
	.string "even live here.$"

DanceTheater_Text_KENJIAfterBattle:
	.string "KENJI: No, do not apologise. Nobody\n"
	.string "in this building has made me work\l"
	.string "that hard.\p"
	.string "I will tell him you said the RHYDON\n"
	.string "has no feet for it. He will disagree\l"
	.string "with you as well.$"

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
