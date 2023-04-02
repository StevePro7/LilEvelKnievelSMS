#ifndef _SPRITE_MANAGER_H_
#define _SPRITE_MANAGER_H_

// TODO delete
//void engine_sprite_manager_clear( unsigned char ch );
void engine_sprite_manager_draw( unsigned char idx, unsigned char x, unsigned char y );
void engine_sprite_manager_head( unsigned char x, unsigned char y );
void engine_sprite_manager_mode( unsigned char idx, unsigned char mode, unsigned char x, unsigned char y );
void engine_sprite_manager_zoom( unsigned char mode, unsigned char x, unsigned char y );
//void engine_sprite_manager_draw( unsigned char x, unsigned char y, unsigned int tile );
//void engine_sprite_manager_fish( unsigned char x, unsigned char y );
//void engine_sprite_manager_octopus( unsigned char x, unsigned char y );

#endif//_SPRITE_MANAGER_H_