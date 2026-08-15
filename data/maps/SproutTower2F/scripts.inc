SproutTower2F_MapScripts::
	.byte 0

SproutTower2F_EventScript_NICO::
	trainerbattle_single TRAINER_JOHTO_SAGE_NICO, SproutTower2F_Text_NICOSeen, SproutTower2F_Text_NICOBeaten
	msgbox SproutTower2F_Text_NICOAfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower2F_EventScript_EDMOND::
	trainerbattle_single TRAINER_JOHTO_SAGE_EDMOND, SproutTower2F_Text_EDMONDSeen, SproutTower2F_Text_EDMONDBeaten
	msgbox SproutTower2F_Text_EDMONDAfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower2F_EventScript_Statue::
	msgbox SproutTower2F_Text_Statue, MSGBOX_SIGN
	end

SproutTower2F_Text_NICOSeen:
	.string "However hard we\nbattle, the TOWER\lwill stand strong.$"

SproutTower2F_Text_NICOBeaten:
	.string "I fought hard but\nI'm too weak.$"

@ GSC SageNicoAfterBattleText.
SproutTower2F_Text_NICOAfterBattle:
	.string "The flexible pillar protects the\n"
	.string "TOWER, even from earthquakes.$"

SproutTower2F_Text_EDMONDSeen:
	.string "…Sway like leaves\nin the wind…$"

SproutTower2F_Text_EDMONDBeaten:
	.string "Oh, I'm weak!$"

@ GSC SageEdmondAfterBattleText.
SproutTower2F_Text_EDMONDAfterBattle:
	.string "I tried to copy BELLSPROUT's\n"
	.string "gentle movements for battle…\p"
	.string "But I didn't train well enough.$"

SproutTower2F_Text_Statue:
	.string "A POKéMON statue…\pIt looks very\ndistinguished.$"
