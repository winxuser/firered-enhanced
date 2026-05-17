NewBarkTown_MapScripts::
	.byte 0

NewBarkTown_EventScript_StopPlayerExit::
	lockall
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	delay 40

	getplayerxy VAR_TEMP_2, VAR_TEMP_3

	@ Branching based on Player's Y-coordinate
	compare VAR_TEMP_3, 9
	call_if_eq NewBarkTown_EventScript_NPCMoveTo_Y9
	compare VAR_TEMP_3, 10
	call_if_eq NewBarkTown_EventScript_NPCMoveTo_Y10
	compare VAR_TEMP_3, 11
	call_if_eq NewBarkTown_EventScript_NPCMoveTo_Y11
	compare VAR_TEMP_3, 12
	call_if_eq NewBarkTown_EventScript_NPCMoveTo_Y12

	waitmovement 0
	msgbox NewBarkTown_Text_WaitElmIsWaiting, MSGBOX_DEFAULT
	closemessage

	@ Push player back and return NPC
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Movement_PlayerStepBack
	@ NPC returns based on where she is (Y-coordinate)
	compare VAR_TEMP_3, 9
	call_if_eq NewBarkTown_EventScript_NPCReturn_Y9
	compare VAR_TEMP_3, 10
	call_if_eq NewBarkTown_EventScript_NPCReturn_Y10
	compare VAR_TEMP_3, 11
	call_if_eq NewBarkTown_EventScript_NPCReturn_Y11
	compare VAR_TEMP_3, 12
	call_if_eq NewBarkTown_EventScript_NPCReturn_Y12
	waitmovement 0
	releaseall
	end

	@ The NPC's regular script when you talk to her
NewBarkTown_EventScript_Woman::
	lock
	faceplayer
	@ Check if the player has already finished the Lab event
	compare VAR_ELM_INTRO_STATE, 1
	goto_if_eq NewBarkTown_EventScript_WomanHi
	msgbox NewBarkTown_Text_WaitElmIsWaiting, MSGBOX_DEFAULT
	release
	end

NewBarkTown_EventScript_WomanHi::
	msgbox NewBarkTown_Text_WomanNormalHi, MSGBOX_DEFAULT
	release
	end

NewBarkTown_EventScript_NPCMoveTo_Y9::
	applymovement 1, NewBarkTown_Movement_WalkToY9
	return

NewBarkTown_EventScript_NPCMoveTo_Y10::
	applymovement 1, NewBarkTown_Movement_WalkToY10
	return

NewBarkTown_EventScript_NPCMoveTo_Y11::
	applymovement 1, NewBarkTown_Movement_WalkToY11
	return

NewBarkTown_EventScript_NPCMoveTo_Y12::
	applymovement 1, NewBarkTown_Movement_WalkToY12
	return

NewBarkTown_EventScript_NPCReturn_Y9::
	applymovement 1, NewBarkTown_Movement_ReturnFromY9
	return

NewBarkTown_EventScript_NPCReturn_Y10::
	applymovement 1, NewBarkTown_Movement_ReturnFromY10
	return

NewBarkTown_EventScript_NPCReturn_Y11::
	applymovement 1, NewBarkTown_Movement_ReturnFromY11
	return

NewBarkTown_EventScript_NPCReturn_Y12::
	applymovement 1, NewBarkTown_Movement_ReturnFromY12
	return

	@ From 6,10 to 3,9
NewBarkTown_Movement_WalkToY9:
	walk_left
	walk_left
	walk_up
	face_left
	step_end

	@ From 6,10 to 3,10 (Direct line)
NewBarkTown_Movement_WalkToY10:
	walk_left
	walk_left
	face_left
	step_end

	@ From 6,10 to 3,11
NewBarkTown_Movement_WalkToY11:
	walk_left
	walk_left
	walk_down
	face_left
	step_end

	@ From 6,10 to 3,12
NewBarkTown_Movement_WalkToY12:
	walk_left
	walk_left
	walk_down
	walk_down
	face_left
	step_end

	@ Player is at X:3, needs to move to X:4
NewBarkTown_Movement_PlayerStepBack:
	walk_right
	step_end

	@ Returns NPC to X:6, Y:10
NewBarkTown_Movement_NPCGoBack:
	walk_right
	walk_right
	walk_right
	face_down @ Adjust this if you want her facing a different way at rest
	step_end

	@ From 3,9 back to 6,10
	NewBarkTown_Movement_ReturnFromY9:
	walk_down
	walk_right
	walk_right
	face_down
	step_end

	@ From 3,10 back to 6,10
	NewBarkTown_Movement_ReturnFromY10:
	walk_right
	walk_right
	face_down
	step_end

	@ From 3,11 back to 6,10
	NewBarkTown_Movement_ReturnFromY11:
	walk_up
	walk_right
	walk_right
	face_down
	step_end

	@ From 3,12 back to 6,10
	NewBarkTown_Movement_ReturnFromY12:
	walk_up
	walk_up
	walk_right
	walk_right
	face_down
	step_end

NewBarkTown_Text_WaitElmIsWaiting:
	.string "Wait! PROF. ELM is waiting for you\n"
	.string "in the LAB. You should go see him\l"
	.string "before heading out!$"

NewBarkTown_Text_WomanNormalHi:
	.string "Hi! It's a beautiful day in\n"
	.string "NEW BARK TOWN, isn't it?$"
