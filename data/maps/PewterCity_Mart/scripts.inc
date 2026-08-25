PewterCity_Mart_MapScripts::
	.byte 0

PewterCity_Mart_EventScript_Youngster::
	msgbox PewterCity_Mart_Text_Youngster, MSGBOX_NPC
	end

PewterCity_Mart_EventScript_Boy::
	msgbox PewterCity_Mart_Text_Boy, MSGBOX_NPC
	end

PewterCity_Mart_EventScript_Clerk::
	msgbox PewterCity_Mart_Text_Clerk, MSGBOX_NPC
	end

PewterCity_Mart_Text_Youngster:
	.string "A shady old guy sucked me into\nbuying this weird fish POKéMON!\pIt's totally weak and it cost ¥500!$"

PewterCity_Mart_Text_Boy:
	.string "Good things can happen if you raise\nPOKéMON diligently.\pEven the weak ones can surprise\nyou if you don't give up on them.$"

PewterCity_Mart_Text_Clerk:
	.string "Folks in KANTO don't get many\nvisitors from HOENN. Word is one\lof them cleaned up in JOHTO too.$"
