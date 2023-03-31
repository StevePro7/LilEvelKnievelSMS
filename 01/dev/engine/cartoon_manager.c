#include "cartoon_manager.h"
#include "enum_manager.h"
#include "font_manager.h"
#include "global_manager.h"

#ifdef _CONSOLE
#else
#pragma disable_warning 261
#endif

unsigned char engine_cartoon_manager_wave( unsigned char frame )
{
	if( frame < player_frame_ground_left_01 )
	{
		return 1 - frame;
	}

	if( frame < player_frame_theair_rght_01 )
	{
		if( player_frame_ground_left_01 == frame )
		{
			return player_frame_ground_left_02;
		}
		else if( player_frame_ground_left_02 == frame )
		{
			return player_frame_ground_left_01;
		}
	}

	return frame;
}

unsigned char engine_cartoon_manager_swap( unsigned char frame )
{
	if( frame < player_frame_theair_rght_01 )
	{
		if( frame == player_frame_ground_rght_01 || frame == player_frame_ground_left_01 )
		{
			return 2 - frame;
		}
	}
	else if( frame < player_frame_theair_left_01 )
	{
		return frame + 4;
	}
	else if( frame < player_frame_sprite_maximum )
	{
		return frame - 4;
	}

	return frame;
}

unsigned char engine_cartoon_manager_flip( unsigned char frame, unsigned char command )
{
	if( player_frame_ground_rght_01 == frame )
	{
		return player_frame_theair_rght_01;
	}
	else if( player_frame_ground_left_01 == frame )
	{
		return player_frame_theair_left_01;
	}
	else if( frame < player_frame_theair_left_01 )
	{
		if( ( COMMAND_LEFT_MASK & command ) == COMMAND_LEFT_MASK )
		{
			if( player_frame_theair_rght_01 == frame )
			{
				return player_frame_theair_rght_04;
			}
			else
			{
				return frame - 1;
			}
		}
		else
		{
			if( player_frame_theair_rght_04 == frame )
			{
				frame = player_frame_theair_rght_01;
			}
			else
			{
				return frame + 1;
			}
		}
	}
	else if( frame < player_frame_sprite_maximum )
	{
		if( ( COMMAND_RGHT_MASK & command ) == COMMAND_RGHT_MASK )
		{
			if( player_frame_theair_left_04 == frame )
			{
				return player_frame_theair_left_01;
			}
			else
			{
				return frame + 1;
			}
		}
		else
		{
			if( player_frame_theair_left_01 == frame )
			{
				frame = player_frame_theair_left_04;
			}
			else
			{
				return frame - 1;
			}
		}
	}

	return frame;
}