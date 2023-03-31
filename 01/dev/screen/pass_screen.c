#include "pass_screen.h"
#include "../engine/asm_manager.h"
#include "../engine/audio_manager.h"
#include "../engine/command_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/input_manager.h"
#include "../engine/level_manager.h"
#include "../engine/player_manager.h"
#include "../engine/riff_manager.h"
#include "../engine/scroll_manager.h"
#include "../engine/timer_manager.h"
#include "../engine/util_manager.h"
#include "../devkit/_sms_manager.h"
#include "../devkit/_snd_manager.h"
#include "../banks/bank2.h"

static unsigned char player_passX;
static unsigned char player_endY;
static unsigned char swap;
static unsigned char count;
static unsigned char value;
static unsigned char loops;
static unsigned char next_screen;

void screen_pass_screen_load()
{
	struct_game_object *go = &global_game_object;

	struct_command_object *co = &global_command_object;
	struct_player_object *po = &global_player_object;
	static unsigned char index, maxim;
	unsigned char game_world, game_round, game_point;
	unsigned char game_level;

	player_passX = engine_player_manager_get_deltaX( po->player_state, co->prev_command );
	player_passX >>= 1;
	player_endY = engine_player_manager_finish();

	engine_player_manager_draw();
	engine_player_manager_head();
	swap = 0;

	engine_riff_manager_init();
	//devkit_PSGStop();
	engine_music_manager_stop();

	// TODO - update magic number?
	maxim = 3;
	index = engine_random_manager_next( maxim );
	index += RIFF_START_PASS;
	value = riff_indexs[ index ];
	count = riff_counts[ index ];
	loops = 0;

	next_screen = screen_type_init;
	game_world = go->game_world;
	game_round = go->game_round;
	game_point = go->game_point;
	game_level = go->game_level;
	engine_graphics_manager_level_texts();
	engine_graphics_manager_level_stats( game_world, game_round, game_point );

	// TODO - pause and goto interim screen to increment level until beat_screen...
	game_round++;
	if( MAX_ROUNDS == game_round )
	{
		game_round = 0;
		game_world++;
		if( MAX_WOLRDS == game_world )
		{
			game_world = 0;
			next_screen = screen_type_beat;
		}
	}
	game_point = 0;
	engine_game_manager_set_level_data( game_world, game_round, game_point );

	// TODO remove only used for testing
	//game_level += 1;
	//engine_font_manager_data( go->game_level, 20, 15 );
	//engine_font_manager_data( game_level, 20, 16 );
	//engine_game_manager_set_level_test( game_level );
	//engine_font_manager_data( go->game_level, 20, 18 );
	//engine_font_manager_data( game_level, 20, 19 );
	// TODO remove only used for testing
}

// TODO - show the world round point text on screen when pass.
void screen_pass_screen_update( unsigned char *screen_type )
{
	struct_player_object *po = &global_player_object;
	struct_game_object *go = &global_game_object;

//	unsigned char next_screen;
	//unsigned char input1, input2;
	//unsigned char check;

	// TODO - had to comment out for now as was still playing SFX despite the fact told not to...!!
	//// Player chance to quit out to start screen.
	//input1 = engine_input_manager_move( input_type_up );
	//if( input1 )
	//{
	//	check = engine_reset_manager_update();
	//	if( check )
	//	{
	//		input2 = engine_input_manager_move( input_type_fire1 );
	//		//input3 = engine_input_manager_hold( input_type_fire2 );
	//		if( input2 )
	//		{
	//			engine_music_manager_stop();
	//			engine_sound_manager_stop();

	//			devkit_SMS_mapROMBank( bggame_tiles__tiles__psgcompr_bank );
	//			*screen_type = screen_type_start;
	//			return;
	//		}
	//	}
	//}
	//else
	//{
	//	engine_reset_manager_reset();
	//}


	if( swap )
	{
		if( po->posnX >= LEVELS_SIDE )
		{
			// Check if SFX complete...
			if( !devkit_PSGSFXGetStatus() )
			{
				engine_sound_manager_stop();

				// A bit sucks but we MUST go back to tiles bank for further graphics...
				devkit_SMS_mapROMBank( bggame_tiles__tiles__psgcompr_bank );
				//*screen_type = screen_type_pass;
				//*screen_type = screen_type_init;
				*screen_type = next_screen;
				return;
			}
			else
			{
				if( 2 == swap )
				{
					engine_player_manager_pass_frame();
					swap = 3;
				}

				// Continue invoke function in case player still in air.
				engine_player_manager_pass( player_passX, player_endY );
				engine_player_manager_draw();
				engine_player_manager_head();
			}
		}
		else
		{
			// Wrap to block movement on riff play.
			if( 2 == swap )
			{
				engine_player_manager_pass( player_passX, player_endY );
			}

			engine_player_manager_draw();
			engine_player_manager_head();
		}

		if( 1 == swap )
		{
			if( loops < count )
			{
				engine_riff_manager_play( loops + value );
				loops++;
			}
			else
			{
				swap = 2;
				// Play SFX
				engine_sound_manager_play( 1 );
			}
		}
	}
	else
	{
		engine_player_manager_pass( player_passX, player_endY );
		swap = 1;
	}

	// don't draw player here as "blinks"
	//engine_player_manager_draw();
	engine_player_manager_head();
	*screen_type = screen_type_pass;
}