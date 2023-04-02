#include "dead_screen.h"
#include "../engine/audio_manager.h"
#include "../engine/command_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/global_manager.h"
#include "../engine/input_manager.h"
#include "../engine/player_manager.h"
#include "../engine/riff_manager.h"
#include "../engine/scroll_manager.h"
#include "../engine/timer_manager.h"
#include "../engine/util_manager.h"
#include "../devkit/_snd_manager.h"

#ifdef _CONSOLE
#else
#pragma disable_warning 110
#pragma disable_warning 126
#endif

static unsigned char player_deadX;
static unsigned char deltaX;
static signed int deltaY;
static unsigned char swap;
static unsigned char count;
static unsigned char value;
static unsigned char loops;

void screen_dead_screen_load()
{
	struct_command_object *co = &global_command_object;
	struct_player_object *po = &global_player_object;
	static unsigned char index, maxim;
	engine_player_manager_dying();

	player_deadX = engine_player_manager_get_deltaX( po->player_state, co->prev_command );
	player_deadX >>= 1;

	engine_player_manager_draw();
	engine_player_manager_head();
	engine_reset_manager_load( NORMAL_DELAY );
	swap = 0;

	engine_riff_manager_init();
	devkit_PSGStop();

	// TODO - update magic number?
	maxim = 8;
	index = engine_random_manager_next( maxim );
	index += RIFF_START_DEAD;
	value = riff_indexs[ index ];
	count = riff_counts[ index ];
	loops = 0;
}

// TODO - inject pause before going to next screen...
void screen_dead_screen_update( unsigned char *screen_type )
{
	struct_player_object *po = &global_player_object;
	unsigned char input1, input2;
	//unsigned char input;
	//unsigned char check;

	if( swap )
	{
		if( po->posnY >= PLAYER_DEAD )
		{
			// Check if SFX complete...
			if( !devkit_PSGSFXGetStatus() )
			{
				if( 0 == po->player_lives )
				{
					*screen_type = screen_type_cont;
					return;
				}
				else
				{
					*screen_type = screen_type_load;
					return;
				}
			}
		}
		else
		{
			input1 = engine_input_manager_hold( input_type_up );
			input2 = engine_input_manager_move( input_type_down );
			input1 = 1;		// TODO delete
			if( input1 || input2 )
			{
				engine_player_manager_dead( player_deadX );
				engine_player_manager_draw();
				engine_player_manager_head();
			}
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
				engine_sound_manager_play( 0 );
			}
		}
	}

	if( !swap )
	{
		engine_player_manager_dead( player_deadX );
		swap = 1;
	}
	
	// don't draw player here as "blinks"
	//engine_player_manager_draw();
	engine_player_manager_head();
	*screen_type = screen_type_dead;
}
