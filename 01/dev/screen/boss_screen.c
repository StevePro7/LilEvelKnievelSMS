#include "boss_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/input_manager.h"
#include "../engine/player_manager.h"
#include "../banks/bank2.h"

static unsigned char index;

void screen_boss_screen_load()
{
	////unsigned char byte1, byte2;
	//unsigned int command_frame_index;

	////byte1 = 0xA4;
	////byte2 = 0x00;

	////command_frame_index = byte2 * 256 + byte1;

	//command_frame_index = 0x00A5;
	//engine_font_manager_data( command_frame_index, 15, 5 );
	//engine_font_manager_text( "BOSS SCREEN!!", 10, 2 );

	index = 0;
	engine_font_manager_text( "BOSS SCREEN!!", 10, 2 );

	//engine_player_manager_initX( 1, 1 );
	//engine_player_manager_loadY( 16 );
	////engine_player_manager_draw();
	engine_player_manager_head();

	engine_font_manager_data( index, 14, 9 );
	engine_font_manager_text( ( unsigned char* ) song_object_texts[ index ], 10, 10 );
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
	if( input && index < 8 )
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
		engine_sound_manager_play( index );
	}


	//engine_player_manager_draw();
	engine_player_manager_head();
	*screen_type = screen_type_boss;
}
