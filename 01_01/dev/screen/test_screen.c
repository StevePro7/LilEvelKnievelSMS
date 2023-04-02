#include "test_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/collision_manager.h"
#include "../engine/command_manager.h"
#include "../engine/debug_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/global_manager.h"
#include "../engine/input_manager.h"
#include "../engine/level_manager.h"
#include "../engine/player_manager.h"
#include "../engine/scroll_manager.h"
#include "../engine/timer_manager.h"
#include <stdbool.h>

#ifdef _CONSOLE
#else
#pragma disable_warning 110
#pragma disable_warning 261
#endif

static bool complete;
static signed int deltaY;

static void printScrollInfo()
{
	struct_scroll_object *so = &global_scroll_object;
	unsigned char lookup1;
	unsigned char lookup2;
	engine_font_manager_data( so->scrollLeftX, 20, 0 );
	engine_font_manager_data( so->scrollRight, 20, 1 );

	lookup1 = so->scrollLeftX  & SCREEN_LESS_ONE;
	engine_font_manager_data( lookup1, 20, 2 );
	lookup2 = so->scrollRight  & SCREEN_LESS_ONE;
	engine_font_manager_data( lookup2, 20, 3 );
}

void screen_test_screen_load()
{
	struct_game_object *go = &global_game_object;
	engine_frame_manager_load();
	engine_frame_manager_draw();

	//engine_music_manager_play( 3 );
	complete = false;
	deltaY = 0;

	engine_font_manager_text( "TEST SCREEN", 1, 5 );
	//printScrollInfo();
}

