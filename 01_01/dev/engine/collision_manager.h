#ifndef _COLLISION_MANAGER_H_
#define _COLLISION_MANAGER_H_

void engine_collision_manager_init( unsigned char difficulty );
void engine_collision_manager_init_org( unsigned char difficulty );
signed char engine_collision_manager_player( unsigned char lookX, unsigned char tileY );
void engine_collision_manager_finish( unsigned char lookX, unsigned char tileY, unsigned char posnY, unsigned char *player_begY, unsigned char *player_endY );

#endif//_COLLISION_MANAGER_H_