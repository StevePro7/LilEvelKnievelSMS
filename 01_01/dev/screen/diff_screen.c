#include "diff_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/input_manager.h"
#include "../engine/level_manager.h"
#include "../engine/player_manager.h"
#include "../engine/storage_manager.h"
#include "../engine/util_manager.h"
#include "../devkit/_sms_manager.h"
#include "../devkit/_snd_manager.h"
#include "../banks/bank2.h"
#include <stdbool.h>

#define CURSOR_X	12

static void setupPlayer();
static void printCursor();

static unsigned char player_loadY;
static unsigned char game_difficulty;
static unsigned char check;

void screen_diff_screen_load()
{
	struct_player_object *po = &global_player_object;
	struct_level_object *lo = &global_level_object;
	struct_game_object *go = &global_game_object;
	unsigned char checkScreen;

	devkit_SMS_displayOff();
	engine_graphics_manager_screen( CLEAR_TILE_BLUE );
	engine_graphics_manager_title();
	engine_graphics_manager_sea();


	//	TODO - localize	TODO - refactor and still work??
	engine_font_manager_text( "SELECT  DIFFICULTY", 7, SHARE_TEXT_ROW + 0 );
	engine_font_manager_text( "EASIER", CURSOR_X + 3, SHARE_TEXT_ROW + 1 );
	engine_font_manager_text( "NORMAL", CURSOR_X + 3, SHARE_TEXT_ROW + 2 );
	engine_font_manager_text( "HARDER", CURSOR_X + 3, SHARE_TEXT_ROW + 3 );
	engine_font_manager_text( "INSANE", CURSOR_X + 3, SHARE_TEXT_ROW + 4 );


	game_difficulty = go->game_difficulty;

	engine_level_manager_init( go->game_level );
	checkScreen = lo->check_width * go->game_point;
	engine_level_manager_draw_screen( checkScreen );

	setupPlayer();
	printCursor();
	devkit_SMS_displayOn();

	engine_player_manager_draw();
	check = stage_mode_inc0;
}

void screen_diff_screen_update( unsigned char *screen_type )
{
	struct_player_object *po = &global_player_object;
	unsigned char input1, input2;
	bool updateDiff = false;

	if( stage_mode_inc1 == check )
	{
		engine_player_manager_draw();
		if( !devkit_PSGSFXGetStatus() )
		{
			engine_sound_manager_stop();
			devkit_SMS_mapROMBank( bggame_tiles__tiles__psgcompr_bank );
			*screen_type = screen_type_level;
			return;
		}
	}

	input2 = engine_input_manager_hold( input_type_left );
	if( input2 )
	{
		updateDiff = true;
		if( 0 == game_difficulty )
		{
			game_difficulty = MAX_DIFFICULTY - 1;
		}
		else
		{
			game_difficulty--;
		}
	}

	input1 = engine_input_manager_hold( input_type_right );
	if( input1 )
	{
		updateDiff = true;
		if( ( MAX_DIFFICULTY - 1 ) == game_difficulty )
		{
			game_difficulty = 0;
		}
		else
		{
			game_difficulty++;
		}
	}

	if( updateDiff )
	{
		printCursor();
		setupPlayer();
	}

	input1 = engine_input_manager_hold( input_type_fire1 );
	if( input1 )
	{
		engine_game_manager_set_difficulty( game_difficulty );
		engine_player_manager_lives( game_difficulty );
		engine_storage_manager_save();

		engine_sound_manager_play( sound_type_accept );
		engine_player_manager_draw();
		check = stage_mode_inc1;
		return;
	}

	input1 = engine_input_manager_hold( input_type_fire2 );
	if( input1 )
	{
		engine_game_manager_set_difficulty( game_difficulty );
		engine_player_manager_lives( game_difficulty );
		engine_storage_manager_save();

		*screen_type = screen_type_start;
		return;
	}

	engine_player_manager_draw();
	*screen_type = screen_type_diff;
}

static void setupPlayer()
{
	struct_player_object *po = &global_player_object;
	struct_game_object *go = &global_game_object;

	engine_player_manager_initX( game_difficulty, go->game_world );
	engine_player_manager_loadX( go->game_point );
	player_loadY = level_platforms[ po->lookX ];
	engine_player_manager_loadY( player_loadY );
}

static void printCursor()
{
	unsigned char index;
	for( index = 0; index < MAX_DIFFICULTY; index++ )
	{
		engine_font_manager_char( ' ', CURSOR_X, SHARE_TEXT_ROW + index + 1 );
	}

	engine_font_manager_char( '>', CURSOR_X, SHARE_TEXT_ROW + game_difficulty + 1 );
}
