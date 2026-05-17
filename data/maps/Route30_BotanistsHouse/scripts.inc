Route30_BotanistsHouse_MapScripts::
	.byte 0

Route30_BotanistsHouse_EventScript_Botanist::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer

	@ Check if this is the first time meeting him
	goto_if_unset FLAG_RECEIVED_BOTANIST_BERRY, Route30_BotanistsHouse_EventScript_FirstMeet

	@ Read how many steps the player has taken since their last check-in
	copyvar VAR_TEMP_0, VAR_HAPPINESS_STEP_COUNTER

	@ Deduct those steps from our remaining target
	goto_if_ge VAR_TEMP_0, VAR_BOTANIST_STEP_TARGET, Route30_BotanistsHouse_EventScript_PlantsRegrown

	@ Subtract the steps taken from the target milestone
	subvar VAR_BOTANIST_STEP_TARGET, VAR_TEMP_0

	@ Reset the happiness step counter tracker so we start fresh from 0
	setvar VAR_HAPPINESS_STEP_COUNTER, 0

	@ Display how many steps are still remaining
	buffernumberstring STR_VAR_1, VAR_BOTANIST_STEP_TARGET
	msgbox Route30_BotanistsHouse_Text_StillGrowing
	release
	end

Route30_BotanistsHouse_EventScript_FirstMeet::
	msgbox Route30_BotanistsHouse_Text_MeetBotanist
	setflag FLAG_RECEIVED_BOTANIST_BERRY
	goto Route30_BotanistsHouse_EventScript_GiveBerry
	end

Route30_BotanistsHouse_EventScript_PlantsRegrown::
	msgbox Route30_BotanistsHouse_Text_NewHarvestReady
	goto Route30_BotanistsHouse_EventScript_GiveBerry
	end

Route30_BotanistsHouse_EventScript_GiveBerry::
	random 3
	goto_if_eq VAR_RESULT, 0, Route30_BotanistsHouse_EventScript_GiveCheri
	goto_if_eq VAR_RESULT, 1, Route30_BotanistsHouse_EventScript_GiveChesto
	goto_if_eq VAR_RESULT, 2, Route30_BotanistsHouse_EventScript_GivePecha
	end

Route30_BotanistsHouse_EventScript_GiveCheri::
	giveitem ITEM_CHERI_BERRY, 1
	goto Route30_BotanistsHouse_EventScript_ResetCounter
	end

Route30_BotanistsHouse_EventScript_GiveChesto::
	giveitem ITEM_CHESTO_BERRY, 1
	goto Route30_BotanistsHouse_EventScript_ResetCounter
	end

Route30_BotanistsHouse_EventScript_GivePecha::
	giveitem ITEM_PECHA_BERRY, 1
	goto Route30_BotanistsHouse_EventScript_ResetCounter
	end

Route30_BotanistsHouse_EventScript_ResetCounter::
	@ Set the next harvest goal to require 1000 steps
	setvar VAR_BOTANIST_STEP_TARGET, 1000
	setvar VAR_HAPPINESS_STEP_COUNTER, 0

	msgbox Route30_BotanistsHouse_Text_ExplainBerries
	release
	end

Route30_BotanistsHouse_Text_MeetBotanist:
	.string "Hello there, young traveler!\n"
	.string "Welcome to my JOHTO GREENHOUSE.\p"
	.string "Since we don't have BERRY TREES growing\n"
	.string "wild on the routes anymore, I cultivate\l"
	.string "them right here in these pots!\p"
	.string "Here, take one of my fresh harvests!$"

Route30_BotanistsHouse_Text_NewHarvestReady:
	.string "Ah, perfect timing! My potted plants\n"
	.string "have sprouted a brand new batch of\l"
	.string "fresh BERRIES. Here you go!$"

Route30_BotanistsHouse_Text_StillGrowing:
	.string "My plants are still growing safely\n"
	.string "in their pots.\p"
	.string "It looks like they need about {STR_VAR_1}\n"
	.string "more steps before they are fully ripe!$"

Route30_BotanistsHouse_Text_ExplainBerries:
.string "If you give a BERRY to a POKéMON to\n"
.string "hold, they can heal themselves right\l"
.string "in the middle of a battle!$"
