Cherrygrove_City_Pokecenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Cherrygrove_City_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Cherrygrove_City_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY
	setflag FLAG_WORLD_MAP_CHERRYGROVE_CITY_POKEMON_CENTER_1F
	end

	@ Assuming the Nurse is Object ID 1 in Porymap
	.set LOCALID_NURSE, 1

Cherrygrove_City_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	call EventScript_PkmnCenterNurse
	release
	end
