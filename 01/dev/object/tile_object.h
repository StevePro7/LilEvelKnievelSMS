#ifndef _TILE_OBJECT_H_
#define _TILE_OBJECT_H_

// Tiles Manager.
#define TILMAP_WIDE				24
#define TILE_STRIP				4
#define TILE_NONE				0
#define TILE_SKY_AND_SEA		64

#define TILE_WAVES_BLOCK		144
#define TILE_BRIDGE_MIDD		152
#define TILE_BRIDGE_SIDE		160
#define TILE_BRIDGE_SIGN		168
#define TILE_BRIDGE_GOAL		176
#define TILE_ISLAND_MIDD		184

#define TILE_ISLAND_LEFT		816
#define TILE_ISLAND_RGHT		824
#define TILE_ISLAND_SIGN		832
#define TILE_ISLAND_GOAL		840
#define TILE_ISLAND_TREEL		848
#define TILE_ISLAND_TREER		856

#define TILE_TURTLE_SEA1		1488
#define TILE_TURTLE_SEA2		1496
#define TILE_TURTLE_FLY1		1504
#define TILE_TURTLE_FLY2		1512
#define TILE_TURTLE_FLY3		1520
#define TILE_TURTLE_FLY4		1528

#define TILE_TURTLE_FLIP		1768

#define TILE_CLOUD_LARGE		2160
#define TILE_CLOUD_SMALL		2176

#define TILE_PLAY_TITLE			2304

extern const unsigned int tiles_object_indexes[];
extern const unsigned char tiles_object_platform[];

//typedef struct tag_struct_tile_object
//{
//	unsigned int tilemap_index;
//	unsigned char tile_wide;
//	//unsigned char tile_high;		TODO delete - as #define 
//	unsigned char tile_platform;
//
//} struct_tile_object;

#endif//_LEVEL_OBJECT_H_