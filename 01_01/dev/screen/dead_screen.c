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

	// Get previous deltaX and move half pace while dying...
	player_deadX = engine_player_manager_get_deltaX( po->player_state, co->prev_command );
	player_deadX >>= 1;

	engine_player_manager_draw();
	engine_player_manager_head();
	engine_reset_manager_load( NORMAL_DELAY );
	swap = stage_mode_inc0;

	engine_riff_manager_init();
	devkit_PSGStop();

	index = engine_random_manager_next( MAX_RIFFS_DEATH );
	index += RIFF_START_DEAD;
	value = riff_indexs[ index ];
	count = riff_counts[ index ];
	loops = 0;
}

void screen_dead_screen_update( unsigned char *screen_type )
{
	struct_player_object *po = &global_player_object;
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
			engine_player_manager_dead( player_deadX );
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
				engine_sound_manager_play( sound_type_death );
			}
		}
	}

	if( !swap )
	{
		engine_player_manager_dead( player_deadX );
		swap = stage_mode_inc1;
	}
	
	// Don't draw player here as "blinks"
	//engine_player_manager_draw();
	engine_player_manager_head();
	*screen_type = screen_type_dead;
}
