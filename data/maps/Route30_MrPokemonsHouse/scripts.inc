Route30_MrPokemonsHouse_MapScripts::
	.byte 0

Route30_MrPokemonsHouse_EventScript_MrPokemon::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MYSTERY_EGG, Route30_MrPokemonsHouse_EventScript_Gossip
	msgbox Route30_MrPokemonsHouse_Text_MeetMrPokemon

	@ Ensure the player has at least one open slot in their party for an Egg
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, 6, Route30_MrPokemonsHouse_EventScript_PartyFull

	@ Roll a number from 0 to 9 to pick from 10 baby Pokémon
	random 10
	goto_if_eq VAR_RESULT, 0, Route30_MrPokemonsHouse_EventScript_EggPichu
	goto_if_eq VAR_RESULT, 1, Route30_MrPokemonsHouse_EventScript_EggCleffa
	goto_if_eq VAR_RESULT, 2, Route30_MrPokemonsHouse_EventScript_EggIgglybuff
	goto_if_eq VAR_RESULT, 3, Route30_MrPokemonsHouse_EventScript_EggTogepi
	goto_if_eq VAR_RESULT, 4, Route30_MrPokemonsHouse_EventScript_EggTyrogue
	goto_if_eq VAR_RESULT, 5, Route30_MrPokemonsHouse_EventScript_EggSmoochum
	goto_if_eq VAR_RESULT, 6, Route30_MrPokemonsHouse_EventScript_EggElekid
	goto_if_eq VAR_RESULT, 7, Route30_MrPokemonsHouse_EventScript_EggAzurill
	goto_if_eq VAR_RESULT, 8, Route30_MrPokemonsHouse_EventScript_EggWynaut
	goto_if_eq VAR_RESULT, 9, Route30_MrPokemonsHouse_EventScript_EggMagby
	end

Route30_MrPokemonsHouse_EventScript_EggPichu::
	giveegg SPECIES_PICHU
	goto Route30_MrPokemonsHouse_EventScript_ReceivedEgg
	end

Route30_MrPokemonsHouse_EventScript_EggCleffa::
	giveegg SPECIES_CLEFFA
	goto Route30_MrPokemonsHouse_EventScript_ReceivedEgg
	end

Route30_MrPokemonsHouse_EventScript_EggIgglybuff::
	giveegg SPECIES_IGGLYBUFF
	goto Route30_MrPokemonsHouse_EventScript_ReceivedEgg
	end

Route30_MrPokemonsHouse_EventScript_EggTogepi::
	giveegg SPECIES_TOGEPI
	goto Route30_MrPokemonsHouse_EventScript_ReceivedEgg
	end

Route30_MrPokemonsHouse_EventScript_EggTyrogue::
	giveegg SPECIES_TYROGUE
	goto Route30_MrPokemonsHouse_EventScript_ReceivedEgg
	end

Route30_MrPokemonsHouse_EventScript_EggSmoochum::
	giveegg SPECIES_SMOOCHUM
	goto Route30_MrPokemonsHouse_EventScript_ReceivedEgg
	end

Route30_MrPokemonsHouse_EventScript_EggElekid::
	giveegg SPECIES_ELEKID
	goto Route30_MrPokemonsHouse_EventScript_ReceivedEgg
	end

Route30_MrPokemonsHouse_EventScript_EggAzurill::
	giveegg SPECIES_AZURILL
	goto Route30_MrPokemonsHouse_EventScript_ReceivedEgg
	end

Route30_MrPokemonsHouse_EventScript_EggWynaut::
	giveegg SPECIES_WYNAUT
	goto Route30_MrPokemonsHouse_EventScript_ReceivedEgg
	end

Route30_MrPokemonsHouse_EventScript_EggMagby::
	giveegg SPECIES_MAGBY
	goto Route30_MrPokemonsHouse_EventScript_ReceivedEgg
	end

Route30_MrPokemonsHouse_EventScript_ReceivedEgg::
	setflag FLAG_RECEIVED_MYSTERY_EGG

	@ Also give the physical Bag Key Item for plot purposes
	giveitem ITEM_MYSTERY_EGG, 1

	msgbox Route30_MrPokemonsHouse_Text_TakeToElm
	release
	end

Route30_MrPokemonsHouse_EventScript_PartyFull::
	msgbox Route30_MrPokemonsHouse_Text_PartyFullText
	release
	end

Route30_MrPokemonsHouse_EventScript_Gossip::
	msgbox Route30_MrPokemonsHouse_Text_MrPokemonGossip
	release
	end

Route30_MrPokemonsHouse_Text_MeetMrPokemon:
	.string "Hello, hello! You must be the famous\n"
	.string "KANTO CHAMPION I've heard so much about!\p"
	.string "Professor ELM told me you were exploring\n"
	.string "our region with a fresh team.\p"
	.string "Perfect timing! My friend from overseas\n"
	.string "sent me this strange POKéMON EGG.\l"
	.string "Please, take it to ELM for research!$"

Route30_MrPokemonsHouse_Text_TakeToElm:
	.string "I put the EGG right into your party!\n"
	.string "I know ELM will discover something\l"
	.string "incredible from it!$"

Route30_MrPokemonsHouse_Text_PartyFullText:
	.string "Oh? You don't have any room in your\n"
	.string "active party to carry this EGG.\p"
	.string "Go store a POKéMON in the PC Center\n"
	.string "and come right back!$"

Route30_MrPokemonsHouse_Text_MrPokemonGossip:
	.string "Life is full of wonderful mysteries.\n"
	.string "That's why they call me MR. POKéMON!$"

