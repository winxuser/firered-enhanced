CherrygroveCity_Mart_MapScripts::
	.byte 0

CherrygroveCity_Mart_EventScript_Clerk::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart CherrygroveCity_Mart_Items
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
CherrygroveCity_Mart_Items::
	.hword ITEM_POKE_BALL
	.hword ITEM_POTION
	.hword ITEM_ANTIDOTE
	.hword ITEM_PARALYZE_HEAL
	.hword ITEM_AWAKENING
	.hword ITEM_REPEL
	.hword ITEM_NONE
	release
	end
