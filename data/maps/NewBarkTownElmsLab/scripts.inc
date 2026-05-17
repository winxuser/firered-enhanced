NewBarkTownElmsLab_MapScripts::
	.byte 0

NewBarkTown_NPC_Script::
	lock
	faceplayer
	compare VAR_JOHTO_STATE, 5
	goto_if_eq Johto_Event_Finished
	msgbox Text_WelcomeToJohto, MSGBOX_DEFAULT
	setvar VAR_JOHTO_STATE, 1
	release
	end

NewBarkTown_ElmsLab_EventScript_Elm::
	lock
	faceplayer
	checkflag FLAG_GOT_JOHTO_STARTER
	goto_if_set FLAG_GOT_JOHTO_STARTER, NewBarkTown_ElmsLab_EventScript_ElmPostChoice @ Add comma
	msgbox NewBarkTown_ElmsLab_Text_ElmPickAMon, MSGBOX_DEFAULT
	release
	end

NewBarkTown_ElmsLab_EventScript_ElmPostChoice::
	msgbox NewBarkTown_ElmsLab_Text_ElmHowIsStarter, MSGBOX_DEFAULT
	release
	end

@ --- Starter Poké Ball Interaction Scripts ---

NewBarkTown_ElmsLab_EventScript_CyndaquilBall::
	lock
	faceplayer
	checkflag FLAG_GOT_JOHTO_STARTER
	goto_if_set FLAG_GOT_JOHTO_STARTER, NewBarkTown_ElmsLab_EventScript_AlreadyPicked
	goto_if_unset FLAG_ACCEPTED_JOHTO_JOURNEY, NewBarkTown_ElmsLab_EventScript_DontTouchBalls
	showmonpic SPECIES_CYNDAQUIL, 10, 3
	msgbox NewBarkTown_ElmsLab_Text_TakeCyndaquil, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_ElmsLab_EventScript_GiveCyndaquil
	hidemonpic
	release
	end

NewBarkTown_ElmsLab_EventScript_TotodileBall::
	lock
	faceplayer
	checkflag FLAG_GOT_JOHTO_STARTER
	goto_if_set FLAG_GOT_JOHTO_STARTER, NewBarkTown_ElmsLab_EventScript_AlreadyPicked
	goto_if_unset FLAG_ACCEPTED_JOHTO_JOURNEY, NewBarkTown_ElmsLab_EventScript_DontTouchBalls
	showmonpic SPECIES_TOTODILE, 10, 3
	msgbox NewBarkTown_ElmsLab_Text_TakeTotodile, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_ElmsLab_EventScript_GiveTotodile
	hidemonpic
	release
	end

NewBarkTown_ElmsLab_EventScript_ChikoritaBall::
	lock
	faceplayer
	checkflag FLAG_GOT_JOHTO_STARTER
	goto_if_set FLAG_GOT_JOHTO_STARTER, NewBarkTown_ElmsLab_EventScript_AlreadyPicked
	goto_if_unset FLAG_ACCEPTED_JOHTO_JOURNEY, NewBarkTown_ElmsLab_EventScript_DontTouchBalls
	showmonpic SPECIES_CHIKORITA, 10, 3
	msgbox NewBarkTown_ElmsLab_Text_TakeChikorita, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_ElmsLab_EventScript_GiveChikorita
	hidemonpic
	release
	end

	@ --- Individual Give Logic (Modified so balls stay on table) ---

NewBarkTown_ElmsLab_EventScript_GiveCyndaquil::
	setvar VAR_TEMP_1, SPECIES_CYNDAQUIL
	removeobject 2
	setflag FLAG_HIDE_CYNDAQUIL_BALL
	goto NewBarkTown_ElmsLab_EventScript_FinishGiveStarter

NewBarkTown_ElmsLab_EventScript_GiveTotodile::
	setvar VAR_TEMP_1, SPECIES_TOTODILE
	removeobject 3
	setflag FLAG_HIDE_TOTODILE_BALL
	goto NewBarkTown_ElmsLab_EventScript_FinishGiveStarter

