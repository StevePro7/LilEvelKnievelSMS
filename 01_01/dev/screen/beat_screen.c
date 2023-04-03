#include "beat_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/collision_manager.h"
#include "../engine/command_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/input_manager.h"
#include "../engine/level_manager.h"
#include "../engine/player_manager.h"
#include "../engine/riff_manager.h"
#include "../engine/scroll_manager.h"
#include "../engine/sprite_manager.h"
#include "../engine/tile_manager.h"
#include "../engine/timer_manager.h"
#include "../engine/util_manager.h"
#include "../devkit/_sms_manager.h"
#include "../devkit/_snd_manager.h"
#include "../banks/bank2.h"

#ifdef _CONSOLE
#else
#pragma disable_warning 261
#endif

static void printBeatGame();

static bool complete;
static unsigned char frame_counter;
static unsigned char available;
static unsigned char local_prev_command;

static unsigned char lookXs[] = { 5, 13, 17, 17 };
static unsigned char delay;
static unsigned char check;
static unsigned char lookX;
static bool flag;

void screen_beat_screen_load()
{
	// init_screen
	struct_player_object *po = &global_player_object;
	struct_level_object *lo = &global_level_object;
	struct_game_object *go = &global_game_object;
	unsigned char player_loadY;
	unsigned char checkScreen;
	unsigned char beat_level;

	unsigned char game_difficulty;
	unsigned char game_world;
	unsigned char game_point;

	beat_level = 49;
	game_difficulty = go->game_difficulty;
	game_world = 4;
	game_point = 0;

	// Hack to make collision detection work when landing on turtle irrespective of difficulty.
	lookX = lookXs[ game_difficulty ];

	engine_level_manager_init( beat_level );
	engine_player_manager_initX( game_difficulty, game_world );
	engine_collision_manager_init( game_difficulty );

	devkit_SMS_displayOff();
	engine_graphics_manager_screen( CLEAR_TILE_BLUE );
	
	// Work in terms of screens.
	checkScreen = lo->check_width * game_point;
	engine_level_manager_draw_screen( checkScreen );

	engine_player_manager_initX( game_difficulty, game_world );
	engine_player_manager_loadX( checkScreen );
	player_loadY = level_platforms[ po->lookX ];
	engine_player_manager_loadY( player_loadY );
	engine_player_manager_draw();

	engine_graphics_manager_sea();
	printBeatGame();

	devkit_SMS_displayOn();

	engine_frame_manager_load();

	// TODO music magic number?
	engine_game_manager_set_level_data( 0, 0, 0 );
	engine_music_manager_playnorepeat( 6 );
}

void screen_beat_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	struct_scroll_object *so = &global_scroll_object;
	struct_player_object *po = &global_player_object;
	struct_level_object *lo = &global_level_object;
	struct_game_object *go = &global_game_object;
	unsigned char input1;
	unsigned char input2;

	unsigned char deltaX;
	signed int deltaY;
	enum_player_state player_state;

	unsigned char command = COMMAND_NONE_MASK;
	player_state = po->player_state;
	deltaX = 0;
	deltaY = 0;

	input1 = engine_input_manager_hold( input_type_fire1 );
	input2 = engine_input_manager_hold( input_type_fire2 );
	if( !devkit_PSGGetStatus() || input1 || input2 )
	{
		devkit_SMS_mapROMBank( bggame_tiles__tiles__psgcompr_bank );
		engine_music_manager_stop();
		engine_sound_manager_stop();
		*screen_type = screen_type_start;
		return;
	}

	if( 60 == fo->frame_count )
	{
		command = engine_command_manager_build( po->player_state, 0, 0, 0, 0, 1, 0 );
	}
	else if( 20 == fo->frame_count || 40 == fo->frame_count || 80 == fo->frame_count || 100 == fo->frame_count )
	{
		command = engine_command_manager_build( po->player_state, 1, 0, 0, 0, 0, 1 );		//Jump index = 4.
	}
	else if( 10 == fo->frame_count )//|| 8 == fo->frame_count )
	{
		command = engine_command_manager_build( po->player_state, 0, 1, 1, 0, 0, 1 );		//Jump index = 4.
	}
	else
	{
		command = engine_command_manager_build( po->player_state, 0, 0, 0, 0, 0, 0 );
	}

	engine_frame_manager_update();
	//engine_frame_manager_draw();

	if( fo->frame_count >= 150 )
	{
		fo->frame_count = 0;
	}

	if( COMMAND_NONE_MASK != command )
	{
		// Get horizontal movement - NO X-movement.
		deltaX = 0; // TODO delete

		// Get button action.
		engine_player_manager_set_action( po->player_frame, command );

		// Set horizontal movement -NO X-movement
		engine_player_manager_horz( deltaX );

		// Get / set vertical movement.
		deltaY = 0;
		if( player_state_isintheair == po->player_state )
		{
			deltaY = engine_player_manager_get_deltaY();
			engine_player_manager_vert( deltaY );
			engine_player_manager_bounds( deltaY, po->posnY, go->game_isgod );
		}
		else if( player_state_isonground == po->player_state )
		{
			engine_player_manager_animate( po->player_frame );
		}

		// General all-purpose collision detection routine.
		engine_player_manager_collision( po->player_state, lookX, po->tileY, deltaY, po->posnY, go->game_isgod );
	}

	engine_command_manager_update( command );
	engine_player_manager_draw();

	*screen_type = screen_type_beat;
}


static void printBeatGame()
{
	const unsigned char *tiles = bggame_tiles__tilemap__bin;
	unsigned char x, y, d;

	x = 4;
	y = 0;
	d = 0;
	engine_graphics_manager_image( tiles, TILE_TURTLE_FLIP, x + 0, y + 1, 4, 3 );
	engine_graphics_manager_image( tiles, TILE_TURTLE_FLIP, x + 4, y, 4, 3 );
	engine_graphics_manager_image( tiles, TILE_TURTLE_FLIP, x + 8, y, 4, 3 );
	engine_graphics_manager_image_flip( tiles, TILE_TURTLE_FLIP, x + 12 + d, y, 4, 3 );
	engine_graphics_manager_image_flip( tiles, TILE_TURTLE_FLIP, x + 16 + d, y, 4, 3 );
	engine_graphics_manager_image_flip( tiles, TILE_TURTLE_FLIP, x + 20 + d, y + 1, 4, 3 );

	y = 5;
	engine_graphics_manager_image( tiles, TILE_TURTLE_FLIP, x + 0, y - 1, 4, 3 );
	engine_graphics_manager_image( tiles, TILE_TURTLE_FLIP, x + 4, y, 4, 3 );
	engine_graphics_manager_image( tiles, TILE_TURTLE_FLIP, x + 8, y, 4, 3 );
	engine_graphics_manager_image_flip( tiles, TILE_TURTLE_FLIP, x + 12 + d, y, 4, 3 );
	engine_graphics_manager_image_flip( tiles, TILE_TURTLE_FLIP, x + 16 + d, y, 4, 3 );
	engine_graphics_manager_image_flip( tiles, TILE_TURTLE_FLIP, x + 20 + d, y - 1, 4, 3 );

	// TODO - localize
	engine_font_manager_text( "CONGLATURATION", 9, 3 );
	engine_font_manager_text( "AWINNER IS YOU", 9, 4 );
}