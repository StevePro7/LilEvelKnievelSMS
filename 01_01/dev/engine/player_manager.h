#ifndef _PLAYER_MANAGER_H_
#define _PLAYER_MANAGER_H_

#include "enum_manager.h"
#include "../object/player_object.h"
	
// Global variable.
extern struct_player_object global_player_object;

void engine_player_manager_init();
void engine_player_manager_initX( unsigned char difficulty, unsigned char world );
void engine_player_manager_loadX( unsigned char checkScreen );
void engine_player_manager_loadY( unsigned char player_loadY );
void engine_player_manager_lives( unsigned char difficulty );

unsigned char engine_player_manager_get_deltaX( unsigned char state, unsigned char command );
signed int engine_player_manager_get_deltaY();
void engine_player_manager_set_action( unsigned char frame, unsigned char command );

void engine_player_manager_horz( unsigned char deltaX );
void engine_player_manager_vert( signed int deltaY );
void engine_player_manager_bounds( signed int deltaY, unsigned char posnY, unsigned char invincible );
void engine_player_manager_animate( unsigned char frame );
enum_player_state engine_player_manager_collision( unsigned char state, unsigned char lookX, unsigned char tileY, signed int deltaY, unsigned char posnY, unsigned char invincible );

void engine_player_manager_draw();
void engine_player_manager_head();
unsigned char engine_player_manager_finish();
void engine_player_manager_dying();
void engine_player_manager_pass( unsigned char player_passX, unsigned char player_endY );
void engine_player_manager_pass_frame();
void engine_player_manager_dead( unsigned char player_deadX );

#endif//_PLAYER_MANAGER_H_
