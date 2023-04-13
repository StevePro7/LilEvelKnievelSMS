#include "title_screen.h"
#include "splash_screen.h"
#include "../engine/asm_manager.h"
#include "../engine/content_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/input_manager.h"
#include "../engine/player_manager.h"
#include "../engine/riff_manager.h"
#include "../engine/sprite_manager.h"
#include "../engine/storage_manager.h"
#include "../engine/timer_manager.h"
#include "../engine/util_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/fixedbank.h"
#include "../banks/bank3.h"

#define MAX_SPOTS	9
#define MAX_FLIPS	8

static void draw_sprite( unsigned char idx, unsigned char mode, unsigned char x, unsigned char y );

static unsigned char flip_posX[ MAX_SPOTS ] = { 8, 30, 52, 74, 96, 118, 140, 162, 184 };
static unsigned char flip_posY[ MAX_SPOTS ] = { 128, 112, 104, 100, 96, 100, 104, 112, 128 };

static const unsigned char *flip_ptr;
static unsigned char index;
static unsigned char value;
static unsigned char check;
static unsigned char delay;

void screen_title_screen_load()
{
	struct_game_object *go = &global_game_object;
	unsigned char flips;

	devkit_SMS_displayOff();
	engine_asm_manager_clear_VRAM();
	engine_content_manager_titles();
	// IMPORTANT must draw title !!
	engine_graphics_manager_image( titles_tiles__tilemap__bin, TILE_IMAGE_SCREEN, 8, 0, 16, 12 );

	engine_content_manager_sprite();
	engine_util_manager_locale_texts( 1, 28, 23 );
	engine_util_manager_locale_texts( 2, 8, 22 );
	engine_util_manager_locale_texts( 3, 7, 23 );
	devkit_SMS_displayOn();

	devkit_SMS_setSpriteMode( devkit_SPRITEMODE_ZOOMED() );

	index = 0;
	check = stage_mode_inc0;

	// If we have never saved [played] game before then always play first animation.
	flips = 0;
	if( !go->game_saved )
	{
		engine_game_manager_set_game_saved( switch_mode_yes );
		engine_storage_manager_save();
	}
	else
	{
		// Otherwise choose random animation on subsequent attempts.
		flips = engine_random_manager_next( MAX_FLIPS );
	}

	flip_ptr = flip_array_ptr[ flips ];
	engine_riff_manager_init();
	value = riff_indexs[ RIFF_START_TITLE ];
	engine_delay_manager_load( NORMAL_DELAY );
	engine_game_manager_set_game_sheet( switch_mode_no );
}

void screen_title_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	unsigned char x, y, f;

	if( check )
	{
		delay = engine_delay_manager_update();
		if( delay )
		{
			*screen_type = screen_type_begin;
			return;
		}

		x = flip_posX[ index ];
		y = flip_posY[ index ];
		f = flip_ptr[ index ];
		draw_sprite( f + 2, sprite_mode_zoomed, x, y );
		return;
	}

	engine_riff_manager_play( index + value );

	x = flip_posX[ index ];
	y = flip_posY[ index ];
	f = flip_ptr[ index ];
	draw_sprite( f + 2, sprite_mode_zoomed, x, y );

	engine_input_manager_update();
	input = engine_input_manager_move( input_type_fire1 );
	if( input || index + 1 >= MAX_SPOTS )
	{
		check = stage_mode_inc1;
		return;
	}

	index++;
	engine_random_manager_rand();
	*screen_type = screen_type_title;
}

static void draw_sprite( unsigned char idx, unsigned char mode, unsigned char x, unsigned char y )
{
	engine_sprite_manager_mode( idx, mode, x - 8, y );

	engine_sprite_manager_zoom( mode, 0, y + mode * 0 );
	engine_sprite_manager_zoom( mode, 8, y + mode * 0 );
	engine_sprite_manager_zoom( mode, 192, y + mode * 0 );
	engine_sprite_manager_zoom( mode, 224, y + mode * 0 );

	engine_sprite_manager_zoom( mode, 0, y + mode * 16 );
	engine_sprite_manager_zoom( mode, 8, y + mode * 16 );
	engine_sprite_manager_zoom( mode, 192, y + mode * 16 );
	engine_sprite_manager_zoom( mode, 224, y + mode * 16 );
}