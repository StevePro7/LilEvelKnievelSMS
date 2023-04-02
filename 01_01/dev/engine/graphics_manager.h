#ifndef _GRAPHICS_MANAGER_H_
#define _GRAPHICS_MANAGER_H_

void engine_graphics_manager_common();
void engine_graphics_manager_screen( unsigned int tile );
void engine_graphics_manager_sea();
void engine_graphics_manager_clouds( unsigned char data );
void engine_graphics_manager_title();
void engine_graphics_manager_image( const unsigned char *tiles, unsigned int tileMap, unsigned char x, unsigned char y, unsigned char w, unsigned char h );
void engine_graphics_manager_image_flip( const unsigned char *tiles, unsigned int tileMap, unsigned char x, unsigned char y, unsigned char w, unsigned char h );
void engine_graphics_manager_level_stats( unsigned char game_world, unsigned char game_round, unsigned char game_point );
void engine_graphics_manager_level_texts();

#endif//_GRAPHICS_MANAGER_H_