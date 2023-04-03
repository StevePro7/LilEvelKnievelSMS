#ifndef _SPRITE_MANAGER_H_
#define _SPRITE_MANAGER_H_

void engine_sprite_manager_draw( unsigned char idx, unsigned char x, unsigned char y );
void engine_sprite_manager_head( unsigned char x, unsigned char y );
void engine_sprite_manager_mode( unsigned char idx, unsigned char mode, unsigned char x, unsigned char y );
void engine_sprite_manager_zoom( unsigned char mode, unsigned char x, unsigned char y );

#endif//_SPRITE_MANAGER_H_