#include "cont_screen.h"
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
#include "../engine/tile_manager.h"
#include "../devkit/_sms_manager.h"
#include "../devkit/_snd_manager.h"
#include "../banks/bank2.h"

#define CURSOR_Y	4

static unsigned char cursorX[] = { 12, 17 };
static unsigned char cursorIdx;
static unsigned char check;

// TODO delete
//static unsigned char offset;
//static void printStuff( unsigned char offset )
//{
//	engine_font_manager_text( "CONTINUE?", offset, 0 );
//	engine_font_manager_text( ">YES  NO", offset, 1 );
//	engine_font_manager_text( "  GAME  ", offset, 2 );
//	engine_font_manager_text( "  OVER  ", offset, 3 );
//	engine_font_manager_data( offset, 1 + offset, 4 );
//	//engine_font_manager_text( "-123456789A123456789B123456789C=", 1 + offset, 2 );
//}

static void printCursor()
{
	engine_font_manager_char( ' ', cursorX[ 0 ], CURSOR_Y );
	engine_font_manager_char( ' ', cursorX[ 1 ], CURSOR_Y );
	engine_font_manager_char( '>', cursorX[ cursorIdx ], CURSOR_Y );
}
static void printContinue()
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
	engine_font_manager_text( "CONTINUE", x + 8, 3 );
	engine_font_manager_text( " YES  NO", x + 8, 4 );
}

void screen_cont_screen_load()
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

	engine_graphics_manager_sea();
	//engine_graphics_manager_clouds( go->game_cloud );
	engine_level_manager_draw_screen( checkScreen );		// Weird - must draw this twice otherwise clouds + sea don't draw??

	printContinue();
	printCursor();

	devkit_SMS_displayOn();

	//engine_riff_manager_init();
	//engine_command_manager_init();
	engine_music_manager_playnorepeat( 4);
	cursorIdx = 0;
	check = 0;
}

void screen_cont_screen_update( unsigned char *screen_type )
{
	struct_player_object *po = &global_player_object;
	struct_game_object *go = &global_game_object;
	unsigned char input1, input2;
	
	if( !devkit_PSGGetStatus() )
	{
		devkit_SMS_mapROMBank( bggame_tiles__tiles__psgcompr_bank );
		engine_music_manager_stop();
		engine_sound_manager_stop();
//engine_font_manager_text( "FINISH", 20, 10 );
		// Resume from init
		*screen_type = screen_type_over;
		return;
	}

	input1 = engine_input_manager_hold( input_type_left );
	input2 = engine_input_manager_hold( input_type_right );
	if( input1 || input2 )
	{
		cursorIdx = 1 - cursorIdx;
		printCursor();
	}

	input1 = engine_input_manager_hold( input_type_fire1 );
	input2 = engine_input_manager_hold( input_type_fire2 );
	if( input1 || input2 )
	{
		// SFX
		devkit_SMS_mapROMBank( bggame_tiles__tiles__psgcompr_bank );
		engine_music_manager_stop();
		engine_sound_manager_stop();
		if( 1 == cursorIdx )
		{
			// Game Over
			*screen_type = screen_type_over;
			return;
		}
		else
		{
			// todo SOUND FX
			// Resume from init
			engine_game_manager_set_game_start( switch_mode_yes );
			engine_player_manager_lives( go->game_difficulty );
			*screen_type = screen_type_load;
			return;
		}
	}

	engine_player_manager_animate( po->player_frame );
	engine_player_manager_draw();
	*screen_type = screen_type_cont;
}


//void screen_cont_screen_loadX()
//{
//	struct_scroll_object *so = &global_scroll_object;
//	unsigned char scroll = so->scrollLeftX;
//
//	unsigned char valueX = 256 - scroll;
//	unsigned char tester = valueX >> 3;
//	//unsigned char lookup1;
//	//lookup1 = so->scrollLeftX  & SCREEN_LESS_ONE;
//
//	//unsigned char scroll = 0;
//	//offset = scroll >> 3;
//	//devkit_SMS_setBGScrollX( 0 );
//
////	devkit_SMS_displayOff();
////	engine_graphics_manager_screen( CLEAR_TILE_BLUE );
//
////	engine_player_manager_draw();
//
////	devkit_SMS_displayOn();
//}