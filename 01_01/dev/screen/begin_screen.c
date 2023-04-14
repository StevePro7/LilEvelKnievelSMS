#include "begin_screen.h"
#include "../engine/debug_manager.h"
#include "../engine/enum_manager.h"
#include "../engine/game_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/util_manager.h"

void screen_begin_screen_load()
{
	unsigned char cloud;

	//Enable for debug mode.
	//engine_debug_manager_initgame();

	cloud = engine_random_manager_next( SPRITE_TILES );
	engine_game_manager_set_cloud_form( cloud );

	engine_graphics_manager_common();
}

void screen_begin_screen_update( unsigned char *screen_type )
{
	//*screen_type = screen_type_start;
	*screen_type = screen_type_diff;
}
