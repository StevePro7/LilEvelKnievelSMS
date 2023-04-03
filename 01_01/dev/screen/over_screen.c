#include "over_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/input_manager.h"
#include "../engine/game_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/level_manager.h"
#include "../engine/player_manager.h"
#include "../engine/scroll_manager.h"
#include "../engine/riff_manager.h"
#include "../engine/tile_manager.h"
#include "../devkit/_sms_manager.h"
#include "../devkit/_snd_manager.h"
#include "../banks/bank2.h"

static unsigned char check;

static void printGameOver()
{
	const unsigned char *tiles = bggame_tiles__tilemap__bin;
	unsigned char x, y, d;

	x = 4;
	y = 0;
	d = 0;
	//engine_graphics_manager_image( tiles, TILE_TURTLE_FLIP, x + 0, y + 1, 4, 3 );
	engine_graphics_manager_image( tiles, TILE_TURTLE_FLIP, x + 4, y + 1, 4, 3 );
	engine_graphics_manager_image( tiles, TILE_TURTLE_FLIP, x + 8, y, 4, 3 );
	engine_graphics_manager_image_flip( tiles, TILE_TURTLE_FLIP, x + 12 + d, y, 4, 3 );
	engine_graphics_manager_image_flip( tiles, TILE_TURTLE_FLIP, x + 16 + d, y + 1, 4, 3 );
	//engine_graphics_manager_image_flip( tiles, TILE_TURTLE_FLIP, x + 20 + d, y + 1, 4, 3 );

	y = 5;
	//engine_graphics_manager_image( tiles, TILE_TURTLE_FLIP, x + 0, y - 1, 4, 3 );
	engine_graphics_manager_image( tiles, TILE_TURTLE_FLIP, x + 4, y - 1, 4, 3 );
	engine_graphics_manager_image( tiles, TILE_TURTLE_FLIP, x + 8, y, 4, 3 );
	engine_graphics_manager_image_flip( tiles, TILE_TURTLE_FLIP, x + 12 + d, y, 4, 3 );
	engine_graphics_manager_image_flip( tiles, TILE_TURTLE_FLIP, x + 16 + d, y - 1, 4, 3 );
	//engine_graphics_manager_image_flip( tiles, TILE_TURTLE_FLIP, x + 20 + d, y - 1, 4, 3 );

	// TODO - localize
	engine_font_manager_text( "GAME", x + 10, 3 );
	engine_font_manager_text( "OVER", x + 10, 4 );
}

void screen_over_screen_load()
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
//	engine_player_manager_draw();							// Don't draw player for game over to differentiate cont screen

	engine_graphics_manager_sea();
	//engine_graphics_manager_clouds( go->game_cloud );
	engine_level_manager_draw_screen( checkScreen );		// Weird - must draw this twice otherwise clouds + sea don't draw??

	printGameOver();
	devkit_SMS_displayOn();

//egine_music_manager_playnorepeat( 5);		// cont

	check = 0;
}

void screen_over_screen_update( unsigned char *screen_type )
{
	//signed char input1, input2;
	unsigned char index;// , maxim;
	if( 1==check )
	{
		if( !devkit_PSGGetStatus() )
		{
			devkit_SMS_mapROMBank( bggame_tiles__tiles__psgcompr_bank );
			engine_music_manager_stop();
			engine_sound_manager_stop();
			//engine_font_manager_text( "FINISH", 20, 10 );
			// Resume from init
			*screen_type = screen_type_start;
			return;
		}
	}
	else
	{
		index = RIFF_START_OVER;
		engine_riff_manager_loop( index );
		check = 1;
		// TODO magic number.
		engine_music_manager_playnorepeat( 5 );
	}

	//engine_scroll_manager_update( 0 );
	//engine_player_manager_draw();
	*screen_type = screen_type_over;
}
