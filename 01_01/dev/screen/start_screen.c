#include "start_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/game_manager.h"
#include "../engine/hack_manager.h"
#include "../engine/input_manager.h"
#include "../engine/level_manager.h"
#include "../engine/riff_manager.h"
#include "../engine/player_manager.h"
#include "../engine/scroll_manager.h"
#include "../engine/storage_manager.h"
#include "../engine/timer_manager.h"
#include "../engine/util_manager.h"
#include "../devkit/_sms_manager.h"
#include "../devkit/_snd_manager.h"
#include "../banks/fixedbank.h"
#include "../banks/bank2.h"
#include <stdbool.h>

#ifdef _CONSOLE
#else
#pragma disable_warning 126
#endif

#define STARTING_SCROLLING		1
#define MAX_START_SCREENS		5

static unsigned char reset;
static unsigned char delay;
static unsigned char check;
static bool flag;

void screen_start_screen_load()
{
	struct_player_object *po = &global_player_object;
	struct_level_object *lo = &global_level_object;
	struct_game_object *go = &global_game_object;
	unsigned char player_loadY;
	unsigned char checkScreen;
	unsigned char game_difficulty;
	unsigned char game_world;
	unsigned char game_point;
	unsigned char start_level;
	unsigned char cloud;
	unsigned char space;

	cloud = engine_random_manager_next( SPRITE_TILES );
	engine_game_manager_set_cloud_form( cloud );

	game_difficulty = difficulty_type_normal;
	game_world = 0;
	game_point = 0;
	start_level = engine_random_manager_next( MAX_START_SCREENS );
	start_level += MAX_LEVELS;

	engine_level_manager_init( start_level );
	engine_player_manager_initX( game_difficulty, game_world );

	devkit_SMS_displayOff();
	engine_graphics_manager_screen( CLEAR_TILE_BLUE );

	// Work in terms of screens.
	checkScreen = lo->check_width * game_point;
	engine_level_manager_draw_screen( checkScreen );

	engine_player_manager_loadX( checkScreen );
	player_loadY = level_platforms[ po->lookX ];
	engine_player_manager_loadY( player_loadY );
	engine_player_manager_draw();

	engine_util_manager_locale_texts( 4, 9, 7 );


	// Draw screen specific graphics.
	engine_graphics_manager_title();
	engine_graphics_manager_sea();
	engine_level_manager_draw_screen( checkScreen );

	if( STARTING_SCROLLING )
	{
		engine_scroll_manager_para_load( 0, 0 );
		engine_scroll_manager_para_update( 0 );
	}

	devkit_SMS_displayOn();

	space = !go->game_saved ? 2 : 10;
	engine_delay_manager_load( NORMAL_DELAY );
	engine_reset_manager_load( NORMAL_DELAY * space );
	reset = 0;
	delay = 0;
	check = stage_mode_inc0;
	flag = true;
}

void screen_start_screen_update( unsigned char *screen_type )
{
	struct_player_object *po = &global_player_object;
	struct_game_object *go = &global_game_object;
	struct_hack_object *ho = &global_hack_object;

	unsigned char input;
	unsigned char cloud;

	if( stage_mode_inc1 == check )
	{
		engine_scroll_manager_para_update( 0 );
		if( !devkit_PSGSFXGetStatus() )
		{
			engine_sound_manager_stop();
			devkit_SMS_mapROMBank( bggame_tiles__tiles__psgcompr_bank );

			// We have seen the start screen at least once = save.
			engine_game_manager_set_game_saved( switch_mode_yes );

			// Read cheat sheet first time around.
			if( !go->game_sheet )
			{
				*screen_type = screen_type_intro;
				return;
			}

			*screen_type = screen_type_diff;
			return;
		}
	}
	else
	{
		input = engine_input_manager_hold( input_type_fire1 );
		if( input )
		{
			engine_player_manager_draw();
			engine_scroll_manager_para_update( 0 );

			cloud = engine_random_manager_next( SPRITE_TILES );
			engine_game_manager_set_cloud_form( cloud );

			engine_util_manager_locale_texts( 4, 9, 7 );
			engine_sound_manager_play( sound_type_accept );
			check = stage_mode_inc1;
			return;
		}
		input = engine_input_manager_hold( input_type_fire2 );
		if( input )
		{
			engine_scroll_manager_para_update( 0 );
			*screen_type = screen_type_title;
			return;
		}

		delay = engine_delay_manager_update();
		if( delay )
		{
			if( !ho->hack_delay )
			{
				flag = !flag;
				if( flag )
				{
					engine_util_manager_locale_texts( 4, 9, 7 );
				}
				else
				{
					engine_util_manager_locale_blank( 0, 9, 7 );
				}
			}
		}

		if( STARTING_SCROLLING )
		{
			engine_scroll_manager_para_update( 2 );
		}

		reset = engine_reset_manager_update();
		if( reset )
		{
			engine_util_manager_locale_blank( 0, 9, 7 );
			*screen_type = screen_type_demo;
			return;
		}
	}

	engine_player_manager_animate( po->player_frame );
	engine_player_manager_draw();
	engine_random_manager_rand();
	*screen_type = screen_type_start;
}
