#include "collision_manager.h"
#include "enum_manager.h"
#include "hack_manager.h"
#include "global_manager.h"
#include "level_manager.h"
#include <stdbool.h>

#define COLLISION_MIN_PLUS_NIL		0						// 00
#define COLLISION_MIN_PLUS_ONE		1						// 01
#define COLLISION_MAX_LESS_ONE		SCREEN_LESS_ONE			// 31
#define COLLISION_MAX_LESS_TWO		SCREEN_WIDE - 2			// 30

static unsigned char collisionDelta;
static unsigned char collisionRange;
static bool moreForgiving;

void engine_collision_manager_init( unsigned char difficulty )
{
	struct_hack_object *ho = &global_hack_object;
	difficulty += 0;

	// Easier + Normal collision delta = 2px range as is more forgiving.
	collisionDelta = 2;
	moreForgiving = true;

	if( ho->hack_ultra )
	{
		// Harder + Insane collision delta = 1px range as is less forgiving.
		collisionDelta = 1;
		moreForgiving = false;
	}

	collisionRange = SCREEN_WIDE - collisionDelta;
}

void engine_collision_manager_init_org( unsigned char difficulty )
{
	// Harder + Insane collision delta = 1px range as is less forgiving.
	difficulty += 0;
	collisionDelta = 1;
	moreForgiving = false;
	if( difficulty_type_easier == difficulty || difficulty_type_normal == difficulty )
	{
		// Easier + Normal collision delta = 2px range as is more forgiving.
		collisionDelta = 2;
		moreForgiving = true;
	}

	collisionRange = SCREEN_WIDE - collisionDelta;
	collisionRange = SCREEN_WIDE;
}

signed char engine_collision_manager_player( unsigned char lookX, unsigned char tileY )
{
	unsigned char lookup_platform;
	unsigned char player_platform;
	signed char collisionTile;

	player_platform = tileY;
	collisionTile = INVALID_INDEX;

	// Check collision left side of player.
	if( ( COLLISION_MIN_PLUS_NIL == lookX ) || ( COLLISION_MIN_PLUS_ONE == lookX && moreForgiving ) )
	{
		collisionTile = lookX + collisionRange;
	}
	else
	{
		collisionTile = lookX - collisionDelta;
	}

	lookup_platform = level_platforms[ collisionTile ];
	if( lookup_platform == player_platform )
	{
		return collisionTile;
	}

	// Check collision right side of player.
	if( ( COLLISION_MAX_LESS_ONE == lookX ) || ( COLLISION_MAX_LESS_TWO == lookX && moreForgiving ) )
	{
		collisionTile = lookX - collisionRange;
	}
	else
	{
		collisionTile = lookX + collisionDelta;
	}

	lookup_platform = level_platforms[ collisionTile ];
	if( lookup_platform == player_platform )
	{
		return collisionTile;
	}

	return INVALID_INDEX;
}

void engine_collision_manager_finish( unsigned char lookX, unsigned char tileY, unsigned char posnY, unsigned char *player_begY, unsigned char *player_endY )
{
	// Short algorithm to compare player finishing level:
	// if player>=lookup_platform then return lookup_platform.
	unsigned char lookup_platform = level_platforms[ lookX ];

	*player_begY = lookup_platform << 3;
	*player_endY = lookup_platform << 3;

	if( tileY < lookup_platform )
	{
		*player_begY = posnY;
	}
}
