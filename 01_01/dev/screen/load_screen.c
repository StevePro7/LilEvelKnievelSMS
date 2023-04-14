#include "load_screen.h"
#include "../engine/asm_manager.h"
#include "../engine/command_manager.h"
#include "../engine/content_manager.h"
//#include "../engine/debug_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/hack_manager.h"
#include "../engine/input_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/level_manager.h"
#include "../engine/player_manager.h"
#include "../engine/riff_manager.h"
#include "../engine/scroll_manager.h"
#include "../engine/tile_manager.h"
#include "../engine/timer_manager.h"
#include "../engine/util_manager.h"
#include "../devkit/_sms_manager.h"

#define MAX_RIFF_LOAD	3

#ifdef _CONSOLE
#else
#pragma disable_warning 261
#endif

static unsigned char check;
static unsigned char delay;

void screen_load_screen_load()
{
	struct_player_object *po = &global_player_object;
	struct_level_object *lo = &global_level_object;
	struct_game_object *go = &global_game_object;
	unsigned char player_loadY;
	unsigned char checkScreen;

	devkit_SMS_displayOff();
	engine_graphics_manager_screen( CLEAR_TILE_BLUE );


	// Work in terms of screens.
	checkScreen = lo->check_width * go->game_point;
	engine_scroll_manager_load( checkScreen, lo->level_check, lo->level_size );
	engine_level_manager_draw_screen( checkScreen );


	engine_player_manager_initX( go->game_difficulty, go->game_world );
	engine_player_manager_loadX( checkScreen );
	player_loadY = level_platforms[ po->lookX ];
	engine_player_manager_loadY( player_loadY );
	engine_player_manager_draw();
	engine_player_manager_head();

	engine_graphics_manager_sea();
	engine_graphics_manager_clouds( go->game_cloud );
	engine_level_manager_draw_screen( checkScreen );		// Weird - must draw this twice otherwise clouds + sea don't draw??

	engine_graphics_manager_level_stats( go->game_world, go->game_round, go->game_point );
	engine_graphics_manager_level_texts();
	devkit_SMS_displayOn();

	engine_riff_manager_init();
	engine_command_manager_init();
	engine_delay_manager_load( NORMAL_DELAY * 2 );
	delay = 0;
	check = stage_mode_inc0;
}

void screen_load_screen_update( unsigned char *screen_type )
{
	struct_game_object *go = &global_game_object;
	struct_hack_object *ho = &global_hack_object;
	unsigned char index;
	unsigned char input;

	if( !check )
	{
		check = stage_mode_inc1;
		*screen_type = screen_type_load;
		return;
	}
	else
	{
		engine_player_manager_draw();
		engine_player_manager_head();
		if( go->game_start && ho->hack_riffs )
		{
			index = engine_random_manager_next( MAX_RIFF_LOAD );
			index += RIFF_START_LOAD;

			engine_riff_manager_loop( index );

			// Clear out the game level statistics.
			engine_util_manager_locale_blank( 3, 0, 3 );
		}
		else
		{
			input = engine_input_manager_hold( input_type_right );
			delay = engine_delay_manager_update();
			if( input || delay )
			{
				// Clear out the game level statistics.
				engine_util_manager_locale_blank( 3, 0, 3 );

				*screen_type = screen_type_play;
				return;
			}

			*screen_type = screen_type_load;
			return;
		}
	}

	// Resume onto play after load.
	*screen_type = screen_type_play;
}
