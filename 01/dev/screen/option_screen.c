#include "option_screen.h"
#include "../engine/command_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/input_manager.h"
#include "../engine/player_manager.h"
#include "../engine/scroll_manager.h"
#include "../engine/storage_manager.h"
#include "../devkit/_sms_manager.h"

static unsigned char cursorY;
//static void printCmds();

void screen_option_screen_load()
{
	unsigned char idx;

	devkit_SMS_displayOff();
	engine_graphics_manager_screen( CLEAR_TILE_BLUE );

	engine_scroll_manager_load( 0, 0, 0 );
	engine_scroll_manager_update( 0 );
	for( idx = 0; idx < SCREEN_HIGH; idx++ )
	{
		engine_font_manager_text( "                                ", 0, idx );
	}

	engine_font_manager_text( "OPTION SCREEN", 10, 2 );
	engine_font_manager_text( "  RECORD CMDS", 10, 0 );
	engine_font_manager_text( "  PLAYBACK!!!", 10, 1 );
	cursorY = 0;
	engine_font_manager_char( '>', 10, cursorY );
	devkit_SMS_displayOn();
}

void screen_option_screen_update( unsigned char *screen_type )
{
	unsigned char input1, input2, input3;
	input1 = engine_input_manager_hold( input_type_up );
	input2 = engine_input_manager_hold( input_type_down );
	//unsigned char available;
	if( input1 || input2 )
	{
		engine_font_manager_char( ' ', 10, cursorY );
		cursorY = 1 - cursorY;
		engine_font_manager_char( '>', 10, cursorY );
	}

	input3 = engine_input_manager_hold( input_type_fire1 );
	//input3 = 1;
	if( input3 )
	{
		if( 0 == cursorY )
		{
			//cursorY = 1;
		//	*screen_type = screen_type_intro;
		//	*screen_type = screen_type_func;
			*screen_type = screen_type_record;
			return;
		}
		if( 1 == cursorY )
		{
			//available = engine_storage_manager_available();
			//if( available )
			//{
			//	engine_storage_manager_load();
			//	printCmds();
			//}
			//engine_font_manager_data( available, 31, 1 );
			//*screen_type = screen_type_test;
			*screen_type = screen_type_repeat;
			return;
		}
	}
	else
	{
		input3 = engine_input_manager_hold( input_type_fire2 );
		if( input3 )
		{
			engine_storage_manager_kill();
			//engine_font_manager_text( "ERASER SCREEN", 10, 2 );
			*screen_type = screen_type_level;
			return;
		}
	}
//	engine_player_manager_draw();
	*screen_type = screen_type_option;
}

//static void printCmds()
//{
//	engine_font_manager_data( command_frame_index[ 0 ], 21, 1 );
//	engine_font_manager_data( command_frame_index[ 1 ], 21, 2 );
//	engine_font_manager_data( command_this_command[ 0 ], 26, 1 );
//	engine_font_manager_data( command_this_command[ 1 ], 26, 2 );
//}