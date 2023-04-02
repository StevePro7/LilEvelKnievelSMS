#include "storage_manager.h"
#include "command_manager.h"
#include "font_manager.h"
#include "game_manager.h"
#include "global_manager.h"
#include "util_manager.h"
#include "../devkit/_sms_manager.h"
#include <stdbool.h>

#define MAGIC			0xACE0B004
#define FINAL			0xC9
#define BUFFER			6

// Global variable.
struct_storage_object global_storage_object;

// Reference:
// https://www.smspower.org/forums/16013-DevkitSMSSMSlibMissingRequestingFeatures
unsigned char engine_storage_manager_available()
{
	struct_storage_object *so = ( struct_storage_object* ) ( devkit_SMS_SRAM() );
	unsigned char foundMagic;

	devkit_SMS_enableSRAM();
	foundMagic = MAGIC == so->Magic;
	devkit_SMS_disableSRAM();
	return foundMagic;
}

void engine_storage_manager_load()
{
	struct_storage_object *so = ( struct_storage_object* ) ( devkit_SMS_SRAM() );

	devkit_SMS_enableSRAM();
	engine_game_manager_set_difficulty( so->storage_difficulty );
	engine_game_manager_set_level_data( so->storage_world, so->storage_round, so->storage_point );
	engine_game_manager_set_game_saved( so->storage_saved );
	engine_command_manager_load( so->storage_frame_index, so->storage_this_command );
	devkit_SMS_disableSRAM();
}

void engine_storage_manager_save()
{
	struct_storage_object *so = ( struct_storage_object* ) ( devkit_SMS_SRAM() );
	struct_game_object *go = &global_game_object;
	unsigned int index;

	devkit_SMS_enableSRAM();
	so->Magic = MAGIC;
	so->storage_difficulty = go->game_difficulty;
	so->storage_world = go->game_world;
	so->storage_round = go->game_round;
	so->storage_level = go->game_level;
	so->storage_point = go->game_point;
	so->storage_saved = go->game_saved;

	for( index = 0; index < BUFFER; index++ )
	{
		so->storage_padding[ index ] = 0;
	}

	// Iterate all the commands.
	for( index = 0; index < MAX_COMMANDS; index++ )
	{
		so->storage_frame_index[ index ] = command_frame_index[ index ];
		so->storage_this_command[ index ] = command_this_command[ index ];
	}

	so->terminal = FINAL;
	devkit_SMS_disableSRAM();
}

void engine_storage_manager_kill()
{
	struct_storage_object *so = ( struct_storage_object* ) ( devkit_SMS_SRAM() );
	devkit_SMS_enableSRAM();
	unsigned int index;

	so->Magic = 0x00000000;
	so->storage_difficulty = 0;
	so->storage_world = 0;
	so->storage_round = 0;
	so->storage_level = 0;
	so->storage_point = 0;
	so->storage_saved = 0;

	for( index = 0; index < BUFFER; index++ )
	{
		so->storage_padding[ index ] = 0;
	}

	// Iterate all the commands.
	for( index = 0; index < MAX_COMMANDS; index++ )
	{
		so->storage_frame_index[ index ] = 0;
		so->storage_this_command[ index ] = 0;
	}

	so->terminal = FINAL;
	devkit_SMS_disableSRAM();
}