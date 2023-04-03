#include "play_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/collision_manager.h"
#include "../engine/command_manager.h"
#include "../engine/debug_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/hack_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/input_manager.h"
#include "../engine/level_manager.h"
#include "../engine/player_manager.h"
#include "../engine/riff_manager.h"
#include "../engine/scroll_manager.h"
#include "../engine/timer_manager.h"
#include "../engine/util_manager.h"
#include "../devkit/_snd_manager.h"
#include <stdbool.h>

#ifdef _CONSOLE
#else
#pragma disable_warning 110
#pragma disable_warning 261
#endif

static bool complete;
static void play_checkpoint_riff();

void screen_play_screen_load()
{
	struct_game_object *go = &global_game_object;
	struct_hack_object *ho = &global_hack_object;
	engine_frame_manager_load();

	if( go->game_start )
	{
		engine_music_manager_play( go->game_music );
		engine_game_manager_set_game_start( switch_mode_no );
	}
	else
	{
		engine_music_manager_resume();
	}

	complete = false;

}

void screen_play_screen_update( unsigned char *screen_type )
{
	// TODO delete
	struct_frame_object *fo = &global_frame_object;

	struct_scroll_object *so = &global_scroll_object;
	struct_player_object *po = &global_player_object;
	struct_command_object *co = &global_command_object;
	struct_level_object *lo = &global_level_object;
	struct_game_object *go = &global_game_object;

	unsigned char input1, input2, input3, input4, input5, input6;
	unsigned char command;

	unsigned char deltaX;
	signed int deltaY;
	unsigned char loops;
	enum_scroll_state scroll_state;
	enum_player_state player_state;

	command = COMMAND_NONE_MASK;
	player_state = po->player_state;
	deltaX = 0;
	deltaY = 0;

	input1 = engine_input_manager_move( input_type_left );
	input2 = engine_input_manager_move( input_type_right );
	input3 = engine_input_manager_move( input_type_up );
	input4 = engine_input_manager_move( input_type_down );
	input5 = engine_input_manager_hold( input_type_fire1 );
	input6 = engine_input_manager_hold( input_type_fire2 );

	//input1 = engine_input_manager_hold( input_type_left );
	//input2 = engine_input_manager_move( input_type_right );
	////input1 = 1;		// TODO delete
	//if( input1 || input2 )
	//{
	//	if( 2 == fo->frame_count )
	//	{
	//		//command = engine_command_manager_build( po->player_state, 1, 0, 0, 0, 0, 1 );		//Jump index = 1.
	//		//command = engine_command_manager_build( po->player_state, 0, 0, 0, 0, 0, 1 );		//Jump index = 2.
	//		//command = engine_command_manager_build( po->player_state, 0, 1, 0, 0, 0, 1 );		//Jump index = 3.
	//		command = engine_command_manager_build( po->player_state, 0, 1, 1, 0, 0, 1 );		//Jump index = 4.
	//	}
	//	else
	//	{
	//		command = engine_command_manager_build( po->player_state, 0, 1, 0, 0, 0, 0 );
	//	}
	//}

	command = engine_command_manager_build( po->player_state, input1, input2, input3, input4, input5, input6 );
	//engine_font_manager_data( po->player_state, 31, 1 );
	//engine_font_manager_data( command, 31, 2 );

	if( command != co->prev_command )
	{
		// Store command for future use.
		engine_command_manager_update( command );

		// Record command to play back later...
		//engine_command_manager_record( fo->frame_count, command );

		//engine_font_manager_data( fo->frame_count, 30, 4 );
		//engine_font_manager_data( command, 30, 5 );
		//	engine_command_manager_draw();
	}

	engine_frame_manager_update();
	//engine_frame_manager_draw();

	if( COMMAND_NONE_MASK != command )
	{
		// Get horizontal movement.
		deltaX = engine_player_manager_get_deltaX( po->player_state, command );
		//deltaX = 1; // TODO delete


		// Get button action.
		engine_player_manager_set_action( po->player_frame, command );

		// Implement scrolling.
		for( loops = 0; loops < deltaX; loops++ )
		{
			scroll_state = engine_scroll_manager_update( 1 );
			if( scroll_state_tile == scroll_state )
			{
				engine_level_manager_draw_column( so->scrollColumn );
			}
			else if( scroll_state_line == scroll_state )
			{
				engine_game_manager_inc_checkpoint();
				play_checkpoint_riff();
			}
			else if( scroll_state_comp == scroll_state )
			{
				complete = scroll_state_comp == scroll_state;
				if( complete )
				{
					break;
				}
			}
		}

		// Set horizontal movement.
		engine_player_manager_horz( deltaX );

		// Get / set vertical movement.
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
		player_state = engine_player_manager_collision( po->player_state, po->lookX, po->tileY, deltaY, po->posnY, go->game_isgod );

		// Finally, check if player forcing downward drop.
		if( player_state_isintheair == po->player_state )
		{
			// If player forces down while in the air then only apply on the descent!
			if( ( COMMAND_DOWN_MASK & command ) == COMMAND_DOWN_MASK )
			{
				if( deltaY > 0 )
				{
					deltaY = engine_player_manager_get_deltaY();
					engine_player_manager_vert( deltaY );
					engine_player_manager_bounds( deltaY, po->posnY, go->game_isgod );
				}
			}

			// General all-purpose collision detection routine.
			player_state = engine_player_manager_collision( po->player_state, po->lookX, po->tileY, deltaY, po->posnY, go->game_isgod );
		}
	}

	engine_player_manager_draw();
	engine_player_manager_head();


	// Check to see if player completes level.
	if( complete )
	{
		*screen_type = screen_type_pass;
		return;
	}

	// Check if moving on to the dying sequence.
	if( player_state_isnowdying == player_state )
	{
		*screen_type = screen_type_dead;
		return;
	}

	*screen_type = screen_type_play;
}

static void play_checkpoint_riff()
{
	struct_game_object *go = &global_game_object;
	struct_hack_object *ho = &global_hack_object;
	unsigned char index, maxim;

	// TODO magic number
	maxim = 9;
	index = engine_random_manager_next( maxim );

	devkit_PSGStop();
	if( ho->hack_riffs )
	{
		engine_graphics_manager_level_stats( go->game_world, go->game_round, go->game_point );
		engine_graphics_manager_level_texts();
		engine_riff_manager_loop( index );
	}

	// Clear out the game level statistics.
	engine_util_manager_locale_blank( 3, 0, 3 );
	engine_music_manager_resume();
}