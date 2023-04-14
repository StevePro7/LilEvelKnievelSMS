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

#define MAX_RIFF_PASS	3

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
	unsigned char index;
	unsigned char game_world, game_round, game_point;
	unsigned char game_level;

	player_passX = engine_player_manager_get_deltaX( po->player_state, co->prev_command );
	player_passX >>= 1;
	player_endY = engine_player_manager_finish();

	engine_player_manager_draw();
	engine_player_manager_head();
	swap = stage_mode_inc0;

	engine_riff_manager_init();
	engine_music_manager_stop();

	index = engine_random_manager_next( MAX_RIFF_PASS );
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
}

void screen_pass_screen_update( unsigned char *screen_type )
{
	struct_player_object *po = &global_player_object;
	struct_game_object *go = &global_game_object;

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
				*screen_type = next_screen;
				return;
			}
			else
			{
				if( stage_mode_inc2 == swap )
				{
					engine_player_manager_pass_frame();
					swap = stage_mode_inc3;
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
			if( stage_mode_inc2 == swap )
			{
				engine_player_manager_pass( player_passX, player_endY );
			}

			engine_player_manager_draw();
			engine_player_manager_head();
		}

		if( stage_mode_inc1 == swap )
		{
			if( loops < count )
			{
				engine_riff_manager_play( loops + value );
				loops++;
			}
			else
			{
				swap = stage_mode_inc2;

				// Play SFX
				engine_sound_manager_play( sound_type_level );
			}
		}
	}
	else
	{
		engine_player_manager_pass( player_passX, player_endY );
		swap = stage_mode_inc1;
	}

	// Don't draw player here as "blinks"
	//engine_player_manager_draw();
	engine_player_manager_head();
	*screen_type = screen_type_pass;
}