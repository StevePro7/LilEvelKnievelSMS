#include "audio_manager.h"
#include "hack_manager.h"
#include "../devkit/_sms_manager.h"
#include "../devkit/_snd_manager.h"
#include "../banks/fixedbank.h"
#include <stdlib.h>

// Global variable.
struct_audio_object global_audio_object;

void engine_audio_manager_init()
{
	struct_audio_object *ao = &global_audio_object;
	ao->music_data = NULL;
	ao->music_bank = 0;
	ao->sound_data = NULL;
	ao->sound_bank = 0;
}

void engine_music_manager_play( unsigned char index )
{
	struct_audio_object *ao = &global_audio_object;
	struct_hack_object *ho = &global_hack_object;
	if( !ho->hack_music )
	{
		return;
	}

	devkit_SMS_mapROMBank( FIXED_BANK );
	ao->music_data = ( unsigned char* ) music_object_data[ index ];
	ao->music_bank = music_object_bank[ index ];

	devkit_SMS_mapROMBank( ao->music_bank );
	devkit_PSGPlay( ( unsigned char* ) ao->music_data );
}

void engine_music_manager_playnorepeat( unsigned char index )
{
	struct_audio_object *ao = &global_audio_object;
	struct_hack_object *ho = &global_hack_object;
	if( !ho->hack_music )
	{
		return;
	}

	devkit_SMS_mapROMBank( FIXED_BANK );
	ao->music_data = ( unsigned char* ) music_object_data[ index ];
	ao->music_bank = music_object_bank[ index ];

	devkit_SMS_mapROMBank( ao->music_bank );
	devkit_PSGPlayNoRepeat( ( unsigned char* ) ao->music_data );
}

void engine_music_manager_stop()
{
	struct_audio_object *ao = &global_audio_object;
	ao->music_data = NULL;
	ao->music_bank = 0;
	devkit_PSGStop();
}

void engine_music_manager_resume()
{
	struct_hack_object *ho = &global_hack_object;
	if( !ho->hack_music )
	{
		return;
	}

	devkit_PSGResume();
}

void engine_sound_manager_play( unsigned char index )
{
	struct_audio_object *ao = &global_audio_object;
	struct_hack_object *ho = &global_hack_object;
	if( !ho->hack_sound )
	{
		return;
	}

	devkit_SMS_mapROMBank( FIXED_BANK );
	ao->sound_data = ( unsigned char* ) sound_object_data[ index ];
	ao->sound_bank = sound_object_bank[ index ];

	devkit_SMS_mapROMBank( ao->sound_bank );
	devkit_PSGSFXPlay( ( unsigned char* ) ao->sound_data, devkit_SFX_CHANNELS2AND3() );
}

void engine_sound_manager_stop()
{
	struct_audio_object *ao = &global_audio_object;
	ao->sound_data = NULL;
	ao->sound_bank = 0;
	devkit_PSGSFXStop();
}

void engine_audio_manager_update()
{
	// Thanks to @eruiz for this code!
	struct_audio_object *ao = &global_audio_object;
	if( 0 != ao->music_bank )
	{
		devkit_SMS_mapROMBank( ao->music_bank );
		devkit_PSGFrame();
	}

	if( 0 != ao->sound_bank )
	{
		devkit_SMS_mapROMBank( ao->sound_bank );
		devkit_PSGSFXFrame();
	}
}