NewBarkTown_ElmsLab_EventScript_GiveChikorita::
	setvar VAR_TEMP_1, SPECIES_CHIKORITA
	removeobject 4
	setflag FLAG_HIDE_CHIKORITA_BALL
	goto NewBarkTown_ElmsLab_EventScript_FinishGiveStarter

@ --- Consolidated Logic (The "Fresh Start" Sequence) ---

NewBarkTown_ElmsLab_EventScript_FinishGiveStarter::
	setflag FLAG_GOT_JOHTO_STARTER
	hidemonpic
	msgbox NewBarkTown_ElmsLab_Text_FreshStartNotice, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	@ This calls your C function from field_specials.c
	special StoreAllNonStarterPokemon
	playse SE_PC_LOGIN
	waitse
	fadescreen FADE_FROM_BLACK
	givemon VAR_TEMP_1, 5, ITEM_NONE
	playfanfare MUS_LEVEL_UP
	msgbox NewBarkTown_ElmsLab_Text_ReceivedMon, MSGBOX_DEFAULT
	waitfanfare
	release
	end

NewBarkTown_ElmsLab_EventScript_AlreadyPicked::
	msgbox NewBarkTown_ElmsLab_Text_AlreadyPicked, MSGBOX_DEFAULT
	release
	end

NewBarkTown_ElmsLab_EventScript_ElmGreetingTrigger::
	lockall
	setvar VAR_ELM_INTRO_STATE, 1

	@ Exclamation Mark over Professor (Object ID 1)
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	delay 40

	@ Identify which tile was stepped on
	getplayerxy VAR_TEMP_2, VAR_TEMP_3

	@ Branching logic to reach X:7, Y:5
	compare VAR_TEMP_2, 4
	call_if_eq NewBarkTown_ElmsLab_EventScript_MoveToCenter_4
	compare VAR_TEMP_2, 5
	call_if_eq NewBarkTown_ElmsLab_EventScript_MoveToCenter_5
	compare VAR_TEMP_2, 6
	call_if_eq NewBarkTown_ElmsLab_EventScript_MoveToCenter_6
	compare VAR_TEMP_2, 7
	call_if_eq NewBarkTown_ElmsLab_EventScript_MoveToCenter_7
	compare VAR_TEMP_2, 8
	call_if_eq NewBarkTown_ElmsLab_EventScript_MoveToCenter_8

	waitmovement 0

	@ Professor walks to face the player
	applymovement 1, NewBarkTown_ElmsLab_Movement_ElmApproachPlayer
	waitmovement 0

	msgbox NewBarkTown_ElmsLab_Text_ElmGreeting, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBarkTown_ElmsLab_EventScript_AcceptNewJourney

	@ If "No"
	msgbox NewBarkTown_ElmsLab_Text_ElmKeepOldTeam, MSGBOX_DEFAULT
	releaseall
	end

NewBarkTown_ElmsLab_EventScript_AcceptNewJourney::
	setflag FLAG_ACCEPTED_JOHTO_JOURNEY @ New flag to unlock the balls
	msgbox NewBarkTown_ElmsLab_Text_ElmGoPick, MSGBOX_DEFAULT
	setvar VAR_ELM_INTRO_STATE, 1
	releaseall
	end

	@ Movement for the player to step forward so they aren't stuck on the door tile
NewBarkTown_ElmsLab_Movement_PlayerStepsIn:
	walk_up
	step_end

@ --- Text Entries ---

NewBarkTown_ElmsLab_Text_ElmGreeting:
	.string "ELM: Ah, {PLAYER}! I've heard you've\n"
	.string "conquered the KANTO LEAGUE!\p"
	.string "Since you're here in JOHTO, would you\n"
	.string "like to start fresh with a new partner\l"
	.string "from my lab?$"

