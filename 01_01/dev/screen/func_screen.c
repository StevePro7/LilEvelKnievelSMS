#include "func_screen.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/input_manager.h"
#include "../engine/riff_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/fixedbank.h"
#include "../banks/bank2.h"

#define MAX_RIFF_TEST	25

static unsigned char index;

void screen_func_screen_load()
{
	devkit_SMS_displayOff();
	engine_graphics_manager_screen( CLEAR_TILE_BLUE );
	engine_font_manager_text( "RIFF TEST SCREEN", 10, 2 );
	engine_font_manager_data( index, 14, 9 );
	engine_font_manager_text( ( unsigned char* ) riff_object_texts[ index ], 10, 10 );
	devkit_SMS_displayOn();
}

void screen_func_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	unsigned char loops, count, value;

	input = engine_input_manager_hold( input_type_up );
	if( input && index > 0 )
	{
		index--;
		engine_font_manager_data( index, 14, 9 );
		engine_font_manager_text( ( unsigned char* ) riff_object_texts[ index ], 10, 10 );
	}

	input = engine_input_manager_hold( input_type_down );
	if( input && index < MAX_RIFF_TEST )
	{
		index++;
		engine_font_manager_data( index, 14, 9 );
		engine_font_manager_text( ( unsigned char* ) riff_object_texts[ index ], 10, 10 );
	}

	input = engine_input_manager_hold( input_type_fire1 );
	if( input )
	{
		count = riff_counts[ index ];
		value = riff_indexs[ index ];
		if( 1 == count )
		{
			engine_riff_manager_play( value );
		}
		else
		{
			for( loops = 0; loops < count; loops++ )
			{
				engine_riff_manager_play( loops + value );
			}
		}
	}

	*screen_type = screen_type_func;
}
