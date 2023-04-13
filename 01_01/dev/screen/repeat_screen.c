#include "repeat_screen.h"
#include "../engine/collision_manager.h"
#include "../engine/command_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/input_manager.h"	
#include "../engine/level_manager.h"
#include "../engine/player_manager.h"
#include "../engine/scroll_manager.h"
#include "../engine/storage_manager.h"
#include "../engine/timer_manager.h"
#include "../engine/util_manager.h"
#include "../devkit/_sms_manager.h"
#include <stdbool.h>

#ifdef _CONSOLE
#else
#pragma disable_warning 110
#pragma disable_warning 261
#endif

static bool complete;
static unsigned char frame_counter;
static unsigned char available;
static unsigned char local_prev_command;

void screen_repeat_screen_load()
{
	// init_screen
	struct_player_object *po = &global_player_object;
	struct_level_object *lo = &global_level_object;
	struct_game_object *go = &global_game_object;
	unsigned char player_loadY;
	unsigned char checkScreen;
	unsigned char cloud_formation = engine_random_manager_next( SPRITE_TILES );

	engine_level_manager_init( go->game_level );
	engine_player_manager_initX( go->game_difficulty, go->game_world );
	engine_collision_manager_init( go->game_difficulty );

	// load_screen
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
	engine_graphics_manager_clouds( go->game_cloud );
	engine_level_manager_draw_screen( checkScreen );		// Weird - must draw this twice otherwise clouds + sea don't draw??
	devkit_SMS_displayOn();

	engine_font_manager_text( "NEW REPEAT SCREEN", 10, 2 );

	engine_frame_manager_load();
	//engine_frame_manager_draw();
	engine_command_manager_init();

	complete = false;
	frame_counter = 0;
	local_prev_command = COMMAND_NONE_MASK;

	available = engine_storage_manager_available();
	if( available )
	{
		engine_storage_manager_load();
	}
}

void screen_repeat_screen_update( unsigned char *screen_type )
{
	struct_frame_object *fo = &global_frame_object;
	struct_scroll_object *so = &global_scroll_object;
	struct_player_object *po = &global_player_object;
	struct_level_object *lo = &global_level_object;
	struct_game_object *go = &global_game_object;
	struct_command_object *co = &global_command_object;

	unsigned char input1;// input2, input3, input4, input5, input6;
	unsigned char input2;
	unsigned char deltaX;
	signed int deltaY;
	unsigned char loops;

	enum_scroll_state scroll_state;
	enum_player_state player_state;

	unsigned char command = COMMAND_NONE_MASK;
	player_state = po->player_state;

	// Quit out.
	if( !available )
	{
		*screen_type = screen_type_option;
		return;
	}

	if( !complete )
	{
		input1 = engine_input_manager_hold( input_type_left );
		input2 = engine_input_manager_move( input_type_right );
		if( input1 || input2 )
		{
			if( command_frame_index[ frame_counter ] == fo->frame_count )
			{
				command = command_this_command[ frame_counter ];
				local_prev_command = command;
				frame_counter++;
			}
			else
			{
				command = local_prev_command;
			}

			engine_frame_manager_update();
			//engine_frame_manager_draw();
		}

		if( COMMAND_NONE_MASK != command )
		{
			// Get horizontal movement.
			deltaX = engine_player_manager_get_deltaX( po->player_state, command );

			// Get button action.
			engine_player_manager_set_action( po->player_frame, command );

			for( loops = 0; loops < deltaX; loops++ )
			{
				scroll_state = engine_scroll_manager_update( 1 );
				if( scroll_state_tile == scroll_state )
				{
					engine_level_manager_draw_column( so->scrollColumn );
				}
				//IMPORTANT - do NOT implement this code as will mis-align the checkpoint!
				//else if( scroll_state_line == scroll_state )
				//{
				//	engine_game_manager_inc_checkpoint();
				//}
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

		engine_player_manager_draw();

		// Check to see if player completes level.
		if( complete )
		{
			*screen_type = screen_type_option;
			return;
		}

		// Check if moving on to the dying sequence.
		if( player_state_isnowdying == player_state )
		{
			*screen_type = screen_type_option;
			return;
		}
	}

	engine_player_manager_draw();
	*screen_type = screen_type_repeat;
}