NewBarkTown_ElmsLab_Text_ElmKeepOldTeam:
	.string "ELM: I see! Your bond with your current\n"
	.string "team is truly impressive.\p"
	.string "Feel free to explore JOHTO with them!$"

NewBarkTown_ElmsLab_Text_ElmGoPick:
	.string "ELM: Excellent! I have three POKéMON\n"
	.string "right here. Take your pick!$"

NewBarkTown_ElmsLab_Text_ElmPickAMon:
	.string "ELM: Go ahead, {PLAYER}!\n"
	.string "Choose a partner for your\l"
	.string "Johto journey!$"

NewBarkTown_ElmsLab_Text_ElmHowIsStarter:
	.string "ELM: Your POKéMON looks very\n"
	.string "happy with you!$"

NewBarkTown_ElmsLab_Text_TakeCyndaquil:
	.string "Will you take the FIRE POKéMON,\n"
	.string "CYNDAQUIL?$"

NewBarkTown_ElmsLab_Text_TakeTotodile:
	.string "Will you take the WATER POKéMON,\n"
	.string "TOTODILE?$"

NewBarkTown_ElmsLab_Text_TakeChikorita:
	.string "Will you take the GRASS POKéMON,\n"
	.string "CHIKORITA?$"

NewBarkTown_ElmsLab_Text_FreshStartNotice:
	.string "For a fresh start in Johto, your\n"
	.string "current party will be sent to the PC.$"

NewBarkTown_ElmsLab_Text_ReceivedMon:
	.string "{PLAYER} received the POKéMON\n"
	.string "from PROF. ELM!$"

NewBarkTown_ElmsLab_Text_AlreadyPicked:
	.string "You already have a POKéMON!$"

NewBarkTown_ElmsLab_EventScript_DontTouchBalls::
	msgbox NewBarkTown_ElmsLab_Text_DontTouchBalls, MSGBOX_DEFAULT
	release
	end

NewBarkTown_ElmsLab_Text_DontTouchBalls::
	.string "It's a POKé BALL containing\n"
	.string "a POKéMON. Better not touch it!$"

Johto_Event_Finished::
	msgbox Text_JohtoIsGreat, MSGBOX_DEFAULT
	release
	end

Text_WelcomeToJohto:
	.string "Welcome to the Johto region!$"

Text_JohtoIsGreat:
	.string "Johto is a great place to explore.$"
	@ --- Player Centering Movements ---

	@ --- Player Pathing to X:7, Y:5 ---

	NewBarkTown_ElmsLab_EventScript_MoveToCenter_4::
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_ElmsLab_Movement_X4_to_Center
	return

	NewBarkTown_ElmsLab_EventScript_MoveToCenter_5::
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_ElmsLab_Movement_X5_to_Center
	return

	NewBarkTown_ElmsLab_EventScript_MoveToCenter_6::
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_ElmsLab_Movement_X6_to_Center
	return

	NewBarkTown_ElmsLab_EventScript_MoveToCenter_7::
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_ElmsLab_Movement_X7_to_Center
	return

	NewBarkTown_ElmsLab_EventScript_MoveToCenter_8::
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_ElmsLab_Movement_X8_to_Center
	return

	@ --- Movement Data ---

	NewBarkTown_ElmsLab_Movement_X4_to_Center:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	face_up
	step_end

	NewBarkTown_ElmsLab_Movement_X5_to_Center:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

	NewBarkTown_ElmsLab_Movement_X6_to_Center:
	walk_up
	walk_up
	walk_up
	walk_right
	face_up
	step_end

	NewBarkTown_ElmsLab_Movement_X7_to_Center:
	walk_up
	walk_up
	walk_up
	face_up
	step_end

	NewBarkTown_ElmsLab_Movement_X8_to_Center:
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end

	@ --- Elm Movement ---

	NewBarkTown_ElmsLab_Movement_ElmApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	face_down
	step_end