void screen_test_screen_update( unsigned char *screen_type )
{
	// TODO delete
	struct_frame_object *fo = &global_frame_object;

	struct_scroll_object *so = &global_scroll_object;
	struct_player_object *po = &global_player_object;
	struct_level_object *lo = &global_level_object;
	struct_game_object *go = &global_game_object;
	unsigned char input1;
	unsigned char input2;
	// TODO TESTING
	unsigned char input3;

	unsigned char deltaX;
	//signed int deltaY;
	unsigned char loops;
	//signed char collision;
	enum_scroll_state scroll_state;
	enum_player_state player_state;

	unsigned char command = COMMAND_NONE_MASK;
	player_state = po->player_state;
	deltaX = 0;
	deltaY = 0;

	input3 = engine_input_manager_hold( input_type_up );
	if( input3 )
	{
		engine_font_manager_text( "TEST UPDATE", 1, 7 );
		//*screen_type = screen_type_beat;
		//*screen_type = screen_type_cont;
		return;
	}
	input3 = engine_input_manager_hold( input_type_down );
	if( input3 )
	{
		//engine_font_manager_text( "TEST UPDATE", 1, 7 );
		//*screen_type = screen_type_beat;
		*screen_type = screen_type_cont;
		return;
	}

	input1 = engine_input_manager_hold( input_type_left );
	input2 = engine_input_manager_move( input_type_right );
	//input1 = 1;		// TODO delete
	if( input1 || input2 )
	{
		if( 50 == fo->frame_count )//|| 8 == fo->frame_count )
		{
			command = engine_command_manager_build( po->player_state, 0, 1, 0, 0, 0, 1 );		//Jump index = 1.
			//command = engine_command_manager_build( po->player_state, 0, 0, 0, 0, 0, 1 );		//Jump index = 2.
			//command = engine_command_manager_build( po->player_state, 0, 1, 0, 0, 0, 1 );		//Jump index = 3.
			//command = engine_command_manager_build( po->player_state, 0, 1, 0, 0, 0, 1 );		//Jump index = 4.
		}
		else
		{
			command = engine_command_manager_build( po->player_state, 0, 1, 0, 0, 0, 0 );
		}

		//if( 24 == fo->frame_count )
		{
			//command = engine_command_manager_build( po->player_state, 0, 0, 0, 0, 1, 0 );
		}
		//else if( 3 == fo->frame_count )
		//{
		//	command = engine_command_manager_build( po->player_state, 0, 1, 0, 0, 0, 0 );
		//}

		//command = engine_command_manager_build( po->player_state, 0, 1, 0, 0, 0, 0 );

		//if( 60 == fo->frame_count )
		//{
		//	command = engine_command_manager_build( po->player_state, 0, 1, 0, 0, 1, 0 );
		//}
		//if( 96 == fo->frame_count )//|| 6 == fo->frame_count )//|| 8 == fo->frame_count )
		//{
		//	command = engine_command_manager_build( po->player_state, 0, 1, 1, 0, 0, 1 );
		//}
		//if( 170 == fo->frame_count )
		//{
		//	command = engine_command_manager_build( po->player_state, 0, 0, 0, 0, 0, 1 );
		//}
		//if( 180 == fo->frame_count )
		//{
		////	command = engine_command_manager_build( po->player_state, 1, 0, 0, 0, 0, 1 );
		//}
		////if( 5 == fo->frame_count )
		////{
		////	//command = engine_command_manager_build( po->player_state, 0, 0, 0, 0, 1, 0 );
		////}


		//command = engine_command_manager_build( po->player_state, 0, 1, 0, 0, 0, 0 );

		engine_frame_manager_update();
		engine_frame_manager_draw();
		//if( 60 == fo->frame_count )
		//{
		//	command = engine_command_manager_build( po->player_state, 0, 1, 0, 0, 1, 0 );
		//}
		//if( 70 == fo->frame_count )//|| 6 == fo->frame_count )//|| 8 == fo->frame_count )
		//{
		//	command = engine_command_manager_build( po->player_state, 0, 0, 0, 0, 0, 1 );
		//}
		//if( 110 == fo->frame_count )
		//{
		//	command = engine_command_manager_build( po->player_state, 0, 0, 0, 0, 0, 1 );
		//}
		//if( 180 == fo->frame_count )
		//{
		//	command = engine_command_manager_build( po->player_state, 0, 1, 1, 0, 0, 1 );
		//}
		//if( 250 == fo->frame_count )
		//{
		//	command = engine_command_manager_build( po->player_state, 0, 0, 0, 0, 1, 0 );
		//}
	}

	if( COMMAND_NONE_MASK != command )
	{
		// Get horizontal movement.
		deltaX = engine_player_manager_get_deltaX( po->player_state, command );
		deltaX = 8; // TODO delete

		// TODO delete this debugging info - for newIndex!!
		//engine_font_manager_data( deltaX, 31, 6 );
		// TODO delete this debugging info - for newIndex!!

		//if( po->player_state == player_state_isintheair )
		//{
		//	//totalX += deltaX;
		//	//frameX++;
		//}
		//else
		//{
		//	if( fo->frame_count > 1 && po->player_state == player_state_isonground && !//flag )
		//	{
		//		//flag = 1;
		//		engine_font_manager_data( //totalX, 30, 2 );
		//		engine_font_manager_data( //frameX, 30, 3 );
		//	}
		//}

		// Get button action.
		engine_player_manager_set_action( po->player_frame, command );

		// No scroll.
		//if( 0 == deltaX )
		//{
		//	engine_scroll_manager_update( 0 );
		//}
		//else
		//{
			//if( !complete ) {}
		for( loops = 0; loops < deltaX; loops++ )
		{
			scroll_state = engine_scroll_manager_update( 1 );
			//printScrollInfo();	// TODO delete


			if( scroll_state_tile == scroll_state )
			{
				engine_level_manager_draw_column( so->scrollColumn );

				//if (fo->frame_count == 0 || po->player_state == 1 )
				//{
				//	scroll_count++;		// TODO delete as only used for impossible jump debugging
				//}
			}
			else if( scroll_state_line == scroll_state )
			{
				engine_game_manager_inc_checkpoint();
				//TODO used for debugging - remove
				//engine_font_manager_data( go->game_point, 20, go->game_point );
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

		// TODO delete
		//printScrollInfo();	// TODO delete
		// TODO delete


		// TODO delete this debugging info - for newIndex!!
		//engine_font_manager_data( scroll_count, 31, 8 );
		//engine_font_manager_data( scroll_count / 4, 31, 9 );
		// TODO delete this debugging info - for newIndex!!

		// Set horizontal movement.
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

	// Store command for future use.
	engine_command_manager_update( command );
	//}
	//else
	//{
	//	engine_scroll_manager_update( 0 );
	//}

	engine_player_manager_draw();
	engine_player_manager_head();

	//engine_debug_manager_printout();
	//	engine_font_manager_data( deltaY, 30, 2 );
	//	engine_font_manager_data( po->posnY, 30, 3 );

	// Check to see if player completes level.
	if( complete )
	{
		//engine_scroll_manager_update( 0 );		// TODO remove - nop
		*screen_type = screen_type_pass;
		return;
	}

	// Check if moving on to the dying sequence.
	if( player_state_isnowdying == player_state )
	{
		//engine_scroll_manager_update( 0 );		// TODO remove - nop
		*screen_type = screen_type_dead;
		return;
	}

	*screen_type = screen_type_test;
}

