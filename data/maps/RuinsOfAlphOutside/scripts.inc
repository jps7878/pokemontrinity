RuinsOfAlphOutside_MapScripts::
	.byte 0

RuinsOfAlphOutside_EventScript_NATHAN::
	trainerbattle_single TRAINER_JOHTO_PSYCHIC_T_NATHAN, RuinsOfAlphOutside_Text_NATHANSeen, RuinsOfAlphOutside_Text_NATHANBeaten
	msgbox RuinsOfAlphOutside_Text_NATHANBeaten, MSGBOX_AUTOCLOSE
	end

RuinsOfAlphOutside_EventScript_MysteryChamberSign::
	msgbox RuinsOfAlphOutside_Text_MysteryChamberSign, MSGBOX_SIGN
	end

RuinsOfAlphOutside_EventScript_RuinsOfAlphSign::
	msgbox RuinsOfAlphOutside_Text_RuinsOfAlphSign, MSGBOX_SIGN
	end

RuinsOfAlphOutside_EventScript_RuinsOfAlphResearchCenterSign::
	msgbox RuinsOfAlphOutside_Text_RuinsOfAlphResearchCenterSign, MSGBOX_SIGN
	end

RuinsOfAlphOutside_Text_NATHANSeen:
	.string "Hmmm… This is a\nstrange place.$"

RuinsOfAlphOutside_Text_NATHANBeaten:
	.string "…$"

RuinsOfAlphOutside_Text_MysteryChamberSign:
	.string "MYSTERY STONE\nPANEL CHAMBER$"

RuinsOfAlphOutside_Text_RuinsOfAlphSign:
	.string "RUINS OF ALPH\nVISITORS WELCOME$"

RuinsOfAlphOutside_Text_RuinsOfAlphResearchCenterSign:
	.string "RUINS OF ALPH\nRESEARCH CENTER\pTHE AUTHORITY ON\nTHE RUINS OF ALPH$"
