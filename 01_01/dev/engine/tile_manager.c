#include "tile_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/fixedbank.h"
#include "../banks/bank2.h"

#define TILE_SCROLL_HIGH	8
#define TILE_SCROLL_ROWS	14

static unsigned int flippedX;

void engine_tile_manager_init()
{
	flippedX = devkit_TILE_FLIPPED_X();
}

//void engine_tile_manager_draw_columns( unsigned char tile_type, unsigned char x, unsigned char col )
void engine_tile_manager_draw_column( unsigned char tile_type, unsigned char x, unsigned char col, bool flip )
{
	const unsigned char *tiles = bggame_tiles__tilemap__bin;
	unsigned int idx;
	unsigned int tmp;
	unsigned int val;
	unsigned char row;
	devkit_SMS_mapROMBank( bggame_tiles__tiles__psgcompr_bank );

	tmp = tiles_object_indexes[ tile_type ];
	for( row = 0; row < TILE_SCROLL_ROWS; row++ )
	{
		idx = tmp + row * 2 * TILMAP_WIDE + col * 2;
		val = tiles[ idx ];
		if( flip )
		{
			// TODO - do I want to do this or pass unsigned int??
			val |= flippedX;
		}

		devkit_SMS_setNextTileatXY( x, TILE_SCROLL_HIGH + row );
		devkit_SMS_setTile( val );
	}
}

void engine_tile_manager_draw_cloud( unsigned int tileMap, unsigned char x, unsigned char y, bool flip )
{
	const unsigned char *tiles = bggame_tiles__tilemap__bin;
	unsigned int idx;
	unsigned int val;
	unsigned char row, col, tmp;
	const unsigned char w = 8;
	const unsigned char h = 3;

	for( row = 0; row < h; row++ )
	{
		for( col = 0; col < w; col++ )
		{
			tmp = flip ? ( w - col - 1 ) : col;
			idx = tileMap + row * 2 * TILMAP_WIDE + col * 2;
			val = tiles[ idx ];
			if( flip )
			{
				// TODO - do I want to do this or pass unsigned int??
				val |= flippedX;
			}

			devkit_SMS_setNextTileatXY( x + tmp, y + row );
			devkit_SMS_setTile( ( val ) );
		}
	}
}
