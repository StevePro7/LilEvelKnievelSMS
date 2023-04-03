#include "splash_screen.h"
#include "../engine/asm_manager.h"
#include "../engine/content_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/input_manager.h"
#include "../engine/riff_manager.h"
#include "../engine/storage_manager.h"
#include "../engine/util_manager.h"
#include "../devkit/_sms_manager.h"
#include "../banks/fixedbank.h"
#include "../banks/bank2.h"

static unsigned char check;
static unsigned char erase;

void screen_splash_screen_load()
{
	devkit_SMS_displayOff();
	engine_asm_manager_clear_VRAM();
	engine_content_manager_splash();
	engine_graphics_manager_image( splash_tiles__tilemap__bin, TILE_IMAGE_SCREEN, 4, 4, 24, 16 );
	devkit_SMS_displayOn();
	check = stage_mode_inc0;
	erase = switch_mode_no;
}

void screen_splash_screen_update( unsigned char *screen_type )
{
	unsigned char input;
	unsigned char loops;
	unsigned char index;
	unsigned char count;
	unsigned char value;

	if( stage_mode_inc0 == check )
	{
		check = stage_mode_inc1;
		index = RIFF_START_SPLASH;
		value = riff_indexs[ index ];
		count = riff_counts[ index ];
		engine_riff_manager_init();
		for( loops = 0; loops < count; loops++ )
		{
			engine_riff_manager_play( loops + value );

			engine_input_manager_update();
			input = engine_input_manager_move( input_type_fire2 );
			if( input )
			{
				if( !erase )
				{
					erase = switch_mode_yes;

					// Erase SRAM and re-init game vars.
					engine_storage_manager_kill();
					engine_game_manager_init();
					engine_util_manager_locale_texts( 0, 25, 23 );
				}
			}
			input = engine_input_manager_move( input_type_fire1 );
			if( input )
			{
				break;
			}
		}
	}

	engine_random_manager_rand();
	*screen_type = screen_type_title;
}
