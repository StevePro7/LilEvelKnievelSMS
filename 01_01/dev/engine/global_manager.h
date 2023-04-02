#ifndef _GLOBAL_MANAGER_H_
#define _GLOBAL_MANAGER_H_

// Screens
#define MAX_SCREEENS		24

// Levels.
#define MAX_WOLRDS			5
#define MAX_ROUNDS			2	//8
#define MAX_LEVELS			40
#define MAX_CHECKS			4

// Player.
#define MAX_DIFFICULTY		4
#define MAX_LIVES			3

// Sprites.
#define SPRITE_TILES		256

#define PIXELS_WIDE			256
#define PIXELS_HIGH			192
#define LEVELS_SIDE			240
#define PLAYER_DEAD			224
//#define DEATH_PX_HI			224		// TODO delete
//#define OCEAN_PX_HI			168		// TODO delete

#define SCREEN_WIDE			32
#define SCREEN_LESS_ONE		SCREEN_WIDE - 1
#define SCREEN_HIGH			24
#define OCEANS_HIGH			3		// TODO - in gfx mgr only?

//#define MAX_JUMPS			1024	// TODO delete
//#define WAVES_HIGH		21		// TODO delete


#define MAX_MUSIC			4
#define MAX_TILE_OBJECTS	16

#define INVALID_INDEX		-1

#define TILE_IMAGE_SCREEN	144
#define SHARE_TEXT_ROW		3

#define CLEAR_TILE_BLACK	59
#define CLEAR_TILE_BLUE		0


// Delay
#define NORMAL_DELAY		50

// Commands
#define MAX_COMMANDS		64
#define COMMAND_NONE_MASK	0b00000000

#define COMMAND_LEFT_MASK	0b00000001
#define COMMAND_MIDD_MASK	0b00000010
#define COMMAND_RGHT_MASK	0b00000100
#define COMMAND_HIGH_MASK	0b00001000
#define COMMAND_DOWN_MASK	0b00010000
#define COMMAND_JUMP_MASK	0b00100000
#define COMMAND_SWAP_MASK	0b01000000
#define COMMAND_FLIP_MASK	0b10000000

#endif//_GLOBAL_MANAGER_H_