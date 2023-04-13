#include "debug_manager.h"
#include "../engine/game_manager.h"
#include "../engine/player_manager.h"

void engine_debug_manager_initgame()
{
	struct_player_object *po = &global_player_object;
	struct_game_object *go = &global_game_object;

	//go->game_difficulty = difficulty_type_easier;
	go->game_difficulty = difficulty_type_normal;
	//go->game_difficulty = difficulty_type_harder;
	//go->game_difficulty = difficulty_type_insane;
	engine_player_manager_lives( go->game_difficulty );

	go->game_world = 0;
	go->game_round = 0;
	go->game_point = 0;

	go->game_world -= 1;
	go->game_round -= 1;
	go->game_point -= 1;
	engine_game_manager_set_level_data( go->game_world, go->game_round, go->game_point );
}

