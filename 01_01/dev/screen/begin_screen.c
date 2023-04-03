#include "begin_screen.h"
#include "../engine/asm_manager.h"
#include "../engine/content_manager.h"
#include "../engine/debug_manager.h"
#include "../engine/enum_manager.h"
//#include "../engine/font_manager.h"
#include "../engine/game_manager.h"
#include "../engine/global_manager.h"
#include "../engine/graphics_manager.h"
#include "../engine/util_manager.h"
#include "../devkit/_sms_manager.h"

void screen_begin_screen_load()
{
	unsigned char cloud;

	// TODO delete this.
	engine_debug_manager_initgame();
	// TODO delete this.

	// TODO delete here - from start.
	cloud = engine_random_manager_next( SPRITE_TILES );
	engine_game_manager_set_cloud_form( cloud );

	// TODO - can run this inline as this will be the only consumer eventually...
	engine_graphics_manager_common();
}

void screen_begin_screen_update( unsigned char *screen_type )
{
	//*screen_type = screen_type_over;
	//*screen_type = screen_type_intro;
	//*screen_type = screen_type_init;
	//*screen_type = screen_type_level;			// level select world by round
	//*screen_type = screen_type_option;
	//*screen_type = screen_type_diff;
	*screen_type = screen_type_beat;
	//*screen_type = screen_type_boss;
	//*screen_type = screen_type_demo;
	
	////*screen_type = screen_type_record;
	//*screen_type = screen_type_ready;			// level select level by level
	//*screen_type = screen_type_intro;
	//*screen_type = screen_type_begin;

	//*screen_type = screen_type_start;
}
