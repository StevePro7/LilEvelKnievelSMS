#include "ready_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/input_manager.h"
#include "../engine/level_manager.h"
#include "../engine/player_manager.h"
#include "../engine/scroll_manager.h"
#include "../engine/util_manager.h"
#include "../devkit/_sms_manager.h"
#include "../devkit/_snd_manager.h"
#include "../banks/bank2.h"
#include <stdbool.h>

static unsigned char cursorX[] = { 2, 11, 20 };
static unsigned char cursorIdx;
static unsigned char game_world, game_round, game_point;
static unsigned char game_level;
static unsigned int game_screen;
static unsigned int numb_screen;
static unsigned char player_loadY;
static unsigned char check;

static void printStats();
static void updateCheck();

// Used for level screen backup
void screen_ready_screen_load()
{
	struct_player_object *po = &global_player_object;
	struct_level_object *lo = &global_level_object;
	struct_game_object *go = &global_game_object;

	game_world = go->game_world;
	game_round = go->game_round;
	game_level = go->game_level;
	game_point = go->game_point;
	game_screen = 0;
	numb_screen = 0;
	cursorIdx = 2;

	devkit_SMS_displayOff();
	engine_graphics_manager_screen( CLEAR_TILE_BLUE );
	engine_graphics_manager_title();
	engine_graphics_manager_sea();

	engine_level_manager_init( game_level );
	numb_screen = lo->level_check >> 3;	// / 8 blocks per screen;
	game_screen = lo->check_width * game_point;
	engine_scroll_manager_load( game_screen, lo->level_check, lo->level_size );
	engine_level_manager_draw_screen( game_screen );

	engine_graphics_manager_level_stats( game_world, game_round, game_point );
	engine_graphics_manager_level_texts();
	printStats();

	engine_font_manager_char( '>', cursorX[ cursorIdx ], SHARE_TEXT_ROW );
	engine_player_manager_initX( go->game_difficulty, go->game_world );
	engine_player_manager_loadX( game_screen );
	player_loadY = level_platforms[ po->lookX ];
	engine_player_manager_loadY( player_loadY );
	engine_player_manager_draw();

	devkit_SMS_displayOn();
	check = stage_mode_inc0;
}

void screen_ready_screen_update( unsigned char *screen_type )
{
	struct_player_object *po = &global_player_object;
	struct_level_object *lo = &global_level_object;
	unsigned char input;
	bool updateLevel = false;

	if( stage_mode_inc1 == check )
	{
		engine_player_manager_draw();
		if( !devkit_PSGSFXGetStatus() )
		{
			engine_sound_manager_stop();
			devkit_SMS_mapROMBank( bggame_tiles__tiles__psgcompr_bank );
			*screen_type = screen_type_init;
			return;
		}
	}

	input = engine_input_manager_hold( input_type_left );
	if( input && 0 != cursorIdx )
	{
		engine_font_manager_char( ' ', cursorX[ cursorIdx ], SHARE_TEXT_ROW );
		cursorIdx--;
		engine_font_manager_char( '>', cursorX[ cursorIdx ], SHARE_TEXT_ROW );
	}

	input = engine_input_manager_hold( input_type_right );
	if( input )
	{
		if( 2 == cursorIdx )
		{
			updateLevel = true;
			if( game_screen < ( numb_screen - 1 ) )
			{
				game_screen++;
				game_point = game_screen / lo->check_width;
			}
		}
		else
		{
			engine_font_manager_char( ' ', cursorX[ cursorIdx ], SHARE_TEXT_ROW );
			cursorIdx++;
			engine_font_manager_char( '>', cursorX[ cursorIdx ], SHARE_TEXT_ROW );
		}
	}

	input = engine_input_manager_hold( input_type_up );
	if( input )
	{
		updateLevel = true;
		if( 0 == cursorIdx )
		{
			if( game_world > 0 )
			{
				game_world--;
			}
		}
		else if( 1 == cursorIdx )
		{
			if( game_level > 0 )
			{
				game_round--;
				game_level--;
				game_point = 0;
				game_screen = lo->check_width * game_point;
			}
		}
		else
		{
			if( game_point > 0 )
			{
				game_point--;
				game_screen = lo->check_width * game_point;
			}
			else
			{
				game_point = 0;
				game_screen = lo->check_width * game_point;
			}
		}
	}
	input = engine_input_manager_hold( input_type_down );
	if( input )
	{
		updateLevel = true;
		if( 0 == cursorIdx )
		{
			if( game_world < ( MAX_WOLRDS - 1 ) )
			{
				game_world++;
				//game_level++;
				game_point = 0;
				game_screen = lo->check_width * game_point;
			}
		}
		else if( 1 == cursorIdx )
		{
			if( game_level < ( MAX_LEVELS - 1 ) )
			{
				game_round++;
				game_level++;
				game_point = 0;
				game_screen = lo->check_width * game_point;
			}
		}
		else
		{
			if( game_point < ( MAX_CHECKS - 1 ) )
			{
				game_point++;
				game_screen = lo->check_width * game_point;
			}
		}
	}

	if( updateLevel )
	{
		updateCheck();

		engine_player_manager_loadX( game_point );
		player_loadY = level_platforms[ po->lookX ];
		engine_player_manager_loadY( player_loadY );

		engine_graphics_manager_level_stats( game_world, game_round, game_point );
		printStats();
	}

	input = engine_input_manager_hold( input_type_fire1 );
	if( input )
	{
		engine_game_manager_set_level_data( game_world, game_round, game_point );
		engine_sound_manager_play( sound_type_accept );
		engine_player_manager_draw();
		check = stage_mode_inc1;
		return;
	}

	input = engine_input_manager_hold( input_type_fire2 );
	if( input )
	{
		engine_game_manager_set_level_data( game_world, game_round, game_point );
		*screen_type = screen_type_diff;
		return;
	}

	engine_player_manager_draw();
	*screen_type = screen_type_ready;
}

static void updateCheck()
{
	struct_level_object *lo = &global_level_object;
	engine_level_manager_init( game_level );
	numb_screen = lo->level_check >> 3;	// / 8 blocks per screen;
	engine_level_manager_draw_screen( game_screen );
}

static void printStats()
{
	unsigned char delta;
	delta = 1;

	engine_font_manager_text( "GAME-LEVEL: ", 5, SHARE_TEXT_ROW + 3 );
	engine_font_manager_text( "NO.SCREENS: ", 5, SHARE_TEXT_ROW + 4 );
	engine_font_manager_text( "SCREEN-NO.: ", 5, SHARE_TEXT_ROW + 5 );

	engine_font_manager_data( game_level + delta, 20, SHARE_TEXT_ROW + 3 );
	engine_font_manager_data( numb_screen, 20, SHARE_TEXT_ROW + 4 );
	engine_font_manager_data( game_screen + delta, 20, SHARE_TEXT_ROW + 5 );
}