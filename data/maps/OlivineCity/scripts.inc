OlivineCity_MapScripts::
	.byte 0

OlivineCity_EventScript_Sailor1::
	msgbox OlivineCity_Text_Sailor1, MSGBOX_NPC
	end

@ Trinity M4b S6: this NPC carried one of M4a's five rotating "the HOENN
@ champion" filler strings. He now carries the chapter's hook -- the GYM is open
@ but empty until the SECRETPOTION reaches the LIGHTHOUSE. Read-only on
@ FLAG_TRINITY_J_AMPHY_CURED; the OLIVINE GYM greeter says the same thing from
@ inside, so a player who walks straight into the gym is not relying on this.
OlivineCity_EventScript_StandingYoungster::
	lock
	faceplayer
	goto_if_set FLAG_TRINITY_J_AMPHY_CURED, OlivineCity_EventScript_StandingYoungsterCured
	msgbox OlivineCity_Text_StandingYoungster, MSGBOX_DEFAULT
	release
	end

OlivineCity_EventScript_StandingYoungsterCured::
	msgbox OlivineCity_Text_StandingYoungsterCured, MSGBOX_DEFAULT
	release
	end

OlivineCity_EventScript_Sailor2::
	msgbox OlivineCity_Text_Sailor2, MSGBOX_NPC
	end

OlivineCity_EventScript_Sign::
	msgbox OlivineCity_Text_Sign, MSGBOX_SIGN
	end

OlivineCity_EventScript_PortSign::
	msgbox OlivineCity_Text_PortSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_OlivineGymSign::
	msgbox OlivineCity_Text_OlivineGymSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_OlivineLighthouseSign::
	msgbox OlivineCity_Text_OlivineLighthouseSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_BattleTowerSign::
	msgbox OlivineCity_Text_BattleTowerSign, MSGBOX_SIGN
	end

OlivineCity_Text_Sailor1:
	.string "Dark roads are\ndangerous at\lnight.\pBut in the pitch-\nblack of night,\pthe sea is even\nmore treacherous!\pWithout the beacon\nof the LIGHTHOUSE\pto guide it, no\nship can sail.$"

OlivineCity_Text_StandingYoungster:
	.string "Looking for the GYM? It's open, but\n"
	.string "don't get your hopes up.\p"
	.string "JASMINE hasn't been down from the\n"
	.string "LIGHTHOUSE in weeks. There's a\l"
	.string "POKéMON up there that's sick, and\l"
	.string "she won't leave it.\p"
	.string "The big lamp's been dark the whole\n"
	.string "time. My dad won't sail at night.$"

OlivineCity_Text_StandingYoungsterCured:
	.string "The lamp's lit! Did you see it come\n"
	.string "on? The whole harbour saw it.\p"
	.string "JASMINE walked back down to the GYM\n"
	.string "the same evening.\p"
	.string "She'll be in a mood to battle now.$"

OlivineCity_Text_Sailor2:
	.string "The sea is sweet!\pSunsets on the sea\nare marvelous!\pSing with me! \nYo-ho! Blow the\lman down!…$"

OlivineCity_Text_Sign:
	.string "OLIVINE CITY\pThe Port Closest\nto Foreign Lands$"

OlivineCity_Text_PortSign:
	.string "OLIVINE PORT\nFAST SHIP PIER$"

OlivineCity_Text_OlivineGymSign:
	.string "OLIVINE CITY\nPOKéMON GYM\lLEADER: JASMINE\pThe Steel-Clad\nDefense Girl$"

OlivineCity_Text_OlivineLighthouseSign:
	.string "OLIVINE LIGHTHOUSE\nAlso known as the\lGLITTER LIGHTHOUSE$"

OlivineCity_Text_BattleTowerSign:
	.string "BATTLE TOWER AHEAD\nOpening Now!$"
