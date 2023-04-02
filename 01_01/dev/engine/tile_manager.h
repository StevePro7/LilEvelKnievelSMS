#ifndef _TILE_MANAGER_H_
#define _TILE_MANAGER_H_

#include "global_manager.h"
#include "../object/tile_object.h"
#include <stdbool.h>

// Global variable.
//extern struct_tile_object global_tile_object;
//extern struct_tile_object global_tile_objects[ MAX_TILE_OBJECTS ];

//void engine_tile_manager_draw_columns( unsigned char tile_type, unsigned char x, unsigned char col );
void engine_tile_manager_draw_column( unsigned char tile_type, unsigned char x, unsigned char col, bool flip );
void engine_tile_manager_draw_cloud( unsigned int tileMap, unsigned char x, unsigned char y, bool flip );

//void engine_tile_manager_stevepro( unsigned int tileMap, unsigned char x, unsigned char y, unsigned char w, unsigned char h );
//void engine_tile_manager_stevepro2( unsigned int tileMap, unsigned char x, unsigned char y, unsigned char w, unsigned char h );
//void engine_tile_manager_stevepro3( unsigned int tileMap, unsigned char x, unsigned char y, unsigned char w, unsigned char h );
void engine_tile_manager_init();
/*
void engine_tile_manager_draw( unsigned char tile_type );
void engine_tile_manager_draw_columns( unsigned char tile_type, unsigned char x, unsigned char y, unsigned char col, bool flip );
//void engine_tile_manager_draw_columns( unsigned char tile_type, unsigned char col, unsigned char x, bool flip );

void engine_tile_manager_gfx5( unsigned int tmp, unsigned char x, unsigned char y, unsigned char w, unsigned char h );
void engine_tile_manager_gfx4( unsigned int tmp, unsigned char h );
void engine_tile_manager_gfx3( unsigned char tmp, unsigned char x, unsigned char col );
void engine_tile_manager_gfx2( unsigned char tmp );
void engine_tile_manager_gfx();

void engine_tile_manager_clouds();
void engine_tile_manager_island();
void engine_tile_manager_tree();
void engine_tile_manager_bridge();
void engine_tile_manager_turtle();
void engine_tile_manager_sign();

void engine_tile_manager_sky();
void engine_tile_manager_sea();
*/
#endif//_TILE_MANAGER_H_