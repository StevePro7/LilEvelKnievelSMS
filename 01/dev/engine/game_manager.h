#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include "../object/game_object.h"

// Global variable.
extern struct_game_object global_game_object;

void engine_game_manager_init();
void engine_game_manager_set_cloud_form( unsigned char game_cloud );
void engine_game_manager_set_difficulty( unsigned char game_difficulty );
void engine_game_manager_set_level_data( unsigned char game_world, unsigned char game_round, unsigned char game_point );
void engine_game_manager_set_game_saved( unsigned char game_saved );
void engine_game_manager_set_game_start( unsigned char game_start );
void engine_game_manager_set_game_music( unsigned char game_music );
void engine_game_manager_set_game_sheet( unsigned char game_sheet );

void engine_game_manager_inc_checkpoint();

// TODO delete - only used for testing
void engine_game_manager_set_level_test( unsigned char game_level );

#endif//_GAME_MANAGER_H_