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
	//go->game_difficulty = difficulty_type_harder;
	//go->game_difficulty = difficulty_type_insane;
	//engine_player_manager_lives( go->game_difficulty );
	//go->game_isgod = false;
	//go->game_isgod = true;

	////go->game_level = 1;

	//go->game_world = 1;	// TODO - currently not aligned with game_level but used for testing...
	//go->game_round = 2;
	//go->game_point = 4;

	//go->game_world -= 1;
	//go->game_round -= 1;
	//go->game_point -= 1;
	//engine_game_manager_set_level_data( go->game_world, go->game_round, go->game_point );

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

// TODO - delete this!!
//void engine_debug_manager_printout()
//{
//	struct_player_object *po = &global_player_object;
//	struct_level_object *lo = &global_level_object;
//	//unsigned char idx, tmp;
//
//	//devkit_SMS_mapROMBank( bggame_tiles__tiles__psgcompr_bank );
//	//for( idx = 0; idx < 16; idx++ )
//	//{
//	//	engine_font_manager_data( idx, 14, idx );
//	//	engine_font_manager_data( level_platforms[ idx ], 18, idx );
//
//	//	tmp = idx + 16;
//	//	engine_font_manager_data( tmp, 25, idx );
//	//	engine_font_manager_data( level_platforms[ tmp ], 30, idx );
//	//}
//
//	engine_font_manager_data( po->posnX, 8, 0 );
//	engine_font_manager_data( po->tileX, 8, 1 );
//	engine_font_manager_data( po->lookX, 8, 2 );
//
//	engine_font_manager_data( po->posnY, 8, 3 );
//	engine_font_manager_data( po->tileY, 8, 4 );
//	engine_font_manager_data( po->drawY, 8, 5 );
//	engine_font_manager_data( po->player_state, 20, 3 );
//	engine_font_manager_data( po->jumper_index, 20, 4 );
//	engine_font_manager_data( po->deltaY_index, 20, 5 );
//}
