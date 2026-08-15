EarlsPokemonAcademy_MapScripts::
	.byte 0

@ ============================================================================
@ Trinity M4b S2 -- EARL, the academy's only story object in the M4b inventory
@ (SPRITE_FISHER at (4,2), EVENT_EARLS_ACADEMY_EARL). Adapts pokecrystal
@ AcademyEarl: his broken word order is the character, so it is kept, and GSC's
@ two-question teaching tree collapses to one MSGBOX_YESNO gate.
@ Skipped from the GSC room, with reasons: AcademyEarlSpinMovement (cosmetic --
@ MOVEMENT_TYPE_LOOK_AROUND is the port's own mapping for GSC's
@ SPRITEMOVEDATA_SPINRANDOM_SLOW and needs no LOCALID or movement script), the
@ two GAMEBOY_KIDs (SPRITE_GAMEBOY_KID has no SPRITE_MAP entry -- link-cable
@ flavor with no Trinity analogue), and AcademyNotebook (SPRITE_POKEDEX at
@ (2,4), which decodes collision-1 in the ported layout -- nothing can stand
@ there).
@ (4,2) decodes collision-0 elevation-3 MB_NORMAL. He seals nothing: row 2 is
@ open at x=0..2 and x=4..7, and (4,1) stays reachable via (5,1) from (5,2).
@ ============================================================================
EarlsPokemonAcademy_EventScript_Earl::
	lock
	faceplayer
	msgbox EarlsPokemonAcademy_Text_EarlIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EarlsPokemonAcademy_EventScript_EarlDone
	msgbox EarlsPokemonAcademy_Text_EarlLesson, MSGBOX_DEFAULT
	release
	end

EarlsPokemonAcademy_EventScript_EarlDone::
	msgbox EarlsPokemonAcademy_Text_EarlNoMoreToTeach, MSGBOX_DEFAULT
	release
	end

EarlsPokemonAcademy_EventScript_Youngster1::
	msgbox EarlsPokemonAcademy_Text_Youngster1, MSGBOX_NPC
	end

EarlsPokemonAcademy_EventScript_Youngster2::
	msgbox EarlsPokemonAcademy_Text_Youngster2, MSGBOX_NPC
	end

@ (3,0) and (4,0) decode collision-1 -- the blackboard wall, read facing north
@ from (3,1)/(4,1). GSC's 5-way _2dmenu (PSN/PAR/SLP/BRN/FRZ sub-pages) has no
@ clean Emerald script equivalent and is tutorial material an L58+ CHAMPION
@ does not need, so it collapses to one summary. The two BOOKSHELF tiles at
@ (0,1)/(1,1) get NO bg_event on purpose: they decode MB_BOOKSHELF, which the
@ engine already handles unconditionally (src/field_control_avatar.c:491 ->
@ EventScript_BookShelf), and a bg_event would override working behavior.
EarlsPokemonAcademy_EventScript_Blackboard::
	msgbox EarlsPokemonAcademy_Text_Blackboard, MSGBOX_SIGN
	end

@ ============================================================================
@ Text
@ ============================================================================
@ GSC AcademyEarlIntroText.
EarlsPokemonAcademy_Text_EarlIntro:
	.string "EARL, I am!\p"
	.string "Wonderful are POKéMON, yes!\p"
	.string "Teach you I will, to be a better\n"
	.string "trainer!\p"
	.string "…Hmm. Badges you have. Many\n"
	.string "badges. From far away.\p"
	.string "Teach you anyway, should I?$"

@ GSC AcademyEarlTeachHowToWinText + AcademyEarlTeachHowToRaiseWellText,
@ compressed into the one lesson the tree actually delivers.
EarlsPokemonAcademy_Text_EarlLesson:
	.string "Good! Teach you, I will!\p"
	.string "In battle, POKéMON top of list\n"
	.string "jumps out first!\p"
	.string "Put weak POKéMON at top. Switch\n"
	.string "out quick, quick!\p"
	.string "Even short time in battle, EXP.\n"
	.string "Points it gets.\p"
	.string "This way, weak POKéMON strong\n"
	.string "become!\p"
	.string "…This you knew already, yes.\n"
	.string "Nod politely you did. Kind, that\l"
	.string "is.$"

@ GSC AcademyEarlNoMoreToTeachText.
EarlsPokemonAcademy_Text_EarlNoMoreToTeach:
	.string "Oh! Smart student you are!\n"
	.string "Nothing more do I teach!\p"
	.string "Good to POKéMON you must be!$"

EarlsPokemonAcademy_Text_Youngster1:
	.string "I'm taking notes\nof the teacher's\llecture.\pI'd better copy\nthe stuff on the\lblackboard too.$"

EarlsPokemonAcademy_Text_Youngster2:
	.string "A POKéMON holding\na BERRY will heal\litself in battle.\pMany other items\ncan be held by\lPOKéMON…\pIt sure is tough\ntaking notes…$"

@ Adapts AcademyBlackboardText + a one-line summary of the five sub-pages the
@ GSC menu used to hold.
EarlsPokemonAcademy_Text_Blackboard:
	.string "The blackboard describes POKéMON\n"
	.string "status changes in battle.\p"
	.string "PSN drains HP as you walk --\n"
	.string "cure it with an ANTIDOTE.\p"
	.string "PAR halves SPEED and may lock a\n"
	.string "turn. SLP and FRZ stop a POKéMON\l"
	.string "outright.\p"
	.string "BRN drains HP and softens\n"
	.string "physical attacks.\p"
	.string "A FULL HEAL clears any of them.$"
