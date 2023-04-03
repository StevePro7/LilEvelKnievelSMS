#include "game_manager.h"
#include "enum_manager.h"
#include "global_manager.h"
#include "util_manager.h"

// Global variable.
struct_game_object global_game_object;

void engine_game_manager_init()
{
	struct_game_object *go = &global_game_object;
	go->game_difficulty = difficulty_type_normal;
	go->game_world = 0;
	go->game_round = 0;
	go->game_level = 0;
	go->game_point = 0;
	go->game_saved = switch_mode_no;
	go->game_start = switch_mode_no;
	go->game_music = 0;
	go->game_cloud = 0;
	go->game_isgod = switch_mode_no;
	go->game_sheet = switch_mode_no;
}

void engine_game_manager_set_cloud_form( unsigned char game_cloud )
{
	struct_game_object *go = &global_game_object;
	go->game_cloud = game_cloud;
}
void engine_game_manager_set_difficulty( unsigned char game_difficulty )
{
	struct_game_object *go = &global_game_object;
	go->game_difficulty = game_difficulty;
}
void engine_game_manager_set_level_data( unsigned char game_world, unsigned char game_round, unsigned char game_point )
{
	struct_game_object *go = &global_game_object;
	go->game_world = game_world;
	go->game_round = game_round;
	go->game_point = game_point;

	// Align level.
	go->game_level = game_world * MAX_ROUNDS + game_round;
}
void engine_game_manager_set_game_saved( unsigned char game_saved )
{
	// Keep track if game has been saved before; i.e. loaded and played.
	struct_game_object *go = &global_game_object;
	go->game_saved = game_saved;
}
void engine_game_manager_set_game_start( unsigned char game_start )
{
	// Keep track if level has start so only play intro riff once
	struct_game_object *go = &global_game_object;
	go->game_start = game_start;
}
void engine_game_manager_set_game_music( unsigned char game_music )
{
	// Keep track of music.
	struct_game_object *go = &global_game_object;
	go->game_music = game_music;
}
void engine_game_manager_set_game_sheet( unsigned char game_sheet )
{
	// Keep track of cheat sheet.
	struct_game_object *go = &global_game_object;
	go->game_sheet = game_sheet;
}
void engine_game_manager_inc_checkpoint()
{
	struct_game_object *go = &global_game_object;
	go->game_point++;
}
