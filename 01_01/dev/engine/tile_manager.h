#ifndef _TILE_MANAGER_H_
#define _TILE_MANAGER_H_

#include "global_manager.h"
#include "../object/tile_object.h"
#include <stdbool.h>

void engine_tile_manager_init();
void engine_tile_manager_draw_column( unsigned char tile_type, unsigned char x, unsigned char col, bool flip );
void engine_tile_manager_draw_cloud( unsigned int tileMap, unsigned char x, unsigned char y, bool flip );

#endif//_TILE_MANAGER_H_