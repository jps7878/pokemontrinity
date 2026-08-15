GoldenrodFlowerShop_MapScripts::
	.byte 0

@ Trinity M4b S4. FLORIA added at (5,6) -- GSC's tile.
@ HAND-OFF TO S5, deliberate: in GSC, FLORIA is the source of the SQUIRTBOTTLE
@ that wakes the SUDOWOODO blocking ROUTE 36. S5 owns SUDOWOODO and therefore
@ owns the item-versus-flag decision, so S4 seeds the hook as DIALOGUE ONLY --
@ she talks about the shop's watering can and the "tree" that will not move,
@ and hands over nothing. S5 rewrites this one script; the map data already
@ has the object, so no S4 file needs a second pass.
GoldenrodFlowerShop_EventScript_Floria::
	msgbox GoldenrodFlowerShop_Text_Floria, MSGBOX_NPC
	end

GoldenrodFlowerShop_EventScript_FlowerShopTeacher::
	msgbox GoldenrodFlowerShop_Text_FlowerShopTeacher, MSGBOX_NPC
	end

GoldenrodFlowerShop_Text_Floria:
	.string "FLORIA: Welcome to the FLOWER\n"
	.string "SHOP!\p"
	.string "…You've come up ROUTE 36,\n"
	.string "haven't you. Then you've seen\l"
	.string "the tree.\p"
	.string "The one standing in the middle\n"
	.string "of the road that isn't a tree.\p"
	.string "Everyone tries to move it.\n"
	.string "Nobody thinks to water it.\p"
	.string "Our SQUIRTBOTTLE would settle\n"
	.string "the question in about four\l"
	.string "seconds. Sister has it, and\l"
	.string "sister is out.$"

GoldenrodFlowerShop_Text_FlowerShopTeacher:
	.string "Flowers do better in GOLDENROD\n"
	.string "than anywhere in JOHTO.\p"
	.string "All that city, all that noise,\n"
	.string "and things still insist on\l"
	.string "growing here.$"
