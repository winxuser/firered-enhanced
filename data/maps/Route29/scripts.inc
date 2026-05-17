Route29_MapScripts::
	.byte 0

Route29_EventScript_ItemPotion::
	finditem ITEM_POTION
	end

Route29_EventScript_YoungsterJoey::
	trainerbattle_single TRAINER_YOUNGSTER_JOEY_2, Route29_Text_JoeyIntro, Route29_Text_JoeyDefeat
	msgbox Route29_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
	end

Route29_Text_JoeyIntro:
	.string "My RATTATA is different from regular\n"
	.string "RATTATA. It's like my RATTATA is\l"
	.string "in the top percentage of RATTATA!$"

Route29_Text_JoeyDefeat:
	.string "Urgh! Maybe my RATTATA isn't\n"
	.string "that high percentage...$"

Route29_Text_JoeyPostBattle:
	.string "I'm going to keep training until\n"
	.string "mine is the best in JOHTO!$"

Route29_EventScript_BugCatcherWade::
	trainerbattle_single TRAINER_BUG_CATCHER_WADE, Route29_Text_WadeIntro, Route29_Text_WadeDefeat
	msgbox Route29_Text_WadePostBattle, MSGBOX_AUTOCLOSE
	end

Route29_Text_WadeIntro:
	.string "I'm looking for bug POKéMON!\n"
	.string "Did you see any in the tall grass?$"

Route29_Text_WadeDefeat:
	.string "My bugs were squashed...$"

Route29_Text_WadePostBattle:
	.string "You can find different bugs depending\n"
	.string "on what time of day it is.$"
