GoldenrodFlowerShop_MapScripts::
	.byte 0

@ Trinity M4b S4. FLORIA added at (5,6) -- GSC's tile.
@ M4b S12 CORRECTION: this header previously read "HAND-OFF TO S5", claiming
@ FLORIA's dialogue promised a SQUIRTBOTTLE that wakes a SUDOWOODO blocking
@ ROUTE 36. No SUDOWOODO object was ever placed by S4 or any slice through
@ S11B -- that content is M6's, not M4b's. The final-review gate (S12) caught
@ the dangling promise (a road-tree the player can never find) and DE-PROMISED
@ the line below: FLORIA now frets about her shop and her watering can only,
@ with no claim about ROUTE 36. When M6 actually builds the SUDOWOODO/
@ SQUIRTBOTTLE puzzle, that slice owns rewriting her dialogue AND placing the
@ object together, in the same pass -- not before.
GoldenrodFlowerShop_EventScript_Floria::
	msgbox GoldenrodFlowerShop_Text_Floria, MSGBOX_NPC
	end

GoldenrodFlowerShop_EventScript_FlowerShopTeacher::
	msgbox GoldenrodFlowerShop_Text_FlowerShopTeacher, MSGBOX_NPC
	end

GoldenrodFlowerShop_Text_Floria:
	.string "FLORIA: Welcome to the FLOWER\n"
	.string "SHOP!\p"
	.string "I'm supposed to be watering\n"
	.string "the whole shop today, and I\l"
	.string "can't find our SQUIRTBOTTLE\l"
	.string "anywhere.\p"
	.string "Sister probably has it. Sister\n"
	.string "is out.\p"
	.string "So it's just me, some very\n"
	.string "thirsty flowers, and a lot of\l"
	.string "waiting.$"

GoldenrodFlowerShop_Text_FlowerShopTeacher:
	.string "Flowers do better in GOLDENROD\n"
	.string "than anywhere in JOHTO.\p"
	.string "All that city, all that noise,\n"
	.string "and things still insist on\l"
	.string "growing here.$"
