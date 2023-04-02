#ifndef _LEVEL_MANAGER_H_
#define _LEVEL_MANAGER_H_

#include "../object/level_object.h"

// Global variable.
extern struct_level_object global_level_object;

void engine_level_manager_init( unsigned char level );
void engine_level_manager_draw_screen( unsigned char checkScreen );
//void engine_level_manager_draw_point( unsigned char checkPoint );
void engine_level_manager_draw_column( unsigned int scrollColumn );
//void engine_level_manager_draw_column( unsigned int scrollColumn );		// TODO delete dup

#endif//_LEVEL_MANAGER_H_