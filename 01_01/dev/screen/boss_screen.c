#include "boss_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/input_manager.h"
#include "../engine/player_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/bank2.h"

#define MAX_SONG_TEST	6

static unsigned char index;

void screen_boss_screen_load()
{
	index = 0;

	devkit_SMS_displayOff();
	engine_graphics_manager_screen( CLEAR_TILE_BLUE );
	engine_font_manager_text( "SONG TEST SCREEN", 10, 2 );
	engine_font_manager_data( index, 14, 9 );
	engine_font_manager_text( ( unsigned char* ) song_object_texts[ index ], 10, 10 );
	devkit_SMS_displayOn();
}

void screen_boss_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	input = engine_input_manager_hold( input_type_up );
	if( input && index > 0 )
	{
		index--;
		engine_font_manager_data( index, 14, 9 );
		engine_font_manager_text( ( unsigned char* ) song_object_texts[ index ], 10, 10 );
	}

	input = engine_input_manager_hold( input_type_down );
	if( input && index < MAX_SONG_TEST )
	{
		index++;
		engine_font_manager_data( index, 14, 9 );
		engine_font_manager_text( ( unsigned char* ) song_object_texts[ index ], 10, 10 );
	}

	input = engine_input_manager_hold( input_type_fire1 );
	if( input )
	{
		engine_music_manager_stop();
		engine_music_manager_play( index );
	}

	input = engine_input_manager_hold( input_type_fire2 );
	if( input )
	{
		engine_music_manager_stop();
		engine_sound_manager_play( index );
	}

	*screen_type = screen_type_boss;
}
