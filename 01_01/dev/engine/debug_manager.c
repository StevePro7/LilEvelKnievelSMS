#include "debug_manager.h"
#include "../engine/asm_manager.h"
#include "../engine/content_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/level_manager.h"
#include "../engine/player_manager.h"
#include "../engine/scroll_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/bank2.h"
#include <stdbool.h>

void engine_debug_manager_initgame()
{
	struct_player_object *po = &global_player_object;
	struct_game_object *go = &global_game_object;
	//go->game_difficulty = difficulty_type_easier;
	//go->game_difficulty = difficulty_type_normal;
	go->game_difficulty = difficulty_type_harder;
	//go->game_difficulty = difficulty_type_insane;
	engine_player_manager_lives( go->game_difficulty );
	//go->game_isgod = false;
	//go->game_isgod = true;

	////go->game_level = 1;

	go->game_world = 1;	// TODO - currently not aligned with game_level but used for testing...
	go->game_round = 2;
	go->game_point = 4;

	go->game_world -= 1;
	go->game_round -= 1;
	go->game_point -= 1;
	engine_game_manager_set_level_data( go->game_world, go->game_round, go->game_point );

	// 9 = turtles
	// 3 = long512
	//go->game_level = 0;
	//go->game_level = 9;
	//go->game_level = 0;
	//go->game_level = 1;
	//go->game_level = 3;
	//go->game_level = 9;
	//go->game_level = 17;// 64x screens
	//go->game_level = 20;	// testing large jumps
	//go->game_level = 24;	// bank8

	//go->game_level = 3;	// trees
	//go->game_level = 7;	// trees
	//go->game_level = 9;	// turtles
	//go->game_level = 6;
	//go->game_level = 7;
	//go->game_level = 0;
	//go->game_cloud = 88;		// TODO will be random
}

