#include "graphics_manager.h"
#include "asm_manager.h"
#include "content_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "tile_manager.h"
#include "util_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/bank2.h"

#define CLOUD_ROW_START		4
#define CLOUD_COL_START		1
#define CLOUD_COL_WIDES		8

#ifdef _CONSOLE
#else
#pragma disable_warning 261
#endif

void engine_graphics_manager_common()
{
	devkit_SMS_displayOff();
	engine_asm_manager_clear_VRAM();
	engine_content_manager_bggame();
	engine_content_manager_sprite();
	engine_graphics_manager_screen( CLEAR_TILE_BLACK );
	devkit_SMS_setSpriteMode( devkit_SPRITEMODE_NORMAL() );
	devkit_SMS_displayOn();
}

void engine_graphics_manager_screen( unsigned int tile )
{
	unsigned int index;
	unsigned int maxim;

	devkit_SMS_setNextTileatXY( 0, 0 );
	maxim = SCREEN_WIDE * SCREEN_HIGH;
	for( index = 0; index < maxim; index++ )
	{
		devkit_SMS_setTile( tile );
	}
}

void engine_graphics_manager_clouds( unsigned char data )
{
	unsigned int cloud_tile_type[] = { TILE_CLOUD_LARGE , TILE_CLOUD_SMALL };
	unsigned char result, height;
	unsigned char flip1, flip2;

	result = ( COMMAND_FLIP_MASK & data ) == COMMAND_FLIP_MASK;
	height = ( COMMAND_SWAP_MASK & data ) == COMMAND_SWAP_MASK;
	flip1 = ( COMMAND_JUMP_MASK & data ) == COMMAND_JUMP_MASK;
	flip2 = ( COMMAND_DOWN_MASK & data ) == COMMAND_DOWN_MASK;
	if( cloud_type_large == result )
	{
		engine_tile_manager_draw_cloud( cloud_tile_type[ cloud_type_large ], CLOUD_COL_START + 0 * CLOUD_COL_WIDES, CLOUD_ROW_START + 1, flip1 );
		engine_tile_manager_draw_cloud( cloud_tile_type[ cloud_type_small ], CLOUD_COL_START + 1 * CLOUD_COL_WIDES, CLOUD_ROW_START + height, flip2 );
	}
	else
	{
		engine_tile_manager_draw_cloud( cloud_tile_type[ cloud_type_small ], CLOUD_COL_START + 0 * CLOUD_COL_WIDES, CLOUD_ROW_START + height, flip1 );
		engine_tile_manager_draw_cloud( cloud_tile_type[ cloud_type_large ], CLOUD_COL_START + 1 * CLOUD_COL_WIDES, CLOUD_ROW_START + 1, flip2 );
	}

	result = ( COMMAND_HIGH_MASK & data ) == COMMAND_HIGH_MASK;
	height = ( COMMAND_RGHT_MASK & data ) == COMMAND_RGHT_MASK;
	flip1 = ( COMMAND_MIDD_MASK & data ) == COMMAND_MIDD_MASK;
	flip2 = ( COMMAND_LEFT_MASK & data ) == COMMAND_LEFT_MASK;
	if( cloud_type_large == result )
	{
		engine_tile_manager_draw_cloud( cloud_tile_type[ cloud_type_large ], CLOUD_COL_START + 2 * CLOUD_COL_WIDES, CLOUD_ROW_START + 1, flip1 );
		engine_tile_manager_draw_cloud( cloud_tile_type[ cloud_type_small ], CLOUD_COL_START + 3 * CLOUD_COL_WIDES, CLOUD_ROW_START + height, flip2 );
	}
	else
	{
		engine_tile_manager_draw_cloud( cloud_tile_type[ cloud_type_small ], CLOUD_COL_START + 2 * CLOUD_COL_WIDES, CLOUD_ROW_START + height, flip1 );
		engine_tile_manager_draw_cloud( cloud_tile_type[ cloud_type_large ], CLOUD_COL_START + 3 * CLOUD_COL_WIDES, CLOUD_ROW_START + 1, flip2 );
	}
}

void engine_graphics_manager_title()
{
	engine_graphics_manager_image( bggame_tiles__tilemap__bin, TILE_PLAY_TITLE, 4, 0, 24, 3 );
}

