#include "intro_screen.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/input_manager.h"
#include "../engine/scroll_manager.h"
#include "../engine/timer_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/bank2.h"

static void print( unsigned char index, unsigned char x, unsigned char y )
{
	engine_font_manager_text( ( unsigned char * ) locale_object_intro[ index ], x, y );
}
static unsigned char delay;

void screen_intro_screen_load()
{
	unsigned char col, row;
	col = 3;
	row = 3;
	devkit_SMS_displayOff();
	engine_graphics_manager_screen( CLEAR_TILE_BLUE );
	engine_graphics_manager_title();

	//engine_font_manager_text( "[[[[[[[[[[[[[[[[[[[[[[[[[[[[", col - 0, row + 0 );
	print( 0, col - 0, row + 0 );
	//engine_font_manager_text( "[=====[CHEAT[SHEET[======[[[", col - 0, row + 1 );
	print( 1, col - 0, row + 1 );
	//engine_font_manager_text( "[[[[[[[[[[[[[[[[[[[[[[[[[[[[", col - 0, row + 2 );
	print( 0, col - 0, row + 2 );
	//engine_font_manager_text( "[[[[[[[[[[[[[[[[[[[[[[[[[[[[", col - 0, row + 3 );
	print( 0, col - 0, row + 3 );
	row += 2;
	//engine_font_manager_text( "[JUMP[CATEGORIES[[ON[GROUND[", col - 0, row + 2 );
	print( 2, col - 0, row + 2 );
	row += 1;

	//engine_font_manager_text( "[SKIP[SMALLEST[[[LEFT+FIRE1[", col - 0, row + 2 );
	print( 3, col - 0, row + 2 );
	//engine_font_manager_text( "[[[[[[[[[[[[[[[[[[[[[[[[[[[[", col - 0, row + 3 );
	print( 0, col - 0, row + 3 );
	//engine_font_manager_text( "[JUMP[STANDARD[[[LEFT+FIRE2[", col - 0, row + 4 );
	print( 4, col - 0, row + 4 );
	//engine_font_manager_text( "[[[[[[[[[[[[[[[[[OR[[[FIRE1[", col - 0, row + 5 );
	print( 5, col - 0, row + 5 );
	//engine_font_manager_text( "[[[[[[[[[[[[[[[[[[[[[[[[[[[[", col - 0, row + 6 );
	print( 0, col - 0, row + 6 );
	//engine_font_manager_text( "[LEAP[SIZEABLE[[RIGHT+FIRE1[", col - 0, row + 7 );
	print( 6, col - 0, row + 7 );
	//engine_font_manager_text( "[[[[[[[[[[[[[[[[OR[[[[FIRE2[", col - 0, row + 8 );
	print( 7, col - 0, row + 8 );
	//engine_font_manager_text( "[[[[[[[[[[[[[[[[[[[[[[[[[[[[", col - 0, row + 9 );
	print( 0, col - 0, row + 9 );
	//engine_font_manager_text( "[HURL[COLOSSAL[[RIGHT+FIRE2[", col - 0, row + 10 );
	print( 8, col - 0, row + 10 );

	//engine_font_manager_text( "[[[[[[[[[[[[[[[[[[[[[[[[[[[[", col - 0, row + 11 );
	//engine_font_manager_text( "[[[[[[[[[[[[[[[[[[[[[[[[[[[[", col - 0, row + 12 );
	//engine_font_manager_text( "[[[[[[[[[[[[[[[[[[[[[[[[[[[[", col - 0, row + 13 );
	print( 0, col - 0, row + 11 );
	print( 0, col - 0, row + 12 );
	print( 0, col - 0, row + 13 );

	row += 13;
	//engine_font_manager_text( "[JUMP[ACTIVITIES[[AIRBORNE![", col - 0, row + 0 );
	print( 9, col - 0, row + 0 );
	//engine_font_manager_text( "[SWAP[DIRECTION[[[[[[[FIRE1[", col - 0, row + 1 );
	print( 10, col - 0, row + 1 );
	//engine_font_manager_text( "[FLIP[SOMERSAULT[[[[[[FIRE2[", col - 0, row + 2 );
	print( 11, col - 0, row + 2 );
	//engine_font_manager_text( "[[[[[[[[[[[[[[[[[[[[[[[[[[[[", col - 0, 22 );
	print( 0, col - 0, 22 );

	engine_scroll_manager_para_load( 0, 0 );
	engine_scroll_manager_para_update( 0 );
	devkit_SMS_displayOn();

	engine_delay_manager_load( NORMAL_DELAY * 10 );
}

void screen_intro_screen_update( unsigned char *screen_type )
{
	unsigned char input1;
	unsigned char delay;

	input1 = engine_input_manager_hold( input_type_fire1 );
	delay = engine_delay_manager_update();
	if( input1 || delay )
	{
		engine_game_manager_set_game_sheet( switch_mode_yes );
		//*screen_type = screen_type_diff;
		return;
	}

	*screen_type = screen_type_intro;
}
