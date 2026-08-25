VermilionCity_House3_MapScripts::
	.byte 0

VermilionCity_House3_EventScript_Boy::
	msgbox VermilionCity_House3_Text_Boy, MSGBOX_NPC
	end

VermilionCity_House3_EventScript_Lass::
	msgbox VermilionCity_House3_Text_Lass, MSGBOX_NPC
	end

VermilionCity_House3_EventScript_Letter::
	msgbox VermilionCity_House3_Text_Letter, MSGBOX_SIGN
	end

VermilionCity_House3_Text_Boy:
	.string "I'm getting my PIDGEY to fly a\nletter to SAFFRON in the north.$"

VermilionCity_House3_Text_Lass:
	.string "I want to exchange MAIL with all\nsorts of people.\pI send my PIDGEY to a UNION ROOM\nto exchange MAIL for me.$"

VermilionCity_House3_Text_Letter:
	.string "Dear PIPPI,\nI hope to see you soon.\pI heard SAFFRON has problems with\nTEAM ROCKET.\pVERMILION appears to be safe.$"
