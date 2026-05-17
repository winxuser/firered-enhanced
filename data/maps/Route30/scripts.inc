Route30_MapScripts::
	.byte 0

Route30_EventScript_Mikey::
	trainerbattle_single TRAINER_YOUNGSTER_MIKEY, Route30_Text_MikeyIntro, Route30_Text_MikeyDefeat
	msgbox Route30_Text_MikeyPostBattle, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Don::
	trainerbattle_single TRAINER_BUG_CATCHER_DON, Route30_Text_DonIntro, Route30_Text_DonDefeat
	msgbox Route30_Text_DonPostBattle, MSGBOX_AUTOCLOSE
	end

Route30_Text_MikeyIntro:
	.string "My dad gave me some cool POKéMON\n"
	.string "from overseas to train with!\l"
	.string "Check this out!$"

Route30_Text_MikeyDefeat:
	.string "Aww! My team wasn't ready!$"

Route30_Text_MikeyPostBattle:
	.string "That black-furred puppy POKéMON is\n"
	.string "called POOCHYENA. It's originally\l"
	.string "from the HOENN region!$"

Route30_Text_DonIntro:
	.string "I'm looking for rare BUG POKéMON\n"
	.string "in these tall weeds!\l"
	.string "Let's have a quick battle!$"

Route30_Text_DonDefeat:
	.string "Argh! My bugs got squashed!$"

Route30_Text_DonPostBattle:
	.string "The tall grass on this route hides\n"
	.string "different bugs depending on whether\l"
	.string "it's morning or night!$"
