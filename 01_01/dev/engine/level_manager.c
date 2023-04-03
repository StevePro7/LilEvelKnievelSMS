#include "level_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"
#include "tile_manager.h"
#include "util_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/fixedbank.h"
#include "../banks/bank12.h"
#include "../banks/bank2.h"
#include <stdbool.h>

#define LEVEL_FLIP_TILE_FLAG	8

// Global variable.
struct_level_object global_level_object;

void engine_level_manager_init( unsigned char level )
{
	struct_level_object *lo = &global_level_object;
	lo->column_draw = SCREEN_LESS_ONE;

	devkit_SMS_mapROMBank( FIXED_BANK );
	if( level >= MAX_LEVELS )
	{
		lo->level_data = ( unsigned char* ) extra_object_data[ level - MAX_LEVELS ];
		lo->level_size = extra_object_size[ level - MAX_LEVELS ];
		lo->level_bank = extra_object_bank[ level - MAX_LEVELS ];
	}
	else
	{
		lo->level_data = ( unsigned char* ) level_object_data[ level ];
		lo->level_size = level_object_size[ level ];
		lo->level_bank = level_object_bank[ level ];
	}

	lo->level_check = lo->level_size >> 2;			// equivalent to divide by MAX_CHECKS [4].
	lo->check_width = lo->level_check >> 5;			// equivalent to divide by SCREEN_WIDE 32.
	// IMPORTANT
	// Must store level_size as 1px less to ensure scrolling finishes OK.
	lo->level_size -= 1;
}

void engine_level_manager_draw_screen( unsigned char checkScreen )
{
	struct_level_object *lo = &global_level_object;
	unsigned int scrollColumn;
	unsigned char index;

	// Reset column draw each full screen render.
	lo->column_draw = SCREEN_LESS_ONE;

	scrollColumn = checkScreen * SCREEN_WIDE;
	for( index = 0; index < SCREEN_WIDE; index++ )
	{
		engine_level_manager_draw_column( scrollColumn + index );
	}
}

void engine_level_manager_draw_column( unsigned int scrollColumn )
{
	struct_level_object *lo = &global_level_object;
	unsigned char level_data, level_column;
	unsigned char level_object, level_platform;
	bool flip = false;

	lo->column_draw++;
	if( lo->column_draw >= SCREEN_WIDE )
	{
		lo->column_draw = 0;
	}

	devkit_SMS_mapROMBank( lo->level_bank );
	level_data = lo->level_data[ scrollColumn ];
	engine_util_manager_convertByteToNibbles( level_data, &level_column, &level_object );

	level_platform = tiles_object_platform[ level_object ];
	level_platforms[ lo->column_draw ] = level_platform;
	if( level_column >= LEVEL_FLIP_TILE_FLAG )
	{
		flip = true;
		level_column -= LEVEL_FLIP_TILE_FLAG;
	}

	engine_tile_manager_draw_column( level_object, lo->column_draw, level_column, flip );
}