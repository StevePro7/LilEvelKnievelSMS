#include "command_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "hack_manager.h"
#include "global_manager.h"
#include "player_manager.h"

#ifdef _CONSOLE
#else
#pragma disable_warning 261
#endif

// Global variable.
struct_command_object global_command_object;

void engine_command_manager_init()
{
	struct_command_object *co = &global_command_object;
	unsigned char index;
	co->frame_index = 0;
	co->curr_command = COMMAND_NONE_MASK;
	co->prev_command = COMMAND_NONE_MASK;

	for( index = 0; index < MAX_COMMANDS; index++ )
	{
		command_frame_index[ index ] = COMMAND_NONE_MASK;
		command_this_command[ index ] = COMMAND_NONE_MASK;
	}
}

void engine_command_manager_load( unsigned int *storage_frame_index, unsigned char* storage_this_command )
{
	struct_command_object *co = &global_command_object;
	unsigned char index;

	for( index = 0; index < MAX_COMMANDS; index++ )
	{
		command_frame_index[ index ] = storage_frame_index[ index ];
		command_this_command[ index ] = storage_this_command[ index ];
	}
}

void engine_command_manager_record( unsigned int frame, unsigned char command )
{
	struct_command_object *co = &global_command_object;
	if( co->frame_index < MAX_COMMANDS )
	{
		command_frame_index[ co->frame_index ] = frame;
		command_this_command[ co->frame_index ] = command;
		co->frame_index++;
	}

	co->prev_command = command;
}

void engine_command_manager_update( unsigned char command )
{
	struct_command_object *co = &global_command_object;
	co->prev_command = command;
}


// TODO delete - only used for debugging.
//void engine_command_manager_draw()
//{
//	struct_command_object *co = &global_command_object;
//	unsigned char index;
//
//	for( index = 0; index < MAX_COMMANDS; index++ )
//	{
//		engine_font_manager_data( command_frame_index[ index ], 20, index + 4 );
//		engine_font_manager_data( command_this_command[ index ], 30, index + 4 );
//	}
//}

unsigned char engine_command_manager_build( unsigned char state, unsigned char input1, unsigned char input2, unsigned char input3, unsigned char input4, unsigned char input5, unsigned char input6 )
{
	struct_player_object *po = &global_player_object;
	struct_hack_object *ho = &global_hack_object;
	unsigned char command = COMMAND_NONE_MASK;

	// TODO inject ho and po
	// TODO remove from signature as not used.
	input3 += 0;

	// Action buttons.
	if( input5 )
	{
		if( player_state_isonground == state )
		{
			command |= COMMAND_JUMP_MASK;
		}
		if( player_state_isintheair == state )
		{
			// Let play jump while falling!
			if( ho->hack_inair && !po->jumper_index )
			{
				command |= COMMAND_JUMP_MASK;
			}
			else
			{
				command |= COMMAND_SWAP_MASK;
			}
		}
	}
	if( input6 )
	{
		if( player_state_isonground == state )
		{
			command |= COMMAND_JUMP_MASK;
			command |= COMMAND_HIGH_MASK;
		}
		if( player_state_isintheair == state )
		{
			// Let play jump while falling!
			if( ho->hack_inair && !po->jumper_index )
			{
				command |= COMMAND_JUMP_MASK;
				command |= COMMAND_HIGH_MASK;
			}
			else
			{
				command |= COMMAND_FLIP_MASK;
			}
		}
	}

	// Horizontal movement.
	if( !input1 && !input2 )
	{
		command |= COMMAND_MIDD_MASK;
	}
	else
	{
		if( input1 )
		{
			command |= COMMAND_LEFT_MASK;
		}
		if( input2 )
		{
			command |= COMMAND_RGHT_MASK;
		}
	}

	// Vertical movement.
	//if( input3 )
	//{
	//	if( player_state_isonground == state )
	//	{
	//		// Edge case: ignore up direction if on ground but NOT jumping to filter out unused commands.
	//		if( input5 || input6 )
	//		{
	//			// re-use high mask as above.
	//			//command |= COMMAND_HIGH_MASK;
	//		}
	//	}
	//}
	if( input4 )
	{
		if( player_state_isintheair == state )
		{
			command |= COMMAND_DOWN_MASK;
		}
	}

	return command;
}



// Not reliable??
/*
unsigned char engine_command_manager_buildX( unsigned char  state, unsigned char input1, unsigned char input2, unsigned char input3, unsigned char input4, unsigned char input5, unsigned char input6 )
{
	unsigned char command = COMMAND_NONE_MASK;

	// Horizontal movement.
	if( !input1 && !input2 )
	{
		command |= COMMAND_MIDD_MASK;
	}
	else
	{
		if( input1 )
		{
			command |= COMMAND_LEFT_MASK;
		}
		if( input2 )
		{
			command |= COMMAND_RGHT_MASK;
		}
	}

	// Vertical movement + Action buttons.
	if( player_state_isonground == state )
	{
		if( input3 )
		{
			command |= COMMAND_HIGH_MASK;
		}
		if( input5 || input6 )
		{
			command |= COMMAND_JUMP_MASK;
		}
	}
	if( player_state_isintheair == state )
	{
		if( input4 )
		{
			command |= COMMAND_DOWN_MASK;
		}
		if( input5 )
		{
			command |= COMMAND_SWAP_MASK;
		}
		if( input6 )
		{
			command |= COMMAND_FLIP_MASK;
		}
	}

	return command;
}
*/


