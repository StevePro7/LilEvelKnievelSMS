#include "main.h"

void main( void )
{
	unsigned char open_screen_type;
	bool global_pause;

	devkit_SMS_init();
	devkit_SMS_setSpriteMode( devkit_SPRITEMODE_NORMAL() );
	devkit_SMS_useFirstHalfTilesforSprites( false );
	devkit_SMS_VDPturnOnFeature( devkit_VDPFEATURE_HIDEFIRSTCOL() );

	engine_game_manager_init();
	if( engine_storage_manager_available() )
	{
		engine_storage_manager_load();
	}

	engine_hack_manager_init();
	engine_hack_manager_load();
	engine_audio_manager_init();
	engine_input_manager_init();
	engine_tile_manager_init();

	//open_screen_type = screen_type_splash;
	//open_screen_type = screen_type_title;
	open_screen_type = screen_type_begin;

	engine_player_manager_init();
	engine_screen_manager_init( open_screen_type );
	global_pause = false;
	for( ;; )
	{
		if( devkit_SMS_queryPauseRequested() )
		{
			devkit_SMS_resetPauseRequest();
			global_pause = !global_pause;
			if( global_pause )
			{
				devkit_PSGSilenceChannels();
			}
			else
			{
				devkit_PSGRestoreVolumes();
			}
		}

		if( global_pause )
		{
			engine_scroll_manager_para_update( 0 );
			devkit_SMS_waitForVBlank();
			continue;
		}

		devkit_SMS_initSprites();
		engine_input_manager_update();

		engine_screen_manager_update();

		devkit_SMS_finalizeSprites();
		devkit_SMS_waitForVBlank();

		devkit_UNSAFE_SMS_copySpritestoSAT();
		engine_audio_manager_update();
	}
}