void engine_graphics_manager_image( const unsigned char *tiles, unsigned int tileMap, unsigned char x, unsigned char y, unsigned char w, unsigned char h )
{
	unsigned int idx;
	unsigned int val;
	unsigned char row, col;

	for( row = 0; row < h; row++ )
	{
		for( col = 0; col < w; col++ )
		{
			idx = tileMap + row * 2 * TILMAP_WIDE + col * 2;
			val = tiles[ idx ];
			devkit_SMS_setNextTileatXY( x + col, y + row );
			devkit_SMS_setTile( ( val ) );
		}
	}
}

void engine_graphics_manager_image_flip( const unsigned char *tiles, unsigned int tileMap, unsigned char x, unsigned char y, unsigned char w, unsigned char h )
{
	unsigned int idx;
	unsigned int tmp;
	unsigned int val;
	unsigned char row, col;
	unsigned int flippedX;

	flippedX = devkit_TILE_FLIPPED_X();
	for( row = 0; row < h; row++ )
	{
		for( col = 0; col < w; col++ )
		{
			tmp = w - col - 1;
			idx = tileMap + row * 2 * TILMAP_WIDE + tmp * 2;
			val = tiles[ idx ];
			val |= flippedX;
			devkit_SMS_setNextTileatXY( x + col, y + row );
			devkit_SMS_setTile( ( val ) );
		}
	}
}

// NOTES
/*
OLD
unsigned char sea_line1[] = { 66, 66, 67, 68, };
unsigned char sea_line2[] = { 65, 65, 65, 73, };
unsigned char sea_line3[] = { 65, 71, 72, 65, };


Z			116
black			120

skyblue0	64	124
blue1		65	126	60
wave2		66	128	61
wave3		67	130	62
wave4		68	132	63
wave5		69	134	64
wave6		70	136	65
wave7		71	138	66
wave8		72	140	67
wave9		73	142	68

white		2920		191
*/
void engine_graphics_manager_sea()
{
	// TODO -call API in tile mgr
	const unsigned char *tiles = bggame_tiles__tilemap__bin;

	//TODO fixed bank this
	unsigned char row, col;
	unsigned char x, y;
	unsigned char tileIdx, tileMap;
	unsigned int idx, val;

	// Original data - new data is 2x tiles offset

	// TODO use TILE_SEA as offset here!
	unsigned char sea_lines[] =
	{
		66, 66, 67, 68,
		65, 65, 65, 73,
		65, 71, 72, 65,
	};

	for( row = 0; row < OCEANS_HIGH; row++ )
	{
		y = 21 + row;
		//x = 0;
		for( x = 0; x < SCREEN_WIDE; x += 4 )
		{

			for( col = 0; col < TILE_STRIP; col++ )
			{
				tileIdx = row * TILE_STRIP + col;
				tileMap = sea_lines[ tileIdx ];
				tileMap -= 2;
				tileMap *= 2;

				idx = tileMap;// +0 * 2 * TILMAP_WIDE + 0 * 2;
				val = tiles[ idx ];
				devkit_SMS_setNextTileatXY( x + col, y + 0 );
				devkit_SMS_setTile( ( val ) );
			}
		}
	}
}

void engine_graphics_manager_level_stats( unsigned char game_world, unsigned char game_round, unsigned char game_point )
{
	unsigned char delta;
	delta = 1;

	engine_font_manager_valu( ( game_world + delta ), 9, SHARE_TEXT_ROW );
	engine_font_manager_valu( ( game_round + delta ), 18, SHARE_TEXT_ROW );
	engine_font_manager_valu( ( game_point + delta ), 27, SHARE_TEXT_ROW );
}

void engine_graphics_manager_level_texts()
{
	engine_util_manager_locale_texts( 6, 3, SHARE_TEXT_ROW );
	engine_util_manager_locale_texts( 7, 12, SHARE_TEXT_ROW );
	engine_util_manager_locale_texts( 8, 21, SHARE_TEXT_ROW );

	engine_font_manager_char( '0', 8, SHARE_TEXT_ROW );
	engine_font_manager_char( '0', 17, SHARE_TEXT_ROW );
	engine_font_manager_char( '0', 26, SHARE_TEXT_ROW );
	engine_font_manager_text( "/04", 28, SHARE_TEXT_ROW );
}