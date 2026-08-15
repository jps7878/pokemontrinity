GoldenrodUndergroundSwitchRoomEntrances_MapScripts::
	.byte 0

GoldenrodUndergroundSwitchRoomEntrances_EventScript_Teacher::
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_Teacher, MSGBOX_NPC
	end

GoldenrodUndergroundSwitchRoomEntrances_EventScript_SuperNerd::
	msgbox GoldenrodUndergroundSwitchRoomEntrances_Text_SuperNerd, MSGBOX_NPC
	end

GoldenrodUndergroundSwitchRoomEntrances_Text_Teacher:
	.string "There are some\nshops downstairs…\pBut there are\nalso trainers.\pI'm scared to go\ndown there.$"

GoldenrodUndergroundSwitchRoomEntrances_Text_SuperNerd:
	.string "I was challenged\nto a battle down-\lstairs.\pIt's rough down\nthere. You'd\lbetter be careful.$"
